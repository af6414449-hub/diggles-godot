import pefile
GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
pe = pefile.PE(GAME)
base = pe.OPTIONAL_HEADER.ImageBase
raw = open(GAME, "rb").read()
for va, name in ((0x00735d50, "userinit.tcl"), (0x00735d90, "systeminit.tcl")):
    pat = va.to_bytes(4, "little")
    pos = []
    i = 0
    while True:
        j = raw.find(pat, i)
        if j < 0: break
        pos.append(j); i = j + 1
    print(name, hex(va), "refs at file offsets:", [hex(p) for p in pos[:10]])
    for p in pos[:10]:
        try:
            rva = pe.get_rva_from_offset(p)
            print("   -> VA", hex(base + rva))
        except Exception as e:
            print("   -> (no va)", e)
