import json, os
from collections import Counter
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
ch = json.load(open(os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json"), encoding="utf-8"))
meshes = ch["meshes"]
xp = Counter(); yp = Counter(); sl = 0
for bid, parts in meshes.items():
    for p in parts:
        v = p["vertices"]; idx = p["indices"]
        for s in range(0, len(idx), 3):
            vs = [v[idx[s+k]*5:idx[s+k]*5+3] for k in range(3)]
            zs = [t[2] for t in vs]
            if max(zs) - min(zs) < 1e-4:
                continue
            xs = [t[0] for t in vs]; ys = [t[1] for t in vs]
            if max(xs) - min(xs) < 0.02:
                xp[round(sum(xs)/3.0, 2)] += 1
            elif max(ys) - min(ys) < 0.02:
                yp[round(sum(ys)/3.0, 2)] += 1
            else:
                sl += 1
print("vertical faces in planes x = const:", sorted(xp.items()))
print("vertical faces in planes y = const:", sorted(yp.items()))
print("tilted vertical faces:", sl)
