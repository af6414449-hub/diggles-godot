extends SceneTree
## The self-test of the dwarves of the campaign chapter.
##
## The checks are deterministic: the test builds its own map of blocks and
## drives the clock of the dwarves by hand. The clips, the frames and the
## sockets of the model come from the files of the original, so the test reads
## them unchanged.

const DWARF: Script = preload("res://scripts/native_campaign_dwarf.gd")
const DIG: Script = preload("res://scripts/native_campaign_dig_test.gd")
const NORMALS_PATH: String = "res://models/native_model_material.json"

## The first cell of the test and the cell of the order of the walk.
const START_CELL: Vector2i = Vector2i(10, 10)
const WALK_CELL: Vector2i = Vector2i(14, 10)
const DIG_CELL: Vector2i = Vector2i(12, 10)
## The step of the clock of the test.
const STEP: float = 1.0 / 60.0


class FakeProfile:
	extends RefCounted
	## The profile of the terrain of the test map: every cell is earth, so
	## every cell of the map can be dug.
	var data: Dictionary = {"normals": []}

	func cell_material(_cell: Vector2i) -> int:
		return 2
	func ground_file(_cell: Vector2i, _variant: int) -> String:
		return "Gnd_A01.tga"
	func detail_texture(_cell: Vector2i, _part: int) -> String:
		return "50PGray.tga"
	func detail_slot(_detail: String) -> Vector2:
		return Vector2.ZERO
	func terrain_material(_variant: int, _a: bool, _b: bool, _file: String, _c: bool,
			_dir: String, _d: bool) -> Material:
		return StandardMaterial3D.new()
	func terrain_channels(_cell: Vector2i, _local: Vector3, _normal: Array,
			_sky: float) -> Dictionary:
		return {"diffuse": Color.WHITE, "secondary": Color(0.0, 0.0, 0.0, 1.0)}


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var root := Node3D.new()
	root.name = "CampaignRenderSpace"
	get_root().add_child(root)
	var camera := Camera3D.new()
	camera.name = "ChapterCamera"
	camera.current = true
	camera.fov = 38.0
	camera.near = 0.05
	camera.far = 3000.0
	root.add_child(camera)
	var hud := CanvasLayer.new()
	get_root().add_child(hud)
	var label := Label.new()
	hud.add_child(label)
	var dig: RefCounted = DIG.new()
	var profile := FakeProfile.new()
	profile.data["normals"] = _normal_table()
	dig.setup(root, camera, profile, [], {}, hud, label)
	var dwarfs: RefCounted = DWARF.new()
	dwarfs.setup(root, camera, dig, profile, label)

	var dwarf := Node3D.new()
	dwarf.name = "Zwerg_000"
	# The transform of a dwarf of the chapter: the feet on the cell of the
	# placement and the front of the sprite along the row of the board.
	dwarf.transform = Transform3D(Basis(Vector3(0.0, 0.0, 1.0), Vector3(0.0, 1.0, 0.0),
		Vector3(-1.0, 0.0, 0.0)), Vector3(float(START_CELL.x) + 0.5,
		-float(START_CELL.y) - 0.5, 15.0))
	var body := MeshInstance3D.new()
	var box := BoxMesh.new()
	box.size = Vector3(0.7, 1.0, 0.6)
	body.mesh = box
	dwarf.add_child(body)
	root.add_child(dwarf)
	dwarfs.register_dwarf(dwarf)
	# The camera of the native view: on the normal of the board, tilted.
	var focus := Vector3(dwarf.position.x, dwarf.position.y, 15.0)
	camera.position = focus + Vector3(0.0, sin(0.29), cos(0.29)) * 30.0
	camera.look_at(focus)

	_check_model_clips(dwarfs)
	_check_selection(dwarfs, camera, dwarf)
	_check_lower_platform_pick(dwarfs, camera, dwarf)
	_check_walk(dwarfs, dwarf)
	_check_dig(dwarfs, dig, dwarf)
	_check_dig_chain(dwarfs, dig, dwarf)
	_check_hat(dwarfs, dwarf)

	print("CAMPAIGN_DWARF_TEST_OK clips=1 selection=1 walk=1 turn=1 dig=1 strike=1 "
		+ "torch=1 hat=1")
	quit(0)


## The clips of the model of the original: the locomotion of the manifest of
## the chapter and the clips of the digging of the model file of the original.
func _check_model_clips(dwarfs: RefCounted) -> void:
	var sequences: Dictionary = dwarfs.get("_sequences")
	assert(sequences.has("gehen_start"))
	assert(sequences.has("gehen_loop"))
	assert(sequences.has("gehen_end"))
	assert(sequences.has("laufen_schnell_loop"))
	assert(sequences.has("drehen_ganz_links"))
	assert(sequences.has("stand_anim_a"))
	assert(sequences.has("stand_anim_b"))
	assert((sequences["gehen_start"] as Array).size() == 3)
	assert((sequences["gehen_loop"] as Array).size() == 10)
	assert((sequences["gehen_end"] as Array).size() == 4)
	assert((sequences["stand_anim_a"] as Array).size() == 13)
	assert((sequences["buddeln_unten"] as Array).size() == 13)
	assert((sequences["buddeln_vorn"] as Array).size() == 13)
	assert((sequences["buddeln_oben_normal"] as Array).size() == 13)


## The selection of a dwarf by the click on the sprite.
func _check_selection(dwarfs: RefCounted, camera: Camera3D, dwarf: Node3D) -> void:
	var screen: Vector2 = camera.unproject_position(dwarf.global_position + Vector3(0.0, 0.5, 0.0))
	assert(dwarfs.dwarf_at_screen(screen) == dwarf)
	assert(dwarfs.dwarf_at_screen(screen + Vector2(400.0, 400.0)) == null)
	dwarfs.call("_select_dwarf", dwarf)
	assert(dwarfs.selected() == dwarf)
	assert((dwarf.get_node("SelectionSilhouette") as MeshInstance3D).visible)


func _check_lower_platform_pick(dwarfs: RefCounted, camera: Camera3D,
		dwarf: Node3D) -> void:
	var original: float = dwarf.position.z
	dwarf.position.z = 12.0
	var world_point := Vector3(15.5, -12.5, 12.0)
	var screen: Vector2 = camera.unproject_position(world_point)
	var picked: Variant = dwarfs.call("_map_point", screen)
	assert(picked is Vector2)
	assert((picked as Vector2).distance_to(Vector2(15.5, 12.5)) < 0.02)
	dwarf.position.z = original


## The order of the walk: the turn of the dwarf, the walk and the arrival.
func _check_walk(dwarfs: RefCounted, dwarf: Node3D) -> void:
	dwarfs.call("_assign_walk", dwarf, WALK_CELL)
	assert(dwarfs.dwarf_walk_actions.has(dwarf))
	var walk: RefCounted = dwarfs.dwarf_walk_actions[dwarf]
	# The dwarf faces the left of the board, the order is to the right: the
	# turn is a full one.
	assert(String(walk.state).begins_with("drehen_"))
	var frames: int = 0
	while dwarfs.dwarf_walk_actions.has(dwarf) and frames < 600:
		dwarfs.advance(STEP)
		frames += 1
	assert(not dwarfs.dwarf_walk_actions.has(dwarf))
	assert(dwarf.position.x > float(WALK_CELL.x) - 0.6)
	assert(dwarf.position.x <= float(WALK_CELL.x) + 0.5)
	assert(absf(dwarf.position.y + float(WALK_CELL.y) + 0.5) < 0.6)
	assert(absf(dwarf.position.z - 15.0) < 0.01)
	# The front of the sprite follows the direction of the walk.
	var front: Vector3 = dwarf.transform.basis.z
	assert(front.x > 0.9)


## The order of the digging: the dwarf walks to the cell, digs it and the
## excavation of the chapter opens the cell.
func _check_dig(dwarfs: RefCounted, dig: RefCounted, dwarf: Node3D) -> void:
	dig.call("_mark_corridor", [DIG_CELL] as Array[Vector2i])
	assert(dig.is_marked(DIG_CELL))
	assert(dig.mark_target_level(DIG_CELL) == 11)
	var level_before: float = dig.cell_level(DIG_CELL)
	dwarfs.call("_assign_dig", dwarf, DIG_CELL)
	assert(dwarfs.dwarf_dig_jobs.has(dwarf))
	var frames: int = 0
	while dwarfs.dwarf_dig_jobs.has(dwarf) and frames < 900:
		dwarfs.advance(STEP)
		frames += 1
	assert(not dwarfs.dwarf_dig_jobs.has(dwarf))
	# The cell of the mark is dug: the floor of the cell is at the level that
	# the mark of the tunnel asks for.
	assert(dig.cell_level(DIG_CELL) < level_before)
	assert(dig.cell_level(DIG_CELL) == 11.0)
	assert(not dig.is_marked(DIG_CELL))
	# The dwarf lights the passage that he opened.
	assert(dwarfs.torch_nodes.has(DIG_CELL))


func _check_dig_chain(dwarfs: RefCounted, dig: RefCounted, dwarf: Node3D) -> void:
	var first := Vector2i(13, 10)
	var second := Vector2i(14, 10)
	dig.call("_mark_corridor", [first, second] as Array[Vector2i])
	assert(dig.is_marked(first) and dig.is_marked(second))
	dwarfs.call("_assign_dig", dwarf, first)
	assert(dwarfs.dwarf_dig_jobs.has(dwarf))
	var continued: bool = false
	for frame: int in range(1500):
		dwarfs.advance(STEP)
		if not dig.is_marked(first) and dig.is_marked(second):
			continued = dwarfs.dwarf_dig_jobs.has(dwarf)
		if not dig.is_marked(second):
			break
	assert(continued)
	assert(not dig.is_marked(first) and not dig.is_marked(second))
	assert(not dwarfs.dwarf_dig_jobs.has(dwarf))


## The table of the normals of the original: the excavation of the chapter
## draws the rock of the dug cells with it.
func _normal_table() -> Array:
	var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(NORMALS_PATH))
	if not parsed is Dictionary:
		return []
	return (parsed as Dictionary).get("normal_table", [])


## The hat of the miner: the socket of the model of the original and the lamp
## of the battle scene, which burns while the dwarf digs.
func _check_hat(dwarfs: RefCounted, dwarf: Node3D) -> void:
	var hat: Node3D = dwarf.get_node_or_null("muetze_stein_a")
	assert(hat != null)
	var pickaxe: Node3D = dwarf.get_node_or_null("spitzhacke")
	assert(pickaxe != null)
	assert((hat.get_node("MinerHelmetLight") as OmniLight3D) != null)
