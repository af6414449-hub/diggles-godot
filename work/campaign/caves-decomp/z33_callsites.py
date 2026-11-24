# -*- coding: utf-8 -*-
"""Сканер call-сайтов: ищет E8 rel32 -> target и печатает окружение."""
import struct, sys

EXE = r'C:\diggles-ghidra\Diggles.exe'
data = open(EXE, 'rb').read()
pe = struct.unpack_from('<I', data, 0x3C)[0]
nsec = struct.unpack_from('<H', data, pe + 6)[0]
opt_size = struct.unpack_from('<H', data, pe + 20)[0]
sec_off = pe + 24 + opt_size
TEXT = None
for i in range(nsec):
    o = sec_off + i * 40
    nm = data[o:o + 8].rstrip(b'\x00').decode('latin-1')
    vsize, vaddr, rawsz, rawptr = struct.unpack_from('<4I', data, o + 8)
    if nm == '.text':
        TEXT = (0x400000 + vaddr, rawptr, rawsz)

base, rawptr, rawsz = TEXT
body = data[rawptr:rawptr + rawsz]

TARGETS = {0x0043fd30: 'FUN_0043fd30', 0x00405af0: 'FUN_00405af0'}

hits = []
for i in range(len(body) - 5):
    if body[i] != 0xE8:
        continue
    rel = struct.unpack_from('<i', body, i + 1)[0]
    tgt = base + i + 5 + rel
    if tgt in TARGETS:
        hits.append((base + i, tgt))

print('найдено call-сайтов: %d' % len(hits))
want = sys.argv[1] if len(sys.argv) > 1 else None
for va, tgt in hits:
    if want and TARGETS[tgt] != want:
        continue
    print('\n--- call %s @ %08X ---' % (TARGETS[tgt], va))
    off = rawptr + (va - base)
    start = max(rawptr, off - 40)
    for j in range(start, off + 10):
        va2 = base + (j - rawptr)
        b = data[j]
        if b == 0xE8:
            rel = struct.unpack_from('<i', data, j + 1)[0]
            print('  %08X: call %08X' % (va2, va2 + 5 + rel))
        else:
            print('  %08X: %02X' % (va2, b))
        if j == off + 4:
            break
