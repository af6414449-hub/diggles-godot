extends SceneTree
## Baseline profile of native_walkmap.rebuild_after_strike on the real
## multi_start_010 map data: wall-clock per strike plus the volume of host
## height/gate lookups that the current implementation performs.

const HARNESS: Script = preload("res://tools/walkmap_harness.gd")

var height_calls: int = 0
var gate_calls: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var harness: RefCounted = HARNESS.new()
	if not harness.build():
		print("BENCH_FAILED to build harness")
		quit(1)
		return
	var raw_heights: Callable = harness.heights()
	var raw_gates: Callable = harness.gates()
	var counting_heights: Callable = func(sample: Vector2i) -> Variant:
		height_calls += 1
		return raw_heights.call(sample)
	var counting_gates: Callable = func(cell: Vector2i) -> Variant:
		gate_calls += 1
		return raw_gates.call(cell)
	var bounds: Rect2i = harness.sample_bounds()
	var points: Array[Vector2i] = [Vector2i(13, 1), Vector2i(20, 2), Vector2i(9, 3),
		Vector2i(16, 5), Vector2i(24, 6), Vector2i(11, 8), Vector2i(30, 9),
		Vector2i(18, 12), Vector2i(7, 15), Vector2i(27, 17)]
	var samples: Array[int] = []
	var times: Array[int] = []
	var total_height_calls: int = 0
	var total_gate_calls: int = 0
	var total_samples: int = 0
	for point: Vector2i in points:
		for level: int in range(4):
			var patch: Dictionary = harness.strike(point, 0, 3)
			if not bool(patch["accepted"]):
				break
			height_calls = 0
			gate_calls = 0
			var started: int = Time.get_ticks_usec()
			var report: Dictionary = harness.walkmap.rebuild_after_strike(patch, counting_heights,
				counting_gates, bounds)
			var elapsed: int = Time.get_ticks_usec() - started
			times.append(elapsed)
			total_height_calls += height_calls
			total_gate_calls += gate_calls
			var rebuilt: int = int(report["rebuilt"])
			total_samples += rebuilt
			samples.append(rebuilt)
			print("BENCH point=%s level=%d rebuilt=%d changed=%d unknown=%d height_calls=%d gate_calls=%d us=%d" % [
				str(point), level, rebuilt, int(report["changed"]), int(report["unknown_total"]),
				height_calls, gate_calls, elapsed])
	print("BENCH_SUMMARY strikes=%d samples_total=%d height_calls_total=%d gate_calls_total=%d" % [
		times.size(), total_samples, total_height_calls, total_gate_calls])
	var total_us: int = 0
	var worst: int = 0
	for value: int in times:
		total_us += value
		worst = maxi(worst, value)
	print("BENCH_SUMMARY total_us=%d avg_us=%d max_us=%d" % [total_us, total_us / maxi(times.size(), 1), worst])
	quit(0)
