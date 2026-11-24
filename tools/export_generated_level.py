#!/usr/bin/env python3
"""Exports a generated level into the format of the campaign chapter.

The level generator of the original (godot/scripts/native_level_generator.gd)
writes a plan: the templates of the level and the number of the objects of every
resource class. This tool stamps those templates of the installed game into a
map, exactly like the chapter export does, so a generated level can be looked
at and rendered.

The stamping itself is the code of tools/export_campaign_chapter.py: the same
readers of the pmp and the l2m files, the same blocks of the BlockDB and the
same detail atlas. The chapter export is used as a module, so there is only one
implementation of the format.

Source of truth, read-only:
  C:\\Program Files (x86)\\Steam\\steamapps\\common\\Diggles The Myth of Fenris\\data
"""
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import export_campaign_chapter as chapter  # noqa: E402


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--game-data", type=Path, required=True)
    parser.add_argument("--plan", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--model-manifest-output", type=Path, required=True)
    parser.add_argument("--detail-textures", type=Path, required=True)
    parser.add_argument("--atlas-output", type=Path, required=True)
    parser.add_argument("--reuse-atlas", type=Path, default=None,
                        help="An existing atlas that covers every detail of the level")
    args = parser.parse_args()

    plan = json.loads(args.plan.read_text(encoding="utf-8"))
    placements = []
    for entry in plan.get("placements", []):
        placements.append({
            "template": str(entry["template"]),
            "x": int(entry["x"]),
            "y": int(entry["y"]),
            "role": str(entry.get("role", "generated")),
        })

    # The chapter export builds its map from two lists: the placements of the
    # chapter and the story placements of the zone. A generated level has its
    # own list, so the chapter list is replaced by the plan and the story list
    # is empty.
    def fake_first_level(_rng):
        return placements, {
            "adapter": True,
            "source": "godot/scripts/native_level_generator.gd",
            "zone": plan.get("zone", ""),
            "seed": plan.get("seed", 0),
            "group_value": plan.get("group_value", 0.0),
            "resources": plan.get("resources", []),
        }

    chapter.first_level = fake_first_level
    chapter.zone_placements = lambda _root, _zone: []

    if args.reuse_atlas is not None:
        # The atlas of the chapter already holds every detail of the level, so
        # the file of the chapter is used and nothing new is written.
        atlas = json.loads(args.reuse_atlas.read_text(encoding="utf-8"))
        chapter.build_atlas = lambda _textures, _output: atlas

    sys.argv = [
        "export_generated_level.py",
        "--game-data", str(args.game_data),
        "--seed", str(plan.get("seed", 0)),
        "--output", str(args.output),
        "--model-manifest-output", str(args.model_manifest_output),
        "--detail-textures", str(args.detail_textures),
        "--atlas-output", str(args.atlas_output),
    ]
    result = chapter.main()
    if result != 0:
        return result
    place_resources(args.output, args.model_manifest_output, plan)
    return 0


def cell_height(level: dict, block: int) -> float:
    """The height of the surface of a cell, the top of its block."""
    highest = None
    for part in level["meshes"].get(str(block), []):
        values = part["vertices"]
        for index in range(0, len(values), 5):
            height = float(values[index + 2])
            if highest is None or height > highest:
                highest = height
    return highest if highest is not None else 0.0


def place_resources(output: Path, manifest_output: Path, plan: dict) -> None:
    """Places the objects of the resource classes in the caves of the level.

    The generator of the original fills the level with the classes of the
    filter (story.tcl:83 lg_set_objcount), the resources of a zone are the
    objects of these classes (story.tcl:960-987). The engine puts them on the
    floor of the level; here they are put on the floor of the caves, which is
    the surface of their cells.
    """
    resources = plan.get("resources", [])
    if not resources:
        return
    level = json.loads(output.read_text(encoding="utf-8"))
    manifest = json.loads(manifest_output.read_text(encoding="utf-8"))
    manifest_objects = manifest.get("objects", [])

    # The floor of the caves: the cells of their footprint.
    index = {(int(cell["x"]), int(cell["y"])): cell for cell in level["cells"]}
    floors: list[tuple[int, int, float]] = []
    for placement in plan.get("placements", []):
        if placement.get("role") != "cave":
            continue
        width = int(placement.get("width", 0))
        height = int(placement.get("height", 0))
        for column in range(int(placement["x"]), int(placement["x"]) + width):
            for row in range(int(placement["y"]), int(placement["y"]) + height):
                cell = index.get((column, row))
                if cell is None:
                    continue
                floors.append((column, row, cell_height(level, int(cell["block"]))))
    if not floors:
        return
    floors.sort()

    for resource in resources:
        object_class = str(resource["class"])
        count = int(resource["count"])
        source = next((item for item in manifest_objects if item.get("class") == object_class), None)
        if source is None:
            print(json.dumps({"warning": "no model for the resource class",
                              "class": object_class}, ensure_ascii=False))
            continue
        step = max(1, len(floors) // max(1, count))
        for number in range(count):
            column, row, height = floors[(number * step) % len(floors)]
            item = dict(source)
            item.update({
                "template": "generated",
                "template_x": column,
                "template_y": row,
                "class": object_class,
                "x": column + 0.5,
                "y": row + 0.5,
                "z": height,
                "rotation": [0.0, 0.0, 0.0],
                "owner": -1,
                "physic": True,
                "autolight": False,
                "boxed": False,
                "story": False,
                "source_line": 0,
            })
            level["objects"].append(item)
            manifest_objects.append(item)

    level["summary"]["objects"] = len(level["objects"])
    level["summary"]["objects_with_model"] = len(manifest_objects)
    level["summary"]["generated_resources"] = sum(int(item["count"]) for item in resources)
    add_light_placements(level, manifest)
    output.write_text(json.dumps(level, ensure_ascii=False, separators=(",", ":")), encoding="utf-8")
    manifest["objects"] = manifest_objects
    manifest_output.write_text(json.dumps(manifest, ensure_ascii=False, indent=1), encoding="utf-8")
    print(json.dumps({"resources": level["summary"]["generated_resources"],
                      "objects": level["summary"]["objects"]}, ensure_ascii=False))


def add_light_placements(level: dict, manifest: dict) -> None:
    """The light sources of the level are no models, so the model export drops
    them. The preview needs their places, so they are added to the manifest."""
    manifest_objects = manifest.get("objects", [])
    known = {str(item.get("class", "")) for item in manifest_objects}
    added = 0
    for item in level.get("objects", []):
        object_class = str(item.get("class", ""))
        if "LightSrc" not in object_class and "Feuerstelle" not in object_class:
            continue
        if object_class in known:
            continue
        known.add(object_class)
        entry = {
            "template": str(item.get("template", "")),
            "template_x": int(item.get("template_x", 0)),
            "template_y": int(item.get("template_y", 0)),
            "class": object_class,
            "x": float(item.get("x", 0.0)),
            "y": float(item.get("y", 0.0)),
            "z": float(item.get("z", 0.0)),
            "rotation": [0.0, 0.0, 0.0],
            "owner": -1,
            "physic": False,
            "autolight": True,
            "boxed": False,
            "story": False,
            "source_line": 0,
        }
        manifest_objects.append(entry)
        added += 1
    if added:
        print(json.dumps({"light_placements": added}, ensure_ascii=False))


if __name__ == "__main__":
    raise SystemExit(main())
