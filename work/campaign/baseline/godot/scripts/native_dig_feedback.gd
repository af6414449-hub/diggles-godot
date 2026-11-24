extends RefCounted
## Source contract only. Native (Tcl) Y, not Godot Y, is used below.
## No RNG, scene mutation, placement approximation, or implicit clock.

const DATA_PATH: String = "res://models/native_dig_feedback.json"


static func read_data() -> Dictionary:
	var value: Variant = JSON.parse_string(FileAccess.get_file_as_string(DATA_PATH))
	return value if value is Dictionary else {}


static func chance(exp_stein: float, height_delta: float, on_ground: bool = true,
		has_airhammer: bool = false, laser_branch: bool = false,
		accident_possible: bool = true) -> Dictionary:
	# z_dignwalk:389-411. The positive amplitude is tested, never rolled.
	var amplitude: float = maxf((0.2 - exp_stein) * 5.0, 0.0)
	var front: bool = height_delta > 0.6 and height_delta <= 1.6
	var eligible: bool = on_ground and not has_airhammer and not laser_branch \
		and accident_possible and not front and amplitude > 0.0
	return {"status": "confirmed", "probability": 1.0 if eligible else 0.0,
		"random": false, "amplitude_raw": amplitude,
		"event": "pick_accident", "source": "z_dignwalk.tcl:389-411"}


static func clip(height_delta: float, accident: bool = false) -> String:
	# Native direction is selected before the later orientation calculation.
	var direction: String = "up" if height_delta > 1.6 else (
		"front" if height_delta > 0.6 else "down")
	if accident and direction == "front":
		return "" # No front accident clip in this branch.
	return "dig" + direction + ("accident" if accident else "")


static func plan(exp_stein: float, height_delta: float, on_ground: bool = true,
		has_airhammer: bool = false, laser_branch: bool = false,
		accident_possible: bool = true) -> Dictionary:
	if not on_ground or has_airhammer or laser_branch:
		return {"status": "outside_pick_ground_scope", "steps": []}
	var result: Dictionary = chance(exp_stein, height_delta, on_ground,
		has_airhammer, laser_branch, accident_possible)
	var steps: Array[Dictionary] = []
	if float(result["probability"]) > 0.0:
		steps.append({"alias": clip(height_delta, true), "dig_execute": false,
			"completion": "state_enable this", "reenter_accident_possible": false})
	steps.append({"alias": clip(height_delta), "dig_execute": true,
		"completion": "state_enable this;dig_execute {$digpos};dig_continue"})
	return {"status": "confirmed", "chance": result, "steps": steps,
		"retry_note": "Native retry re-evaluates pose/inventory: dig_anim {$digpos} 0"}


static func clip_data(data: Dictionary, alias: String) -> Dictionary:
	var clips: Dictionary = data.get("clips", {})
	var record: Dictionary = clips.get(alias, {})
	return record.duplicate(true)


static func callbacktime(data: Dictionary, alias: String) -> Dictionary:
	var record: Dictionary = clip_data(data, alias)
	return record.get("callback", {"trigger": "unknown", "seconds": null})


static func placement_rule() -> Dictionary:
	return {"status": "unknown", "chance": null, "callbacktime": null,
		"transform": null, "automatic_corridor_class": null,
		"candidate_only": "res://models/native_dig_feedback/board_candidate.json"}
