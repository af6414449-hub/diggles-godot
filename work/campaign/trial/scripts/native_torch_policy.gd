extends RefCounted
## EXE 590E60 placement predicate over a supplied snapshot of registered lights.
## The light spatial index is replaced by a full scan of its supplied records.
## Missing world/material/region state is deferred, never treated as empty.

const FIX: Script = preload("res://scripts/native_fix_dig.gd")


static func evaluate(position: Vector3, bounds: Rect2i, minimum_y: Variant,
		material_at: Callable, regions: Variant, lights: Array[Dictionary]) -> Dictionary:
	if not position.is_finite():
		return {"status": "invalid_input"}
	if position.x < float(bounds.position.x)+2.0 or position.x >= float(bounds.end.x)-2.0 \
			or position.y < float(bounds.position.y)+2.0 or position.y >= float(bounds.end.y)-2.0:
		return {"status": "outside_world"}
	if not minimum_y is int:
		return {"status": "deferred", "reason": "minimum_y"}
	if position.y < float(minimum_y):
		return {"status": "below_y_cutoff"}
	var cell: Vector2i = Vector2i(int(FIX._f32(position.x+0.5)), int(FIX._f32(position.y+0.5)))
	var material: Variant = material_at.call(cell)
	if not material is int:
		return {"status": "deferred", "reason": "material", "cell": cell}
	if (int(material) & 3) == 3:
		if not regions is Array:
			return {"status": "deferred", "reason": "region_registry"}
		for region: Dictionary in regions:
			var center: Vector2 = region["position"]
			if not bounds.has_point(Vector2i(floori(center.x),floori(center.y))):
				continue # Native predicate removes expired outside-world entries.
			var dx: float = FIX._f32(center.x-position.x)
			var dy: float = FIX._f32(center.y-position.y)
			var distance: float = FIX._f32(sqrt(FIX._f32(FIX._f32(dx*dx)+FIX._f32(dy*dy))))
			if float(region["radius"]) > distance:
				return {"status": "region_excluded"}
	for light: Dictionary in lights:
		var radius: float = float(light["range"])
		if radius <= 0.0:
			continue
		var center: Vector3 = light["position"]
		var dx: float = FIX._f32(center.x-position.x)
		var dy: float = FIX._f32(center.y-position.y)
		var squared: float = FIX._f32(FIX._f32(dx*dx)+FIX._f32(dy*dy))
		if FIX._f32(radius*radius) <= squared:
			continue
		# Source zeroes candidate copy Z before this stage; no light Z is read.
		var distance: float = FIX._f32(sqrt(squared))
		if FIX._f32(radius+4.0) > distance:
			return {"status": "already_lit"}
	return {"status": "allowed"}
