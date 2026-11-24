#!/usr/bin/env python3
"""Cross-check the recovered native command table against the game scripts.

The table (tcl_command_table.tsv) is the engine's native API as recovered
from the decompiled registration code. The scripts of the original game
(tcl_native_candidates.tsv) show which of those commands the game actually
calls. The difference is the "unused" part of the API.

Usage: python tcl_api_vs_scripts.py <ref-dir>
"""
from __future__ import annotations

import sys
from pathlib import Path


def main() -> int:
    ref = Path(sys.argv[1])
    table = ref / "tcl_command_table.tsv"
    vocab = ref / "tcl_native_candidates.tsv"

    api: dict[str, str] = {}
    for line in table.read_text(encoding="utf-8").splitlines()[1:]:
        p = line.split("\t")
        if len(p) >= 2:
            api.setdefault(p[0], p[1])

    used: dict[str, int] = {}
    for line in vocab.read_text(encoding="utf-8").splitlines():
        if line.startswith("#") or not line.strip():
            continue
        p = line.split("\t")
        if len(p) >= 2:
            try:
                used[p[0].strip()] = int(p[1])
            except ValueError:
                pass

    hits = {c: n for c, n in used.items() if c in api}
    unused = sorted(set(api) - set(used))

    out = ref / "tcl_api_usage.tsv"
    lines = ["tcl_command\thandler\tused_in_scripts"]
    for c in sorted(api):
        lines.append(f"{c}\t{api[c]}\t{used.get(c, 0)}")
    out.write_text("\n".join(lines) + "\n", encoding="utf-8")

    print(f"# native commands in the engine: {len(api)}")
    print(f"# of them called by the game scripts: {len(hits)}")
    print(f"# not used by the scripts: {len(unused)}")
    print(f"# written: {out}")
    print()
    print("--- используются игрой (топ-25 по частоте) ---")
    for c, n in sorted(hits.items(), key=lambda kv: -kv[1])[:25]:
        print(f"{n:6d}  {c:32s} -> {api[c]}")
    print()
    print("--- регистрируются движком, но не зовутся скриптами ---")
    for c in unused[:40]:
        print(f"        {c:32s} -> {api[c]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
