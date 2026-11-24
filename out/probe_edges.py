import json, os
from collections import defaultdict
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
ch = json.load(open(os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json"), encoding="utf-8"))
meshes = ch["meshes"]

# flat triangle edges on the global cell boundary planes
edges = defaultdict(set)   # (axis, global coordinate) -> set of z
for entry in ch["cells"]:
    cx, cy = int(entry["x"]), int(entry["y"])
    for p in meshes.get(str(entry["block"]), []):
        v = p["vertices"]; idx = p["indices"]
        for s in range(0, len(idx), 3):
            tri = []
            for k in range(3):
                o = idx[s+k]*5
                tri.append((v[o]+cx, v[o+1]+cy, v[o+2]))
            zs = [t[2] for t in tri]
            if max(zs)-min(zs) > 1e-4:
                continue
            for a in range(3):
                p0 = tri[a]; p1 = tri[(a+1) % 3]
                if abs(p0[0]-p1[0]) > 1e-4 and abs(p0[1]-p1[1]) > 1e-4:
                    continue
                if abs(p0[0]-p1[0]) <= 1e-4:
                    edges[("x", round(p0[0], 3))].add(round(p0[2], 2))
                else:
                    edges[("y", round(p0[1], 3))].add(round(p0[2], 2))

def levels_at(axis, coord):
    return sorted(edges.get((axis, coord), ()))

print("sample global x planes (the cell boundary) and the levels found there:")
for x in range(226, 244):
    print("  x=%3d : %s" % (x, levels_at("x", float(x))))
print()
print("sample global y planes:")
for y in range(38, 44):
    print("  y=%3d : %s" % (y, levels_at("y", float(y))))
