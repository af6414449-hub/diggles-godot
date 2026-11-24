"""З16 (итерация 4): сравнение RLE-карты .pmp с выходом beautifier'а (контекст карты)."""
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


def beautify(W, H, mat, blocks, outside="clamp", use_step=True):
    gx0, gy0 = -8, -16
    gw = W * 8 + 16
    gh = H * 8 + 18 + 32
    grid = bytearray(gw * gh)

    def cb(cx, cy):
        if outside == "clamp":
            cx = max(0, min(W - 1, cx))
            cy = max(0, min(H - 1, cy))
            return block_map(blocks[cy * W + cx])
        return bytes([outside] * 64)

    for cy in range(-2, H + 2):
        for cx in range(-2, W + 2):
            bm = cb(cx, cy)
            for r in range(8):
                gy = cy * 8 + r - gy0
                if not (0 <= gy < gh):
                    continue
                for c in range(8):
                    gx = cx * 8 + c - gx0
                    if 0 <= gx < gw:
                        grid[gy * gw + gx] = bm[r * 8 + c]

    def h(gx, gy):
        return grid[(gy - gy0) * gw + (gx - gx0)]

    out = bytearray(W * 8 * H * 8)
    for gy in range(H * 8):
        for gx in range(W * 8):
            cx, cy = (gx + 4) >> 3, (gy + 4) >> 3
            cx = max(0, min(W - 1, cx))
            cy = max(0, min(H - 1, cy))
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
            elif use_step:
                hc = h(gx, gy)
                if (h(gx, gy - 1) + 2 < hc) and (h(gx, gy - 8) + 2 < hc):
                    st = 3
                elif (hc + 2 < h(gx, gy + 1)) and (h(gx, gy - 15) + 2 < h(gx, gy + 1)):
                    st = 3
            out[gy * W * 8 + gx] = st
    return out


p = sys.argv[1] if len(sys.argv) > 1 else os.path.join(GAME, "Templates", "multi_start_010.pmp")
W, H, mat, blocks, rle = parse_pmp(p)
pred = beautify(W, H, mat, blocks)
print(f"{os.path.basename(p)} {W}x{H}")
print("  RLE  :", sorted(Counter(rle).items()))
print("  пред :", sorted(Counter(pred).items()))
inter = sum(1 for a, b in zip(rle, pred) if a and b)
print(f"  ненулевых RLE={sum(1 for v in rle if v)}, пред={sum(1 for v in pred if v)}, "
      f"пересечение={inter}")
print(f"  RLE ненулевые вне пред={sum(1 for a, b in zip(rle, pred) if a and not b)}")

CH = {0: ".", 1: "-", 3: "#"}
step = max(1, (H * 8) // 60)
print(f"\n== RLE (каждые {step}) ==")
for r in range(0, H * 8, step):
    print("".join(CH[rle[r * W * 8 + c]] for c in range(0, W * 8, step)))
print("\n== beautifier (каждые %d) ==" % step)
for r in range(0, H * 8, step):
    print("".join(CH[pred[r * W * 8 + c]] for c in range(0, W * 8, step)))
