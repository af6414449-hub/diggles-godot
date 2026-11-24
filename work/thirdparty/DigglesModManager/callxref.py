#!/usr/bin/env python3
"""callxref.py - find direct CALL instructions (E8 rel32) to a given VA in Diggles.exe.

The existing findref.py misses some call sites; this one scans the whole
.text section byte by byte and decodes E8 rel32, which is exact for direct
near calls.

Usage:  python callxref.py 0x00592F10 [exe_path]
        python callxref.py 0x00592F10 --section .text
"""
import struct
import sys

DEFAULT_EXE = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"


def read_sections(data):
    """Return {name: (rva, vaddr, size)} for the PE sections."""
    pe_off = struct.unpack_from("<I", data, 0x3C)[0]
    assert data[pe_off:pe_off + 4] == b"PE\0\0", "not a PE file"
    coff = pe_off + 4
    n_sections = struct.unpack_from("<H", data, coff + 2)[0]
    opt_size = struct.unpack_from("<H", data, coff + 16)[0]
    opt = coff + 20
    magic = struct.unpack_from("<H", data, opt)[0]
    image_base = struct.unpack_from("<I", data, opt + 28)[0] if magic == 0x10B else None
    if image_base is None:
        image_base = struct.unpack_from("<Q", data, opt + 24)[0]
    sec_off = opt + opt_size
    secs = {}
    for i in range(n_sections):
        o = sec_off + i * 40
        name = data[o:o + 8].rstrip(b"\0").decode("ascii", "replace")
        vsize, vaddr, rawsize, rawptr = struct.unpack_from("<IIII", data, o + 8)
        secs[name] = (vaddr, image_base + vaddr, rawsize, rawptr)
    return secs, image_base


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    target = int(sys.argv[1], 16)
    exe = DEFAULT_EXE
    if len(sys.argv) > 2 and not sys.argv[2].startswith("--"):
        exe = sys.argv[2]
    with open(exe, "rb") as fh:
        data = fh.read()
    secs, image_base = read_sections(data)
    hits = []
    for name, (vaddr, va, rawsize, rawptr) in secs.items():
        if name != ".text":
            continue
        blob = data[rawptr:rawptr + rawsize]
        i = 0
        n = len(blob)
        while True:
            i = blob.find(b"\xE8", i)
            if i < 0 or i + 5 > n:
                break
            rel = struct.unpack_from("<i", blob, i + 1)[0]
            site = va + i
            dest = site + 5 + rel
            if dest == target:
                hits.append(site)
            i += 1
    print("target 0x%08X  image_base 0x%08X" % (target, image_base))
    if hits:
        for h in hits:
            print("  call at 0x%08X" % h)
    else:
        print("  no direct call found")
    return 0


if __name__ == "__main__":
    sys.exit(main())
