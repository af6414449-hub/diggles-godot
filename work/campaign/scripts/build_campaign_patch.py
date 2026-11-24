#!/usr/bin/env python3
"""Build the unified diff of the campaign level generator integration.

The "before" side is the live project (read only). The "after" side is the
campaign work tree. Added and modified files are detected automatically and
emitted as a git style unified diff that can be applied with `git apply` or
`patch -p1` from the root of the Godot project.

Usage:
    python build_campaign_patch.py [--work DIR] [--live DIR] [--out FILE]
"""
from __future__ import annotations

import argparse
import difflib
import hashlib
from pathlib import Path

LIVE = Path(r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot")
WORK = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\godot")
OUT = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\campaign-level-generator.patch")
SKIP_DIRS = {".godot", "out"}
TEXT_SUFFIXES = {".gd", ".json", ".tscn", ".tres", ".gdshader", ".cfg", ".md", ".txt", ".import"}


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for block in iter(lambda: handle.read(1 << 20), b""):
            digest.update(block)
    return digest.hexdigest()


def read_lines(path: Path) -> list[str]:
    return path.read_text(encoding="utf-8").splitlines(keepends=True)


def is_text(path: Path) -> bool:
    return path.suffix.lower() in TEXT_SUFFIXES


def diff_new(rel: str) -> list[str]:
    target = WORK / rel
    header = (
        f"diff --git a/{rel} b/{rel}\n"
        f"new file mode 100644\n"
    )
    body = list(difflib.unified_diff([], read_lines(target), fromfile="/dev/null", tofile=f"b/{rel}", n=3))
    return [header] + body


def diff_modified(rel: str) -> list[str]:
    before = read_lines(LIVE / rel)
    after = read_lines(WORK / rel)
    header = f"diff --git a/{rel} b/{rel}\n"
    body = list(difflib.unified_diff(before, after, fromfile=f"a/{rel}", tofile=f"b/{rel}", n=3))
    return [header] + body


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--work", type=Path, default=WORK)
    parser.add_argument("--live", type=Path, default=LIVE)
    parser.add_argument("--out", type=Path, default=OUT)
    parser.add_argument("--modified", nargs="*", default=[],
                        help="Files this worker changed in an existing file. Files that differ "
                             "from the live tree without being listed here are reported as drift "
                             "and never patched, so parallel work in the live tree is not reverted.")
    args = parser.parse_args()
    work: Path = args.work
    live: Path = args.live
    added: list[str] = []
    drift: list[str] = []
    for path in sorted(work.rglob("*")):
        rel_path = path.relative_to(work)
        if any(part in SKIP_DIRS for part in rel_path.parts):
            continue
        if not path.is_file():
            continue
        rel = rel_path.as_posix()
        counterpart = live / rel_path
        if not counterpart.is_file():
            if is_text(path):
                added.append(rel)
            continue
        if sha256(path) != sha256(counterpart) and is_text(path):
            if rel in args.modified:
                added.append(rel) if False else None
            else:
                drift.append(rel)
    modified: list[str] = [rel for rel in args.modified if rel not in added]
    chunks: list[str] = []
    for rel in modified:
        chunks.append("".join(diff_modified(rel)))
    for rel in added:
        chunks.append("".join(diff_new(rel)))
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text("\n".join(chunks), encoding="utf-8", newline="\n")
    print(f"modified: {len(modified)} {modified}")
    print(f"added:    {len(added)} {added}")
    print(f"patch written: {args.out} ({args.out.stat().st_size} bytes)")
    if drift:
        print(f"\nlive drift not patched (parallel work in the live tree): {drift}")
    print("\n=== SHA-256 of the delivered files")
    for rel in added + modified:
        target = work / rel
        print(f"  {sha256(target)}  {rel}  ({target.stat().st_size} B)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
