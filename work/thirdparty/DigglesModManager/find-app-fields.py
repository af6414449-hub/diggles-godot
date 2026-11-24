import sys, os, pefile, capstone

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref\ghidra-out"

pe = pefile.PE(GAME + r"\Diggles.exe")
base = pe.OPTIONAL_HEADER.ImageBase
text = [s for s in pe.sections if s.Name.rstrip(b"\x00") == b".text"][0]
data = text.get_data()
textva = base + text.VirtualAddress

# function table
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


def owner(va):
    lo, hi = 0, len(funcs) - 1
    best = None
    for e, s, n in funcs:
        if e <= va < e + s:
            best = (e, s, n)
        elif e > va:
            break
    return best


md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True

WANT = [int(a, 16) for a in sys.argv[1:]] or [0x370, 0x37C, 0x368]

# collect hit addresses per function
seen = set()
for entry, size, name in funcs:
    off = entry - textva
    chunk = data[off:off + size]
    hits = []
    for ins in md.disasm(chunk, entry):
        if any(("%+d" % w) in ins.op_str or ("+ 0x%x]" % w) in ins.op_str for w in WANT):
            hits.append(ins.address)
    if hits:
        print("=" * 78)
        print("func %s entry=0x%08x size=%d" % (name, entry, size))
        show = set()
        for ins in md.disasm(chunk, entry):
            if ins.address in hits:
                show.add(ins.address)
        # print hit lines with a little context
        allins = list(md.disasm(chunk, entry))
        for i, ins in enumerate(allins):
            if ins.address in show:
                lo = max(0, i - 6)
                for j in range(lo, min(len(allins), i + 7)):
                    mark = ">>" if allins[j].address in show else "  "
                    print("%s 0x%08x  %-8s %s" % (mark, allins[j].address, allins[j].mnemonic, allins[j].op_str))
                print("   ---")
