"""З16 (итерация 2): точная реконструкция beautifier'а FUN_005a6b40.

Правило восстановлено построчно из декомпиляции:
  * сетка высот — карта 8x8 уровней блоков, построенная по расширенному
    прямоугольнику (x0-8 .. x1+8, y0-16 .. y1+2) в СУБ-КЛЕТКАХ;
  * фильтр 1: бит 7 байта материала клетки -> состояние 0;
  * фильтр 2: любой из 31 соседей с уровнем >= 14 -> состояние 0;
  * фильтр 3: состояние 3, если
        (h[r-1][c] + 2 < h[r][c]  и  h[r-8][c] + 2 < h[r][c])
     или (h[r][c] + 2 < h[r+1][c] и  h[r-15][c] + 2 < h[r+1][c]);
  * иначе состояние 1.
Область обработки: x в [max(x0, mapX0+24), min(x1, mapX1-24)),
                   y в [max(y0, mapY0+16), min(y1, mapY1-24)]  (в суб-клетках).
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
    assert len(out) == 64 * n, (len(out), 64 * n)
    return W, H, mat, blocks, bytes(out), tail


# 31 смещение (dRow, dCol) в суб-клетках, восстановлены из FUN_005a6b40
OFFS = [(-8, 0), (-15, -7), (-15, 7), (-15, 0), (-1, 0),
        (-8, -7), (-8, 7), (-3, -4), (-3, 4), (-5, -7),
        (-5, 7), (-12, -7), (-12, 7), (-15, -4), (-15, 4),
        (-12, 0), (-4, 0), (-8, -4), (-8, 4), (-13, -3),
        (-13, 3), (-11, -5), (-11, 5), (-10, -2), (-10, 2),
        (-6, -2), (-6, 2), (-5, -5), (-5, 5), (-2, -2), (-2, 2)]

# фильтр 3
STEP_A = ((-1, 0), (-8, 0))      # h[r-1]+2 < h[r]  и  h[r-8]+2 < h[r]
STEP_B = ((1, 0), (-15, 0))      # h[r]+2 < h[r+1]  и  h[r-15]+2 < h[r+1]


def build_grid(W, H, blocks, outside_level=None):
    """Сетка высот по расширенному прямоугольнику; внешние клетки зажаты к краю карты."""
    x0, y0 = 0, 0
    x1, y1 = W * 8, H * 8
    gx0, gy0 = x0 - 8, y0 - 16
    gw = (x1 + 8) - gx0
    gh = (y1 + 2) - gy0
    grid = bytearray(gw * gh)

    def cell_block(cx, cy):
        # зажатие координат клетки к границам карты (как FUN_00595e40)
        cx = max(0, min(W - 1, cx))
        cy = max(0, min(H - 1, cy))
        return block_map(blocks[cy * W + cx])

    for cy in range(-2, H + 1):
        for cx in range(-1, W + 1):
            bm = cell_block(cx, cy)
            # 8x8 блока -> в сетку, начиная с угла (0,0) блока
            # клетка (cx,cy) занимает в сетке суб-клетки [cx*8 .. cx*8+8) x [cy*8 .. cy*8+8)
            # но сетка начинается с gx0/gy0
            for r in range(8):
                gy = cy * 8 + r - gy0
                for c in range(8):
                    gx = cx * 8 + c - gx0
                    grid[gy * gw + gx] = bm[r * 8 + c]
    return grid, gw, gh, gx0, gy0


def beautify(W, H, mat, blocks, mapx0=0, mapy0=0, mapx1=None, mapy1=None):
    """Возвращает карту состояний 64 байта на клетку (индекс cell*64 + r*8 + c)."""
    if mapx1 is None:
        mapx1 = W
    if mapy1 is None:
        mapy1 = H
    grid, gw, gh, gx0, gy0 = build_grid(W, H, blocks)
    x0, y0, x1, y1 = 0, 0, W * 8, H * 8
    xl = max(x0, mapx0 * 8 + 24)
    xh = min(x1, mapx1 * 8 - 24)
    yl = max(y0, mapy0 * 8 + 16)
    yh = min(y1, mapy1 * 8 - 24)
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
            r = (gy - cy * 8)
            c = (gx - cx * 8)
            out[base + r * 8 + c] = st
    return out


def compare(pmp_path, verbose=True):
    W, H, mat, blocks, rle, tail = parse_pmp(pmp_path)
    pred = beautify(W, H, mat, blocks)
    hist = Counter()
    match = 0
    for i in range(64 * W * H):
        hist[(rle[i], pred[i])] += 1
        if rle[i] == pred[i]:
            match += 1
    total = 64 * W * H
    if verbose:
        print(f"\n== {os.path.basename(pmp_path)}  {W}x{H} ==")
        print(f"  совпало {match}/{total} = {100.0*match/total:.1f}%")
        for (w, g), c in sorted(hist.items()):
            print(f"    pmp={w} пред={g}: {c}{'' if w == g else '   <-- расхождение'}")
    return match, total


T = os.path.join(GAME, "Templates", "pmp")
cands = []
for root, dirs, files in os.walk(os.path.join(GAME, "Templates")):
    for f in files:
        if f.lower().endswith(".pmp") and f.startswith("caves_"):
            cands.append(os.path.join(root, f))
cands.sort()
for p in cands:
    compare(p)
