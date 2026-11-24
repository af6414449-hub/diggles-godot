import sys, pefile, capstone, os

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
ROOT = r"C:\Users\frant\OneDrive\Р”РѕРєСѓРјРµРЅС‚С‹\MiniMax\Diggles\work\campaign\ref\ghidra-out"

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


md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True
md.skipdata = True

want = [int(a, 0) for a in sys.argv[1:]]
print("scanning .text for memory operands with displacement in %s" % [hex(w) for w in want])
count = 0
for x in md.disasm(data, textva):
    for op in x.operands:
        if op.type != capstone.x86.X86_OP_MEM:
            continue
        d = op.mem.disp
        if d in want:
            print("0x%08x  %-34s %-8s %s" % (x.address, owner(x.address), x.mnemonic, x.op_str))
            count += 1
            break
print("total hits:", count)
