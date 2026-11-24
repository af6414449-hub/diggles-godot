"""Ориентация карты 8x8 блока: строки по Y (низ/верх) и колонки по X."""
import os
import sys
from collections import defaultdict

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
sys.path.insert(0, os.path.join(ROOT, "tools"))
from inspect_bdb import BdbDatabase, _METADATA_BYTES  # noqa: E402

BDB = BdbDatabase(os.path.join(GAME, "BlockDB0.BDB"))
META_OFF = BDB.sections["opaque_block_metadata"]["offset"]

for bid in (81, 27192, 1202, 71):
    meta = BDB.data[META_OFF + bid * _METADATA_BYTES: META_OFF + (bid + 1) * _METADATA_BYTES]
    grid = list(meta[:64])
    parts = BDB.get_block(bid)
    print(f"\n=== block {bid} ===")
    print("  карта 8x8 (индекс r*8+c):")
    for r in range(8):
        print("   ", " ".join(f"{grid[r*8+c]:3d}" for c in range(8)))
    rows = defaultdict(set)
    cols = defaultdict(set)
    ymin = ymax = None
    zmin = zmax = None
    for pt in parts:
        for v in pt["vertices"]:
            x, y, z = v[0], v[1], v[2]
            ymin = y if ymin is None else min(ymin, y)
            ymax = y if ymax is None else max(ymax, y)
            zmin = z if zmin is None else min(zmin, z)
            zmax = z if zmax is None else max(zmax, z)
            rows[round(y, 3)].add(round(z, 3))
            cols[round(x, 3)].add(round(z, 3))
    print(f"  меш: y [{ymin} .. {ymax}], z [{zmin} .. {zmax}]")
    print("  z по строкам Y:")
    for y in sorted(rows):
        print(f"    y={y:8.3f} -> z {sorted(rows[y])}")
    print("  z по колонкам X:")
    for x in sorted(cols):
        print(f"    x={x:8.3f} -> z {sorted(cols[x])}")
