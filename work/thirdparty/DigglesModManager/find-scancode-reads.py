import os, pefile, capstone, re

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref\ghidra-out"

pe = pefile.PE(GAME + r"\Diggles.exe")
base = pe.OPTIONAL_HEADER.ImageBase
text = [s for s in pe.sections if s.Name.rstrip(b"\x00") == b".text"][0]
tdata = text.get_data()
textva = base + text.VirtualAddress

funcs = []
for line in open(os.path.join(ROOT, "index.tsv"), encoding="utf-8", errors="replace").read().splitlines()[1:]:
    p = line.split("\t")
    if len(p) < 4:
        continue
    try:
        funcs.append((int(p[1], 16), int(p[2]), p[0]))
    except ValueError:
        pass
funcs.sort()

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True

pat = re.compile(r"word ptr \[\w+ \+ 0x10\]")
hits = []
for entry, size, name in funcs:
    off = entry - textva
    allins = list(md.disasm(tdata[off:off + size], entry))
    for i, ins in enumerate(allins):
        if pat.search(ins.op_str):
            hits.append((entry, size, name, i, allins))

print("reads of word ptr [reg+0x10]:", len(hits))
for entry, size, name, i, allins in hits:
    print("=" * 78)
    print("func %s entry=0x%08x size=%d" % (name, entry, size))
    lo = max(0, i - 6)
    for j in range(lo, min(len(allins), i + 10)):
        mark = ">>" if j == i else "  "
        a = allins[j]
        print("%s 0x%08x  %-8s %s" % (mark, a.address, a.mnemonic, a.op_str))
