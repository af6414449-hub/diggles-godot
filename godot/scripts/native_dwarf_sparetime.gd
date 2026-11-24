extends RefCounted
## Sparetime decision contract ported from the original Diggles Tcl.
##
## Source of truth (installed game, read only):
##   data/Scripts/classes/zwerg/z_spare_main.tcl   sparetime_decide_occup, future plan
##   data/Scripts/classes/zwerg/z_spare_procs.tcl  search range, disappointment, taste
##   data/Scripts/classes/zwerg/z_spare_fun.tcl    place judgement, fun stations
##   data/Scripts/misc/sparetimetunes.tcl          tuning table
##
## Golden values live in res://models/native_dwarf_sparetime.json and were produced
## by running the original procedures in a Tcl interpreter.
##
## The decision keeps the source spelling of its state variables so that every
## branch can be traced back to a line range in the original file.

const DATA_PATH: String = "res://models/native_dwarf_sparetime.json"
const OCCUPATIONS: Array[String] = ["eat", "fun", "slp", "bth"]
const EMERGENCY_JOBS: Array[String] = ["eat", "fun", "slp", "bth", "ill"]
const POWERS_POSITIVE: Array[float] = [
	1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10, 1e11,
	1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18, 1e19, 1e20, 1e21, 1e22]
const POWERS_NEGATIVE: Array[float] = [
	1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-9, 1e-10, 1e-11,
	1e-12, 1e-13, 1e-14, 1e-15, 1e-16, 1e-17, 1e-18, 1e-19, 1e-20, 1e-21, 1e-22]

static var _constants: Dictionary = {}


static func constants() -> Dictionary:
	if _constants.is_empty():
		var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(DATA_PATH))
		if parsed is Dictionary:
			_constants = parsed["constants"]
	return _constants


static func constant(name: String, fallback: float = 0.0) -> float:
	var table: Dictionary = constants()
	return float(table.get(name, fallback))


# --------------------------------------------------------------------------- #
# Tcl compatible number formatting
# --------------------------------------------------------------------------- #
## Tcl prints doubles with the shortest representation that round-trips and
## switches to exponent form outside -4 < exp < 17. The source relies on the
## resulting *string* order: z_spare_main.tcl:422 sorts the emergency list with
## a plain `lsort -index 1`, which is an ASCII comparison of those strings.
static func tcl_double_string(value: float) -> String:
	if value == 0.0:
		return "-0.0" if _negative_zero(value) else "0.0"
	var negative: bool = value < 0.0
	var magnitude: float = absf(value)
	var exponent: int = _decimal_exponent(magnitude)
	var digits: String = ""
	var text: String = ""
	for significant: int in range(1, 18):
		var decimals: int = maxi(0, significant - 1 - exponent)
		text = _format_fixed(magnitude, decimals)
		if text.to_float() == magnitude:
			digits = _significant_digits(text)
			break
	if digits.is_empty():
		text = _format_fixed(magnitude, 17)
		digits = _significant_digits(text)
	var result: String = ""
	if exponent < -4 or exponent > 16:
		result = digits.substr(0, 1)
		if digits.length() > 1:
			result += "." + digits.substr(1)
		result += "e"
		result += "-" if exponent < 0 else "+"
		result += str(absi(exponent))
	else:
		var dot: int = text.find(".")
		result = text if dot >= 0 else text + ".0"
	return ("-" if negative else "") + result


## Correctly rounded fixed notation. Godot's own float formatting rounds the
## last decimal digit differently from the C library, and the source goal
## strings are compared byte for byte, so the rounding is done here with exact
## error free transformations.
static func _format_fixed(value: float, decimals: int) -> String:
	var scaled: int = _scaled_integer(value, decimals)
	var negative: bool = scaled < 0
	var digits: String = str(absi(scaled))
	if decimals == 0:
		return ("-" if negative else "") + digits
	while digits.length() <= decimals:
		digits = "0" + digits
	var split: int = digits.length() - decimals
	return ("-" if negative else "") + digits.substr(0, split) + "." + digits.substr(split)


## round_half_even(value * 10^decimals) without losing a bit.
static func _scaled_integer(value: float, decimals: int) -> int:
	var scale: float = _power_of_ten(decimals)
	var product: Array = _two_product(value, scale)
	var sum: Array = _two_sum(float(product[0]), float(product[1]))
	var result: int = roundi(float(sum[0]))
	var residual: float = float(sum[1])
	if absf(residual) == 0.5 and (result & 1) != 0:
		result += 1 if residual > 0.0 else -1
	return result


## Exact sum: a + b == sum + error.
static func _two_sum(a: float, b: float) -> Array:
	var total: float = a + b
	var b_virtual: float = total - a
	var a_virtual: float = total - b_virtual
	var b_round: float = b - b_virtual
	var a_round: float = a - a_virtual
	return [total, a_round + b_round]


## Exact product: a * b == product + error.
static func _two_product(a: float, b: float) -> Array:
	var product: float = a * b
	const SPLITTER: float = 134217729.0
	var c_a: float = SPLITTER * a
	var a_high: float = c_a - (c_a - a)
	var a_low: float = a - a_high
	var c_b: float = SPLITTER * b
	var b_high: float = c_b - (c_b - b)
	var b_low: float = b - b_high
	var error: float = ((a_high * b_high - product) + a_high * b_low + a_low * b_high) \
		+ a_low * b_low
	return [product, error]


static func _power_of_ten(exponent: int) -> float:
	if exponent >= 0:
		return POWERS_POSITIVE[exponent] if exponent < POWERS_POSITIVE.size() \
			else pow(10.0, exponent)
	# POWERS_NEGATIVE[0] is 1e-1, so 1e-n lives at index n-1.
	var index: int = -exponent - 1
	return POWERS_NEGATIVE[index] if index < POWERS_NEGATIVE.size() else pow(10.0, exponent)


## floor(log10(magnitude)) for a positive double.
static func _decimal_exponent(magnitude: float) -> int:
	if magnitude >= 1.0:
		return str(floori(magnitude)).length() - 1
	for exponent: int in range(1, 30):
		if magnitude >= _power_of_ten(-exponent):
			return -exponent
	return -30


static func _significant_digits(text: String) -> String:
	var dot: int = text.find(".")
	var raw: String = text if dot < 0 else text.substr(0, dot) + text.substr(dot + 1)
	var start: int = 0
	while start < raw.length() and raw[start] == "0":
		start += 1
	var digits: String = raw.substr(start)
	while digits.length() > 1 and digits.ends_with("0"):
		digits = digits.substr(0, digits.length() - 1)
	return digits


static func _negative_zero(value: float) -> bool:
	var buffer: PackedFloat64Array = PackedFloat64Array()
	buffer.resize(1)
	buffer[0] = value
	var bytes: PackedByteArray = buffer.to_byte_array()
	return (bytes[7] & 0x80) != 0


# --------------------------------------------------------------------------- #
# Tcl expression subset used by the source goals
# --------------------------------------------------------------------------- #
## The source stores its leisure goal as a Tcl expression string and evaluates
## it with `if "$sparetime_goal"`. Only numbers, $variable references, + - *
## and the comparison operators appear there.
static func evaluate(expression: String, values: Dictionary) -> float:
	var tokens: Array = _tokenize(expression)
	var cursor: Dictionary = {"index": 0}
	return _parse_comparison(tokens, cursor, values)


static func _is_name_char(char: String) -> bool:
	return (char >= "a" and char <= "z") or (char >= "A" and char <= "Z") \
		or (char >= "0" and char <= "9") or char == "_"


static func _is_digit(char: String) -> bool:
	return char >= "0" and char <= "9"


static func _tokenize(expression: String) -> Array:
	var tokens: Array = []
	var index: int = 0
	var length: int = expression.length()
	while index < length:
		var char: String = expression[index]
		if char == " " or char == "\t" or char == "\n" or char == "\r":
			index += 1
			continue
		if char == "$":
			index += 1
			var name_start: int = index
			while index < length and _is_name_char(expression[index]):
				index += 1
			tokens.append({"kind": "ref", "value": expression.substr(name_start, index - name_start)})
			continue
		if _is_digit(char) or char == ".":
			var number_start: int = index
			while index < length and (_is_digit(expression[index]) or expression[index] == "."):
				index += 1
			if index < length and (expression[index] == "e" or expression[index] == "E"):
				var probe: int = index + 1
				if probe < length and (expression[probe] == "+" or expression[probe] == "-"):
					probe += 1
				if probe < length and _is_digit(expression[probe]):
					index = probe
					while index < length and _is_digit(expression[index]):
						index += 1
			tokens.append({"kind": "number",
				"value": expression.substr(number_start, index - number_start).to_float()})
			continue
		if _is_name_char(char):
			var name_start: int = index
			while index < length and _is_name_char(expression[index]):
				index += 1
			tokens.append({"kind": "ref", "value": expression.substr(name_start, index - name_start)})
			continue
		var pair: String = expression.substr(index, 2)
		if pair in [">=", "<=", "==", "!="]:
			tokens.append({"kind": "op", "value": pair})
			index += 2
			continue
		if char in [">", "<", "+", "-", "*", "(", ")"]:
			tokens.append({"kind": "op", "value": char})
			index += 1
			continue
		index += 1
	return tokens


static func _parse_comparison(tokens: Array, cursor: Dictionary, values: Dictionary) -> float:
	var left: float = _parse_sum(tokens, cursor, values)
	if int(cursor["index"]) < tokens.size():
		var token: Dictionary = tokens[int(cursor["index"])]
		if str(token["kind"]) == "op" and str(token["value"]) in [">", "<", ">=", "<=", "==", "!="]:
			cursor["index"] = int(cursor["index"]) + 1
			var right: float = _parse_sum(tokens, cursor, values)
			match str(token["value"]):
				">": return 1.0 if left > right else 0.0
				"<": return 1.0 if left < right else 0.0
				">=": return 1.0 if left >= right else 0.0
				"<=": return 1.0 if left <= right else 0.0
				"==": return 1.0 if left == right else 0.0
				"!=": return 1.0 if left != right else 0.0
	return left


static func _parse_sum(tokens: Array, cursor: Dictionary, values: Dictionary) -> float:
	var total: float = _parse_term(tokens, cursor, values)
	while int(cursor["index"]) < tokens.size():
		var token: Dictionary = tokens[int(cursor["index"])]
		if str(token["kind"]) == "op" and str(token["value"]) in ["+", "-"]:
			cursor["index"] = int(cursor["index"]) + 1
			var right: float = _parse_term(tokens, cursor, values)
			if str(token["value"]) == "+":
				total += right
			else:
				total -= right
		else:
			break
	return total


static func _parse_term(tokens: Array, cursor: Dictionary, values: Dictionary) -> float:
	var product: float = _parse_factor(tokens, cursor, values)
	while int(cursor["index"]) < tokens.size():
		var token: Dictionary = tokens[int(cursor["index"])]
		if str(token["kind"]) == "op" and str(token["value"]) == "*":
			cursor["index"] = int(cursor["index"]) + 1
			product *= _parse_factor(tokens, cursor, values)
		else:
			break
	return product


static func _parse_factor(tokens: Array, cursor: Dictionary, values: Dictionary) -> float:
	if int(cursor["index"]) >= tokens.size():
		return 0.0
	var token: Dictionary = tokens[int(cursor["index"])]
	match str(token["kind"]):
		"number":
			cursor["index"] = int(cursor["index"]) + 1
			return float(token["value"])
		"ref":
			cursor["index"] = int(cursor["index"]) + 1
			return float(values.get(str(token["value"]), 0.0))
		"op":
			if str(token["value"]) == "(":
				cursor["index"] = int(cursor["index"]) + 1
				var inner: float = _parse_comparison(tokens, cursor, values)
				if int(cursor["index"]) < tokens.size():
					var closing: Dictionary = tokens[int(cursor["index"])]
					if str(closing["kind"]) == "op" and str(closing["value"]) == ")":
						cursor["index"] = int(cursor["index"]) + 1
				return inner
			if str(token["value"]) == "-":
				cursor["index"] = int(cursor["index"]) + 1
				return -_parse_factor(tokens, cursor, values)
	return 0.0


static func _is_numeric(value: Variant) -> bool:
	var text: String = str(value)
	if text.is_empty():
		return false
	return text.is_valid_float()


## Tcl compares numerically only when both operands are numeric strings.
static func tcl_less(left: Variant, right: Variant) -> bool:
	if _is_numeric(left) and _is_numeric(right):
		return float(left) < float(right)
	return str(left) < str(right)


# --------------------------------------------------------------------------- #
# Goal helpers
# --------------------------------------------------------------------------- #
## `lindex $sparetime_goal 1` - the attribute value frozen into the goal.
static func goal_base(goal: String) -> float:
	var tokens: PackedStringArray = goal.split(" ", false)
	if tokens.size() < 2:
		return 0.0
	return tokens[1].to_float()


## `[subst [string trim [lindex $sparetime_goal 0] "-"]]` - the live attribute.
static func goal_head(goal: String, values: Dictionary) -> float:
	var tokens: PackedStringArray = goal.split(" ", false)
	if tokens.is_empty():
		return 0.0
	var token: String = _trim_dashes(tokens[0])
	if token.begins_with("$"):
		token = token.substr(1)
	return float(values.get(token, 0.0))


## Tcl `string trim <text> "-"` removes the dash from both ends.
static func _trim_dashes(text: String) -> String:
	var start: int = 0
	var end: int = text.length()
	while start < end and text[start] == "-":
		start += 1
	while end > start and text[end - 1] == "-":
		end -= 1
	return text.substr(start, end - start)


# --------------------------------------------------------------------------- #
# Future plan (z_spare_main.tcl:53-68)
# --------------------------------------------------------------------------- #
## The source plans the leisure sequence once per leisure phase. `hceil` is a
## native command; the double form is used here because the switch patterns in
## the original are written as "0.0" .. "4.0".
static func plan_future(rest: float, initialize: int, bath_desire: float,
		random_index: int = 0) -> Array[String]:
	var ceiling: float = ceil(rest)
	var future: Array[String] = []
	if is_equal_approx(ceiling, 0.0):
		future = []
	elif is_equal_approx(ceiling, 1.0):
		future = ["eat", "slp"]
		future = [future[clampi(random_index, 0, future.size() - 1)]]
	elif is_equal_approx(ceiling, 2.0):
		future = _lrange(["eat", "slp", "eat"], initialize - 1, initialize)
	elif is_equal_approx(ceiling, 3.0):
		future = _lrange(["", "eat", "fun", "slp", "eat"], initialize, initialize + 2)
	elif is_equal_approx(ceiling, 4.0):
		future = ["eat", "fun", "slp", "eat"]
	else:
		future = ["eat", "fun", "slp", "bth", "eat"]
	if bath_desire < 3.0:
		future = _list_and_not(future, ["bth"])
	return future


## Tcl `lrange` keeps the elements from max(first, 0) to last and returns an
## empty list when last is before that start.
static func _lrange(source: Array[String], first: int, last: int) -> Array[String]:
	var start: int = maxi(first, 0)
	var result: Array[String] = []
	if last < start or start >= source.size():
		return result
	var end: int = mini(last, source.size() - 1)
	for index: int in range(start, end + 1):
		result.append(source[index])
	return result


## Native `lnand a b` returns the elements of b that are not in a.
static func _list_and_not(source: Array[String], removed: Array[String]) -> Array[String]:
	var result: Array[String] = []
	for item: String in source:
		if not removed.has(item):
			result.append(item)
	return result


# --------------------------------------------------------------------------- #
# Emergency list (z_spare_main.tcl:422)
# --------------------------------------------------------------------------- #
## `lsort -index 1` without -real is an ASCII comparison of the printed value.
static func emergency_order(at_nu: float, at_al: float, at_fun: float) -> Array[Dictionary]:
	var entries: Array[Dictionary] = [
		{"name": "eat", "value": at_nu},
		{"name": "slp", "value": at_al},
		{"name": "fun", "value": at_fun},
	]
	# Insertion sort keeps the stable order of the original list sort.
	for index: int in range(1, entries.size()):
		var current: Dictionary = entries[index]
		var key: String = tcl_double_string(float(current["value"]))
		var position: int = index - 1
		while position >= 0 and tcl_double_string(float(entries[position]["value"])) > key:
			entries[position + 1] = entries[position]
			position -= 1
		entries[position + 1] = current
	return entries


static func station_count(stations: int) -> int:
	var count: int = 0
	var bit: int = 1
	while bit < 17:
		if (stations & bit) != 0:
			count += 1
		bit <<= 1
	return count


# --------------------------------------------------------------------------- #
# sparetime_decide_occup (z_spare_main.tcl:378-710)
# --------------------------------------------------------------------------- #
## Port of the source dispatcher. The state dictionary uses the original
## variable names; the result contains the updated state and the source return
## value ("1" when the leisure goal was reached).
static func decide_occup(state: Dictionary) -> Dictionary:
	var work: Dictionary = state.duplicate(true)
	var at_hi: float = float(work["at_Hi"])
	var at_nu: float = float(work["at_Nu"])
	var at_al: float = float(work["at_Al"])
	var at_mo: float = float(work["at_Mo"])
	var occupation: String = str(work["current_occupation"])
	var wish: String = str(work["current_wish_occupation"])
	var goal: String = str(work.get("sparetime_goal", ""))
	var mingoal: String = str(work.get("sparetime_mingoal", ""))
	var goal_reached: int = int(work.get("sparetime_goal_reached", 2))
	var emergency: bool = int(work.get("sparetime_emergency", 0)) != 0
	var emchange_initial: bool = int(work.get("sparetime_emchange_initial", 0)) != 0
	var compare_value: float = float(work.get("sparetime_compare_value", 0.0))
	var remembered_scv: float = float(work.get("sparetime_remembered_scv", 0.0))
	var future: Array = _as_list(work.get("sparetime_future", []))
	var history: Array = _as_list(work.get("sparetime_history", []))
	var fun_ignore: int = int(work.get("spt_fun_ignore", 0))
	var fun_stations: int = int(work.get("spt_fun_stations", 0))
	var fun_needs: int = int(work.get("spt_fun_needs", 0))
	var fun_portion: float = float(work.get("spt_fun_portion", 0.0))
	var bath_desire: float = float(work.get("spt_bath_desire", 0.0))
	var has_bathed: float = float(work.get("has_bathed", 0.0))
	var eat_check0: bool = int(work.get("eat_check", 0)) != 0
	var ill_check: bool = int(work.get("ill_check", 0)) != 0
	var remaining_spare: float = float(work.get("remaining_spare", 0.0))

	if goal_reached == 2:
		mingoal = ""

	var funstations: int = station_count(fun_stations)
	var funlack: float = float(fun_needs - funstations)
	var at_fun: float = minf(at_mo, 1.0 - funlack * 0.09)
	var emergency_tolerance: float = 0.3 + float(goal_reached) * 0.1
	if future.is_empty() and not emergency and bath_desire > 6.0:
		future = ["bth"]

	var maychange: bool = false
	var emergencies: Array[Dictionary] = []
	if at_hi < 0.97 and ill_check:
		emergencies = [{"name": "ill", "value": 0.0}]
	else:
		if fun_ignore != 0 and eat_check0 and at_nu < 0.8 \
				and (occupation == "fun" or occupation == "eat") \
				and not future.is_empty() and str(future[0]) == "eat":
			maychange = true
			goal = ""
			goal_reached = 2
		if maychange or (at_hi < 0.8 and (at_al < 0.4 or (at_nu < 0.4 and eat_check0))):
			if wish == "eat":
				fun_ignore = 0
			if at_nu + 0.1 < at_al:
				emergencies = [{"name": "eat", "value": at_nu}, {"name": "slp", "value": at_al}]
			else:
				emergencies = [{"name": "slp", "value": at_al}, {"name": "eat", "value": at_nu}]
		else:
			emergencies = emergency_order(at_nu, at_al, at_fun)

	var first_option: String = "eat"
	var emindex1: int = 0
	var emindex2: int = 0
	var while_counter: int = 0
	var emergency_tolerance_local: float = 1.0
	if emergency:
		emergency_tolerance_local = goal_base(goal) - 0.1
	var eat_check: bool = false
	var nextfuture: bool = false
	var is_emergency: bool = false

	while ((first_option == "eat" and not eat_check) or nextfuture) and while_counter < 100:
		nextfuture = false
		while_counter += 1
		is_emergency = true
		if emindex1 + emindex2 == 0:
			eat_check = eat_check0
		if emindex1 >= emergencies.size():
			# The source reads an empty entry here; the comparison would raise a
			# Tcl error. The port stops instead of aborting the dwarf.
			break
		first_option = str(emergencies[emindex1]["name"])
		var emergency_value: float = float(emergencies[emindex1]["value"])
		if first_option == "eat":
			emindex1 += 1
		if first_option == wish:
			if emchange_initial:
				emchange_initial = false
				compare_value = minf(emergency_tolerance_local, emergency_tolerance)
			elif not emergency:
				compare_value = emergency_tolerance_local + 0.2 - float(goal_reached) * 0.1
		else:
			emchange_initial = true
			compare_value = minf(emergency_tolerance_local, emergency_tolerance)
		if emergency:
			if goal_head(goal, _symbols(at_hi, at_nu, at_al, at_mo, has_bathed, funlack)) > 0.1 \
					and compare_value < 0.05:
				compare_value = 0.05
		if emergency_value > minf(compare_value, 0.5):
			is_emergency = false
			emergency = false
			var second_option: String = ""
			if goal_reached == 2 or emindex2 != 0:
				second_option = str(future[emindex2]) if emindex2 < future.size() else ""
				emchange_initial = false
			else:
				second_option = wish
			if goal_reached < 2 and (wish != "eat" or eat_check):
				first_option = wish
				second_option = wish
			else:
				if second_option == "":
					second_option = "fun"
					first_option = "fun"
				elif goal_reached == 2:
					var sc_value: float = 1.0
					match second_option:
						"eat": sc_value = at_nu
						"slp": sc_value = at_al
						"fun": sc_value = at_fun
						"bth": sc_value = 1.0 - bath_desire * 0.01
					if sc_value > 0.9 or (second_option == "eat" and sc_value > 0.8):
						if (at_nu < 0.8 and future.has("eat")) \
								or (at_al < 0.9 and future.has("slp")):
							emindex2 += 1
							nextfuture = true
							continue
						elif at_nu > 0.8 and at_al > 0.9:
							second_option = "fun"
							first_option = "fun"
					else:
						first_option = second_option
						if first_option == "eat":
							emindex2 += 1
		else:
			emergency = true

	emergency = is_emergency

	if wish != first_option:
		if not mingoal.is_empty():
			if evaluate(mingoal, _symbols(at_hi, at_nu, at_al, at_mo, has_bathed, funlack)) != 0.0:
				first_option = wish
	if wish != first_option and OCCUPATIONS.has(wish) and not goal.is_empty():
		if evaluate(goal + "*0.7", _symbols(at_hi, at_nu, at_al, at_mo, has_bathed, funlack)) != 0.0:
			var history_index: int = future.find(occupation)
			if history_index != -1:
				future.remove_at(history_index)
		history.append(occupation)
		goal = ""

	if goal.is_empty():
		mingoal = ""
		var second_value: Variant = ""
		if emergencies.size() > 1:
			second_value = float(emergencies[1]["value"])
		if emergency and (tcl_less(second_value, emergency_tolerance)
				or compare_value != remembered_scv):
			match first_option:
				"eat":
					var reachfor: float = minf(0.7, compare_value) if at_al < 0.4 else 0.88
					reachfor += 0.1
					goal = "$at_Nu- %s >(%s-%s)" % [tcl_double_string(at_nu),
						tcl_double_string(reachfor), tcl_double_string(at_nu)]
					if at_nu < 0.5 and minf(at_al, at_mo) < at_nu + 0.2:
						mingoal = "$at_Nu<%s+0.2" % tcl_double_string(at_nu)
				"slp":
					var reachfor: float = minf(0.7, compare_value) \
						if (at_nu < 0.5 and at_al < 0.5) else 0.88
					reachfor += 0.1
					goal = "$at_Al- %s >(%s-%s)" % [tcl_double_string(at_al),
						tcl_double_string(reachfor), tcl_double_string(at_al)]
					if at_al < 0.5 and minf(at_mo, at_nu) < at_al + 0.2:
						mingoal = "$at_Al<%s+0.2" % tcl_double_string(at_al)
				"fun":
					var funposs: float = 1.0
					if at_mo > 0.5:
						if funlack + float(fun_needs) > 5.0:
							goal = "%s- %s >($funlack-%s)" % [tcl_double_string(at_mo),
								tcl_double_string(at_mo), str(int(funlack))]
							funposs = maxf(1.0, funlack - 1.0)
						elif at_mo < 0.95:
							goal = "$at_Mo- %s >(0.98-%s)" % [tcl_double_string(at_mo),
								tcl_double_string(at_mo)]
						else:
							goal = "$at_Mo- %s >(-1)" % tcl_double_string(at_mo)
					else:
						goal = "$at_Mo- %s >(%s-%s+0.1)" % [tcl_double_string(at_mo),
							tcl_double_string(minf(0.7, compare_value)), tcl_double_string(at_mo)]
					fun_portion = (1.0 - at_mo) / funposs
					if at_mo < 0.5 and minf(at_al, at_nu) < at_mo + 0.2:
						mingoal = "$at_Mo<%s+0.2" % tcl_double_string(at_mo)
				"ill":
					goal = "$at_Hi- %s >(0.98-%s)" % [tcl_double_string(at_hi),
						tcl_double_string(at_hi)]
				_:
					goal = "1"
			remembered_scv = compare_value
		else:
			mingoal = ""
			if not future.has(first_option):
				future.insert(0, first_option)
			var deficit: float = 3.0 - at_nu - at_al - at_mo + remaining_spare * 0.1
			match first_option:
				"eat":
					var target: float = 0.0
					if _last_index(future, "eat") > 0 and at_nu < 0.5:
						target = 0.80 - at_nu
					else:
						target = 0.95 - at_nu
					goal = "$at_Nu- %s >=%s" % [tcl_double_string(at_nu), tcl_double_string(target)]
				"slp":
					var target: float = 0.0
					if at_nu < at_mo - 0.2:
						target = minf(0.98 - at_al,
							(1.0 - at_al + remaining_spare * 0.03) * 0.2 * remaining_spare / deficit)
					else:
						target = 0.98 - at_al
					goal = "$at_Al- %s >=%s" % [tcl_double_string(at_al), tcl_double_string(target)]
				"bth":
					goal = "$has_bathed>=5.0"
				"fun":
					var funposs: float = 1.0
					if funlack + float(fun_needs) > 5.0:
						goal = "%s- %s >($funlack-%s)" % [tcl_double_string(at_mo),
							tcl_double_string(at_mo), str(int(funlack))]
						funposs = maxf(1.0, funlack - 1.0)
					elif at_mo < 0.95:
						goal = "$at_Mo- %s >(0.98-%s)" % [tcl_double_string(at_mo),
							tcl_double_string(at_mo)]
					else:
						goal = "%s- %s >(-1)" % [tcl_double_string(at_mo), tcl_double_string(at_mo)]
					fun_portion = (1.0 - at_mo) / funposs
				_:
					goal = "1"
		goal_reached = 0
		wish = first_option
	else:
		var symbols: Dictionary = _symbols(at_hi, at_nu, at_al, at_mo, has_bathed, funlack)
		if evaluate(goal, symbols) != 0.0:
			goal_reached = 2
			fun_ignore = 0
		elif evaluate(goal + "*0.5", symbols) != 0.0:
			goal_reached = 1
			fun_ignore = 0
		else:
			goal_reached = 0
		if goal_reached == 2:
			goal = ""
			var done_index: int = future.find(occupation)
			if done_index != -1:
				future.remove_at(done_index)
			emergency = false
			wish = "fun"
			work["returned"] = 1
			_store(work, at_hi, at_nu, at_al, at_mo, occupation, wish, goal, mingoal,
				goal_reached, emergency, emchange_initial, compare_value, remembered_scv,
				future, history, fun_ignore, fun_portion)
			return work

	work["returned"] = 0
	_store(work, at_hi, at_nu, at_al, at_mo, occupation, wish, goal, mingoal,
		goal_reached, emergency, emchange_initial, compare_value, remembered_scv,
		future, history, fun_ignore, fun_portion)
	return work


static func _store(work: Dictionary, at_hi: float, at_nu: float, at_al: float, at_mo: float,
		occupation: String, wish: String, goal: String, mingoal: String, goal_reached: int,
		emergency: bool, emchange_initial: bool, compare_value: float, remembered_scv: float,
		future: Array, history: Array, fun_ignore: int, fun_portion: float) -> void:
	work["at_Hi"] = at_hi
	work["at_Nu"] = at_nu
	work["at_Al"] = at_al
	work["at_Mo"] = at_mo
	work["current_occupation"] = occupation
	work["current_wish_occupation"] = wish
	work["sparetime_goal"] = goal
	work["sparetime_mingoal"] = mingoal
	work["sparetime_goal_reached"] = goal_reached
	work["sparetime_emergency"] = 1 if emergency else 0
	work["sparetime_emchange_initial"] = 1 if emchange_initial else 0
	work["sparetime_compare_value"] = compare_value
	work["sparetime_remembered_scv"] = remembered_scv
	work["sparetime_future"] = future
	work["sparetime_history"] = history
	work["spt_fun_ignore"] = fun_ignore
	work["spt_fun_portion"] = fun_portion


static func _symbols(at_hi: float, at_nu: float, at_al: float, at_mo: float,
		has_bathed: float, funlack: float) -> Dictionary:
	return {"at_Hi": at_hi, "at_Nu": at_nu, "at_Al": at_al, "at_Mo": at_mo,
		"has_bathed": has_bathed, "funlack": funlack}


static func _as_list(value: Variant) -> Array:
	var result: Array = []
	if value is Array:
		for item: Variant in value:
			result.append(str(item))
	elif value is String and not str(value).is_empty():
		for item: String in str(value).split(" ", false):
			result.append(item)
	return result


static func _last_index(source: Array, item: String) -> int:
	for index: int in range(source.size() - 1, -1, -1):
		if str(source[index]) == item:
			return index
	return -1


# --------------------------------------------------------------------------- #
# Supporting source procedures
# --------------------------------------------------------------------------- #
## z_spare_procs.tcl:5-8 - the search range shrinks when the auto schedule is off.
static func search_range(auto_schedule: bool) -> float:
	var maximum: float = constant("stt_maxsearch_range", 160.0)
	return maximum * 0.05 if not auto_schedule else maximum


## z_spare_procs.tcl:22-26 - the disappointment is clamped to a band.
static func set_disapp(disappointment: float) -> float:
	var maximum: float = constant("stt_disapp_max", 0.2)
	var factor: float = constant("stt_disapp_factor", 0.3)
	var value: float = minf(maximum, disappointment * factor)
	return maxf(maximum * -0.5, value)


## z_spare_procs.tcl:10-20 - the disappointment decays over the stored rates.
static func disappoint(disappointment: float, rates: int) -> Dictionary:
	if rates != 0:
		var decrement: float = disappointment / float(-rates)
		return {"disappointment": disappointment + decrement, "rates": rates - 1,
			"mood": decrement}
	return {"disappointment": 0.0, "rates": 0, "mood": 0.0}


## z_spare_procs.tcl:28-46 - the after taste is renormalised once it sums to one.
static func exec_taste(aftertaste: Array, tastelist: Array) -> Array:
	var result: Array = []
	var total: float = 0.0
	for index: int in range(4):
		var value: float = float(aftertaste[index]) + float(tastelist[index])
		result.append(value)
		total += value
	if total < 1.0:
		return result
	var normalised: Array = []
	for item: float in result:
		normalised.append(item / total)
	return normalised


## z_spare_procs.tcl:48-56 - the taste wish is the distance to the best taste.
static func taste_wish(aftertaste: Array) -> Array:
	var best: float = aftertaste[0]
	for item: float in aftertaste:
		best = maxf(best, item)
	var result: Array = []
	for item: float in aftertaste:
		result.append(best - item)
	return result


## z_spare_procs.tcl:58-61 - the eat judgement mixes taste, civilisation and recency.
static func eat_judge(taste: float, civ_state: float, recent_count: int) -> float:
	return (1.0 - sqrt(civ_state) * (0.8 - 10.0 * taste)) \
		* (1.0 - sqrt(civ_state) * 0.1 * float(recent_count))


## z_spare_main.tcl:902-913 - eating the same food too often lowers the fun loss.
static func eat_variety(recent_food: Array, eat_classes: Array) -> float:
	var value: float = (10.0 - float(recent_food.size())) * 0.04 + 0.1
	for item: String in eat_classes:
		var count: int = recent_food.count(item)
		if count != 0:
			value += (15.0 - float(count)) * 0.01
	return value


## z_spare_main.tcl:914-925 - the same applies to visited places.
static func place_variety(recent_fun: Array, fav_places: Array) -> float:
	var value: float = (10.0 - float(recent_fun.size())) * 0.01 + 0.2
	var places: Array = ["pub", "tht", "dsc", "fit", "bwl"]
	places.append_array(fav_places)
	for item: String in places:
		var count: int = recent_fun.count(item)
		if count != 0:
			value += (15.0 - float(count)) * 0.008
	return value


## z_spare_fun.tcl:465 and z_spare_procs.tcl:148 - the path cost metric.
static func path_cost(delta_x: float, delta_y: float, weight: float = 2.0) -> float:
	return absf(delta_x) + absf(delta_y) * weight


## z_spare_fun.tcl:488 - the place judgement combines distance and disappointment.
static func place_judgement(cost: float, max_range: float, disappointment: float) -> float:
	return 1.0 - (1.0 - (cost * cost) / (max_range * max_range)) * (1.0 - disappointment)


## z_spare_fun.tcl:480 - recently visited places raise the dissatisfaction.
static func recent_place_penalty(desire: float, recent_count: int) -> float:
	var value: float = desire * 0.2
	return value + (1.0 - value) * 0.05 * float(recent_count)


## z_spare_main.tcl:759 - the favourite places follow the best skill.
static func fav_places(best_exp: String) -> Array[String]:
	if best_exp.is_empty():
		return []
	var table: Dictionary = constants()
	var raw: Variant = table.get("stt_exp_%s" % best_exp, [])
	var result: Array[String] = []
	if raw is Array:
		for item: Variant in raw:
			result.append(str(item))
	return result
