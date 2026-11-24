extends SceneTree
## Self-test of the Urwald campaign level generator.
##
## It checks the recovered `irandom` stream, the `Campaign.tcl:first_level`
## placement list against golden values, the determinism of the generator, the
## overlay of the geometry and the material layer, the player dwarves on the
## start template, the `Wuker` removal and the fog rectangle of the original
## campaign script.

const GENERATOR := preload("res://scripts/diggles_campaign_generator.gd")
const TEMPLATES := preload("res://scripts/diggles_campaign_templates.gd")
const COMPOSER := preload("res://scripts/diggles_campaign_composer.gd")
const SCENE := preload("res://scripts/diggles_campaign_scene.gd")
const RNG := preload("res://scripts/diggles_irandom.gd")

const GOLDEN_PATH: String = "res://models/campaign_urwald_first_level_golden.json"
const MANIFEST_PATH: String = "res://models/campaign_urwald_first_level.json"
const GOLDEN_SEEDS: Array[int] = [1, 4357, 123456789]

var _checks: int = 0
var _failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _check(condition: bool, message: String) -> bool:
	_checks += 1
	if not condition:
		_failures += 1
		push_error("CAMPAIGN_LEVEL_GENERATOR_SELF_TEST_FAILED " + message)
	return condition


func _run() -> void:
	var golden: Dictionary = _load_json(GOLDEN_PATH)
	var templates: TEMPLATES = TEMPLATES.new()
	if not templates.load_manifest(MANIFEST_PATH):
		_failures += 1
		push_error("CAMPAIGN_LEVEL_GENERATOR_SELF_TEST_FAILED manifest")
		quit(1)
		return
	_check(templates.is_loaded(), "manifest load")

	_check_rng()
	_check_generator(golden)
	_check_composition(templates, golden)
	await _check_scene(templates, golden)

	if _failures > 0:
		print("CAMPAIGN_LEVEL_GENERATOR_SELF_TEST_FAILED checks=%d failures=%d" % [_checks, _failures])
		quit(1)
		return
	print("CAMPAIGN_LEVEL_GENERATOR_SELF_TEST_OK assertions=%d templates=%d seeds=%d" % [
		_checks, templates.get_template_count(), GOLDEN_SEEDS.size()])
	quit(0)


func _load_json(path: String) -> Dictionary:
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(path))
	if not decoded is Dictionary:
		return {}
	return decoded


func _check_rng() -> void:
	# Golden draws of the native irandom stream, produced by the independent
	# Python reference implementation of Diggles.exe 0x49C670.
	var golden: Dictionary = _load_json(GOLDEN_PATH)
	for key: Variant in golden.keys():
		var seed_value: int = int(key)
		var entry: Dictionary = golden[key]
		var draws: Array = entry["draws"]
		var rng: RNG = RNG.new(seed_value)
		for index: int in range(draws.size()):
			_check(rng.next_u32() == int(draws[index]),
					"irandom draw %d of seed %d" % [index, seed_value])
	# The native command divides by its argument, so a limit of one is zero.
	var limiter: RNG = RNG.new(1)
	_check(limiter.irandom(1) == 0, "irandom(1) must be zero")
	for limit: int in [2, 3, 5, 8, 6, 4, 7]:
		var bounded: RNG = RNG.new(limit)
		for _step: int in range(32):
			var value: int = bounded.irandom(limit)
			_check(value >= 0 and value < limit, "irandom(%d) range" % limit)


func _check_generator(golden: Dictionary) -> void:
	for key: Variant in golden.keys():
		var seed_value: int = int(key)
		var entry: Dictionary = golden[key]
		var generator: GENERATOR = GENERATOR.new()
		var level: Dictionary = generator.first_level(208, 0, seed_value)
		var placements: Array = level["placements"]
		var expected: Array = entry["placements"]
		_check(placements.size() == expected.size(), "placement count of seed %d" % seed_value)
		var count: int = mini(placements.size(), expected.size())
		for index: int in range(count):
			var actual: Dictionary = placements[index]
			var reference: Dictionary = expected[index]
			_check(str(actual["template"]) == str(reference["template"]),
					"template %d of seed %d" % [index, seed_value])
			_check(int(actual["x"]) == int(reference["x"]),
					"template %d x of seed %d" % [index, seed_value])
			_check(int(actual["y"]) == int(reference["y"]),
					"template %d y of seed %d" % [index, seed_value])
		# Determinism: the same seed always yields the same level.
		var repeat: Dictionary = generator.first_level(208, 0, seed_value)
		_check(repeat["placements"] == placements, "determinism of seed %d" % seed_value)
	# A different seed must not repeat the same level.
	var first: Dictionary = GENERATOR.new().first_level(208, 0, 1)
	var other: Dictionary = GENERATOR.new().first_level(208, 0, 2)
	_check(first["placements"] != other["placements"], "distinct seeds differ")


func _check_composition(templates: TEMPLATES, golden: Dictionary) -> void:
	var generator: GENERATOR = GENERATOR.new()
	var composer: COMPOSER = COMPOSER.new()
	var level: Dictionary = generator.first_level(208, 0, 1)
	var composed: Dictionary = composer.compose(level["placements"], templates)
	_check(composed["size"] == Vector2i(512, 640), "map size")
	var cells: Array = composed["cells"]
	_check(cells.size() > 0, "composed cells")
	var layer2: PackedInt32Array = composed["layer2_words"]
	_check(layer2.size() == 512 * 640, "material layer size")

	# The start template is stamped at (208, 0); its geometry and its material
	# layer must land on the same cells.
	var start: Dictionary = templates.get_template("urw_unq_start")
	var start_pmp: Dictionary = start["pmp"]
	var start_l2m: Dictionary = start["l2m"]
	var start_words: PackedInt32Array = start_l2m["words"]
	_check(start_pmp["width"] == 60 and start_pmp["height"] == 36, "start template geometry size")
	var material_ok: bool = true
	for row: int in range(start_l2m["height"]):
		for column: int in range(start_l2m["width"]):
			var world_x: int = 208 + column
			var world_y: int = 0 + row
			if layer2[world_y * 512 + world_x] != start_words[row * int(start_l2m["width"]) + column]:
				material_ok = false
	_check(material_ok, "start template material overlay")

	# The cave painting contributes its material layer at (30, 23) only.
	var painting: Dictionary = templates.get_template("urw_unq_hoehlenmalerei")
	var painting_words: PackedInt32Array = painting["l2m"]["words"]
	var painting_ok: bool = true
	for row: int in range(int(painting["l2m"]["height"])):
		for column: int in range(int(painting["l2m"]["width"])):
			if layer2[(23 + row) * 512 + (30 + column)] != painting_words[row * int(painting["l2m"]["width"]) + column]:
				painting_ok = false
	_check(painting_ok, "cave painting material overlay")

	# A placed cave must carry its own geometry and material.
	var cave_placement: Dictionary = level["placements"][0]
	var cave: Dictionary = templates.get_template(str(cave_placement["template"]))
	var cave_words: PackedInt32Array = cave["l2m"]["words"]
	var cave_ok: bool = true
	for row: int in range(int(cave["l2m"]["height"])):
		for column: int in range(int(cave["l2m"]["width"])):
			var world_x: int = int(cave_placement["x"]) + column
			var world_y: int = int(cave_placement["y"]) + row
			if layer2[world_y * 512 + world_x] != cave_words[row * int(cave["l2m"]["width"]) + column]:
				cave_ok = false
	_check(cave_ok, "cave material overlay")

	# The player dwarves come from the start template.
	var objects: Array = composed["objects"]
	var dwarves: int = 0
	var resources: int = 0
	var wukers: int = 0
	for object: Dictionary in objects:
		var object_class: String = str(object["class"])
		if object_class == "Zwerg":
			dwarves += 1
			_check(object["owner"] == 0, "dwarf owner flag")
			_check(object["autolight"] == true, "dwarf autolight flag")
		elif object_class == "Pilz" or object_class == "Raupe" or object_class == "Stein":
			resources += 1
		elif object_class == "Wuker":
			wukers += 1
	_check(dwarves == 5, "player dwarves on the start template")
	_check(resources > 0, "cave resources")
	_check(wukers == 0, "Wuker objects removed")

	# The removal has to be meaningful: the raw templates do contain Wukers.
	var raw_wukers: int = 0
	for name: String in ["urw_hol_001_a", "urw_hol_027_a", "urw_gng_002_b"]:
		var template: Dictionary = templates.get_template(name)
		for object: Dictionary in template["objects"]:
			if str(object["class"]) == "Wuker":
				raw_wukers += 1
	_check(raw_wukers > 0, "templates contain Wuker objects")

	# A resource of the first cave must sit at the template relative position.
	var resource_ok: bool = false
	for object: Dictionary in objects:
		if str(object["class"]) == "Pilz" and str(object["template"]) == str(cave_placement["template"]):
			resource_ok = true
	_check(resource_ok, "cave resource placement")

	# Every surviving object of the first placed cave keeps its template
	# relative position, and the cave resources keep their class and flags.
	var cave_name: String = str(cave_placement["template"])
	var cave_source: Dictionary = templates.get_template(cave_name)
	var expected_objects: int = 0
	var placed_objects: int = 0
	for source: Dictionary in cave_source["objects"]:
		if str(source["class"]) == "Wuker":
			continue
		expected_objects += 1
		for object: Dictionary in objects:
			if str(object["template"]) != cave_name:
				continue
			if str(object["class"]) != str(source["class"]):
				continue
			if absf(float(object["x"]) - (float(cave_placement["x"]) + float(source["x"]))) > 0.0001:
				continue
			if absf(float(object["y"]) - (float(cave_placement["y"]) + float(source["y"]))) > 0.0001:
				continue
			if absf(float(object["z"]) - float(source["z"])) > 0.0001:
				continue
			_check(object["physic"] == source["flags"].get("physic", null),
					"cave object physic flag of " + cave_name)
			placed_objects += 1
			break
	_check(placed_objects == expected_objects,
			"every cave object keeps its template position (%d of %d)" % [placed_objects, expected_objects])

	# The resources of the cave template must exist with the native classes.
	var cave_resources: int = 0
	for source: Dictionary in cave_source["objects"]:
		if str(source["class"]) == "Pilz" or str(source["class"]) == "Raupe" or str(source["class"]) == "Stein":
			cave_resources += 1
	_check(cave_resources > 0, "cave template declares resources")

	# The fog remover of Campaign.tcl:205-209.
	var fog: Dictionary = composed["fog"]
	_check(fog["position"] == Vector3i(239, 14, 15), "fog remover position")
	_check(fog["rect"] == Vector3i(0, 46, 22), "fog remover rectangle")
	_check(fog["undeletable"] == true, "fog remover is undeletable")


func _check_scene(templates: TEMPLATES, golden: Dictionary) -> void:
	var generator: GENERATOR = GENERATOR.new()
	var composer: COMPOSER = COMPOSER.new()
	var level: Dictionary = generator.first_level(208, 0, 1)
	var composed: Dictionary = composer.compose(level["placements"], templates)
	var scene: Node3D = SCENE.build(composed)
	root.add_child(scene)
	await process_frame
	var terrain: MeshInstance3D = scene.get_node("CampaignTerrain") as MeshInstance3D
	_check(terrain != null, "campaign terrain node")
	if terrain != null:
		_check(terrain.mesh != null, "campaign terrain mesh")
		_check(terrain.mesh.get_surface_count() == 1, "campaign terrain surface")
	var objects: Node3D = scene.get_node("CampaignObjects") as Node3D
	_check(objects != null, "campaign objects node")
	if objects != null:
		_check(objects.get_child_count() == composed["objects"].size(), "campaign object count")
		var dwarf_nodes: int = 0
		var wuker_nodes: int = 0
		for child: Node in objects.get_children():
			if str(child.get_meta("native_class", "")) == "Zwerg":
				dwarf_nodes += 1
			if str(child.get_meta("native_class", "")) == "Wuker":
				wuker_nodes += 1
		_check(dwarf_nodes == 5, "campaign dwarf nodes")
		_check(wuker_nodes == 0, "campaign Wuker nodes")
	var fog: Node3D = scene.get_node("FogRemover") as Node3D
	_check(fog != null, "campaign fog node")
	if fog != null:
		_check(fog.get_meta("native_fog_remove", Vector3i.ZERO) == Vector3i(0, 46, 22), "campaign fog rectangle")
	scene.queue_free()
