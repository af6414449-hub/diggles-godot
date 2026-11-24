#!/usr/bin/env python3
"""find-camctrl.py — находит обработчик нативной Tcl-команды в Diggles.exe.

Команды регистрируются через Tcl_CreateObjCommand(interp, objv, name, cmdProc, clientData).
Имя команды лежит в .rdata как литерал; в коде на него ссылаются либо push imm32,
либо mov reg, imm32 с последующим push reg.

Шаги:
 1. найти VA литерала имени команды (берём из строк .rdata рядом с таблицей имён);
 2. найти в .text все ссылки на этот VA и распознать push/mov;
 3. восстановить адрес cmdProc (аргумент рядом с именем при вызове регистратора);
 4. вывести строковые литералы, на которые ссылается функция-обработчик, —
    они раскрывают синтаксис команды (имена действий, ключей, подкоманд).
"""
import struct
import sys

import capstone

EXE = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
TARGET = "camctrlmapping"


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


def cstr(v, data, base, secs):
    o = va2off(v, base, secs)
    if o is None:
        return None
    e = data.find(b"\x00", o)
    if e < 0 or e - o > 160:
        return None
    s = data[o:e]
    try:
        t = s.decode("ascii")
    except UnicodeDecodeError:
        return None
    return t if all(32 <= ord(c) < 127 for c in t) else None


def find_literal(data, base, secs, name):
    """VA литерала в .rdata: ищем уникальную последовательность байт name\\0 в .rdata."""
    pat = name.encode("ascii") + b"\x00"
    hits = []
    for nm, va, vs, ro, rs in secs:
        blob = data[ro:ro + rs]
        i = 0
        while True:
            i = blob.find(pat, i)
            if i < 0:
                break
            hits.append(base + va + i)
            i += 1
    return hits


def main():
    data, base, secs = load(EXE)
    text = next(s for s in secs if s[0] == ".text")
    _, tva, tvsize, troff, trsize = text

    for name_va in find_literal(data, base, secs, TARGET):
        print(f"=== литерал '{TARGET}' по VA {name_va:#010x} ===")
        pat = struct.pack("<I", name_va)
        i = 0
        while True:
            i = data.find(pat, i)
            if i < 0:
                break
            ref_va = None
            for nm, va, vs, ro, rs in secs:
                if ro <= i < ro + rs:
                    ref_va = base + va + (i - ro)
            i += 1
            if ref_va is None:
                continue
            if not (base + tva <= ref_va < base + tva + tvsize):
                continue  # ссылка в .rdata (таблица) — отдельно разберём
            print(f"  ссылка в .text: VA {ref_va:#010x}")
            disasm_window(data, base, secs, ref_va, 40)

    # Табличный вариант: указатель на литерал в .rdata, рядом — указатель на обработчик
    for nm, va, vs, ro, rs in secs:
        blob = data[ro:ro + rs]
        pat = struct.pack("<I", find_literal(data, base, secs, TARGET)[0])
        i = 0
        while True:
            i = blob.find(pat, i)
            if i < 0:
                break
            abs_off = ro + i
            print(f"  указатель в {nm} по файловому смещению {abs_off:#x}")
            for delta in (-8, -4, 4, 8):
                if abs_off + delta + 4 <= len(data):
                    v = struct.unpack_from("<I", data, abs_off + delta)[0]
                    s = cstr(v, data, base, secs)
                    print(f"     [{delta:+3d}] {v:#010x} -> {s!r}")
            i += 1


def disasm_window(data, base, secs, ref_va, back):
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    start_off = va2off(ref_va - back, base, secs)
    if start_off is None:
        return
    blob = data[start_off:start_off + back * 3]
    for ins in md.disasm(blob, ref_va - back):
        extra = ""
        if ins.mnemonic == "push" and ins.op_str.startswith("0x"):
            v = int(ins.op_str, 16)
            s = cstr(v, data, base, secs)
            if s:
                extra = f'  ; "{s}"'
        mark = "  <<<" if ins.address <= ref_va < ins.address + ins.size else ""
        print(f"    {ins.address:#010x}: {ins.mnemonic:8s} {ins.op_str}{extra}{mark}")


if __name__ == "__main__":
    sys.exit(main())
