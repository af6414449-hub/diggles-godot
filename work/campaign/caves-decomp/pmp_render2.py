"""Рендер RLE и уровней для шаблона unq_start (multi_start_010) главы."""
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
    return list(raw[:64])


def parse_pmp(path):
    d = open(path, "rb").read()
    W, H = struct.unpack_from("<ii", d, 0)
    o = 8
    n = W * H
    mat = d[o:o + n]; o += n
    blocks = struct.unpack_from(f"<{n}i", d, o); o += 4 * n
    cnt = struct.unpack_from("<i", d, o)[0]; o += 4
    words = struct.unpack_from(f"<{cnt}H", d, o); o += 2 * cnt
    tail = d[o:o + n]
    out = bytearray()
    for v in words:
        ln = v >> 2
        if ln == 0:
            ln = 0x4000
        out.extend(bytes([v & 3]) * ln)
    return W, H, mat, blocks, bytes(out), tail


p = sys.argv[1] if len(sys.argv) > 1 else os.path.join(GAME, "Templates", "multi_start_010.pmp")
W, H, mat, blocks, dec, tail = parse_pmp(p)
print(f"{os.path.basename(p)} {W}x{H} клеток ({W*8}x{H*8} суб-клеток)")
print("  состояния:", sorted(Counter(dec).items()))
nz = [i for i, v in enumerate(dec) if v]
cells_nz = sorted(set(i // 64 for i in nz))
print(f"  ненулевых {len(nz)} ({100.0*len(nz)/len(dec):.1f}%), затронуто клеток {len(cells_nz)} из {W*H}")
print(f"  extra: {sorted(Counter(tail).items())}")

CH = {0: ".", 1: "-", 3: "#"}
STEP = max(1, (H * 8) // 90)
print(f"\n== состояния (каждые {STEP} суб-клетки) ==")
for r in range(0, H * 8, STEP):
    line = "".join(CH[dec[(r // 8) * W * 64 + (r % 8) * 8 + (c // 8) * 8 + (c % 8)]]
                   for c in range(0, W * 8, STEP))
    print(f"{r:4d} {line}")

print("\n== уровни (каждые 8 суб-клеток -> уровень левого верхнего угла клетки) ==")
for cy in range(0, H, max(1, H // 45)):
    line = ""
    for cx in range(0, W, max(1, W // 110)):
        bm = block_map(blocks[cy * W + cx])
        line += "0123456789abcdef"[bm[0]]
    print(f"{cy:4d} {line}")
