#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""List the functions called by a decompiled file, with call counts and
the line of first use.

Usage: python calls_of.py <file.c> [--top N]
"""
from __future__ import annotations

import re
import sys
from collections import Counter
from pathlib import Path

CALL_RE = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]{2,60})\s*\(")
SKIP = {
    "if", "while", "for", "switch", "return", "sizeof", "defined", "else", "do",
    "case", "break", "continue", "goto", "typedef", "struct", "union", "enum",
    "static", "const", "void", "int", "char", "long", "short", "unsigned",
    "float", "double", "bool", "true", "false", "new", "delete", "this",
}


def main() -> int:
    path = Path(sys.argv[1])
    top = 40
    if "--top" in sys.argv:
        top = int(sys.argv[sys.argv.index("--top") + 1])
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    cnt: Counter = Counter()
    first: dict[str, int] = {}
    for i, ln in enumerate(lines, 1):
        code = ln.split("//")[0]
        for m in CALL_RE.finditer(code):
            n = m.group(1)
            if n in SKIP:
                continue
            cnt[n] += 1
            first.setdefault(n, i)
    print(f"{path.name}: {len(cnt)} distinct calls")
    for n, c in cnt.most_common(top):
        print(f"  {c:>4}  line {first[n]:>5}  {n}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
