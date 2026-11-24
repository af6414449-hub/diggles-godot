import json, os
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
ch = json.load(open(os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json"), encoding="utf-8"))
meshes = ch["meshes"]
flat = 0
vert = 0
vert_cells = 0
cells = ch["cells"]
for entry in cells:
    parts = meshes.get(str(entry["block"]), [])
    has_vert = False
    for p in parts:
        v = p["vertices"]
        idx = p["indices"]
        for s in range(0, len(idx), 3):
            zs = [v[idx[s+k]*5+2] for k in range(3)]
            if max(zs) - min(zs) < 1e-4:
                flat += 1
            else:
                vert += 1
                has_vert = True
    if has_vert:
        vert_cells += 1
print("triangles flat:", flat, " vertical:", vert)
print("cells with vertical faces: %d of %d (%.1f%%)" % (vert_cells, len(cells), 100.0*vert_cells/len(cells)))
