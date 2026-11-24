extends Node3D
## Source map X/Y are horizontal/down; Z is depth toward the viewer.

const NATIVE_POINT_SCALE: float = 16384.0
# Native unit-instance render scale (ModelRenderer.cpp draw at 0x4874a3).
const OBJECT_WORLD_SCALE: float = 0.005
const BDB_DEPTH_SCALE: float = 2.0
const BDB_DEPTH_OFFSET: float = -14.0
const RENDER_DEPTH_SCALE: float = 0.5
const RENDER_DEPTH_OFFSET: float = 7.0
const NATIVE_DIG_RULES: Script = preload("res://scripts/native_dig_rules.gd")

var camera: Camera3D
var focus: Vector3 = Vector3(12.0, -7.5, 11.0)
var scene_root: Node3D
var yaw: float = 0.0
var pitch: float = 0.16
var distance: float = 25.0
var triangle_count: int = 0
var status: Label
var terrain_part_filter: PackedStringArray = PackedStringArray()
var terrain_flag_filter: PackedStringArray = PackedStringArray()
var include_objects: bool = true
var include_terrain: bool = true
var terrain_double_sided: bool = false
var terrain_cull_front: bool = false
var camera_yaw_base: float = 0.0
var render_depth_scale: float = RENDER_DEPTH_SCALE
var use_orthographic_camera: bool = false
var model_count: int = 0
var placement_count: int = 0
var texture_count: int = 0
var touch_points: Dictionary[int, Vector2] = {}
var gesture_centroid: Vector2 = Vector2.ZERO
var gesture_span: float = 0.0
var gesture_baseline_ready: bool = false
var gesture_dirty: bool = false
var two_finger_mode: StringName = &"none"
var touch_start_positions: Dictionary[int, Vector2] = {}
var mouse_press_position: Vector2 = Vector2.ZERO
var mouse_dragged: bool = false
var mouse_pressed_dwarf: bool = false
var gesture_had_multiple_touches: bool = false
var dwarf_nodes: Array[Node3D] = []
var dwarf_headings: Dictionary = {}
var selected_dwarf: Node3D = null
var dwarf_locomotion_visuals: Dictionary = {}
var moving_dwarf: Node3D = null
var movement_target: Vector3 = Vector3.ZERO
var movement_path: Array[Vector3] = []
var movement_path_index: int = 0
var locomotion_state: StringName = &"idle"
var locomotion_elapsed: float = 0.0
var locomotion_frame: int = -1
var selection_outline_material: ShaderMaterial = null
var navigation_grid: AStarGrid2D = null
var navigation_obstacles: Array[Vector3] = []
var last_walk_target: Vector3 = Vector3(INF, INF, INF)
var fast_walk: bool = false
var pending_heading: float = 0.0
var idle_animation_elapsed: float = 0.0
var dwarf_idle_frame_indices: Dictionary = {}
var player_cave_brushes: Array[Dictionary] = []
var selected_cave_brush: int = 1
var show_cave_brush_preview: bool = false
var strict_native_cell_state: bool = false
var cave_brush_preview_root: Node3D = null
var native_terrain_width: int = 0
var native_terrain_height: int = 0
var native_terrain_cells: Dictionary = {}
var native_mark_nibbles: Dictionary = {}
var native_cell_heights: Dictionary = {}
var native_active_caves: Array[Dictionary] = []
var native_finished_cave_skins: Array[Dictionary] = []
var cave_skin_resources: Dictionary = {}
var cave_dig_timer: float = 0.0
var automatic_cave_demo: bool = false
var dig_tool: String = ""
var dig_toolbar: HBoxContainer
var toolbar_touch_ids: Dictionary = {}
var toolbar_mouse_down := false
var corridor_mode: bool = false
var corridor_preview_root: Node3D = null
var corridor_last_cell: Variant = null
var corridor_marked_cells: Dictionary = {}
var corridor_marker_nodes: Dictionary = {}
var open_air: Dictionary = {}
var tool_cursor: Label
var barrels: Array[Node3D] = []
var barrel_goal: Node3D
var corridor_shader: Shader = null

const WALKABLE_FLOOR_Y: float = -10.5
const WALKABLE_FLOOR_MIN_X: float = 4.0
const WALKABLE_FLOOR_MAX_X: float = 23.5
const WALKABLE_FLOOR_MIN_Z: float = 1.0
const WALKABLE_FLOOR_MAX_Z: float = 15.0
const NAVIGATION_CELL_SIZE: float = 0.5
const WALK_SPEED: float = 0.98
const RUN_SPEED_MULTIPLIER: float = 2.113626
const WALK_ANIMATION_FPS: float = 12.0
const IDLE_ANIMATION_FPS: float = 7.0
const TWO_FINGER_DECISION_PIXELS: float = 5.0
const TWO_FINGER_DOMINANCE: float = 1.15
const DIG_MARK_DEPTH: float = 15.12
const GRID_Y_OFFSET: float = 0.5 # floor at map Y 10.5
const CORRIDOR_GRID_STEP: float = 2.5


func _ready() -> void:
	_load_native_cave_brushes()
	_load_cave_skin_resources()
	var contents: String = FileAccess.get_file_as_string("res://models/hol_024_terrain.json")
	var decoded: Variant = JSON.parse_string(contents)
	if not decoded is Dictionary:
		push_error("Native terrain manifest is missing or invalid")
		get_tree().quit(1)
		return
	var data: Dictionary = decoded
	_load_native_terrain_grid(data)
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var part_index: int = args.find("--terrain-part")
	if part_index >= 0 and part_index + 1 < args.size():
		terrain_part_filter = args[part_index + 1].split(",")
	var flags_index: int = args.find("--terrain-flags")
	if flags_index >= 0 and flags_index + 1 < args.size():
		terrain_flag_filter = args[flags_index + 1].split(",")
	include_objects = not args.has("--no-objects")
	include_terrain = not args.has("--no-terrain")
	show_cave_brush_preview = args.has("--show-cave-brush-preview")
	strict_native_cell_state = args.has("--strict-native-cell-state")
	automatic_cave_demo = args.has("--demo-auto-dig")
	terrain_double_sided = args.has("--terrain-double-sided")
	terrain_cull_front = args.has("--terrain-cull-front")
	use_orthographic_camera = args.has("--orthographic")
	var depth_scale_index: int = args.find("--depth-scale")
	if depth_scale_index >= 0 and depth_scale_index + 1 < args.size():
		render_depth_scale = clampf(float(args[depth_scale_index + 1]), 0.35, 1.0)
	scene_root = Node3D.new()
	scene_root.name = "NativeRenderSpace"
	# Keep all source placements in logical units and pack the complete scene
	# once, exactly as the native point-emission path does (EXE 0x409baf).
	scene_root.scale.z = render_depth_scale
	scene_root.position.z = RENDER_DEPTH_OFFSET
	add_child(scene_root)
	camera_yaw_base = PI if args.has("--camera-from-back") else 0.0
	yaw = camera_yaw_base
	_build_geometry(data)
	if show_cave_brush_preview:
		if native_cave_brush_can_place(1, 16, 11):
			_build_cave_brush_preview(1, 16, 11)
		else:
			push_error("Native cave brush preview placement rejected")
	_build_corridor_preview_root()
	if args.has("--show-cave-skin-preview"):
		_spawn_cave_skin_visual(1, Vector3(15.0, WALKABLE_FLOOR_Y, 8.0))
	if args.has("--demo-complete-cave"):
		_run_cave_completion_demo()
	if include_objects:
		_build_static_objects()
	_build_navigation_grid()
	if terrain_flag_filter.is_empty() and triangle_count != int(data["summary"]["triangles"]):
		push_error("Native terrain triangle count differs from exported source")
		get_tree().quit(1)
		return
	_index_open_air(data)
	_build_camera_and_light()
	_build_caption()
	_update_camera()
	var depth_range: Array = data["summary"]["packed_depth_range"]
	print("NATIVE_TERRAIN_READY cells=%d triangles=%d packed_depth=%s..%s" % [int(data["summary"]["cells"]), triangle_count, str(depth_range[0]), str(depth_range[1])])
	var capture_index: int = args.find("--capture-dir")
	if capture_index >= 0 and capture_index + 1 < args.size():
		_capture_views(args[capture_index + 1])
	print("DEMO_START_MODELS_READY placements=%d unique_models=%d original_textures=%d" % [placement_count, model_count, texture_count])
	if show_cave_brush_preview:
		print("NATIVE_CAVE_BRUSH_PREVIEW_READY brush=%d cursor=(16,11)" % selected_cave_brush)


func _load_native_cave_brushes() -> void:
	var contents: String = FileAccess.get_file_as_string("res://resources/digging/player_cave_brushes.json")
	var decoded: Variant = JSON.parse_string(contents)
	if not decoded is Dictionary:
		push_error("Native cave brush manifest is missing or invalid")
		return
	var manifest: Dictionary = decoded
	var brushes_variant: Variant = manifest.get("brushes", [])
	if not brushes_variant is Array or brushes_variant.size() != 4:
		push_error("Native cave brush manifest must contain four brushes")
		return
	for brush_variant: Variant in brushes_variant:
		if not brush_variant is Dictionary:
			push_error("Native cave brush entry is invalid")
			return
		var brush: Dictionary = brush_variant
		var rows_variant: Variant = brush.get("rows", [])
		if not rows_variant is Array or rows_variant.size() != 32:
			push_error("Native cave brush must contain a 32x32 mask")
			return
		for row_variant: Variant in rows_variant:
			if not row_variant is Array or row_variant.size() != 32:
				push_error("Native cave brush row must contain 32 cells")
				return
		player_cave_brushes.append(brush)
	print("NATIVE_CAVE_BRUSHES_READY count=%d anchor=%s" % [player_cave_brushes.size(), str(manifest.get("anchor", []))])
	for brush_number: int in range(1, player_cave_brushes.size() + 1):
		var cells: Array[Vector3i] = native_cave_brush_cells(brush_number, 16, 32)
		print("NATIVE_CAVE_BRUSH brush=%d cells=%d bounds=%s" % [brush_number, cells.size(), str(native_cave_brush_bounds(brush_number, 16, 32))])


func _load_cave_skin_resources() -> void:
	for size: int in range(1, 5):
		var resource_path: String = "res://models/cave_skins/urw_caves_%d_a_a.json" % size
		if not FileAccess.file_exists(resource_path):
			print("NATIVE_CAVE_SKIN_PENDING missing=" + resource_path)
			continue
		var contents: String = FileAccess.get_file_as_string(resource_path)
		var decoded: Variant = JSON.parse_string(contents)
		if not decoded is Dictionary:
			print("NATIVE_CAVE_SKIN_PENDING invalid=" + resource_path)
			continue
		var manifest: Dictionary = decoded
		var surfaces_variant: Variant = manifest.get("surfaces", [])
		if not surfaces_variant is Array:
			print("NATIVE_CAVE_SKIN_PENDING surfaces=" + resource_path)
			continue
		var meshes: Array[ArrayMesh] = _build_cave_skin_meshes(surfaces_variant)
		cave_skin_resources[size] = meshes
		print("NATIVE_CAVE_SKIN_READY size=%d meshes=%d" % [size, meshes.size()])


func _build_cave_skin_meshes(surfaces: Array) -> Array[ArrayMesh]:
	var meshes: Array[ArrayMesh] = []
	for surface_variant: Variant in surfaces:
		if not surface_variant is Dictionary:
			continue
		var surface_data: Dictionary = surface_variant
		var points_variant: Variant = surface_data.get("points", [])
		var uvs_variant: Variant = surface_data.get("uvs", [])
		var triangles_variant: Variant = surface_data.get("triangles", [])
		if not points_variant is Array or not uvs_variant is Array or not triangles_variant is Array:
			continue
		var points: Array = points_variant
		var uvs: Array = uvs_variant
		var triangles: Array = triangles_variant
		var surface_tool: SurfaceTool = SurfaceTool.new()
		surface_tool.begin(Mesh.PRIMITIVE_TRIANGLES)
		for index_variant: Variant in triangles:
			var index: int = int(index_variant)
			if index < 0 or index >= points.size() or index >= uvs.size():
				continue
			var point: Array = points[index]
			var uv: Array = uvs[index]
			surface_tool.set_uv(Vector2(float(uv[0]), 1.0 - float(uv[1])))
			surface_tool.add_vertex(Vector3(float(point[0]), -float(point[1]), float(point[2])) * OBJECT_WORLD_SCALE)
		surface_tool.generate_normals()
		var mesh: ArrayMesh = surface_tool.commit()
		if mesh == null:
			continue
		var material: StandardMaterial3D = StandardMaterial3D.new()
		material.cull_mode = BaseMaterial3D.CULL_DISABLED
		material.roughness = 0.95
		var texture_name: String = str(surface_data.get("texture", "Holz_Standard_a_256.tga"))
		var texture_path: String = "res://assets/textures/" + texture_name
		if ResourceLoader.exists(texture_path):
			material.albedo_texture = load(texture_path) as Texture2D
		mesh.surface_set_material(0, material)
		meshes.append(mesh)
	return meshes


func _spawn_cave_skin_visual(size: int, local_position: Vector3) -> Node3D:
	var visual_root: Node3D = Node3D.new()
	visual_root.name = "CaveSkinPreview_%d" % size
	visual_root.position = local_position
	var meshes_variant: Variant = cave_skin_resources.get(size, [])
	if not meshes_variant is Array:
		return visual_root
	for mesh_variant: Variant in meshes_variant:
		if not mesh_variant is ArrayMesh:
			continue
		var mesh_instance: MeshInstance3D = MeshInstance3D.new()
		mesh_instance.mesh = mesh_variant
		visual_root.add_child(mesh_instance)
	scene_root.add_child(visual_root)
	print("NATIVE_CAVE_SKIN_PREVIEW size=%d meshes=%d position=%s" % [size, visual_root.get_child_count(), str(local_position)])
	return visual_root


func _load_native_terrain_grid(data: Dictionary) -> void:
	native_terrain_width = int(data.get("width", 0))
	native_terrain_height = int(data.get("height", 0))
	native_terrain_cells.clear()
	var cells_variant: Variant = data.get("cells", [])
	if not cells_variant is Array:
		return
	for cell_variant: Variant in cells_variant:
		if not cell_variant is Dictionary:
			continue
		var cell: Dictionary = cell_variant
		var key: Vector2i = Vector2i(int(cell.get("x", -1)), int(cell.get("y", -1)))
		if key.x >= 0 and key.y >= 0:
			native_terrain_cells[key] = cell
	print("NATIVE_TERRAIN_GRID_READY size=%dx%d cells=%d" % [native_terrain_width, native_terrain_height, native_terrain_cells.size()])


func native_cave_brush_cells(brush_number: int, cursor_x: int, cursor_y: int) -> Array[Vector3i]:
	var cells: Array[Vector3i] = []
	if brush_number < 1 or brush_number > player_cave_brushes.size():
		return cells
	var brush: Dictionary = player_cave_brushes[brush_number - 1]
	var rows_variant: Variant = brush.get("rows", [])
	if not rows_variant is Array:
		return cells
	var rows: Array = rows_variant
	for mask_y: int in range(rows.size()):
		var row_variant: Variant = rows[mask_y]
		if not row_variant is Array:
			continue
		var row: Array = row_variant
		for mask_x: int in range(row.size()):
			var value: int = int(row[mask_x])
			if value == 4:
				continue
			# Native 0x567CB0 anchor: cursor minus (16, 32).
			cells.append(Vector3i(cursor_x + mask_x - 16, value, cursor_y + mask_y - 32))
	return cells


func native_cave_brush_bounds(brush_number: int, cursor_x: int, cursor_y: int) -> Rect2i:
	var cells: Array[Vector3i] = native_cave_brush_cells(brush_number, cursor_x, cursor_y)
	if cells.is_empty():
		return Rect2i()
	var bounds: Rect2i = Rect2i(Vector2i(cells[0].x, cells[0].z), Vector2i.ONE)
	for cell: Vector3i in cells:
		bounds = bounds.expand(Vector2i(cell.x, cell.z))
	return bounds


func native_cave_brush_can_place(brush_number: int, cursor_x: int, cursor_y: int) -> bool:
	var cells: Array[Vector3i] = native_cave_brush_cells(brush_number, cursor_x, cursor_y)
	if cells.is_empty():
		return false
	for cell: Vector3i in cells:
		var map_cell: Vector2i = Vector2i(cell.x, cell.z)
		if map_cell.x < 0 or map_cell.x >= native_terrain_width:
			return false
		if map_cell.y < 0 or map_cell.y >= native_terrain_height:
			return false
		if not native_terrain_cells.has(map_cell):
			return false
		if strict_native_cell_state and not native_cave_cell_state_allows_dig(map_cell):
			return false
	return true


func native_cave_cell_state_allows_dig(map_cell: Vector2i) -> bool:
	if not native_terrain_cells.has(map_cell):
		return false
	var cell_variant: Variant = native_terrain_cells[map_cell]
	if not cell_variant is Dictionary:
		return false
	var cell: Dictionary = cell_variant
	# Native 0x5671A0 rejects material states 0 and 3. The exported terrain
	# manifest preserves the source cell_attribute; interpretation stays opt-in
	# until the runtime field mapping is dynamically confirmed.
	var source_state: int = int(cell.get("cell_attribute", -1))
	return source_state != 0 and source_state != 3


func native_mark_cave_cell(owner_id: int, map_cell: Vector2i, mark_value: int, layer: int = 0) -> bool:
	if owner_id < 0 or owner_id > 6 or layer < 0 or layer > 3:
		return false
	if not native_terrain_cells.has(map_cell):
		return false
	if mark_value < 0 or mark_value > 3:
		return false
	var key: String = _native_cell_key(map_cell, layer, owner_id)
	native_mark_nibbles[key] = 8 | mark_value
	return true


func native_clear_cave_mark(owner_id: int, map_cell: Vector2i, layer: int = 0) -> void:
	if owner_id < 0 or owner_id > 6 or layer < 0 or layer > 3:
		return
	native_mark_nibbles.erase(_native_cell_key(map_cell, layer, owner_id))


func native_dig_apply_cell(owner_id: int, map_cell: Vector2i, layer: int = 0) -> bool:
	if owner_id < 0 or owner_id > 6 or layer < 0 or layer > 3:
		return false
	var key: String = _native_cell_key(map_cell, layer, owner_id)
	if not native_mark_nibbles.has(key):
		return false
	var mark_nibble: int = int(native_mark_nibbles[key])
	if (mark_nibble & 15) == 0:
		return false
	var target_height: int = NATIVE_DIG_RULES.target_height(mark_nibble)
	var current_height: int = int(native_cell_heights.get(key, 15))
	if current_height <= target_height:
		native_clear_cave_mark(owner_id, map_cell, layer)
		return false
	var next_height: int = maxi(target_height, current_height - 1)
	native_cell_heights[key] = next_height
	if next_height <= target_height:
		native_clear_cave_mark(owner_id, map_cell, layer)
	return true


func native_begin_cave(owner_id: int, brush_number: int, cursor_x: int, cursor_y: int, layer: int = 0) -> bool:
	if owner_id < 0 or owner_id > 6 or layer < 0 or layer > 3:
		return false
	if not native_cave_brush_can_place(brush_number, cursor_x, cursor_y):
		return false
	var cells: Array[Vector3i] = native_cave_brush_cells(brush_number, cursor_x, cursor_y)
	var record: Dictionary = {
		"owner_id": owner_id,
		"layer": layer,
		"brush_number": brush_number,
		"cursor": Vector2i(cursor_x, cursor_y),
		"cells": cells,
	}
	for cell: Vector3i in cells:
		native_mark_cave_cell(owner_id, Vector2i(cell.x, cell.z), cell.y, layer)
	native_active_caves.append(record)
	return true


func native_cave_is_complete(record: Dictionary) -> bool:
	var owner_id: int = int(record.get("owner_id", -1))
	var layer: int = int(record.get("layer", -1))
	var cells_variant: Variant = record.get("cells", [])
	if owner_id < 0 or layer < 0 or not cells_variant is Array:
		return false
	for cell_variant: Variant in cells_variant:
		if not cell_variant is Vector3i:
			return false
		var cell: Vector3i = cell_variant
		var key: String = _native_cell_key(Vector2i(cell.x, cell.z), layer, owner_id)
		if native_mark_nibbles.has(key):
			return false
	return true


func native_apply_next_cave_strike(cave_index: int) -> bool:
	if cave_index < 0 or cave_index >= native_active_caves.size():
		return false
	var record: Dictionary = native_active_caves[cave_index]
	var owner_id: int = int(record.get("owner_id", -1))
	var layer: int = int(record.get("layer", -1))
	var cells_variant: Variant = record.get("cells", [])
	if not cells_variant is Array:
		return false
	for cell_variant: Variant in cells_variant:
		if not cell_variant is Vector3i:
			continue
		var cell: Vector3i = cell_variant
		if native_dig_apply_cell(owner_id, Vector2i(cell.x, cell.z), layer):
			return true
	return false


func native_select_cave_skin(record: Dictionary, detail: int = 2) -> String:
	var brush_number: int = int(record.get("brush_number", 0))
	var size_index: int = clampi(brush_number, 1, 4)
	var detail_index: int = clampi(detail, 0, 2)
	var detail_suffix: String = ["c", "b", "a"][detail_index]
	return "urw_caves_%d_a_%s" % [size_index, detail_suffix]


func native_finish_completed_caves() -> int:
	var completed_count: int = 0
	var remaining: Array[Dictionary] = []
	for record: Dictionary in native_active_caves:
		if not native_cave_is_complete(record):
			remaining.append(record)
			continue
		var finished: Dictionary = record.duplicate(true)
		finished["skin_key"] = native_select_cave_skin(record)
		finished["native_z"] = 15.0
		native_finished_cave_skins.append(finished)
		var center: Vector2i = _native_cave_record_center(record)
		_spawn_cave_skin_visual(int(record.get("brush_number", 0)),
			Vector3(float(center.x), WALKABLE_FLOOR_Y, float(center.y)))
		completed_count += 1
	native_active_caves = remaining
	return completed_count


func _native_cave_record_center(record: Dictionary) -> Vector2i:
	var cursor_variant: Variant = record.get("cursor", Vector2i.ZERO)
	if not cursor_variant is Vector2i:
		return Vector2i.ZERO
	var cursor: Vector2i = cursor_variant
	var brush_number: int = int(record.get("brush_number", 0))
	var bounds: Rect2i = native_cave_brush_bounds(brush_number, cursor.x, cursor.y)
	return Vector2i(bounds.position.x + int(floor(float(bounds.size.x) * 0.5)),
		bounds.position.y + int(floor(float(bounds.size.y) * 0.5)))


func _run_cave_completion_demo() -> void:
	var started: bool = native_begin_cave(0, 1, 16, 11)
	if not started:
		push_error("Native cave completion demo could not start")
		return
	var strikes: int = 0
	while not native_active_caves.is_empty() and strikes < 1000:
		var applied: bool = native_apply_next_cave_strike(0)
		if not applied:
			break
		strikes += 1
	var completed: int = native_finish_completed_caves()
	print("NATIVE_CAVE_COMPLETION_DEMO strikes=%d completed=%d skins=%d" % [strikes, completed, native_finished_cave_skins.size()])


func _native_cell_key(map_cell: Vector2i, layer: int, owner_id: int) -> String:
	return "%d:%d:%d:%d" % [map_cell.x, map_cell.y, layer, owner_id]


func native_cave_brush_target_height(mark_value: int) -> int:
	if mark_value < 0 or mark_value > 3:
		return 15
	return NATIVE_DIG_RULES.target_height(8 | mark_value)


func _build_cave_brush_preview(brush_number: int, cursor_x: int, cursor_y: int) -> void:
	if cave_brush_preview_root != null:
		cave_brush_preview_root.queue_free()
	cave_brush_preview_root = Node3D.new()
	cave_brush_preview_root.name = "NativeCaveBrushPreview"
	scene_root.add_child(cave_brush_preview_root)
	var cells: Array[Vector3i] = native_cave_brush_cells(brush_number, cursor_x, cursor_y)
	for cell: Vector3i in cells:
		var marker: MeshInstance3D = MeshInstance3D.new()
		marker.name = "BrushCell_%d_%d" % [cell.x, cell.z]
		var cube: BoxMesh = BoxMesh.new()
		cube.size = Vector3(0.34, 0.34, 0.035)
		marker.mesh = cube
		var material: StandardMaterial3D = StandardMaterial3D.new()
		material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA
		material.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
		material.albedo_color = _cave_brush_preview_color(cell.y)
		marker.material_override = material
		marker.position = Vector3(float(cell.x), -float(cell.z), DIG_MARK_DEPTH)
		cave_brush_preview_root.add_child(marker)


func _cave_brush_preview_color(mark_value: int) -> Color:
	match mark_value:
		0:
			return Color(0.12, 0.35, 1.0, 0.82)
		1:
			return Color(0.1, 0.85, 1.0, 0.82)
		2:
			return Color(0.15, 1.0, 0.55, 0.82)
		3:
			return Color(1.0, 0.85, 0.1, 0.9)
		_:
			return Color.WHITE


func _build_static_objects() -> void:
	var contents: String = FileAccess.get_file_as_string("res://models/demo_start_models.json")
	var decoded: Variant = JSON.parse_string(contents)
	if not decoded is Dictionary:
		push_error("Demo start model manifest is missing or invalid")
		return
	var data: Dictionary = decoded
	var model_data: Dictionary = data["objects"]
	model_count = model_data.size()
	placement_count = data["placements"].size()
	texture_count = data["textures"].size()
	var mesh_cache: Dictionary = {}
	var locomotion_cache: Dictionary = {}
	for key: String in model_data:
		var model: Dictionary = model_data[key]
		mesh_cache[key] = _build_model_meshes(model["surfaces"])
		var locomotion: Dictionary = model.get("locomotion", {})
		if not locomotion.is_empty():
			var sequence_cache: Dictionary = {}
			for sequence_name: String in locomotion:
				var sequence: Dictionary = locomotion[sequence_name]
				var frames: Array = []
				for frame: Dictionary in sequence["frames"]:
					frames.append(_build_model_meshes(frame["surfaces"]))
				sequence_cache[sequence_name] = frames
			locomotion_cache[key] = sequence_cache
	var placements: Array = data["placements"]
	for placement: Dictionary in placements:
		var placement_class: String = str(placement["class"])
		var key: String = str(placement.get("model_package", "")).to_lower() + "::" + str(placement.get("model_object", "")).to_lower()
		if not mesh_cache.has(key) and not placement_class.begins_with("Misc_LightSrc_"):
			continue
		var position_data: Array = placement["position"]
		var rotation_data: Array = placement["rotation"]
		var instance_root: Node3D = Node3D.new()
		instance_root.name = "%s_%03d" % [str(placement["class"]), int(placement["ordinal"])]
		var game_to_godot: Basis = Basis(Vector3.RIGHT, Vector3.DOWN, Vector3.BACK)
		# Native Euler builder uses row vectors Rz * Rx * Ry. Transpose
		# that basis for Godot's column vectors before reflecting source Y.
		var source_rotation: Basis = Basis(Vector3.UP, -float(rotation_data[1])) \
			* Basis(Vector3.RIGHT, -float(rotation_data[0])) \
			* Basis(Vector3.BACK, -float(rotation_data[2]))
		var mapped_rotation: Basis = game_to_godot * source_rotation * game_to_godot.inverse()
		# 3DB displacements already use renderer units. Convert the rotated
		# displacement into logical Z so the outer packing does not halve it.
		var render_to_logical: Basis = Basis(Vector3.RIGHT, Vector3.UP, Vector3(0.0, 0.0, 1.0 / render_depth_scale))
		instance_root.transform = Transform3D(render_to_logical * mapped_rotation,
			Vector3(float(position_data[0]), -float(position_data[1]), float(position_data[2])))
		var obstacle_radius: float = _navigation_obstacle_radius(placement_class)
		if obstacle_radius > 0.0 and absf(float(position_data[1]) - 10.5) < 0.8:
			navigation_obstacles.append(Vector3(float(position_data[0]), float(position_data[2]), obstacle_radius))
		var default_visuals: Array[MeshInstance3D] = []
		if mesh_cache.has(key):
			for mesh_index: int in range(mesh_cache[key].size()):
				var mesh_instance: MeshInstance3D = MeshInstance3D.new()
				mesh_instance.mesh = mesh_cache[key][mesh_index]
				instance_root.add_child(mesh_instance)
				default_visuals.append(mesh_instance)
		if placement_class == "Misc_Light" or placement_class.begins_with("Misc_LightSrc_"):
			_add_template_light(instance_root, placement_class)
		scene_root.add_child(instance_root)
		if placement_class == "Schatztonne":
			barrels.append(instance_root)
		if placement_class == "Zwerg":
			dwarf_nodes.append(instance_root)
			dwarf_headings[instance_root] = 0.0
			var sequence_visuals: Dictionary = {}
			if locomotion_cache.has(key):
				var cached_sequences: Dictionary = locomotion_cache[key]
				for sequence_name: String in cached_sequences:
					var frame_visuals: Array[Node3D] = []
					var cached_frames: Array = cached_sequences[sequence_name]
					for frame_index: int in range(cached_frames.size()):
						var frame_root: Node3D = Node3D.new()
						frame_root.name = "%s_%02d" % [sequence_name, frame_index]
						frame_root.visible = false
						var frame_meshes: Array = cached_frames[frame_index]
						for frame_mesh: ArrayMesh in frame_meshes:
							var frame_instance: MeshInstance3D = MeshInstance3D.new()
							frame_instance.mesh = frame_mesh
							frame_root.add_child(frame_instance)
						instance_root.add_child(frame_root)
						frame_visuals.append(frame_root)
					sequence_visuals[sequence_name] = frame_visuals
			dwarf_locomotion_visuals[instance_root] = {
				"default": default_visuals, "sequences": sequence_visuals, "current": null}


func _navigation_obstacle_radius(placement_class: String) -> float:
	if placement_class.begins_with("Dummy_Baumstumpf"):
		return 1.05
	if placement_class == "Zelt":
		return 1.35
	if placement_class == "Feuerstelle":
		return 0.75
	if "Seule" in placement_class:
		return 0.62
	if "Traeger" in placement_class:
		return 0.58
	if placement_class.begins_with("Dummy_Balken"):
		return 0.5
	if placement_class in ["Schatztonne", "Dummy_Strohballen_a", "Dummy_Strohballen_c"]:
		return 0.62
	if placement_class == "Pilz":
		return 0.58
	return 0.0


func _build_model_meshes(surfaces: Array) -> Array[ArrayMesh]:
	var meshes: Array[ArrayMesh] = []
	for source_surface: Dictionary in surfaces:
		var vertices: Array = source_surface["points"]
		var uvs: Array = source_surface["uvs"]
		var indices: Array = source_surface["triangles"]
		var brightness: Array = source_surface.get("brightness", [])
		var use_source_brightness: bool = str(source_surface["texture"]).begins_with("Trollh_Wandschmuck")
		if vertices.is_empty() or uvs.is_empty() or indices.is_empty():
			continue
		var surface_tool: SurfaceTool = SurfaceTool.new()
		surface_tool.begin(Mesh.PRIMITIVE_TRIANGLES)
		for index_value: Variant in indices:
			var index: int = int(index_value)
			if index >= vertices.size() or index >= uvs.size():
				continue
			var raw_point: Array = vertices[index]
			var uv: Array = uvs[index]
			surface_tool.set_uv(Vector2(float(uv[0]), float(uv[1])))
			if use_source_brightness and index < brightness.size():
				var shade: float = float(brightness[index]) / 255.0
				surface_tool.set_color(Color(shade, shade, shade, 1.0))
			var native_point: Vector3 = Vector3(float(raw_point[0]) - 0.5,
				-(float(raw_point[1]) - 0.5), float(raw_point[2]) - 0.5) * NATIVE_POINT_SCALE
			surface_tool.add_vertex(native_point * OBJECT_WORLD_SCALE)
		surface_tool.generate_normals()
		var mesh: ArrayMesh = surface_tool.commit()
		var material: StandardMaterial3D = StandardMaterial3D.new()
		material.cull_mode = BaseMaterial3D.CULL_DISABLED
		material.roughness = 0.95
		material.vertex_color_use_as_albedo = use_source_brightness
		var texture_path: String = "res://assets/textures/" + str(source_surface["texture"])
		if ResourceLoader.exists(texture_path):
			material.albedo_texture = load(texture_path) as Texture2D
			var alpha_range: Array = source_surface.get("alpha_range", [255, 255])
			if int(alpha_range[0]) < 128:
				if str(source_surface["texture"]).begins_with("FX_"):
					material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA
				else:
					material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA_SCISSOR
					material.alpha_scissor_threshold = 0.35
		mesh.surface_set_material(0, material)
		meshes.append(mesh)
	return meshes


func _build_navigation_grid() -> void:
	navigation_grid = AStarGrid2D.new()
	var width: int = int(round((WALKABLE_FLOOR_MAX_X - WALKABLE_FLOOR_MIN_X) / NAVIGATION_CELL_SIZE)) + 1
	var depth: int = int(round((WALKABLE_FLOOR_MAX_Z - WALKABLE_FLOOR_MIN_Z) / NAVIGATION_CELL_SIZE)) + 1
	navigation_grid.region = Rect2i(Vector2i.ZERO, Vector2i(width, depth))
	navigation_grid.cell_size = Vector2(NAVIGATION_CELL_SIZE, NAVIGATION_CELL_SIZE)
	navigation_grid.diagonal_mode = AStarGrid2D.DIAGONAL_MODE_ONLY_IF_NO_OBSTACLES
	navigation_grid.update()
	var blocked_count: int = 0
	for grid_z: int in range(depth):
		for grid_x: int in range(width):
			var point: Vector2 = Vector2(WALKABLE_FLOOR_MIN_X + float(grid_x) * NAVIGATION_CELL_SIZE,
				WALKABLE_FLOOR_MIN_Z + float(grid_z) * NAVIGATION_CELL_SIZE)
			var blocked: bool = false
			for obstacle: Vector3 in navigation_obstacles:
				if point.distance_to(Vector2(obstacle.x, obstacle.y)) <= obstacle.z + 0.28:
					blocked = true
					break
			if blocked:
				navigation_grid.set_point_solid(Vector2i(grid_x, grid_z), true)
				blocked_count += 1
	print("DWARF_NAV_READY size=%dx%d obstacles=%d blocked=%d" % [width, depth,
		navigation_obstacles.size(), blocked_count])


func _local_to_navigation_id(local_position: Vector3) -> Vector2i:
	var grid_x: int = int(round((local_position.x - WALKABLE_FLOOR_MIN_X) / NAVIGATION_CELL_SIZE))
	var grid_z: int = int(round((local_position.z - WALKABLE_FLOOR_MIN_Z) / NAVIGATION_CELL_SIZE))
	return Vector2i(clampi(grid_x, 0, navigation_grid.region.size.x - 1),
		clampi(grid_z, 0, navigation_grid.region.size.y - 1))


func _navigation_id_to_local(grid_id: Vector2i) -> Vector3:
	return Vector3(WALKABLE_FLOOR_MIN_X + float(grid_id.x) * NAVIGATION_CELL_SIZE,
		WALKABLE_FLOOR_Y, WALKABLE_FLOOR_MIN_Z + float(grid_id.y) * NAVIGATION_CELL_SIZE)


func _nearest_walkable_id(origin: Vector2i) -> Variant:
	if not navigation_grid.is_point_solid(origin):
		return origin
	for radius: int in range(1, 7):
		var best: Vector2i = Vector2i(-1, -1)
		var best_distance: float = INF
		for z_offset: int in range(-radius, radius + 1):
			for x_offset: int in range(-radius, radius + 1):
				if absi(x_offset) != radius and absi(z_offset) != radius:
					continue
				var candidate: Vector2i = origin + Vector2i(x_offset, z_offset)
				if not navigation_grid.region.has_point(candidate) or navigation_grid.is_point_solid(candidate):
					continue
				var candidate_distance: float = Vector2(candidate).distance_to(Vector2(origin))
				if candidate_distance < best_distance:
					best = candidate
					best_distance = candidate_distance
		if best.x >= 0:
			return best
	return null


func _navigation_path(from_local: Vector3, target_local: Vector3) -> Array[Vector3]:
	var result: Array[Vector3] = []
	if navigation_grid == null:
		return result
	var start_variant: Variant = _nearest_walkable_id(_local_to_navigation_id(from_local))
	var target_variant: Variant = _nearest_walkable_id(_local_to_navigation_id(target_local))
	if not start_variant is Vector2i or not target_variant is Vector2i:
		return result
	var ids: Array[Vector2i] = navigation_grid.get_id_path(start_variant, target_variant, false)
	for grid_id: Vector2i in ids:
		result.append(_navigation_id_to_local(grid_id))
	return result


func _add_template_light(parent: Node3D, placement_class: String) -> void:
	var light: OmniLight3D = OmniLight3D.new()
	var light_offset: Vector3 = Vector3(0.0, 0.5, 0.0)
	light.light_color = Color(0.6, 0.6, 0.5)
	light.omni_range = 3.0
	light.light_energy = 1.2
	if placement_class == "Misc_Light":
		light_offset = Vector3(0.0, 0.5, 1.0)
		light.light_color = Color(0.9, 0.9, 0.8)
		light.omni_range = 6.0
		light.light_energy = 1.4
	else:
		var suffix: int = "abcdef".find(placement_class.right(1))
		light.omni_range = [2.0, 3.0, 4.0, 5.0, 6.0, 8.0][maxi(0, suffix)]
		light.light_color = Color(0.7, 0.7, 0.6) if suffix >= 4 else Color(0.6, 0.6, 0.5)
	light.position = light_offset
	light.shadow_enabled = false
	parent.add_child(light)


func _index_open_air(data: Dictionary) -> void:
	# Recessed flat faces belong to the exposed chamber or tunnel back wall.
	for cell: Dictionary in data.cells:
		var parts: Array = data.meshes[str(int(cell.block))]
		if parts.size() == 1 and int(parts[0].part) == 0:
			var vertices: Array = parts[0].vertices
			var recessed := not vertices.is_empty()
			for i in range(2, vertices.size(), 5):
				if float(vertices[i]) != float(vertices[2]) or float(vertices[i]) >= 14.5:
					recessed = false
					break
			if recessed:
				open_air[Vector2i(int(cell.x), int(cell.y))] = true


func _build_geometry(data: Dictionary) -> void:
	var tools: Array[SurfaceTool] = []
	var materials: Array[StandardMaterial3D] = []
	for variant in range(15):
		var material: StandardMaterial3D = StandardMaterial3D.new()
		material.albedo_texture = load("res://textures/ground/Gnd_B%02d.tga" % (variant + 1)) as Texture2D # lint:ignore missing_resource -- formatted path, all 15 files are exported together
		material.roughness = 1.0
		material.texture_filter = BaseMaterial3D.TEXTURE_FILTER_LINEAR_WITH_MIPMAPS_ANISOTROPIC
		material.cull_mode = BaseMaterial3D.CULL_DISABLED if terrain_double_sided else (BaseMaterial3D.CULL_FRONT if terrain_cull_front else BaseMaterial3D.CULL_BACK)
		materials.append(material)
		for part in range(3):
			var surface: SurfaceTool = SurfaceTool.new()
			surface.begin(Mesh.PRIMITIVE_TRIANGLES)
			tools.append(surface)
	var meshes: Dictionary = data["meshes"]
	var cells: Array = data["cells"]
	var normals: Array = data["normals"]
	for entry: Dictionary in cells:
		if not terrain_flag_filter.is_empty() and not terrain_flag_filter.has(str(int(entry["flags"]))):
			continue
		var variant_index: int = clampi(int(entry.get("ground_variant", 1)) - 1, 0, 14)
		var block_parts: Array = meshes[str(int(entry["block"]))]
		for part: Dictionary in block_parts:
			var values: Array = part["vertices"]
			var indices: Array = part["indices"]
			var normal_indices: Array = part["attributes"]
			var surface: SurfaceTool = tools[variant_index * 3 + int(part["part"])]
			for triangle_start in range(0, indices.size(), 3):
				var triangle_points: Array[Vector3] = []
				for corner in range(3):
					var offset: int = int(indices[triangle_start + corner]) * 5
					# BDB corners encode depth as (game_z + 14) / 2.
					# PMP row is vertical, like the Tcl yoffset, not depth.
					triangle_points.append(Vector3(float(values[offset]) + float(entry["x"]),
						-(float(values[offset + 1]) + float(entry["y"])),
						BDB_DEPTH_SCALE * float(values[offset + 2]) + BDB_DEPTH_OFFSET))
				for corner in range(3):
					var vertex_index: int = int(indices[triangle_start + corner])
					var offset: int = vertex_index * 5
					var source_normal: Array = normals[int(normal_indices[vertex_index])]
					# Inverse transpose for unpacking Z; the outer renderer-space
					# transform restores the normal from sphere.dat.
					surface.set_normal(Vector3(float(source_normal[0]), -float(source_normal[1]),
						float(source_normal[2]) / BDB_DEPTH_SCALE).normalized())
					surface.set_uv(Vector2(float(values[offset + 3]), float(values[offset + 4])))
					surface.add_vertex(triangle_points[corner])
			triangle_count += int(indices.size() / 3.0)
	for variant in range(15):
		for part in range(3):
			var tool_index: int = variant * 3 + part
			var terrain_mesh: ArrayMesh = tools[tool_index].commit()
			if terrain_mesh.get_surface_count() == 0:
				continue
			terrain_mesh.surface_set_material(0, materials[variant])
			var instance: MeshInstance3D = MeshInstance3D.new()
			instance.name = "NativeTerrainB%02dPart%d" % [variant + 1, part]
			instance.mesh = terrain_mesh
			instance.visible = include_terrain and (terrain_part_filter.is_empty() or terrain_part_filter.has(str(part)))
			scene_root.add_child(instance)


func _build_camera_and_light() -> void:
	camera = Camera3D.new()
	camera.name = "ReferenceCamera"
	camera.current = true
	camera.projection = Camera3D.PROJECTION_ORTHOGONAL if use_orthographic_camera else Camera3D.PROJECTION_PERSPECTIVE
	camera.fov = 38.0
	camera.near = 0.05
	camera.far = 250.0
	add_child(camera)
	var environment: Environment = Environment.new()
	environment.background_mode = Environment.BG_COLOR
	environment.background_color = Color(0.035, 0.045, 0.055)
	environment.ambient_light_source = Environment.AMBIENT_SOURCE_COLOR
	environment.ambient_light_color = Color(0.85, 0.9, 1.0)
	environment.ambient_light_energy = 0.45
	var world_environment: WorldEnvironment = WorldEnvironment.new()
	world_environment.environment = environment
	add_child(world_environment)
	var light: DirectionalLight3D = DirectionalLight3D.new()
	light.rotation_degrees = Vector3(-32.0, -25.0, 0.0)
	light.light_energy = 1.1
	add_child(light)
	var fill: OmniLight3D = OmniLight3D.new()
	fill.position = Vector3(12.0, 12.0, -5.0)
	fill.omni_range = 35.0
	fill.light_energy = 1.0
	add_child(fill)


func _build_caption() -> void:
	var layer: CanvasLayer = CanvasLayer.new()
	layer.name = "HUDLayer"
	add_child(layer)
	status = Label.new()
	status.name = "Status"
	status.position = Vector2(18.0, 14.0)
	status.text = "Diggles demo_start\n1 finger: rotate | 2 fingers: pan/zoom | Tap dwarf to move\nT corridor mode (green) | C cave size (%d)\n%d objects / %d models / %d textures" % [selected_cave_brush, placement_count, model_count, texture_count]
	status.add_theme_color_override("font_color", Color.WHITE)
	status.add_theme_color_override("font_shadow_color", Color.BLACK)
	status.add_theme_constant_override("shadow_offset_x", 1)
	status.add_theme_constant_override("shadow_offset_y", 1)
	layer.add_child(status)
	tool_cursor = Label.new()
	tool_cursor.mouse_filter = Control.MOUSE_FILTER_IGNORE
	tool_cursor.visible = false
	layer.add_child(tool_cursor)
	dig_toolbar = HBoxContainer.new()
	layer.add_child(dig_toolbar)
	dig_toolbar.set_anchors_and_offsets_preset(Control.PRESET_CENTER_BOTTOM)
	dig_toolbar.grow_horizontal = Control.GROW_DIRECTION_BOTH
	dig_toolbar.grow_vertical = Control.GROW_DIRECTION_BEGIN
	var group := ButtonGroup.new()
	for tool: String in ["Выбор", "Коридор", "Пещера 1", "Пещера 2", "Пещера 3", "Пещера 4", "Ластик"]:
		var button := Button.new()
		button.text = tool
		button.toggle_mode = true
		button.button_group = group
		button.custom_minimum_size.y = 44
		button.focus_mode = Control.FOCUS_NONE
		button.button_pressed = tool == "Выбор"
		button.pressed.connect(_choose_tool.bind(tool))
		dig_toolbar.add_child(button)


func _choose_tool(tool: String) -> void:
	dig_tool = tool
	corridor_mode = tool in ["Коридор", "Ластик"]
	corridor_last_cell = null
	if tool.begins_with("Пещера"):
		selected_cave_brush = int(tool.right(1))
	for child: Button in dig_toolbar.get_children():
		child.set_pressed_no_signal(child.text == tool)
	status.text = tool
	tool_cursor.text = tool
	tool_cursor.position = get_viewport().get_mouse_position() + Vector2(12, 12)
	tool_cursor.visible = tool != "Выбор"


func _pan_camera(relative: Vector2) -> void:
	var pan_scale: float = distance * 0.0017
	focus.x -= relative.x * pan_scale
	focus.y += relative.y * pan_scale
	_update_camera()


func _update_camera() -> void:
	var offset: Vector3 = Vector3(sin(yaw) * cos(pitch), sin(pitch), cos(yaw) * cos(pitch)) * distance
	camera.position = focus + offset
	camera.look_at(focus)
	if use_orthographic_camera:
		camera.size = distance * 0.8


func _process(_delta: float) -> void:
	_update_dwarf_locomotion(_delta)
	_update_dwarf_idle_animations(_delta)
	var camera_move: Vector2 = Input.get_vector("move_left", "move_right", "move_up", "move_down")
	if camera_move != Vector2.ZERO:
		focus.x += camera_move.x * _delta * 9.0
		focus.y -= camera_move.y * _delta * 9.0
		_update_camera()
	if automatic_cave_demo and not native_active_caves.is_empty():
		cave_dig_timer += _delta
		if cave_dig_timer >= 0.035:
			cave_dig_timer = 0.0
			for cave_index: int in range(native_active_caves.size()):
				native_apply_next_cave_strike(cave_index)
			native_finish_completed_caves()
	var touch_count: int = touch_points.size()
	if not gesture_dirty or touch_count != 2:
		return
	var current_centroid: Vector2 = _current_touch_centroid()
	var current_span: float = _current_pinch_span()
	if gesture_baseline_ready:
		var span_delta: float = current_span - gesture_span
		var centroid_delta: Vector2 = current_centroid - gesture_centroid
		var centroid_distance: float = centroid_delta.length()
		if two_finger_mode == &"pending":
			if absf(span_delta) >= TWO_FINGER_DECISION_PIXELS \
					and absf(span_delta) > centroid_distance * TWO_FINGER_DOMINANCE:
				two_finger_mode = &"zoom"
			elif centroid_distance >= TWO_FINGER_DECISION_PIXELS \
					and centroid_distance > absf(span_delta) * TWO_FINGER_DOMINANCE:
				two_finger_mode = &"pan"
		if two_finger_mode == &"zoom" and current_span > 0.0:
			distance = clampf(distance * gesture_span / current_span, 10.0, 65.0)
		elif two_finger_mode == &"pan":
			_pan_camera(centroid_delta)
		if two_finger_mode != &"pending":
			gesture_centroid = current_centroid
			gesture_span = current_span
			_update_camera()
	gesture_dirty = false


func _input(event: InputEvent) -> void:
	if dig_toolbar == null:
		return
	if event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_LEFT:
		if event.pressed:
			toolbar_mouse_down = dig_toolbar.get_global_rect().has_point(event.position)
		if toolbar_mouse_down:
			if not event.pressed:
				toolbar_mouse_down = false
			return
	if event is InputEventMouseMotion:
		tool_cursor.position = event.position + Vector2(12, 12)
	if event is InputEventMouseMotion and toolbar_mouse_down:
		return
	if event is InputEventScreenTouch:
		if event.pressed and dig_toolbar.get_global_rect().has_point(event.position):
			toolbar_touch_ids[event.index] = true
		if toolbar_touch_ids.has(event.index):
			if not event.pressed:
				toolbar_touch_ids.erase(event.index)
			return
	if event is InputEventScreenDrag and toolbar_touch_ids.has(event.index):
		return
	if event is InputEventMouseMotion and event.button_mask & MOUSE_BUTTON_MASK_LEFT:
		if corridor_mode:
			if mouse_pressed_dwarf:
				return
			var drag_cell: Variant = _screen_to_terrain_cell(event.position)
			if drag_cell is Vector2i:
				_mark_corridor_from(drag_cell, _terrain_point(event.position))
			return
		if event.position.distance_to(mouse_press_position) > 8.0:
			mouse_dragged = true
		yaw = clampf(yaw - event.relative.x * 0.006, camera_yaw_base - 0.75, camera_yaw_base + 0.75)
		pitch = clampf(pitch + event.relative.y * 0.006, -0.5, 0.6)
	elif event is InputEventMouseButton:
		if event.button_index == MOUSE_BUTTON_LEFT:
			if event.pressed:
				mouse_press_position = event.position
				mouse_dragged = false
				mouse_pressed_dwarf = false
				var clicked_dwarf: Node3D = _dwarf_at_screen(event.position)
				if clicked_dwarf != null:
					_select_dwarf(clicked_dwarf)
					mouse_pressed_dwarf = true
				elif corridor_mode:
					corridor_last_cell = null
					var press_cell: Variant = _screen_to_terrain_cell(event.position)
					if press_cell is Vector2i:
						_mark_corridor_from(press_cell, _terrain_point(event.position))
			elif mouse_pressed_dwarf:
				mouse_pressed_dwarf = false
			elif not mouse_dragged and mouse_press_position.distance_to(event.position) <= 8.0:
				if not corridor_mode:
					_handle_tap(event.position)
			else:
				corridor_last_cell = null
		elif event.pressed and event.button_index == MOUSE_BUTTON_WHEEL_UP:
			distance = maxf(10.0, distance * 0.9)
		elif event.pressed and event.button_index == MOUSE_BUTTON_WHEEL_DOWN:
			distance = minf(65.0, distance / 0.9)
	elif event is InputEventScreenTouch:
		if event.pressed:
			touch_points[event.index] = event.position
			touch_start_positions[event.index] = event.position
			if touch_points.size() == 2:
				gesture_had_multiple_touches = true
				gesture_centroid = _current_touch_centroid()
				gesture_span = _current_pinch_span()
				gesture_baseline_ready = true
				two_finger_mode = &"pending"
			elif touch_points.size() > 2:
				gesture_had_multiple_touches = true
				gesture_baseline_ready = false
				two_finger_mode = &"none"
		else:
			var touch_start: Vector2 = touch_start_positions.get(event.index, event.position)
			var was_multi_touch: bool = gesture_had_multiple_touches
			touch_points.erase(event.index)
			touch_start_positions.erase(event.index)
			if touch_points.is_empty():
				gesture_had_multiple_touches = false
				two_finger_mode = &"none"
			if not was_multi_touch and touch_start.distance_to(event.position) <= 18.0:
				_handle_tap(event.position)
		if touch_points.size() != 2:
			gesture_baseline_ready = false
			gesture_span = 0.0
		gesture_dirty = false
	elif event is InputEventScreenDrag:
		touch_points[event.index] = event.position
		if touch_points.size() == 2:
			gesture_dirty = true
		elif touch_points.size() == 1 and not gesture_had_multiple_touches:
			yaw = clampf(yaw - event.relative.x * 0.006, camera_yaw_base - 0.75, camera_yaw_base + 0.75)
			pitch = clampf(pitch + event.relative.y * 0.006, -0.5, 0.6)
	elif event is InputEventKey and event.pressed and not event.echo:
		if event.physical_keycode == KEY_R:
			yaw = camera_yaw_base
			pitch = 0.16
			distance = 25.0
		elif event.physical_keycode == KEY_O:
			camera.projection = Camera3D.PROJECTION_ORTHOGONAL if camera.projection == Camera3D.PROJECTION_PERSPECTIVE else Camera3D.PROJECTION_PERSPECTIVE
		elif event.physical_keycode == KEY_C:
			_choose_tool("Пещера %d" % (selected_cave_brush % 4 + 1))
			status.text = "Cave size %d selected; tap terrain to place" % selected_cave_brush
		elif event.physical_keycode == KEY_T:
			_choose_tool("Выбор" if corridor_mode else "Коридор")
			corridor_last_cell = null
			status.text = "Corridor mode ON: tap points to draw green tunnel" if corridor_mode else "Corridor mode OFF"
	_update_camera()


func _current_pinch_span() -> float:
	var positions: Array[Vector2] = touch_points.values()
	if positions.size() < 2:
		return 0.0
	return positions[0].distance_to(positions[1])


func _current_touch_centroid() -> Vector2:
	var positions: Array[Vector2] = touch_points.values()
	if positions.size() < 2:
		return Vector2.ZERO
	var centroid: Vector2 = Vector2.ZERO
	for touch_position: Vector2 in positions:
		centroid += touch_position
	return centroid / float(positions.size())


func _handle_tap(screen_position: Vector2) -> void:
	var nearest: Node3D = _dwarf_at_screen(screen_position)
	if nearest != null:
		_select_dwarf(nearest)
	elif selected_dwarf != null and not corridor_mode and not dig_tool.begins_with("Пещера"):
		_command_selected_dwarf(screen_position)
	else:
		var cave_cell: Variant = _screen_to_terrain_cell(screen_position)
		if cave_cell is Vector2i:
			if corridor_mode:
				_mark_corridor_from(cave_cell, _terrain_point(screen_position))
				return
			if not dig_tool.begins_with("Пещера"):
				return
			if open_air.has(cave_cell):
				return
			var cursor: Vector2i = cave_cell + Vector2i(16, 32)
			for sample in native_cave_brush_cells(selected_cave_brush, cursor.x, cursor.y):
				var point := Vector2i(sample.x, sample.z)
				if not open_air.has(point) and native_terrain_cells.has(point) and not native_cave_cell_state_allows_dig(point):
					_flash_blocked(Vector2(point), Vector2.ONE)
					return
			var started: bool = native_begin_cave(0, selected_cave_brush, cursor.x, cursor.y)
			status.text = "Пещера %d размечена; ожидает исполнителя" % selected_cave_brush if started else "Здесь нельзя разметить пещеру"
			print("CAVE_TAP cell=%s started=%s" % [str(cave_cell), str(started)])
			return


func _dwarf_at_screen(screen_position: Vector2) -> Node3D:
	return _object_at_screen(screen_position, dwarf_nodes)


func _object_at_screen(screen_position: Vector2, candidates: Array[Node3D]) -> Node3D:
	var nearest: Node3D = null
	var nearest_distance: float = INF
	for dwarf: Node3D in candidates:
		var bounds: Rect2 = Rect2()
		var has_bounds: bool = false
		for node: Node in dwarf.find_children("*", "MeshInstance3D", true, false):
			var mesh_instance: MeshInstance3D = node as MeshInstance3D
			if not mesh_instance.is_visible_in_tree():
				continue
			var box: AABB = mesh_instance.get_aabb()
			for corner: int in range(8):
				var local_point: Vector3 = box.position + Vector3(
					box.size.x if (corner & 1) else 0.0,
					box.size.y if (corner & 2) else 0.0,
					box.size.z if (corner & 4) else 0.0)
				var world_point: Vector3 = mesh_instance.global_transform * local_point
				if camera.is_position_behind(world_point):
					continue
				var projected: Vector2 = camera.unproject_position(world_point)
				if not has_bounds:
					bounds = Rect2(projected, Vector2.ZERO)
					has_bounds = true
				else:
					bounds = bounds.expand(projected)
		if not has_bounds or not bounds.grow(12.0).has_point(screen_position):
			continue
		var screen_distance: float = bounds.get_center().distance_to(screen_position)
		if screen_distance < nearest_distance:
			nearest = dwarf
			nearest_distance = screen_distance
	return nearest


func _build_corridor_preview_root() -> void:
	corridor_preview_root = Node3D.new()
	corridor_preview_root.name = "NativeCorridorPreview"
	scene_root.add_child(corridor_preview_root)


func _mark_corridor_from(cell: Vector2i, exact: Variant = null) -> void:
	if open_air.has(cell) and dig_tool != "Ластик":
		corridor_last_cell = null
		return
	if not native_terrain_cells.has(cell):
		status.text = "Corridor rejected outside terrain"
		return
	var point_xy: Vector2 = exact if exact is Vector2 else Vector2(cell)
	var grid_cell := Vector2i(floori(point_xy.x / CORRIDOR_GRID_STEP), floori((point_xy.y - GRID_Y_OFFSET) / CORRIDOR_GRID_STEP))
	if corridor_last_cell is Vector2i:
		var previous: Vector2i = corridor_last_cell
		var steps: int = maxi(absi(grid_cell.x - previous.x), absi(grid_cell.y - previous.y))
		for step: int in range(steps + 1):
			var amount: float = float(step) / float(maxi(steps, 1))
			var point: Vector2i = Vector2i(roundi(lerpf(float(previous.x), float(grid_cell.x), amount)),
				roundi(lerpf(float(previous.y), float(grid_cell.y), amount)))
			_add_corridor_stamp(point)
	else:
		_add_corridor_stamp(grid_cell)
	corridor_last_cell = grid_cell
	status.text = "Green corridor cells: %d" % corridor_marked_cells.size()


func _add_corridor_stamp(cell: Vector2i) -> void:
	_add_corridor_marker(cell)


func _add_corridor_marker(cell: Vector2i) -> void:
	if dig_tool == "Ластик":
		for index in range(native_active_caves.size() - 1, -1, -1):
			var record: Dictionary = native_active_caves[index]
			for sample: Vector3i in record["cells"]:
				var tile := Vector2i(floori(sample.x / CORRIDOR_GRID_STEP), floori((sample.z - GRID_Y_OFFSET) / CORRIDOR_GRID_STEP))
				if tile == cell:
					for mark: Vector3i in record["cells"]:
						native_clear_cave_mark(record.owner_id, Vector2i(mark.x, mark.z), record.layer)
					native_active_caves.remove_at(index)
					break
		if corridor_marker_nodes.has(cell):
			corridor_marker_nodes[cell].queue_free()
			corridor_marker_nodes.erase(cell)
			corridor_marked_cells.erase(cell)
			for offset: Vector2i in [Vector2i.LEFT, Vector2i.RIGHT, Vector2i.UP, Vector2i.DOWN]:
				_update_corridor_corners(cell + offset)
		return
	if corridor_marked_cells.has(cell):
		return
	var origin_x: float = float(cell.x) * CORRIDOR_GRID_STEP
	var origin_y: float = float(cell.y) * CORRIDOR_GRID_STEP + GRID_Y_OFFSET
	var tile_width: float = minf(CORRIDOR_GRID_STEP, float(native_terrain_width) - origin_x)
	var tile_height: float = minf(CORRIDOR_GRID_STEP, float(native_terrain_height) - origin_y)
	if tile_width <= 0.0 or tile_height <= 0.0:
		return
	var center_x: float = origin_x + tile_width * 0.5
	var center_y: float = origin_y + tile_height * 0.5
	if not native_terrain_cells.has(Vector2i(floori(center_x), floori(center_y))):
		return
	if (cell.x & 1) == 1 and (cell.y & 1) == 0:
		return
	if open_air.has(Vector2i(floori(center_x), floori(center_y))):
		return
	for y in range(ceili(origin_y), ceili(origin_y + tile_height)):
		for x in range(ceili(origin_x), ceili(origin_x + tile_width)):
			if not open_air.has(Vector2i(x, y)) and not native_cave_cell_state_allows_dig(Vector2i(x, y)):
				_flash_blocked(Vector2(center_x, center_y), Vector2(tile_width, tile_height))
				return
	corridor_marked_cells[cell] = true
	var marker: MeshInstance3D = MeshInstance3D.new()
	marker.name = "CorridorCell_%d_%d" % [cell.x, cell.y]
	var cube := QuadMesh.new()
	cube.size = Vector2(tile_width, tile_height)
	marker.mesh = cube
	if corridor_shader == null:
		corridor_shader = Shader.new()
		corridor_shader.code = """shader_type spatial;
render_mode unshaded, cull_disabled, blend_mix, depth_draw_never;
uniform vec4 rounded_corners = vec4(1.0);
uniform vec4 exposed_edges = vec4(1.0);
uniform vec2 tile_size = vec2(2.5);
varying vec2 tile_position;
void vertex() {
    tile_position = VERTEX.xy / tile_size;
    vec2 world = (MODEL_MATRIX * vec4(VERTEX, 1.0)).xy;
    VERTEX.xy += 0.065 * vec2(sin(0.76 * world.y + TIME * 0.82), sin(0.70 * world.x + TIME * 0.72));
}
void fragment() {
    vec2 p = tile_position;
    float corner = 0.0;
    if (p.x < -0.34 && p.y > 0.34) corner = rounded_corners.x;
    if (p.x > 0.34 && p.y > 0.34) corner = rounded_corners.y;
    if (p.x > 0.34 && p.y < -0.34) corner = rounded_corners.z;
    if (p.x < -0.34 && p.y < -0.34) corner = rounded_corners.w;
    float alpha = 0.28;
    if (corner > 0.5) {
        vec2 center = vec2(sign(p.x) * 0.34, sign(p.y) * 0.34);
        alpha *= 1.0 - smoothstep(0.15, 0.17, length(p - center));
    }
    float border = 0.0;
    border = max(border, exposed_edges.x * smoothstep(0.40, 0.49, -p.x));
    border = max(border, exposed_edges.y * smoothstep(0.40, 0.49, p.x));
    border = max(border, exposed_edges.z * smoothstep(0.40, 0.49, p.y));
    border = max(border, exposed_edges.w * smoothstep(0.40, 0.49, -p.y));
    ALBEDO = mix(vec3(0.22, 0.44, 0.15), vec3(0.10, 0.23, 0.07), border);
    alpha *= mix(1.0, 1.65, border);
    ALPHA = alpha;
}"""
	var material: ShaderMaterial = ShaderMaterial.new()
	material.shader = corridor_shader
	material.set_shader_parameter("tile_size", Vector2(tile_width, tile_height))
	marker.material_override = material
	marker.position = Vector3(center_x, -center_y, DIG_MARK_DEPTH)
	corridor_preview_root.add_child(marker)
	corridor_marker_nodes[cell] = marker
	for offset: Vector2i in [Vector2i.ZERO, Vector2i.LEFT, Vector2i.RIGHT, Vector2i.UP, Vector2i.DOWN]:
		_update_corridor_corners(cell + offset)


func _flash_blocked(center: Vector2, size: Vector2) -> void:
	var marker := MeshInstance3D.new()
	var quad := QuadMesh.new()
	quad.size = size
	marker.mesh = quad
	var mat := StandardMaterial3D.new()
	mat.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
	mat.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA
	mat.albedo_color = Color(0.85, 0.12, 0.10, 0.42)
	marker.material_override = mat
	marker.position = Vector3(center.x, -center.y, DIG_MARK_DEPTH + 0.02)
	corridor_preview_root.add_child(marker)
	get_tree().create_timer(0.35).timeout.connect(marker.queue_free)


func _update_corridor_corners(cell: Vector2i) -> void:
	if not corridor_marker_nodes.has(cell):
		return
	var marker: MeshInstance3D = corridor_marker_nodes[cell]
	var material: ShaderMaterial = marker.material_override as ShaderMaterial
	if material == null:
		return
	var left_open: bool = not corridor_marked_cells.has(cell + Vector2i.LEFT)
	var right_open: bool = not corridor_marked_cells.has(cell + Vector2i.RIGHT)
	var top_open: bool = not corridor_marked_cells.has(cell + Vector2i.UP)
	var bottom_open: bool = not corridor_marked_cells.has(cell + Vector2i.DOWN)
	material.set_shader_parameter("rounded_corners", Vector4(
		float(left_open and top_open), float(right_open and top_open),
		float(right_open and bottom_open), float(left_open and bottom_open)))
	material.set_shader_parameter("exposed_edges", Vector4(
		float(left_open), float(right_open), float(top_open), float(bottom_open)))


func _screen_to_terrain_cell(screen_position: Vector2) -> Variant:
	var point: Variant = _terrain_point(screen_position)
	if point is Vector2:
		return Vector2i(point.floor())
	return null


func _terrain_point(screen_position: Vector2) -> Variant:
	var ray_origin: Vector3 = camera.project_ray_origin(screen_position)
	var ray_direction: Vector3 = camera.project_ray_normal(screen_position)
	var local_origin: Vector3 = scene_root.to_local(ray_origin)
	var local_direction: Vector3 = scene_root.to_local(ray_origin + ray_direction) - local_origin
	var intersection: Variant = Plane(Vector3(0.0, 0.0, 1.0), DIG_MARK_DEPTH).intersects_ray(local_origin, local_direction)
	if not intersection is Vector3:
		return null
	return Vector2(intersection.x, -intersection.y)


func _select_dwarf(dwarf: Node3D) -> void:
	if selected_dwarf != null and selected_dwarf != dwarf:
		_set_dwarf_outline(selected_dwarf, false)
	selected_dwarf = dwarf
	_set_dwarf_outline(dwarf, true)
	print("DWARF_SELECTED " + dwarf.name)
	if status != null:
		status.text = "Selected %s | tap a destination" % dwarf.name


func _clear_dwarf_selection() -> void:
	if selected_dwarf == null:
		return
	_set_dwarf_outline(selected_dwarf, false)
	selected_dwarf = null
	if status != null:
		status.text = "Selection cleared | C cycles cave size; tap terrain to dig"


func _set_dwarf_outline(dwarf: Node3D, enabled: bool) -> void:
	if selection_outline_material == null:
		var shader: Shader = Shader.new()
		shader.code = """shader_type spatial;
render_mode unshaded, cull_front;
uniform float outline_width = 0.018;
uniform vec4 outline_color : source_color = vec4(1.0, 1.0, 1.0, 1.0);
void vertex() { VERTEX += NORMAL * outline_width; }
void fragment() { ALBEDO = outline_color.rgb; EMISSION = outline_color.rgb * 0.35; }
"""
		selection_outline_material = ShaderMaterial.new()
		selection_outline_material.shader = shader
	_set_outline_recursive(dwarf, enabled)


func _set_outline_recursive(node: Node, enabled: bool) -> void:
	var mesh_instance: MeshInstance3D = node as MeshInstance3D
	if mesh_instance != null:
		mesh_instance.material_overlay = selection_outline_material if enabled else null
	for child: Node in node.get_children():
		_set_outline_recursive(child, enabled)


func _command_selected_dwarf(screen_position: Vector2) -> void:
	barrel_goal = null
	var barrel := _object_at_screen(screen_position, barrels)
	if barrel != null:
		var target: Variant = _resolve_walk_target(barrel.global_position)
		if target is Vector3 and target.distance_to(barrel.position) <= 1.8:
			if selected_dwarf.position.distance_to(barrel.position) <= 1.5:
				_open_barrel(barrel)
			else:
				_start_dwarf_walk(selected_dwarf, target)
				if moving_dwarf == selected_dwarf and movement_target.is_equal_approx(target):
					barrel_goal = barrel
		return
	var ray_origin: Vector3 = camera.project_ray_origin(screen_position)
	var ray_direction: Vector3 = camera.project_ray_normal(screen_position)
	var floor_global_y: float = scene_root.to_global(Vector3(0.0, WALKABLE_FLOOR_Y, 0.0)).y
	var movement_plane: Plane = Plane(Vector3.UP, floor_global_y)
	var intersection: Variant = movement_plane.intersects_ray(ray_origin, ray_direction)
	if not intersection is Vector3:
		return
	var resolved: Variant = _resolve_walk_target(intersection)
	if not resolved is Vector3:
		print("DWARF_MOVE_REJECT target outside walkable floor")
		return
	_start_dwarf_walk(selected_dwarf, resolved)


func _resolve_walk_target(world_intersection: Vector3) -> Variant:
	var local_target: Vector3 = scene_root.to_local(world_intersection)
	if local_target.x < WALKABLE_FLOOR_MIN_X or local_target.x > WALKABLE_FLOOR_MAX_X:
		return null
	if local_target.z < WALKABLE_FLOOR_MIN_Z or local_target.z > WALKABLE_FLOOR_MAX_Z:
		return null
	local_target.y = WALKABLE_FLOOR_Y
	var target_id: Variant = _nearest_walkable_id(_local_to_navigation_id(local_target))
	if not target_id is Vector2i:
		return null
	return _navigation_id_to_local(target_id)


func _start_dwarf_walk(dwarf: Node3D, local_target: Vector3) -> void:
	var path: Array[Vector3] = _navigation_path(dwarf.position, local_target)
	if path.size() < 2:
		print("DWARF_MOVE_REJECT no path")
		return
	if moving_dwarf != null and moving_dwarf != dwarf:
		_show_dwarf_default(moving_dwarf)
	moving_dwarf = dwarf
	movement_path = path
	movement_path_index = 1
	movement_target = path[path.size() - 1]
	fast_walk = not is_inf(last_walk_target.x) and Vector2(last_walk_target.x, last_walk_target.z).distance_to(
		Vector2(movement_target.x, movement_target.z)) < 3.0
	last_walk_target = movement_target
	var first_direction: Vector2 = Vector2(movement_path[1].x - dwarf.position.x,
		movement_path[1].z - dwarf.position.z).normalized()
	pending_heading = atan2(first_direction.x, first_direction.y)
	var current_heading: float = float(dwarf_headings.get(dwarf, 0.0))
	var turn_delta: float = wrapf(pending_heading - current_heading, -PI, PI)
	if absf(turn_delta) > 1.4:
		locomotion_state = &"drehen_ganz_links" if turn_delta > 0.0 else &"drehen_ganz"
	elif absf(turn_delta) > 0.2:
		locomotion_state = &"drehen_links" if turn_delta > 0.0 else &"drehen_rechts"
	else:
		locomotion_state = _walk_sequence(&"start")
	locomotion_elapsed = 0.0
	locomotion_frame = -1
	_show_dwarf_animation_frame(dwarf, locomotion_state, 0)
	print("DWARF_WALK_START %s target=%s nodes=%d speed=%.3f" % [dwarf.name,
		str(movement_target), movement_path.size(), _current_walk_speed()])


func _walk_sequence(stage: StringName) -> StringName:
	var prefix: String = "laufen_schnell_" if fast_walk else "gehen_"
	return StringName(prefix + String(stage))


func _current_walk_speed() -> float:
	return WALK_SPEED * RUN_SPEED_MULTIPLIER if fast_walk else WALK_SPEED


func _update_dwarf_locomotion(delta: float) -> void:
	if moving_dwarf == null:
		return
	locomotion_elapsed += delta
	var sequence_count: int = _dwarf_sequence_frame_count(moving_dwarf, locomotion_state)
	if sequence_count == 0:
		_advance_dwarf_along_path(delta)
		return
	var requested_frame: int = int(floor(locomotion_elapsed * WALK_ANIMATION_FPS))
	if String(locomotion_state).begins_with("drehen_") and requested_frame >= sequence_count:
		_set_dwarf_heading(moving_dwarf, pending_heading)
		locomotion_state = _walk_sequence(&"start")
		locomotion_elapsed = 0.0
		requested_frame = 0
		sequence_count = _dwarf_sequence_frame_count(moving_dwarf, locomotion_state)
	elif locomotion_state == _walk_sequence(&"start") and requested_frame >= sequence_count:
		locomotion_state = _walk_sequence(&"loop")
		locomotion_elapsed = 0.0
		requested_frame = 0
		sequence_count = _dwarf_sequence_frame_count(moving_dwarf, locomotion_state)
	elif locomotion_state == _walk_sequence(&"loop"):
		requested_frame %= sequence_count
	elif locomotion_state == _walk_sequence(&"end") and requested_frame >= sequence_count:
		_finish_dwarf_walk()
		return
	if locomotion_state == _walk_sequence(&"start") or locomotion_state == _walk_sequence(&"loop"):
		if _advance_dwarf_along_path(delta):
			locomotion_state = _walk_sequence(&"end")
			locomotion_elapsed = 0.0
			requested_frame = 0
	if requested_frame != locomotion_frame:
		locomotion_frame = requested_frame
		_show_dwarf_animation_frame(moving_dwarf, locomotion_state, requested_frame)


func _update_dwarf_idle_animations(delta: float) -> void:
	idle_animation_elapsed += delta
	for dwarf_index: int in range(dwarf_nodes.size()):
		var dwarf: Node3D = dwarf_nodes[dwarf_index]
		if dwarf == moving_dwarf:
			continue
		var sequence_name: StringName = &"stand_anim_a" if dwarf_index % 2 == 0 else &"stand_anim_b"
		var frame_count: int = _dwarf_sequence_frame_count(dwarf, sequence_name)
		if frame_count == 0:
			continue
		var frame_index: int = (int(floor(idle_animation_elapsed * IDLE_ANIMATION_FPS)) + dwarf_index * 3) % frame_count
		if int(dwarf_idle_frame_indices.get(dwarf, -1)) == frame_index:
			continue
		dwarf_idle_frame_indices[dwarf] = frame_index
		_show_dwarf_animation_frame(dwarf, sequence_name, frame_index)


func _advance_dwarf_along_path(delta: float) -> bool:
	if moving_dwarf == null or movement_path_index >= movement_path.size():
		return true
	var waypoint: Vector3 = movement_path[movement_path_index]
	var current_2d: Vector2 = Vector2(moving_dwarf.position.x, moving_dwarf.position.z)
	var target_2d: Vector2 = Vector2(waypoint.x, waypoint.z)
	var direction: Vector2 = current_2d.direction_to(target_2d)
	var step: float = _current_walk_speed() * delta
	var next_2d: Vector2 = current_2d.move_toward(target_2d, step)
	moving_dwarf.position = Vector3(next_2d.x, WALKABLE_FLOOR_Y, next_2d.y)
	if direction.length_squared() > 0.0:
		var segment_heading: float = atan2(direction.x, direction.y)
		var current_heading: float = float(dwarf_headings.get(moving_dwarf, 0.0))
		_set_dwarf_heading(moving_dwarf, lerp_angle(current_heading, segment_heading,
			clampf(delta * 8.0, 0.0, 1.0)))
	if next_2d.is_equal_approx(target_2d):
		movement_path_index += 1
		if movement_path_index >= movement_path.size():
			return true
	return false


func _set_dwarf_heading(dwarf: Node3D, heading: float) -> void:
	# scene_root packs logical depth by 0.5. Applying ordinary Node3D rotation
	# below that non-uniform parent scale stretches the model at oblique angles.
	# Pre-multiply the heading by the inverse packing basis so the final global
	# basis remains a pure rotation in render space.
	var render_to_logical: Basis = Basis(Vector3.RIGHT, Vector3.UP,
		Vector3(0.0, 0.0, 1.0 / render_depth_scale))
	dwarf.transform.basis = render_to_logical * Basis(Vector3.UP, heading)
	dwarf_headings[dwarf] = heading


func _dwarf_sequence_frame_count(dwarf: Node3D, sequence_name: StringName) -> int:
	if not dwarf_locomotion_visuals.has(dwarf):
		return 0
	var visuals: Dictionary = dwarf_locomotion_visuals[dwarf]
	var sequences: Dictionary = visuals["sequences"]
	if not sequences.has(String(sequence_name)):
		return 0
	var frames: Array = sequences[String(sequence_name)]
	return frames.size()


func _show_dwarf_animation_frame(dwarf: Node3D, sequence_name: StringName, frame_index: int) -> void:
	if not dwarf_locomotion_visuals.has(dwarf):
		return
	var visuals: Dictionary = dwarf_locomotion_visuals[dwarf]
	var defaults: Array = visuals["default"]
	for default_mesh: MeshInstance3D in defaults:
		default_mesh.visible = false
	var current: Variant = visuals.get("current")
	if current is Node3D:
		current.visible = false
	var sequences: Dictionary = visuals["sequences"]
	var sequence_key: String = String(sequence_name)
	if not sequences.has(sequence_key):
		return
	var frames: Array = sequences[sequence_key]
	if frames.is_empty():
		return
	var frame_root: Node3D = frames[clampi(frame_index, 0, frames.size() - 1)]
	frame_root.visible = true
	visuals["current"] = frame_root


func _show_dwarf_default(dwarf: Node3D) -> void:
	if not dwarf_locomotion_visuals.has(dwarf):
		return
	var visuals: Dictionary = dwarf_locomotion_visuals[dwarf]
	var current: Variant = visuals.get("current")
	if current is Node3D:
		current.visible = false
	for default_mesh: MeshInstance3D in visuals["default"]:
		default_mesh.visible = true
	visuals["current"] = null


func _open_barrel(barrel: Node3D) -> void:
	barrels.erase(barrel)
	for obstacle: Vector3 in navigation_obstacles:
		if Vector2(obstacle.x, obstacle.y).distance_to(Vector2(barrel.position.x, barrel.position.z)) < 0.01:
			navigation_obstacles.erase(obstacle)
			break
	barrel.queue_free()
	_build_navigation_grid()
	status.text = "Бочка открыта"


func _finish_dwarf_walk() -> void:
	var finished_dwarf: Node3D = moving_dwarf
	if is_instance_valid(barrel_goal) and finished_dwarf.position.distance_to(barrel_goal.position) <= 1.8:
		_open_barrel(barrel_goal)
	barrel_goal = null
	_show_dwarf_default(finished_dwarf)
	moving_dwarf = null
	movement_path.clear()
	movement_path_index = 0
	locomotion_state = &"idle"
	locomotion_elapsed = 0.0
	locomotion_frame = -1
	print("DWARF_WALK_RESULT %s result=4" % finished_dwarf.name)


func _capture_views(output_dir: String) -> void:
	DirAccess.make_dir_recursive_absolute(output_dir)
	var report: Dictionary = {"space": "native_renderer", "depth_scale": render_depth_scale,
		"depth_offset": RENDER_DEPTH_OFFSET, "nodes": [], "views": []}
	for child: Node in scene_root.get_children():
		var spatial: Node3D = child as Node3D
		if spatial == null:
			continue
		var record: Dictionary = {"name": spatial.name,
			"logical_position": _vector_array(spatial.position),
			"render_position": _vector_array(spatial.global_position)}
		var mesh_instance: MeshInstance3D = child as MeshInstance3D
		if mesh_instance != null:
			var bounds: AABB = mesh_instance.global_transform * mesh_instance.mesh.get_aabb()
			record["render_bounds_min"] = _vector_array(bounds.position)
			record["render_bounds_max"] = _vector_array(bounds.end)
		report["nodes"].append(record)
	var views: Array[Vector2] = [Vector2(camera_yaw_base, 0.0), Vector2(camera_yaw_base + 0.40, 0.16), Vector2(camera_yaw_base - 0.30, 0.36)]
	for index in range(views.size()):
		yaw = views[index].x
		pitch = views[index].y
		_update_camera()
		await get_tree().process_frame
		await RenderingServer.frame_post_draw
		var filename: String = output_dir.path_join("hol_024_native_%d.png" % index)
		var result: Error = get_viewport().get_texture().get_image().save_png(filename)
		if result != OK:
			push_error("Could not save reference view: " + filename)
			get_tree().quit(1)
			return
		print("NATIVE_TERRAIN_CAPTURE " + filename)
		report["views"].append({"image": filename, "camera": _vector_array(camera.position),
			"yaw": yaw, "pitch": pitch})
	var report_file: FileAccess = FileAccess.open(output_dir.path_join("scene_space.json"), FileAccess.WRITE)
	if report_file == null or not report_file.store_string(JSON.stringify(report, "\t")):
		push_error("Could not save scene-space report")
		get_tree().quit(1)
		return
	get_tree().quit()


func _vector_array(value: Vector3) -> Array[float]:
	return [value.x, value.y, value.z]
