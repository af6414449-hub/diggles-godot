# Movement and original-file feedback — 2026-11-18

## Implemented and verified

- Fixed discarded movement budget at 1/8-cell waypoints. Both floor and surface executors consume the remaining distance instead of waiting until the next update. This disproportionately slowed running and sideways climbing.
- Replaced movement's 12 FPS / guessed .98 speed with source timing: 10 frames per game second, male walk .8110876083, run 1.7143362761 world units/game second. Wall speed uses the native mean of the four direction slots, separately for ordinary/fast clips. Source vectors and constants are exported reproducibly from mann/frau.3db and the SHA-256-pinned EXE.
- Surface floor heading now uses both X and rendered Z; pure depth movement updates heading. Removed gradual heading lag during translated floor motion. Wall-facing PI remains the original wall pose.
- Floor clicks raycast the actual terrain floor (layer 1, upward normal), preserving clicked depth. Original vector_fix normalizes XY. A host refinement spreads depth across the last flat floor stretch instead of deferring all Z until its endpoint. It checks source body clearance at each sample. This is not native Calc1 or a complete 3D pathfinder.
- Source vector_fix also replaces the old .8-unit click-radius approximation: known right-floor targets x30/35/40, y18.5 and nearby clicks y16/17.25 normalize and route successfully.
- Pick and stone work hat use original per-frame sockets (hand 0, head 4), packed 3DB attachment records, original meshes/textures and native Euler composition. They follow work frames and hide on cancellation/idle. No fitted hand/head offsets. Runtime male actor uses muetze_stein_a; palette selection and complete equip/put-away lifecycle remain future work.
- Added buddeln_oben_normal (13 source frames, z_anims.tcl:305); removed explicit upward-work rejection. This does not prove every vertical mark chain: get_digedge still lacks the original C+0x34 owner producer, and the host stance safety gate remains conservative.
- Hover outline appears on corridor/cave tool selection and pointer movement without pressing, snaps using existing original brush/selection data and does not commit marks. Geometry is extracted from outer-radius edges of the existing contour atlas; native outline-only rendering, stroke width/color and wave shader still need comparison. Committed mark fill is unchanged.

## Evidence and limits

Timing: `native-animation-timing-2026-11-17.json` contains 24 complete instruction spans with hashes; `godot/models/native_animation_timing.json` contains 14 clips per sex and original vectors. Source clock addresses include 0x462040, vec_a speed 0x42290E, wall mean 0x418E87. Fixed two unfinished exporter range ends to instruction boundaries. One Godot delta second is currently one game second. Live x87 mode, original render interpolation and external time-factor capture are not established. Finite digging actions still use their explicitly labeled 12 FPS adapter; movement now uses the recovered 10 FPS contract.

Attachments: `native-attachments-2026-11-17.txt`, `tools/export_dwarf_attachments.py`, additive `tools/inspect_3db.py`, `godot/scripts/native_attachment.gd`. Checked 1,926 samples, 288 independent scalar rotation fixtures, 1,776 asset vertices. Source package includes female sockets too; current runtime actors are male. Actual OpenGL frame: `work-attachments-2026-11-18.png` (work-start frame; vegetation partially occludes the body).

New regression `movement_feedback_self_test.gd`: 20 assertions, headless and OpenGL. Checks native run speed, full distance over multiple short nodes, early depth travel, pure Z heading, hover/no mark mutation, source upward clip, visible work tool/hat and cancellation. Surface walk 44, wall work 22 and excavated passage 37 assertions pass. All three scenes smoke-run without errors/warnings. Lint clean. Timing/dig/attachment exporters pass --check. APK not rebuilt.

Previous milestone: `excavated-walk-2026-11-17.md` — one assignment, four actual mutations, 64 newly navigable samples, actor enters 16 of them and returns from the new floor.

## Next work from the user's original-game observations

1. Compare actual motion visually in the right cave after this change, including back/front travel, descent and sideways climbing. Complete native Calc1, floor_snap and get_digedge before treating host path refinement as original behavior.
2. Selection: original outline-only pass, mixed-validity colors and oscillation. Keep hover separate from committed marks; do not animate terrain facts.
3. Lighting: compare source material/light attenuation/detail blend and fog with the supplied original screenshots. Existing nine native lamp placements are present, but Godot ambient/directional and attenuation remain adapters. Source rock/granite around authored caves must come from BDB/material/L2M, not screenshot-based recoloring; raw material 2 -> Gnd_C versus existing Gnd_B approximation remains a known discrepancy.
4. Dust/chips and complete work equipment lifecycle: recover source event/emitter timing and hat palette/skill rules. Current attachment work does not implement particles.
5. Background water: recover original texture/UV animation rather than add arbitrary wave amplitude/speed.
6. Multiplayer surrounding world: follow original map generation/template placement for the whole world. Imported 44x24 start template is not the generated battle map; authored 600x600 context supplies bounds/offset only.
7. Creature and dwarf AI: read classes/characters/hamster.tcl and original creature/worm definitions; dwarf schedule, work/idle, conversation clouds, sleep and needs are separate systems. Preserve the existing manual-action tests while porting state transitions. Do not call idle frame playback AI.

Both research agents stopped at the usage limit; partial source tools/data were reviewed, regenerated and tested locally. No active agent is required for this checkpoint.
