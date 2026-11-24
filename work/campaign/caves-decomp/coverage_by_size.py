#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Coverage by CODE SIZE, not by function count.

Uses the Ghidra index.tsv (function -> size in bytes) of both binaries and
the tier column of coverage.tsv to answer "how many bytes of game code are
actually explained by the report".
"""
from __future__ import annotations

from collections import defaultdict
from pathlib import Path

ZONE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp")
COV = ZONE / "coverage.tsv"
INDEXES = {
    "exe": Path(r"C:\diggles-ghidra\out\index.tsv"),
    "port": Path(r"C:\diggles-ghidra\out_port\index.tsv"),
}


def load_sizes(path: Path) -> dict[str, int]:
    sizes: dict[str, int] = {}
    if not path.exists():
        return sizes
    with path.open(encoding="utf-8", errors="replace") as f:
        next(f, None)
        for line in f:
            p = line.rstrip("\n").split("\t")
            if len(p) >= 3:
                try:
                    sizes[p[0].strip()] = int(p[2])
                except ValueError:
                    pass
    return sizes


def main() -> None:
    sizes = {m: load_sizes(p) for m, p in INDEXES.items()}
    rows = []
    with COV.open(encoding="utf-8") as f:
        next(f, None)
        for line in f:
            p = line.rstrip("\n").split("\t")
            if len(p) >= 9:
                rows.append(p)

    for module in ("exe", "port"):
        sel = [r for r in rows if r[0] == module]
        sz = sizes.get(module, {})
        tot = sum(sz.get(r[2], 0) for r in sel)
        game = [r for r in sel if r[5] == "game"]
        tot_game = sum(sz.get(r[2], 0) for r in game)
        for label, group in (("all", sel), ("game", game)):
            t = sum(sz.get(r[2], 0) for r in group)
            cov = sum(sz.get(r[2], 0) for r in group if r[6] != "0")
            cov3 = sum(sz.get(r[2], 0) for r in group if r[6] == "3")
            print(f"{module}/{label}: total={t} B covered(tier>=1)={cov} B "
                  f"({cov * 100.0 / t if t else 0:.2f} %) tier3={cov3} B "
                  f"({cov3 * 100.0 / t if t else 0:.2f} %)")
        # per-subsystem code size
        by = defaultdict(int)
        for r in game:
            by[r[4]] += sz.get(r[2], 0)
        print("  top subsystems by code size:")
        for sub, b in sorted(by.items(), key=lambda kv: -kv[1])[:12]:
            print(f"     {sub:<28} {b:>8} B")
        print()


if __name__ == "__main__":
    main()
