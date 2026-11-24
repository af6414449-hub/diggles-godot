extends SceneTree
## The opening map must contain only Campaign.tcl:first_level and its start.
const PROFILE = preload("res://scripts/native_campaign_profile.gd")
const GROUND = preload("res://scripts/native_campaign_ground.gd")
const CHAPTER_PATH: String = "res://models/native_campaign_chapter.json"

var checks: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _check(ok: bool, message: String) -> void:
	checks += 1
	if not ok:
		failures += 1
		printerr("FAIL: " + message)


func _run() -> void:
	var chapter: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(CHAPTER_PATH))
	var profile = PROFILE.new()
	_check(profile.load_chapter(CHAPTER_PATH), "chapter profile loads")
	var templates: Dictionary = {}
	var caves: int = 0
	for placement: Dictionary in chapter["placements"]:
		templates[str(placement["template"])] = true
		if str(placement.get("role", "")) == "cave":
			caves += 1
	var initial_cells: Array = []
	var initial_positions: Dictionary = {}
	for entry: Dictionary in chapter["cells"]:
		if bool(entry.get("story", false)):
			continue
		initial_cells.append(entry)
		initial_positions[Vector2i(int(entry["x"]), int(entry["y"]))] = true
	_check(templates.size() == 14 and caves == 2, "start template, two caves and their connections")
	_check(initial_cells.size() == 3447, "only the original first_level cells are active")
	profile.set_active_templates(templates)
	profile.set_active_cells(initial_cells)
	var light_data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(
		"res://models/native_campaign_lights.json"))
	var active_lights: int = 0
	for source: Dictionary in light_data["lights"]:
		if templates.has(str(source["placement_source"]["template"])):
			active_lights += 1
	_check(profile.terrain_lights.size() == active_lights and active_lights == 31,
		"story lights cannot reach the initial level")
	var story_material_cell: Vector2i = Vector2i(-1, -1)
	var story_detail_cell: Vector2i = Vector2i(-1, -1)
	for entry: Dictionary in chapter["cells"]:
		if not bool(entry.get("story", false)):
			continue
		var cell := Vector2i(int(entry["x"]), int(entry["y"]))
		if initial_positions.has(cell):
			continue
		var key: String = "%d,%d" % [cell.x, cell.y]
		if story_material_cell.x < 0 and (chapter["materials"] as Dictionary).has(key):
			story_material_cell = cell
		if story_detail_cell.x < 0 and (chapter["layer2"] as Dictionary).has(key):
			story_detail_cell = cell
		if story_material_cell.x >= 0 and story_detail_cell.x >= 0:
			break
	_check(story_material_cell.x >= 0 and story_detail_cell.x >= 0,
		"export contains deferred material and detail records")
	if story_material_cell.x >= 0:
		_check(int(profile.cell_material(story_material_cell)) ==
			GROUND.free_material(profile.ground_materials,
				story_material_cell.x, story_material_cell.y),
			"deferred cave material falls back to the original free map")
		_check(is_equal_approx(profile.cell_surface_level(story_material_cell),
			GROUND.MAP_GROUND_LEVEL), "deferred cave leaves the free surface intact")
	if story_detail_cell.x >= 0:
		_check(profile.layer2_word(story_detail_cell) == 0,
			"deferred cave detail is not painted on free rock")
	print("NATIVE_CAMPAIGN_INITIAL_WORLD_SELF_TEST checks=%d failures=%d" % [checks, failures])
	quit(0 if failures == 0 else 1)
