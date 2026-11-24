#!/usr/bin/env python3
"""find-tcl-handler.py — по имени нативной Tcl-команды находит её обработчик
и печатает строковые литералы функции (синтаксис команды).

Использование:  python find-tcl-handler.py option [camctrlmapping ...]

Как работает:
 1. литерал имени ищется в .rdata;
 2. в .text ищется ссылка на него (mov/push imm32) — это регистрация команды;
 3. рядом с ней в коде лежит адрес cmdProc (push imm32 перед регистратором);
 4. функция-обработчик дизассемблируется с аннотацией строк.
"""
import struct
import sys

import capstone

EXE = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"


def load(path):
    data = open(path, "rb").read()
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    nsec = struct.unpack_from("<H", data, pe + 6)[0]
    opt = struct.unpack_from("<H", data, pe + 20)[0]
    base = struct.unpack_from("<I", data, pe + 24 + 28)[0]
    off = pe + 24 + opt
    secs = []
    for i in range(nsec):
        s = off + i * 40
        nm = data[s:s + 8].rstrip(b"\x00").decode("ascii", "replace")
        vs, va, rs, ro = struct.unpack_from("<IIII", data, s + 8)
        secs.append((nm, va, vs, ro, rs))
    return data, base, secs


def va2off(v, base, secs):
    rva = v - base
    for nm, va, vs, ro, rs in secs:
        if va <= rva < va + max(vs, rs):
            return ro + (rva - va)
    return None


def cstr(v, data, base, secs, maxlen=160):
    o = va2off(v, base, secs)
    if o is None:
        return None
    e = data.find(b"\x00", o)
    if e < 0 or e - o > maxlen:
        return None
    try:
        t = data[o:e].decode("ascii")
    except UnicodeDecodeError:
        return None
    return t if t and all(32 <= ord(c) < 127 for c in t) else None


def literal_vas(data, base, secs, name):
    pat = name.encode("ascii") + b"\x00"
    out = []
    for nm, va, vs, ro, rs in secs:
        blob = data[ro:ro + rs]
        i = 0
        while True:
            i = blob.find(pat, i)
            if i < 0:
                break
            out.append(base + va + i)
            i += 1
    return out


def find_handler(data, base, secs, name):
    text = next(s for s in secs if s[0] == ".text")
    _, tva, tvsize, troff, trsize = text
    blob = data[troff:troff + trsize]
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    for lit in literal_vas(data, base, secs, name):
        pat = struct.pack("<I", lit)
        i = 0
        while True:
            i = blob.find(pat, i)
            if i < 0:
                break
            ref = base + tva + i
            i += 1
            if not (base + tva <= ref < base + tva + tvsize):
                continue
            # рядом с регистрацией лежит push imm32 — кандидат в cmdProc
            lo = max(0, i - 40)
            win = blob[lo:i + 60]
            for ins in md.disasm(win, base + tva + lo):
                if ins.mnemonic == "push" and ins.op_str.startswith("0x"):
                    v = int(ins.op_str, 16)
                    if base + tva <= v < base + tva + tvsize and v != lit:
                        yield v, ""


def dump(data, base, secs, va, limit=0x500):
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    off = va2off(va, base, secs)
    if off is None:
        return
    seen = set()
    for ins in md.disasm(data[off:off + limit], va):
        extra = ""
        for op in ins.operands:
            v = op.imm if op.type == capstone.x86.X86_OP_IMM else (
                op.mem.disp if op.type == capstone.x86.X86_OP_MEM else 0)
            if v and 0x400000 <= v < 0x2000000:
                s = cstr(v, data, base, secs)
                if s and s not in seen:
                    seen.add(s)
                    extra += f'  ; "{s}"'
        if extra:
            print(f"  {ins.address:#010x}: {ins.mnemonic:8s} {ins.op_str}{extra}")
        if ins.mnemonic == "ret":
            break


def main():
    data, base, secs = load(EXE)
    for name in sys.argv[1:]:
        print(f"########## {name} ##########")
        found = False
        for handler, src in find_handler(data, base, secs, name):
            found = True
            print(f"обработчик: {handler:#010x}")
            dump(data, base, secs, handler)
        if not found:
            print("  обработчик не найден")
    return 0


if __name__ == "__main__":
    sys.exit(main())
