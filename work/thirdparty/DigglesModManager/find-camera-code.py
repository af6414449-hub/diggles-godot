import os, pefile, capstone

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

CAM = {0x134: "target_x", 0x138: "target_y", 0x13C: "zoom",
       0x100: "cur_x", 0x104: "cur_y", 0x108: "cur_zoom",
       0x5A4: "view_ptr_off"}

for entry, size, name in funcs:
    off = entry - textva
    chunk = tdata[off:off + size]
    allins = list(md.disasm(chunk, entry))
    hits = []
    for i, ins in enumerate(allins):
        for op in ins.operands:
            if op.type == 3 and op.mem.disp in (0x134, 0x138, 0x13C):  # MEM
                hits.append((i, ins, op.mem.disp))
    if hits:
        print("=" * 78)
        print("func %s entry=0x%08x size=%d  hits=%d" % (name, entry, size, len(hits)))
        shown = set()
        for i, ins, disp in hits:
            lo = max(0, i - 4)
            for j in range(lo, min(len(allins), i + 5)):
                if allins[j].address in shown:
                    continue
                shown.add(allins[j].address)
                mark = ">>" if j == i else "  "
                a = allins[j]
                extra = ("   ; %s" % CAM[disp]) if j == i else ""
                print("%s 0x%08x  %-8s %s%s" % (mark, a.address, a.mnemonic, a.op_str, extra))
            print("   ---")
