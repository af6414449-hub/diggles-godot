import pefile, capstone
GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
pe = pefile.PE(GAME); base = pe.OPTIONAL_HEADER.ImageBase
text = [s for s in pe.sections if s.Name.rstrip(b"\x00") == b".text"][0]
data = text.get_data(); textva = base + text.VirtualAddress
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
targets = {0x0072d258: "load_done", 0x0072d9a4: "show_loading", 0x0072d24c: "load_info"}
for ins in md.disasm(data, textva):
    for op in ins.operands:
        if op.type == capstone.x86.X86_OP_IMM and op.imm in targets:
            print("0x%08x  %-12s %s %s" % (ins.address, targets[op.imm], ins.mnemonic, ins.op_str))
