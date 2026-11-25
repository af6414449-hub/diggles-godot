extends SceneTree
## The height of a dug cave against the tunnel it branches from, on the real
## map of the first chapter.
##
## The probe digs a corridor and a cave with the brush of the original and
## prints the level of every kind of ground: the surface of the chapter, the
## floor of the new tunnel, the floor of the chamber of the cave and the place
## where the frame of the cave stands.
##
## The levels of the original are the levels of the BDB: the surface of the
## chapter is 15, the floor of a corridor is 11, the floor of the chamber of a
## cave is the code of its brush (0, 3, 7 or 11). The world Z of the scene is
## 7.0 + 0.5 * level.
const DIG = preload("res://scripts/native_campaign_dig_test.gd")
const PROFILE = preload("res://scripts/native_campaign_profile.gd")
const STROKE = preload("res://scripts/native_corridor_stroke.gd")
const CHAPTER_PATH: String = "res://models/native_campaign_chapter.json"
const RENDER_DEPTH_SCALE: float = 0.5
const RENDER_DEPTH_OFFSET: float = 7.0
## The corridor and the cave of the demonstration of the scene.
const CORRIDOR_FROM: Vector2 = Vector2(260, 54)
const CORRIDOR_TO: Vector2 = Vector2(275, 54)
const CAVE_BRUSH: int = 1
const CAVE_CURSOR: Vector2i = Vector2i(268, 55)


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var profile: RefCounted = PROFILE.new()
	if not profile.call("load_chapter", CHAPTER_PATH):
		print("CAVE_PROBE_ERROR the profile of the chapter")
		quit(1)
		return
	profile.call("set_lit_excavation", true)
	var chapter: Dictionary = profile.data
	var initial_templates: Dictionary = {}
	for placement: Dictionary in chapter.get("placements", []):
		initial_templates[str(placement.get("template", ""))] = true
	var start_cells: Array = []
	for entry: Dictionary in chapter["cells"]:
		if not bool(entry.get("story", false)):
			start_cells.append(entry)
	profile.call("set_active_templates", initial_templates)
	profile.call("set_active_cells", start_cells)

	var render_root := Node3D.new()
	root.add_child(render_root)
	var camera := Camera3D.new()
	render_root.add_child(camera)
	var hud := CanvasLayer.new()
	root.add_child(hud)
	var label := Label.new()
	hud.add_child(label)
	var dig: RefCounted = DIG.new()
	dig.setup(render_root, camera, profile, start_cells, {}, hud, label)

	# The ground of the chapter before any dig.
	var untouched: float = dig._cell_surface_level(CAVE_CURSOR)
	print("CAVE_PROBE_SURFACE cell=%s level=%.2f world=%.2f" % [str(CAVE_CURSOR),
		untouched, RENDER_DEPTH_SCALE * untouched + RENDER_DEPTH_OFFSET])

	# The tunnel of the demonstration: mark it and dig it.
	var stroke: RefCounted = STROKE.new()
	stroke.begin(CORRIDOR_FROM, Rect2i(0, 0, 511, 639))
	stroke.update(CORRIDOR_TO)
	dig._mark_corridor(stroke.finish())
	print("CAVE_PROBE_CORRIDOR marked=%d" % dig.marked_count())
	dig.start_digging()
	_dig_out(dig, 240)
	var tunnel_cell: Vector2i = _first_corridor_cell(dig)
	print("CAVE_PROBE_TUNNEL cell=%s level=%.2f world=%.2f excavated=%d" % [
		str(tunnel_cell), dig._cell_surface_level(tunnel_cell),
		RENDER_DEPTH_SCALE * dig._cell_surface_level(tunnel_cell) + RENDER_DEPTH_OFFSET,
		dig.excavated_cells.size()])

	# The cave of the demonstration: the brush of the original decides the depth
	# of every cell of the chamber.
	dig._mark_cave(CAVE_BRUSH, CAVE_CURSOR)
	print("CAVE_PROBE_CAVE_MARKED cells=%d groups=%d status=%s" % [
		dig.marked_cave_cells.size(), dig.cave_groups.size(), label.text])
	_report_wish(dig)
	dig.start_digging()
	_dig_out(dig, 600)
	print("CAVE_PROBE_CAVE_DUG cells=%d excavated=%d frames=%d" % [
		dig.excavated_cave_cells.size(), dig.excavated_cells.size(), dig.cave_frames.size()])
	_report_levels(dig)
	if not dig.cave_frames.is_empty():
		var frame: Node3D = dig.cave_frames[0]
		var level: float = frame.position.z
		print("CAVE_PROBE_FRAME logical=%.2f world=%.2f name=%s" % [level,
			RENDER_DEPTH_SCALE * level + RENDER_DEPTH_OFFSET, frame.name])
	print("CAVE_PROBE_DONE")
	quit(0)


func _dig_out(dig: RefCounted, steps: int) -> void:
	for step: int in range(steps):
		if dig.queue.is_empty():
			break
		dig.advance(0.25)


func _first_corridor_cell(dig: RefCounted) -> Vector2i:
	for cell: Vector2i in dig.excavated_cells:
		return cell
	return Vector2i(-1, -1)


## The levels that the brush of the original asks for, before the dig.
func _report_wish(dig: RefCounted) -> void:
	var wish: Dictionary = {}
	for cell: Vector2i in dig.marked_cave_cells:
		var nibble: int = int(dig.marked_cave_cells[cell]["nibble"])
		var target: int = 3
		match nibble & 3:
			0: target = 0
			1: target = 3
			2: target = 7
			3: target = 11
		wish[target] = int(wish.get(target, 0)) + 1
	print("CAVE_PROBE_WISH %s" % str(wish))


## The levels that the cells of the chamber really have after the dig.
func _report_levels(dig: RefCounted) -> void:
	var real: Dictionary = {}
	for cell: Vector2i in dig.excavated_cave_cells:
		var level: float = dig._cell_surface_level(cell)
		real[level] = int(real.get(level, 0)) + 1
	print("CAVE_PROBE_REAL %s" % str(real))
	print("CAVE_PROBE_FLOOR %.2f" % dig._cave_floor_level(dig.excavated_cave_cells.keys()))
