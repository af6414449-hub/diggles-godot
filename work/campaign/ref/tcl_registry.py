#!/usr/bin/env python3
"""Recover the native Tcl command registry of Diggles.exe.

The engine exposes hundreds of native commands to the Tcl scripts
(map_create, set_view, sm_draw_stone, generate_color_variation, ...).
They are registered through Tcl_CreateObjCommand from tcl83.dll, so the
registry can be rebuilt without a decompiler:

  1. map the IAT -> "dll!name";
  2. find every indirect call to the registration function;
  3. for each call site, look back through the preceding push-immediates
     for the command-name string (in .rdata) and the proc pointer (in .text).

Result: a table "tcl command -> native handler VA", which is the exact
interface between the original Tcl scripts and the C++ engine.

Usage: python tcl_registry.py <path-to-exe> [--out table.tsv]
"""
from __future__ import annotations

import bisect
import struct
import sys
from pathlib import Path

from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_OP_REG

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections, va_to_file_off, file_off_to_va, read_cstr  # noqa: E402


def import_map(data: bytes, sections, image_base) -> dict[int, str]:
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    opt = pe + 24
    magic = struct.unpack_from("<H", data, opt)[0]
    ddoff = opt + (112 if magic == 0x20B else 96)
    impva, _ = struct.unpack_from("<II", data, ddoff + 8)
    result: dict[int, str] = {}
    off = va_to_file_off(image_base + impva, sections, image_base)
    if off is None:
        return result
    while True:
        ilt, ts, fc, nm, fta = struct.unpack_from("<IIIII", data, off)
        if nm == 0:
            break
        no = va_to_file_off(image_base + nm, sections, image_base)
        dll = read_cstr(data, no) if no is not None else "?"
        thunk_rva = ilt if ilt else fta
        t = va_to_file_off(image_base + thunk_rva, sections, image_base)
        if t is None:
            off += 20
            continue
        step = 8 if magic == 0x20B else 4
        iat_rva = fta
        while True:
            v = struct.unpack_from("<Q" if magic == 0x20B else "<I", data, t)[0]
            if v == 0:
                break
            if not (v & (1 << 63)):
                ho = va_to_file_off(image_base + v, sections, image_base)
                if ho is not None:
                    result[image_base + iat_rva] = f"{dll}!{read_cstr(data, ho + 2)}"
            iat_rva += step
            t += step
        off += 20
    return result


def is_text(sections, va: int, image_base: int) -> bool:
    rva = va - image_base
    for s in sections:
        if s["name"] == ".text" and s["va"] <= rva < s["va"] + max(s["vsize"], s["raw_size"]):
            return True
    return False


def cstr_at(data: bytes, sections, image_base: int, va: int, maxlen: int = 96) -> str | None:
    off = va_to_file_off(va, sections, image_base)
    if off is None or off >= len(data):
        return None
    txt = read_cstr(data, off)
    if not txt or len(txt) > maxlen:
        return None
    if not all(32 <= ord(c) < 127 for c in txt):
        return None
    return txt


def main() -> int:
    path = Path(sys.argv[1])
    out_path = None
    if "--out" in sys.argv:
        out_path = Path(sys.argv[sys.argv.index("--out") + 1])

    data = path.read_bytes()
    sections, image_base = parse_sections(data)
    imps = import_map(data, sections, image_base)

    reg_slots = {
        va: name for va, name in imps.items()
        if "CreateObjCommand" in name or name.endswith("!Tcl_CreateCommand")
    }
    print(f"# registration slots: {[(hex(k), v) for k, v in reg_slots.items()]}")
    if not reg_slots:
        print("no Tcl_Create*Command import found")
        return 1

    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = True
    text = next(s for s in sections if s["name"] == ".text")
    blob = data[text["raw_ptr"]:text["raw_ptr"] + text["raw_size"]]
    va_base = image_base + text["va"]
    mv = memoryview(blob)

    push_addrs: list[int] = []
    push_vals: list[int] = []
    call_sites: list[tuple[int, int]] = []
    reg_iat: dict[int, int] = {}

    off = 0
    total = len(blob)
    while off < total:
        last = off
        for ins in md.disasm(mv[off:], va_base + off):
            last = ins.address + ins.size - va_base
            ops = ins.operands
            if ins.mnemonic == "push" and len(ops) == 1 and ops[0].type == X86_OP_IMM:
                push_addrs.append(ins.address)
                push_vals.append(ops[0].imm & 0xFFFFFFFF)
            elif ins.mnemonic == "mov" and len(ops) == 2 and ops[0].type == X86_OP_REG \
                    and ops[1].type == X86_OP_MEM:
                m = ops[1].mem
                if m.base == 0 and m.index == 0 and m.disp in reg_slots:
                    reg_iat[ops[0].reg] = m.disp
            elif ins.mnemonic == "call" and len(ops) == 1:
                if ops[0].type == X86_OP_MEM:
                    m = ops[0].mem
                    if m.base == 0 and m.index == 0 and m.disp in reg_slots:
                        call_sites.append((ins.address, m.disp))
                elif ops[0].type == X86_OP_REG and ops[0].reg in reg_iat:
                    call_sites.append((ins.address, reg_iat[ops[0].reg]))
        off = last if last > off else off + 1

    print(f"# pushes: {len(push_vals)}, registration call sites: {len(call_sites)}")

    rows: list[tuple[str, int, int]] = []
    for call_va, slot in call_sites:
        lo = bisect.bisect_left(push_addrs, call_va - 80)
        hi = bisect.bisect_left(push_addrs, call_va)
        name_str = None
        handler = None
        for k in range(hi - 1, lo - 1, -1):
            v = push_vals[k]
            if name_str is None:
                s = cstr_at(data, sections, image_base, v)
                if s and all(c.isalnum() or c in "_." for c in s) and not s[0].isdigit():
                    name_str = s
                    continue
            elif is_text(sections, v, image_base):
                handler = v
                break
        if name_str and handler:
            rows.append((name_str, handler, call_va))

    seen: dict[str, tuple[int, int]] = {}
    for name, handler, call_va in rows:
        if name not in seen:
            seen[name] = (handler, call_va)

    print(f"# recovered {len(seen)} native Tcl commands")
    lines = ["# native Tcl commands of Diggles.exe: name<TAB>handler_va<TAB>call_site"]
    for name in sorted(seen):
        handler, call_va = seen[name]
        lines.append(f"{name}\t0x{handler:08X}\t0x{call_va:08X}")
        print(f"{name:32s} 0x{handler:08X}")
    if out_path:
        out_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
        print(f"# written: {out_path}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
