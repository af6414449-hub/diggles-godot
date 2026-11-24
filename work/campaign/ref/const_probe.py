#!/usr/bin/env python3
"""Locate float/int constants of interest inside Diggles.exe and name the
functions that use them.

The port keeps guessing numbers like the map level steps (14.5 / 12.5 / 7.0 /
0.5) and the camera tilt (0.29) / zoom (1.478). If such a literal exists in
the engine, the binary says exactly which function owns it.

For every requested value the script:
  * finds the 4-byte IEEE-754 pattern (float) or the integer pattern;
  * lists the hits in .text (code) and .rdata (data);
  * for code hits, walks back to the nearest MSVC prologue to name the
    enclosing function (cross-referenced with method_map.tsv when possible).

Usage: python const_probe.py <path-to-exe> <ref-dir> [value ...]
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections, va_to_file_off, file_off_to_va  # noqa: E402

PROLOGUE = b"\x55\x8B\xEC"


def load_method_names(ref: Path) -> dict[int, str]:
    names: dict[int, str] = {}
    p = ref / "method_map.tsv"
    if not p.exists():
        return names
    for line in p.read_text(encoding="utf-8").splitlines()[1:]:
        parts = line.split("\t")
        if len(parts) < 4 or not parts[3]:
            continue
        try:
            va = int(parts[3], 16)
        except ValueError:
            continue
        names.setdefault(va, f"{parts[1].strip()}::{parts[2].strip()}")
    return names


def main() -> int:
    path = Path(sys.argv[1])
    ref = Path(sys.argv[2])
    values = [float(v) for v in sys.argv[3:]] or [14.5, 12.5, 7.0, 0.5, 0.29, 1.478]

    data = path.read_bytes()
    sections, image_base = parse_sections(data)
    text = next(s for s in sections if s["name"] == ".text")
    t_off, t_size = text["raw_ptr"], text["raw_size"]
    t_va = image_base + text["va"]
    t_blob = data[t_off:t_off + t_size]
    method_names = load_method_names(ref)

    for value in values:
        pat = struct.pack("<f", value)
        ipat = struct.pack("<i", int(round(value)))
        print(f"\n=== {value} ===")
        found = False
        # float pattern
        for label, needle in (("float", pat), ("int", ipat)):
            start = 0
            while True:
                i = data.find(needle, start)
                if i < 0:
                    break
                start = i + 1
                va = file_off_to_va(i, sections, image_base)
                where = "?"
                for s in sections:
                    if s["raw_ptr"] <= i < s["raw_ptr"] + s["raw_size"]:
                        where = s["name"]
                info = ""
                if where == ".text":
                    j = t_blob.rfind(PROLOGUE, 0, i)
                    if j >= 0:
                        fva = t_va + j
                        info = f"func=0x{fva:08X} {method_names.get(fva, '')}"
                print(f"   {label:5s} {where:8s} file=0x{i:08X} va=0x{va:08X} {info}")
                found = True
        if not found:
            print("   (не найдено)")


if __name__ == "__main__":
    sys.exit(main())
