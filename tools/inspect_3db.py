"""Inspect native Diggles 3DDB model packages and export a selected static frame as OBJ.

The reader is a small independent implementation of the observed little-endian
3DDB layout. Animation frame sequences are exported one mesh index at a time.
"""
from __future__ import annotations

import argparse
import json
import shutil
import struct
from pathlib import Path


# Mesh bounds in the 3DB header use this coordinate scale. World placement
# applies further transforms that are not part of this file format.
NATIVE_POINT_SCALE = 16384.0


class Reader:
    def __init__(self, data: bytes):
        self.data = data
        self.offset = 0

    def read(self, fmt: str):
        value = struct.unpack_from("<" + fmt, self.data, self.offset)
        self.offset += struct.calcsize("<" + fmt)
        return value[0] if len(value) == 1 else value

    def string(self):
        length = self.read("I")
        value = self.data[self.offset:self.offset + length]
        if len(value) != length:
            raise ValueError(f"truncated string at {self.offset - 4}")
        self.offset += length
        return value.decode("cp1252", errors="replace")

    def skip(self, size: int):
        if size < 0 or self.offset + size > len(self.data):
            raise ValueError(f"invalid skip {size} at {self.offset}")
        self.offset += size


def parse(path: Path):
    r = Reader(path.read_bytes())
    version, name = r.string(), r.string()
    materials = []
    for _ in range(r.read("H")):
        materials.append({"name": r.string(), "path": r.string(), "unknown": r.read("I")})

    meshes = []
    for _ in range(r.read("I")):
        mesh_file_offset = r.offset
        links = [tuple(r.read("H") for _ in range(6)) for _ in range(r.read("H"))]
        bounds = (*r.read("3f"), *r.read("3f"))
        attachment_file_offset = r.offset
        # C3DDB mesh reader 0x4027C6: raw 0x80 bytes -> mesh+0x5C.
        # get_linkpos/get_linkrot and renderer index these as 32 uint32s.
        attachment_indices = r.read("32I")
        # Preserve the rest of the former skip without assigning semantics.
        auxiliary_u16_a = r.read("H")
        auxiliary_vecs = r.read("12f")
        auxiliary_u16_b = r.read("H")
        meshes.append({"links": links, "bounds": bounds,
                       "file_offset": mesh_file_offset,
                       "attachment_file_offset": attachment_file_offset,
                       "attachment_indices": attachment_indices,
                       "auxiliary_u16_a": auxiliary_u16_a,
                       "auxiliary_vecs": auxiliary_vecs,
                       "auxiliary_u16_b": auxiliary_u16_b})

    objects = {}
    for _ in range(r.read("H")):
        key = r.string()
        objects[key] = [r.read("I") for _ in range(r.read("H"))]

    animations = []
    for _ in range(r.read("H")):
        animation_name = r.string()
        frame_indices = [r.read("I") for _ in range(r.read("H"))]
        extra = {"u16": r.read("H"), "f32": r.read("f"), "string": r.string(), "vec_a": r.read("3f"), "vec_b": r.read("3f")}
        animations.append({"name": animation_name, "mesh_indices": frame_indices, "extra": extra})

    for _ in range(r.read("H")):
        r.skip(32 * 32)
    for _ in range(r.read("H")):
        width, height = r.read("H"), r.read("H")
        r.skip(4 + width * height)

    triangle_count, uv_count, point_count, brightness_count = r.read("H"), r.read("H"), r.read("H"), r.read("H")
    unknown_count = r.read("I")
    triangle_sizes = [r.read("H") for _ in range(triangle_count)]
    uv_sizes = [r.read("H") for _ in range(uv_count)]
    point_sizes = [r.read("H") for _ in range(point_count)]
    brightness_sizes = [r.read("H") for _ in range(brightness_count)]
    # C3DDB loader 0x40464B..0x404674 maps count*20 bytes into DB+0xA8.
    # 0x408A10 decodes position; 0x6873B7 reads rotation at +8,+12,+16.
    attachment_records_offset = r.offset
    attachment_records = []
    for _ in range(unknown_count):
        record_offset = r.offset
        position_u16 = r.read("3H")
        padding_u16 = r.read("H")
        rotation = r.read("3f")
        attachment_records.append({
            "file_offset": record_offset, "position_u16": position_u16,
            "padding_u16": padding_u16,
            "position_native": tuple((v - 32768) / 4.0 for v in position_u16),
            "rotation_radians": rotation,
        })
    triangles = [[r.read("H") for _ in range(size)] for size in triangle_sizes]
    uvs = [[r.read("2f") for _ in range(size)] for size in uv_sizes]
    # Native decoder: (u16 - 32768) / 4, equivalently
    # 16384 * (u16 / 65536 - 0.5). The endpoint is not 65535-normalized.
    points = [[tuple(value / 65536.0 for value in r.read("3H")) for _ in range(size)] for size in point_sizes]
    brightness = [[r.read("B") for _ in range(size)] for size in brightness_sizes]
    return {
        "version": version,
        "name": name,
        "materials": materials,
        "meshes": meshes,
        "objects": objects,
        "animations": animations,
        "triangles": triangles,
        "uvs": uvs,
        "points": points,
        "brightness": brightness,
        "attachment_records_offset": attachment_records_offset,
        "attachment_records": attachment_records,
        "consumed_bytes": r.offset,
        "file_bytes": len(r.data),
    }


def export_obj(model, object_name: str, frame_number: int, output: Path, texture_root: Path | None):
    object_indices = model["objects"].get(object_name)
    if object_indices is None:
        raise ValueError(f"object not found: {object_name}")
    animation_index = object_indices[0]
    animation = model["animations"][animation_index]
    frame_indices = animation["mesh_indices"]
    if frame_number < 0 or frame_number >= len(frame_indices):
        raise ValueError(f"frame {frame_number} outside 0..{len(frame_indices) - 1}")
    mesh_index = frame_indices[frame_number]
    mesh = model["meshes"][mesh_index]
    output.parent.mkdir(parents=True, exist_ok=True)
    mtl_path = output.with_suffix(".mtl")
    lines = [f"mtllib {mtl_path.name}"]
    mtl = []
    copied = {}
    vertex_base = 1
    uv_base = 1
    for link_index, link in enumerate(mesh["links"]):
        material_id, _unknown, tri_id, uv_id, point_id, _brightness_id = link
        if point_id >= len(model["points"]) or uv_id >= len(model["uvs"]) or tri_id >= len(model["triangles"]):
            continue
        pts, texcoords, indices = model["points"][point_id], model["uvs"][uv_id], model["triangles"][tri_id]
        material = model["materials"][material_id] if material_id < len(model["materials"]) else {"name": f"material_{material_id}", "path": ""}
        safe_name = material["name"].replace(" ", "_") or f"material_{material_id}"
        lines.append(f"usemtl {safe_name}")
        for x, y, z in pts:
            # 16-bit points are centered on 0.5; 16384 maps them to the
            # float bounds stored alongside the mesh.
            lines.append(f"v {(x - 0.5) * NATIVE_POINT_SCALE:.7f} {(y - 0.5) * NATIVE_POINT_SCALE:.7f} {(z - 0.5) * NATIVE_POINT_SCALE:.7f}")
        for u, v in texcoords:
            lines.append(f"vt {u:.7f} {1.0-v:.7f}")
        if len(indices) % 3 == 0:
            for i in range(0, len(indices), 3):
                face = []
                for index in indices[i:i + 3]:
                    vi, ti = vertex_base + index, uv_base + index
                    face.append(f"{vi}/{ti}" if index < len(texcoords) else str(vi))
                lines.append("f " + " ".join(face))
        vertex_base += len(pts)
        uv_base += len(texcoords)
        if safe_name not in copied:
            material_path = Path(material["path"].replace("\\", "/")).name
            local = None
            if texture_root and material_path:
                local = next((p for p in texture_root.rglob("*") if p.is_file() and p.name.casefold() == material_path.casefold()), None)
            if local:
                target = output.parent / local.name
                if local.resolve() != target.resolve():
                    shutil.copy2(local, target)
                copied[safe_name] = target.name
            else:
                copied[safe_name] = None
            mtl.append(f"newmtl {safe_name}\nKd 1 1 1\nKa 0 0 0\n" + (f"map_Kd {copied[safe_name]}\n" if copied[safe_name] else ""))
    output.write_text("\n".join(lines) + "\n", encoding="utf-8")
    mtl_path.write_text("\n".join(mtl), encoding="utf-8")
    return {"object": object_name, "animation": animation["name"], "animation_index": animation_index, "frame_number": frame_number, "mesh_index": mesh_index, "mesh_links": len(mesh["links"]), "obj": str(output), "mtl": str(mtl_path), "textures_found": sum(v is not None for v in copied.values()), "materials": len(copied)}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("model", type=Path)
    parser.add_argument("--object", help="named object key from the 3DB package")
    parser.add_argument("--frame", type=int, default=0)
    parser.add_argument("--output", type=Path, default=Path("model.obj"))
    parser.add_argument("--texture-root", type=Path)
    parser.add_argument("--summary", action="store_true")
    parser.add_argument("--animation", action="append", default=[],
                        help="include frame indices and extra values for an animation name")
    args = parser.parse_args()
    model = parse(args.model)
    summary = {
        "version": model["version"], "name": model["name"],
        "materials": len(model["materials"]), "meshes": len(model["meshes"]),
        "animation_count": len(model["animations"]),
        "animation_names": sorted({a["name"] for a in model["animations"]}),
        "object_count": len(model["objects"]),
        "object_names": sorted(model["objects"]),
        "triangles_arrays": len(model["triangles"]), "uv_arrays": len(model["uvs"]),
        "point_arrays": len(model["points"]), "consumed_bytes": model["consumed_bytes"], "file_bytes": model["file_bytes"],
    }
    if args.object:
        summary["export"] = export_obj(model, args.object, args.frame, args.output, args.texture_root)
    if args.animation:
        wanted = {name.casefold() for name in args.animation}
        summary["selected_animations"] = [
            {"index": index, "name": animation["name"],
             "frame_count": len(animation["mesh_indices"]),
             "mesh_indices": animation["mesh_indices"], "extra": animation["extra"]}
            for index, animation in enumerate(model["animations"])
            if animation["name"].casefold() in wanted
        ]
    print(json.dumps(summary, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()
