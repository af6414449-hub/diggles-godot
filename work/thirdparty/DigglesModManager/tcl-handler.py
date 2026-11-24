#!/usr/bin/env python3
"""tcl-handler.py — дизассемблирует функцию Diggles.exe и печатает её с
аннотацией строковых литералов .rdata (полезно, чтобы понять синтаксис
нативных Tcl-команд по их обработчикам).

Использование:  python tcl-handler.py 0x0061fe30 [max_bytes]
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


def main():
    va = int(sys.argv[1], 0)
    limit = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x400
    data, base, secs = load(EXE)
    off = va2off(va, base, secs)
    if off is None:
        print("VA вне файла")
        return 1
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    blob = data[off:off + limit]
    print(f"=== функция по VA {va:#010x} (макс {limit:#x} байт) ===")
    for ins in md.disasm(blob, va):
        extra = ""
        for op in ins.operands:
            if op.type == capstone.x86.X86_OP_IMM and 0x400000 <= op.imm < 0x2000000:
                s = cstr(op.imm, data, base, secs)
                if s:
                    extra += f'  ; "{s}"'
            elif op.type == capstone.x86.X86_OP_MEM and op.mem.disp and 0x400000 <= op.mem.disp < 0x2000000:
                s = cstr(op.mem.disp, data, base, secs)
                if s:
                    extra += f'  ; "{s}"'
        print(f"  {ins.address:#010x}: {ins.mnemonic:8s} {ins.op_str}{extra}")
        if ins.mnemonic == "ret":
            break
    return 0


if __name__ == "__main__":
    sys.exit(main())
