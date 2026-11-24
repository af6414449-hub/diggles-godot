import pefile, hashlib
GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
VA = 0x005807b2
pe = pefile.PE(GAME)
base = pe.OPTIONAL_HEADER.ImageBase
off = pe.get_offset_from_rva(VA - base)
data = open(GAME, "rb").read()
print("file offset: 0x%08x (%d)" % (off, off))
print("bytes at offset:", data[off:off+6].hex(" "))
print("context -6..+6:", data[off-6:off+6].hex(" "))
print("sha256 exe:", hashlib.sha256(data).hexdigest().upper())
# how many occurrences of the exact 3-byte pattern in .text?
text = [s for s in pe.sections if s.Name.rstrip(b"\x00") == b".text"][0]
td = text.get_data()
pat = bytes.fromhex("c607ff")
cnt = 0; pos = []
i = 0
while True:
    j = td.find(pat, i)
    if j < 0: break
    cnt += 1; pos.append(hex(base + text.VirtualAddress + j)); i = j + 1
print("occurrences of c6 07 ff in .text:", cnt, pos[:20])
