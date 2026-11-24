"""Проверка примера инициатора: блок 80 на клетке (163,94) главы."""
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


def block_map(bid):
    raw = BDB.data[META_OFF + bid * _METADATA_BYTES: META_OFF + (bid + 1) * _METADATA_BYTES]
    return bytes(raw[:64])


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

chap = json.load(open(os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json"),
                      encoding="utf-8"))
cells = {(c["x"], c["y"]): c for c in chap["cells"]}
TX, TY = 163, 94
print("клетка главы:", cells.get((TX, TY)))
print("карта 8x8 блока 80:", sorted(Counter(block_map(80)).items()))

for t in chap["templates"]:
    pl = t["placements"][0]
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
    px, py = pl["x"], pl["y"]
    if not (px <= TX < px + W and py <= TY < py + H):
        continue
    lx, ly = TX - px, TY - py
    idx = ly * W + lx
    # RLE — плоское изображение (W*8)x(H*8); индекс суб-клетки = (ly*8+r)*(W*8) + (lx*8+c)
    def rle_at(r, c):
        return rle[(ly * 8 + r) * (W * 8) + (lx * 8 + c)]
    st = bytes(rle_at(r, c) for r in range(8) for c in range(8))
    print(f"\nшаблон {os.path.basename(pmp_rel)} размещение ({px},{py}); "
          f"клетка ({lx},{ly}) блок={blocks[idx]}")
    print("  RLE-состояния:", sorted(Counter(st).items()))
    bm = block_map(blocks[idx])
    for r in range(8):
        print("   ", " ".join(f"{bm[r*8+c]:3d}" for c in range(8)), "   |  ",
              " ".join(f"{st[r*8+c]:3d}" for c in range(8)))
    # соседи по шаблону
    for dy in (-2, -1, 1, 2):
        ny = ly + dy
        if 0 <= ny < H:
            nb = block_map(blocks[ny * W + lx])
            print(f"  сосед y{dy:+d}: блок {blocks[ny*W+lx]}, уровни "
                  f"{sorted(Counter(nb).items())}")
    for dx in (-2, -1, 1, 2):
        nx = lx + dx
        if 0 <= nx < W:
            nb = block_map(blocks[ly * W + nx])
            print(f"  сосед x{dx:+d}: блок {blocks[ly*W+nx]}, уровни "
                  f"{sorted(Counter(nb).items())}")
    # предсказание beautifier'а (контекст = клетки шаблона)
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

    def h(gx, gy):
        return grid[(gy - gy0) * gw + (gx - gx0)]

    print("  DEBUG: gw", gw, "gx0", gx0, "gy0", gy0,
          "h(120,144)", h(120, 144), "h(120,143)", h(120, 143),
          "h(120,136)", h(120, 136), "h(120,129)", h(120, 129),
          "mat[735]", mat[735])

    pred = bytearray(64)
    for r in range(8):
        for c in range(8):
            gx, gy = lx * 8 + c, ly * 8 + r
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
            pred[r * 8 + c] = st
    print("\n  предсказание beautifier'а:")
    for r in range(8):
        print("   ", " ".join(f"{pred[r*8+c]:3d}" for c in range(8)))
    print("  совпадение с RLE:",
          sum(1 for a, b in zip(st, pred) if a == b), "/64")
