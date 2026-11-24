extends SceneTree
## Godot --headless --path godot --script res://tools/native_walk_flags_self_test.gd
## Pure tests: no scene/controller, exporter, navigation graph, or APK.

const FLAGS: Script = preload("res://scripts/native_walk_flags.gd")
const FIXTURES: String = "../docs/reverse-engineering/native-walk-flags-2026-11-17.json"

var _assertions: int = 0
var _failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	_test_clearance()
	_test_edges()
	_test_gate()
	_test_rect_and_overlay()
	_test_source_fixtures()
	_test_partial_queries()
	if _failures > 0:
		push_error("NATIVE_WALK_FLAGS_SELF_TEST_FAILED assertions=%d failures=%d" % [
			_assertions, _failures])
		quit(1)
		return
	print("NATIVE_WALK_FLAGS_SELF_TEST_OK assertions=%d" % _assertions)
	quit(0)


func _flat(sample: Vector2i, value: int = 0) -> Dictionary:
	var heights: Dictionary = {}
	for dy: int in range(-16, 3):
		for dx: int in range(-8, 9):
			heights[sample + Vector2i(dx, dy)] = value
	return heights


func _test_clearance() -> void:
	var sample: Vector2i = Vector2i(32, 32)
	var properties: Dictionary = {Vector2i(4, 4): 0}
	_check(FLAGS.CLEARANCE_OFFSETS.size() == 31, "exactly 31 native clearance probes")
	_check(FLAGS.terrain_sample(sample, _flat(sample), properties) == 1, "flat zero height -> 1")
	for offset: Vector2i in FLAGS.CLEARANCE_OFFSETS:
		var probe_heights: Dictionary = _flat(sample)
		probe_heights[sample + offset] = 13
		_check(FLAGS.terrain_sample(sample, probe_heights, properties) == 1,
			"probe %s accepts 13" % offset)
		probe_heights[sample + offset] = 14
		_check(FLAGS.terrain_sample(sample, probe_heights, properties) == 0,
			"probe %s rejects exactly 14" % offset)
		probe_heights[sample + offset] = 15
		_check(FLAGS.terrain_sample(sample, probe_heights, properties) == 0,
			"probe %s rejects 15" % offset)
	var heights: Dictionary = _flat(sample)
	heights[sample + Vector2i(6, -7)] = 255
	_check(FLAGS.terrain_sample(sample, heights, properties) == 1,
		"unsampled interior is not an invented filled rectangle")
	heights[sample] = 15
	_check(FLAGS.terrain_sample(sample, heights, properties) == 3,
		"current height is not a clearance probe: native source sample (180,84) also has 15")


func _test_edges() -> void:
	var sample: Vector2i = Vector2i(32, 32)
	var properties: Dictionary = {Vector2i(4, 4): 0}
	var heights: Dictionary = _flat(sample)
	heights[sample] = 2
	_check(FLAGS.terrain_sample(sample, heights, properties) == 1, "upper delta 2 -> 1")
	heights[sample] = 3
	_check(FLAGS.terrain_sample(sample, heights, properties) == 3, "upper delta 3 -> 3")
	heights[sample + Vector2i(0, -11)] = 1
	_check(FLAGS.terrain_sample(sample, heights, properties) == 1, "upper far delta must also exceed 2")
	heights = _flat(sample)
	heights[sample + Vector2i(0, 1)] = 2
	_check(FLAGS.terrain_sample(sample, heights, properties) == 1, "lower delta 2 -> 1")
	heights[sample + Vector2i(0, 1)] = 3
	_check(FLAGS.terrain_sample(sample, heights, properties) == 3, "lower delta 3 -> 3")
	heights[sample + Vector2i(0, -10)] = 1
	_check(FLAGS.terrain_sample(sample, heights, properties) == 1, "lower far probe is y-10")
	heights[sample + Vector2i(0, -10)] = 0
	heights[sample + Vector2i(0, -11)] = 15
	_check(FLAGS.terrain_sample(sample, heights, properties) == 3,
		"lower branch must not accidentally reuse upper y-11")


func _test_gate() -> void:
	var sample: Vector2i = Vector2i(35, 32)
	var properties: Dictionary = {Vector2i(4, 4): 0, Vector2i(5, 4): 0x80}
	_check(FLAGS.terrain_sample(sample, _flat(sample), properties) == 1,
		"sample x=35 gates cell 4")
	sample.x = 36
	_check(FLAGS.terrain_sample(sample, {}, properties) == 0,
		"sample x=36 gates cell 5 before any height read")
	properties[Vector2i(5, 4)] = 0x7F
	_check(FLAGS.terrain_sample(sample, _flat(sample), properties) == 1,
		"only bit 7 of C+0x18 gates terrain computation")


func _test_rect_and_overlay() -> void:
	var sample: Vector2i = Vector2i(32, 32)
	var heights: Dictionary = _flat(sample)
	var saved: Dictionary = heights.duplicate()
	var properties: Dictionary = {Vector2i(4, 4): 0}
	var result: Dictionary = FLAGS.rebuild_terrain(Rect2i(32, 32, 2, 2), heights, properties)
	_check(result.size() == 4, "2x2 half-open rect produces four sample bytes")
	_check(result.has(Vector2i(33, 33)) and not result.has(Vector2i(34, 33)), "right edge excluded")
	_check(not result.has(Vector2i(33, 34)), "bottom edge excluded")
	_check(heights == saved, "rebuild leaves source heights unchanged")
	_check(FLAGS.rebuild_terrain(Rect2i(32, 32, 0, 2), {}, {}).is_empty(), "empty region reads nothing")
	_check(FLAGS.terrain_dependency_rect(Rect2i(64, 16, 16, 16)) == Rect2i(56, 14, 32, 34),
		"strike (9,3) invalidation expands to (56,14)-(88,48) before native clipping")
	_check(FLAGS.object_overlay(3, 0, 0) == 3, "ordinary object preserves bits 0/1")
	_check(FLAGS.object_overlay(15, 0, 0) == 3, "ordinary object clears bits 2/3")
	_check(FLAGS.object_overlay(3, 4, 0x7FFFFFFF) == 4, "INT_MAX object clears then ORs its byte")
	_check(FLAGS.object_overlay(0, 3, 0x7FFFFFFF) == 3, "object byte can explicitly set bits 0/1")
	_check(FLAGS.object_overlay(0xA3, 0x1FF, -1) == 0xFF, "object field is truncated to low byte")


func _test_source_fixtures() -> void:
	var path: String = ProjectSettings.globalize_path("res://").path_join(FIXTURES)
	var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(path))
	_check(parsed is Dictionary, "evidence JSON loads")
	if not parsed is Dictionary:
		return
	var evidence: Dictionary = parsed
	for fixture: Dictionary in evidence["fixtures"]:
		var xy: Array = fixture["sample"]
		var sample: Vector2i = Vector2i(int(xy[0]), int(xy[1]))
		var heights: Dictionary = _flat(sample, int(fixture["required_height_default"]))
		for entry: Array in fixture["height_overrides"]:
			heights[sample + Vector2i(int(entry[0]), int(entry[1]))] = int(entry[2])
		var gate_cell: Vector2i = Vector2i((sample.x + 4) >> 3, (sample.y + 4) >> 3)
		var properties: Dictionary = {gate_cell: int(fixture["center_cell_byte18_high_bit"])}
		var actual: int = FLAGS.terrain_sample(sample, heights, properties)
		_check(actual == int(fixture["expected"]), "source BDB sample %s" % sample)
		_check(actual == int(fixture["initial_rle_value"]), "source PMP RLE sample %s" % sample)


func _test_partial_queries() -> void:
	var sample: Vector2i = Vector2i(32, 32)
	var heights: Dictionary = _flat(sample)
	var gates: Dictionary = {Vector2i(4, 4): 0}
	var height_query: Callable = func(point: Vector2i) -> Variant: return heights.get(point)
	var gate_query: Callable = func(point: Vector2i) -> Variant: return gates.get(point)
	heights.erase(sample + Vector2i(0, -8))
	_check(FLAGS.terrain_sample_query(sample, height_query, gate_query) == null, "unknown clearance remains unknown")
	heights[sample + Vector2i(7, -15)] = 14
	_check(FLAGS.terrain_sample_query(sample, height_query, gate_query) == 0, "known blocker proves zero despite an unknown neighbor")
	gates[Vector2i(4, 4)] = 0x80
	heights.clear()
	_check(FLAGS.terrain_sample_query(sample, height_query, gate_query) == 0, "known material gate needs no invented heights")
	gates.clear()
	_check(FLAGS.terrain_sample_query(sample, height_query, gate_query) == null, "missing material is unknown")
	gates[Vector2i(4, 4)] = 0
	heights.merge(_flat(sample))
	heights[sample] = 15
	heights.erase(sample + Vector2i(0, -11))
	_check(FLAGS.terrain_sample_query(sample, height_query, gate_query) == null, "unresolved upper slope remains unknown")
	heights[sample + Vector2i(0, 1)] = 20
	_check(FLAGS.terrain_sample_query(sample, height_query, gate_query) == 3, "known lower slope proves bit2 despite unresolved upper branch")


func _check(condition: bool, label: String) -> void:
	_assertions += 1
	if not condition:
		_failures += 1
		push_error("ASSERT: " + label)
