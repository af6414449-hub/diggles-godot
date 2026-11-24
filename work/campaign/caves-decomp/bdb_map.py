import sys, os, json, struct
from collections import Counter

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
sys.path.insert(0, os.path.join(ROOT, "tools"))

from inspect_bdb import BdbDatabase, _METADATA_BYTES  # read-only import

# locate BlockDB files
cands = [os.path.join(GAME, f) for f in ("BlockDB0.BDB", "BlockDB1.BDB", "BlockDB2.BDB")]
cands += [os.path.join(GAME, "Templates", f) for f in ("BlockDB0.BDB", "BlockDB1.BDB", "BlockDB2.BDB")]
cands = [p for p in cands if os.path.exists(p)]
print("BDB files:", cands)

dbs = []
for p in cands:
    d = BdbDatabase(p)
    dbs.append((p, d))
    print(f"  {os.path.basename(p)}: blocks={d.block_count} verts={d.vertex_count}")

# --- 1. global histogram of the 64-byte map values, per DB ---
print("\n=== histogram of map bytes (block+0x00..0x3F), all blocks ===")
allhist = Counter()
for p, d in dbs:
    off = d.sections["opaque_block_metadata"]["offset"]
    hist = Counter()
    for b in range(d.block_count):
        meta = d.data[off + b * _METADATA_BYTES: off + (b + 1) * _METADATA_BYTES]
        hist.update(meta[:64])
    print(f"  {os.path.basename(p)}: {sorted(hist.items())}")
    allhist.update(hist)
print("  ALL:", sorted(allhist.items()))

# --- 2. chapter block usage ---
chap_path = os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json")
used = None
if os.path.exists(chap_path):
    chap = json.load(open(chap_path, encoding="utf-8"))
    blocks = chap.get("blocks") or chap.get("chapter", {}).get("blocks")
    if isinstance(blocks, dict):
        used = sorted(int(k) for k in blocks.keys())
    elif isinstance(blocks, list):
        used = sorted(int(b.get("id", b.get("block", 0))) for b in blocks)
    print(f"\nchapter file: {chap_path}\nchapter blocks: {len(used) if used else 0}")
print("top-level keys:", list(chap.keys())[:20] if os.path.exists(chap_path) else "n/a")

def dump_block(d, bid):
    off = d.sections["opaque_block_metadata"]["offset"]
    meta = d.data[off + bid * _METADATA_BYTES: off + (bid + 1) * _METADATA_BYTES]
    grid = meta[:64]
    print(f"\n--- block {bid} ({os.path.basename(d.path)}) meta89 ---")
    print("  child blocks +0x40..0x4f:", list(struct.unpack_from("<4i", meta, 0x40)),
          " quadrant mat +0x50..0x53:", list(meta[0x50:0x54]),
          " +0x54:", meta[0x54], " +0x55..0x58:", list(meta[0x55:0x59]))
    print("  8x8 map (rows = y, cols = x):")
    for r in range(8):
        print("   ", " ".join(f"{grid[r*8+c]:3d}" for c in range(8)))
    try:
        parts = d.get_block(bid)
        zs = [v[2] for pt in parts for v in pt["vertices"]]
        xs = [v[0] for pt in parts for v in pt["vertices"]]
        ys = [v[1] for pt in parts for v in pt["vertices"]]
        attrs = Counter(a for pt in parts for a in pt["attributes"])
        print(f"  verts={len(zs)} x[{min(xs) if xs else 0:.4g}..{max(xs) if xs else 0:.4g}] "
              f"y[{min(ys) if ys else 0:.4g}..{max(ys) if ys else 0:.4g}] "
              f"z[{min(zs) if zs else 0:.4g}..{max(zs) if zs else 0:.4g}]")
        print(f"  per-vertex U8 attributes: {sorted(attrs.items())}")
    except Exception as e:
        print("  get_block failed:", e)

for bid in (0, 71, 81):
    for p, d in dbs:
        if bid < d.block_count:
            dump_block(d, bid)

# --- 3. blocks with uniform map value: print value + z range for a sample ---
print("\n=== uniform-map blocks: map value vs mesh z-range (sample) ===")
p, d = dbs[0]
off = d.sections["opaque_block_metadata"]["offset"]
uni = {}
for b in range(d.block_count):
    meta = d.data[off + b * _METADATA_BYTES: off + (b + 1) * _METADATA_BYTES]
    g = meta[:64]
    if len(set(g)) == 1:
        uni.setdefault(g[0], []).append(b)
for v, bl in sorted(uni.items()):
    print(f"  map value {v}: {len(bl)} blocks, e.g. {bl[:6]}")
for v, bl in sorted(uni.items()):
    for bid in bl[:2]:
        try:
            parts = d.get_block(bid)
            zs = [vv[2] for pt in parts for vv in pt["vertices"]]
            if zs:
                print(f"    block {bid}: map={v} z[{min(zs):.4g}..{max(zs):.4g}] n={len(zs)}")
        except Exception as e:
            print("    block", bid, "err", e)
