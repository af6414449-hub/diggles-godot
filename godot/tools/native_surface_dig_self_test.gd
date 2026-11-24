extends SceneTree
var assertions: int = 0
var failures: int = 0

func _initialize() -> void:
	call_deferred("_run")

func _run() -> void:
	var packed: PackedScene = load("res://scenes/multiplayer_test.tscn")
	var subject: Node3D = packed.instantiate()
	subject.autonomous_dwarf_work = false # Isolate the manual-action scenario.
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	await process_frame
	if subject.get_script() == null:
		push_error("NATIVE_SURFACE_DIG_SELF_TEST_FAILED controller missing")
		quit(1)
		return
	subject.set_process(false)
	var worker: Node3D = subject.dwarf_nodes[0]
	var initial: Vector3 = worker.position
	var normalized: Dictionary = subject.query_native_walk_target(Vector3(2.875,13.875,12))
	_expect(normalized["status"] == "ok" and bool(normalized["found_navigation"]), "original vector_fixdig result did not normalize to a source navigation sample")
	_expect(normalized["point"] == Vector3(2.875,14.375,12), "independent PMP vector_fix sample differs")
	print("SOURCE_VECTOR_FIX_PMP_CASE ", normalized)
	var points: Array[Vector2i] = [Vector2i(23,2), Vector2i(21,2)]
	for commit: int in range(3):
		subject.native_dig_groups.finish_commit(0)
	for point: Vector2i in points:
		_expect(subject.native_mark_corridor_cell(0, point), "upper corridor source point rejected")
	var facts: Dictionary = subject.terrain_state.facts.duplicate(true)
	_expect(subject.assign_dwarf_dig(worker, points[0]), "surface dig approach was not assigned")
	_expect(worker.position == initial and subject.terrain_state.facts == facts, "planning changed actor position or terrain")
	_expect(subject.dwarf_dig_jobs[worker]["planner"] == "source_fixdig_vectorfix_surface_route", "surface task bypassed original target chain")
	for step: int in range(20):
		subject.call("_process", 0.05)
	_expect(subject.terrain_state.revision == 0 and subject.dig_action_completions == 0, "approach mutated terrain")
	subject._cancel_dwarf_dig(worker)
	_expect(not subject.dwarf_dig_jobs.has(worker) and not subject.dwarf_walk_actions.has(worker), "cancelled approach leaked worker action")
	_expect(subject.native_mark_nibbles.size() == 2 and subject.terrain_state.facts == facts, "cancelled approach consumed marks or source blocks")
	subject.dig_selection_history.clear()
	_expect(subject.assign_dwarf_dig(worker, points[0]), "cancelled surface job could not be reassigned")
	var climbed: bool = false
	var work_seen: bool = false
	var maximum_step: float = 0.0
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var capture_index: int = args.find("--surface-dig-capture-dir")
	var directory: String = args[capture_index+1] if capture_index >= 0 and capture_index+1 < args.size() else ""
	for step: int in range(10000):
		var before: Vector3 = worker.position
		subject.call("_process", 0.05)
		maximum_step = maxf(maximum_step, before.distance_to(worker.position))
		climbed = climbed or worker.position.y > -5.0
		if subject.dwarf_dig_jobs.has(worker) and subject.dwarf_dig_jobs[worker]["phase"] == "work" \
				and int(subject.dwarf_dig_jobs[worker]["frame"]) >= 4 and not work_seen:
			work_seen = true
			_expect(str(subject.dwarf_dig_jobs[worker]["clip"]).begins_with("kletter_hack_"), "wall action used ground digging frames")
			_expect(subject.terrain_state.revision == 0, "terrain changed before work clip completed")
			if not directory.is_empty():
				DirAccess.make_dir_recursive_absolute(directory)
				subject.focus = worker.position
				subject.distance = 8.0
				subject._update_camera()
				await process_frame
				await RenderingServer.frame_post_draw
				var result: Error = root.get_texture().get_image().save_png(directory.path_join("wall_dig.png"))
				_expect(result == OK, "wall digging capture failed")
		if not subject.dwarf_dig_jobs.has(worker):
			break
	_expect(climbed and work_seen, "task did not reach upper wall and work")
	_expect(maximum_step <= subject.WALK_SPEED * subject.RUN_SPEED_MULTIPLIER * 0.05 + 0.0001, "surface dig approach teleported actor")
	_expect(subject.terrain_state.revision == 2 and subject.dig_action_completions == 2, "one assignment did not produce two wall-work mutations")
	_expect(subject.native_mark_nibbles.is_empty(), "upper work chain left marks")
	_expect(subject.native_walkmap.revision == 2, "wall work did not update current navigation")
	_expect(subject.dig_selection_history.size() == 2, "wall queue selected extra or missing work")
	var standing_sample: Vector2i = subject._actor_navigation_sample(worker.position)
	var standing_flags: Variant = subject.native_walkmap.sample(standing_sample)
	_expect(standing_flags != null and (int(standing_flags) & 1) != 0 \
		and worker.position.z == subject.WALK_POSE.wall_depth(standing_sample, subject._native_height_sample), "wall work left actor without current source support")
	_expect(subject.dwarf_walk_actions.is_empty() and subject.dwarf_dig_jobs.is_empty(), "completed wall work leaked actions")
	if subject.dig_selection_history.size() == 2:
		_expect(int(subject.dig_selection_history[1]["group"]) == 3, "surface route reset accepted worker group")
	print("NATIVE_SURFACE_DIG_MAX_STEP ", maximum_step)
	print("NATIVE_SURFACE_DIG_RESULT selections=", subject.dig_selection_history, " position=", worker.position)
	if failures == 0:
		print("NATIVE_SURFACE_DIG_SELF_TEST_OK assertions=%d assignments=1 wall_mutations=2" % assertions)
	if failures == 0 and not directory.is_empty():
		subject.focus = Vector3(19,-12,11)
		subject.distance = 36.0
		await subject._capture_views(directory)
		return
	subject.queue_free()
	quit(0 if failures == 0 else 1)

func _expect(condition: bool, message: String) -> void:
	assertions += 1
	if not condition:
		failures += 1
		push_error("NATIVE_SURFACE_DIG_SELF_TEST_FAILED " + message)
