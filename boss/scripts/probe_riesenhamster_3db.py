"""Probe the original riesenhamster.3db package.

Read-only probe for the next queued block: it proves the boss geometry is
present in the original install and reports the exact clip/frame contract the
exporter has to reproduce (no frame data is written).

Source (read only):
  original install  data/3db/riesenhamster.3db
"""
from __future__ import annotations

import hashlib
import json
from pathlib import Path

from inspect_3db import parse

DATA = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data")
PACKAGE = "riesenhamster.3db"
OBJECT = "riesenhamster"


def main() -> None:
    path = DATA / "3db" / PACKAGE
    parsed = parse(path)
    animations = parsed["animations"]
    textures: dict[str, int] = {}
    materials: dict[str, str] = {}
    for animation in animations:
        for mesh_index in animation["mesh_indices"]:
            mesh = parsed["meshes"][mesh_index]
            for link in mesh["links"]:
                material_id, _, _, _, _, _ = link
                material = parsed["materials"][material_id]
                name = Path(str(material["path"]).replace("\\", "/")).name
                textures[name] = textures.get(name, 0) + 1
                materials[name] = material["path"]
    report = {
        "package": PACKAGE,
        "bytes": path.stat().st_size,
        "sha256": hashlib.sha256(path.read_bytes()).hexdigest(),
        "decoded_fully": parsed["consumed_bytes"] == parsed["file_bytes"],
        "meshes": len(parsed["meshes"]),
        "points": len(parsed["points"]),
        "triangles": len(parsed["triangles"]),
        "clips": len(animations),
        "frames": sum(len(a["mesh_indices"]) for a in animations),
        "clip_frames": {a["name"]: len(a["mesh_indices"]) for a in animations},
        "textures": textures,
        "material_paths": materials,
    }
    print(json.dumps(report, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
