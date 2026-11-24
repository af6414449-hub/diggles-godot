extends SceneTree
## Cross-check of the independent ports of Campaign.tcl:first_level.
##
## Run:
##   godot --headless --path godot --script res://tools/native_campaign_cross_check.gd
##
## The project currently holds more than one port of the same procedure:
##
##   scripts/native_campaign_level.gd      port A (MCode)
##   scripts/diggles_campaign_generator.gd port B (Codex)
##   tools/export_campaign_chapter.py      port C (Python exporter)
##
## Port C is checked against the exported chapter manifest by
## tools/native_campaign_chapter_self_test.gd. This test compares A and B on
## several seeds, template by template and coordinate by coordinate. Two ports
## written from the same source that agree on every placement is the strongest
## evidence that the placement rules were read correctly.

const PORT_A: Script = preload("res://scripts/native_campaign_level.gd")
const PORT_B: Script = preload("res://scripts/diggles_campaign_generator.gd")
const CHAPTER_PATH: String = "res://models/native_campaign_chapter.json"

const SEEDS: Array[int] = [0, 1, 7, 12345]
const START_X: int = 208
const START_Y: int = 0

var _checks: int = 0
var _failures: Array[String] = []


func _init() -> void:
	for seed_value: int in SEEDS:
		_compare_ports(seed_value)
	_check_against_export()
	_report()


func _compare_ports(seed_value: int) -> void:
	var port_a: Dictionary = (PORT_A.new() as RefCounted).call("generate", seed_value, START_X, START_Y)
	var port_b: Dictionary = (PORT_B.new() as RefCounted).call("first_level", START_X, START_Y, seed_value)
	# Port A also emits the chapter prologue (the start template and the
	# painting layer, Campaign.tcl:12-15); port B covers first_level only.
	var a_list: Array = []
	for placement: Dictionary in port_a["placements"]:
		if str(placement.get("role", "")) in ["chapter_start", "layer_only"]:
			continue
		a_list.append(placement)
	var b_list: Array = port_b.get("placements", [])
	_check(a_list.size() == b_list.size(),
		"seed %d: placement count A %d, B %d" % [seed_value, a_list.size(), b_list.size()])
	if a_list.size() != b_list.size():
		return
	for index: int in range(a_list.size()):
		var a: Dictionary = a_list[index]
		var b: Dictionary = b_list[index]
		_check(str(a["template"]) == str(b["template"]),
			"seed %d placement %d: template A %s, B %s" % [seed_value, index,
				str(a["template"]), str(b["template"])])
		_check(int(a["x"]) == int(b["x"]) and int(a["y"]) == int(b["y"]),
			"seed %d placement %d (%s): position A (%d,%d), B (%d,%d)" % [seed_value, index,
				str(a["template"]), int(a["x"]), int(a["y"]), int(b["x"]), int(b["y"])])


## Port A against the chapter that the Python exporter produced.
func _check_against_export() -> void:
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(CHAPTER_PATH))
	if not decoded is Dictionary:
		_fail("chapter manifest is missing or invalid")
		return
	var chapter: Dictionary = decoded
	var seed_value: int = int(chapter.get("seed", 0))
	# The exported chapter carries the prologue as well, so the full port A
	# list is compared here.
	var port_a: Dictionary = (PORT_A.new() as RefCounted).call("generate", seed_value, START_X, START_Y)
	var a_list: Array = port_a["placements"]
	var exported: Array = chapter["placements"]
	_check(a_list.size() == exported.size(),
		"export: placement count A %d, export %d" % [a_list.size(), exported.size()])
	if a_list.size() != exported.size():
		return
	for index: int in range(a_list.size()):
		var a: Dictionary = a_list[index]
		var e: Dictionary = exported[index]
		_check(str(a["template"]) == str(e["template"]) and int(a["x"]) == int(e["x"])
			and int(a["y"]) == int(e["y"]),
			"export placement %d: A (%s,%d,%d) export (%s,%d,%d)" % [index,
				str(a["template"]), int(a["x"]), int(a["y"]),
				str(e["template"]), int(e["x"]), int(e["y"])])


func _check(condition: bool, message: String) -> void:
	_checks += 1
	if not condition:
		_failures.append(message)


func _fail(message: String) -> void:
	_failures.append(message)


func _report() -> void:
	if _failures.is_empty():
		print("CAMPAIGN_CROSS_CHECK_OK checks=%d seeds=%d" % [_checks, SEEDS.size()])
		quit(0)
		return
	for failure: String in _failures:
		push_error("CAMPAIGN_CROSS_CHECK_FAIL: " + failure)
	print("CAMPAIGN_CROSS_CHECK_FAIL checks=%d failures=%d" % [_checks, _failures.size()])
	quit(1)
