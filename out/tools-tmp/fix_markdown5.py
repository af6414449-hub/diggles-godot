# -*- coding: utf-8 -*-
"""Put the two new sections back into the documents, cleanly."""
import pathlib

BASE = pathlib.Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\docs"
                    r"\reverse-engineering")
TMP = pathlib.Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\tools-tmp")

PLAN = [
    ("campaign-map-problems-and-solutions.md", "## 20. Земля и гранит",
     TMP / "section20.md", None),
    ("agent-result-campaign-map-2026-11-20.md", "### 3.26 Земля и гранит",
     TMP / "section3_26.md", "INTEGRATION_HANDOFF:"),
]


def main():
    for name, marker, source, handoff in PLAN:
        path = BASE / name
        text = path.read_text(encoding="utf-8")
        lines = text.split("\n")
        cut = None
        for index, line in enumerate(lines):
            if line.startswith(marker):
                cut = index
                break
        if cut is None:
            print("%s: the marker is not found" % name)
            continue
        head = lines[:cut]
        while head and head[-1].strip() == "":
            head.pop()
        section = source.read_text(encoding="utf-8").rstrip("\n")
        tail = []
        if handoff is not None:
            for line in lines[cut:]:
                if line.startswith(handoff):
                    tail.append(line)
                    break
        out = head + [""] + section.split("\n")
        if tail:
            out += ["", tail[0]]
        with path.open("w", encoding="utf-8", newline="\n") as handle:
            handle.write("\n".join(out) + "\n")
        check = path.read_text(encoding="utf-8")
        print("%s: %d lines, the handoff is the last one: %s"
              % (name, len(check.split("\n")), check.rstrip().endswith(
                  "INTEGRATION_HANDOFF: docs/reverse-engineering/agent-result-campaign-map-2026-11-20.md")))


if __name__ == "__main__":
    main()
