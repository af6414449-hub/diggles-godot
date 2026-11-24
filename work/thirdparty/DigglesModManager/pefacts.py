"""Факты по exe: секции, байты в точках патча, релокации.

python pefacts.py [--orig]
"""
import os
import struct
import sys

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
EXE = os.path.join(GAME, "Diggles.exe")
ORIG = os.path.join(GAME, "Diggles.exe.camera.orig")


def dump(path):
    import pefile
    print("=" * 70)
    print("FILE:", path)
    pe = pefile.PE(path)
    ib = pe.OPTIONAL_HEADER.ImageBase
    print("ImageBase %08X  SizeOfImage %08X  DllCharacteristics %04X"
          % (ib, pe.OPTIONAL_HEADER.SizeOfImage,
             pe.OPTIONAL_HEADER.DllCharacteristics))
    print("ASLR:", bool(pe.OPTIONAL_HEADER.DllCharacteristics & 0x40))
    for s in pe.sections:
        n = s.Name.decode("utf-8", "replace").rstrip("\x00")
        print("  %-8s VA %08X VS %08X raw %08X size %08X  end_va %08X end_raw %08X"
              % (n, ib + s.VirtualAddress, s.Misc_VirtualSize, s.PointerToRawData,
                 s.SizeOfRawData, ib + s.VirtualAddress + s.Misc_VirtualSize,
                 s.PointerToRawData + s.SizeOfRawData))
    data = open(path, "rb").read()
    pe.close()

    def off(va):
        for s in pe.sections:
            pass
        return None

    import pefile as _p
    pe2 = _p.PE(path)
    for va in (0x006B6968, 0x006B6A60, 0x006B6A75, 0x006B5A75, 0x00529611,
               0x0071493A, 0x00714900):
        try:
            o = pe2.get_offset_from_rva(va - ib)
        except Exception as e:
            print("  va %08X -> %s" % (va, e))
            continue
        chunk = data[o:o + 16]
        print("  va %08X off %08X : %s" % (va, o, chunk.hex(" ")))
    pe2.close()
    return data, ib


def relocs(path):
    import pefile
    pe = pefile.PE(path)
    ib = pe.OPTIONAL_HEADER.ImageBase
    base = None
    for s in pe.sections:
        if s.Name.startswith(b".reloc"):
            base = s
    if base is None:
        print("no .reloc")
        return
    d = pe.__data__
    off = base.PointerToRawData
    end = off + base.SizeOfRawData
    print("reloc section: VA %08X raw %08X size %08X"
          % (ib + base.VirtualAddress, off, base.SizeOfRawData))
    i = off
    hits = []
    total = 0
    while i + 8 <= end:
        page_rva, block_size = struct.unpack_from("<II", d, i)
        if block_size < 8:
            break
        n = (block_size - 8) // 2
        for k in range(n):
            e = struct.unpack_from("<H", d, i + 8 + k * 2)[0]
            typ = e >> 12
            rva = page_rva + (e & 0xFFF)
            if typ == 10:  # HIGHLOW
                total += 1
                if 0x2B0000 <= rva <= 0x2C0000 or 0x310000 <= rva <= 0x320000:
                    hits.append((rva, typ))
        i += block_size
    print("HIGHLOW entries total:", total)
    for rva, typ in hits:
        print("   rva %08X type %d" % (rva, typ))
    pe.close()


if __name__ == "__main__":
    which = sys.argv[1] if len(sys.argv) > 1 else "both"
    if which in ("patched", "both"):
        dump(EXE)
        relocs(EXE)
    if which in ("orig", "both"):
        dump(ORIG)
        relocs(ORIG)
