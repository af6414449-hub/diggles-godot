extends SceneTree
const Clock: Script = preload("res://scripts/native_work_clock.gd")
const Needs: Script = preload("res://scripts/native_dwarf_needs.gd")
var checks: int = 0
var failures: int = 0


func check(condition: bool, label: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		printerr("FAIL ", label)


func _init() -> void:
	var data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_dwarf_life.json"))
	check(data["constants"]["seconds_per_hour"] == Clock.SECONDS_PER_HOUR, "source hours scale")
	check(data["constants"]["round_bias"] == 0.05, "source tolerance, not nearest-half rounding")
	for sample: Dictionary in data["needs_oracle"]:
		var result: Dictionary = Needs.tick(sample["needs"], sample["context"])
		for key: String in ["hitpoints", "nutrition", "alertness", "mood"]:
			check(absf(float(result["needs"][key])-float(sample["expected"][key])) < 0.000000000001,
				"actual Tcl needs "+key+" "+str(sample["context"]))
		check(result["common_mood"] == sample["common_mood"], "source mood before attribute update")
	for sample: Dictionary in data["shift_oracle"]:
		var plan: Array[Dictionary] = Needs.assign_ordered_shifts(int(sample["count"]), float(sample["hours"]))
		check(plan.size() == sample["expected"].size(), "source assignment count")
		for index: int in range(plan.size()):
			check(int(plan[index]["start"]) == int(sample["expected"][index]["start"])
				and float(plan[index]["duration"]) == float(sample["expected"][index]["duration"]), "actual Tcl shift slot")
	check(Clock.hours(150) == 1.0 and Clock.hours(1800) == 12.0, "hours are not wall-clock hours")
	check(Clock.quantize_shift(0.3) == 0.0 and Clock.quantize_shift(0.49) == 0.5, "source floor quantization")
	check(Clock.quantize_shift(0.4749) == 0.0 and Clock.quantize_shift(0.4751) == 0.5, "source tolerance boundary")
	check(Clock.working(0, 0, 6) and Clock.working(899.9, 0, 6), "ordinary shift start included")
	check(not Clock.working(900, 0, 6), "ordinary shift end excluded")
	check(Clock.working(1500, 9, 6) and Clock.working(0, 9, 6), "wrapped shift")
	check(not Clock.working(450, 9, 6), "wrapped end excluded")
	check(not Clock.working(0, 0, 0) and not Clock.working(0, 0, 12), "native modulo duration, including full-cycle zero")
	check(is_equal_approx(Clock.remaining_spare(900, 0, false), 6.0), "remaining spare is hours")
	check(Clock.remaining_spare(900, 0, true) == 0.0, "working flag suppresses sparetime")
	var clock: RefCounted = Clock.new()
	clock.advance(0.5)
	clock.paused = true
	check(clock.advance(100.0) == 0.0 and clock.seconds == 0.5, "pause freezes game time")
	clock.paused = false
	clock.time_scale = 2.0
	check(clock.advance(0.25) == 0.5 and clock.seconds == 1.0, "explicit time scale")
	check(is_equal_approx(Needs.shift_priority(data["defaults"]), 0.5), "source weighted nutrition priority")
	print("NATIVE_DWARF_LIFE_SELF_TEST checks=", checks, " failures=", failures)
	quit(0 if failures == 0 else 1)
