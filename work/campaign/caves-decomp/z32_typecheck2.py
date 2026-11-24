# -*- coding: utf-8 -*-
"""Уточнение З30: что реально лежит в 0x773650 (шаг 0x40) и в 0x783650 (шаг 0x40)."""
import struct

EXE = r'C:\diggles-ghidra\Diggles.exe'
IMAGE_BASE = 0x400000
data = open(EXE, 'rb').read()
pe = struct.unpack_from('<I', data, 0x3C)[0]
nsec = struct.unpack_from('<H', data, pe + 6)[0]
opt_size = struct.unpack_from('<H', data, pe + 20)[0]
sec_off = pe + 24 + opt_size
secs = []
for i in range(nsec):
    o = sec_off + i * 40
    secs.append((struct.unpack_from('<I', data, o + 12)[0],
                 struct.unpack_from('<I', data, o + 8)[0],
                 struct.unpack_from('<I', data, o + 20)[0],
                 struct.unpack_from('<I', data, o + 16)[0]))


def off_of(va):
    rva = va - IMAGE_BASE
    for vaddr, vsize, praw, psize in secs:
        if vaddr <= rva < vaddr + max(vsize, psize):
            return praw + (rva - vaddr)
    return None


def raw(va, n):
    o = off_of(va)
    return None if o is None else data[o:o + n]


def cstr(va, maxn=96):
    b = raw(va, maxn)
    if not b:
        return None
    z = b.find(b'\x00')
    if z <= 0:
        return None
    try:
        s = b[:z].decode('latin-1')
    except Exception:
        return None
    return s if all(32 <= ord(c) < 127 for c in s) else None


print('=== 0x783650 + k*0x40 : 16 dword записи ===')
for k in range(8):
    b = raw(0x783650 + k * 0x40, 0x40)
    if not b:
        print('  вне секций'); break
    d = struct.unpack_from('<16I', b, 0)
    f = struct.unpack_from('<4f', b, 0)
    nm = cstr(d[15]) if 0x400000 < d[15] < 0x800000 else None
    print('  тип %d: float0..3 = %s | +3C ptr=%08X -> %r'
          % (k, ['%.4f' % x for x in f], d[15], nm))
    if nm is None:
        print('        dwords: %s' % ' '.join('%08X' % x for x in d))

print()
print('=== 0x773650 + k*0x40 (runtime-состояние типа) ===')
for k in range(6):
    b = raw(0x773650 + k * 0x40, 0x40)
    if not b:
        print('  вне секций'); break
    d = struct.unpack_from('<16I', b, 0)
    print('  тип %d: +00=%08X +04=%08X +08=%08X +0C=%08X' % (k, d[0], d[1], d[2], d[3]))
