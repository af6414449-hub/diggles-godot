# -*- coding: utf-8 -*-
"""Есть ли в меше блока вертикальные грани (откосы) и где они стоят.

Проверяем блок 71 (основная порода главы) и несколько других: ищем треугольники,
у которых два вершины имеют одинаковые (x, y), но разные z — это вертикальная грань.
Печатаем её положение (в локальных координатах блока) и её высоту.
"""
import json, os, collections

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
ch = json.load(open(os.path.join(ROOT, "native_campaign_chapter.json"), encoding="utf-8"))
meshes = ch["meshes"]
print("блоков в экспорте:", len(meshes))


def analyse(bid):
    parts = meshes.get(str(bid), [])
    vert = []
    for part in parts:
        v = part["vertices"]
        verts = [tuple(float(v[i + k]) for k in range(5)) for i in range(0, len(v), 5)]
        idx = part["indices"]
        for t in range(0, len(idx) - 2, 3):
            a, b, c = verts[idx[t]], verts[idx[t + 1]], verts[idx[t + 2]]
            for p, q in ((a, b), (b, c), (c, a)):
                if abs(p[0] - q[0]) < 1e-6 and abs(p[1] - q[1]) < 1e-6 and abs(p[2] - q[2]) > 1e-4:
                    # вертикальная грань: ребро вертикально
                    vert.append((round(p[0], 4), round(p[1], 4),
                                 round(min(p[2], q[2]), 4), round(max(p[2], q[2]), 4)))
    return vert


for bid in (71, 81, 59, 13868, 0):
    vs = analyse(bid)
    print("\n=== блок %s: вертикальных рёбер %d ===" % (bid, len(vs)))
    cnt = collections.Counter((x, y) for x, y, z0, z1 in vs)
    for (x, y), n in sorted(cnt.items()):
        zz = [(z0, z1) for (xx, yy, z0, z1) in vs if (xx, yy) == (x, y)]
        lo = min(z[0] for z in zz); hi = max(z[1] for z in zz)
        print("   x=%8.4f y=%8.4f  рёбер=%d  z[%.2f..%.2f]" % (x, y, n, lo, hi))
