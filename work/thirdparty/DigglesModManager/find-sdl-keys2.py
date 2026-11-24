import struct, os, pefile, capstone, sys

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
ROOT = r"C:\Users\frant\OneDrive\Р”РѕРєСѓРјРµРЅС‚С‹\MiniMax\Diggles\work\campaign\ref\ghidra-out"

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

# SDLK_* constants (SDLK_SCANCODE_MASK = 1<<30)
CONSTS = {
    0x40000050: "SDLK_LEFT",
    0x4000004F: "SDLK_RIGHT",
    0x40000052: "SDLK_UP",
    0x40000051: "SDLK_DOWN",
    79: "scancode RIGHT(79)",
    80: "scancode LEFT(80)",
    81: "scancode DOWN(81)",
    82: "scancode UP(82)",
}

# find functions whose code contains one of these immediates
want = set(CONSTS.keys())
found = {}
for entry, size, name in funcs:
    off = entry - textva
    chunk = tdata[off:off + size]
    hit = False
    for ins in md.disasm(chunk, entry):
        for op in ins.operands:
            if op.type == 2 and op.imm in want and ins.mnemonic in ("cmp","test"):  # IMM
                hit = True
    if hit:
        found[entry] = (size, name)

print("functions containing arrow constants:", len(found))
for entry, (size, name) in list(found.items()):
    off = entry - textva
    chunk = tdata[off:off + size]
    hits = []
    allins = list(md.disasm(chunk, entry))
    for i, ins in enumerate(allins):
        for op in ins.operands:
            if op.type == 2 and op.imm in want:
                hits.append((i, ins, op.imm))
    print("=" * 78)
    print("func %s entry=0x%08x size=%d" % (name, entry, size))
    shown = set()
    for i, ins, imm in hits:
        lo = max(0, i - 5)
        for j in range(lo, min(len(allins), i + 6)):
            if allins[j].address in shown:
                continue
            shown.add(allins[j].address)
            mark = ">>" if j == i else "  "
            a = allins[j]
            extra = ("   ; " + CONSTS[imm]) if (j == i and imm in CONSTS) else ""
            print("%s 0x%08x  %-8s %s%s" % (mark, a.address, a.mnemonic, a.op_str, extra))
        print("   ---")

