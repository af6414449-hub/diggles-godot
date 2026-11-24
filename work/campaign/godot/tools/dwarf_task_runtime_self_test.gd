extends SceneTree
var checks: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func check(condition: bool, label: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		printerr("FAIL ", label)


func _random_one(_args: Array[String]) -> Dictionary:
	return {"code": 0, "value": "1"}


func _run() -> void:
	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	subject.autonomous_dwarf_work = false # Isolate the manual-action scenario.
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	await process_frame
	subject.set_process(false)
	var tasks: RefCounted = subject.actor_tasks
	var first: Node3D = subject.dwarf_nodes[0]
	var second: Node3D = subject.dwarf_nodes[1]
	var third: Node3D = subject.dwarf_nodes[2]
	check(tasks.submit(first, "walk_pos {5 14.5 14};set started yes"), "first actor script accepted")
	check(tasks.submit(second, "walk_pos {14 14.5 14}"), "second actor script accepted")
	check(tasks.submit(first, "play_anim standloopa;set compound_marker yes", false), "append source alias animation")
	check(tasks.submit(first, "set animation_done yes", false), "append post-animation command")
	subject._process(0.05)
	var state: RefCounted = tasks.runner(first)
	check(state.blocked and state.evaluator.variables.get("started") == "yes", "walk blocks queue but not compound script")
	check(not state.evaluator.variables.has("compound_marker"), "next element not started during walk")
	check(subject.dwarf_walk_actions.size() == 2, "two independent queued walks")
	var animation_started: bool = false
	for frame: int in range(1500):
		subject._process(0.05)
		if tasks.animating(first):
			animation_started = true
			break
	check(animation_started, "arrival callback enables next animation")
	check(first.position.distance_to(Vector3(5, -14.5, 14)) < 0.02, "queued walk arrives at actual target")
	check(state.evaluator.variables.get("compound_marker") == "yes", "compound side effect occurs at animation start")
	check(not state.evaluator.variables.has("animation_done"), "next element waits for animation completion")
	for frame: int in range(300):
		subject._process(0.05)
		if state.evaluator.variables.has("animation_done"):
			break
	check(state.evaluator.variables.get("animation_done") == "yes", "finite animation resumes queue")
	check(state.last_error.is_empty(), "supported commands complete without evaluator error")
	# Replacement invalidates only this actor, including a captured old token.
	tasks.walk(second, Vector3(17, -14.5, 14))
	tasks.submit(first, "play_anim standloopa")
	subject._process(0.05)
	var previous_token: int = state.token
	var other_walk: RefCounted = subject.dwarf_walk_actions.get(second)
	tasks.walk(first, Vector3(6, -14.5, 14))
	subject._process(0.05)
	check(not state.complete(previous_token) and state.blocked, "old animation callback cannot unblock new walk")
	check(subject.dwarf_walk_actions.get(second) == other_walk and other_walk != null, "replacement leaves other actor's walk intact")
	# A cancelled mining animation cannot commit terrain even if its old clock finishes.
	check(subject.native_mark_corridor_cell(0, Vector2i(1, 15)), "mining source mark")
	check(tasks.dig(first, Vector2i(1, 15)), "dig event queued")
	tasks.submit(first, "set cancelled_command_ran yes", false)
	for frame: int in range(1500):
		subject._process(0.05)
		if subject.dwarf_dig_jobs.has(first) and subject.dwarf_dig_jobs[first]["phase"] == "work":
			break
	check(subject.dwarf_dig_jobs.has(first) and subject.dwarf_dig_jobs[first]["phase"] == "work", "queue drives actual mining approach and animation")
	var old_animation: RefCounted = subject.dwarf_dig_jobs[first]["action"]
	previous_token = state.token
	var before_revision: int = subject.terrain_state.revision
	tasks.walk(first, Vector3(6, -14.5, 14))
	subject._process(0.05)
	old_animation.advance(100.0)
	check(not state.complete(previous_token), "cancelled work completion rejected")
	for frame: int in range(100):
		subject._process(0.05)
	check(subject.terrain_state.revision == before_revision, "cancelled mining never mutates terrain")
	check(not state.evaluator.variables.has("cancelled_command_ran"), "replacement clears pending old commands")
	check(not subject.dwarf_dig_jobs.has(first) and not subject.dwarf_manual_dig_tasks.has(first), "cancellation releases work reservation")
	# The queue waits for the entire connected mining region, not a single cell.
	check(subject.native_mark_corridor_cell(0, Vector2i(2, 15)), "connected second source mark")
	tasks.dig(first, Vector2i(1, 15))
	tasks.submit(first, "set mining_done yes", false)
	var observed_first_mutation: bool = false
	for frame: int in range(2200):
		subject._process(0.05)
		if subject.terrain_state.revision > before_revision and not observed_first_mutation:
			observed_first_mutation = true
			check(not state.evaluator.variables.has("mining_done"), "single-cell completion does not release region task")
		if state.evaluator.variables.has("mining_done"):
			break
	check(observed_first_mutation and subject.terrain_state.revision >= before_revision + 2, "queued mining commits both original cells")
	check(state.evaluator.variables.get("mining_done") == "yes" and not state.blocked, "region completion resumes following command")
	check(not subject.dwarf_manual_dig_tasks.has(first), "finished queued region releases assignment")
	# Source braces defer the random choice until the queued script is dispatched.
	# Oracle RNG fixes index1, whose real clip is exported in the current scene.
	tasks.runner(third).evaluator.handlers["irandom"] = _random_one
	tasks.submit(third, "tasklist_add this {play_anim standloop[string index abcd [irandom 4]]};set enqueued yes")
	subject._process(0.05)
	check(not tasks.animating(third) and tasks.runner(third).queue.count() == 1,
		"source tasklist_add stores deferred expression without executing it")
	subject._process(0.05)
	check(tasks.animating(third) and tasks.active[third]["clip"] == &"stand_anim_b", "original deferred idle command runs in real scene")
	check(tasks.runner(third).last_error.is_empty(), "deferred expression is supported")
	tasks.interrupt(third)
	# Native sample surface routing remains available through the queue.
	first.position = Vector3(1.5, -15.5, 12)
	subject.dwarf_surface_modes[first] = 2
	tasks.walk(first, Vector3(8, -14.5, 12))
	for frame: int in range(2000):
		subject._process(0.05)
		if not state.blocked and state.queue.count() == 0:
			break
	check(state.last_error.is_empty() and first.position.distance_to(Vector3(8, -14.5, 12)) < 0.05, "queued shaft exit preserves depth route")
	# An unreachable region remains a task, without draining its next command.
	check(subject.native_mark_corridor_cell(0, Vector2i(9, 3)), "pending region mark")
	tasks.dig(second, Vector2i(9, 3))
	tasks.submit(second, "set pending_finished yes", false)
	for frame: int in range(20):
		subject._process(0.05)
	check(tasks.runner(second).blocked and subject.dwarf_manual_dig_tasks.has(second)
		and not tasks.runner(second).evaluator.variables.has("pending_finished"), "waiting frontier does not release queue")
	tasks.interrupt(second)
	check(not tasks.runner(second).blocked and not subject.dwarf_manual_dig_tasks.has(second), "interrupt releases waiting frontier")
	# Exercise actual user-command entry with a marked terrain point.
	subject.focus = Vector3(8, -14, 11)
	subject.yaw = 0.0
	subject.pitch = 0.0
	subject.distance = 60.0
	subject.camera.projection = Camera3D.PROJECTION_ORTHOGONAL
	subject.camera.size = 40.0
	subject._update_camera()
	check(subject.native_mark_corridor_cell(0, Vector2i(1, 16)), "input mark")
	subject._select_dwarf(third)
	var screen: Vector2 = subject.camera.unproject_position(subject.scene_root.to_global(Vector3(1, -16, subject.DIG_MARK_DEPTH)))
	subject._command_selected_dwarf(screen)
	check(tasks.runner(third).queue.count() == 1, "player click enqueues command")
	check(tasks.runner(third).queue.get_command(0).begins_with("dig_starttask"), "player selection uses source dig command")
	tasks.interrupt(third)
	check(tasks.runner(third).queue.count() == 0, "player cancellation clears queue")
	tasks.submit(third, "play_anim standloopa;play_anim standloopb")
	tasks.dispatch()
	check(not tasks.runner(third).last_error.is_empty() and tasks.active[third]["clip"] == &"stand_anim_a",
		"unsupported second async action fails explicitly instead of running two actions together")
	tasks.interrupt(third)
	subject.queue_free()
	await process_frame
	print("DWARF_TASK_RUNTIME_SELF_TEST checks=", checks, " failures=", failures)
	quit(0 if failures == 0 else 1)
