extends SceneTree
## Place registry: the guest seat bookkeeping is compared against the original
## Tcl procedure executed by tools/export_dwarf_sparetime_contract.py.
##
## Source of truth:
##   data/Scripts/classes/zwerg/z_spare_procs.tcl:851-880  sparetime_find_place
##   data/Scripts/classes/zwerg/z_spare_procs.tcl:882-917  sparetime_check_in

const Registry: Script = preload("res://scripts/native_dwarf_place_registry.gd")
var checks: int = 0
var failures: int = 0


func check(condition: bool, label: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		printerr("FAIL ", label)


func check_equal(actual: Variant, expected: Variant, label: String) -> void:
	checks += 1
	if str(actual) != str(expected):
		failures += 1
		printerr("FAIL ", label, " actual=", str(actual), " expected=", str(expected))


func _init() -> void:
	var data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(
		"res://models/native_dwarf_sparetime.json"))
	check(data["schema"] == "diggles.dwarf_sparetime.v1", "source contract schema")
	_check_check_in(data)
	_check_seat_table()
	_check_recent_places()
	print("NATIVE_DWARF_PLACE_REGISTRY_SELF_TEST checks=", checks, " failures=", failures)
	quit(0 if failures == 0 else 1)


## z_spare_procs.tcl:882-917 - the whole check in sequence.
func _check_check_in(data: Dictionary) -> void:
	for row: Dictionary in data["check_in"]:
		var registry: RefCounted = Registry.new()
		registry.register_place(33, "Feuerstelle", 2 if str(row["name"]) != "full" else 0)
		registry.random_seat = func(_place_id: int) -> int: return 1
		if str(row["name"]) == "replace":
			# The dwarf already sits in place 33 on seat 0.
			registry.current_place_ref = 33
			registry.current_place = "Feuerstelle"
			registry.seat = 0
		var result: Dictionary = registry.check_in(33, int(row["method"]))
		check_equal(_calls(result["calls"]), row["expected_calls"],
			"check in calls " + str(row["name"]))
		check_equal(int(result["result"]), int(row["expected_result"]),
			"check in result " + str(row["name"]))
		check_equal(int(result["place_ref"]), int(row["expected_place_ref"]),
			"check in place ref " + str(row["name"]))
		check_equal(str(result["place_class"]), _text(row["expected_place_class"]),
			"check in place class " + str(row["name"]))
		check_equal(int(result["seat"]), int(row["expected_seat"]),
			"check in seat " + str(row["name"]))


## The registry owns the seat table that the original keeps in `prod_guest`.
func _check_seat_table() -> void:
	var registry: RefCounted = Registry.new()
	registry.register_place(7, "Feuerstelle", 3)
	check(registry.seat_count(7) == 3, "seat table count")
	check(registry.free_seat(7) == 0, "seat table first free seat")
	check(registry.claim(7, 0, 42), "seat table claim")
	check(registry.occupied_seats(7) == 1, "seat table occupied")
	check(registry.free_seat(7) == 1, "seat table next free seat")
	check(registry.guest_at(7, 0) == 42, "seat table guest")
	check(registry.release(7, 42) == 0, "seat table release")
	check(registry.occupied_seats(7) == 0, "seat table released")
	check(registry.free_seat(7) == 0, "seat table free again")
	check(not registry.claim(9, 0, 42), "seat table unknown place")
	check(registry.free_seat(9) == -1, "seat table unknown place has no seat")
	registry.remove_place(7)
	check(not registry.has_place(7), "seat table removed")


## z_spare_fun.tcl:480 and z_spare_fun.tcl:604-613 - the recent place penalty.
func _check_recent_places() -> void:
	var registry: RefCounted = Registry.new()
	check(registry.recent_count("pub") == 0, "recent places start empty")
	registry.note_visit("pub")
	registry.note_visit("pub")
	check(registry.recent_count("pub") == 2, "recent places counted")
	# The source adds (1-da)*0.05*count, so a normal desire raises the value.
	check(registry.place_penalty(1.0, "pub") > registry.place_penalty(1.0, "tht"),
		"recent places raise the penalty")
	# With the oracle tuning of 50.0 the factor (1-da) is negative, so the
	# source lowers the desire instead. The port keeps that inversion.
	check(registry.place_penalty(50.0, "pub") < registry.place_penalty(50.0, "tht"),
		"recent places invert with the oracle tuning")
	check(registry.desire_with_favourites(1.0, "pub", ["pub"]) > registry.place_penalty(1.0, "pub"),
		"favourite places double the desire")
	var finished: Dictionary = registry.place_finished("pub", 55, 1000.0)
	check_equal(_calls(finished["calls"]), [["sparetime_fun_entry", "place"]],
		"place finished entry")
	check(registry.recent_fun().has("pub"), "place finished remembered")
	check(registry.avoid_place()["ref"] == 55, "place finished avoids the place")
	var again: Dictionary = registry.place_finished("pub", 55, 1010.0)
	check((again["calls"] as Array).is_empty(), "place finished inside the cooldown")


# --------------------------------------------------------------------------- #
# helpers
# --------------------------------------------------------------------------- #
## The oracle keeps an empty place class as the number zero.
func _text(value: Variant) -> String:
	if value is int:
		return "" if int(value) == 0 else str(value)
	if value is float:
		return "" if is_zero_approx(value) else str(value)
	return str(value)


func _calls(calls: Array) -> Array:
	var result: Array = []
	for call: Array in calls:
		var row: Array = []
		for item: Variant in call:
			row.append(str(item))
		result.append(row)
	return result
