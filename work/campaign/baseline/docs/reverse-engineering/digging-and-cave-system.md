# Digging, cave blueprints and finished lining

Updated: 2026-11-16. This document separates behavior proved by installed Tcl/3DB/PMP files from behavior that remains inside `Diggles.exe`.

## Confirmed player tools

The game exposes five digging brushes through owner attributes `digenable0..4`.

- Brush `0` is the free corridor/tunnel tool. The tutorial enables it first at `Scripts/classes/story/Trigger_Tutorial.tcl:854`, waits for the tunnel to be marked and dug, then disables it at line 937.
- Brushes `1..4` are four fixed cave tools. The tutorial enables brush `1` at line 938 and then waits for `cavemarked`.
- Brushes `2`, `3`, and `4` unlock at stone experience `0.15`, `0.30`, and `0.70`, respectively (`z_dignwalk.tcl:185-203`, `techtreetunes.tcl:1355-1361`).

This confirms the user's distinction: a corridor is not the same operation as a cave. The four exact player-brush masks have now been recovered from the original files loaded by the native `DigMark.cpp` code.

## Exact player cave brushes

The `DigMark` singleton constructor at preferred VA `0x5661C0` loads these original files:

- `data/templates/cave0.tga`
- `data/templates/cave1.tga`
- `data/templates/cave2.tga`
- `data/templates/cave3.tga`

Each image is `32 × 32` RGBA. The constructor transforms every source byte with `(value + 32) >> 6`. The marking loop at `0x567CB0` reads the red component, ignores value `4`, and passes values `0`, `1`, or `3` to the native single-cell cave marker at `0x5671A0`. It anchors the mask 16 cells left and 32 cells above the selected point, so the bottom centre of the mask is the cursor anchor.

`E` below is native value `3`, the four connection/entrance cells. Spaces are native value `4` and are skipped.

```text
brush 1: 34 interior + 4 entrance, 10 × 5 active bounds
   1111
  111111
 11111111
E11111111E
E11111111E

brush 2: 54 interior + 4 entrance, 14 × 5 active bounds
   00000000
  0000000000
 000000000000
E000000000000E
E000000000000E

brush 3: 132 interior + 4 entrance, 18 × 9 active bounds
    0000000000
   000000000000
  00000000000000
 0000000000000000
 0000000000000000
 0000000000000000
 0000000000000000
E0000000000000000E
E0000000000000000E

brush 4: 124 interior + 4 entrance, 14 × 12 active bounds
     0000
    000000
   00000000
  0000000000
 000000000000
 000000000000
 000000000000
 000000000000
 000000000000
 000000000000
E000000000000E
E000000000000E
```

The untouched TGAs, enlarged previews, exact 32 × 32 arrays and extraction metadata are in `docs/reverse-engineering/player-cave-brushes/brushes.json`. They can be regenerated with `python tools/extract_cave_brushes.py`.

## Native marking modes visible from Tcl

`dig_mark` is used in three modes:

| Call | Proven Tcl role |
| --- | --- |
| `dig_mark owner x y 0 layer` | shaped cave/depth mark |
| `dig_mark owner x y 1` | tunnel mark |
| `dig_mark owner x y 2` | remove mark |

The blue/green/red colors and the wobbling selection surface are not specified in Tcl; those visuals are native. The association of cave mode `0` with the observed blue marking and tunnel mode `1` with the observed green marking is supported by behavior but still needs a runtime/EXE trace for exact colors and shader motion.

## Three AI cave masks

`Scripts/ai/std_ai.tcl:2969-3005` contains three complete cave masks used by computer-controlled clans. Native tracing now proves that they reproduce the interiors of player brushes 1-3 exactly; the four value-3 entrance cells come from the player brush images and are absent from the AI Tcl loops. Brush 4 has no AI equivalent in the installed Tcl.

### AI subtype 0

- target heightmap value: `8`
- layer: `1`
- rows: `8, 8, 8, 6, 4`
- occupied points: `34`
- mask bounds: `8 × 5`

### AI subtype 1

- target value: `4`
- layer: `0`
- rows: `12, 12, 12, 10, 8`
- occupied points: `54`
- mask bounds: `12 × 5`

### AI subtype 2

- target value: `4`
- layer: `0`
- rows: `16, 16, 16, 16, 16, 16, 14, 12, 10`
- occupied points: `132`
- mask bounds: `16 × 9`

The AI starts from the largest mask that fits and downgrades when space is insufficient (`std_ai.tcl:2829-2890`). Materials `0` and `3` reject a candidate as rock. A cave is attached to an existing horizontal tunnel and uses a one-cell `cave_skin add subtype x1 y1 x2 y2` anchor, not a rectangle describing the entire cave (`std_ai.tcl:3013-3043`).

## AI tunnel construction

The AI analyses a coarse map with step `2`, then expands each selected coarse position to a `2 × 2` group of heightmap points. Horizontal and vertical proposals therefore produce a two-point-thick tunnel and target heightmap value `11.0` (`std_ai.tcl:2904-2967`).

Its documented world-map bits are:

| Bit | Meaning in `std_ai.tcl:2561-2618` |
| ---: | --- |
| 1 | tunnel-height cell |
| 2 / 4 | tunnel above / below |
| 8 / 16 | tunnel left / right |
| 32 | deeper/open area |
| 64 | flat platform condition |
| 128 | rock/forbidden material |

These rules prove path validity and target heights. Wall rounding, progressive rebuilding of the dug face, supports, torches, and the player's arbitrary corridor stroke remain native.

## Digging execution

Tcl controls the actor workflow while native commands own terrain mutation:

1. `get_digedge` selects a reachable edge.
2. `vector_fixdig` produces the work position.
3. `dig_next` selects the next marked point.
4. Tcl selects upward/front/downward animation from point height.
5. `dig_apply` mutates the terrain after the strike and may expose a resource.
6. The cycle repeats while another marked point remains reachable.

Evidence: `z_dignwalk.tcl:136-163`, `205-293`, and `295-382`.

Static tracing now identifies the actual one-strike terrain core at preferred VA `0x596B80`, called by the `dig_apply` Tcl wrapper at `0x634A13`. It validates the selected grid point, reads the active owner's layer from the dwarf, compares the current height against the mark target, replaces the four BlockDB cells sharing that grid corner, sets terrain-dirty flags, clears completed mark nibbles, schedules redraw regions and emits the falling-ground/resource side effects.

The four-bit mark nibble maps to exact target height as follows:

| Mark nibble state | Target height |
| --- | ---: |
| zero/unmarked fallback | `15` |
| nonzero tunnel-style mark (bit 8 clear; native tunnel nibble is `3`) | `11` |
| active value `0` | `0` |
| active value `1` | `3` |
| active value `2` | `7` |
| active value `3` | `11` |

Therefore the brush images have direct terrain meaning: brush 1's interior value `1` digs to height `3`; brushes 2-4 use interior value `0` and dig to height `0`; every brush's four value-`3` entrance cells target corridor height `11`. This independently explains the special entrance pixels and matches the AI's layer choices.

Original male animations in `mann.3db` include:

| Action | Animation | Frames |
| --- | --- | ---: |
| dig upward | `buddeln_oben_normal` | 13 |
| dig forward | `buddeln_vorn` | 13 |
| dig downward | `buddeln_unten` | 13 |
| front wood/metal/stone | `buddeln_vorn_holz/metall/stein` | 13 each |
| down wood/metal/stone | `buddeln_unten_holz/metall/stein` | 13 each |
| climbing strikes | `kletter_hack_oben/rechts/unten/links` | 10 each |

Accident variants contain 29 or 31 frames. Female equivalents exist in `frau.3db`. Sound events place upward/downward strikes at frames 3/5 and material effects at frame 8 (`z_soundinit.tcl:594-607`).

## Four finished cave sizes

The finished cave lining is not something the port needs to invent. It is stored in `data/3db/auskleidung.3db` and registered by `Scripts/classes/deco/dummy_auskleidung.tcl`.

`SetCaveSkinClasses` parses and registers three dimensions (`animinit.tcl:382-428`):

- world set: `Urw=0`, `Met=1`, `Kris=2`, `Golden=3`;
- fixed size: class-name `1..4` maps to native size `0..3`;
- detail suffix: final `a/b/c` maps to detail `2/1/0`.

The middle `a/b/c` component is an alternate geometry variant in the same set/size/detail pool; it is not consumed by the Tcl registration call.

The four matching source PMP templates are:

| Template | Grid |
| --- | ---: |
| `caves_1.pmp` | `12 × 8` |
| `caves_2.pmp` | `16 × 8` |
| `caves_3.pmp` | `20 × 12` |
| `caves_4.pmp` | `16 × 16` |

The corresponding environment templates `urw_caves_<size>_<variant>.tcl` place `Dummy_Urw_caves_*` objects over these PMP shapes. Equivalent `Met`, `Kris`, and `Golden` families are installed.

### Supports are integral geometry

Parsed Urwald cave meshes use both `Holz_Standard_a_256` and `trollh_4_wand_d`. Thus the wooden rafters that appear on completion are embedded in the original finished `urw_caves_*` mesh, not separate supports that should be guessed and manually positioned.

The first source exports are under `docs/reverse-engineering/cave-skins/` as OBJ/MTL plus their original textures for sizes 1-4. They are extraction evidence, not yet runtime Godot assets.

## Corridor decoration

Original procedural corridor templates exist as `urw_gng_*`, `swf_gng_*`, `kris_gng_*`, and `lava_gng_*`. Urwald layouts place `Dummy_Multi_Holzstuetze_a..i`, backed by `JoinedObjs.3db::Multi_Holzstuetze_a..i`. These models combine wood with moss, mushrooms, vines, or cobwebs.

These templates prove exact source models and example placements for generated corridors. They do not yet prove that the native post-digging system uses the identical template-selection policy.

The standard visible torch is known exactly:

- class: `Misc_Light`;
- model: `licht.3db::fackel`;
- light offset: `{0 -0.5 1.0}`;
- range: `6`;
- color: `{0.9 0.9 0.8}`;
- particle emitter type: `2`;
- wall snapping enabled.

Evidence: `Scripts/classes/items/emitter.tcl:3-10`. No `Misc_Light` placement occurs in the installed `*_gng_*` or `*_caves_*` Tcl templates, so automatic torch spacing after digging is native.

## Proven native boundary

The following command strings are present in `Diggles.exe` and have no Tcl implementation:

| Command | EXE file offset of string |
| --- | ---: |
| `add_cave_skin_class` | `0x32B968` |
| `cave_skin` | `0x32D244` |
| `dig_mark` | `0x32C754` |
| `dig_next` | `0x32C774` |
| `dig_apply` | `0x32C780` |
| `get_digedge` | `0x32C78C` |

Static cross-references identify the Tcl callback functions (preferred VA and RVA are shown because ASLR may relocate the module):

| Command | Preferred VA | RVA |
| --- | ---: | ---: |
| `add_cave_skin_class` | `0x617570` | `0x217570` |
| `dig_mark` | `0x6586C0` | `0x2586C0` |
| `dig_apply` | `0x6347A0` | `0x2347A0` |
| `dig_next` | `0x634B50` | `0x234B50` |
| `get_digedge` | `0x635180` | `0x235180` |
| `cave_skin` | `0x66A9A0` | `0x26A9A0` |

`dig_mark` dispatch is now proven:

- mode `0` calls `0x5671A0`, which writes one cave-mark nibble;
- mode `1` calls `0x5672D0`, which writes one tunnel-mark nibble after its validity test;
- mode `2` clears the selected layer's mark nibble directly;
- mark state is stored in four-bit fields, with bit `8` denoting an active dig mark and the lower bits carrying the target shape/depth value;
- owner data is stored in the corresponding nibble of the adjacent cell field.

`cave_skin` has two native subcommands:

- `cave_skin add subtype x1 y1 x2 y2` requires exactly seven Tcl objects, rounds the four coordinates to integers, and appends a record containing the rectangle and subtype to the world's cave list;
- `cave_skin rem x y` requires exactly four Tcl objects and removes the cave record found at the rounded map coordinate.

`add_cave_skin_class` is registered at callback `0x617570`, requires exactly four Tcl objects, and appends the class/size/detail registration to the same world subsystem. The reproducible command/call map is generated by `python tools/inspect_native_commands.py` into `docs/reverse-engineering/native-dig-command-map.json`.

### Proven completion chain

The `dig_apply` wrapper calls the one-strike terrain core at `0x596B80` and, after a successful mutation, enters the cave completion manager at `0x58BA00`. The manager walks the active `cave_skin add` records, evaluates their marked rectangle, selects a registered skin class through `0x58E9C0`, resolves the three detail pools through `0x58C336`, `0x58C369`, and `0x58C39C`, and creates the selected finished object at `0x58C450` with native ground height `z = 15`. The consumed pending record is then removed through `0x58C437 -> 0x58F2A0`.

This proves that finished caves are not assembled from guessed props. Digging mutates the terrain until the native completion predicate succeeds, then the engine replaces the pending rectangle with one of the registered `auskleidung` meshes. Their wooden rafters are integral mesh geometry, which explains why they appear only when the cave is complete.

The remaining unknowns that must be traced in the EXE/runtime are now:

1. corridor stroke validity/coloring details beyond the recovered checkerboard rasterizer;
2. the exact cave-completion predicate and alternate-variant choice inside the now-known completion chain;
3. tunnel support and torch placement/spacing;
4. exact selection colors, wobble parameters, and debris presentation.

## Porting consequence

The port can now import the exact four player brushes rather than approximating their silhouettes. The next implementation should combine those masks with all four Urwald cave-skin sizes and the original dig animations, then reproduce the visible Tcl state machine. Terrain mutation and the completion dispatch are no longer unknown; only the four narrower native policies above still require further reverse engineering.
