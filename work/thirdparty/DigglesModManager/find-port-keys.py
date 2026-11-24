import pefile, capstone, struct, os

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
DLL = GAME + r"\DigglesPort.dll"
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref\ghidra-out"

pe = pefile.PE(DLL)
base = pe.OPTIONAL_HEADER.ImageBase
text = [s for s in pe.sections if s.Name.rstrip(b"\x00") == b".text"][0]
tdata = text.get_data()
textva = base + text.VirtualAddress

# function table from index_port.tsv
funcs = []
for line in open(os.path.join(ROOT, "index_port.tsv"), encoding="utf-8", errors="replace").read().splitlines()[1:]:
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

NAMES = {79: "SCAN_RIGHT", 80: "SCAN_LEFT", 81: "SCAN_DOWN", 82: "SCAN_UP",
         4: "SCAN_A", 7: "SCAN_D", 22: "SCAN_S", 26: "SCAN_W",
         0x40000050: "SDLK_LEFT", 0x4000004F: "SDLK_RIGHT",
         0x40000052: "SDLK_UP", 0x40000051: "SDLK_DOWN"}

for entry, size, name in funcs:
    off = entry - textva
    allins = list(md.disasm(tdata[off:off + size], entry))
    hits = []
    for i, ins in enumerate(allins):
        for op in ins.operands:
            if op.type == 2 and op.imm in NAMES and ins.mnemonic in ("cmp", "test", "sub", "and", "or"):
                hits.append((i, ins, op.imm))
    if hits:
        print("=" * 78)
        print("func %s entry=0x%08x size=%d" % (name, entry, size))
        shown = set()
        for i, ins, imm in hits:
            lo = max(0, i - 6)
            for j in range(lo, min(len(allins), i + 7)):
                if allins[j].address in shown:
                    continue
                shown.add(allins[j].address)
                mark = ">>" if j == i else "  "
                a = allins[j]
                extra = ("   ; %s" % NAMES[imm]) if j == i else ""
                print("%s 0x%08x  %-8s %s%s" % (mark, a.address, a.mnemonic, a.op_str, extra))
