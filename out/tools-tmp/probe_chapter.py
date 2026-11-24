import json
p = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models\native_campaign_chapter.json"
d = json.load(open(p, encoding="utf-8"))
print("top keys:", list(d.keys()))
cells = d["cells"]
print("cells:", len(cells))
print("cell sample:", json.dumps(cells[0])[:600])
meshes = d["meshes"]
print("meshes type:", type(meshes), len(meshes))
k = list(meshes.keys())[:3] if isinstance(meshes, dict) else None
print("mesh keys sample:", k)
if isinstance(meshes, dict):
    for kk in k:
        m = meshes[kk]
        print(kk, list(m.keys()) if isinstance(m, dict) else type(m))
        if isinstance(m, dict):
            for kk2, vv in m.items():
                print("   ", kk2, type(vv), (len(vv) if hasattr(vv,"__len__") else vv))
        break
