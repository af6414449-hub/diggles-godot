#!/usr/bin/env python3
"""Attribute unnamed functions to subsystems via the call graph.

Without PDB, 3 764 engine functions keep the placeholder name FUN_xxxxxxxx.
Most of them are not virtual (CMap, CFogOfWar, CProdPlanner, CObj have no
vtable), so the vtable map does not place them. The call graph does: a
function called only from CTclGlobalMethods__SetView belongs to the camera
subsystem, one called only from CTclObjMethods__ProdAssignWorker belongs to
the production planner.

This script builds the caller graph over the decompiled dump and buckets the
unnamed functions by the named functions that call them.

Usage: python callgraph_subsystems.py <decomp-dir> [--out buckets.tsv]
"""
from __future__ import annotations

import re
import sys
from collections import defaultdict
from pathlib import Path

CALL_RE = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]{2,60})\s*\(")
SKIP = {
    "if", "while", "for", "switch", "return", "sizeof", "defined", "else",
    "do", "case", "break", "continue", "goto", "typedef", "struct", "union",
    "enum", "static", "const", "void", "int", "char", "long", "short",
    "unsigned", "float", "double", "bool", "true", "false",
}


def main() -> int:
    root = Path(sys.argv[1])
    out_path = Path(sys.argv[sys.argv.index("--out") + 1]) if "--out" in sys.argv \
        else Path(__file__).resolve().parent / "callgraph_subsystems.tsv"

    # address -> function name, taken from the Ghidra index
    addr_names: dict[str, str] = {}
    index = root.parent / "index.tsv"
    if index.exists():
        for line in index.read_text(encoding="utf-8", errors="replace").splitlines()[1:]:
            p = line.split("\t")
            if len(p) > 1:
                addr_names[p[1].lower()] = p[0]

    callers: dict[str, set[str]] = defaultdict(set)
    for f in root.glob("*.c"):
        stem = f.stem
        addr = stem.split("_")[-1].lower()
        caller = addr_names.get(addr, stem)
        try:
            text = f.read_text(encoding="utf-8", errors="replace")
        except Exception:
            continue
        for name in set(CALL_RE.findall(text)):
            if name in SKIP or name == caller:
                continue
            if re.fullmatch(r"FUN_[0-9a-f]{8}", name) or re.fullmatch(
                    r"(CTcl\w+|C3DDB__\w+|TclCmd_\w+|CAct\w*|CObj\w*|CMap\w*|"
                    r"CFogOfWar\w*|CProdPlanner\w*|CModelRenderer\w*|CPlaceFinder\w*|"
                    r"CFightActionMgr\w*|CStoryMgr\w*|ViWin\w*)", name):
                callers[name].add(caller)

    # bucket each unnamed function by its named callers
    buckets: dict[str, set[str]] = defaultdict(set)
    for callee, cs in callers.items():
        if not callee.startswith("FUN_"):
            continue
        for c in cs:
            if not c.startswith("FUN_"):
                buckets[c].add(callee)

    out = ["named_caller\tunnamed_callees\tcount"]
    for named in sorted(buckets, key=lambda k: -len(buckets[k])):
        out.append(f"{named}\t{len(buckets[named])}\t" + " ".join(sorted(buckets[named])))
    out_path.write_text("\n".join(out) + "\n", encoding="utf-8")

    total = len({c for s in buckets.values() for c in s})
    print(f"# named functions with unnamed callees: {len(buckets)}")
    print(f"# distinct unnamed functions attributed: {total}")
    print(f"# written: {out_path}")
    print()
    for named in sorted(buckets, key=lambda k: -len(buckets[k]))[:15]:
        print(f"{len(buckets[named]):4d}  {named}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
