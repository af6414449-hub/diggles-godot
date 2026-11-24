# -*- coding: utf-8 -*-
"""Repair the markdown of the sections that PowerShell mangled.

The sections were appended with a PowerShell here-string, and the backtick of
the markdown code marks was eaten by PowerShell as an escape character.
"""
import pathlib
import re

BASE = pathlib.Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\docs"
                    r"\reverse-engineering")

FIXES = [
    # the broken lines: the backtick before the n was a newline escape
    ("LITERAL:1. _ground_edge_band (\nate_campaign_first_level.gd):",
     "1. `_ground_edge_band` (`native_campaign_first_level.gd`):"),
    ("LITERAL:2. ase_material (\nate_campaign_ground.gd):",
     "2. `base_material` (`native_campaign_ground.gd`):"),
    ("LITERAL:**Сделано в порту:** \n",
     "**Сделано в порту:**\n"),
    # the identifiers that lost their backticks
    (r"(?<![\w`])ate_campaign_map_material\.gd",
     "`native_campaign_map_material.gd`"),
    (r"(?<![\w`])ate_campaign_first_level\.gd",
     "`native_campaign_first_level.gd`"),
    (r"(?<![\w`])ate_campaign_ground\.gd",
     "`native_campaign_ground.gd`"),
    (r"(?<![\w`])ate_campaign_profile\.gd:cell_material",
     "`native_campaign_profile.gd:cell_material`"),
    (r"(?<![\w`])ate_campaign_backdrop\.gd",
     "`native_campaign_backdrop.gd`"),
    (r"(?<![\w`])ase_material\b", "`base_material`"),
    (r"(?<![\w`])_ground_edge_band\b", "`_ground_edge_band`"),
    (r"(?<![\w`])180-stone-default\.png", "`v180-stone-default.png`"),
    (r"(?<![\w`])182-rings-fixed\.png", "`v182-rings-fixed.png`"),
    (r"(?<![\w`])183-rings-fixed-wide\.png", "`v183-rings-fixed-wide.png`"),
    (r"(?<![\w`])184-low-wide\.png", "`v184-low-wide.png`"),
    (r"(?<![\w`])z-start-before-after\.png", "`zz-start-before-after.png`"),
    (r"(?<![\w`])zz-gen-offset\.png", "`zz-gen-offset.png`"),
    (r"(?<![\w`])data/Scripts/gameplay/Campaign\.tcl:2-5",
     "`data/Scripts/gameplay/Campaign.tcl:2-5`"),
    (r"(?<![\w`])data/Scripts/gameplay/Campaign\.tcl:2-4",
     "`data/Scripts/gameplay/Campaign.tcl:2-4`"),
    (r"(?<![\w`])systeminit\.tcl:64", "`systeminit.tcl:64`"),
    (r"(?<![\w`])CTclGlobalMethods::SMDrawStone", "`CTclGlobalMethods::SMDrawStone`"),
    (r"(?<![\w`])FUN_005fc9d0(?![:\w])", "`FUN_005fc9d0`"),
    (r"(?<![\w`])FUN_00598f10(?![:\w])", "`FUN_00598f10`"),
    (r"(?<![\w`])FUN_0047edc0(?![:\w])", "`FUN_0047edc0`"),
    (r"(?<![\w`])FUN_0049c670(?![:\w])", "`FUN_0049c670`"),
    (r"(?<![\w`])FUN_004454d0(?![:\w])", "`FUN_004454d0`"),
    (r"(?<![\w`])sm_draw_stone\b", "`sm_draw_stone`"),
    (r"(?<![\w`])map create\b", "`map create`"),
    (r"(?<![\w`])hash_value\b", "`hash_value`"),
    (r"(?<![\w`])set_view\b", "`set_view`"),
]


def repair(path: pathlib.Path) -> int:
    text = path.read_text(encoding="utf-8")
    before = text
    for pattern, replacement in FIXES:
        if pattern.startswith("LITERAL:"):
            text = text.replace(pattern[len("LITERAL:"):], replacement)
        else:
            text = re.sub(pattern, replacement, text)
    if text != before:
        path.write_text(text, encoding="utf-8")
        return 1
    return 0


def main():
    for name in ("campaign-map-problems-and-solutions.md",
                 "agent-result-campaign-map-2026-11-20.md"):
        path = BASE / name
        changed = repair(path)
        print("%s: %s" % (name, "repaired" if changed else "no change"))
        text = path.read_text(encoding="utf-8")
        print("   the leftovers: %s" % sorted(set(
            re.findall(r"(?<![\w`])ate_campaign_\w+|(?<![\w`])ase_material", text))))


if __name__ == "__main__":
    main()
