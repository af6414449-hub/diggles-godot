extends SceneTree
## ADAPTER: opt-in timing probe of the complete chapter, including the five
## imported dwarves, real profile and excavation meshes. No player window.

const RULES: Script = preload("res://scripts/native_dig_rules.gd")

func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var capture_path: String = ""
	var capture_index: int = args.find("--probe-capture")
	if capture_index >= 0 and capture_index + 1 < args.size():
		capture_path = args[capture_index + 1]
	var chapter: Node3D = load("res://scenes/campaign_first_level.tscn").instantiate()
	get_root().add_child(chapter)
	chapter.set_process(false)
	var dig: RefCounted = chapter.get("dig_test")
	var dwarfs: RefCounted = chapter.get("dwarfs")
	var dwarf: Node3D = dwarfs.dwarf_nodes[-1]
	dwarfs.call("_select_dwarf", dwarf)
	var cells: Array[Vector2i] = []
	for y: int in range(31, 35):
		for x: int in range(257, 260):
			if dig.can_dig(Vector2i(x, y)) \
					and RULES.corridor_indices_allowed(Vector2i(x, y)):
				cells.append(Vector2i(x, y))
	print("RUNTIME_PROBE candidates=%s" % str(cells))
	if cells.is_empty():
		quit(0)
		return
	var first: Vector2i = cells[0]
	dig.call("_mark_corridor", [first] as Array[Vector2i])
	assert(dig.is_marked(first))
	var second: Variant = null
	for cell: Vector2i in cells:
		if (cell - first).length() <= 1.5 and cell != first:
			second = cell
			break
	if second is Vector2i:
		dig.call("_mark_corridor", [second] as Array[Vector2i])
		assert(dig.is_marked(second))
	var begun: int = Time.get_ticks_usec()
	dwarfs.call("_assign_dig", dwarf, first)
	print("RUNTIME_PROBE assignment_ms=%.2f assigned=%s first=%s second=%s" % [
		float(Time.get_ticks_usec() - begun) / 1000.0,
		dwarfs.dwarf_dig_jobs.has(dwarf), first, second])
	var slowest_us: int = 0
	var slow_frames: int = 0
	var captured: bool = false
	for frame: int in range(2400):
		var tick: int = Time.get_ticks_usec()
		dwarfs.advance(1.0 / 60.0)
		dig.advance(1.0 / 60.0)
		var duration: int = Time.get_ticks_usec() - tick
		slowest_us = maxi(slowest_us, duration)
		if duration > 50000:
			slow_frames += 1
			if slow_frames <= 12:
				print("RUNTIME_PROBE slow frame=%d ms=%.2f terrain_revision=%d walking=%s job=%s" % [
					frame, float(duration) / 1000.0, dig.terrain_revision,
					dwarfs.dwarf_walk_actions.has(dwarf), dwarfs.dwarf_dig_jobs.has(dwarf)])
		if not captured and not capture_path.is_empty() and dwarf.position.x > 257.0 \
				and dwarfs.dwarf_dig_jobs.has(dwarf) \
				and str(dwarfs.dwarf_dig_jobs[dwarf]["phase"]) == "work":
			captured = true
			await process_frame
			await process_frame
			var picture: Image = get_root().get_viewport().get_texture().get_image()
			print("RUNTIME_PROBE capture_error=%d dwarf=%s" % [
				picture.save_png(capture_path), str(dwarf.position)])
		if not dwarfs.dwarf_dig_jobs.has(dwarf) and frame > 60:
			break
	print("RUNTIME_PROBE result slowest_ms=%.2f slow_frames=%d first_marked=%s second_marked=%s" % [
		float(slowest_us) / 1000.0, slow_frames, dig.is_marked(first),
		dig.is_marked(second) if second is Vector2i else false])
	quit(0)
