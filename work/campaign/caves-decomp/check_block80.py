"""Проверка блоков 80, 27192, 1202, 81 из BDB: карта 8×8 уровней + z меша."""
import os
import sys
from collections import Counter

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
sys.path.insert(0, os.path.join(ROOT, "tools"))
from inspect_bdb import BdbDatabase, _METADATA_BYTES  # noqa: E402

path = os.path.join(GAME, "BlockDB0.BDB")
d = BdbDatabase(path)
off = d.sections["opaque_block_metadata"]["offset"]
for bid in (80, 27192, 1202, 81, 0, 71):
    if bid >= d.block_count:
        print(f"block {bid}: out of range")
        continue
    meta = d.data[off + bid * _METADATA_BYTES: off + (bid + 1) * _METADATA_BYTES]
    grid = meta[:64]
    print(f"\n--- block {bid} ---")
    print("  8x8 levels:", sorted(Counter(grid).items()))
    for r in range(8):
        print("   ", " ".join(f"{grid[r * 8 + c]:3d}" for c in range(8)))
    print("  children +0x40..0x4f:", [int.from_bytes(meta[0x40 + 4 * i:0x44 + 4 * i], "little", signed=True) for i in range(4)])
    print("  quad materials +0x50..0x53:", list(meta[0x50:0x54]))
    try:
        parts = d.get_block(bid)
        zs = [v[2] for pt in parts for v in pt["vertices"]]
        print("  mesh z:", sorted(set(round(z, 4) for z in zs)))
    except Exception as e:
        print("  get_block failed:", e)
