#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Structure of the multiplayer map models: where is the lighting data?"""
import json
import os

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))

PATHS = [
    "godot/models/multi_start_010_terrain.json",
    "godot/models/multi_start_010_profile.json",
    "godot/models/multi_start_010_models.json",
    "godot/models/multi_start_010_world_context.json",
    "godot/models/native_campaign_chapter.json",
]


def describe(value, depth=0):
    if isinstance(value, dict):
        return "{%d keys: %s}" % (len(value), ", ".join(list(value.keys())[:12]))
    if isinstance(value, list):
        return "[%d]" % len(value)
    return repr(value)[:60]


for rel in PATHS:
    path = os.path.join(ROOT, rel)
    if not os.path.exists(path):
        print("MISSING", rel)
        continue
    data = json.load(open(path, encoding="utf-8"))
    print("==", rel, os.path.getsize(path), "bytes")
    if isinstance(data, dict):
        for key, value in data.items():
            print("   %-28s %s" % (key, describe(value)))
        for key in ("summary", "meta", "info"):
            if isinstance(data.get(key), dict):
                print("   -- %s --" % key)
                for k2, v2 in data[key].items():
                    print("      %-24s %s" % (k2, describe(v2)))
    print()
