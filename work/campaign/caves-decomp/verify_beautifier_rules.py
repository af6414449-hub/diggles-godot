import os, struct, sys
from collections import Counter

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
sys.path.insert(0, os.path.join(ROOT, "tools"))
from inspect_bdb import BdbDatabase, _METADATA_BYTES

BDB = BdbDatabase(os.path.join(GAME, "BlockDB0.BDB"))
META_OFF = BDB.sections["opaque_block_metadata"]["offset"]
_c = {}
def block_map(bid):
    if bid not in _c:
        m = BDB.data[META_OFF + bid * _METADATA_BYTES: META_OFF + (bid + 1) * _METADATA_BYTES]
        _c[bid] = list(m[:64])
    return _c[bid]

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

def grid_of(W, H, blocks, outside, flipxy=False):
    W8, H8 = W * 8, H * 8
    g = [[outside] * W8 for _ in range(H8)]
    for cy in range(H):
        for cx in range(W):
            bm = block_map(blocks[cy * W + cx])
            for r in range(8):
                for c in range(8):
                    rr, cc = (7 - r, 7 - c) if flipxy else (r, c)
                    g[cy * 8 + r][cx * 8 + c] = bm[rr * 8 + cc]
    return g, W8, H8

RULES = {
 "только своя":            [(0, 0)],
 "3x3 (r-1..r+1,c-1..c+1)": [(dr, dc) for dr in (-1, 0, 1) for dc in (-1, 0, 1)],
 "строка r-1, 3 колонки":  [(-1, dc) for dc in (-1, 0, 1)],
 "строка r-1, 1 колонка":  [(-1, 0)],
 "5x5":                     [(dr, dc) for dr in range(-2, 3) for dc in range(-2, 3)],
 "круг R=8 (соседи)":      [(dr, dc) for dr in range(-8, 9) for dc in range(-8, 9)
                             if 0 < dr * dr + dc * dc <= 64],
 "круг R=15":              [(dr, dc) for dr in range(-15, 16) for dc in range(-15, 16)
                             if 0 < dr * dr + dc * dc <= 225],
 "полукруг R=15 (вверх)":  [(dr, dc) for dr in range(-15, 1) for dc in range(-15, 16)
                             if 0 < dr * dr + dc * dc <= 225],
 "полукруг R=15 (вниз)":  [(dr, dc) for dr in range(0, 16) for dc in range(-15, 16)
                             if 0 < dr * dr + dc * dc <= 225],
 "полукруг R=8 (вверх)":   [(dr, dc) for dr in range(-8, 1) for dc in range(-8, 9)
                             if 0 < dr * dr + dc * dc <= 64],
}

def evaluate(pmp_path, offs, outside=15, flipxy=False, thresh=14, step=3):
    W, H, mat, blocks, rle = parse_pmp(pmp_path)
    g, W8, H8 = grid_of(W, H, blocks, outside, flipxy)
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
                    if mat[cy * W + cx] & 0x80:
                        got = 0
                    else:
                        got = 1
                        for dr, dc in offs:
                            if h(gx + dc, gy + dr) >= thresh:
                                got = 0
                                break
                        if got:
                            for dr in (-1, 1):
                                if abs(h(gx, gy + dr) - h(gx, gy)) >= step:
                                    got = 3
                                    break
                    total += 1
                    if want == got:
                        match += 1
    return match, total

files = sorted({os.path.join(r, f) for r, d, fs in os.walk(os.path.join(GAME, "Templates"))
                for f in fs if f in ("caves_1.pmp", "caves_3.pmp", "caves_4.pmp")})

print(f"{'rule':32s} " + " ".join(f"{os.path.basename(f):>12s}" for f in files) + "    avg")
for name, offs in RULES.items():
    cells, tot = [], 0.0
    for f in files:
        m, t = evaluate(f, offs)
        cells.append(f"{100.0*m/t:11.1f}%")
        tot += 100.0 * m / t
    print(f"{name:32s} " + " ".join(cells) + f"  {tot/len(files):5.1f}%")

print("\n--- порог и шаг для лучших правил ---")
for name in ("3x3 (r-1..r+1,c-1..c+1)", "полукруг R=15 (вверх)"):
    offs = RULES[name]
    for th in (12, 13, 14, 15):
        m, t = evaluate(files[0], offs, thresh=th)
        print(f"  {name} thresh={th}: {100.0*m/t:.1f}%  ({os.path.basename(files[0])})")
    for st in (2, 3, 4):
        m, t = evaluate(files[0], offs, step=st)
        print(f"  {name} step={st}: {100.0*m/t:.1f}%  ({os.path.basename(files[0])})")
