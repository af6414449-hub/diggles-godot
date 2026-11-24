extends RefCounted
## Shared harness for the walkmap performance work.
## Builds the native world exactly like godot/scripts/multiplayer_test.gd does:
## same terrain manifest, same mutable BlockDB package, same initial PMP RLE
## walkmap, same source world context, same height/gate callables.
## The harness never substitutes a plane or an A* grid for the native walkmap.

const STATE: Script = preload("res://scripts/native_terrain_state.gd")
const WALKMAP: Script = preload("res://scripts/native_walkmap.gd")
const WORLD: Script = preload("res://scripts/native_world_context.gd")

var terrain: Dictionary = {}
var terrain_state: RefCounted = null
var walkmap: RefCounted = null
var world: RefCounted = null
var terrain_cells: Dictionary = {}
var ok: bool = false


func build(walkmap_script: Script = WALKMAP) -> bool:
	terrain = JSON.parse_string(FileAccess.get_file_as_string("res://models/multi_start_010_terrain.json"))
	if not terrain is Dictionary:
		return false
	var facts: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/multi_start_010_tunnel_rules.json"))
	terrain_state = STATE.new()
	if not terrain_state.load_state("res://models/multi_start_010_mutable.json", terrain, facts):
		return false
	walkmap = walkmap_script.new()
	if not walkmap.load_map("res://models/multi_start_010_walkmap.json", terrain):
		return false
	world = WORLD.new()
	if not world.load_context("res://models/multi_start_010_world_context.json", "authored_2p", terrain):
		return false
	for cell: Dictionary in terrain.get("cells", []):
		terrain_cells[Vector2i(int(cell["x"]), int(cell["y"]))] = cell
	ok = true
	return true


func heights() -> Callable:
	# Mirrors multiplayer_test.gd:_native_height_sample.
	return func(sample: Vector2i) -> Variant:
		return terrain_state.surface_depth(Vector2(sample) * 0.125)


func gates() -> Callable:
	# Mirrors multiplayer_test.gd:_native_walk_gate.
	return func(cell: Vector2i) -> Variant:
		if terrain_state.cell(cell).is_empty() or not terrain_cells.has(cell):
			return null
		return int(terrain_cells[cell]["flags"]) & 0x80


func surface_cells() -> Callable:
	# Optional bulk accessor for the whole 8x8 surface block of one map cell.
	return func(cell: Vector2i) -> Variant:
		return terrain_state.cell_surface_samples(cell)


func sample_bounds() -> Rect2i:
	return world.local_sample_bounds()


func strike(point: Vector2i, slot: int, marks: int) -> Dictionary:
	return terrain_state.apply_accepted_step(point, slot, marks, true)
