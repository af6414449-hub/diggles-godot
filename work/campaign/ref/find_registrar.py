#!/usr/bin/env python3
"""Find the function(s) that register the native Tcl commands.

Tcl_CreateObjCommand is called from the engine's registration function(s).
In the decompiled dump the call appears as a call through the IAT slot, so
the easiest fingerprint is the presence of many command-name strings and the
Tcl_CreateObjCommand call in one function.

Usage: python find_registrar.py <decomp-dir> [--top 10]
"""
from __future__ import annotations

import re
import sys
from pathlib import Path


def main() -> int:
    root = Path(sys.argv[1])
    limit = int(sys.argv[sys.argv.index("--top") + 1]) if "--top" in sys.argv else 10
    hits = []
    for f in root.glob("*.c"):
        try:
            text = f.read_text(encoding="utf-8", errors="replace")
        except Exception:
            continue
        n = text.count("CreateObjCommand")
        if n:
            # count string literals that look like command names
            names = set(re.findall(r'"([a-z][a-z0-9_]{2,40})"', text))
            hits.append((n, len(names), f.name, sorted(names)[:12]))
    hits.sort(reverse=True)
    print(f"# functions referencing CreateObjCommand: {len(hits)}")
    for n, nn, name, sample in hits[:limit]:
        print(f"\n{n:4d} refs, {nn:3d} name-literals  {name}")
        print(f"        sample: {', '.join(sample)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
