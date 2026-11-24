#!/usr/bin/env python3
"""find-string-refs.py — находит в .text ссылки на строковый литерал и печатает
окружающий код с аннотацией строк.

Использование:  python find-string-refs.py ButtonMapping [длина_окна]
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


def cstr(v, data, base, secs, maxlen=200):
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

    name = sys.argv[1]
    win = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x120

    pat = name.encode("ascii") + b"\x00"
    lits = []
    for nm, va, vs, ro, rs in secs:
        b = data[ro:ro + rs]
        i = 0
        while True:
            i = b.find(pat, i)
            if i < 0:
                break
            lits.append(base + va + i)
            i += 1
    print(f"литерал '{name}': {[hex(v) for v in lits]}")

    for lit in lits:
        ipat = struct.pack("<I", lit)
        i = 0
        while True:
            i = blob.find(ipat, i)
            if i < 0:
                break
            ref = base + tva + i
            i += 1
            if not (base + tva <= ref < base + tva + tvsize):
                continue
            print(f"--- ссылка в .text: {ref:#010x} ---")
            o = va2off(ref - win // 2, base, secs)
            for ins in md.disasm(data[o:o + win], ref - win // 2):
                extra = ""
                for op in ins.operands:
                    v = op.imm if op.type == capstone.x86.X86_OP_IMM else (
                        op.mem.disp if op.type == capstone.x86.X86_OP_MEM else 0)
                    if v and 0x400000 <= v < 0x2000000:
                        s = cstr(v, data, base, secs)
                        if s:
                            extra += f'  ; "{s}"'
                print(f"  {ins.address:#010x}: {ins.mnemonic:8s} {ins.op_str}{extra}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
