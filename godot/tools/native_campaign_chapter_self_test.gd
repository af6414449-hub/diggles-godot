extends SceneTree
## Golden test of the campaign chapter map.
##
## Run:
##   godot --headless --path godot --script res://tools/native_campaign_chapter_self_test.gd
##
## The check that matters: the runtime generator (scripts/native_campaign_level.gd,
## a GDScript port) and the exporter (tools/export_campaign_chapter.py, a Python
## implementation) are two independent ports of Campaign.tcl:first_level. They
## must agree on every template and every coordinate.

const LEVEL: Script = preload("res://scripts/native_campaign_level.gd")
const CHAPTER_PATH: String = "res://models/native_campaign_chapter.json"

var _checks: int = 0
var _failures: Array[String] = []


func _init() -> void:
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(CHAPTER_PATH))
	if not decoded is Dictionary:
		_fail("chapter manifest is missing or invalid")
		_report()
		return
	var chapter: Dictionary = decoded
	var seed_value: int = int(chapter.get("seed", 0))

	_check_map_size(chapter)
	_check_placements_match_generator(chapter, seed_value)
	_check_determinism(seed_value)
	_check_seed_changes_the_level(seed_value)
	_check_dwarves(chapter)
	_check_deleted_class(chapter)
	_check_bounds(chapter)
	_check_story_placements(chapter)
	_check_terrain(chapter)
	_report()


## The two ports must produce the same chapter.
func _check_placements_match_generator(chapter: Dictionary, seed_value: int) -> void:
	var generator: RefCounted = LEVEL.new()
	var generated: Dictionary = generator.call("generate", seed_value)
	var produced: Array = generated["placements"]
	var exported: Array = chapter["placements"]
	_check(produced.size() == exported.size(),
		"placement count: generator %d, export %d" % [produced.size(), exported.size()])
	if produced.size() != exported.size():
		return
	for index: int in range(produced.size()):
		var mine: Dictionary = produced[index]
		var theirs: Dictionary = exported[index]
		_check(str(mine["template"]) == str(theirs["template"]),
			"placement %d template: generator %s, export %s" % [index, str(mine["template"]), str(theirs["template"])])
		_check(int(mine["x"]) == int(theirs["x"]) and int(mine["y"]) == int(theirs["y"]),
			"placement %d position: generator (%d,%d), export (%d,%d)" % [index,
				int(mine["x"]), int(mine["y"]), int(theirs["x"]), int(theirs["y"])])


func _check_map_size(chapter: Dictionary) -> void:
	var size: Dictionary = chapter.get("map_size", {})
	_check(int(size.get("width", 0)) == 512 and int(size.get("height", 0)) == 640,
		"map size is %s, expected 512x640" % str(size))


func _check_determinism(seed_value: int) -> void:
	var first: Dictionary = (LEVEL.new() as RefCounted).call("generate", seed_value)
	var second: Dictionary = (LEVEL.new() as RefCounted).call("generate", seed_value)
	_check(str(first["placements"]) == str(second["placements"]),
		"two runs of the same seed differ")


func _check_seed_changes_the_level(seed_value: int) -> void:
	var other: Dictionary = (LEVEL.new() as RefCounted).call("generate", seed_value + 1)
	var mine: Dictionary = (LEVEL.new() as RefCounted).call("generate", seed_value)
	_check(str(other["placements"]) != str(mine["placements"]),
		"two different seeds produced the same level")


## The player dwarves come from the chapter start template (urw_unq_start).
## The story caves of the zone have dwarves of their own, so they are counted
## apart from the dwarves of the chapter.
func _check_dwarves(chapter: Dictionary) -> void:
	var reports: Dictionary = {}
	for report: Dictionary in chapter.get("templates", []):
		reports[str(report["template"])] = report
	var start_dwarves: Array = []
	for object_data: Dictionary in chapter["objects"]:
		if str(object_data["class"]) != "Zwerg":
			continue
		if str(object_data.get("template", "")) == "urw_unq_start":
			start_dwarves.append(object_data)
	_check(start_dwarves.size() >= 5,
		"expected at least five dwarves at the start, found %d" % start_dwarves.size())
	var start_x: int = 208
	var start_y: int = 0
	for dwarf: Dictionary in start_dwarves:
		_check(float(dwarf["x"]) > float(start_x) and float(dwarf["x"]) < float(start_x) + 60,
			"dwarf x %f is outside the start template" % float(dwarf["x"]))
		_check(float(dwarf["y"]) > float(start_y) and float(dwarf["y"]) < float(start_y) + 36,
			"dwarf y %f is outside the start template" % float(dwarf["y"]))
	# Every dwarf stands inside the template it belongs to.
	for dwarf: Dictionary in chapter["objects"]:
		if str(dwarf["class"]) != "Zwerg":
			continue
		var report: Dictionary = reports.get(str(dwarf.get("template", "")), {})
		if report.is_empty():
			continue
		var local_x: float = float(dwarf["x"]) - float(dwarf["template_x"])
		var local_y: float = float(dwarf["y"]) - float(dwarf["template_y"])
		_check(local_x >= -2.0 and local_x <= float(report["width"]) + 2.0
			and local_y >= -2.0 and local_y <= float(report["height"]) + 2.0,
			"dwarf of %s is outside its template" % str(dwarf.get("template", "")))


## The story content of the zone: CampaignInit.tcl places the hand made caves
## of the Urwald zone at fixed positions of the map.
func _check_story_placements(chapter: Dictionary) -> void:
	var story: Array = chapter.get("story_placements", [])
	_check(story.size() > 0, "the chapter has no story caves")
	for placement: Dictionary in story:
		_check(int(placement["x"]) >= 0 and int(placement["x"]) < 512
			and int(placement["y"]) >= 0 and int(placement["y"]) < 640,
			"story placement %s is outside the map" % str(placement["template"]))
	var summary: Dictionary = chapter.get("summary", {})
	_check(int(summary.get("story_placements", 0)) == story.size(),
		"summary story placement count does not match the story placement list")


## Campaign.tcl:198-203 deletes every Wuker after the chapter is assembled.
func _check_deleted_class(chapter: Dictionary) -> void:
	var deleted_class: String = str(chapter.get("deleted_class", ""))
	_check(deleted_class == "Wuker", "deleted class is %s" % deleted_class)
	var found: int = 0
	for object_data: Dictionary in chapter["objects"]:
		if str(object_data["class"]) == deleted_class:
			found += 1
	_check(found > 0, "the chapter has no %s objects to delete" % deleted_class)


func _check_bounds(chapter: Dictionary) -> void:
	for placement: Dictionary in chapter["placements"]:
		_check(int(placement["x"]) >= 0 and int(placement["x"]) < 512
			and int(placement["y"]) >= 0 and int(placement["y"]) < 640,
			"placement %s is outside the chapter map" % str(placement["template"]))


func _check_terrain(chapter: Dictionary) -> void:
	var cells: Array = chapter["cells"]
	_check(not cells.is_empty(), "the chapter has no terrain cells")
	_check(not (chapter.get("meshes", {}) as Dictionary).is_empty(), "the chapter has no block meshes")
	_check(not (chapter.get("layer2", {}) as Dictionary).is_empty(), "the chapter has no material layer")
	var summary: Dictionary = chapter.get("summary", {})
	_check(int(summary.get("objects", 0)) > 0, "the chapter has no objects")
	_check(int(summary.get("placements", 0)) == int(chapter["placements"].size()),
		"summary placement count does not match the placement list")


func _check(condition: bool, message: String) -> void:
	_checks += 1
	if not condition:
		_failures.append(message)


func _fail(message: String) -> void:
	_failures.append(message)


func _report() -> void:
	if _failures.is_empty():
		print("CAMPAIGN_CHAPTER_SELF_TEST_OK checks=%d" % _checks)
		quit(0)
		return
	for failure: String in _failures:
		push_error("CAMPAIGN_CHAPTER_SELF_TEST_FAIL: " + failure)
	print("CAMPAIGN_CHAPTER_SELF_TEST_FAIL checks=%d failures=%d" % [_checks, _failures.size()])
	quit(1)
