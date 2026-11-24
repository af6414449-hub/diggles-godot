#!/usr/bin/env python3
"""Identify a decompiled function by the trace strings it references.

Ghidra emits the assert/trace strings of the original engine as DAT_xxxxxx
references. The string table of the neighbour session (work/campaign/ref/
ghidra-out/strings.tsv) maps the address back to the text, and the engine
writes the source file and the method signature into those strings. So a
function that references "Engine\\WallRenderer.cpp" is a method of the wall
renderer, and one that references "TCL:CTclGlobalMethods::SMDrawStone()" is
the native command handler.

Usage:
    python decomp_id.py <decomp-dir> <file.c> [<file.c> ...]
    python decomp_id.py <decomp-dir> --callers <FUN_xxxx>
"""

import re
import sys
from pathlib import Path

DAT = re.compile(r"DAT_00([0-9a-fA-F]{6})")


def load_strings(path: Path) -> dict:
    table = {}
    if not path.is_file():
        return table
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines()[1:]:
        parts = line.split("\t")
        if len(parts) >= 3:
            table[parts[0].strip().lower()] = parts[2].strip()
    return table


def identify(path: Path, table: dict) -> list:
    text = path.read_text(encoding="utf-8", errors="replace")
    hits = []
    for address in dict.fromkeys(DAT.findall(text)):
        key = address.lower()
        value = table.get(key)
        if value and value not in hits:
            hits.append(value)
    return hits


def main() -> int:
    root = Path(sys.argv[1])
    strings_path = root / "strings.tsv"
    files = sys.argv[2:]
    if files and files[0] == "--strings":
        strings_path = Path(files[1])
        files = files[2:]
    table = load_strings(strings_path)
    if not table:
        print(f"no string table at {strings_path}")
        return 1
    if len(files) > 1 and files[0] == "--callers":
        needle = files[1]
        for path in sorted(root.glob("*.c")):
            text = path.read_text(encoding="utf-8", errors="replace")
            if needle in text:
                hits = identify(path, table)
                label = "; ".join(hits[:2]) if hits else "-"
                print(f"caller {path.name} :: {label}")
        return 0
    for name in files:
        path = root / name
        if not path.is_file():
            print(f"{name}: missing")
            continue
        hits = identify(path, table)
        print(f"{name}:")
        for hit in hits:
            print(f"    {hit}")
        if not hits:
            print("    (no trace strings referenced)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
