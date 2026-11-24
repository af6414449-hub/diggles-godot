# -*- coding: utf-8 -*-
"""Add the two new sections to the documents (without the PowerShell escapes)."""
import pathlib

BASE = pathlib.Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\docs"
                    r"\reverse-engineering")
TMP = pathlib.Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\tools-tmp")
HANDOFF = "INTEGRATION_HANDOFF: docs/reverse-engineering/agent-result-campaign-map-2026-11-20.md"


def add_section(name: str, source: pathlib.Path, before_handoff: bool) -> None:
    path = BASE / name
    lines = path.read_text(encoding="utf-8").split("\n")
    section = source.read_text(encoding="utf-8").rstrip("\n").split("\n")
    handoff = [line for line in lines if line.startswith("INTEGRATION_HANDOFF:")]
    if before_handoff and handoff:
        cut = len(lines) - 1 - lines[::-1].index(handoff[-1])
        head = lines[:cut]
        while head and head[-1].strip() == "":
            head.pop()
        out = head + [""] + section + ["", handoff[-1]]
    else:
        while lines and lines[-1].strip() == "":
            lines.pop()
        out = lines + [""] + section
    with path.open("w", encoding="utf-8", newline="\n") as handle:
        handle.write("\n".join(out) + "\n")
    check = path.read_text(encoding="utf-8")
    print("%s: %d lines, the handoff is the last one: %s"
          % (name, len(check.split("\n")), check.rstrip().endswith(HANDOFF)))


def main():
    add_section("campaign-map-problems-and-solutions.md", TMP / "section20_2.md", False)
    add_section("agent-result-campaign-map-2026-11-20.md", TMP / "section3_28.md", True)


if __name__ == "__main__":
    main()
