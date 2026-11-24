# -*- coding: utf-8 -*-
"""Move the handoff line of the report to the end of the file."""
import pathlib

path = pathlib.Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\docs"
                    r"\reverse-engineering\agent-result-campaign-map-2026-11-20.md")
text = path.read_text(encoding="utf-8")
lines = text.split("\n")
handoff = [line for line in lines if line.startswith("INTEGRATION_HANDOFF:")]
if not handoff:
    raise SystemExit("no handoff line")
lines = [line for line in lines if not line.startswith("INTEGRATION_HANDOFF:")]
while lines and lines[-1].strip() == "":
    lines.pop()
lines.append("")
lines.append(handoff[-1])
path.write_text("\n".join(lines) + "\n", encoding="utf-8")
print("the handoff line is now the last one: %s" % handoff[-1])
print("the lines: %d" % len(lines))
