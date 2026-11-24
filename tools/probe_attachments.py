# -*- coding: utf-8 -*-
"""Подробно смотрит dwarf_attachments.json и ключи dig_action про spitzhacke/hand."""
import io, json, os

MODELS = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"

def load(name):
    with io.open(os.path.join(MODELS, name), encoding="utf-8") as f:
        return json.load(f)

def walk(obj, prefix="", depth=0, maxdepth=4):
    if depth > maxdepth:
        return
    if isinstance(obj, dict):
        for k, v in obj.items():
            if isinstance(v, (dict, list)):
                size = len(v)
                print("%s%s{%s size=%d}" % ("  " * depth, prefix, k, size))
                walk(v, "", depth + 1, maxdepth)
            else:
                print("%s%s%s = %r" % ("  " * depth, prefix, k, v))
    elif isinstance(obj, list):
        if obj and isinstance(obj[0], (dict, list)):
            print("%s[0] of %d:" % ("  " * depth, len(obj)))
            walk(obj[0], "", depth + 1, maxdepth)
        else:
            print("%s%s%r" % ("  " * depth, prefix, obj[:12]))

att = load("dwarf_attachments.json")
print("=" * 70)
print("dwarf_attachments.json")
walk(att, "", 0, 3)

dig = load("dwarf_dig_action.json")
print("=" * 70)
print("dwarf_dig_action.json -> mesh_exporter")
walk(dig["mesh_exporter"], "", 0, 3)
print("=" * 70)
print("dwarf_dig_action.json -> point_contract")
walk(dig["point_contract"], "", 0, 2)
print("=" * 70)
print("dwarf_dig_action.json -> object / actor_class / aliases")
for k in ("object", "actor_class", "aliases", "default_work_clip"):
    print(k, "=", json.dumps(dig.get(k), ensure_ascii=False)[:400])
