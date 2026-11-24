import json
root=r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
d=json.load(open(root+r"\godot\models\native_campaign_chapter.json",encoding="utf-8"))
for block in ("228","80"):
    print("=== block", block, "===")
    for p in d["meshes"].get(block,[]):
        v=p["vertices"]; idx=p["indices"]
        print(" part", p["part"], "verts:")
        for i in range(len(v)//5):
            print("    v%d = (%.2f, %.2f, %.2f)" % (i, v[i*5], v[i*5+1], v[i*5+2]))
        print("   indices:", idx)