# -*- coding: utf-8 -*-
"""З9: сетка высот блока + дочерние блоки; уровень субклетки под объектом."""
import struct, os

G = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"

BDB = {}
for db in (0, 1, 2):
    p = os.path.join(G, "BlockDB%d.BDB" % db)
    if not os.path.exists(p):
        continue
    d = open(p, "rb").read()
    N = struct.unpack_from("<I", d, 8)[0]
    block_off = 28 + 18 * N
    for i in range(N):
        o = block_off + i * 0x59
        BDB[i] = (d[o:o + 64], struct.unpack_from("<4i", d, o + 0x40))


def show(bid):
    g, ch = BDB[bid]
    print("--- блок %d: сетка 8x8 (значения = уровни) ---" % bid)
    for r in range(8):
        print("   ", " ".join("%2d" % b for b in g[r * 8:r * 8 + 8]))
    print("    дети (+0x40..0x4c):", ch)
    for k, c in enumerate(ch):
        if c >= 0:
            cg = BDB[c][0]
            print("   Quadrant %d -> блок %d: min=%d max=%d" % (k, c, min(cg), max(cg)))
            for r in range(8):
                print("        ", " ".join("%2d" % b for b in cg[r * 8:r * 8 + 8]))


for b in (71, 81, 13868, 59, 0):
    show(b)
