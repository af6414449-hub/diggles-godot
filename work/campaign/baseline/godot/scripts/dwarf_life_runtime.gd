extends RefCounted
## Source clock/needs/shift contracts over the current scene actions.
## Automatic job registration uses a bounded host producer over native dig_next;
## the original clan job registry and full sparetime dispatcher are not ported.

const Clock: Script = preload("res://scripts/native_work_clock.gd")
const Needs: Script = preload("res://scripts/native_dwarf_needs.gd")
var subject: Node3D = null
var clock: RefCounted = null
var models: Dictionary = {}
var data: Dictionary = {}
var next_attribute_second: float = 1.0
var attribute_ticks: int = 0
var automatic_assignments: int = 0


func configure(scene: Node3D, game_clock: RefCounted) -> void:
	subject = scene
	clock = game_clock
	data = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_dwarf_life.json"))
	for dwarf: Node3D in subject.dwarf_nodes:
		models[dwarf] = {"needs": data["defaults"].duplicate(), "birth_seconds": clock.seconds - float(data["birth_age_seconds"]),
			"origin": "none", "time_plan": "sparetime", "occupation": "idle", "shift_start": 0.0,
			"shift_duration": 6.0, "is_sleeping": false, "trap_mode": 0, "disappointment": 0.0,
			"fun_items": false, "is_human": true, "failed_revision": "", "failed_points": {}}
	# Explicit bootstrap: current fixture actors are separate unpaired entries.
	# This reuses the source clan assignment block, not native constructor balancing.
	var plan: Array[Dictionary] = Needs.assign_ordered_shifts(models.size(), Clock.hours(clock.seconds))
	for index: int in range(plan.size()):
		var dwarf: Node3D = subject.dwarf_nodes[index]
		models[dwarf]["shift_start"] = plan[index]["start"]
		models[dwarf]["shift_duration"] = plan[index]["duration"]
	refresh_plans()


func seek(game_seconds: float) -> void:
	# Save/fixture initialization, deliberately does not replay skipped needs ticks.
	assert(game_seconds >= 0.0 and is_finite(game_seconds))
	clock.seconds = game_seconds
	next_attribute_second = floorf(game_seconds) + 1.0
	refresh_plans()


func refresh_plans() -> void:
	for dwarf: Node3D in models:
		var model: Dictionary = models[dwarf]
		var plan: String = "work" if Clock.working(clock.seconds, model["shift_start"], model["shift_duration"]) else "sparetime"
		if model["time_plan"] != plan or not dwarf.has_meta("current_time_plan"):
			dwarf.set_meta("current_time_plan", plan)
		model["time_plan"] = plan
		if model.get("published_start") != model["shift_start"] or model.get("published_duration") != model["shift_duration"]:
			dwarf.set_meta("work_shift", [model["shift_start"], model["shift_duration"]])
			model["published_start"] = model["shift_start"]
			model["published_duration"] = model["shift_duration"]


func advance() -> void:
	refresh_plans()
	while next_attribute_second <= clock.seconds + 0.000000001:
		_heartbeat(next_attribute_second)
		next_attribute_second += 1.0


func note_manual(dwarf: Node3D) -> void:
	if models.has(dwarf):
		models[dwarf]["origin"] = "manual"


func should_stop_auto_dig(dwarf: Node3D) -> bool:
	return models.has(dwarf) and models[dwarf]["origin"] == "automatic" \
		and (not subject.autonomous_dwarf_work \
			or not Clock.working(clock.seconds, models[dwarf]["shift_start"], models[dwarf]["shift_duration"]))


func _heartbeat(at_seconds: float) -> void:
	attribute_ticks += 1
	for dwarf: Node3D in models:
		var model: Dictionary = models[dwarf]
		var busy: bool = subject.dwarf_walk_actions.has(dwarf) or subject.dwarf_dig_jobs.has(dwarf) \
			or subject.actor_tasks.active.has(dwarf)
		model["occupation"] = "slp" if model["is_sleeping"] else ("work" if busy else "idle")
		var updated: Dictionary = Needs.tick(model["needs"], {"occupation": model["occupation"],
			"age_seconds": at_seconds - float(model["birth_seconds"]), "trap_mode": model["trap_mode"],
			"is_human": model["is_human"], "fun_items": model["fun_items"],
			"disappointment": model["disappointment"], "sleeping": model["is_sleeping"]})
		model["needs"] = updated["needs"]
		dwarf.set_meta("needs", model["needs"].duplicate())
		dwarf.set_meta("common_mood", updated["common_mood"])
		dwarf.set_meta("current_occupation", model["occupation"])
		if not subject.autonomous_dwarf_work:
			continue
		var state: RefCounted = subject.actor_tasks.runner(dwarf)
		# Release an unsupported automatic frontier instead of retaining a manual
		# waiting task. Cache rejected cells until marks or terrain change.
		if model["origin"] == "automatic" and subject.dwarf_manual_dig_tasks.has(dwarf) \
				and not subject.dwarf_dig_jobs.has(dwarf):
			model["failed_points"].merge(subject.dwarf_manual_dig_tasks[dwarf]["region"])
			subject.actor_tasks.interrupt(dwarf)
			model["origin"] = "none"
			continue
		if busy or subject.dwarf_manual_dig_tasks.has(dwarf) or state.blocked \
				or state.queue.count() > 0 or not str(state.last_error).is_empty():
			continue
		if model["time_plan"] != "work" or float(model["needs"]["hitpoints"]) < 0.01 \
				or int(model["trap_mode"]) != 0:
			continue
		var revision: String = "%d/%d" % [subject.terrain_state.revision, subject.native_marks_revision]
		if model["failed_revision"] != revision:
			model["failed_points"].clear()
			model["failed_revision"] = revision
		var candidate: Dictionary = subject.query_automatic_dig_seed(dwarf, model["failed_points"])
		if candidate.get("status") == "ok":
			if subject.actor_tasks.dig(dwarf, candidate["point"], true, "automatic"):
				model["origin"] = "automatic"
				automatic_assignments += 1
