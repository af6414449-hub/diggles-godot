#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Where are the 122 chapter light sources relative to the chapter cells?

The campaign chapter is placed on the 512x640 map at an offset; the light
sources of the chapter must live in the same coordinate space as the cells,
otherwise the terrain gets no contribution from them.
"""
import json
import os
from collections import Counter

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))


def load(rel):
    with open(os.path.join(ROOT, rel), encoding="utf-8") as handle:
        return json.load(handle)


chapter = load("godot/models/native_campaign_chapter.json")
cells = chapter.get("cells", [])
xs = [int(c["x"]) for c in cells]
ys = [int(c["y"]) for c in cells]
print("chapter cells: %d  x %d..%d  y %d..%d" % (len(cells), min(xs), max(xs), min(ys), max(ys)))

for key in ("placements", "story_placements"):
    rows = chapter.get(key, [])
    print()
    print("== %s: %d" % (key, len(rows)))
    for row in rows[:8]:
        pos = row.get("position", row.get("pos"))
        print("   ", row.get("class"), "pos", pos, "keys", list(row.keys())[:10])

lights = load("godot/models/native_campaign_lights.json")
print()
print("== light source classes:")
for name, count in sorted(lights.get("class_summary", {}).items()):
    print("   %-28s %s" % (name, count))
print()
print("== source block:")
print(json.dumps(lights.get("source", {}), ensure_ascii=False, indent=1)[:1500])

positions = [spec["position"] for spec in lights.get("lights", [])]
lx = [p[0] for p in positions]
ly = [p[1] for p in positions]
lz = [p[2] for p in positions]
print()
print("== light positions: x %s..%s  y %s..%s  z %s..%s" % (
    min(lx), max(lx), min(ly), max(ly), min(lz), max(lz)))
inside = sum(1 for p in positions if min(xs) <= p[0] <= max(xs) and min(ys) <= p[1] <= max(ys))
print("   lights inside the chapter cell box: %d of %d" % (inside, len(positions)))

by_class = Counter(spec["class"] for spec in lights.get("lights", []))
print("   light classes:", by_class.most_common())
sample = {}
for spec in lights.get("lights", []):
    sample.setdefault(spec["class"], spec)
for name, spec in sorted(sample.items()):
    print("   sample %-24s pos %s range %s color %s" % (
        name, spec["position"], spec["range"], spec["color"]))
