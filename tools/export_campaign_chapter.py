"""Export the first campaign chapter map (Urwald chapter 1) from the original game.

The original chapter is not a map file. `Scripts/gameplay/Campaign.tcl` assembles
it at load time from the campaign's own templates:

  Campaign.tcl:2    map create 512 640
  Campaign.tcl:12   set temppos {208 0}; call templates/tcl/urw_unq_start.tcl
  Campaign.tcl:13   set temppos {30 23}; call templates/tcl/urw_unq_hoehlenmalerei.tcl
  Campaign.tcl:15   map_setlayer2 30 23 data/templates/urw_unq_hoehlenmalerei.l2m
  Campaign.tcl:22   proc first_level {startx starty}
  Campaign.tcl:195  first_level 208 0

This exporter reproduces that assembly for one seed and writes the merged
512x640 chapter as a single manifest that the Godot scene can render.

The chapter map is NOT the multiplayer map: the multiplayer reference level
comes from Templates/multi_urw_start_010_a_0.tcl, and none of its cells,
objects or story belong to the campaign.

Sources are read-only, installed game:
  C:\\Program Files (x86)\\Steam\\steamapps\\common\\Diggles The Myth of Fenris\\data

Outputs:
  godot/models/native_campaign_chapter.json       merged chapter manifest
  godot/models/native_campaign_terrain_render.json per-cell ground materials
  godot/assets/terrain_detail/native_campaign_detail_atlas.png
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import shutil
import struct
import sys
from collections import Counter
from pathlib import Path

from PIL import Image

sys.path.insert(0, str(Path(__file__).resolve().parent))

from diggles_rng import DigglesRandom
from extract_template_objects import NEW, coordinate_values, index_class_assets
from inspect_bdb import BdbDatabase

MAP_WIDTH = 512
MAP_HEIGHT = 640

# ---------------------------------------------------------------------------
# Verbatim source readers, reused from the project tooling.
# ---------------------------------------------------------------------------


def read_pmp(path: Path) -> tuple[int, int, bytes, tuple[int, ...], bytes]:
    """PMP layout as loaded by Diggles.exe (see tools/export_pmp_terrain.py)."""
    data = path.read_bytes()
    if len(data) < 12:
        raise ValueError("PMP header is truncated")
    width, height = struct.unpack_from("<II", data)
    cells = width * height
    tail = 8 + 5 * cells
    if width < 1 or height < 1 or tail + 4 > len(data):
        raise ValueError("Invalid PMP dimensions")
    tail_count = struct.unpack_from("<I", data, tail)[0]
    if tail + 4 + 2 * tail_count + cells != len(data):
        raise ValueError("PMP layout does not match the observed loader")
    trailing_offset = tail + 4 + 2 * tail_count
    return (width, height, data[8:8 + cells],
            struct.unpack_from(f"<{cells}I", data, 8 + cells),
            data[trailing_offset:trailing_offset + cells])


def materials(width: int, height: int, flags: bytes) -> list:
    """Per-cell ground material from the source flags.

    Verbatim from tools/export_native_terrain_render.py; the four-corner rule
    is the native loader behaviour, not a guess.
    """
    first = [{0: 0, 2: 3, 3: 2, 4: 1, 5: 4}[value & 127] for value in flags]
    result = []
    for y in range(height):
        for x in range(width):
            code = next((first[(y + dy) * width + x + dx] for dx, dy in ((0, 0), (0, 1), (1, 0), (1, 1))
                         if x + dx < width and y + dy < height and first[(y + dy) * width + x + dx]), 0)
            result.append(None if not code else (3 if code == 4 else code - 1))
    return result


def canonical(corners: tuple) -> list:
    values = [0 if value == 3 else value for value in corners]
    if sum(1 << value for value in set(values)) >= 7:
        values = [0 if value == 2 else value for value in values]
    return values


# ---------------------------------------------------------------------------
# The story content of a campaign zone.
# ---------------------------------------------------------------------------
# Scripts/gameplay/CampaignInit.tcl registers the hand made caves of a zone:
#   sm_add_zone "Urwald"
#   sm_add_temp urw_der_einsiedler 56 60
#   sm_def_temp_group urw_trollburg_ring { {56 20 urw_gng_015_b} ... }
# The group members are placed relative to the position of the group.
GROUP_PATTERN = re.compile(r"sm_def_temp_group\s+(\S+)\s*\{")
ZONE_PATTERN = re.compile(r'sm_add_zone\s+"([^"]*)"')
TEMP_PATTERN = re.compile(r"sm_add_temp\s+(\S+)\s*(.*)$")

# story.tcl:249-252 swaps urw_unq_troll_012_a and urw_unq_troll_014_a: the
# engine puts one of the two on the same spot, never both of them.
EXCLUSIVE_PAIRS = (("urw_unq_troll_012_a", "urw_unq_troll_014_a"),)


def _braced_block(text: str, brace: int) -> str:
    """The braced block that starts at the opening brace at the index."""
    depth = 0
    for index in range(brace, len(text)):
        char = text[index]
        if char == "{":
            depth += 1
        elif char == "}":
            depth -= 1
            if depth == 0:
                return text[brace:index + 1]
    raise ValueError("Unbalanced braces in the template group")


def template_groups(root: Path) -> dict:
    """The template groups of CampaignInit.tcl: name -> [(dx, dy, template)]."""
    path = root / "Scripts" / "gameplay" / "CampaignInit.tcl"
    text = path.read_text(encoding="cp1252", errors="replace")
    groups = {}
    for match in GROUP_PATTERN.finditer(text):
        brace = text.index("{", match.end() - 1)
        members = []
        for row in re.findall(r"\{([^{}]*)\}", _braced_block(text, brace)):
            parts = row.split()
            # A group holds placements and "mat" material rectangles; only the
            # placements are templates.
            if len(parts) == 3 and parts[0].isdigit() and parts[1].isdigit():
                members.append((int(parts[0]), int(parts[1]), parts[2]))
        groups[match.group(1)] = members
    return groups


def zone_placements(root: Path, zone: str) -> list:
    """The templates of one campaign zone, with their map positions.

    The positions are map cells: the groups of the Urwald zone span x 56..272
    and y 60..208 of the 512x640 map of Campaign.tcl:2.
    """
    path = root / "Scripts" / "gameplay" / "CampaignInit.tcl"
    text = path.read_text(encoding="cp1252", errors="replace")
    groups = template_groups(root)
    placements = []
    current_zone = ""
    for line in text.splitlines():
        zone_match = ZONE_PATTERN.search(line)
        if zone_match:
            current_zone = zone_match.group(1)
            continue
        temp_match = TEMP_PATTERN.match(line.strip())
        if not temp_match or current_zone != zone:
            continue
        name = temp_match.group(1)
        arguments = temp_match.group(2).split()
        if len(arguments) < 2 or not arguments[0].isdigit() or not arguments[1].isdigit():
            # No position: the campaign script places the template itself.
            continue
        base_x = int(arguments[0])
        base_y = int(arguments[1])
        if name in groups:
            for offset_x, offset_y, member in groups[name]:
                placements.append({
                    "template": member, "x": base_x + offset_x, "y": base_y + offset_y,
                    "role": "story", "group": name,
                    "source": "CampaignInit.tcl sm_def_temp_group %s" % name,
                })
        else:
            placements.append({
                "template": name, "x": base_x, "y": base_y, "role": "story",
                "source": "CampaignInit.tcl sm_add_temp %s" % name,
            })
    # One template of every exclusive pair.
    kept = []
    for placement in placements:
        name = placement["template"]
        skip = False
        for pair in EXCLUSIVE_PAIRS:
            if name not in pair:
                continue
            partner = pair[0] if pair[1] == name else pair[1]
            if any(item["template"] == partner and item["x"] == placement["x"]
                   and item["y"] == placement["y"] for item in kept):
                skip = True
        if skip:
            continue
        kept.append(placement)
    return kept


def texture_tables(root: Path) -> dict:
    path = root / "Scripts/init/txtinit.tcl"
    text = path.read_text(encoding="cp1252", errors="replace")
    tables = {}
    for match in re.finditer(r"load_scape_texture\s+(\d+)\s+(\d+)\s*\{", text):
        rows = re.findall(r"\{([^{}]*)\}", _block_at(text, match.end() - 1))
        if len(rows) != 16:
            raise ValueError(f"Expected 16 texture masks: {match.group(0)}")
        tables[(int(match[1]), int(match[2]))] = [row.split() for row in rows]
    return tables


def _block_at(text: str, opening: int) -> str:
    depth = 0
    for index in range(opening, len(text)):
        if text[index] == "{":
            depth += 1
        elif text[index] == "}":
            depth -= 1
            if depth == 0:
                return text[opening + 1:index]
    raise ValueError("Unclosed Tcl block")


def decode_detail(word: int, part: int, tables: dict) -> dict:
    """L2M detail selection, Diggles.exe 0x4C4C50..0x4C4DDD."""
    states = [(word >> (8 + 2 * index)) & 3 for index in range(4)]
    bank = 0
    for state in states:
        if state == 0:
            break
        if state == 2:
            bank = 1
            break
    mask = sum((state != bank) << index for index, state in enumerate(states))
    if part == 1:
        mask = (mask & ~4) | ((mask & 1) << 2)
        mask = (mask & ~8) | ((mask & 2) << 2)
    elif part == 2:
        mask = (mask & ~1) | ((mask & 2) >> 1)
        mask = (mask & ~4) | ((mask & 8) >> 1)
    theme = (word >> 5) & 7
    variant = word & 31
    options = tables.get((theme, bank), [[]] * 16)[mask]
    texture = options[variant % len(options)] if mask and options else "50PGray.tga"
    return {"texture": texture, "theme": theme, "bank": bank, "mask": mask,
            "variant": variant, "states": states}


# ---------------------------------------------------------------------------
# first_level, ported from Scripts/gameplay/Campaign.tcl:22-191.
# ---------------------------------------------------------------------------

CAVE_LIST = [("urw_hol_001_a", 20, 4), ("urw_hol_014_b", 20, 12),
             ("urw_hol_018_c", 28, 16), ("urw_hol_019_b", 24, 16),
             ("urw_hol_027_a", 16, 4)]

COMB_LIST = [(0, 1, [0]), (0, 2, [0]), (0, 4, [0]), (1, 0, [4]),
             (1, 3, [4]), (4, 0, [0]), (4, 2, [0]), (4, 3, [0])]

TUNNEL_LIST = [("urw_gng_013_", 4, 0), ("urw_gng_002_", 8, 0), ("urw_gng_003_", 12, 0)]

# The first element of each connection is the horizontal shift of the level
# (Campaign.tcl:114 consumes it with lrem); the rest is the tunnel sequence.
CONNECTION_LIST = [(0, [0, 0, 1, 2]), (0, [0, 0, 2, 1]), (0, [0, 1, 0, 2]),
                   (4, [4, 2, 0, 1]), (4, [4, 2, 1, 0]), (4, [4, 1, 2, 0])]

VODO_LIST = [("urw_gng_001_", "ab"), ("urw_gng_007_", "abcd"), ("urw_gng_008_", "abc"),
             ("urw_gng_009_", "abcd"), ("urw_gng_012_", "abcd"), ("urw_gng_019_", "abc"),
             ("urw_gng_022_", "abdeg"), ("urw_gng_023_", "abc"), ("urw_gng_026_", "abc"),
             ("urw_gng_028_", "bcd"), ("urw_gng_030_", "a"), ("urw_gng_032_", "ab"),
             ("urw_gng_034_", "acdfhk"), ("urw_gng_039_", "ab"), ("urw_gng_042_", "ab"),
             ("urw_gng_045_", "ab"), ("urw_unq_vodo_001_", "a"), ("urw_gng_004_", "ab"),
             ("urw_gng_027_", "abc"), ("urw_gng_036_", "ab"), ("urw_gng_043_", "ab"),
             ("urw_gng_044_", "ab")]

VODO_CHAINS_LEFT = [
    [(3, 20, 0), (8, 8, 12), (5, 20, 12), (6, 24, 12), (16, -24, 12)],
    [(1, 20, 0), (13, 4, 16), (7, 4, 28), (9, 12, 4), (16, -28, 12)],
    [(2, 20, 0), (5, 20, 8), (6, 24, 8), (15, 8, 8), (12, 4, 16), (6, 16, 24), (16, -28, 12)],
    [(2, 20, 0), (14, 12, 8), (4, 8, 12), (13, 0, 16), (7, 0, 28), (16, -32, 12)],
    [(2, 20, 0), (11, 0, 16), (15, 8, 8), (5, 20, 8), (6, 24, 8), (7, 8, 28), (16, -32, 12)],
    [(1, 20, 0), (6, 16, 20), (4, 8, 8), (14, 12, 4), (10, 4, 12), (16, -28, 12)],
]

VODO_CHAINS_RIGHT = [
    [(18, 20, 0), (0, 20, 20), (10, 24, 12), (6, 36, 20), (16, -12, 12)],
    [(20, 20, 0), (21, 32, 4), (17, 20, 20), (10, 36, 12), (6, 48, 20), (16, -12, 12)],
    [(19, 20, 0), (1, 24, 12), (14, 16, 16), (6, 32, 8), (16, -16, 12)],
]

LEFT_LETTER_SETS = ("abdef", "cgih")
RIGHT_LETTER_SETS = ("cfkh", "abdeg")


def first_level(rng: DigglesRandom, start_x: int = 208, start_y: int = 0) -> tuple[list, dict]:
    """Reproduce Campaign.tcl:first_level for one seed."""
    placements = []
    present_side = rng.irandom(2)
    left_letters = LEFT_LETTER_SETS[present_side]
    right_letters = RIGHT_LETTER_SETS[present_side]
    std_x = start_x + 36
    std_y = start_y + 40

    comb_index = rng.irandom(len(COMB_LIST))
    left_id, right_id, y_offsets = COMB_LIST[comb_index]
    std_y += y_offsets[rng.irandom(len(y_offsets))]

    conn_index = rng.irandom(len(CONNECTION_LIST))
    x_shift, tunnels = CONNECTION_LIST[conn_index]
    std_x += x_shift
    # Campaign.tcl:114 - lrem conn 0 consumes the first element of the
    # connection as the horizontal shift; the loop below runs over the rest.
    tunnels = list(tunnels[1:])

    if conn_index < 2:
        chains = VODO_CHAINS_RIGHT
    elif conn_index < 4:
        chains = VODO_CHAINS_LEFT + VODO_CHAINS_RIGHT
    else:
        chains = VODO_CHAINS_LEFT
    chain = chains[rng.irandom(len(chains))]

    # Left cave and its end piece.
    name, x_offset, y_offset = CAVE_LIST[left_id]
    left_x = std_x - x_offset
    placements.append({"template": name, "x": left_x, "y": std_y - y_offset, "role": "cave"})
    letter = left_letters[rng.irandom(len(left_letters))]
    placements.append({"template": "urw_gng_021_" + letter, "x": left_x - 4, "y": std_y,
                       "role": "cave_end"})

    # Right cave and its end piece.
    name, x_offset, y_offset = CAVE_LIST[right_id]
    placements.append({"template": name, "x": std_x + 24, "y": std_y - y_offset, "role": "cave"})
    letter = right_letters[rng.irandom(len(right_letters))]
    placements.append({"template": "urw_gng_022_" + letter, "x": std_x + x_offset + 24,
                       "y": std_y, "role": "cave_end"})

    # Tunnel chain. vodo_x is fixed when the chain reaches tunnel 0.
    x = std_x
    vodo_x = 0
    vodo_y = 0
    for tunnel_id in tunnels:
        if tunnel_id == 0:
            vodo_x = x - 20
            vodo_y = std_y + 4
        prefix, x_offset, y_offset = TUNNEL_LIST[tunnel_id]
        letters = "ab" if prefix == "urw_gng_002_" else "abc"
        placements.append({"template": prefix + letters[rng.irandom(len(letters))], "x": x,
                           "y": std_y + y_offset, "role": "tunnel"})
        x += x_offset

    # Voodoo chain.
    for template_id, dx, dy in chain:
        prefix, variants = VODO_LIST[template_id]
        placements.append({"template": prefix + variants[rng.irandom(len(variants))],
                           "x": vodo_x + dx, "y": vodo_y + dy, "role": "voodoo"})

    state = {
        "present_side": present_side,
        "left_letters": left_letters,
        "right_letters": right_letters,
        "combination_index": comb_index,
        "connection_index": conn_index,
        "voodoo_chain_count": len(chains),
        "voodoo_chain_length": len(chain),
        "std_x": std_x,
        "std_y": std_y,
        "vodo_x": vodo_x,
        "vodo_y": vodo_y,
    }
    return placements, state


# ---------------------------------------------------------------------------
# Template contract.
# ---------------------------------------------------------------------------

PMP_PATTERN = re.compile(r"map_template\s+(\S+\.pmp)")
L2M_PATTERN = re.compile(r"map_setlayer2\s+\S+\s+\S+\s+(\S+\.l2m)")
FLAG_PATTERN = re.compile(r"^set_(owner|physic|autolight|boxed)\s+\$objhandle\s+(.+?)\s*$")


def read_template(root: Path, name: str) -> dict:
    # The flat templates in Templates/ are the ones the chapter calls:
    # Campaign.tcl:186 calls "data/templates/$template.tcl". Templates/tcl/
    # holds the sources, including the split_template form of the start area.
    path = root / "Templates" / f"{name}.tcl"
    if not path.is_file():
        raise FileNotFoundError(f"template {name} not found")
    text = path.read_text(encoding="cp1252", errors="replace")
    pmp_match = PMP_PATTERN.search(text)
    l2m_match = L2M_PATTERN.search(text)
    objects = []
    last = None
    tier = "default"
    for line_number, line in enumerate(text.splitlines(), 1):
        tier_match = re.search(r"\bloading_objdetail\s+(high|medium|low|off)\b", line)
        if tier_match:
            tier = tier_match.group(1)
        for match in NEW.finditer(line):
            class_name, position, rotation = match.groups()
            coords = coordinate_values(position)
            if coords is None:
                continue
            last = {
                "class": class_name,
                "local_x": coords[0],
                "local_y": coords[1],
                "z": coords[2],
                "rotation": [float(value) for value in rotation.split()],
                "detail_tier": tier,
                "source_line": line_number,
            }
            objects.append(last)
        flag_match = FLAG_PATTERN.match(line.strip())
        if flag_match and last is not None:
            name_flag, raw = flag_match.groups()
            last[name_flag] = _flag_value(raw)
    return {
        "name": name,
        "source": str(path),
        "pmp": pmp_match.group(1) if pmp_match else "",
        "l2m": l2m_match.group(1) if l2m_match else "",
        "objects": objects,
    }


def _flag_value(raw: str):
    if raw in ("true", "1"):
        return True
    if raw in ("false", "0"):
        return False
    try:
        return int(raw)
    except ValueError:
        return raw


def read_layer2(path: Path) -> tuple[int, int, tuple]:
    layer = path.read_bytes()
    magic, width, height = struct.unpack_from("<4sII", layer)
    if magic != b"M2L\0" or len(layer) != 12 + width * height * 2:
        raise ValueError("Invalid L2M dimensions/signature")
    return width, height, struct.unpack_from(f"<{width * height}H", layer, 12)


def build_atlas(textures: dict, output: Path) -> dict:
    """One atlas for every detail texture used by the chapter."""
    tile, padding, columns = 64, 8, 8
    stride = tile + 2 * padding
    rows = (len(textures) + columns - 1) // columns
    atlas = Image.new("RGB", (columns * stride, rows * stride))
    slots = {}
    for index, name in enumerate(sorted(textures)):
        image = textures[name].convert("RGB")
        if image.size == (1, 1):
            image = image.resize((tile, tile), Image.Resampling.NEAREST)
        x, y = index % columns, index // columns
        slots[name] = [x, y]
        for offset_x in (-tile, 0, tile):
            for offset_y in (-tile, 0, tile):
                dest = (x * stride + padding + offset_x, y * stride + padding + offset_y)
                left = max(dest[0], x * stride)
                top = max(dest[1], y * stride)
                right = min(dest[0] + tile, (x + 1) * stride)
                bottom = min(dest[1] + tile, (y + 1) * stride)
                if right > left and bottom > top:
                    atlas.paste(image.crop((left - dest[0], top - dest[1],
                                            right - dest[0], bottom - dest[1])), (left, top))
    output.parent.mkdir(parents=True, exist_ok=True)
    atlas.save(output)
    return {"file": output.name, "size": list(atlas.size), "tile_size": tile,
            "padding": padding, "stride": stride, "slots": slots}


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--game-data", type=Path, required=True)
    parser.add_argument("--seed", type=int, default=0)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--model-manifest-output", type=Path, required=True)
    parser.add_argument("--detail-textures", type=Path, required=True)
    parser.add_argument("--atlas-output", type=Path, required=True)
    args = parser.parse_args()

    root = args.game_data
    rng = DigglesRandom(args.seed)
    procedural, state = first_level(rng)

    # Campaign.tcl:12-15 - the chapter prologue. urw_unq_hoehlenmalerei is
    # called but its MapTemplateSet is commented out, so it contributes only
    # the material layer.
    placements = [
        {"template": "urw_unq_start", "x": 208, "y": 0, "role": "chapter_start"},
        {"template": "urw_unq_hoehlenmalerei", "x": 30, "y": 23, "role": "layer_only"},
    ] + procedural
    # The hand made story caves of the zone. The engine stamps them when the
    # dwarves dig towards them, so they come after the chapter templates. They
    # are kept apart from the chapter placements: first_level is the chapter,
    # the story content is the zone around it.
    story_placements = zone_placements(root, "Urwald")
    all_placements = placements + story_placements

    layer_only = {"urw_unq_hoehlenmalerei"}
    templates = {}
    for placement in all_placements:
        name = placement["template"]
        if name not in templates:
            templates[name] = read_template(root, name)

    database = BdbDatabase(root / "BlockDB2.BDB")
    normals = [list(vector) for vector in struct.iter_unpack(
        "<3f", (root / "sphere.dat").read_bytes())]

    mesh_cache = {}
    cells = []
    cell_materials = {}
    cell_attributes = {}
    layer2_words = {}
    objects = []
    used_detail = set()
    detail_tables = texture_tables(root)
    template_reports = {}

    for placement in all_placements:
        name = placement["template"]
        template = templates[name]
        offset_x = int(placement["x"])
        offset_y = int(placement["y"])
        is_story: bool = str(placement.get("role", "")) == "story"
        report = template_reports.setdefault(name, {
            "template": name, "placements": [], "pmp": "", "l2m": "",
            "width": 0, "height": 0, "cells": 0, "objects": 0,
        })
        report["placements"].append({"x": offset_x, "y": offset_y, "role": placement["role"]})

        # Campaign.tcl:14 comments out the MapTemplateSet call of
        # urw_unq_hoehlenmalerei, so it contributes only the material layer.
        if template["pmp"] and name not in layer_only:
            pmp_path = root / "Templates" / Path(template["pmp"]).name
            if not pmp_path.is_file():
                raise FileNotFoundError(pmp_path)
            width, height, flags, refs, attributes = read_pmp(pmp_path)
            grid_materials = materials(width, height, flags)
            report["pmp"] = template["pmp"]
            report["width"] = width
            report["height"] = height
            for row in range(height):
                for column in range(width):
                    index = row * width + column
                    corners = [flags[y * width + x] & 0x7F
                               for y, x in ((row, column), (row + 1, column),
                                            (row, column + 1), (row + 1, column + 1))
                               if y < height and x < width]
                    if not any(corners):
                        continue
                    block_id = refs[index]
                    if block_id not in mesh_cache:
                        parts = []
                        for part in database.get_block(block_id):
                            if not part["vertices"] or not part["indices"]:
                                continue
                            parts.append({
                                "part": part["part"],
                                "vertices": [round(float(value), 7) for point in part["vertices"]
                                             for value in point],
                                "indices": list(part["indices"]),
                                "attributes": list(part["attributes"]),
                            })
                        mesh_cache[block_id] = parts
                    map_x = offset_x + column
                    map_y = offset_y + row
                    cells.append({
                        "x": map_x, "y": map_y, "block": block_id,
                        "flags": flags[index], "cell_attribute": attributes[index],
                        "story": is_story,
                    })
                    cell_materials[f"{map_x},{map_y}"] = grid_materials[index]
                    cell_attributes[f"{map_x},{map_y}"] = attributes[index]
                    report["cells"] += 1

        if template["l2m"]:
            l2m_path = root / "Templates" / Path(template["l2m"]).name
            if not l2m_path.is_file():
                raise FileNotFoundError(l2m_path)
            width, height, words = read_layer2(l2m_path)
            report["l2m"] = template["l2m"]
            for row in range(height):
                for column in range(width):
                    word = words[row * width + column]
                    if not word:
                        continue
                    layer2_words[f"{offset_x + column},{offset_y + row}"] = word
                    used_detail.add(word)

        if name in layer_only:
            # Geometry is not placed for the layer-only prologue template;
            # its objects are still part of the chapter and were added above.
            pass

        for entry in template["objects"]:
            objects.append({
                "template": name,
                "template_x": offset_x,
                "template_y": offset_y,
                "class": entry["class"],
                "x": offset_x + entry["local_x"],
                "y": offset_y + entry["local_y"],
                "z": entry["z"],
                "rotation": entry["rotation"],
                "detail_tier": entry["detail_tier"],
                "source_line": entry["source_line"],
                "owner": entry.get("owner", -1),
                "physic": entry.get("physic", False),
                "autolight": entry.get("autolight", False),
                "boxed": entry.get("boxed", False),
                "story": is_story,
            })
            report["objects"] += 1

    # A template that is placed later overwrites the cells of an earlier one,
    # the way the engine applies MapTemplateSet. The story content of the zone
    # overlaps the procedural caves of the chapter.
    if len(cells) != len({(cell["x"], cell["y"]) for cell in cells}):
        latest = {}
        for index, cell in enumerate(cells):
            latest[(cell["x"], cell["y"])] = (index, cell)
        cells = [cell for _, cell in sorted(latest.values(), key=lambda item: item[0])]

    # Detail textures and the atlas.
    detail_dir = root / "Ground/detail"
    textures = {}
    for word in sorted(used_detail):
        for part in range(3):
            name = decode_detail(word, part, detail_tables)["texture"]
            if name in textures:
                continue
            source = detail_dir / name
            if not source.is_file():
                continue
            textures[name] = Image.open(source).convert("RGB")
    args.detail_textures.mkdir(parents=True, exist_ok=True)
    for name in textures:
        shutil.copy2(detail_dir / name, args.detail_textures / name)
    atlas = build_atlas(textures, args.atlas_output)

    decoded = {}
    for word in sorted(used_detail):
        decoded[str(word)] = [decode_detail(word, part, detail_tables) for part in range(3)]

    # Model manifest for export_demo_start_models.py.
    class_names = {item["class"] for item in objects}
    assets = index_class_assets(root, class_names)
    model_objects = []
    for item in objects:
        if item["class"] not in assets:
            continue
        model_objects.append({**item, **assets[item["class"]]})
    args.model_manifest_output.parent.mkdir(parents=True, exist_ok=True)
    args.model_manifest_output.write_text(json.dumps({
        "source_tcl": "Scripts/gameplay/Campaign.tcl",
        "map_template": "campaign first level (512x640)",
        "objects": model_objects,
    }, ensure_ascii=False, indent=1), encoding="utf-8")

    triangles = 0
    vertices = 0
    for parts in mesh_cache.values():
        for part in parts:
            triangles += len(part["indices"]) // 3
            vertices += len(part["vertices"]) // 5

    result = {
        "schema": "diggles.campaign_chapter.v1",
        "seed": args.seed,
        "map_size": {"width": MAP_WIDTH, "height": MAP_HEIGHT},
        "source": {
            "campaign": "Scripts/gameplay/Campaign.tcl",
            "procedure": "Campaign.tcl:22-191 first_level",
            "prologue": "Campaign.tcl:12-15",
            "epilogue": "Campaign.tcl:198-216",
            "chapter_call": "Campaign.tcl:195 first_level 208 0",
            "map_create": "Campaign.tcl:2 map create 512 640",
            "story_zone": "CampaignInit.tcl:675-692 sm_add_zone/sm_add_temp Urwald",
            "story_groups": "CampaignInit.tcl:110-188 sm_def_temp_group",
        },
        "rng": {
            "algorithm": "MT19937 variant recovered from Diggles.exe",
            "irandom": "0x61afc8 -> 0x62f780 -> 0x49c670, 31-bit mask then modulo",
            "seed_state": "0x4454d0 seeds 624 words from a 32-bit value",
            "limit": "The engine seeds irandom from a wall-clock value, so the seed of a "
                     "recorded chapter is unknown. A seed given here reproduces that seed's "
                     "placement sequence exactly.",
            "adapter": True,
        },
        "generator_state": state,
        "initial_view": {"x": 246.7, "y": 28.8, "zoom": 1.478, "rx": -0.29, "ry": 0.05},
        "fog_remover": {"class": "FogRemover", "position": [239, 14, 15],
                        "fog_remove": [0, 46, 22], "undeletable": True},
        "deleted_class": "Wuker",
        "placements": placements,
        "story_placements": story_placements,
        "templates": list(template_reports.values()),
        "cells": cells,
        "materials": cell_materials,
        "attributes": cell_attributes,
        "layer2": layer2_words,
        "layer2_decoded": decoded,
        "atlas": atlas,
        "objects": objects,
        "meshes": {str(key): value for key, value in mesh_cache.items()},
        "normals": normals,
        "summary": {
            "cells": len(cells),
            "unique_blocks": len(mesh_cache),
            "vertices": vertices,
            "triangles": triangles,
            "templates": len(template_reports),
            "placements": len(placements),
            "story_placements": len(story_placements),
            "objects": len(objects),
            "story_objects": sum(1 for item in objects if item.get("story")),
            "story_cells": sum(1 for cell in cells if cell.get("story")),
            "objects_with_model": len(model_objects),
            "classes": dict(Counter(item["class"] for item in objects).most_common(12)),
        },
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, ensure_ascii=False, separators=(",", ":")),
                           encoding="utf-8")
    print(json.dumps({"output": str(args.output), **result["summary"]}, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
