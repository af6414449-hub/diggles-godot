#!/usr/bin/env python3
"""Extract the engine's own symbol strings from Diggles.exe.

MSVC assert/trace macros in the original engine embed the failing function's
signature, e.g. "TCL:CTclGlobalMethods::IRandom()" or
"C3DDB::Persist(CUniArc& arc) Materials". Those strings survive into the
release binary, so the original class and method names can be recovered
without a decompiler.

The script groups the strings by class and prints a structured inventory:
  * assert/trace strings with "Class::method"
  * Tcl glue strings with the "TCL:" prefix
  * everything else that looks like a symbol

Usage: python engine_symbols.py <path-to-exe> [--out symbols.tsv]
"""
from __future__ import annotations

import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections, file_off_to_va  # noqa: E402

ASCII_RE = re.compile(rb"[\x20-\x7e]{6,}")
SYM_RE = re.compile(r"^(?:(?P<prefix>[A-Z]{2,5}):)?"
                    r"(?P<cls>[A-Za-z_][A-Za-z0-9_]*)::"
                    r"(?P<rest>.+)$")


def main() -> int:
    path = Path(sys.argv[1])
    out_path = None
    if "--out" in sys.argv:
        out_path = Path(sys.argv[sys.argv.index("--out") + 1])

    data = path.read_bytes()
    sections, image_base = parse_sections(data)

    by_class: dict[str, set[str]] = defaultdict(set)
    tcl_glue: dict[str, set[str]] = defaultdict(set)
    rows = []
    for m in ASCII_RE.finditer(data):
        s = m.group(0).decode("latin-1")
        if "::" not in s:
            continue
        va = file_off_to_va(m.start(), sections, image_base)
        vas = f"0x{va:08X}" if va is not None else ""
        head = s.split("::")[0]
        mm = SYM_RE.match(s)
        if not mm:
            continue
        cls = mm.group("cls")
        rest = mm.group("rest")
        method = rest.split("(")[0].strip()
        prefix = mm.group("prefix")
        rows.append((prefix or "", cls, method, s, vas))
        if prefix == "TCL":
            tcl_glue[cls].add(method)
        else:
            by_class[cls].add(method)

    print(f"# symbol strings with '::': {len(rows)}")
    print(f"# classes: {len(by_class) + len(tcl_glue)}")
    print(f"# Tcl glue classes: {len(tcl_glue)}, their methods: {sum(len(v) for v in tcl_glue.values())}")
    print()
    print("## Tcl glue (CTcl*) — the native command surface")
    for cls in sorted(tcl_glue):
        print(f"  {cls}: {', '.join(sorted(tcl_glue[cls]))}")
    print()
    print("## engine classes with named methods")
    for cls in sorted(by_class):
        print(f"  {cls}: {', '.join(sorted(by_class[cls]))}")

    if out_path:
        lines = ["prefix\tclass\tmethod\tva\ttext"]
        for prefix, cls, method, text, va in rows:
            lines.append(f"{prefix}\t{cls}\t{method}\t{va}\t{text}")
        out_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
        print(f"\n# written: {out_path}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
