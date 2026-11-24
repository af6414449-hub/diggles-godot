#!/usr/bin/env python3
"""find-cam-table.py — ищет, кто заполняет нативную таблицу привязки камеры.

Таблица живёт в глобальной памяти рядом с 0x768354 (обработчик camctrlmapping
пишет туда индекс слота). Ищем в .text все ссылки на этот диапазон и печатаем
окружающий код с аннотацией строк.
"""
import struct
import sys

import capstone

EXE = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
RANGE = list(range(0x768340, 0x768384, 4))


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


def cstr(v, data, base, secs, maxlen=120):
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


def main():
    data, base, secs = load(EXE)
    text = next(s for s in secs if s[0] == ".text")
    _, tva, tvsize, troff, trsize = text
    blob = data[troff:troff + trsize]

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True

    hits = []
    for t in RANGE:
        pat = struct.pack("<I", t)
        i = 0
        while True:
            i = blob.find(pat, i)
            if i < 0:
                break
            hits.append((base + tva + i, t))
            i += 1
    print(f"ссылок на таблицу камеры: {len(hits)}")
    for va, tgt in sorted(hits):
        o = va2off(va - 6, base, secs)
        print(f"--- {va:#010x} -> {tgt:#010x} ---")
        for ins in md.disasm(data[o:o + 34], va - 6):
            extra = ""
            for op in ins.operands:
                v = None
                if op.type == capstone.x86.X86_OP_IMM:
                    v = op.imm
                elif op.type == capstone.x86.X86_OP_MEM:
                    v = op.mem.disp
                if v and 0x400000 <= v < 0x2000000:
                    s = cstr(v, data, base, secs)
                    if s:
                        extra += f'  ; "{s}"'
            print(f"   {ins.address:#010x}: {ins.mnemonic:8s} {ins.op_str}{extra}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
