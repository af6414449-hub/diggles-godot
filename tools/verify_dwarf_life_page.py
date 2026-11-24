# -*- coding: utf-8 -*-
"""Verify the packed dwarf blob against the source model JSON."""
import base64, io, json, os, re, struct, sys

HTML = r"C:\Users\frant\Downloads\dwarf_life.html"
MODELS = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"

raw = io.open(HTML, encoding="utf-8").read()
m = re.search(r'const CLIPS_B64 = "([A-Za-z0-9+/=]+)";', raw)
blob = base64.b64decode(m.group(1))
print("blob bytes:", len(blob))

off = 0
magic = blob[0:4]
off = 4
version, clip_count = struct.unpack_from("<II", blob, off)
off += 8
print("magic:", magic, "version:", version, "clips:", clip_count)

clips = {}
for c in range(clip_count):
    name_len = struct.unpack_from("<I", blob, off)[0]; off += 4
    name = blob[off:off + name_len].decode("utf-8"); off += name_len
    frame_count, surface_count = struct.unpack_from("<II", blob, off); off += 8
    fps, scale = struct.unpack_from("<ff", blob, off); off += 8
    center = struct.unpack_from("<fff", blob, off); off += 12
    height = struct.unpack_from("<f", blob, off)[0]; off += 4
    surfaces = []
    for s in range(surface_count):
        point_count, index_count = struct.unpack_from("<II", blob, off); off += 8
        tex_index = blob[off]; off += 1
        indices = struct.unpack_from("<%dH" % index_count, blob, off); off += index_count * 2
        surfaces.append({"points": point_count, "indices": index_count, "tex": tex_index, "idx": indices})
    frames = []
    for f in range(frame_count):
        per = []
        for s in surfaces:
            positions = struct.unpack_from("<%dh" % (s["points"] * 3), blob, off); off += s["points"] * 6
            uvs = struct.unpack_from("<%dh" % (s["points"] * 2), blob, off); off += s["points"] * 4
            bright = blob[off:off + s["points"]]; off += s["points"]
            per.append({"pos": positions, "uv": uvs, "bright": bright})
        frames.append(per)
    clips[name] = {"frames": frames, "surfaces": surfaces, "fps": fps, "scale": scale,
                   "center": center, "height": height}

print("decoded OK, consumed %d of %d bytes" % (off, len(blob)))
assert off == len(blob), "trailing bytes!"

# --- compare with the source JSON -----------------------------------------
POINT_SCALE = 16384.0
UV_SCALE = 32767.0

def load(name):
    return json.load(io.open(os.path.join(MODELS, name), encoding="utf-8"))

checks = 0
errors = 0
demo = load("demo_start_models.json")
surface_walk = load("dwarf_surface_walk.json")
dig_action = load("dwarf_dig_action.json")
dig_feedback = load("native_dig_feedback.json")
floor_sleep = load("native_floor_sleep.json")

sources = {
    "gehen_loop": demo["objects"]["mann.3db::mann"]["locomotion"]["gehen_loop"],
    "kletter_hoch_loop": surface_walk["clips"]["kletter_hoch_loop"],
    "buddeln_unten": dig_action["clips"]["buddeln_unten"],
    "buddeln_unten_unfall": dig_feedback["clips"]["digdownaccident"],
    "schlafen_boden_loop": floor_sleep["clips"]["schlafen_boden_loop"],
}

for name, clip in sources.items():
    packed = clips[name]
    frames = clip["frames"]
    assert packed["frames"] and len(packed["frames"]) == len(frames), name
    for fi in (0, len(frames) - 1):
        for si, surface in enumerate(frames[fi]["surfaces"]):
            ps = packed["surfaces"][si]
            assert ps["points"] == len(surface["points"]), (name, si, "point count")
            assert ps["indices"] == len(surface["triangles"]), (name, si, "index count")
            assert list(ps["idx"]) == list(surface["triangles"]), (name, si, "indices")
            for i in range(min(8, len(surface["points"]))):
                p = surface["points"][i]
                expect = (round((p[0] - 0.5) * POINT_SCALE),
                          round(-(p[1] - 0.5) * POINT_SCALE),
                          round((p[2] - 0.5) * POINT_SCALE))
                got = (packed["frames"][fi][si]["pos"][i * 3],
                       packed["frames"][fi][si]["pos"][i * 3 + 1],
                       packed["frames"][fi][si]["pos"][i * 3 + 2])
                checks += 1
                if expect != got:
                    errors += 1
                    print("MISMATCH pos", name, fi, si, i, expect, got)
                u = surface["uvs"][i]
                euv = (round(u[0] * UV_SCALE), round(u[1] * UV_SCALE))
                guv = (packed["frames"][fi][si]["uv"][i * 2], packed["frames"][fi][si]["uv"][i * 2 + 1])
                checks += 1
                if euv != guv:
                    errors += 1
                    print("MISMATCH uv", name, fi, si, i, euv, guv)
            checks += 1
            if bytes(packed["frames"][fi][si]["bright"]) != bytes(surface["brightness"]):
                errors += 1
                print("MISMATCH bright", name, fi, si)

print("checked %d values, %d errors" % (checks, errors))

# --- every clip in the payload must exist in the blob ---------------------
payload = json.loads(re.search(r'const PAYLOAD = (\{.*?\});\n', raw, re.S).group(1))
missing = [c["name"] for c in payload["clips"] if c["name"] not in clips]
extra = [k for k in clips if k not in {c["name"] for c in payload["clips"]}]
print("payload clips:", len(payload["clips"]), "blob clips:", len(clips),
      "missing:", missing, "extra:", extra)

# --- every button in the page must reference an existing clip -------------
refs = re.findall(r'\["([a-z_0-9]+)",\s*(\d+)\]', raw)
bad = sorted({c for c, _ in refs if c not in clips and c not in ("0",)})
print("button clip refs:", len({c for c, _ in refs}), "unknown:", bad)
print("RESULT:", "OK" if (errors == 0 and not missing and not extra and not bad) else "FAIL")
