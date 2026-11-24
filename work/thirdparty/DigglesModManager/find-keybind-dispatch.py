#!/usr/bin/env python3
"""Find the engine code that dispatches keybind entries.

The keybind table lives at DAT_00772400 + 0x148 (entries) and +0x14c (count).
Only CTclGlobalMethods::KeyBind was decompiled, so the dispatcher has to be
located in the raw binary.  Search for instructions that read those offsets
and disassemble the surroundings.

Usage: python find-keybind-dispatch.py [path-to-Diggles.exe]
"""
import sys
import struct

from capstone import Cs, CS_ARCH_X86, CS_MODE_32

EXE = sys.argv[1] if len(sys.argv) > 1 else (
    r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
)
IMAGE_BASE = 0x400000
GLOB_PTR = 0x00772400          # DAT_00772400
TABLE_OFF = 0x148              # entries pointer
COUNT_OFF = 0x14C              # entry count


def sections(data):
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    nsec = struct.unpack_from("<H", data, pe + 6)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    off = pe + 24 + optsz
    out = []
    for i in range(nsec):
        o = off + 40 * i
        name = data[o:o + 8].rstrip(b"\x00").decode("ascii", "replace")
        vsize, vaddr, rawsize, rawptr = struct.unpack_from("<IIII", data, o + 8)
        out.append((name, IMAGE_BASE + vaddr, vsize, rawptr, rawsize))
    return out


def to_file(secs, rva):
    for name, va, vsize, rawptr, rawsize in secs:
        if va <= IMAGE_BASE + rva < va + vsize:
            return rawptr + (rva - (va - IMAGE_BASE))
    return None


def main():
    data = open(EXE, "rb").read()
    secs = sections(data)
    print("sections:")
    for s in secs:
        print("   %-8s va=0x%08X vsize=0x%X raw=0x%X rawsize=0x%X" % s)

    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = False

    hits = []
    # mov reg, [reg+0x148]  -> 8B <modrm> 48 01 00 00
    for i in range(len(data) - 6):
        if data[i] != 0x8B:
            continue
        modrm = data[i + 1]
        disp = data[i + 2:i + 6]
        if disp not in (b"\x48\x01\x00\x00", b"\x4c\x01\x00\x00"):
            continue
        # modrm must reference a 32-bit register with disp32 (mod=10)
        if (modrm & 0xC0) != 0x80:
            continue
        hits.append((i, 0x148 if disp[0] == 0x48 else 0x14C))

    print("\nraw hits for [reg+0x148] / [reg+0x14c]: %d" % len(hits))
    seen = set()
    for off, kind in hits:
        rva = None
        for name, va, vsize, rawptr, rawsize in secs:
            if rawptr <= off < rawptr + rawsize:
                rva = (va - IMAGE_BASE) + (off - rawptr)
                break
        if rva is None:
            continue
        va = IMAGE_BASE + rva
        if va in seen:
            continue
        seen.add(va)
        # widen the window: 96 bytes before, 160 after
        start_off = max(0, off - 96)
        end_off = min(len(data), off + 160)
        chunk = data[start_off:end_off]
        start_va = IMAGE_BASE + (rva - (off - start_off))
        print("\n=== hit at VA 0x%08X (offset 0x%X, %s) ===" % (va, off, "0x148" if kind == 0x148 else "0x14C"))
        for ins in md.disasm(chunk, start_va):
            mark = " <<<" if ins.address == va else ""
            print("   0x%08X  %-8s %s%s" % (ins.address, ins.mnemonic, ins.op_str, mark))
            if ins.address > va + 120:
                break


if __name__ == "__main__":
    main()
