#!/usr/bin/env python3
"""Recover the class -> vtable map of Diggles.exe from MSVC RTTI.

MSVC x86 layout:

    TypeDescriptor   [pVFTable][spare][name ".?AVCAct@@"]
    CompleteObjectLocator [sig][offset][cdOffset][pTypeDescriptor][pClassHierarchy]
    vftable          immediately after the COL: [fn0][fn1][fn2]...

The COL is referenced from the vftable, so scanning .rdata for pointers to a
TypeDescriptor gives the COL address, and COL+8 is the vftable. The vftable
entries are consecutive code pointers, which yields the virtual method slots
of every class.

Names for the slots are taken from the engine's own assert strings
(method_map.tsv), so a slot can be labelled with the original method name
when the method is known to carry an assert string.

Usage: python rtti_vtables.py <path-to-exe> [--map method_map.tsv] [--out vtables.tsv]
"""
from __future__ import annotations

import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections, va_to_file_off, file_off_to_va  # noqa: E402

RTTI_RE = re.compile(rb"\.\?AV([A-Za-z_][A-Za-z0-9_]*)@@\x00")


def load_names(map_path: Path) -> dict[int, str]:
    names: dict[int, str] = {}
    if not map_path.exists():
        return names
    for line in map_path.read_text(encoding="utf-8").splitlines()[1:]:
        p = line.split("\t")
        if len(p) < 4 or not p[3]:
            continue
        try:
            va = int(p[3], 16)
        except ValueError:
            continue
        names.setdefault(va, f"{p[1].strip()}::{p[2].strip()}")
    return names


def main() -> int:
    path = Path(sys.argv[1])
    map_path = Path(sys.argv[sys.argv.index("--map") + 1]) if "--map" in sys.argv \
        else Path(__file__).resolve().parent / "method_map.tsv"
    out_path = Path(sys.argv[sys.argv.index("--out") + 1]) if "--out" in sys.argv \
        else Path(__file__).resolve().parent / "rtti_vtables.tsv"
    names = load_names(map_path)

    data = path.read_bytes()
    sections, image_base = parse_sections(data)
    rdata = next((s for s in sections if s["name"] == ".rdata"), None)
    if rdata is None:
        print("no .rdata")
        return 1

    rdata_blob = data[rdata["raw_ptr"]:rdata["raw_ptr"] + rdata["raw_size"]]
    rdata_va = image_base + rdata["va"]

    rows = []
    seen_pairs = set()
    # TypeDescriptors live in .data, the Complete Object Locators in .rdata
    for m in RTTI_RE.finditer(data):
        cls = m.group(1).decode()
        name_va = file_off_to_va(m.start(), sections, image_base)
        if name_va is None:
            continue
        td_va = name_va - 8          # TypeDescriptor starts 8 bytes before the name
        needle = struct.pack("<I", td_va)
        start = 0
        while True:
            i = data.find(needle, start)
            if i < 0:
                break
            start = i + 1
            col_va = file_off_to_va(i, sections, image_base)
            if col_va is None:
                continue
            col_va -= 12             # pTypeDescriptor is the 4th field of the COL
            # The vftable lies *before* the COL: the slot right in front of
            # vftable[0] holds the COL address itself.
            vft_va = None
            selfneedle = struct.pack("<I", col_va)
            j = data.find(selfneedle)
            while j >= 0:
                slot_va = file_off_to_va(j, sections, image_base)
                if slot_va is not None:
                    cand = slot_va + 4
                    off0 = va_to_file_off(cand, sections, image_base)
                    if off0 is not None:
                        fn0 = struct.unpack_from("<I", data, off0)[0]
                        fo = va_to_file_off(fn0, sections, image_base)
                        if fo is not None and any(
                                s["name"] == ".text" and s["raw_ptr"] <= fo < s["raw_ptr"] + s["raw_size"]
                                for s in sections):
                            vft_va = cand
                            break
                j = data.find(selfneedle, j + 1)
            if vft_va is None:
                continue
            if (cls, vft_va) in seen_pairs:
                continue
            seen_pairs.add((cls, vft_va))
            # read vftable entries
            slots = []
            for k in range(64):
                off = va_to_file_off(vft_va + 4 * k, sections, image_base)
                if off is None:
                    break
                fn = struct.unpack_from("<I", data, off)[0]
                # must look like a code pointer
                fo = va_to_file_off(fn, sections, image_base)
                if fo is None:
                    break
                in_code = any(s["name"] == ".text" and s["raw_ptr"] <= fo < s["raw_ptr"] + s["raw_size"]
                              for s in sections)
                if not in_code:
                    break
                slots.append(fn)
            if len(slots) >= 1:
                rows.append((cls, vft_va, slots))

    out = ["class\tvftable_va\tnum_slots\tslots"]
    for cls, vft, slots in sorted(rows, key=lambda r: r[0]):
        labelled = []
        for fn in slots:
            lbl = names.get(fn, "")
            labelled.append(f"0x{fn:08X}" + (f":{lbl}" if lbl else ""))
        out.append(f"{cls}\t0x{vft:08X}\t{len(slots)}\t" + " ".join(labelled))
    out_path.write_text("\n".join(out) + "\n", encoding="utf-8")

    print(f"# classes with a vtable: {len(rows)}")
    print(f"# written: {out_path}")
    print()
    for cls, vft, slots in sorted(rows, key=lambda r: -len(r[2]))[:15]:
        print(f"{cls:24s} vftable=0x{vft:08X} slots={len(slots):3d}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
