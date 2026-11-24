import json
from collections import Counter
p = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models\native_campaign_chapter.json"
d = json.load(open(p, encoding="utf-8"))
meshes = d["meshes"]
cells = [c for c in d["cells"] if 100 <= c["x"] <= 140 and 70 <= c["y"] <= 90]
print("cells in region:", len(cells))
rows = {}
for c in cells:
    m = meshes.get(str(c["block"]))
    if not m: continue
    zs = Counter()
    flat = vert = ramp = 0
    for part in m:
        v = part["vertices"]; idx = part["indices"]
        for i in range(0, len(idx), 3):
            zs3 = [v[idx[i+k]*5+2] for k in range(3)]
            for z in zs3: zs[z] += 1
            lo, hi = min(zs3), max(zs3)
            if hi - lo <= 0.01: flat += 1
            else:
                import math
                ax,ay,az = [v[idx[i+k]*5] for k in range(3)], [v[idx[i+k]*5+1] for k in range(3)], zs3
                e1 = (ax[1]-ax[0], ay[1]-ay[0], az[1]-az[0]); e2 = (ax[2]-ax[0], ay[2]-ay[0], az[2]-az[0])
                nx = e1[1]*e2[2]-e1[2]*e2[1]; ny = e1[2]*e2[0]-e1[0]*e2[2]; nz = e1[0]*e2[1]-e1[1]*e2[0]
                ln = math.sqrt(nx*nx+ny*ny+nz*nz)
                if ln>0 and abs(nz/ln) > 0.5: ramp += 1
                else: vert += 1
    rows[(c["x"], c["y"])] = (sorted(zs.keys()), flat, vert, ramp)
for k in sorted(rows):
    zs, fl, ve, ra = rows[k]
    print(k, "z=", [round(z,2) for z in zs], "flat", fl, "vert", ve, "ramp", ra)
