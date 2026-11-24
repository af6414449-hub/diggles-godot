import json
from collections import Counter
p = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models\native_campaign_chapter.json"
d = json.load(open(p, encoding="utf-8"))
att = d["attributes"]
c = Counter(att.values())
print("распределение атрибутов света (топ-12):", c.most_common(12))
print("всего значений:", len(att))
# доля клеток с атрибутом 1 и 4
print("доля 1:", c[1]/len(att), "доля 4:", c[4]/len(att))
