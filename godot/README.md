# Diggles scene reference

Godot 4.7.2 PC reference for `demo_start/hol_024`: 2,800 original terrain triangles, 70 mapped placements, 49 representative 3DB meshes and 47 original model textures.

Run `project.godot`. Drag to rotate/tilt, wheel to zoom, R to reset, O to switch projection. On touch: one finger rotates; two fingers lock to either pan or zoom after the initial motion is classified, and cannot mix modes until both fingers are released. Tap a dwarf to select it with the original-friendly white context color, then tap the cave floor. Dwarfs use an X/Z A* graph to route around the stump, tent, columns and props, turn toward path segments, and play original `mann` idle/turn/walk/run frame sequences. Full dynamic tunnel navigation and digging remain pending.

Multi-touch suppresses rotation until every finger is released. A 5 px threshold and directional dominance select pan or zoom once per gesture. Dwarf headings are applied through an inverse depth-packing basis, and the default orthographic camera removes perspective-dependent stretching at oblique angles.

## Coordinate spaces

PMP columns/rows are the side map X/downward Y. Tcl positions are `(x,y,logical_z)`. BDB vertices use `(local_x,local_y,render_z)` where `render_z=7+logical_z/2`; the native terrain renderer adds the cell column/row to the first two components. The reference unpacks BDB into logical space, maps Y downward to Godot -Y, then packs the entire scene Z once. No X or Z scene mirror is applied. Normal lookup indices refer to the original 256-vector sphere.dat table.

Native evidence: `../docs/reverse-engineering/bdb-axis-evidence-audit.md`. `python tools/audit_scene_space.py` from the repository root checks original EXE instructions, 531 corner values, the y=10.5 floor and both wall torches. Their logical depth 1.01 is 0.005 renderer units in front of the wall at logical depth 1.

`--capture-dir ABSOLUTE_PATH` saves three views plus `scene_space.json` with actual runtime positions/bounds. Current captures: `../docs/reverse-engineering/native-scene-space/`. Diagnostic options: `--terrain-part 0,1`, `--terrain-flags 2,4,132`, `--no-terrain`, `--no-objects`, `--terrain-double-sided`, `--terrain-cull-front`, `--camera-from-back`. Earlier global mirrors and Y/Z-swapped captures are obsolete.

Remaining concerns: source model scale/rotation convention, randomized variants, original terrain material/lighting, particle effects, actor animation and runtime changes to static declarations. The `android/` Java prototype is a separate diagnostic application.
