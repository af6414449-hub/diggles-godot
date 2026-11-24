#!/usr/bin/env python3
"""Scan Diggles .ent template files for embedded float/object coordinates.

Goal: find out what world-Z the engine actually stores for objects whose
template .tcl lists a (possibly negative) z literal.  We look for the float
values of interesting template z literals (e.g. -39.01) and for plausible
transformed values (z + 7.0, z + 14.5, z - 7.0 ...).

Read-only.  Usage:
    python scan_ent.py <file.ent> [z1 z2 ...]
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path


def floats(data: bytes):
    for off in range(0, len(data) - 3):
        yield off, struct.unpack_from("<f", data, off)[0]


def doubles(data: bytes):
    for off in range(0, len(data) - 7):
        yield off, struct.unpack_from("<d", data, off)[0]


def main() -> int:
    path = Path(sys.argv[1])
    data = path.read_bytes()
    print(f"file      : {path}")
    print(f"size      : {len(data)} bytes")

    targets = []
    for a in sys.argv[2:]:
        targets.append(float(a))

    if not targets:
        # just report the float histogram of plausible z-like values
        targets = []

    fl = list(floats(data))
    print(f"float32 count: {len(fl)}")

    # 1. direct hits of the requested values (as float32 and float64)
    for t in targets:
        hits = [off for off, v in fl if abs(v - t) < 0.005]
        print(f"  float32 ~ {t:>10}: {len(hits)} hits  {hits[:8]}")
        hits64 = []
        for off in range(0, len(data) - 7):
            v = struct.unpack_from("<d", data, off)[0]
            if abs(v - t) < 0.005:
                hits64.append(off)
        print(f"  float64 ~ {t:>10}: {len(hits64)} hits  {hits64[:8]}")

    # 2. all floats that look like z of the template objects (|v| < 200)
    #    and are not obviously part of a texture id etc.
    vals = sorted({round(v, 4) for _, v in fl if 0.001 < abs(v) < 200.0})
    print(f"\nfloat32 values in (0,200) excluding tiny: {len(vals)}")
    print(vals[:400])
    return 0


if __name__ == "__main__":
    sys.exit(main())
