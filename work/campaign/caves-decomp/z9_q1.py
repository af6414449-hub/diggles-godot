# -*- coding: utf-8 -*-
"""Опрос экспорта главы: откуда приходят Dummy_Obw_* / Dummy_Urw_*."""
import json, os, collections

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
ch = json.load(open(os.path.join(ROOT, "native_campaign_chapter.json"), encoding="utf-8"))

print("ключи верхнего уровня:", list(ch.keys()))
pl = ch["placements"]
print("placements:", len(pl))
print("ключи placement[0]:", list(pl[0].keys()))
print("пример placement:", json.dumps(pl[0], ensure_ascii=False)[:400])

cnt = collections.Counter()
for p in pl:
    cls = str(p.get("class", ""))
    if "Obw" in cls or "Urw" in cls:
        cnt[(str(p.get("source_template")), cls)] += 1
print("\n--- Obw/Urw по source_template ---")
for k, v in sorted(cnt.items()):
    print("  ", k, v)

print("\n--- templates ---")
tm = ch.get("templates")
print(json.dumps(tm, ensure_ascii=False)[:3000])

print("\n--- story_placements ---")
sp = ch.get("story_placements")
if sp is not None:
    print(type(sp), len(sp) if hasattr(sp, "__len__") else "")
    print(json.dumps(sp, ensure_ascii=False)[:2000])
