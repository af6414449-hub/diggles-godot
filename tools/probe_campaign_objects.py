#!/usr/bin/env python3
"""Where do the chapter objects stand?

Groups the placements by class and height and prints a sample per class, so
the surface of the map can be located in the data instead of guessed.

Usage:
  python tools/probe_campaign_objects.py
"""
import json
import os
import sys
from collections import Counter

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MODELS = os.path.join(ROOT, "godot", "models", "native_campaign_models.json")


def main():
    with open(MODELS, "r", encoding="utf-8") as handle:
        manifest = json.load(handle)
    placements = manifest.get("placements", [])
    print("placements: %d" % len(placements))
    keys = sorted(placements[0].keys()) if placements else []
    print("keys: %s" % ", ".join(keys))

    by_class = Counter()
    by_height = Counter()
    for placement in placements:
        by_class[placement.get("class", "?")] += 1
        by_height[round(float(placement.get("z", 0.0)), 2)] += 1

    print()
    print("classes:")
    for name, count in by_class.most_common():
        print("  %-24s %d" % (name, count))
    print()
    print("heights (z):")
    for height, count in sorted(by_height.items(), reverse=True):
        print("  %8.2f : %d" % (height, count))

    print()
    print("samples per class:")
    seen = {}
    for placement in placements:
        name = placement.get("class", "?")
        if name in seen:
            continue
        seen[name] = 1
        print("  %-20s x=%7.2f y=%7.2f z=%6.2f  %s" % (
            name, float(placement.get("x", 0.0)), float(placement.get("y", 0.0)),
            float(placement.get("z", 0.0)), str(placement.get("model_object", ""))[:40]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
