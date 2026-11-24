# -*- coding: utf-8 -*-
"""Z38: dump strings around 0x722C40..0x722D10 (enum constant names) + peek a .3db file."""
import struct, io, os

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

START, END = 0x322A80, 0x322AD0
off = rva2off(START)
chunk = data[off:off+(END-START)]
i = 0
print('=== strings RVA 0x%08X..0x%08X ===' % (START, END))
while i < len(chunk):
    j = chunk.find(b'\x00', i)
    if j < 0:
        break
    s = chunk[i:j]
    if len(s) >= 2:
        print('VA 0x%08X  %r' % (START+i+0x400000, s.decode('latin1')))
    i = j + 1

print()
print('=== .3db samples ===')
d3 = r'C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\3db'
for fn in ['licht.3db', 'lavawelt.3db', 'Interface.3db']:
    p = os.path.join(d3, fn)
    if not os.path.exists(p):
        continue
    b = open(p, 'rb').read()
    print('--- %s  (%d bytes) ---' % (fn, len(b)))
    txt = b.decode('latin1')
    print(repr(txt[:600]))
    print()
