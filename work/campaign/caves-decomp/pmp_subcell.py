import os, struct, sys
from collections import Counter

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
TPL = os.path.join(GAME, "Templates")

# найти все .pmp
pmps = []
for root, dirs, files in os.walk(GAME):
    for f in files:
        if f.lower().endswith(".pmp"):
            pmps.append(os.path.join(root, f))
print("pmp files found:", len(pmps))

def parse_pmp(path, verbose=True):
    data = open(path, "rb").read()
    off = 0
    W, H = struct.unpack_from("<ii", data, off); off += 8
    if W <= 0 or H <= 0 or W * H > 4_000_000:
        return None
    n = W * H
    mat = data[off:off + n]; off += n
    blocks = struct.unpack_from(f"<{n}i", data, off); off += 4 * n
    count = struct.unpack_from("<i", data, off)[0]; off += 4
    rle = data[off:off + count * 2]; off += count * 2
    tail = data[off:off + n]; off += n
    rest = len(data) - off
    # декодирование RLE
    out = bytearray()
    for i in range(count):
        v = struct.unpack_from("<H", rle, i * 2)[0]
        ln = v >> 2
        if ln == 0:
            ln = 0x4000
        out.extend(bytes([v & 3]) * ln)
    res = dict(W=W, H=H, mat=mat, blocks=blocks, count=count, tail=tail,
               rle_len=len(rle), dec=len(out), rest=rest,
               expect_sub=64 * n)
    if verbose:
        print(f"\n== {os.path.basename(path)} ==")
        print(f"  W={W} H={H} cells={n}")
        print(f"  material bytes: uniq={sorted(Counter(mat).items())[:8]}")
        print(f"  block ids: uniq={len(set(blocks))} sample={blocks[:8]}")
        print(f"  RLE words={count} decoded={len(out)} expected_subcell_bytes={64*n} match={len(out)==64*n}")
        print(f"  tail array (W*H bytes): uniq={sorted(Counter(tail).items())[:8]}")
        print(f"  leftover after arrays: {rest} bytes")
        if len(out) == 64 * n:
            c = Counter(out)
            print(f"  RLE value histogram: {sorted(c.items())}")
            # карта одной клетки
            for cy in range(min(2, H)):
                for cx in range(min(2, W)):
                    base = (cy * W + cx) * 64
                    print(f"  cell({cx},{cy}) 8x8:")
                    for r in range(8):
                        print("     ", " ".join(f"{out[base+r*8+c]:2d}" for c in range(8)))
    return res

names = [p for p in pmps if os.path.getsize(p) > 16]
for p in names[:3]:
    try:
        parse_pmp(p)
    except Exception as e:
        print("ERR", p, e)

# какие .pmp использует глава
camp = os.path.join(GAME, "Scripts", "gameplay", "Campaign.tcl")
if os.path.exists(camp):
    txt = open(camp, encoding="utf-8", errors="replace").read()
    print("\n== Campaign.tcl: упоминания .pmp / MapTemplateSet ==")
    for i, line in enumerate(txt.splitlines(), 1):
        low = line.lower()
        if ".pmp" in low or "maptemplateset" in low or "map_template" in low:
            print(f"  {i}: {line.strip()[:160]}")
