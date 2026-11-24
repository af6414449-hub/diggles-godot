"""Прочитать float-константы exe по VA (адреса из .rdata).

Использование:  python readfloat.py 0x7373d8 0x737138 ...
"""
import sys
import struct

import pefile

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"

pe = pefile.PE(GAME)
base = pe.OPTIONAL_HEADER.ImageBase


def read(va):
    rva = va - base
    try:
        off = pe.get_offset_from_rva(rva)
    except Exception:
        return None
    data = pe.get_data(rva, 4)
    if len(data) < 4:
        return None
    return struct.unpack("<f", data)[0]


for a in sys.argv[1:]:
    va = int(a, 16)
    v = read(va)
    print("VA %08X  = %s" % (va, v))
