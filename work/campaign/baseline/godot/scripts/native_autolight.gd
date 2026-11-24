extends RefCounted
## Source-only producer/queue: EXE 5CC163, 5CD520, 5912A0, 5D44F6.
## Caller supplies real outer gates, RNG draws, x87 mode and creation predicate.
## No guessed FOW radius, native tick frequency or material/observer policy.

const FIX_DIG: Script = preload("res://scripts/native_fix_dig.gd")


static func scheduled(tick: int, object_id: int, outer_gates: bool) -> bool:
	return outer_gates and tick > 10 and tick % 4 == 1 and (tick >> 2) % 4 == object_id % 4


static func rand15(state: int) -> Dictionary:
	var next_state: int = (state * 214013 + 2531011) & 0xFFFFFFFF
	return {"state": next_state, "value": (next_state >> 16) & 0x7FFF}


static func candidate(native_xy: Vector2, y_draw: int, x_draw: int,
		sample_bounds: Rect2i, depth_at: Callable,
		rounding_mode: StringName = &"unspecified") -> Dictionary:
	if not native_xy.is_finite() or y_draw < 0 or y_draw > 32767 or x_draw < 0 or x_draw > 32767:
		return {"status": "invalid_input"}
	if not rounding_mode in [&"nearest_even", &"floor", &"ceil", &"truncate"]:
		return {"status": "deferred", "reason": "x87_rounding_mode"}
	var y: float = _f32(_f32(native_xy.y - 0.20000000298023224) - _f32(float(y_draw) / 32768.0))
	var x: float = _f32(native_xy.x + _f32(_f32(float(x_draw) / 32768.0) - 0.5))
	var sample_xy: Vector2i = Vector2i(FIX_DIG._round(_f32(x * 8.0), rounding_mode),
		FIX_DIG._round(_f32(y * 8.0), rounding_mode))
	if not sample_bounds.has_point(sample_xy):
		return {"status": "outside_world", "sample": sample_xy}
	var center: Variant = depth_at.call(sample_xy)
	if not _depth_known(center):
		return {"status": "deferred", "reason": "raw_depth", "sample": sample_xy}
	if int(center) >= 15:
		return {"status": "solid", "sample": sample_xy}
	var maximum: int = int(center)
	for offset: Vector2i in [Vector2i.LEFT, Vector2i.RIGHT, Vector2i.UP, Vector2i.DOWN]:
		var value: Variant = depth_at.call(sample_xy + offset)
		if not _depth_known(value):
			return {"status": "deferred", "reason": "raw_depth", "sample": sample_xy + offset}
		if int(value) < 15:
			maximum = maxi(maximum, int(value))
	return {"status": "candidate", "position": Vector3(x, y, mini(maximum, 14)), "sample": sample_xy}


## Mutates only the supplied native queue snapshot. Dedup ignores Z, strict <10.
static func enqueue(queue: Array[Dictionary], position: Vector3) -> int:
	for index: int in range(queue.size()):
		var previous: Vector3 = queue[index]["position"]
		var distance: float = _f32(_f32(absf(_f32(previous.x-position.x)))
			+ _f32(absf(_f32(previous.y-position.y))))
		if distance < 10.0:
			queue[index]["counter"] = mini(int(queue[index]["counter"]), 10)
			return index
	queue.append({"position": position, "counter": 0})
	return queue.size()-1


## Native consumer passes, not seconds. Caller implements world bounds/margin1,
## world+29 and 590E60, class creation, animation and presentation updates.
## Failed/deferred predicate at counter3 is NOT retried at counter4 or5.
static func advance(queue: Array[Dictionary], consumer_gates: bool, attempt: Callable) -> Array[Dictionary]:
	var events: Array[Dictionary] = []
	if not consumer_gates:
		return events
	var index: int = 0
	while index < queue.size():
		var entry: Dictionary = queue[index]
		entry["counter"] = int(entry["counter"]) + 1
		if int(entry["counter"]) == 3:
			events.append({"position": entry["position"], "result": attempt.call(entry["position"])})
		if int(entry["counter"]) == 6:
			queue.remove_at(index)
		else:
			index += 1
	return events


static func _depth_known(value: Variant) -> bool:
	return value is int and int(value) >= 0 and int(value) <= 255


static func _f32(value: float) -> float:
	return FIX_DIG._f32(value)
