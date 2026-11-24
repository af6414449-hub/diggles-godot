"""Проверка таблицы инициатора (docs/review/caves-audit-2026-11-21.md §11.6):
связь отметки «3» в RLE-карте с однородностью карты 8×8 блока.

Индексация RLE: плоское изображение (W*8)x(H*8);
суб-клетка (x,y,r,c) -> индекс (y*8+r)*(W*8) + (x*8+c).
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


chap = json.load(open(os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json"),
                      encoding="utf-8"))
cells = {(c["x"], c["y"]): c for c in chap["cells"]}

# карта RLE главы: для каждой клетки главы — 64 байта из RLE соответствующего шаблона
rle_of_cell = {}
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
    for pl in t["placements"]:
        px, py = pl["x"], pl["y"]
        for ly in range(H):
            for lx in range(W):
                gx, gy = px + lx, py + ly
                if (gx, gy) not in cells:
                    continue
                sub = bytes(rle[(ly * 8 + r) * (W * 8) + (lx * 8 + c)]
                            for r in range(8) for c in range(8))
                rle_of_cell[(gx, gy)] = (sub, blocks[ly * W + lx], W, H, lx, ly)

print(f"клеток главы с RLE-картой: {len(rle_of_cell)} из {len(cells)}")

tab = Counter()
uniform_with_step = []
for (gx, gy), (sub, bid, W, H, lx, ly) in rle_of_cell.items():
    bm = block_map(bid)
    levels = set(bm)
    uniform = len(levels) == 1
    has_step = 3 in sub
    has_floor = any(v in (1, 3) for v in sub)
    tab[(uniform, has_step, has_floor)] += 1
    if uniform and has_step:
        uniform_with_step.append((gx, gy, bid, sorted(levels), sorted(Counter(sub).items())))

print("\n(карта 8x8 однородна, есть отметка 3, есть «земля» 1/3) -> клеток")
for k in sorted(tab):
    print("   ", k, "->", tab[k])
print(f"\nоднородных клеток с отметкой «3»: {len(uniform_with_step)}")
for item in uniform_with_step[:12]:
    print("   ", item)

b80 = [(gx, gy) for (gx, gy), (sub, bid, W, H, lx, ly) in rle_of_cell.items() if bid == 80]
print(f"\nклеток с блоком 80: {len(b80)}; примеры: {b80[:6]}")
for (gx, gy) in b80[:4]:
    sub, bid, W, H, lx, ly = rle_of_cell[(gx, gy)]
    print(f"   ({gx},{gy}) состояния: {sorted(Counter(sub).items())}")
