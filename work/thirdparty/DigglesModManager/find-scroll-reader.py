import struct, os, pefile, capstone

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
DISPS = {0x18C: "BorderScroll", 0x190: "MouseScroll", 0x194: "KeyScroll", 0x5A4: "view_ptr"}

# locate all "mov reg, [0x772400]" sites, then look for the disp in the next few insns
patA1 = b"\xa1" + struct.pack("<I", APP)
hits = []
pos = 0
while True:
    k = tdata.find(patA1, pos)
    if k < 0:
        break
    hits.append(textva + k)
    pos = k + 1
print("app loads:", len(hits))

# also "mov reg, dword ptr [0x772400]" with other regs
for opbyte in (0x8b,):
    for modrm in range(0x05, 0x40):
        pat = bytes([opbyte, modrm]) + struct.pack("<I", APP)
        p2 = 0
        while True:
            k = tdata.find(pat, p2)
            if k < 0:
                break
            hits.append(textva + k)
            p2 = k + 1

for h in sorted(set(hits)):
    off = h - textva
    # disassemble 40 bytes forward
    chunk = tdata[off:off + 48]
    allins = list(md.disasm(chunk, h))
    for i, ins in enumerate(allins):
        for op in ins.operands:
            if op.type == 3 and op.mem.disp in DISPS:
                f = None
                for e, s, n in funcs:
                    if e <= h < e + s:
                        f = (e, s, n)
                        break
                print("=" * 78)
                print("app-load at 0x%08x   %s" % (h, ("func %s entry=0x%08x size=%d" % (f[2], f[0], f[1])) if f else ""))
                lo = max(0, i - 3)
                for j in range(lo, min(len(allins), i + 4)):
                    mark = ">>" if j == i else "  "
                    a = allins[j]
                    extra = ("   ; %s" % DISPS[op.mem.disp]) if j == i else ""
                    print("%s 0x%08x  %-8s %s%s" % (mark, a.address, a.mnemonic, a.op_str, extra))
