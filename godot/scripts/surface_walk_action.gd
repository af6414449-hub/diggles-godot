extends "res://scripts/floor_walk_action.gd"
## Explicit host route/timeline adapter over original navigation samples.
## Mode and BDB depth are source rules; BFS ordering/cost are not native Calc1.

const POSE: Script = preload("res://scripts/native_walk_pose.gd")

var samples: Array[Vector2i] = []
var modes: Array[int] = []
var can_climb: bool = true
var previous_mode: int = 2
var final_point: Variant = null
var new_samples_entered: int = 0


## Host embedding of a source XY route in the actual cave depth. Native
## floor_depth's side pose is not a depth target for every intermediate node.
## Wall endpoints retain the source wall_depth; flat floor runs connect them.
static func project_floor_runs(route_positions: Array[Vector3], route_modes: Array[int],
		route_samples: Array[Vector2i], heights: Callable, actor_depth: float, goal_depth: Variant = null) -> bool:
	var cursor: int = 0
	var projected: Dictionary = {}
	while cursor < route_positions.size():
		if route_modes[cursor] != 2:
			cursor += 1
			continue
		var first: int = cursor
		while cursor+1 < route_positions.size() and route_modes[cursor+1] == 2:
			cursor += 1
		var last: int = cursor
		var start_depth: float = actor_depth if first == 0 else route_positions[first-1].z
		var end_depth: float = route_positions[last+1].z if last+1 < route_positions.size() else start_depth
		if last == route_positions.size()-1 and goal_depth != null:
			end_depth = float(goal_depth)
		var cumulative: PackedFloat32Array = PackedFloat32Array([0.0])
		for index: int in range(first+1,last+1):
			cumulative.append(cumulative[-1]+Vector2(route_positions[index].x-route_positions[index-1].x,route_positions[index].y-route_positions[index-1].y).length())
		for index: int in range(first,last+1):
			var fraction: float = float(cumulative[index-first])/float(cumulative[-1]) if cumulative[-1]>0.000001 else 1.0
			var clearance: Variant = POSE.wall_depth(route_samples[index],heights)
			if clearance == null:
				return false
			var waypoint: Vector3 = route_positions[index]
			waypoint.z = maxf(float(clearance),lerpf(start_depth,end_depth,fraction))
			projected[index] = waypoint
		cursor += 1
	for index: int in projected:
		route_positions[index] = projected[index]
	return true


static func plan(start: Vector2i, goal: Vector2i, walkmap: RefCounted, heights: Callable,
		allow_climb: bool, prefer_direct: bool = false) -> Dictionary:
	var start_flags: Variant = walkmap.sample(start)
	var goal_flags: Variant = walkmap.sample(goal)
	if start_flags == null or goal_flags == null:
		return {"status": "unknown"}
	if (int(start_flags) & 1) == 0 or (int(goal_flags) & 1) == 0:
		return {"status": "no_navigation"}
	if (int(start_flags) & 4) != 0 or (int(goal_flags) & 4) != 0:
		return {"status": "unsupported_object_route"}
	if not allow_climb and ((int(start_flags) & 2) == 0 or (int(goal_flags) & 2) == 0):
		return {"status": "climbing_disabled"}
	var route: Array[Vector2i] = []
	var planner: String = "host_cardinal_bfs_over_source_samples"
	# ADAPTER: a short direct route avoids the representative-cell detour,
	# which can walk backward through the same shaft before proceeding.
	if prefer_direct and absi(start.x - goal.x) + absi(start.y - goal.y) <= 64:
		var low: Vector2i = Vector2i(mini(start.x, goal.x), mini(start.y, goal.y)) - Vector2i(16, 16)
		var high: Vector2i = Vector2i(maxi(start.x, goal.x), maxi(start.y, goal.y)) + Vector2i(16, 16)
		route = _sample_route(start, goal, walkmap, allow_climb,
			Rect2i(low, high - low + Vector2i.ONE).intersection(walkmap.sample_bounds))
	if walkmap.has_method("cell_representative"):
		if route.is_empty():
			route = _representative_route(start,goal,walkmap,allow_climb)
			if not route.is_empty():
				planner = "host_bfs_via_source_cell_representatives"
	if route.is_empty():
		route = _sample_route(start,goal,walkmap,allow_climb,walkmap.sample_bounds)
	if route.is_empty():
		return {"status":"no_supported_route"}
	return _route_result(route, walkmap, heights, planner)


## One BFS reaches the nearest usable work stance; the chapter no longer
## rebuilds a full route for every individual sample around a dig cell.
static func plan_to_any(start: Vector2i, targets: Dictionary, walkmap: RefCounted,
		heights: Callable, permitted: Rect2i) -> Dictionary:
	if targets.is_empty():
		return {"status": "no_supported_route"}
	var first: Variant = walkmap.sample(start)
	if first == null or (int(first) & 5) != 1:
		return {"status": "no_navigation"}
	var queue: Array[Vector2i] = [start]
	var parents: Dictionary = {start: start}
	var cursor: int = 0
	var goal: Variant = start if targets.has(start) else null
	while cursor < queue.size() and goal == null:
		var point: Vector2i = queue[cursor]
		cursor += 1
		for offset: Vector2i in [Vector2i.RIGHT, Vector2i.UP, Vector2i.LEFT, Vector2i.DOWN]:
			var next: Vector2i = point + offset
			if parents.has(next) or not permitted.has_point(next):
				continue
			var flags: Variant = walkmap.sample(next)
			if flags == null or (int(flags) & 5) != 1:
				continue
			parents[next] = point
			if targets.has(next):
				goal = next
				break
			queue.append(next)
	if goal == null:
		return {"status": "no_supported_route"}
	var chosen: Vector2i = goal
	var route: Array[Vector2i] = [chosen]
	while route[-1] != start:
		route.append(parents[route[-1]])
	route.reverse()
	var result: Dictionary = _route_result(route, walkmap, heights,
		"host_bfs_nearest_reachable_dig_stance")
	result["stance_sample"] = goal
	return result


static func _route_result(route: Array[Vector2i], walkmap: RefCounted,
		heights: Callable, planner: String) -> Dictionary:
	var positions: Array[Vector3] = []
	var route_modes: Array[int] = []
	for index: int in range(route.size()):
		var point: Vector2i = route[index]
		var flags: int = int(walkmap.sample(point))
		var mode_value: int = POSE.mode(flags, false, false)
		var direction_x: int = point.x - route[maxi(0, index - 1)].x
		var depth: Variant = POSE.floor_depth(direction_x) if mode_value == 2 else POSE.wall_depth(point, heights)
		if depth == null:
			return {"status": "unknown", "at_sample": point}
		positions.append(Vector3(float(point.x) * 0.125, -float(point.y) * 0.125, float(depth)))
		route_modes.append(mode_value)
	return {"status": "ok", "samples": route, "positions": positions, "modes": route_modes,
		"planner": planner}


static func _sample_route(start: Vector2i, goal: Vector2i, walkmap: RefCounted,
		allow_climb: bool, permitted: Rect2i) -> Array[Vector2i]:
	var queue: Array[Vector2i] = [start]
	var parents: Dictionary = {start:start}
	var cursor: int = 0
	while cursor<queue.size() and not parents.has(goal):
		var point: Vector2i = queue[cursor]
		cursor += 1
		for offset: Vector2i in [Vector2i.RIGHT,Vector2i.UP,Vector2i.LEFT,Vector2i.DOWN]:
			var next: Vector2i = point+offset
			if parents.has(next) or not permitted.has_point(next):
				continue
			var flags: Variant = walkmap.sample(next)
			if flags==null or (int(flags)&5)!=1 or (not allow_climb and (int(flags)&2)==0):
				continue
			parents[next] = point
			queue.append(next)
	if not parents.has(goal):
		return []
	var result: Array[Vector2i] = [goal]
	while result[-1]!=start:
		result.append(parents[result[-1]])
	result.reverse()
	return result


static func _representative_route(start: Vector2i, goal: Vector2i,
		walkmap: RefCounted, allow_climb: bool) -> Array[Vector2i]:
	# Source cell representatives, host graph/connectivity. Every connecting
	# sample is checked; no rounding of an existing path through solid terrain.
	var first: Vector2i = Vector2i(start.x>>3,start.y>>3)
	var last: Vector2i = Vector2i(goal.x>>3,goal.y>>3)
	if first==last:
		return []
	var first_point: Variant = walkmap.cell_representative(first)
	var last_point: Variant = walkmap.cell_representative(last)
	if not first_point is Vector2i or not last_point is Vector2i:
		return []
	var entry: Array[Vector2i] = _sample_route(start,first_point,walkmap,allow_climb,Rect2i(first*8,Vector2i(8,8)))
	var exit: Array[Vector2i] = _sample_route(last_point,goal,walkmap,allow_climb,Rect2i(last*8,Vector2i(8,8)))
	if entry.is_empty() or exit.is_empty():
		return []
	var queue: Array[Vector2i] = [first]
	var parents: Dictionary = {first:first}
	var links: Dictionary = {}
	var cursor: int = 0
	while cursor<queue.size() and not parents.has(last):
		var cell: Vector2i = queue[cursor]
		cursor += 1
		var from: Vector2i = walkmap.cell_representative(cell)
		for offset: Vector2i in [Vector2i.RIGHT,Vector2i.UP,Vector2i.LEFT,Vector2i.DOWN]:
			var next: Vector2i = cell+offset
			if parents.has(next):
				continue
			var next_point: Variant = walkmap.cell_representative(next)
			if not next_point is Vector2i:
				continue
			if not allow_climb and (int(walkmap.sample(next_point))&2)==0:
				continue
			var window: Rect2i = Rect2i(cell*8,Vector2i(8,8)).merge(Rect2i(next*8,Vector2i(8,8)))
			var link: Array[Vector2i] = _sample_route(from,next_point,walkmap,allow_climb,window)
			if link.is_empty():
				continue
			parents[next] = cell
			links[next] = link
			queue.append(next)
	if not parents.has(last):
		return []
	var cells: Array[Vector2i] = [last]
	while cells[-1]!=first:
		cells.append(parents[cells[-1]])
	cells.reverse()
	var result: Array[Vector2i] = entry
	for index: int in range(1,cells.size()):
		var link: Array[Vector2i] = links[cells[index]]
		for sample_index: int in range(1,link.size()):
			result.append(link[sample_index])
	for index: int in range(1,exit.size()):
		result.append(exit[index])
	return result
