extends RefCounted
## Composer for the Urwald campaign level.
##
## It overlays the PMP geometry and the L2M material layer of every placed
## template onto the level grid and places the template objects with their
## native flags, then applies the post-processing of the original campaign
## script.
##
## FACT (source: data/Scripts/gameplay/Campaign.tcl, read-only):
##   * line 2   - the level is a 512 x 640 map.
##   * line 12  - the start template `urw_unq_start` is placed at (208, 0).
##   * lines 13-15 - the cave painting contributes its material layer only:
##                  `map_setlayer2 30 23 data/templates/urw_unq_hoehlenmalerei.l2m`.
##   * lines 178-190 - every template of the placement list is stamped with
##                  `sm_mark_temparea`, `call data/templates/<name>.tcl` and
##                  `MapTemplateSet <x> <y>`.
##   * lines 198-203 - every object of class `Wuker` is deleted.
##   * lines 205-209 - a `FogRemover` is created at (239, 14, 15) with
##                  `fog_remove 0 46 22` and `set_undeletable 1`.

const TEMPLATES := preload("res://scripts/diggles_campaign_templates.gd")

const MAP_WIDTH: int = 512
const MAP_HEIGHT: int = 640
const START_TEMPLATE: String = "urw_unq_start"
const START_X: int = 208
const START_Y: int = 0
const CAVE_PAINTING_TEMPLATE: String = "urw_unq_hoehlenmalerei"
const CAVE_PAINTING_X: int = 30
const CAVE_PAINTING_Y: int = 23
const REMOVED_CLASS: String = "Wuker"
const FOG_POSITION: Vector3i = Vector3i(239, 14, 15)
const FOG_RECT: Vector3i = Vector3i(0, 46, 22)


## Compose a full level from the placement list of the generator.
func compose(placements: Array[Dictionary], templates: TEMPLATES) -> Dictionary:
	var size: Vector2i = Vector2i(MAP_WIDTH, MAP_HEIGHT)
	var cells: Dictionary = {}
	var layer2: PackedInt32Array = PackedInt32Array()
	layer2.resize(size.x * size.y)
	var objects: Array[Dictionary] = []
	var stamped: Array[Dictionary] = []

	# Campaign.tcl:12 - the start template carries the player dwarves.
	_stamp(templates, START_TEMPLATE, START_X, START_Y, cells, layer2, size, objects, stamped, true)
	# Campaign.tcl:13-15 - the cave painting contributes the material layer only.
	_stamp(templates, CAVE_PAINTING_TEMPLATE, CAVE_PAINTING_X, CAVE_PAINTING_Y,
			cells, layer2, size, objects, stamped, false)

	for placement: Dictionary in placements:
		_stamp(templates, str(placement["template"]), int(placement["x"]), int(placement["y"]),
				cells, layer2, size, objects, stamped, true)

	# Campaign.tcl:198-203 - every Wuker object is deleted after the build.
	var kept: Array[Dictionary] = []
	var removed: Array[Dictionary] = []
	for object: Dictionary in objects:
		if str(object["class"]) == REMOVED_CLASS:
			removed.append(object)
		else:
			kept.append(object)

	var ordered_cells: Array[Dictionary] = []
	for key: Variant in cells.keys():
		ordered_cells.append(cells[key])
	ordered_cells.sort_custom(func(a: Dictionary, b: Dictionary) -> bool:
		if int(a["y"]) == int(b["y"]):
			return int(a["x"]) < int(b["x"])
		return int(a["y"]) < int(b["y"]))

	return {
		"size": size,
		"cells": ordered_cells,
		"layer2_words": layer2,
		"objects": kept,
		"removed_objects": removed,
		"placements": stamped,
		"fog": {
			"position": FOG_POSITION,
			"rect": FOG_RECT,
			"undeletable": true,
		},
		"removed_classes": [REMOVED_CLASS],
	}


func _stamp(templates: TEMPLATES, template_name: String, origin_x: int, origin_y: int,
		cells: Dictionary, layer2: PackedInt32Array, size: Vector2i,
		objects: Array[Dictionary], stamped: Array[Dictionary], with_geometry: bool) -> void:
	var template: Dictionary = templates.get_template(template_name)
	if template.is_empty():
		stamped.append({"template": template_name, "x": origin_x, "y": origin_y, "resolved": false})
		return
	if with_geometry and template.has("pmp"):
		_stamp_geometry(template, origin_x, origin_y, cells, size)
	if template.has("l2m"):
		_stamp_layer(template, origin_x, origin_y, layer2, size)
	if with_geometry:
		for object: Dictionary in template.get("objects", []):
			objects.append(_place_object(object, template_name, origin_x, origin_y))
	stamped.append({
		"template": template_name,
		"x": origin_x,
		"y": origin_y,
		"resolved": true,
		"geometry": with_geometry and template.has("pmp"),
		"material": template.has("l2m"),
	})


func _stamp_geometry(template: Dictionary, origin_x: int, origin_y: int,
		cells: Dictionary, size: Vector2i) -> void:
	var pmp: Dictionary = template["pmp"]
	var width: int = int(pmp["width"])
	var height: int = int(pmp["height"])
	var blocks: PackedInt32Array = pmp["blocks"]
	var flags: PackedByteArray = pmp["flags"]
	var attributes: PackedByteArray = pmp["attributes"]
	for row: int in range(height):
		for column: int in range(width):
			if not _has_geometry(flags, width, height, row, column):
				continue
			var index: int = row * width + column
			var cell_x: int = origin_x + column
			var cell_y: int = origin_y + row
			if cell_x < 0 or cell_y < 0 or cell_x >= size.x or cell_y >= size.y:
				continue
			cells[Vector2i(cell_x, cell_y)] = {
				"x": cell_x,
				"y": cell_y,
				"block": blocks[index],
				"flags": flags[index],
				"cell_attribute": attributes[index],
				"template": str(template["name"]),
			}


## The native loader combines four neighbouring flag samples and skips a cell
## whose neighbourhood is empty (Diggles.exe 0x599A92..0x599B3E).
func _has_geometry(flags: PackedByteArray, width: int, height: int, row: int, column: int) -> bool:
	for offset: Vector2i in [Vector2i.ZERO, Vector2i.RIGHT, Vector2i.DOWN, Vector2i.ONE]:
		var sample_x: int = column + offset.x
		var sample_y: int = row + offset.y
		if sample_x >= width or sample_y >= height:
			continue
		if (flags[sample_y * width + sample_x] & 0x7F) != 0:
			return true
	return false


func _stamp_layer(template: Dictionary, origin_x: int, origin_y: int,
		layer2: PackedInt32Array, size: Vector2i) -> void:
	var l2m: Dictionary = template["l2m"]
	var width: int = int(l2m["width"])
	var height: int = int(l2m["height"])
	var words: PackedInt32Array = l2m["words"]
	for row: int in range(height):
		for column: int in range(width):
			var cell_x: int = origin_x + column
			var cell_y: int = origin_y + row
			if cell_x < 0 or cell_y < 0 or cell_x >= size.x or cell_y >= size.y:
				continue
			layer2[cell_y * size.x + cell_x] = words[row * width + column]


func _place_object(source: Dictionary, template_name: String, origin_x: int, origin_y: int) -> Dictionary:
	var flags: Dictionary = source.get("flags", {})
	return {
		"class": str(source["class"]),
		"x": float(source["x"]) + float(origin_x),
		"y": float(source["y"]) + float(origin_y),
		"z": float(source["z"]),
		"rotation": source.get("rotation", []),
		"owner": flags.get("owner", null),
		"physic": flags.get("physic", null),
		"autolight": flags.get("autolight", null),
		"boxed": flags.get("boxed", null),
		"info": source.get("info", {}),
		"template": template_name,
	}
