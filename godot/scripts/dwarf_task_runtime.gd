extends RefCounted
## Source tasklist ordering over the existing movement/mining scene adapters.
## Coordinates here use the selected template's local native axes (Y down).
## Full Tcl procedures, autonomous scheduling and world offsets are not replayed.

const Runner: Script = preload("res://scripts/native_actor_tasks.gd")
const Eval: Script = preload("res://scripts/native_task_eval.gd")
const Aliases: Script = preload("res://scripts/native_animation_aliases.gd")
const SourceClip: Script = preload("res://scripts/source_animation_action.gd")
const Timing: Script = preload("res://scripts/native_animation_timing.gd")
var subject: Node3D = null
var runners: Dictionary = {}
var active: Dictionary = {}
var rng: RandomNumberGenerator = RandomNumberGenerator.new()


func configure(scene: Node3D) -> void:
	subject = scene
	rng.randomize() # Host RNG; original irandom algorithm has not been recovered.


func runner(dwarf: Node3D) -> RefCounted:
	if not runners.has(dwarf):
		var state: RefCounted = Runner.new()
		state.evaluator.handlers = {"walk_pos": _walk.bind(dwarf), "dig_starttask": _dig.bind(dwarf),
			"play_anim": _play.bind(dwarf), "irandom": _random,
			"tasklist_add": _queue_edit.bind(dwarf, "add"),
			"tasklist_addfront": _queue_edit.bind(dwarf, "front"),
			"tasklist_clear": _queue_edit.bind(dwarf, "clear")}
		runners[dwarf] = state
	return runners[dwarf]


func interrupt(dwarf: Node3D) -> void:
	if not is_instance_valid(dwarf):
		return
	if runners.has(dwarf):
		runners[dwarf].interrupt()
	active.erase(dwarf)
	subject._cancel_dwarf_dig(dwarf)
	subject._stop_dwarf_walk(dwarf)
	subject._show_dwarf_default(dwarf)
	subject.dwarf_idle_frame_indices.erase(dwarf)
	subject.dwarf_sleep.interrupt(dwarf)


func submit(dwarf: Node3D, script: String, replace: bool = true, origin: String = "manual") -> bool:
	if not is_instance_valid(dwarf) or not subject.dwarf_nodes.has(dwarf):
		return false
	if replace:
		interrupt(dwarf)
	if origin == "manual" and replace:
		subject.dwarf_life.note_manual(dwarf)
	runner(dwarf).queue.add(script)
	return true


func walk(dwarf: Node3D, point: Vector3, replace: bool = true) -> bool:
	var accepted: bool = submit(dwarf, "walk_pos {%.9f %.9f %.9f}" % [point.x, -point.y, point.z], replace)
	if accepted:
		subject.dwarf_life.note_manual(dwarf)
	return accepted


func dig(dwarf: Node3D, point: Vector2i, replace: bool = true, origin: String = "manual") -> bool:
	if not submit(dwarf, "dig_starttask {%d %d 0}" % [point.x, point.y], replace, origin):
		return false
	if origin == "manual":
		subject.dwarf_life.note_manual(dwarf)
	# evt_task_dig sets this before enqueuing. dig_starttask reads the global.
	runner(dwarf).evaluator.variables["current_digpos"] = "%d %d 0" % [point.x, point.y]
	return true


func dispatch() -> void:
	for dwarf: Node3D in runners.keys():
		if not is_instance_valid(dwarf):
			runners.erase(dwarf)
			active.erase(dwarf)
			continue
		var result: Dictionary = runners[dwarf].dispatch()
		if result.get("dispatched", false) and not str(runners[dwarf].last_error).is_empty():
			print("DWARF_TASK_ERROR ", dwarf.name, " ", runners[dwarf].last_error)
			subject.status.text = "Команда гнома не поддерживается: " + str(runners[dwarf].last_error)


func advance(delta: float) -> void:
	for dwarf: Node3D in active.keys():
		var action: Dictionary = active[dwarf]
		var state: RefCounted = runners[dwarf]
		var done: bool = false
		var failure: String = ""
		match action["kind"]:
			"walk":
				if subject.dwarf_walk_actions.has(dwarf):
					if subject.dwarf_walk_actions[dwarf] != action["walk"]:
						failure = "Walk was replaced outside task runtime"
				else:
					done = dwarf.position.distance_to(action["walk"].target) < 0.02
					if not done:
						failure = "Walk ended before reaching target"
			"dig":
				done = not subject.dwarf_dig_jobs.has(dwarf) and not subject.dwarf_manual_dig_tasks.has(dwarf)
			"anim":
				var step: Dictionary = action["animation"].advance(delta)
				if int(step["frame"]) >= 0:
					subject._show_dwarf_animation_frame(dwarf, action["clip"], int(step["frame"]))
				done = bool(step["complete"])
		if done or not failure.is_empty():
			active.erase(dwarf)
			if failure.is_empty():
				if action["kind"] == "anim":
					subject.dwarf_sleep.animation_finished(dwarf, action["clip"])
				state.complete(int(action["token"]))
			else:
				state.fail(int(action["token"]), failure)


func animating(dwarf: Node3D) -> bool:
	return active.get(dwarf, {}).get("kind") == "anim"


func _vector(value: String) -> Dictionary:
	var words: PackedStringArray = value.replace("\t", " ").replace("\n", " ").split(" ", false)
	if words.size() != 3:
		return Eval.error("Expected a three-number vector")
	for word: String in words:
		if not word.is_valid_float() or is_nan(float(word)) or is_inf(float(word)):
			return Eval.error("Invalid vector component")
	return {"code": 0, "point": Vector3(float(words[0]), float(words[1]), float(words[2]))}


func _walk(args: Array[String], dwarf: Node3D) -> Dictionary:
	if active.has(dwarf):
		return Eval.error("Replacing an active action inside one script is not supported")
	if args.size() != 1:
		return Eval.error("Only unforced walk_pos is supported")
	var parsed: Dictionary = _vector(args[0])
	if int(parsed["code"]) != 0:
		return parsed
	var point: Vector3 = parsed["point"]
	var target: Vector3 = Vector3(point.x, -point.y, point.z)
	var sample: Vector2i = Vector2i(roundi(point.x * 8.0), roundi(point.y * 8.0))
	var flags: Variant = subject.native_walkmap.sample(sample)
	var use_surface: bool = absf(target.y - subject.WALKABLE_FLOOR_Y) > 0.25 \
		or absf(dwarf.position.y - subject.WALKABLE_FLOOR_Y) > 0.25 \
		or int(subject.dwarf_surface_modes.get(dwarf, 2)) == 0 \
		or target.x < subject.WALKABLE_FLOOR_MIN_X or target.x > subject.WALKABLE_FLOOR_MAX_X \
		or (flags != null and (int(flags) & 1) != 0 \
			and ((int(flags) & 2) == 0 or subject.native_walkmap.is_newly_navigable(sample)))
	if use_surface:
		if not subject.assign_dwarf_surface_walk(dwarf, sample, true, false, target.z):
			return Eval.error("No supported surface route")
	else:
		subject._start_dwarf_walk(dwarf, target)
	if not subject.dwarf_walk_actions.has(dwarf):
		return Eval.ok("1") if dwarf.position.distance_to(target) < 0.02 else Eval.error("No supported floor route")
	active[dwarf] = {"kind": "walk", "token": runner(dwarf).begin_action(),
		"walk": subject.dwarf_walk_actions[dwarf]}
	return Eval.ok("1")


func _dig(args: Array[String], dwarf: Node3D) -> Dictionary:
	if active.has(dwarf):
		return Eval.error("Replacing an active action inside one script is not supported")
	if args.size() != 1:
		return Eval.error("Invalid dig_starttask arity")
	var state: RefCounted = runner(dwarf)
	if args[0] == "0":
		state.evaluator.variables["current_digpos"] = "%f %f %f" % [dwarf.position.x, -dwarf.position.y, dwarf.position.z]
	if not state.evaluator.variables.has("current_digpos"):
		return Eval.error("Missing actor current_digpos")
	var parsed: Dictionary = _vector(str(state.evaluator.variables["current_digpos"]))
	if int(parsed["code"]) != 0:
		return parsed
	var point: Vector3 = parsed["point"]
	var started: bool = subject.assign_dwarf_dig(dwarf, Vector2i(roundi(point.x), roundi(point.y)))
	if subject.dwarf_manual_dig_tasks.has(dwarf):
		# Existing connected-region action is an explicit host embedding of
		# walk_pos_dig / dig_continue, not a literal port of the entire procedure.
		active[dwarf] = {"kind": "dig", "token": state.begin_action()}
	return Eval.ok("1" if started else "0")


func _play(args: Array[String], dwarf: Node3D) -> Dictionary:
	if active.has(dwarf):
		return Eval.error("Replacing an active action inside one script is not supported")
	if args.size() != 1:
		return Eval.error("Only play_anim without mining callback arguments is supported")
	var clip: StringName = StringName(Aliases.get_clip(args[0]))
	if String(clip).is_empty():
		return Eval.error("Unknown animation alias: " + args[0])
	var count: int = subject._dwarf_sequence_frame_count(dwarf, clip)
	if count == 0:
		subject._ensure_surface_clip(dwarf, clip)
		count = subject._dwarf_sequence_frame_count(dwarf, clip)
	if count == 0:
		subject.dwarf_sleep.ensure_clip(dwarf, clip)
		count = subject._dwarf_sequence_frame_count(dwarf, clip)
	if count == 0:
		return Eval.error("Animation is not exported in this scene: " + args[0])
	var animation: RefCounted = SourceClip.new()
	animation.begin(count, Timing.FRAMES_PER_GAME_SECOND)
	active[dwarf] = {"kind": "anim", "token": runner(dwarf).begin_action(), "clip": clip,
		"animation": animation}
	subject.dwarf_idle_frame_indices.erase(dwarf)
	subject._show_dwarf_animation_frame(dwarf, clip, 0)
	return Eval.ok("1")


func _random(args: Array[String]) -> Dictionary:
	if args.size() != 1 or not args[0].is_valid_int() or int(args[0]) <= 0:
		return Eval.error("Invalid irandom bound")
	return Eval.ok(str(rng.randi_range(0, int(args[0]) - 1)))


func _queue_edit(args: Array[String], dwarf: Node3D, operation: String) -> Dictionary:
	if args.is_empty() or args[0] != "this" or args.size() != (1 if operation == "clear" else 2):
		return Eval.error("Only this actor's tasklist is supported")
	var queue: RefCounted = runner(dwarf).queue
	match operation:
		"clear": queue.clear()
		"front": queue.add_front(args[1])
		"add": queue.add(args[1])
	return Eval.ok()
