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

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True

# usage: disasm.py 0xADDR [len] ...   (len default: from index.tsv, else 160)
for a in sys.argv[1:]:
    va = int(a, 16)
    size = None
    name = None
    for entry, fsize, fname in funcs:
        if entry <= va < entry + fsize:
            size, name = fsize - (va - entry), fname
            break
    if size is None:
        size = 160
    off = va - textva
    print("=" * 78)
    print("func %s va=0x%08x size=%d" % (name or "?", va, size))
    print("=" * 78)
    for ins in md.disasm(data[off:off + size], va):
        print("0x%08x  %-8s %s" % (ins.address, ins.mnemonic, ins.op_str))
