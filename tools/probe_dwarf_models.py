# -*- coding: utf-8 -*-
"""Probe the dwarf model JSONs: surface layout, topology stability, bounds."""
import io, json, os, collections

BASE = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"

def load(name):
    with io.open(os.path.join(BASE, name), encoding="utf-8") as f:
        return json.load(f)

def frames_of_clip(clip):
    return clip["frames"]

def describe_surfaces(tag, clip):
    fr = clip["frames"]
    sigs = set()
    for f in fr:
        sig = tuple((s["material"], s["texture"], len(s["points"]), len(s["triangles"])) for s in f["surfaces"])
        sigs.add(sig)
    print("%-28s frames=%2d  surface-shapes=%d" % (tag, len(fr), len(sigs)))
    # topology stability: are triangle lists identical across frames?
    tris = [tuple(tuple(s["triangles"]) for s in f["surfaces"]) for f in fr]
    same = len(set(tris)) == 1
    pts = [repr([s["points"] for s in f["surfaces"]]) for f in fr]
    print("%-28s topology-identical=%s  geometry-varied=%s" % ("", same, len(set(pts)) > 1))
    return fr

print("=" * 70)
print("DEMO START MODELS - locomotion")
d = load("demo_start_models.json")
mann = d["objects"]["mann.3db::mann"]
print("object keys:", list(mann.keys()))
print("bounds:", mann.get("bounds"))
print("animation:", mann.get("animation"), "animation_index:", mann.get("animation_index"))
for name, clip in mann["locomotion"].items():
    describe_surfaces(name, clip)
s0 = mann["locomotion"]["gehen_loop"]["frames"][0]["surfaces"][0]
print("sample surface keys:", list(s0.keys()))
print("sample point:", s0["points"][0], "uv:", s0["uvs"][0], "tri:", s0["triangles"][:6], "bright:", s0["brightness"][:6])
print("alpha_range:", s0["alpha_range"], "texture:", s0["texture"], "material:", s0["material"])

print("=" * 70)
print("SURFACE WALK")
sw = load("dwarf_surface_walk.json")
for name, clip in sw["clips"].items():
    describe_surfaces(name, clip)
print("sample surface keys:", list(sw["clips"]["kletter_hoch_loop"]["frames"][0]["surfaces"][0].keys()))

print("=" * 70)
print("DIG ACTION")
da = load("dwarf_dig_action.json")
print("tool:", json.dumps(da["tool"], ensure_ascii=False)[:800])
for name, clip in da["clips"].items():
    describe_surfaces(name, clip)

print("=" * 70)
print("DIG FEEDBACK")
df = load("native_dig_feedback.json")
print("keys:", list(df.keys()))
for name, clip in df["clips"].items():
    describe_surfaces(name, clip)

print("=" * 70)
print("FLOOR SLEEP")
fs = load("native_floor_sleep.json")
for name, clip in fs["clips"].items():
    describe_surfaces(name, clip)

print("=" * 70)
print("TEXTURE INVENTORY (all distinct textures used by the dwarf)")
tex = collections.Counter()
for src in [
    [f for f in mann["locomotion"].values()],
    list(sw["clips"].values()), list(da["clips"].values()),
    list(df["clips"].values()), list(fs["clips"].values()),
]:
    for clip in src:
        for f in clip["frames"]:
            for s in f["surfaces"]:
                tex[s["texture"]] += 1
for t, c in tex.most_common():
    print("  %-28s %d" % (t, c))

print("=" * 70)
print("BOUNDS of mann object:")
print(json.dumps(mann.get("bounds"), ensure_ascii=False)[:500])
b = mann["locomotion"]["gehen_loop"]["frames"][0].get("bounds")
print("frame bounds:", json.dumps(b, ensure_ascii=False)[:400])
