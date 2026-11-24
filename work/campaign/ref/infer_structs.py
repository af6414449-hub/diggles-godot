#!/usr/bin/env python3
"""Infer per-class field layouts from the decompiled code and annotate it.

Ghidra does not know the members of the original C++ classes (there is no
PDB), so the dump shows raw accesses:

    *(int *)(in_ECX + 0xc)        // this->field at 0x0C
    *(double *)(in_ECX + 0x40)    // this->field at 0x40

The `this` pointer lives in ECX (MSVC thiscall). This script:

  1. collects every field access per function;
  2. attributes the function to its class - via the vtable slot map
     (rtti_vtables.tsv) or via the engine's own assert strings
     (method_map.tsv, "Class::method");
  3. aggregates the offsets into a field layout per class
     (struct_layouts.tsv);
  4. writes an annotated copy of the decompiled code where the raw accesses
     become this->i_2c / this->d_40 / this->p_1c.

The raw Ghidra dump stays authoritative; the annotated copy is for reading.

Usage: python infer_structs.py <decomp-dir> <ref-dir> [--out decomp_typed]
"""
from __future__ import annotations

import re
import sys
from collections import defaultdict
from pathlib import Path

ACCESS_RE = re.compile(
    r"\*\((?:const\s+)?(\w+)\s*\*\)\s*\(\s*in_ECX\s*\+\s*(0x[0-9a-fA-F]+|\d+)\s*\)")

TYPE_PREFIX = {
    "int": "i", "long": "i", "uint": "i", "undefined4": "i", "unsignedint": "i",
    "short": "s", "word": "s", "unsignedshort": "s",
    "float": "f", "double": "d",
    "char": "c", "bool": "c", "undefined1": "c", "byte": "c",
    "undefined2": "s",
    "undefined8": "q", "longlong": "q",
}


def prefix_for(t: str) -> str:
    t = t.strip()
    if t.endswith("*") or t in ("void", "undefined"):
        return "p"
    return TYPE_PREFIX.get(t, "p")


def load_class_maps(ref: Path) -> dict[str, str]:
    """function address -> owning class."""
    owner: dict[str, str] = {}
    vt = ref / "rtti_vtables.tsv"
    if vt.exists():
        for line in vt.read_text(encoding="utf-8").splitlines()[1:]:
            p = line.split("\t")
            if len(p) < 4:
                continue
            cls = p[0]
            for slot in p[3].split():
                if ":" in slot:
                    slot = slot.split(":")[0]
                m = re.fullmatch(r"0x([0-9A-Fa-f]{8})", slot)
                if m:
                    owner.setdefault(m.group(1).lower(), cls)
    mm = ref / "method_map.tsv"
    if mm.exists():
        for line in mm.read_text(encoding="utf-8").splitlines()[1:]:
            p = line.split("\t")
            if len(p) < 4 or not p[3]:
                continue
            owner.setdefault(p[3].replace("0x", "").lower(), p[1].strip())
    return owner


def main() -> int:
    decomp = Path(sys.argv[1])
    ref = Path(sys.argv[2])
    out_dir = Path(sys.argv[sys.argv.index("--out") + 1]) if "--out" in sys.argv \
        else ref / "ghidra-out" / "decomp_typed"

    owner = load_class_maps(ref)
    layout: dict[str, dict[int, dict]] = defaultdict(lambda: defaultdict(dict))
    access_counts: dict[str, dict[int, int]] = defaultdict(lambda: defaultdict(int))
    func_class: dict[str, str] = {}
    func_access: dict[str, list[tuple[int, str]]] = {}

    files = sorted(decomp.glob("*.c"))
    for f in files:
        addr = f.stem.split("_")[-1].lower()
        try:
            text = f.read_text(encoding="utf-8", errors="replace")
        except Exception:
            continue
        accs = [(int(off, 0), t) for t, off in ACCESS_RE.findall(text)]
        if not accs:
            continue
        cls = owner.get(addr)
        if not cls:
            continue
        func_class[f.stem] = cls
        func_access[f.stem] = accs
        for off, t in accs:
            pref = prefix_for(t)
            cell = layout[cls][off]
            cell[pref] = cell.get(pref, 0) + 1
            access_counts[cls][off] += 1

    # write the layout table
    lines = ["class\toffset\tfield\ttypes_by_count\toffset_accesses"]
    for cls in sorted(layout):
        for off in sorted(layout[cls]):
            cell = layout[cls][off]
            best = max(cell, key=lambda k: cell[k])
            field = f"{best}_{off:02x}"
            types = ",".join(f"{k}:{v}" for k, v in sorted(cell.items(), key=lambda kv: -kv[1]))
            lines.append(f"{cls}\t0x{off:02X}\t{field}\t{types}\t{access_counts[cls][off]}")
    (ref / "struct_layouts.tsv").write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"# classes with inferred layout: {len(layout)}")
    print(f"# field slots: {len(lines) - 1}")
    print(f"# written: {ref / 'struct_layouts.tsv'}")

    # annotate the decompiled code
    out_dir.mkdir(parents=True, exist_ok=True)
    renamed = 0
    for f in files:
        cls = func_class.get(f.stem)
        if not cls:
            continue
        text = f.read_text(encoding="utf-8", errors="replace")

        def repl(m):
            t, off = m.group(1), int(m.group(2), 0)
            pref = prefix_for(t)
            cell = layout[cls].get(off)
            if cell:
                pref = max(cell, key=lambda k: cell[k])
            return f"this->{pref}_{off:02x}"

        new = ACCESS_RE.sub(repl, text)
        if new != text:
            new = new.replace("in_ECX", "this")
            (out_dir / f.name).write_text(new, encoding="utf-8")
            renamed += 1
    print(f"# annotated files written: {renamed} -> {out_dir}")

    print()
    for cls in sorted(layout, key=lambda c: -len(layout[c]))[:12]:
        offs = sorted(layout[cls])
        print(f"{cls:26s} полей: {len(offs):3d}  смещения: "
              + ", ".join(f"{o:#x}" for o in offs[:10]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
