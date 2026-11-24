# -*- coding: utf-8 -*-
"""Граница породы (острова) в районе деревьев: какие клетки заняты породой, где пусто."""
import json
import os
from collections import defaultdict

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
ch = json.load(open(os.path.join(ROOT, "native_campaign_chapter.json"), encoding="utf-8"))
cells = ch["cells"]
meshes = ch["meshes"]

rock = {(int(c["x"]), int(c["y"])) for c in cells}
xs = sorted({x for x, y in rock})
ys = sorted({y for x, y in rock})
print("порода: x %d..%d, y %d..%d, клеток %d" % (xs[0], xs[-1], ys[0], ys[-1], len(rock)))

print("\n--- колонки x=225..252: строки с породой (y) ---")
for x in range(225, 253):
    col = sorted(y for (xx, y) in rock if xx == x)
    if not col:
        print("x=%3d: нет породы" % x); continue
    # непрерывные интервалы
    runs, s, p = [], col[0], col[0]
    for y in col[1:]:
        if y != p + 1:
            runs.append((s, p)); s = y
        p = y
    runs.append((s, p))
    print("x=%3d: %s" % (x, ", ".join("%d-%d" % r if r[0] != r[1] else "%d" % r[0] for r in runs)))

print("\n--- строка y=30: интервалы x с породой ---")
row = sorted(x for (x, y) in rock if y == 30)
runs, s, p = [], row[0], row[0]
for x in row[1:]:
    if x != p + 1:
        runs.append((s, p)); s = x
    p = x
runs.append((s, p))
print(", ".join("%d-%d" % r if r[0] != r[1] else "%d" % r[0] for r in runs))

print("\n--- блоки в окрестности деревьев ---")
for (x, y) in [(249, 30), (249, 29), (249, 31), (240, 30), (230, 30), (227, 30),
                (237, 31), (251, 30), (253, 30), (255, 30), (249, 25), (249, 20)]:
    c = next((c for c in cells if int(c["x"]) == x and int(c["y"]) == y), None)
    if c is None:
        print("  (%3d,%2d): СВОБОДНАЯ клетка" % (x, y)); continue
    bid = str(int(c["block"]))
    zs = []
    for part in meshes.get(bid, []):
        v = part["vertices"]
        zs += [float(v[k]) for k in range(2, len(v), 5)]
    print("  (%3d,%2d): блок %-6s z[%.1f..%.1f] flags=%s" %
          (x, y, bid, min(zs), max(zs), c.get("flags")))
