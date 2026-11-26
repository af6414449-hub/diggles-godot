extends SceneTree
## The measurement of the heading of the dwarves of the campaign chapter.
##
## The test drives the dwarves of the chapter and records, for every route,
## the rendered movement of the dwarf and the rendered front of its body. The
## two are compared by the angle between them: the scene of the multiplayer
## always turns the body into the movement, so the angle is the measure of
## the divergence of the chapter.
##
## The coordinates of the chapter are the coordinates of the board: the board
## lies in the XY plane, the level of a cell is its depth along Z, and the
## root of the scene packs the depth by 0.5 (native_campaign_first_level.gd:
## RENDER_DEPTH_SCALE). The rendered front is therefore the front of the
## global basis of the dwarf, and the rendered movement is the difference of
## the global positions.

const DWARF: Script = preload("res://scripts/native_campaign_dwarf.gd")
const DIG: Script = preload("res://scripts/native_campaign_dig_test.gd")
const SURFACE_WALK: Script = preload("res://scripts/surface_walk_action.gd")

## The start cell of the test and the cells of the measured routes.
const START_CELL: Vector2i = Vector2i(10, 10)
const STEP: float = 1.0 / 60.0
## The scale of the depth of the board, the same as in the chapter.
const RENDER_DEPTH_SCALE: float = 0.5
## The samples of the real chapter used by the measured surface routes.
const SURFACE_START: Vector2i = Vector2i(1852, 244)
const SURFACE_GOAL: Vector2i = Vector2i(1884, 244)
const SURFACE_SHAFT: Vector2i = Vector2i(245 * 8 + 4, 244)


class FakeProfile:
	extends RefCounted
	## The profile of the terrain of the test map: every cell is earth.
	var data: Dictionary = {"normals": []}

	func cell_material(_cell: Vector2i) -> int:
		return 2
	func ground_file(_cell: Vector2i, _variant: int) -> String:
		return "Gnd_A01.tga"
	func detail_texture(_cell: Vector2i, _part: int) -> String:
		return "50PGray.tga"
	func detail_slot(_detail: String) -> Vector2:
		return Vector2.ZERO
	func terrain_material(_variant: int, _a: bool, _b: bool, _file: String, _c: bool,
			_dir: String, _d: bool) -> Material:
		return StandardMaterial3D.new()
	func terrain_channels(_cell: Vector2i, _local: Vector3, _normal: Array,
			_sky: float) -> Dictionary:
		return {"diffuse": Color.WHITE, "secondary": Color(0.0, 0.0, 0.0, 1.0)}


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var chapter: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(
		"res://models/native_campaign_chapter.json"))
	var cells: Array = chapter.get("cells", [])
	var root := Node3D.new()
	root.name = "CampaignRenderSpace"
	# ADAPTER of the test: the scene of the chapter packs the depth of the
	# board by 0.5 and shifts it by 7 (native_campaign_first_level.gd:276).
	root.scale.z = RENDER_DEPTH_SCALE
	root.position.z = 7.0
	get_root().add_child(root)
	var camera := Camera3D.new()
	camera.name = "ChapterCamera"
	camera.current = true
	camera.fov = 38.0
	camera.near = 0.05
	camera.far = 3000.0
	root.add_child(camera)
	var hud := CanvasLayer.new()
	get_root().add_child(hud)
	var label := Label.new()
	hud.add_child(label)
	var dig: RefCounted = DIG.new()
	var profile := FakeProfile.new()
	dig.setup(root, camera, profile, cells, {}, hud, label)
	# The controller without the navigation of the chapter walks on the board
	# itself; the controller with the navigation walks on the samples of the
	# surface of the original.
	var dwarfs: RefCounted = DWARF.new()
	dwarfs.setup(root, camera, dig, profile, label)
	var surface_dwarfs: RefCounted = DWARF.new()
	surface_dwarfs.setup(root, camera, dig, profile, label, cells)

	var dwarf := Node3D.new()
	dwarf.name = "Zwerg_000"
	var body := MeshInstance3D.new()
	var box := BoxMesh.new()
	box.size = Vector3(0.7, 1.0, 0.6)
	body.mesh = box
	dwarf.add_child(body)
	root.add_child(dwarf)
	dwarfs.register_dwarf(dwarf)

	print("HEADING_MEASURE part=board")
	for entry: Array in [
			["+X", Vector2i(14, 10)],
			["-X", Vector2i(6, 10)],
			["+Y_down", Vector2i(10, 14)],
			["-Y_up", Vector2i(10, 6)],
			["DIAG", Vector2i(13, 7)]]:
		_reset(dwarf)
		dwarfs.call("_assign_walk", dwarf, entry[1])
		_measure(dwarfs, dwarf, String(entry[0]))

	print("HEADING_MEASURE part=platform")
	for entry: Array in [
			["depth_near", Vector3(10.5, -10.5, 13.0)],
			["depth_far", Vector3(10.5, -10.5, 17.0)],
			["depth_diag", Vector3(11.5, -10.5, 13.0)],
			["along_x", Vector3(12.5, -10.5, 15.0)]]:
		_reset(dwarf)
		var path: Array[Vector3] = [dwarf.position, entry[1]]
		dwarfs.call("_start_walk", dwarf, path, true)
		_measure(dwarfs, dwarf, String(entry[0]))

	print("HEADING_MEASURE part=surface")
	for entry: Array in [["surface_x", SURFACE_GOAL], ["surface_shaft", SURFACE_SHAFT]]:
		_reset_surface(dwarf)
		var started: bool = bool(surface_dwarfs.call("_start_surface_walk", dwarf, entry[1]))
		if not started:
			print("HEADING_MEASURE route=%s skipped=1" % String(entry[0]))
			continue
		# ADAPTER of the test: the clip of the transition needs the model of
		# the wall, the fixture of the test walks on the floor only, so the
		# route starts in the mode of its first sample.
		var action: RefCounted = surface_dwarfs.dwarf_walk_actions.get(dwarf)
		if action != null:
			action.previous_mode = int(action.modes[0])
		_measure(surface_dwarfs, dwarf, String(entry[0]))

	print("HEADING_MEASURE part=surface_depth")
	_reset_surface(dwarf)
	var started_depth: bool = bool(surface_dwarfs.call("_start_surface_walk", dwarf, SURFACE_GOAL))
	if started_depth:
		var depth_action: RefCounted = surface_dwarfs.dwarf_walk_actions.get(dwarf)
		if depth_action != null:
			depth_action.previous_mode = int(depth_action.modes[0])
			# The ground of the map has a thickness: the waypoint of the floor
			# lies deeper than the dwarf, the body must turn into the depth.
			if depth_action.path.size() > 1:
				depth_action.path[1].z = 13.0
		_measure(surface_dwarfs, dwarf, "surface_depth")

	print("HEADING_MEASURE part=rule")
	for entry: Array in [
			["board_x", Vector3(1.0, 0.0, 0.0), "board"],
			["board_diag", Vector3(1.0, 1.0, 0.0), "board"],
			["board_down", Vector3(0.0, -1.0, 0.0), "board"],
			["surface_depth", Vector3(0.125, 0.0, -2.0), "surface"],
			["surface_diag", Vector3(0.125, -0.125, -2.0), "surface"],
			["platform_depth", Vector3(0.0, 0.0, -2.0), "platform"],
			["platform_diag", Vector3(1.0, 0.0, -2.0), "platform"]]:
		_measure_rule(dwarfs, dwarf, String(entry[0]), entry[1], String(entry[2]))

	print("HEADING_MEASURE part=roundtrip")
	for angle: float in [0.0, 0.785, 1.571, 2.356, 3.142]:
		dwarfs.call("_set_dwarf_heading", dwarf, angle)
		var stored: float = float(dwarfs.call("_heading_of", dwarf))
		print("HEADING_RULE route=roundtrip heading=%.3f stored=%.3f drift=%.3f" % [
			angle, stored, absf(wrapf(stored - angle, -PI, PI))])

	print("HEADING_MEASURE part=route_depth")
	for entry: Array in [["route_x", SURFACE_GOAL], ["route_shaft", SURFACE_SHAFT]]:
		_measure_route_positions(surface_dwarfs, dwarf, String(entry[0]), entry[1])

	print("HEADING_MEASURE part=deep_route")
	# The shaft of the chapter: the ground line of the map steps down there,
	# so the depth of the route changes. The cells are dug first, the same
	# way the walkmap test digs them.
	dwarf.position = Vector3(231.5378, -30.44, 12.78)
	dwarf.transform.basis = Basis.IDENTITY
	for row: int in range(31, 37):
		var cell := Vector2i(233, row)
		dig.call("_mark_corridor", [cell] as Array[Vector2i])
		if not dig.is_marked(cell):
			continue
		surface_dwarfs.call("_assign_dig", dwarf, cell)
		var frames: int = 0
		while surface_dwarfs.dwarf_dig_jobs.has(dwarf) and frames < 900:
			surface_dwarfs.advance(STEP)
			frames += 1
	_measure_route_positions(surface_dwarfs, dwarf, "route_shaft_dug",
		Vector2i(233 * 8 + 4, 34 * 8 + 4))

	print("CAMPAIGN_DWARF_HEADING_TEST_OK")
	quit(0)


## The depth of the ground along a real route of the chapter: how much of the
## movement of the dwarf is the thickness of the ground and how much is the
## line of the ground.
func _measure_route_positions(surface_dwarfs: RefCounted, dwarf: Node3D, label: String,
		target: Vector2i) -> void:
	var start: Variant = surface_dwarfs.call("_nearest_surface_sample",
		Vector2(dwarf.position.x, -dwarf.position.y), 0.3)
	if not start is Vector2i:
		print("HEADING_ROUTE route=%s skipped=1" % label)
		return
	var walkmap: RefCounted = surface_dwarfs.walkmap
	walkmap.set_route_window(start, target)
	var route: Dictionary = SURFACE_WALK.plan(start, target, walkmap,
		Callable(walkmap, "surface_height"), true, true)
	if route.get("status") != "ok":
		print("HEADING_ROUTE route=%s status=%s" % [label, str(route.get("status"))])
		return
	var positions: Array = route["positions"]
	var worst: float = 0.0
	var sum: float = 0.0
	var count: int = 0
	var depth_low: float = INF
	var depth_high: float = -INF
	for index: int in range(1, positions.size()):
		var step: Vector3 = positions[index] - positions[index - 1]
		depth_low = minf(depth_low, positions[index].z)
		depth_high = maxf(depth_high, positions[index].z)
		if step.length_squared() <= 0.0:
			continue
		# The rendered movement of the chapter: the root packs the depth by 0.5.
		var rendered := Vector3(step.x, step.y, step.z * RENDER_DEPTH_SCALE)
		# The rule of the chapter: the angle from the board plane only.
		var heading: float = float(surface_dwarfs.call("_heading_of_direction",
			Vector2(step.x, step.y)))
		var front := Vector3(sin(heading), 0.0, cos(heading))
		var angle: float = rad_to_deg(acos(clampf(rendered.normalized().dot(front), -1.0, 1.0)))
		sum += angle
		count += 1
		worst = maxf(worst, angle)
	print("HEADING_ROUTE route=%s steps=%d depth=%.1f..%.1f mean_angle=%.1f worst_angle=%.1f" % [
		label, count, depth_low, depth_high, (sum / float(count)) if count > 0 else 0.0, worst])


## The rule of the facing itself: the chapter projects the movement into the
## plane of the body and snaps it to one of four facings, the scene of the
## multiplayer turns the body into the movement of the ground.
func _measure_rule(dwarfs: RefCounted, dwarf: Node3D, label: String, movement: Vector3,
		plane: String) -> void:
	var direction: Vector2 = Vector2.ZERO
	match plane:
		"board":
			direction = Vector2(movement.x, movement.y)
		"surface":
			direction = Vector2(movement.x, movement.y)
		"platform":
			direction = Vector2(movement.x, -movement.z)
	var heading: float = float(dwarfs.call("_heading_of_direction", direction))
	dwarfs.call("_set_dwarf_heading", dwarf, heading)
	var front: Vector3 = dwarf.global_transform.basis.z.normalized()
	# The rendered movement of the chapter: the root packs the depth by 0.5.
	var rendered: Vector3 = Vector3(movement.x, movement.y, movement.z * RENDER_DEPTH_SCALE)
	var angle: float = 0.0
	if rendered.length_squared() > 0.0:
		angle = rad_to_deg(acos(clampf(rendered.normalized().dot(front), -1.0, 1.0)))
	# The reading of the heading of the stored basis: the root packs the
	# depth, so the stored basis must not be read as a plain rotation.
	var stored: float = float(dwarfs.call("_heading_of", dwarf))
	var drift: float = absf(wrapf(stored - heading, -PI, PI))
	print("HEADING_RULE route=%s plane=%s move=%s heading=%.3f front=%s angle=%.1f stored=%.3f drift=%.3f" % [
		label, plane, str(_round3(movement)), heading, str(_round3(front)), angle, stored, drift])


## The dwarf at the start cell, with the front towards the camera: the native
## default of the gnome of the campaign (z_dignwalk.tcl:1055).
func _reset(dwarf: Node3D) -> void:
	dwarf.position = Vector3(float(START_CELL.x) + 0.5, -float(START_CELL.y) - 0.5, 15.0)
	dwarf.transform.basis = Basis.IDENTITY


## The dwarf at the first navigable sample of the real chapter.
func _reset_surface(dwarf: Node3D) -> void:
	dwarf.position = Vector3(float(SURFACE_START.x) * 0.125, -float(SURFACE_START.y) * 0.125, 15.0)
	dwarf.transform.basis = Basis.IDENTITY


## One route: the frames of the walk, the rendered movement of every frame
## and the rendered front of the body at that frame.
func _measure(dwarfs: RefCounted, dwarf: Node3D, label: String) -> void:
	var previous: Vector3 = dwarf.global_position
	var start_position: Vector3 = dwarf.position
	var movement: Vector3 = Vector3.ZERO
	var front: Vector3 = Vector3(0.0, 0.0, 1.0)
	var worst: float = 0.0
	var worst_move: Vector3 = Vector3.ZERO
	var worst_front: Vector3 = Vector3.ZERO
	var sum: float = 0.0
	var samples: int = 0
	var clip: String = "-"
	var frames: int = 0
	var path_size: int = 0
	var path_index: int = 0
	var first_waypoint: Vector3 = Vector3.ZERO
	var active: RefCounted = dwarfs.dwarf_walk_actions.get(dwarf)
	if active != null:
		path_size = active.path.size()
		if path_size > 0:
			first_waypoint = active.path[0]
	while dwarfs.dwarf_walk_actions.has(dwarf) and frames < 3600:
		dwarfs.advance(STEP)
		frames += 1
		var current: Vector3 = dwarf.global_position
		var step: Vector3 = current - previous
		if step.length() > 0.0001:
			previous = current
			var direction: Vector3 = step.normalized()
			var body: Vector3 = dwarf.global_transform.basis.z.normalized()
			var angle: float = rad_to_deg(acos(clampf(direction.dot(body), -1.0, 1.0)))
			movement += direction
			sum += angle
			samples += 1
			if angle > worst:
				worst = angle
				worst_move = direction
				worst_front = body
		var walk: RefCounted = dwarfs.dwarf_walk_actions.get(dwarf)
		if walk != null:
			clip = String(walk.state)
			path_index = walk.path_index
		front = dwarf.global_transform.basis.z.normalized()
	print("HEADING_MEASURE route=%s frames=%d mean_angle=%.1f worst_angle=%.1f worst_move=%s worst_front=%s clip=%s" % [
		label, frames, (sum / float(samples)) if samples > 0 else 0.0, worst,
		str(_round3(worst_move)), str(_round3(worst_front)), clip])
	print("HEADING_DETAIL route=%s start=%s end=%s path=%d index=%d first=%s mean_move=%s" % [
		label, str(_round3(start_position)), str(_round3(dwarf.position)), path_size, path_index,
		str(_round3(first_waypoint)),
		str(_round3(movement.normalized())) if samples > 0 else str(Vector3.ZERO)])


func _round3(value: Vector3) -> Vector3:
	return Vector3(snappedf(value.x, 0.001), snappedf(value.y, 0.001), snappedf(value.z, 0.001))
