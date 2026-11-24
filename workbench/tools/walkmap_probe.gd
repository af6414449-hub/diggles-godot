extends SceneTree
## Probe: which strike points are accepted on the pristine map, and how long the
## current native_walkmap.rebuild_after_strike takes for each of them.

const HARNESS: Script = preload("res://tools/walkmap_harness.gd")

const MARKS_CORRIDOR: int = 3      # target 11
const MARKS_CAVE_7: int = 10       # target 7
const MARKS_CAVE_0: int = 8        # target 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var harness: RefCounted = HARNESS.new()
	if not harness.build():
		print("PROBE_FAILED to build harness")
		quit(1)
		return
	print("PROBE world sample bounds = %s" % str(harness.sample_bounds()))
	print("PROBE walkmap sample bounds = %s" % str(harness.walkmap.sample_bounds))
	var corridor: Array[Vector2i] = []
	var cave7: Array[Vector2i] = []
	var cave0: Array[Vector2i] = []
	for y: int in range(0, 24):
		for x: int in range(0, 44):
			var point: Vector2i = Vector2i(x, y)
			if bool(harness.terrain_state.preview_accepted_step(point, 0, MARKS_CORRIDOR, true)["accepted"]):
				corridor.append(point)
			if bool(harness.terrain_state.preview_accepted_step(point, 0, MARKS_CAVE_7, true)["accepted"]):
				cave7.append(point)
			if bool(harness.terrain_state.preview_accepted_step(point, 0, MARKS_CAVE_0, true)["accepted"]):
				cave0.append(point)
	print("PROBE corridor_candidates=%d" % corridor.size())
	print("PROBE cave7_candidates=%d" % cave7.size())
	print("PROBE cave0_candidates=%d" % cave0.size())
	var sample: Array[Vector2i] = []
	for index: int in range(mini(12, corridor.size())):
		sample.append(corridor[index])
	print("PROBE corridor_sample=%s" % str(sample))
	print("PROBE cave7_sample=%s" % str(cave7.slice(0, 8)))
	print("PROBE cave0_sample=%s" % str(cave0.slice(0, 8)))
	quit(0)
