extends SceneTree
## --headless --path godot --script res://tools/native_hamster_ai_self_test.gd
## Checks the hamster animation table and the ported hamster behaviour.
const Animations = preload("res://scripts/native_hamster_animations.gd")
const Hamster = preload("res://scripts/native_hamster_ai.gd")
var _checks: int = 0
var _failures: Array[String] = []

func _initialize() -> void:
	call_deferred("_run")

func _check(condition: bool, message: String) -> void:
	_checks += 1
	if not condition:
		_failures.append(message)
		printerr("FAIL: " + message)

func _run() -> void:
	# --- animation table ---------------------------------------------------
	_check(Animations.alias_count("Hamster") == 27, "the hamster has 27 aliases")
	_check(Animations.get_clip("Hamster", "standstill") == "stand_anim", "standstill maps to stand_anim")
	_check(Animations.get_clip("Hamster", "walkloop") == "laufen_loop", "walkloop maps to laufen_loop")
	_check(Animations.get_clip("Hamster", "hoppelloop") == "hoppeln_loop", "hoppelloop maps to hoppeln_loop")
	_check(Animations.get_clip("Hamster", "galoploop") == "galopp_loop", "galoploop maps to galopp_loop")
	_check(Animations.get_clip("Hamster", "ridestill") == "reiten_stand", "ridestill maps to reiten_stand")
	_check(Animations.get_clip("Hamster", "goteaten") == "gefressen_werden", "goteaten maps to gefressen_werden")
	_check(Animations.get_clip("Hamster", "gothit") == "getroffen", "gothit maps to getroffen")
	_check(Animations.get_clip("Hamster", "beg") == "maennchen", "beg maps to maennchen")
	_check(Animations.get_clip("Hamster", "no_such_alias") == "", "an unknown alias returns empty")
	_check(Animations.get_target("Hamster", "walkloop") == "hamster.laufen_loop", "the target keeps the package prefix")
	_check(Animations.get_frame_count("Hamster", "walkloop") == 7, "laufen_loop has 7 frames")
	_check(Animations.get_frame_count("Hamster", "sleeploop") == 8, "schlafen_loop has 8 frames")
	_check(Animations.get_frame_count("Hamster", "sterben") == -1, "sterben has no alias in the table")
	_check(Animations.get_clip_frames("Hamster", "sterben") == 21, "the package catalog knows sterben with 21 frames")

	# --- animsets ----------------------------------------------------------
	_check(Animations.animset_ids("Hamster").size() == 3, "the hamster has three animsets")
	_check(Animations.get_animset_role("Hamster", "0", "walk_loop") == "hamster.laufen_loop", "walk animset uses the walk clips")
	_check(Animations.get_animset_role("Hamster", "1", "walk_loop") == "hamster.hoppeln_loop", "hoppel animset uses the hop clips")
	_check(Animations.get_animset_role("Hamster", "2", "walk_loop") == "hamster.galopp_loop", "galopp animset uses the gallop clips")

	# --- fleeing -----------------------------------------------------------
	var escape := Hamster.escape_target(Vector3(0, 0, 0), [Vector3(3, 0, 0)])
	_check(bool(escape["found"]), "a dwarf in range is detected")
	_check(int(escape["count"]) == 1, "one dwarf is counted")
	_check((escape["target"] as Vector3) == Vector3(-2, 0, 0), "the hamster runs away from the dwarf")
	_check((escape["clipping"] as Array).size() == 1, "a clip box is built around the dwarf")

	escape = Hamster.escape_target(Vector3(0, 0, 0), [Vector3(10, 0, 0)])
	_check(not bool(escape["found"]), "a dwarf out of range is ignored")

	escape = Hamster.escape_target(Vector3(0, 0, 0), [Vector3(2, 0, 0), Vector3(-2, 0, 0)])
	_check(int(escape["count"]) == 2, "two dwarves are counted")
	_check((escape["average"] as Vector3) == Vector3.ZERO, "the average of symmetric dwarves is the own position")
	_check((escape["target"] as Vector3) == Vector3.ZERO, "without a direction there is nothing to run to")

	var decision := Hamster.escape_decision(true)
	_check(String(decision["mode"]) == "escape" and bool(decision["rescan"]), "a found place means a direct escape")
	decision = Hamster.escape_decision(false)
	_check(String(decision["mode"]) == "random" and not bool(decision["rescan"]), "no place means the random path finder")

	# --- idle activities ---------------------------------------------------
	var plan := Hamster.choose_activity(-1, false, 0)
	_check(int(plan["activity"]) == 0 and String(plan["kind"]) == "clean", "activity 0 is grooming")
	plan = Hamster.choose_activity(-1, false, 1)
	_check(String(plan["kind"]) == "beg", "activity 1 is mating")
	plan = Hamster.choose_activity(-1, false, 2)
	_check(String(plan["kind"]) == "wait", "activity 2 is waiting")
	plan = Hamster.choose_activity(-1, false, 3)
	_check(String(plan["kind"]) == "sleep", "activity 3 is sleeping")
	plan = Hamster.choose_activity(-1, false, 4)
	_check(String(plan["kind"]) == "hoppel_random", "activity 4 is hopping")

	plan = Hamster.choose_activity(0, false, 0)
	_check(int(plan["activity"]) == 1, "a repeated activity is shifted by one")

	plan = Hamster.choose_activity(-1, true, 4)
	_check(String(plan["kind"]) == "hoppel_farm", "a farmed hamster hops inside the pen")
	plan = Hamster.choose_activity(-1, true, 5)
	_check(int(plan["activity"]) == 0, "a farm has five activities only")

	# --- farm pen ----------------------------------------------------------
	var cell := Hamster.farm_cell_position(Vector3(10, 0, 20), 0)
	_check(cell == Vector3(8.5, 0, 18), "the first cell of the pen is bottom left")
	cell = Hamster.farm_cell_position(Vector3(10, 0, 20), 6)
	_check(cell == Vector3(11.5, 0, 18), "the seventh cell is on the same row")
	cell = Hamster.farm_cell_position(Vector3(10, 0, 20), 7)
	_check(cell == Vector3(8.5, 0, 19), "the eighth cell starts the next row")

	# --- food --------------------------------------------------------------
	var step := Hamster.nutrition_step(0)
	_check(int(step["nutrition"]) == 1 and not bool(step["seek_food"]), "the hamster counts up while fed")
	step = Hamster.nutrition_step(49)
	_check(int(step["nutrition"]) == 50 and not bool(step["seek_food"]), "the counter reaches the limit")
	step = Hamster.nutrition_step(50)
	_check(int(step["nutrition"]) == 0 and bool(step["seek_food"]), "the counter resets and the hamster looks for food")

	var commands := Hamster.eat_commands(Vector3(4, 0, 6), "item7")
	_check((commands as Array).size() == 7, "a feeding round is seven commands")
	_check(String((commands as Array)[0]) == "walk_pos {4.0 0.0 6.0}", "the hamster walks to the food")
	_check(String((commands as Array)[5]) == "play_anim goteaten", "the eating animation repeats five times")
	_check(String((commands as Array)[6]) == "take_item item7", "the food is taken at the end")

	# --- loop animations ---------------------------------------------------
	var loop := Hamster.loop_anim_commands("sleep", 3)
	_check((loop as Array).size() == 5, "the loop is start, three loops and stop")
	_check(String((loop as Array)[0]) == "play_anim sleepstart", "the loop starts with the start clip")
	_check(String((loop as Array)[4]) == "play_anim sleepstop", "the loop ends with the stop clip")
	_check(Hamster.loop_anim_repetitions(6, 10, 0) == 6, "the minimum repetition count")
	_check(Hamster.loop_anim_repetitions(6, 10, 3) == 9, "the repetition count grows with the draw")
	_check(Hamster.loop_anim_repetitions(2, 6, 0) == 2, "grooming starts at two repetitions")

	# --- paralysis ---------------------------------------------------------
	_check(Hamster.should_paralyze(true, false), "a contained hamster is paralysed")
	_check(Hamster.should_paralyze(false, true), "an underwater hamster is paralysed")
	_check(not Hamster.should_paralyze(false, false), "a free hamster is not paralysed")
	var paralysis := Hamster.paralysis_plan()
	_check(bool(paralysis["clear_queue"]), "the queue is cleared on paralysis")
	_check(int(paralysis["wakeup_seconds"]) == 1800, "the hamster wakes up after 30 minutes")

	# --- walk actions ------------------------------------------------------
	var params := Hamster.walk_action_params("walk_random", 5.0)
	_check(String(params["animsets"]) == "0" and int(params["can_climb"]) == 0, "walk_random uses the walk set and no climbing")
	_check(int(params["random_z"]) == 4, "walk_random wanders up to four in height")
	params = Hamster.walk_action_params("hoppel_random", 3.0)
	_check(String(params["animsets"]) == "1" and int(params["random_z"]) == 2, "hoppel_random uses the hop set")
	params = Hamster.walk_action_params("walk_pos", 0.0, Vector3(1, 2, 3))
	_check((params["target"] as Vector3) == Vector3(1, 2, 3), "walk_pos carries the target")
	_check(int(params["use_objects"]) == 0, "the hamster ignores objects while walking")

	# --- timers and queries ------------------------------------------------
	_check(Hamster.scan_interval("fast") == 1, "the fast scan runs every second")
	_check(Hamster.scan_interval("slow") == 5, "the slow scan runs every five seconds")
	_check(int(Hamster.scan_query()["range"]) == 4, "the scan range is four")
	_check(int(Hamster.food_query()[0]["range"]) == 6, "the food search range is six")
	_check(String(Hamster.food_query()[0]["class"]) == "Pilzhut", "the mushroom hat is the first choice")
	_check(String(Hamster.food_query()[1]["class"]) == "Grillpilz", "the grilled mushroom is the second choice")

	if _failures.is_empty():
		print("NATIVE_HAMSTER_AI_SELF_TEST_OK assertions=%d" % _checks)
	else:
		printerr("NATIVE_HAMSTER_AI_SELF_TEST_FAIL failures=%d" % _failures.size())
	quit(0 if _failures.is_empty() else 1)
