"""З16 (итог): проверка гипотезы «RLE .pmp = результат beautifier'а в контексте карты».

Для каждого шаблона главы с .pmp:
  A) контекст = клетки самого шаблона (как при авторинге в редакторе),
     края зажаты к границам шаблона (FUN_00595e40);
  B) контекст = карта главы целиком (native_campaign_chapter.json -> ID блоков -> BDB).
Сравнивается с RLE-картой .pmp.
"""
import json
import os
import struct
import sys
from collections import Counter

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
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
    words = struct.unpack_from(f"<{cnt}H", d, o); o += 2 * cnt
    out = bytearray()
    for v in words:
        ln = v >> 2
        if ln == 0:
            ln = 0x4000
        out.extend(bytes([v & 3]) * ln)
    return W, H, mat, blocks, bytes(out)


OFFS = [(-8, 0), (-15, -7), (-15, 7), (-15, 0), (-1, 0),
        (-8, -7), (-8, 7), (-3, -4), (-3, 4), (-5, -7),
        (-5, 7), (-12, -7), (-12, 7), (-15, -4), (-15, 4),
        (-12, 0), (-4, 0), (-8, -4), (-8, 4), (-13, -3),
        (-13, 3), (-11, -5), (-11, 5), (-10, -2), (-10, 2),
        (-6, -2), (-6, 2), (-5, -5), (-5, 5), (-2, -2), (-2, 2)]


def predict(W, H, mat, blocks, grid, gw, gx0, gy0):
    """Состояния по subcell из готовой сетки высот."""
    def h(gx, gy):
        return grid[(gy - gy0) * gw + (gx - gx0)]

    out = bytearray(W * 8 * H * 8)
    for gy in range(H * 8):
        for gx in range(W * 8):
            cx = max(0, min(W - 1, (gx + 4) >> 3))
            cy = max(0, min(H - 1, (gy + 4) >> 3))
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
            out[gy * W * 8 + gx] = st
    return out


def grid_from_template(W, H, blocks):
    gx0, gy0 = -8, -16
    gw = W * 8 + 16
    gh = H * 8 + 18 + 32
    grid = bytearray(gw * gh)
    for cy in range(-2, H + 2):
        for cx in range(-2, W + 2):
            bm = block_map(blocks[max(0, min(H - 1, cy)) * W + max(0, min(W - 1, cx))])
            for r in range(8):
                gy = cy * 8 + r - gy0
                if not (0 <= gy < gh):
                    continue
                for c in range(8):
                    gx = cx * 8 + c - gx0
                    if 0 <= gx < gw:
                        grid[gy * gw + gx] = bm[r * 8 + c]
    return grid, gw, gx0, gy0


# --- карта главы -----------------------------------------------------------
chap = json.load(open(os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json"),
                      encoding="utf-8"))
cells = chap["cells"]
cx_min = min(c["x"] for c in cells)
cx_max = max(c["x"] for c in cells)
cy_min = min(c["y"] for c in cells)
cy_max = max(c["y"] for c in cells)
CW = cx_max - cx_min + 1
CH_ = cy_max - cy_min + 1
print(f"карта главы: клетки x[{cx_min}..{cx_max}] y[{cy_min}..{cy_max}] = {CW}x{CH_}, "
      f"всего клеток в экспорте {len(cells)}")
block_of = {}
for c in cells:
    block_of[(c["x"] - cx_min, c["y"] - cy_min)] = c["block"]
missing = sum(1 for y in range(CH_) for x in range(CW) if (x, y) not in block_of)
print(f"  клеток без блока в экспорте: {missing} из {CW*CH_}")

gw = CW * 8 + 16
gh = CH_ * 8 + 18 + 32
chgrid = bytearray(gw * gh)
gx0, gy0 = -8, -16
for y in range(CH_):
    for x in range(CW):
        bid = block_of.get((x, y))
        if bid is None:
            continue
        bm = block_map(bid)
        for r in range(8):
            gy = y * 8 + r - gy0
            if not (0 <= gy < gh):
                continue
            for c in range(8):
                gx = x * 8 + c - gx0
                if 0 <= gx < gw:
                    chgrid[gy * gw + gx] = bm[r * 8 + c]
print(f"  сетка главы: {gw}x{gh} суб-клеток")


def chapter_predict(W, H, mat, px, py):
    """Прогон beautifier'а по клеткам шаблона, размещённого в карте главы."""
    def h(gx, gy):
        # мировые суб-клетки карты главы
        mx = px * 8 + gx
        my = py * 8 + gy
        ix = mx - gx0
        iy = my - gy0
        if not (0 <= ix < gw and 0 <= iy < gh):
            return 15
        return chgrid[iy * gw + ix]

    out = bytearray(W * 8 * H * 8)
    for gy in range(H * 8):
        for gx in range(W * 8):
            cx = max(0, min(W - 1, (gx + 4) >> 3))
            cy = max(0, min(H - 1, (gy + 4) >> 3))
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
            out[gy * W * 8 + gx] = st
    return out


# --- перебор шаблонов ------------------------------------------------------
tot_a = tot_b = tot_n = 0
rows = []
for t in chap["templates"]:
    pmp_rel = t.get("pmp") or ""
    if not pmp_rel:
        continue
    p = os.path.join(GAME, pmp_rel.replace("/", os.sep))
    if not os.path.exists(p):
        alt = os.path.join(GAME, "Templates", os.path.basename(pmp_rel))
        p = alt if os.path.exists(alt) else None
    if not p:
        continue
    W, H, mat, blocks, rle = parse_pmp(p)
    pl = t["placements"][0]
    px, py = pl["x"] - cx_min, pl["y"] - cy_min

    g, gw2, gx02, gy02 = grid_from_template(W, H, blocks)
    pred_a = predict(W, H, mat, blocks, g, gw2, gx02, gy02)
    pred_b = chapter_predict(W, H, mat, px, py)

    ma = sum(1 for a, b in zip(rle, pred_a) if a == b)
    mb = sum(1 for a, b in zip(rle, pred_b) if a == b)
    n = len(rle)
    tot_a += ma
    tot_b += mb
    tot_n += n
    rows.append((os.path.basename(pmp_rel), W, H, 100.0 * ma / n, 100.0 * mb / n))

print(f"\n{'шаблон':28s} {'W x H':>8s} {'A: свой контекст':>18s} {'B: контекст главы':>19s}")
for name, W, H, a, b in rows:
    print(f"{name:28s} {W:3d} x{H:3d} {a:17.2f}% {b:18.2f}%")
print(f"\nИТОГО: A = {100.0*tot_a/tot_n:.2f}%  B = {100.0*tot_b/tot_n:.2f}%  "
      f"(суб-клеток {tot_n})")
