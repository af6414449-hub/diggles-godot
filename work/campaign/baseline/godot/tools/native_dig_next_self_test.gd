extends SceneTree

const NEXT: Script = preload("res://scripts/native_dig_next.gd")

var assertions: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var path: String = ProjectSettings.globalize_path("res://").path_join("../docs/reverse-engineering/native-dig-next-2026-11-17.json")
	var fixture_data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(path))
	var bounds: Rect2i = Rect2i(0, 0, 44, 24)
	for fixture: Dictionary in fixture_data["fixtures"]:
		var samples: Dictionary = _empty_world(bounds)
		for row: Array in fixture["samples"]:
			samples[Vector2i(int(row[0]), int(row[1]))] = {"marks": int(row[2]), "material_word": int(row[3]), "next_height": int(row[4]), "groups": int(row[5])}
		var p: Array = fixture.get("position", fixture_data["default_position"])
		var position: Vector3 = Vector3(float(p[0]), float(p[1]), float(p[2]))
		var before: Dictionary = samples.duplicate(true)
		var result: Dictionary = NEXT.select_next(position, bounds, int(fixture.get("slot", 0)), int(fixture.get("worker_group", 0)), samples, int(fixture.get("rank_index", 0)), bool(fixture.get("require_same_group", false)))
		var expected: Array = fixture["expected_point"]
		var id: String = str(fixture["id"])
		_expect(result["status"] == fixture.get("expected_status", "ok"), id + " status")
		_expect(result.get("point") == Vector3(float(expected[0]), float(expected[1]), float(expected[2])), id + " XYZ")
		var packed: PackedFloat32Array = PackedFloat32Array([float(result.get("cost", -1.0))])
		_expect(packed.to_byte_array().decode_u32(0) == str(fixture["cost_bits"]).hex_to_int(), id + " exact float32 cost")
		_expect(samples == before, id + " mutated input")
	_test_bounds_and_unknowns()
	print("NATIVE_DIG_NEXT_SELF_TEST_%s assertions=%d fixtures=%d" % ["OK" if failures == 0 else "FAILED", assertions, fixture_data["fixtures"].size()])
	quit(0 if failures == 0 else 1)


func _test_bounds_and_unknowns() -> void:
	_expect(NEXT.scan_rect(Vector3(10, 10.75, 9), Rect2i(0, 0, 44, 24)) == Rect2i(2, 2, 24, 20), "clipped exclusive world bounds")
	_expect(NEXT.scan_rect(Vector3(22, 20.75, 9), Rect2i(0, 0, 64, 64)) == Rect2i(6, 3, 32, 32), "asymmetric Y window")
	_expect(NEXT.scan_rect(Vector3(-0.75, -0.25, 9), Rect2i(-32, -32, 128, 128)) == Rect2i(-16, -17, 32, 32), "negative truncation toward zero")
	_expect(NEXT.scan_rect(Vector3(110, 210.75, 9), Rect2i(100, 200, 44, 24)) == Rect2i(102, 202, 24, 20), "nonzero native origin")
	var bounds: Rect2i = Rect2i(0, 0, 44, 24)
	var position: Vector3 = Vector3(10, 10.75, 9)
	var samples: Dictionary = _empty_world(bounds)
	var result: Dictionary = NEXT.select_next(position, bounds, 0, 0, samples)
	_expect(result["status"] == "no_candidate" and result["point"] == Vector3(-1, -1, 1), "no marks sentinel")
	samples.erase(Vector2i(2, 2))
	result = NEXT.select_next(position, bounds, 0, 0, samples)
	_expect(result["status"] == "unknown" and result["at"] == Vector2i(2, 2), "missing unmarked cell cannot be assumed empty")
	samples[Vector2i(2, 2)] = {"marks": 3}
	result = NEXT.select_next(position, bounds, 0, 0, samples)
	_expect(result["status"] == "unknown" and result["missing"] == "material_word", "missing material")
	samples[Vector2i(2, 2)] = {"marks": 3, "material_word": 2}
	result = NEXT.select_next(position, bounds, 0, 0, samples)
	_expect(result["status"] == "unknown" and result["missing"] == "next_height", "missing Hnext")
	samples[Vector2i(2, 2)]["next_height"] = 11
	result = NEXT.select_next(position, bounds, 0, 0, samples)
	_expect(result["status"] == "unknown" and result["missing"] == "groups", "missing group word")
	samples[Vector2i(2, 2)]["material_word"] = 0
	result = NEXT.select_next(position, bounds, 0, 0, samples)
	_expect(result["status"] == "no_candidate", "material gate does not demand later fields")
	samples = _empty_world(bounds)
	samples.erase(Vector2i(26, 10))
	result = NEXT.select_next(position, bounds, 0, 0, samples)
	_expect(result["status"] == "no_candidate", "exclusive scan end is not read")
	result = NEXT.select_next(position, Rect2i(0, 0, 3, 3), 0, 0, {})
	_expect(result["status"] == "no_candidate", "empty scan window")
	result = NEXT.select_next(position, bounds, 8, 0, samples)
	_expect(result["status"] == "invalid_input", "invalid slot is adapter error")


func _empty_world(bounds: Rect2i) -> Dictionary:
	var samples: Dictionary = {}
	for y: int in range(bounds.position.y, bounds.end.y):
		for x: int in range(bounds.position.x, bounds.end.x):
			samples[Vector2i(x, y)] = {"marks": 0}
	return samples


func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error(message)
