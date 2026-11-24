extends RefCounted
## 0x635610 wrapper -> 0x594E00, under an explicit x87 rounding mode.
## Query callables read native 1/8-cell samples: flags and BDB height, not Hnext.
## Unknown inputs remain unknown. The native no-surface fallback is preserved.


static func solve(target: Vector3, worker: Vector3, bounds: Rect2i, flags: Callable, heights: Callable, rounding_mode: StringName = &"unspecified") -> Dictionary:
	if not target.is_finite() or not worker.is_finite() or bounds.size.x <= 0 or bounds.size.y <= 0:
		return {"status": "invalid_input"}
	if not rounding_mode in [&"nearest_even", &"floor", &"ceil", &"truncate"]:
		return {"status": "unknown", "missing": "x87_rounding_mode"}
	var search_origin: Vector2i = seed_sample(target, worker, rounding_mode)
	var initial: Variant = flags.call(_clamped_sample(search_origin, bounds))
	if initial == null:
		return _unknown(search_origin, "walk_flags")
	var best: Vector2i = search_origin
	var found: bool = (int(initial) & 1) != 0
	if not found:
		var cursor: Vector2i = search_origin
		var length: int = 1
		var limit: int = 50
		var best_squared: int = 0x7FFFFFFF
		while true:
			# Native square spiral: +X,+Y at length L; -X,-Y at L+1.
			for direction: Vector2i in [Vector2i.RIGHT, Vector2i.DOWN, Vector2i.LEFT, Vector2i.UP]:
				if direction == Vector2i.LEFT:
					length += 1
				for step: int in range(length):
					cursor += direction
					var value: Variant = flags.call(_clamped_sample(cursor, bounds))
					if value == null:
						return _unknown(cursor, "walk_flags")
					if (int(value) & 1) == 0:
						continue
					var delta: Vector2i = cursor - search_origin
					var squared: int = delta.x * delta.x + delta.y * delta.y
					if squared >= best_squared:
						continue
					best_squared = squared
					best = cursor
					found = true
					# float32 sqrt/add, then double +2.1 and truncation.
					var distance: float = _f32(sqrt(_f32(float(squared))))
					limit = mini(limit, int(_f32(distance + distance) + 2.1))
			length += 1
			if length >= limit:
				break
	var floor_found: bool = false
	if found:
		for dy: int in range(8):
			var probe: Vector2i = best + Vector2i(0, dy)
			var value: Variant = flags.call(_clamped_sample(probe, bounds))
			if value == null:
				return _unknown(probe, "walk_flags")
			if (int(value) & 2) != 0:
				best = probe
				floor_found = true
				break
	best.y -= 5
	var height: Variant = heights.call(_clamped_sample(best, bounds))
	if height == null:
		return _unknown(best, "block_height")
	var depth: float = minf(14.5, maxf(_f32(worker.z), float(int(height) + 1)))
	return {"status": "ok", "point": Vector3(float(best.x) * 0.125, float(best.y) * 0.125, depth),
		"seed_sample": search_origin, "result_sample": best, "found_navigation": found,
		"found_floor": floor_found, "rounding_mode": rounding_mode}


static func seed_sample(target: Vector3, worker: Vector3, rounding_mode: StringName) -> Vector2i:
	var dx: float = _f32(_f32(target.x) - _f32(worker.x))
	var dy: float = _f32(_f32(target.y) - _f32(worker.y))
	var distance: float = _f32(sqrt(_f32(_f32(dy * dy) + _f32(dx * dx))))
	var x: float = _f32(worker.x)
	var y: float = _f32(worker.y)
	if distance >= 1.0:
		x = _f32(_f32(_f32(_f32(worker.x) - _f32(target.x)) / distance) + _f32(target.x))
		y = _f32(_f32(_f32(_f32(worker.y) - _f32(target.y)) / distance) + _f32(target.y))
	return Vector2i(_round(_f32(x * 8.0), rounding_mode), _round(_f32(y * 8.0), rounding_mode) + 8)


static func _round(value: float, mode: StringName) -> int:
	match mode:
		&"floor":
			return floori(value)
		&"ceil":
			return ceili(value)
		&"truncate":
			return int(value)
		_:
			var low: int = floori(value)
			var fraction: float = value - float(low)
			if fraction == 0.5:
				return low if (low & 1) == 0 else low + 1
			return low if fraction < 0.5 else low + 1


static func _clamped_sample(sample: Vector2i, bounds: Rect2i) -> Vector2i:
	# Native clamps the CELL, then keeps the original local low three bits.
	var x: int = clampi(sample.x >> 3, bounds.position.x, bounds.end.x - 1)
	var y: int = clampi(sample.y >> 3, bounds.position.y, bounds.end.y - 1)
	return Vector2i(x * 8 + (sample.x & 7), y * 8 + (sample.y & 7))


static func _f32(value: float) -> float:
	return PackedFloat32Array([value])[0]


static func _unknown(sample: Vector2i, field: String) -> Dictionary:
	return {"status": "unknown", "at_sample": sample, "missing": field}
