import json, os, sys
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
ch = json.load(open(os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json"), encoding="utf-8"))
meshes = ch["meshes"]
for block in (0, 59, 71, 76, 33):
    parts = meshes.get(str(block), [])
    print("=== block %d, %d patches ===" % (block, len(parts)))
    for p in parts:
        v = p["vertices"]
        print("  part %d: %d verts, %d indices" % (p["part"], len(v)//5, len(p["indices"])))
        for i in range(0, len(v), 5):
            print("    v%d  x=%6.3f y=%6.3f z=%6.3f  uv=(%5.3f,%5.3f)" % (i//5, v[i], v[i+1], v[i+2], v[i+3], v[i+4]))
        print("    idx:", p["indices"])
