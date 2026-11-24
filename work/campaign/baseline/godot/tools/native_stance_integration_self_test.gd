extends SceneTree

var assertions: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var scene: PackedScene = load("res://scenes/multiplayer_test.tscn")
	var subject: Node3D = scene.instantiate()
	subject.autonomous_dwarf_work = false # Isolate the manual-action scenario.
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	await process_frame
	if subject.get_script() == null:
		push_error("NATIVE_STANCE_INTEGRATION_SELF_TEST_FAILED controller missing")
		quit(1)
		return
	subject.set_process(false)
	_expect(subject.native_world.bounds == Rect2i(0, 0, 600, 600), "template dimensions still used as world bounds")
	_expect(subject.native_world.template_offset in [Vector2i(92, 84), Vector2i(200, 108)], "unverified authored context offset")
	var initial: Dictionary = subject.query_native_dig_stance(Vector3(2, 15, 13), Vector3(3, -14.5, 12))
	_expect(initial["status"] == "ok" and initial["point"] == Vector3(2.875, 13.875, 12), "original PMP stance differs")
	var world_point: Vector3 = initial["world_point"]
	_expect(subject.native_world.to_local(world_point) == initial["point"], "world/local stance conversion changed renderer placement")
	var flags_before: PackedByteArray = subject.native_walkmap.flags.duplicate()
	_expect(subject.native_mark_corridor_cell(0, Vector2i(1, 15)), "source mutation fixture rejected")
	_expect(subject.native_dig_apply_cell(0, Vector2i(1, 15)), "source mutation failed")
	var update: Dictionary = subject.native_walkmap.last_rebuild
	_expect(int(update["changed"]) > 0, "navigation kept stale PMP bytes after excavation")
	var changes: Array = []
	var outside_unchanged: bool = true
	var width: int = subject.native_walkmap.sample_bounds.size.x
	for index: int in range(flags_before.size()):
		var point: Vector2i = Vector2i(index % width, floori(float(index) / float(width)))
		var inside: bool = false
		for rect: Rect2i in update["rects"]:
			inside = inside or rect.has_point(point)
		var current: Variant = subject.native_walkmap.sample(point)
		if not inside:
			outside_unchanged = outside_unchanged and current != null and int(current) == int(flags_before[index])
		elif current != null and int(current) != int(flags_before[index]) and changes.size() < 20:
			changes.append([point.x, point.y, int(flags_before[index]), int(current)])
	_expect(outside_unchanged, "dirty navigation changed samples outside native dependency rect")
	_expect(subject.native_walkmap.revision == 1, "navigation revision not tied to terrain mutation")
	_expect(subject.native_walkmap.unknown_count > 0, "unimported surrounding terrain was fabricated")
	var after: Dictionary = subject.query_native_dig_stance(Vector3(2, 15, 13), Vector3(2, -14.5, 12))
	_expect(after["status"] == "ok" and after["cache_stage"] == "native_terrain_rebuilt", "updated native stance did not read rebuilt cache")
	print("NATIVE_NAVIGATION_DELTA " + str(changes))
	# A complete 2x2 stroke at the crop edge now belongs to the surrounding world.
	# One diagnostic strike above is already complete; the next assignment must
	# finish the other three, including local X=1 which was previously clipped.
	var points: Array[Vector2i] = [Vector2i(2, 15), Vector2i(1, 16), Vector2i(2, 16)]
	for point: Vector2i in points:
		_expect(subject.native_mark_corridor_cell(0, point), "edge stroke source point rejected")
	var worker: Node3D = subject.dwarf_nodes[0]
	_expect(subject.assign_dwarf_dig(worker, Vector2i(2, 15)), "edge continuation not assigned")
	for step: int in range(1200):
		subject.call("_process", 0.05)
		if not subject.dwarf_dig_jobs.has(worker):
			break
	_expect(subject.terrain_state.revision == 4, "source world context did not finish all four crop-edge points")
	_expect(subject.native_mark_nibbles.is_empty(), "source crop edge left an unreachable border mark")
	_expect(subject.dig_action_completions == 3, "source-context continuation callback count")
	_expect(subject._has_source_floor(Vector2(worker.position.x, worker.position.z)), "source requests moved actor off its supported floor")
	if failures == 0:
		print("NATIVE_STANCE_INTEGRATION_SELF_TEST_OK assertions=%d total_mutations=4" % assertions)
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var capture: int = args.find("--stance-capture-dir")
	if failures == 0 and capture >= 0 and capture + 1 < args.size():
		subject.distance = 36.0
		await subject._capture_views(args[capture + 1])
		return
	subject.queue_free()
	quit(0 if failures == 0 else 1)


func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("NATIVE_STANCE_INTEGRATION_SELF_TEST_FAILED " + message)
