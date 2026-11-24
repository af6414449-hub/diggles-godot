"""З16 (итерация 3): перебор вариантов контекста для точной формулы beautifier'а.

Параметры:
  margin_x, margin_y_lo, margin_y_hi — отступы рабочей области (в суб-клетках),
  outside                         — 'clamp' (как FUN_00595e40) или уровень 0/15.
"""
import os
import struct
import sys
from collections import Counter

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
sys.path.insert(0, os.path.join(ROOT, "tools"))
from inspect_bdb import BdbDatabase, _METADATA_BYTES  # noqa: E402

BDB = BdbDatabase(os.path.join(GAME, "BlockDB0.BDB"))
META_OFF = BDB.sections["opaque_block_metadata"]["offset"]
_cache = {}


def block_map(bid):
    m = _cache.get(bid)
    if m is None:
        raw = BDB.data[META_OFF + bid * _METADATA_BYTES: META_OFF + (bid + 1) * _METADATA_BYTES]
        m = bytes(raw[:64])
        _cache[bid] = m
    return m


def parse_pmp(path):
    d = open(path, "rb").read()
    W, H = struct.unpack_from("<ii", d, 0)
    o = 8
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
    assert len(out) == 64 * n
    return W, H, mat, blocks, bytes(out)


OFFS = [(-8, 0), (-15, -7), (-15, 7), (-15, 0), (-1, 0),
        (-8, -7), (-8, 7), (-3, -4), (-3, 4), (-5, -7),
        (-5, 7), (-12, -7), (-12, 7), (-15, -4), (-15, 4),
        (-12, 0), (-4, 0), (-8, -4), (-8, 4), (-13, -3),
        (-13, 3), (-11, -5), (-11, 5), (-10, -2), (-10, 2),
        (-6, -2), (-6, 2), (-5, -5), (-5, 5), (-2, -2), (-2, 2)]


def build_grid(W, H, blocks, outside):
    gx0, gy0 = -8, -16
    gw = W * 8 + 16
    gh = H * 8 + 18 + 32          # +32 запаса
    grid = bytearray(gw * gh)

    def cell_block(cx, cy):
        if outside == "clamp":
            cx = max(0, min(W - 1, cx))
            cy = max(0, min(H - 1, cy))
            return block_map(blocks[cy * W + cx])
        return bytes([outside] * 64)

    for cy in range(-2, H + 2):
        for cx in range(-2, W + 2):
            bm = cell_block(cx, cy)
            for r in range(8):
                gy = cy * 8 + r - gy0
                if not (0 <= gy < gh):
                    continue
                for c in range(8):
                    gx = cx * 8 + c - gx0
                    if 0 <= gx < gw:
                        grid[gy * gw + gx] = bm[r * 8 + c]
    return grid, gw, gh, gx0, gy0


def beautify(W, H, mat, blocks, outside="clamp", mx=0, mylo=0, myhi=0):
    grid, gw, gh, gx0, gy0 = build_grid(W, H, blocks, outside)
    x0, y0, x1, y1 = 0, 0, W * 8, H * 8
    xl = max(x0, mx)
    xh = min(x1, W * 8 - mx)
    yl = max(y0, mylo)
    yh = min(y1, H * 8 - myhi)
    out = bytearray(64 * W * H)

    def h(gx, gy):
        return grid[(gy - gy0) * gw + (gx - gx0)]

    for gy in range(yl, yh):
        for gx in range(xl, xh):
            cx = (gx + 4) >> 3
            cy = (gy + 4) >> 3
            if cx < 0 or cx >= W or cy < 0 or cy >= H:
                continue
            if mat[cy * W + cx] & 0x80:
                continue
            st = 1
            bad = False
            for dr, dc in OFFS:
                if h(gx + dc, gy + dr) >= 14:
                    bad = True
                    break
            if bad:
                st = 0
            else:
                hc = h(gx, gy)
                if (h(gx, gy - 1) + 2 < hc) and (h(gx, gy - 8) + 2 < hc):
                    st = 3
                elif (hc + 2 < h(gx, gy + 1)) and (h(gx, gy - 15) + 2 < h(gx, gy + 1)):
                    st = 3
            base = (cy * W + cx) * 64
            out[base + (gy - cy * 8) * 8 + (gx - cx * 8)] = st
    return out


def compare(pmp_path, **kw):
    W, H, mat, blocks, rle = parse_pmp(pmp_path)
    pred = beautify(W, H, mat, blocks, **kw)
    hist = Counter()
    match = 0
    for i in range(64 * W * H):
        hist[(rle[i], pred[i])] += 1
        if rle[i] == pred[i]:
            match += 1
    return match, 64 * W * H, hist, rle, pred


T = os.path.join(GAME, "Templates", "pmp")
cands = []
for root, dirs, files in os.walk(os.path.join(GAME, "Templates")):
    for f in files:
        if f.lower().endswith(".pmp") and f.startswith("caves_"):
            cands.append(os.path.join(root, f))
cands.sort()

VARIANTS = [
    ("clamp, no margins", dict(outside="clamp", mx=0, mylo=0, myhi=0)),
    ("clamp, m 24/16/24", dict(outside="clamp", mx=24, mylo=16, myhi=24)),
    ("level 15, no margins", dict(outside=15, mx=0, mylo=0, myhi=0)),
    ("level 0, no margins", dict(outside=0, mx=0, mylo=0, myhi=0)),
]

for p in cands:
    print(f"\n=== {os.path.basename(p)} ===")
    for name, kw in VARIANTS:
        match, total, hist, rle, pred = compare(p, **kw)
        print(f"  {name:26s} {100.0*match/total:6.1f}%   " +
              " ".join(f"pmp{a}/pred{b}:{c}" for (a, b), c in sorted(hist.items()) if a != b))
    # где в RLE ненулевые значения (для проверки полей)
    W, H, mat, blocks, rle = parse_pmp(p)
    nz = [i for i, v in enumerate(rle) if v]
    cells_nz = sorted(set(i // 64 for i in nz))
    print(f"  RLE: ненулевых {len(nz)}, затронуто клеток {len(cells_nz)} из {W*H}")
    print(f"  клетки: {[ (c % W, c // W) for c in cells_nz[:24] ]}")
