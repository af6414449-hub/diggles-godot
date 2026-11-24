"""Рендер RLE-карты состояний и карты уровней шаблона (ASCII)."""
import os
import struct
import sys

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
print(f"{os.path.basename(p)}  {W}x{H} клеток = {W*8}x{H*8} суб-клеток")

CH = {0: ".", 1: "-", 3: "#"}


def cell_state(idx):
    return rle[idx * 64:(idx + 1) * 64]


def render(title, get):
    print(f"\n== {title} ==")
    print("   " + "".join(str((c // 8) % 10) for c in range(W * 8)))
    for r in range(H * 8):
        line = []
        for c in range(W * 8):
            v = get(r, c)
            line.append(v)
        print(f"{r:3d}" + "".join(line))


def state_at(r, c):
    cy, cx = r // 8, c // 8
    st = cell_state(cy * W + cx)
    return CH[st[(r % 8) * 8 + (c % 8)]]


def level_at(r, c):
    cy, cx = r // 8, c // 8
    bm = block_map(blocks[cy * W + cx])
    return "0123456789abcdef"[bm[(r % 8) * 8 + (c % 8)]]


render("состояния RLE (0='.', 1='-', 3='#')", state_at)
render("уровни блоков (0..15 -> 0..f)", level_at)
