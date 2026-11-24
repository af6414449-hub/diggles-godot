import json
root=r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
d=json.load(open(root+r"\godot\models\native_campaign_chapter.json",encoding="utf-8"))
for block in ("80","81","228","461"):
    parts=d["meshes"].get(block,[])
    print("block %s: %d parts" % (block,len(parts)))
    for i,p in enumerate(parts):
        v=p["vertices"]
        xs=v[0::5]; ys=v[1::5]; zs=v[2::5]
        print("   part %d: %d verts, x %.2f..%.2f, y %.2f..%.2f, z %.2f..%.2f" %
              (i,len(v)//5,min(xs),max(xs),min(ys),max(ys),min(zs),max(zs)))