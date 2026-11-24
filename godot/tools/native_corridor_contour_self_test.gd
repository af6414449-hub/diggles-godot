extends SceneTree
## Godot --headless --path godot --script res://tools/native_corridor_contour_self_test.gd
## Independent source-branch expectations, not scene/controller integration.

const CONTOUR: Script = preload("res://scripts/native_corridor_contour.gd")
const EPSILON: float = 0.00001
const EXPECTED_TRIANGLES: Array[int] = [0, 12, 12, 4, 12, 4, 24, 8, 12, 24, 4, 8, 4, 8, 8, 2]

var _assertions: int = 0
var _failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	_test_masks()
	_test_corner_order()
	_test_source_writers()
	_test_assembly()
	if _failures > 0:
		push_error("NATIVE_CORRIDOR_CONTOUR_SELF_TEST_FAILED assertions=%d failures=%d" % [_assertions, _failures])
		quit(1)
		return
	print("NATIVE_CORRIDOR_CONTOUR_SELF_TEST_OK assertions=%d masks=16 stamp_triangles=66" % _assertions)
	quit(0)


func _test_masks() -> void:
	for mask: int in range(16):
		var triangles: PackedVector2Array = CONTOUR.cell_triangles(mask)
		_expect(triangles.size() == EXPECTED_TRIANGLES[mask] * 3, "native triangle count mask=%d" % mask)
		var bounded: bool = true
		for point: Vector2 in triangles:
			bounded = bounded and is_finite(point.x) and is_finite(point.y)
			bounded = bounded and point.x >= -EPSILON and point.y >= -EPSILON
			bounded = bounded and point.x <= 1.0 + EPSILON and point.y <= 1.0 + EPSILON
		_expect(bounded, "source unit-cell bounds mask=%d" % mask)
	_expect(CONTOUR.cell_triangles(-1).is_empty(), "no invented case for invalid mask")
	_expect(CONTOUR.cell_triangles(16).is_empty(), "no mask aliasing")


func _test_corner_order() -> void:
	var origin: Vector2i = Vector2i(5, 9)
	var corners: Array[Vector2i] = [origin, origin + Vector2i.RIGHT,
		origin + Vector2i.DOWN, origin + Vector2i.ONE]
	for corner: int in range(4):
		var samples: Dictionary = {corners[corner]: 3}
		_expect(CONTOUR.cell_mask(samples, origin) == (1 << corner), "TL/TR/BL/BR bit=%d" % corner)


func _test_source_writers() -> void:
	# 0x56A9BC..0x56AE19: literal quad and original index order.
	var full: PackedVector2Array = PackedVector2Array([Vector2(0, 0), Vector2(1, 0), Vector2(0, 1),
		Vector2(1, 0), Vector2(0, 1), Vector2(1, 1)])
	_expect(CONTOUR.cell_triangles(15) == full, "full quad source indices 012 123")
	# Mask 3, 0x56853E onward: strip plus overlapping fill, not a half-cell guess.
	var top: PackedVector2Array = PackedVector2Array([
		Vector2(0, 0.30), Vector2(1, 0.30), Vector2(0, 0.49),
		Vector2(1, 0.30), Vector2(0, 0.49), Vector2(1, 0.49),
		Vector2(0, 0.49), Vector2(1, 0.49), Vector2(0, 0),
		Vector2(1, 0.49), Vector2(0, 0), Vector2(1, 0)])
	_expect(_arrays_close(CONTOUR.cell_triangles(3), top), "native .30/.49 straight edge and fill")
	# 0x56A027..0x56A4CF: quarter arc has 4 segments, two radii, source trig angles.
	var arc: PackedVector2Array = CONTOUR.cell_triangles(1)
	_expect(_close(arc[0], Vector2.ZERO), "single-corner fan origin")
	_expect(_close(arc[1], Vector2(0, 0.49)), "outer radius .49")
	_expect(_close(arc[2], Vector2(0.1875148863, 0.4527009726)), "pi/8 outer arc sample")
	_expect(_close(arc[7], Vector2(0, 0.30)), "inner radius .30 retained")
	_expect(_diagonal_is_separate(6), "mask 6 has two separate fans, no bridge")
	_expect(_diagonal_is_separate(9), "mask 9 has two separate fans, no bridge")
	# 0x569279..0x569726: middle radial sample has factor sqrt(2), not a circular fillet.
	var concave: PackedVector2Array = CONTOUR.cell_triangles(7)
	_expect(_close(concave[2], Vector2(0.49, 0.49)), "three-corner native middle miter")


func _test_assembly() -> void:
	_expect(CONTOUR.build_triangles({}).is_empty(), "empty sample set")
	var single: Dictionary = {Vector2i(5, 9): 3}
	_expect(CONTOUR.build_triangles(single).size() == 48 * 3, "single sample touches four unit cells")
	var samples: Dictionary = {Vector2i(5, 9): 3, Vector2i(6, 9): 3,
		Vector2i(5, 10): 3, Vector2i(6, 10): 3}
	var triangles: PackedVector2Array = CONTOUR.build_triangles(samples)
	_expect(triangles.size() == 66 * 3, "2x2 samples produce nine source cells / 66 triangles")
	var minimum: Vector2 = Vector2(INF, INF)
	var maximum: Vector2 = Vector2(-INF, -INF)
	for point: Vector2 in triangles:
		minimum = Vector2(minf(minimum.x, point.x), minf(minimum.y, point.y))
		maximum = Vector2(maxf(maximum.x, point.x), maxf(maximum.y, point.y))
	_expect(_close(minimum, Vector2(4.51, 8.51)), "static contour minimum from .49 source radius")
	_expect(_close(maximum, Vector2(6.49, 10.49)), "static contour maximum from .49 source radius")
	var reversed: Dictionary = {Vector2i(6, 10): true, Vector2i(5, 10): true,
		Vector2i(6, 9): true, Vector2i(5, 9): true}
	_expect(CONTOUR.build_triangles(reversed) == triangles, "deterministic sample order / values opaque")
	var stroke: Dictionary = {}
	for sample_y: int in range(9, 11):
		for sample_x: int in range(5, 11):
			stroke[Vector2i(sample_x, sample_y)] = 3
	_expect(CONTOUR.build_triangles(stroke).size() == 106 * 3, "6x2 sample stroke native case composition")
	var far_sample: Dictionary = {Vector2i(43, 23): 3}
	var far_triangles: PackedVector2Array = CONTOUR.build_triangles(far_sample)
	_expect(far_triangles.size() == 48 * 3, "44x24 map scale preserves topology")


func _diagonal_is_separate(mask: int) -> bool:
	var triangles: PackedVector2Array = CONTOUR.cell_triangles(mask)
	for first: int in range(0, triangles.size(), 3):
		var first_region: bool = true
		var second_region: bool = true
		for offset: int in range(3):
			var point: Vector2 = triangles[first + offset]
			if mask == 6:
				first_region = first_region and point.x >= 0.5 - EPSILON and point.y <= 0.5 + EPSILON
				second_region = second_region and point.x <= 0.5 + EPSILON and point.y >= 0.5 - EPSILON
			else:
				first_region = first_region and point.x <= 0.5 + EPSILON and point.y <= 0.5 + EPSILON
				second_region = second_region and point.x >= 0.5 - EPSILON and point.y >= 0.5 - EPSILON
		if not first_region and not second_region:
			return false
	return true


func _arrays_close(actual: PackedVector2Array, expected: PackedVector2Array) -> bool:
	if actual.size() != expected.size():
		return false
	for index: int in range(actual.size()):
		if not _close(actual[index], expected[index]):
			return false
	return true


func _close(actual: Vector2, expected: Vector2) -> bool:
	return absf(actual.x - expected.x) <= EPSILON and absf(actual.y - expected.y) <= EPSILON


func _expect(condition: bool, description: String) -> void:
	_assertions += 1
	if not condition:
		_failures += 1
		push_error("NATIVE_CORRIDOR_CONTOUR_ASSERT_FAILED " + description)
