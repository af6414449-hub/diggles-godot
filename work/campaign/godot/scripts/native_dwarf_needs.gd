extends RefCounted
## Formula/API reference: read-only Minimax utility module. Source Tcl oracle
## corrects trap gating and age units. These are attribute ticks, not frames.


static func mood(needs: Dictionary, sleeping: bool) -> String:
	var hi: float = needs["hitpoints"]
	var nu: float = needs["nutrition"]
	var al: float = needs["alertness"]
	var mo: float = needs["mood"]
	var feeling: String = "good"
	if mo < 0.4 or nu < 0.2 or al < 0.1 or hi < 0.5:
		feeling = "bad"
	elif mo < 0.8 or nu < 0.4 or al < 0.2 or hi < 0.8:
		feeling = "normal"
	var suffix: String = "awake"
	if sleeping:
		suffix = "sleep"
	elif al < 0.3:
		suffix = "tired"
	elif al < 0.6:
		suffix = "dizzy"
	elif al < 0.8:
		suffix = "normal"
	return feeling + "_" + suffix


static func tick(needs: Dictionary, context: Dictionary) -> Dictionary:
	var hi: float = needs["hitpoints"]
	var nu: float = needs["nutrition"]
	var al: float = needs["alertness"]
	var mo: float = needs["mood"]
	var dh: float = 0.0
	var dn: float = 0.0
	var da: float = 0.0
	var dm: float = 0.0
	if nu < 0.2:
		dh = (nu - 0.2) * 0.004
	if al < 0.1:
		dh += (al - 0.1) * 0.002
	if nu > 0.2 and al > 0.1:
		dh = (minf(nu, 0.6) - 0.2) * 0.0006 + (minf(al, 0.5) - 0.1) * 0.0004
	if nu < 0.4:
		dm += (maxf(nu, 0.2) - 0.4) * 0.0006
	if al < 0.4:
		dm += (maxf(al, 0.2) - 0.4) * 0.0003
	var age: float = float(context.get("age_seconds", 1200.0))
	if age > 43200.0:
		dh -= 0.01
	elif age > 39600.0:
		da -= 0.0001
		dn += 0.0001
	if context.get("occupation", "idle") == "work":
		da -= 0.00022
		dn -= 0.00025
		dm -= 0.00012
	else:
		da -= 0.00017
		dn -= 0.000195
		dm -= 0.00004
	dm += float(context.get("disappointment", 0.0))
	if bool(context.get("fun_items", false)):
		dm *= 0.5
	if not bool(context.get("is_human", true)):
		dn *= 0.5
		da *= 0.5
		dm *= 0.5
	var result: Dictionary = needs.duplicate()
	if int(context.get("trap_mode", 0)) == 0:
		result = {"hitpoints": clampf(hi + dh, 0.0, 1.0), "nutrition": clampf(nu + dn, 0.0, 1.0),
			"alertness": clampf(al + da, 0.0, 1.0), "mood": clampf(mo + dm, 0.0, 1.0)}
	return {"needs": result, "common_mood": mood(needs, bool(context.get("sleeping", false)))}


static func shift_priority(needs: Dictionary, future_count: int = 0) -> float:
	return (4.0 - float(needs["nutrition"]) - float(needs["nutrition"]) \
		- float(needs["alertness"]) - float(needs["mood"])) \
		* (2.0 - float(needs["hitpoints"])) + float(future_count) * 0.5


static func assign_ordered_shifts(count: int, current_hours: float) -> Array[Dictionary]:
	var result: Array[Dictionary] = []
	if count <= 1:
		return result # Original leaves an existing single-entry schedule alone.
	var plans: Dictionary = {2: [6], 3: [6, 3], 4: [6, 3, 6], 5: [6, 3, 6, 3],
		6: [4, 4, 2, 4, 4], 7: [4, 4, 2, 4, 4, 2]}
	var gaps: Array = plans.get(count, [4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 4, 4, 2])
	var hour: int = int(current_hours) % 12 + 7
	for index: int in range(count):
		if hour > 11:
			hour -= 12
		result.append({"start": hour, "duration": 6.0})
		hour += int(gaps[index]) if index < gaps.size() else 2
	return result
