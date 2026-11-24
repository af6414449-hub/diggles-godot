extends SceneTree

const GROUPS: Script = preload("res://scripts/native_dig_groups.gd")
var assertions: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var path: String = ProjectSettings.globalize_path("res://").path_join("../docs/reverse-engineering/native-worker-group-2026-11-17.json")
	var data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(path))
	var point: Vector2i = Vector2i(9, 3)
	for fixture: Dictionary in data["placement_fixtures"]:
		var model: RefCounted = GROUPS.new()
		var slot: int = int(fixture["slot"])
		model.counters[slot] = int(fixture["counter_before"])
		model.words[point] = str(fixture["groups_before"]).hex_to_int()
		if bool(fixture["accepted_point"]):
			model.stamp(point, slot)
		model.finish_commit(slot)
		_expect(model.word(point) == str(fixture["groups_after"]).hex_to_int(), str(fixture["id"]) + " packed word")
		_expect(model.counters[slot] == int(fixture["counter_after"]), str(fixture["id"]) + " counter")
	for fixture: Dictionary in data["stamp_fixtures"]:
		if fixture["event"] != "accepted":
			continue # Reset/rejected/announce lifecycle is tested at the controller.
		var word: int = str(fixture["groups"]).hex_to_int()
		var slot: int = int(fixture["slot"])
		var actual: int = GROUPS.worker_stamp(word, slot)
		_expect(actual == str(fixture["worker_bits_after"]).hex_to_int(), str(fixture["id"]) + " raw worker SHR")
		_expect((((word >> (4 * slot)) & 15) == actual) == bool(fixture["same_group"]), str(fixture["id"]) + " candidate comparison")
	_expect(GROUPS.worker_stamp(-2147483647, 1) == 0x08000000, "signed64 input was not converted to u32")
	var empty: RefCounted = GROUPS.new()
	_expect(empty.word(point) == 0 and empty.counters[0] == 0, "fresh cleared manager state")
	empty.counters[0] = 0xFFFFFFFF
	empty.finish_commit(0)
	_expect(empty.counters[0] == 0, "dword counter overflow")
	if failures == 0:
		print("NATIVE_DIG_GROUPS_SELF_TEST_OK assertions=%d" % assertions)
	quit(0 if failures == 0 else 1)


func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("NATIVE_DIG_GROUPS_SELF_TEST_FAILED " + message)
