class_name NativeLevelGenerator
extends RefCounted
## The level generator of the original game.
##
## The original does not hand out the map of a zone: it generates it. The
## generator is the engine command `lg_start`, and the scripts around it hold
## its rules:
##
##   data/Scripts/init/lginit.tcl:6            lg_addfilterclass - the classes
##                                              a spot of a level may hold
##   data/Scripts/init/lginit.tcl:8-43         LG_set_templategroup - the
##                                              families of templates of a world
##   data/Scripts/init/lginit.tcl:46-51        LG_set_templateprops - game count,
##                                              level count and tunnel weight
##   data/Scripts/init/lgtools.tcl:4-56        the syntax of a group: a pool per
##                                              family, a glob over the templates
##   data/Scripts/init/lgtools.tcl:66-71       the caves and the galleries may
##                                              be used once in a level
##   data/Scripts/classes/story/story.tcl:92-105  the calls that run the
##                                              generator over an area of a zone
##   data/Scripts/classes/story/story.tcl:142-146  the value of the group of
##                                              the caves of a zone
##   data/Scripts/classes/story/story.tcl:199-206  lg_set_templateratio - the share
##                                              of the area the level fills
##   data/Scripts/classes/story/story.tcl:960-987  the number of the objects of
##                                              every resource class in a level
##
## The engine does the rest. The commands of Diggles.exe were recovered with
## Ghidra, and they give the rules this port follows:
##
##   CTclGlobalMethods::LGStart          0x00652bc0 - the run of the generator
##   FUN_00583ac0                       0x00583ac0 - lg_set_area: the area is kept
##                                              8 cells away from the bounds of
##                                              the map and is snapped to the grid
##   FUN_00583650                       0x00583650 - lg_tp_clear: the clearance
##                                              of the generator is 4 cells
##   FUN_005862c0                       0x005862c0 - the next template of the
##                                              chain and its place: 16 tries of
##                                              the random stream
##   FUN_005842c0                       0x005842c0 - the placement of a template:
##                                              the block must be free, the
##                                              clearance around it is taken
##   FUN_00586710                       0x00586710 - the score of a template:
##                                              the smaller, the better
##   FUN_005826d0                       0x005826d0 - the loader of the ent files:
##                                              the connection points of a template
##
## FACT: the families of the templates, their real names and sizes, the values
## of the groups, the quotas of the resources, the classes of the filter, the
## connection points of the templates and the rules of the placements above.
## ADAPTER: the order of the placements. The native walks the open ends of the
## level and scores the templates for every one of them; this port walks the
## same open ends and scores the templates the same way, but it does not
## reproduce the exact walk of the original. UNKNOWN: the stopping rule of the
## native. The scripts name the first value of lg_set_templateratio the
## optimal ratio and the second one the limit; the native uses the first one to
## steer the choice of the templates and the second one as the hard limit. This
## port stops the level when it has reached the optimal share as well.
##
## The inventory of the templates of every world is read from
## res://models/native_level_templates.json, which tools/build_level_template_inventory.py
## writes from the installed game (the real templates, with the size of their
## map, their objects and their connection points).
##
## The random stream is the one of the engine, recovered from Diggles.exe and
## already in the project: scripts/native_campaign_level.gd (DigglesRandom).

const INVENTORY_PATH: String = "res://models/native_level_templates.json"

## story.tcl:101 - the level type of the generated levels.
const LEVEL_TYPE: String = "base"

## The families of a group, in the order of lginit.tcl.
const FAMILY_ORDER: Array[String] = ["Gng", "Gsg", "Hol"]

## The classes a spot of a level may hold (lginit.tcl:6).
const FILTER_CLASSES: Array[String] = [
	"Zwerg", "Wuker", "Troll", "Pilz", "Kohle",
	"Kristallerz", "Golderz", "Eisenerz", "Schatztonne",
]

## The classes with a number of their own in a level (story.tcl:960).
const RESOURCE_CLASSES: Array[String] = [
	"Kohle", "Kristallerz", "Golderz", "Eisenerz", "Pilz",
]

## The step of the grid of the generator: the place of a template is a
## multiple of four on both axes (FUN_005842c0: `(x | y) & 3` must be 0).
const GRID_STEP: int = 4

## The clearance of the generator: lg_tp_clear puts it to four cells
## (FUN_00583650). Every template keeps that many cells free around itself on
## the sides where it has no connection point.
const CLEARANCE: int = 4

## lg_set_area keeps the area eight cells away from the bounds of the map
## (FUN_00583ac0).
const AREA_MARGIN: int = 8

## story.tcl:206 - lg_set_templateratio 0 0.10 1.0: the level fills the tenth
## of the free cells of the area and never more than all of them.
const TARGET_FILL: float = 0.10
const MAX_FILL: float = 1.0

## The native tries sixteen places of the random stream for a template before
## it gives up (FUN_005862c0).
const RANDOM_TRIES: int = 16

## The size the native prefers for a template: |20 - (width + height)|
## (FUN_00586710).
const PREFERRED_SIZE: int = 20

## The sides of a template. The native derives the side of a connection point
## from its place in the block of the template (FUN_005826d0).
const SIDE_TOP: int = 0
const SIDE_RIGHT: int = 1
const SIDE_BOTTOM: int = 2
const SIDE_LEFT: int = 3

var _inventory: Dictionary = {}
var _loaded: bool = false

## The state of one level.
var _rng: RefCounted = null
var _grid: PackedInt32Array = PackedInt32Array()
var _area: Rect2i = Rect2i()
var _free_cells: int = 0
var _filled: int = 0
var _placements: Array[Dictionary] = []
var _open_ends: Array[Dictionary] = []
var _uses: Dictionary = {}


## Reads the inventory of the templates of the original.
func load_inventory() -> bool:
	if _loaded:
		return true
	if not FileAccess.file_exists(INVENTORY_PATH):
		push_error("The inventory of the level templates is missing")
		return false
	var contents: String = FileAccess.get_file_as_string(INVENTORY_PATH)
	var decoded: Variant = JSON.parse_string(contents)
	if not decoded is Dictionary:
		push_error("The inventory of the level templates is invalid")
		return false
	_inventory = decoded as Dictionary
	_loaded = true
	return true


## The data of one zone: the families of its templates, the value of the group
## of its caves and the number of the objects of every resource class.
func zone_data(zone: String) -> Dictionary:
	var zones: Dictionary = _inventory.get("zones", {}) as Dictionary
	return zones.get(zone, {}) as Dictionary


## The names of the templates of a family of a zone.
func family_templates(zone: String, family: String) -> Array:
	var data: Dictionary = zone_data(zone)
	var families: Dictionary = data.get("families", {}) as Dictionary
	var entry: Dictionary = families.get(family, {}) as Dictionary
	return entry.get("templates", []) as Array


## The number of the objects of a class in a level of a zone.
func resource_count(zone: String, object_class: String) -> int:
	var data: Dictionary = zone_data(zone)
	var counts: Dictionary = data.get("object_counts", {}) as Dictionary
	return int(counts.get(object_class, 0))


## The value of the group of the caves of a zone (story.tcl:142-146).
func group_value(zone: String) -> float:
	var data: Dictionary = zone_data(zone)
	return float(data.get("group_value", 0.0))


## Generates the level of one zone.
##
## `area` is the rectangle of the map the level is filled into, in the cells of
## the generator (the resolution of the map is four of them). `map_bounds` is the
## rectangle of the whole map: the native keeps the area eight cells away from
## its bounds (FUN_00583ac0), and an empty rectangle means that the bounds are
## not known. The result is the plan of the level: the placements of the
## templates and the number of the objects of every resource class.
func generate(seed_value: int, zone: String, area: Rect2i, map_bounds: Rect2i = Rect2i()) -> Dictionary:
	if not load_inventory():
		return {}
	var tunnels: Array = family_templates(zone, "Gng")
	if tunnels.is_empty():
		return {}

	_rng = NativeCampaignLevel.DigglesRandom.new(seed_value)
	_area = _clamp_area(area, map_bounds)
	if _area.size.x < GRID_STEP * 4 or _area.size.y < GRID_STEP * 4:
		return {}

	_grid = PackedInt32Array()
	_grid.resize(_area.size.x * _area.size.y)
	_grid.fill(0)
	_free_cells = _area.size.x * _area.size.y
	_filled = 0
	_placements = []
	_open_ends = []
	_uses = {}

	# The chain of the tunnels. It starts with the first template of four
	# cells with two connection points (FUN_005862c0) and grows from its open
	# ends until the level has reached its share of the area.
	_place_start(tunnels)
	_grow_chain(tunnels)

	# The gallery closes a free end of the chain, the cave is dug beside it.
	_place_gallery(family_templates(zone, "Gsg"))
	_place_cave(family_templates(zone, "Hol"))

	# The order of the level: the engine sorts it before it is used
	# (story.tcl:112 lg_sort_level).
	_placements.sort_custom(_level_order)

	var resources: Array[Dictionary] = []
	for object_class: String in RESOURCE_CLASSES:
		var count: int = resource_count(zone, object_class)
		if count > 0:
			resources.append({"class": object_class, "count": count})

	var counts: Dictionary = {"Gng": 0, "Gsg": 0, "Hol": 0}
	for placement: Dictionary in _placements:
		var family: String = String(placement["family"])
		if counts.has(family):
			counts[family] = int(counts[family]) + 1

	return {
		"zone": zone,
		"seed": seed_value,
		"level_type": LEVEL_TYPE,
		"area": [_area.position.x, _area.position.y, _area.size.x, _area.size.y],
		"group_value": group_value(zone),
		"placements": _placements,
		"resources": resources,
		"counts": counts,
		"fill": _filled,
		"free_cells": _free_cells,
	}


## The area of the level, as the native holds it: eight cells away from the
## bounds of the map and on the grid of four (FUN_00583ac0).
func _clamp_area(area: Rect2i, map_bounds: Rect2i) -> Rect2i:
	var x0: int = area.position.x
	var y0: int = area.position.y
	var x1: int = area.end.x
	var y1: int = area.end.y
	if map_bounds.size.x > 0 and map_bounds.size.y > 0:
		x0 = maxi(x0, map_bounds.position.x + AREA_MARGIN)
		y0 = maxi(y0, map_bounds.position.y + AREA_MARGIN)
		x1 = mini(x1, map_bounds.end.x - AREA_MARGIN)
		y1 = mini(y1, map_bounds.end.y - AREA_MARGIN)
	x0 = (x0 + GRID_STEP - 1) & ~(GRID_STEP - 1)
	y0 = (y0 + GRID_STEP - 1) & ~(GRID_STEP - 1)
	x1 = x1 & ~(GRID_STEP - 1)
	y1 = y1 & ~(GRID_STEP - 1)
	return Rect2i(x0, y0, maxi(0, x1 - x0), maxi(0, y1 - y0))


## The first piece of the level: the native takes the first template of four
## cells with two connection points and looks a free place for it, sixteen
## tries of the random stream long (FUN_005862c0).
func _place_start(tunnels: Array) -> void:
	var start: Dictionary = {}
	for template: Dictionary in tunnels:
		var points: Array = template.get("entries", []) as Array
		if int(template["width"]) == 4 and int(template["height"]) == 4 and points.size() == 2:
			start = template
			break
	if start.is_empty():
		return
	var span_x: int = _area.size.x - int(start["width"]) - GRID_STEP
	var span_y: int = _area.size.y - int(start["height"]) - GRID_STEP
	if span_x <= 0 or span_y <= 0:
		return
	for _try: int in range(RANDOM_TRIES):
		var x: int = ((_rng.call("irandom", span_x) / GRID_STEP) * GRID_STEP) + GRID_STEP
		var y: int = ((_rng.call("irandom", span_y) / GRID_STEP) * GRID_STEP) + GRID_STEP
		if _place(start, x, y, "tunnel", "Gng"):
			return


## Grows the chain of the tunnels from the open ends of the level.
##
## Every open end is a connection point of a template that is already there.
## The template that joins it is the one whose connection point of the other
## side falls on the open end.
func _grow_chain(tunnels: Array) -> void:
	while _filled < _target_area():
		var grown: bool = false
		var index: int = 0
		while index < _open_ends.size():
			var end: Dictionary = _open_ends[index]
			var template: Dictionary = _best_template(tunnels, int(end["side"]))
			if not template.is_empty():
				var entry: Dictionary = _entry_for(template, _wanted_side(int(end["side"])))
				var x: int = int(end["x"]) - int(entry["x"])
				var y: int = int(end["y"]) - int(entry["y"])
				if _place(template, x, y, "tunnel", "Gng"):
					grown = true
					break
			index += 1
		if not grown:
			return


## The gallery: the piece that closes an end of the chain.
func _place_gallery(ends: Array) -> void:
	if ends.is_empty():
		return
	var index: int = 0
	while index < _open_ends.size():
		var end: Dictionary = _open_ends[index]
		var wanted: int = _wanted_side(int(end["side"]))
		for template: Dictionary in ends:
			if not _may_use(template):
				continue
			var entry: Dictionary = _entry_for(template, wanted)
			if entry.is_empty():
				continue
			var x: int = int(end["x"]) - int(entry["x"])
			var y: int = int(end["y"]) - int(entry["y"])
			if _place(template, x, y, "gallery_end", "Gsg"):
				return
		index += 1


## The cave: the group of the caves is registered for every world
## (lginit.tcl:8-43), so every level gets one cave of it. The value of the
## group is the share of the level the caves take (story.tcl:142-146).
##
## The native puts the group of the caves into a rectangle of its own
## (FUN_00587480); the port digs the cave beside the chain of the tunnels,
## keeping the clearance of the generator.
func _place_cave(caves: Array) -> void:
	if caves.is_empty():
		return
	var tunnels: Array[Dictionary] = []
	for placement: Dictionary in _placements:
		if String(placement["family"]) == "Gng":
			tunnels.append(placement)
	if tunnels.is_empty():
		return
	for _try: int in range(RANDOM_TRIES):
		var template: Dictionary = _pick(caves)
		if not _may_use(template):
			continue
		var width: int = int(template["width"])
		var height: int = int(template["height"])
		if width <= 0 or height <= 0:
			continue
		if _filled + width * height > int(MAX_FILL * float(_free_cells)):
			continue
		var host: Dictionary = tunnels[int(_rng.call("irandom", tunnels.size()))]
		var host_x: int = int(host["x"]) - _area.position.x
		var host_y: int = int(host["y"]) - _area.position.y
		var host_width: int = int(host["width"])
		var host_height: int = int(host["height"])
		var x: int = host_x
		var y: int = host_y
		if _rng.call("irandom", 2) == 0:
			# above or below the tunnel
			x = host_x + int(_rng.call("irandom", maxi(1, host_width - width + 1)))
			y = host_y - height - CLEARANCE
			if _rng.call("irandom", 2) == 0:
				y = host_y + host_height + CLEARANCE
		else:
			# left or right of the tunnel
			y = host_y + int(_rng.call("irandom", maxi(1, host_height - height + 1)))
			x = host_x - width - CLEARANCE
			if _rng.call("irandom", 2) == 0:
				x = host_x + host_width + CLEARANCE
		if _place(template, x, y, "cave", "Hol"):
			return


## Puts a template into the level.
##
## The block of the template must lie on free cells, and the clearance around
## it - four cells on every side where it has no connection point - is taken,
## so that no other template comes that close (FUN_005842c0). The native tests
## the block only and takes the clearance afterwards; two clearances may lie
## on one another there.
func _place(template: Dictionary, x: int, y: int, role: String, family: String) -> bool:
	var width: int = int(template["width"])
	var height: int = int(template["height"])
	if width <= 0 or height <= 0:
		return false
	# The native puts a template on the grid of four cells: `(x | y) & 3` must
	# be zero (FUN_005842c0).
	if (x | y) & (GRID_STEP - 1) != 0:
		return false
	if x < 0 or y < 0 or x + width > _area.size.x or y + height > _area.size.y:
		return false
	if not _rect_free(x, y, x + width, y + height):
		return false
	var zone: Rect2i = _zone_of(template, x, y)
	_mark_rect(zone.position.x, zone.position.y, zone.end.x, zone.end.y)
	_filled += width * height
	var name: String = String(template["name"])
	_uses[name] = int(_uses.get(name, 0)) + 1
	_placements.append({
		"template": name,
		"x": x + _area.position.x,
		"y": y + _area.position.y,
		"role": role,
		"family": family,
		"width": width,
		"height": height,
	})
	# The connection points of the template become the open ends of the level.
	# An open end that a new point falls on is closed (FUN_00583f60).
	for entry: Dictionary in template.get("entries", []) as Array:
		var ex: int = x + int(entry["x"])
		var ey: int = y + int(entry["y"])
		var closed: bool = false
		var index: int = 0
		while index < _open_ends.size():
			var end: Dictionary = _open_ends[index]
			if int(end["x"]) == ex and int(end["y"]) == ey:
				_open_ends.remove_at(index)
				closed = true
				break
			index += 1
		if not closed:
			_open_ends.append({
				"x": ex,
				"y": ey,
				"side": int(entry["side"]),
			})
	return true


## The cells a template takes: its block and the clearance around it on the
## sides where it has no connection point (FUN_005842c0).
func _zone_of(template: Dictionary, x: int, y: int) -> Rect2i:
	var flags: int = int(template.get("side_flags", 0))
	var x0: int = x
	var y0: int = y
	var x1: int = x + int(template["width"])
	var y1: int = y + int(template["height"])
	if (flags & (1 << SIDE_TOP)) == 0:
		y0 = maxi(0, y - CLEARANCE)
	if (flags & (1 << SIDE_BOTTOM)) == 0:
		y1 = mini(_area.size.y, y1 + CLEARANCE)
	if (flags & (1 << SIDE_LEFT)) == 0:
		x0 = maxi(0, x - CLEARANCE)
	if (flags & (1 << SIDE_RIGHT)) == 0:
		x1 = mini(_area.size.x, x1 + CLEARANCE)
	return Rect2i(x0, y0, x1 - x0, y1 - y0)


## True when the rectangle lies inside the area and none of its cells is taken.
func _rect_free(x0: int, y0: int, x1: int, y1: int) -> bool:
	if x0 < 0 or y0 < 0 or x1 > _area.size.x or y1 > _area.size.y:
		return false
	for row: int in range(y0, y1):
		var base: int = row * _area.size.x
		for column: int in range(x0, x1):
			if _grid[base + column] != 0:
				return false
	return true


## Takes the cells of a rectangle.
func _mark_rect(x0: int, y0: int, x1: int, y1: int) -> void:
	for row: int in range(y0, y1):
		var base: int = row * _area.size.x
		for column: int in range(x0, x1):
			_grid[base + column] = 1


## The template that fits an open end the best.
##
## The native scores every template of the pool for the end and takes the one
## with the smallest score (FUN_00586710).
func _best_template(tunnels: Array, side: int) -> Dictionary:
	var wanted: int = _wanted_side(side)
	var target: float = _target_entries()
	var best: Dictionary = {}
	var best_score: float = INF
	for template: Dictionary in tunnels:
		if not _may_use(template):
			continue
		if _entry_for(template, wanted).is_empty():
			continue
		var width: int = int(template["width"])
		var height: int = int(template["height"])
		if _filled + width * height > int(MAX_FILL * float(_free_cells)):
			continue
		var score: float = _score(template, target)
		if score < best_score:
			best_score = score
			best = template
	return best


## The score of a template: the smaller, the better (FUN_00586710).
##
## The native likes a block of about twenty cells, a number of connection
## points that fits the state of the level, a template that is not used yet
## and it breaks the ties with the random stream.
func _score(template: Dictionary, target: float) -> float:
	var width: int = int(template["width"])
	var height: int = int(template["height"])
	var points: int = (template.get("entries", []) as Array).size()
	var uses: int = int(_uses.get(String(template["name"]), 0))
	var size_term: float = 2.0 * absf(float(PREFERRED_SIZE) - float(width + height))
	var point_term: float = 100.0 * absf(target - float(points))
	var use_term: float = 250.0 * float(uses)
	var jitter: float = float(_rng.call("irandom", 32768)) / 32768.0
	return size_term + point_term + use_term + jitter


## The number of the connection points the native prefers at the moment: it
## wants branching tunnels while the level is empty and dead ends when the
## level is full (FUN_00586710).
func _target_entries() -> float:
	var fill: float = 0.0
	if _free_cells > 0:
		fill = (float(_filled) / float(_free_cells)) / TARGET_FILL
	if fill < 0.3:
		return 3.0
	if fill < 0.6:
		return 2.5
	if fill < 0.8:
		return 2.0
	return 1.0


## The share of the area the level may take (story.tcl:206).
func _target_area() -> int:
	return int(TARGET_FILL * float(_free_cells))


## The side that joins an open end: the other side of the same border.
func _wanted_side(side: int) -> int:
	return (side + 2) & 3


## The connection point of a template on a side.
func _entry_for(template: Dictionary, side: int) -> Dictionary:
	for entry: Dictionary in template.get("entries", []) as Array:
		if int(entry["side"]) == side:
			return entry
	return {}


## True when the template may be used once more: the level count of the
## template and of its group (lginit.tcl:46-51, lgtools.tcl:66-71).
func _may_use(template: Dictionary) -> bool:
	var limit: int = int(template.get("level_count", 0))
	if limit <= 0:
		return true
	return int(_uses.get(String(template["name"]), 0)) < limit


## The order of the level of the engine: by the row, then by the column.
func _level_order(first: Dictionary, second: Dictionary) -> bool:
	if int(first["y"]) != int(second["y"]):
		return int(first["y"]) < int(second["y"])
	return int(first["x"]) < int(second["x"])


## One template of a pool, drawn from the random stream of the engine.
func _pick(pool: Array) -> Dictionary:
	var index: int = int(_rng.call("irandom", pool.size()))
	return pool[index] as Dictionary
