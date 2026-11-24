#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Compare the lighting data of the multiplayer map and the campaign chapter.

Multiplayer (battle) map: res://models/native_terrain_render.json
    attributes -> per corner base-light bytes of the cell grid
    materials  -> per corner material of the cell grid
    constants  -> the native illumination constants
Campaign chapter: res://models/native_campaign_chapter.json
    attributes -> per cell attribute byte of the chapter export
"""
import json
import os
from collections import Counter

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))


def load(rel):
    with open(os.path.join(ROOT, rel), encoding="utf-8") as handle:
        return json.load(handle)


render = load("godot/models/native_terrain_render.json")
print("== native_terrain_render.json keys:", list(render.keys()))
print("   constants:")
for key, value in render.get("constants", {}).items():
    print("      %-24s %s" % (key, value))
print("   attributes:", len(render.get("attributes", [])), "materials:", len(render.get("materials", [])))
multi_attr = render.get("attributes", [])
multi_mat = render.get("materials", [])
print("   attribute histogram:", sorted(Counter(multi_attr).items()))
print("   material   histogram:", sorted(Counter(str(v) for v in multi_mat).items()))
if "evidence" in render:
    ev = render["evidence"]
    print("   evidence keys:", list(ev.keys()) if isinstance(ev, dict) else ev)
    for key, value in (ev.items() if isinstance(ev, dict) else []):
        text = json.dumps(value, ensure_ascii=False)
        print("      %-20s %s" % (key, text[:600]))

chapter = load("godot/models/native_campaign_chapter.json")
camp_attr = chapter.get("attributes", {})
values = list(camp_attr.values())
print()
print("== chapter attributes:", len(values))
print("   histogram:", sorted(Counter(values).items()))
print("   chapter materials histogram:", sorted(Counter(chapter.get("materials", {}).values()).items()))

lights = load("godot/models/native_campaign_lights.json")
print()
print("== campaign lights:", len(lights.get("lights", [])))
for spec in lights.get("lights", [])[:12]:
    print("   ", spec.get("class"), "pos", spec.get("position"), "off", spec.get("offset"),
          "range", spec.get("range"), "color", spec.get("color"))
print("   light keys:", list(lights.keys()))

profile = load("godot/models/multi_start_010_profile.json")
print()
print("== multiplayer profile lights:", len(profile.get("lights", [])))
for spec in profile.get("lights", [])[:12]:
    print("   ", spec.get("class"), "pos", spec.get("position"), "range", spec.get("range"),
          "color", spec.get("color"))
print("   horizons:", json.dumps(profile.get("horizons", []), ensure_ascii=False)[:700])
