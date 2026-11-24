import struct, pefile, capstone, os

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref\ghidra-out"

pe = pefile.PE(GAME + r"\Diggles.exe")
base = pe.OPTIONAL_HEADER.ImageBase
text = [s for s in pe.sections if s.Name.rstrip(b"\x00") == b".text"][0]
tdata = text.get_data()
textva = base + text.VirtualAddress

imports = {}
for e in pe.DIRECTORY_ENTRY_IMPORT:
    for imp in e.imports:
        imports[imp.name.decode() if imp.name else str(imp.ordinal)] = imp.address

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True

target = imports["SetWindowsHookExA"]
print("SetWindowsHookExA IAT:", hex(target))
pat = b"\xff\x15" + struct.pack("<I", target)
pos = 0
while True:
    k = tdata.find(pat, pos)
    if k < 0:
        break
    va = textva + k
    print("=" * 70)
    print("call at VA 0x%08x" % va)
    start = va - 0x40
    o = start - textva
    for ins in md.disasm(tdata[o:o + 0x90], start):
        mark = ">>" if ins.address == va else "  "
        if ins.address > va + 0x40:
            break
        print("%s 0x%08x  %-8s %s" % (mark, ins.address, ins.mnemonic, ins.op_str))
    pos = k + 1
