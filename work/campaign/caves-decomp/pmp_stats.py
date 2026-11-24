import os, struct, collections
G = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
P = os.path.join(G, "Templates", "pmp")
dims = collections.Counter(); tails = []
shapes = collections.Counter(); extras = collections.Counter()
hts = collections.Counter(); blocks = set(); rlecount = []
for n in sorted(os.listdir(P)):
    if not n.lower().endswith(".pmp"):
        continue
    d = open(os.path.join(P, n), "rb").read()
    w, h = struct.unpack_from("<ii", d, 0); off = 8; N = w * h
    dims[(w, h)] += 1
    shape = d[off:off + N]; off += N
    bl = struct.unpack_from("<%di" % N, d, off); off += 4 * N
    (cnt,) = struct.unpack_from("<i", d, off); off += 4
    rle = struct.unpack_from("<%dH" % cnt, d, off); off += 2 * cnt
    extra = d[off:off + N]; off += N
    if off != len(d):
        tails.append((n, len(d) - off))
    rlecount.append(cnt)
    shapes.update(shape); extras.update(extra); blocks.update(bl)
    for c in rle:
        ln = c >> 2
        if ln == 0:
            ln = 0x4000
        hts[c & 3] += ln
print("files:", sum(dims.values()), " with tail != 0:", len(tails), tails[:5])
print("dims (w,h):", dims.most_common())
print("shape codes:", sorted(shapes.items()))
print("extra values:", sorted(extras.items()))
print("height code -> total bytes:", sorted(hts.items()))
print("rle_count min/max:", min(rlecount), max(rlecount))
print("block id range:", min(blocks), "..", max(blocks), " distinct:", len(blocks))
