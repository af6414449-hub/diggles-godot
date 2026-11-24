import json
p=r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models\native_campaign_chapter.json"
d=json.load(open(p,encoding="utf-8"))
print("keys:", list(d.keys())[:20])
print("initial_view:", d.get("initial_view"))
cells=d["cells"]
print("cells:", len(cells), "sample:", cells[0])
xs=[c["x"] for c in cells]; ys=[c["y"] for c in cells]
print("box:", min(xs), min(ys), max(xs), max(ys))
print("depth keys:", [k for k in d.keys() if "depth" in k.lower() or "span" in k.lower()])