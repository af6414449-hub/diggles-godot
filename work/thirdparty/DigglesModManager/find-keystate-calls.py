import sys, pefile, capstone

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
EXE = GAME + r"\Diggles.exe"

pe = pefile.PE(EXE)
base = pe.OPTIONAL_HEADER.ImageBase
text = [s for s in pe.sections if s.Name.rstrip(b"\x00") == b".text"][0]
data = text.get_data()
textva = base + text.VirtualAddress

imports = {}
for entry in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []):
    dll = entry.dll.decode()
    for imp in entry.imports:
        name = imp.name.decode() if imp.name else "ord%d" % imp.ordinal
        imports[imp.address] = (dll, name)

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True

insns = list(md.disasm(data, textva))
idx = {ins.address: i for i, ins in enumerate(insns)}

def ctx(va, before=0x40, after=0x40):
    off = va - textva
    i = idx.get(va)
    if i is None:
        return
    lo = max(0, i - 40)
    for ins in insns[lo:i+40]:
        if ins.address < va - before or ins.address > va + after:
            continue
        mark = ">>" if ins.address == va else "  "
        print("%s 0x%08x  %-8s %s" % (mark, ins.address, ins.mnemonic, ins.op_str))

def call_sites(iat_va):
    res = []
    for ins in insns:
        if ins.mnemonic in ("call", "jmp") and "dword ptr [0x" in ins.op_str:
            try:
                tgt = int(ins.op_str.split("[")[1].split("]")[0], 16)
            except ValueError:
                continue
            if tgt == iat_va:
                res.append(ins.address)
    return res

targets = {"GetAsyncKeyState": None, "GetKeyState": None, "GetKeyNameTextA": None, "MapVirtualKeyA": None}
for addr, (dll, name) in imports.items():
    if name in targets:
        targets[name] = addr

for name, addr in targets.items():
    if addr is None:
        continue
    sites = call_sites(addr)
    print("=" * 70)
    print("%s IAT 0x%08x  calls=%d" % (name, addr, len(sites)))
    for s in sites:
        print("--- 0x%08x ---" % s)
        ctx(s, 0x30, 0x20)
