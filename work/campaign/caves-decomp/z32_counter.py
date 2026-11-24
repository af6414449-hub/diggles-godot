# -*- coding: utf-8 -*-
"""Корректная сверка (исправлен порядок полей заголовка секции PE):
   VirtualSize, VirtualAddress, SizeOfRawData, PointerToRawData."""
import struct

EXE = r'C:\diggles-ghidra\Diggles.exe'
data = open(EXE, 'rb').read()
pe = struct.unpack_from('<I', data, 0x3C)[0]
nsec = struct.unpack_from('<H', data, pe + 6)[0]
opt_size = struct.unpack_from('<H', data, pe + 20)[0]
sec_off = pe + 24 + opt_size

SECS = []
for i in range(nsec):
    o = sec_off + i * 40
    nm = data[o:o + 8].rstrip(b'\x00').decode('latin-1')
    vsize, vaddr, rawsz, rawptr = struct.unpack_from('<4I', data, o + 8)
    SECS.append((nm, vaddr, vsize, rawptr, rawsz))

for nm, vaddr, vsize, rawptr, rawsz in SECS:
    print('%-8s RVA %08X vsize %08X  rawptr %08X rawsize %08X'
          % (nm, vaddr, vsize, rawptr, rawsz))


def off_of(va):
    rva = va - 0x400000
    for nm, vaddr, vsize, rawptr, rawsz in SECS:
        if vaddr <= rva < vaddr + max(vsize, rawsz):
            return rawptr + (rva - vaddr)
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
    s = b[:z].decode('latin-1')
    return s if all(32 <= ord(c) < 127 for c in s) else None


print()
print('--- счётчик типов по VA 0x783650 ---')
b = raw(0x783650, 16)
print('  байты: %s' % ' '.join('%02X' % x for x in b))
print('  dword[0] = %d (ожидается 0 — счётчик)' % struct.unpack_from('<I', b, 0)[0])

print()
print('--- реестр типов 0x773650 + k*0x40 ---')
for k in range(6):
    b = raw(0x773650 + k * 0x40, 0x40)
    if not b:
        print('  вне секций'); break
    d = struct.unpack_from('<16I', b, 0)
    nm = cstr(d[15]) if 0x400000 < d[15] < 0xC000000 else None
    print('  тип %d: +00=%08X +04=%08X +08=%08X +3C=%08X -> %r'
          % (k, d[0], d[1], d[2], d[15], nm))

print()
print('--- имя типа по VA 0x71c7f4 (как в дизассемблере) ---')
print('  %r' % cstr(0x71c7f4))

print()
print('--- поиск всех строк "C3DDB::Persist" с корректным VA ---')
needle = b'C3DDB::Persist'
idx = data.find(needle)
while idx != -1:
    va = None
    for nm, vaddr, vsize, rawptr, rawsz in SECS:
        if rawptr <= idx < rawptr + rawsz:
            va = 0x400000 + vaddr + (idx - rawptr)
            print('  VA %08X  %r' % (va, data[idx:idx + 60].split(b'\x00')[0].decode('latin-1')))
            break
    idx = data.find(needle, idx + 1)
    if idx == -1:
        break
