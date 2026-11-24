# -*- coding: utf-8 -*-
"""З9 (уточнение): кто из объектов с уровнем < 0 попадает под остров, а кто нет;
и что именно оставляет порт по своему порогу OVERWORLD_GROUND_WORLD_Z = 2.0."""
import json, os

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
ch = json.load(open(os.path.join(ROOT, "native_campaign_chapter.json"), encoding="utf-8"))
mo = json.load(open(os.path.join(ROOT, "native_campaign_models.json"), encoding="utf-8"))

cells = {(int(c["x"]), int(c["y"])) for c in ch["cells"]}
xs = sorted({x for x, y in cells})
ys = sorted({y for x, y in cells})
print("клеток главы: %d, прямоугольник x %d..%d, y %d..%d" % (len(cells), xs[0], xs[-1], ys[0], ys[-1]))

# блок под каждой клеткой (для оценки, есть ли порода)
block = {(int(c["x"]), int(c["y"])): int(c["block"]) for c in ch["cells"]}
meshes = ch["meshes"]


def bz(bid):
    zs = []
    for part in meshes.get(str(bid), []):
        v = part["vertices"]
        zs += [float(v[k]) for k in range(2, len(v), 5)]
    return (min(zs), max(zs)) if zs else (None, None)


def wz(level):
    return 7.0 + 0.5 * level


neg = [p for p in mo["placements"] if float(p["z"]) < 0]
print("\nобъектов с уровнем < 0 (world-Z < 7.0): %d" % len(neg))

inside, outside = [], []
for p in neg:
    cell = (int(float(p["x"])), int(float(p["y"])))
    (inside if cell in cells else outside).append((p, cell))

print("\n=== ПОД ОСТРОВОМ (клетка главы) — в оригинале закрыты мешами: %d ===" % len(inside))
for p, cell in sorted(inside, key=lambda t: -float(t[0]["z"])):
    bid = block.get(cell)
    b = bz(bid) if bid is not None else None
    print("  %-24s level=%-10s world-Z=%8.2f  x=%8.2f y=%8.2f клетка=%-9s блок=%-6s z[%s..%s]" %
          (p["class"], p["z"], wz(float(p["z"])), p["x"], p["y"], cell, bid,
           b[0] if b else "-", b[1] if b else "-"))

print("\n=== ВНЕ острова (в пустоте) — видны в оригинале: %d ===" % len(outside))
for p, cell in sorted(outside, key=lambda t: -float(t[0]["z"])):
    print("  %-24s level=%-10s world-Z=%8.2f  x=%8.2f y=%8.2f клетка=%s" %
          (p["class"], p["z"], wz(float(p["z"])), p["x"], p["y"], cell))

# портовый порог
PORT = 2.0
kept = [p for p in neg if wz(float(p["z"])) >= PORT]
cut = [p for p in neg if wz(float(p["z"])) < PORT]
print("\n=== ПОРТ (OVERWORLD_GROUND_WORLD_Z = %.1f) ===" % PORT)
print("оставляет: %d, режет: %d" % (len(kept), len(cut)))
print("оставленные — все ли под островом?")
for p in sorted(kept, key=lambda q: float(q["z"])):
    cell = (int(float(p["x"])), int(float(p["y"])))
    print("   %-24s world-Z=%6.2f клетка=%-9s под островом: %s" %
          (p["class"], wz(float(p["z"])), cell, cell in cells))
print("резанные:")
for p in sorted(cut, key=lambda q: float(q["z"])):
    cell = (int(float(p["x"])), int(float(p["y"])))
    print("   %-24s world-Z=%6.2f клетка=%-9s под островом: %s" %
          (p["class"], wz(float(p["z"])), cell, cell in cells))
