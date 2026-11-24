# -*- coding: utf-8 -*-
"""З9: геометрия моделей obw_* и посадка объектов главы относительно поверхности."""
import json, os, collections

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
ch = json.load(open(os.path.join(ROOT, "native_campaign_chapter.json"), encoding="utf-8"))
mo = json.load(open(os.path.join(ROOT, "native_campaign_models.json"), encoding="utf-8"))
print("models.json ключи:", list(mo.keys()))
for k in ("objects", "placements", "meshes"):
    v = mo.get(k)
    print(" ", k, type(v).__name__, len(v) if hasattr(v, "__len__") else "")
    if isinstance(v, list) and v:
        print("    ключи[0]:", list(v[0].keys()))
        print("    пример:", json.dumps(v[0], ensure_ascii=False)[:400])
    elif isinstance(v, dict) and v:
        kk = list(v.keys())[:3]
        print("    пример:", kk, json.dumps({x: v[x] for x in kk}, ensure_ascii=False)[:400])

cells = ch["cells"]
cellmap = {}
for c in cells:
    cellmap[(int(c["x"]), int(c["y"]))] = c
meshes = ch["meshes"]


def block_z(bid):
    zs = []
    for part in meshes.get(str(bid), []):
        v = part["vertices"]
        zs += [float(v[k]) for k in range(2, len(v), 5)]
    return (min(zs), max(zs)) if zs else (None, None)


print("\n=== Объекты Obw/Urw в главе ===")
for o in ch["objects"]:
    cls = str(o.get("class", ""))
    if "Obw" not in cls and "Urw" not in cls:
        continue
    lvl = float(o["z"])
    wz = 7.0 + 0.5 * lvl
    cx, cy = int(o["x"]), int(o["y"])
    c = cellmap.get((cx, cy))
    if c:
        lo, hi = block_z(str(int(c["block"])))
        surf = "свободная (%.1f)" % hi
        extra = "блок %s z[%.1f..%.1f]" % (c["block"], lo, hi)
    else:
        extra = "НЕТ КЛЕТКИ"
    print("  %-26s (%8.3f,%7.3f) level=%9.4f -> worldZ=%7.3f  %s" %
          (cls, o["x"], o["y"], lvl, wz, extra))
