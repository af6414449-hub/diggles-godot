#!/usr/bin/env python3
"""One-pass analysis of Diggles.exe: native Tcl registry + method map.

Two facts are recovered from the binary itself, without a decompiler:

1. NATIVE TCL REGISTRY — the engine registers its native commands through
   Tcl_CreateObjCommand(tcl83.dll). Each registration call is preceded by
   the pushes of its arguments: deleteProc, clientData, proc, objName, interp.
   Reading the pushes backwards from the call gives the Tcl command name
   (a string in .rdata) and the native handler (a pointer into .text).

2. METHOD MAP — the original engine's assert/trace macros embed the failing
   function's signature ("TCL:CTclGlobalMethods::IRandom()"). Such a string
   is referenced from the code of that very method, so the nearest MSVC
   prologue ("55 8B EC") above the reference is the method's entry point.

Outputs (next to the exe):
  tcl_commands.tsv   name <TAB> handler_va <TAB> call_site_va
  method_map.tsv     prefix <TAB> class <TAB> method <TAB> func_va <TAB> ref_va <TAB> str_va

Usage: python exe_map.py <path-to-exe> [--outdir dir]
"""
from __future__ import annotations

import bisect
import re
import struct
import sys
from pathlib import Path

from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_OP_REG

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections, va_to_file_off, file_off_to_va, read_cstr  # noqa: E402

ASCII_RE = re.compile(rb"[\x20-\x7e]{6,}")
SYM_RE = re.compile(r"^(?P<prefix>[A-Z]{2,5}:)?(?P<cls>[A-Za-z_][A-Za-z0-9_]*)::(?P<rest>.+)$")
PROLOGUE = b"\x55\x8B\xEC"
FUNC_START = (b"\x55\x8B\xEC", b"\x6A\xFF", b"\xCC\x55\x8B\xEC")


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
        thunk = ilt if ilt else fta
        t = va_to_file_off(image_base + thunk, sections, image_base)
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


def section_name(sections, va: int, image_base: int) -> str | None:
    rva = va - image_base
    for s in sections:
        if s["va"] <= rva < s["va"] + max(s["vsize"], s["raw_size"]):
            return s["name"]
    return None


def cstr_at(data, sections, image_base, va, maxlen=96) -> str | None:
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
    outdir = Path(sys.argv[sys.argv.index("--outdir") + 1]) if "--outdir" in sys.argv else path.parent
    data = path.read_bytes()
    sections, image_base = parse_sections(data)
    imps = import_map(data, sections, image_base)

    reg_slots = {va: n for va, n in imps.items() if "CreateObjCommand" in n or n.endswith("!Tcl_CreateCommand")}
    print(f"# registration slots: {[(hex(k), v) for k, v in reg_slots.items()]}")

    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = True
    text = next(s for s in sections if s["name"] == ".text")
    blob = data[text["raw_ptr"]:text["raw_ptr"] + text["raw_size"]]
    t_va = image_base + text["va"]
    mv = memoryview(blob)

    push_addrs: list[int] = []
    push_vals: list[int] = []
    call_sites: list[tuple[int, int]] = []
    direct_calls: list[int] = []          # addresses of "call <imm>"
    direct_targets: list[int] = []
    reg_iat: dict[int, int] = {}
    # (insn va, imm value) for immediates that point into a data section
    imm_refs: list[tuple[int, int]] = []

    off = 0
    total = len(blob)
    while off < total:
        last = off
        for ins in md.disasm(mv[off:], t_va + off):
            last = ins.address + ins.size - t_va
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
                if ops[0].type == X86_OP_IMM:
                    direct_calls.append(ins.address)
                    direct_targets.append(ops[0].imm & 0xFFFFFFFF)
                elif ops[0].type == X86_OP_MEM:
                    m = ops[0].mem
                    if m.base == 0 and m.index == 0 and m.disp in reg_slots:
                        call_sites.append((ins.address, m.disp))
            for op in ops:
                if op.type == X86_OP_IMM:
                    v = op.imm & 0xFFFFFFFF
                    if 0x00400000 < v < 0x00900000:
                        imm_refs.append((ins.address, v))
        off = last if last > off else off + 1

    print(f"# pushes: {len(push_vals)}, registration calls: {len(call_sites)}, imm refs: {len(imm_refs)}")

    # --- 1. native Tcl command registry -------------------------------------
    # Registration pattern (MSVC cdecl):
    #   push 0            ; deleteProc
    #   push clientData   ; register
    #   push <handler>    ; proc      -> pointer into .text
    #   lea  eax,[esi+0xC]; objName   -> std::string buffer, built earlier from
    #   push <literal>    ;             the pushed string literal
    #   push interp
    #   call [Tcl_CreateObjCommand]
    registry: dict[str, tuple[int, int]] = {}
    for call_va, slot in call_sites:
        lo = bisect.bisect_left(push_addrs, call_va - 300)
        hi = bisect.bisect_left(push_addrs, call_va)
        name_str = None
        handler = None
        for k in range(hi - 1, lo - 1, -1):
            v = push_vals[k]
            if handler is None and section_name(sections, v, image_base) == ".text":
                handler = v
                continue
            if name_str is None:
                s = cstr_at(data, sections, image_base, v)
                if s and all(c.isalnum() or c in "_." for c in s) and not s[0].isdigit():
                    name_str = s
        if not name_str:
            # The name literal is pushed right before the std::string
            # constructor call that precedes the registration call.
            ci = bisect.bisect_left(direct_calls, call_va) - 1
            if ci >= 0:
                ctor_call = direct_calls[ci]
                j = bisect.bisect_left(push_addrs, ctor_call) - 1
                while j >= 0 and push_addrs[j] >= ctor_call - 24:
                    v = push_vals[j]
                    s = cstr_at(data, sections, image_base, v)
                    if s and all(c.isalnum() or c in "_." for c in s) and not s[0].isdigit():
                        name_str = s
                        break
                    j -= 1
        if name_str and handler:
            registry.setdefault(name_str, (handler, call_va))

    print(f"# native Tcl commands recovered: {len(registry)}")
    tsv = ["# native Tcl commands: name <TAB> handler_va <TAB> call_site_va"]
    for name in sorted(registry):
        handler, call_va = registry[name]
        tsv.append(f"{name}\t0x{handler:08X}\t0x{call_va:08X}")
    (outdir / "tcl_commands.tsv").write_text("\n".join(tsv) + "\n", encoding="utf-8")
    print(f"# written: {outdir / 'tcl_commands.tsv'}")

    # --- 2. method map from embedded symbol strings -------------------------
    refs_by_va: dict[int, list[int]] = {}
    for ins_va, v in imm_refs:
        refs_by_va.setdefault(v, []).append(ins_va)

    rows = []
    for m in ASCII_RE.finditer(data):
        s = m.group(0).decode("latin-1")
        if "::" not in s:
            continue
        mm = SYM_RE.match(s)
        if not mm:
            continue
        sva = file_off_to_va(m.start(), sections, image_base)
        if sva is None:
            continue
        cls = mm.group("cls")
        method = mm.group("rest").split("(")[0].strip()
        prefix = (mm.group("prefix") or "").rstrip(":")
        for ref_va in refs_by_va.get(sva, []):
            off_in_text = ref_va - t_va
            j = blob.rfind(PROLOGUE, 0, off_in_text)
            func_va = t_va + j if j >= 0 else None
            rows.append((prefix, cls, method, func_va, ref_va, sva, s))

    print(f"# method symbol references: {len(rows)}")
    msv = ["prefix\tclass\tmethod\tfunc_va\tref_va\tstr_va\ttext"]
    for prefix, cls, method, func_va, ref_va, sva, s in rows:
        msv.append(f"{prefix}\t{cls}\t{method}\t"
                   f"{'0x%08X' % func_va if func_va else ''}\t"
                   f"0x{ref_va:08X}\t0x{sva:08X}\t{s}")
    (outdir / "method_map.tsv").write_text("\n".join(msv) + "\n", encoding="utf-8")
    print(f"# written: {outdir / 'method_map.tsv'}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
