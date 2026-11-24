"""Диагностика caves_*.pmp: карты 8x8 блоков рядом с состояниями RLE."""
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
    rle = d[o:o + cnt * 2]; o += cnt * 2
    tail = d[o:o + n]
    out = bytearray()
    for i in range(cnt):
        v = struct.unpack_from("<H", rle, i * 2)[0]
        ln = v >> 2
        if ln == 0:
            ln = 0x4000
        out.extend(bytes([v & 3]) * ln)
    return W, H, mat, blocks, bytes(out)


p = sys.argv[1] if len(sys.argv) > 1 else os.path.join(GAME, "Templates", "pmp", "caves_1.pmp")
W, H, mat, blocks, rle = parse_pmp(p)
print(f"{os.path.basename(p)}  {W}x{H}")
for cy in range(H):
    for cx in range(W):
        idx = cy * W + cx
        bm = block_map(blocks[idx])
        st = rle[idx * 64:(idx + 1) * 64]
        if not any(st):
            continue
        print(f"\n--- cell ({cx},{cy}) block={blocks[idx]} mat=0x{mat[idx]:02x} "
              f"levels={sorted(Counter(bm).items())} states={sorted(Counter(st).items())}")
        for r in range(8):
            print("    " + " ".join(f"{bm[r*8+c]:3d}" for c in range(8)) +
                  "   |  " + " ".join(f"{st[r*8+c]:3d}" for c in range(8)))
        for dy in (-1, 1):
            ny = cy + dy
            if 0 <= ny < H:
                nb = block_map(blocks[ny * W + cx])
                print(f"    сосед y{dy:+d} ({cx},{ny}) block={blocks[ny*W+cx]} "
                      f"levels={sorted(Counter(nb).items())}")
