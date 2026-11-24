# -*- coding: utf-8 -*-
"""Проверка: DAT_00773650 — реестр типов объектов (шаг 0x40) или склейка RTTI-vtable Ghidra?"""
import struct, sys

EXE = r'C:\diggles-ghidra\Diggles.exe'
IMAGE_BASE = 0x400000

data = open(EXE, 'rb').read()
pe = struct.unpack_from('<I', data, 0x3C)[0]
nsec = struct.unpack_from('<H', data, pe + 6)[0]
opt_size = struct.unpack_from('<H', data, pe + 20)[0]
sec_off = pe + 24 + opt_size


def rva_to_off(rva):
    for i in range(nsec):
        o = sec_off + i * 40
        vaddr = struct.unpack_from('<I', data, o + 12)[0]
        vsize = struct.unpack_from('<I', data, o + 8)[0]
        praw = struct.unpack_from('<I', data, o + 20)[0]
        psize = struct.unpack_from('<I', data, o + 16)[0]
        if vaddr <= rva < vaddr + max(vsize, psize):
            return praw + (rva - vaddr)
    return None


def read_va(va, n):
    off = rva_to_off(va - IMAGE_BASE)
    if off is None:
        return None
    return data[off:off + n]


def cstr_at(va, maxn=64):
    b = read_va(va, maxn)
    if not b:
        return None
    z = b.find(b'\x00')
    if z < 0:
        return None
    try:
        return b[:z].decode('latin-1')
    except Exception:
        return None


BASE = 0x773650
print('=== дамп 0x40 x N по VA 0x%X ===' % BASE)
for k in range(8):
    va = BASE + k * 0x40
    raw = read_va(va, 0x40)
    if raw is None:
        print('%2d  <вне секций>' % k)
        continue
    dwords = struct.unpack_from('<16I', raw, 0)
    nameptr = dwords[15]
    nm = cstr_at(nameptr) if 0x400000 < nameptr < 0x800000 else None
    print('%2d  vtable=%08X  +30=%08X +34=%08X +38=%08X +3C=%08X -> %r'
          % (k, dwords[0], dwords[12], dwords[13], dwords[14], nameptr, nm))

print()
print('=== как выглядит указатель +0x3C у первых записей (проверка на строку) ===')
for k in range(6):
    va = BASE + k * 0x40
    raw = read_va(va, 0x40)
    if not raw:
        continue
    dwords = struct.unpack_from('<16I', raw, 0)
    for off in (0, 12, 13, 14, 15):
        p = dwords[off]
        s = cstr_at(p) if 0x400000 < p < 0x800000 else None
        if s:
            print('  запись %d, поле +%02X -> %08X = %r' % (k, off * 4, p, s))
