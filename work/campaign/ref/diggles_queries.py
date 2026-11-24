#!/usr/bin/env python3
"""Diggles.exe helper queries: IAT names, constant table, call-site search."""
from __future__ import annotations

import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections, va_to_file_off, file_off_to_va, read_cstr  # noqa: E402


def import_map(data: bytes, sections, image_base) -> dict[int, str]:
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    nsec = struct.unpack_from("<H", data, pe + 6)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    opt = pe + 24
    magic = struct.unpack_from("<H", data, opt)[0]
    ddoff = opt + (112 if magic == 0x20B else 96)
    impva, _ = struct.unpack_from("<II", data, ddoff + 8)
    result: dict[int, str] = {}
    off = va_to_file_off(impva, sections, image_base)
    if off is None:
        return result
    while True:
        ilt, ts, fc, nm, fta = struct.unpack_from("<IIIII", data, off)
        if nm == 0:
            break
        no = va_to_file_off(nm, sections, image_base)
        dll = read_cstr(data, no) if no is not None else "?"
        thunk_rva = ilt if ilt else fta
        t = va_to_file_off(thunk_rva, sections, image_base)
        if t is None:
            off += 20
            continue
        step = 8 if magic == 0x20B else 4
        iat_rva = fta
        while True:
            if magic == 0x20B:
                v = struct.unpack_from("<Q", data, t)[0]
            else:
                v = struct.unpack_from("<I", data, t)[0]
            if v == 0:
                break
            if not (v & (1 << 63)):
                ho = va_to_file_off(v, sections, image_base)
                if ho is not None:
                    nm2 = read_cstr(data, ho + 2)
                    result[image_base + iat_rva] = f"{dll}!{nm2}"
            iat_rva += step
            t += step
        off += 20
    return result


def find_calls(data: bytes, sections, image_base, target_va: int) -> list[int]:
    """Find E8 rel32 call sites targeting target_va."""
    hits = []
    for s in sections:
        if s["name"] != ".text":
            continue
        base = s["raw_ptr"]
        end = base + s["raw_size"]
        for off in range(base, end - 5):
            if data[off] != 0xE8:
                continue
            rel = struct.unpack_from("<i", data, off + 1)[0]
            va = file_off_to_va(off, sections, image_base)
            if va is None:
                continue
            if va + 5 + rel == target_va:
                hits.append(va)
    return hits


def main() -> int:
    path = Path(sys.argv[1])
    data = path.read_bytes()
    sections, image_base = parse_sections(data)
    imps = import_map(data, sections, image_base)

    for addr in (0x715340, 0x715574, 0x715540):
        print(f"IAT 0x{addr:08X} -> {imps.get(addr, 'NOT FOUND')}")

    print("\n-- constant table at 0x724484 --")
    off = va_to_file_off(0x724484, sections, image_base)
    vals = struct.unpack_from("<2I", data, off)
    print(f"   0x{vals[0]:08X}  0x{vals[1]:08X}")

    print("\n-- callers of seed 0x4454d0 --")
    for c in find_calls(data, sections, image_base, 0x4454D0):
        print(f"   0x{c:08X}")

    print("\n-- callers of irandom handler 0x62f780 (registration) --")
    for c in find_calls(data, sections, image_base, 0x62F780):
        print(f"   0x{c:08X}")

    print("\n-- writers of counter 0x768350 --")
    target = struct.pack("<I", 0x768350)
    i = 0
    while True:
        i = data.find(target, i)
        if i < 0:
            break
        va = file_off_to_va(i, sections, image_base)
        print(f"   imm ref at file 0x{i:X} va 0x{va:08X}")
        i += 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
