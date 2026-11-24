#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Search both Diggles binaries for known DirectX interface GUIDs.

Used to confirm which DirectX generation the engine actually talks to.
"""
from __future__ import annotations

import struct
from pathlib import Path

BINS = {
    "Diggles.exe": Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref\Diggles.exe"),
    "DigglesPort.dll": Path(r"C:\diggles-ghidra\DigglesPort.dll"),
}

# {Data1-Data2-Data3-Data4}
GUIDS = {
    "IID_IDirectDraw": "6C14DB80-A733-11CF-8D43-00A0C911005A",
    "IID_IDirectDraw2": "B3A6F3E0-2B43-11CF-A2DE-00AA00B93356",
    "IID_IDirectDraw4": "9c59509a-39bd-11d2-89cf-0060b0a03a00",
    "IID_IDirectDraw7": "15DD65E0-8DDF-11CF-8D43-00A0C911005A",
    "IID_IDirectDrawSurface7": "15E65EC0-3B9C-11D2-B92F-00609797EA5B",
    "IID_IDirectDrawSurface3": "15E65EC0-3B9C-11D2-B92F-00609797EA5B",
    "IID_IDirect3D7": "15DD65E2-8DDF-11CF-8D43-00A0C911005A",
    "IID_IDirect3DDevice7": "15DD65E3-8DDF-11CF-8D43-00A0C911005A",
    "IID_IDirectDrawSurface4": "0B2B8630-AD35-11D0-8EA6-00609797EA5B",
    "IID_IDirectDrawPalette": "9c59509a-39bd-11d2-89cf-0060b0a03a00",
}


def guid_bytes(s: str) -> bytes:
    p = s.split("-")
    d1 = struct.pack("<I", int(p[0], 16))
    d2 = struct.pack("<H", int(p[1], 16))
    d3 = struct.pack("<H", int(p[2], 16))
    d4 = bytes.fromhex(p[3]) + bytes.fromhex(p[4])
    return d1 + d2 + d3 + d4


def main() -> None:
    for tag, path in BINS.items():
        if not path.exists():
            print(f"{tag}: MISSING {path}")
            continue
        data = path.read_bytes()
        print(f"=== {tag} ({len(data)} bytes)")
        for name, gs in GUIDS.items():
            gb = guid_bytes(gs)
            hits = []
            start = 0
            while True:
                i = data.find(gb, start)
                if i < 0:
                    break
                hits.append(i)
                start = i + 1
                if len(hits) > 8:
                    break
            if hits:
                print(f"   {name:<26} {gs}  -> {len(hits)} hit(s) at "
                      + ", ".join(f"0x{h:X}" for h in hits[:6]))
        print()


if __name__ == "__main__":
    main()
