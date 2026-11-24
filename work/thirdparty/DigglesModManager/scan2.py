import sys, pefile, capstone, os

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref\ghidra-out"

pe = pefile.PE(GAME + r"\Diggles.exe")
base = pe.OPTIONAL_HEADER.ImageBase
text = [s for s in pe.sections if s.Name.rstrip(b"\x00") == b".text"][0]
data = text.get_data()
textva = base + text.VirtualAddress

funcs = []
idx = os.path.join(ROOT, "index.tsv")
if os.path.exists(idx):
    for line in open(idx, encoding="utf-8", errors="replace").read().splitlines()[1:]:
        p = line.split("\t")
        if len(p) < 4:
            continue
        try:
            funcs.append((int(p[1], 16), int(p[2]), p[0]))
        except ValueError:
            pass
    funcs.sort()


def owner(va):
    for e, s, n in funcs:
        if e <= va < e + s:
            return n
    return "?"


mode = sys.argv[1]
vals = [int(a, 0) for a in sys.argv[2:]]

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True
md.skipdata = True

print("scanning .text for %s in %s" % (mode, [hex(v) for v in vals]))
count = 0
for x in md.disasm(data, textva):
    if x.id == 0:
        continue
    hit = False
    for op in x.operands:
        if mode == "imm" and op.type == capstone.x86.X86_OP_IMM and op.imm in vals:
            hit = True
        if mode == "disp" and op.type == capstone.x86.X86_OP_MEM and op.mem.disp in vals:
            hit = True
    if hit:
        print("0x%08x  %-34s %-8s %s" % (x.address, owner(x.address), x.mnemonic, x.op_str))
        count += 1
print("total hits:", count)
