# -*- coding: utf-8 -*-
"""
Export male dwarf (mann.3db::mann) combat and invention clips for the
self-contained HTML viewer.

The clip roles come from the original game scripts
(Diggles\\data\\Scripts\\classes\\zwerg\\z_anims.tcl):

  // Kampf-Animationen / Fitnessstudio
  punch       -> mann.boxen            (11 frames)
  puncha      -> mann.schlagen_a       (11 frames)
  punchc      -> mann.schlagen_c       (13 frames)
  punchside   -> mann.schlagen_zur_seite(13 frames)
  // erfinden
  invent_a    -> mann.erfinden_a       (31 frames)
  invent_b    -> mann.erfinden_b       (31 frames)
  invent_c    -> mann.erfinden_c       (31 frames)
  invent_brains -> mann.erfinden_brains (31 frames)
  invent_done -> mann.erfinden_geschafft (28 frames)
  // kurbeln  (Feuerstelle: the dwarf turns the mechanism)
  windstart   -> mann.kurbeln_start    (3 frames)
  windloop    -> mann.kurbeln_loop     (8 frames)
  windend     -> mann.kurbeln_end      (4 frames)

erfinden_a / erfinden_brains are the "walking in a circle while inventing"
clips: the body centre of their frames traces a full circle of radius ~200
model units around the clip origin.

Output format matches godot/models/dwarf_surface_walk.json:
  clips -> name -> {animation_index, frame_count, frames[], adapter_fps}
  frame -> {mesh_index, bounds, surfaces[], frame_index}
  surface -> {material, texture, points, uvs, triangles, brightness, alpha_range}
"""
from __future__ import annotations

import hashlib
import json
import sys
from pathlib import Path
from PIL import Image

sys.path.insert(0, str(Path(__file__).resolve().parent))
from inspect_3db import parse

GAME = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data")
MODEL = GAME / "3db" / "mann.3db"
OBJECT = "mann"

# клип -> частота кадров на странице
CLIPS = {
    "boxen": 12.0,
    "schlagen_a": 12.0,
    "schlagen_c": 12.0,
    "schlagen_zur_seite": 12.0,
    "erfinden_a": 10.0,
    "erfinden_b": 10.0,
    "erfinden_c": 10.0,
    "erfinden_brains": 10.0,
    "erfinden_geschafft": 10.0,
    "kurbeln_start": 12.0,
    "kurbeln_loop": 12.0,
    "kurbeln_end": 12.0,
}

OUT = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models\dwarf_combat_invent.json")


def file_digest(path: Path) -> dict:
    data = path.read_bytes()
    return {"path": str(path), "bytes": len(data), "sha256": hashlib.sha256(data).hexdigest()}


def alpha_range(path: Path) -> list:
    with Image.open(path) as image:
        alpha = image.getchannel("A") if "A" in image.getbands() else None
        return list(alpha.getextrema()) if alpha else [255, 255]


def main() -> None:
    parsed = parse(MODEL)
    indices = parsed["objects"].get(OBJECT)
    if not indices:
        raise SystemExit("object not found: " + OBJECT)

    animations = {}
    for index in indices:
        animations.setdefault(parsed["animations"][index]["name"], index)

    # текстуры игры: ищем нужный файл по имени
    texture_files = {}
    for path in GAME.rglob("*.tga"):
        texture_files.setdefault(path.name.casefold(), []).append(path)

    alpha_by_texture = {}

    def export_mesh(mesh_index: int) -> dict:
        mesh = parsed["meshes"][mesh_index]
        surfaces = []
        for material_id, _unknown, triangle_id, uv_id, point_id, brightness_id in mesh["links"]:
            if (triangle_id >= len(parsed["triangles"]) or uv_id >= len(parsed["uvs"])
                    or point_id >= len(parsed["points"])):
                continue
            material = (parsed["materials"][material_id] if material_id < len(parsed["materials"])
                        else {"name": "unknown", "path": ""})
            texture = Path(material["path"].replace("\\", "/")).name
            key = texture.casefold()
            if key not in alpha_by_texture:
                candidates = texture_files.get(key, [])
                if not candidates:
                    raise SystemExit("texture not found: " + texture)
                alpha_by_texture[key] = alpha_range(max(candidates, key=lambda p: p.stat().st_size))
            surfaces.append({
                "material": material["name"],
                "texture": texture,
                "points": parsed["points"][point_id],
                "uvs": parsed["uvs"][uv_id],
                "triangles": parsed["triangles"][triangle_id],
                "brightness": parsed["brightness"][brightness_id] if brightness_id < len(parsed["brightness"]) else [],
                "alpha_range": alpha_by_texture[key],
            })
        return {"mesh_index": mesh_index, "bounds": mesh["bounds"], "surfaces": surfaces}

    clips = {}
    missing = []
    for name, fps in CLIPS.items():
        index = animations.get(name)
        if index is None:
            missing.append(name)
            continue
        animation = parsed["animations"][index]
        frames = []
        for frame_index, mesh_index in enumerate(animation["mesh_indices"]):
            frame = export_mesh(mesh_index)
            frame["frame_index"] = frame_index
            frames.append(frame)
        clips[name] = {
            "animation_index": index,
            "frame_count": len(frames),
            "frames": frames,
            "adapter_fps": fps,
        }

    result = {
        "schema": "diggles.combat_invent_clips.v1",
        "sources": [
            file_digest(MODEL),
            file_digest(GAME / "Scripts" / "classes" / "zwerg" / "z_anims.tcl"),
            file_digest(GAME / "Scripts" / "classes" / "zwerg" / "z_work_common.tcl"),
        ],
        "mesh_exporter": {"path": "tools/export_demo_start_models.py", "function": "main.export_mesh",
                          "line": 69, "end_line": 88},
        "clips": clips,
        "missing": missing,
        "limits": "Original male body frames of the combat and invention clips. Weapons are "
                  "separate models in the game and are not part of these body clips.",
    }
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text(json.dumps(result, separators=(",", ":"), ensure_ascii=False), encoding="utf-8")

    print(json.dumps({"output": str(OUT), "clips": len(clips), "missing": missing,
                      "textures": sorted({s["texture"] for c in clips.values()
                                          for f in c["frames"] for s in f["surfaces"]}),
                      "bytes": OUT.stat().st_size}, ensure_ascii=False, indent=1))


if __name__ == "__main__":
    main()
