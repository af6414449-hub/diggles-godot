#!/usr/bin/env python3
"""Independent reference implementation of Campaign.tcl:first_level (Urwald).

This is the cross-check for `godot/scripts/diggles_campaign_generator.gd`.
The tables and the draw order are transcribed from
`data/Scripts/gameplay/Campaign.tcl` (lines 22-191); the random source is the
native `irandom` command recovered from Diggles.exe.

Usage:
    python reference_first_level.py --seed 1 [--seed 2 ...] [--json out.json]
"""
from __future__ import annotations

import argparse
import json
from pathlib import Path

MASK = 0xFFFFFFFF
MAG01 = (0x00000000, 0x9908B0DF)
STATE_SIZE = 624


class DigglesIrandom:
    """Diggles.exe irandom stream (0x4454D0 seeding, 0x49C670 generator)."""

    def __init__(self, seed: int) -> None:
        self.state = [0] * STATE_SIZE
        value = seed & MASK
        for index in range(STATE_SIZE):
            high = value & 0xFFFF0000
            next_value = ((value * 69069) + 1) & MASK
            self.state[index] = high | (next_value >> 16)
            value = ((next_value * 69069) + 1) & MASK
        self.index = STATE_SIZE

    def next_u32(self) -> int:
        if self.index >= STATE_SIZE:
            self._twist()
            self.index = 1
            value = self.state[0]
        else:
            value = self.state[self.index]
            self.index += 1
        return self._temper(value)

    def irandom(self, limit: int) -> int:
        value = self.next_u32() & 0x7FFFFFFF
        if limit == 0:
            return value % 0x7FFFFFFF
        return value % limit

    @staticmethod
    def _temper(value: int) -> int:
        value &= MASK
        value = (value ^ (value >> 11)) & MASK
        value = (value ^ ((value << 7) & 0x9D2C5680)) & MASK
        value = (value ^ ((value << 15) & 0xEFC60000)) & MASK
        value = (value ^ (value >> 18)) & MASK
        return value

    def _twist(self) -> None:
        state = self.state
        for index in range(0, 227):
            mixed = ((state[index] ^ state[index + 1]) & 0x7FFFFFFF) ^ state[index]
            mixed = ((mixed >> 1) ^ MAG01[mixed & 1]) & MASK
            state[index] = (mixed ^ state[index + 397]) & MASK
        for index in range(227, 623):
            mixed = ((state[index] ^ state[index + 1]) & 0x7FFFFFFF) ^ state[index]
            mixed = ((mixed >> 1) ^ MAG01[mixed & 1]) & MASK
            state[index] = (mixed ^ state[index - 227]) & MASK
        tail = ((state[623] ^ state[0]) & 0x7FFFFFFF) ^ state[623]
        tail = ((tail >> 1) ^ MAG01[tail & 1]) & MASK
        state[623] = (tail ^ state[396]) & MASK
        previous = state[623]
        post = ((state[0] ^ previous) & 0x7FFFFFFF) ^ previous
        post = ((post >> 1) ^ MAG01[post & 1]) & MASK
        state[623] = (post ^ state[396]) & MASK


CAVE_LIST = [
    ("urw_hol_001_a", 20, 4),
    ("urw_hol_014_b", 20, 12),
    ("urw_hol_018_c", 28, 16),
    ("urw_hol_019_b", 24, 16),
    ("urw_hol_027_a", 16, 4),
]

COMB_LIST = [
    (0, 1, [0]), (0, 2, [0]), (0, 4, [0]), (1, 0, [4]),
    (1, 3, [4]), (4, 0, [0]), (4, 2, [0]), (4, 3, [0]),
]

TUNN_LIST = [
    ("urw_gng_013_", 4, 0),
    ("urw_gng_002_", 8, 0),
    ("urw_gng_003_", 12, 0),
]

CON_LIST = [
    [0, 0, 1, 2], [0, 0, 2, 1], [0, 1, 0, 2],
    [4, 2, 0, 1], [4, 2, 1, 0], [4, 1, 2, 0],
]

VODO_LIST = [
    ("urw_gng_001_", "ab"), ("urw_gng_007_", "abcd"), ("urw_gng_008_", "abc"),
    ("urw_gng_009_", "abcd"), ("urw_gng_012_", "abcd"), ("urw_gng_019_", "abc"),
    ("urw_gng_022_", "abdeg"), ("urw_gng_023_", "abc"), ("urw_gng_026_", "abc"),
    ("urw_gng_028_", "bcd"), ("urw_gng_030_", "a"), ("urw_gng_032_", "ab"),
    ("urw_gng_034_", "acdfhk"), ("urw_gng_039_", "ab"), ("urw_gng_042_", "ab"),
    ("urw_gng_045_", "ab"), ("urw_unq_vodo_001_", "a"), ("urw_gng_004_", "ab"),
    ("urw_gng_027_", "abc"), ("urw_gng_036_", "ab"), ("urw_gng_043_", "ab"),
    ("urw_gng_044_", "ab"),
]

VOCON_LIST_1 = [
    [(3, 20, 0), (8, 8, 12), (5, 20, 12), (6, 24, 12), (16, -24, 12)],
    [(1, 20, 0), (13, 4, 16), (7, 4, 28), (9, 12, 4), (16, -28, 12)],
    [(2, 20, 0), (5, 20, 8), (6, 24, 8), (15, 8, 8), (12, 4, 16), (6, 16, 24), (16, -28, 12)],
    [(2, 20, 0), (14, 12, 8), (4, 8, 12), (13, 0, 16), (7, 0, 28), (16, -32, 12)],
    [(2, 20, 0), (11, 0, 16), (15, 8, 8), (5, 20, 8), (6, 24, 8), (7, 8, 28), (16, -32, 12)],
    [(1, 20, 0), (6, 16, 20), (4, 8, 8), (14, 12, 4), (10, 4, 12), (16, -28, 12)],
]

VOCON_LIST_2 = [
    [(18, 20, 0), (0, 20, 20), (10, 24, 12), (6, 36, 20), (16, -12, 12)],
    [(20, 20, 0), (21, 32, 4), (17, 20, 20), (10, 36, 12), (6, 48, 20), (16, -12, 12)],
    [(19, 20, 0), (1, 24, 12), (14, 16, 16), (6, 32, 8), (16, -16, 12)],
]

LEFT_LETTERS = ("abdef", "cgih")
RIGHT_LETTERS = ("cfkh", "abdeg")


def first_level(start_x: int, start_y: int, seed: int) -> dict:
    rng = DigglesIrandom(seed)
    present_side = rng.irandom(2)
    left_letters = LEFT_LETTERS[present_side]
    right_letters = RIGHT_LETTERS[present_side]
    std_x = start_x + 36
    std_y = start_y + 40
    comb_index = rng.irandom(len(COMB_LIST))
    left_id, right_id, y_offsets = COMB_LIST[comb_index]
    std_y += y_offsets[rng.irandom(len(y_offsets))]
    conn_index = rng.irandom(len(CON_LIST))
    conn = list(CON_LIST[conn_index])
    std_x += conn.pop(0)
    if conn_index < 2:
        vocon_list = VOCON_LIST_2
    elif conn_index < 4:
        vocon_list = VOCON_LIST_1 + VOCON_LIST_2
    else:
        vocon_list = VOCON_LIST_1
    vodo = vocon_list[rng.irandom(len(vocon_list))]

    placements = []

    def add(name: str, x: int, y: int) -> None:
        placements.append({"template": name, "x": x, "y": y})

    left_name, left_x, left_y = CAVE_LIST[left_id]
    add(left_name, std_x - left_x, std_y - left_y)
    add("urw_gng_021_" + left_letters[rng.irandom(len(left_letters))], std_x - left_x - 4, std_y)
    right_name, right_x, right_y = CAVE_LIST[right_id]
    add(right_name, std_x + 24, std_y - right_y)
    add("urw_gng_022_" + right_letters[rng.irandom(len(right_letters))], std_x + right_x + 24, std_y)

    tunnel_x = std_x
    vodo_x = std_x - 20
    vodo_y = std_y + 4
    for element in conn:
        if element == 0:
            vodo_x = tunnel_x - 20
            vodo_y = std_y + 4
        prefix, advance, offset_y = TUNN_LIST[element]
        pool = "ab" if prefix == "urw_gng_002_" else "abc"
        add(prefix + pool[rng.irandom(len(pool))], tunnel_x, std_y + offset_y)
        tunnel_x += advance

    for template_id, dx, dy in vodo:
        prefix, letters = VODO_LIST[template_id]
        add(prefix + letters[rng.irandom(len(letters))], vodo_x + dx, vodo_y + dy)

    return {
        "seed": seed,
        "start": {"x": start_x, "y": start_y},
        "placements": placements,
        "selection": {
            "present_side": present_side,
            "comb_index": comb_index,
            "conn_index": conn_index,
            "vodo_chain_count": len(vocon_list),
        },
    }


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--seed", type=int, action="append", default=None)
    parser.add_argument("--json", type=Path)
    args = parser.parse_args()
    seeds = args.seed if args.seed else [1, 2, 3]
    result = {}
    for seed in seeds:
        level = first_level(208, 0, seed)
        probe = DigglesIrandom(seed)
        level["draws"] = [probe.next_u32() for _ in range(8)]
        result[str(seed)] = level
        print(f"seed={seed} side={level['selection']['present_side']} "
              f"comb={level['selection']['comb_index']} conn={level['selection']['conn_index']} "
              f"templates={len(level['placements'])}")
        for item in level["placements"]:
            print(f"    {item['template']:24s} {item['x']:5d} {item['y']:5d}")
    if args.json:
        args.json.parent.mkdir(parents=True, exist_ok=True)
        args.json.write_text(json.dumps(result, indent=1) + "\n", encoding="utf-8", newline="\n")


if __name__ == "__main__":
    main()
