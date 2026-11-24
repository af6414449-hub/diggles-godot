extends RefCounted
## First floor-sleep action over the source queue and source clips.
## Placement uses only the current safe floor fallback. Ongoing leisure
## arbitration, sleep furniture, particles and disturbance penalties remain open.

const Policy: Script = preload("res://scripts/native_floor_sleep.gd")
const Eval: Script = preload("res://scripts/native_task_eval.gd")
var subject: Node3D = null
var states: Dictionary = {}
var idle_since: Dictionary = {}
var pending_wakes: Dictionary = {}
var data: Dictionary = {}
var meshes: Dictionary = {}
var gain_cycles: int = 0


func configure(scene: Node3D) -> void:
	subject = scene


func ensure_clip(dwarf: Node3D, clip: StringName) -> bool:
	if data.is_empty():
		data = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_floor_sleep.json"))
	var name: String = String(clip)
	if not data["clips"].has(name) or not subject.dwarf_locomotion_visuals.has(dwarf):
		return false
	var visuals: Dictionary = subject.dwarf_locomotion_visuals[dwarf]
	if visuals["sequences"].has(name):
		return true
	if not meshes.has(name):
		var frames: Array = []
		for frame: Dictionary in data["clips"][name]["frames"]:
			frames.append(subject._build_model_meshes(frame["surfaces"]))
		meshes[name] = frames
	visuals["sequences"][name] = meshes[name]
	return true


func update() -> void:
	for dwarf: Node3D in subject.dwarf_life.models:
		var model: Dictionary = subject.dwarf_life.models[dwarf]
		var runner: RefCounted = subject.actor_tasks.runner(dwarf)
		var busy: bool = subject.dwarf_walk_actions.has(dwarf) or subject.dwarf_manual_dig_tasks.has(dwarf) \
			or subject.actor_tasks.active.has(dwarf) or runner.blocked or runner.queue.count() > 0
		if states.has(dwarf):
			if busy or not str(runner.last_error).is_empty():
				continue
			var state: Dictionary = states[dwarf]
			if state["phase"] == "waking":
				states.erase(dwarf)
				idle_since[dwarf] = subject.game_clock.seconds
				model["origin"] = "none"
			elif not subject.autonomous_dwarf_sparetime or model["time_plan"] == "work" \
					or Policy.reached(state["goal"], model["needs"]["alertness"]):
				wake(dwarf)
			else:
				# sparetime_slp_loop: gain once, then two complete source clips.
				model["needs"]["alertness"] = minf(1.0, float(model["needs"]["alertness"]) \
					+ float(data["floor_gain"]) * float(data["floor_gain_factor"]))
				gain_cycles += 1
				runner.queue.add("play_anim sleepside")
				runner.queue.add("play_anim sleepside")
			continue
		if busy or model["time_plan"] != "sparetime" or not subject.autonomous_dwarf_sparetime \
				or not str(runner.last_error).is_empty() or int(model["trap_mode"]) != 0:
			idle_since.erase(dwarf)
			continue
		if not idle_since.has(dwarf):
			idle_since[dwarf] = subject.game_clock.seconds
		if subject.game_clock.seconds - float(idle_since[dwarf]) <= 5.0:
			continue
		var goal: Dictionary = Policy.fresh_goal(model["needs"])
		if not goal.is_empty() and safe_floor(dwarf):
			begin(dwarf, goal)


func safe_floor(dwarf: Node3D) -> bool:
	if int(subject.dwarf_surface_modes.get(dwarf, 2)) != 2:
		return false
	var sample: Vector2i = Vector2i(roundi(dwarf.position.x*8.0), roundi(-dwarf.position.y*8.0))
	var flags: Variant = subject.native_walkmap.sample(sample)
	if flags == null or (int(flags) & 3) != 3:
		return false
	for other: Node3D in subject.dwarf_nodes:
		if other != dwarf and other.position.distance_to(dwarf.position) < 2.0:
			return false
	return true


func begin(dwarf: Node3D, goal: Dictionary) -> void:
	# Current floor is reserved by states; no native object/place registry claim.
	ensure_clip(dwarf, &"stand_zu_schlafen")
	var runner: RefCounted = subject.actor_tasks.runner(dwarf)
	runner.evaluator.handlers["sparetime_start_sleep"] = _start_sleep.bind(dwarf)
	states[dwarf] = {"phase": "laying", "goal": goal, "position": dwarf.position}
	subject.dwarf_life.models[dwarf]["origin"] = "sparetime"
	runner.queue.add("play_anim laydown; sparetime_start_sleep")


func _start_sleep(args: Array[String], dwarf: Node3D) -> Dictionary:
	if not args.is_empty() or not states.has(dwarf):
		return Eval.error("Invalid floor sleep start")
	states[dwarf]["phase"] = "sleeping"
	subject.dwarf_life.models[dwarf]["is_sleeping"] = true
	subject.dwarf_life.models[dwarf]["occupation"] = "slp"
	return Eval.ok()


func wake(dwarf: Node3D) -> void:
	states[dwarf]["phase"] = "waking"
	subject.dwarf_life.models[dwarf]["is_sleeping"] = false
	subject.actor_tasks.runner(dwarf).queue.add("play_anim sleeptostand")


func interrupt(dwarf: Node3D) -> void:
	idle_since.erase(dwarf)
	if not states.has(dwarf) and not pending_wakes.has(dwarf):
		return
	var needs_wake: bool = pending_wakes.has(dwarf) or subject.dwarf_life.models[dwarf]["is_sleeping"] \
		or states.get(dwarf, {}).get("phase") == "waking"
	states.erase(dwarf) # Releases the host reservation, including pending laydown.
	subject.dwarf_life.models[dwarf]["is_sleeping"] = false
	if needs_wake:
		pending_wakes[dwarf] = true
		subject.actor_tasks.runner(dwarf).queue.add("play_anim sleeptostand")


func animation_finished(dwarf: Node3D, clip: StringName) -> void:
	if clip == &"schlafen_zu_stand":
		pending_wakes.erase(dwarf)
