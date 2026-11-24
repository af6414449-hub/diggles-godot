import re, sys, os, pefile, capstone

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref\ghidra-out"

pe = pefile.PE(GAME + r"\Diggles.exe")
base = pe.OPTIONAL_HEADER.ImageBase
d = open(GAME + r"\Diggles.exe", "rb").read()
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


def owner(va):
    for e, s, n in funcs:
        if e <= va < e + s:
            return (e, s, n)
        if e > va:
            break
    return None


md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True

DISP = 0x37C
needle = struct_pack = DISP.to_bytes(4, "little")
hits = []
pos = 0
while True:
    k = tdata.find(needle, pos)
    if k < 0:
        break
    hits.append(textva + k)
    pos = k + 1
print("raw displacement hits:", len(hits))

# For each hit, find instruction start by scanning backwards up to 8 bytes and
# disassembling from the owning function.
seen_funcs = set()
for h in hits:
    f = owner(h)
    if not f:
        continue
    key = (f[0], h)
    if key in seen_funcs:
        continue
    seen_funcs.add(key)
    entry, size, name = f
    off = entry - textva
    allins = list(md.disasm(tdata[off:off + size], entry))
    for i, ins in enumerate(allins):
        if ins.address <= h < ins.address + ins.size:
            lo = max(0, i - 8)
            print("=" * 70)
            print("func %s entry=0x%08x" % (name, entry))
            for j in range(lo, min(len(allins), i + 9)):
                mark = ">>" if j == i else "  "
                print("%s 0x%08x  %-8s %s" % (mark, allins[j].address, allins[j].mnemonic, allins[j].op_str))
            break
