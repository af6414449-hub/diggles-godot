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


func _run() -> void:
	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	subject.set_process(false)
	var life: RefCounted = subject.dwarf_life
	var first: Node3D = subject.dwarf_nodes[0]
	var second: Node3D = subject.dwarf_nodes[1]
	var model: Dictionary = life.models[first]
	check(subject.autonomous_dwarf_work, "automatic work is enabled in normal scene")
	check(life.models.size() == 3 and model["needs"]["nutrition"] == 0.9, "source initial needs")
	check(model["shift_start"] == 7 and life.models[second]["shift_start"] == 1, "explicit unpaired bootstrap uses source assignment")
	for dwarf: Node3D in subject.dwarf_nodes:
		life.models[dwarf]["shift_start"] = 1.0
		life.models[dwarf]["shift_duration"] = 0.5
	model["shift_start"] = 0.0
	first.position = Vector3(3, -14.5, 14)
	check(subject.native_mark_corridor_cell(0, Vector2i(1, 15)), "first original mark")
	check(subject.native_mark_corridor_cell(0, Vector2i(2, 15)), "second original mark")
	var normal_strike_started: bool = false
	for frame: int in range(600):
		subject._process(0.05)
		if subject.dwarf_dig_jobs.has(first):
			var job: Dictionary = subject.dwarf_dig_jobs[first]
			if job["phase"] == "work" and not job.get("accident_prelude", false):
				normal_strike_started = true
				break
	check(normal_strike_started and life.automatic_assignments == 1, "free working actor chooses and approaches native-ranked mark")
	check(model["origin"] == "automatic", "automatic assignment identity")
	subject.actor_tasks.submit(first, "set auto_finished yes", false)
	check(model["origin"] == "automatic", "queue continuation is not a new manual event")
	check(not subject.dwarf_dig_jobs.has(second), "off-duty actor does not take work")
	check(life.attribute_ticks > 0 and model["needs"]["nutrition"] < 0.9, "needs advance by game-second timer")
	# Cross the end of a half-hour shift during a normal accepted strike.
	life.seek(74.95)
	var before: int = subject.terrain_state.revision
	subject._process(0.1)
	check(model["time_plan"] == "sparetime" and subject.dwarf_dig_jobs.has(first), "end of shift changes plan without cancelling current strike")
	for frame: int in range(150):
		subject._process(0.05)
		if not subject.dwarf_manual_dig_tasks.has(first):
			break
	check(subject.terrain_state.revision == before + 1, "last accepted strike commits once after shift end")
	check(not subject.native_mark_nibbles.is_empty() and not subject.dwarf_manual_dig_tasks.has(first), "automatic dig stops before next cell")
	check(life.automatic_assignments == 1, "off-duty dispatcher does not reassign work")
	var remaining: Vector2i = Vector2i(1, 15) if subject._work_mark(Vector2i(1, 15)) != 0 else Vector2i(2, 15)
	subject.actor_tasks.dig(first, remaining)
	check(model["origin"] == "manual", "manual event replaces automatic ownership")
	for frame: int in range(900):
		subject._process(0.05)
		if subject.terrain_state.revision >= before + 2:
			break
	check(subject.terrain_state.revision == before + 2, "manual mining continues outside work hours")
	# Pause holds a new command in the queue and freezes both needs and movement.
	subject.autonomous_dwarf_work = false
	subject.actor_tasks.walk(first, Vector3(6, -14.5, 14))
	subject.simulation_paused = true
	var old_time: float = subject.game_clock.seconds
	var old_ticks: int = life.attribute_ticks
	var old_position: Vector3 = first.position
	subject._process(10.0)
	check(subject.game_clock.seconds == old_time and life.attribute_ticks == old_ticks, "pause freezes clock and attribute timer")
	check(subject.actor_tasks.runner(first).queue.count() == 1 and first.position == old_position, "paused command waits without movement")
	check(subject.clock_caption.text.ends_with("Пауза"), "clock HUD reports pause")
	subject.simulation_paused = false
	subject.simulation_time_scale = 2.0
	subject._process(0.25)
	check(is_equal_approx(subject.game_clock.seconds - old_time, 0.5), "main applies one game time scale")
	check(subject.dwarf_walk_actions.has(first), "unpause starts queued movement")
	subject.actor_tasks.interrupt(first)
	subject.simulation_time_scale = 1.0
	# Needs timer is independent of render frame partition, with exact trap gating.
	life.seek(0.0)
	model["needs"] = life.data["defaults"].duplicate()
	for frame: int in range(100):
		subject._process(0.01)
	var partitioned: Dictionary = model["needs"].duplicate()
	life.seek(0.0)
	model["needs"] = life.data["defaults"].duplicate()
	subject._process(1.0)
	check(model["needs"] == partitioned, "one hundred small frames equal one needs second")
	model["trap_mode"] = 1
	var trapped: Dictionary = model["needs"].duplicate()
	subject._process(1.0)
	check(model["needs"] == trapped, "trap prevents all need changes in real scene")
	model["trap_mode"] = 0
	check(first.has_meta("needs") and first.has_meta("current_time_plan"), "observable actor state is published")
	# An unsupported automatic frontier is rejected once until the world changes;
	# the same point remains a retained waiting task when ordered manually.
	subject.autonomous_dwarf_work = true
	life.seek(0.0)
	check(subject.native_mark_corridor_cell(0, Vector2i(9, 3)), "unsupported frontier mark")
	var assignments: int = life.automatic_assignments
	for frame: int in range(120):
		subject._process(0.1)
	check(life.automatic_assignments == assignments + 1 and not subject.dwarf_manual_dig_tasks.has(first),
		"failed automatic frontier is not reassigned every heartbeat")
	subject.actor_tasks.dig(first, Vector2i(9, 3))
	for frame: int in range(20):
		subject._process(0.1)
	check(model["origin"] == "manual" and subject.dwarf_manual_dig_tasks.has(first)
		and subject.actor_tasks.runner(first).blocked, "manual waiting task survives active autonomous dispatcher")
	subject.actor_tasks.interrupt(first)
	subject.queue_free()
	await process_frame
	print("DWARF_LIFE_RUNTIME_SELF_TEST checks=", checks, " failures=", failures)
	quit(0 if failures == 0 else 1)
