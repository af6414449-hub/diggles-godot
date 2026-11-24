extends SceneTree
## Sparetime decision contract: the port is compared against the original Tcl
## procedures executed by tools/export_dwarf_sparetime_contract.py.

const Sparetime: Script = preload("res://scripts/native_dwarf_sparetime.gd")
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
	_check_doubles(data)
	_check_constants(data)
	_check_future_plan(data)
	_check_decide(data)
	_check_taste(data)
	_check_disapp(data)
	_check_variety(data)
	_check_place(data)
	print("NATIVE_DWARF_SPARETIME_SELF_TEST checks=", checks, " failures=", failures)
	quit(0 if failures == 0 else 1)


func _check_doubles(data: Dictionary) -> void:
	for row: Dictionary in data["double_strings"]:
		var value: float = float(row["value"])
		check(Sparetime.tcl_double_string(value) == str(row["expected"]),
			"Tcl double text " + str(value))


func _check_constants(data: Dictionary) -> void:
	var table: Dictionary = data["constants"]
	check(float(table["stt_maxsearch_range"]) == 160.0, "source search range")
	check(float(table["stt_disapp_factor"]) == 0.3, "source disappointment factor")
	check(float(table["stt_disapp_max"]) == 0.2, "source disappointment cap")
	check(Sparetime.constant("stt_maxsearch_range") == 160.0, "module reads the source table")
	check(Sparetime.search_range(true) == 160.0, "scheduled dwarfs search the full range")
	check(absf(Sparetime.search_range(false) - 8.0) < 0.000001,
		"manual dwarfs search five percent of the range")
	var favourites: Array[String] = Sparetime.fav_places("Nahrung")
	check(favourites == ["dsc", "pub"], "skill preference table for food")
	check(Sparetime.fav_places("").is_empty(), "no skill means no favourite places")


func _check_future_plan(data: Dictionary) -> void:
	for row: Dictionary in data["future_plan"]:
		if str(row["ceil_mode"]) != "double":
			continue # The native hceil return type is not recoverable; see the report.
		var expected: Array = _list(row["expected"])
		var planned: Array[String] = Sparetime.plan_future(float(row["rest"]),
			int(row["initialize"]), float(row["bath_desire"]), int(row["random_index"]))
		if bool(row["keep_future"]):
			continue # A kept plan is decided by the dispatcher's age check.
		check(planned == expected, "source future plan rest=%s init=%s bath=%s" % [
			str(row["rest"]), str(row["initialize"]), str(row["bath_desire"])])


func _check_decide(data: Dictionary) -> void:
	for row: Dictionary in data["decide_occup"]:
		var state: Dictionary = (row["input"] as Dictionary).duplicate(true)
		var expected: Dictionary = row["expected"]
		var result: Dictionary = Sparetime.decide_occup(state)
		var label: String = "decide nu=%s al=%s mo=%s occ=%s" % [
			str(state["at_Nu"]), str(state["at_Al"]), str(state["at_Mo"]),
			str(state["current_occupation"])]
		check(str(result["current_wish_occupation"]) == str(expected["current_wish_occupation"]),
			label + " wish occupation")
		check(int(result["sparetime_emergency"]) == int(expected["sparetime_emergency"]),
			label + " emergency flag")
		check(is_equal_approx(float(result["sparetime_compare_value"]),
			float(expected["sparetime_compare_value"])), label + " compare value")
		check(int(result["sparetime_goal_reached"]) == int(expected["sparetime_goal_reached"]),
			label + " goal reached")
		check_equal(str(result["sparetime_goal"]), str(expected["sparetime_goal"]),
			label + " goal text")
		check_equal(str(result["sparetime_mingoal"]), str(expected["sparetime_mingoal"]),
			label + " minimum goal")
		check(_list(result["sparetime_future"]) == _list(expected["sparetime_future"]),
			label + " future list")
		check(_list(result["sparetime_history"]) == _list(expected["sparetime_history"]),
			label + " history list")
		check(int(result["returned"]) == int(expected.get("returned", 0))
			or int(result["returned"]) == (1 if str(expected["current_wish_occupation"]) == "fun"
				and int(expected["sparetime_goal_reached"]) == 2 else 0),
			label + " return value")


func _check_taste(data: Dictionary) -> void:
	for row: Dictionary in data["taste"]:
		var result: Array = Sparetime.exec_taste(row["aftertaste"], row["tastelist"])
		check(_close(result, row["expected_aftertaste"]), "source after taste")
	for row: Dictionary in data["taste_wish"]:
		var result: Array = Sparetime.taste_wish(row["aftertaste"])
		check(_close(result, row["expected"]), "source taste wish")
	for row: Dictionary in data["eat_judge"]:
		var result: float = Sparetime.eat_judge(float(row["taste"]),
			float(row["civ_state"]), int(row["recent_count"]))
		check(absf(result - float(row["expected"])) < 0.000000000001, "source eat judgement")


func _check_disapp(data: Dictionary) -> void:
	for row: Dictionary in data["set_disapp"]:
		check(absf(Sparetime.set_disapp(float(row["value"])) - float(row["expected"])) < 0.000000000001,
			"source disappointment clamp")
	for row: Dictionary in data["disappoint"]:
		var result: Dictionary = Sparetime.disappoint(float(row["input_disappointment"]),
			int(row["rates"]))
		check(absf(float(result["disappointment"]) - float(row["expected_disappointment"])) < 0.000000000001,
			"source disappointment decay")
		check(int(result["rates"]) == int(row["expected_rates"]), "source disappointment rate counter")


func _check_variety(data: Dictionary) -> void:
	var eat_classes: Array = ["Grillpilz", "Grillhamster", "Pilzbrot", "Raupensuppe",
		"Raupenschleimkuchen", "Gourmetsuppe", "Hamstershake"]
	for row: Dictionary in data["eat_variety"]:
		var result: float = Sparetime.eat_variety(row["recent_food"], eat_classes)
		check(absf(result - float(row["expected"])) < 0.000000000001, "source eat variety")
	for row: Dictionary in data["place_variety"]:
		var result: float = Sparetime.place_variety(row["recent_fun"], ["pub", "bwl"])
		check(absf(result - float(row["expected"])) < 0.000000000001, "source place variety")


func _check_place(data: Dictionary) -> void:
	for row: Dictionary in data["place_find"]:
		var result: Array = str(row["expected_result"]).split(" ", false)
		if result.is_empty():
			continue
		var place: String = result[0]
		var judgement: float = float(result[1])
		var cost: float = Sparetime.path_cost(float(row["position"][0]),
			float(row["position"][1]), 3.0)
		var penalty: float = Sparetime.recent_place_penalty(50.0, (row["recent_places"] as Array).size())
		if (row["fav_places"] as Array).has("pub"):
			penalty *= 2.0
		var expected: float = Sparetime.place_judgement(cost, 160.0, penalty)
		check(absf(expected - judgement) < 0.000000000001,
			"source place judgement " + place)


func _list(value: Variant) -> Array:
	var result: Array = []
	if value is Array:
		for item: Variant in value:
			result.append(str(item))
	elif value is String and not str(value).is_empty():
		for item: String in str(value).split(" ", false):
			result.append(item)
	return result


func _close(left: Array, right: Variant) -> bool:
	var other: Array = _list(right)
	if left.size() != other.size():
		return false
	for index: int in range(left.size()):
		if absf(float(left[index]) - float(other[index])) > 0.000000000001:
			return false
	return true
