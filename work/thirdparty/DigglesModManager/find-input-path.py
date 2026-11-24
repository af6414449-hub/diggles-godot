import sys, pefile, capstone

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
EXE = GAME + r"\Diggles.exe"

pe = pefile.PE(EXE)
base = pe.OPTIONAL_HEADER.ImageBase
text = None
for s in pe.sections:
    if s.Name.rstrip(b"\x00") == b".text":
        text = s
print("image base", hex(base), "text rva", hex(text.VirtualAddress), "size", hex(text.SizeOfRawData))

# --- imports ---
imports = {}
for entry in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []):
    dll = entry.dll.decode()
    for imp in entry.imports:
        name = imp.name.decode() if imp.name else "ord%d" % imp.ordinal
        imports[imp.address] = (dll, name)
print("imports:", len(imports))

for addr, (dll, name) in sorted(imports.items()):
    if "SDL" in dll or "key" in name.lower() or "Key" in name:
        print("  IAT 0x%08x  %s!%s" % (addr, dll, name))

data = text.get_data()
textva = base + text.VirtualAddress

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True

def disasm_range(va, length):
    off = va - textva
    code = data[off:off+length]
    out = []
    for ins in md.disasm(code, va):
        out.append(ins)
        if ins.address >= va + length:
            break
    return out

def find_calls_to_iat(iat_va):
    hits = []
    for ins in md.disasm(data, textva):
        if ins.mnemonic in ("call", "jmp") and ins.op_str.startswith("dword ptr [0x"):
            try:
                tgt = int(ins.op_str.split("[")[1].split("]")[0], 16)
            except ValueError:
                continue
            if tgt == iat_va:
                hits.append(ins.address)
    return hits

# find GetVKScanCode IAT
for addr, (dll, name) in sorted(imports.items()):
    if "VKScan" in name:
        print("\n=== %s!%s IAT 0x%08x ===" % (dll, name, addr))
        sites = find_calls_to_iat(addr)
        print("call sites:", [hex(s) for s in sites])
        for s in sites:
            print("--- context at 0x%08x ---" % s)
            for ins in disasm_range(s - 0x30, 0x70):
                mark = ">>" if ins.address == s else "  "
                print("%s 0x%08x  %-8s %s" % (mark, ins.address, ins.mnemonic, ins.op_str))
