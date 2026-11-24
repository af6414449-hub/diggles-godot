import os, struct, sys, itertools
from collections import Counter

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
sys.path.insert(0, os.path.join(ROOT, "tools"))
from inspect_bdb import BdbDatabase, _METADATA_BYTES

BDB = BdbDatabase(os.path.join(GAME, "BlockDB0.BDB"))
META_OFF = BDB.sections["opaque_block_metadata"]["offset"]
_cache = {}
def block_map(bid):
    if bid not in _cache:
        m = BDB.data[META_OFF + bid * _METADATA_BYTES: META_OFF + (bid + 1) * _METADATA_BYTES]
        _cache[bid] = list(m[:64])
    return _cache[bid]

def parse_pmp(path):
    d = open(path, "rb").read()
    W, H = struct.unpack_from("<ii", d, 0); o = 8
    n = W * H
    mat = d[o:o + n]; o += n
    blocks = struct.unpack_from(f"<{n}i", d, o); o += 4 * n
    cnt = struct.unpack_from("<i", d, o)[0]; o += 4
    rle = d[o:o + cnt * 2]; o += cnt * 2
    out = bytearray()
    for i in range(cnt):
        v = struct.unpack_from("<H", rle, i * 2)[0]
        ln = v >> 2
        if ln == 0:
            ln = 0x4000
        out.extend(bytes([v & 3]) * ln)
    return W, H, mat, blocks, out

OFFS = [(-1, 0), (-2, -2), (-2, 2), (-3, -4), (-3, 4), (-4, -4), (-4, 4),
        (-5, 0), (-5, -7), (-5, 7), (-6, -2), (-6, 2), (-8, 0), (-8, -7), (-8, 7),
        (-10, -2), (-10, 2), (-11, -5), (-11, 5), (-12, -7), (-12, 7),
        (-13, -3), (-13, 3), (-15, 0), (-15, -7), (-15, 7),
        (-5, 0), (-4, -4), (-4, 4), (-2, -2), (-2, 2)]

def transform_offs(mode):
    if mode == "base":
        return OFFS
    if mode == "swap":
        return [(dc, dr) for dr, dc in OFFS]
    if mode == "negrow":
        return [(-dr, dc) for dr, dc in OFFS]
    if mode == "negcol":
        return [(dr, -dc) for dr, dc in OFFS]
    if mode == "negboth":
        return [(-dr, -dc) for dr, dc in OFFS]
    if mode == "swapneg":
        return [(-dc, -dr) for dr, dc in OFFS]
    raise ValueError(mode)

def build_grid(W, H, blocks, mapmode, outside):
    W8, H8 = W * 8, H * 8
    g = [[outside] * W8 for _ in range(H8)]
    for cy in range(H):
        for cx in range(W):
            bm = block_map(blocks[cy * W + cx])
            for r in range(8):
                for c in range(8):
                    if mapmode == "row":
                        v = bm[r * 8 + c]; gr, gc = cy * 8 + r, cx * 8 + c
                    elif mapmode == "col":
                        v = bm[c * 8 + r]; gr, gc = cy * 8 + r, cx * 8 + c
                    elif mapmode == "flipx":
                        v = bm[r * 8 + (7 - c)]; gr, gc = cy * 8 + r, cx * 8 + c
                    elif mapmode == "flipy":
                        v = bm[(7 - r) * 8 + c]; gr, gc = cy * 8 + r, cx * 8 + c
                    elif mapmode == "flipxy":
                        v = bm[(7 - r) * 8 + (7 - c)]; gr, gc = cy * 8 + r, cx * 8 + c
                    g[gr][gc] = v
    return g, W8, H8

def score(pmp_path, omode, mapmode, outside=15):
    W, H, mat, blocks, rle = parse_pmp(pmp_path)
    g, W8, H8 = build_grid(W, H, blocks, mapmode, outside)
    offs = transform_offs(omode)
    def h(gx, gy):
        if 0 <= gx < W8 and 0 <= gy < H8:
            return g[gy][gx]
        return outside
    match = total = 0
    for cy in range(H):
        for cx in range(W):
            base = (cy * W + cx) * 64
            for r in range(8):
                for c in range(8):
                    gx, gy = cx * 8 + c, cy * 8 + r
                    want = rle[base + r * 8 + c]
                    if (mat[cy * W + cx] & 0x80):
                        got = 0
                    else:
                        got = 1
                        for dr, dc in offs:
                            if h(gx + dc, gy + dr) >= 14:
                                got = 0
                                break
                        if got:
                            for dr in (-1, 1):
                                if abs(h(gx, gy + dr) - h(gx, gy)) >= 3:
                                    got = 3
                                    break
                    total += 1
                    if want == got:
                        match += 1
    return match, total

files = []
for root, dirs, fs in os.walk(os.path.join(GAME, "Templates")):
    for f in fs:
        if f.lower().endswith(".pmp") and f.startswith("caves_") and f in ("caves_1.pmp","caves_3.pmp"):
            files.append(os.path.join(root, f))
files = sorted(set(files))

print(f"{'offsets':10s} {'map':8s} " + " ".join(f"{os.path.basename(f):>12s}" for f in files))
best = []
for omode in ("base", "swap", "negrow", "negcol", "negboth", "swapneg"):
    for mapmode in ("row", "col", "flipx", "flipy", "flipxy"):
        cells = []
        tot_pct = 0
        for f in files:
            m, t = score(f, omode, mapmode)
            cells.append(f"{100.0*m/t:11.1f}%")
            tot_pct += 100.0 * m / t
        avg = tot_pct / len(files)
        best.append((avg, omode, mapmode))
        print(f"{omode:10s} {mapmode:8s} " + " ".join(cells) + f"   avg={avg:.1f}%")
best.sort(reverse=True)
print("\nTOP:", best[:5])
