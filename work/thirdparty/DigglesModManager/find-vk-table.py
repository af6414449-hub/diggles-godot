import struct, pefile

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
DLL = GAME + r"\DigglesPort.dll"

pe = pefile.PE(DLL)
base = pe.OPTIONAL_HEADER.ImageBase
data = open(DLL, "rb").read()

# GetVKScanCode is at RVA 0x11650, size 1141 (from Ghidra index_port.tsv)
RVA, SIZE = 0x11650, 1141
# find file offset of that rva
fo = pe.get_offset_from_rva(RVA)
print("GetVKScanCode file offset:", hex(fo), "rva", hex(RVA), "size", SIZE)

TARGETS = {
    0x00410004: ("A", 0x25),   # scancode 4  -> VK_LEFT
    0x00440007: ("D", 0x27),   # scancode 7  -> VK_RIGHT
    0x00530016: ("S", 0x28),   # scancode 22 -> VK_DOWN
    0x0057001A: ("W", 0x26),   # scancode 26 -> VK_UP
    0x00250050: ("LEFT", None),
    0x0027004F: ("RIGHT", None),
    0x00280051: ("DOWN", None),
    0x00260052: ("UP", None),
}

for packed, (name, _) in TARGETS.items():
    needle = struct.pack("<I", packed)
    hits = []
    pos = 0
    while True:
        k = data.find(needle, pos)
        if k < 0:
            break
        hits.append(k)
        pos = k + 1
    in_fn = [h for h in hits if fo <= h < fo + SIZE]
    print("0x%08x %-6s hits=%d  in GetVKScanCode: %s" % (packed, name, len(hits), [hex(h) for h in in_fn]))
