#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Locate the render-technique registry table in Diggles.exe.

strings.tsv gives the VA of every technique name (model_blend, scape_fow, ...).
The exe stores them in a table of pointers; we find the table and print the
neighbouring dwords, which carry the technique ids used by the renderer.
"""
from __future__ import annotations

import struct
from pathlib import Path

EXE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref\Diggles.exe")
STR = Path(r"C:\diggles-ghidra\out\strings.tsv")


def parse_sections(data: bytes):
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    nsec = struct.unpack_from("<H", data, pe + 6)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    opt = pe + 24
    sec_off = opt + optsz
    out = []
    for i in range(nsec):
        b = sec_off + 40 * i
        name = data[b:b + 8].rstrip(b"\x00").decode("latin-1")
        vsize, va, rsize, ptr = struct.unpack_from("<IIII", data, b + 8)
        out.append((name, va, vsize, rsize, ptr))
    return out, struct.unpack_from("<I", data, opt + 28)[0]


def main() -> None:
    data = EXE.read_bytes()
    sections, base = parse_sections(data)

    def va_to_off(va):
        rva = va - base
        for name, sva, vsize, rsize, ptr in sections:
            if sva <= rva < sva + max(vsize, rsize):
                return ptr + (rva - sva)
        return None

    names = []
    with STR.open(encoding="utf-8", errors="replace") as f:
        for line in f:
            p = line.rstrip("\n").split("\t")
            if len(p) >= 3:
                try:
                    va = int(p[0], 16)
                except ValueError:
                    continue
                if 0x00722E80 <= va <= 0x00723200:
                    names.append((va, p[2]))
    print(f"candidate technique names: {len(names)}")

    # find pointers to those strings
    hits = []
    for va, text in names:
        needle = struct.pack("<I", va)
        start = 0
        while True:
            i = data.find(needle, start)
            if i < 0:
                break
            off = va_to_off(base + i)  # i is a file offset, not VA
            hits.append((i, va, text))
            start = i + 1
    # only pointers inside a real section are meaningful
    def section_of(off):
        for name, va, vsize, rsize, ptr in sections:
            if ptr <= off < ptr + rsize:
                return name
        return "?"

    keep = [h for h in hits if section_of(h[0]) != "?"]
    print(f"pointers inside a section: {len(keep)}")
    for h in keep[:8]:
        print("   ", hex(h[0]), section_of(h[0]), h[2])
    hits = keep
    if not hits:
        return
    hits.sort()
    print(f"file-offset range: 0x{hits[0][0]:X}..0x{hits[-1][0]:X}")

    # the table: consecutive 4-byte slots; print name + following dwords
    print("\n| off | section | name | next dwords |")
    for off, va, text in hits:
        nxt = [struct.unpack_from("<I", data, off + 4 * k)[0] for k in range(1, 4)]
        print(f"| 0x{off:X} | {section_of(off)} | {text:<26} | "
              + " ".join(f"{x:08X}" for x in nxt) + " |")


if __name__ == "__main__":
    main()
