#!/usr/bin/env python3
"""Apply the wild hamster integration to the working tree multiplayer_test.gd.

Every insertion uses a text anchor (never a line number) and asserts that the
anchor occurs exactly once. The host function block is taken verbatim from the
MCode snapshot so that the integration stays byte identical to the verified
implementation.
"""
from __future__ import annotations

import sys
from pathlib import Path

SNAP = Path(
    r"C:\Users\frant\.minimax\sessions\mvs_e213cb8b6788404489ad3b0b5c39827f"
    r"\workspace\Diggles-mcode\work\godot\scripts\multiplayer_test.gd"
)
TARGET = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\scripts\multiplayer_test.gd")

HOST_BLOCK_FIRST_LINE = "## Spawn one wild hamster of the original level."
HOST_BLOCK_LAST_LINE = "\t\twild_hamster_food.erase(entry)"
HOST_BLOCK_ANCHOR = "func _navigation_obstacle_radius(placement_class: String) -> float:"


def host_block() -> str:
    """The verified host block of the snapshot, lines 852..1124."""
    lines = SNAP.read_text(encoding="utf-8").split("\n")
    start = next(i for i, line in enumerate(lines) if line == HOST_BLOCK_FIRST_LINE)
    end = next(i for i, line in enumerate(lines) if line == HOST_BLOCK_LAST_LINE)
    if end < start:
        raise SystemExit("host block bounds wrong")
    return "\n".join(lines[start : end + 1])


def replace_once(text: str, anchor: str, replacement: str, label: str) -> str:
    count = text.count(anchor)
    if count != 1:
        raise SystemExit(f"anchor {label}: expected 1 occurrence, found {count}")
    return text.replace(anchor, replacement)


def main() -> int:
    original = TARGET.read_text(encoding="utf-8")
    text = original

    # 1. Constants and variables of the hamster integration.
    anchor = 'const WORLD_MODEL_LIGHT: Script = preload("res://scripts/native_world_model_light.gd")\n'
    addition = (
        anchor
        + 'const WILD_HAMSTER: Script = preload("res://scripts/native_wild_hamster.gd")\n'
        + 'const LEVEL_GROUND := preload("res://scripts/native_level_ground.gd")\n'
        + "var wild_hamsters: Array[Node3D] = []\n"
        + "var wild_hamster_food: Array[Dictionary] = []\n"
        + "# The ground of the level per height level. The navigation grid of the scene\n"
        + "# covers the main floor only, the hamsters of the upper terrace need their own.\n"
        + "var wild_hamster_ground: RefCounted = null\n"
        + "var wild_hamster_grids: Dictionary = {}\n"
    )
    text = replace_once(text, anchor, addition, "A1 constants")

    # 2. Load the terrain of the level. Must run after WORLD_SPACE.apply() and
    #    _build_geometry(): the world shift rewrites terrain["cells"] in place.
    anchor = (
        "\tsource_profile.use_native_diffuse = (native_terrain_lighting_preview "
        'or args.has("--native-terrain-lighting")) and not args.has("--legacy-terrain-lighting")\n'
        "\t_build_geometry(data)\n"
    )
    addition = anchor + (
        "\twild_hamster_ground = LEVEL_GROUND.new() as RefCounted\n"
        '\t(wild_hamster_ground as RefCounted).call("load_terrain", data)\n'
    )
    text = replace_once(text, anchor, addition, "A2 load_terrain")

    # 3. Spawn the hamster of a placement. After the world shift, so that the
    #    hamster stands on its own terrace and not in the void.
    anchor = (
        "\t\tposition_data = [float(position_data[0])+template_shift.x,\n"
        "\t\t\tfloat(position_data[1])+template_shift.y,position_data[2]]\n"
        "\t\tvar rotation_data: Array = placement[\"rotation\"]\n"
        "\t\tvar instance_root: Node3D = Node3D.new()\n"
    )
    addition = (
        "\t\tposition_data = [float(position_data[0])+template_shift.x,\n"
        "\t\t\tfloat(position_data[1])+template_shift.y,position_data[2]]\n"
        "\t\tvar rotation_data: Array = placement[\"rotation\"]\n"
        "\t\tif placement_class == \"Hamster\":\n"
        "\t\t\t# The original level places the wild hamsters as living objects of\n"
        "\t\t\t# the class hamster.tcl, not as scenery. They get the actor of that\n"
        "\t\t\t# class and the original clips of the hamster.3db package.\n"
        "\t\t\t_spawn_wild_hamster(placement, position_data, rotation_data)\n"
        "\t\t\tcontinue\n"
        "\t\tvar instance_root: Node3D = Node3D.new()\n"
    )
    text = replace_once(text, anchor, addition, "A3 hamster spawn")

    # 4. Collect the food of the hamster.
    anchor = "\t\tscene_root.add_child(instance_root)\n"
    addition = anchor + (
        '\t\tif placement_class == "Grillpilz":\n'
        "\t\t\t# The second food of the hamster in hamster.tcl:319-344.\n"
        '\t\t\twild_hamster_food.append({"ref": instance_root.name,\n'
        '\t\t\t\t"position": instance_root.position, "node": instance_root})\n'
    )
    text = replace_once(text, anchor, addition, "A4 food")

    # 5. The host functions, verbatim from the verified snapshot.
    block = host_block()
    text = replace_once(text, HOST_BLOCK_ANCHOR, block + "\n\n\n" + HOST_BLOCK_ANCHOR, "A5 host block")

    if text == original:
        raise SystemExit("no change applied")
    TARGET.write_text(text, encoding="utf-8", newline="\n")
    print(f"applied: {len(original)} -> {len(text)} bytes")
    return 0


if __name__ == "__main__":
    sys.exit(main())
