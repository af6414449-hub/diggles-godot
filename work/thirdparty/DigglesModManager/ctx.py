import sys, pefile, capstone, os

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref\ghidra-out"

pe = pefile.PE(GAME + r"\Diggles.exe")
base = pe.OPTIONAL_HEADER.ImageBase
text = [s for s in pe.sections if s.Name.rstrip(b"\x00") == b".text"][0]
data = text.get_data()
textva = base + text.VirtualAddress

# function map from Ghidra index
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


def find_func(va):
    lo, hi = 0, len(funcs) - 1
    best = None
    for entry, size, name in funcs:
        if entry <= va < entry + size:
            best = (entry, size, name)
    return best


def dump(entry, size, name, center=None, span=0x50):
    off = entry - textva
    print("=" * 78)
    print("func %s  entry=0x%08x size=%d" % (name, entry, size))
    print("=" * 78)
    for ins in md.disasm(data[off:off + size], entry):
        if center is not None:
            if not (center - span <= ins.address <= center + span):
                continue
        mark = ">>" if ins.address == center else "  "
        print("%s 0x%08x  %-8s %s" % (mark, ins.address, ins.mnemonic, ins.op_str))


for a in sys.argv[1:]:
    va = int(a, 16)
    f = find_func(va)
    if not f:
        print("no function for 0x%08x" % va)
        continue
    dump(f[0], f[1], f[2], center=va)
