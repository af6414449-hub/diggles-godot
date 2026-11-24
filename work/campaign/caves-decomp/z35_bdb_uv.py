# -*- coding: utf-8 -*-
"""Читает таблицу вершин BlockDB (x,y,z,u,v) по формуле FUN_00565ab0 и печатает
диапазоны UV. Цель — проверить, равен ли UV диапазону 0..1 внутри клетки."""
import struct, sys, os

GAME = r'C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data'

def u32(f, off):
    f.seek(off); return struct.unpack('<I', f.read(4))[0]

def analyse(path):
    size = os.path.getsize(path)
    with open(path, 'rb') as f:
        hdr = struct.unpack('<7I', f.read(28))
        n_blocks, n_u16, n_h, n_vert = hdr[2], hdr[4], hdr[5], hdr[6]
        off_mesh = 0x1C
        off_blocks = off_mesh + 18 * n_blocks
        off_u16 = off_blocks + 0x59 * n_blocks
        off_heights = off_u16 + 2 * n_u16
        off_verts = off_heights + 8 * n_h
        end_verts = off_verts + 20 * n_vert
        print('=== %s' % os.path.basename(path))
        print('  file size      : %d' % size)
        print('  header         : %s' % (hdr,))
        print('  N_blocks       : %d' % n_blocks)
        print('  mesh table @   : 0x%X (%d B)' % (off_mesh, 18 * n_blocks))
        print('  blocks array @ : 0x%X (step 0x59)' % off_blocks)
        print('  uint16 array @ : 0x%X (n=%d)' % (off_u16, n_u16))
        print('  heights array @: 0x%X (n=%d)' % (off_heights, n_h))
        print('  VERTEX table @ : 0x%X (n=%d, 20 B each)' % (off_verts, n_vert))
        print('  end of verts   : 0x%X  | tail left = %d B' % (end_verts, size - end_verts))
        if off_verts + 20 * n_vert > size:
            print('  !! vertex table does not fit in file')
            return
        f.seek(off_verts)
        blob = f.read(20 * n_vert)
        xs = []; ys = []; zs = []; us = []; vs = []
        for i in range(n_vert):
            x, y, z, u, v = struct.unpack('<5f', blob[i*20:(i+1)*20])
            xs.append(x); ys.append(y); zs.append(z); us.append(u); vs.append(v)
        def rng(name, arr):
            print('  %-3s min=%9.4f max=%9.4f   first10=%s' % (
                name, min(arr), max(arr),
                ' '.join('%.3f' % a for a in arr[:10])))
        rng('X', xs); rng('Y', ys); rng('Z', zs); rng('U', us); rng('V', vs)
        # распределение по "углам": пары (u,v) -> частоты
        from collections import Counter
        c = Counter((round(u, 4), round(v, 4)) for u, v in zip(us, vs))
        print('  distinct (u,v) pairs: %d' % len(c))
        print('  top 12 pairs: %s' % sorted(c.items(), key=lambda kv: -kv[1])[:12])

for name in ('BlockDB0.BDB', 'BlockDB1.BDB', 'BlockDB2.BDB'):
    p = os.path.join(GAME, name)
    if os.path.exists(p):
        analyse(p)
    else:
        print('missing %s' % p)
