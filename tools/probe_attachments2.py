# -*- coding: utf-8 -*-
"""Смотрит формат креплений и мешей в dwarf_attachments.json + ищет бинарник с записями."""
import io, json, os

PROJECT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
MODELS = os.path.join(PROJECT, "godot", "models")

with io.open(os.path.join(MODELS, "dwarf_attachments.json"), encoding="utf-8") as f:
    att = json.load(f)

mann = att["models"]["mann.3db::mann"]
print("model keys:", list(mann.keys()))

clip = mann["clips"]["buddeln_oben_normal"]
print("\nclips[buddeln_oben_normal] =")
print(json.dumps(clip, ensure_ascii=False, indent=1)[:1200])

print("\nclips[standard] =")
print(json.dumps(mann["clips"]["standard"], ensure_ascii=False, indent=1)[:600])

meshes = mann["meshes"]
for mid in list(meshes.keys())[:3]:
    print("\nmeshes[%s] =" % mid)
    print(json.dumps(meshes[mid], ensure_ascii=False, indent=1)[:900])

# ищем бинарник с записями креплений
print("\n=== поиск файла с attachment_records_offset ===")
target = mann["attachment_records_offset"]
print("offset:", target, "records:", mann["attachment_record_count"],
      "=> размер ~", mann["attachment_record_count"] * 20)
for root, dirs, files in os.walk(PROJECT):
    dirs[:] = [d for d in dirs if d not in (".git", "node_modules", "__pycache__")]
    for name in files:
        p = os.path.join(root, name)
        try:
            size = os.path.getsize(p)
        except OSError:
            continue
        if size > 100000 and (name.endswith(".bin") or name.endswith(".dat") or name.endswith(".raw")):
            print("%-70s %d" % (os.path.relpath(p, PROJECT), size))
