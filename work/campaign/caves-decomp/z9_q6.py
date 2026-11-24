# -*- coding: utf-8 -*-
"""З9: знаковые ли высоты в BlockDB; уровень субклетки под объектами."""
import struct, os, collections

G = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"

# --- 1. гистограмма байтов сетки высот во всех BlockDB ---
hist = collections.Counter()
neg = collections.Counter()
tot = 0
blocks = {}
for db in (0, 1, 2):
    p = os.path.join(G, "BlockDB%d.BDB" % db)
    if not os.path.exists(p):
        continue
    d = open(p, "rb").read()
    u32 = lambda o: struct.unpack_from("<I", d, o)[0]
    N = u32(8)
    block_off = 28 + 18 * N
    print("BlockDB%d: N=%d size=%d" % (db, N, len(d)))
    for i in range(N):
        o = block_off + i * 0x59
        g = d[o:o + 64]
        hist.update(g)
        tot += 64
        blocks[i] = (min(g), max(g), g)
print("всего байт сетки:", tot)
print("гистограмма значений сетки (байт):")
for v in sorted(hist):
    s = v - 256 if v > 127 else v
    print("   %3d (signed %4d): %d" % (v, s, hist[v]))
hi = max(hist)
print("макс байт =", hi, "-> signed", hi - 256 if hi > 127 else hi)
