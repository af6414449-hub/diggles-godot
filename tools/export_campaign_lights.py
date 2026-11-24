#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The native light sources of the campaign chapter.

The battle scene lights its terrain with the light of the native scene: the
sources of the level are baked into the vertex colour of the terrain
(scripts/native_terrain_illumination.gd) and added as omni lights for the
models (scripts/native_scene_profile.gd:add_lights). The chapter has the same
native light classes in its templates - Misc_LightSrc_*, Urw_LightSrc_*,
Feuerstelle and the fire bowls - but the chapter export carries no light
specification, so the list is rebuilt here.

The specification of a light source is the class definition of the original:
every class that emits light has a "class_light {offset} range {colour}" line
in Scripts/classes/**. The exporter reads those definitions, takes the objects
of the chapter export whose class has a light, and writes the list of the
chapter.

The result is the same shape as the list of the battle scene
(godot/models/multi_start_010_profile.json -> lights): class, ordinal,
position, rotation, offset, range, colour and the sources of the rule.

Usage:
    python tools/export_campaign_lights.py [--game-data DIR] [--chapter PATH]
                                           [--output PATH]
"""
import argparse
import json
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
DEFAULT_GAME_DATA = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
DEFAULT_CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"
DEFAULT_OUTPUT = ROOT / "godot" / "models" / "native_campaign_lights.json"

# def_class <Name> <rest of the line>
DEF_CLASS = re.compile(r"^\s*def_class\s+(\S+)")
# class_light {ox oy oz} <range> {r g b} [extra]
CLASS_LIGHT = re.compile(
    r"^\s*class_light\s*\{([^}]*)\}\s*([-+0-9.eE]+)\s*\{([^}]*)\}\s*(.*)$")


def read_class_lights(game_data: pathlib.Path) -> dict:
    """The light of every native class that has one."""
    lights = {}
    classes = game_data / "Scripts" / "classes"
    for path in sorted(classes.rglob("*.tcl")):
        current = None
        try:
            lines = path.read_text(encoding="latin-1").splitlines()
        except OSError:
            continue
        for number, line in enumerate(lines, start=1):
            match = DEF_CLASS.match(line)
            if match is not None:
                current = match.group(1)
                continue
            if current is None:
                continue
            light = CLASS_LIGHT.match(line)
            if light is None:
                continue
            offset = [float(value) for value in light.group(1).split()]
            while len(offset) < 3:
                offset.append(0.0)
            colour = [float(value) for value in light.group(3).split()]
            while len(colour) < 3:
                colour.append(0.0)
            lights[current] = {
                "offset": offset[:3],
                "range": float(light.group(2)),
                "color": colour[:3],
                "extra": light.group(4).strip(),
                "class_source": {
                    "file": path.relative_to(game_data).as_posix(),
                    "line": number,
                },
            }
    return lights


def chapter_objects(chapter_path: pathlib.Path) -> list:
    chapter = json.loads(chapter_path.read_text(encoding="utf-8"))
    objects = chapter.get("objects", [])
    result = []
    for entry in objects:
        name = str(entry.get("class", ""))
        result.append({
            "class": name,
            "position": [float(entry["x"]), float(entry["y"]), float(entry.get("z", 0.0))],
            "rotation": [float(value) for value in entry.get("rotation", [0.0, 0.0, 0.0])],
            "source_line": int(entry.get("source_line", 0)),
            "template": str(entry.get("template", "")),
            "template_x": float(entry.get("template_x", 0.0)),
            "template_y": float(entry.get("template_y", 0.0)),
            "autolight": bool(entry.get("autolight", False)),
        })
    return result


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--game-data", default=DEFAULT_GAME_DATA)
    parser.add_argument("--chapter", default=str(DEFAULT_CHAPTER))
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT))
    arguments = parser.parse_args()

    game_data = pathlib.Path(arguments.game_data)
    chapter_path = pathlib.Path(arguments.chapter)
    output_path = pathlib.Path(arguments.output)

    class_lights = read_class_lights(game_data)
    objects = chapter_objects(chapter_path)

    counts = {}
    lights = []
    for entry in objects:
        name = entry["class"]
        spec = class_lights.get(name)
        if spec is None:
            continue
        ordinal = counts.get(name, 0)
        counts[name] = ordinal + 1
        lights.append({
            "class": name,
            "ordinal": ordinal,
            "position": entry["position"],
            "rotation": entry["rotation"],
            "offset": spec["offset"],
            "range": spec["range"],
            "color": spec["color"],
            "class_source": spec["class_source"],
            "placement_source": {
                "file": "Templates/%s.tcl" % entry["template"],
                "line": entry["source_line"],
                "template": entry["template"],
                "template_x": entry["template_x"],
                "template_y": entry["template_y"],
            },
            "autolight": entry["autolight"],
        })

    report = {
        "schema": "diggles.campaign_lights.v1",
        "source": {
            "chapter": chapter_path.name,
            "classes": "Scripts/classes/**/*.tcl",
            "rule": "class_light {offset} range {colour}",
        },
        "class_count": len(class_lights),
        "light_count": len(lights),
        "class_summary": counts,
        "lights": lights,
    }
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(report, ensure_ascii=False, indent=1), encoding="utf-8")
    print("classes with a light: %d" % len(class_lights))
    print("lights of the chapter: %d" % len(lights))
    for name in sorted(counts):
        print("  %-24s %d" % (name, counts[name]))
    print("written %s" % output_path)
    return 0


if __name__ == "__main__":
    sys.exit(main())
