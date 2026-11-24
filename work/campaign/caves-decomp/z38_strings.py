# -*- coding: utf-8 -*-
"""Z38: dump rest of name pool + find pointer tables referencing it."""
import struct

EXE = r'C:\diggles-ghidra\Diggles.exe'
with open(EXE, 'rb') as f:
    data = f.read()

pe = struct.unpack('<I', data[0x3C:0x40])[0]
nsec = struct.unpack('<H', data[pe+6:pe+8])[0]
opthdr = struct.unpack('<H', data[pe+0x14:pe+0x16])[0]
base = pe + 0x18 + opthdr
secs = []
for i in range(nsec):
    e = base + i*40
    name = data[e:e+8].rstrip(b'\x00').decode('latin1')
    vsize, vaddr, rsize, raddr = struct.unpack('<IIII', data[e+8:e+24])
    secs.append((name, vaddr, vsize, raddr, rsize))

def rva2off(rva):
    for name, vaddr, vsize, raddr, rsize in secs:
        if vaddr <= rva < vaddr + max(vsize, rsize):
            return raddr + (rva - vaddr)
    return None

def off2rva(off):
    for name, vaddr, vsize, raddr, rsize in secs:
        if raddr <= off < raddr + rsize:
            return vaddr + (off - raddr)
    return None

IMAGEBASE = 0x400000

# ---- 1. full pool dump ----
START, END = 0x322D00, 0x323260
off = rva2off(START)
chunk = data[off:off+(END-START)]
print('=== name pool RVA 0x%08X..0x%08X ===' % (START, END))
names = []
i = 0
while i < len(chunk):
    j = chunk.find(b'\x00', i)
    if j < 0:
        break
    s = chunk[i:j]
    if len(s) >= 2:
        names.append((START+i, s.decode('latin1')))
    i = j + 1
for k, (rva, s) in enumerate(names):
    print('%3d  RVA %08X  VA %08X  %r' % (k, rva, rva+IMAGEBASE, s))

# ---- 2. find pointer tables ----
print()
print('=== pointer references (4-byte LE) to pool strings ===')
for rva, s in names:
    va = rva + IMAGEBASE
    needle = struct.pack('<I', va)
    pos = []
    st = 0
    while True:
        j = data.find(needle, st)
        if j < 0:
            break
        pos.append(j)
        st = j + 1
    refs = []
    for p in pos:
        rr = off2rva(p)
        refs.append('rva=%08X(va %08X)' % (rr, rr+IMAGEBASE) if rr is not None else 'off %08X(raw)' % p)
    print('%-24s VA %08X  refs: %s' % (s, va, ', '.join(refs) if refs else 'NONE'))
