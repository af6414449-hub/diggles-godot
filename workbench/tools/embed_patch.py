"""Regenerate the unified diff and embed it into the result report."""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import make_patch

WB = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\workbench"
REPORT = (r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\docs"
          r"\reverse-engineering\agent-result-walkmap-performance-2026-11-19.md")


def main():
    if make_patch.main() != 0:
        raise SystemExit("patch generation failed")
    with open(os.path.join(WB, "walkmap-performance.patch"), "r", encoding="utf-8", newline="") as handle:
        patch = handle.read()
    if "```" in patch:
        raise SystemExit("patch contains a fence marker")
    with open(REPORT, "r", encoding="utf-8", newline="") as handle:
        report = handle.read()
    if "<!--PATCH-->" not in report:
        raise SystemExit("marker missing")
    report = report.replace("<!--PATCH-->", patch.rstrip("\n"))
    with open(REPORT, "w", encoding="utf-8", newline="") as handle:
        handle.write(report)
    print("EMBEDDED patch bytes=%d report bytes=%d" % (len(patch), len(report)))


if __name__ == "__main__":
    main()
