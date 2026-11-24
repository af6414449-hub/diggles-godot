import re, sys, pefile, capstone

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
pe = pefile.PE(GAME + r"\Diggles.exe")
base = pe.OPTIONAL_HEADER.ImageBase
text = [s for s in pe.sections if s.Name.rstrip(b"\x00") == b".text"][0]
data = text.get_data()
textva = base + text.VirtualAddress

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True

PAT = sys.argv[1] if len(sys.argv) > 1 else "+ 0x37c]"
CTX = int(sys.argv[2]) if len(sys.argv) > 2 else 8

hits = []
for ins in md.disasm(data, textva):
    if PAT.lower() in ins.op_str.lower():
        hits.append(ins.address)

print("pattern %r hits: %d" % (PAT, len(hits)))
for h in hits[:40]:
    print("=" * 70)
    print("hit 0x%08x" % h)
    off = h - textva
    start = max(0, off - CTX * 8)
    for ins in md.disasm(data[start:start + CTX * 16], textva + start):
        if ins.address > h + CTX * 8:
            break
        mark = ">>" if ins.address == h else "  "
        print("%s 0x%08x  %-8s %s" % (mark, ins.address, ins.mnemonic, ins.op_str))
