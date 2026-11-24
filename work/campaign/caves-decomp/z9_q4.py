# -*- coding: utf-8 -*-
"""З9: bounds моделей obw_*/urw_* и преобразование координат."""
import json, os

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
mo = json.load(open(os.path.join(ROOT, "native_campaign_models.json"), encoding="utf-8"))
print("coordinate_transform:", json.dumps(mo.get("coordinate_transform"), ensure_ascii=False, indent=1))
print("native_model_transform:", json.dumps(mo.get("native_model_transform"), ensure_ascii=False, indent=1))
print("map_template:", mo.get("map_template"), "source_template:", mo.get("source_template"))
print("limits:", json.dumps(mo.get("limits"), ensure_ascii=False))
print("missing:", json.dumps(mo.get("missing"), ensure_ascii=False)[:800])

objs = mo["objects"]
keys = sorted(objs.keys())
print("\n=== bounds моделей, встречающихся в главе (obw/urw) ===")
for k in keys:
    kl = k.lower()
    if "obw" not in kl and "urw" not in kl:
        continue
    o = objs[k]
    b = o.get("bounds")
    print("  %-34s bounds=%s" % (k, [round(v, 3) for v in b] if b else None))
