extends RefCounted
## Host task scope over the source work mask (0xB), not native owner-byte policy.
## Four-connected traversal matches get_digedge's component expansion order.

static func component(origin: Vector2i, marks: Dictionary) -> Dictionary:
	if (int(marks.get(origin,0)) & 0xB) == 0:
		return {}
	var queue: Array[Vector2i] = [origin]
	var visited: Dictionary = {origin:true}
	var cursor: int = 0
	while cursor < queue.size():
		var point: Vector2i = queue[cursor]
		cursor += 1
		for offset: Vector2i in [Vector2i.RIGHT,Vector2i.LEFT,Vector2i.DOWN,Vector2i.UP]:
			var next: Vector2i = point + offset
			if not visited.has(next) and (int(marks.get(next,0)) & 0xB) != 0:
				visited[next] = true
				queue.append(next)
	return visited

static func ordered(region: Dictionary, marks: Dictionary, actor: Vector2) -> Array[Vector2i]:
	var result: Array[Vector2i] = []
	for point: Vector2i in region:
		if (int(marks.get(point,0)) & 0xB) != 0:
			result.append(point)
	result.sort_custom(func(a: Vector2i,b: Vector2i) -> bool:
		var da: float = actor.distance_squared_to(Vector2(a))
		var db: float = actor.distance_squared_to(Vector2(b))
		return da < db if da != db else (a.y < b.y or (a.y == b.y and a.x < b.x)))
	return result
