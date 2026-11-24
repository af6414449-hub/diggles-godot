extends RefCounted
## Pure 0x597B20 ranking, not a pathfinder or a strike policy.
## Inputs are native logical XYZ, exclusive world bounds and resolved runtime cells.
## No terrain, marks, worker, scene or task state is changed.

const INVALID_POINT: Vector3 = Vector3(-1.0, -1.0, 1.0)
const INITIAL_COST: float = 10000000.0


static func scan_rect(position: Vector3, world_bounds: Rect2i) -> Rect2i:
	# CVTTSS2SI truncates toward zero, including negative input. 0x597B9F..BF5.
	var center: Vector2i = Vector2i(int(_f32(position.x)), int(_f32(position.y)))
	var low: Vector2i = Vector2i(maxi(world_bounds.position.x + 2, center.x - 16), maxi(world_bounds.position.y + 2, center.y - 17))
	var high: Vector2i = Vector2i(mini(world_bounds.end.x - 2, center.x + 16), mini(world_bounds.end.y - 2, center.y + 15))
	return Rect2i(low, Vector2i(maxi(0, high.x - low.x), maxi(0, high.y - low.y)))


static func select_next(position: Vector3, world_bounds: Rect2i, slot: int, worker_group: int, samples: Dictionary, rank_index: int = 0, require_same_group: bool = false) -> Dictionary:
	# samples[Vector2i] has marks; eligible cells additionally need material_word,
	# next_height (0x5968B0, not current height), and packed groups.
	# rank_index is zero based. Tcl's four-argument form maps max(try, 0) here;
	# its FIVE-argument form ignores try and always uses rank_index=0.
	# Missing source input is UNKNOWN, never silently treated as an unmarked cell.
	if slot < 0 or slot > 7 or world_bounds.size.x < 0 or world_bounds.size.y < 0 or not position.is_finite():
		return {"status": "invalid_input"}
	var rect: Rect2i = scan_rect(position, world_bounds)
	var rank: int = maxi(0, rank_index)
	var shift: int = 4 * slot
	var mask: int = 0xB << shift
	var best: Array[Dictionary] = []
	for y: int in range(rect.position.y, rect.end.y):
		for x: int in range(rect.position.x, rect.end.x):
			var point: Vector2i = Vector2i(x, y)
			if not samples.has(point):
				return _unknown(point, "marks")
			var sample: Dictionary = samples[point]
			if not sample.has("marks"):
				return _unknown(point, "marks")
			if (int(sample["marks"]) & mask) == 0:
				continue
			if not sample.has("material_word"):
				return _unknown(point, "material_word")
			var material: int = int(sample["material_word"]) & 3
			if material == 0 or material == 3:
				continue
			if not sample.has("next_height"):
				return _unknown(point, "next_height")
			var height: int = int(sample["next_height"])
			if height == -1:
				continue
			if not sample.has("groups"):
				return _unknown(point, "groups")
			var group: int = (int(sample["groups"]) >> shift) & 15
			# Native compares the masked candidate with RAW worker+0x250.
			if require_same_group and group != worker_group:
				continue
			var cost: float = _cost(position, point, height, group != worker_group)
			if cost >= INITIAL_COST:
				continue
			# 0x597E4E..E8C: strict replacement; ties keep y-then-x scan order.
			var index: int = 0
			while index < best.size() and float(best[index]["cost"]) <= cost:
				index += 1
			if index > rank:
				continue
			best.insert(index, {"point": Vector3(x, y, clampi(height + 6, 1, 14)), "cost": cost})
			if best.size() > rank + 1:
				best.pop_back()
	if best.size() <= rank:
		# Normal K>=1 epilogue clamps sentinel Z: -1 + 2 -> 1. 0x5980FB..8142.
		return {"status": "no_candidate", "point": INVALID_POINT, "cost": INITIAL_COST, "scan_rect": rect}
	return {"status": "ok", "point": best[rank]["point"], "cost": best[rank]["cost"], "scan_rect": rect}


static func _cost(position: Vector3, point: Vector2i, height: int, foreign_group: bool) -> float:
	# Preserve each ADDSS/SUBSS/MULSS rounding, then sqrt(double(f32))->f32.
	# 0x597D95..0x597E0E; sqrt 0x40B7E6..F7. Do not use Vector3.distance_to.
	var dx: float = _f32(_f32(float(point.x)) - _f32(position.x))
	var dy: float = _f32(_f32(float(point.y)) - _f32(_f32(position.y) - 0.75))
	var dz: float = _f32(_f32(float(height + 4)) - _f32(_f32(position.z) + 6.0))
	var xy: float = _f32(_f32(dx * dx) + _f32(dy * dy))
	var squared: float = _f32(xy + _f32(_f32(dz * dz) * 0.25))
	var cost: float = _f32(sqrt(squared))
	return _f32(cost + 8.0) if foreign_group else cost


static func _f32(value: float) -> float:
	var packed: PackedFloat32Array = PackedFloat32Array([value])
	return packed[0]


static func _unknown(point: Vector2i, field: String) -> Dictionary:
	return {"status": "unknown", "at": point, "missing": field}
