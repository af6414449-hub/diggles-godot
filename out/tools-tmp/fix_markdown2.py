# -*- coding: utf-8 -*-
"""The last repair of the mangled markdown: the broken lines and the control
characters that PowerShell left in the text."""
import pathlib
import re

BASE = pathlib.Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\docs"
                    r"\reverse-engineering")

BROKEN = [
    ("1. `_ground_edge_band` (\nate_campaign_first_level.gd):",
     "1. `_ground_edge_band` (`native_campaign_first_level.gd`):"),
    ("2. `base_material` (\nate_campaign_ground.gd):",
     "2. `base_material` (`native_campaign_ground.gd`):"),
    ("**Сделано в порту:** \n", "**Сделано в порту:**\n"),
    ("(`hash_value`(x+31,y+17)", "(`hash_value(x+31,y+17)`)"),
]


def main():
    for name in ("campaign-map-problems-and-solutions.md",
                 "agent-result-campaign-map-2026-11-20.md"):
        path = BASE / name
        text = path.read_text(encoding="utf-8")
        for old, new in BROKEN:
            text = text.replace(old, new)
        # the control characters of the PowerShell escapes
        text = re.sub(r"[\x00-\x08\x0b\x0c\x0e-\x1f]", "", text)
        path.write_text(text, encoding="utf-8")
        lines = text.split("\n")
        print("%s: %d lines" % (name, len(lines)))
        bad = [line for line in lines
               if "ate_campaign_" in line or "ase_material" in line
               or re.search(r"[\x00-\x08\x0b\x0c\x0e-\x1f]", line)]
        print("   the leftovers: %d" % len(bad))
        for line in bad[:6]:
            print("   |", repr(line)[:140])


if __name__ == "__main__":
    main()
