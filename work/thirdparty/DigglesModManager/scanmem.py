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


md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True

offset = int(sys.argv[1], 0)
pat = (offset & 0xFFFFFFFF).to_bytes(4, "little")
i = -1
seen = set()
while True:
    i = data.find(pat, i + 1)
    if i < 0:
        break
    # try instruction lengths 2..12 ending right after the displacement
    for ilen in range(2, 13):
        start = i + 4 - ilen
        if start < 0:
            continue
        chunk = data[start:i + 4]
        ins = list(md.disasm(chunk, textva + start))
        if len(ins) != 1 or ins[0].size != ilen:
            continue
        x = ins[0]
        if x.address in seen:
            continue
        # does the instruction have a memory operand with our displacement?
        ok = False
        for op in x.operands:
            if op.type == capstone.x86.X86_OP_MEM and op.mem.disp == (offset if offset >= 0 else offset):
                ok = True
        if ok:
            seen.add(x.address)
            print("0x%08x  %-34s %-8s %s" % (x.address, owner(x.address), x.mnemonic, x.op_str))
            break
