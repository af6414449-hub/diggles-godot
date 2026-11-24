# -*- coding: utf-8 -*-
"""Где стоят Dummy_Obw_baum_*/berg_* относительно породы главы (по экспорту порта)."""
import json
import math
import os

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
ch = json.load(open(os.path.join(ROOT, "native_campaign_chapter.json"), encoding="utf-8"))
mo = json.load(open(os.path.join(ROOT, "native_campaign_models.json"), encoding="utf-8"))

print("ключи chapter:", list(ch.keys()))
print("ключи models :", list(mo.keys()))

cells = ch["cells"]
meshes = ch["meshes"]
print("пример клетки:", {k: cells[0][k] for k in list(cells[0])[:8]})

# ---- найти все placements с Obw/Urw
def walk(o, path=""):
    if isinstance(o, dict):
        for k, v in o.items():
            yield from walk(v, path + "/" + str(k))
    elif isinstance(o, list):
        for i, v in enumerate(o):
            yield from walk(v, path + "/%d" % i)
    else:
        yield path, o

pl = mo.get("placements") or mo.get("objects") or mo.get("models")
if pl is None:
    print("!!! не найден список placements;顶层:", list(mo.keys()))
    raise SystemExit(1)
print("placements:", len(pl))
print("пример:", pl[0])

# ---- карта клеток
index = {(int(c["x"]), int(c["y"])): c for c in cells}
print("клеток в карте:", len(index))

TARGET = ("Dummy_Obw_baum", "Dummy_Obw_berg", "Dummy_Urw_baum", "Dummy_Urw_berg", "Dummy_Obw_rasen", "Dummy_Obw_boden")

hits = []
for p in pl:
    s = json.dumps(p)
    name = p.get("name") or p.get("class") or p.get("model") or ""
    if any(t in str(name) for t in TARGET) or any(t in s for t in TARGET):
        hits.append(p)
print("найдено по Obw/Urw/rasen:", len(hits))

for p in hits[:40]:
    name = p.get("name") or p.get("class") or p.get("model")
    x = p.get("x"); y = p.get("y"); z = p.get("z")
    if x is None and "position" in p:
        pos = p["position"]
        x, y, z = pos[0], pos[1], pos[2]
    cx, cy = int(math.floor(x)), int(math.floor(y))
    c = index.get((cx, cy))
    info = "нет клетки"
    if c is not None:
        bid = str(int(c["block"]))
        zs = []
        for part in meshes.get(bid, []):
            v = part["vertices"]
            zs += [float(v[k]) for k in range(2, len(v), 5)]
        lo, hi = (min(zs), max(zs)) if zs else (None, None)
        info = "блок %s, z[%s..%s]" % (bid, lo, hi)
    print("  %-26s x=%8.2f y=%7.2f z=%8.3f -> клетка(%d,%d) %s | world-Z(7+0.5z)=%.2f"
          % (name, x, y, z, cx, cy, info, 7.0 + 0.5 * float(z)))
