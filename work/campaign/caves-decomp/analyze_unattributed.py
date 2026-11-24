#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""What is inside the 'unattributed' bucket of coverage.tsv?

Prints the most common name shapes of functions that the BFS attribution
could not reach from any named function (depth <= 6).
"""
from __future__ import annotations

import re
from collections import Counter
from pathlib import Path

TSV = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp\coverage.tsv")


def shape(name: str) -> str:
    if name.startswith("FUN_"):
        return "FUN_*"
    n = re.sub(r"_[0-9a-f]{8}$", "", name)
    n = re.sub(r"[0-9]+", "#", n)
    return n


def main() -> None:
    rows = []
    with TSV.open(encoding="utf-8") as f:
        head = next(f)
        for line in f:
            p = line.rstrip("\n").split("\t")
            if len(p) < 9:
                continue
            rows.append(p)
    print("columns:", head.strip())
    for module in ("exe", "port"):
        sel = [r for r in rows if r[0] == module and r[4] == "unattributed"
               and r[5] == "game"]
        print(f"\n=== {module}: unattributed game functions = {len(sel)}")
        c = Counter(shape(r[2]) for r in sel)
        for name, n in c.most_common(25):
            print(f"   {n:>5}  {name}")
        print("   --- examples ---")
        for r in sel[:15]:
            print(f"      {r[2]:<45} callers={r[8]}")


if __name__ == "__main__":
    main()
