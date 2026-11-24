#!/usr/bin/env python3
"""Prepare the data for the Ghidra structure pass.

Outputs (into the ref dir, consumed by ApplyStructs.java):
  ghidra_structs.tsv  class <TAB> offset <TAB> field <TAB> type
  ghidra_funcs.tsv    0xADDRESS <TAB> class

The type names are Ghidra data type names: int, float, double, char, short,
undefined4 (dword), void* (pointer). Field offsets come from the inferred
layout (infer_structs.py), the function list from the vtable slots and the
engine's assert strings.

Usage: python prepare_ghidra_structs.py <ref-dir>
"""
from __future__ import annotations

import re
import sys
from collections import defaultdict
from pathlib import Path

PREFIX_TYPE = {
    "i": "int",
    "s": "short",
    "f": "float",
    "d": "double",
    "c": "char",
    "p": "void *",
    "q": "long long",
}


def main() -> int:
    ref = Path(sys.argv[1])
    layouts = ref / "struct_layouts.tsv"
    funcs = ref / "ghidra_funcs.tsv"

    # classes -> {offset: (field, type)}
    out_lines = ["class\toffset\tfield\ttype"]
    for line in layouts.read_text(encoding="utf-8").splitlines()[1:]:
        p = line.split("\t")
        if len(p) < 4:
            continue
        cls, off, field, types = p[0], p[1], p[2], p[3]
        best = types.split(",")[0].split(":")[0]
        tname = PREFIX_TYPE.get(best, "int")
        out_lines.append(f"{cls}\t{off}\t{field}\t{tname}")
    funcs.parent.mkdir(parents=True, exist_ok=True)
    layouts.with_name("ghidra_structs.tsv").write_text("\n".join(out_lines) + "\n", encoding="utf-8")
    print(f"# structures: {len(out_lines) - 1} field slots "
          f"({len({l.split(chr(9))[0] for l in out_lines[1:]})} classes)")

    # functions -> class
    owner: dict[str, str] = {}
    vt = ref / "rtti_vtables.tsv"
    if vt.exists():
        for line in vt.read_text(encoding="utf-8").splitlines()[1:]:
            p = line.split("\t")
            if len(p) < 4:
                continue
            for slot in p[3].split():
                m = re.fullmatch(r"0x([0-9A-Fa-f]{8})", slot.split(":")[0])
                if m:
                    owner.setdefault(m.group(1).lower(), p[0])
    mm = ref / "method_map.tsv"
    if mm.exists():
        for line in mm.read_text(encoding="utf-8").splitlines()[1:]:
            p = line.split("\t")
            if len(p) < 4 or not p[3]:
                continue
            owner.setdefault(p[3].replace("0x", "").lower(), p[1].strip())

    flines = ["address\tclass"]
    for addr, cls in sorted(owner.items()):
        flines.append(f"0x{addr}\t{cls}")
    funcs.write_text("\n".join(flines) + "\n", encoding="utf-8")
    print(f"# functions with a known class: {len(flines) - 1}")
    print(f"# written: {layouts.with_name('ghidra_structs.tsv')}")
    print(f"# written: {funcs}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
