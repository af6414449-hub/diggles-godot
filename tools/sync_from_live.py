"""Sync the live Codex Godot project into the Minimax primary tree.

The Minimax workspace becomes the primary project, so it must first be brought
to the exact state of the live Codex tree.

Policy:
  * every live file is copied into the Minimax tree (per file, explicit paths);
  * files that only exist in the Minimax tree are reported as EXTRAS and are
    NOT deleted automatically - the caller decides;
  * a keep-list protects local scaffolding that the live tree does not carry.

Usage:
    python sync_from_live.py <live_godot_dir> <minimax_godot_dir>
"""
import hashlib
import os
import shutil
import sys

KEEP_DIRS = {"docs", "out", "export_templates", "feature_profiles",
             "script_templates", "text_editor_themes"}
SKIP_DIRS = {".godot"}


def sha256(path):
    digest = hashlib.sha256()
    with open(path, "rb") as handle:
        for chunk in iter(lambda: handle.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def walk(root):
    for base, dirs, names in os.walk(root):
        dirs[:] = [d for d in dirs if d not in SKIP_DIRS]
        for name in names:
            full = os.path.join(base, name)
            rel = os.path.relpath(full, root).replace("\\", "/")
            yield rel, full


def main():
    live = sys.argv[1]
    target = sys.argv[2]
    os.makedirs(target, exist_ok=True)

    copied = 0
    unchanged = 0
    live_rels = set()
    for rel, source in walk(live):
        live_rels.add(rel)
        destination = os.path.join(target, rel.replace("/", os.sep))
        if not os.path.exists(destination):
            os.makedirs(os.path.dirname(destination), exist_ok=True)
            shutil.copy2(source, destination)
            copied += 1
            continue
        if os.path.getsize(source) != os.path.getsize(destination):
            shutil.copy2(source, destination)
            copied += 1
            continue
        if sha256(source) != sha256(destination):
            shutil.copy2(source, destination)
            copied += 1
            continue
        unchanged += 1

    extras = []
    for rel, full in walk(target):
        if rel in live_rels:
            continue
        top = rel.split("/")[0]
        if top in KEEP_DIRS:
            continue
        extras.append(rel)

    print("copied/changed:", copied)
    print("unchanged      :", unchanged)
    print("live files     :", len(live_rels))
    print("extras in target (not deleted):", len(extras))
    for rel in sorted(extras)[:60]:
        print("   EXTRA", rel)


if __name__ == "__main__":
    main()
