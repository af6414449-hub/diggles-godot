# -*- coding: utf-8 -*-
"""Проверка массивов, на которые ссылается З30: тайловые bbox и счётчики."""
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
                 struct.unpack_from('<I', data, o + 16)[0],
                 data[o:o + 8].rstrip(b'\x00').decode('latin-1')))


def off_of(va):
    rva = va - IMAGE_BASE
    for vaddr, vsize, praw, psize, nm in secs:
        if vaddr <= rva < vaddr + max(vsize, psize):
            return praw + (rva - vaddr)
    return None


def raw(va, n):
    o = off_of(va)
    return None if o is None else data[o:o + n]


print('секции:')
for vaddr, vsize, praw, psize, nm in secs:
    print('  %-8s VA %08X  vsize %08X  raw %08X' % (nm, IMAGE_BASE + vaddr, vsize, praw))

print()
print('=== 0x773680 + tile*0x10 : первые 8 записей (4 float + ? ) ===')
for t in range(8):
    b = raw(0x773680 + t * 0x10, 16)
    if b is None:
        print('  вне секций'); break
    f = struct.unpack_from('<4f', b, 0)
    i = struct.unpack_from('<4I', b, 0)
    print('  tile %3d: float %s | int %s' % (t, ['%.3f' % x for x in f],
                                             ['%08X' % x for x in i]))

print()
print('=== 0x783650 / 0x783654 : первые 24 dword ===')
b = raw(0x783650, 96)
if b:
    vals = struct.unpack_from('<24I', b, 0)
    for i in range(0, 24, 6):
        print('  +%02X: %s' % (i * 4, ' '.join('%08X' % v for v in vals[i:i + 6])))
else:
    print('  вне секций')

print()
print('=== поиск: где в .rdata лежат строки "Mapping/Materials/Meshes/Objects/Anims" ===')
needle = b'C3DDB::Persist'
idx = data.find(needle)
while idx != -1:
    # найти VA
    va = None
    for vaddr, vsize, praw, psize, nm in secs:
        if praw <= idx < praw + psize:
            va = IMAGE_BASE + vaddr + (idx - praw)
            print('  строка по VA %08X (секция %s)' % (va, nm))
            break
    idx = data.find(needle, idx + 1)
    if idx == -1:
        break
