"""Material probe for the campaign chapter.

Prints the ground texture family of every cell of the chapter, using the same
four-corner rule as the Godot profile (scripts/native_campaign_profile.gd), and
the distribution of the families. The free cells of the map are not in the
export, so the base layer of the scene needs a material of its own.

Usage:
    python tools/probe_campaign_materials.py
"""

import json
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
from probe_campaign_levels import dominant_level  # noqa: E402

ROOT = pathlib.Path(__file__).resolve().parent.parent
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"
TERRAIN_RENDER = ROOT / "godot" / "models" / "native_terrain_render.json"

OFFSETS = ((0, 0), (1, 0), (0, 1), (1, 1))


def ground_file(materials, patterns, x, y, variant):
    signature = ""
    for dx, dy in OFFSETS:
        value = materials.get("%d,%d" % (x + dx, y + dy))
        code = 0 if value is None or int(value) == 3 else int(value)
        signature += str(code)
    pattern = patterns.get(signature)
    if pattern is None:
        return "Gnd_A01.tga"
    if pattern.get("mixed"):
        return str(pattern.get("file"))
    return "Gnd_%s%02d.tga" % (str(pattern.get("family")), variant + 1)


def main():
    chapter = json.loads(CHAPTER.read_text(encoding="utf-8"))
    terrain_render = json.loads(TERRAIN_RENDER.read_text(encoding="utf-8"))
    materials = chapter.get("materials", {})
    patterns = terrain_render.get("patterns", {})

    families = {}
    by_level = {}
    meshes = chapter.get("meshes", {})
    for cell in chapter.get("cells", []):
        variant = max(0, min(13, int(cell.get("ground_variant", 1)) - 1))
        name = ground_file(materials, patterns, int(cell["x"]), int(cell["y"]), variant)
        families[name] = families.get(name, 0) + 1
        level = dominant_level(cell, meshes)
        slot = by_level.setdefault("%.2f" % level, {})
        slot[name] = slot.get(name, 0) + 1

    print("cells=%d distinct=%d" % (len(chapter.get("cells", [])), len(families)))
    for name in sorted(families):
        print("  %-16s %d" % (name, families[name]))

    by_family = {}
    for name, count in families.items():
        by_family.setdefault(name.split("_")[1][:1], 0)
        by_family[name.split("_")[1][:1]] += count
    print("families:", by_family)

    print("by level:")
    for level in sorted(by_level, key=lambda value: -float(value)):
        slot = by_level[level]
        counts = {}
        for name, count in slot.items():
            counts.setdefault(name.split("_")[1][:1], 0)
            counts[name.split("_")[1][:1]] += count
        print("  level %-6s cells=%-5d families=%s" % (level, sum(slot.values()), counts))


if __name__ == "__main__":
    main()
