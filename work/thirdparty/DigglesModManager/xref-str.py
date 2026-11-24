import struct, pefile, capstone, sys

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
pe = pefile.PE(GAME + r"\Diggles.exe")
base = pe.OPTIONAL_HEADER.ImageBase
text = [s for s in pe.sections if s.Name.rstrip(b"\x00") == b".text"][0]
data = text.get_data()
textva = base + text.VirtualAddress

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True

STR = int(sys.argv[1], 16)   # VA of string
needle = b"\x68" + struct.pack("<I", STR)   # push imm32

hits = []
pos = 0
while True:
    k = data.find(needle, pos)
    if k < 0:
        break
    hits.append(textva + k)
    pos = k + 1

print("push %08x sites: %s" % (STR, [hex(h) for h in hits]))

for h in hits:
    start = h - 0x40
    off = start - textva
    print("=" * 70)
    print("context near 0x%08x" % h)
    for ins in md.disasm(data[off:off + 0x120], start):
        if ins.address > h + 0x60:
            break
        mark = ">>" if ins.address == h else "  "
        print("%s 0x%08x  %-8s %s" % (mark, ins.address, ins.mnemonic, ins.op_str))
