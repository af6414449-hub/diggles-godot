# Dwarf selection and locomotion evidence

## Source-backed command flow

- `data/Scripts/init/eventgen.tcl:17-40,149-158` returns the contextual action `select` for a hovered friendly object and `walk` for the alternate world action. The engine owns the final selection rendering.
- `data/Scripts/classes/zwerg/z_events.tcl:333-362` clears the current work, queues `walk_pos`, and treats a repeated command within three world units as fast movement.
- `data/Scripts/classes/zwerg/z_dignwalk.tcl:590-604` applies native `vector_fix`, passes `-forcetarget 0`, and invokes the native `action this walk` pathfinder. The prior Godot plane tween skipped all three safeguards.
- `data/Scripts/classes/zwerg/z_dignwalk.tcl:910-935` treats walk result `4` as success and every other callback result as failure. `genericfight.tcl:878` identifies result `2` as `WS_NOTFINISHED`.
- `data/Scripts/classes/zwerg/z_anims.tcl:23-71,1278-1306` maps normal walking to `mann.gehen_start`, `mann.gehen_loop`, and `mann.gehen_end`, with separate turn, climb and fast-run states.

## Original model data

`data/3db/mann.3db` contains the exact normal-walk frame sequences now exported to Godot:

| Sequence | Frames | Mesh indices | Stored movement vector |
| --- | ---: | --- | --- |
| `gehen_start` | 3 | 59-61 | `(0, -16.221752, 0)` |
| `gehen_loop` | 10 | 62-71 | `(0, -16.221752, 0)` |
| `gehen_end` | 4 | 72-75 | `(0, -16.221752, 0)` |

The native time unit is not established, so version 0.4.0 keeps the original frame order but uses a temporary 10 fps playback rate and 1.2 logical units/second. Fast movement preserves the source 3DB root-motion ratio `34.286724 / 16.221752 = 2.113626`. The absolute timing values remain calibration targets, not claimed native constants.

## Current faithful boundary

The reconstructed `demo_start` floor is independently established at source Y `10.5`; the visible cave floor and placements span X/Z. Version 0.4.0 replaces the temporary one-dimensional strip with a scene-specific X/Z navigation grid that:

1. intersects taps with the actual floor plane at logical Y `-10.5`;
2. accepts the visible cave floor bounds X `4..23.5`, Z `1..15`;
3. snaps occupied targets to the nearest free grid cell, matching the role of native `get_place`;
4. routes around the stump, tent, columns, supports, mushrooms, bales and barrels with A*;
5. turns the dwarf toward path segments with original `drehen_*` frames;
6. uses `gehen_start/loop/end`, or `laufen_schnell_start/loop/end` after a repeated nearby command;
7. reports result `4` only on arrival.

This removes flight below the floor and commands through cave walls without pretending that the still-native, dynamic Diggles pathfinder has already been decoded. Full tunnels require a mutable cell graph with floor/climb/ladder/swim edges.

## Selection evidence and limitation

`selection clear/include/check`, `set_selectedobject`, `is_selected`, and independent `set_selectable`/`set_hoverable` flags are present in Tcl. No universal selection-ring model, texture, color, outline shader, or wobble parameters exist in `data`; the visual effect is native EXE behavior. `Interface.3db::krake_select` is the Krake character model, not a selection marker.

Version 0.4.0 removes the unsupported blue floor oval and uses a mobile-safe white inverted-hull outline on the selected friendly dwarf. White follows the supplied original-game observation; green assignment and red attack-target contexts are reserved in the interaction design but need buildings/enemies before they can be exercised.

Version 0.4.1 corrects two device-observed regressions. Pinch now owns the entire touch sequence and suppresses rotation until all participating fingers are released. Dwarf heading uses `S^-1 * R`, where `S=diag(1,1,0.5)` is the outer renderer depth packing, so the final global basis is the pure rotation `R` instead of the stretching transform `S * R * S^-1`.

Version 0.4.2 replaces the temporary PAN button and grace timer. One contact rotates immediately; two contacts suppress rotation and are classified once as pan or zoom from centroid motion versus span change. The selected mode is immutable until the gesture ends, preventing zoom/pan mixing caused by imperfect finger tracking. The default camera is orthographic so the already unit-length render basis is not visually distorted by perspective.

The same export now carries original `mann.3db` idle sequences: `stand_anim_a` has 13 frames and `stand_anim_b` has 7. Stationary dwarfs alternate between these sequences with phase offsets; locomotion still takes exclusive control while a dwarf moves.
