"""Точная дизассемблировка окна вокруг заданного VA (capstone, без привязки
к границам функций - полезно, когда линейная дизассемблировка сбилась).

    python disasmwin.py 0x4811c1 [0x4811b0]
"""
import struct
import sys

EXE = (r"C:\Program Files (x86)\Steam\steamapps\common"
       r"\Diggles The Myth of Fenris\Diggles.exe")


def main():
    va = int(sys.argv[1], 16)
    back = int(sys.argv[2], 16) if len(sys.argv) > 2 else 16
    import pefile
    import capstone
    pe = pefile.PE(EXE)
    base = pe.OPTIONAL_HEADER.ImageBase
    rva = va - base
    off = pe.get_offset_from_rva(rva)
    raw = open(EXE, "rb").read()
    pe.close()
    start = va - back
    blk = raw[off - back: off + 48]
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    print("--- окно вокруг %08X (начало %08X) ---" % (va, start))
    for ins in md.disasm(blk, start):
        mark = "   <<<" if ins.address == va else ""
        print("%08X  %-24s %s%s" % (ins.address, ins.bytes.hex(" "),
                                    ins.mnemonic + " " + ins.op_str, mark))


if __name__ == "__main__":
    main()
