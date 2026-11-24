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

APP = 0x772400
DISPS = {0x18C: "BorderScroll", 0x190: "MouseScroll", 0x194: "KeyScroll",
         0x5A4: "view_ptr", 0x148: "keyevent_holder"}

REGS = ["eax", "ebx", "ecx", "edx", "esi", "edi", "ebp"]


def reg_index(r):
    try:
        return REGS.index(r)
    except ValueError:
        return -1


for entry, size, name in funcs:
    off = entry - textva
    chunk = tdata[off:off + size]
    allins = list(md.disasm(chunk, entry))
    isapp = [False] * 8
    for i, ins in enumerate(allins):
        # track "mov reg, [0x772400]"
        if ins.mnemonic == "mov" and len(ins.operands) == 2:
            dst, src = ins.operands
            if dst.type == 1 and src.type == 3 and src.mem.base == 0 and src.mem.index == 0 and src.mem.disp == APP:
                isapp[reg_index(ins.reg_name(dst.reg))] = True
            elif src.type == 3 and src.mem.base != 0 and src.mem.disp == APP and src.mem.index == 0:
                isapp[reg_index(ins.reg_name(src.mem.base))] = True
        for op in ins.operands:
            if op.type == 3 and op.mem.disp in DISPS and op.mem.base != 0:
                bi = reg_index(ins.reg_name(op.mem.base))
                if bi >= 0 and isapp[bi]:
                    print("=" * 78)
                    print("func %s entry=0x%08x size=%d" % (name, entry, size))
                    lo = max(0, i - 8)
                    for j in range(lo, min(len(allins), i + 9)):
                        mark = ">>" if j == i else "  "
                        a = allins[j]
                        extra = ("   ; %s" % DISPS[op.mem.disp]) if j == i else ""
                        print("%s 0x%08x  %-8s %s%s" % (mark, a.address, a.mnemonic, a.op_str, extra))
                    break
