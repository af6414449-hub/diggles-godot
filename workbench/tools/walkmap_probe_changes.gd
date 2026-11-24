extends SceneTree
## Probe: which strikes actually change the navigation bytes of the map.
## A regression series that never changes a byte would not prove anything.

const HARNESS: Script = preload("res://tools/walkmap_harness.gd")
const BASELINE_WALKMAP: Script = preload("res://baseline/scripts/native_walkmap.gd")

var hits: Array[Vector2i] = []
var accepted: int = 0
var changed_strikes: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var harness: RefCounted = HARNESS.new()
	if not harness.build(BASELINE_WALKMAP):
		print("PROBE_CHANGES_FAILED")
		quit(1)
		return
	var bounds: Rect2i = harness.sample_bounds()
	for y: int in range(0, 24):
		for x: int in range(0, 44):
			var point: Vector2i = Vector2i(x, y)
			var patch: Dictionary = harness.terrain_state.apply_accepted_step(point, 0, 3, true)
			if not bool(patch["accepted"]):
				continue
			accepted += 1
			var report: Dictionary = harness.walkmap.rebuild_after_strike(patch, harness.heights(),
				harness.gates(), bounds)
			if int(report["changed"]) > 0:
				changed_strikes += 1
				hits.append(point)
	print("PROBE_CHANGES accepted=%d changed_strikes=%d" % [accepted, changed_strikes])
	print("PROBE_CHANGES hits=%s" % str(hits.slice(0, 24)))
	quit(0)
