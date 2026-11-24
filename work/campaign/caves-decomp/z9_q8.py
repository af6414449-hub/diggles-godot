# -*- coding: utf-8 -*-
"""З9: эффективная сетка высот клетки (родитель + 4 квадранта) и локальный
уровень поверхности в точке объекта против его z-литерала."""
import struct, os, json

G = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"

BDB = {}
for db in (0, 1, 2):
    p = os.path.join(G, "BlockDB%d.BDB" % db)
    if not os.path.exists(p):
        continue
    d = open(p, "rb").read()
    N = struct.unpack_from("<I", d, 8)[0]
    bo = 28 + 18 * N
    for i in range(N):
        o = bo + i * 0x59
        BDB[i] = (d[o:o + 64], struct.unpack_from("<4i", d, o + 0x40))


def effective_grid(bid):
    """8x8 сетка клетки: квадранты (2x2) перекрывают родителя."""
    parent, children = BDB[bid]
    g = [list(parent[r * 8:r * 8 + 8]) for r in range(8)]
    for qi, ch in enumerate(children):
        if ch < 0:
            continue
        cg = BDB[ch][0]
        r0 = 0 if qi in (0, 1) else 4
        c0 = 0 if qi in (0, 2) else 4
        for r in range(r0, r0 + 4):
            for c in range(c0, c0 + 4):
                g[r][c] = cg[(r - r0) * 8 + (c - c0)]
    return g


def surface_level(bid, x, y):
    """Уровень поверхности в точке (x,y) внутри клетки (floor)."""
    cx, cy = int(x), int(y)
    g = effective_grid(bid)
    sx = min(7, max(0, int((x - cx) * 8)))
    sy = min(7, max(0, int((y - cy) * 8)))
    return g[sy][sx], g


ch = json.load(open(os.path.join(ROOT, "native_campaign_chapter.json"), encoding="utf-8"))
cellmap = {(int(c["x"]), int(c["y"])): int(c["block"]) for c in ch["cells"]}

print("%-26s %9s %8s %8s | %-6s %-9s %-9s %s" %
      ("class", "x", "y", "z(лит)", "клетка", "уровень", "worldZ", "вердикт"))
for o in ch["objects"]:
    cls = str(o.get("class", ""))
    if "Obw" not in cls and "Urw" not in cls and cls != "Zwerg":
        continue
    x, y, z = float(o["x"]), float(o["y"]), float(o["z"])
    cx, cy = int(x), int(y)
    bid = cellmap.get((cx, cy))
    if bid is None:
        lvl = None
    else:
        lvl, _ = surface_level(bid, x, y)
    wz = 7.0 + 0.5 * z
    if lvl is None:
        verdict = "НЕТ КЛЕТКИ"
        ltxt = "-"
    else:
        ltxt = "%d" % lvl
        dz = wz - (7.0 + 0.5 * lvl)
        verdict = "на поверхности" if abs(dz) < 0.3 else ("ниже на %.2f" % -dz)
    print("%-26s %9.3f %8.3f %8.3f | (%3d,%2d) %-6s %-9s %-9.2f %s" %
          (cls, x, y, z, cx, cy, bid, ltxt, wz, verdict))
