# -*- coding: utf-8 -*-
"""Ищет в Diggles.exe таблицу пар {указатель на имя, значение} реестра
материалов/техник и печатает её целиком (имя -> значение)."""
import struct

EXE = r'C:\diggles-ghidra\Diggles.exe'
IMAGE_BASE = 0x400000

data = open(EXE, 'rb').read()

# --- секции PE ---
e_lfanew = struct.unpack_from('<I', data, 0x3C)[0]
nsec = struct.unpack_from('<H', data, e_lfanew + 6)[0]
optsz = struct.unpack_from('<H', data, e_lfanew + 20)[0]
sec_off = e_lfanew + 24 + optsz
sections = []
for i in range(nsec):
    o = sec_off + 40 * i
    name = data[o:o + 8].rstrip(b'\x00').decode('ascii', 'replace')
    vs, va, rs, pr = struct.unpack_from('<IIII', data, o + 8)
    sections.append((name, va, vs, pr, rs))


def rva2off(rva):
    for name, va, vs, pr, rs in sections:
        if va <= rva < va + max(vs, rs):
            return pr + (rva - va)
    return None


def cstr(off, limit=64):
    end = data.find(b'\x00', off)
    if end < 0 or end - off > limit:
        return None
    try:
        return data[off:end].decode('ascii')
    except Exception:
        return None


# --- ищем указатели на известные имена ---
targets = {
    0x722DC4: 'model',
    0x722DCC: 'scape_st',
    0x722E18: 'fogofwar',
    0x722E7C: 'water_mt0',
}
hits = []
for rva, nm in targets.items():
    needle = struct.pack('<I', IMAGE_BASE + rva)
    pos = 0
    while True:
        p = data.find(needle, pos)
        if p < 0:
            break
        # определить, в какой секции лежит p, и какой это RVA
        r = None
        for name, va, vs, pr, rs in sections:
            if pr <= p < pr + rs:
                r = va + (p - pr)
                break
        if r is not None:
            hits.append((r, nm))
        pos = p + 1
print('указатели найдены (RVA):', hits)

if hits:
    r0 = min(h[0] for h in hits)
    off0 = rva2off(r0)
    print('--- таблица начиная с RVA 0x%X ---' % r0)
    # пары {ptr, int}: ptr на имя в образе
    k = 0
    while k < 120:
        p = off0 + k * 8
        ptr, val = struct.unpack_from('<Ii', data, p)
        rr = None
        for name, va, vs, pr, rs in sections:
            if pr <= p < pr + rs:
                rr = va + (p - pr)
                break
        if rr is None:
            break
        if IMAGE_BASE <= ptr < IMAGE_BASE + 0x1000000:
            so = rva2off(ptr - IMAGE_BASE)
            s = cstr(so) if so is not None else None
        else:
            s = None
        if s is None:
            break
        print('  %3d  %-26s = %d' % (k, s, val))
        k += 1
