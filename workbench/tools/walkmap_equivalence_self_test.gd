extends SceneTree
## Regression self-test for the walkmap performance work.
##
## It proves that the optimised native_walkmap produces byte-identical
## navigation state to the unmodified full rebuild:
##   * flags of every sample,
##   * unknown_samples of every sample and unknown_count,
##   * the representative of every map cell,
##   * is_newly_navigable of every sample (dig face availability),
##   * the result of the native path query for a series of targets.
## The strike series covers corridor, cave and wall strikes on the real
## multi_start_010 BlockDB data and contains many strikes that really change
## the navigation bytes. The native walkmap is never replaced by a plane or by
## an A* grid.

const HARNESS: Script = preload("res://tools/walkmap_harness.gd")
const BASELINE_WALKMAP: Script = preload("res://baseline/scripts/native_walkmap.gd")
const OPT_WALKMAP: Script = preload("res://scripts/native_walkmap.gd")
const BASE_FLAGS: Script = preload("res://baseline/scripts/native_walk_flags.gd")
const OPT_FLAGS: Script = preload("res://scripts/native_walk_flags.gd")
const FIX_DIG: Script = preload("res://scripts/native_fix_dig.gd")

## Corridor mark 3 (target 11), cave mark 10 (target 7), cave mark 8 (target 0).
## The points are the strikes that really change navigation bytes on the
## pristine map, plus the source fixture point (9,3) of
## native-terrain-strike-2026-11-17.md.
const STRIKES: Array = [
	[Vector2i(9, 3), 3], [Vector2i(9, 3), 10], [Vector2i(9, 3), 8],
	[Vector2i(20, 1), 3], [Vector2i(23, 1), 3],
]

## Cave and deep-cave strikes in virgin terrain.
const CAVE_STRIKES: Array = [
	[Vector2i(9, 3), 10], [Vector2i(9, 3), 8],
	[Vector2i(20, 1), 10], [Vector2i(23, 1), 10],
	[Vector2i(15, 2), 10], [Vector2i(16, 2), 8],
	[Vector2i(17, 2), 10], [Vector2i(18, 2), 8],
	[Vector2i(19, 2), 10], [Vector2i(20, 2), 8],
]

var assertions: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	_test_cached_predicate_matches_source()
	var narrow_stats: Dictionary = _test_strike_series(true)
	var full_stats: Dictionary = _test_strike_series(false)
	print("WALKMAP_EQUIVALENCE_SERIES narrow accepted=%d byte_changing=%d" % [
		int(narrow_stats["accepted"]), int(narrow_stats["byte_changing"])])
	print("WALKMAP_EQUIVALENCE_SERIES wide   accepted=%d byte_changing=%d" % [
		int(full_stats["accepted"]), int(full_stats["byte_changing"])])
	_expect(int(narrow_stats["byte_changing"]) >= 15, "narrow series changed too few navigation bytes")
	_expect(int(full_stats["byte_changing"]) >= 15, "wide series changed too few navigation bytes")
	print("WALKMAP_EQUIVALENCE_SELF_TEST_%s assertions=%d" % ["OK" if failures == 0 else "FAILED", assertions])
	quit(0 if failures == 0 else 1)


func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("WALKMAP_EQUIVALENCE_ASSERT " + message)


## Unit level: the cached predicate must answer exactly like the source
## predicate for every input, including missing heights and a closed gate.
func _test_cached_predicate_matches_source() -> void:
	var rng: RandomNumberGenerator = RandomNumberGenerator.new()
	rng.seed = 20261119
	var width: int = 96
	var rows: int = 96
	var heights: Dictionary = {}
	var gates: Dictionary = {}
	for y: int in range(-20, rows + 20):
		for x: int in range(-20, width + 20):
			var roll: int = rng.randi_range(0, 99)
			if roll < 6:
				continue
			var value: int = rng.randi_range(0, 18)
			if roll < 20:
				value = 14
			heights[Vector2i(x, y)] = value
	for y: int in range(0, rows):
		for x: int in range(0, width):
			if rng.randf() < 0.15:
				gates[Vector2i(x, y)] = 0x80
	var cached_heights: PackedInt32Array = PackedInt32Array()
	cached_heights.resize(width * rows)
	cached_heights.fill(-1)
	for key: Vector2i in heights:
		if key.x < 0 or key.y < 0 or key.x >= width or key.y >= rows:
			continue
		cached_heights[index_of(key, width)] = int(heights[key]) & 0xFF
	var host_heights: Callable = func(point: Vector2i) -> Variant: return heights.get(point)
	var host_gates: Callable = func(cell: Vector2i) -> Variant: return gates.get(cell)
	var compared: int = 0
	for y: int in range(0, rows):
		for x: int in range(0, width):
			var sample: Vector2i = Vector2i(x, y)
			var gate_cell: Vector2i = Vector2i((sample.x + 4) >> 3, (sample.y + 4) >> 3)
			var gate: Variant = gates.get(gate_cell)
			var source: Variant = BASE_FLAGS.terrain_sample_query(sample, host_heights, host_gates)
			var cached: Variant = OPT_FLAGS.terrain_sample_query_cached(sample, cached_heights,
				Vector2i.ZERO, width, rows, gate)
			compared += 1
			if str(source) != str(cached):
				_expect(false, "cached predicate differs at %s: source=%s cached=%s" % [
					str(sample), str(source), str(cached)])
				return
	_expect(compared > 8000, "cached predicate covered %d samples" % compared)


func index_of(point: Vector2i, width: int) -> int:
	return point.y * width + point.x


## The strike series of one equivalence run.
## Phase 1 digs caves in virgin terrain, phase 2 sweeps the upper half of the
## map in row-major corridor order. The sweep order matters: digging a region
## first is what makes later strikes open new navigable bytes, so the series
## really exercises the navigation byte changes.
func _strike_series() -> Array:
	var series: Array = []
	for entry: Array in CAVE_STRIKES:
		series.append(entry)
	for entry: Array in STRIKES:
		series.append(entry)
	for y: int in range(0, 12):
		for x: int in range(0, 44):
			series.append([Vector2i(x, y), 3])
	return series


## Integration level: run the same strike series on two independent worlds and
## compare the whole navigation state after every strike.
func _test_strike_series(narrow: bool) -> Dictionary:
	var base: RefCounted = HARNESS.new()
	var opt: RefCounted = HARNESS.new()
	if not base.build(BASELINE_WALKMAP):
		_expect(false, "baseline harness failed")
		return {"accepted": 0, "byte_changing": 0}
	if not opt.build(OPT_WALKMAP):
		_expect(false, "optimised harness failed")
		return {"accepted": 0, "byte_changing": 0}
	opt.walkmap.narrow_to_dirty_samples = narrow
	var base_bounds: Rect2i = base.sample_bounds()
	var opt_bounds: Rect2i = opt.sample_bounds()
	var accepted: int = 0
	var byte_changing: int = 0
	for entry: Array in _strike_series():
		var point: Vector2i = entry[0]
		var marks: int = int(entry[1])
		var base_patch: Dictionary = base.terrain_state.apply_accepted_step(point, 0, marks, true)
		var opt_patch: Dictionary = opt.terrain_state.apply_accepted_step(point, 0, marks, true)
		_expect(bool(base_patch["accepted"]) == bool(opt_patch["accepted"]),
			"strike %s acceptance diverged" % str(point))
		if not bool(base_patch["accepted"]):
			continue
		accepted += 1
		var base_report: Dictionary = base.walkmap.rebuild_after_strike(base_patch, base.heights(),
			base.gates(), base_bounds)
		var opt_report: Dictionary = opt.walkmap.rebuild_after_strike(opt_patch, opt.heights(),
			opt.gates(), opt_bounds)
		if int(base_report["changed"]) > 0:
			byte_changing += 1
		_expect(int(base_report["changed"]) == int(opt_report["changed"]),
			"strike %s changed count differs" % str(point))
		_expect(int(base_report["unknown_total"]) == int(opt_report["unknown_total"]),
			"strike %s unknown_total differs" % str(point))
		_expect(base.walkmap.flags == opt.walkmap.flags,
			"strike %s (narrow=%s): navigation bytes differ" % [str(point), str(narrow)])
		_expect(base.walkmap.unknown_samples == opt.walkmap.unknown_samples,
			"strike %s (narrow=%s): unknown samples differ" % [str(point), str(narrow)])
		_expect(str(base_report["rects"]) == str(opt_report["rects"]),
			"strike %s (narrow=%s): rebuilt rects differ" % [str(point), str(narrow)])
		_compare_paths(base, opt, point, narrow)
	_compare_derived_state(base, opt, narrow)
	return {"accepted": accepted, "byte_changing": byte_changing}


## The native path query must return the same result for both walkmaps.
func _compare_paths(base: RefCounted, opt: RefCounted, point: Vector2i, narrow: bool) -> void:
	var bounds: Rect2i = base.walkmap.sample_bounds
	var cell_bounds: Rect2i = Rect2i(0, 0, bounds.size.x / 8, bounds.size.y / 8)
	var base_flags_reader: Callable = func(sample: Vector2i) -> Variant: return base.walkmap.sample(sample)
	var opt_flags_reader: Callable = func(sample: Vector2i) -> Variant: return opt.walkmap.sample(sample)
	var base_heights: Callable = func(sample: Vector2i) -> Variant: return base.terrain_state.surface_depth(Vector2(sample) * 0.125)
	var opt_heights: Callable = func(sample: Vector2i) -> Variant: return opt.terrain_state.surface_depth(Vector2(sample) * 0.125)
	var differences: int = 0
	for query: Array in _path_queries():
		var base_result: Dictionary = FIX_DIG.solve(query[0], query[1], cell_bounds,
			base_flags_reader, base_heights, &"nearest_even")
		var opt_result: Dictionary = FIX_DIG.solve(query[0], query[1], cell_bounds,
			opt_flags_reader, opt_heights, &"nearest_even")
		if str(base_result) != str(opt_result):
			differences += 1
	_expect(differences == 0, "strike %s (narrow=%s): %d path results differ" % [
		str(point), str(narrow), differences])


## Representatives and dig face availability are derived from the same bytes,
## so they are compared once after the whole series.
func _compare_derived_state(base: RefCounted, opt: RefCounted, narrow: bool) -> void:
	var bounds: Rect2i = base.walkmap.sample_bounds
	var representative_diff: int = 0
	for cy: int in range(0, int(bounds.size.y / 8)):
		for cx: int in range(0, int(bounds.size.x / 8)):
			var cell: Vector2i = Vector2i(bounds.position.x / 8 + cx, bounds.position.y / 8 + cy)
			if str(base.walkmap.cell_representative(cell)) != str(opt.walkmap.cell_representative(cell)):
				representative_diff += 1
	_expect(representative_diff == 0, "narrow=%s: %d cell representatives differ" % [
		str(narrow), representative_diff])
	var nav_diff: int = 0
	for y: int in range(0, bounds.size.y):
		for x: int in range(0, bounds.size.x):
			var sample: Vector2i = Vector2i(bounds.position.x + x, bounds.position.y + y)
			if bool(base.walkmap.is_newly_navigable(sample)) != bool(opt.walkmap.is_newly_navigable(sample)):
				nav_diff += 1
	_expect(nav_diff == 0, "narrow=%s: %d dig face availability verdicts differ" % [
		str(narrow), nav_diff])


func _path_queries() -> Array:
	return [
		[Vector3(1.5, 0.5, 0.0), Vector3(1.0, 0.25, -14.5)],
		[Vector3(10.25, 2.125, 0.0), Vector3(9.0, 1.0, -14.5)],
		[Vector3(20.75, 8.5, 0.0), Vector3(16.0, 5.0, -14.5)],
		[Vector3(3.875, 12.25, 0.0), Vector3(7.0, 11.0, -14.5)],
		[Vector3(25.5, 17.75, 0.0), Vector3(22.0, 16.0, -14.5)],
	]
