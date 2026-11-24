extends RefCounted
## Mutable native cell refs. Meshes and transition metadata stay source-derived.
## Initial imported-cell facts are shared with the tunnel validator, so its
## Hnext/support queries can be refreshed after an actual block replacement.

const CORNER_OFFSETS: Array[Vector2i] = [Vector2i.ZERO, Vector2i.LEFT, Vector2i.UP, -Vector2i.ONE]
const DIG_RULES: Script = preload("res://scripts/native_dig_rules.gd")

var package: Dictionary = {}
var facts: Dictionary = {}
var bounds: Rect2i
var revision: int = 0
var cell_overrides: Dictionary = {}


func load_state(path: String, terrain: Dictionary, initial_facts: Dictionary) -> bool:
	var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(path))
	if not parsed is Dictionary:
		return false
	package = parsed
	if package.get("source_pmp_sha256") != terrain.get("source_pmp_sha256") \
			or package.get("source_bdb_sha256") != terrain.get("source_bdb_sha256"):
		return false
	facts = initial_facts
	bounds = Rect2i(0, 0, int(facts["width"]), int(facts["height"]))
	for id: String in package["blocks"]:
		var metadata: Dictionary = package["blocks"][id]
		if metadata["next"].size() != 4 or metadata["heights"].size() != 4 or not package["meshes"].has(id):
			return false
		for next_ref: Variant in metadata["next"]:
			if int(next_ref) >= 0 and not package["blocks"].has(str(int(next_ref))):
				return false
	return true


func cell(point: Vector2i) -> Dictionary:
	if not bounds.has_point(point):
		return {}
	if cell_overrides.has(point):
		return cell_overrides[point]
	var result: Dictionary = facts["cells"][point.y * bounds.size.x + point.x]
	return result if result["material_low"] != null else {}


func block_ref(point: Vector2i) -> int:
	var entry: Dictionary = cell(point)
	return int(entry["block"]) if not entry.is_empty() else -1


func current_height(point: Vector2i) -> Variant:
	var id: int = block_ref(point)
	if id < 0:
		return null
	return int(package["blocks"][str(id)]["support"])


func next_height(point: Vector2i) -> Variant:
	var maximum: int = -1
	var changed: bool = false
	for corner: int in range(4):
		var id: int = block_ref(point + CORNER_OFFSETS[corner])
		if id < 0:
			return null
		var metadata: Dictionary = package["blocks"][str(id)]
		var next_ref: int = int(metadata["next"][corner])
		if next_ref >= 0 and next_ref != id:
			changed = true
			metadata = package["blocks"][str(next_ref)]
		maximum = maxi(maximum, int(metadata["heights"][corner]))
	return maximum if changed else -1


func surface_depth(position: Vector2) -> Variant:
	# Native 0x4093F0 reads the 8x8 height samples preceding the next-ref fields.
	var origin: Vector2i = Vector2i(floori(position.x), floori(position.y))
	var id: int = block_ref(origin)
	if id < 0:
		return null
	var x: int = clampi(floori((position.x - float(origin.x)) * 8.0), 0, 7)
	var y: int = clampi(floori((position.y - float(origin.y)) * 8.0), 0, 7)
	return int(package["blocks"][str(id)]["surface_samples"][y * 8 + x])


func cell_surface_samples(cell: Vector2i) -> PackedByteArray:
	# Optional bulk accessor: the whole 8x8 surface block of one map cell in a
	# single host call. The native producer reads the same 64 bytes per cell
	# through 0x595E40 before it evaluates the samples of that cell.
	var id: int = block_ref(cell)
	if id < 0:
		return PackedByteArray()
	var samples: Array = package["blocks"][str(id)]["surface_samples"]
	var result: PackedByteArray = PackedByteArray()
	result.resize(64)
	for index: int in range(64):
		result[index] = int(samples[index]) & 0xFF
	return result


func refresh_rules(changed_cells: Array[Vector2i]) -> void:
	var dirty: Dictionary = {}
	for changed: Vector2i in changed_cells:
		for dy: int in range(-1, 2):
			for dx: int in range(-1, 2):
				dirty[changed + Vector2i(dx, dy)] = true
	for point: Vector2i in dirty:
		var entry: Dictionary = cell(point)
		if entry.is_empty():
			continue
		entry["next_height"] = next_height(point)
		var support: Variant = true
		for offset: Vector2i in [Vector2i.DOWN, Vector2i.RIGHT, Vector2i.LEFT, Vector2i(1, 1), Vector2i(-1, 1)]:
			var id: int = block_ref(point + offset)
			if id < 0:
				if support != false:
					support = null
			elif int(package["blocks"][str(id)]["support"]) < 2:
				support = false
		entry["support_ok"] = support


func preview_accepted_step(point: Vector2i, slot: int, marks: int, policy_passed: bool, groups: int = 0) -> Dictionary:
	# Query a private runtime snapshot; shared source metadata/meshes are immutable.
	var model_script: Script = get_script()
	var simulation: RefCounted = model_script.new()
	simulation.package = package
	simulation.facts = facts
	simulation.bounds = bounds
	# Only this 4x4 neighborhood can be written by the four corner changes and
	# refresh_rules. Keep the large world read-only everywhere else in a preview.
	for y: int in range(point.y-2,point.y+2):
		for x: int in range(point.x-2,point.x+2):
			var location: Vector2i = Vector2i(x,y)
			var entry: Dictionary = cell(location)
			if not entry.is_empty():
				simulation.cell_overrides[location] = entry.duplicate()
	return simulation.apply_accepted_step(point, slot, marks, policy_passed, groups)


func apply_accepted_step(point: Vector2i, slot: int, marks: int, policy_passed: bool, groups: int = 0) -> Dictionary:
	# Exact core state branch after the separately evaluated native object policy.
	# EXE 0x596B80; see native-terrain-strike-2026-11-17.md.
	var result: Dictionary = {"accepted": false, "marks": marks, "groups": groups,
		"changes": [], "dirty_cells": [], "invalidations": [], "reason": "bounds"}
	if slot < 0 or slot > 7 or not bounds.grow(-1).has_point(point):
		return result
	if not policy_passed:
		result["marks"] = marks & ~(15 << (slot * 4))
		result["reason"] = "policy"
		return result
	var upcoming: Variant = next_height(point)
	if upcoming == null:
		result["reason"] = "unknown_cells"
		return result
	var target: int = DIG_RULES.target_height((marks >> (slot * 4)) & 15)
	if target > int(upcoming):
		result["marks"] = marks & ~(15 << (slot * 4))
		result["reason"] = "target_reached"
		return result
	var touched: Array[Vector2i] = []
	# Snapshot all choices before committing any reference, in native NW..SE order.
	for corner: int in range(3, -1, -1):
		var location: Vector2i = point + CORNER_OFFSETS[corner]
		var old_ref: int = block_ref(location)
		var candidate: int = int(package["blocks"][str(old_ref)]["next"][corner])
		var replacement: int = old_ref
		if candidate >= 0 and int(package["blocks"][str(candidate)]["heights"][corner]) == int(upcoming):
			replacement = candidate
		result["changes"].append({"cell": location, "before": old_ref, "after": replacement})
		touched.append(location)
	for change: Dictionary in result["changes"]:
		var entry: Dictionary = cell(change["cell"])
		entry["block"] = int(change["after"])
		entry["dirty_flags"] = int(entry.get("dirty_flags", 0)) | 1
	var center: Dictionary = cell(point)
	center["dirty_flags"] = int(center["dirty_flags"]) | 2
	var post_height: int = int(next_height(point))
	var updated_marks: int = marks
	for index: int in range(8):
		if DIG_RULES.target_height((marks >> (index * 4)) & 15) > post_height:
			updated_marks &= ~(15 << (index * 4))
	result["marks"] = updated_marks
	result["accepted"] = true
	result["reason"] = "applied"
	result["height_before_next"] = int(upcoming)
	result["height_after_next"] = post_height
	result["current_height"] = current_height(point)
	result["worker_group_value"] = (groups & 0xFFFFFFFF) >> (slot * 4)
	result["dirty_cells"] = touched
	result["invalidations"] = [
		{"flags": 0x10040, "rect": Rect2i(point * 8 - Vector2i(8, 8), Vector2i(16, 16))},
		{"flags": 0x200, "rect": Rect2i(point * 8 - Vector2i(4, 4), Vector2i(8, 8))}]
	refresh_rules(touched)
	revision += 1
	return result
