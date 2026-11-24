"""Поиск всех ссылок на float-константу в .rdata exe (по VA).

    python refscan.py 0x7373d8        # все обращения к константе 2.5
    python refscan.py 0x7373d8 0x73756c

Печатает VA каждой инструкции, где встречается байтовый адрес константы
(абсолютный операнд 32 бита), плюс байты вокруг - чтобы видеть,
какая это инструкция.
"""
import struct
import sys

EXE = (r"C:\Program Files (x86)\Steam\steamapps\common"
       r"\Diggles The Myth of Fenris\Diggles.exe")


def main():
    import pefile
    pe = pefile.PE(EXE)
    base = pe.OPTIONAL_HEADER.ImageBase
    raw = open(EXE, "rb").read()
    for arg in sys.argv[1:]:
        va = int(arg, 16)
        needle = struct.pack("<I", va)
        print("=== ссылок на %08X:" % va)
        n = 0
        for s in pe.sections:
            if not (s.Characteristics & 0x20000000):  # IMAGE_SCN_MEM_EXECUTE
                continue
            start = s.PointerToRawData
            end = start + s.SizeOfRawData
            pos = start
            while True:
                i = raw.find(needle, pos, end)
                if i < 0:
                    break
                rva = s.VirtualAddress + (i - start)
                ctx = raw[max(start, i - 6):i + 8]
                print("  VA %08X (RVA %08X)  %s" % (base + rva, rva, ctx.hex(" ")))
                n += 1
                pos = i + 1
        print("  всего:", n)
    pe.close()


if __name__ == "__main__":
    main()
