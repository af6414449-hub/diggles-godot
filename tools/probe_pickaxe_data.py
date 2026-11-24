# -*- coding: utf-8 -*-
"""Смотрит структуру исходных JSON Diggles: есть ли сетка кирки и точки крепления."""
import io, json, os, collections

MODELS = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"

def show(name, keys=None):
    path = os.path.join(MODELS, name)
    with io.open(path, encoding="utf-8") as f:
        data = json.load(f)
    print("=" * 70)
    print(name, "-> top keys:", list(data.keys())[:12])
    return data

def dig(obj, path):
    for k in path:
        obj = obj[k]
    return obj

data = show("dwarf_dig_action.json")
clips = data["clips"]
print("clips:", list(clips.keys()))
for name, clip in clips.items():
    print("\n--- clip", name, "keys:", list(clip.keys()))
    frame = clip["frames"][0]
    print("  frame keys:", list(frame.keys()))
    for i, s in enumerate(frame["surfaces"]):
        print("   surface", i, "keys:", list(s.keys()),
              "texture:", s.get("texture"),
              "points:", len(s.get("points", [])),
              "tris:", len(s.get("triangles", [])))
    break

print("\n=== поиск ключей с упоминанием кирки/руки/креплений ===")
for name in os.listdir(MODELS):
    if not name.endswith(".json"):
        continue
    with io.open(os.path.join(MODELS, name), encoding="utf-8") as f:
        raw = f.read()
    hits = []
    for word in ["spitzhacke", "hacke", "pick", "hand", "attach", "attach_point",
                 "mesh_exported", "werkzeug", "tool"]:
        if word in raw.lower():
            hits.append(word)
    if hits:
        print("%-34s %s" % (name, ", ".join(hits)))
