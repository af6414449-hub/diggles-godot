# -*- coding: utf-8 -*-
"""Проверка уровней уступов блока 71 по экспорту главы (z world -> уровень)."""
import json
import collections

P = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models\native_campaign_chapter.json"
ch = json.load(open(P, encoding="utf-8"))
meshes = ch["meshes"]
print("блоков в экспорте:", len(meshes))

for bid in ("71",):
    parts = meshes.get(bid)
    if parts is None:
        print("блока", bid, "нет")
        continue
    print("блок", bid, ": частей", len(parts))
    levels = collections.Counter()
    for i, part in enumerate(parts):
        v = part["vertices"]
        zs = [float(v[k]) for k in range(2, len(v), 5)]
        ls = sorted(set(round((z - 7.0) / 0.5, 3) for z in zs))
        for l in ls:
            levels[l] += 1
        print("   part %d: z in [%s] -> уровни %s" %
              (i, ", ".join("%.2f" % z for z in sorted(set(zs))), ls))
    print("   сводка уровней блока:", sorted(levels.items()))

# сколько клеток главы на каждом уровне поверхности
cells = ch["cells"]
print("клеток в главе:", len(cells))
lv = collections.Counter()
for c in cells:
    for part in meshes.get(str(int(c["block"])), []):
        v = part["vertices"]
        zs = [float(v[k]) for k in range(2, len(v), 5)]
        for z in set(zs):
            lv[round((z - 7.0) / 0.5, 3)] += 1
print("распределение уровней по клеткам главы:", sorted(lv.items()))
