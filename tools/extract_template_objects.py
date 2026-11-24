"""Extract static `new` placements from templates referenced by a save.

This is an index of Tcl declarations, not a Tcl interpreter: dynamic commands,
conditions, substitutions, and engine-created entities are intentionally not
evaluated.
"""
import argparse
import json
import re
import sys
from pathlib import Path


NEW = re.compile(r'\[new\s+([^\s\]]+)\s+"[^"]*"\s+"(.*?)"\s+"(.*?)"\s*\]', re.DOTALL)
SPLIT = re.compile(r'\{\s*([A-Za-z0-9_]+\.tcl)\s+\S+\.pmp\s+(-?\d+)\s+(-?\d+)\s*\}')
EXPR = re.compile(r'\[expr\s*(?:\{([^}]*)\}|([^\]]*))\]')
NUMBER = re.compile(r'[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?')
REPRESENTATIVE_ASSETS = {
    "Alienpflanze": ("flusslandschaft", "alienpflanze"),
    "Dummy_Gras_03": ("flusslandschaft", "gras_03_a"),
    "Dummy_Gras_04": ("flusslandschaft", "gras_04_a"),
    "Dummy_Gras_05": ("flusslandschaft", "gras_05_a"),
    "Dummy_Urw_sumpf": ("hinterlegung", "urw_sumpf"),
    "Eisen": ("rohstoffe", "eisen"),
    "Feuerstelle": ("produktionsstaetten", "feuerstelle"),
    "Grillhamster": ("nahrung", "grillhamster"),
    "Grillpilz": ("nahrung", "grillpilz"),
    "Hamster": ("hamster", "hamster"),
    "Kleiner_Heiltrank": ("nahrung", "heiltrank_klein"),
    "Leiter": ("transport", "leiter"),
    "Misc_Light": ("licht", "fackel"),
    "Pilz": ("produktionsstaetten", "pilz"),
    "Raupe": ("rohstoffe", "raupe01"),
    "Schatzbuch": ("halbzeuge", "buch_blau"),
    "Schatztonne": ("trollhausen", "tonne"),
    "Schwefelwuker": ("wuker", "wuker"),
    "Stein": ("rohstoffe", "stein_01"),
    "Steinbrocken": ("rohstoffe", "stein_00"),
    "Troll": ("troll", "troll"),
    "Wuker": ("wuker", "wuker"),
    "Zelt": ("produktionsstaetten", "zelt_a"),
    "Zwerg": ("mann", "mann"),
}


def coordinate_values(value):
    """Read three literal coordinates, retaining offset-relative constants."""
    result = []
    position = 0
    for match in EXPR.finditer(value):
        between = value[position:match.start()]
        result.extend(NUMBER.findall(between))
        expr = match.group(1) if match.group(1) is not None else match.group(2)
        nums = NUMBER.findall(expr)
        result.append(nums[-1] if "$xoffset" in expr or "$yoffset" in expr else (nums[0] if nums else None))
        position = match.end()
    result.extend(NUMBER.findall(value[position:]))
    return [float(v) for v in result[:3] if v is not None] if len(result) >= 3 else None


def expand(root: Path, template: str, dx=0.0, dy=0.0, stack=()):
    if template in stack:
        return
    path = root / template
    if not path.is_file():
        return
    text = path.read_text(encoding="cp1252", errors="replace")
    yield path, text, dx, dy
    for match in SPLIT.finditer(text):
        child, child_x, child_y = match.groups()
        yield from expand(root, child, dx + float(child_x), dy + float(child_y), stack + (template,))


def index_class_assets(data_root: Path, class_names):
    """Map generated Dummy_* classes to 3DB package and animation names."""
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    from inspect_3db import parse as parse_3db

    scripts = data_root / "Scripts/classes"
    result = {}
    package_cache = {}
    pair = re.compile(r'\{\s*([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s*\}')
    default_anim = re.compile(r'\bclass_defaultanim\s+([A-Za-z0-9_]+)')
    for path in scripts.rglob("*.tcl"):
        stem = path.stem.lower()
        package = stem.removeprefix("dummy_") if stem.startswith("dummy_") else None
        if not package or not (data_root / "3db" / f"{package}.3db").is_file():
            continue
        text = path.read_text(encoding="cp1252", errors="replace")
        package_path = data_root / "3db" / f"{package}.3db"
        if package not in package_cache:
            package_cache[package] = parse_3db(package_path)
        model_objects = {key.casefold() for key in package_cache[package]["objects"]}
        for name, animation in pair.findall(text):
            candidate = f"Dummy_{name}"
            if candidate in class_names and animation.casefold() in model_objects:
                result.setdefault(candidate, {"model_object": animation, "model_package": f"{package}.3db", "mapping_source": path.name})
        for match in re.finditer(r'def_class\s+(Dummy_[A-Za-z0-9_]+)(?:(?!\bdef_class\b)[\s\S]){0,1200}', text):
            block = match.group(0)
            animation = default_anim.search(block)
            class_name = match.group(1)
            if class_name in class_names and animation and animation.group(1).casefold() in model_objects:
                result.setdefault(class_name, {"model_object": animation.group(1), "model_package": f"{package}.3db", "mapping_source": path.name})
    for class_name, (package, model_object) in REPRESENTATIVE_ASSETS.items():
        if class_name not in class_names or class_name in result:
            continue
        if package not in package_cache:
            package_path = data_root / "3db" / f"{package}.3db"
            if package_path.is_file():
                package_cache[package] = parse_3db(package_path)
        if package in package_cache and model_object in package_cache[package]["objects"]:
            result[class_name] = {
                "model_object": model_object,
                "model_package": f"{package}.3db",
                "mapping_source": "verified static representative; randomized/runtime variant may differ",
            }
    return result


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("manifest", type=Path)
    parser.add_argument("game_data", type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    result = json.loads(args.manifest.read_text(encoding="utf-8"))
    template_root = args.game_data / "Templates/tcl"
    objects = []
    missing = []
    declarations_seen = 0
    coordinate_parse_failures = 0
    for placement_index, placement in enumerate(result.get("saved_runtime_placements", [])):
        root_name = placement["template"] + ".tcl"
        root_path = template_root / root_name
        if not root_path.is_file():
            missing.append(root_name)
            continue
        for path, text, split_x, split_y in expand(template_root, root_name):
            tier = "default"
            for line_number, line in enumerate(text.splitlines(), 1):
                load_tier = re.search(r'\bloading_objdetail\s+(high|medium|low|off)\b', line)
                if load_tier:
                    tier = load_tier.group(1)
                for match in NEW.finditer(line):
                    declarations_seen += 1
                    class_name, position, rotation = match.groups()
                    coords = coordinate_values(position)
                    if coords is None:
                        coordinate_parse_failures += 1
                        continue
                    x, y, z = coords
                    objects.append({
                        "template_placement_index": placement_index,
                        "template": placement["template"],
                        "source_template": path.stem,
                        "source_line": line_number,
                        "class": class_name,
                        "x": placement["x"] + split_x + x,
                        "y": placement["y"] + split_y + y,
                        "z": z,
                        "detail_tier": tier,
                        "rotation": rotation,
                    })
    result["saved_template_objects"] = objects
    class_names = {item["class"] for item in objects}
    assets = index_class_assets(args.game_data, class_names)
    for item in objects:
        if item["class"] in assets:
            item.update(assets[item["class"]])
    result["template_object_extraction"] = {
        "static_new_declarations": len(objects),
        "new_commands_seen": declarations_seen,
        "coordinate_parse_failures": coordinate_parse_failures,
        "classes_mapped_to_3db": len(assets),
        "unique_classes": len(class_names),
        "missing_root_templates": missing,
        "limitations": "Static literal coordinates only; no Tcl evaluation, conditional execution, or runtime-generated objects.",
    }
    output = args.output or args.manifest
    output.write_text(json.dumps(result, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    print(f"Extracted {len(objects)} static object declarations to {output}")


if __name__ == "__main__":
    main()
