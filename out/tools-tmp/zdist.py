import json
from collections import Counter
p = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models\native_campaign_chapter.json"
d = json.load(open(p, encoding="utf-8"))
meshes = d["meshes"]
top = Counter()
for c in d["cells"]:
    m = meshes.get(str(c["block"]))
    if not m: continue
    zs = []
    for part in m:
        v = part["vertices"]
        for i in range(0, len(v), 5):
            zs.append(v[i+2])
    if zs:
        top[max(zs)] += 1
print("максимальный z клетки главы (топ-12):", top.most_common(12))
