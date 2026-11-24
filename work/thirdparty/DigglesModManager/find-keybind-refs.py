#!/usr/bin/env python3
"""Locate code that touches the keybind table at DAT_00772400 + 0x148/0x14c.

Strategy: find every reference to the global pointer DAT_00772400 (absolute
address 0x00772400 encoded little endian), disassemble a window around it and
report the ones that also access the +0x148 / +0x14c offsets.

Usage: python find-keybind-refs.py [exe] [out.asm]
"""
import sys
import struct

from capstone import Cs, CS_ARCH_X86, CS_MODE_32

EXE = sys.argv[1] if len(sys.argv) > 1 else (
    r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
)
OUT = sys.argv[2] if len(sys.argv) > 2 else "keybind-refs.asm"

IMAGE_BASE = 0x400000
GLOB = 0x00772400
PAT = struct.pack("<I", GLOB)


def sections(data):
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    nsec = struct.unpack_from("<H", data, pe + 6)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    off = pe + 24 + optsz
    res = []
    for i in range(nsec):
        o = off + 40 * i
        vsize, vaddr, rawsize, rawptr = struct.unpack_from("<IIII", data, o + 8)
        res.append((IMAGE_BASE + vaddr, vsize, rawptr, rawsize))
    return res


def va_of(secs, off):
    for va, vsize, rawptr, rawsize in secs:
        if rawptr <= off < rawptr + rawsize:
            return va + (off - rawptr)
    return None


def main():
    data = open(EXE, "rb").read()
    secs = sections(data)
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.skipdata = True

    refs = []
    i = 0
    while True:
        i = data.find(PAT, i)
        if i < 0:
            break
        refs.append(i)
        i += 1
    print("absolute references to 0x%08X: %d" % (GLOB, len(refs)))

    found = []
    fh = open(OUT, "w", encoding="utf-8")
    for off in refs:
        va = va_of(secs, off)
        if va is None:
            continue
        lo = max(0, off - 120)
        chunk = data[lo:off + 200]
        start_va = va - (off - lo)
        ins_list = list(md.disasm(chunk, start_va))
        text = "\n".join("%08X  %-8s %s" % (i.address, i.mnemonic, i.op_str) for i in ins_list)
        interesting = ("0x148" in text and "0x14c" in text) or ("0x148" in text)
        if interesting:
            found.append(va)
            fh.write("\n\n======== VA 0x%08X (file 0x%X) ========\n" % (va, off))
            for i2 in ins_list:
                mark = "   <<<" if i2.address == va else ""
                fh.write("0x%08X  %-8s %s%s\n" % (i2.address, i2.mnemonic, i2.op_str, mark))
    fh.close()
    print("windows containing +0x148/+0x14c access: %d" % len(found))
    for v in found:
        print("   VA 0x%08X" % v)


if __name__ == "__main__":
    main()
