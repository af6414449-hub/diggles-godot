# -*- coding: utf-8 -*-
"""The last repair of the two appended sections.

PowerShell ate the backticks of the markdown and the letter n of the names
that started with it (the backtick n is a newline escape). The lines that were
broken by that newline are joined here, the code marks are put back and the
file keeps the line endings it had (LF).
"""
import pathlib
import re

BASE = pathlib.Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\docs"
                    r"\reverse-engineering")

FIXES = [
    ("(`hash_value(x+31,y+17)`) % 100 < 90)", "(`hash_value(x+31,y+17) % 100 < 90`)"),
    ("(* ", "(* `"),
    ("* ", "* `"),
]


def repair(path: pathlib.Path) -> None:
    text = path.read_text(encoding="utf-8")
    lines = text.split("\n")
    out: list[str] = []
    for line in lines:
        if re.match(r"^ative_campaign_\w", line) and out:
            out[-1] = out[-1].rstrip("\r") + " (`native_campaign_" + line[len("ative_campaign_"):]
            continue
        out.append(line)
    text = "\n".join(out)
    text = re.sub(r"(?<![\w`])ative_campaign_([\w.]+)", r"`native_campaign_\1`", text)
    text = text.replace("(* `", "* `")
    for old, new in FIXES:
        if old != new:
            text = text.replace(old, new)
    # the bullets of the list that the join broke: "(\n`native_campaign_...`)" is
    # fine, the list markers of the section "Что сделано в порту" are not.
    text = re.sub(r"^\* `native_campaign", "* `native_campaign", text, flags=re.M)
    text = re.sub(r"[\x00-\x08\x0b\x0c\x0e-\x1f]", "", text)
    with path.open("w", encoding="utf-8", newline="\n") as handle:
        handle.write(text)
    broken = [line for line in text.split("\n")
              if re.match(r"^ative_campaign_", line) or "(`native_campaign" in line
              and line.endswith("(")]
    print("%s: %d lines, the leftovers: %d" % (path.name, len(text.split("\n")), len(broken)))
    for line in broken[:5]:
        print("   |", repr(line)[:130])


def main():
    for name in ("campaign-map-problems-and-solutions.md",
                 "agent-result-campaign-map-2026-11-20.md"):
        repair(BASE / name)


if __name__ == "__main__":
    main()
