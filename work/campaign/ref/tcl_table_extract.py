#!/usr/bin/env python3
"""Extract the engine's native Tcl command table from the static pair table.

Most native commands are not registered one by one. The engine keeps a
static table of pairs

    { std::string* name, void (*proc)(...) }

and loops over it:

    for (i = 0; i < count; i++) {
        Tcl_CreateObjCommand(interp,
            *(int *)(table + i * 8) + 0xc,          // name: SSO buffer
            *(undefined4 *)(table + i * 8 + 4));     // handler
    }

This script finds such tables directly in the image: a run of 8-byte pairs
whose first element points at a std::string object in .data/.rdata and whose
second element points into .text. The name is read from the string object
(+0xC for the small-string buffer, or the heap pointer for long names).

Usage: python tcl_table_extract.py <path-to-exe> [--out table.tsv]
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections, va_to_file_off, file_off_to_va  # noqa: E402


def read_std_string(data: bytes, sections, image_base: int, obj_va: int) -> str | None:
    """Read a MSVC std::string object at obj_va and return its contents."""
    off = va_to_file_off(obj_va, sections, image_base)
    if off is None or off + 16 > len(data):
        return None
    flags_or_ptr, capacity = struct.unpack_from("<II", data, off)
    size = struct.unpack_from("<I", data, off + 8)[0]
    if capacity == 0 or capacity > 0x10000 or size > 0x10000:
        return None
    if capacity <= 15:                       # small string: inline buffer
        buf_off = off + 12
    else:                                   # long string: heap pointer
        buf_off = va_to_file_off(flags_or_ptr, sections, image_base)
        if buf_off is None:
            return None
    if buf_off + size > len(data):
        return None
    raw = data[buf_off:buf_off + size]
    try:
        s = raw.decode("latin-1")
    except Exception:
        return None
    return s


def main() -> int:
    path = Path(sys.argv[1])
    out_path = Path(sys.argv[sys.argv.index("--out") + 1]) if "--out" in sys.argv \
        else Path(__file__).resolve().parent / "tcl_command_table_full.tsv"
    data = path.read_bytes()
    sections, image_base = parse_sections(data)

    data_secs = [s for s in sections if s["name"] in (".data", ".rdata")]
    text = next(s for s in sections if s["name"] == ".text")
    t_lo = image_base + text["va"]
    t_hi = t_lo + max(text["vsize"], text["raw_size"])

    rows: dict[str, int] = {}
    for sec in data_secs:
        blob = data[sec["raw_ptr"]:sec["raw_ptr"] + sec["raw_size"]]
        sec_va = image_base + sec["va"]
        i = 0
        n = len(blob)
        while i + 8 <= n:
            name_ptr, proc = struct.unpack_from("<II", blob, i)
            # quick filter: handler must be a code pointer
            if not (t_lo <= proc < t_hi):
                i += 4
                continue
            # name object must live in a data section
            name_obj = None
            for s in data_secs:
                lo = image_base + s["va"]
                hi = lo + max(s["vsize"], s["raw_size"])
                if lo <= name_ptr < hi:
                    name_obj = name_ptr
                    break
            if name_obj is None:
                i += 4
                continue
            name = read_std_string(data, sections, image_base, name_obj)
            if name and name and all(32 <= ord(c) < 127 for c in name) and name[0].isalpha():
                rows.setdefault(name, proc)
            i += 4

    out = ["tcl_command\thandler_va"]
    for name in sorted(rows):
        out.append(f"{name}\t0x{rows[name]:08X}")
    out_path.write_text("\n".join(out) + "\n", encoding="utf-8")

    print(f"# commands from the static table: {len(rows)}")
    print(f"# written: {out_path}")
    print()
    for name in sorted(rows)[:40]:
        print(f"{name:36s} 0x{rows[name]:08X}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
