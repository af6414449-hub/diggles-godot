import json
p = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models\native_campaign_chapter.json"
d = json.load(open(p, encoding="utf-8"))
idx = {(c["x"], c["y"]): c for c in d["cells"]}
for cy in (82,83,84,85,86,87,88):
    c = idx.get((118, cy))
    if c:
        print((118,cy), "block", c["block"], "flags", c["flags"], "attr", c["cell_attribute"], "story", c["story"])
    else:
        print((118,cy), "нет клетки")
print()
print("materials sample:", json.dumps(d["materials"])[:300])
print()
att = d["attributes"]
print("attributes type", type(att), len(att))
print("sample:", json.dumps(att)[:400] if not isinstance(att, dict) else list(att.items())[:5])
