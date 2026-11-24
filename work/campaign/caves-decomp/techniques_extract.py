#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Extract the render-technique registry from FUN_00457b90 (Diggles.exe).

Linear scan.  Between two commits we see:
    <state record writes>            -> state fields (int array, 0x6C bytes)
    VAR = FUN_006ba810(0x19)         -> name object
    <name byte writes to VAR>        -> name (dwords / halfwords / bytes)
    FUN_0045aa00(&state)             -> commit  == one technique
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

DEFAULT = Path(r"C:\diggles-ghidra\out\decomp\FUN_00457b90_00457b90.c")

RE_ALLOC = re.compile(r"((?:local_[0-9a-f]+|piVar2))\s*=\s*\(int \*\)FUN_006ba810\(0x19")
RE_FIELD = re.compile(r"((?:local_[0-9a-f]+|piVar2))\[(0x[0-9a-fA-F]+|\d+)\]\s*=\s*([-\w]+);")
RE_LEN = re.compile(r"((?:local_[0-9a-f]+|piVar2))\[2\]\s*=\s*(-?0x[0-9a-fA-F]+|-?\d+);")
RE_WORD = re.compile(r"((?:local_[0-9a-f]+|piVar2))\[(\d+)\]\s*=\s*(0x[0-9a-fA-F]+);")
RE_PWORD = re.compile(r"\*\(undefined4 \*\)\(((?:local_[0-9a-f]+|piVar2)) \+ (\d+)\)\s*=\s*(0x[0-9a-fA-F]+);")
RE_HALF = re.compile(r"\*\(undefined2 \*\)\(((?:local_[0-9a-f]+|piVar2)) \+ (\d+)\)\s*=\s*(0x[0-9a-fA-F]+);")
RE_BYTE = re.compile(r"\*\(undefined1 \*\)\(((?:local_[0-9a-f]+|piVar2)) \+ (\d+)\)\s*=\s*(\d+);")
RE_BYTE2 = re.compile(r"\*\(undefined1 \*\)\(\(int\)((?:local_[0-9a-f]+|piVar2)) \+ (0x[0-9a-fA-F]+)\)\s*=\s*(\d+);")
RE_COMMIT = re.compile(r"FUN_0045aa00\(&((?:local_[0-9a-f]+|piVar2))\)")


def num(tok: str) -> int:
    return int(tok, 16) if tok.startswith("0x") else int(tok)


def printable4(v: int) -> bool:
    return all(0x20 <= c <= 0x7E for c in v.to_bytes(4, "little"))


def main() -> int:
    path = Path(sys.argv[1]) if len(sys.argv) > 1 else DEFAULT
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()

    state: dict[int, int] = {}
    namevar: str | None = None
    collecting = False
    slots: dict[int, bytes] = {}
    nlen = 0
    rows = []

    for ln in lines:
        if not collecting:
            for m in RE_FIELD.finditer(ln):
                state[num(m.group(2))] = num(m.group(3))
        am = RE_ALLOC.search(ln)
        if am:
            namevar = am.group(1)
            collecting = True
            slots = {}
            nlen = 0
            continue
        if collecting:
            for m in RE_LEN.finditer(ln):
                if m.group(1) == namevar and num(m.group(2)) > 0:
                    nlen = num(m.group(2))
            for m in RE_WORD.finditer(ln):
                if m.group(1) == namevar and printable4(num(m.group(3))):
                    slots[int(m.group(2))] = num(m.group(3)).to_bytes(4, "little")
            for m in RE_PWORD.finditer(ln):
                if m.group(1) == namevar and printable4(num(m.group(3))):
                    slots[int(m.group(2)) // 4] = num(m.group(3)).to_bytes(4, "little")
            for m in RE_HALF.finditer(ln):
                if m.group(1) == namevar:
                    slots[int(m.group(2))] = num(m.group(3)).to_bytes(2, "little")
            for m in RE_BYTE.finditer(ln):
                if m.group(1) == namevar:
                    slots[int(m.group(2))] = bytes([num(m.group(3))])
            for m in RE_BYTE2.finditer(ln):
                if m.group(1) == namevar:
                    slots[int(num(m.group(2)) // 4)] = bytes([num(m.group(3))])
        cm = RE_COMMIT.search(ln)
        if cm:
            buf = bytearray()
            for idx in sorted(slots):
                off = (idx - 3) * 4
                if off >= nlen:
                    continue
                buf += slots[idx][: nlen - off]
            name = buf[:nlen].decode("latin-1", errors="replace")
            rows.append((name, nlen, dict(state)))
            state = {}
            collecting = False
            namevar = None

    print(f"techniques: {len(rows)}")
    print("| id | technique | len | st2 | st3 | st7 | st8 | st10 | st11 | st17 |")
    print("|---:|---|---:|---:|---:|---:|---:|---:|---:|---:|")
    for i, (name, nlen, st) in enumerate(rows):
        print(f"| {i} | `{name}` | {nlen} | {st.get(2)} | {st.get(3)} | {st.get(7)} | "
              f"{st.get(8)} | {st.get(10)} | {st.get(11)} | {st.get(17)} |")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
