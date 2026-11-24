# -*- coding: utf-8 -*-
"""Проверяет покрытие клипов креплениями и печатает трансформ сокета руки."""
import io, json, os

PROJECT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
MODELS = os.path.join(PROJECT, "godot", "models")

with io.open(os.path.join(MODELS, "dwarf_attachments.json"), encoding="utf-8") as f:
    att = json.load(f)
mann = att["models"]["mann.3db::mann"]

# наши клипы и их число кадров
with io.open(os.path.join(MODELS, "demo_start_models.json"), encoding="utf-8") as f:
    demo = json.load(f)
srcs = [
    ("demo_start_models.json", demo["objects"]["mann.3db::mann"]["locomotion"]),
]
for fn in ("dwarf_surface_walk.json", "dwarf_dig_action.json", "native_floor_sleep.json"):
    with io.open(os.path.join(MODELS, fn), encoding="utf-8") as f:
        srcs.append((fn, json.load(f)["clips"]))
with io.open(os.path.join(MODELS, "native_dig_feedback.json"), encoding="utf-8") as f:
    srcs.append(("native_dig_feedback.json", json.load(f)["clips"]))

print("%-30s %6s %6s %-12s %s" % ("clip", "frames", "att", "slot0 ok", "origin_render frame0"))
for fn, clips in srcs:
    for name, clip in clips.items():
        if name not in att["models"]["mann.3db::mann"]["clips"]:
            continue
        a = mann["clips"][name]
        nframes = clip.get("frame_count", len(clip.get("frames", [])))
        ok = len(a["mesh_indices"]) == nframes
        slot0 = []
        for mi in a["mesh_indices"]:
            m = mann["meshes"].get(str(mi))
            slot0.append("0" in (m or {}).get("slots", {}))
        o = mann["meshes"][str(a["mesh_indices"][0])]["slots"].get("0", {}).get("origin_render")
        print("%-30s %6d %6d %-12s %s" % (
            name, nframes, len(a["mesh_indices"]),
            "%d/%d" % (sum(slot0), len(slot0)), o))

# сокет руки у клипов копки: как он двигается
print("\n=== движение сокета правой руки (buddeln_oben_normal) ===")
a = mann["clips"]["buddeln_oben_normal"]
for i, mi in enumerate(a["mesh_indices"]):
    s = mann["meshes"][str(mi)]["slots"]["0"]
    print(" frame %2d origin_render=%s  rot=%s" % (
        i, [round(v, 4) for v in s["origin_render"]],
        [round(v, 3) for v in s["rotation_radians"]]))
