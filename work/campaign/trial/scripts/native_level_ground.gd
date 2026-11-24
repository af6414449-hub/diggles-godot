extends RefCounted
## Walkable ground of the level, one area per height level.
##
## The scene builds its navigation grid from the floor triangles of the main
## level only (game height 14.5, scene Y -14.5). The wild hamsters of the
## upper terrace of the multiplayer level stand at game height 18.5, so
## without this helper they have no ground under them and walk off the ledge
## into the void.
##
## Source: res://models/multi_start_010_terrain.json, the same terrain the
## scene builds its meshes from. The corner math is the one of the scene: the
## BDB depth packing for Z, the PMP row as the height of the cell for Y.
##
## The scene space is used: X to the right, Y the height (up is negative),
## Z the depth of the level. The level key is the game height (14.5, 18.5).
const BDB_DEPTH_SCALE := 2.0
const BDB_DEPTH_OFFSET := -14.0

var _floors: Dictionary = {}
var _columns: Dictionary = {}
var _bounds: Dictionary = {}


## Collect the horizontal surfaces of every height level of the terrain.
func load_terrain(data: Dictionary) -> void:
	_floors.clear()
	_columns.clear()
	_bounds.clear()
	var meshes: Dictionary = data.get("meshes", {})
	for entry: Dictionary in data.get("cells", []):
		var parts: Array = meshes.get(str(int(entry["block"])), [])
		var cell := Vector2i(int(entry["x"]), int(entry["y"]))
		for part: Dictionary in parts:
			var values: Array = part["vertices"]
			var indices: Array = part["indices"]
			for start: int in range(0, indices.size(), 3):
				var corners: Array[Vector3] = []
				for corner: int in range(3):
					var offset: int = int(indices[start + corner]) * 5
					corners.append(Vector3(
						float(values[offset]) + float(cell.x),
						-(float(values[offset + 1]) + float(cell.y)),
						BDB_DEPTH_SCALE * float(values[offset + 2]) + BDB_DEPTH_OFFSET))
				if absf(corners[1].y - corners[0].y) > 0.0001:
					continue
				if absf(corners[2].y - corners[0].y) > 0.0001:
					continue
				var triangle := PackedVector2Array()
				for corner: Vector3 in corners:
					triangle.append(Vector2(corner.x, corner.z))
				if absf((triangle[1] - triangle[0]).cross(triangle[2] - triangle[0])) <= 0.00001:
					continue
				_add_floor(-corners[0].y, cell, triangle)


func _add_floor(level: float, cell: Vector2i, triangle: PackedVector2Array) -> void:
	var key := _level_key(level)
	if not _floors.has(key):
		_floors[key] = {}
		_columns[key] = {}
		_bounds[key] = Rect2()
	var floors: Dictionary = _floors[key]
	if not floors.has(cell):
		floors[cell] = []
	(floors[cell] as Array).append(triangle)
	var columns: Dictionary = _columns[key]
	var minimum := minf(triangle[0].x, minf(triangle[1].x, triangle[2].x))
	var maximum := maxf(triangle[0].x, maxf(triangle[1].x, triangle[2].x))
	for column: int in range(floori(minimum - 0.00001), floori(maximum + 0.00001) + 1):
		if not columns.has(column):
			columns[column] = {}
		(columns[column] as Dictionary)[cell] = true
	var bounds: Rect2 = _bounds[key]
	var minimum_z := minf(triangle[0].y, minf(triangle[1].y, triangle[2].y))
	var maximum_z := maxf(triangle[0].y, maxf(triangle[1].y, triangle[2].y))
	if bounds.size == Vector2.ZERO:
		_bounds[key] = Rect2(minimum, minimum_z, maximum - minimum, maximum_z - minimum_z)
	else:
		var merged := bounds
		merged = merged.expand(Vector2(minimum, minimum_z))
		merged = merged.expand(Vector2(maximum, maximum_z))
		_bounds[key] = merged


func _level_key(level: float) -> float:
	return snappedf(level, 0.01)


## The game heights of the levels the terrain has.
func levels() -> Array:
	var result: Array = []
	for key: float in _floors.keys():
		result.append(key)
	result.sort()
	return result


func has_level(level: float) -> bool:
	return _floors.has(_level_key(level))


## The area of the level on the ground plane.
func level_bounds(level: float) -> Rect2:
	return _bounds.get(_level_key(level), Rect2())


## Is there ground of this level under the point?
##
## The test is the one of the scene for the main floor: the point is inside one
## of the floor triangles of the level.
func floor_at(level: float, point: Vector2) -> bool:
	var key := _level_key(level)
	var floors: Dictionary = _floors.get(key, {})
	if floors.is_empty():
		return false
	var columns: Dictionary = _columns.get(key, {})
	var candidates: Dictionary = columns.get(floori(point.x), {})
	for cell: Vector2i in candidates:
		for triangle: PackedVector2Array in floors.get(cell, []):
			var a: float = (triangle[1] - triangle[0]).cross(point - triangle[0])
			var b: float = (triangle[2] - triangle[1]).cross(point - triangle[1])
			var c: float = (triangle[0] - triangle[2]).cross(point - triangle[2])
			if not (minf(a, minf(b, c)) < -0.00001 and maxf(a, maxf(b, c)) > 0.00001):
				return true
	return false


## The game height of a scene position (the scene counts the height down).
static func level_of(scene_y: float) -> float:
	return snappedf(-scene_y, 0.01)
