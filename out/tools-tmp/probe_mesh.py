import json
p = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models\native_campaign_chapter.json"
d = json.load(open(p, encoding="utf-8"))
meshes = d["meshes"]
cell = d["cells"][0]
print("cell:", cell)
m = meshes[str(cell["block"])]
print("parts:", len(m))
part = m[0]
print("part keys:", list(part.keys()))
print("part number:", part["part"])
print("vertices[:12]:", part["vertices"][:12])
print("indices[:9]:", part["indices"][:9])
print("attributes[:9]:", part["attributes"][:9])
