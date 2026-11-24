#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Two boundary checks for Diggles.exe:

1) where does the statically linked UCRT start (address-wise)?
2) what GUID does the engine pass to DirectDrawCreateExPort? (IID_IDirectDraw7?)
"""
from __future__ import annotations

import re
import struct
from pathlib import Path

EXE = Path(r"C:\diggles-ghidra\out\decomp")
BIN = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref\Diggles.exe")

# {15DD65Ex-8DDF-11CF-8D43-00A0C911005A}, x = 0 (DirectDraw7), 2 (Direct3D7), 3 (D3DDevice7)
IID_TMPL = bytes.fromhex("e065dd15df8dcf118d4300a0c911005a")
IID_IDirectDraw7 = IID_TMPL
IID_IDirect3D7 = bytes([0xE2]) + IID_TMPL[1:]
IID_IDirect3DDevice7 = bytes([0xE3]) + IID_TMPL[1:]


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


def va_to_off(sections, base, va):
    rva = va - base
    for name, sva, vsize, rsize, ptr in sections:
        if sva <= rva < sva + max(vsize, rsize):
            return ptr + (rva - sva)
    return None


def main() -> None:
    data = BIN.read_bytes()
    sections, base = parse_sections(data)
    off = va_to_off(sections, base, 0x007156A0)
    guid = data[off:off + 16]
    d1 = struct.unpack_from("<IHH", guid, 0)
    rest = guid[8:]
    s = f"{d1[0]:08X}-{d1[1]:04X}-{d1[2]:04X}-{rest[0]:02X}{rest[1]:02X}-" + \
        "".join(f"{b:02X}" for b in rest[2:])
    print("GUID @ 0x007156A0 =", s)
    print("  == IID_IDirectDraw7    :", guid == IID_IDirectDraw7)
    print("  == IID_IDirect3D7      :", guid == IID_IDirect3D7)
    print("  == IID_IDirect3DDevice7:", guid == IID_IDirect3DDevice7)

    # --- name census in the suspicious window -------------------------------
    fns = []
    for f in EXE.glob("*.c"):
        m = re.match(r"^(.*?)_([0-9a-fA-F]{8})$", f.stem)
        if m:
            fns.append((int(m.group(2), 16), m.group(1)))
    fns.sort()
    print(f"\nfunctions in 0x006A0000..0x006C2000: "
          f"{sum(1 for a, _ in fns if 0x006A0000 <= a <= 0x006C2000)}")
    for a, n in fns:
        if 0x006A0000 <= a <= 0x006C2000:
            print(f"   0x{a:08X}  {n}")
    # gap analysis: biggest contiguous block whose names look like CRT
    print("\n-- last 12 named (non FUN_) functions below 0x6C0000 --")
    named = [(a, n) for a, n in fns if a < 0x006C0000 and not n.startswith("FUN_")]
    for a, n in named[-12:]:
        print(f"   0x{a:08X}  {n}")


if __name__ == "__main__":
    main()
