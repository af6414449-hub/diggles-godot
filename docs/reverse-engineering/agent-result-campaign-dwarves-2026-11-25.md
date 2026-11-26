# The dwarves of the campaign chapter

> Исправление 26.11.2026: вывод о скорости `6.4887`, прямая линия как
> единственный путь и отсутствие лазания ниже описывают ошибочную первую
> версию. Проверенный патч и границы переноса маршрутов мультиплеера:
> `agent-result-campaign-dwarf-navigation-2026-11-26.md`.

**Block:** the control of the dwarves of the chapter, ported from the battle scene.
**Date:** 2026-11-25
**Files:** `godot/scripts/native_campaign_dwarf.gd` (new), `godot/scripts/native_campaign_dig_test.gd`
(public face of the excavation), `godot/scripts/native_campaign_first_level.gd` (the scene),
`godot/tools/native_campaign_dwarf_test.gd` (new self-test).

## 1. The scope

The battle scene (`scripts/multiplayer_test.gd`, 4236 lines) drives its dwarves with the native
streams of the model of the original. The chapter had no dwarves at all: the placements of the
class `Zwerg` were drawn as static models and nothing could be selected, ordered or animated.

The port keeps the streams of the model unchanged and writes the rules that belong to the map of
the battle scene for the board of the chapter.

## 2. The data that was carried over (SOURCE)

| What | Where it comes from | Notes |
|---|---|---|
| The clips of the walk, of the turn and of the idle stand | `res://models/native_campaign_models.json` → `objects["mann.3db::mann"]["locomotion"]` | 12 clips: `gehen_start` (3 frames), `gehen_loop` (10), `gehen_end` (4), `laufen_schnell_*`, `drehen_links`/`drehen_rechts`/`drehen_ganz_links`/`drehen_ganz`, `stand_anim_a` (13), `stand_anim_b` (7) |
| The clips of the digging | `res://models/dwarf_dig_action.json` | `buddeln_unten`, `buddeln_vorn`, `buddeln_oben_normal` (13 frames each), `adapter_fps` = 12.0 |
| The sockets of the pickaxe and of the miner hat | `res://models/dwarf_attachments.json` + `scripts/native_attachment.gd` | the assets `spitzhacke` (slot 0) and `muetze_stein_a` (slot 4) |
| The speed of the walk | `res://models/native_animation_timing.json` | `gehen_loop.slot_speed_world_per_game_second` = 0.8110876083374023 |
| The visual of the torch and its light | `res://models/native_torch_visual.json` | the light: rgb 0.9/0.9/0.8, range 6 |
| The flame of the torch | `res://models/native_flame.json`, class `Misc_Light` | the emitter of the original |

The battle scene keeps its locomotion in `multi_start_010_models.json`; the chapter carries the
same block in its own manifest, so nothing had to be exported again.

## 3. The measured facts of the board of the chapter

These are the facts the rules of the port are built on. They were measured, not assumed.

1. **The board.** The map lies in the XY plane of the scene, the level of a cell is its height
   along Z (`native_campaign_camera.gd`: "the map lies in the XY plane, the level of a cell is its
   height along Z"). The root of the scene packs that depth by 0.5
   (`RENDER_DEPTH_SCALE`), so the world Z of a cell is `0.5 * level + 7.0`: the flat ground of the
   map is the level 15 (world 14.5), the floor of a tunnel is the level 11 (world 12.5).

2. **The up axis of a dwarf is the screen vertical, not the normal of the board.** The model of
   `mann.3db::mann` spans 0.71 × 1.05 × 0.62 world units; the largest axis is the Y of the model
   space, and the socket of the hat (`muetze_stein_a`) sits at the local Y = +0.9975, the top of
   that span, while the socket of the pickaxe sits at +0.104, near the feet. The origin of a
   placement is therefore the feet of the dwarf and the body reaches one unit up the screen. A
   sprite of the board stands like that in the original too: all the dwarves of the start template
   carry the same rotation (`rotation[1]` = 4.71273), the dwarves of the voodoo templates another
   one (0.0).

3. **A dwarf of the board can face four ways.** The front of the sprite is its local Z; with the
   up along the screen vertical, a rotation around that up turns the front in the plane of the
   column and of the level. The port uses the four fronts of the board: along the row to the left
   and to the right, and towards the camera and away from it.

4. **The level of the cell of the placement.** The dwarves of the start template stand at the rim
   of the shaft of the chapter at the levels 11.98 … 12.78 (the origin is the head of the model,
   the feet are one unit below it), and the flat ground of the map is at the level 15.

5. **The speed of the walk (corrected 26.11).** The original clip specifies
   `0.8110876083374023` world units per game second. `0.125` is the distance
   between navigation samples, not a world-scale conversion. The earlier
   `6.4887` value was an error; the chapter now uses the clip speed directly.

6. **The rule of the clip of the digging.** The battle scene picks the clip of the digging by the
   height of the cell of the worker against the cell of the dig (`z_dignwalk.tcl:388-420`): more
   than 1.6 above → `buddeln_oben_normal`, more than 0.6 → `buddeln_vorn`, otherwise
   `buddeln_unten`. On the board the height of the target on the screen is the distance of the
   rows of the map (the vertical of the screen) minus the lean of the level towards the camera
   with the tilt of the native view (`Campaign.tcl:10`, rx = -0.29):
   `height = (row_dwarf - row_cell) * cos(0.29) - (level_cell - level_dwarf) * sin(0.29)`.

## 4. The rules of the port (ADAPTER)

| Rule | What the port does | Why |
|---|---|---|
| The selection | The dwarf under the pointer is found by the box of its mesh on the screen, the nearest centre wins (`multiplayer_test.gd:_object_at_screen`) | the same rule as the battle scene, and it needs no navigation grid |
| The outline | One merged mesh of the body of the sprite, drawn with the outline shader of the battle scene | an overlay per part would draw a seam around the beard and the helmet |
| The path of the walk | The straight line between the cell of the dwarf and the cell of the order; the order is refused when a cell of the line carries another level | the chapter has no `AStarGrid2D` and no `native_walkmap`; the dwarves walk on the flat ground and in the tunnels of their own level, they do not climb the slopes of the chapter yet |
| The heading | The front of the sprite follows the direction of the walk over the four fronts of the board | the sprite of the board stands along the screen vertical, so it cannot be yawed in the plane of the board |
| The order of the digging | A marked cell within the reach of the dwarf (3 cells) is dug by the dwarf: he walks to a free cell next to it, plays the clip of the digging and one clip is one strike of the cell | the battle scene has the same rule (the reach of 3 cells and the strike at the end of the clip) |
| The strike | `native_campaign_dig_test.gd:apply_dwarf_strike()` opens the cell with the own step of the excavation of the module and clears the mark when the cell reached its target depth | the rules of the excavation stay in one place; the cell leaves the queue of the automatic excavation, so the two clocks never strike the same cell |
| The torch of the excavation | Every cell that a dwarf opens gets the visual of the torch of the original, its light and its flame | the battle scene ties its torches to the light model of the native world (`TORCH_RUNTIME`); the chapter has no such model, so the torch of the excavation is the simple form of the same thing |
| The light of the frames | The frames of the clips are lit by the world model path of the chapter, like the models of the chapter | otherwise a dwarf would change its tone the moment it starts to walk |
| The input | A click on a dwarf selects it, a click on a marked cell orders the digging, a click on the free ground orders the walk while no tool of the excavation is armed | the tool of the excavation keeps the priority over the walk, so a tunnel can still be marked |

## 5. The verification

`godot/tools/native_campaign_dwarf_test.gd` (`CAMPAIGN_DWARF_TEST_OK`) checks:

* the clips of the model: the twelve clips of the locomotion with their frame counts and the three
  clips of the digging with their thirteen frames;
* the selection: the dwarf is found at the click on its sprite and nothing is found far away;
* the walk: the order starts a full turn (`drehen_*`), the dwarf walks, arrives at the cell of the
  order on the level of the cell, and the front of the sprite follows the direction of the walk;
* the digging: the mark of the cell asks for the level 11, the dwarf walks to the cell next to it,
  the clip `buddeln_vorn` plays, the strike opens the cell down to the level 11, the mark goes
  away and the torch of the passage appears;
* the hat: the sockets of the hat and of the pickaxe of the model of the original are on the dwarf,
  with the lamp of the battle scene.

The scene itself was run headless (`--quit-after 90`): the chapter builds and reports
`CAMPAIGN_DWARFS_READY dwarves=5`.

## 6. The known limitations

* In this first version dwarves could not climb and used a straight line.
  The 26.11 correction adds the source surface clips and the multiplayer route;
  see `agent-result-campaign-dwarf-navigation-2026-11-26.md` for its limits.
* The reach of the digging is the reach of the original (3 cells), so a cell of a tunnel has to be
  reached with the walk before it can be dug.
* The light of the frames of the clips is the light of the placement of the first dwarf; the
  dwarves of the chapter stand in the same clearing, so the difference is not visible.
* The automatic torches of the battle scene (a torch that follows every dwarf) are not ported: the
  light model of the native world has no counterpart in the chapter.
