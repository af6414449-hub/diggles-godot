#!/usr/bin/env python3
"""Diagnose native Tcl registration call sites: show the pushes and the code
around each call to Tcl_CreateObjCommand, so the argument pattern can be seen.

Usage: python tcl_reg_diag.py <path-to-exe> [count] [--va 0x...]
"""
from __future__ import annotations

import bisect
import struct
import sys
from pathlib import Path

from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_OP_REG

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections, va_to_file_off, read_cstr  # noqa: E402
from exe_map import import_map, section_name, cstr_at  # noqa: E402


def main() -> int:
    path = Path(sys.argv[1])
    limit = int(sys.argv[2]) if len(sys.argv) > 2 and not sys.argv[2].startswith("--") else 6
    only = None
    if "--va" in sys.argv:
        only = int(sys.argv[sys.argv.index("--va") + 1], 0)

    data = path.read_bytes()
    sections, image_base = parse_sections(data)
    imps = import_map(data, sections, image_base)
    reg_slots = {va: n for va, n in imps.items() if "CreateObjCommand" in n}

    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = True
    text = next(s for s in sections if s["name"] == ".text")
    blob = data[text["raw_ptr"]:text["raw_ptr"] + text["raw_size"]]
    t_va = image_base + text["va"]
    mv = memoryview(blob)

    pushes: list[tuple[int, int]] = []
    calls: list[int] = []
    off = 0
    while off < len(blob):
        last = off
        for ins in md.disasm(mv[off:], t_va + off):
            last = ins.address + ins.size - t_va
            if ins.mnemonic == "push" and len(ins.operands) == 1 and ins.operands[0].type == X86_OP_IMM:
                pushes.append((ins.address, ins.operands[0].imm & 0xFFFFFFFF))
            elif ins.mnemonic == "call" and len(ins.operands) == 1:
                op = ins.operands[0]
                if op.type == X86_OP_MEM:
                    m = op.mem
                    if m.base == 0 and m.index == 0 and m.disp in reg_slots:
                        calls.append(ins.address)
        off = last if last > off else off + 1

    push_addrs = [a for a, _ in pushes]
    push_vals = [v for _, v in pushes]
    print(f"# calls: {len(calls)}")

    shown = 0
    for call_va in calls:
        if only and call_va != only:
            continue
        lo = bisect.bisect_left(push_addrs, call_va - 48)
        hi = bisect.bisect_left(push_addrs, call_va)
        print(f"\n=== call at 0x{call_va:08X} ===")
        for k in range(hi - 1, lo - 1, -1):
            v = push_vals[k]
            sec = section_name(sections, v, image_base)
            s = cstr_at(data, sections, image_base, v)
            desc = s if s else ""
            print(f"   push 0x{v:08X}  {sec or '-':8s} {desc}")
        start = call_va - 48
        off_in = start - t_va
        for ins in md.disasm(mv[off_in:off_in + 64], start):
            mark = "  <<<" if ins.address == call_va else ""
            print(f"   0x{ins.address:08X}: {ins.mnemonic:8s} {ins.op_str}{mark}")
        shown += 1
        if shown >= limit:
            break
    return 0


if __name__ == "__main__":
    sys.exit(main())
