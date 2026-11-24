extends SceneTree

const STATE: Script = preload("res://scripts/native_terrain_state.gd")

var assertions: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var path: String = ProjectSettings.globalize_path("res://").path_join("../docs/reverse-engineering/native-terrain-strike-2026-11-17.json")
	var fixtures: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(path))
	for fixture: Dictionary in fixtures["fixtures"]:
		_test_fixture(fixture)
	var world: RefCounted = _new_state()
	var rejected: Dictionary = world.apply_accepted_step(Vector2i(9, 3), 0, 0xA3, false)
	_expect(not rejected["accepted"] and int(rejected["marks"]) == 0xA0, "policy failure did not clear only selected slot")
	_expect(world.revision == 0 and world.block_ref(Vector2i(9, 3)) == 0, "policy failure changed terrain")
	var terminal_marks: int = 8
	for step: int in range(8):
		var patch: Dictionary = world.apply_accepted_step(Vector2i(9, 3), 0, terminal_marks, true)
		terminal_marks = int(patch["marks"])
		if terminal_marks == 0:
			break
	_expect(terminal_marks == 0 and int(world.current_height(Vector2i(9, 3))) == 0, "terminal cave did not reach source zero state")
	print("NATIVE_TERRAIN_STATE_SELF_TEST_%s assertions=%d fixtures=7" % ["OK" if failures == 0 else "FAILED", assertions])
	quit(0 if failures == 0 else 1)


func _new_state() -> RefCounted:
	var terrain: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/multi_start_010_terrain.json"))
	var facts: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/multi_start_010_tunnel_rules.json"))
	var world: RefCounted = STATE.new()
	_expect(world.load_state("res://models/multi_start_010_mutable.json", terrain, facts), "source package failed validation")
	return world


func _test_fixture(fixture: Dictionary) -> void:
	var world: RefCounted = _new_state()
	var base: String = str(fixture["base"])
	if base == "A_initial_9_3_corridor":
		world.apply_accepted_step(Vector2i(9, 3), 0, 3, true)
	elif base == "F_cave_target7_first_strike":
		world.apply_accepted_step(Vector2i(9, 3), 0, 10, true)
	var point: Vector2i = Vector2i(int(fixture["point"][0]), int(fixture["point"][1]))
	var cells: Array[Vector2i] = [point - Vector2i.ONE, point + Vector2i.UP, point + Vector2i.LEFT, point]
	if fixture.has("dirty_byte13_before"):
		for index: int in range(4):
			world.cell(cells[index])["dirty_flags"] = int(fixture["dirty_byte13_before"][index])
	var marks: int = int(fixture.get("mark_nibble", 3))
	var groups: int = 0
	if fixture.has("marks_before"):
		marks = str(fixture["marks_before"]).hex_to_int()
		groups = str(fixture["group_word_before_and_after"]).hex_to_int()
	var patch: Dictionary = world.apply_accepted_step(point, 0, marks, true, groups)
	_expect(bool(patch["accepted"]) == bool(fixture["result"]), str(fixture["id"]) + " acceptance")
	for index: int in range(4):
		_expect(world.block_ref(cells[index]) == int(fixture["new_refs"][index]), str(fixture["id"]) + " block ref")
	if fixture.has("marks_after"):
		_expect(int(patch["marks"]) == str(fixture["marks_after"]).hex_to_int(), "packed eight-slot marks")
		_expect(int(patch["groups"]) == groups, "groups were changed")
		for index: int in range(4):
			_expect(int(world.cell(cells[index])["dirty_flags"]) == int(fixture["dirty_byte13_after"][index]), "dirty flag preservation")
	else:
		_expect((int(patch["marks"]) & 15) == int(fixture["new_mark_nibble"]), str(fixture["id"]) + " completion")
	if fixture.has("post_Hnext"):
		_expect(int(world.next_height(point)) == int(fixture["post_Hnext"]), str(fixture["id"]) + " post height")
	if bool(patch["accepted"]):
		_expect(patch["dirty_cells"].size() == 4 and patch["invalidations"].size() == 2, "dirty area contract")
		_expect(patch["invalidations"][0]["rect"] == Rect2i(point * 8 - Vector2i(8, 8), Vector2i(16, 16)), "native 8x invalidation bounds")


func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("TERRAIN_STATE_ASSERT " + message)
