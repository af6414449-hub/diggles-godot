#!/usr/bin/env python3
"""Disassemble a VA range of Diggles.exe and save to a text file.

Usage: python dump-va.py <start-hex> <end-hex> <out-file> [exe-path]
"""
import sys
import struct

from capstone import Cs, CS_ARCH_X86, CS_MODE_32

EXE = sys.argv[4] if len(sys.argv) > 4 else (
    r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
)
start = int(sys.argv[1], 16)
end = int(sys.argv[2], 16)
out = sys.argv[3]

IMAGE_BASE = 0x400000


def sections(data):
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    nsec = struct.unpack_from("<H", data, pe + 6)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    off = pe + 24 + optsz
    res = []
    for i in range(nsec):
        o = off + 40 * i
        name = data[o:o + 8].rstrip(b"\x00").decode("ascii", "replace")
        vsize, vaddr, rawsize, rawptr = struct.unpack_from("<IIII", data, o + 8)
        res.append((name, IMAGE_BASE + vaddr, vsize, rawptr, rawsize))
    return res


def main():
    data = open(EXE, "rb").read()
    secs = sections(data)
    off = None
    for name, va, vsize, rawptr, rawsize in secs:
        if va <= start < va + vsize:
            off = rawptr + (start - va)
            break
    if off is None:
        raise SystemExit("VA not mapped")
    size = end - start
    chunk = data[off:off + size]
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = False
    md.skipdata = True
    with open(out, "w", encoding="utf-8") as fh:
        fh.write("Disassembly of %s  VA 0x%08X - 0x%08X\n\n" % (EXE, start, end))
        for ins in md.disasm(chunk, start):
            fh.write("0x%08X  %-8s %s\n" % (ins.address, ins.mnemonic, ins.op_str))
    print("written", out)


if __name__ == "__main__":
    main()
