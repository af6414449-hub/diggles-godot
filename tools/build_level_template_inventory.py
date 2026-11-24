#!/usr/bin/env python3
"""The inventory of the level generator of the original game.

The original fills a zone of the campaign map with a generated level: a chain of
tunnels, caves dug beside it and the objects of the resource classes. The rules
live in four places of the installed game, all of them read-only:

  data/Scripts/init/lginit.tcl      the template groups per world, the filter
                                   classes and the properties of the templates
  data/Scripts/init/lgtools.tcl     the syntax of a group and the props of a
                                   template (gamecount, levelcount, tunnel)
  data/Scripts/classes/story/story.tcl
                                   the quotas of the resource classes per zone
                                   and the calls that run the generator
  data/Templates/<set>.ent          the connection points of the templates

This tool writes the inventory of the template families of every world: the
name of every template, the size of its map (the header of its pmp file), the
classes of its objects and the connection points that join the templates into
a chain. The generator reads this inventory, so it knows the real templates of
the original and not a guess.

The reading of the ent files follows the native loader of Diggles.exe
(FUN_005826d0): it takes only the points of the kind 1, it moves the point into
the block of the template and it derives the side of the point from its place
in the block.

Source of truth, read-only:
  C:\\Program Files (x86)\\Steam\\steamapps\\common\\Diggles The Myth of Fenris\\data
"""
from __future__ import annotations

import argparse
import json
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import export_campaign_chapter as chapter  # noqa: E402  (the pmp and tcl readers)

# lginit.tcl:8-43 - the groups of the generator. The pool of a family is a
# glob over the templates of the world: 'tcl/urw_gng_*' and so on.
ZONES: dict[str, str] = {
    "Urwald": "urw",
    "Metall": "swf",
    "Kristall": "kris",
    "Lava": "lava",
}

# lginit.tcl:8-15 - the three families of a group.
FAMILIES: dict[str, str] = {
    "Gng": "gng",
    "Gsg": "gsg",
    "Hol": "hol",
}

# story.tcl:142-146 - the value of the group of the caves of a zone.
GROUP_VALUES: dict[str, float] = {
    "Urwald": 0.287,
    "Metall": 0.185,
    "Kristall": 0.077,
    "Lava": 0.105,
}

# story.tcl:960-987 - the object count per class and zone.
OBJECT_COUNTS: dict[str, dict[str, int]] = {
    "Urwald": {"Kohle": 0, "Kristallerz": 0, "Golderz": 0, "Eisenerz": 0, "Pilz": 12},
    "Metall": {"Kohle": 5, "Kristallerz": 0, "Golderz": 2, "Eisenerz": 15, "Pilz": 5},
    "Kristall": {"Kohle": 15, "Kristallerz": 20, "Golderz": 5, "Eisenerz": 20, "Pilz": 5},
    "Lava": {"Kohle": 20, "Kristallerz": 20, "Golderz": 15, "Eisenerz": 20, "Pilz": 3},
}

# lginit.tcl:6 - the classes the generator may fill a spot with.
FILTER_CLASSES: list[str] = [
    "Zwerg", "Wuker", "Troll", "Pilz", "Kohle",
    "Kristallerz", "Golderz", "Eisenerz", "Schatztonne",
]

# lginit.tcl:46-51 - the properties of the templates that are not the default:
# game count, level count and the tunnel weight.
TEMPLATE_PROPS: list[dict[str, object]] = [
    {"template": "urw_gng_050_a", "gamecount": 1, "levelcount": 1, "tunnel": None},
    {"template": "urw_gng_051_a", "gamecount": 1, "levelcount": 1, "tunnel": None},
    {"template": "urw_gng_052_a", "gamecount": 1, "levelcount": 1, "tunnel": None},
    {"template": "urw_gng_054_a", "gamecount": 1, "levelcount": 1, "tunnel": None},
]

# lgtools.tcl:66-71 - the group of the caves and the group of the galleries get
# a level count of one: every template of them may be used once in a level.
GROUP_LEVEL_COUNT: dict[str, int] = {
    "Hol": 1,
    "Gsg": 1,
}

# The sides of a template. The native derives the side of a connection point
# from its place in the block of the template (FUN_005826d0): a point on the
# left border is a left point, one on the right border a right point, and so
# on. A point in a corner takes the side of the border it was tested last.
SIDE_TOP: int = 0
SIDE_RIGHT: int = 1
SIDE_BOTTOM: int = 2
SIDE_LEFT: int = 3


def _div8(value: int) -> int:
    """The division by eight of the native: it rounds towards zero."""
    if value >= 0:
        return value >> 3
    return -((-value + 7) >> 3)


def read_entries(ent_path: Path, width: int, height: int) -> tuple[list[dict], int, int]:
    """The connection points of a template, from the ent file of its set.

    The native reads the ent file in FUN_005826d0 and does the same: it takes
    only the points of the kind 1, it moves the point into the block of the
    template and it derives the side of the point from its place.

    Returns the points, the mask of the sides they use and the mode of the
    template (1 horizontal, 2 vertical, 0 unknown).
    """
    entries: list[dict] = []
    flags: int = 0
    if not ent_path.is_file():
        return entries, flags, 0
    text = ent_path.read_text(encoding="cp1252", errors="replace")
    for line in text.splitlines():
        parts = line.split()
        if len(parts) < 4 or parts[0] != "map_entry":
            continue
        try:
            kind = int(parts[1])
            raw_x = int(parts[2])
            raw_y = int(parts[3])
        except ValueError:
            continue
        if kind != 1:
            # The native takes only the points of the kind 1.
            continue
        x = _div8(raw_x) & ~3
        y = _div8(raw_y) & ~3
        mod_x = raw_x & 31
        mod_y = raw_y & 31
        if mod_y < mod_x:
            if mod_x + mod_y < 32:
                x += 2
            else:
                x += 4
                y += 2
        else:
            if mod_x + mod_y < 32:
                y += 2
            else:
                x += 2
                y += 4
        side = -1
        if x == 0:
            side = SIDE_LEFT
        if y == 0:
            side = SIDE_TOP
        if x == width:
            side = SIDE_RIGHT
        if y == height:
            side = SIDE_BOTTOM
        if side < 0:
            # A point that is not on a border of the block joins nothing.
            continue
        entries.append({"x": x, "y": y, "side": side})
        flags |= 1 << side
    return entries, flags, _connect_mode(entries, width, height)


def _connect_mode(entries: list[dict], width: int, height: int) -> int:
    """The mode of a template: 1 horizontal, 2 vertical, 0 unknown.

    The native sets it when the template has two points and the block of the
    template is four cells wide or high (FUN_005826d0).
    """
    if len(entries) != 2:
        return 0
    state = 0
    for entry in entries:
        if entry["side"] == SIDE_TOP:
            state = 2
        elif entry["side"] == SIDE_BOTTOM:
            state = 1
    if state == 0:
        return 0
    size = height if state == 1 else width
    return state if size == 4 else 0


def template_size(root: Path, template: dict) -> tuple[int, int]:
    """The size of the map of a template, from the header of its pmp file."""
    if not template["pmp"]:
        return 0, 0
    pmp_path = root / "Templates" / Path(template["pmp"]).name
    if not pmp_path.is_file():
        return 0, 0
    width, height, _flags, _refs, _attributes = chapter.read_pmp(pmp_path)
    return width, height


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--game-data", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    root = args.game_data
    templates_dir = root / "Templates"

    props = {str(item["template"]): item for item in TEMPLATE_PROPS}

    zones: dict[str, dict] = {}
    for zone, prefix in ZONES.items():
        families: dict[str, dict] = {}
        for family, middle in FAMILIES.items():
            entries = []
            for path in sorted(templates_dir.glob(f"{prefix}_{middle}_*.tcl")):
                name = path.stem
                template = chapter.read_template(root, name)
                width, height = template_size(root, template)
                classes = Counter(item["class"] for item in template["objects"])
                # The set of the template: the map and the points of the
                # connection live in files of the set (gng_050.pmp,
                # gng_050.ent) and every variant of the set shares them.
                set_name = Path(template["pmp"]).stem if template["pmp"] else ""
                points, flags, mode = read_entries(
                    templates_dir / f"{set_name}.ent", width, height)
                own = props.get(name, {})
                group_count = GROUP_LEVEL_COUNT.get(family, 0)
                level_count = own.get("levelcount", group_count)
                entries.append({
                    "name": name,
                    "set": set_name,
                    "width": width,
                    "height": height,
                    "objects": len(template["objects"]),
                    "classes": dict(classes.most_common()),
                    "entries": points,
                    "side_flags": flags,
                    "connect_mode": mode,
                    "level_count": int(level_count) if level_count is not None else 0,
                    "game_count": int(own.get("gamecount", 0) or 0),
                    "tunnel": own.get("tunnel"),
                })
            families[family] = {
                "prefix": f"{prefix}_{middle}_",
                "count": len(entries),
                "level_count": GROUP_LEVEL_COUNT.get(family, 0),
                "templates": entries,
            }
        zones[zone] = {
            "prefix": f"{prefix}_",
            "group_value": GROUP_VALUES[zone],
            "object_counts": OBJECT_COUNTS[zone],
            "families": families,
        }

    result = {
        "schema": "diggles.level_templates.v2",
        "source": {
            "groups": "data/Scripts/init/lginit.tcl:8-43 LG_set_templategroup",
            "syntax": "data/Scripts/init/lgtools.tcl:4-56 LG_set_templategroup",
            "props": "data/Scripts/init/lginit.tcl:46-51 LG_set_templateprops",
            "group_props": "data/Scripts/init/lgtools.tcl:66-71 LG_set_templategroupprops",
            "filter": "data/Scripts/init/lginit.tcl:6 lg_addfilterclass",
            "quotas": "data/Scripts/classes/story/story.tcl:960-987 oc_list",
            "group_values": "data/Scripts/classes/story/story.tcl:142-146 lg_set_templategroupvalue",
            "entries": "data/Templates/<set>.ent map_entry (loader FUN_005826d0)",
        },
        "filter_classes": FILTER_CLASSES,
        "template_props": TEMPLATE_PROPS,
        "zones": zones,
        "summary": {
            zone: {
                family: data["count"]
                for family, data in zones[zone]["families"].items()
            }
            for zone in zones
        },
    }

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, ensure_ascii=False, separators=(",", ":")),
                           encoding="utf-8")
    print(json.dumps({"output": str(args.output), **result["summary"]}, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
