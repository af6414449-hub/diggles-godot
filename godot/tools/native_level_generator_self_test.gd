extends SceneTree
## --headless --path godot --script res://tools/native_level_generator_self_test.gd
## Checks the level generator of the original: the inventory of the templates
## against the installed game, the connection points of the templates and the
## plan of a generated level against the rules of the native generator.
const Generator = preload("res://scripts/native_level_generator.gd")

## FUN_005842c0 - the clearance of the generator, four cells.
const CLEARANCE: int = 4

## The sides of a template: top, right, bottom, left.
const TOP: int = 0
const RIGHT: int = 1
const BOTTOM: int = 2
const LEFT: int = 3

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
	var generator: RefCounted = Generator.new()
	_check(generator.call("load_inventory"), "the inventory of the templates loads")

	# --- the inventory against the installed game -----------------------------
	# lginit.tcl:8-43 - the pools of the groups are a glob over the templates.
	var expected_counts: Dictionary = {
		"Urwald": {"Gng": 143, "Gsg": 9, "Hol": 40},
		"Metall": {"Gng": 115, "Gsg": 7, "Hol": 21},
		"Kristall": {"Gng": 129, "Gsg": 15, "Hol": 9},
		"Lava": {"Gng": 123, "Gsg": 21, "Hol": 13},
	}
	for zone: String in expected_counts:
		for family: String in expected_counts[zone]:
			var pool: Array = generator.call("family_templates", zone, family)
			_check(pool.size() == int(expected_counts[zone][family]),
				"the pool of %s.%s holds %d templates" % [zone, family, int(expected_counts[zone][family])])

	# story.tcl:142-146 - the value of the group of the caves of a zone.
	_check(absf(float(generator.call("group_value", "Urwald")) - 0.287) < 0.000001,
		"the value of the caves of Urwald is 0.287")
	_check(absf(float(generator.call("group_value", "Metall")) - 0.185) < 0.000001,
		"the value of the caves of Metall is 0.185")
	_check(absf(float(generator.call("group_value", "Kristall")) - 0.077) < 0.000001,
		"the value of the caves of Kristall is 0.077")
	_check(absf(float(generator.call("group_value", "Lava")) - 0.105) < 0.000001,
		"the value of the caves of Lava is 0.105")

	# story.tcl:960-987 - the number of the objects of every class and zone.
	_check(int(generator.call("resource_count", "Urwald", "Pilz")) == 12,
		"Urwald holds twelve mushrooms")
	_check(int(generator.call("resource_count", "Urwald", "Kohle")) == 0,
		"Urwald holds no coal")
	_check(int(generator.call("resource_count", "Urwald", "Golderz")) == 0,
		"Urwald holds no gold")
	_check(int(generator.call("resource_count", "Metall", "Eisenerz")) == 15,
		"Metall holds fifteen iron")
	_check(int(generator.call("resource_count", "Metall", "Golderz")) == 2,
		"Metall holds two gold")
	_check(int(generator.call("resource_count", "Kristall", "Kristallerz")) == 20,
		"Kristall holds twenty crystal ore")
	_check(int(generator.call("resource_count", "Lava", "Kohle")) == 20,
		"Lava holds twenty coal")

	# lginit.tcl:6 - the classes of the filter.
	var filter_classes: Array = Generator.FILTER_CLASSES
	_check(filter_classes.size() == 9, "the filter has nine classes")
	_check(filter_classes.has("Schatztonne"), "the filter holds the treasure chest")
	_check(filter_classes.has("Kohle") and filter_classes.has("Kristallerz"),
		"the filter holds the ores")

	# --- the connection points of the templates -------------------------------
	# The native reads the ent file of the set of a template (FUN_005826d0): the
	# points of the kind 1 become the connection points of the template and
	# their side follows from their place in the block.
	for zone: String in expected_counts:
		for family: String in expected_counts[zone]:
			var with_points: int = 0
			var on_border: bool = true
			var flags_match: bool = true
			for entry: Dictionary in generator.call("family_templates", zone, family):
				var points: Array = entry.get("entries", []) as Array
				if points.is_empty():
					continue
				with_points += 1
				var width: int = int(entry["width"])
				var height: int = int(entry["height"])
				var flags: int = 0
				for point: Dictionary in points:
					var x: int = int(point["x"])
					var y: int = int(point["y"])
					var side: int = int(point["side"])
					if x != 0 and x != width and y != 0 and y != height:
						on_border = false
					if side == LEFT and x != 0:
						on_border = false
					if side == RIGHT and x != width:
						on_border = false
					if side == TOP and y != 0:
						on_border = false
					if side == BOTTOM and y != height:
						on_border = false
					flags |= 1 << side
				if flags != int(entry.get("side_flags", 0)):
					flags_match = false
			_check(with_points == int(expected_counts[zone][family]),
				"every template of %s.%s holds connection points" % [zone, family])
			_check(on_border, "the connection points of %s.%s lie on the border of the block" % [zone, family])
			_check(flags_match, "the sides of %s.%s match its connection points" % [zone, family])

	# The points of one template of the original: gng_050.ent holds the points
	# of the set of urw_gng_050_a, a block of twenty cells.
	var gng_050: Dictionary = _template_entry(generator, "Urwald", "Gng", "urw_gng_050_a")
	_check(int(gng_050.get("width", 0)) == 20 and int(gng_050.get("height", 0)) == 16,
		"urw_gng_050_a is a block of twenty by sixteen cells")
	var points_050: Array = gng_050.get("entries", []) as Array
	_check(points_050.size() == 2, "urw_gng_050_a holds two connection points")
	if points_050.size() == 2:
		_check(int(points_050[0]["x"]) == 0 and int(points_050[0]["y"]) == 10
			and int(points_050[0]["side"]) == LEFT,
			"the left point of urw_gng_050_a lies on the left border")
		_check(int(points_050[1]["x"]) == 20 and int(points_050[1]["y"]) == 10
			and int(points_050[1]["side"]) == RIGHT,
			"the right point of urw_gng_050_a lies on the right border")

	# lginit.tcl:46-51 and lgtools.tcl:66-71 - the number of the uses of a
	# template in one level.
	_check(int(_template_entry(generator, "Urwald", "Gng", "urw_gng_050_a").get("level_count", 0)) == 1,
		"urw_gng_050_a may be used once in a level")
	_check(int(_template_entry(generator, "Urwald", "Hol", "urw_hol_001_a").get("level_count", 0)) == 1,
		"a cave may be used once in a level")
	_check(int(_template_entry(generator, "Urwald", "Gsg", "urw_gsg_001_a").get("level_count", 0)) == 1,
		"a gallery may be used once in a level")
	_check(int(_template_entry(generator, "Urwald", "Gng", "urw_gng_045_a").get("level_count", 0)) == 0,
		"a tunnel is not limited in a level")

	# --- the plan of a level --------------------------------------------------
	var area := Rect2i(0, 0, 160, 96)
	var plan: Dictionary = generator.call("generate", 12345, "Urwald", area)
	_check(not plan.is_empty(), "the generator returns a plan")
	_check(str(plan.get("zone", "")) == "Urwald", "the plan keeps the zone")
	_check(str(plan.get("level_type", "")) == "base", "the plan keeps the level type")

	# FUN_00583ac0 - the area of the level lies on the grid of four.
	var plan_area: Array = plan.get("area", [])
	_check(plan_area.size() == 4, "the plan keeps the area")
	_check(int(plan_area[0]) % 4 == 0 and int(plan_area[1]) % 4 == 0,
		"the area of the level starts on the grid of four")
	_check(int(plan_area[2]) % 4 == 0 and int(plan_area[3]) % 4 == 0,
		"the area of the level ends on the grid of four")

	var placements: Array = plan.get("placements", [])
	_check(placements.size() > 4, "the level holds placements")

	# The blocks of the templates and their clearance.
	var blocks: Array = []
	var on_grid: bool = true
	var inside: bool = true
	var uses: Dictionary = {}
	for placement: Dictionary in placements:
		var entry: Dictionary = _template_entry(generator, "Urwald",
			str(placement.get("family", "")), str(placement["template"]))
		var width: int = int(entry.get("width", 0))
		var height: int = int(entry.get("height", 0))
		var x: int = int(placement["x"])
		var y: int = int(placement["y"])
		if (x | y) & 3 != 0:
			on_grid = false
		if x < area.position.x or y < area.position.y:
			inside = false
		if x + width > area.end.x or y + height > area.end.y:
			inside = false
		var name: String = str(placement["template"])
		uses[name] = int(uses.get(name, 0)) + 1
		blocks.append({"x": x, "y": y, "w": width, "h": height,
			"flags": int(entry.get("side_flags", 0)), "points": entry.get("entries", [])})
	_check(on_grid, "every template lies on the grid of four cells")
	_check(inside, "every placement lies inside the area")

	# No two templates lie on one another, and no block of a template lies in
	# the clearance of another one (FUN_005842c0).
	var clear: bool = true
	for first in range(blocks.size()):
		for second in range(first + 1, blocks.size()):
			var one: Dictionary = blocks[first]
			var two: Dictionary = blocks[second]
			if _overlaps(one, two):
				clear = false
			if _in_zone(one, two) or _in_zone(two, one):
				clear = false
	_check(clear, "the templates keep the clearance of the generator")

	# The chain of the tunnels: the connection points of the tunnels meet.
	var points: Array = []
	for block: Dictionary in blocks:
		for point: Dictionary in block["points"] as Array:
			points.append({"x": int(block["x"]) + int(point["x"]),
				"y": int(block["y"]) + int(point["y"]), "side": int(point["side"])})
	var joined: int = 0
	var free_ends: int = 0
	for point: Dictionary in points:
		var wanted: int = (int(point["side"]) + 2) & 3
		var twin: bool = false
		for other: Dictionary in points:
			if int(other["side"]) == wanted and int(other["x"]) == int(point["x"]) \
					and int(other["y"]) == int(point["y"]):
				twin = true
				break
		if twin:
			joined += 1
		else:
			free_ends += 1
	_check(joined > 0, "the tunnels of the level meet each other")
	_check(free_ends >= 1, "the level holds a free end")

	# The tunnels form one chain.
	var tunnels: int = 0
	for placement: Dictionary in placements:
		if str(placement.get("role", "")) == "tunnel":
			tunnels += 1
	_check(tunnels >= 2, "the level holds a chain of tunnels")

	# The caves of the level: the group of the caves is registered for every
	# world, so every level gets one cave of it.
	var caves: int = 0
	for placement: Dictionary in placements:
		if str(placement.get("role", "")) == "cave":
			caves += 1
	_check(caves == 1, "the level holds one cave")

	# The number of the uses of a template keeps the level count.
	var limits: bool = true
	for name: String in uses:
		var entry: Dictionary = _template_entry(generator, "Urwald", _family_of(name), name)
		var limit: int = int(entry.get("level_count", 0))
		if limit > 0 and int(uses[name]) > limit:
			limits = false
	_check(limits, "no template is used more often than its level count")

	# story.tcl:206 - the level fills its share of the area.
	var fill: int = int(plan.get("fill", 0))
	var free_cells: int = int(plan.get("free_cells", 0))
	_check(free_cells > 0, "the plan holds the free cells of the area")
	_check(fill <= free_cells, "the level does not fill more than the area")

	# The resources of the plan are the quotas of the zone.
	var resources: Array = plan.get("resources", [])
	_check(resources.size() == 1, "Urwald has one resource class")
	_check(str(resources[0]["class"]) == "Pilz", "the resource of Urwald is the mushroom")
	_check(int(resources[0]["count"]) == 12, "Urwald holds twelve mushrooms")

	# The same seed gives the same level, another seed another one.
	var again: Dictionary = generator.call("generate", 12345, "Urwald", area)
	var other: Dictionary = generator.call("generate", 54321, "Urwald", area)
	_check(_plan_digest(plan) == _plan_digest(again), "the same seed gives the same level")
	_check(_plan_digest(plan) != _plan_digest(other), "another seed gives another level")

	# A bigger area holds more of the level.
	var big: Dictionary = generator.call("generate", 12345, "Urwald", Rect2i(0, 0, 320, 192))
	_check((big.get("placements", []) as Array).size() > placements.size(),
		"a bigger area holds more of the level")

	# Every world of the original generates a level.
	for zone: String in expected_counts:
		var zone_plan: Dictionary = generator.call("generate", 12345, zone, area)
		_check(not zone_plan.is_empty(), "the level of %s is generated" % zone)

	if _failures.is_empty():
		print("NATIVE_LEVEL_GENERATOR_SELF_TEST_OK assertions=%d" % _checks)
	else:
		printerr("NATIVE_LEVEL_GENERATOR_SELF_TEST_FAIL failures=%d" % _failures.size())
	quit(0 if _failures.is_empty() else 1)


## True when two blocks lie on one another.
func _overlaps(first: Dictionary, second: Dictionary) -> bool:
	return int(first["x"]) < int(second["x"]) + int(second["w"]) \
		and int(second["x"]) < int(first["x"]) + int(first["w"]) \
		and int(first["y"]) < int(second["y"]) + int(second["h"]) \
		and int(second["y"]) < int(first["y"]) + int(first["h"])


## True when a block lies in the clearance of another one: the clearance is
## four cells on every side where the template has no connection point.
func _in_zone(block: Dictionary, other: Dictionary) -> bool:
	var zone: Rect2i = _zone_of(other)
	var box := Rect2i(int(block["x"]), int(block["y"]), int(block["w"]), int(block["h"]))
	return zone.intersects(box)


## The cells a template takes: its block and the clearance around it.
func _zone_of(block: Dictionary) -> Rect2i:
	var flags: int = int(block["flags"])
	var x0: int = int(block["x"])
	var y0: int = int(block["y"])
	var x1: int = int(block["x"]) + int(block["w"])
	var y1: int = int(block["y"]) + int(block["h"])
	if (flags & (1 << TOP)) == 0:
		y0 = maxi(0, y0 - CLEARANCE)
	if (flags & (1 << BOTTOM)) == 0:
		y1 += CLEARANCE
	if (flags & (1 << LEFT)) == 0:
		x0 = maxi(0, x0 - CLEARANCE)
	if (flags & (1 << RIGHT)) == 0:
		x1 += CLEARANCE
	return Rect2i(x0, y0, x1 - x0, y1 - y0)


## The family a template belongs to.
func _family_of(name: String) -> String:
	if name.contains("_gng_"):
		return "Gng"
	if name.contains("_gsg_"):
		return "Gsg"
	return "Hol"


func _template_entry(generator: RefCounted, zone: String, family: String, name: String) -> Dictionary:
	for entry: Dictionary in generator.call("family_templates", zone, family):
		if str(entry["name"]) == name:
			return entry
	return {}


## A short digest of a plan, so two plans can be compared.
func _plan_digest(plan: Dictionary) -> String:
	var parts: Array[String] = []
	for placement: Dictionary in plan.get("placements", []):
		parts.append("%s@%d,%d" % [str(placement["template"]), int(placement["x"]), int(placement["y"])])
	return ";".join(parts)
