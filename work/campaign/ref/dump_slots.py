#!/usr/bin/env python3
"""Dump 4-byte slots around a file offset and classify what each points to."""
from __future__ import annotations

import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections, va_to_file_off, file_off_to_va, read_cstr  # noqa: E402


def classify(val: int, data: bytes, sections, image_base) -> str:
    fo = va_to_file_off(val, sections, image_base)
    if fo is None:
        return "?"
    for s in sections:
        if s["raw_ptr"] <= fo < s["raw_ptr"] + s["raw_size"]:
            if s["name"] == ".text":
                return f".text+0x{fo - s['raw_ptr']:X}"
            break
    if 0 <= fo < len(data):
        try:
            txt = read_cstr(data, fo)
        except Exception:
            return "?"
        if txt and all(32 <= ord(c) < 127 for c in txt) and len(txt) < 60:
            return repr(txt)
    return "?"


def main() -> int:
    path = Path(sys.argv[1])
    center = int(sys.argv[2], 0)
    window = int(sys.argv[3], 0) if len(sys.argv) > 3 else 0x100
    data = path.read_bytes()
    sections, image_base = parse_sections(data)
    lo = center - window - (window % 4)
    hi = center + window
    for off in range(lo, hi, 4):
        val = struct.unpack_from("<I", data, off)[0]
        va = file_off_to_va(off, sections, image_base)
        mark = "  <<<" if off == center else ""
        print(f"0x{off:06X} (va 0x{va:08X}) : 0x{val:08X}  {classify(val, data, sections, image_base)}{mark}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
