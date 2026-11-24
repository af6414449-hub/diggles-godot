extends Node3D
## Source map X/Y are horizontal/down; Z is depth toward the viewer.

const NATIVE_POINT_SCALE: float = 16384.0
# Native unit-instance render scale (ModelRenderer.cpp draw at 0x4874a3).
const OBJECT_WORLD_SCALE: float = 0.005
const BDB_DEPTH_SCALE: float = 2.0
const BDB_DEPTH_OFFSET: float = -14.0
const RENDER_DEPTH_SCALE: float = 0.5
const RENDER_DEPTH_OFFSET: float = 7.0
const NATIVE_SCENE_PROFILE: Script = preload("res://scripts/native_scene_profile.gd")
const NATIVE_DIG_RULES: Script = preload("res://scripts/native_dig_rules.gd")
const CORRIDOR_STROKE: Script = preload("res://scripts/native_corridor_stroke.gd")
const TUNNEL_RULES: Script = preload("res://scripts/native_tunnel_rules.gd")
const ERASE_BRUSH: Script = preload("res://scripts/native_erase_brush.gd")
const TERRAIN_STATE: Script = preload("res://scripts/native_terrain_state.gd")
const SOURCE_ACTION: Script = preload("res://scripts/source_animation_action.gd")
const ACTOR_TASK_RUNTIME: Script = preload("res://scripts/dwarf_task_runtime.gd")
var actor_tasks: RefCounted = ACTOR_TASK_RUNTIME.new()
const WORK_CLOCK: Script = preload("res://scripts/native_work_clock.gd")
const DWARF_LIFE: Script = preload("res://scripts/dwarf_life_runtime.gd")
var game_clock: RefCounted = WORK_CLOCK.new()
var dwarf_life: RefCounted = DWARF_LIFE.new()
const DWARF_SLEEP: Script = preload("res://scripts/dwarf_sleep_runtime.gd")
var dwarf_sleep: RefCounted = DWARF_SLEEP.new()
const DWARF_SPARETIME: Script = preload("res://scripts/dwarf_sparetime_runtime.gd")
var dwarf_sparetime: RefCounted = DWARF_SPARETIME.new()
@export var autonomous_dwarf_sparetime: bool = true
const WORLD_SPACE: Script = preload("res://scripts/playable_world_space.gd")
@export var extended_world: bool = true
var template_shift: Vector2i = Vector2i.ZERO
@export var autonomous_dwarf_work: bool = true
@export var simulation_paused: bool = false
@export var simulation_time_scale: float = 1.0
const FLOOR_WALK: Script = preload("res://scripts/floor_walk_action.gd")
const DIG_NEXT: Script = preload("res://scripts/native_dig_next.gd")
const WORK_REGION: Script = preload("res://scripts/manual_dig_region.gd")
var dwarf_manual_dig_tasks: Dictionary = {}
var native_marks_revision: int = 0
var work_preview_revision: int = -1
var work_preview_cache: Dictionary = {}
var floor_cells_by_x: Dictionary = {}
const DIG_GROUPS: Script = preload("res://scripts/native_dig_groups.gd")
const FIX_DIG: Script = preload("res://scripts/native_fix_dig.gd")
const WALKMAP: Script = preload("res://scripts/native_walkmap.gd")
const WORLD_CONTEXT: Script = preload("res://scripts/native_world_context.gd")
const SURFACE_WALK: Script = preload("res://scripts/surface_walk_action.gd")
const WALK_POSE: Script = preload("res://scripts/native_walk_pose.gd")
const VECTOR_FIX: Script = preload("res://scripts/native_vector_fix.gd")
const DIG_POSE: Script = preload("res://scripts/native_dig_pose.gd")
const WALK_FLAGS: Script = preload("res://scripts/native_walk_flags.gd")
const TORCH_RUNTIME: Script = preload("res://scripts/native_torch_runtime.gd")
const TERRAIN_ILLUMINATION: Script = preload("res://scripts/native_terrain_illumination.gd")
const NATIVE_FLAME: Script = preload("res://scripts/native_flame_emitter.gd")
const MODEL_NORMALS: Script = preload("res://scripts/native_model_material.gd")
var native_model_material: RefCounted = MODEL_NORMALS.new()
const DIG_FEEDBACK: Script = preload("res://scripts/native_dig_feedback.gd")
const ANIMATION_ALIASES: Script = preload("res://scripts/native_animation_aliases.gd")
var dig_feedback_data: Dictionary = {}
var dig_feedback_frames: Dictionary = {}
var model_texture_cache: Dictionary = {}
var native_flame_data: Dictionary = {}
var flame_emitters: Dictionary = {}
const WORLD_MODEL_LIGHT: Script = preload("res://scripts/native_world_model_light.gd")
const WILD_HAMSTER: Script = preload("res://scripts/native_wild_hamster.gd")
const LEVEL_GROUND := preload("res://scripts/native_level_ground.gd")
var wild_hamsters: Array[Node3D] = []
var wild_hamster_food: Array[Dictionary] = []
# The ground of the level per height level. The navigation grid of the scene
# covers the main floor only, the hamsters of the upper terrace need their own.
var wild_hamster_ground: RefCounted = null
var wild_hamster_grids: Dictionary = {}
@export var native_world_model_lighting: bool = true
var model_light_records: Array[Dictionary] = []
var model_light_horizon: Dictionary = {}
var model_light_updates: int = 0
var model_light_skipped: int = 0
var model_lighting_queue: Array[int] = []
var model_lighting_changes: Dictionary = {}
const MODEL_LIGHTING_RECORDS_PER_FRAME: int = 1

@export var automatic_torches: bool = true
@export var verbose_runtime_trace: bool = false
var torch_runtime: RefCounted = null
var torch_visual_data: Dictionary = {}
var torch_meshes: Array[ArrayMesh] = []
var torch_nodes: Dictionary = {}
var torch_terrain_indices: Dictionary = {}
var terrain_lighting_inputs: Dictionary = {}
var torch_lighting_updates: int = 0
var torch_lighting_vertices: int = 0
var torch_terrain_lighting_queue: Array[String] = []
var torch_terrain_lighting_changes: Dictionary = {}
const TORCH_TERRAIN_LIGHTING_BUCKETS_PER_FRAME: int = 1

@export var source_world_case: String = "authored_2p"

var source_profile: RefCounted = NATIVE_SCENE_PROFILE.new()
var tunnel_rules: RefCounted = TUNNEL_RULES.new()
var terrain_state: RefCounted = TERRAIN_STATE.new()
var terrain_manifest: Dictionary = {}
var terrain_mesh_nodes: Dictionary = {}
var terrain_mesh_cells: Dictionary = {}
var terrain_cell_triangles: Dictionary = {}
var terrain_cell_omitted: Dictionary = {}
var terrain_floor_triangles: Dictionary = {}
## Terrain meshes are shared by texture variant. Rebuilding one used to rebuild
## every matching cell synchronously after every pick strike, which starved all
## animation and camera processing on the enlarged field.
var terrain_refresh_pending: bool = false
var terrain_refresh_wait: float = 0.0
var terrain_refresh_variants: Dictionary = {}
var terrain_refresh_cells: Dictionary = {}
var terrain_refresh_count: int = 0
const TERRAIN_REFRESH_COALESCE_SECONDS: float = 0.75
const TERRAIN_CHUNK_CELLS: int = 8
var navigation_refresh_pending: bool = false
var navigation_refresh_wait: float = 0.0
var navigation_refresh_count: int = 0
var navigation_body_height: float = 1.0
var navigation_depth_clearance: float = 0.0
var dig_action_data: Dictionary = {}
var dwarf_dig_jobs: Dictionary = {}
var dwarf_walk_actions: Dictionary = {}
var dwarf_last_walk_targets: Dictionary = {}
var dig_action_completions: int = 0
var dwarf_dig_groups: Dictionary = {}
var native_dig_groups: RefCounted = DIG_GROUPS.new()
var native_walkmap: RefCounted = WALKMAP.new()
var native_world: RefCounted = WORLD_CONTEXT.new()
var native_walkmap_overlay: MeshInstance3D
var surface_walk_data: Dictionary = {}
var surface_walk_meshes: Dictionary = {}
var dwarf_surface_modes: Dictionary = {}
var surface_walk_history: Array[Dictionary] = []
var surface_walk_results: Dictionary = {}
var dig_selection_history: Array[Dictionary] = []
var last_native_strike: Dictionary = {}
var scene_environment: Environment

var camera: Camera3D
var focus: Vector3 = Vector3(19.0, -12.0, 11.0)
var scene_root: Node3D
var yaw: float = 0.0
var pitch: float = 0.16
var distance: float = 25.0
var triangle_count: int = 0
var status: Label
var clock_caption: Label
var terrain_part_filter: PackedStringArray = PackedStringArray()
var terrain_flag_filter: PackedStringArray = PackedStringArray()
var include_objects: bool = true
var include_terrain: bool = true
var terrain_double_sided: bool = false
var terrain_cull_front: bool = false
var camera_yaw_base: float = 0.0
@export var native_terrain_lighting_preview: bool = true
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
var dwarf_outline_proxies: Dictionary = {}
var dwarf_outline_mesh_cache: Dictionary = {}
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
var corridor_stroke: RefCounted = CORRIDOR_STROKE.new()
var erase_brush: RefCounted = ERASE_BRUSH.new()
var corridor_touch_id: int = -1
var corridor_visual: MeshInstance3D
var cave_visual: MeshInstance3D
var corridor_contour: Script
var open_air: Dictionary = {}
var tool_cursor: Label
var barrels: Array[Node3D] = []
var barrel_goal: Node3D

var WALKABLE_FLOOR_Y: float = -14.5
var WALKABLE_FLOOR_MIN_X: float = 1.0
var WALKABLE_FLOOR_MAX_X: float = 17.5
const WALKABLE_FLOOR_MIN_Z: float = 1.0
const WALKABLE_FLOOR_MAX_Z: float = 15.0
const NAVIGATION_CELL_SIZE: float = 0.5
const ATTACHMENT: Script = preload("res://scripts/native_attachment.gd")
var attachment_data: Dictionary = {}
var attachment_meshes: Dictionary = {}
var actor_attachments: Dictionary = {}
var hover_visual: MeshInstance3D = null
var hover_key: String = ""
const NATIVE_TIMING: Script = preload("res://scripts/native_animation_timing.gd")
var movement_timing: Dictionary = {}
const WALK_SPEED: float = 0.8110876083374023
const RUN_SPEED_MULTIPLIER: float = 2.113626
const WALK_ANIMATION_FPS: float = 10.0
const IDLE_ANIMATION_FPS: float = 7.0
const TWO_FINGER_DECISION_PIXELS: float = 5.0
const TWO_FINGER_DOMINANCE: float = 1.15
const DIG_MARK_DEPTH: float = 15.12


func _ready() -> void:
	actor_tasks.configure(self)
	if not native_model_material.load_fixture():
		push_error("Original model normal table is missing")
		get_tree().quit(1)
		return
	_load_native_cave_brushes()
	_load_cave_skin_resources()
	var contents: String = FileAccess.get_file_as_string("res://models/multi_start_010_terrain.json")
	var decoded: Variant = JSON.parse_string(contents)
	if not decoded is Dictionary:
		push_error("Native terrain manifest is missing or invalid")
		get_tree().quit(1)
		return
	var data: Dictionary = decoded
	terrain_manifest = data
	if not tunnel_rules.load_rules("res://models/multi_start_010_tunnel_rules.json", data):
		push_error("Native tunnel rules do not match the terrain source")
		get_tree().quit(1)
		return
	if not source_profile.load_profile("res://models/multi_start_010_profile.json", data):
		get_tree().quit(1)
		return
	if not terrain_state.load_state("res://models/multi_start_010_mutable.json", data, tunnel_rules.data):
		push_error("Mutable BlockDB package does not match the terrain source")
		get_tree().quit(1)
		return
	if not native_walkmap.load_map("res://models/multi_start_010_walkmap.json", data):
		push_error("Native navigation samples do not match the terrain source")
		get_tree().quit(1)
		return
	data["meshes"].merge(terrain_state.package["meshes"], true)
	_load_native_terrain_grid(data)
	var args: PackedStringArray = OS.get_cmdline_user_args()
	native_world_model_lighting = native_world_model_lighting and not args.has("--legacy-model-lighting")
	var context_arg: int = args.find("--source-world-case")
	if context_arg >= 0 and context_arg + 1 < args.size():
		source_world_case = args[context_arg + 1]
	if not native_world.load_context("res://models/multi_start_010_world_context.json", source_world_case, data):
		push_error("Unknown or mismatched source world context")
		get_tree().quit(1)
		return
	if extended_world:
		template_shift = WORLD_SPACE.apply(self, data)
		WALKABLE_FLOOR_Y -= template_shift.y
		WALKABLE_FLOOR_MIN_X += template_shift.x
		WALKABLE_FLOOR_MAX_X += template_shift.x
		focus += Vector3(template_shift.x,-template_shift.y,0)
		_load_native_terrain_grid(data)
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
	source_profile.use_native_diffuse = (native_terrain_lighting_preview or args.has("--native-terrain-lighting")) and not args.has("--legacy-terrain-lighting")
	_build_geometry(data)
	wild_hamster_ground = LEVEL_GROUND.new() as RefCounted
	(wild_hamster_ground as RefCounted).call("load_terrain", data)
	if args.has("--show-native-walkmap"):
		_build_native_walkmap_overlay()
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
		_load_dig_action_visuals()
	_build_navigation_grid()
	if triangle_count != int(data["summary"]["triangles"]):
		push_error("Terrain input triangle count differs from exported source")
		get_tree().quit(1)
		return
	_index_open_air(data)
	_build_camera_and_light()
	_build_caption()
	_update_camera()
	_initialize_automatic_torches()
	_initialize_source_flames()
	dwarf_life.configure(self, game_clock)
	dwarf_sleep.configure(self)
	dwarf_sparetime.configure(self)
	print("WORLD_MODEL_LIGHT_READY surfaces=%d skipped=%d enabled=%s host_owner=255 shared_source_gain=%f" % [model_light_records.size(),model_light_skipped,native_world_model_lighting,float(source_profile.world_model_lighting["gain"]["default"])])
	var depth_range: Array = data["summary"]["packed_depth_range"]
	print("NATIVE_TERRAIN_READY cells=%d triangles=%d packed_depth=%s..%s" % [int(data["summary"]["cells"]), triangle_count, str(depth_range[0]), str(depth_range[1])])
	var capture_index: int = args.find("--capture-dir")
	if capture_index >= 0 and capture_index + 1 < args.size():
		_capture_views(args[capture_index + 1])
	print("MULTIPLAYER_START_MODELS_READY placements=%d unique_models=%d original_textures=%d" % [placement_count, model_count, texture_count])
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
	native_marks_revision += 1
	return true


func native_clear_cave_mark(owner_id: int, map_cell: Vector2i, layer: int = 0) -> void:
	if owner_id < 0 or owner_id > 6 or layer < 0 or layer > 3:
		return
	native_mark_nibbles.erase(_native_cell_key(map_cell, layer, owner_id))
	native_marks_revision += 1


func native_mark_corridor_cell(owner_id: int, map_cell: Vector2i, layer: int = 0) -> bool:
	if owner_id < 0 or owner_id > 6 or layer < 0 or layer > 3:
		return false
	if _corridor_point_rule(map_cell, owner_id, layer) != TUNNEL_RULES.ACCEPT:
		return false
	native_mark_nibbles[_native_cell_key(map_cell, layer, owner_id)] = 3
	native_marks_revision += 1
	if owner_id == 0 and layer == 0:
		native_dig_groups.stamp(map_cell, 0)
	return true


func _corridor_point_rule(point: Vector2i, owner_id: int = 0, layer: int = 0) -> int:
	var here: int = int(native_mark_nibbles.get(_native_cell_key(point, layer, owner_id), 0))
	var below: int = int(native_mark_nibbles.get(_native_cell_key(point + Vector2i.DOWN, layer, owner_id), 0))
	return tunnel_rules.point_rule(point, (here & 8) != 0, (below & 8) != 0)


func native_dig_apply_cell(owner_id: int, map_cell: Vector2i, layer: int = 0, policy_passed: bool = true) -> bool:
	# Current playable adapter exposes the first native slot. The pure model
	# implements all eight slots; player/group mapping is a separate subsystem.
	if owner_id != 0 or layer != 0:
		return false
	var key: String = _native_cell_key(map_cell, layer, owner_id)
	if not native_mark_nibbles.has(key):
		return false
	var mark_nibble: int = int(native_mark_nibbles[key])
	var patch: Dictionary = terrain_state.apply_accepted_step(map_cell, 0, mark_nibble, policy_passed,
		native_dig_groups.word(map_cell))
	last_native_strike = patch
	if (int(patch["marks"]) & 15) == 0:
		native_clear_cave_mark(owner_id, map_cell, layer)
	if not bool(patch["accepted"]):
		return false
	var walk_update: Dictionary = native_walkmap.rebuild_after_strike(patch,
		_native_height_sample, _native_walk_gate, native_world.local_sample_bounds(),
		_native_cell_surface_samples)
	if verbose_runtime_trace:
		print("NATIVE_WALKMAP_REBUILT samples=%d changed=%d unknown=%d" % [
			walk_update["rebuilt"], walk_update["changed"], walk_update["unknown_total"]])
	var variants: Dictionary = {}
	var changed_cells: Dictionary = {}
	for change: Dictionary in patch["changes"]:
		var point: Vector2i = change["cell"]
		var entry: Dictionary = native_terrain_cells[point]
		entry["block"] = int(change["after"])
		variants[int(entry["ground_variant"]) - 1] = true
		changed_cells[point] = true
	native_cell_heights[key] = int(terrain_state.current_height(map_cell))
	_queue_terrain_refresh(variants, changed_cells)
	_rebuild_corridor_preview()
	if verbose_runtime_trace:
		print("NATIVE_TERRAIN_STRIKE point=%s revision=%d height=%d variants=%d" % [map_cell, terrain_state.revision, native_cell_heights[key], variants.size()])
	return true


func _queue_terrain_refresh(variants: Dictionary, changed_cells: Dictionary = {}) -> void:
	terrain_refresh_variants.merge(variants)
	terrain_refresh_cells.merge(changed_cells)
	terrain_refresh_pending = true
	terrain_refresh_wait = TERRAIN_REFRESH_COALESCE_SECONDS
	# Chunks keep the visible terrain and collision in lockstep with walkmap.
	# Rebuild immediately: delaying made workers navigate through a still-visible
	# wall. Only callers with no changed cells use the deferred full refresh.
	if not changed_cells.is_empty() or not is_processing():
		_flush_terrain_refresh()


func _flush_terrain_refresh() -> void:
	if not terrain_refresh_pending:
		return
	var variants: Dictionary = terrain_refresh_variants.duplicate()
	var changed_cells: Dictionary = terrain_refresh_cells.duplicate()
	terrain_refresh_variants.clear()
	terrain_refresh_cells.clear()
	terrain_refresh_pending = false
	terrain_refresh_wait = 0.0
	var geometry_started: int = Time.get_ticks_usec()
	# Collision must be rebuilt whenever the terrain changed. Passing
	# changed_cells.is_empty() here skipped the rebuild for every real strike
	# and dropped the floor collision of the touched chunks.
	_build_geometry(terrain_manifest, variants, changed_cells, true)
	var geometry_ms: float = float(Time.get_ticks_usec()-geometry_started)/1000.0
	var open_air_started: int = Time.get_ticks_usec()
	open_air.clear()
	_index_open_air(terrain_manifest)
	var open_air_ms: float = float(Time.get_ticks_usec()-open_air_started)/1000.0
	var navigation_ms: float = 0.0
	if changed_cells.is_empty():
		var navigation_started: int = Time.get_ticks_usec()
		_build_navigation_grid()
		navigation_ms = float(Time.get_ticks_usec()-navigation_started)/1000.0
	else:
		_queue_navigation_refresh()
	if is_instance_valid(native_walkmap_overlay):
		_build_native_walkmap_overlay()
	terrain_refresh_count += 1
	if verbose_runtime_trace:
		print("NATIVE_TERRAIN_REFRESH batches=%d variants=%d geometry_ms=%.3f open_air_ms=%.3f navigation_ms=%.3f" % [terrain_refresh_count, variants.size(),geometry_ms,open_air_ms,navigation_ms])


func _queue_navigation_refresh() -> void:
	navigation_refresh_pending = true
	navigation_refresh_wait = TERRAIN_REFRESH_COALESCE_SECONDS
	if not is_processing():
		_flush_navigation_refresh()


func _flush_navigation_refresh() -> void:
	if not navigation_refresh_pending:
		return
	navigation_refresh_pending = false
	navigation_refresh_wait = 0.0
	_build_navigation_grid()
	navigation_refresh_count += 1
	print("NATIVE_NAVIGATION_REFRESH batches=%d" % navigation_refresh_count)


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
	if corridor_visual != null:
		_rebuild_corridor_preview()
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
		# Map Y is Godot's vertical negative axis; map Y is not world depth.
		# The previous x/floorY/mapY placement put the whole cave skin below the
		# excavated chamber. BDB native Z=15 maps to local depth16.
		_spawn_cave_skin_visual(int(record.get("brush_number", 0)),
			Vector3(float(center.x), -float(center.y), BDB_DEPTH_SCALE * 15.0 + BDB_DEPTH_OFFSET))
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
	var contents: String = FileAccess.get_file_as_string("res://models/multi_start_010_models.json")
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
		var programs: Array = source_profile.model_programs["objects"].get(key,[])
		if not programs.is_empty() and programs.size()==mesh_cache[key].size():
			for index: int in range(programs.size()):
				mesh_cache[key][index].set_meta("native_program",programs[index]["program"])
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
		# class_editor_icon marker meshes are not visible game objects. Their
		# actual light rules are imported independently, including fire bowls.
		if placement_class.begins_with("Misc_LightSrc_") or placement_class == "Misc_Light":
			continue
		if placement_class == "Dummy_Urw_sumpf":
			var placement_rotation: Array = placement["rotation"]
			# Temporary visual workaround retained from screenshot review.
			# Both placements exist in Tcl; their native visibility/rendering
			# distinction has not been established yet.
			if absf(float(placement_rotation[0])) > 0.1:
				continue
		var key: String = str(placement.get("model_package", "")).to_lower() + "::" + str(placement.get("model_object", "")).to_lower()
		if not mesh_cache.has(key) and not placement_class.begins_with("Misc_LightSrc_"):
			continue
		var position_data: Array = placement["position"]
		if placement_class == "Zwerg":
			position_data = [8.0 + dwarf_nodes.size() * 2.0, 14.5, 10.0]
		position_data = [float(position_data[0])+template_shift.x,
			float(position_data[1])+template_shift.y,position_data[2]]
		var rotation_data: Array = placement["rotation"]
		if placement_class == "Hamster":
			# The original level places the wild hamsters as living objects of
			# the class hamster.tcl, not as scenery. They get the actor of that
			# class and the original clips of the hamster.3db package.
			_spawn_wild_hamster(placement, position_data, rotation_data)
			continue
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
		instance_root.set_meta("native_class",placement_class)
		instance_root.set_meta("native_rotation_basis",source_rotation)
		instance_root.set_meta("native_ordinal",int(placement["ordinal"]))
		var obstacle_radius: float = _navigation_obstacle_radius(placement_class)
		if obstacle_radius > 0.0 and absf(float(position_data[1]) + WALKABLE_FLOOR_Y) < 0.8:
			navigation_obstacles.append(Vector3(float(position_data[0]), float(position_data[2]), obstacle_radius))
		var default_visuals: Array[MeshInstance3D] = []
		if mesh_cache.has(key):
			for mesh_index: int in range(mesh_cache[key].size()):
				var mesh_instance: MeshInstance3D = MeshInstance3D.new()
				mesh_instance.mesh = mesh_cache[key][mesh_index]
				if placement_class == "Feuerstelle" and mesh_instance.mesh.get_aabb().size.y < 0.00001:
					# Presentation depth separation for a source decal coplanar with the floor.
					mesh_instance.position.y = 0.0075
				instance_root.add_child(mesh_instance)
				default_visuals.append(mesh_instance)
		scene_root.add_child(instance_root)
		if placement_class == "Grillpilz":
			# The second food of the hamster in hamster.tcl:319-344.
			wild_hamster_food.append({"ref": instance_root.name,
				"position": instance_root.position, "node": instance_root})
		if native_world_model_lighting and ("kaserne" in placement_class or placement_class.begins_with("Dummy_Urw_")) \
				and placement_class!="Dummy_Urw_sumpf":
			_register_model_lighting(instance_root,default_visuals)
		if placement_class == "Schatztonne":
			barrels.append(instance_root)
		if placement_class == "Zwerg":
			dwarf_nodes.append(instance_root)
			instance_root.set_meta("autolight_host_id",int(placement["ordinal"]))
			for body_mesh: MeshInstance3D in default_visuals:
				var body_bounds: AABB = body_mesh.mesh.get_aabb()
				navigation_body_height = maxf(navigation_body_height, body_bounds.end.y)
				navigation_depth_clearance = maxf(navigation_depth_clearance,
					maxf(absf(body_bounds.position.z), absf(body_bounds.end.z)) / render_depth_scale)
			dwarf_headings[instance_root] = 0.0
			var animated: Node3D = Node3D.new()
			animated.name = "AnimatedBody"
			animated.visible = false
			instance_root.add_child(animated)
			var sequence_visuals: Dictionary = locomotion_cache.get(key,{})
			dwarf_locomotion_visuals[instance_root] = {"default":default_visuals,
				"sequences":sequence_visuals.duplicate(),"current":null,"animated":animated,"body_instances":[]}



## Spawn one wild hamster of the original level.
##
## The placement comes from the multiplayer Tcl (the class list of the scene
## manifest). The object itself is the class hamster.tcl: the actor of that
## class plus the original clips of the hamster.3db package.
func _spawn_wild_hamster(placement: Dictionary, position_data: Array, rotation_data: Array) -> void:
	var hamster: Node3D = WILD_HAMSTER.new()
	hamster.name = "%s_%03d" % [str(placement["class"]), int(placement["ordinal"])]
	var game_to_godot: Basis = Basis(Vector3.RIGHT, Vector3.DOWN, Vector3.BACK)
	var source_rotation: Basis = Basis(Vector3.UP, -float(rotation_data[1])) \
		* Basis(Vector3.RIGHT, -float(rotation_data[0])) \
		* Basis(Vector3.BACK, -float(rotation_data[2]))
	var mapped_rotation: Basis = game_to_godot * source_rotation * game_to_godot.inverse()
	var render_to_logical: Basis = Basis(Vector3.RIGHT, Vector3.UP, Vector3(0.0, 0.0, 1.0 / render_depth_scale))
	hamster.transform = Transform3D(render_to_logical * mapped_rotation,
		Vector3(float(position_data[0]), -float(position_data[1]), float(position_data[2])))
	hamster.set_meta("native_class", str(placement["class"]))
	hamster.set_meta("native_ordinal", int(placement["ordinal"]))
	# The height of the placement is the level the hamster stands on: the main
	# floor of the cave or the upper terrace.
	var level := LEVEL_GROUND.level_of(-float(position_data[1]))
	hamster.set_meta("native_ground_level", level)
	scene_root.add_child(hamster)
	wild_hamsters.append(hamster)
	hamster.call("setup", _wild_hamster_host(level, _wild_hamster_initial_heading(hamster)))


## The direction the model of the placement looks to.
##
## The model of the hamster walks along its local Z axis, so the heading is the
## angle of that axis in the logical space of the scene.
func _wild_hamster_initial_heading(hamster: Node3D) -> float:
	var forward := Vector3(hamster.transform.basis.z.x, 0.0, hamster.transform.basis.z.z)
	if forward.length_squared() < 0.000001:
		return 0.0
	return atan2(forward.x, forward.z)


## The world of the wild hamsters.
##
## The hamster works in the logical space of the scene: the positions of the
## dwarves, the food, the navigation path and the heading convention are the
## ones of the project, so the ranges of the original (scan range four, escape
## range two, search range six) are game units. The level is the height the
## hamster stands on, the terrace has its own ground.
func _wild_hamster_host(level: float, initial_heading: float = 0.0) -> Dictionary:
	return {
		"initial_heading": initial_heading,
		"dwarf_positions": func() -> Array: return _wild_hamster_dwarves(),
		"food_entries": func() -> Array: return wild_hamster_food,
		"walk_path": func(from: Vector3, to: Vector3) -> Array: return _wild_hamster_path(from, to, level),
		"free_spot": func(center: Vector3, radius: float, mindist: float, clip: Array) -> Variant:
			return _wild_hamster_free_spot(center, radius, mindist, clip, level),
		"apply_heading": func(node: Node3D, heading: float) -> void: _set_wild_hamster_heading(node, heading),
		"depth_scale": func() -> float: return render_depth_scale,
		"is_walkable": func(point: Vector3) -> bool: return _wild_hamster_is_walkable(point, level),
		"delete_item": func(reference: String) -> void: _delete_wild_hamster_food(reference),
		"object_position": func(reference: String) -> Variant:
			return _wild_hamster_food_position(reference),
	}


## The dwarves of the scene in the logical space of the scene root.
func _wild_hamster_dwarves() -> Array:
	var positions: Array = []
	for dwarf: Node3D in dwarf_nodes:
		positions.append(dwarf.position)
	return positions


## The path of a wild hamster.
##
## The navigation grid of the scene covers the main floor only, so every level
## gets its own grid: the floor of the level comes from the terrain, the
## obstacles of the placements block the cells.
func _wild_hamster_path(from: Vector3, to: Vector3, level: float) -> Array[Vector3]:
	var entry: Dictionary = _wild_hamster_grid(level)
	if entry.is_empty():
		return []
	var grid: AStarGrid2D = entry["grid"]
	var origin: Vector2 = entry["origin"]
	var start: Variant = _wild_hamster_nearest_id(grid, origin, from)
	var target: Variant = _wild_hamster_nearest_id(grid, origin, to)
	if not start is Vector2i or not target is Vector2i:
		return []
	var ids: Array[Vector2i] = grid.get_id_path(start, target, false)
	var result: Array[Vector3] = []
	for grid_id: Vector2i in ids:
		result.append(Vector3(origin.x + float(grid_id.x) * NAVIGATION_CELL_SIZE,
			from.y, origin.y + float(grid_id.y) * NAVIGATION_CELL_SIZE))
	return result


## The navigation grid of a level of the cave.
##
## The main floor uses the grid of the scene, the other levels get a grid of
## their own: the floor of the level comes from the terrain, the obstacles of
## the placements block the cells.
func _wild_hamster_grid(level: float) -> Dictionary:
	if absf(level + WALKABLE_FLOOR_Y) < 0.25:
		if navigation_grid == null:
			return {}
		return {"grid": navigation_grid, "origin": Vector2(WALKABLE_FLOOR_MIN_X, WALKABLE_FLOOR_MIN_Z)}
	if wild_hamster_grids.has(level):
		return wild_hamster_grids[level]
	if wild_hamster_ground == null:
		return {}
	var bounds: Rect2 = (wild_hamster_ground as RefCounted).call("level_bounds", level)
	if bounds.size == Vector2.ZERO:
		return {}
	var origin := Vector2(floorf(bounds.position.x / NAVIGATION_CELL_SIZE) * NAVIGATION_CELL_SIZE,
		floorf(bounds.position.y / NAVIGATION_CELL_SIZE) * NAVIGATION_CELL_SIZE)
	var width: int = int(ceil((bounds.end.x - origin.x) / NAVIGATION_CELL_SIZE)) + 1
	var depth: int = int(ceil((bounds.end.y - origin.y) / NAVIGATION_CELL_SIZE)) + 1
	var grid := AStarGrid2D.new()
	grid.region = Rect2i(Vector2i.ZERO, Vector2i(width, depth))
	grid.cell_size = Vector2(NAVIGATION_CELL_SIZE, NAVIGATION_CELL_SIZE)
	grid.diagonal_mode = AStarGrid2D.DIAGONAL_MODE_ONLY_IF_NO_OBSTACLES
	grid.update()
	var blocked_count: int = 0
	for grid_z: int in range(depth):
		for grid_x: int in range(width):
			var point := Vector2(origin.x + float(grid_x) * NAVIGATION_CELL_SIZE,
				origin.y + float(grid_z) * NAVIGATION_CELL_SIZE)
			if not _wild_hamster_has_floor(point, level) or not _wild_hamster_body_clear(point, level):
				grid.set_point_solid(Vector2i(grid_x, grid_z), true)
				blocked_count += 1
	var entry := {"grid": grid, "origin": origin}
	wild_hamster_grids[level] = entry
	print("WILD_HAMSTER_NAV_READY level=%.2f size=%dx%d blocked=%d" % [level, width, depth, blocked_count])
	return entry


## Is there floor of the level under the point?
func _wild_hamster_has_floor(point: Vector2, level: float) -> bool:
	if absf(level + WALKABLE_FLOOR_Y) < 0.25:
		return _has_source_floor(point)
	if wild_hamster_ground == null:
		return false
	return bool((wild_hamster_ground as RefCounted).call("floor_at", level, point))


## Is the point free of the obstacles of the placements?
##
## The obstacles of the scene are the objects of the main floor, so they only
## block the main level.
func _wild_hamster_body_clear(point: Vector2, level: float) -> bool:
	if absf(level + WALKABLE_FLOOR_Y) >= 0.25:
		return true
	for obstacle: Vector3 in navigation_obstacles:
		if point.distance_to(Vector2(obstacle.x, obstacle.y)) <= obstacle.z + 0.28:
			return false
	return true


## The cell of the grid that is the closest one that can be walked on.
func _wild_hamster_nearest_id(grid: AStarGrid2D, origin: Vector2, point: Vector3) -> Variant:
	var grid_id := Vector2i(
		int(round((point.x - origin.x) / NAVIGATION_CELL_SIZE)),
		int(round((point.z - origin.y) / NAVIGATION_CELL_SIZE)))
	grid_id.x = clampi(grid_id.x, 0, grid.region.size.x - 1)
	grid_id.y = clampi(grid_id.y, 0, grid.region.size.y - 1)
	if not grid.is_point_solid(grid_id):
		return grid_id
	for radius: int in range(1, 7):
		var best := Vector2i(-1, -1)
		var best_distance: float = INF
		for z_offset: int in range(-radius, radius + 1):
			for x_offset: int in range(-radius, radius + 1):
				if absi(x_offset) != radius and absi(z_offset) != radius:
					continue
				var candidate: Vector2i = grid_id + Vector2i(x_offset, z_offset)
				if not grid.region.has_point(candidate) or grid.is_point_solid(candidate):
					continue
				var candidate_distance: float = Vector2(candidate).distance_to(Vector2(grid_id))
				if candidate_distance < best_distance:
					best = candidate
					best_distance = candidate_distance
		if best.x >= 0:
			return best
	return null


## Is there ground of the level under the point?
func _wild_hamster_is_walkable(point: Vector3, level: float) -> bool:
	var entry: Dictionary = _wild_hamster_grid(level)
	if entry.is_empty():
		return false
	var grid: AStarGrid2D = entry["grid"]
	var origin: Vector2 = entry["origin"]
	var grid_id := Vector2i(
		int(round((point.x - origin.x) / NAVIGATION_CELL_SIZE)),
		int(round((point.z - origin.y) / NAVIGATION_CELL_SIZE)))
	if not grid.region.has_point(grid_id):
		return false
	return not grid.is_point_solid(grid_id)


## get_place of the original (hamster.tcl:216).
##
## The hamster wants a free spot on the floor: the nearest walkable cell of
## the navigation grid that is inside the circle, outside the clip boxes of
## the dwarves and not closer than the minimum distance.
func _wild_hamster_free_spot(center: Vector3, radius: float, mindist: float, clip: Array, level: float) -> Variant:
	var entry: Dictionary = _wild_hamster_grid(level)
	if entry.is_empty():
		return null
	var grid: AStarGrid2D = entry["grid"]
	var origin: Vector2 = entry["origin"]
	var center_id := Vector2i(
		int(round((center.x - origin.x) / NAVIGATION_CELL_SIZE)),
		int(round((center.z - origin.y) / NAVIGATION_CELL_SIZE)))
	var span := maxi(1, int(ceil(radius / NAVIGATION_CELL_SIZE)))
	var best: Variant = null
	var best_distance := INF
	for z_offset: int in range(-span, span + 1):
		for x_offset: int in range(-span, span + 1):
			var grid_id := center_id + Vector2i(x_offset, z_offset)
			if not grid.region.has_point(grid_id) or grid.is_point_solid(grid_id):
				continue
			var point := Vector3(origin.x + float(grid_id.x) * NAVIGATION_CELL_SIZE,
				center.y, origin.y + float(grid_id.y) * NAVIGATION_CELL_SIZE)
			var candidate_distance := Vector2(point.x - center.x, point.z - center.z).length()
			if candidate_distance > radius or candidate_distance < mindist:
				continue
			if _wild_hamster_inside_clip(point, clip):
				continue
			if candidate_distance < best_distance:
				best = point
				best_distance = candidate_distance
	return best


## The clip boxes of the original around the dwarves (hamster.tcl:204).
func _wild_hamster_inside_clip(point: Vector3, clip: Array) -> bool:
	for box: Dictionary in clip:
		if point.x < float(box.get("min_x", 0.0)) or point.x > float(box.get("max_x", 0.0)):
			continue
		if point.z < float(box.get("min_z", 0.0)) or point.z > float(box.get("max_z", 0.0)):
			continue
		return true
	return false


## The heading of a wild hamster.
##
## The hamster is a child of the scene root, so it needs the same depth
## packing compensation as the dwarves. Only the hamster that walks is turned,
## the other ones keep their own direction.
func _set_wild_hamster_heading(hamster: Node3D, heading: float) -> void:
	if hamster == null:
		return
	var render_to_logical: Basis = Basis(Vector3.RIGHT, Vector3.UP,
		Vector3(0.0, 0.0, 1.0 / render_depth_scale))
	hamster.transform.basis = render_to_logical * Basis(Vector3.UP, heading)


func _wild_hamster_food_position(reference: String) -> Variant:
	for entry: Dictionary in wild_hamster_food:
		if String(entry.get("ref", "")) == reference:
			return entry.get("position", null)
	return null


func _delete_wild_hamster_food(reference: String) -> void:
	for entry: Dictionary in wild_hamster_food:
		if String(entry.get("ref", "")) != reference:
			continue
		var node: Variant = entry.get("node", null)
		if node is Node:
			(node as Node).queue_free()
		wild_hamster_food.erase(entry)


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


func _load_dig_action_visuals() -> void:
	var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string("res://models/dwarf_dig_action.json"))
	if not parsed is Dictionary:
		push_error("Source digging clips could not be loaded")
		return
	dig_action_data = parsed
	var cache: Dictionary = {}
	for clip_name: String in dig_action_data["clips"]:
		var clip: Dictionary = dig_action_data["clips"][clip_name]
		for frame: Dictionary in clip["frames"]:
			var mesh_id: int = int(frame["mesh_index"])
			if not cache.has(mesh_id):
				cache[mesh_id] = _build_model_meshes(frame["surfaces"])
		var frames: Array = []
		for frame: Dictionary in clip["frames"]:
			frames.append(cache[int(frame["mesh_index"])])
		for dwarf: Node3D in dwarf_nodes:
			dwarf_locomotion_visuals[dwarf]["sequences"][clip_name] = frames

	print("DWARF_DIG_CLIPS_READY clips=%d frames=%d" % [dig_action_data["clips"].size(), cache.size()])


func _model_light_fields(point: Vector3) -> Dictionary:
	# Explicit host cell selection (floor), live owner bytes remain unimported.
	# Do not clamp a vertex outside the imported world to an invented border.
	var cell: Vector2i = Vector2i(floori(point.x),floori(point.y))
	var width: int = int(source_profile.terrain_render["width"])
	var height: int = int(source_profile.terrain_render["height"])
	if cell.x<0 or cell.y<0 or cell.x+1>=width or cell.y+1>=height:
		return {}
	var attributes: Array = []
	for offset: Vector2i in [Vector2i.ZERO,Vector2i.RIGHT,Vector2i.DOWN,Vector2i.ONE]:
		attributes.append(source_profile.terrain_render["attributes"][(cell.y+offset.y)*width+cell.x+offset.x])
	return WORLD_MODEL_LIGHT.interpolate(attributes,[255,255,255,255],Vector2(point.x-cell.x,point.y-cell.y))


func _register_model_lighting(anchor: Node3D, visuals: Array[MeshInstance3D]) -> void:
	var rotation_basis: Basis = anchor.get_meta("native_rotation_basis",Basis.IDENTITY)
	for visual: MeshInstance3D in visuals:
		var arrays: Array = visual.mesh.surface_get_arrays(0)
		var points: PackedVector3Array = arrays[Mesh.ARRAY_VERTEX]
		var normals: PackedVector3Array = arrays[Mesh.ARRAY_NORMAL]
		var material: StandardMaterial3D = visual.mesh.surface_get_material(0) as StandardMaterial3D
		var program: Dictionary = visual.mesh.get_meta("native_program",{})
		if material==null or material.albedo_texture==null or program.is_empty() \
				or points.size()!=normals.size():
			model_light_skipped += 1
			continue
		var source_points: PackedVector3Array = PackedVector3Array()
		var source_normals: PackedVector3Array = PackedVector3Array()
		var fields: Array[Dictionary] = []
		for index: int in range(points.size()):
			var local: Vector3 = anchor.transform*points[index]
			var point: Vector3 = Vector3(local.x,-local.y,local.z*render_depth_scale+RENDER_DEPTH_OFFSET)
			var input: Dictionary = _model_light_fields(point)
			if input.is_empty():
				break
			source_points.append(point)
			source_normals.append(rotation_basis*Vector3(normals[index].x,-normals[index].y,normals[index].z))
			fields.append(input)
		if fields.size()!=points.size():
			model_light_skipped += 1
			continue
		var native_material: ShaderMaterial = ShaderMaterial.new()
		var blending: bool = str(program["blend"])=="srcalpha_invsrcalpha"
		native_material.shader = load("res://shaders/native_world_model_blend.gdshader" if blending else "res://shaders/native_world_model.gdshader") as Shader
		native_material.set_shader_parameter("albedo_texture",material.albedo_texture)
		native_material.set_shader_parameter("native_gamma",source_profile.shader_pipeline["defaults"]["gamma"])
		native_material.set_shader_parameter("native_brightness",source_profile.shader_pipeline["defaults"]["brightness"])
		native_material.set_shader_parameter("alpha_cutout",true)
		native_material.set_shader_parameter("alpha_threshold",float(program["alpha_ref"])/255.0)
		model_light_records.append({"visual":visual,"arrays":arrays,"points":source_points,
			"normals":source_normals,"fields":fields,"material":native_material,"source_mesh":visual.mesh,"program":program})


func _refresh_model_lighting(changed_lights: Array = []) -> void:
	if model_light_records.is_empty():
		return
	for record: Dictionary in model_light_records:
		if not changed_lights.is_empty() and not _model_record_may_receive_light(record,changed_lights):
			continue
		_refresh_model_lighting_record(record)
	model_light_updates += 1


func _model_record_may_receive_light(record: Dictionary, changes: Array) -> bool:
	for point: Vector3 in record["points"]:
		for light: Dictionary in changes:
			if point.distance_squared_to(light["position"]) < float(light["range"])*float(light["range"]):
				return true
	return false


func _queue_model_lighting(changes: Array) -> void:
	for index: int in range(model_light_records.size()):
		var record: Dictionary = model_light_records[index]
		if not _model_record_may_receive_light(record,changes):
			continue
		if not model_lighting_changes.has(index):
			model_lighting_queue.append(index)
			model_lighting_changes[index] = []
		var pending_changes: Array = model_lighting_changes[index]
		pending_changes.append_array(changes)


func _step_model_lighting() -> void:
	for record_index: int in range(mini(MODEL_LIGHTING_RECORDS_PER_FRAME,model_lighting_queue.size())):
		var index: int = model_lighting_queue.pop_front()
		model_lighting_changes.erase(index)
		if index >= 0 and index < model_light_records.size():
			_refresh_model_lighting_record(model_light_records[index])
			model_light_updates += 1


func _refresh_model_lighting_record(record: Dictionary) -> void:
	var arrays: Array = record["arrays"].duplicate()
	var vertices: PackedVector3Array = arrays[Mesh.ARRAY_VERTEX]
	var colors: PackedColorArray = PackedColorArray()
	var secondary: PackedFloat32Array = PackedFloat32Array()
	for index: int in range(vertices.size()):
		#Manager+38E4 aliases terrain subobject+1034; use the shared default.
		var color: Dictionary = WORLD_MODEL_LIGHT.channels(record["points"][index],record["normals"][index],
			record["fields"][index],source_profile.terrain_lights,float(source_profile.world_model_lighting["gain"]["default"]),model_light_horizon)
		colors.append(color["diffuse"])
		var spec: Color = color["secondary"]
		secondary.append_array(PackedFloat32Array([spec.r,spec.g,spec.b,1.0]))
	arrays[Mesh.ARRAY_COLOR] = colors
	arrays[Mesh.ARRAY_CUSTOM0] = secondary
	var mesh: ArrayMesh = ArrayMesh.new()
	mesh.add_surface_from_arrays(Mesh.PRIMITIVE_TRIANGLES,arrays,[],{},Mesh.ARRAY_CUSTOM_RGBA_FLOAT<<Mesh.ARRAY_FORMAT_CUSTOM0_SHIFT)
	mesh.surface_set_material(0,record["material"])
	record["visual"].mesh = mesh


func _update_model_horizon(horizon: Dictionary) -> void:
	if not native_world_model_lighting or model_light_records.is_empty():
		return
	var converted: Dictionary = {}
	if not horizon.is_empty():
		var raw: Array = horizon["color"]
		converted = {"distance":float(horizon["distance"]),
			"rgb_bytes":WORLD_MODEL_LIGHT.horizon_rgb(raw)}
	if converted!=model_light_horizon or model_light_updates==0:
		model_light_horizon = converted
		_refresh_model_lighting()


func _build_model_meshes(surfaces: Array, texture_directory: String = "res://textures/models") -> Array[ArrayMesh]:
	var meshes: Array[ArrayMesh] = []
	for source_surface: Dictionary in surfaces:
		var vertices: Array = source_surface["points"]
		var uvs: Array = source_surface["uvs"]
		var indices: Array = source_surface["triangles"]
		# The legacy field 'brightness' is actually the sphere.dat normal index.
		var source_normals: PackedVector3Array = native_model_material.godot_local_normals(source_surface)
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
			if not source_normals.is_empty():
				surface_tool.set_normal(source_normals[index])
			var native_point: Vector3 = Vector3(float(raw_point[0]) - 0.5,
				-(float(raw_point[1]) - 0.5), float(raw_point[2]) - 0.5) * NATIVE_POINT_SCALE
			surface_tool.add_vertex(native_point * OBJECT_WORLD_SCALE)
		if source_normals.is_empty():
			surface_tool.generate_normals()
		var mesh: ArrayMesh = surface_tool.commit()
		var material: StandardMaterial3D = StandardMaterial3D.new()
		material.cull_mode = BaseMaterial3D.CULL_DISABLED
		material.roughness = 0.95
		material.vertex_color_use_as_albedo = false
		var texture_name: String = str(source_surface["texture"])
		var texture_path: String = str(source_surface.get("texture_res_path",texture_directory+"/"+texture_name))
		if not ResourceLoader.exists(texture_path) and not FileAccess.file_exists(texture_path):
			texture_path = "res://assets/textures/" + texture_name
		if not model_texture_cache.has(texture_path):
			if ResourceLoader.exists(texture_path):
				model_texture_cache[texture_path] = load(texture_path) as Texture2D
			elif FileAccess.file_exists(texture_path):
				model_texture_cache[texture_path] = ImageTexture.create_from_image(Image.load_from_file(texture_path))
		if model_texture_cache.has(texture_path):
			material.albedo_texture = model_texture_cache[texture_path]
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
			if not _has_source_floor(point) or not _navigation_body_clear(point):
				blocked = true
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


func _has_source_floor(point: Vector2, replacements: Dictionary = {}) -> bool:
	var candidates: Dictionary = floor_cells_by_x.get(floori(point.x),{}).duplicate()
	for cell: Vector2i in replacements:
		candidates[cell] = true
	for cell: Vector2i in candidates:
		var triangles: Array = replacements.get(cell, terrain_floor_triangles.get(cell,[]))
		for triangle: PackedVector2Array in triangles:
			# Grid points lie on shared mesh edges; include those edges rather
			# than isolating every cell with the engine's strict interior test.
			var a: float = (triangle[1] - triangle[0]).cross(point - triangle[0])
			var b: float = (triangle[2] - triangle[1]).cross(point - triangle[1])
			var c: float = (triangle[0] - triangle[2]).cross(point - triangle[2])
			if not (minf(a, minf(b, c)) < -0.00001 and maxf(a, maxf(b, c)) > 0.00001):
				return true
	return false


func _preview_work_step(point: Vector2i) -> Dictionary:
	if work_preview_revision != terrain_state.revision:
		work_preview_revision = terrain_state.revision
		work_preview_cache.clear()
	var key: Vector3i = Vector3i(point.x,point.y,_work_mark(point))
	if not work_preview_cache.has(key):
		work_preview_cache[key] = terrain_state.preview_accepted_step(point,0,_work_mark(point),true,native_dig_groups.word(point))
	return work_preview_cache[key]


func _future_floor_for_dig(point: Vector2i) -> Dictionary:
	var patch: Dictionary = _preview_work_step(point)
	var replacements: Dictionary = {}
	if not bool(patch["accepted"]):
		return replacements
	for change: Dictionary in patch["changes"]:
		var cell: Vector2i = change["cell"]
		var triangles: Array[PackedVector2Array] = []
		var parts: Array = terrain_state.package["meshes"][str(int(change["after"]))]
		for part: Dictionary in parts:
			var values: Array = part["vertices"]
			var indices: Array = part["indices"]
			for start: int in range(0, indices.size(), 3):
				var triangle: PackedVector2Array = PackedVector2Array()
				for corner: int in range(3):
					var offset: int = int(indices[start + corner]) * 5
					if absf(-(float(values[offset + 1]) + float(cell.y)) - WALKABLE_FLOOR_Y) > 0.0001:
						break
					triangle.append(Vector2(float(values[offset]) + float(cell.x),
						BDB_DEPTH_SCALE * float(values[offset + 2]) + BDB_DEPTH_OFFSET))
				if triangle.size() == 3 and absf((triangle[1] - triangle[0]).cross(triangle[2] - triangle[0])) > 0.00001:
					triangles.append(triangle)
		replacements[cell] = triangles
	return replacements


func _navigation_body_clear(point: Vector2) -> bool:
	# Explicit floor-navigation adapter; sample the source body height over the
	# native 8x8 terrain profile instead of treating the whole X/Z plane as air.
	for index: int in range(1, ceili(navigation_body_height * 8.0) + 1):
		var sample_height: float = minf(navigation_body_height, float(index) / 8.0)
		var depth: Variant = terrain_state.surface_depth(Vector2(point.x, -WALKABLE_FLOOR_Y - sample_height))
		if depth == null or point.y - navigation_depth_clearance < float(depth):
			return false
	return true


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


func _build_geometry(data: Dictionary, dirty_variants: Dictionary = {}, dirty_cells: Dictionary = {}, build_collision: bool = true) -> void:
	var baked_terrain_lights: Array = _terrain_baked_lights()
	var dirty_chunks: Dictionary = {}
	for cell: Vector2i in dirty_cells:
		dirty_chunks[Vector2i(floori(float(cell.x) / float(TERRAIN_CHUNK_CELLS)),
			floori(float(cell.y) / float(TERRAIN_CHUNK_CELLS)))] = true
	for key: String in terrain_mesh_nodes.keys():
		var variant: int = int(key.split(":")[0])
		var mesh_cells: Dictionary = terrain_mesh_cells.get(key,{})
		var touches_dirty_chunk: bool = dirty_chunks.is_empty()
		if not dirty_chunks.is_empty():
			for cell: Vector2i in mesh_cells:
				var chunk: Vector2i = Vector2i(floori(float(cell.x) / float(TERRAIN_CHUNK_CELLS)),
					floori(float(cell.y) / float(TERRAIN_CHUNK_CELLS)))
				if dirty_chunks.has(chunk):
					touches_dirty_chunk = true
					break
		if (dirty_variants.is_empty() or dirty_variants.has(variant)) and touches_dirty_chunk:
			(terrain_mesh_nodes[key] as MeshInstance3D).free()
			terrain_mesh_nodes.erase(key)
			terrain_mesh_cells.erase(key)
			terrain_lighting_inputs.erase(key)
	var tools: Dictionary = {}
	var materials: Dictionary = {}
	var surface_parts: Dictionary = {}
	var used_details: Dictionary = {}
	var meshes: Dictionary = data["meshes"]
	var cells: Array = data["cells"]
	var normals: Array = data["normals"]
	var backdrop_samples: Dictionary = {}
	for entry: Dictionary in cells:
		if int(entry["flags"]) == 0x85:
			backdrop_samples[Vector2i(int(entry["x"]), int(entry["y"]))] = true
	var omitted_back_triangles: int = 0
	for entry: Dictionary in cells:
		if not terrain_flag_filter.is_empty() and not terrain_flag_filter.has(str(int(entry["flags"]))):
			continue
		var variant_index: int = clampi(int(entry.get("ground_variant", 1)) - 1, 0, 14)
		if not dirty_variants.is_empty() and not dirty_variants.has(variant_index):
			continue
		var block_parts: Array = meshes[str(int(entry["block"]))]
		var cell_origin: Vector2i = Vector2i(int(entry["x"]), int(entry["y"]))
		var chunk_origin: Vector2i = Vector2i(floori(float(cell_origin.x) / float(TERRAIN_CHUNK_CELLS)),
			floori(float(cell_origin.y) / float(TERRAIN_CHUNK_CELLS)))
		if not dirty_chunks.is_empty() and not dirty_chunks.has(chunk_origin):
			continue
		var cell_triangle_count: int = 0
		var cell_omitted_count: int = 0
		var floor_triangles: Array[PackedVector2Array] = []
		var borders_backdrop: bool = false
		for corner_offset: Vector2i in [Vector2i.ZERO, Vector2i.RIGHT, Vector2i.DOWN, Vector2i.ONE]:
			if backdrop_samples.has(cell_origin + corner_offset):
				borders_backdrop = true
		for part: Dictionary in block_parts:
			var values: Array = part["vertices"]
			var indices: Array = part["indices"]
			var normal_indices: Array = part["attributes"]
			var part_number: int = int(part["part"])
			var detail: String = source_profile.detail_texture(cell_origin, part_number)
			var ground_file: String = source_profile.ground_file(cell_origin, variant_index)
			var key: String = "%02d:%d:%s:%d:%d" % [variant_index, part_number,ground_file,
				chunk_origin.x,chunk_origin.y]
			if not tools.has(key):
				var new_surface: SurfaceTool = SurfaceTool.new()
				new_surface.begin(Mesh.PRIMITIVE_TRIANGLES)
				new_surface.set_custom_format(0, SurfaceTool.CUSTOM_RGBA_FLOAT)
				tools[key] = new_surface
				terrain_lighting_inputs[key] = {"points":PackedVector3Array(),"normals":PackedVector3Array(),"base":PackedInt32Array()}
				terrain_mesh_cells[key] = {}
				materials[key] = source_profile.terrain_material(variant_index, terrain_double_sided, terrain_cull_front,ground_file)
				surface_parts[key] = part_number
			used_details[detail] = true
			var surface: SurfaceTool = tools[key] as SurfaceTool
			terrain_mesh_cells[key][cell_origin] = true
			for triangle_start in range(0, indices.size(), 3):
				# Screenshot-validated reconstruction, not a port of GetBlockHole.
				# Keep floors and bevels while omitting the deepest flat closing
				# face adjacent to the source 0x85 samples.
				var backdrop_face: bool = borders_backdrop and int(part["part"]) == 0
				for corner in range(3):
					var depth_index: int = int(indices[triangle_start + corner]) * 5 + 2
					if absf(float(values[depth_index]) - 8.5) > 0.0001:
						backdrop_face = false
				if backdrop_face:
					cell_omitted_count += 1
					continue
				var triangle_points: Array[Vector3] = []
				for corner in range(3):
					var offset: int = int(indices[triangle_start + corner]) * 5
					# BDB corners encode depth as (game_z + 14) / 2.
					# PMP row is vertical, like the Tcl yoffset, not depth.
					triangle_points.append(Vector3(float(values[offset]) + float(entry["x"]),
						-(float(values[offset + 1]) + float(entry["y"])),
						BDB_DEPTH_SCALE * float(values[offset + 2]) + BDB_DEPTH_OFFSET))
				if absf(triangle_points[0].y - WALKABLE_FLOOR_Y) < 0.0001 \
						and absf(triangle_points[1].y - WALKABLE_FLOOR_Y) < 0.0001 \
						and absf(triangle_points[2].y - WALKABLE_FLOOR_Y) < 0.0001:
					var floor_triangle: PackedVector2Array = PackedVector2Array()
					for point: Vector3 in triangle_points:
						floor_triangle.append(Vector2(point.x, point.z))
					if absf((floor_triangle[1] - floor_triangle[0]).cross(floor_triangle[2] - floor_triangle[0])) > 0.00001:
						floor_triangles.append(floor_triangle)
				for corner in range(3):
					var vertex_index: int = int(indices[triangle_start + corner])
					var offset: int = vertex_index * 5
					var source_normal: Array = normals[int(normal_indices[vertex_index])]
					# Inverse transpose for unpacking Z; the outer renderer-space
					# transform restores the normal from sphere.dat.
					surface.set_normal(Vector3(float(source_normal[0]), -float(source_normal[1]),
						float(source_normal[2]) / BDB_DEPTH_SCALE).normalized())
					surface.set_uv(Vector2(float(values[offset + 3]), float(values[offset + 4])))
					surface.set_uv2(source_profile.detail_slot(detail))
					var source_local: Vector3 = Vector3(values[offset],values[offset+1],values[offset+2])
					var source_point: Vector3 = source_local+Vector3(cell_origin.x,cell_origin.y,0)
					var light_normal: Vector3 = Vector3(source_normal[0],source_normal[1],source_normal[2])
					var base_byte: int = source_profile.terrain_base_byte(cell_origin,Vector2(source_local.x,source_local.y))
					var light_channels: Dictionary = TERRAIN_ILLUMINATION.channels(source_point,light_normal,base_byte,
						baked_terrain_lights,source_profile.terrain_render["constants"])
					surface.set_color(light_channels["diffuse"])
					surface.set_custom(0,light_channels["secondary"])
					surface.add_vertex(triangle_points[corner])
					terrain_lighting_inputs[key]["points"].append(source_point)
					terrain_lighting_inputs[key]["normals"].append(light_normal)
					terrain_lighting_inputs[key]["base"].append(base_byte)
			cell_triangle_count += int(indices.size() / 3.0)
		terrain_cell_triangles[cell_origin] = cell_triangle_count
		terrain_cell_omitted[cell_origin] = cell_omitted_count
		terrain_floor_triangles[cell_origin] = floor_triangles
	# Index actual floor triangle extents for approach queries, instead of
	# scanning all 943 terrain cells for every candidate navigation node.
	floor_cells_by_x.clear()
	for cell: Vector2i in terrain_floor_triangles:
		for triangle: PackedVector2Array in terrain_floor_triangles[cell]:
			var minimum: float = minf(triangle[0].x,minf(triangle[1].x,triangle[2].x))
			var maximum: float = maxf(triangle[0].x,maxf(triangle[1].x,triangle[2].x))
			for column: int in range(floori(minimum-0.00001),floori(maximum+0.00001)+1):
				if not floor_cells_by_x.has(column):
					floor_cells_by_x[column] = {}
				floor_cells_by_x[column][cell] = true
	triangle_count = 0
	for value: int in terrain_cell_triangles.values():
		triangle_count += value
	for value: int in terrain_cell_omitted.values():
		omitted_back_triangles += value
	print("TERRAIN_BACKDROP_OPENING source_triangles=%d omitted_back_faces=%d retained_triangles=%d" % [triangle_count, omitted_back_triangles, triangle_count - omitted_back_triangles])
	var surface_count: int = 0
	for key: String in tools:
		var terrain_mesh: ArrayMesh = (tools[key] as SurfaceTool).commit()
		if terrain_mesh == null or terrain_mesh.get_surface_count() == 0:
			continue
		terrain_mesh.surface_set_material(0, materials[key] as Material)
		var instance: MeshInstance3D = MeshInstance3D.new()
		instance.name = "NativeTerrain_" + key.replace(":", "_").replace(".tga", "")
		instance.mesh = terrain_mesh
		instance.visible = include_terrain and (terrain_part_filter.is_empty() or terrain_part_filter.has(str(surface_parts[key])))
		scene_root.add_child(instance)
		terrain_mesh_nodes[key] = instance
		if build_collision:
			var body: StaticBody3D = StaticBody3D.new()
			body.name = "NativeGroundCollision"
			body.collision_layer = 1
			body.collision_mask = 0
			instance.add_child(body)
			var collision: CollisionShape3D = CollisionShape3D.new()
			collision.shape = terrain_mesh.create_trimesh_shape()
			body.add_child(collision)
		surface_count += 1
	print("NATIVE_L2M_READY cells=%d detail_textures=%d surfaces=%d" % [cells.size(), used_details.size(), surface_count])


func _build_native_walkmap_overlay() -> void:
	# Optional source-data view; never part of normal play or collision geometry.
	if is_instance_valid(native_walkmap_overlay):
		native_walkmap_overlay.free()
	var surface: SurfaceTool = SurfaceTool.new()
	surface.begin(Mesh.PRIMITIVE_TRIANGLES)
	var offsets: Array[Vector2] = [Vector2(-0.04, -0.04), Vector2(0.04, -0.04), Vector2(0.04, 0.04),
		Vector2(-0.04, -0.04), Vector2(0.04, 0.04), Vector2(-0.04, 0.04)]
	var width: int = native_walkmap.sample_bounds.size.x
	var shown: int = 0
	for index: int in range(native_walkmap.flags.size()):
		if native_walkmap.unknown_samples[index] != 0:
			continue
		var value: int = int(native_walkmap.flags[index])
		if (value & 1) == 0:
			continue
		shown += 1
		var center: Vector2 = Vector2(float(index % width), floorf(float(index) / float(width))) * 0.125
		surface.set_color(Color(0.1, 0.9, 1.0, 0.9) if (value & 2) != 0 else Color(1.0, 0.5, 0.05, 0.9))
		for offset: Vector2 in offsets:
			surface.set_normal(Vector3.BACK)
			surface.add_vertex(Vector3(center.x + offset.x, -(center.y + offset.y), DIG_MARK_DEPTH + 0.2))
	var material: StandardMaterial3D = StandardMaterial3D.new()
	material.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
	material.vertex_color_use_as_albedo = true
	material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA
	material.cull_mode = BaseMaterial3D.CULL_DISABLED
	native_walkmap_overlay = MeshInstance3D.new()
	native_walkmap_overlay.name = "SourceNavigationSamples"
	native_walkmap_overlay.mesh = surface.commit()
	native_walkmap_overlay.material_override = material
	scene_root.add_child(native_walkmap_overlay)
	print("NATIVE_WALKMAP_OVERLAY bit0_samples=%d stage=%s" % [shown, native_walkmap.stage])


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
	scene_environment = environment
	environment.background_mode = Environment.BG_COLOR
	environment.background_color = Color(0.035, 0.045, 0.055)
	environment.ambient_light_source = Environment.AMBIENT_SOURCE_COLOR
	# Temporary Godot adapter. Native vertex illumination has a separate
	# normal-dependent base and local light accumulation, still being ported.
	environment.ambient_light_color = Color.WHITE
	environment.ambient_light_energy = 0.3
	var world_environment: WorldEnvironment = WorldEnvironment.new()
	world_environment.environment = environment
	add_child(world_environment)
	var light: DirectionalLight3D = DirectionalLight3D.new()
	light.rotation_degrees = Vector3(-32.0, -25.0, 0.0)
	light.light_energy = 0.6
	add_child(light)
	var source_light_count: int = source_profile.add_lights(scene_root)
	print("NATIVE_SCENE_LIGHTS_READY lights=%d horizons=%d terrain_materials=source native_diffuse_preview=%s models=%s" % [source_light_count, source_profile.data.get("horizons", []).size(),source_profile.use_native_diffuse,"world_subset_and_godot" if native_world_model_lighting else "godot_adapter"])


func _build_caption() -> void:
	var layer: CanvasLayer = CanvasLayer.new()
	layer.name = "HUDLayer"
	add_child(layer)
	status = Label.new()
	status.name = "Status"
	status.position = Vector2(18.0, 14.0)
	status.text = "Diggles multiplayer start 010\n1 finger: rotate | 2 fingers: pan/zoom | Tap dwarf to move\nT corridor mode (green) | C cave size (%d)\n%d gnomes / %d models / %d textures" % [selected_cave_brush, dwarf_nodes.size(), model_count, texture_count]
	status.add_theme_color_override("font_color", Color.WHITE)
	status.add_theme_color_override("font_shadow_color", Color.BLACK)
	status.add_theme_constant_override("shadow_offset_x", 1)
	status.add_theme_constant_override("shadow_offset_y", 1)
	layer.add_child(status)
	var clock_margin: MarginContainer = MarginContainer.new()
	clock_margin.name = "GameClock"
	layer.add_child(clock_margin)
	clock_margin.set_anchors_and_offsets_preset(Control.PRESET_TOP_RIGHT)
	clock_margin.offset_left = -190.0
	clock_margin.offset_right = -18.0
	clock_margin.offset_top = 14.0
	clock_margin.offset_bottom = 44.0
	clock_margin.mouse_filter = Control.MOUSE_FILTER_IGNORE
	clock_caption = Label.new()
	clock_caption.horizontal_alignment = HORIZONTAL_ALIGNMENT_RIGHT
	clock_caption.mouse_filter = Control.MOUSE_FILTER_IGNORE
	clock_margin.add_child(clock_caption)
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
	_cancel_corridor_stroke()
	# A release from the previous tool must not become a click for the new one.
	mouse_dragged = true
	mouse_pressed_dwarf = false
	if not touch_points.is_empty():
		gesture_had_multiple_touches = true
	dig_tool = tool
	corridor_mode = tool in ["Коридор", "Ластик"]
	if tool.begins_with("Пещера"):
		selected_cave_brush = int(tool.right(1))
	for child: Button in dig_toolbar.get_children():
		child.set_pressed_no_signal(child.text == tool)
	status.text = tool
	tool_cursor.text = tool
	tool_cursor.position = get_viewport().get_mouse_position() + Vector2(12, 12)
	tool_cursor.visible = false
	_update_hover_brush(get_viewport().get_mouse_position())


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
	if scene_environment != null:
		var horizon: Dictionary = source_profile.horizon_at(Vector2(camera.position.x, -camera.position.y))
		_update_model_horizon(horizon)
		if not horizon.is_empty():
			var color: Array = horizon["color"]
			scene_environment.background_color = Color(float(color[0]), float(color[1]), float(color[2]))
		else:
			scene_environment.background_color = Color(0.035, 0.045, 0.055)


func _process(_delta: float) -> void:
	game_clock.paused = simulation_paused
	game_clock.time_scale = simulation_time_scale
	var game_delta: float = game_clock.advance(_delta)
	var shown_minutes: int = int(floorf(fmod(WORK_CLOCK.hours(game_clock.seconds), 12.0) * 60.0))
	var clock_text: String = "%02d:%02d" % [floori(float(shown_minutes) / 60.0), shown_minutes % 60]
	if simulation_paused:
		clock_text += "  Пауза"
	if clock_caption.text != clock_text:
		clock_caption.text = clock_text
	if game_delta > 0.0:
		dwarf_life.advance()
		dwarf_sleep.update()
		dwarf_sparetime.update()
		actor_tasks.dispatch()
		_update_dwarf_locomotion(game_delta)
		_update_dwarf_dig_jobs(game_delta)
		_update_pending_manual_dig()
		actor_tasks.advance(game_delta)
		_update_dwarf_idle_animations(game_delta)
		# Complete at most one previously queued baked-light bucket before a
		# source torch can enqueue more work this frame.
		_step_torch_terrain_lighting()
		_step_model_lighting()
		_update_automatic_torches(game_delta)
		_update_source_flames()
		if terrain_refresh_pending:
			# Shared terrain meshes and the complete floor grid are expensive to
			# rebuild. Native walk samples have already changed for the current
			# strike, so defer redraw until the active mining batch settles.
			if not dwarf_dig_jobs.is_empty():
				terrain_refresh_wait = TERRAIN_REFRESH_COALESCE_SECONDS
			else:
				terrain_refresh_wait -= game_delta
				if terrain_refresh_wait <= 0.0:
					_flush_terrain_refresh()
		if navigation_refresh_pending:
			# Source walk samples already drive digging/climbing. The broad floor
			# A* is only an adapter for long player-directed walks, so rebuild it
			# between active mining jobs instead of once per pick impact.
			if not dwarf_dig_jobs.is_empty():
				navigation_refresh_wait = TERRAIN_REFRESH_COALESCE_SECONDS
			else:
				navigation_refresh_wait -= game_delta
				if navigation_refresh_wait <= 0.0:
					_flush_navigation_refresh()
	var camera_move: Vector2 = Input.get_vector("move_left", "move_right", "move_up", "move_down")
	if camera_move != Vector2.ZERO:
		focus.x += camera_move.x * _delta * 9.0
		focus.y -= camera_move.y * _delta * 9.0
		_update_camera()
	# No work advances without a worker in normal play. The previous timer is
	# retained only as an explicitly requested state/skin demonstration.
	if automatic_cave_demo and not native_active_caves.is_empty():
		cave_dig_timer += game_delta
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
	# Touch events already drive selection. Emulated mouse events must not
	# confirm the same stroke a second time; GUI controls still receive them.
	if event is InputEventMouse and event.device == InputEvent.DEVICE_ID_EMULATION:
		return
	if event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_LEFT:
		if event.pressed:
			toolbar_mouse_down = dig_toolbar.get_global_rect().has_point(event.position)
			if toolbar_mouse_down:
				_cancel_corridor_stroke()
		if toolbar_mouse_down:
			if not event.pressed:
				toolbar_mouse_down = false
			return
	if event is InputEventMouseMotion:
		tool_cursor.position = event.position + Vector2(12, 12)
		_update_hover_brush(event.position)
	if event is InputEventMouseMotion and toolbar_mouse_down:
		return
	if event is InputEventScreenTouch:
		if event.pressed and dig_toolbar.get_global_rect().has_point(event.position):
			toolbar_touch_ids[event.index] = true
			_cancel_corridor_stroke()
		if toolbar_touch_ids.has(event.index):
			if not event.pressed:
				toolbar_touch_ids.erase(event.index)
			return
	if event is InputEventScreenDrag and toolbar_touch_ids.has(event.index):
		return
	if _handle_corridor_input(event):
		return
	if event is InputEventMouseMotion and event.button_mask & MOUSE_BUTTON_MASK_LEFT:
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
			elif mouse_pressed_dwarf:
				mouse_pressed_dwarf = false
			elif not mouse_dragged and mouse_press_position.distance_to(event.position) <= 8.0:
				if not corridor_mode:
					_handle_tap(event.position)
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
			status.text = "Коридор: протяните выделение и отпустите" if corridor_mode else "Выбор"
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
	if corridor_mode:
		return # Corridor touch release was handled by its stroke controller.
	var nearest: Node3D = _dwarf_at_screen(screen_position)
	if nearest != null:
		_select_dwarf(nearest)
	elif selected_dwarf != null and not corridor_mode and not dig_tool.begins_with("Пещера"):
		_command_selected_dwarf(screen_position)
	else:
		var cave_cell: Variant = _screen_to_terrain_cell(screen_position)
		if cave_cell is Vector2i:
			if not dig_tool.begins_with("Пещера"):
				return
			if open_air.has(cave_cell):
				return
			# Hover and commit share the source cursor. native_cave_brush_cells
			# already subtracts the native (16,32) anchor.
			var cursor: Vector2i = cave_cell
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
	corridor_visual = MeshInstance3D.new()
	corridor_visual.name = "NativeCorridorSelection"
	corridor_preview_root.add_child(corridor_visual)
	var material: StandardMaterial3D = StandardMaterial3D.new()
	material.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
	material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA
	material.depth_draw_mode = BaseMaterial3D.DEPTH_DRAW_DISABLED
	material.cull_mode = BaseMaterial3D.CULL_DISABLED
	# Presentation color remains an adapter; contour data comes from the EXE.
	material.albedo_color = Color(0.22, 0.44, 0.15, 0.38)
	corridor_visual.material_override = material
	corridor_visual.visible = false
	cave_visual = MeshInstance3D.new()
	cave_visual.name = "NativeCaveSelection"
	corridor_preview_root.add_child(cave_visual)
	var cave_material: StandardMaterial3D = material.duplicate() as StandardMaterial3D
	# Original selection reads as a muted blue under the cave lighting. Keep it
	# distinct from the green corridor without an emissive-looking cyan fill.
	cave_material.albedo_color = Color(0.12, 0.20, 0.48, 0.30)
	cave_visual.material_override = cave_material
	cave_visual.visible = false


func _update_hover_brush(screen: Vector2) -> void:
	if corridor_preview_root == null:
		return
	if hover_visual == null:
		hover_visual = MeshInstance3D.new()
		hover_visual.name = "BrushOutline"
		corridor_preview_root.add_child(hover_visual)
		var material: StandardMaterial3D = StandardMaterial3D.new()
		material.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
		material.albedo_color = Color(0.42, 0.56, 0.32)
		material.cull_mode = BaseMaterial3D.CULL_DISABLED
		hover_visual.material_override = material
	hover_visual.visible = false
	if dig_tool == "Выбор" or dig_toolbar.get_global_rect().has_point(screen):
		return
	var hover_material: StandardMaterial3D = hover_visual.material_override as StandardMaterial3D
	hover_material.albedo_color = Color(0.30,0.32,0.56) if dig_tool.begins_with("Пещера") else (Color(0.40,0.42,0.43) if dig_tool == "Ластик" else Color(0.42,0.56,0.32))
	var raw: Variant = _terrain_point(screen)
	if not raw is Vector2:
		return
	var samples: Dictionary = {}
	if dig_tool == "Коридор":
		var stroke: RefCounted = CORRIDOR_STROKE.new()
		stroke.begin(raw, _corridor_sample_bounds())
		for point: Vector2i in stroke.samples():
			samples[point] = true
	elif dig_tool.begins_with("Пещера"):
		for cell: Vector3i in native_cave_brush_cells(selected_cave_brush, int(raw.x), int(raw.y)):
			samples[Vector2i(cell.x, cell.z)] = true
	elif dig_tool == "Ластик":
		# Same native 2x2 tool-5 footprint as an erase press, shown as a grey
		# outline only. Hover never changes marks.
		for point: Vector2i in ERASE_BRUSH.between(Vector3(raw.x,raw.y,DIG_MARK_DEPTH), Vector3(raw.x,raw.y,DIG_MARK_DEPTH), tunnel_rules.bounds):
			samples[point] = true
	if samples.is_empty():
		return
	var key: String = str(samples.keys())
	hover_visual.visible = true
	if key == hover_key:
		return
	hover_key = key
	var contour: Script = load("res://scripts/native_corridor_contour.gd")
	var triangles: PackedVector2Array = contour.build_triangles(samples,true)
	var surface: SurfaceTool = SurfaceTool.new()
	surface.begin(Mesh.PRIMITIVE_TRIANGLES)
	for point: Vector2 in triangles:
		surface.add_vertex(Vector3(point.x,-point.y,DIG_MARK_DEPTH+0.01))
	hover_visual.mesh = surface.commit() if not triangles.is_empty() else null


func _notification(what: int) -> void:
	if what == NOTIFICATION_WM_WINDOW_FOCUS_OUT:
		_cancel_corridor_stroke()


func _handle_corridor_input(event: InputEvent) -> bool:
	if not corridor_mode:
		return false
	if event is InputEventKey and event.pressed and event.physical_keycode == KEY_ESCAPE:
		if corridor_stroke.active or erase_brush.active:
			_cancel_corridor_stroke()
			status.text = "Разметка отменена"
		else:
			_choose_tool("Выбор")
		return true
	if event is InputEventMouseButton:
		if event.button_index == MOUSE_BUTTON_RIGHT and event.pressed:
			_cancel_corridor_stroke()
			return true
		if event.button_index == MOUSE_BUTTON_LEFT:
			if event.pressed:
				_begin_corridor_stroke(event.position)
			elif dig_toolbar.get_global_rect().has_point(event.position):
				_cancel_corridor_stroke()
			else:
				if erase_brush.active:
					_update_corridor_stroke(event.position)
				_finish_corridor_stroke()
			return true
	if event is InputEventMouseMotion and (event.button_mask & MOUSE_BUTTON_MASK_LEFT):
		_update_corridor_stroke(event.position)
		return true
	if event is InputEventScreenTouch:
		if event.pressed:
			if touch_points.is_empty() and not gesture_had_multiple_touches:
				_begin_corridor_stroke(event.position)
				corridor_touch_id = event.index
			else:
				_cancel_corridor_stroke()
		elif event.index == corridor_touch_id:
			if event.canceled or gesture_had_multiple_touches:
				_cancel_corridor_stroke()
			else:
				if erase_brush.active:
					_update_corridor_stroke(event.position)
				_finish_corridor_stroke()
		# Preserve the existing two-finger gesture tracker.
		return false
	if event is InputEventScreenDrag and touch_points.size() == 1 and not gesture_had_multiple_touches:
		touch_points[event.index] = event.position
		if event.index == corridor_touch_id:
			_update_corridor_stroke(event.position)
		return true
	return false


func _corridor_sample_bounds() -> Rect2i:
	# Native commit's exclusive end is world_max-1. The point validator then
	# applies the interior border of this explicitly standalone local world.
	return Rect2i(Vector2i.ZERO, tunnel_rules.bounds.size - Vector2i.ONE)


func _begin_corridor_stroke(screen_position: Vector2) -> void:
	var point: Variant = _terrain_point(screen_position)
	if not point is Vector2:
		_cancel_corridor_stroke()
		return
	if dig_tool == "Ластик":
		_erase_at(point, true)
		return
	corridor_stroke.begin(point, _corridor_sample_bounds())
	_rebuild_corridor_preview()


func _update_corridor_stroke(screen_position: Vector2) -> void:
	var point: Variant = _terrain_point(screen_position)
	if point is Vector2:
		if erase_brush.active:
			_erase_at(point)
			return
		corridor_stroke.update(point)
	_rebuild_corridor_preview()


func _finish_corridor_stroke() -> void:
	if erase_brush.active:
		erase_brush.cancel()
		corridor_touch_id = -1
		return
	if not corridor_stroke.active:
		return
	var samples: Array[Vector2i] = corridor_stroke.finish()
	corridor_touch_id = -1
	var changed: int = 0
	for sample: Vector2i in samples:
		if native_mark_corridor_cell(0, sample):
			changed += 1
	native_dig_groups.finish_commit(0)
	_rebuild_corridor_preview()
	status.text = "Коридор размечен: %d точек; ожидает исполнителя" % changed if changed > 0 else "Здесь пока нельзя разметить коридор"
	print("NATIVE_CORRIDOR_COMMIT samples=%d accepted=%d" % [samples.size(), changed])


func _cancel_corridor_stroke() -> void:
	corridor_stroke.cancel()
	erase_brush.cancel()
	corridor_touch_id = -1
	if corridor_visual != null:
		_rebuild_corridor_preview()


func _erase_at(point: Vector2, begin: bool = false) -> void:
	if not point.is_finite():
		return
	var start_point: Vector2i = Vector2i(int(point.x), int(point.y))
	if not tunnel_rules.bounds.has_point(start_point):
		return
	var cursor: Vector3 = Vector3(point.x, point.y, DIG_MARK_DEPTH)
	if begin:
		erase_brush.active = true
		erase_brush.previous = cursor
	var changed: int = 0
	var seed_mark: int = int(native_mark_nibbles.get(_native_cell_key(start_point, 0, 0), 0))
	if (seed_mark & 8) != 0:
		changed = _erase_cave_group(start_point)
	else:
		for sample: Vector2i in erase_brush.update(cursor, tunnel_rules.bounds):
			var key: String = _native_cell_key(sample, 0, 0)
			var mark: int = int(native_mark_nibbles.get(key, 0))
			if mark != 0 and (mark & 8) == 0:
				native_clear_cave_mark(0, sample)
				changed += 1
	_rebuild_corridor_preview()
	status.text = "Снято меток: %d" % changed


func _erase_cave_group(start_point: Vector2i) -> int:
	# Existing local pending-record model. Native removes only the first
	# containing rectangle, replacing it by the last entry (0x58EC00).
	for index: int in range(native_active_caves.size()):
		var record: Dictionary = native_active_caves[index]
		if int(record["owner_id"]) != 0 or int(record["layer"]) != 0:
			continue
		var lower: Vector2i = Vector2i(native_terrain_width, native_terrain_height)
		var upper: Vector2i = Vector2i.ZERO
		for sample: Vector3i in record["cells"]:
			lower = Vector2i(mini(lower.x, sample.x), mini(lower.y, sample.z))
			upper = Vector2i(maxi(upper.x, sample.x), maxi(upper.y, sample.z))
		if start_point.x >= lower.x and start_point.y >= lower.y and start_point.x <= upper.x and start_point.y <= upper.y:
			native_active_caves[index] = native_active_caves.back()
			native_active_caves.pop_back()
			break
	# 0x5675AF..0x567733: four-connected cave marks of the same group.
	# In this local model the group is represented by owner 0 / layer 0 keys.
	var pending: Array[Vector2i] = [start_point]
	var head: int = 0
	var changed: int = 0
	while head < pending.size():
		var point: Vector2i = pending[head]
		head += 1
		var key: String = _native_cell_key(point, 0, 0)
		if (int(native_mark_nibbles.get(key, 0)) & 8) == 0:
			continue
		native_clear_cave_mark(0, point)
		changed += 1
		for offset: Vector2i in [Vector2i.LEFT, Vector2i.RIGHT, Vector2i.UP, Vector2i.DOWN]:
			if tunnel_rules.bounds.has_point(point + offset):
				pending.append(point + offset)
	return changed


func _corridor_mark_samples() -> Dictionary:
	var samples: Dictionary = {}
	for key: String in native_mark_nibbles:
		if int(native_mark_nibbles[key]) != 3:
			continue
		var parts: PackedStringArray = key.split(":")
		if parts.size() == 4 and int(parts[2]) == 0 and int(parts[3]) == 0:
			samples[Vector2i(int(parts[0]), int(parts[1]))] = true
	return samples


func _rebuild_corridor_preview() -> void:
	if corridor_visual == null:
		return
	var samples: Dictionary = {}
	var cave_samples: Dictionary = {}
	for point: Vector2i in _work_marks():
		if (_work_mark(point) & 8) != 0:
			cave_samples[point] = true
		elif (_work_mark(point) & 0xB) != 0:
			samples[point] = true
	if corridor_stroke.active:
		var accepted: int = 0
		for sample: Vector2i in corridor_stroke.samples():
			if _corridor_point_rule(sample) == TUNNEL_RULES.ACCEPT:
				samples[sample] = true
				accepted += 1
		status.text = "Предварительная разметка: %d точек" % accepted
	_update_work_preview_mesh(samples, corridor_visual)
	_update_work_preview_mesh(cave_samples, cave_visual)


func _update_work_preview_mesh(samples: Dictionary, visual: MeshInstance3D) -> void:
	if samples.is_empty():
		visual.visible = false
		visual.mesh = null
		return
	if corridor_contour == null:
		var contour_path: String = "res://scripts/native_corridor_contour.gd"
		if ResourceLoader.exists(contour_path):
			corridor_contour = load(contour_path) as Script
		if corridor_contour == null:
			push_error("Native corridor contour resource is missing")
			return
	var triangles: PackedVector2Array = corridor_contour.build_triangles(samples)
	if triangles.is_empty():
		visual.visible = false
		return
	var surface: SurfaceTool = SurfaceTool.new()
	surface.begin(Mesh.PRIMITIVE_TRIANGLES)
	for point: Vector2 in triangles:
		surface.add_vertex(Vector3(point.x, -point.y, DIG_MARK_DEPTH))
	visual.mesh = surface.commit()
	visual.visible = true


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


func _screen_to_terrain_cell(screen_position: Vector2) -> Variant:
	var point: Variant = _terrain_point(screen_position)
	if point is Vector2:
		return Vector2i(point.floor())
	return null


func _walk_floor_at_screen(screen_position: Vector2) -> Variant:
	var origin: Vector3 = camera.project_ray_origin(screen_position)
	var query: PhysicsRayQueryParameters3D = PhysicsRayQueryParameters3D.create(origin,
		origin + camera.project_ray_normal(screen_position) * 200.0, 1)
	var hit: Dictionary = get_world_3d().direct_space_state.intersect_ray(query)
	if hit.is_empty() or Vector3(hit["normal"]).dot(Vector3.UP) < 0.65:
		return null
	return scene_root.to_local(hit["position"])


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
		status.text = "%s выбран: нажмите на цель или область копания" % dwarf.name


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
	# An overlay per model part creates seams around the beard, limbs, helmet
	# and even work attachments.  The original selection reads as one exterior
	# contour, therefore use one combined proxy made exclusively from body mesh.
	var proxy: MeshInstance3D = _dwarf_outline_proxy(dwarf)
	proxy.visible = enabled
	if enabled:
		_refresh_dwarf_outline(dwarf)


func _dwarf_outline_proxy(dwarf: Node3D) -> MeshInstance3D:
	if dwarf_outline_proxies.has(dwarf):
		return dwarf_outline_proxies[dwarf] as MeshInstance3D
	var proxy: MeshInstance3D = MeshInstance3D.new()
	proxy.name = "SelectionSilhouette"
	proxy.cast_shadow = GeometryInstance3D.SHADOW_CASTING_SETTING_OFF
	proxy.material_override = selection_outline_material
	proxy.visible = false
	dwarf.add_child(proxy)
	dwarf_outline_proxies[dwarf] = proxy
	return proxy


func _refresh_dwarf_outline(dwarf: Node3D) -> void:
	if dwarf != selected_dwarf or not dwarf_locomotion_visuals.has(dwarf):
		return
	var visuals: Dictionary = dwarf_locomotion_visuals[dwarf]
	var body_meshes: Array[ArrayMesh] = []
	var current: Variant = visuals.get("current")
	if current is Node3D and (current as Node3D).visible:
		for instance: MeshInstance3D in visuals["body_instances"]:
			if instance.visible and instance.mesh is ArrayMesh:
				body_meshes.append(instance.mesh as ArrayMesh)
	else:
		for instance: MeshInstance3D in visuals["default"]:
			if instance.visible and instance.mesh is ArrayMesh:
				body_meshes.append(instance.mesh as ArrayMesh)
	var proxy: MeshInstance3D = _dwarf_outline_proxy(dwarf)
	proxy.mesh = _combined_dwarf_outline_mesh(body_meshes)


func _combined_dwarf_outline_mesh(body_meshes: Array[ArrayMesh]) -> ArrayMesh:
	var key_parts: PackedStringArray = PackedStringArray()
	for mesh: ArrayMesh in body_meshes:
		key_parts.append(str(mesh.get_instance_id()))
	var key: String = ":".join(key_parts)
	if dwarf_outline_mesh_cache.has(key):
		return dwarf_outline_mesh_cache[key] as ArrayMesh
	var surface: SurfaceTool = SurfaceTool.new()
	surface.begin(Mesh.PRIMITIVE_TRIANGLES)
	for mesh: ArrayMesh in body_meshes:
		for surface_index: int in range(mesh.get_surface_count()):
			var arrays: Array = mesh.surface_get_arrays(surface_index)
			var vertices: PackedVector3Array = arrays[Mesh.ARRAY_VERTEX]
			var normals: PackedVector3Array = arrays[Mesh.ARRAY_NORMAL]
			var index_data: Variant = arrays[Mesh.ARRAY_INDEX]
			var indices: PackedInt32Array = index_data if index_data is PackedInt32Array else PackedInt32Array()
			if indices.is_empty():
				for index: int in range(vertices.size()):
					surface.set_normal(normals[index] if index < normals.size() else Vector3.UP)
					surface.add_vertex(vertices[index])
			else:
				for index: int in indices:
					surface.set_normal(normals[index] if index < normals.size() else Vector3.UP)
					surface.add_vertex(vertices[index])
	var combined: ArrayMesh = surface.commit()
	dwarf_outline_mesh_cache[key] = combined
	return combined


func _command_selected_dwarf(screen_position: Vector2) -> void:
	actor_tasks.interrupt(selected_dwarf)
	var picked: Variant = _terrain_point(screen_position)
	if picked is Vector2:
		var point: Vector2i = Vector2i(roundi(picked.x), roundi(picked.y))
		if native_mark_nibbles.has(_native_cell_key(point, 0, 0)):
			actor_tasks.dig(selected_dwarf, point, false)
			return
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
					dwarf_walk_actions[selected_dwarf].barrel = barrel
		return
	if picked is Vector2:
		var clicked_floor: Variant = _walk_floor_at_screen(screen_position)
		var native_target: Vector3 = Vector3(picked.x, picked.y, 14.5)
		if clicked_floor is Vector3:
			native_target = Vector3(clicked_floor.x, -clicked_floor.y, clicked_floor.z)
		var target_request: Dictionary = query_native_walk_target(native_target)
		var surface_target: Variant = target_request.get("local_sample") if target_request.get("status") == "ok" \
				and bool(target_request.get("found_navigation", false)) else null
		if surface_target is Vector2i and (absf(float(surface_target.y) * 0.125 + WALKABLE_FLOOR_Y) > 0.25 \
				or absf(selected_dwarf.position.y - WALKABLE_FLOOR_Y) > 0.25 \
				or int(dwarf_surface_modes.get(selected_dwarf, 2)) == 0 \
				or native_walkmap.is_newly_navigable(surface_target) \
				or (int(native_walkmap.sample(surface_target)) & 2) == 0 \
				or float(surface_target.x) * 0.125 < WALKABLE_FLOOR_MIN_X \
				or float(surface_target.x) * 0.125 > WALKABLE_FLOOR_MAX_X):
			var depth_goal: Variant = null
			if clicked_floor is Vector3:
				depth_goal = clicked_floor.z
			var goal: Vector3 = Vector3(float(surface_target.x)*0.125,-float(surface_target.y)*0.125,
				float(depth_goal) if depth_goal != null else selected_dwarf.position.z)
			actor_tasks.walk(selected_dwarf,goal,false)
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
	actor_tasks.walk(selected_dwarf, resolved, false)


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
	if absf(dwarf.position.y - WALKABLE_FLOOR_Y) > 0.25 or int(dwarf_surface_modes.get(dwarf, 2)) == 0:
		var surface_target: Variant = _nearest_surface_sample(Vector2(local_target.x, -local_target.y), 0.8)
		if surface_target is Vector2i:
			assign_dwarf_surface_walk(dwarf,surface_target,true,false,local_target.z)
		return
	var path: Array[Vector3] = _navigation_path(dwarf.position, local_target)
	if path.size() < 2:
		print("DWARF_MOVE_REJECT no path")
		return
	_stop_dwarf_walk(dwarf)
	var walk: RefCounted = FLOOR_WALK.new()
	walk.path = path
	walk.target = path[path.size() - 1]
	var last_target: Vector3 = dwarf_last_walk_targets.get(dwarf, Vector3.INF)
	walk.fast = not is_inf(last_target.x) and Vector2(last_target.x, last_target.z).distance_to(
		Vector2(walk.target.x, walk.target.z)) < 3.0
	dwarf_last_walk_targets[dwarf] = walk.target
	var first_direction: Vector2 = Vector2(path[1].x - dwarf.position.x,
		path[1].z - dwarf.position.z).normalized()
	walk.pending_heading = atan2(first_direction.x, first_direction.y)
	var current_heading: float = float(dwarf_headings.get(dwarf, 0.0))
	var turn_delta: float = wrapf(walk.pending_heading - current_heading, -PI, PI)
	if absf(turn_delta) > 1.4:
		walk.state = &"drehen_ganz_links" if turn_delta > 0.0 else &"drehen_ganz"
	elif absf(turn_delta) > 0.2:
		walk.state = &"drehen_links" if turn_delta > 0.0 else &"drehen_rechts"
	else:
		walk.state = _walk_sequence(&"start", walk)
	dwarf_walk_actions[dwarf] = walk
	_sync_walk_debug(dwarf)
	_show_dwarf_animation_frame(dwarf, walk.state, 0)
	print("DWARF_WALK_START %s target=%s nodes=%d speed=%.3f" % [dwarf.name,
		str(walk.target), path.size(), _current_walk_speed(walk)])


func _walk_sequence(stage: StringName, walk: RefCounted = null) -> StringName:
	var fast: bool = walk.fast if walk != null else fast_walk
	var prefix: String = "laufen_schnell_" if fast else "gehen_"
	return StringName(prefix + String(stage))


func _dwarf_dig_clip(worker_position: Vector3, point: Vector2i) -> StringName:
	# z_dignwalk.tcl:388-420, ordinary tool, ground pose.
	var height: float = -worker_position.y - float(point.y)
	if height > 1.6:
		return &"buddeln_oben_normal"
	return &"buddeln_vorn" if height > 0.6 else &"buddeln_unten"


func _dwarf_dig_reachable(worker_position: Vector3, point: Vector2i) -> bool:
	# Source dig_check and vector_dist; initial exp_Stein=0, no laser/hammer.
	# Known source samples only; unknown neighbors cannot count as empty.
	var offset: Vector2 = Vector2(worker_position.x, -worker_position.y - 0.8) - Vector2(point)
	if offset.length() >= 3.0 or _dwarf_dig_clip(worker_position, point).is_empty():
		return false
	return _dwarf_dig_check(worker_position, point)


func _dwarf_dig_check(worker_position: Vector3, point: Vector2i) -> bool:
	# Tcl dig_check has no distance gate; dig_execute checks reach separately.
	var offset: Vector2 = Vector2(worker_position.x, -worker_position.y - 0.8) - Vector2(point)
	var direction: int
	if absf(offset.x) > absf(offset.y):
		direction = 1 if offset.x > 0.0 else 3
	else:
		direction = 2 if offset.y > 0.0 else 0
	var offsets: Array = [
		[Vector2i(0, -1), Vector2i(-1, -1), Vector2i(1, -1)],
		[Vector2i(1, 0), Vector2i(1, -1), Vector2i(1, 1)],
		[Vector2i(0, 1), Vector2i(-1, 1), Vector2i(1, 1)],
		[Vector2i(-1, 0), Vector2i(-1, -1), Vector2i(-1, 1)]]
	var free_neighbors: int = 0
	for neighbor: Vector2i in offsets[direction]:
		var height: Variant = terrain_state.current_height(point + neighbor)
		if height != null and int(height) < 13:
			free_neighbors += 1
	return free_neighbors >= 2


func assign_dwarf_dig(dwarf: Node3D, point: Vector2i) -> bool:
	if not is_instance_valid(dwarf) or not dwarf_nodes.has(dwarf):
		return false
	_cancel_dwarf_dig(dwarf)
	dwarf_dig_groups[dwarf] = -1
	var region: Dictionary = WORK_REGION.component(point,_work_marks())
	if region.is_empty():
		return false
	dwarf_manual_dig_tasks[dwarf] = {"region":region,"seed":point}
	return _assign_region_frontier(dwarf)


func _work_mark(point: Vector2i) -> int:
	return int(native_mark_nibbles.get(_native_cell_key(point,0,0),0))


func _work_marks() -> Dictionary:
	var result: Dictionary = {}
	for key: String in native_mark_nibbles:
		var parts: PackedStringArray = key.split(":")
		if parts.size()==4 and int(parts[2])==0 and int(parts[3])==0:
			result[Vector2i(int(parts[0]),int(parts[1]))] = int(native_mark_nibbles[key])
	return result


func _remember_work_region(dwarf: Node3D, origin: Vector2i) -> void:
	if not dwarf_manual_dig_tasks.has(dwarf):
		return
	var connected: Dictionary = WORK_REGION.component(origin,_work_marks())
	for point: Vector2i in connected:
		dwarf_manual_dig_tasks[dwarf]["region"][point] = true


func _assign_region_frontier(dwarf: Node3D) -> bool:
	if not dwarf_manual_dig_tasks.has(dwarf):
		return false
	var task: Dictionary = dwarf_manual_dig_tasks[dwarf]
	var marks: Dictionary = _work_marks()
	# Retain old cells so consuming a bridge does not split the assigned task.
	var expanded: Dictionary = {}
	for point: Vector2i in task["region"].keys():
		if (int(marks.get(point,0)) & 0xB) != 0 and not expanded.has(point):
			var connected: Dictionary = WORK_REGION.component(point,marks)
			expanded.merge(connected)
			task["region"].merge(connected)

	var points: Array[Vector2i] = WORK_REGION.ordered(task["region"],marks,Vector2(dwarf.position.x,-dwarf.position.y))
	var remaining: int = 0
	var removed_completed: bool = false
	for point: Vector2i in points:
		var next: Variant = terrain_state.next_height(point)
		if next != null and (int(next) == -1 or NATIVE_DIG_RULES.target_height(_work_mark(point)) > int(next)):
			native_clear_cave_mark(0,point)
			removed_completed = true
			continue
		remaining += 1
		# This is a host reachable-frontier adapter. get_digedge's C+34 owner
		# producer and native Calc1 are not fabricated here.
		if _assign_dwarf_dig_point(dwarf,point):
			return true
	if removed_completed:
		_rebuild_corridor_preview()
	if remaining == 0:
		_cancel_dwarf_dig(dwarf)
		native_finish_completed_caves()
		status.text = "Область копания завершена"
		return false
	_cancel_dwarf_dig(dwarf,false)
	task["terrain_revision"] = terrain_state.revision
	task["marks_revision"] = native_marks_revision
	task["reservations"] = dwarf_dig_jobs.size()
	status.text = "Задание сохранено: ждёт доступного забоя"
	return false


func _update_pending_manual_dig() -> void:
	for dwarf: Node3D in dwarf_manual_dig_tasks.keys():
		if dwarf_life.should_stop_auto_dig(dwarf) and not dwarf_dig_jobs.has(dwarf):
			_cancel_dwarf_dig(dwarf)
			continue
		if dwarf_dig_jobs.has(dwarf):
			continue
		var task: Dictionary = dwarf_manual_dig_tasks[dwarf]
		if int(task.get("terrain_revision",-1)) != terrain_state.revision \
				or int(task.get("marks_revision",-1)) != native_marks_revision \
				or int(task.get("reservations",-1)) != dwarf_dig_jobs.size():
			_assign_region_frontier(dwarf)


func _assign_dwarf_dig_point(dwarf: Node3D, point: Vector2i, rank: int = -1, source_point: Variant = null) -> bool:
	if (_work_mark(point) & 0xB) == 0:
		return false
	for worker: Node3D in dwarf_dig_jobs:
		if worker != dwarf and dwarf_dig_jobs[worker]["point"] == point:
			status.text = "Эту точку уже копает другой гном"
			return false
	var digpoint: Vector3 = source_point if source_point is Vector3 else Vector3(point.x, point.y, float(terrain_state.current_height(point)))
	var source_request: Dictionary = query_native_dig_stance(digpoint, dwarf.position)
	if absf(-WALKABLE_FLOOR_Y-0.8-float(point.y)) >= 3.0 \
			or absf(dwarf.position.y - WALKABLE_FLOOR_Y) > 0.25 or int(dwarf_surface_modes.get(dwarf, 2)) == 0 \
			or bool(dwarf_dig_jobs.get(dwarf, {}).get("surface", false)):
		return _assign_surface_dig(dwarf, point, digpoint, source_request, rank)
	var native_goal: Variant = source_request.get("point") if source_request.get("status") == "ok" and bool(source_request.get("found_navigation", false)) else null
	# Native vector_fixdig now supplies the preferred request. Route/final pose
	# remain an explicit projection to our supported floor, not native action-walk.
	var best: Vector3 = Vector3.INF
	var best_length: float = INF
	var best_alignment: float = INF
	var best_count: int = 0
	var future_floor: Dictionary = _future_floor_for_dig(point)
	for z: int in range(navigation_grid.region.size.y):
		for x: int in range(navigation_grid.region.size.x):
			var id: Vector2i = Vector2i(x, z)
			if navigation_grid.is_point_solid(id):
				continue
			var stance: Vector3 = _navigation_id_to_local(id)
			if not _dwarf_dig_reachable(stance, point):
				continue
			if not _has_source_floor(Vector2(stance.x, stance.z), future_floor):
				continue
			var path: Array[Vector3] = _navigation_path(dwarf.position, stance)
			if path.is_empty():
				continue
			var length: float = dwarf.position.distance_to(path[0])
			for index: int in range(1, path.size()):
				length += path[index - 1].distance_to(path[index])
			var alignment: float = 0.0
			if native_goal is Vector3:
				var dx: float = stance.x - native_goal.x
				var dz: float = stance.z - native_goal.z
				alignment = dx * dx + 0.25 * dz * dz
			# Choose the nearest supported stance first. The old alignment-first
			# adaptation made a worker traverse depth/side lanes just to match an
			# approximate native request, then repeat that search after each strike.
			if length < best_length - 0.00001 or (absf(length - best_length) <= 0.00001 and alignment < best_alignment):
				best = stance
				best_length = length
				best_alignment = alignment
				best_count = path.size()
	if is_inf(best.x):
		return _assign_surface_dig(dwarf, point, digpoint, source_request, rank)
	barrel_goal = null
	_stop_dwarf_walk(dwarf)
	dwarf_dig_jobs[dwarf] = {"point": point, "phase": "approach", "stance": best, "rank": rank}
	dwarf_dig_jobs[dwarf]["digpoint"] = digpoint
	dwarf_dig_jobs[dwarf]["source_walk_request"] = source_request
	dwarf_dig_jobs[dwarf]["planner"] = "source_request_floor_projection" if native_goal is Vector3 else "floor_adapter"
	dig_selection_history.append({"worker": str(dwarf.name), "point": point, "rank": rank,
		"digpoint": digpoint, "group": int(dwarf_dig_groups.get(dwarf, -1)),
		"source_walk_request": source_request, "planner": dwarf_dig_jobs[dwarf]["planner"]})
	print("DWARF_DIG_ASSIGNED %s point=%s stance=%s" % [dwarf.name, point, best])
	status.text = "%s идёт к забою" % dwarf.name
	if best_count < 2 and dwarf.position.distance_to(best) < 0.1:
		_begin_dwarf_dig_action(dwarf)
	else:
		_start_dwarf_walk(dwarf, best)
		if not dwarf_walk_actions.has(dwarf):
			_cancel_dwarf_dig(dwarf,false)
			return false
	return dwarf_dig_jobs.has(dwarf)


func _native_height_sample(sample: Vector2i) -> Variant:
	return terrain_state.surface_depth(Vector2(sample) * 0.125)


func _native_cell_surface_samples(cell: Vector2i) -> PackedByteArray:
	return terrain_state.cell_surface_samples(cell)


func _native_world_height_sample(sample: Vector2i) -> Variant:
	return _native_height_sample(sample - native_world.template_offset * 8)


func _native_world_walk_sample(sample: Vector2i) -> Variant:
	return native_walkmap.sample(sample - native_world.template_offset * 8)


func _native_walk_gate(cell: Vector2i) -> Variant:
	if terrain_state.cell(cell).is_empty() or not native_terrain_cells.has(cell):
		return null
	return int(native_terrain_cells[cell]["flags"]) & 0x80


func query_native_dig_stance(source_target: Vector3, actor_position: Vector3) -> Dictionary:
	# Explicit nearest-even policy for our runtime; the live original x87 mode
	# has not been captured. Pure helper supports all modes and unknown mode.
	var source_worker: Vector3 = native_world.to_source(Vector3(actor_position.x, -actor_position.y, actor_position.z))
	var request: Dictionary = FIX_DIG.solve(native_world.to_source(source_target), source_worker, native_world.bounds,
		_native_world_walk_sample, _native_world_height_sample, &"nearest_even")
	if request.get("point") is Vector3:
		request["world_point"] = request["point"]
		request["point"] = native_world.to_local(request["point"])
	request["cache_stage"] = native_walkmap.stage
	request["object_overlays_applied"] = false
	return request


func query_native_walk_target(local_target: Vector3) -> Dictionary:
	var result: Dictionary = VECTOR_FIX.solve(native_world.to_source(local_target), native_world.bounds,
		_native_world_walk_sample, _native_world_height_sample, &"nearest_even")
	if result.get("point") is Vector3:
		result["world_point"] = result["point"]
		result["point"] = native_world.to_local(result["point"])
	if result.get("sample") is Vector2i:
		result["local_sample"] = result["sample"] - native_world.template_offset * 8
	return result


func _actor_navigation_sample(position_local: Vector3) -> Vector2i:
	var source: Vector3 = native_world.to_source(Vector3(position_local.x, -position_local.y, position_local.z))
	return Vector2i(FIX_DIG._round(FIX_DIG._f32(source.x * 8.0), &"nearest_even"),
		FIX_DIG._round(FIX_DIG._f32(source.y * 8.0), &"nearest_even")) - native_world.template_offset * 8


func _surface_work_clip_at(position_local: Vector3, digpoint: Vector3) -> StringName:
	var sample: Vector2i = _actor_navigation_sample(position_local)
	var contact: Variant = WALK_POSE.ground_contact(sample, native_world.local_sample_bounds(), native_walkmap.sample)
	if contact == null:
		return &""
	if bool(contact):
		return _dwarf_dig_clip(position_local, Vector2i(int(digpoint.x), int(digpoint.y)))
	return DIG_POSE.wall_clip(native_world.to_source(Vector3(position_local.x, -position_local.y, position_local.z)),
		native_world.to_source(digpoint))


func _dwarf_work_clip(dwarf: Node3D, point: Vector2i) -> StringName:
	if bool(dwarf_dig_jobs.get(dwarf, {}).get("surface", false)):
		return _surface_work_clip_at(dwarf.position, dwarf_dig_jobs[dwarf]["digpoint"])
	return _dwarf_dig_clip(dwarf.position, point)


func _dwarf_work_reachable(dwarf: Node3D, point: Vector2i) -> bool:
	if not bool(dwarf_dig_jobs.get(dwarf, {}).get("surface", false)):
		return _dwarf_dig_reachable(dwarf.position, point)
	var flags: Variant = native_walkmap.sample(_actor_navigation_sample(dwarf.position))
	if flags == null or (int(flags) & 1) == 0:
		return false
	var offset: Vector2 = Vector2(dwarf.position.x, -dwarf.position.y - 0.8) - Vector2(point)
	return offset.length() < 3.0 and not _dwarf_work_clip(dwarf, point).is_empty() and _dwarf_dig_check(dwarf.position, point)


func _height_with_refs(sample: Vector2i, refs: Dictionary) -> Variant:
	var cell: Vector2i = Vector2i(sample.x >> 3, sample.y >> 3)
	var block: int = int(refs.get(cell, terrain_state.block_ref(cell)))
	if block < 0:
		return null
	return int(terrain_state.package["blocks"][str(block)]["surface_samples"][(sample.y & 7) * 8 + (sample.x & 7)])


func _surface_dig_supports_next(point: Vector2i, stance: Vector3) -> bool:
	# Host safety gate: accepted source mutation must retain a known body sample.
	# This is a pure BDB preview, not the original action scheduling policy.
	var patch: Dictionary = _preview_work_step(point)
	if not bool(patch["accepted"]):
		return false
	var refs: Dictionary = {}
	for change: Dictionary in patch["changes"]:
		refs[change["cell"]] = int(change["after"])
	var heights: Callable = func(probe_sample: Vector2i) -> Variant: return _height_with_refs(probe_sample, refs)
	var sample: Vector2i = Vector2i(roundi(stance.x * 8.0), roundi(-stance.y * 8.0))
	var future: Variant = WALK_FLAGS.terrain_sample_query(sample, heights, _native_walk_gate)
	if future == null or (int(future) & 1) == 0:
		return false
	var before: Variant = WALK_POSE.wall_depth(sample, _native_height_sample)
	var after: Variant = WALK_POSE.wall_depth(sample, heights)
	return before != null and after != null and float(after) <= stance.z


func _surface_stance_valid(point: Vector2i, digpoint: Vector3, stance: Vector3) -> bool:
	return (Vector2(stance.x,-stance.y-0.8)-Vector2(point)).length()<3.0 \
		and not _surface_work_clip_at(stance,digpoint).is_empty() \
		and _dwarf_dig_check(stance,point) and _surface_dig_supports_next(point,stance)


func _known_surface_work_stances(dwarf: Node3D, point: Vector2i, digpoint: Vector3) -> Array[Dictionary]:
	# Explicit host frontier over KNOWN native navigation, used when the source
	# spiral reaches missing surrounding-world samples or its preferred pose
	# cannot work. It never turns an unknown sample into an empty/usable one.
	var candidates: Array[Dictionary] = []
	var lower: Vector2i = Vector2i(floori((point.x-3.0)*8.0),floori((point.y-3.0+0.8)*8.0))
	var upper: Vector2i = Vector2i(ceili((point.x+3.0)*8.0),ceili((point.y+3.0+0.8)*8.0))
	for y: int in range(lower.y,upper.y):
		for x: int in range(lower.x,upper.x):
			var sample: Vector2i = Vector2i(x,y)
			var flags: Variant = native_walkmap.sample(sample)
			if flags==null or (int(flags)&5)!=1:
				continue
			var depth: Variant = WALK_POSE.wall_depth(sample,_native_height_sample)
			if depth==null:
				continue
			var stance: Vector3 = Vector3(float(x)*0.125,-float(y)*0.125,float(depth))
			if _surface_stance_valid(point,digpoint,stance):
				candidates.append({"stance":stance,"sample":sample,"cost":dwarf.position.distance_squared_to(stance)})
	candidates.sort_custom(func(a: Dictionary,b: Dictionary) -> bool: return float(a["cost"])<float(b["cost"]))
	return candidates


func _assign_surface_dig(dwarf: Node3D, point: Vector2i, digpoint: Vector3, request: Dictionary, rank: int) -> bool:
	var candidates: Array[Dictionary] = []
	var normalized: Dictionary = {}
	if request.get("status")=="ok" and bool(request.get("found_navigation",false)):
		normalized = query_native_walk_target(request["point"])
		if normalized.get("status")=="ok" and bool(normalized.get("found_navigation",false)):
			var target: Vector3 = normalized["point"]
			var stance: Vector3 = Vector3(target.x,-target.y,target.z)
			if _surface_stance_valid(point,digpoint,stance):
				candidates.append({"stance":stance,"sample":normalized["local_sample"],"planner":"source_fixdig_vectorfix_surface_route"})
	if candidates.is_empty():
		candidates = _known_surface_work_stances(dwarf,point,digpoint)
	for candidate: Dictionary in candidates:
		var stance: Vector3 = candidate["stance"]
		var planner: String = str(candidate.get("planner","host_known_surface_frontier"))
		var worker_group: int = int(dwarf_dig_groups.get(dwarf,-1))
		if not assign_dwarf_surface_walk(dwarf,candidate["sample"],true,true,stance.z):
			continue
		dwarf_dig_groups[dwarf] = worker_group
		var walk: RefCounted = dwarf_walk_actions[dwarf]
		walk.final_point = stance
		walk.target = stance
		dwarf_dig_jobs[dwarf] = {"point":point,"phase":"approach","stance":stance,"rank":rank,
			"digpoint":digpoint,"source_walk_request":request,"normalized_walk_target":normalized,
			"planner":planner,"surface":true}
		dig_selection_history.append({"worker":str(dwarf.name),"point":point,"rank":rank,
			"digpoint":digpoint,"group":int(dwarf_dig_groups.get(dwarf,-1)),"source_walk_request":request,
			"normalized_walk_target":normalized,"planner":planner})
		status.text = "%s подбирается к забою" % dwarf.name
		print("SURFACE_DIG_ASSIGNED %s point=%s stance=%s planner=%s" % [dwarf.name,point,stance,planner])
		return true
	status.text = "К выбранному забою пока нет проверенного подхода"
	print("SURFACE_DIG_REJECT point=%s reason=no_known_supported_stance request=%s" % [point,request])
	return false


func _cancel_dwarf_dig(dwarf: Node3D, release_task: bool = true) -> void:
	if not is_instance_valid(dwarf):
		return
	if release_task:
		dwarf_manual_dig_tasks.erase(dwarf)
	if not dwarf_dig_jobs.has(dwarf):
		_update_work_attachments(dwarf,"stand_anim_a",0)
		return
	dwarf_dig_jobs.erase(dwarf)
	dwarf_dig_groups[dwarf] = -1
	_stop_dwarf_walk(dwarf)
	_show_dwarf_default(dwarf)
	dwarf_idle_frame_indices.erase(dwarf)
	print("DWARF_DIG_ENDED %s" % dwarf.name)


func _native_dig_snapshot(native_position: Vector3) -> Dictionary:
	# Bounds/offset come from the explicitly selected authored test context.
	# Only host-owned marks exist here; surrounding terrain stays unimported.
	# Group words belong to the fresh native mark manager and survive mark clearing.
	var samples: Dictionary = {}
	var rect: Rect2i = DIG_NEXT.scan_rect(native_position, native_world.bounds)
	for y: int in range(rect.position.y, rect.end.y):
		for x: int in range(rect.position.x, rect.end.x):
			var point: Vector2i = Vector2i(x, y)
			var local_point: Vector2i = point - native_world.template_offset
			var marks: int = int(native_mark_nibbles.get(_native_cell_key(local_point, 0, 0), 0))
			var sample: Dictionary = {"marks": marks}
			if (marks & 0xB) != 0:
				var fact: Dictionary = terrain_state.cell(local_point)
				if not fact.is_empty():
					sample["material_word"] = int(fact["material_low"])
					var height: Variant = terrain_state.next_height(local_point)
					if height != null:
						sample["next_height"] = int(height)
						sample["groups"] = native_dig_groups.word(local_point)
			samples[point] = sample
	return samples


func query_automatic_dig_seed(dwarf: Node3D, excluded: Dictionary = {}) -> Dictionary:
	# Native candidate ranking, with an explicit host job-registration adapter.
	# The clan's gnome_idle/available-work registry has not been reconstructed.
	var native_position: Vector3 = native_world.to_source(Vector3(dwarf.position.x, -dwarf.position.y, dwarf.position.z))
	var samples: Dictionary = _native_dig_snapshot(native_position)
	for rank: int in range(9):
		var candidate: Dictionary = DIG_NEXT.select_next(native_position, native_world.bounds, 0, -1, samples, rank)
		if candidate.get("status") != "ok":
			return candidate
		var local: Vector3 = native_world.to_local(candidate["point"] + Vector3(0, 0, -1))
		var point: Vector2i = Vector2i(int(local.x), int(local.y))
		if point.y <= 0 or excluded.has(point) or (_work_mark(point) & 0xB) == 0:
			continue
		var reserved: bool = false
		for worker: Node3D in dwarf_dig_jobs:
			reserved = reserved or dwarf_dig_jobs[worker]["point"] == point
		if not reserved:
			return {"status": "ok", "point": point, "rank": rank, "cost": candidate["cost"]}
	return {"status": "no_available_candidate"}


func _continue_dwarf_dig(dwarf: Node3D) -> void:
	if dwarf_life.should_stop_auto_dig(dwarf):
		_cancel_dwarf_dig(dwarf)
		return
	var previous_job: Dictionary = dwarf_dig_jobs.get(dwarf,{})
	var native_position: Vector3 = native_world.to_source(Vector3(dwarf.position.x, -dwarf.position.y, dwarf.position.z))
	var samples: Dictionary = _native_dig_snapshot(native_position)
	for retry: int in range(9):
		if retry > 6:
			dwarf_dig_groups[dwarf] = -1
		var result: Dictionary = DIG_NEXT.select_next(native_position, native_world.bounds, 0,
			int(dwarf_dig_groups.get(dwarf, -1)), samples, retry)
		if result["status"] != "ok":
			print("DWARF_DIG_QUEUE_STOP %s reason=%s retry=%d" % [dwarf.name, result["status"], retry])
			break
		# z_dignwalk.tcl:212 subtracts one AFTER native Z clamping.
		var digpoint: Vector3 = native_world.to_local(result["point"] + Vector3(0.0, 0.0, -1.0))
		var point: Vector2i = Vector2i(int(digpoint.x), int(digpoint.y))
		if point.y <= 0:
			break
		if (_work_mark(point) & 0xB) == 0:
			continue
		if not _dwarf_dig_check(dwarf.position, point):
			continue
		# A contiguous cave should not make a dwarf re-plan a decorative Z hop
		# after every cell. Keep the exact supported stance while it can still
		# reach the next native-ranked point; only a lost floor/support may force
		# the slower surface planner below.
		if not bool(previous_job.get("surface",false)) \
				and _dwarf_dig_reachable(dwarf.position,point) \
				and _has_source_floor(Vector2(dwarf.position.x,dwarf.position.z),_future_floor_for_dig(point)):
			var inherited_request: Variant = previous_job.get("source_walk_request", {})
			dwarf_dig_jobs[dwarf] = {"point":point,"phase":"approach","stance":dwarf.position,
				"rank":retry,"digpoint":digpoint,"planner":"stable_floor_stance",
				"source_walk_request": inherited_request}
			# The retained-stance planner selects a source point as well, so it has
			# to be recorded like the other planners: the dig queue report and its
			# self-test compare the whole selection sequence with the source.
			dig_selection_history.append({"worker": str(dwarf.name), "point": point, "rank": retry,
				"digpoint": digpoint, "group": int(dwarf_dig_groups.get(dwarf, -1)),
				"source_walk_request": inherited_request, "planner": "stable_floor_stance"})
			_remember_work_region(dwarf,point)
			print("DWARF_DIG_STANCE_RETAINED %s point=%s stance=%s" % [dwarf.name,point,dwarf.position])
			_begin_dwarf_dig_action(dwarf)
			return
		# Reservations and floor approach are explicit host adapters. Candidates
		# remain in the native ranking; a failed approach advances its rank.
		if _assign_dwarf_dig_point(dwarf, point, retry, digpoint):
			_remember_work_region(dwarf,point)
			print("DWARF_DIG_QUEUE_NEXT %s point=%s rank=%d cost=%.6f" % [dwarf.name, digpoint, retry, result["cost"]])
			return
	if dwarf_manual_dig_tasks.has(dwarf):
		_assign_region_frontier(dwarf)
		return
	_cancel_dwarf_dig(dwarf)


func _begin_dwarf_dig_action(dwarf: Node3D) -> void:
	if dwarf_life.should_stop_auto_dig(dwarf):
		_cancel_dwarf_dig(dwarf)
		return
	var job: Dictionary = dwarf_dig_jobs[dwarf]
	var point: Vector2i = job["point"]
	if (_work_mark(point) & 0xB) == 0 \
			or not _dwarf_work_reachable(dwarf, point):
		_cancel_dwarf_dig(dwarf,false)
		return
	var clip: StringName = _dwarf_work_clip(dwarf, point)
	if not bool(job.get("accident_handled",false)):
		job["accident_handled"] = true
		var height_delta: float = -dwarf.position.y-float(point.y)
		var accident: Dictionary = DIG_FEEDBACK.chance(float(dwarf.get_meta("exp_Stein",0.0)),height_delta,
			not String(clip).begins_with("kletter_hack_"))
		if float(accident["probability"])>0.0:
			if dig_feedback_data.is_empty():
				dig_feedback_data = DIG_FEEDBACK.read_data()
			var alias: String = DIG_FEEDBACK.clip(height_delta,true)
			var native_clip: String = str(dig_feedback_data["aliases"][alias])
			if _ensure_pick_feedback_clip(dwarf,alias):
				job["accident_prelude"] = true
				clip = StringName(native_clip)
	if String(clip).begins_with("kletter_hack_"):
		_ensure_surface_clip(dwarf, clip)
	var count: int = _dwarf_sequence_frame_count(dwarf, clip)
	if count == 0:
		_cancel_dwarf_dig(dwarf,false)
		return
	var action: RefCounted = SOURCE_ACTION.new()
	var fps: float = NATIVE_TIMING.FRAMES_PER_GAME_SECOND
	if not bool(job.get("accident_prelude",false)):
		var clips: Dictionary = surface_walk_data["clips"] if String(clip).begins_with("kletter_hack_") else dig_action_data["clips"]
		fps = float(clips[String(clip)]["adapter_fps"])
	action.begin(count,fps)
	job["phase"] = "work"
	job["clip"] = clip
	job["action"] = action
	job["frame"] = 0
	var digpoint: Vector3 = job["digpoint"]
	_set_dwarf_heading(dwarf, PI if String(clip).begins_with("kletter_hack_") else atan2(digpoint.x - dwarf.position.x, digpoint.z - dwarf.position.z))
	_show_dwarf_animation_frame(dwarf, clip, 0)
	status.text = "%s копает" % dwarf.name
	print("DWARF_DIG_ANIMATION %s clip=%s point=%s" % [dwarf.name, clip, point])


func _update_dwarf_dig_jobs(delta: float) -> void:
	for dwarf: Node3D in dwarf_dig_jobs.keys():
		var job: Dictionary = dwarf_dig_jobs[dwarf]
		var point: Vector2i = job["point"]
		if (_work_mark(point) & 0xB) == 0:
			_continue_dwarf_dig(dwarf)
			continue
		if job["phase"] != "work":
			continue
		var action: RefCounted = job["action"]
		var step: Dictionary = action.advance(delta)
		if int(step["frame"]) != int(job["frame"]):
			job["frame"] = step["frame"]
			_show_dwarf_animation_frame(dwarf, job["clip"], int(step["frame"]))
		if not bool(step["complete"]):
			continue
		if bool(job.get("accident_prelude",false)):
			job["accident_prelude"] = false
			_begin_dwarf_dig_action(dwarf)
			continue
		dig_action_completions += 1
		# Source callback boundary, with an explicit deterministic work-rate
		# Strike adapter: one accepted step, no native success RNG/resources yet.
		var applied: bool = false
		if _dwarf_work_reachable(dwarf, point):
			applied = native_dig_apply_cell(0, point)
			if applied:
				dwarf_dig_groups[dwarf] = int(last_native_strike["worker_group_value"])
		print("DWARF_DIG_CALLBACK %s point=%s accepted=%s" % [dwarf.name, point, applied])
		# Source play_anim always calls dig_continue after dig_execute, including
		# a rejected strike that consumed a stale mark without changing terrain.
		_continue_dwarf_dig(dwarf)


func _current_walk_speed(walk: RefCounted = null) -> float:
	var fast: bool = walk.fast if walk != null else fast_walk
	if movement_timing.is_empty():
		movement_timing = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_animation_timing.json"))
	var model: Dictionary = movement_timing["models"]["mann"]
	if walk is SURFACE_WALK and walk.previous_mode == 0:
		return float(model["wall_group_speed_world_per_game_second"]["schnell" if fast else "loop"])
	return float(model["clips"]["laufen_schnell_loop" if fast else "gehen_loop"]["slot_speed_world_per_game_second"])


func _update_dwarf_locomotion(delta: float) -> void:
	for dwarf: Node3D in dwarf_walk_actions.keys():
		_update_one_dwarf_walk(dwarf, delta)
	_sync_walk_debug()


func _update_one_dwarf_walk(dwarf: Node3D, delta: float) -> void:
	if not dwarf_walk_actions.has(dwarf):
		return
	var walk: RefCounted = dwarf_walk_actions[dwarf]
	if walk is SURFACE_WALK:
		_update_surface_walk(dwarf, delta)
		return
	walk.elapsed += delta
	var sequence_count: int = _dwarf_sequence_frame_count(dwarf, walk.state)
	if sequence_count == 0:
		if _advance_dwarf_along_path(delta, dwarf) and dwarf_walk_actions.has(dwarf):
			_finish_dwarf_walk(dwarf)
		return
	var requested_frame: int = int(floor(walk.elapsed * WALK_ANIMATION_FPS))
	if String(walk.state).begins_with("drehen_") and requested_frame >= sequence_count:
		_set_dwarf_heading(dwarf, walk.pending_heading)
		walk.state = _walk_sequence(&"start", walk)
		walk.elapsed = 0.0
		requested_frame = 0
		sequence_count = _dwarf_sequence_frame_count(dwarf, walk.state)
	elif walk.state == _walk_sequence(&"start", walk) and requested_frame >= sequence_count:
		walk.state = _walk_sequence(&"loop", walk)
		walk.elapsed = 0.0
		requested_frame = 0
		sequence_count = _dwarf_sequence_frame_count(dwarf, walk.state)
	elif walk.state == _walk_sequence(&"loop", walk):
		requested_frame %= sequence_count
	elif walk.state == _walk_sequence(&"end", walk) and requested_frame >= sequence_count:
		_finish_dwarf_walk(dwarf)
		return
	if walk.state == _walk_sequence(&"start", walk) or walk.state == _walk_sequence(&"loop", walk):
		if _advance_dwarf_along_path(delta, dwarf):
			if not dwarf_walk_actions.has(dwarf):
				return
			walk.state = _walk_sequence(&"end", walk)
			walk.elapsed = 0.0
			requested_frame = 0
	if requested_frame != walk.frame:
		walk.frame = requested_frame
		_show_dwarf_animation_frame(dwarf, walk.state, requested_frame)


func _update_dwarf_idle_animations(delta: float) -> void:
	idle_animation_elapsed += delta
	for dwarf_index: int in range(dwarf_nodes.size()):
		var dwarf: Node3D = dwarf_nodes[dwarf_index]
		if actor_tasks.animating(dwarf):
			continue
		if dwarf_sleep.states.has(dwarf):
			continue
		if dwarf_walk_actions.has(dwarf):
			continue
		if dwarf_dig_jobs.has(dwarf) and dwarf_dig_jobs[dwarf]["phase"] == "work":
			continue
		var sequence_name: StringName = &"stand_anim_a" if dwarf_index % 2 == 0 else &"stand_anim_b"
		if int(dwarf_surface_modes.get(dwarf, 2)) == 0:
			sequence_name = &"kletterstand_anim"
			_ensure_surface_clip(dwarf, sequence_name)
		var frame_count: int = _dwarf_sequence_frame_count(dwarf, sequence_name)
		if frame_count == 0:
			continue
		var frame_index: int = (int(floor(idle_animation_elapsed * IDLE_ANIMATION_FPS)) + dwarf_index * 3) % frame_count
		if int(dwarf_idle_frame_indices.get(dwarf, -1)) == frame_index:
			continue
		dwarf_idle_frame_indices[dwarf] = frame_index
		_show_dwarf_animation_frame(dwarf, sequence_name, frame_index)


func _advance_dwarf_along_path(delta: float, dwarf: Node3D = null) -> bool:
	if dwarf == null:
		dwarf = moving_dwarf
	if not dwarf_walk_actions.has(dwarf):
		return true
	var walk: RefCounted = dwarf_walk_actions[dwarf]
	if walk.path_index >= walk.path.size():
		return true
	var waypoint: Vector3 = walk.path[walk.path_index]
	if navigation_grid.is_point_solid(_local_to_navigation_id(waypoint)):
		print("DWARF_WALK_INTERRUPTED %s reason=terrain_changed" % dwarf.name)
		_cancel_dwarf_dig(dwarf,false)
		_stop_dwarf_walk(dwarf)
		return true
	var current_2d: Vector2 = Vector2(dwarf.position.x, dwarf.position.z)
	var target_2d: Vector2 = Vector2(waypoint.x, waypoint.z)
	var direction: Vector2 = current_2d.direction_to(target_2d)
	var step: float = _current_walk_speed(walk) * delta
	var next_2d: Vector2 = current_2d.move_toward(target_2d, step)
	dwarf.position = Vector3(next_2d.x, WALKABLE_FLOOR_Y, next_2d.y)
	if direction.length_squared() > 0.0:
		var segment_heading: float = atan2(direction.x, direction.y * render_depth_scale)
		_set_dwarf_heading(dwarf, segment_heading)
	if next_2d.is_equal_approx(target_2d):
		walk.path_index += 1
		if walk.path_index >= walk.path.size():
			return true
		var remaining: float = delta - current_2d.distance_to(target_2d) / _current_walk_speed(walk)
		if remaining > 0.000001:
			return _advance_dwarf_along_path(remaining, dwarf)
	return false


func _stop_dwarf_walk(dwarf: Node3D) -> void:
	if not dwarf_walk_actions.has(dwarf):
		return
	if dwarf_walk_actions[dwarf] is SURFACE_WALK and int(surface_walk_results.get(dwarf, 2)) == 2:
		surface_walk_results[dwarf] = 1
		surface_walk_history.append({"worker": str(dwarf.name), "event": "cancelled", "result": 1})
	dwarf_walk_actions.erase(dwarf)
	_show_dwarf_default(dwarf)
	dwarf_idle_frame_indices.erase(dwarf)
	_sync_walk_debug()


func _sync_walk_debug(preferred: Node3D = null) -> void:
	# Legacy diagnostics project one actor; gameplay reads the per-actor actions.
	if preferred != null and dwarf_walk_actions.has(preferred):
		moving_dwarf = preferred
	if not dwarf_walk_actions.has(moving_dwarf):
		moving_dwarf = null if dwarf_walk_actions.is_empty() else dwarf_walk_actions.keys()[0]
	if moving_dwarf == null:
		movement_path = []
		movement_path_index = 0
		locomotion_state = &"idle"
		locomotion_elapsed = 0.0
		locomotion_frame = -1
		barrel_goal = null
		return
	var walk: RefCounted = dwarf_walk_actions[moving_dwarf]
	movement_path = walk.path
	movement_path_index = walk.path_index
	movement_target = walk.target
	locomotion_state = walk.state
	locomotion_elapsed = walk.elapsed
	locomotion_frame = walk.frame
	fast_walk = walk.fast
	pending_heading = walk.pending_heading
	last_walk_target = dwarf_last_walk_targets[moving_dwarf]
	barrel_goal = walk.barrel


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
	var frame_meshes: Array = frames[clampi(frame_index,0,frames.size()-1)]
	var frame_root: Node3D = visuals["animated"]
	var instances: Array = visuals["body_instances"]
	while instances.size() < frame_meshes.size():
		var instance: MeshInstance3D = MeshInstance3D.new()
		frame_root.add_child(instance)
		instances.append(instance)
	for index: int in range(instances.size()):
		var instance: MeshInstance3D = instances[index]
		instance.visible = index < frame_meshes.size()
		if instance.visible:
			instance.mesh = frame_meshes[index]
	frame_root.name = "%s_%02d" % [sequence_key,frame_index]
	frame_root.visible = true
	visuals["current"] = frame_root
	_refresh_dwarf_outline(dwarf)
	_update_work_attachments(dwarf, sequence_key, frame_index)


func _update_work_attachments(dwarf: Node3D, clip: String, frame: int) -> void:
	var working: bool = dwarf_dig_jobs.has(dwarf) and dwarf_dig_jobs[dwarf]["phase"] == "work"
	var assigned: bool = dwarf_manual_dig_tasks.has(dwarf)
	if not working and not assigned:
		if actor_attachments.has(dwarf):
			for attached: Node3D in actor_attachments[dwarf].values():
				attached.visible = false
		return
	if attachment_data.is_empty():
		attachment_data = ATTACHMENT.read_data()
		var textures: Dictionary = ATTACHMENT.decode_textures(attachment_data)
		for asset: String in ["spitzhacke", "muetze_stein_a"]:
			attachment_meshes[asset] = ATTACHMENT.build_meshes(attachment_data["assets"][asset]["frames"][0], textures)
	if not actor_attachments.has(dwarf):
		actor_attachments[dwarf] = {}
		for asset: String in attachment_meshes:
			var attached: Node3D = Node3D.new()
			attached.name = asset
			dwarf.add_child(attached)
			for mesh: ArrayMesh in attachment_meshes[asset]:
				var visual: MeshInstance3D = MeshInstance3D.new()
				visual.mesh = mesh
				attached.add_child(visual)
			if asset == "muetze_stein_a":
				# The miner helmet is an attachment in the original model stream.
				# Keep its lamp outside the selection proxy and switch its actual
				# light on only for an active mining action.
				var lamp: OmniLight3D = OmniLight3D.new()
				lamp.name = "MinerHelmetLight"
				lamp.position = Vector3(0.0, 0.04, 0.08)
				lamp.light_color = Color(1.0, 0.82, 0.54)
				lamp.light_energy = 1.35
				lamp.omni_range = 2.8
				lamp.shadow_enabled = false
				lamp.visible = false
				attached.add_child(lamp)
			actor_attachments[dwarf][asset] = attached
	for asset: String in actor_attachments[dwarf]:
		var slot: int = int(attachment_data["assets"][asset]["default_slot"])
		var result: Dictionary = ATTACHMENT.sample(attachment_data, "mann.3db::mann", clip, frame, slot)
		if not bool(result["ok"]) and dig_feedback_frames.has(clip):
			var frames: Array = dig_feedback_frames[clip]
			if frame>=0 and frame<frames.size() and frames[frame]["attachment_slots"].has(str(slot)):
				var socket: Dictionary = frames[frame]["attachment_slots"][str(slot)]
				var columns: Array = socket["basis_columns"]
				result = {"ok":true,"transform":Transform3D(Basis(ATTACHMENT.vector(columns[0]),
					ATTACHMENT.vector(columns[1]),ATTACHMENT.vector(columns[2])),ATTACHMENT.vector(socket["origin_render"]))}
		var attached: Node3D = actor_attachments[dwarf][asset]
		attached.visible = bool(result["ok"]) and (asset != "spitzhacke" or working)
		if attached.visible:
			attached.transform = result["transform"]
		if asset == "muetze_stein_a":
			var lamp: OmniLight3D = attached.get_node_or_null("MinerHelmetLight") as OmniLight3D
			if lamp != null:
				lamp.visible = attached.visible and working


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
	_refresh_dwarf_outline(dwarf)
	if actor_attachments.has(dwarf):
		for asset: String in actor_attachments[dwarf]:
			actor_attachments[dwarf][asset].visible = asset != "spitzhacke" and dwarf_manual_dig_tasks.has(dwarf)


func _open_barrel(barrel: Node3D) -> void:
	barrels.erase(barrel)
	for obstacle: Vector3 in navigation_obstacles:
		if Vector2(obstacle.x, obstacle.y).distance_to(Vector2(barrel.position.x, barrel.position.z)) < 0.01:
			navigation_obstacles.erase(obstacle)
			break
	barrel.queue_free()
	_build_navigation_grid()
	status.text = "Бочка открыта"


func _finish_dwarf_walk(dwarf: Node3D = null) -> void:
	if dwarf == null:
		dwarf = moving_dwarf
	if not is_instance_valid(dwarf) or not dwarf_walk_actions.has(dwarf):
		return
	var walk: RefCounted = dwarf_walk_actions[dwarf]
	if walk is SURFACE_WALK:
		status.text = "%s пришёл к выбранному месту" % dwarf.name
	if is_instance_valid(walk.barrel) and dwarf.position.distance_to(walk.barrel.position) <= 1.8:
		_open_barrel(walk.barrel)
	_stop_dwarf_walk(dwarf)
	print("DWARF_WALK_RESULT %s result=4" % dwarf.name)
	if dwarf_dig_jobs.has(dwarf) and dwarf_dig_jobs[dwarf]["phase"] == "approach":
		_begin_dwarf_dig_action(dwarf)


func _ensure_surface_clip(dwarf: Node3D, clip_name: StringName) -> bool:
	if surface_walk_data.is_empty():
		var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string("res://models/dwarf_surface_walk.json"))
		if not parsed is Dictionary:
			return false
		surface_walk_data = parsed
	if not surface_walk_data["clips"].has(String(clip_name)):
		return false
	var visuals: Dictionary = dwarf_locomotion_visuals[dwarf]
	if visuals["sequences"].has(String(clip_name)):
		return true
	var frames: Array = []
	for source_frame: Dictionary in surface_walk_data["clips"][String(clip_name)]["frames"]:
		var mesh_id: int = int(source_frame["mesh_index"])
		if not surface_walk_meshes.has(mesh_id):
			surface_walk_meshes[mesh_id] = _build_model_meshes(source_frame["surfaces"])
		frames.append(surface_walk_meshes[mesh_id])
	visuals["sequences"][String(clip_name)] = frames
	return true


func _nearest_surface_sample(local_xy: Vector2, max_distance: float) -> Variant:
	var best: Variant = null
	var best_squared: float = max_distance * max_distance
	var bounds: Rect2i = native_walkmap.sample_bounds
	var low: Vector2i = Vector2i((local_xy-Vector2.ONE*max_distance)*8.0).clamp(bounds.position,bounds.end-Vector2i.ONE)
	var high: Vector2i = Vector2i((local_xy+Vector2.ONE*max_distance)*8.0).clamp(bounds.position,bounds.end-Vector2i.ONE)
	for y: int in range(low.y, high.y+1):
		for x: int in range(low.x, high.x+1):
			var index: int = y*bounds.size.x+x
			if native_walkmap.unknown_samples[index] != 0 or (int(native_walkmap.flags[index]) & 1) == 0:
				continue
			var point: Vector2i = Vector2i(x,y)
			var squared: float = (Vector2(point)*0.125).distance_squared_to(local_xy)
			if squared < best_squared:
				best = point
				best_squared = squared
	return best


func assign_dwarf_surface_walk(dwarf: Node3D, target_sample: Vector2i, can_climb: bool = true, work_approach: bool = false, target_depth: Variant = null) -> bool:
	if not is_instance_valid(dwarf) or not dwarf_nodes.has(dwarf):
		return false
	var start: Variant = _nearest_surface_sample(Vector2(dwarf.position.x, -dwarf.position.y), 0.3)
	if not start is Vector2i:
		return false
	var route: Dictionary = SURFACE_WALK.plan(start, target_sample, native_walkmap, _native_height_sample, can_climb)
	if route["status"] != "ok":
		print("SURFACE_WALK_REJECT %s reason=%s" % [dwarf.name, route["status"]])
		return false
	if not SURFACE_WALK.project_floor_runs(route["positions"],route["modes"],route["samples"],
			_native_height_sample,dwarf.position.z,target_depth):
		return false
	_cancel_dwarf_dig(dwarf,not work_approach)
	_stop_dwarf_walk(dwarf)
	var walk: RefCounted = SURFACE_WALK.new()
	walk.samples = route["samples"]
	walk.modes = route["modes"]
	walk.path = route["positions"]
	walk.path_index = 0
	walk.target = walk.path[-1]
	walk.previous_mode = int(dwarf_surface_modes.get(dwarf, 2))
	walk.can_climb = can_climb
	var last_target: Vector3 = dwarf_last_walk_targets.get(dwarf, Vector3.INF)
	walk.fast = not is_inf(last_target.x) and Vector2(last_target.x, last_target.y).distance_to(
		Vector2(walk.target.x, walk.target.y)) < 3.0
	dwarf_last_walk_targets[dwarf] = walk.target
	dwarf_walk_actions[dwarf] = walk
	surface_walk_results[dwarf] = 2
	surface_walk_history.append({"worker": str(dwarf.name), "event": "assigned", "samples": walk.samples.size(),
		"planner": route["planner"], "can_climb": can_climb,
		"target_sample": [target_sample.x, target_sample.y],
		"target_newly_navigable": native_walkmap.is_newly_navigable(target_sample),
		"terrain_revision": terrain_state.revision, "navigation_revision": native_walkmap.revision})
	_sync_walk_debug(dwarf)
	status.text = "%s идёт к выбранному месту" % dwarf.name
	print("SURFACE_WALK_ASSIGNED %s samples=%d target=%s" % [dwarf.name, walk.samples.size(), walk.target])
	return true


func _set_surface_floor_goal(dwarf: Node3D, walk: RefCounted, depth: float) -> void:
	if not SURFACE_WALK.project_floor_runs(walk.path,walk.modes,walk.samples,_native_height_sample,dwarf.position.z,depth):
		return
	walk.final_point = walk.path[-1]
	walk.target = walk.final_point


func _surface_clip(dwarf: Node3D, walk: RefCounted, clip: StringName, delta: float, loop: bool) -> bool:
	if walk.state != clip:
		walk.state = clip
		walk.elapsed = 0.0
		walk.frame = -1
		if String(clip).begins_with("kletter") or clip == &"stand_zu_kletterstand":
			_ensure_surface_clip(dwarf, clip)
		surface_walk_history.append({"worker": str(dwarf.name), "event": "clip", "clip": String(clip)})
	walk.elapsed += delta
	var count: int = _dwarf_sequence_frame_count(dwarf, clip)
	if count <= 0:
		_abort_surface_walk(dwarf, "missing_clip")
		return false
	var frame: int = int(floor(walk.elapsed * WALK_ANIMATION_FPS))
	if not loop and frame >= count:
		return true
	frame = frame % count if loop else mini(frame, count - 1)
	if frame != walk.frame:
		walk.frame = frame
		_show_dwarf_animation_frame(dwarf, clip, frame)
	return false


func _abort_surface_walk(dwarf: Node3D, reason: String) -> void:
	surface_walk_results[dwarf] = 3
	surface_walk_history.append({"worker": str(dwarf.name), "event": "aborted", "reason": reason})
	_stop_dwarf_walk(dwarf)
	_cancel_dwarf_dig(dwarf,false)
	print("SURFACE_WALK_ABORTED %s reason=%s" % [dwarf.name, reason])
	status.text = "Маршрут стал недоступен"


func _update_surface_walk(dwarf: Node3D, delta: float) -> void:
	# Consume the full movement budget across short 1/8-cell waypoints.
	var remaining: float = delta
	for iteration: int in range(4096):
		if not dwarf_walk_actions.has(dwarf):
			return
		var action: RefCounted = dwarf_walk_actions[dwarf]
		if action.path_index >= action.path.size():
			_step_surface_walk(dwarf, 0.0)
			return
		if action.modes[action.path_index] != action.previous_mode:
			_step_surface_walk(dwarf, remaining)
			return
		var target: Vector3 = action.path[action.path_index]
		if action.previous_mode == 0:
			var depth: Variant = WALK_POSE.wall_depth(action.samples[action.path_index], _native_height_sample)
			if depth != null:
				target.z = float(depth)
		if action.path_index == action.path.size() - 1 and action.final_point is Vector3:
			target = action.final_point
		var duration: float = dwarf.position.distance_to(target) / _current_walk_speed(action)
		var spent: float = minf(remaining, duration)
		_step_surface_walk(dwarf, spent)
		remaining -= spent
		if remaining <= 0.000001:
			return


func _step_surface_walk(dwarf: Node3D, delta: float) -> void:
	var walk: RefCounted = dwarf_walk_actions[dwarf]
	if walk.path_index >= walk.path.size():
		surface_walk_results[dwarf] = 4
		surface_walk_history.append({"worker": str(dwarf.name), "event": "completed", "result": 4,
			"new_samples_entered": walk.new_samples_entered,
			"position": _vector_array(dwarf.position), "terrain_revision": terrain_state.revision,
			"navigation_revision": native_walkmap.revision})
		_finish_dwarf_walk(dwarf)
		return
	var sample: Vector2i = walk.samples[walk.path_index]
	var flags: Variant = native_walkmap.sample(sample)
	if flags == null or (int(flags) & 1) == 0:
		_abort_surface_walk(dwarf, "navigation_changed_or_unknown")
		return
	var mode_value: int = WALK_POSE.mode(int(flags), false, false)
	if mode_value != walk.modes[walk.path_index] or (mode_value == 0 and not walk.can_climb):
		_abort_surface_walk(dwarf, "mode_changed")
		return
	if mode_value != walk.previous_mode:
		var transition: StringName = &"stand_zu_kletterstand" if mode_value == 0 else &"kletterstand_zu_stand"
		_set_dwarf_heading(dwarf, PI)
		if not _surface_clip(dwarf, walk, transition, delta, false):
			return
		walk.previous_mode = mode_value
		dwarf_surface_modes[dwarf] = mode_value
		walk.state = &""
	var waypoint: Vector3 = walk.path[walk.path_index]
	if mode_value == 0 and not (walk.path_index == walk.path.size() - 1 and walk.final_point is Vector3):
		var depth: Variant = WALK_POSE.wall_depth(sample, _native_height_sample)
		if depth == null:
			_abort_surface_walk(dwarf, "unknown_wall_height")
			return
		waypoint.z = float(depth)
	if walk.path_index == walk.path.size() - 1 and walk.final_point is Vector3:
		waypoint = walk.final_point
	var direction: Vector3 = waypoint - dwarf.position
	var clip: StringName
	if mode_value == 0:
		var map_delta: Vector2i = sample - walk.samples[maxi(0, walk.path_index - 1)]
		var name_part: String = "hoch" if map_delta.y < 0 else "runter"
		if map_delta.x != 0:
			name_part = "rechts" if map_delta.x > 0 else "links"
		clip = StringName("kletter_%s_%s" % [name_part, "schnell" if walk.fast else "loop"])
		_set_dwarf_heading(dwarf, PI)
	else:
		clip = _walk_sequence(&"loop", walk)
		if Vector2(direction.x, direction.z).length_squared() > 0.00000001:
			_set_dwarf_heading(dwarf, atan2(direction.x, direction.z * render_depth_scale))
	_surface_clip(dwarf, walk, clip, delta, true)
	if not dwarf_walk_actions.has(dwarf):
		return
	dwarf.position = dwarf.position.move_toward(waypoint, _current_walk_speed(walk) * delta)
	if dwarf.position.is_equal_approx(waypoint):
		dwarf_surface_modes[dwarf] = mode_value
		if native_walkmap.is_newly_navigable(sample):
			walk.new_samples_entered += 1
		walk.path_index += 1


func _initialize_automatic_torches() -> void:
	if not automatic_torches or not include_objects:
		return
	var source: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_torches.json"))
	torch_visual_data = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_torch_visual.json"))
	var first_frame: Dictionary = torch_visual_data["asset"]["frames"][0]
	torch_meshes = _build_model_meshes(first_frame["surfaces"],"res://textures/native_torch")
	var registered: Array[Dictionary] = []
	for light: Dictionary in source_profile.data["lights"]:
		registered.append({"position":native_world.to_source(source_profile._source_light_point(light)),"range":light["range"]})
	var first_id: int = 0
	for dwarf: Node3D in dwarf_nodes:
		first_id = maxi(first_id,int(dwarf.get_meta("autolight_host_id"))+1)
	torch_runtime = TORCH_RUNTIME.new()
	torch_runtime.configure(native_world.bounds,_native_world_height_sample,_torch_world_material,source,registered,first_id)
	torch_runtime.frame_playback_mode = int(torch_visual_data["playback"]["mode"])
	# Clean standalone world constructor; imported Info_Fog initializers supply
	# the actual horizon registry. The surrounding world is not generated here.
	torch_runtime.minimum_y = int(source["placement_defaults"]["minimum_y"])
	torch_runtime.region_records = []
	for horizon: Dictionary in source_profile.data["horizons"]:
		var coordinates: Array = horizon["position"]
		var world: Vector3 = native_world.to_source(Vector3(coordinates[0],coordinates[1],coordinates[2]))
		torch_runtime.region_records.append({"position":Vector2(world.x,world.y),"radius":horizon["selection_radius"]})
	print("NATIVE_AUTOLIGHT_READY actors=%d source_model=fackel.standard mode=STILL host_rng_seed=1" % dwarf_nodes.size())


func _torch_world_material(source_cell: Vector2i) -> Variant:
	var cell: Dictionary = terrain_state.cell(source_cell-native_world.template_offset)
	var value: Variant = cell.get("material_low")
	if value == null:
		return null
	return int(value)


func _update_automatic_torches(delta_game_seconds: float) -> void:
	if torch_runtime == null or not automatic_torches:
		return
	var actors: Array[Dictionary] = []
	for dwarf: Node3D in dwarf_nodes:
		actors.append({"id":int(dwarf.get_meta("autolight_host_id")),"autolight":true,
			"position":native_world.to_source(Vector3(dwarf.position.x,-dwarf.position.y,dwarf.position.z))})
	var result: Dictionary = torch_runtime.update(delta_game_seconds,actors)
	var light_changes: Array[Dictionary] = []
	for record: Dictionary in result["created"]:
		_spawn_automatic_torch(record)
		_sync_automatic_torch(record,light_changes)
	for record: Dictionary in result["moved"]:
		_sync_automatic_torch(record,light_changes)
	if not light_changes.is_empty():
		_queue_torch_terrain_lighting(light_changes)
		_queue_model_lighting(light_changes)


func _spawn_automatic_torch(record: Dictionary) -> void:
	var root: Node3D = Node3D.new()
	root.name = "AutomaticTorch_%d" % int(record["id"])
	root.set_meta("native_class","Misc_Light")
	root.set_meta("native_ordinal",int(record["id"]))
	var body: Node3D = Node3D.new()
	body.scale.z = 1.0/render_depth_scale
	root.add_child(body)
	for mesh: ArrayMesh in torch_meshes:
		var visual: MeshInstance3D = MeshInstance3D.new()
		visual.mesh = mesh
		body.add_child(visual)
	var light: OmniLight3D = OmniLight3D.new()
	light.name = "SourceLight"
	var spec: Dictionary = torch_visual_data["light"]
	var offset: Array = spec["offset_native"]
	light.position = Vector3(offset[0],-float(offset[1]),offset[2])
	light.light_color = Color(spec["rgb"][0],spec["rgb"][1],spec["rgb"][2])
	light.omni_range = float(spec["range_native"])
	light.shadow_enabled = false
	root.add_child(light)
	scene_root.add_child(root)
	torch_nodes[int(record["id"])] = root
	_add_source_flame(root,"Misc_Light")
	print("NATIVE_AUTOLIGHT_CREATED id=%d source_xyz=%s" % [int(record["id"]),record["position"]])


func _sync_automatic_torch(record: Dictionary, changes: Array[Dictionary]) -> void:
	var id: int = int(record["id"])
	var local: Vector3 = native_world.to_local(record["position"])
	(torch_nodes[id] as Node3D).position = Vector3(local.x,-local.y,local.z)
	var native_light: Dictionary = torch_runtime.light_records[int(record["light_index"])]
	var point: Vector3 = native_world.to_local(native_light["position"])
	point.z = point.z*float(source_profile.terrain_render["constants"]["depth_half"]) \
		+ float(source_profile.terrain_render["constants"]["depth_offset"])
	var light: Dictionary = {"position":point,"range":native_light["range"],
		"color":TERRAIN_ILLUMINATION.class_light_color(torch_visual_data["light"]["rgb"],source_profile.shader_pipeline["light_conversion"])}
	if torch_terrain_indices.has(id):
		var index: int = int(torch_terrain_indices[id])
		changes.append(source_profile.terrain_lights[index])
		source_profile.terrain_lights[index] = light
	else:
		torch_terrain_indices[id] = source_profile.terrain_lights.size()
		source_profile.terrain_lights.append(light)
	changes.append(light)
	source_profile.set_dynamic_torch_lights(_automatic_torch_lights())


func _automatic_torch_lights() -> Array:
	var lights: Array = []
	for id: int in torch_terrain_indices:
		var index: int = int(torch_terrain_indices[id])
		if index >= 0 and index < source_profile.terrain_lights.size():
			lights.append(source_profile.terrain_lights[index])
	return lights


func _terrain_baked_lights() -> Array:
	if torch_terrain_indices.is_empty():
		return source_profile.terrain_lights
	var automatic_indices: Dictionary = {}
	for id: int in torch_terrain_indices:
		automatic_indices[int(torch_terrain_indices[id])] = true
	var lights: Array = []
	for index: int in range(source_profile.terrain_lights.size()):
		if not automatic_indices.has(index):
			lights.append(source_profile.terrain_lights[index])
	return lights


func _queue_torch_terrain_lighting(_changes: Array) -> void:
	# Automatic torches are a shared shader uniform. Rebuilding vertex colours
	# here caused both a stall and a visible chunk-by-chunk lighting wave.
	# Keep this entry point for tools/tests, but intentionally schedule no mesh work.
	source_profile.set_dynamic_torch_lights(_automatic_torch_lights())


func _terrain_bucket_may_receive_light(key: String, changes: Array) -> bool:
	var parts: PackedStringArray = key.split(":")
	if parts.size() < 5:
		return false
	var chunk_x: float = float(int(parts[parts.size()-2]) * TERRAIN_CHUNK_CELLS)
	var chunk_y: float = float(int(parts[parts.size()-1]) * TERRAIN_CHUNK_CELLS)
	for light: Dictionary in changes:
		var radius: float = float(light["range"]) + 1.5
		# Terrain illumination stores unflipped source X/Y; only the render
		# vertex converts Y to Godot's vertical axis. A chunk AABB is enough for
		# queue selection; the later vertex pass remains exact.
		var nearest_x: float = clampf(float(light["position"].x),chunk_x,chunk_x+float(TERRAIN_CHUNK_CELLS))
		var nearest_y: float = clampf(float(light["position"].y),chunk_y,chunk_y+float(TERRAIN_CHUNK_CELLS))
		if Vector2(nearest_x,nearest_y).distance_squared_to(Vector2(light["position"].x,light["position"].y)) <= radius*radius:
			return true
	return false


func _step_torch_terrain_lighting() -> void:
	for bucket_index: int in range(mini(TORCH_TERRAIN_LIGHTING_BUCKETS_PER_FRAME,torch_terrain_lighting_queue.size())):
		var key: String = torch_terrain_lighting_queue.pop_front()
		var changes: Array = torch_terrain_lighting_changes.get(key,[])
		torch_terrain_lighting_changes.erase(key)
		_refresh_torch_terrain_lighting_bucket(key,changes)


func _refresh_torch_terrain_lighting(changes: Array) -> void:
	# Test/tool entry point: drain only matching buckets synchronously.
	_queue_torch_terrain_lighting(changes)
	while not torch_terrain_lighting_queue.is_empty():
		_step_torch_terrain_lighting()


func _refresh_torch_terrain_lighting_bucket(key: String, changes: Array) -> void:
	if not terrain_mesh_nodes.has(key) or not terrain_lighting_inputs.has(key):
		return
	var inputs: Dictionary = terrain_lighting_inputs[key]
	var points: PackedVector3Array = inputs["points"]
	var affected_indices: PackedInt32Array = PackedInt32Array()
	for index: int in range(points.size()):
		for light: Dictionary in changes:
			var radius_squared: float = float(light["range"])*float(light["range"])
			if points[index].distance_squared_to(light["position"]) < radius_squared:
				affected_indices.append(index)
				break
	if affected_indices.is_empty():
		return
	var instance: MeshInstance3D = terrain_mesh_nodes[key]
	var previous: ArrayMesh = instance.mesh as ArrayMesh
	var arrays: Array = previous.surface_get_arrays(0)
	var normals: PackedVector3Array = inputs["normals"]
	var bases: PackedInt32Array = inputs["base"]
	var colors: PackedColorArray = arrays[Mesh.ARRAY_COLOR]
	var secondary: PackedFloat32Array = arrays[Mesh.ARRAY_CUSTOM0]
	for index: int in affected_indices:
		var channels: Dictionary = TERRAIN_ILLUMINATION.channels(points[index],normals[index],bases[index],
			source_profile.terrain_lights,source_profile.terrain_render["constants"])
		colors[index] = channels["diffuse"]
		var extra: Color = channels["secondary"]
		secondary[index*4] = extra.r
		secondary[index*4+1] = extra.g
		secondary[index*4+2] = extra.b
		secondary[index*4+3] = extra.a
	arrays[Mesh.ARRAY_COLOR] = colors
	arrays[Mesh.ARRAY_CUSTOM0] = secondary
	var refreshed: ArrayMesh = ArrayMesh.new()
	refreshed.add_surface_from_arrays(Mesh.PRIMITIVE_TRIANGLES,arrays,[],{},previous.surface_get_format(0))
	refreshed.surface_set_material(0,previous.surface_get_material(0))
	instance.mesh = refreshed
	torch_lighting_updates += 1
	torch_lighting_vertices += affected_indices.size()


func _ensure_pick_feedback_clip(dwarf: Node3D, alias: String) -> bool:
	if dig_feedback_data.is_empty():
		dig_feedback_data = DIG_FEEDBACK.read_data()
	var source: Dictionary = dig_feedback_data["clips"].get(alias,{})
	if source.is_empty():
		return false
	var clip_name: String = ANIMATION_ALIASES.get_clip(alias)
	if clip_name != str(dig_feedback_data["aliases"][alias]) \
			or ANIMATION_ALIASES.get_frame_count(alias) != source["frames"].size():
		push_error("Dig feedback disagrees with original animation alias: "+alias)
		return false
	if not dig_feedback_frames.has(clip_name):
		dig_feedback_frames[clip_name] = source["frames"]
	if not surface_walk_meshes.has(clip_name):
		var sequences: Array[Array] = []
		for frame: Dictionary in source["frames"]:
			sequences.append(_build_model_meshes(frame["surfaces"]))
		surface_walk_meshes[clip_name] = sequences
	dwarf_locomotion_visuals[dwarf]["sequences"][clip_name] = surface_walk_meshes[clip_name]
	return true


func _initialize_source_flames() -> void:
	native_flame_data = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_flame.json"))
	for child: Node in scene_root.get_children():
		if child is Node3D and child.has_meta("native_class"):
			_add_source_flame(child,str(child.get_meta("native_class")))


func _add_source_flame(anchor: Node3D, source_class: String) -> void:
	if native_flame_data.is_empty() or flame_emitters.has(anchor) \
			or not native_flame_data["classes"].has(source_class):
		return
	var source: Dictionary = native_flame_data.duplicate()
	source["emitter"] = native_flame_data["classes"][source_class]["emitter"]
	var effect: Node3D = NATIVE_FLAME.new()
	effect.name = "SourceFlame_"+str(anchor.name)
	scene_root.add_child(effect)
	var source_rotation: Basis = anchor.get_meta("native_rotation_basis",Basis.IDENTITY)
	var reflect_y: Basis = Basis(Vector3.RIGHT,Vector3.DOWN,Vector3.BACK)
	var extent: Vector2 = NATIVE_FLAME.projection_half_extents(source,camera.get_camera_projection())
	var configured: Error = effect.configure(source,Transform3D(reflect_y*source_rotation,Vector3.ZERO),extent,
		int(anchor.get_meta("native_ordinal",1)),float(source_profile.shader_pipeline["defaults"]["gamma"]))
	if configured!=OK:
		push_error("Original flame source could not configure: "+source_class)
		effect.queue_free()
		return
	flame_emitters[anchor] = effect
	effect.position = anchor.position


func _update_source_flames() -> void:
	if flame_emitters.is_empty():
		return
	var extent: Vector2 = NATIVE_FLAME.projection_half_extents(native_flame_data,camera.get_camera_projection())
	for anchor: Node3D in flame_emitters.keys():
		var effect: Node3D = flame_emitters[anchor]
		if not is_instance_valid(anchor):
			flame_emitters.erase(anchor)
			effect.queue_free()
			continue
		effect.position = anchor.position
		effect.set_projection(extent)
		effect.update_native_tick(anchor.is_visible_in_tree(),float(native_flame_data["projection"]["update_scale"]))
		var inverse: Basis = effect.global_basis.inverse()
		effect.update_visual(inverse*camera.global_basis.x,inverse*camera.global_basis.y)


func _capture_views(output_dir: String) -> void:
	DirAccess.make_dir_recursive_absolute(output_dir)
	var source_pmp: String = str(source_profile.data["terrain"]["file"])
	var capture_prefix: String = source_pmp.get_file().get_basename()
	var report: Dictionary = {"space": "native_renderer", "depth_scale": render_depth_scale,
		"depth_offset": RENDER_DEPTH_OFFSET, "nodes": [], "views": [],
		"source_pmp": source_pmp,
		"source_pmp_sha256": source_profile.data["terrain"]["sha256"],
		"source_template": source_profile.data["template"],
		"corridor_marks": [], "corridor_preview_active": corridor_stroke.active,
		"terrain_revision": terrain_state.revision, "terrain_triangles": triangle_count,
		"native_diffuse_preview": source_profile.use_native_diffuse,
		"ground_materials": "source_two_pass_loader_and_masks"}
	report["dig_selections"] = []
	for selection: Dictionary in dig_selection_history:
		var selected_point: Vector2i = selection["point"]
		var selected_target: Vector3 = selection["digpoint"]
		report["dig_selections"].append({"worker": selection["worker"],
			"point": [selected_point.x, selected_point.y], "rank": selection["rank"],
			"target_xyz": _vector_array(selected_target), "worker_group": selection["group"]})
		var record: Dictionary = report["dig_selections"][-1]
		var request: Dictionary = selection.get("source_walk_request", {})
		record["planner"] = selection.get("planner", "floor_adapter")
		record["native_walk_request_status"] = request.get("status", "unavailable")
		if request.get("point") is Vector3:
			record["native_walk_request_xyz"] = _vector_array(request["point"])
		var normalized: Dictionary = selection.get("normalized_walk_target", {})
		if normalized.get("point") is Vector3:
			record["normalized_walk_target_xyz"] = _vector_array(normalized["point"])
			record["normalized_walk_target_reason"] = normalized.get("reason", "unknown")
		record["native_walk_rounding"] = request.get("rounding_mode", "unknown")
	report["native_walkmap_current"] = native_walkmap.current
	report["source_world_context"] = {"id": native_world.id,
		"bounds": [native_world.bounds.position.x, native_world.bounds.position.y, native_world.bounds.size.x, native_world.bounds.size.y],
		"template_offset": [native_world.template_offset.x, native_world.template_offset.y]}
	report["native_walkmap_stage"] = native_walkmap.stage
	report["native_walkmap_revision"] = native_walkmap.revision
	report["native_walkmap_unknown_samples"] = native_walkmap.unknown_count
	report["surface_walk_history"] = surface_walk_history
	report["last_terrain_changes"] = []
	for change: Dictionary in last_native_strike.get("changes", []):
		var changed_cell: Vector2i = change["cell"]
		report["last_terrain_changes"].append([changed_cell.x, changed_cell.y, int(change["before"]), int(change["after"])])
	report["surface_walk_actors"] = []
	for dwarf: Node3D in dwarf_nodes:
		report["surface_walk_actors"].append({"worker": str(dwarf.name), "local_position": _vector_array(dwarf.position),
			"mode": int(dwarf_surface_modes.get(dwarf, 2)), "result": int(surface_walk_results.get(dwarf, -1))})
	for sample: Vector2i in _corridor_mark_samples():
		report["corridor_marks"].append([sample.x, sample.y])
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
		var filename: String = output_dir.path_join("%s_native_%d.png" % [capture_prefix, index])
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
