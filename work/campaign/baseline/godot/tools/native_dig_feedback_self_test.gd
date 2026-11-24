extends SceneTree

const Feedback = preload("res://scripts/native_dig_feedback.gd")
var failures: int = 0
var checks: int = 0


func check(condition: bool, label: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		printerr("FAIL ", label)


func _init() -> void:
	var data: Dictionary = Feedback.read_data()
	check(data.get("schema") == "diggles.native_dig_feedback.v1", "source schema")
	check(Feedback.chance(0.199999, 0.6)["probability"] == 1.0, "tiny positive is deterministic")
	check(Feedback.chance(0.2, 0.6)["probability"] == 0.0, "strict exp boundary")
	check(Feedback.chance(0.0, 0.600001)["probability"] == 0.0, "front excludes accident")
	check(Feedback.chance(0.0, 1.6)["probability"] == 0.0, "front upper boundary")
	check(Feedback.chance(0.0, 1.600001)["probability"] == 1.0, "up strict boundary")
	check(Feedback.chance(0.0, 0.0, false)["probability"] == 0.0, "wall excludes")
	check(Feedback.chance(0.0, 0.0, true, true)["probability"] == 0.0, "airhammer excludes pick accident")
	check(Feedback.chance(0.0, 0.0, true, false, true)["probability"] == 0.0, "laser excludes")
	check(Feedback.chance(0.0, 0.0, true, false, false, false)["probability"] == 0.0, "retry suppression")
	var sequence: Dictionary = Feedback.plan(0.0, 0.0)
	var steps: Array = sequence["steps"]
	check(steps.size() == 2, "accident then work")
	check(steps[0]["alias"] == "digdownaccident" and not steps[0]["dig_execute"], "no early terrain mutation")
	check(steps[1]["alias"] == "digdown" and steps[1]["dig_execute"], "work completion mutates")
	check(Feedback.plan(0.2, 0.0)["steps"].size() == 1, "experienced normal work")
	check(Feedback.plan(0.0, 0.0, false)["steps"].is_empty(), "no invented wall plan")
	check(Feedback.clip(1.6) == "digfront" and Feedback.clip(0.6) == "digdown", "pose boundaries")
	check(Feedback.clip(1.0, true).is_empty(), "no invented front accident")
	var expected: Dictionary = {"digup": 13, "digfront": 13, "digdown": 13,
		"digupaccident": 29, "digdownaccident": 31}
	for alias: String in expected:
		var record: Dictionary = Feedback.clip_data(data, alias)
		check(record.get("frame_count", 0) == expected[alias], "native frames " + alias)
		var frames: Array = record.get("frames", [])
		check(frames.size() == expected[alias], "mesh count " + alias)
		var callback: Dictionary = Feedback.callbacktime(data, alias)
		check(callback["trigger"] == "animation_completion" and callback["seconds"] == null,
			"no guessed callback seconds " + alias)
		for frame: Dictionary in frames:
			check(not frame["surfaces"].is_empty(), "nonempty frame")
			for surface: Dictionary in frame["surfaces"]:
				check(FileAccess.file_exists(surface["texture_res_path"]), "isolated source texture")
	check(Feedback.placement_rule()["status"] == "unknown", "board rule unknown")
	check(Feedback.placement_rule()["chance"] == null, "unknown is not zero chance")
	var board_raw: Variant = JSON.parse_string(FileAccess.get_file_as_string(
		"res://models/native_dig_feedback/board_candidate.json"))
	check(board_raw is Dictionary and board_raw["clips"]["brett"]["frame_count"] == 2, "raw board resource")
	print("NATIVE_DIG_FEEDBACK_SELF_TEST ", "PASS" if failures == 0 else "FAIL",
		" checks=", checks, " failures=", failures)
	quit(0 if failures == 0 else 1)
