# -*- coding: utf-8 -*-
"""Определяет знак Y пересчёта сокета по сокету головы (slot 4) и симметрии рук."""
import io, json, os

MODELS = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
PS = 16384.0
with io.open(os.path.join(MODELS, "dwarf_attachments.json"), encoding="utf-8") as f:
    att = json.load(f)
mann = att["models"]["mann.3db::mann"]

with io.open(os.path.join(MODELS, "demo_start_models.json"), encoding="utf-8") as f:
    demo = json.load(f)
clips = dict(demo["objects"]["mann.3db::mann"]["locomotion"])
with io.open(os.path.join(MODELS, "dwarf_surface_walk.json"), encoding="utf-8") as f:
    clips.update(json.load(f)["clips"])

def body_bbox(clip):
    xs, ys, zs = [], [], []
    for frame in clip["frames"]:
        for s in frame["surfaces"]:
            for p in s["points"]:
                xs.append((p[0]-0.5)*PS); ys.append(-(p[1]-0.5)*PS); zs.append((p[2]-0.5)*PS)
    return min(xs), max(xs), min(ys), max(ys), min(zs), max(zs)

for name in ("stand_anim_b", "stand_anim_a", "kletterstand"):
    clip = clips[name]
    minx, maxx, miny, maxy, minz, maxz = body_bbox(clip)
    a = mann["clips"][name]
    print("=== %s  body bbox x[%.0f..%.0f] y[%.0f..%.0f] z[%.0f..%.0f]" % (
        name, minx, maxx, miny, maxy, minz, maxz))
    for slot in ("0", "1", "4"):
        o = mann["meshes"][str(a["mesh_indices"][0])]["slots"].get(slot, {}).get("origin_render")
        if not o:
            print("   slot", slot, "нет"); continue
        noflip = (o[0]*200, o[1]*200, o[2]*200)
        flip = (o[0]*200, -o[1]*200, o[2]*200)
        print("   slot %s origin_render=%s" % (slot, [round(v,4) for v in o]))
        print("        без F: (%7.1f,%7.1f,%7.1f)   с F: (%7.1f,%7.1f,%7.1f)" % (
            noflip[0], noflip[1], noflip[2], flip[0], flip[1], flip[2]))
    print()
