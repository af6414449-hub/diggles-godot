# Original Diggles excavation trace

## SOURCE: confirmed in the installed original

- Installation: `C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris`.
- `z_dignwalk.tcl` calls `dig_next` and `dig_apply` from the Zwerg class. The original `userinit.tcl` is a different Tcl context: the 2026-11-25 startup trace reported `dig_execute_visible=""` and `digtrace_class_emit_visible=""` there.
- The first live test marked and excavated tunnels and a small cave, yet the v1 log contained only startup events. V1 did **not** observe user gameplay. After the v2 upgrade, a controlled startup produced `class_script_loaded`. Two subsequent user runs produced real `dig_next`, `dig_execute` and `dig_apply` events, including the excavation of a small cave. The archived evidence and measurements are in [original-dig-trace-2026-11-25.md](../../docs/reverse-engineering/original-dig-trace-2026-11-25.md).
- `dig_mark` and `cave_skin` are native Tcl commands, but ordinary UI marking may bypass their Tcl wrappers. Do not infer that a missing `dig_mark` line means the player did not mark a cell.

## ADAPTER: what this trace records

- `data/dig_trace.tcl` logs the global Tcl context and script calls to `dig_mark`/`cave_skin`.
- `dwarf_helpers.tcl` is inserted into the Zwerg class script. It logs class loading, calls to `dig_next`, entry into `dig_execute`, and each `dig_apply` result with a 3×3 grid of raw `get_hmap` values, original `get_material`, gnome position and nearby object references/classes/positions before and after the strike.
- After a successful strike it also schedules six `object_snapshot` events on the dwarf task queue. These snapshots capture delayed changes in object position or query visibility; they do not by themselves prove object creation. Each includes the nearby object list and raw heights.
- The JSONL file is `C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\diggles_dig_trace.jsonl`. The class stream closes the file after each event. It stops after 5,000 class events per process; the global stream stops after 10,000.
- `install.ps1` creates timestamped backups in `tools/dig_trace/backups/` before any game-script change. The existing fog/camera modifications and `Diggles.exe` are preserved. Run from the project root:

```powershell
python tools/dig_trace/verify.py
powershell -NoProfile -ExecutionPolicy Bypass -File tools/dig_trace/install.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File tools/dig_trace/install.ps1 -Install
```

The first PowerShell command is a read-only dry run. Use `-Upgrade` instead of `-Install` only if the v1 trace is already installed. Close Diggles before applying either change. The current installation was upgraded to v2 on 2026-11-25.

## UNKNOWN: limits and next observation

- The live runs confirm that `obj_query` exposes the original `Schatztonne`, `Dummy_Moos_hm_*` and `Dummy_Multi_Holzstuetze_*` classes near a strike. Cave frames or other renderer-only decorations may still be invisible to this query. An empty object list is not proof that those decorations were absent.
- `analyze.py` compares class and horizontal position because `obj_query` references can change across observations. Its `stationary_snapshot_transitions` list is a list of changes in query visibility, not a proven list of all native create/delete operations; even at a fixed actor position some moss entries fluctuate. Inspect surrounding raw events before claiming a creation or deletion.
- The installed class helper now also queries `Dummy_Urw_caves_*` and `Dummy_Wurzel_*` near each strike. The cave-skin classes are registered by the original `dummy_auskleidung.tcl`; the extra query tests whether native frame instances are visible to Tcl and captures their positions if so. `update_snapshot_classes.ps1` makes a backup before updating the original installation.
- On the first observation of each class plus horizontal placement, the helper emits `object_surface` with that object's 3×3 `get_hmap` neighborhood. This lets the same run compare supports, moss, roots, and cave frames with the actual terrain below them without repeatedly sampling every object on every strike.
- The analyzer's `same_ref_z_movements` reports repeated observations of one object reference at nearly unchanged XY with changed Z. It has captured real rise sequences of roots, supports and moss. Timestamp resolution is one second, so the sequence alone does not establish frame duration.
- `match_template_placements.py ARCHIVED_JSONL` matches live support, moss, and root positions to the installed `urw_gng_*`, `urw_hol_*`, and `urw_unq_start` Tcl declarations at four-cell offsets. The latest archived session matched 21/21 observed placements (19 unambiguous). It does not establish when an instance was created. The original `Campaign.tcl` loads whole templates while building the chapter; `CMapBeautifier::ScanAtPos` selects visual map details, not Tcl templates.
- The Tcl trace does not yet record the native UI cave placement validator's accepted/rejected decision. If the v2 strike trace cannot explain the cave alignment or frame/support rule, locate and instrument that specific native path instead of inventing a Godot heuristic.
- For a new capture, start the original, load a save, mark the desired tunnel or cave, wait for a gnome strike, exit normally, then run `python tools/dig_trace/analyze.py` or pass an archived JSONL file as its argument. Preserve raw coordinates and Tcl list strings; no Godot coordinate conversion is assumed.
