# Visual reference: `demo_start`

Date: 2026-11-15. The user supplied three screenshots of the same start cave at different camera angles; copies are in `reference-images/`.

## What the reference establishes

- The scene is a side-readable cave with real 3D depth. Camera rotation changes visible wall/floor geometry and occlusion; a single flat cutaway cannot reproduce all three views.
- The cave has a continuous irregular rock ceiling, rear wall, floor and front edge. A dark opening continues the cave to the right.
- Mushrooms, moss, roots, plants, supports, torches, containers and dwarves occupy distinct positions and depths. They are integrated into the cave, not scattered as a flat sprite strip.
- Original lighting includes a bright overhead source, smaller warm wall lights and deep shadow outside the lit playable area.
- The screenshots show that the user’s first playable scope can be checked against a concrete original scene without needing a save file.
- The three attached views are a single cave viewed from a side angle, a rotated angle, and a higher angle. The change in the visible right-hand exit, rear wall, floor edge, roots, and foreground ledge confirms that this is real camera parallax over volumetric geometry, not a fixed side image. The bright central structures and crystal-like blocks also sit at distinct depths; they should not be laid out as one flat row.
- The latest close reference resolves the enclosure: the player camera looks into the occupied cave volume; the roof curves over the camera and toward the foreground, while the lit rear wall stays behind the central lamp. The stump and two mushrooms anchor the front-left; the timber support and fire belong on the right at different depths. A view that reads the roof as a rear slope has its depth orientation wrong, even if the left/right object order looks plausible.

## Current Godot comparison

Active captures: `flag-standards-final/` (three angles and runtime `scene_space.json`). The scene includes 2,800 original terrain triangles, 70 mapped placements, 49 representative meshes and 47 original textures. Ground material is still diagnostic gray. The user confirmed the corrected cave composition and placement as a 100% match except for two missing flags. Those two remaining standards are now reconstructed from `trollhausen.3db::fahne_a` and `Trollh_Wandschmuck_c_256.tga`; their final visual acceptance remains pending.

The static `Templates/demo_start.tcl` does not instantiate the two visible standards. Their source class and mesh exist in `dummy_trollhausen.tcl` and `trollhausen.3db`. `demo_start_runtime_supplement.json` records this distinction instead of pretending they came from the static template. The flags are anchored by their top edge because the original mesh extends in positive native Y; placing their origin at floor level hid them below the cave floor. Source vertex brightness is applied to these cloth meshes so the original red atlas is not overexposed by the reconstructed lamp.

The old claim that BDB Z is physical vertical was wrong. The collision routine samples a depth field over side-map X/Y. The native terrain emitter adds the cell column/row to BDB X/Y without swapping Y/Z. It leaves packed Z untouched. Logical emission uses `render_z=7+logical_z/2`; the inverse also exists in the EXE. See `bdb-axis-evidence-audit.md` for verified addresses and bytes.

The corrected scene uses logical `(x,-y,z)` and then applies the native depth packing once to the complete scene. The previous X mirror is removed. BDB floor block 2601 lies at map Y=10.5, exactly the floor-level Tcl placements. Both source torches at Z=1.01 sit just in front of wall depth 1, giving 0.005 render units clearance. `scene-space-audit.json` records 531 matching corner depth checks and 12 independent floor cells. This corrects the space mismatch; arbitrary per-object Z shifts are unnecessary.

BDB byte attributes index 256 normals in the original `sphere.dat`; they are no longer treated as unknown material/visibility flags. All three parts remain enabled. Part 0 contains the inner wall as well as the outside sheet; deleting it to remove a previous gray curtain would remove real cave geometry. The original floor/ceiling connections in parts 1/2 are retained.

The earlier castle arches came from another identified bug: 3DB named objects point to animation indices, which point to mesh frames. The importer now follows that chain. `Multi_Moos_Mix_uh_3` resolves animation 17 to mesh 34, instead of drawing castle mesh 17. Feuerstelle uses `brennt`, Zelt uses a representative `zelt_a`, and Zwerg uses a static `mann.standard` representative. This does not evaluate the full class runtime.

All captures from `animation-index-corrected/`, the mirror experiments and `depth-axis-rollback/` predate the native coordinate correction. They remain historical evidence of failed assumptions. Compare against `native-scene-space/` now.

## Template-file correction

There are two files named `demo_start.tcl`. `Templates/tcl/demo_start.tcl` contains the `hol_024.pmp` declaration and object placements but no layer command. `Templates/demo_start.tcl`, the editor-loadable wrapper, contains the same placements plus `map_setlayer2 ... demo_start.l2m`. The referenced `data/Templates/demo_start.l2m` is absent in the installed game directory. The scene manifest now records the wrapper script, 76 literal declarations, 64 mesh placements and four additional light-only placements. Do not claim the missing L2M supplied the textures seen in the reference screenshots.

## Validation

- Native EXE bytes, BDB corner metadata, floor strips and source wall torches are checked by `tools/audit_scene_space.py` and recorded in `scene-space-audit.json`.
- Exported sphere.dat contains 256 unit normals. All 2,800 source triangles remain present.
- Godot script parsing and fixed three-angle rendering are checked after changes. Final capture produced all three PNG files; `audit_scene_space.py` passes 531 corner checks, 12 floor cells, two wall torches, 256 normals and 70 runtime placements.
- Model textures use the highest-resolution installed same-named variant, rather than the first Gray/m032 filename match.
