import struct, sys, collections

P = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\BlockDB0.BDB"
d = open(P, "rb").read()
u32 = lambda o: struct.unpack_from("<I", d, o)[0]

hdr = [u32(i * 4) for i in range(7)]
print("size:", len(d))
print("header dwords[0..6]:", hdr)

N = hdr[2]
print("assumed numBlocks =", N)

mesh_off = 28
block_off = mesh_off + 18 * N
print("mesh section:", mesh_off, "..", block_off, " (18 B per block)")
print("block array at:", block_off, " size:", N * 0x59, " end:", block_off + N * 0x59)

# sanity: mesh records of block 0
for i in range(3):
    o = mesh_off + i * 6
    print("  mesh rec %d: mat=%d off=%d" % (i, struct.unpack_from("<H", d, o)[0], struct.unpack_from("<I", d, o + 2)[0]))

def show_block(i):
    o = block_off + i * 0x59
    grid = d[o:o + 64]
    print("--- block %d @ %d ---" % (i, o))
    for r in range(8):
        print("   ", " ".join("%2d" % b for b in grid[r * 8:r * 8 + 8]))
    ch = struct.unpack_from("<4i", d, o + 0x40)
    print("   children(+0x40):", ch)
    print("   +0x50..0x53:", d[o + 0x50:o + 0x54].hex())
    print("   +0x54:", hex(d[o + 0x54]), " +0x55:", hex(d[o + 0x55]), " +0x58:", hex(d[o + 0x58]))
    return grid

for i in (0, 1, 2, 17, 100):
    if i < N:
        show_block(i)

# распределение значений сетки по всему массиву блоков
vals = collections.Counter()
maxv = 0
for i in range(0, min(N, 4000)):
    o = block_off + i * 0x59
    g = d[o:o + 64]
    vals.update(g)
    if max(g) > maxv:
        maxv = max(g)
print("grid value histogram (first %d blocks):" % min(N, 4000), sorted(vals.items())[:20], "max =", maxv)
