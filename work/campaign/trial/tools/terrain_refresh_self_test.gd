extends SceneTree
var checks: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func check(condition: bool, label: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		printerr("FAIL ",label)


func _run() -> void:
	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	subject.extended_world = false
	subject.autonomous_dwarf_work = false
	root.add_child(subject)
	await process_frame
	# Keep normal scene processing enabled: a struck terrain chunk must update
	# immediately, without waiting for the worker/nav state to diverge.
	check(subject.is_processing(), "normal runtime processing enabled")
	var before_nav: AStarGrid2D = subject.navigation_grid
	var before_refreshes: int = subject.terrain_refresh_count
	var strike_ms: Array[float] = []
	for point: Vector2i in [Vector2i(1,15),Vector2i(2,15),Vector2i(1,16)]:
		var started: int = Time.get_ticks_usec()
		check(subject.native_mark_corridor_cell(0,point) and subject.native_dig_apply_cell(0,point), "accepted queued strike")
		strike_ms.append(float(Time.get_ticks_usec()-started)/1000.0)
	check(subject.terrain_state.revision == 3, "native state changes without waiting for visual batch")
	check(not subject.terrain_refresh_pending and subject.terrain_refresh_count == before_refreshes+3,
		"every strike refreshes only its visible terrain chunk immediately")
	check(subject.navigation_grid == before_nav and subject.navigation_refresh_pending,
		"expensive broad navigation rebuild is deferred after a visible local update")
	for frame: int in range(8):
		subject._process(0.1)
	check(subject.navigation_grid != before_nav and not subject.navigation_refresh_pending,
		"navigation refreshes once the digging burst has settled")
	subject.queue_free()
	await process_frame
	print("TERRAIN_REFRESH_SELF_TEST checks=",checks," failures=",failures," strike_ms=",strike_ms)
	quit(0 if failures == 0 else 1)
