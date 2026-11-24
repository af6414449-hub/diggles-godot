#!/usr/bin/env python3
"""Locate the native `irandom` Tcl command implementation inside Diggles.exe.

Strategy (no decompiler available on this host):
  1. Parse the PE section table to translate between file offsets and RVAs/VAs.
  2. Locate the "irandom" literal in .rdata and compute its VA.
  3. Find every 4-byte pointer to that VA -> these are entries of the Tcl
     command-name table.
  4. Recover the sibling function-pointer table (the array that sits next to
     the name table and holds one callback per command).
  5. Print the callback address plus a capstone disassembly of it.

Usage: python pe_irandom.py <path-to-exe>
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path

IMAGE_BASE = 0x00400000


def parse_sections(data: bytes) -> list[dict]:
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if data[pe:pe + 4] != b"PE\x00\x00":
        raise SystemExit("not a PE file")
    nsec = struct.unpack_from("<H", data, pe + 6)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    opt = pe + 24
    magic = struct.unpack_from("<H", data, opt)[0]
    pe32plus = magic == 0x20B
    if pe32plus:
        image_base = struct.unpack_from("<Q", data, opt + 24)[0]
    else:
        image_base = struct.unpack_from("<I", data, opt + 28)[0]
    sec_off = opt + optsz
    sections = []
    for i in range(nsec):
        b = sec_off + 40 * i
        name = data[b:b + 8].rstrip(b"\x00").decode("latin-1")
        vsize, va, rsize, ptr = struct.unpack_from("<IIII", data, b + 8)
        sections.append(
            {
                "name": name,
                "va": va,
                "vsize": vsize,
                "raw_size": rsize,
                "raw_ptr": ptr,
            }
        )
    return sections, image_base


def file_off_to_va(off: int, sections: list[dict], image_base: int) -> int | None:
    for s in sections:
        if s["raw_ptr"] <= off < s["raw_ptr"] + s["raw_size"]:
            return image_base + s["va"] + (off - s["raw_ptr"])
    return None


def va_to_file_off(va: int, sections: list[dict], image_base: int) -> int | None:
    rva = va - image_base
    for s in sections:
        if s["va"] <= rva < s["va"] + max(s["vsize"], s["raw_size"]):
            return s["raw_ptr"] + (rva - s["va"])
    return None


def find_literal(data: bytes, needle: bytes) -> int:
    idx = data.find(needle)
    if idx < 0:
        raise SystemExit(f"literal {needle!r} not found")
    return idx


def read_cstr(data: bytes, off: int) -> str:
    end = data.find(b"\x00", off)
    return data[off:end].decode("latin-1")


def main() -> int:
    path = Path(sys.argv[1])
    data = path.read_bytes()
    sections, image_base = parse_sections(data)
    print(f"image_base=0x{image_base:08X}")
    for s in sections:
        print(
            f"  sec {s['name']:10s} va=0x{s['va']:06X} vsize=0x{s['vsize']:06X} "
            f"raw=0x{s['raw_ptr']:06X} rsize=0x{s['raw_size']:06X}"
        )

    off = find_literal(data, b"irandom\x00")
    va = file_off_to_va(off, sections, image_base)
    print(f"\n'irandom' file offset=0x{off:X} va=0x{va:08X}")

    # Collect every 4-byte pointer to that VA.
    needle = struct.pack("<I", va)
    ptr_offs = []
    start = 0
    while True:
        i = data.find(needle, start)
        if i < 0:
            break
        ptr_offs.append(i)
        start = i + 1
    print("pointers to 'irandom':", [f"0x{o:X}" for o in ptr_offs])

    # The name table is an array of char*; walk backwards/forwards from each
    # hit while entries keep pointing into the same .rdata string blob.
    for hit in ptr_offs:
        arr_start = hit
        while True:
            prev = arr_start - 4
            if prev < 0:
                break
            val = struct.unpack_from("<I", data, prev)[0]
            nxt = va_to_file_off(val, sections, image_base)
            if nxt is None or not (32 <= nxt < len(data)):
                break
            try:
                txt = read_cstr(data, nxt)
            except Exception:
                break
            if not txt or not all(32 <= ord(c) < 127 for c in txt):
                break
            arr_start = prev
        arr_end = hit + 4
        while True:
            val = struct.unpack_from("<I", data, arr_end)[0]
            nxt = va_to_file_off(val, sections, image_base)
            if nxt is None or not (32 <= nxt < len(data)):
                break
            try:
                txt = read_cstr(data, nxt)
            except Exception:
                break
            if not txt or not all(32 <= ord(c) < 127 for c in txt):
                break
            arr_end += 4
        n = (arr_end - arr_start) // 4
        idx = (hit - arr_start) // 4
        print(
            f"\nname array at file 0x{arr_start:X} (va 0x{file_off_to_va(arr_start, sections, image_base):08X})"
            f" entries={n} 'irandom' index={idx}"
        )
        names = []
        for k in range(n):
            val = struct.unpack_from("<I", data, arr_start + 4 * k)[0]
            o = va_to_file_off(val, sections, image_base)
            names.append(read_cstr(data, o) if o is not None else "?")
        for k, nm in enumerate(names):
            marker = "  <<<" if k == idx else ""
            print(f"   [{k:3d}] {nm}{marker}")

        # Sibling arrays: scan +-4096 bytes of data for an array of the same
        # length whose entries look like code pointers.
        base_va = file_off_to_va(arr_start, sections, image_base)
        code_ranges = [
            s for s in sections if s["name"] in (".text", "CODE", ".code")
        ] or sections
        for delta in range(-2048, 2048, 4):
            cand = hit + delta
            if cand < 0 or cand + 4 * n > len(data):
                continue
            vals = [struct.unpack_from("<I", data, cand + 4 * k)[0] for k in range(n)]
            if len(set(vals)) != n:
                continue
            good = 0
            in_code = 0
            for v in vals:
                fo = va_to_file_off(v, sections, image_base)
                if fo is None:
                    continue
                good += 1
                for cr in code_ranges:
                    if cr["raw_ptr"] <= fo < cr["raw_ptr"] + cr["raw_size"]:
                        in_code += 1
                        break
            if good == n and in_code >= max(1, n // 2):
                cand_va = file_off_to_va(cand, sections, image_base)
                print(
                    f"\n  candidate fn-pointer array at file 0x{cand:X} va 0x{cand_va:08X}"
                    f" delta={delta:+d} code_entries={in_code}/{n}"
                )
                for k in range(n):
                    print(f"     [{k:3d}] 0x{vals[k]:08X}  ({names[k]})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
