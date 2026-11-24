# -*- coding: utf-8 -*-
"""Проверяет, что сокет руки попадает в тело гнома: сравнивает позицию сокета
с центром bbox клипа (в единицах модели) и с реальными точками тела."""
import io, json, os

PROJECT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
MODELS = os.path.join(PROJECT, "godot", "models")
PS = 16384.0

with io.open(os.path.join(MODELS, "dwarf_attachments.json"), encoding="utf-8") as f:
    att = json.load(f)
mann = att["models"]["mann.3db::mann"]

def body_points(clip):
    for frame in clip["frames"]:
        for s in frame["surfaces"]:
            for p in s["points"]:
                yield ((p[0] - 0.5) * PS, -(p[1] - 0.5) * PS, (p[2] - 0.5) * PS)

def check(name, clip):
    a = mann["clips"].get(name)
    if not a:
        print("%-28s нет креплений" % name)
        return
    pts = list(body_points(clip))
    minx = min(p[0] for p in pts); maxx = max(p[0] for p in pts)
    miny = min(p[1] for p in pts); maxy = max(p[1] for p in pts)
    minz = min(p[2] for p in pts); maxz = max(p[2] for p in pts)
    center = ((minx + maxx) / 2, (miny + maxy) / 2, (minz + maxz) / 2)
    for fi in (0, len(a["mesh_indices"]) // 2, len(a["mesh_indices"]) - 1):
        o = mann["meshes"][str(a["mesh_indices"][fi])]["slots"]["0"]["origin_render"]
        hand = (o[0] * 200.0, o[1] * 200.0, o[2] * 200.0)
        rel = (hand[0] - center[0], hand[1] - center[1], hand[2] - center[2])
        inside = (minx <= hand[0] <= maxx and miny <= hand[1] <= maxy and minz <= hand[2] <= maxz)
        print("%-26s f%-3d hand=(%8.1f,%8.1f,%8.1f) rel_to_center=(%7.1f,%7.1f,%7.1f) inside=%s"
              % (name, fi, hand[0], hand[1], hand[2], rel[0], rel[1], rel[2], inside))

with io.open(os.path.join(MODELS, "demo_start_models.json"), encoding="utf-8") as f:
    demo = json.load(f)
clips = dict(demo["objects"]["mann.3db::mann"]["locomotion"])
for fn in ("dwarf_surface_walk.json", "dwarf_dig_action.json", "native_floor_sleep.json"):
    with io.open(os.path.join(MODELS, fn), encoding="utf-8") as f:
        clips.update(json.load(f)["clips"])

for name in ("stand_anim_b", "gehen_loop", "kletterstand", "kletter_hoch_loop",
             "stand_zu_kletterstand", "werkzeug_raus_a", "buddeln_oben_normal",
             "buddeln_vorn", "werkzeug_weg_a"):
    if name in clips:
        check(name, clips[name])
    print()
