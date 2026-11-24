# -*- coding: utf-8 -*-
"""Геометрия моделей деревьев Obw: локальный z меша и мировой z."""
import json, os, collections

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
ch = json.load(open(os.path.join(ROOT, "native_campaign_chapter.json"), encoding="utf-8"))
objs = ch.get("objects")
print("objects:", type(objs), len(objs) if hasattr(objs, "__len__") else "")
if isinstance(objs, list):
    print("ключи objects[0]:", list(objs[0].keys()))
    for o in objs[:5]:
        print(" ", json.dumps(o, ensure_ascii=False)[:300])
elif isinstance(objs, dict):
    ks = list(objs.keys())[:5]
    for k in ks:
        print(" ", k, json.dumps(objs[k], ensure_ascii=False)[:300])

print("\n--- summary ---")
print(json.dumps(ch.get("summary"), ensure_ascii=False)[:2000])
