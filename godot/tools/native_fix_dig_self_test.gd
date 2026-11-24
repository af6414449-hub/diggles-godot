extends SceneTree

const FIX: Script = preload("res://scripts/native_fix_dig.gd")
const WALKMAP: Script = preload("res://scripts/native_walkmap.gd")
const TERRAIN: Script = preload("res://scripts/native_terrain_state.gd")
var failures: int = 0
var assertions: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var path: String = ProjectSettings.globalize_path("res://").path_join("../docs/reverse-engineering/native-fix-dig-2026-11-17.json")
	var data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(path))
	for fixture: Dictionary in data["fixtures"]:
		var values: Dictionary = {}
		for row: Array in fixture["flags"]:
			values[Vector2i(int(row[0]), int(row[1]))] = int(row[2])
		var flag_query: Callable = func(sample: Vector2i) -> Variant: return values.get(sample, 0)
		var height_query: Callable = func(_sample: Vector2i) -> Variant: return int(fixture.get("height", 4))
		var bounds: Array = fixture.get("bounds", [0, 0, 44, 24])
		var result: Dictionary = FIX.solve(_vector(fixture.get("target", [10, 10, 99])),
			_vector(fixture.get("worker", [10, 10, 12])),
			Rect2i(int(bounds[0]), int(bounds[1]), int(bounds[2]), int(bounds[3])), flag_query, height_query,
			StringName(str(fixture.get("rounding", "nearest_even"))))
		var name: String = str(fixture["id"])
		_expect(result["status"] == "ok", name + " status")
		if result["status"] != "ok":
			continue
		_expect(result["point"] == _vector(fixture["expected"]), name + " source XYZ")
		_expect(result["seed_sample"] == Vector2i(int(fixture["seed"][0]), int(fixture["seed"][1])), name + " source seed")
		_expect(bool(result["found_navigation"]) == bool(fixture["found"]), name + " native fallback")
		_expect(bool(result["found_floor"]) == bool(fixture["floor"]), name + " bit2 probe")
	_test_original_map(data["source_cases"])
	_test_unknowns()
	if failures == 0:
		print("NATIVE_FIX_DIG_SELF_TEST_OK assertions=%d arithmetic_fixtures=18 original_PMP_cases=2" % assertions)
	quit(0 if failures == 0 else 1)


func _test_original_map(cases: Array) -> void:
	var terrain: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/multi_start_010_terrain.json"))
	var facts: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/multi_start_010_tunnel_rules.json"))
	var state: RefCounted = TERRAIN.new()
	var walkmap: RefCounted = WALKMAP.new()
	_expect(state.load_state("res://models/multi_start_010_mutable.json", terrain, facts), "mutable source package")
	_expect(walkmap.load_map("res://models/multi_start_010_walkmap.json", terrain), "navigation source package")
	var height_query: Callable = func(sample: Vector2i) -> Variant: return state.surface_depth(Vector2(sample) * 0.125)
	for fixture: Dictionary in cases:
		var result: Dictionary = FIX.solve(_vector(fixture["target"]), _vector(fixture["worker"]),
			state.bounds, walkmap.sample, height_query, &"nearest_even")
		_expect(result["status"] == "ok", str(fixture["id"]) + " status")
		_expect(result.get("point") == _vector(fixture["expected"]), str(fixture["id"]) + " exact XYZ")
		_expect(result.get("seed_sample") == Vector2i(int(fixture["seed"][0]), int(fixture["seed"][1])), str(fixture["id"]) + " seed")
	var before: PackedByteArray = walkmap.flags.duplicate()
	walkmap.invalidate()
	var unknown: Dictionary = FIX.solve(Vector3(2, 15, 13), Vector3(3, 14.5, 12), state.bounds,
		walkmap.sample, height_query, &"nearest_even")
	_expect(unknown["status"] == "unknown", "dirty map read stale imported navigation flags")
	_expect(walkmap.flags == before, "invalidation destroyed original evidence")


func _test_unknowns() -> void:
	var absent: Callable = func(_sample: Vector2i) -> Variant: return null
	var known: Callable = func(_sample: Vector2i) -> Variant: return 3
	var bounds: Rect2i = Rect2i(0, 0, 44, 24)
	var result: Dictionary = FIX.solve(Vector3(10, 10, 99), Vector3(10, 10, 12), bounds, known, known)
	_expect(result["status"] == "unknown" and result["missing"] == "x87_rounding_mode", "undeclared rounding silently guessed")
	result = FIX.solve(Vector3(10, 10, 99), Vector3(10, 10, 12), bounds, absent, known, &"nearest_even")
	_expect(result["status"] == "unknown" and result["missing"] == "walk_flags", "unknown flag treated as empty")
	result = FIX.solve(Vector3(10, 10, 99), Vector3(10, 10, 12), bounds, known, absent, &"nearest_even")
	_expect(result["status"] == "unknown" and result["missing"] == "block_height", "unknown height fabricated")
	result = FIX.solve(Vector3.ZERO, Vector3.ZERO, Rect2i(), known, known, &"nearest_even")
	_expect(result["status"] == "invalid_input", "empty world bounds accepted")


func _vector(values: Array) -> Vector3:
	return Vector3(float(values[0]), float(values[1]), float(values[2]))


func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("NATIVE_FIX_DIG_SELF_TEST_FAILED " + message)
