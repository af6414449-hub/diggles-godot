extends SceneTree
## Real chapter probe for the source terrain-byte navigation adapter.

const DIG: Script = preload("res://scripts/native_campaign_dig_test.gd")
const WALKMAP: Script = preload("res://scripts/native_campaign_walkmap.gd")
const SURFACE_WALK: Script = preload("res://scripts/surface_walk_action.gd")
const DWARF: Script = preload("res://scripts/native_campaign_dwarf.gd")
const WALK_POSE: Script = preload("res://scripts/native_walk_pose.gd")


class ProbeProfile:
	extends RefCounted
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
		return {"diffuse": Color.WHITE, "secondary": Color.BLACK}


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var chapter: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(
		"res://models/native_campaign_chapter.json"))
	var root := Node3D.new()
	get_root().add_child(root)
	var camera := Camera3D.new()
	root.add_child(camera)
	var hud := CanvasLayer.new()
	get_root().add_child(hud)
	var caption := Label.new()
	hud.add_child(caption)
	var dig: RefCounted = DIG.new()
	var profile := ProbeProfile.new()
	var normals: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(
		"res://models/native_model_material.json"))
	profile.data["normals"] = normals["normal_table"]
	dig.setup(root, camera, profile, chapter["cells"], {}, hud, caption)
	var walkmap: RefCounted = WALKMAP.new()
	walkmap.setup(dig, chapter["cells"])
	var count: int = 0
	var found: Array[Vector2i] = []
	var first: Vector2i = Vector2i(231 * 8, 30 * 8)
	for y: int in range(-8, 17):
		for x: int in range(-8, 17):
			var flag: Variant = walkmap.sample(first + Vector2i(x, y))
			if flag != null and (int(flag) & 1) != 0:
				count += 1
				found.append(first + Vector2i(x, y))
	print("CAMPAIGN_WALKMAP_PROBE_OK nearby_navigable=%d examples=%s" % [count,
		str(found.slice(0, 30))])
	assert(count == 25)
	var start: Vector2i = Vector2i(1852, 244)
	var goal: Vector2i = Vector2i(1884, 244)
	walkmap.set_route_window(start, goal)
	var route: Dictionary = SURFACE_WALK.plan(start, goal, walkmap,
		Callable(walkmap, "surface_height"), true)
	print("CAMPAIGN_WALKMAP_ROUTE status=%s planner=%s count=%d first=%s last=%s" % [
		route.get("status"), route.get("planner"), route.get("positions", []).size(),
		str(route.get("positions", []).slice(0, 3)), str(route.get("positions", []).slice(-3))])
	assert(route.get("status") == "ok")
	assert(route["samples"].size() == 33)
	var shaft_entrance: Vector2i = Vector2i(245 * 8 + 4, 244)
	walkmap.set_route_window(start, shaft_entrance)
	var entrance_route: Dictionary = SURFACE_WALK.plan(start, shaft_entrance, walkmap,
		Callable(walkmap, "surface_height"), true)
	assert(entrance_route.get("status") == "ok")
	for row: int in range(30, 52, 2):
		var count_row: int = 0
		for x: int in range(243 * 8, 248 * 8):
			for y: int in range(row * 8, (row + 2) * 8):
				var flag: Variant = walkmap.sample(Vector2i(x, y))
				if flag != null and (int(flag) & 1) != 0:
					count_row += 1
		print("SHAFT_NAV row=%d count=%d" % [row, count_row])
	var dwarfs: RefCounted = DWARF.new()
	dwarfs.setup(root, camera, dig, profile, caption, chapter["cells"])
	var dwarf := Node3D.new()
	dwarf.name = "ChapterProbeDwarf"
	dwarf.position = Vector3(231.5378, -30.44, 12.78)
	root.add_child(dwarf)
	dwarfs.register_dwarf(dwarf)
	dwarfs.call("_assign_walk", dwarf, Vector2i(235, 30))
	assert(dwarfs.dwarf_walk_actions.has(dwarf))
	for frame: int in range(600):
		if not dwarfs.dwarf_walk_actions.has(dwarf):
			break
		dwarfs.advance(1.0 / 60.0)
		if frame == 60:
			assert(dwarf.position.x - 231.5378 < 1.0)
		assert(absf(dwarf.position.z - 12.78) < 0.05)
	print("CHAPTER_DWARF_WALK x=%.3f y=%.3f z=%.3f active=%s" % [
		dwarf.position.x, dwarf.position.y, dwarf.position.z,
		dwarfs.dwarf_walk_actions.has(dwarf)])
	assert(not dwarfs.dwarf_walk_actions.has(dwarf))
	assert(absf(dwarf.position.z - 12.78) < 0.05)
	assert(absf(dwarf.position.x - 235.5) < 0.2)
	var dig_cell: Vector2i = Vector2i(233, 31)
	for row: int in range(31, 37):
		var candidate: Vector2i = Vector2i(233, row)
		dig.call("_mark_corridor", [candidate] as Array[Vector2i])
		print("CHAPTER_DIG_MARK cell=%s marked=%s can=%s level=%s" % [candidate,
			dig.is_marked(candidate), dig.can_dig(candidate), dig.cell_level(candidate)])
		if dig.is_marked(candidate):
			dig_cell = candidate
			break
	if dig.is_marked(dig_cell):
		dwarfs.call("_assign_dig", dwarf, dig_cell)
		print("CHAPTER_DIG_JOB assigned=%s" % dwarfs.dwarf_dig_jobs.has(dwarf))
		for frame: int in range(900):
			if not dwarfs.dwarf_dig_jobs.has(dwarf):
				break
			dwarfs.advance(1.0 / 60.0)
		print("CHAPTER_DIG_RESULT marked=%s level=%s position=%s" % [
			dig.is_marked(dig_cell), dig.cell_level(dig_cell), dwarf.position])
		assert(not dig.is_marked(dig_cell))
		assert(dig.cell_level(dig_cell) == 11.0)
	for row: int in [32, 33]:
		var next_cell: Vector2i = Vector2i(233, row)
		dig.call("_mark_corridor", [next_cell] as Array[Vector2i])
		print("SHAFT_NEXT_MARK cell=%s marked=%s" % [next_cell, dig.is_marked(next_cell)])
		if not dig.is_marked(next_cell):
			continue
		var planning_started: int = Time.get_ticks_msec()
		dwarfs.call("_assign_dig", dwarf, next_cell)
		print("SHAFT_PLAN_MS cell=%s ms=%d" % [next_cell, Time.get_ticks_msec() - planning_started])
		print("SHAFT_NEXT_JOB cell=%s assigned=%s" % [next_cell, dwarfs.dwarf_dig_jobs.has(dwarf)])
		if row == 33:
			assert(not dwarfs.dwarf_dig_jobs.has(dwarf))
			assert(dig.is_marked(next_cell))
			continue
		assert(dwarfs.dwarf_dig_jobs.has(dwarf))
		for frame: int in range(900):
			if not dwarfs.dwarf_dig_jobs.has(dwarf):
				break
			dwarfs.advance(1.0 / 60.0)
		print("SHAFT_NEXT_RESULT cell=%s marked=%s level=%s position=%s" % [
			next_cell, dig.is_marked(next_cell), dig.cell_level(next_cell), dwarf.position])
		assert(not dig.is_marked(next_cell))
		assert(dig.cell_level(next_cell) == 11.0)
		for nav_row: int in range(30, 35):
			var nav_count: int = 0
			for sx: int in range(232 * 8, 236 * 8):
				for sy: int in range(nav_row * 8, (nav_row + 1) * 8):
					var nav: Variant = walkmap.sample(Vector2i(sx, sy))
					if nav != null and (int(nav) & 1) != 0:
						nav_count += 1
			print("SHAFT_AFTER cell=%s row=%d nav=%d" % [next_cell, nav_row, nav_count])
	for target_cell: Vector2i in [Vector2i(234, 31), Vector2i(234, 32),
			Vector2i(234, 33), Vector2i(233, 33)]:
		if not dig.is_marked(target_cell):
			dig.call("_mark_corridor", [target_cell] as Array[Vector2i])
		if not dig.is_marked(target_cell):
			print("SHAFT_WIDE_NO_MARK cell=%s" % target_cell)
			continue
		dwarfs.call("_assign_dig", dwarf, target_cell)
		print("SHAFT_WIDE_JOB cell=%s assigned=%s" % [target_cell,
			dwarfs.dwarf_dig_jobs.has(dwarf)])
		assert(dwarfs.dwarf_dig_jobs.has(dwarf))
		var pauses: int = 0
		var longest_pause: int = 0
		var slowest_frame_us: int = 0
		var mode_changes: int = 0
		if dwarfs.dwarf_walk_actions.has(dwarf):
			var action: RefCounted = dwarfs.dwarf_walk_actions[dwarf]
			var route_modes: Array = action.modes
			for index: int in range(1, route_modes.size()):
				if route_modes[index] != route_modes[index - 1]:
					mode_changes += 1
			if target_cell == Vector2i(234, 33):
				var depth_range: Vector2 = Vector2(INF, -INF)
				for point: Vector3 in action.path:
					depth_range.x = minf(depth_range.x, point.z)
					depth_range.y = maxf(depth_range.y, point.z)
				print("SHAFT_ROUTE_DEPTH min=%.2f max=%.2f modes=%s" % [
					depth_range.x, depth_range.y, str(route_modes)])
				print("SHAFT_ROUTE_SAMPLES %s" % str(action.samples))
		for frame: int in range(900):
			if not dwarfs.dwarf_dig_jobs.has(dwarf):
				break
			var before: Vector3 = dwarf.position
			var far_wall_depth: float = INF
			if dwarfs.dwarf_walk_actions.has(dwarf):
				var current_walk: RefCounted = dwarfs.dwarf_walk_actions[dwarf]
				if current_walk.path_index < current_walk.samples.size() \
						and current_walk.modes[current_walk.path_index] == 0:
					var source_depth: Variant = WALK_POSE.wall_depth(
						current_walk.samples[current_walk.path_index],
						Callable(walkmap, "surface_height"))
					if source_depth != null:
						far_wall_depth = float(source_depth)
			var tick: int = Time.get_ticks_usec()
			dwarfs.advance(1.0 / 60.0)
			if not is_inf(far_wall_depth):
				assert(dwarf.position.z <= far_wall_depth + 0.01)
			slowest_frame_us = maxi(slowest_frame_us, Time.get_ticks_usec() - tick)
			if dwarfs.dwarf_walk_actions.has(dwarf) and dwarf.position.distance_to(before) < 0.0001:
				pauses += 1
				longest_pause = maxi(longest_pause, pauses)
			else:
				pauses = 0
		print("SHAFT_WIDE_RESULT cell=%s marked=%s level=%s position=%s" % [
			target_cell, dig.is_marked(target_cell), dig.cell_level(target_cell), dwarf.position])
		print("SHAFT_PAUSE cell=%s mode_changes=%d longest_frames=%d slowest_ms=%.2f" % [
			target_cell, mode_changes, longest_pause, float(slowest_frame_us) / 1000.0])
		# A transition clip may change pose, but must not stop travel for a
		# second while the dwarf is crawling through the shaft.
		assert(longest_pause <= 2)
		assert(not dig.is_marked(target_cell))
		assert(dig.cell_level(target_cell) == 11.0)
		if target_cell == Vector2i(234, 32):
			assert(int(dwarfs.dwarf_surface_modes.get(dwarf, 2)) == 0)
	assert(dwarf.position.y <= -31.8)
	assert(dwarf.position.z <= 12.1)
	var unfinished: Vector2i = Vector2i(234, 34)
	dig.call("_mark_corridor", [unfinished] as Array[Vector2i])
	assert(dig.is_marked(unfinished))
	dig.dwarf_cells[unfinished] = true
	dig.queue.erase(unfinished)
	dwarfs.dwarf_dig_jobs[dwarf] = {"point": unfinished, "phase": "approach"}
	dwarfs.call("_cancel_dig", dwarf)
	assert(not dig.dwarf_cells.has(unfinished))
	assert(dig.queue.has(unfinished))
	assert(dig.is_marked(unfinished))
	print("CAMPAIGN_WALKMAP_TEST_OK source_samples=1 speed=1 grounded=1 shaft_route=1 strike=1 cancel=1")
	quit(0)
