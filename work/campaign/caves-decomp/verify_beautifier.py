import os, struct, sys
from collections import Counter

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
sys.path.insert(0, os.path.join(ROOT, "tools"))
from inspect_bdb import BdbDatabase, _METADATA_BYTES

BDB = BdbDatabase(os.path.join(GAME, "BlockDB0.BDB"))
META_OFF = BDB.sections["opaque_block_metadata"]["offset"]

def block_map(bid):
    m = BDB.data[META_OFF + bid * _METADATA_BYTES: META_OFF + (bid + 1) * _METADATA_BYTES]
    return list(m[:64])

def parse_pmp(path):
    d = open(path, "rb").read()
    W, H = struct.unpack_from("<ii", d, 0); o = 8
    n = W * H
    mat = d[o:o + n]; o += n
    blocks = struct.unpack_from(f"<{n}i", d, o); o += 4 * n
    cnt = struct.unpack_from("<i", d, o)[0]; o += 4
    rle = d[o:o + cnt * 2]; o += cnt * 2
    tail = d[o:o + n]
    out = bytearray()
    for i in range(cnt):
        v = struct.unpack_from("<H", rle, i * 2)[0]
        ln = v >> 2
        if ln == 0:
            ln = 0x4000
        out.extend(bytes([v & 3]) * ln)
    return W, H, mat, blocks, out

# смещения 31 проверок (dRow, dCol) в суб-клетках
OFFS = [(-1, 0), (-2, -2), (-2, 2), (-3, -4), (-3, 4), (-4, -4), (-4, 4),
        (-5, 0), (-5, -7), (-5, 7), (-6, -2), (-6, 2), (-8, 0), (-8, -7), (-8, 7),
        (-10, -2), (-10, 2), (-11, -5), (-11, 5), (-12, -7), (-12, 7),
        (-13, -3), (-13, 3), (-15, 0), (-15, -7), (-15, 7),
        (-5, 0), (-4, -4), (-4, 4), (-2, -2), (-2, 2)]

def run(pmp_path, outside_level, verbose=True):
    W, H, mat, blocks, rle = parse_pmp(pmp_path)
    # карта высот по всей карте (суб-клетки), 0 = вне области .pmp
    # индекс: (gx, gy) в суб-клетках, gx в [0, W*8), gy в [0, H*8)
    W8, H8 = W * 8, H * 8
    hmap = [[outside_level] * W8 for _ in range(H8)]
    for cy in range(H):
        for cx in range(W):
            bm = block_map(blocks[cy * W + cx])
            for r in range(8):
                for c in range(8):
                    hmap[cy * 8 + r][cx * 8 + c] = bm[r * 8 + c]

    def h(gx, gy):
        if 0 <= gx < W8 and 0 <= gy < H8:
            return hmap[gy][gx]
        return outside_level

    match = 0
    total = 0
    hist = Counter()
    for cy in range(H):
        for cx in range(W):
            base = (cy * W + cx) * 64
            for r in range(8):
                for c in range(8):
                    gx, gy = cx * 8 + c, cy * 8 + r
                    want = rle[base + r * 8 + c]
                    # фильтр 1: бит 7 байта материала
                    if (mat[cy * W + cx] & 0x80) != 0:
                        got = 0
                    else:
                        # фильтр 2: 31 соседей
                        bad = False
                        for dr, dc in OFFS:
                            if h(gx + dc, gy + dr) >= 14:
                                bad = True
                                break
                        if bad:
                            got = 0
                        else:
                            got = 1
                            # фильтр 3: ступенька (разница >= 3 уровней со строкой +-1)
                            for dr in (-1, 1):
                                hv = h(gx, gy + dr)
                                if abs(hv - h(gx, gy)) >= 3:
                                    got = 3
                                    break
                    hist[(want, got)] += 1
                    total += 1
                    if want == got:
                        match += 1
    if verbose:
        print(f"\n== {os.path.basename(pmp_path)} outside_level={outside_level} ==")
        print(f"  совпало {match}/{total} = {100.0*match/total:.1f}%")
        for (w, g), c in sorted(hist.items()):
            flag = "" if w == g else "   <-- расхождение"
            print(f"    pmp={w} формула={g}: {c}{flag}")
    return match, total

T = os.path.join(GAME, "Templates", "pmp")
cands = []
for root, dirs, files in os.walk(os.path.join(GAME, "Templates")):
    for f in files:
        if f.lower().endswith(".pmp") and f.startswith("caves_"):
            cands.append(os.path.join(root, f))
cands.sort()
print("candidates:", [os.path.basename(c) for c in cands])

for p in cands[:4]:
    for ol in (0, 15):
        run(p, ol)
