#!/usr/bin/env python3
"""Locate the engine's camera-scroll key handling.

The engine uses Windows virtual-key codes (FUN_004e4cf0 calls
GetKeyNameTextA).  Arrow keys are VK_LEFT 0x25, VK_UP 0x26, VK_RIGHT 0x27,
VK_DOWN 0x28 (possibly with the extended flag 0x10000); WASD are
0x57/0x41/0x53/0x44.

Scans .text for comparison instructions against those immediates and groups
the hits per function (functions are separated by INT3 padding).

Usage: python find-arrow-keys.py [exe] [out.asm]
"""
import sys
import struct

from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from capstone.x86 import X86_OP_IMM, X86_OP_MEM

EXE = sys.argv[1] if len(sys.argv) > 1 else (
    r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
)
OUT = sys.argv[2] if len(sys.argv) > 2 else "arrow-keys.asm"

IMAGE_BASE = 0x400000
ARROWS = {0x25: "LEFT", 0x26: "UP", 0x27: "RIGHT", 0x28: "DOWN",
          0x10025: "LEFT+ext", 0x10026: "UP+ext", 0x10027: "RIGHT+ext", 0x10028: "DOWN+ext"}
WASDK = {0x57: "W", 0x41: "A", 0x53: "S", 0x44: "D"}


def main():
    data = open(EXE, "rb").read()
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    nsec = struct.unpack_from("<H", data, pe + 6)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    off = pe + 24 + optsz
    text = None
    for i in range(nsec):
        o = off + 40 * i
        vsize, vaddr, rawsize, rawptr = struct.unpack_from("<IIII", data, o + 8)
        if vaddr == 0x1000:
            text = (IMAGE_BASE + vaddr, rawptr, rawsize)
    if text is None:
        raise SystemExit("no .text")
    va0, rawptr, rawsize = text
    chunk = data[rawptr:rawptr + rawsize]

    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = True
    md.skipdata = True

    hits = []
    for ins in md.disasm(chunk, va0):
        if ins.id == 0:          # capstone skipdata pseudo instruction
            continue
        if ins.mnemonic not in ("cmp", "test"):
            continue
        for op in ins.operands:
            if op.type == X86_OP_IMM and op.imm in ARROWS:
                hits.append((ins.address, op.imm, "ARROW"))
            elif op.type == X86_OP_IMM and op.imm in WASDK:
                hits.append((ins.address, op.imm, "WASD"))

    # group by 0xCC padding gaps -> approximate function boundaries
    funcs = []
    for addr, imm, kind in hits:
        if not funcs or addr - funcs[-1][-1][0] > 0x400:
            funcs.append([])
        funcs[-1].append((addr, imm, kind))

    print("total immediate hits: %d" % len(hits))
    print("groups (approximate functions): %d" % len(funcs))
    fh = open(OUT, "w", encoding="utf-8")
    for grp in funcs:
        arrows = [h for h in grp if h[2] == "ARROW"]
        if len(arrows) < 2:
            continue
        lo = min(h[0] for h in grp) - 0x80
        hi = max(h[0] for h in grp) + 0x80
        print("\n--- candidate function, %d arrow compares, range 0x%08X-0x%08X ---"
              % (len(arrows), lo, hi))
        for a, i, k in grp:
            print("      0x%08X  %-5s %s" % (a, k, ARROWS.get(i, WASDK.get(i, hex(i)))))
        start = rawptr + (lo - va0)
        sub = data[start:start + (hi - lo)]
        md2 = Cs(CS_ARCH_X86, CS_MODE_32)
        md2.detail = False
        md2.skipdata = True
        fh.write("\n\n======== candidate 0x%08X - 0x%08X ========\n" % (lo, hi))
        for ins in md2.disasm(sub, lo):
            mark = ""
            for a, i, k in grp:
                if ins.address == a:
                    mark = "   <<< %s" % (ARROWS.get(i, WASDK.get(i, hex(i))))
            fh.write("0x%08X  %-8s %s%s\n" % (ins.address, ins.mnemonic, ins.op_str, mark))
    fh.close()
    print("\nwritten", OUT)


if __name__ == "__main__":
    main()
