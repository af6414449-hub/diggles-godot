import json, os
from collections import Counter
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
ch = json.load(open(os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json"), encoding="utf-8"))
meshes = ch["meshes"]
pos = Counter()
interior = Counter()
for bid, parts in meshes.items():
    for p in parts:
        v = p["vertices"]
        idx = p["indices"]
        for s in range(0, len(idx), 3):
            vs = [v[idx[s+k]*5:idx[s+k]*5+3] for k in range(3)]
            zs = [t[2] for t in vs]
            if max(zs) - min(zs) < 1e-4:
                continue
            # the vertical plane: all x equal or all y equal
            xs = set(round(t[0],3) for t in vs)
            ys = set(round(t[1],3) for t in vs)
            if len(xs) == 1:
                pos[("x", sorted(xs)[0])] += 1
            elif len(ys) == 1:
                pos[("y", sorted(ys)[0])] += 1
            else:
                interior["slanted"] += 1
print("vertical faces by plane (block local coords):")
for key, count in sorted(pos.items()):
    print("  %s = %-6s : %d" % (key[0], key[1], count))
print("other:", dict(interior))
