#!/usr/bin/env python3
"""Dump ASCII and UTF-16LE strings of a PE file with their virtual addresses.

Usage: python strings_dump.py <path-to-pe> [--min 5] [--grep substr]
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections, file_off_to_va  # noqa: E402

ASCII_RE = re.compile(rb"[\x20-\x7e]{%d,}" % 4)


def main() -> int:
    path = Path(sys.argv[1])
    minlen = 5
    grep = None
    if "--min" in sys.argv:
        minlen = int(sys.argv[sys.argv.index("--min") + 1])
    if "--grep" in sys.argv:
        grep = sys.argv[sys.argv.index("--grep") + 1].lower()

    data = path.read_bytes()
    sections, image_base = parse_sections(data)

    rows = []
    for m in ASCII_RE.finditer(data):
        s = m.group(0).decode("latin-1")
        if grep and grep not in s.lower():
            continue
        rows.append((m.start(), "ascii", s))
    # utf-16le
    i = 0
    while i < len(data) - 1:
        if 32 <= data[i] < 127 and data[i + 1] == 0:
            j = i
            chars = []
            while j < len(data) - 1 and 32 <= data[j] < 127 and data[j + 1] == 0:
                chars.append(chr(data[j]))
                j += 2
            if len(chars) >= minlen:
                s = "".join(chars)
                if not grep or grep in s.lower():
                    rows.append((i, "utf16", s))
            i = j
        else:
            i += 1

    rows.sort()
    for off, kind, s in rows:
        va = file_off_to_va(off, sections, image_base)
        vas = f"0x{va:08X}" if va is not None else "--------"
        print(f"{off:08X} {vas} {kind:5s} {s}")
    print(f"# total: {len(rows)} strings")
    return 0


if __name__ == "__main__":
    sys.exit(main())
