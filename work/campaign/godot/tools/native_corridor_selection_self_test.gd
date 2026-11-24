extends SceneTree
## Run: Godot --headless --path godot --script res://tools/native_corridor_selection_self_test.gd
## Expectations are hand-derived examples from corridor-task-audit-2026-11-17.md.
## Loads only the pure contract; it does not instantiate the runtime scene.

const SELECTION: Script = preload("res://scripts/native_corridor_selection.gd")

var _assertions: int = 0
var _failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	_test_start()
	_test_drag()
	_test_samples()
	_test_parity()
	_test_bounds()
	if _failures > 0:
		push_error("NATIVE_CORRIDOR_SELECTION_SELF_TEST_FAILED assertions=%d failures=%d" % [
			_assertions, _failures])
		quit(1)
		return
	print("NATIVE_CORRIDOR_SELECTION_SELF_TEST_OK assertions=%d float32_intermediates=true" % _assertions)
	quit(0)


func _test_start() -> void:
	# VA 0x5680C7..0x568175: the 3.5 boundary must survive raw input handling.
	_check(SELECTION.snap_start(Vector2(3.49, 9.2)) == Vector2(1.5, 9.5),
		"3.49 stays at center 1.5")
	_check(SELECTION.snap_start(Vector2(3.5, 9.2)) == Vector2(5.5, 9.5),
		"3.5 moves to center 5.5")
	_check(SELECTION.snap_start(Vector2(7.49, 9.2)) == Vector2(5.5, 9.5),
		"7.49 stays at center 5.5")
	_check(SELECTION.snap_start(Vector2(7.5, 9.2)) == Vector2(9.5, 9.5),
		"7.5 moves to center 9.5")
	_check(SELECTION.snap_start(Vector2(0.01, 0.01)) == Vector2(1.5, 1.5),
		"positive map origin has center 1.5 without guessed offsets")
	# 3.4999999 rounds to 3.5 in IEEE binary32. A pure double formula differs.
	_check(SELECTION.snap_start(Vector2(3.4999999, 9.2)) == Vector2(5.5, 9.5),
		"native float32 input rounding at the 3.5 boundary")


func _test_drag() -> void:
	var anchor: Vector2 = Vector2(5.5, 9.5)
	_check(SELECTION.snap_drag(Vector2(10.0, 10.0), anchor) == Vector2(9.5, 9.5),
		"anchor (5.5,9.5), pointer (10,10): horizontal")
	_check(SELECTION.snap_drag(Vector2(10.0, 14.0), anchor) == Vector2(5.5, 13.5),
		"equal snapped displacement chooses vertical")
	_check(SELECTION.snap_drag(Vector2(10.0, 10.0), anchor) == Vector2(9.5, 9.5),
		"axis is recomputed from initial anchor without latched state")
	# Additional VA 0x5683E1..0x5683EF branches; not claimed to be normal S4 starts.
	_check(SELECTION.snap_drag(Vector2(12.0, 16.0), Vector2(7.5, 9.5)) == Vector2(11.5, 9.5),
		"odd X / even Y anchor restricts drag to horizontal")
	_check(SELECTION.snap_drag(Vector2(16.0, 16.0), Vector2(5.5, 11.5)) == Vector2(5.5, 15.5),
		"even X / odd Y anchor restricts drag to vertical")
	_check(anchor == Vector2(5.5, 9.5), "snap_drag leaves caller anchor unchanged")


func _test_samples() -> void:
	var bounds: Rect2i = Rect2i(Vector2i(1, 1), Vector2i(22, 14))
	var anchor: Vector2 = Vector2(5.5, 9.5)
	var expected_start: Array[Vector2i] = [
		Vector2i(5, 9), Vector2i(6, 9), Vector2i(5, 10), Vector2i(6, 10)]
	var start_samples: Array[Vector2i] = SELECTION.rasterize(anchor, anchor, bounds)
	_check(start_samples == expected_start, "single center selects the exact 2x2 sample set")
	var endpoint: Vector2 = SELECTION.snap_drag(Vector2(10.0, 10.0), anchor)
	var expected_stroke: Array[Vector2i] = [
		Vector2i(5, 9), Vector2i(6, 9), Vector2i(7, 9),
		Vector2i(8, 9), Vector2i(9, 9), Vector2i(10, 9),
		Vector2i(5, 10), Vector2i(6, 10), Vector2i(7, 10),
		Vector2i(8, 10), Vector2i(9, 10), Vector2i(10, 10)]
	var stroke_samples: Array[Vector2i] = SELECTION.rasterize(anchor, endpoint, bounds)
	_check(stroke_samples.size() == 12, "6x2 stroke contains 12 samples")
	_check(stroke_samples == expected_stroke, "6x2 stroke is exact and row-major")
	_check(SELECTION.rasterize(endpoint, anchor, bounds) == expected_stroke,
		"reversing endpoints preserves sample set and order")


func _test_parity() -> void:
	var bounds: Rect2i = Rect2i(Vector2i(1, 1), Vector2i(14, 14))
	# Samples {3,4} x {3,4} all have coarse indices (1,1), so all are blocked.
	var blocked: Array[Vector2i] = SELECTION.rasterize(Vector2(3.5, 3.5), Vector2(3.5, 3.5), bounds)
	_check(blocked.is_empty(), "odd / odd coarse indices are blocked")
	var expected_horizontal: Array[Vector2i] = [
		Vector2i(3, 1), Vector2i(4, 1), Vector2i(3, 2), Vector2i(4, 2)]
	_check(SELECTION.rasterize(Vector2(3.5, 1.5), Vector2(3.5, 1.5), bounds) == expected_horizontal,
		"odd X / even Y coarse indices are allowed")
	var expected_vertical: Array[Vector2i] = [
		Vector2i(1, 3), Vector2i(2, 3), Vector2i(1, 4), Vector2i(2, 4)]
	_check(SELECTION.rasterize(Vector2(1.5, 3.5), Vector2(1.5, 3.5), bounds) == expected_vertical,
		"even X / odd Y coarse indices are allowed")


func _test_bounds() -> void:
	var anchor: Vector2 = Vector2(5.5, 9.5)
	var endpoint: Vector2 = Vector2(9.5, 9.5)
	# Caller supplies [6,10) x [10,11); no second native border subtraction.
	var bounds: Rect2i = Rect2i(Vector2i(6, 10), Vector2i(4, 1))
	var expected: Array[Vector2i] = [
		Vector2i(6, 10), Vector2i(7, 10), Vector2i(8, 10), Vector2i(9, 10)]
	_check(SELECTION.rasterize(anchor, endpoint, bounds) == expected,
		"bounds include left/top and exclude right/bottom")
	var one_sample: Array[Vector2i] = [Vector2i(5, 9)]
	_check(SELECTION.rasterize(anchor, anchor, Rect2i(Vector2i(5, 9), Vector2i.ONE)) == one_sample,
		"one-sample bounds are not reduced by another cell")
	_check(SELECTION.rasterize(anchor, endpoint, Rect2i(Vector2i(6, 10), Vector2i(0, 1))).is_empty(),
		"empty bounds produce no samples")
	_check(SELECTION.rasterize(anchor, endpoint, Rect2i(Vector2i(20, 20), Vector2i(2, 2))).is_empty(),
		"disjoint bounds produce no samples")


func _check(condition: bool, description: String) -> void:
	_assertions += 1
	if not condition:
		_failures += 1
		push_error("NATIVE_CORRIDOR_SELECTION_ASSERT_FAILED " + description)
