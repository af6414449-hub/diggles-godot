#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Probe the Diggles.exe PE for build toolchain evidence.

Extracts:
  * COFF/optional-header fields (machine, timestamp, linker version, subsystem)
  * Rich header entries (prodid / build / count) -> compiler + linker versions
  * VS_VERSION_INFO: fixed version + string table
  * imported DLL names

Usage: python pe_toolchain_probe.py <path-to-exe> [--out file.txt]
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path

# Rich header product-id -> human label (partial, MSVC-era ids)
RICH_TOOLS = {
    0x01: "Import0 (VS6 imp lib)",
    0x02: "Linker5.10",
    0x03: "Cvtomf5.10",
    0x04: "Linker6.00",
    0x05: "Cvtomf6.00",
    0x06: "Cvtres5.00",
    0x0E: "Masm6.13",
    0x0F: "Masm7.10",
    0x10: "Linker5.11",
    0x13: "Linker5.12",
    0x19: "Implib7.00",
    0x1E: "Linker6.10",
    0x25: "Linker6.20",
    0x2A: "Masm6.15",
    0x2B: "Utc13_LTCG_C",
    0x2C: "Utc13_LTCG_CPP",
    0x2D: "Masm6.16",
    0x2E: "Utc13_POGO_I_C",
    0x2F: "Utc13_POGO_I_CPP",
    0x30: "Utc13_POGO_O_C",
    0x31: "Utc13_POGO_O_CPP",
    0x40: "Linker7.10p",
    0x45: "Utc13_C (VS2003)",
    0x46: "Utc13_CPP (VS2003)",
    0x47: "Linker8.00 (VS2005)",
    0x48: "Cvtomf8.00",
    0x5A: "Masm8.00 (VS2005)",
    0x5D: "Utc13_C_2",
    0x5E: "Linker9.00 (VS2008)",
    0x60: "Utc13_CPP_2 (VS2008)",
    0x6D: "Utc1310_C (VS2010)",
    0x6E: "Utc1310_CPP (VS2010)",
    0x78: "Linker10.10 (VS2010)",
    0x83: "Utc1400_C (VS2015)",
    0x84: "Utc1400_CPP (VS2015)",
    0x93: "Utc1400_C (VS2015)",
    0x94: "Utc1400_CPP (VS2015)",
    0x95: "Linker14.00 (VS2015)",
    0x9D: "Utc1500_C (VS2017)",
    0x9E: "Utc1500_CPP (VS2017)",
    0xAA: "Linker14.10 (VS2017)",
    0xAB: "Masm14.10 (VS2017)",
    0xAF: "Utc1610_C (VS2019)",
    0xB0: "Utc1610_CPP (VS2019)",
    0xC7: "Utc1610_C (VS2019)",
    0xC8: "Utc1610_CPP (VS2019)",
    0xC9: "Linker14.20 (VS2019)",
    0xCA: "Utc1610_C (VS2019)",
    0xCB: "Utc1610_CPP (VS2019)",
    0xCC: "Linker14.20 (VS2019)",
    0xCD: "Utc1610_C (VS2019)",
    0xCE: "Utc1610_CPP (VS2019)",
    0xCF: "Utc1500_C (VS2017)",
    0xD0: "Utc1500_CPP (VS2017)",
    0xFF: "Unknown",
}


def u16(data: bytes, off: int) -> int:
    return struct.unpack_from("<H", data, off)[0]


def u32(data: bytes, off: int) -> int:
    return struct.unpack_from("<I", data, off)[0]


def parse_rich(data: bytes) -> tuple[list[tuple[int, int, int]], int]:
    """Return (entries, key). entries = (prodid, build, count)."""
    idx = data.find(b"Rich")
    if idx < 0:
        return [], 0
    key = u32(data, idx + 4)
    # walk backwards over 8-byte dwords
    start = 0x80
    # find DanS (encoded)
    pos = idx - 4
    while pos >= start:
        if u32(data, pos) ^ key == 0x536E6144:  # "DanS"
            break
        pos -= 4
    else:
        return [], key
    entries = []
    p = pos + 16  # skip DanS + 3 padding dwords
    while p < idx:
        comp = u32(data, p) ^ key
        cnt = u32(data, p + 4) ^ key
        prodid = (comp >> 16) & 0xFFFF
        build = comp & 0xFFFF
        entries.append((prodid, build, cnt))
        p += 8
    return entries, key


def parse_version(data: bytes) -> tuple[dict, dict]:
    fixed: dict = {}
    strings: dict = {}
    marker = "VS_VERSION_INFO".encode("utf-16-le")
    pos = data.find(marker)
    if pos < 0:
        return fixed, strings
    # VS_FIXEDFILEINFO starts after the key + padding, 4-byte aligned
    p = pos + len(marker) + 2
    p = (p + 3) & ~3
    if u32(data, p) == 0xFEEF04BD:
        fixed["signature"] = "0xFEEF04BD"
        fms, fls = u32(data, p + 8), u32(data, p + 12)
        pms, pls = u32(data, p + 16), u32(data, p + 20)
        fixed["FileVersion"] = f"{fms >> 16}.{fms & 0xFFFF}.{fls >> 16}.{fls & 0xFFFF}"
        fixed["ProductVersion"] = f"{pms >> 16}.{pms & 0xFFFF}.{pls >> 16}.{pls & 0xFFFF}"
        fixed["FileFlagsMask"] = hex(u32(data, p + 24))
        fixed["FileOS"] = hex(u32(data, p + 28))
        fixed["FileType"] = hex(u32(data, p + 32))
    for key in ("CompanyName", "FileDescription", "FileVersion", "InternalName",
                "LegalCopyright", "OriginalFilename", "ProductName", "ProductVersion",
                "Comments", "LegalTrademarks", "PrivateBuild", "SpecialBuild"):
        kb = key.encode("utf-16-le")
        k = data.find(kb, pos)
        if k < 0:
            continue
        # skip key + NUL, align to 4
        vp = k + len(kb) + 2
        vp = (vp + 3) & ~3
        # value: null-terminated utf-16
        end = data.find(b"\x00\x00", vp)
        if end < 0:
            continue
        raw = data[vp:end + 1]
        try:
            val = raw.decode("utf-16-le", errors="replace").strip("\x00")
        except Exception:
            continue
        if val:
            strings[key] = val
    return fixed, strings


def parse_imports(data: bytes, sections, image_base: int) -> list[str]:
    def va_to_off(va: int) -> int | None:
        rva = va - image_base
        for s in sections:
            if s["va"] <= rva < s["va"] + max(s["vsize"], s["raw_size"]):
                return s["raw_ptr"] + (rva - s["va"])
        return None

    pe = u32(data, 0x3C)
    opt = pe + 24
    magic = u16(data, opt)
    dd = opt + (96 if magic == 0x10B else 112)
    imp_rva = u32(data, dd + 8)
    off = va_to_off(image_base + imp_rva)
    dlls: list[str] = []
    if off is None:
        return dlls
    i = 0
    while True:
        base = off + i * 20
        name_rva = u32(data, base + 12)
        if name_rva == 0:
            break
        no = va_to_off(image_base + name_rva)
        if no is None:
            break
        end = data.find(b"\x00", no)
        dlls.append(data[no:end].decode("latin-1"))
        i += 1
    return dlls


def main() -> int:
    exe = Path(sys.argv[1])
    out = Path(sys.argv[sys.argv.index("--out") + 1]) if "--out" in sys.argv else None
    data = exe.read_bytes()
    lines: list[str] = []
    add = lines.append

    add(f"FILE: {exe}")
    add(f"SIZE: {len(data)} bytes")
    pe = u32(data, 0x3C)
    add(f"PE offset: 0x{pe:X}")
    machine = u16(data, pe + 4)
    nsec = u16(data, pe + 6)
    ts = u32(data, pe + 8)
    optsz = u16(data, pe + 20)
    chars = u16(data, pe + 22)
    opt = pe + 24
    magic = u16(data, opt)
    major_link = data[opt + 2]
    minor_link = data[opt + 3]
    add(f"Machine: 0x{machine:04X} ({'i386' if machine == 0x14C else 'other'})")
    add(f"Sections: {nsec}")
    add(f"TimeDateStamp: 0x{ts:08X} ({ts})")
    import datetime
    try:
        add(f"  -> UTC: {datetime.datetime.utcfromtimestamp(ts).isoformat()}Z")
    except Exception:
        pass
    add(f"Characteristics: 0x{chars:04X}")
    add(f"OptionalHeader magic: 0x{magic:04X} ({'PE32' if magic == 0x10B else 'PE32+'})")
    add(f"Linker version: {major_link}.{minor_link}")
    add(f"EntryPoint RVA: 0x{u32(data, opt + 16):08X}")
    if magic == 0x10B:
        add(f"ImageBase: 0x{u32(data, opt + 28):08X}")
        subsys = u16(data, opt + 68)
        dllchar = u16(data, opt + 70)
        ndd = u32(data, opt + 92)
        dd = opt + 96
    else:
        add(f"ImageBase: 0x{u64_at(data, opt + 24):016X}")
        subsys = u16(data, opt + 68)
        dllchar = u16(data, opt + 70)
        ndd = u32(data, opt + 108)
        dd = opt + 112
    add(f"Subsystem: {subsys} ({'GUI' if subsys == 2 else 'CUI' if subsys == 3 else 'other'})")
    add(f"DllCharacteristics: 0x{dllchar:04X}")
    add(f"NumberOfRvaAndSizes: {ndd}")

    # sections
    sec_off = opt + optsz
    sections = []
    add("SECTIONS:")
    for i in range(nsec):
        b = sec_off + 40 * i
        name = data[b:b + 8].rstrip(b"\x00").decode("latin-1")
        vsize, va, rsize, ptr = struct.unpack_from("<IIII", data, b + 8)
        ch = u32(data, b + 36)
        sections.append({"name": name, "va": va, "vsize": vsize,
                         "raw_size": rsize, "raw_ptr": ptr})
        add(f"  {name:<10} RVA=0x{va:08X} VSize=0x{vsize:08X} Raw=0x{ptr:08X} RawSz=0x{rsize:08X} Chars=0x{ch:08X}")

    # Rich header
    entries, key = parse_rich(data)
    add("")
    add("RICH HEADER:")
    if not entries:
        add("  (not found)")
    else:
        add(f"  XOR key: 0x{key:08X}")
        for prodid, build, cnt in entries:
            label = RICH_TOOLS.get(prodid, f"tool 0x{prodid:02X}")
            add(f"  prodid=0x{prodid:04X} build={build:<7} count={cnt:<6} {label}")

    # version resource
    fixed, strings = parse_version(data)
    add("")
    add("VERSION RESOURCE:")
    if not fixed and not strings:
        add("  (not found)")
    for k, v in fixed.items():
        add(f"  {k}: {v}")
    for k, v in strings.items():
        add(f"  {k}: {v}")

    # imports
    image_base = u32(data, opt + 28) if magic == 0x10B else u64_at(data, opt + 24)
    dlls = parse_imports(data, sections, image_base)
    add("")
    add("IMPORTED DLLs:")
    for d in dlls:
        add(f"  {d}")

    text = "\n".join(lines) + "\n"
    if out:
        out.write_text(text, encoding="utf-8")
        print(f"written: {out}")
    else:
        print(text)
    return 0


def u64_at(data: bytes, off: int) -> int:
    return struct.unpack_from("<Q", data, off)[0]


if __name__ == "__main__":
    sys.exit(main())
