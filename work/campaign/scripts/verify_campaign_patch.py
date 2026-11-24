#!/usr/bin/env python3
"""Round-trip check of the campaign level generator patch.

Applies the patch to a fresh copy of the live project and compares the result
with the campaign work tree. Proves that the delivered patch reproduces the
verified integration exactly.
"""
from __future__ import annotations

import argparse
import hashlib
import shutil
import sys
from pathlib import Path

LIVE = Path(r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot")
WORK = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\godot")
TRIAL = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\trial")
PATCH = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\campaign-level-generator.patch")


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for block in iter(lambda: handle.read(1 << 20), b""):
            digest.update(block)
    return digest.hexdigest()


def parse_patch(text: str) -> list[dict]:
    files: list[dict] = []
    current: dict | None = None
    lines = text.splitlines(keepends=True)
    index = 0
    while index < len(lines):
        line = lines[index]
        if line.startswith("diff --git "):
            current = {"path": line.split(" b/", 1)[1].strip(), "hunks": [], "is_new": False}
            files.append(current)
        elif current is not None and line.startswith("new file mode"):
            current["is_new"] = True
        elif current is not None and line.startswith("@@"):
            old_start = int(line.split("@@")[1].strip().split(" ")[0].split(",")[0].lstrip("-"))
            body: list[str] = []
            index += 1
            while index < len(lines) and not lines[index].startswith(("@@", "diff --git ")):
                body.append(lines[index])
                index += 1
            current["hunks"].append({"old_start": old_start, "body": body})
            continue
        index += 1
    return files


def apply_hunks(original: str, hunks: list[dict]) -> str:
    result = original.splitlines(keepends=True)
    offset = 0
    for hunk in hunks:
        old = [line[1:] for line in hunk["body"] if line.startswith((" ", "-"))]
        new = [line[1:] for line in hunk["body"] if line.startswith((" ", "+"))]
        start = hunk["old_start"] - 1 + offset
        actual = result[start : start + len(old)]
        if actual != old:
            raise SystemExit(
                f"context mismatch at line {hunk['old_start']}:\n"
                f"  expected: {''.join(old)[:160]!r}\n  actual:   {''.join(actual)[:160]!r}"
            )
        result[start : start + len(old)] = new
        offset += len(new) - len(old)
    return "".join(result)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--patch", type=Path, default=PATCH)
    parser.add_argument("--live", type=Path, default=LIVE)
    parser.add_argument("--work", type=Path, default=WORK)
    parser.add_argument("--trial", type=Path, default=TRIAL)
    args = parser.parse_args()
    if args.trial.exists():
        shutil.rmtree(args.trial)
    args.trial.mkdir(parents=True)
    shutil.copytree(args.live, args.trial, dirs_exist_ok=True, ignore=shutil.ignore_patterns("out", ".godot"))
    touched: list[str] = []
    files = parse_patch(args.patch.read_text(encoding="utf-8"))
    for entry in files:
        target = args.trial / entry["path"]
        if entry["is_new"]:
            target.parent.mkdir(parents=True, exist_ok=True)
            original = ""
        else:
            if not target.is_file():
                raise SystemExit(f"patch target missing in live project: {entry['path']}")
            original = target.read_text(encoding="utf-8")
        target.write_text(apply_hunks(original, entry["hunks"]), encoding="utf-8", newline="")
        touched.append(entry["path"])
    print(f"{args.patch.name}: {len(files)} file hunks applied without conflict")
    mismatches: list[str] = []
    for rel in touched:
        a = args.trial / rel
        b = args.work / rel
        if not b.is_file():
            mismatches.append(f"missing in working tree: {rel}")
            continue
        if sha256(a) != sha256(b):
            mismatches.append(f"content differs: {rel}")
    print(f"integration files compared: {len(touched)}")
    if mismatches:
        print("\nMISMATCHES:")
        for line in mismatches:
            print(f"  {line}")
        return 1
    print("\nPATCH ROUND TRIP OK: patching the live project reproduces the verified work tree")
    return 0


if __name__ == "__main__":
    sys.exit(main())
