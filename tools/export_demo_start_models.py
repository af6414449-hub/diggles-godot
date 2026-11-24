"""Export statically mapped demo_start 3DB meshes and original TGA textures."""
from __future__ import annotations

import hashlib
import json
import shutil
import struct
import sys
from pathlib import Path
from PIL import Image

sys.path.insert(0, str(Path(__file__).resolve().parent))
from inspect_3db import parse


PREFERRED_ANIMATION = {"Feuerstelle": "brennt"}
DWARF_LOCOMOTION_ANIMATIONS = (
    "gehen_start", "gehen_loop", "gehen_end",
    "laufen_schnell_start", "laufen_schnell_loop", "laufen_schnell_end",
    "drehen_links", "drehen_rechts", "drehen_ganz_links", "drehen_ganz",
    "stand_anim_a", "stand_anim_b",
)


def main() -> None:
    root = Path(sys.argv[1])
    manifest_path = Path(sys.argv[2])
    output = Path(sys.argv[3])
    texture_output = Path(sys.argv[4])
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    source_objects = list(manifest["objects"])
    supplement_path = Path(sys.argv[5]) if len(sys.argv) > 5 else None
    if supplement_path is not None:
        supplement = json.loads(supplement_path.read_text(encoding="utf-8"))
        source_objects.extend(supplement.get("objects", []))
    source_root = root / "3db"
    texture_root = root / "Texture"
    textures_by_name = {}
    for path in root.rglob("*.tga"):
        textures_by_name.setdefault(path.name.casefold(), []).append(path)

    packages = {}
    exported = {}
    missing = []
    used_materials = set()
    for entry in source_objects:
        package = entry.get("model_package")
        object_name = entry.get("model_object")
        if not package or not object_name:
            continue
        package_path = next((p for p in source_root.iterdir() if p.name.casefold() == package.casefold()), None)
        if package_path is None:
            missing.append({"package": package, "object": object_name, "reason": "package"})
            continue
        parsed = packages.setdefault(package.casefold(), parse(package_path))
        indices = parsed["objects"].get(object_name)
        if not indices:
            missing.append({"package": package, "object": object_name, "reason": "object"})
            continue
        key = package.casefold() + "::" + object_name.casefold()
        if key in exported:
            continue
        preferred = PREFERRED_ANIMATION.get(entry["class"], "standard")
        animation_index = next((i for i in indices if parsed["animations"][i]["name"] == preferred), indices[0])
        animation = parsed["animations"][animation_index]
        if not animation["mesh_indices"]:
            missing.append({"package": package, "object": object_name, "reason": "empty animation"})
            continue
        def export_mesh(mesh_index: int) -> dict:
            mesh = parsed["meshes"][mesh_index]
            surfaces = []
            for link in mesh["links"]:
                material_id, _, triangle_id, uv_id, point_id, brightness_id = link
                if (triangle_id >= len(parsed["triangles"]) or uv_id >= len(parsed["uvs"])
                        or point_id >= len(parsed["points"])):
                    missing.append({"package": package, "object": object_name, "reason": "array reference"})
                    continue
                material = parsed["materials"][material_id] if material_id < len(parsed["materials"]) else {"name": "unknown", "path": ""}
                used_materials.add((package.casefold(), material_id))
                surfaces.append({
                    "material": material["name"],
                    "texture": Path(material["path"].replace("\\", "/")).name,
                    "points": parsed["points"][point_id],
                    "uvs": parsed["uvs"][uv_id],
                    "triangles": parsed["triangles"][triangle_id],
                    "brightness": parsed["brightness"][brightness_id] if brightness_id < len(parsed["brightness"]) else [],
                })
            return {"mesh_index": mesh_index, "bounds": mesh["bounds"], "surfaces": surfaces}

        mesh_index = animation["mesh_indices"][0]
        static_mesh = export_mesh(mesh_index)
        exported[key] = {
            "package": package,
            "object": object_name,
            "mesh_index": mesh_index,
            "animation_index": animation_index,
            "animation": animation["name"],
            "bounds": static_mesh["bounds"],
            "surfaces": static_mesh["surfaces"],
        }
        if package.casefold() == "mann.3db" and object_name.casefold() == "mann":
            locomotion = {}
            for animation_name in DWARF_LOCOMOTION_ANIMATIONS:
                source_index = next((i for i in indices if parsed["animations"][i]["name"] == animation_name), None)
                if source_index is None:
                    missing.append({"package": package, "object": object_name,
                                    "reason": "animation", "animation": animation_name})
                    continue
                source_animation = parsed["animations"][source_index]
                locomotion[animation_name] = {
                    "animation_index": source_index,
                    "extra": source_animation["extra"],
                    "frames": [export_mesh(index) for index in source_animation["mesh_indices"]],
                }
            exported[key]["locomotion"] = locomotion

    texture_output.mkdir(parents=True, exist_ok=True)
    texture_records = []
    copied = {}
    alpha_by_name = {}
    for package_key, material_id in sorted(used_materials):
        parsed = packages[package_key]
        material = parsed["materials"][material_id]
        name = Path(material["path"].replace("\\", "/")).name
        candidates = textures_by_name.get(name.casefold(), [])
        if not candidates:
            texture_records.append({"name": name, "package": package_key, "material": material["name"], "found": False})
            continue
        def texture_rank(path: Path) -> tuple[int, int]:
            header = path.read_bytes()[:18]
            width, height = struct.unpack_from("<HH", header, 12)
            return (width * height, 1 if "m256" in {part.casefold() for part in path.parts} else 0)

        source = max(candidates, key=texture_rank)
        digest = hashlib.sha256(source.read_bytes()).hexdigest()
        target_name = name
        if target_name.casefold() in copied and copied[target_name.casefold()] != digest:
            target_name = f"{source.parent.name}_{name}"
        target = texture_output / target_name
        shutil.copy2(source, target)
        copied[target_name.casefold()] = digest
        with Image.open(source) as image:
            alpha = image.getchannel("A") if "A" in image.getbands() else None
            alpha_range = list(alpha.getextrema()) if alpha else [255, 255]
        alpha_by_name[name.casefold()] = alpha_range
        texture_records.append({"name": name, "file": target_name, "package": package_key, "material": material["name"], "found": True, "sha256": digest, "alpha_range": alpha_range, "source": str(source)})

    def add_alpha_ranges(surfaces: list[dict]) -> None:
        for surface in surfaces:
            surface["alpha_range"] = alpha_by_name.get(surface["texture"].casefold(), [255, 255])

    for model in exported.values():
        add_alpha_ranges(model["surfaces"])
        for sequence in model.get("locomotion", {}).values():
            for frame in sequence["frames"]:
                add_alpha_ranges(frame["surfaces"])

    result = {
        "source_template": manifest["source_tcl"],
        "map_template": manifest["map_template"],
        "coordinate_transform": "Tcl logical position (x,y,z) -> Godot logical (x,-y,z), then render Z=7+z/2. Native model displacements are render units: m=16384*(u16/65536-0.5), q=.005*m*R, R=Rz*Rx*Ry for row vectors. Double rotated world-Z displacement in logical space before common render packing. BDB raw Z is already packed.",
        "native_model_transform": {"point_divisor": 65536, "point_scale": 16384,
                                   "render_scale": 0.005, "normalized_point_scale": 81.92,
                                   "euler_row_order": "Rz(z) * Rx(x) * Ry(y)",
                                   "evidence": "EXE 0x487430,0x484c10,0x48cda0,0x47ec30",
                                   "instance_scale": 1.0},
        "objects": exported,
        "placements": [entry for entry in source_objects
                       if "model_package" in entry or entry["class"].startswith("Misc_LightSrc_")],
        "textures": texture_records,
        "missing": missing,
        "limits": "Static representative meshes plus original dwarf idle, walk, run and turn frames; randomized variants, per-class scale and branch-specific renderer offsets are not evaluated.",
    }
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(result, separators=(",", ":"), ensure_ascii=False), encoding="utf-8")
    print(json.dumps({"output": str(output), "unique_models": len(exported), "placements": len(result["placements"]),
                      "textures_used": len(used_materials), "textures_copied": sum(x["found"] for x in texture_records),
                      "missing": missing}, ensure_ascii=False))


if __name__ == "__main__":
    main()
