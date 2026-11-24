extends SceneTree
## --headless --path godot --script res://tools/native_farm_raupe_self_test.gd
## Checks the worm side of the Farm class: the candidate query, the worm lock,
## the production threshold, the fodder, the creation cooldown and the
## inventory hand in.
##
## Sources (original install, data/Scripts/classes/work/farm.tcl).
const FarmRaupe = preload("res://scripts/native_farm_raupe.gd")

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
	# --- the candidate query (farm.tcl:245) ------------------------------------
	var request := FarmRaupe.candidate_request(Vector3(4.0, 0.0, 0.0))
	_check(String(request["class"]) == "Raupe", "the farm looks for Raupen")
	_check((request["box"] as Vector3) == Vector3(2.0, 0.5, 3.0), "the candidates are the ones next to the farm")
	_check((request["flagneg"] as Array).has("contained"), "a contained Raupe is no candidate")
	_check((request["center"] as Vector3) == Vector3(4.0, 0.0, 0.0), "the query is centred on the farm")

	# --- the worm lock (farm.tcl:470-481) -------------------------------------
	var farm := FarmRaupe.new()
	var candidates: Array = [
		{"ref": "w1", "locked": false},
		{"ref": "w2", "locked": true},
	]
	_check(String(farm.actualize_worm(candidates, "w1")) == "w1", "a locked worm that is still there keeps the lock")
	_check(String(farm.actualize_worm(candidates, "w9")) == "w1", "a lost lock falls to the first free worm")
	var all_locked: Array = [
		{"ref": "w1", "locked": true},
		{"ref": "w2", "locked": true},
	]
	_check(String(farm.actualize_worm(all_locked, "w1")) == "w1", "a worm that is still there keeps the lock")
	_check(String(farm.actualize_worm(all_locked, "w9")) == "", "without a free worm there is no lock")

	# --- the production threshold (farm.tcl:248-259) --------------------------
	_check(FarmRaupe.MAX_WORMS == 6, "a farm holds six Raupen")
	_check(absf(FarmRaupe.threshold(0, 0.0) - 60.0) < 0.0001, "an empty material needs sixty ticks")
	_check(absf(FarmRaupe.threshold(1, 0.0) - 48.0) < 0.0001, "one material removes twelve ticks")
	_check(absf(FarmRaupe.threshold(1, 0.5) - 50.5) < 0.0001, "the threshold carries five random ticks")
	_check(absf(FarmRaupe.WORM_FODDER_COST - 30.0) < 0.0001, "a recreated worm costs thirty fodder")

	var plan := farm.production_plan(6, 100, 0, 0.0, true)
	_check(not bool(plan["recreate"]), "a full farm does not recreate")
	_check(int(plan["counter"]) == 100, "a full farm does not count")
	plan = farm.production_plan(0, 100, 0, 0.0, true)
	_check(not bool(plan["recreate"]), "an empty farm does not recreate")
	plan = farm.production_plan(1, 100, 0, 0.0, false)
	_check(not bool(plan["recreate"]), "without a dwarf there is no recreation")
	_check(int(plan["counter"]) == 100, "without a dwarf there is no counting")
	plan = farm.production_plan(1, 10, 0, 0.0, true)
	_check(not bool(plan["recreate"]), "below the threshold there is no recreation")
	_check(int(plan["counter"]) == 11, "below the threshold the counter grows")
	plan = farm.production_plan(1, 60, 0, 0.0, true)
	_check(not bool(plan["recreate"]), "the threshold is exclusive")
	_check(int(plan["counter"]) == 61, "the exclusive threshold still counts")
	plan = farm.production_plan(1, 61, 0, 0.0, true)
	_check(bool(plan["recreate"]), "above the threshold the farm recreates")
	_check(absf(float(plan["fodder"]) - 30.0) < 0.0001, "a recreation costs thirty fodder")
	_check(int(plan["counter"]) == 0, "a recreation resets the counter")

	# --- the creation cooldown (farm.tcl:498-502) ----------------------------
	_check(absf(FarmRaupe.CREATION_COOLDOWN - 50.0) < 0.0001, "the creation cooldown is fifty seconds")
	var cooldown := FarmRaupe.new()
	cooldown.last_creation = 100.0
	_check(not cooldown.can_recreate(149.9), "the cooldown blocks a creation")
	_check(cooldown.can_recreate(150.0), "the cooldown ends after fifty seconds")
	var create_request := cooldown.recreate_request(Vector3(2.0, 0.0, 3.0))
	_check((create_request["center"] as Vector3) == Vector3(2.0, 0.0, 3.0), "the new worm appears at the farm")
	var rectangle: Array = create_request["rect"]
	_check(absf(float(rectangle[0]) + 1.7) < 0.0001, "the new worm starts 1.7 units before the farm")
	_check(absf(float(rectangle[1]) + 2.5) < 0.0001, "the new worm starts 2.5 units before the farm")
	_check(absf(float(rectangle[2]) - 1.7) < 0.0001, "the new worm ends 1.7 units after the farm")
	_check(absf(float(rectangle[3]) - 2.5) < 0.0001, "the new worm ends 2.5 units after the farm")
	_check(int(create_request["random"]) == 2, "the new worm position is randomised by two")

	# --- applying a creation (farm.tcl:252-255) ------------------------------
	var applied := farm.apply_creation(plan, false)
	_check(int(applied["counter"]) == 61, "a failed creation keeps the counter")
	_check(absf(float(applied["fodder"])) < 0.0001, "a failed creation costs no fodder")
	applied = farm.apply_creation(plan, true)
	_check(int(applied["counter"]) == 0, "a creation resets the counter")
	_check(absf(float(applied["fodder"]) - 30.0) < 0.0001, "a creation costs thirty fodder")

	# --- the inventory hand in (farm.tcl:334-343) ----------------------------
	var removal := FarmRaupe.inventory_removal(7)
	_check(int(removal["type"]) == 7, "the inventory Raupe keeps its type")
	_check(bool(removal["remove"]), "the inventory Raupe is taken out")

	# --- releasing the lock (farm.tcl:354-357) -------------------------------
	farm.original_worm = "w1"
	farm.free_original_worm()
	_check(String(farm.original_worm) == "", "releasing the worm clears the lock")

	if _failures.is_empty():
		print("NATIVE_FARM_RAUPE_SELF_TEST_OK assertions=%d" % _checks)
	else:
		printerr("NATIVE_FARM_RAUPE_SELF_TEST_FAIL failures=%d" % _failures.size())
	quit(0 if _failures.is_empty() else 1)
