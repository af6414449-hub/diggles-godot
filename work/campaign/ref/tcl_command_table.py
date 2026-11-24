#!/usr/bin/env python3
"""Build the definitive native Tcl command table from the decompiled code.

The engine registers native commands in two shapes.

Shape A - the name is a literal handed to the std::string constructor:

    FUN_006b8fb0("ai_getownerid");
    Tcl_CreateObjCommand(interp, piVar3 + 3, TclCmd_ai_getownerid);

Shape B - the name is assembled from 32-bit immediates into the small
string buffer of a std::string, which usually lives in a second variable
("piVar4 = piVar3 + 3"), so one name can be written through two variables:

    piVar4[0] = 0x73616c63;      // "clas"
    piVar4[1] = 0x696c5f73;      // "s_li"
    piVar3[5] = 0x746867;        // "ght"   -> "class_light"
    Tcl_CreateObjCommand(interp, piVar4, CTclObjMethods__ChangeLight);

The script walks each decompiled function linearly, accumulating the constant
writes of the current registration block and decoding them when the
registration call is reached.

Result: tcl_command <TAB> handler_function <TAB> handler_file - the native
API surface of the engine, proven from the code.

Usage: python tcl_command_table.py <decomp-dir> [--out table.tsv]
"""
from __future__ import annotations

import re
import struct
import sys
from pathlib import Path

CALL_RE = re.compile(r"Tcl_CreateObjCommand\s*\(")
ASSIGN_RE = re.compile(r"^\s*([A-Za-z_]\w*)\[(\d+)\]\s*=\s*(0x[0-9a-fA-F]+|\d+)\s*;")
# *(undefinedN *)(var + k) = imm      -> N bytes at byte offset 4*k
PTR_RE = re.compile(r"^\s*\*\(undefined(\d)\s*\*\)\s*\(\s*([A-Za-z_]\w*)\s*\+\s*(\d+)\s*\)\s*=\s*"
                    r"(0x[0-9a-fA-F]+|\d+)\s*;")
# *(undefinedN *)((int)var + k) = imm -> N bytes at byte offset k
PTR2_RE = re.compile(r"^\s*\*\(undefined(\d)\s*\*\)\s*\(\s*\(\s*int\s*\)\s*([A-Za-z_]\w*)\s*\+\s*"
                     r"(0x[0-9a-fA-F]+|\d+)\s*\)\s*\)\s*=\s*(0x[0-9a-fA-F]+|\d+)\s*;")
REL_RE = re.compile(r"^\s*([A-Za-z_]\w*)\s*=\s*([A-Za-z_]\w*)\s*\+\s*(\d+)\s*;")
LITERAL_RE = re.compile(r'FUN_006b8fb0\("([^"]*)"\)')
# table entry: FUN_006bbcd0(&local_14, CTclGlobalMethods__SetView);
ENTRY_RE = re.compile(r"FUN_006bbcd0\s*\(\s*&?\w+\s*,\s*([A-Za-z_]\w*)\s*\)")


def split_args(text: str) -> list[str]:
    """Split a call argument list on top-level commas."""
    out, depth, cur = [], 0, ""
    for ch in text:
        if ch in "([":
            depth += 1
        elif ch in ")]":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
            continue
        cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def printable(name: str) -> bool:
    return bool(name) and all(c.isalnum() or c in "_." for c in name) and not name[0].isdigit()


def main() -> int:
    root = Path(sys.argv[1])
    out_path = Path(sys.argv[sys.argv.index("--out") + 1]) if "--out" in sys.argv \
        else Path(__file__).resolve().parent / "tcl_command_table.tsv"

    rows: list[tuple[str, str, str]] = []
    for f in sorted(root.glob("*.c")):
        try:
            lines = f.read_text(encoding="utf-8", errors="replace").splitlines()
        except Exception:
            continue
        rel: dict[str, tuple[str, int]] = {}
        pending: list[tuple[str, int, bytes]] = []   # (var, byte offset, bytes)
        last_literal = ""

        for line in lines:
            r = REL_RE.match(line)
            if r:
                rel[r.group(1)] = (r.group(2), int(r.group(3)))
                continue
            a = ASSIGN_RE.match(line)
            if a:
                val = int(a.group(3), 0) & 0xFFFFFFFF
                pending.append((a.group(1), int(a.group(2)) * 4, struct.pack("<I", val)))
                continue
            p2 = PTR2_RE.match(line)
            if p2:
                size = int(p2.group(1))
                val = int(p2.group(4), 0)
                pending.append((p2.group(2), int(p2.group(3), 0),
                                val.to_bytes(size, "little")))
                continue
            p1 = PTR_RE.match(line)
            if p1:
                size = int(p1.group(1))
                val = int(p1.group(4), 0)
                pending.append((p1.group(2), int(p1.group(3)) * 4,
                                val.to_bytes(size, "little")))
                continue
            lm = LITERAL_RE.search(line)
            if lm:
                last_literal = lm.group(1)
                continue
            # shape C: the table entry is appended right after the literal
            em = ENTRY_RE.search(line)
            if em:
                if last_literal and printable(last_literal):
                    rows.append((last_literal, em.group(1), f.name))
                last_literal = ""
                pending.clear()
                continue
            if "Tcl_CreateObjCommand" not in line:
                continue

            m = CALL_RE.search(line)
            if not m:
                continue
            # take the argument list of this call (balanced parentheses)
            start = m.end()
            depth = 1
            i = start
            while i < len(line) and depth > 0:
                if line[i] == "(":
                    depth += 1
                elif line[i] == ")":
                    depth -= 1
                i += 1
            parts = split_args(line[start:i - 1])
            handler = parts[-1].rstrip(")") if parts else ""
            name_buf = parts[1] if len(parts) > 2 else None

            name = ""
            if last_literal and printable(last_literal):
                name = last_literal
            elif name_buf:
                base_var, delta = rel.get(name_buf, (name_buf, 0))
                shift = delta * 4
                writes: list[tuple[int, bytes]] = []
                name_offs: list[int] = []
                for var, off, raw in pending:
                    if var == name_buf:
                        writes.append((off + shift, raw))
                        name_offs.append(off + shift)
                    elif var == base_var:
                        writes.append((off, raw))
                if name_offs:
                    start = min(name_offs)
                    mem: dict[int, int] = {}
                    for off, raw in writes:
                        if off < start:
                            continue
                        for k, b in enumerate(raw):
                            mem[off + k] = b
                    blob = bytearray()
                    for off in sorted(mem):
                        blob.append(mem[off])
                    z = blob.find(b"\x00")
                    if z >= 0:
                        blob = blob[:z]
                    cand = blob.decode("latin-1", "replace")
                    if printable(cand):
                        name = cand

            pending.clear()
            last_literal = ""
            if not name:
                continue
            rows.append((name, handler, f.name))

    seen: dict[str, tuple[str, str]] = {}
    for name, handler, fname in rows:
        seen.setdefault(name, (handler, fname))

    out = ["tcl_command\thandler_function\thandler_file"]
    for name in sorted(seen):
        handler, fname = seen[name]
        out.append(f"{name}\t{handler}\t{fname}")
    out_path.write_text("\n".join(out) + "\n", encoding="utf-8")

    print(f"# registrations parsed: {len(rows)}, unique commands: {len(seen)}")
    print(f"# written: {out_path}")
    print()
    for name in sorted(seen):
        print(f"{name:34s} -> {seen[name][0]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
