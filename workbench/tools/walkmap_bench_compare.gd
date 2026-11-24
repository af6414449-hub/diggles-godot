extends SceneTree
## Full-vs-optimised comparison of native_walkmap.rebuild_after_strike on the
## real multi_start_010 BlockDB data.
##
## Variants (each rebuilt in an independent world, same strike series):
##   full   - the unmodified rebuild (baseline/scripts/native_walkmap.gd),
##            every probe of every sample is read through the host Callable.
##   cached - the optimised rebuild with the plain height Callable, the
##            BlockDB surface heights come from the incremental cache and the
##            recompute is narrowed to the samples a strike can change.
##   bulk   - the optimised rebuild with the optional per-cell bulk accessor,
##            one host call returns the whole 8x8 surface block of a cell.
##
## Every variant is measured R times; the median run is reported, because a
## single run of a multi-second benchmark is dominated by machine noise.

const HARNESS: Script = preload("res://tools/walkmap_harness.gd")
const BASELINE_WALKMAP: Script = preload("res://baseline/scripts/native_walkmap.gd")
const OPT_WALKMAP: Script = preload("res://scripts/native_walkmap.gd")

const REPEATS: int = 5

## The same series the equivalence self-test uses: cave strikes in virgin
## terrain, corridor strikes, then a row-major sweep of the upper half of the
## map. The sweep is the part that really opens new navigable bytes.
const CAVE_STRIKES: Array = [
	[Vector2i(9, 3), 10], [Vector2i(9, 3), 8],
	[Vector2i(20, 1), 10], [Vector2i(23, 1), 10],
	[Vector2i(15, 2), 10], [Vector2i(16, 2), 8],
	[Vector2i(17, 2), 10], [Vector2i(18, 2), 8],
	[Vector2i(19, 2), 10], [Vector2i(20, 2), 8],
]

const CORRIDOR_STRIKES: Array = [
	[Vector2i(9, 3), 3], [Vector2i(9, 3), 10], [Vector2i(9, 3), 8],
	[Vector2i(20, 1), 3], [Vector2i(23, 1), 3],
]

var assertions: int = 0
var failures: int = 0
var reference_flags: PackedByteArray = PackedByteArray()
var reference_unknown: PackedByteArray = PackedByteArray()


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var full_runs: Array = []
	var cached_runs: Array = []
	var bulk_runs: Array = []
	for repeat_index: int in range(REPEATS):
		full_runs.append(_run_variant(&"full"))
		cached_runs.append(_run_variant(&"cached"))
		bulk_runs.append(_run_variant(&"bulk"))
	var full_result: Dictionary = _median(full_runs)
	var cached_result: Dictionary = _median(cached_runs)
	var bulk_result: Dictionary = _median(bulk_runs)
	var full_us: int = int(full_result["total_us"])
	var cached_us: int = int(cached_result["total_us"])
	var bulk_us: int = int(bulk_result["total_us"])
	print("BENCH_COMPARE repeats=%d strikes=%d accepted=%d byte_changing=%d" % [
		REPEATS, int(full_result["strikes"]), int(full_result["accepted"]),
		int(full_result["byte_changing"])])
	print("BENCH_COMPARE full    total_us=%d avg_us=%d max_us=%d height_calls=%d gate_calls=%d cell_calls=%d rebuilt=%d" % [
		full_us, int(full_result["avg_us"]), int(full_result["max_us"]),
		int(full_result["height_calls"]), int(full_result["gate_calls"]), int(full_result["cell_calls"]),
		int(full_result["rebuilt"])])
	print("BENCH_COMPARE cached  total_us=%d avg_us=%d max_us=%d height_calls=%d gate_calls=%d cell_calls=%d rebuilt=%d skipped=%d speedup=%.2fx" % [
		cached_us, int(cached_result["avg_us"]), int(cached_result["max_us"]),
		int(cached_result["height_calls"]), int(cached_result["gate_calls"]), int(cached_result["cell_calls"]),
		int(cached_result["rebuilt"]), int(cached_result["skipped"]),
		float(full_us) / maxf(float(cached_us), 1.0)])
	print("BENCH_COMPARE bulk    total_us=%d avg_us=%d max_us=%d height_calls=%d gate_calls=%d cell_calls=%d rebuilt=%d skipped=%d speedup=%.2fx" % [
		bulk_us, int(bulk_result["avg_us"]), int(bulk_result["max_us"]),
		int(bulk_result["height_calls"]), int(bulk_result["gate_calls"]), int(bulk_result["cell_calls"]),
		int(bulk_result["rebuilt"]), int(bulk_result["skipped"]),
		float(full_us) / maxf(float(bulk_us), 1.0)])
	print("BENCH_COMPARE host_call_reduction cached=%.1fx bulk=%.1fx" % [
		float(full_result["height_calls"]) / maxf(float(cached_result["height_calls"]), 1.0),
		float(full_result["height_calls"]) / maxf(float(bulk_result["height_calls"]), 1.0)])
	print("BENCH_COMPARE_DONE assertions=%d failures=%d" % [assertions, failures])
	quit(0 if failures == 0 else 1)


func _strike_series() -> Array:
	var series: Array = []
	for entry: Array in CAVE_STRIKES:
		series.append(entry)
	for entry: Array in CORRIDOR_STRIKES:
		series.append(entry)
	for y: int in range(0, 12):
		for x: int in range(0, 44):
			series.append([Vector2i(x, y), 3])
	return series


func _run_variant(kind: StringName) -> Dictionary:
	var harness: RefCounted = HARNESS.new()
	var walkmap_script: Script = BASELINE_WALKMAP if kind == &"full" else OPT_WALKMAP
	if not harness.build(walkmap_script):
		push_error("BENCH_FAILED harness " + str(kind))
		return {"total_us": 0, "avg_us": 0, "max_us": 0, "strikes": 0, "height_calls": 0,
			"gate_calls": 0, "cell_calls": 0, "accepted": 0, "byte_changing": 0,
			"rebuilt": 0, "skipped": 0}
	var bounds: Rect2i = harness.sample_bounds()
	var raw_heights: Callable = harness.heights()
	var raw_gates: Callable = harness.gates()
	var raw_cells: Callable = harness.surface_cells()
	# Dictionaries are reference types, so the counters survive the lambda copy.
	var counters: Dictionary = {"height": 0, "gate": 0, "cell": 0}
	var heights: Callable = func(sample: Vector2i) -> Variant:
		counters["height"] = int(counters["height"]) + 1
		return raw_heights.call(sample)
	var gates: Callable = func(cell: Vector2i) -> Variant:
		counters["gate"] = int(counters["gate"]) + 1
		return raw_gates.call(cell)
	var cells: Callable = func(cell: Vector2i) -> Variant:
		counters["cell"] = int(counters["cell"]) + 1
		return raw_cells.call(cell)
	var total_us: int = 0
	var worst: int = 0
	var strikes: int = 0
	var accepted: int = 0
	var byte_changing: int = 0
	var rebuilt_total: int = 0
	var skipped_total: int = 0
	var changed_total: int = 0
	for entry: Array in _strike_series():
		var point: Vector2i = entry[0]
		var marks: int = int(entry[1])
		var patch: Dictionary = harness.terrain_state.apply_accepted_step(point, 0, marks, true)
		if not bool(patch["accepted"]):
			continue
		accepted += 1
		var started: int = Time.get_ticks_usec()
		var report: Dictionary = {}
		if kind == &"full":
			report = harness.walkmap.rebuild_after_strike(patch, heights, gates, bounds)
		elif kind == &"bulk":
			report = harness.walkmap.rebuild_after_strike(patch, heights, gates, bounds, cells)
		else:
			report = harness.walkmap.rebuild_after_strike(patch, heights, gates, bounds)
		var elapsed: int = Time.get_ticks_usec() - started
		total_us += elapsed
		worst = maxi(worst, elapsed)
		strikes += 1
		rebuilt_total += int(report["rebuilt"])
		changed_total += int(report["changed"])
		if int(report["changed"]) > 0:
			byte_changing += 1
		if report.has("skipped"):
			skipped_total += int(report["skipped"])
	if kind == &"full":
		reference_flags = harness.walkmap.flags.duplicate()
		reference_unknown = harness.walkmap.unknown_samples.duplicate()
	else:
		_expect(harness.walkmap.flags == reference_flags, "%s changed the navigation bytes" % str(kind))
		_expect(harness.walkmap.unknown_samples == reference_unknown, "%s changed the unknown samples" % str(kind))
	print("BENCH_RUN kind=%s strikes=%d accepted=%d byte_changing=%d rebuilt=%d skipped=%d changed=%d total_us=%d max_us=%d height_calls=%d gate_calls=%d cell_calls=%d" % [
		str(kind), strikes, accepted, byte_changing, rebuilt_total, skipped_total, changed_total,
		total_us, worst, int(counters["height"]), int(counters["gate"]), int(counters["cell"])])
	return {"total_us": total_us, "avg_us": total_us / maxi(strikes, 1), "max_us": worst,
		"strikes": strikes, "height_calls": int(counters["height"]),
		"gate_calls": int(counters["gate"]), "cell_calls": int(counters["cell"]),
		"accepted": accepted, "byte_changing": byte_changing,
		"rebuilt": rebuilt_total, "skipped": skipped_total}


func _median(runs: Array) -> Dictionary:
	# Median by total time; the matching run supplies the derived counters.
	var sorted: Array = runs.duplicate()
	sorted.sort_custom(func(a: Dictionary, b: Dictionary) -> bool:
		return int(a["total_us"]) < int(b["total_us"]))
	return sorted[sorted.size() / 2]


func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("BENCH_ASSERT " + message)
