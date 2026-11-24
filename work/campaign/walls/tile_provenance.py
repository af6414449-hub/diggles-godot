"""Are the ground tiles in the project the native files of the game?

Compares every Gnd_* and Native_* texture of godot/textures/ground with the
file of the same name in the game data, and lists what the game data holds in
addition (the Msk_* masks used to compose the mixed tiles).
"""
from __future__ import annotations

import hashlib
import os

PROJECT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\ground"
GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\ground"


def digest(path: str) -> str:
    with open(path, "rb") as fh:
        return hashlib.sha256(fh.read()).hexdigest()


def main() -> None:
    if not os.path.isdir(GAME):
        print("game data folder not found:", GAME)
        return

    game_files = {f for f in os.listdir(GAME) if f.lower().endswith(".tga")}
    print("game data tiles:", len(game_files))
    masks = sorted(f for f in game_files if f.startswith("Msk_"))
    gnd = sorted(f for f in game_files if f.startswith("Gnd_"))
    native = sorted(f for f in game_files if f.startswith("Native_"))
    print(f"  Gnd_*   : {len(gnd)}")
    print(f"  Native_*: {len(native)}")
    print(f"  Msk_*   : {len(masks)}  -> {masks[:4]}")

    project_files = {f for f in os.listdir(PROJECT) if f.lower().endswith(".tga")}
    same = 0
    differ = 0
    missing = 0
    for name in sorted(project_files):
        src = os.path.join(GAME, name)
        dst = os.path.join(PROJECT, name)
        if not os.path.exists(src):
            missing += 1
            continue
        if digest(src) == digest(dst):
            same += 1
        else:
            differ += 1
            if differ <= 5:
                print("  differs:", name)
    print(f"\nproject tiles identical to the game: {same}, differing: {differ}, "
          f"not in the game data: {missing}")

    absent = sorted(f for f in game_files if f not in project_files)
    print(f"tiles in the game data but not in the project: {len(absent)}")
    print("  ", absent[:10])


if __name__ == "__main__":
    main()
