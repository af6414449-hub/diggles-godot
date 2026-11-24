import pefile, capstone
GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
pe = pefile.PE(GAME)
base = pe.OPTIONAL_HEADER.ImageBase
text = [s for s in pe.sections if s.Name.rstrip(b"\x00") == b".text"][0]
data = text.get_data()
textva = base + text.VirtualAddress
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True
targets = {0x00735d50: "userinit.tcl", 0x00735d90: "systeminit.tcl"}
hits = []
for ins in md.disasm(data, textva):
    for op in ins.operands:
        if op.type == capstone.x86.X86_OP_IMM and op.imm in targets:
            hits.append((ins.address, targets[op.imm], ins.mnemonic, ins.op_str))
for h in hits:
    print("0x%08x  %-14s %s %s" % h)
