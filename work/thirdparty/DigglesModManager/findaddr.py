import sys, pefile, os

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
    for entry, fsize, fname in funcs:
        if entry <= va < entry + fsize:
            return fname
    return "?"


targets = []
for a in sys.argv[1:]:
    if a.startswith("0x"):
        targets.append(int(a, 16))
    else:
        targets.append(int(a))

for t in targets:
    pat = t.to_bytes(4, "little")
    i = -1
    hits = []
    while True:
        i = data.find(pat, i + 1)
        if i < 0:
            break
        hits.append(textva + i)
    print("target 0x%08x" % t)
    if not hits:
        print("  no reference found in .text")
    for h in hits:
        print("  VA 0x%08x  in %s" % (h, owner(h)))
