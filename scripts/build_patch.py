#!/usr/bin/env python3
"""Build the unified diff of the hamster integration.

The "before" side is the live project (read only). The "after" side is the
agent working tree. New files are emitted as /dev/null -> file additions, so
the result can be applied with `git apply` or `patch -p1` from the root of the
Godot project.
"""
from __future__ import annotations

import difflib
import hashlib
from pathlib import Path

LIVE = Path(r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot")
WORK = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot")
OUT = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\hamster-integration.patch")
DATA_OUT = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\hamster-integration-data.patch")

NEW_FILES = [
    "scripts/native_wild_hamster.gd",
    "scripts/native_hamster_actor.gd",
    "scripts/native_hamster_ai.gd",
    "scripts/native_hamster_animations.gd",
    "scripts/native_hamster_clips.gd",
    "scripts/native_level_ground.gd",
    "scripts/native_command_dispatcher.gd",
    "scripts/native_command_handlers.gd",
    "scripts/native_hamster_actor_3d.gd",
    "scripts/native_hamster_demo.gd",
    "scripts/native_wild_hamster_probe.gd",
    "models/native_hamster_animations.json",
    "models/native_tasklist_commands.json",
    "tools/native_wild_hamster_self_test.gd",
    "tools/native_hamster_actor_self_test.gd",
    "tools/native_hamster_ai_self_test.gd",
    "tools/hamster_texture_orientation_probe.gd",
    "tools/native_hamster_probe.gd",
    "scenes/native_hamster_demo.tscn",
    "scenes/native_wild_hamster_probe.tscn",
]
# The clip data is 5 MB of minified JSON on a single line. Its unified diff
# would duplicate the whole payload, so it ships as a separate patch file.
DATA_FILES = [
    "models/native_hamster_clips.json",
]
MODIFIED = [
    "scripts/native_tasklist.gd",
    "scripts/multiplayer_test.gd",
]
# Files that are part of the integration but are excluded from the patch on
# purpose, with the reason recorded in the report.
EXCLUDED = [
    "godot/scripts/native_tasklist.gd.uid",
]


def read_text(path: Path) -> list[str]:
    return path.read_text(encoding="utf-8").splitlines(keepends=True)


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for block in iter(lambda: handle.read(1 << 20), b""):
            digest.update(block)
    return digest.hexdigest()


def diff_new(rel: str, with_data: bool = False) -> list[str]:
    target = WORK / rel
    if rel.endswith(".json") and not with_data:
        # The hamster clip data is 5 MB of JSON; the patch carries it as a
        # separate patch file instead of a line diff in the main patch.
        return []
    lines = read_text(target)
    header = (
        f"diff --git a/{rel} b/{rel}\n"
        f"new file mode 100644\n"
        f"--- /dev/null\n"
        f"+++ b/{rel}\n"
    )
    body = list(
        difflib.unified_diff([], lines, fromfile="/dev/null", tofile=f"b/{rel}", n=3)
    )
    return [header] + body


def diff_modified(rel: str) -> list[str]:
    before = read_text(LIVE / rel)
    after = read_text(WORK / rel)
    if before == after:
        return []
    header = f"diff --git a/{rel} b/{rel}\n"
    body = list(
        difflib.unified_diff(
            before, after, fromfile=f"a/{rel}", tofile=f"b/{rel}", n=3
        )
    )
    return [header] + body


def main() -> None:
    OUT.parent.mkdir(parents=True, exist_ok=True)
    chunks: list[str] = []
    for rel in MODIFIED:
        chunk = diff_modified(rel)
        if chunk:
            chunks.append("".join(chunk))
            print(f"patched file: {rel} ({len(chunk)} lines of diff)")
    for rel in NEW_FILES:
        chunk = diff_new(rel)
        if chunk:
            chunks.append("".join(chunk))
            print(f"new file:     {rel} ({len(chunk)} lines of diff)")
    OUT.write_text("\n".join(chunks), encoding="utf-8", newline="\n")
    print(f"\npatch written: {OUT} ({OUT.stat().st_size} bytes)")

    data_chunks: list[str] = []
    for rel in DATA_FILES:
        chunk = diff_new(rel, with_data=True)
        if chunk:
            data_chunks.append("".join(chunk))
            print(f"data file:    {rel} ({len(chunk)} lines of diff)")
    if data_chunks:
        DATA_OUT.write_text("\n".join(data_chunks), encoding="utf-8", newline="\n")
        print(f"data patch written: {DATA_OUT} ({DATA_OUT.stat().st_size} bytes)")

    print("\n=== SHA-256 of the copied files in the working tree")
    for rel in NEW_FILES + MODIFIED:
        target = WORK / rel
        if target.is_file():
            print(f"  {sha256(target)}  {rel}  ({target.stat().st_size} B)")


if __name__ == "__main__":
    main()
