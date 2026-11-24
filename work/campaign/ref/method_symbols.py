#!/usr/bin/env python3
"""Map the engine's embedded symbol strings to the functions that use them.

The original engine logs assert/trace messages that embed the failing
function signature ("TCL:CTclGlobalMethods::IRandom()"). The message string
lives in .rdata and is pushed onto the stack right before the assert fires,
so the code that references it sits inside that method.

Procedure:
  1. find the string -> its VA;
  2. scan .text for "push <string VA>" (68 xx xx xx xx);
  3. walk backwards from the reference to the nearest MSVC prologue
     ("push ebp; mov ebp, esp" = 55 8B EC) -> function start.

Result: class::method -> function address, ready to be cross-referenced with
the Tcl command registry.

Usage: python method_symbols.py <path-to-exe> [--out map.tsv]
"""
from __future__ import annotations

import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections, va_to_file_off, file_off_to_va  # noqa: E402

ASCII_RE = re.compile(rb"[\x20-\x7e]{6,}")
SYM_RE = re.compile(r"^(?P<prefix>[A-Z]{2,5}:)?(?P<cls>[A-Za-z_][A-Za-z0-9_]*)::(?P<rest>.+)$")
PROLOGUE = b"\x55\x8B\xEC"  # push ebp; mov ebp, esp


def main() -> int:
    path = Path(sys.argv[1])
    out_path = None
    if "--out" in sys.argv:
        out_path = Path(sys.argv[sys.argv.index("--out") + 1])

    data = path.read_bytes()
    sections, image_base = parse_sections(data)
    text = next(s for s in sections if s["name"] == ".text")
    t_off = text["raw_ptr"]
    t_size = text["raw_size"]
    t_va = image_base + text["va"]
    t_blob = data[t_off:t_off + t_size]

    rows = []
    for m in ASCII_RE.finditer(data):
        s = m.group(0).decode("latin-1")
        if "::" not in s:
            continue
        mm = SYM_RE.match(s)
        if not mm:
            continue
        cls = mm.group("cls")
        method = mm.group("rest").split("(")[0].strip()
        prefix = (mm.group("prefix") or "").rstrip(":")
        sva = file_off_to_va(m.start(), sections, image_base)
        if sva is None:
            continue
        # look for push <sva>
        needle = b"\x68" + struct.pack("<I", sva)
        start = 0
        while True:
            i = t_blob.find(needle, start)
            if i < 0:
                break
            start = i + 1
            ref_va = t_va + i
            # walk back to the nearest prologue
            j = t_blob.rfind(PROLOGUE, 0, i)
            func_va = t_va + j if j >= 0 else None
            rows.append((prefix, cls, method, sva, ref_va, func_va, s))

    print(f"# symbol strings: {len(rows)}")
    mapped = [r for r in rows if r[5] is not None]
    print(f"# with a resolved function start: {len(mapped)}")
    print()
    for prefix, cls, method, sva, ref_va, func_va, text_s in mapped[:200]:
        print(f"{prefix:5s} {cls}::{method:38s} func=0x{func_va:08X} str=0x{sva:08X}")

    if out_path:
        lines = ["prefix\tclass\tmethod\tfunc_va\tref_va\tstr_va\ttext"]
        for prefix, cls, method, sva, ref_va, func_va, s in rows:
            lines.append(f"{prefix}\t{cls}\t{method}\t"
                         f"{'0x%08X' % func_va if func_va else ''}\t"
                         f"0x{ref_va:08X}\t0x{sva:08X}\t{s}")
        out_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
        print(f"# written: {out_path}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
