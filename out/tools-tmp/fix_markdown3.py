# -*- coding: utf-8 -*-
"""Join the lines that the newline escape of PowerShell broke and put the code
marks back."""
import pathlib
import re

BASE = pathlib.Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\docs"
                    r"\reverse-engineering")


def main():
    for name in ("campaign-map-problems-and-solutions.md",
                 "agent-result-campaign-map-2026-11-20.md"):
        path = BASE / name
        text = path.read_text(encoding="utf-8")
        lines = text.split("\n")
        out: list[str] = []
        for line in lines:
            if re.match(r"^ate_campaign_\w", line) and out:
                previous = out[-1]
                out[-1] = previous + " (`native_campaign_" + line[len("ate_campaign_"):]
                continue
            out.append(line)
        text = "\n".join(out)
        path.write_text(text, encoding="utf-8")
        bad = [line for line in text.split("\n")
               if re.match(r"^ate_campaign_\w", line)
               or re.search(r"[\x00-\x08\x0b\x0c\x0e-\x1f]", line)]
        print("%s: %d lines, the leftovers: %d" % (name, len(text.split("\n")), len(bad)))
        for line in bad[:5]:
            print("   |", repr(line)[:140])


if __name__ == "__main__":
    main()
