# Diggles: The Myth of Fenris — reimplementation on Godot 4.7.2

A source-first reverse-engineering effort and port of the economy/strategy game
**Diggles: The Myth of Fenris** (released as "Wiggles" in Europe, SEK GmbX / Innonics,
2001–2002) to **Godot 4.7.2** — reproducing the original mechanics rather than inventing
new ones.

> **Status:** private repository, work in progress. The project was never under version
> control until the first commit below; its history used to be kept as manual copies of
> whole trees plus dates. The current state is described in `PROJECT-MAP-2026-11-21.md`.

---

## What this is

Diggles is an RTS/economy game about dwarves who mine ore, run farms, fight creatures and
follow a daily routine. The 2001 original runs on a **C++ engine with its own D3D renderer**
and a **Tcl** scripting layer. Game data lives in binary formats (PMP maps, 3DB models,
BlockDB height maps), and a good part of the rules lives in `.tcl` scripts.

This project reads the original data **read-only** and reproduces its behaviour in
GDScript. It is not "a game inspired by Diggles" — the goal is that a chapter plays out
the way it does in the original.

## Why

**Goal:** a self-contained Android implementation — the player completes a chapter from
start to finish, and the chapter is assembled the same way the original assembles it.

**Definition of done:** an APK with the first chapter, 30 FPS on a Vivo.

| Step | What "done" means | State |
|---|---|---|
| **A. Campaign level generator** | the chapter is assembled from original templates deterministically by seed | done; two implementations still need to be merged into one |
| **B. Dwarf as an autonomous agent** | a dwarf with no orders finds work, sleeps, eats, walks to work | not started (block M7) |
| **C. Economy and farms** | farms produce, dwarves eat and carry | partial |
| **D. Combat and enemies** | combat follows the original combat table | not started (block M6) |
| **E. Story and staging** | story scenes play out, the boss appears on stage | engine exists; dialogue and quests missing |
| **F. Android release** | APK with the first chapter, 30 FPS on a Vivo | not started |

**Order of work:** B → C → E → D → F.

## The project's core rule: FACT / ADAPTER / UNKNOWN

Every claim is labelled, and the labels are never mixed:

- **FACT** — confirmed against the original: an address in the EXE, a line of Tcl, bytes in a
  3DB/PMP file.
- **ADAPTER** — an engineering decision taken where the original is unknown or unusable.
- **UNKNOWN** — written down as such; nothing is invented.

In code this is expressed as `## SOURCE:` comments (fact) and `## ADAPTER:` comments (a port
decision). Numbers from the research documents must never be carried into the code as
constants — they are hypotheses until checked against the original.

## Quick start

**Requirements:** Godot **4.7.2** (GL Compatibility renderer) and Python **3.11** for the
tooling. The original game itself is only needed as a source of facts; the project does not
read its data at runtime.

1. Open `godot/project.godot` in Godot 4.7.2 → import → **F5** (the main scene is
   `res://scenes/campaign_first_level.tscn`).
2. Controls in the campaign scene: **LMB** — orbit/rotate, **RMB** — pan, **wheel** — zoom,
   **Q**/**E** — rotate the camera, **+**/**−** — zoom. On touch: one finger rotates, two
   fingers pan or zoom (the mode is locked in after the first movement and cannot mix until
   both fingers are released).
3. The separate reference scene `godot/scenes/terrain_reference.tscn` reproduces an original
   scene (`demo_start/hol_024`): **R** — reset, **O** — switch projection, **C**/**T** —
   auxiliary toggles.

All other project documentation is in Russian, under `docs/`.

## Repository layout

```
godot/          the main Godot 4.7.2 project
docs/           documentation: plans, research, reverse-engineering notes, reviews
tools/          Python tooling (export, audits, field building)
scripts/        verification, build and patch scripts
work/           reverse-engineering artefacts: Ghidra output, dumps, tree snapshots
out/            run artefacts: screenshots, test logs, ready-made patches
```

| Path | What it is | Size |
|---|---|---|
| `godot/scripts/` | 82 GDScript modules; the `native_*` prefix marks a port of the original | 0.9 MB |
| `godot/tools/` | 69 self-tests (`*_self_test.gd` and `*_test.gd`) and 9 probes (`*_probe.gd`) | 0.5 MB |
| `godot/scenes/` | 9 scenes, main one is `campaign_first_level.tscn` | — |
| `godot/shaders/` | 6 shaders, including `native_campaign_terrain.gdshader` | — |
| `godot/models/` | 48 JSON files holding data extracted from the original (maps, models, lighting) | 81 MB |
| `godot/textures/`, `godot/assets/` | textures and assets extracted from the original | 49 MB |
| `docs/plan/` | work plans; `queue-2026-11-19.md` is the source of truth for the queue | — |
| `docs/research/` | research based on public sources | — |
| `docs/reverse-engineering/` | EXE analysis and per-block reports (`agent-result-*.md`) | — |
| `docs/review/` | integration reviews | — |
| `tools/` | 72 Python tools: chapter export, audits, field building | — |
| `scripts/` | 21 scripts: test runs, patches, round-trip verification | — |
| `work/` | Ghidra decompilation, RE artefacts, tree snapshots | 665 MB |
| `out/` | screenshots and logs from 34+ runs, ready-made patches | 760 MB |

At the repository root: `PROJECT-MAP-2026-11-21.md` — the full map of the project, and
`arrow-keys.asm` / `keybind-refs.asm` — analysis of how the original EXE reads keys.

**Deliberately not in the repository:** `baseline/`, `repro/`, `trial/`, `review-tmp/` —
history snapshots and the verifier's sandbox (see `PROJECT-MAP-2026-11-21.md` §2.3); Godot's
import cache (`godot/.godot/`); `__pycache__`; and `RefusalRates/`, an unrelated task that
does not belong to this project.

## Tests

Every work block is verified by a self-test with golden values. The tests live in
`godot/tools/*_self_test.gd` and run headless through Godot.

```powershell
# all suites at once; the Godot path is hardcoded in scripts/run_all_suites.py (GODOT = ...)
python scripts/run_all_suites.py --project godot --out out/testlogs

# individual suites
python scripts/run_all_suites.py --project godot --out out/testlogs --only native_walk_flags_self_test,native_campaign_camera_self_test
```

A run prints `OK <suite> <N> assertions` per suite and ends with `ALL SUITES GREEN`. The
script kills hung Godot processes by command line, so it does not disturb other sessions'
engines. It exits with `1` if any suite fails.

Targeted tools: `scripts/run_hamster_suites.py`, `scripts/judge_suites.py`,
`scripts/run_scene_headless.py`, `scripts/verify_patch_roundtrip.py` — each has its own
`--help`.

## Subsystems

| Subsystem | Main files | Self-test |
|---|---|---|
| Navigation / walkability | `native_walkmap.gd`, `native_walk_flags.gd`, `native_walk_pose.gd` | `native_walk_flags_self_test` |
| Route planning | `surface_walk_action.gd`, `floor_walk_action.gd`, `native_fix_dig.gd` | `native_fix_dig_self_test` |
| Digging and excavation | `native_dig_rules.gd`, `native_dig_next.gd`, `native_tunnel_rules.gd` | `native_dig_next_self_test` |
| Corridor (player-drawn) | `native_corridor_selection.gd`, `native_corridor_stroke.gd` | `native_corridor_selection_self_test` |
| Ground and surface rendering | `native_campaign_ground.gd`, `native_campaign_walls.gd`, `native_terrain_illumination.gd` | `native_campaign_ground_self_test` |
| Camera and chapter map | `native_campaign_camera.gd`, `native_campaign_level.gd` | `native_campaign_camera_self_test` |
| Level generator | `native_level_generator.gd` | `native_level_generator_self_test` |
| Dwarf agent | `native_dwarf_sparetime.gd`, `native_dwarf_work_states.gd`, `native_dwarf_place_registry.gd` | `native_dwarf_sparetime_self_test` |
| Dwarves of the chapter | `native_campaign_dwarf.gd`, `native_campaign_dig_test.gd` | `native_campaign_dwarf_test` |
| Hamsters and beasts | `native_hamster_actor.gd`, `native_hamster_ai.gd`, `native_wild_hamster.gd` | `native_hamster_actor_self_test` |
| Raupe (worm) and farm | `native_raupe_actor.gd`, `native_farm_raupe.gd` | `native_raupe_actor_self_test` |
| Light and torches | `native_torch_runtime.gd`, `native_torch_placement.gd`, `native_world_model_light.gd` | `native_torch_runtime_self_test` |
| Story | `native_story_sequencer.gd`, `native_command_dispatcher.gd` | `native_story_sequencer_self_test` |
| Combat | `native_battle_world.gd` | `native_battle_world_self_test` |

The full list is in `docs/PROJECT_GUIDE.md` §2.4.

## How the reverse engineering works

The source of facts is the original game data (Tcl scripts, PMP maps, 3DB models, BlockDB)
plus disassembly of the EXE. That is where the specific numbers come from, which no
"similar-looking" engine would yield:

- **Chapter generation:** `first_level` + the original's own RNG `irandom` +
  `sm_mark_temparea` + `MapTemplateSet`. A level is a function of its seed, not a
  hand-made map; the original's worlds run Urwald → Schwefel → Metall → Lava → Kristall →
  6000.
- **Templates:** `urw_unq_start` (start), `urw_hol_*` (caves), `urw_gng_*` (transitions;
  `urw_gng_001…045_` are wood templates); connection points live in `data/Templates/*.ent`.
- **Animation rate:** the original's controller emits **10 frames per game second**
  (`controller_frames_per_game_second` = 10.0, `0x007373F0`). The 12 fps value used here is
  a port adapter.
- **Height grid:** 8 units per cell (8×8 samples per cell), `GetHMap` → `ROUND(x*8.0)`.
- **Coordinates:** PMP is columns/rows with Y pointing down; Tcl is `(x, y, logical_z)`;
  3DB is `(local_x, local_y, render_z)` where `render_z = 7 + logical_z/2`.
- **Chapter map:** 512×640 cells, assembled into `godot/models/native_campaign_chapter.json`.

Details are in `docs/reverse-engineering/` (by EXE address) and `docs/research/`
(public sources).

### Map navigation: four different grids

Mixing grids up is the most common source of wrong edits. In short:

| Grid | Step | Confirmed by |
|---|---|---|
| Map cell | 1:1 with Tcl | `FUN_00592f10`, bounds `map->0x84..0x90` |
| Height / sample | 8 units per cell (8×8 samples per cell) | `GetHMap`, `FUN_004093f0` |
| Edges / rim | 4 units per cell | `FUN_005fa510`, `FUN_005fd060` |
| Map object | twice the size of the playing field | `map->0x74/0x78`, `0x7c/0x80` |

Height (a `level` byte, 0…15) and world Z are related by `world-Z = 7.0 + 0.5 × level`.
Walkability lives in a separate parallel flag array (`cell+0x3C`, 64 bytes per cell), not in
a copy of the height data: bit `0x01` — walkable, `0x02` — step/floor, `0x04` — object or
ladder.

**The rule:** "the original cached flags must never silently survive excavation" — an
original walkability flag must never quietly outlive the excavation that invalidated it.

The reasoning behind this is in `docs/PROJECT_GUIDE.md` §3.

## Documentation

| Document | About |
|---|---|
| `PROJECT-MAP-2026-11-21.md` | the full map of the project: trees, duplicates, branching, state |
| `docs/PROJECT_GUIDE.md` | the project dictionary: terms, map grids, subsystem branches, how to phrase a task |
| `docs/plan/queue-2026-11-19.md` | **the source of truth for the work queue** and the plan |
| `docs/research/README.md` | index of the public-source research and the reading order |
| `docs/reverse-engineering/` | original analysis and a report per work block (`agent-result-*.md`) |
| `docs/review/` | integration reviews |
| `godot/README.md` | the reference scene and the coordinate system |

## Legal notice

This repository is private. It contains **reverse-engineering results** of a commercial game
and data, models and textures extracted from its resources. Rights to the original Diggles,
its assets, music and code belong to SEK GmbX / Innonics; the authors of this project claim
no rights over them. No licence is set on the project code here — use of the code is
limited to personal study.

Third-party code: `work/thirdparty/DigglesModManager/` is an external project (DigglesMods),
included as-is with its own LICENSE files; its authorship belongs to that project's
copyright holders.

## Tools

`tools/` holds 72 Python scripts: chapter export from the original data
(`export_campaign_chapter.py`), ground field building (`build_ground_field.py`), geometry
and texture audits, and the dwarf life-cycle page generator. `scripts/` holds 21 scripts for
test runs, patches and round-trip verification.

Dependencies: the Python standard library. Some audits need Python 3.11+; individual tools
read external data from the original game.

## Contributing

Commit messages and pull request descriptions are written in English. The documentation
under `docs/` is kept in Russian — new reverse-engineering notes follow the existing style
of those files.
