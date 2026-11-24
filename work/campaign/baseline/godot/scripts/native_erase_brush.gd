extends RefCounted
## Native tool-5 footprint: raw cursor, inclusive interpolated samples, no parity.
## EXE 0x567918..0x567C8F. Godot starts a fresh path on each press; the native
## persistent +A0/+A4 counter's external clock has not been established.

var active: bool = false
var previous: Vector3 = Vector3.ZERO


func begin(point: Vector3, bounds: Rect2i) -> Array[Vector2i]:
	active = true
	previous = point
	return update(point, bounds)


func update(point: Vector3, bounds: Rect2i) -> Array[Vector2i]:
	if not active:
		return []
	var result: Array[Vector2i] = between(previous, point, bounds)
	previous = point
	return result


func cancel() -> void:
	active = false


static func between(start: Vector3, end: Vector3, bounds: Rect2i) -> Array[Vector2i]:
	var result: Array[Vector2i] = []
	var seen: Dictionary = {}
	var steps: int = 1 + int((end - start).length())
	for index: int in range(steps + 1):
		var t: float = _f32(float(index) / float(steps))
		var u: float = _f32(1.0 - t)
		var x: int = int(_f32(_f32(start.x * u) + _f32(end.x * t)))
		var y: int = int(_f32(_f32(start.y * u) + _f32(end.y * t)))
		var lower: Vector2i = Vector2i(clampi(x, bounds.position.x, bounds.end.x - 1),
			clampi(y, bounds.position.y, bounds.end.y - 1))
		var upper: Vector2i = Vector2i(clampi(x + 2, bounds.position.x, bounds.end.x - 1),
			clampi(y + 2, bounds.position.y, bounds.end.y - 1))
		for sample_y: int in range(lower.y, upper.y):
			for sample_x: int in range(lower.x, upper.x):
				var sample: Vector2i = Vector2i(sample_x, sample_y)
				if not seen.has(sample):
					seen[sample] = true
					result.append(sample)
	return result


static func _f32(value: float) -> float:
	var packed: PackedFloat32Array = PackedFloat32Array([value])
	return packed[0]
