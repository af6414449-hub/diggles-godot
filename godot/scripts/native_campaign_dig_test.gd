extends RefCounted
## The excavation of the campaign: the marking of a tunnel or a cave, the
## native BDB transitions of the blocks, and the dressing of the new space.
##
## The state of the module is split into four independent categories, so that
## the marking of a tunnel, the marking of a cave, the cells that the BDB
## transition really opened and the cells of a finished cave never mix:
##
##   marked_corridor_cells  the unfinished marking of a tunnel
##   marked_cave_cells      the unfinished marking of a cave (brush and group)
##   excavated_cells        the cells that a BDB transition opened
##   excavated_cave_cells   the open cells of a FINISHED cave
##
## The membership of a cave is never derived from `block_overrides`: it is
## stored when the cave is marked (`cave_group_cells`) and confirmed when the
## cave is finished (`excavated_cave_cells`).
##
## The rules of the original game are in `native_dig_rules.gd`,
## `native_corridor_selection.gd` and `native_corridor_stroke.gd`. The cave
## skins are in `native_cave_skin.gd` (the same exports that the battle scene
## uses).

const STROKE = preload("res://scripts/native_corridor_stroke.gd")
const ERASE = preload("res://scripts/native_erase_brush.gd")
const RULES = preload("res://scripts/native_dig_rules.gd")
const CONTOUR = preload("res://scripts/native_corridor_contour.gd")
const GROUND = preload("res://scripts/native_campaign_ground.gd")
const CAVE_SKIN = preload("res://scripts/native_cave_skin.gd")
const BLOCKS_PATH = "res://models/native_campaign_dig_blocks.json"
const CORNERS: Array[Vector2i] = [Vector2i.ZERO, Vector2i.LEFT, Vector2i.UP, -Vector2i.ONE]
const BRUSH_PATH = "res://resources/digging/player_cave_brushes.json"
const STEP: float = 0.025
const TOP: float = 15.0

## ADAPTER: temporary one-per-run support rule. Live supports match original
## urw_gng_* Tcl placements at four-cell-aligned offsets. Campaign.tcl calls
## those templates during chapter creation; this threshold is not native.
const SUPPORT_MIN_RUN: int = 7
## The distance to an original or to a generated frame of wood.
const SUPPORT_MIN_DISTANCE: float = 3.0
## SOURCE: the live trace sees supports, moss and roots rise along Z during
## digging, and supports leave obj_query while a cave is excavated. The trace
## does not establish when those objects were created. Immediate dig_apply
## before/after queries miss delayed object updates.
## The speed of a falling object, in units per second.
const FALL_SPEED: float = 22.0
## The classes of the original that are bound to a surface and disappear with
## it. The list is the list of the work order: moss, grass, roots, vines, the
## wooden wall and the frame of wood.
const ATTACHMENT_CLASSES: Array[String] = [
	"Dummy_Moos", "Dummy_Multi_Moos", "Dummy_Gras", "Dummy_Wurzel",
	"Dummy_Liane", "Dummy_Holzwand", "Dummy_Multi_Holzstuetze",
]

var root: Node3D
var camera: Camera3D
var profile: RefCounted
var status: Label
var toolbar: HBoxContainer
var tool: String = ""
var stroke: RefCounted = STROKE.new()
var eraser: RefCounted = ERASE.new()
var brushes: Array = []
var queue: Array[Vector2i] = []
var next_group: int = 1
var step_clock: float = 0.0
var digging: bool = false
var native_blocks: Dictionary = {}
var native_meshes: Dictionary = {}
var source_blocks: Dictionary = {}
var block_overrides: Dictionary = {}
var newly_open: Dictionary = {}

## The marking of a tunnel: Vector2i -> true.
var marked_corridor_cells: Dictionary = {}
## The marking of a cave: Vector2i -> {"nibble": int, "group": int, "brush": int}.
var marked_cave_cells: Dictionary = {}
## The caves that are being dug: group -> {"brush", "cells", "pending", "chamber_level"}.
var cave_groups: Dictionary = {}
## The cells of every cave, marked or finished: Vector2i -> group.
var cave_group_cells: Dictionary = {}
## The cells that a BDB transition opened: Vector2i -> true.
var excavated_cells: Dictionary = {}
## The open cells of a finished cave: Vector2i -> {"group": int, "brush": int}.
var excavated_cave_cells: Dictionary = {}
## The caves that are finished: {"group", "brush", "skin_key", "center", "chamber_level"}.
var finished_caves: Array[Dictionary] = []

var falling_objects: Dictionary = {}
var processed_objects: Dictionary = {}
var support_sources: Array[Node3D] = []
var original_supports: Array[Vector2] = []
var decorated: Dictionary = {}
var cave_skin_resources: Dictionary = {}
var cave_frames: Array[Node3D] = []
var dragging: bool = false
var image: Image
var texture: ImageTexture
var cut_mesh: MeshInstance3D
var mark_mesh: MeshInstance3D
var cave_mesh: MeshInstance3D
var hover_mesh: MeshInstance3D
var _choosing: bool = false


func setup(render_root: Node3D, view: Camera3D, source_profile: RefCounted,
		initial_cells: Array, padding: Dictionary, hud: CanvasLayer, caption: Label) -> void:
	root = render_root
	camera = view
	profile = source_profile
	status = caption
	var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(BRUSH_PATH))
	if parsed is Dictionary:
		brushes = parsed.get("brushes", [])
	var block_package: Variant = JSON.parse_string(FileAccess.get_file_as_string(BLOCKS_PATH))
	if block_package is Dictionary:
		native_blocks = block_package.get("blocks", {})
		native_meshes = block_package.get("meshes", {})
	for entry: Dictionary in initial_cells:
		source_blocks[Vector2i(int(entry["x"]), int(entry["y"]))] = int(entry["block"])
	image = Image.create(512, 640, false, Image.FORMAT_L8)
	image.fill(Color.BLACK)
	texture = ImageTexture.create_from_image(image)
	for child: Node in root.get_children():
		if child is MeshInstance3D and (child.name.begins_with("CampaignGround_") or child.name.begins_with("CampaignTerrain_")
				or child.name.begins_with("CampaignWalls_")):
			var node := child as MeshInstance3D
			var mesh := node.mesh as ArrayMesh
			if mesh == null:
				continue
			var material := mesh.surface_get_material(0).duplicate() as ShaderMaterial
			material.set_shader_parameter("excavation_mask", texture)
			material.set_shader_parameter("use_excavation_mask", true)
			node.material_override = material
	for child: Node in root.get_children():
		if child is Node3D and child.has_meta("native_class"):
			var native_class: String = str(child.get_meta("native_class"))
			if native_class.begins_with("Dummy_Multi_Holzstuetze"):
				support_sources.append(child as Node3D)
				original_supports.append(Vector2((child as Node3D).position.x,
					-(child as Node3D).position.y))
	cave_skin_resources = CAVE_SKIN.new().load_skins()
	cut_mesh = MeshInstance3D.new()
	cut_mesh.name = "CampaignTestExcavation"
	root.add_child(cut_mesh)
	mark_mesh = MeshInstance3D.new()
	mark_mesh.name = "CampaignDigMarks"
	var preview := StandardMaterial3D.new()
	preview.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
	preview.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA
	preview.depth_draw_mode = BaseMaterial3D.DEPTH_DRAW_DISABLED
	preview.albedo_color = Color(0.22, 0.44, 0.15, 0.38)
	preview.cull_mode = BaseMaterial3D.CULL_DISABLED
	mark_mesh.material_override = preview
	root.add_child(mark_mesh)
	cave_mesh = MeshInstance3D.new()
	cave_mesh.name = "CampaignCaveMarks"
	var cave_material := preview.duplicate() as StandardMaterial3D
	cave_material.albedo_color = Color(0.12, 0.20, 0.48, 0.30)
	cave_mesh.material_override = cave_material
	root.add_child(cave_mesh)
	hover_mesh = MeshInstance3D.new()
	hover_mesh.name = "CampaignDigHover"
	var hover_material := StandardMaterial3D.new()
	hover_material.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
	hover_material.albedo_color = Color(0.42, 0.56, 0.32)
	hover_material.cull_mode = BaseMaterial3D.CULL_DISABLED
	hover_mesh.material_override = hover_material
	root.add_child(hover_mesh)
	toolbar = HBoxContainer.new()
	toolbar.name = "CampaignDigToolbar"
	hud.add_child(toolbar)
	toolbar.set_anchors_preset(Control.PRESET_BOTTOM_LEFT)
	toolbar.offset_left = 164.0
	toolbar.offset_top = -46.0
	toolbar.offset_right = 444.0
	toolbar.offset_bottom = -6.0
	toolbar.add_theme_constant_override("separation", 0)
	var button_group := ButtonGroup.new()
	button_group.allow_unpress = true
	var icons: Array[Array] = [
		["Туннель", "BuddelnG"],
		["Пещера 1", "BuddelnH0"],
		["Пещера 2", "BuddelnH1"],
		["Пещера 3", "BuddelnH2"],
		["Пещера 4", "BuddelnH3"],
		["Стёрка", "BuddelnUndo"],
		["Вскопка", "Spitzhacke"],
	]
	for item: Array in icons:
		var label: String = item[0]
		var button := TextureButton.new()
		button.name = label.replace(" ", "_")
		button.texture_normal = ImageTexture.create_from_image(
			Image.load_from_file(ProjectSettings.globalize_path("res://textures/gui/%s.tga" % item[1])))
		button.texture_pressed = button.texture_normal
		button.texture_hover = button.texture_normal
		button.custom_minimum_size = Vector2(40.0, 40.0)
		button.stretch_mode = TextureButton.STRETCH_KEEP_CENTERED
		button.tooltip_text = label
		button.focus_mode = Control.FOCUS_NONE
		if label == "Вскопка":
			button.pressed.connect(start_digging)
		else:
			button.toggle_mode = true
			button.button_group = button_group
			button.toggled.connect(_choose.bind(label))
		toolbar.add_child(button)


func _choose(pressed: bool, label: String) -> void:
	if _choosing:
		return
	tool = label if pressed else ""
	stroke.cancel()
	eraser.cancel()
	dragging = false
	_choosing = true
	for child: Node in toolbar.get_children():
		if child is TextureButton:
			var button := child as TextureButton
			# The tool of the toolbar and the state of its button are one state:
			# the right mouse button clears the tool, so the button must not
			# stay pressed.
			if not pressed or button.name != tool.replace(" ", "_"):
				button.button_pressed = false
			button.self_modulate = Color(0.72, 1.0, 0.70) \
				if button.name == tool.replace(" ", "_") else Color.WHITE
	_choosing = false
	_draw_marks()
	_update_hover(root.get_viewport().get_mouse_position())


## The number of the marks that wait for the excavation.
func marked_count() -> int:
	return marked_corridor_cells.size() + marked_cave_cells.size()


func can_dig(cell: Vector2i, target: int = 11) -> bool:
	if cell.x <= 1 or cell.y <= 1 or cell.x >= 510 or cell.y >= 638:
		return false
	var material: int = int(profile.call("cell_material", cell))
	if material != 1 and material != 2:
		return false
	var current: int = _block_ref(cell)
	if native_blocks.has(str(current)):
		var heights: Array = native_blocks[str(current)]["heights"]
		# BDB support is heights[0] (checked against the mutable
		# multiplayer export); max(corners) reselects an open border strip.
		if int(heights[0]) <= target:
			return false
	for corner: Vector2i in CORNERS:
		if not native_blocks.has(str(_block_ref(cell + corner))):
			return false
	return true


func _block_ref(cell: Vector2i) -> int:
	return int(block_overrides.get(cell, source_blocks.get(cell, 0)))


## The height of the ground of a cell: the level of its first corner, which is
## the support of the block of the BDB (`heights[0]`, the same value that
## `can_dig()` uses). The map of the campaign is a height field seen from
## above, so the height of a cell is its Z and not its row.
func _cell_level(cell: Vector2i) -> float:
	var block: int = _block_ref(cell)
	if not native_blocks.has(str(block)):
		return -1.0
	var heights: Array = native_blocks[str(block)]["heights"]
	if heights.size() < 4:
		return -1.0
	return float(heights[0])


## The height of the ground in the middle of a cell: the mean of the levels of
## its four corners. A block of the BDB carries the level of every corner, so
## the middle of a cell lies between them.
func _cell_surface_level(cell: Vector2i) -> float:
	var block: int = _block_ref(cell)
	if not native_blocks.has(str(block)):
		return -1.0
	var heights: Array = native_blocks[str(block)]["heights"]
	if heights.size() < 4:
		return -1.0
	var total: float = 0.0
	for value: Variant in heights:
		total += float(value)
	return total / float(heights.size())


func _next_height(point: Vector2i) -> int:
	var maximum: int = -1
	var changed: bool = false
	for corner: int in range(4):
		var old_ref: int = _block_ref(point + CORNERS[corner])
		if not native_blocks.has(str(old_ref)):
			return -1
		var candidate: int = int(native_blocks[str(old_ref)]["next"][corner])
		if candidate >= 0 and candidate != old_ref:
			changed = true
		else:
			candidate = old_ref
		if not native_blocks.has(str(candidate)):
			return -1
		maximum = maxi(maximum, int(native_blocks[str(candidate)]["heights"][corner]))
	return maximum if changed else -1


func _native_strike(point: Vector2i, mark: int) -> bool:
	var upcoming: int = _next_height(point)
	if upcoming < 0 or RULES.target_height(mark) > upcoming:
		return false
	var replacements: Array[Dictionary] = []
	for corner: int in range(3, -1, -1):
		var cell: Vector2i = point + CORNERS[corner]
		var old_ref: int = _block_ref(cell)
		var candidate: int = int(native_blocks[str(old_ref)]["next"][corner])
		if candidate >= 0 and int(native_blocks[str(candidate)]["heights"][corner]) == upcoming:
			replacements.append({"cell": cell, "block": candidate,
				"was_open": int(native_blocks[str(old_ref)]["heights"][0]) <= 11})
	for change: Dictionary in replacements:
		var cell: Vector2i = change["cell"]
		block_overrides[cell] = int(change["block"])
		if not bool(change["was_open"]) and _is_open(cell):
			newly_open[cell] = true
			excavated_cells[cell] = true
		image.set_pixel(cell.x, cell.y, Color.WHITE)
	return not replacements.is_empty()


func start_digging() -> void:
	if marked_count() == 0:
		status.text = "Нет разметки для вскопки"
		return
	digging = true
	status.text = "Вскопка: %d ожидающих клеток" % marked_count()


func _point(screen: Vector2) -> Variant:
	var world_origin := camera.project_ray_origin(screen)
	var origin: Vector3 = root.to_local(world_origin)
	var direction: Vector3 = root.to_local(world_origin + camera.project_ray_normal(screen)) - origin
	var hit: Variant = Plane(Vector3(0, 0, 1), TOP).intersects_ray(origin, direction)
	return Vector2(hit.x, -hit.y) if hit is Vector3 else null


func handle_input(event: InputEvent) -> bool:
	if tool.is_empty():
		return false
	if event is InputEventKey and event.pressed and event.keycode == KEY_ESCAPE:
		_choose(false, tool)
		return true
	if event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_LEFT:
		if toolbar.get_global_rect().has_point(event.position):
			return false
		var point: Variant = _point(event.position)
		if event.pressed:
			if not point is Vector2:
				return true
			dragging = true
			if tool.contains("Туннель"):
				stroke.begin(point, Rect2i(0, 0, 511, 639))
			elif tool.contains("Стёрка"):
				eraser.begin(Vector3(point.x, point.y, TOP), Rect2i(0, 0, 512, 640))
				_erase(point)
		else:
			if dragging and point is Vector2:
				if tool.contains("Туннель"):
					stroke.update(point)
					_mark_corridor(stroke.finish())
				elif tool.contains("Пещера"):
					_mark_cave(int(tool.right(1)), Vector2i(point.floor()))
				elif tool.contains("Стёрка"):
					_erase(point)
			dragging = false
			eraser.cancel()
		return true
	if event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_RIGHT \
			and event.pressed and not toolbar.get_global_rect().has_point(event.position):
		_choose(false, tool)
		return true
	if event is InputEventMouseMotion:
		if not dragging:
			return false
		var point: Variant = _point(event.position)
		if point is Vector2:
			if tool.contains("Туннель"):
				stroke.update(point)
				_draw_marks()
			elif tool.contains("Стёрка"):
				_erase(point)
		return true
	return false


func _mark_corridor(samples: Array[Vector2i]) -> void:
	var accepted: int = 0
	for cell: Vector2i in samples:
		if not RULES.corridor_indices_allowed(cell) or not can_dig(cell) \
				or marked_corridor_cells.has(cell) or marked_cave_cells.has(cell):
			continue
		marked_corridor_cells[cell] = true
		queue.append(cell)
		accepted += 1
	if accepted > 0:
		status.text = "Туннель: %d клеток размечено; нажмите «Вскопка»" % accepted
	_draw_marks()


func _cave_cells(number: int, cursor: Vector2i) -> Array[Vector3i]:
	var result: Array[Vector3i] = []
	if number < 1 or number > brushes.size():
		return result
	var rows: Array = brushes[number - 1].get("rows", [])
	for y: int in range(rows.size()):
		for x: int in range(rows[y].size()):
			var value: int = int(rows[y][x])
			if value != 4:
				result.append(Vector3i(cursor.x + x - 16, value, cursor.y + y - 32))
	return result


func _mark_cave(number: int, cursor: Vector2i) -> void:
	var samples: Array[Vector3i] = _cave_cells(number, cursor)
	if samples.is_empty():
		return
	var pending: Array[Vector3i] = []
	var chamber_level: int = 99
	for sample: Vector3i in samples:
		var cell := Vector2i(sample.x, sample.z)
		var target: int = RULES.target_height(8 | sample.y)
		if marked_corridor_cells.has(cell) or marked_cave_cells.has(cell):
			status.text = "Пещера пересекает незавершённую разметку"
			return
		chamber_level = mini(chamber_level, target)
		if can_dig(cell, target):
			pending.append(sample)
		elif not _already_at_depth(cell, target):
			status.text = "Пещера: здесь нельзя разметить весь контур"
			return
	if pending.is_empty():
		status.text = "Пещера уже выкопана"
		return
	if not _has_valid_cave_base(samples):
		status.text = "Основание пещеры должно полностью лежать на линии туннеля"
		return
	# SOURCE: the cave of the original is cut from a passage: its outline has
	# to touch an open cell or a marked tunnel (the rule of _touches_tunnel).
	if not _touches_tunnel(samples):
		status.text = "Пещера должна касаться туннеля"
		return
	var group: int = next_group
	next_group += 1
	var cells: Array[Vector2i] = []
	var pending_cells: Array[Vector2i] = []
	for sample: Vector3i in samples:
		cells.append(Vector2i(sample.x, sample.z))
	for sample: Vector3i in pending:
		var cell := Vector2i(sample.x, sample.z)
		marked_cave_cells[cell] = {"nibble": 8 | sample.y, "group": group, "brush": number}
		pending_cells.append(cell)
		queue.append(cell)
	for cell: Vector2i in cells:
		cave_group_cells[cell] = group
	cave_groups[group] = {"brush": number, "cells": cells, "pending": pending_cells,
		"chamber_level": chamber_level}
	status.text = "Пещера %d размечена; нажмите «Вскопка»" % number
	_draw_marks()


func _already_at_depth(cell: Vector2i, target: int) -> bool:
	var block: int = _block_ref(cell)
	return native_blocks.has(str(block)) and int(native_blocks[str(block)]["heights"][0]) <= target


func _touches_tunnel(samples: Array[Vector3i]) -> bool:
	# A cave may branch up, down or sideways from a passage. The preview
	# must touch an existing or pending tunnel along its exterior boundary.
	var cave: Dictionary = {}
	for sample: Vector3i in samples:
		cave[Vector2i(sample.x, sample.z)] = true
	for cell: Vector2i in cave:
		if _is_open(cell):
			return true
		for offset: Vector2i in [Vector2i.UP, Vector2i.DOWN, Vector2i.LEFT, Vector2i.RIGHT]:
			var neighbour: Vector2i = cell + offset
			if cave.has(neighbour):
				continue
			if marked_corridor_cells.has(neighbour):
				return true
			if _is_open(neighbour):
				return true
	return false


## A cave is supported by the complete horizontal tunnel row immediately below
## its lowest cells. A single touching mark is not enough: that produced the
## old floating/half-supported cave preview. The same parity gate as the
## native corridor rasterizer keeps the base on a legal tunnel line.
func _has_valid_cave_base(samples: Array[Vector3i]) -> bool:
	if samples.is_empty():
		return false
	var lowest: int = -1
	var columns: Dictionary = {}
	for sample: Vector3i in samples:
		lowest = maxi(lowest, sample.z)
		columns[sample.x] = true
	var base_row: int = lowest + 1
	if columns.is_empty():
		return false
	var min_x: int = int(columns.keys()[0])
	var max_x: int = min_x
	for x: Variant in columns.keys():
		min_x = mini(min_x, int(x))
		max_x = maxi(max_x, int(x))
	# The corridor rasterizer permits cells in the row as a horizontal run;
	# parity is a property of the selected row anchor, not a reason to punch
	# holes through the physical base.
	for x: int in range(min_x, max_x + 1):
		var cell := Vector2i(x, base_row)
		if not marked_corridor_cells.has(cell) and not _is_open(cell):
			return false
	return true


func _is_open(cell: Vector2i) -> bool:
	var block: int = _block_ref(cell)
	return native_blocks.has(str(block)) and int(native_blocks[str(block)]["heights"][0]) <= 11


func _is_marked(cell: Vector2i) -> bool:
	return marked_corridor_cells.has(cell) or marked_cave_cells.has(cell)


## The nibble of a marked cell: a tunnel is always three, a cave carries the
## depth of its brush.
func _mark_nibble(cell: Vector2i) -> int:
	if marked_cave_cells.has(cell):
		return int(marked_cave_cells[cell]["nibble"])
	return 3


## The mark of a cell is done: the cell reached its target depth.
func _clear_mark(cell: Vector2i) -> void:
	if marked_corridor_cells.erase(cell):
		return
	if not marked_cave_cells.has(cell):
		return
	var group: int = int(marked_cave_cells[cell]["group"])
	marked_cave_cells.erase(cell)
	if not cave_groups.has(group):
		return
	var pending: Array = cave_groups[group]["pending"]
	pending.erase(cell)


func _erase(point: Vector2) -> void:
	var candidates: Array[Vector2i] = eraser.update(Vector3(point.x, point.y, TOP),
		Rect2i(0, 0, 512, 640))
	var removed: int = 0
	for cell: Vector2i in candidates:
		if marked_cave_cells.has(cell):
			removed += _erase_cave_group(int(marked_cave_cells[cell]["group"]))
		elif marked_corridor_cells.has(cell):
			marked_corridor_cells.erase(cell)
			removed += 1
	if removed > 0:
		var remaining: Array[Vector2i] = []
		for cell: Vector2i in queue:
			if _is_marked(cell):
				remaining.append(cell)
		queue = remaining
		status.text = "Стерто ожидающих меток: %d" % removed
	_draw_marks()


## The erasure of a cave takes the whole group with it.
func _erase_cave_group(group: int) -> int:
	if not cave_groups.has(group):
		return 0
	var record: Dictionary = cave_groups[group]
	var removed: int = 0
	for cell: Vector2i in record["pending"]:
		if marked_cave_cells.erase(cell):
			removed += 1
	for cell: Vector2i in record["cells"]:
		cave_group_cells.erase(cell)
	cave_groups.erase(group)
	return removed


func advance(delta: float) -> void:
	_step_falling(delta)
	if not digging:
		return
	step_clock += delta
	if step_clock < STEP:
		return
	step_clock = 0.0
	var changed: bool = false
	newly_open.clear()
	for strike: int in range(4):
		if queue.is_empty():
			digging = false
			break
		var cell: Vector2i = queue.pop_front()
		if not _is_marked(cell):
			continue
		var nibble: int = _mark_nibble(cell)
		if _native_strike(cell, nibble):
			changed = true
		if _next_height(cell) >= 0 and RULES.target_height(nibble) <= _next_height(cell):
			queue.append(cell)
		else:
			_clear_mark(cell)
	if changed:
		texture.update(image)
		_draw_cut()
		_settle_objects()
		_revalidate_supports()
		_draw_marks()
	if queue.is_empty():
		digging = false
		_finish_caves()
		_decorate_new_passages()
		status.text = "Вскопка завершена" if marked_count() == 0 else \
			"Вскопка остановилась: %d меток не выкопаны" % marked_count()


## The objects of the excavation. An object that is bound to a surface
## disappears with the cell it stands in. A free object falls to the ground
## of its own cell.
func _settle_objects() -> void:
	if newly_open.is_empty():
		return
	for child: Node in root.get_children():
		if not child is Node3D or not child.has_meta("native_class") \
				or child.has_meta("generated_decor"):
			continue
		var object: Node3D = child as Node3D
		if processed_objects.has(object):
			continue
		var cell: Vector2i = _object_cell(object)
		if not _object_is_affected(cell):
			continue
		processed_objects[object] = true
		# SOURCE: urw_gng_*.tcl places native wooden supports at chapter setup;
		# the live trace sees them rise into a dug tunnel. Opening that tunnel
		# therefore must not hide the source placement.
		if str(object.get_meta("native_class")).begins_with("Dummy_Multi_Holzstuetze_"):
			# ADAPTER: a support under a shaft that has just been opened cannot
			# stand there any more: the crossing of a horizontal and a vertical
			# tunnel takes it away. The trace of the original covers a support
			# inside a dug tunnel (it rises and stays) and a support inside the
			# area of a cave (it disappears), but not the crossing itself.
			if newly_open.has(cell + Vector2i.UP) or newly_open.has(cell + Vector2i.UP + Vector2i.LEFT) \
					or newly_open.has(cell + Vector2i.UP + Vector2i.RIGHT):
				object.visible = false
			continue
		if _is_attachment(str(object.get_meta("native_class"))):
			object.visible = false
			continue
		var target: float = _cell_world_level(cell)
		if target < 0.0:
			# No ground of the map below the object: the object leaves the
			# world instead of falling for ever.
			object.visible = false
			continue
		if target < object.position.z:
			falling_objects[object] = target


func _is_attachment(native_class: String) -> bool:
	for prefix: String in ATTACHMENT_CLASSES:
		if native_class.begins_with(prefix):
			return true
	return false


## The cell of the map that carries an object. The origin of a placement of
## the chapter is the corner of its cell.
func _object_cell(object: Node3D) -> Vector2i:
	return Vector2i(floori(object.position.x), floori(-object.position.y))


func _object_is_affected(cell: Vector2i) -> bool:
	if newly_open.has(cell):
		return true
	# Placement origins are model corners; a one-cell footprint is therefore
	# allowed to straddle the newly opened cell on either side.
	for offset: Vector2i in [Vector2i.LEFT, Vector2i.RIGHT, Vector2i.UP, Vector2i.DOWN]:
		if newly_open.has(cell + offset):
			return true
	return false


func _cell_world_level(cell: Vector2i) -> float:
	# Objects and generated models are children of the campaign scene root. Its
	# Z transform performs the render conversion (scale .5, offset 7); their
	# local placement must therefore stay in logical level space.
	return _cell_surface_level(cell)


func _step_falling(delta: float) -> void:
	for object: Node3D in falling_objects.keys():
		if not is_instance_valid(object):
			falling_objects.erase(object)
			continue
		var target: float = float(falling_objects[object])
		object.position.z = move_toward(object.position.z, target, FALL_SPEED * delta)
		if is_equal_approx(object.position.z, target):
			falling_objects.erase(object)


## The frames of wood of the new tunnels.
##
## ADAPTER: the port currently puts one support in a straight run. The original
## chapter templates contain exact support placements. CMapBeautifier's
## four-cell-aligned scan selects map visuals, not these Tcl templates.
func _decorate_new_passages() -> void:
	if support_sources.is_empty():
		return
	var rows: Dictionary = {}
	for cell: Vector2i in excavated_cells:
		if cave_group_cells.has(cell):
			continue
		if _is_marked(cell):
			continue
		if not _is_open(cell):
			continue
		if not rows.has(cell.y):
			rows[cell.y] = []
		(rows[cell.y] as Array).append(cell.x)
	for row: int in rows:
		var columns: Array = rows[row]
		columns.sort()
		var run: Array = []
		for x: int in columns:
			if not run.is_empty() and int(run[run.size() - 1]) != x - 1:
				_place_support_run(run, row)
				run = []
			run.append(x)
		if not run.is_empty():
			_place_support_run(run, row)


## One frame of wood per run of a tunnel, in the middle of the run.
func _place_support_run(run: Array, row: int) -> void:
	if run.size() < SUPPORT_MIN_RUN:
		return
	var cell := Vector2i(int(run[run.size() / 2]), row)
	if decorated.has(cell):
		return
	# The upper part of the frame must not reach into an open space: the row
	# above the frame stays rock, and so do the two upper margins.
	if _is_open(cell + Vector2i.UP) or _is_open(cell + Vector2i.UP + Vector2i.LEFT) \
			or _is_open(cell + Vector2i.UP + Vector2i.RIGHT):
		return
	# The frame stands between two walls of the passage.
	if not _is_open(cell + Vector2i.LEFT) or not _is_open(cell + Vector2i.RIGHT):
		return
	if _near_support(Vector2(float(cell.x), float(row))):
		return
	var level: float = _cell_world_level(cell)
	if level < 0.0:
		return
	var exemplar: Node3D = support_sources[posmod(cell.x + row, support_sources.size())]
	var support: Node3D = exemplar.duplicate()
	support.name = "DugHolzstuetze_%d_%d" % [cell.x, row]
	# The frame of wood stands in the middle of its cell, as the original
	# placements do, and rests on the ground of the cell. The lower edge of
	# the model is read from the model itself, so the frame stands on the
	# floor of the new tunnel and does not sink into it.
	var bottom: float = _model_bottom(support)
	support.position = Vector3(float(cell.x) + 0.5, -(float(row) + 0.5), level - bottom)
	support.visible = true
	support.set_meta("generated_decor", true)
	root.add_child(support)
	decorated[cell] = support


## The lower edge of a model below the origin of its node. The frame of wood
## of the original is driven into the ground, so the origin of a placement is
## above the floor of its cell.
func _model_bottom(node: Node3D) -> float:
	var lowest: float = INF
	for child: Node in node.get_children():
		if not child is MeshInstance3D:
			continue
		var instance := child as MeshInstance3D
		if instance.mesh == null:
			continue
		var box: AABB = instance.get_aabb()
		var corner: Vector3 = instance.transform * box.position
		lowest = minf(lowest, corner.z)
	return 0.0 if is_inf(lowest) else lowest


## Is there a frame of wood, original or generated, near the place?
func _near_support(position: Vector2) -> bool:
	for other: Vector2 in original_supports:
		if other.distance_to(position) < SUPPORT_MIN_DISTANCE:
			return true
	for cell: Vector2i in decorated:
		var support: Node3D = decorated[cell]
		if not is_instance_valid(support):
			continue
		var other := Vector2(support.position.x, -support.position.y)
		if other.distance_to(position) < SUPPORT_MIN_DISTANCE:
			return true
	return false


## A frame of wood under an open space is not left there: the tunnel that is
## opened above it takes its place.
func _revalidate_supports() -> void:
	for cell: Vector2i in decorated.keys():
		var support: Node3D = decorated[cell]
		if not is_instance_valid(support):
			decorated.erase(cell)
			continue
		if _is_open(cell + Vector2i.UP) or _is_open(cell + Vector2i.UP + Vector2i.LEFT) \
				or _is_open(cell + Vector2i.UP + Vector2i.RIGHT):
			root.remove_child(support)
			support.queue_free()
			decorated.erase(cell)


## The caves that are dug to the end get their frame of the original game.
func _finish_caves() -> void:
	if cave_groups.is_empty():
		return
	var groups: Array = cave_groups.keys()
	for group: int in groups:
		var record: Dictionary = cave_groups[group]
		var pending: Array = record["pending"]
		if not pending.is_empty():
			continue
		var brush: int = int(record["brush"])
		var cells: Array = record["cells"]
		for cell: Vector2i in cells:
			excavated_cave_cells[cell] = {"group": group, "brush": brush}
		# ADAPTER: the original trace shows a support inside the cave footprint
		# disappear while digging. This removes it at cave completion, which
		# preserves the observed final state without claiming native timing.
		for child: Node in root.get_children():
			if child is Node3D and child.has_meta("native_class") \
					and str(child.get_meta("native_class")).begins_with("Dummy_Multi_Holzstuetze_") \
					and cells.has(_object_cell(child as Node3D)):
				(child as Node3D).visible = false
		var finished: Dictionary = {
			"group": group,
			"brush": brush,
			"skin_key": CAVE_SKIN.skin_key(brush),
			"cells": cells.duplicate(),
			"center": _cave_center(cells),
			"chamber_level": float(record["chamber_level"]),
		}
		finished_caves.append(finished)
		_spawn_cave_frame(finished)
		cave_groups.erase(group)


## The centre of the cave that was really dug: the middle of the box of its
## cells, not the cursor of the brush.
func _cave_center(cells: Array) -> Vector2:
	if cells.is_empty():
		return Vector2.ZERO
	var minimum := Vector2(INF, INF)
	var maximum := Vector2(-INF, -INF)
	for cell: Vector2i in cells:
		minimum.x = minf(minimum.x, float(cell.x))
		minimum.y = minf(minimum.y, float(cell.y))
		maximum.x = maxf(maximum.x, float(cell.x))
		maximum.y = maxf(maximum.y, float(cell.y))
	return Vector2((minimum.x + maximum.x + 1.0) * 0.5, (minimum.y + maximum.y + 1.0) * 0.5)


## The level of the floor that was really dug under the cave.
##
## Only the cells that the transition of the blocks opened carry a floor; the
## cells of the brush that stayed in the rock are not a floor of the chamber.
func _cave_floor_level(cells: Array) -> float:
	var total: float = 0.0
	var count: int = 0
	for cell: Vector2i in cells:
		if not excavated_cells.has(cell):
			continue
		var level: float = _cell_surface_level(cell)
		if level < 0.0:
			continue
		total += level
		count += 1
	if count == 0:
		return -1.0
	return total / float(count)


## The frame of a cave: the original skin of the size of the brush, on the
## floor of the chamber of the cave.
func _spawn_cave_frame(record: Dictionary) -> void:
	var brush: int = int(record["brush"])
	if not cave_skin_resources.has(brush):
		return
	var frame: Node3D = CAVE_SKIN.new().build_frame(cave_skin_resources, brush,
		"CaveFrame_%d" % int(record["group"]))
	if frame.get_child_count() == 0:
		return
	var center: Vector2 = record["center"]
	# The frame stands on the floor that was really dug under the cave: the
	# depth of the brush is the wish of the mark, the transition of the blocks
	# of the map can stop earlier. Without a dig the brush decides.
	var level: float = _cave_floor_level(record["cells"])
	if level < 0.0:
		level = float(record["chamber_level"])
	frame.position = Vector3(center.x, -center.y, level)
	frame.set_meta("generated_decor", true)
	root.add_child(frame)
	cave_frames.append(frame)


func _draw_marks() -> void:
	var corridor: Dictionary = {}
	var cave: Dictionary = {}
	for cell: Vector2i in marked_corridor_cells:
		corridor[cell] = true
	for cell: Vector2i in marked_cave_cells:
		cave[cell] = true
	if stroke.active:
		for cell: Vector2i in stroke.samples():
			if can_dig(cell):
				corridor[cell] = true
	_draw_contour(corridor, mark_mesh, false)
	_draw_contour(cave, cave_mesh, false)

func _draw_contour(samples: Dictionary, visual: MeshInstance3D, outline: bool) -> void:
	if samples.is_empty():
		visual.mesh = null
		return
	var triangles: PackedVector2Array = CONTOUR.build_triangles(samples, outline)
	if triangles.is_empty():
		visual.mesh = null
		return
	var surface := SurfaceTool.new()
	surface.begin(Mesh.PRIMITIVE_TRIANGLES)
	for point: Vector2 in triangles:
		surface.add_vertex(Vector3(point.x, -point.y, 15.13 if outline else 15.12))
	visual.mesh = surface.commit()

func _update_hover(screen: Vector2) -> void:
	if hover_mesh == null:
		return
	hover_mesh.mesh = null
	if tool.is_empty() or toolbar.get_global_rect().has_point(screen):
		return
	var raw: Variant = _point(screen)
	if raw is Vector2:
		_update_hover_at(raw)


func _update_hover_at(raw: Vector2) -> void:
	hover_mesh.mesh = null
	var samples: Dictionary = {}
	var tint := Color(0.42, 0.56, 0.32)
	if tool.contains("Туннель"):
		var preview_stroke: RefCounted = STROKE.new()
		preview_stroke.begin(raw, Rect2i(0, 0, 511, 639))
		for cell: Vector2i in preview_stroke.samples():
			samples[cell] = true
	elif tool.contains("Пещера"):
		tint = Color(0.30, 0.32, 0.56)
		for sample: Vector3i in _cave_cells(int(tool.right(1)), Vector2i(int(raw.x), int(raw.y))):
			samples[Vector2i(sample.x, sample.z)] = true
	elif tool.contains("Стёрка"):
		tint = Color(0.40, 0.42, 0.43)
		for cell: Vector2i in ERASE.between(Vector3(raw.x, raw.y, TOP),
				Vector3(raw.x, raw.y, TOP), Rect2i(0, 0, 512, 640)):
			samples[cell] = true
	(hover_mesh.material_override as StandardMaterial3D).albedo_color = tint
	_draw_contour(samples, hover_mesh, true)

func _draw_cut() -> void:
	var tools: Dictionary = {}
	var materials: Dictionary = {}
	var normals: Array = profile.data["normals"]
	for cell: Vector2i in block_overrides:
		var block: int = int(block_overrides[cell])
		if not native_meshes.has(str(block)):
			continue
		var variant: int = GROUND.base_variant(cell)
		var ground_file: String = profile.ground_file(cell, variant)
		for part: Dictionary in native_meshes[str(block)]:
			var key: String = "%d:%s" % [int(part["part"]), ground_file]
			if not tools.has(key):
				var builder := SurfaceTool.new()
				builder.begin(Mesh.PRIMITIVE_TRIANGLES)
				builder.set_custom_format(0, SurfaceTool.CUSTOM_RGBA_FLOAT)
				tools[key] = builder
				materials[key] = profile.terrain_material(variant, true, false,
					ground_file, false, "res://textures/ground/", true)
			var builder: SurfaceTool = tools[key]
			var values: Array = part["vertices"]
			var indices: Array = part["indices"]
			var attributes: Array = part["attributes"]
			var detail: String = profile.detail_texture(cell, int(part["part"]))
			for index: int in indices:
				var offset: int = index * 5
				var source_normal: Array = normals[int(attributes[index])]
				var local := Vector3(float(values[offset]), float(values[offset + 1]),
					float(values[offset + 2]))
				builder.set_normal(Vector3(float(source_normal[0]), -float(source_normal[1]),
					float(source_normal[2]) * 0.5).normalized())
				builder.set_uv(Vector2(float(values[offset + 3]), float(values[offset + 4])))
				builder.set_uv2(profile.detail_slot(detail))
				var channels: Dictionary = profile.terrain_channels(cell, local, source_normal, 1.0)
				builder.set_color(channels["diffuse"])
				builder.set_custom(0, channels["secondary"])
				builder.add_vertex(Vector3(cell.x + local.x, -(cell.y + local.y),
					2.0 * local.z - 14.0))
	var mesh := ArrayMesh.new()
	for key: String in tools:
		(tools[key] as SurfaceTool).commit(mesh)
		mesh.surface_set_material(mesh.get_surface_count() - 1, materials[key])
	cut_mesh.mesh = mesh
