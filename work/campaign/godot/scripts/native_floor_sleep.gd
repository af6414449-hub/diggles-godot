extends RefCounted
## Fresh emergency branch of sparetime_decide_occup, with no food/hospital/fun
## resources, empty future/history, previous emergency=0, goal_reached=2.
## Full ongoing leisure arbitration and native object registry are not ported.


static func fresh_goal(needs: Dictionary, ill_check: bool = false) -> Dictionary:
	var hp: float = needs["hitpoints"]
	var nu: float = needs["nutrition"]
	var al: float = needs["alertness"]
	var mo: float = needs["mood"]
	for value: float in [hp, nu, al, mo]:
		# Tcl uses lexical lsort. Scientific-notation values need its exact
		# string representation; do not silently replace that with numeric sort.
		if not is_finite(value) or value < 0.0 or value > 1.0 or (value > 0.0 and value < 0.0001):
			return {}
	if hp < 0.97 and ill_check:
		return {}
	var urgent: bool = hp < 0.8 and al < 0.4
	if not urgent and al > mo:
		return {}
	if al > 0.5:
		return {} # Planned leisure is outside this bounded emergency branch.
	return {"base": al, "target": 0.6 if nu < 0.5 and al < 0.5 else 0.98,
		"minimum": al + 0.2 if al < 0.5 and minf(mo, nu) < al + 0.2 else -1.0}


static func reached(goal: Dictionary, alertness: float, fraction: float = 1.0) -> bool:
	return alertness - float(goal["base"]) > (float(goal["target"]) - float(goal["base"])) * fraction
