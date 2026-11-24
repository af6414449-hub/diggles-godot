#!/usr/bin/env python3
"""Extract the Urwald templates that Campaign.tcl:first_level can select.

Reads the original game data read-only and writes one JSON manifest holding,
per template: the geometry reference (PMP grid), the material layer (L2M),
the declared objects (class, local position, rotation, per-object flags and
Editor_Set_Info attributes) and the split-template part list.

The parser is an index of Tcl declarations, not a Tcl interpreter: only the
literal forms used by the Urwald templates are evaluated.

Usage:
    python extract_campaign_templates.py --data <game>/data --output <json>
"""
from __future__ import annotations

import argparse
import base64
import hashlib
import json
import re
import struct
from pathlib import Path

# --- Campaign.tcl:first_level tables (Campaign.tcl lines 24-100) ---------------

CAVE_LIST = [
    ("urw_hol_001_a", 20, 4),
    ("urw_hol_014_b", 20, 12),
    ("urw_hol_018_c", 28, 16),
    ("urw_hol_019_b", 24, 16),
    ("urw_hol_027_a", 16, 4),
]

COMB_LIST = [
    (0, 1, [0]), (0, 2, [0]), (0, 4, [0]), (1, 0, [4]),
    (1, 3, [4]), (4, 0, [0]), (4, 2, [0]), (4, 3, [0]),
]

TUNN_LIST = [
    ("urw_gng_013_", 4, 0),
    ("urw_gng_002_", 8, 0),
    ("urw_gng_003_", 12, 0),
]

CON_LIST = [
    [0, 0, 1, 2], [0, 0, 2, 1], [0, 1, 0, 2],
    [4, 2, 0, 1], [4, 2, 1, 0], [4, 1, 2, 0],
]

VODO_LIST = [
    ("urw_gng_001_", "ab"), ("urw_gng_007_", "abcd"), ("urw_gng_008_", "abc"),
    ("urw_gng_009_", "abcd"), ("urw_gng_012_", "abcd"), ("urw_gng_019_", "abc"),
    ("urw_gng_022_", "abdeg"), ("urw_gng_023_", "abc"), ("urw_gng_026_", "abc"),
    ("urw_gng_028_", "bcd"), ("urw_gng_030_", "a"), ("urw_gng_032_", "ab"),
    ("urw_gng_034_", "acdfhk"), ("urw_gng_039_", "ab"), ("urw_gng_042_", "ab"),
    ("urw_gng_045_", "ab"), ("urw_unq_vodo_001_", "a"), ("urw_gng_004_", "ab"),
    ("urw_gng_027_", "abc"), ("urw_gng_036_", "ab"), ("urw_gng_043_", "ab"),
    ("urw_gng_044_", "ab"),
]

VOCON_LIST_1 = [
    [(3, 20, 0), (8, 8, 12), (5, 20, 12), (6, 24, 12), (16, -24, 12)],
    [(1, 20, 0), (13, 4, 16), (7, 4, 28), (9, 12, 4), (16, -28, 12)],
    [(2, 20, 0), (5, 20, 8), (6, 24, 8), (15, 8, 8), (12, 4, 16), (6, 16, 24), (16, -28, 12)],
    [(2, 20, 0), (14, 12, 8), (4, 8, 12), (13, 0, 16), (7, 0, 28), (16, -32, 12)],
    [(2, 20, 0), (11, 0, 16), (15, 8, 8), (5, 20, 8), (6, 24, 8), (7, 8, 28), (16, -32, 12)],
    [(1, 20, 0), (6, 16, 20), (4, 8, 8), (14, 12, 4), (10, 4, 12), (16, -28, 12)],
]

VOCON_LIST_2 = [
    [(18, 20, 0), (0, 20, 20), (10, 24, 12), (6, 36, 20), (16, -12, 12)],
    [(20, 20, 0), (21, 32, 4), (17, 20, 20), (10, 36, 12), (6, 48, 20), (16, -12, 12)],
    [(19, 20, 0), (1, 24, 12), (14, 16, 16), (6, 32, 8), (16, -16, 12)],
]

# Campaign.tcl lines 101-103: letter pools per present_side.
LEFT_LETTERS = ("abdef", "cgih")
RIGHT_LETTERS = ("cfkh", "abdeg")

# --- Template source parsing -------------------------------------------------

NEW = re.compile(r'\[new\s+([^\s\]]+)\s+"([^"]*)"\s+"(.*?)"\s+"(.*?)"\s*\]', re.DOTALL)
EXPR = re.compile(r'\[expr\s*(?:\{([^}]*)\}|([^\]]*))\]')
NUMBER = re.compile(r'[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?')
MAP_TEMPLATE = re.compile(r'^\s*map_template\s+(\S+)\s+(\S+)\s+(\S+)\s*$')
MAP_SETLAYER2 = re.compile(r'^\s*map_setlayer2\s+(\S+)\s+(\S+)\s+(\S+)\s*$')
SPLIT_TEMPLATE = re.compile(
    r'^\s*split_template\s+(\S+)\s+(\S+)\s+(-?\d+)\s+(-?\d+)\s*\{(.*)\}\s*$', re.DOTALL)
SPLIT_PART = re.compile(r'\{\s*([A-Za-z0-9_]+\.tcl)\s+(\S+\.pmp)\s+(-?\d+)\s+(-?\d+)\s*\}')
CALL_OTHER = re.compile(r'^\s*call\s+(\S+)\s*$')
SET_FLAG = re.compile(r'^\s*set_(owner|physic|autolight|boxed)\s+\$objhandle\s+(.+?)\s*$')
EDITOR_INFO = re.compile(r'^\s*call_method\s+\$objhandle\s+Editor_Set_Info\s+\{(.*)\}\s*$')
LOADING_TIER = re.compile(r'^\s*loading_objdetail\s+(high|medium|low|off)\s*$')


def coordinate_values(value: str) -> list[float] | None:
    """Read three literal coordinates, keeping offset-relative constants."""
    result: list[float] = []
    position = 0
    for match in EXPR.finditer(value):
        between = value[position:match.start()]
        result.extend(float(v) for v in NUMBER.findall(between))
        expr = match.group(1) if match.group(1) is not None else match.group(2)
        nums = NUMBER.findall(expr)
        if not nums:
            return None
        # The last literal of an offset expression is the template-local term.
        result.append(float(nums[-1]))
        position = match.end()
    result.extend(float(v) for v in NUMBER.findall(value[position:]))
    return result[:3] if len(result) >= 3 else None


def read_pmp(path: Path) -> dict:
    """Parse a PMP into width/height, corner flags, block ids and cell attributes."""
    data = path.read_bytes()
    if len(data) < 12:
        raise ValueError(f"PMP header truncated: {path}")
    width, height = struct.unpack_from("<II", data)
    cells = width * height
    tail = 8 + 5 * cells
    if width < 1 or height < 1 or tail + 4 > len(data):
        raise ValueError(f"Invalid PMP dimensions: {path}")
    tail_count = struct.unpack_from("<I", data, tail)[0]
    if tail + 4 + 2 * tail_count + cells != len(data):
        raise ValueError(f"PMP layout does not match the observed loader: {path}")
    trailing = tail + 4 + 2 * tail_count
    return {
        "file": path.name,
        "width": width,
        "height": height,
        "flags": data[8:8 + cells],
        "blocks": struct.unpack_from(f"<{cells}I", data, 8 + cells),
        "attributes": data[trailing:trailing + cells],
        "sha256": hashlib.sha256(data).hexdigest(),
    }


def read_l2m(path: Path) -> dict | None:
    """Parse an L2M material layer into width/height and 16-bit words.

    Some shipped variants reference a zero-byte L2M file; the engine then has no
    material layer for that template. Those are reported as absent.
    """
    data = path.read_bytes()
    if len(data) == 0:
        return None
    if not data.startswith(b"M2L\0") or len(data) < 12:
        raise ValueError(f"Not an L2M file: {path}")
    width, height = struct.unpack_from("<II", data, 4)
    count = width * height
    if 12 + count * 2 > len(data):
        raise ValueError(f"L2M payload is truncated: {path}")
    words = struct.unpack_from(f"<{count}H", data, 12) if count else ()
    return {
        "file": path.name,
        "width": width,
        "height": height,
        "words": words,
        "sha256": hashlib.sha256(data).hexdigest(),
    }


def resolve_asset(root: Path, name: str) -> Path:
    """Resolve a template asset reference such as ``data/templates/x.pmp``."""
    candidate = Path(name.replace("\\", "/")).name
    for base in (root, root / "split", root.parent / "Templates"):
        path = base / candidate
        if path.is_file():
            return path
    return root / candidate


def parse_template(tcl_root: Path, pmp_root: Path, l2m_root: Path, name: str) -> dict:
    """Parse one template .tcl into its structured description."""
    path = tcl_root / f"{name}.tcl"
    if not path.is_file():
        raise FileNotFoundError(path)
    text = path.read_text(encoding="cp1252", errors="replace")
    result: dict = {
        "name": name,
        "source": f"data/Templates/{name}.tcl",
        "kind": "direct",
        "pmp": None,
        "l2m": None,
        "parts": [],
        "objects": [],
        "calls": [],
    }
    current: dict | None = None
    tier = "default"
    lines = text.splitlines()
    line_index = 0
    while line_index < len(lines):
        line = lines[line_index]
        line_index += 1
        tier_match = LOADING_TIER.match(line)
        if tier_match:
            tier = tier_match.group(1)
            continue
        if line.strip().startswith("split_template"):
            # The split block spans several lines; collect it until the braces balance.
            block = line
            while block.count("{") > block.count("}") and line_index < len(lines):
                block += "\n" + lines[line_index]
                line_index += 1
            split_match = SPLIT_TEMPLATE.match(block.strip())
            if split_match:
                result["kind"] = "split"
                result["split_name"] = split_match.group(1)
                result["split_pmp"] = split_match.group(2)
                result["split_size"] = [int(split_match.group(3)), int(split_match.group(4))]
                for part in SPLIT_PART.finditer(split_match.group(5)):
                    result["parts"].append({
                        "tcl": part.group(1),
                        "pmp": part.group(2),
                        "x": int(part.group(3)),
                        "y": int(part.group(4)),
                    })
            continue
        map_match = MAP_TEMPLATE.match(line)
        if map_match:
            pmp_name = map_match.group(1)
            result["pmp"] = read_pmp(resolve_asset(pmp_root, pmp_name))
            continue
        layer_match = MAP_SETLAYER2.match(line)
        if layer_match:
            l2m_name = layer_match.group(3)
            result["l2m"] = read_l2m(resolve_asset(l2m_root, l2m_name))
            continue
        call_match = CALL_OTHER.match(line)
        if call_match:
            result["calls"].append(call_match.group(1))
            continue
        for new_match in NEW.finditer(line):
            class_name, _, position, rotation = new_match.groups()
            coords = coordinate_values(position)
            if coords is None:
                continue
            current = {
                "class": class_name,
                "x": coords[0],
                "y": coords[1],
                "z": coords[2],
                "rotation": rotation.split(),
                "detail_tier": tier,
                "flags": {"owner": None, "physic": None, "autolight": None, "boxed": None},
                "info": {},
            }
            result["objects"].append(current)
            continue
        flag_match = SET_FLAG.match(line)
        if flag_match and current is not None:
            name_, value = flag_match.group(1), flag_match.group(2)
            if value == "true":
                current["flags"][name_] = True
            elif value == "false":
                current["flags"][name_] = False
            else:
                try:
                    current["flags"][name_] = int(value)
                except ValueError:
                    current["flags"][name_] = value
            continue
        info_match = EDITOR_INFO.match(line)
        if info_match and current is not None:
            for pair in re.finditer(r'([A-Za-z0-9_]+)\s+(\S+)', info_match.group(1)):
                current["info"][pair.group(1)] = pair.group(2)
    return result


def pack_template(template: dict) -> dict:
    """Compact a parsed template into the manifest representation."""
    packed = {
        "name": template["name"],
        "source": template["source"],
        "kind": template["kind"],
        "objects": template["objects"],
    }
    if template["pmp"] is not None:
        pmp = template["pmp"]
        packed["pmp"] = {
            "file": pmp["file"],
            "width": pmp["width"],
            "height": pmp["height"],
            "sha256": pmp["sha256"],
            "flags_b64": base64.b64encode(pmp["flags"]).decode("ascii"),
            "blocks_b64": base64.b64encode(struct.pack(f"<{len(pmp['blocks'])}I", *pmp["blocks"])).decode("ascii"),
            "attributes_b64": base64.b64encode(pmp["attributes"]).decode("ascii"),
        }
    if template["l2m"] is not None:
        l2m = template["l2m"]
        packed["l2m"] = {
            "file": l2m["file"],
            "width": l2m["width"],
            "height": l2m["height"],
            "sha256": l2m["sha256"],
            # Native L2M words are 16 bit; they are widened to 32 bit so the
            # runtime can decode the layer with one to_int32_array() call.
            "words_b64": base64.b64encode(struct.pack(f"<{len(l2m['words'])}I", *l2m["words"])).decode("ascii"),
        }
    if template["kind"] == "split":
        packed["split_name"] = template.get("split_name")
        packed["split_pmp"] = template.get("split_pmp")
        packed["split_size"] = template.get("split_size")
        packed["parts"] = template["parts"]
    if template["calls"]:
        packed["calls"] = template["calls"]
    return packed


def required_templates() -> list[str]:
    names: list[str] = []
    names.extend(name for name, _x, _y in CAVE_LIST)
    for prefix, _x, _y in TUNN_LIST:
        names.extend(prefix + letter for letter in "abc")
    for prefix, letters in VODO_LIST:
        names.extend(prefix + letter for letter in letters)
    for letters in LEFT_LETTERS:
        names.extend("urw_gng_021_" + letter for letter in letters)
    for letters in RIGHT_LETTERS:
        names.extend("urw_gng_022_" + letter for letter in letters)
    names.append("urw_unq_start")
    names.append("urw_unq_hoehlenmalerei")
    seen: set[str] = set()
    ordered: list[str] = []
    for name in names:
        if name not in seen:
            seen.add(name)
            ordered.append(name)
    return ordered


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--data", type=Path, required=True, help="Game data directory")
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    tcl_root = args.data / "Templates"
    pmp_root = args.data / "Templates"
    l2m_root = args.data / "Templates"

    templates: dict[str, dict] = {}
    missing: list[str] = []
    for name in required_templates():
        try:
            templates[name] = pack_template(parse_template(tcl_root, pmp_root, l2m_root, name))
        except FileNotFoundError:
            missing.append(name)
    # Split templates reference further .tcl parts; include them so the
    # composer can resolve every part of the start template.
    extra: dict[str, dict] = {}
    for name, template in list(templates.items()):
        if template["kind"] != "split":
            continue
        for part in template["parts"]:
            stem = part["tcl"][:-4]
            if stem in templates or stem in extra:
                continue
            try:
                extra[stem] = pack_template(parse_template(tcl_root, pmp_root, l2m_root, stem))
            except (FileNotFoundError, ValueError):
                missing.append(stem)
    templates.update(extra)

    manifest = {
        "schema": "diggles.campaign_urwald_first_level.v1",
        "campaign_source": "data/Scripts/gameplay/Campaign.tcl:first_level (lines 22-191)",
        "world": "Urwald",
        "map_size": {"width": 512, "height": 640},
        "start_template": {"name": "urw_unq_start", "x": 208, "y": 0},
        "cave_painting_template": {
            "name": "urw_unq_hoehlenmalerei",
            "x": 30,
            "y": 23,
            "note": "Campaign.tcl:13-15 places the material layer only; no map_template geometry.",
        },
        "post_processing": {
            "remove_class": "Wuker",
            "fog_remover": {"position": [239, 14, 15], "fog_remove": [0, 46, 22], "undeletable": True},
            "source": "Campaign.tcl:198-212",
        },
        "tables": {
            "cave_list": [{"name": n, "x": x, "y": y} for n, x, y in CAVE_LIST],
            "comb_list": [{"left": a, "right": b, "y_offsets": c} for a, b, c in COMB_LIST],
            "tunn_list": [{"name": n, "x": x, "y": y} for n, x, y in TUNN_LIST],
            "con_list": CON_LIST,
            "vodo_list": [{"name": n, "letters": l} for n, l in VODO_LIST],
            "vocon_list_1": VOCON_LIST_1,
            "vocon_list_2": VOCON_LIST_2,
            "left_letters": list(LEFT_LETTERS),
            "right_letters": list(RIGHT_LETTERS),
        },
        "templates": templates,
        "missing_templates": missing,
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(manifest, indent=1, ensure_ascii=False) + "\n", encoding="utf-8", newline="\n")
    total_objects = sum(len(t["objects"]) for t in templates.values())
    print(f"templates={len(templates)} objects={total_objects} missing={len(missing)}")
    if missing:
        print("missing:", ", ".join(missing))


if __name__ == "__main__":
    main()
