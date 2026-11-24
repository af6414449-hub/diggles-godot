#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Is the PMP attribute byte the native light of the cell?

The engine keeps the light of a cell in cell+0x07 (C+7): the .pmp loader writes
the attribute byte of the cell there, and FUN_005906a0 recomputes it from the
8x8 height grid (shadow of the neighbouring rock, 0..20). If the attribute is the
stored light, the cells under the surface must carry a smaller attribute than the
cells of the day surface.

The same test on the multiplayer map: its attributes come from the same .pmp
loader, so both maps answer the same question.
"""
import json
import os
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
MODELS = os.path.join(ROOT, "godot", "models")


def load(name):
    with open(os.path.join(MODELS, name), encoding="utf-8") as handle:
        return json.load(handle)


def chapter_report():
    chapter = load("native_campaign_chapter.json")
    meshes = chapter.get("meshes", {})
    levels = {}
    for cell in chapter.get("cells", []):
        block = int(cell["block"])
        highest = -1e9
        for part in meshes.get(str(block), []):
            values = part["vertices"]
            for index in range(2, len(values), 5):
                highest = max(highest, float(values[index]))
        levels[(int(cell["x"]), int(cell["y"]))] = highest
    buckets = defaultdict(Counter)
    for cell in chapter.get("cells", []):
        key = (int(cell["x"]), int(cell["y"]))
        attribute = int(cell.get("cell_attribute", 0))
        level = levels.get(key, 14.5)
        if level >= 14.49:
            buckets["surface (14.5)"][attribute] += 1
        elif level >= 12.0:
            buckets["shelf (12.0-14.5)"][attribute] += 1
        else:
            buckets["underground (<12.0)"][attribute] += 1
    print("== campaign chapter: attribute by surface level")
    for name in ("surface (14.5)", "shelf (12.0-14.5)", "underground (<12.0)"):
        counter = buckets[name]
        total = sum(counter.values())
        mean = sum(value * count for value, count in counter.items()) / max(1, total)
        print("   %-20s cells=%6d mean=%.2f  %s" % (
            name, total, mean, sorted(counter.items())))
    return chapter


def battle_report():
    render = load("native_terrain_render.json")
    terrain = load("multi_start_010_terrain.json")
    meshes = terrain.get("meshes", {})
    levels = {}
    for cell in terrain.get("cells", []):
        block = int(cell["block"])
        highest = -1e9
        for part in meshes.get(str(block), []):
            values = part["vertices"]
            for index in range(2, len(values), 5):
                highest = max(highest, float(values[index]))
        levels[(int(cell["x"]), int(cell["y"]))] = highest
    width = int(render["width"])
    height = int(render["height"])
    attributes = render["attributes"]
    buckets = defaultdict(Counter)
    for index in range(width * height):
        x = index % width
        y = index // width
        attribute = int(attributes[index])
        level = levels.get((x, y))
        if level is None:
            buckets["no cell in the export"][attribute] += 1
        elif level >= 14.49:
            buckets["surface (14.5)"][attribute] += 1
        elif level >= 12.0:
            buckets["shelf (12.0-14.5)"][attribute] += 1
        else:
            buckets["underground (<12.0)"][attribute] += 1
    print()
    print("== multiplayer map: attribute by surface level")
    for name in ("surface (14.5)", "shelf (12.0-14.5)", "underground (<12.0)", "no cell in the export"):
        counter = buckets[name]
        total = sum(counter.values())
        mean = sum(value * count for value, count in counter.items()) / max(1, total)
        print("   %-22s cells=%6d mean=%.2f  %s" % (
            name, total, mean, sorted(counter.items())))


if __name__ == "__main__":
    chapter_report()
    battle_report()
