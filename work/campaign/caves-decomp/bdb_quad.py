"""Статистика по квадрантам блока BDB: child-ids (+0x40..0x4f) и материалы (+0x50..0x53)."""
import os
import sys
from collections import Counter

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
sys.path.insert(0, os.path.join(ROOT, "tools"))
from inspect_bdb import BdbDatabase, _METADATA_BYTES  # noqa: E402

cands = [os.path.join(GAME, f) for f in ("BlockDB0.BDB", "BlockDB1.BDB", "BlockDB2.BDB")]
cands += [os.path.join(GAME, "Templates", f) for f in ("BlockDB0.BDB", "BlockDB1.BDB", "BlockDB2.BDB")]
cands = [p for p in cands if os.path.exists(p)]

for p in cands:
    d = BdbDatabase(p)
    off = d.sections["opaque_block_metadata"]["offset"]
    n = d.block_count
    mats = [Counter() for _ in range(4)]
    child_hist = [Counter() for _ in range(4)]
    all_same = Counter()
    child_any = 0
    mat_all_same = 0
    for b in range(n):
        meta = d.data[off + b * _METADATA_BYTES: off + (b + 1) * _METADATA_BYTES]
        q = list(meta[0x50:0x54])
        ch = list(int.from_bytes(meta[0x40 + 4 * i:0x44 + 4 * i], "little", signed=True) for i in range(4))
        for i in range(4):
            mats[i][q[i]] += 1
            child_hist[i][ch[i]] += 1
        all_same[len(set(q))] += 1
        if any(c != -1 for c in ch):
            child_any += 1
        if len(set(q)) == 1:
            mat_all_same += 1
    print(f"\n=== {os.path.basename(p)}  blocks={n} ===")
    for i in range(4):
        top = mats[i].most_common(12)
        print(f"  q{i} (+0x{0x50+i:02x}) material values: {top}")
    print(f"  blocks with >=2 distinct quadrant materials: {n - mat_all_same} / {n}")
    print(f"  blocks with at least one child block: {child_any} / {n}")
    for i in range(4):
        print(f"  q{i} child ids (top6): {child_hist[i].most_common(6)}")
