extends RefCounted
## The dwarves of the campaign chapter: the selection, the orders, the
## locomotion, the digging, the miner hat and the torch of the excavation.
##
## The battle scene (scripts/multiplayer_test.gd) drives its dwarves with the
## native streams of the model of the original:
##
##   res://models/native_campaign_models.json
##       objects["mann.3db::mann"]["locomotion"] - the clips of the walk, of
##       the turn and of the idle stand of the model of the original.
##   res://models/dwarf_dig_action.json - the clips of the digging.
##   res://models/dwarf_attachments.json - the sockets of the pickaxe and of
##       the miner hat of the model.
##   res://models/native_animation_timing.json - the speed of the walk.
##
## The chapter has its own map, so the port keeps the streams of the model and
## writes the rules that belong to the map of the battle scene for the board of
## the chapter:
##
##   SOURCE: the clips, the frames, the sockets and the speed of the walk are
##       the data of the original and are read unchanged.
##   ADAPTER: the selection, the outline, the orders of the walk and of the
##       digging and the torch of the excavation follow the board of the
##       chapter: the map lies in the XY plane, the level of a cell is its
##       height along Z, and a sprite of the board stands along the screen
##       vertical, so a dwarf of the board can face four ways.

const ATTACHMENT: Script = preload("res://scripts/native_attachment.gd")
const SOURCE_ACTION: Script = preload("res://scripts/source_animation_action.gd")
const MODEL_MATERIAL: Script = preload("res://scripts/native_model_material.gd")
const FLOOR_WALK: Script = preload("res://scripts/floor_walk_action.gd")
const SURFACE_WALK: Script = preload("res://scripts/surface_walk_action.gd")
const WALKMAP: Script = preload("res://scripts/native_campaign_walkmap.gd")
const WALK_POSE: Script = preload("res://scripts/native_walk_pose.gd")
const FIX_DIG: Script = preload("res://scripts/native_fix_dig.gd")
const DIG_POSE: Script = preload("res://scripts/native_dig_pose.gd")
const NATIVE_FLAME: Script = preload("res://scripts/native_flame_emitter.gd")

const MODELS_PATH: String = "res://models/native_campaign_models.json"
const DIG_ACTION_PATH: String = "res://models/dwarf_dig_action.json"
const TORCH_VISUAL_PATH: String = "res://models/native_torch_visual.json"
const TIMING_PATH: String = "res://models/native_animation_timing.json"
const FLAME_PATH: String = "res://models/native_flame.json"
const SURFACE_CLIPS_PATH: String = "res://models/dwarf_surface_walk.json"
const DWARF_MODEL_KEY: String = "mann.3db::mann"

const NATIVE_POINT_SCALE: float = 16384.0
const OBJECT_WORLD_SCALE: float = 0.005
## The scale of the depth of the board: the root of the scene packs the level
## of a cell by this factor (native_campaign_first_level.gd:RENDER_DEPTH_SCALE).
const RENDER_DEPTH_SCALE: float = 0.5
## The level of the flat ground of the map in the logical space of the board.
const GROUND_LEVEL: float = 15.0
## The tilt of the native view of the chapter (Campaign.tcl:10, set_view with
## rx = -0.29): the level of a cell leans towards the camera with it.
const NATIVE_TILT: float = 0.29
## The rate of the clips of the walk and of the idle of the battle scene.
const WALK_ANIMATION_FPS: float = 10.0
const IDLE_ANIMATION_FPS: float = 7.0
## The distance of a press and of its release that is still a click and not a
## drag of the camera.
const CLICK_TOLERANCE: float = 8.0
## The reach of the digging of a dwarf, in cells of the board.
const DIG_REACH: float = 3.0
## ADAPTER: prefer a stance beside the block; use the original outer reach
## only when the present terrain has not opened a closer route yet.
const DIG_PREFERRED_REACH: float = 1.6

var root: Node3D = null
var camera: Camera3D = null
## The excavation of the chapter: the marks of the tunnels and of the caves and
## the blocks of the map.
var dig: RefCounted = null
var walkmap: RefCounted = null
var profile: RefCounted = null
var status: Label = null

## The dwarves of the chapter, in the order of their placement.
var dwarf_nodes: Array[Node3D] = []
## The heading of a dwarf, in the convention of the board: the angle of the
## front of the sprite around the screen vertical.
var dwarf_headings: Dictionary = {}
## The visuals of a dwarf: the static body, the clips and the frames.
var dwarf_visuals: Dictionary = {}
## The walk of a dwarf: the path, the state and the frame of the clip.
var dwarf_walk_actions: Dictionary = {}
## The job of the digging of a dwarf: the cell, the phase and the clip.
var dwarf_dig_jobs: Dictionary = {}
## The frame of the idle clip that every dwarf shows at the moment.
var dwarf_idle_frames: Dictionary = {}
## The dwarves that are on their way to a cell of the board.
var dwarf_last_targets: Dictionary = {}
var dwarf_surface_modes: Dictionary = {}
## The torches of the excavation, by the cell that carries them.
var torch_nodes: Dictionary = {}

var selected_dwarf: Node3D = null
var idle_elapsed: float = 0.0

var _sequences: Dictionary = {}
var _dig_action_data: Dictionary = {}
var _attachment_data: Dictionary = {}
var _attachment_meshes: Dictionary = {}
var _actor_attachments: Dictionary = {}
var _torch_meshes: Array[ArrayMesh] = []
var _torch_visual_data: Dictionary = {}
var _flame_data: Dictionary = {}
var _flame_emitters: Dictionary = {}
var _outline_material: ShaderMaterial = null
var _outline_proxies: Dictionary = {}
var _outline_mesh_cache: Dictionary = {}
var _model_material: RefCounted = null
var _texture_cache: Dictionary = {}
var _timing: Dictionary = {}
var _surface_clip_data: Dictionary = {}
var _surface_meshes: Dictionary = {}
var _press_position: Vector2 = Vector2.ZERO
var _press_on_dwarf: bool = false
## The scene lights the frames of the clips of the dwarves like it lights the
## models of the chapter, so a dwarf does not change its tone when it starts
## to walk.
var _mesh_lighter: Callable = Callable()


## The lighter of the frames of the clips.
func set_mesh_lighter(lighter: Callable) -> void:
	_mesh_lighter = lighter


## The setup of the module: the board, the camera, the excavation of the
## chapter and the label of the state.
func setup(render_root: Node3D, view: Camera3D, excavation: RefCounted,
		source_profile: RefCounted, caption: Label, chapter_cells: Array = []) -> void:
	root = render_root
	camera = view
	dig = excavation
	profile = source_profile
	status = caption
	if not chapter_cells.is_empty():
		walkmap = WALKMAP.new()
		walkmap.setup(dig, chapter_cells)


## The registration of a dwarf of the scene.
##
## The dwarf keeps the transform of its placement: the model of the board
## stands along the screen vertical, so the feet of a dwarf stand on the cell
## of its placement and the body reaches one unit up the screen.
func register_dwarf(node: Node3D) -> void:
	if node == null or dwarf_nodes.has(node):
		return
	dwarf_nodes.append(node)
	dwarf_headings[node] = _heading_of(node)
	if walkmap != null:
		var sample: Variant = _nearest_surface_sample(Vector2(node.position.x, -node.position.y), 0.3)
		if sample is Vector2i:
			dwarf_surface_modes[node] = WALK_POSE.mode(int(walkmap.sample(sample)), false, false)
	var animated := Node3D.new()
	animated.name = "AnimatedBody"
	animated.visible = false
	node.add_child(animated)
	var defaults: Array = []
	for child: Node in node.get_children():
		if child is MeshInstance3D:
			defaults.append(child)
	dwarf_visuals[node] = {"default": defaults, "sequences": _load_sequences().duplicate(),
		"current": null, "animated": animated, "body_instances": []}
	# ADAPTER: build source climbing meshes before the first route so a dwarf
	# never stalls a rendered frame when it first reaches a shaft.
	for clip: StringName in [&"stand_zu_kletterstand", &"kletterstand_zu_stand",
			&"kletter_hoch_loop", &"kletter_runter_loop", &"kletter_links_loop",
			&"kletter_rechts_loop", &"kletter_hoch_schnell", &"kletter_runter_schnell",
			&"kletter_links_schnell", &"kletter_rechts_schnell"]:
		_ensure_surface_clip(node, clip)


func dwarf_count() -> int:
	return dwarf_nodes.size()


func selected() -> Node3D:
	return selected_dwarf


## The clips of the model: the locomotion of the manifest of the chapter and
## the clips of the digging of the model file of the original.
func _load_sequences() -> Dictionary:
	if not _sequences.is_empty():
		return _sequences
	var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(MODELS_PATH))
	if parsed is Dictionary:
		var model: Dictionary = parsed.get("objects", {}).get(DWARF_MODEL_KEY, {})
		var locomotion: Dictionary = model.get("locomotion", {})
		for clip_name: String in locomotion:
			var frames: Array = []
			for frame: Dictionary in locomotion[clip_name].get("frames", []):
				frames.append(_lit_meshes(_build_model_meshes(frame.get("surfaces", []))))
			_sequences[clip_name] = frames
	var dig_parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(DIG_ACTION_PATH))
	if dig_parsed is Dictionary:
		_dig_action_data = dig_parsed
		var mesh_cache: Dictionary = {}
		for clip_name: String in _dig_action_data.get("clips", {}):
			var frames: Array = []
			for frame: Dictionary in _dig_action_data["clips"][clip_name].get("frames", []):
				var mesh_id: int = int(frame["mesh_index"])
				if not mesh_cache.has(mesh_id):
					mesh_cache[mesh_id] = _lit_meshes(_build_model_meshes(frame.get("surfaces", [])))
				frames.append(mesh_cache[mesh_id])
			_sequences[clip_name] = frames
	return _sequences


## The light of the chapter on the frames of the clips.
func _lit_meshes(meshes: Array[ArrayMesh]) -> Array[ArrayMesh]:
	if not _mesh_lighter.is_valid():
		return meshes
	var result: Array[ArrayMesh] = []
	for mesh: ArrayMesh in meshes:
		var lit: Variant = _mesh_lighter.call(mesh)
		result.append(lit as ArrayMesh if lit is ArrayMesh else mesh)
	return result


## The meshes of a frame of a clip of the model.
##
## The contract of the points and of the normals is the contract of the battle
## scene (native_campaign_first_level.gd:_build_model_meshes): the point of
## the source is centred in the unit cube and scaled into the world units.
func _build_model_meshes(surfaces: Array) -> Array[ArrayMesh]:
	var meshes: Array[ArrayMesh] = []
	if _model_material == null:
		_model_material = MODEL_MATERIAL.new()
		if not _model_material.call("load_fixture"):
			push_error("Original model normal table is missing")
			return meshes
	for source_surface: Dictionary in surfaces:
		var vertices: Array = source_surface.get("points", [])
		var uvs: Array = source_surface.get("uvs", [])
		var indices: Array = source_surface.get("triangles", [])
		if vertices.is_empty() or uvs.is_empty() or indices.is_empty():
			continue
		var source_normals: PackedVector3Array = _model_material.call("godot_local_normals", source_surface)
		var builder := SurfaceTool.new()
		builder.begin(Mesh.PRIMITIVE_TRIANGLES)
		for index_value: Variant in indices:
			var index: int = int(index_value)
			if index >= vertices.size() or index >= uvs.size():
				continue
			var raw_point: Array = vertices[index]
			var uv: Array = uvs[index]
			builder.set_uv(Vector2(float(uv[0]), float(uv[1])))
			if not source_normals.is_empty():
				builder.set_normal(source_normals[index])
			var native_point: Vector3 = Vector3(float(raw_point[0]) - 0.5,
				-(float(raw_point[1]) - 0.5), float(raw_point[2]) - 0.5) * NATIVE_POINT_SCALE
			builder.add_vertex(native_point * OBJECT_WORLD_SCALE)
		if source_normals.is_empty():
			builder.generate_normals()
		var mesh: ArrayMesh = builder.commit()
		var material := StandardMaterial3D.new()
		material.cull_mode = BaseMaterial3D.CULL_DISABLED
		material.roughness = 0.95
		material.vertex_color_use_as_albedo = false
		var texture_name: String = str(source_surface.get("texture", ""))
		var texture_path: String = str(source_surface.get("texture_res_path",
			"res://textures/models/" + texture_name))
		if not ResourceLoader.exists(texture_path) and not FileAccess.file_exists(texture_path):
			texture_path = "res://assets/textures/" + texture_name
		if not _texture_cache.has(texture_path):
			if ResourceLoader.exists(texture_path):
				_texture_cache[texture_path] = load(texture_path) as Texture2D
			elif FileAccess.file_exists(texture_path):
				_texture_cache[texture_path] = ImageTexture.create_from_image(Image.load_from_file(texture_path))
		if _texture_cache.has(texture_path):
			material.albedo_texture = _texture_cache[texture_path]
			var alpha_range: Array = source_surface.get("alpha_range", [255, 255])
			if int(alpha_range[0]) < 128:
				if texture_name.begins_with("FX_"):
					material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA
				else:
					material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA_SCISSOR
					material.alpha_scissor_threshold = 0.35
		mesh.surface_set_material(0, material)
		meshes.append(mesh)
	return meshes


## The selection: the dwarf under the pointer.
##
## The battle scene picks a dwarf by the box of its mesh on the screen and
## takes the dwarf whose centre of the box lies nearest to the click
## (multiplayer_test.gd:_object_at_screen).
func dwarf_at_screen(screen_position: Vector2) -> Node3D:
	return _object_at_screen(screen_position, dwarf_nodes)


func _object_at_screen(screen_position: Vector2, candidates: Array[Node3D]) -> Node3D:
	var nearest: Node3D = null
	var nearest_distance: float = INF
	for dwarf: Node3D in candidates:
		var bounds := Rect2()
		var has_bounds: bool = false
		for node: Node in dwarf.find_children("*", "MeshInstance3D", true, false):
			var mesh_instance := node as MeshInstance3D
			if mesh_instance == null or not mesh_instance.is_visible_in_tree():
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


func _select_dwarf(dwarf: Node3D) -> void:
	if selected_dwarf != null and selected_dwarf != dwarf:
		_set_dwarf_outline(selected_dwarf, false)
	selected_dwarf = dwarf
	_set_dwarf_outline(dwarf, true)
	_set_status("%s выбран: нажмите на клетку, чтобы копать, или на землю, чтобы идти" % dwarf.name)
	print("DWARF_SELECTED " + str(dwarf.name))


func _clear_dwarf_selection() -> void:
	if selected_dwarf == null:
		return
	_set_dwarf_outline(selected_dwarf, false)
	selected_dwarf = null


## The outline of the selected dwarf: one contour of the body of the sprite.
##
## The overlay of every part of the model would draw a seam around the beard,
## the limbs and the helmet, so the port uses one merged mesh of the body, as
## the battle scene does (multiplayer_test.gd:_set_dwarf_outline).
func _set_dwarf_outline(dwarf: Node3D, enabled: bool) -> void:
	if _outline_material == null:
		var shader := Shader.new()
		shader.code = """shader_type spatial;
render_mode unshaded, cull_front;
uniform float outline_width = 0.018;
uniform vec4 outline_color : source_color = vec4(1.0, 1.0, 1.0, 1.0);
void vertex() { VERTEX += NORMAL * outline_width; }
void fragment() { ALBEDO = outline_color.rgb; EMISSION = outline_color.rgb * 0.35; }
"""
		_outline_material = ShaderMaterial.new()
		_outline_material.shader = shader
	var proxy: MeshInstance3D = _dwarf_outline_proxy(dwarf)
	proxy.visible = enabled
	if enabled:
		_refresh_dwarf_outline(dwarf)


func _dwarf_outline_proxy(dwarf: Node3D) -> MeshInstance3D:
	if _outline_proxies.has(dwarf):
		return _outline_proxies[dwarf] as MeshInstance3D
	var proxy := MeshInstance3D.new()
	proxy.name = "SelectionSilhouette"
	proxy.cast_shadow = GeometryInstance3D.SHADOW_CASTING_SETTING_OFF
	proxy.material_override = _outline_material
	proxy.visible = false
	dwarf.add_child(proxy)
	_outline_proxies[dwarf] = proxy
	return proxy


func _refresh_dwarf_outline(dwarf: Node3D) -> void:
	if dwarf != selected_dwarf or not dwarf_visuals.has(dwarf):
		return
	var visuals: Dictionary = dwarf_visuals[dwarf]
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
	proxy.mesh = _combined_outline_mesh(body_meshes)


func _combined_outline_mesh(body_meshes: Array[ArrayMesh]) -> ArrayMesh:
	var key_parts := PackedStringArray()
	for mesh: ArrayMesh in body_meshes:
		key_parts.append(str(mesh.get_instance_id()))
	var key: String = ":".join(key_parts)
	if _outline_mesh_cache.has(key):
		return _outline_mesh_cache[key] as ArrayMesh
	var builder := SurfaceTool.new()
	builder.begin(Mesh.PRIMITIVE_TRIANGLES)
	for mesh: ArrayMesh in body_meshes:
		for surface_index: int in range(mesh.get_surface_count()):
			var arrays: Array = mesh.surface_get_arrays(surface_index)
			var vertices: PackedVector3Array = arrays[Mesh.ARRAY_VERTEX]
			var normals: PackedVector3Array = arrays[Mesh.ARRAY_NORMAL]
			var index_data: Variant = arrays[Mesh.ARRAY_INDEX]
			var indices: PackedInt32Array = index_data if index_data is PackedInt32Array else PackedInt32Array()
			if indices.is_empty():
				for index: int in range(vertices.size()):
					builder.set_normal(normals[index] if index < normals.size() else Vector3.UP)
					builder.add_vertex(vertices[index])
			else:
				for index: int in indices:
					builder.set_normal(normals[index] if index < normals.size() else Vector3.UP)
					builder.add_vertex(vertices[index])
	var combined: ArrayMesh = builder.commit()
	_outline_mesh_cache[key] = combined
	return combined


## The input of the dwarves: a click on a dwarf selects it, a click on the
## board gives the order of the selected dwarf.
##
## The tool of the excavation keeps the priority over the order of the walk:
## a click on a marked cell always digs, a click on the free ground walks
## only when no tool of the excavation is armed.
func handle_input(event: InputEvent) -> bool:
	if not (event is InputEventMouseButton):
		return false
	var button := event as InputEventMouseButton
	if button.button_index != MOUSE_BUTTON_LEFT:
		return false
	if button.pressed:
		_press_position = button.position
		_press_on_dwarf = false
		var clicked: Node3D = dwarf_at_screen(button.position)
		if clicked != null:
			_select_dwarf(clicked)
			_press_on_dwarf = true
			return true
		return false
	if _press_on_dwarf:
		_press_on_dwarf = false
		return true
	if _press_position.distance_to(button.position) > CLICK_TOLERANCE:
		return false
	if selected_dwarf == null:
		return false
	_command_selected_dwarf(button.position)
	return true


## The order of the selected dwarf: to dig a marked cell or to walk to a cell.
func _command_selected_dwarf(screen_position: Vector2) -> void:
	# Marks live on the marker plane. A walk order instead belongs to the
	# worker's exposed surface, which may be below that plane.
	var mark_point: Variant = dig._point(screen_position)
	if mark_point is Vector2:
		var mark_cell := Vector2i(floori(mark_point.x), floori(mark_point.y))
		if dig.is_marked(mark_cell):
			_assign_dig(selected_dwarf, mark_cell)
			return
	var picked: Variant = _map_point(screen_position)
	if not picked is Vector2:
		return
	var cell := Vector2i(floori(picked.x), floori(picked.y))
	if not dig.tool.is_empty():
		# The tool of the excavation is armed: the click belongs to the mark.
		return
	_assign_walk(selected_dwarf, cell)


## The cell of the board under the pointer.
##
## The board lies in the XY plane and the level of a cell is its height along
## Z, so the ray of the camera meets the plane of the surface of the map.
func _map_point(screen_position: Vector2) -> Variant:
	if camera == null or root == null:
		return null
	var world_origin := camera.project_ray_origin(screen_position)
	var origin: Vector3 = root.to_local(world_origin)
	var direction: Vector3 = root.to_local(world_origin + camera.project_ray_normal(screen_position)) - origin
	# ADAPTER: projecting every order onto untouched rock shifts clicks on a
	# lower visible platform into its front edge or into closed terrain.
	var level: float = selected_dwarf.position.z if selected_dwarf != null else GROUND_LEVEL
	var hit: Variant = Plane(Vector3(0.0, 0.0, 1.0), level).intersects_ray(origin, direction)
	return Vector2(hit.x, -hit.y) if hit is Vector3 else null


## The order of the walk: the dwarf walks to a cell of the board.
func _assign_walk(dwarf: Node3D, cell: Vector2i) -> void:
	if walkmap != null:
		var target: Variant = _nearest_surface_sample(Vector2(float(cell.x) + 0.5,
			float(cell.y) + 0.5), 1.2)
		if target is Vector2i and _start_surface_walk(dwarf, target):
			_cancel_dig(dwarf)
			return
		_set_status("Туда не пройти по известной карте ходов")
		print("DWARF_MOVE_REJECT reason=no_surface_route cell=%s" % str(cell))
		return
	var level: float = dig.cell_level(cell)
	if level < 0.0:
		_set_status("Эта клетка не принадлежит карте")
		return
	var path: Array[Vector3] = _walk_path(dwarf, cell, level)
	if path.size() < 2:
		_set_status("Туда не пройти: дорога перекрыта")
		print("DWARF_MOVE_REJECT reason=blocked cell=%s" % str(cell))
		return
	_start_walk(dwarf, path)
	_cancel_dig(dwarf)


## The chapter uses the same 1/8-cell surface planner as multiplayer. Search
## only proven navigable samples; a missing chapter cell stays unknown.
func _nearest_surface_sample(position_xy: Vector2, radius: float) -> Variant:
	if walkmap == null:
		return null
	var center: Vector2i = Vector2i(roundi(position_xy.x * 8.0), roundi(position_xy.y * 8.0))
	var count: int = ceili(radius * 8.0)
	var best: Variant = null
	var best_distance: float = radius * radius
	for y: int in range(center.y - count, center.y + count + 1):
		for x: int in range(center.x - count, center.x + count + 1):
			var sample: Vector2i = Vector2i(x, y)
			var distance: float = (Vector2(sample) * 0.125).distance_squared_to(position_xy)
			if distance > best_distance:
				continue
			var flags: Variant = walkmap.sample(sample)
			if flags == null or (int(flags) & 5) != 1:
				continue
			best = sample
			best_distance = distance
	return best


func _start_surface_walk(dwarf: Node3D, target_sample: Vector2i,
		goal_depth: Variant = null) -> bool:
	var start: Variant = _nearest_surface_sample(Vector2(dwarf.position.x, -dwarf.position.y), 0.3)
	if not start is Vector2i:
		return false
	walkmap.set_route_window(start, target_sample)
	var route: Dictionary = SURFACE_WALK.plan(start, target_sample, walkmap,
		Callable(walkmap, "surface_height"), true, true)
	return _start_planned_surface_walk(dwarf, route, goal_depth)


func _start_planned_surface_walk(dwarf: Node3D, route: Dictionary,
		goal_depth: Variant = null) -> bool:
	if route.get("status") != "ok":
		return false
	if not SURFACE_WALK.project_floor_runs(route["positions"], route["modes"], route["samples"],
			Callable(walkmap, "surface_height"), dwarf.position.z, goal_depth):
		return false
	_stop_walk(dwarf)
	var action: RefCounted = SURFACE_WALK.new()
	action.samples = route["samples"]
	action.modes = route["modes"]
	action.path = route["positions"]
	action.path_index = 0
	action.target = action.path[-1]
	action.previous_mode = int(dwarf_surface_modes.get(dwarf, action.modes[0]))
	var last_target: Vector3 = dwarf_last_targets.get(dwarf, Vector3.INF)
	action.fast = not is_inf(last_target.x) and Vector2(last_target.x, last_target.y).distance_to(
		Vector2(action.target.x, action.target.y)) < 3.0
	dwarf_last_targets[dwarf] = action.target
	dwarf_walk_actions[dwarf] = action
	print("DWARF_SURFACE_WALK_START %s target=%s samples=%d planner=%s speed=%.3f" % [
		dwarf.name, str(action.target), action.samples.size(), route["planner"], _walk_speed(action)])
	return true


## The path of the walk: the straight line of the board between the cell of
## the dwarf and the cell of the order.
##
## ADAPTER: the battle scene walks on the grid of its navigation
## (AStarGrid2D over the samples of the map). The board of the chapter has no
## navigation grid, so the port walks on the straight line and accepts it only
## when every cell of the line carries the same level: the dwarves walk on the
## flat ground of the map and in the tunnels of their own level, they do not
## climb the slopes of the chapter yet.
func _walk_path(dwarf: Node3D, cell: Vector2i, level: float) -> Array[Vector3]:
	var start_cell := _dwarf_cell(dwarf)
	var steps: int = maxi(absi(cell.x - start_cell.x), absi(cell.y - start_cell.y))
	var path: Array[Vector3] = [Vector3(dwarf.position.x, dwarf.position.y, level)]
	if steps == 0:
		return path
	for step: int in range(1, steps + 1):
		var ratio: float = float(step) / float(steps)
		var sample := Vector2i(roundi(lerpf(float(start_cell.x), float(cell.x), ratio)),
			roundi(lerpf(float(start_cell.y), float(cell.y), ratio)))
		if absf(dig.cell_level(sample) - level) > 0.01:
			return []
		path.append(_cell_centre(sample, level))
	path[path.size() - 1] = _cell_centre(cell, level)
	return path


## The middle of a cell of the board.
func _cell_centre(cell: Vector2i, level: float) -> Vector3:
	return Vector3(float(cell.x) + 0.5, -float(cell.y) - 0.5, level)


## The start of the walk: the turn of the dwarf and then the walk itself.
func _start_walk(dwarf: Node3D, path: Array[Vector3]) -> void:
	_stop_walk(dwarf)
	var walk: RefCounted = FLOOR_WALK.new()
	walk.path = path
	walk.target = path[path.size() - 1]
	var last_target: Vector3 = dwarf_last_targets.get(dwarf, Vector3.INF)
	walk.fast = not is_inf(last_target.x) and Vector2(last_target.x, last_target.z).distance_to(
		Vector2(walk.target.x, walk.target.y)) < 3.0
	dwarf_last_targets[dwarf] = walk.target
	var first_direction := Vector2(path[1].x - dwarf.position.x, path[1].y - dwarf.position.y)
	if first_direction.length_squared() <= 0.0:
		first_direction = Vector2(walk.target.x - dwarf.position.x, walk.target.y - dwarf.position.y)
	walk.pending_heading = _heading_of_direction(first_direction)
	var current_heading: float = float(dwarf_headings.get(dwarf, 0.0))
	var turn_delta: float = wrapf(walk.pending_heading - current_heading, -PI, PI)
	if absf(turn_delta) > 1.4:
		walk.state = &"drehen_ganz_links" if turn_delta > 0.0 else &"drehen_ganz"
	elif absf(turn_delta) > 0.2:
		walk.state = &"drehen_links" if turn_delta > 0.0 else &"drehen_rechts"
	else:
		walk.state = _walk_sequence(&"start", walk)
	dwarf_walk_actions[dwarf] = walk
	_show_dwarf_animation_frame(dwarf, walk.state, 0)
	print("DWARF_WALK_START %s target=%s nodes=%d speed=%.3f" % [dwarf.name,
		str(walk.target), path.size(), _walk_speed(walk)])


func _walk_sequence(stage: StringName, walk: RefCounted = null) -> StringName:
	var fast: bool = walk.fast if walk != null else false
	return StringName(("laufen_schnell_" if fast else "gehen_") + String(stage))


## The speed of the walk of the original, converted into the cells of the board.
func _walk_speed(walk: RefCounted = null) -> float:
	if _timing.is_empty():
		var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(TIMING_PATH))
		if parsed is Dictionary:
			_timing = parsed
	var fast: bool = walk.fast if walk != null else false
	var model: Dictionary = _timing.get("models", {}).get("mann", {})
	var clip: String = "laufen_schnell_loop" if fast else "gehen_loop"
	var speed: float = float(model.get("clips", {}).get(clip, {}).get(
		"slot_speed_world_per_game_second", 0.8110876083374023))
	# SOURCE: the chapter map and the imported model both use one world unit
	# per chapter cell. The battle scene's 1/8-cell navigation samples are
	# sample spacing, not a multiplier for the movement speed.
	if walk is SURFACE_WALK and walk.previous_mode == 0:
		return float(model.get("wall_group_speed_world_per_game_second", {}).get(
			"schnell" if fast else "loop", speed))
	return speed


## The state machine of the walk: the turn, then the walk, then the end.
func _update_one_dwarf_walk(dwarf: Node3D, delta: float) -> void:
	if not dwarf_walk_actions.has(dwarf):
		return
	var walk: RefCounted = dwarf_walk_actions[dwarf]
	if walk is SURFACE_WALK:
		_update_surface_walk(dwarf, delta)
		return
	walk.elapsed += delta
	var sequence_count: int = _sequence_frame_count(dwarf, walk.state)
	if sequence_count == 0:
		if _advance_along_path(delta, dwarf) and dwarf_walk_actions.has(dwarf):
			_finish_walk(dwarf)
		return
	var requested_frame: int = int(floor(walk.elapsed * WALK_ANIMATION_FPS))
	if String(walk.state).begins_with("drehen_") and requested_frame >= sequence_count:
		_set_dwarf_heading(dwarf, walk.pending_heading)
		walk.state = _walk_sequence(&"start", walk)
		walk.elapsed = 0.0
		requested_frame = 0
		sequence_count = _sequence_frame_count(dwarf, walk.state)
	elif walk.state == _walk_sequence(&"start", walk) and requested_frame >= sequence_count:
		walk.state = _walk_sequence(&"loop", walk)
		walk.elapsed = 0.0
		requested_frame = 0
		sequence_count = _sequence_frame_count(dwarf, walk.state)
	elif walk.state == _walk_sequence(&"loop", walk):
		requested_frame %= sequence_count
	elif walk.state == _walk_sequence(&"end", walk) and requested_frame >= sequence_count:
		_finish_walk(dwarf)
		return
	if walk.state == _walk_sequence(&"start", walk) or walk.state == _walk_sequence(&"loop", walk):
		if _advance_along_path(delta, dwarf):
			if not dwarf_walk_actions.has(dwarf):
				return
			walk.state = _walk_sequence(&"end", walk)
			walk.elapsed = 0.0
			requested_frame = 0
	if requested_frame != walk.frame:
		walk.frame = requested_frame
		_show_dwarf_animation_frame(dwarf, walk.state, requested_frame)


## The movement of the dwarf along the path of the board.
func _advance_along_path(delta: float, dwarf: Node3D) -> bool:
	if not dwarf_walk_actions.has(dwarf):
		return true
	var walk: RefCounted = dwarf_walk_actions[dwarf]
	if walk.path_index >= walk.path.size():
		return true
	var waypoint: Vector3 = walk.path[walk.path_index]
	var current: Vector3 = dwarf.position
	var direction: Vector2 = Vector2(waypoint.x - current.x, waypoint.y - current.y)
	var step: float = _walk_speed(walk) * delta
	var next: Vector3 = current.move_toward(waypoint, step)
	dwarf.position = next
	if direction.length_squared() > 0.0:
		_set_dwarf_heading(dwarf, _heading_of_direction(direction))
	if next.is_equal_approx(waypoint):
		walk.path_index += 1
		if walk.path_index >= walk.path.size():
			return true
		var remaining: float = delta - current.distance_to(waypoint) / _walk_speed(walk)
		if remaining > 0.000001:
			return _advance_along_path(remaining, dwarf)
	return false


func _ensure_surface_clip(dwarf: Node3D, clip: StringName) -> bool:
	if _surface_clip_data.is_empty():
		var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(SURFACE_CLIPS_PATH))
		if not parsed is Dictionary:
			return false
		_surface_clip_data = parsed
	if not _surface_clip_data.get("clips", {}).has(String(clip)):
		return false
	var sequences: Dictionary = dwarf_visuals[dwarf]["sequences"]
	if sequences.has(String(clip)):
		return true
	var frames: Array = []
	for source_frame: Dictionary in _surface_clip_data["clips"][String(clip)]["frames"]:
		var mesh_id: int = int(source_frame["mesh_index"])
		if not _surface_meshes.has(mesh_id):
			_surface_meshes[mesh_id] = _lit_meshes(_build_model_meshes(source_frame["surfaces"]))
		frames.append(_surface_meshes[mesh_id])
	sequences[String(clip)] = frames
	return not frames.is_empty()


func _surface_clip(dwarf: Node3D, walk: RefCounted, clip: StringName,
		delta: float, loop: bool) -> bool:
	if walk.state != clip:
		walk.state = clip
		walk.elapsed = 0.0
		walk.frame = -1
		if String(clip).begins_with("kletter") or clip == &"stand_zu_kletterstand":
			_ensure_surface_clip(dwarf, clip)
	walk.elapsed += delta
	var count: int = _sequence_frame_count(dwarf, clip)
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
	_stop_walk(dwarf)
	_cancel_dig(dwarf)
	_set_status("Маршрут стал недоступен")
	print("DWARF_SURFACE_WALK_ABORTED %s reason=%s" % [dwarf.name, reason])


## Consume the full frame's travel budget across 1/8-cell source waypoints.
func _update_surface_walk(dwarf: Node3D, delta: float) -> void:
	var remaining: float = delta
	for iteration: int in range(4096):
		if not dwarf_walk_actions.has(dwarf):
			return
		var walk: RefCounted = dwarf_walk_actions[dwarf]
		if walk.path_index >= walk.path.size():
			_step_surface_walk(dwarf, 0.0)
			return
		if walk.modes[walk.path_index] != walk.previous_mode:
			_step_surface_walk(dwarf, remaining)
			return
		var waypoint: Vector3 = walk.path[walk.path_index]
		if walk.previous_mode == 0:
			var depth: Variant = WALK_POSE.wall_depth(walk.samples[walk.path_index],
				Callable(walkmap, "surface_height"))
			if depth != null:
				waypoint.z = float(depth)
		var duration: float = dwarf.position.distance_to(waypoint) / maxf(_walk_speed(walk), 0.001)
		var spent: float = minf(remaining, duration)
		_step_surface_walk(dwarf, spent)
		remaining -= spent
		if remaining <= 0.000001:
			return


func _step_surface_walk(dwarf: Node3D, delta: float) -> void:
	var walk: RefCounted = dwarf_walk_actions[dwarf]
	if walk.path_index >= walk.path.size():
		_finish_walk(dwarf)
		return
	var sample: Vector2i = walk.samples[walk.path_index]
	var flags: Variant = walkmap.sample(sample)
	if flags == null or (int(flags) & 1) == 0:
		_abort_surface_walk(dwarf, "navigation_changed_or_unknown")
		return
	var mode: int = WALK_POSE.mode(int(flags), false, false)
	if mode != walk.modes[walk.path_index]:
		_abort_surface_walk(dwarf, "mode_changed")
		return
	if mode != walk.previous_mode:
		var transition: StringName = &"stand_zu_kletterstand" if mode == 0 else &"kletterstand_zu_stand"
		_set_dwarf_heading(dwarf, PI)
		if _surface_clip(dwarf, walk, transition, delta, false):
			walk.previous_mode = mode
			dwarf_surface_modes[dwarf] = mode
			walk.state = &""
	var waypoint: Vector3 = walk.path[walk.path_index]
	if mode == 0:
		var depth: Variant = WALK_POSE.wall_depth(sample, Callable(walkmap, "surface_height"))
		if depth == null:
			_abort_surface_walk(dwarf, "unknown_wall_height")
			return
		waypoint.z = float(depth)
		# ADAPTER: the climbing body belongs to the far, source-derived wall.
		# The chapter's projected floor run can lie near the camera, so moving
		# diagonally toward this point makes the dwarf crawl through open air.
		if dwarf.position.z > waypoint.z:
			dwarf.position.z = waypoint.z
	var direction: Vector3 = waypoint - dwarf.position
	var clip: StringName
	if mode == 0:
		var step: Vector2i = sample - walk.samples[maxi(0, walk.path_index - 1)]
		var part: String = "hoch" if step.y < 0 else "runter"
		if step.x != 0:
			part = "rechts" if step.x > 0 else "links"
		clip = StringName("kletter_%s_%s" % [part, "schnell" if walk.fast else "loop"])
		_set_dwarf_heading(dwarf, PI)
	else:
		clip = _walk_sequence(&"loop", walk)
		if Vector2(direction.x, direction.y).length_squared() > 0.00000001:
			_set_dwarf_heading(dwarf, _heading_of_direction(Vector2(direction.x, direction.y)))
	if mode == walk.previous_mode:
		_surface_clip(dwarf, walk, clip, delta, true)
	if not dwarf_walk_actions.has(dwarf):
		return
	dwarf.position = dwarf.position.move_toward(waypoint, _walk_speed(walk) * delta)
	if dwarf.position.is_equal_approx(waypoint):
		dwarf_surface_modes[dwarf] = mode
		walk.path_index += 1


func _stop_walk(dwarf: Node3D) -> void:
	if not dwarf_walk_actions.has(dwarf):
		return
	dwarf_walk_actions.erase(dwarf)
	_show_dwarf_default(dwarf)
	dwarf_idle_frames.erase(dwarf)


func _finish_walk(dwarf: Node3D) -> void:
	if not dwarf_walk_actions.has(dwarf):
		return
	_stop_walk(dwarf)
	print("DWARF_WALK_RESULT %s result=4" % dwarf.name)
	if dwarf_dig_jobs.has(dwarf) and str(dwarf_dig_jobs[dwarf]["phase"]) == "approach":
		_begin_dig_action(dwarf)


## The heading of a dwarf: the front of the sprite of the board.
##
## ADAPTER: a sprite of the board stands along the screen vertical, so it can
## face four ways: along the row of the board to the left and to the right,
## and towards the camera and away from it. The angle of the front follows the
## convention of the battle scene (atan2 of the x and of the z of the front).
func _heading_of_direction(direction: Vector2) -> float:
	var front := _front_of_direction(direction)
	return atan2(front.x, front.z)


func _front_of_direction(direction: Vector2) -> Vector3:
	if direction.length_squared() <= 0.0:
		return Vector3(-1.0, 0.0, 0.0)
	if absf(direction.x) >= absf(direction.y):
		return Vector3(-1.0, 0.0, 0.0) if direction.x < 0.0 else Vector3(1.0, 0.0, 0.0)
	# Down the screen the dwarf looks at the camera, up the screen it turns
	# its back to the camera.
	return Vector3(0.0, 0.0, 1.0) if direction.y < 0.0 else Vector3(0.0, 0.0, -1.0)


func _heading_of(dwarf: Node3D) -> float:
	var front := dwarf.transform.basis.z
	return atan2(front.x, front.z)


func _set_dwarf_heading(dwarf: Node3D, heading: float) -> void:
	# The root of the scene packs the depth of the board by 0.5, so a rotation
	# below that scale would shear the sprite: the rotation is written in the
	# logical space of the board and the packing is undone in front of it.
	var unpack := Basis(Vector3.RIGHT, Vector3.UP, Vector3(0.0, 0.0, 1.0 / RENDER_DEPTH_SCALE))
	var front := Vector3(sin(heading), 0.0, cos(heading))
	var up := Vector3.UP
	var right := up.cross(front)
	dwarf.transform.basis = unpack * Basis(right, up, front)
	dwarf_headings[dwarf] = heading


## The idle of the dwarves that stand still.
func _update_idle_animations(delta: float) -> void:
	idle_elapsed += delta
	for index: int in range(dwarf_nodes.size()):
		var dwarf: Node3D = dwarf_nodes[index]
		if dwarf_walk_actions.has(dwarf):
			continue
		if dwarf_dig_jobs.has(dwarf) and str(dwarf_dig_jobs[dwarf]["phase"]) == "work":
			continue
		var sequence_name: StringName = &"stand_anim_a" if index % 2 == 0 else &"stand_anim_b"
		if int(dwarf_surface_modes.get(dwarf, 2)) == 0:
			sequence_name = &"kletterstand_anim"
			_ensure_surface_clip(dwarf, sequence_name)
		var frame_count: int = _sequence_frame_count(dwarf, sequence_name)
		if frame_count == 0:
			continue
		var frame_index: int = (int(floor(idle_elapsed * IDLE_ANIMATION_FPS)) + index * 3) % frame_count
		if int(dwarf_idle_frames.get(dwarf, -1)) == frame_index:
			continue
		dwarf_idle_frames[dwarf] = frame_index
		_show_dwarf_animation_frame(dwarf, sequence_name, frame_index)


func _sequence_frame_count(dwarf: Node3D, sequence_name: StringName) -> int:
	if not dwarf_visuals.has(dwarf):
		return 0
	var sequences: Dictionary = dwarf_visuals[dwarf]["sequences"]
	if not sequences.has(String(sequence_name)):
		return 0
	var frames: Array = sequences[String(sequence_name)]
	return frames.size()


## The frame of a clip of a dwarf.
func _show_dwarf_animation_frame(dwarf: Node3D, sequence_name: StringName, frame_index: int) -> void:
	if not dwarf_visuals.has(dwarf):
		return
	var visuals: Dictionary = dwarf_visuals[dwarf]
	for default_mesh: MeshInstance3D in visuals["default"]:
		default_mesh.visible = false
	var current: Variant = visuals.get("current")
	if current is Node3D:
		(current as Node3D).visible = false
	var sequences: Dictionary = visuals["sequences"]
	var sequence_key: String = String(sequence_name)
	if not sequences.has(sequence_key):
		return
	var frames: Array = sequences[sequence_key]
	if frames.is_empty():
		return
	var frame_meshes: Array = frames[clampi(frame_index, 0, frames.size() - 1)]
	var frame_root: Node3D = visuals["animated"]
	var instances: Array = visuals["body_instances"]
	while instances.size() < frame_meshes.size():
		var instance := MeshInstance3D.new()
		frame_root.add_child(instance)
		instances.append(instance)
	for index: int in range(instances.size()):
		var instance: MeshInstance3D = instances[index]
		instance.visible = index < frame_meshes.size()
		if instance.visible:
			instance.mesh = frame_meshes[index]
	frame_root.name = "%s_%02d" % [sequence_key, frame_index]
	frame_root.visible = true
	visuals["current"] = frame_root
	var visual_tick: int = Time.get_ticks_usec()
	_refresh_dwarf_outline(dwarf)
	var outline_ms: float = float(Time.get_ticks_usec() - visual_tick) / 1000.0
	visual_tick = Time.get_ticks_usec()
	_update_work_attachments(dwarf, sequence_key, frame_index)
	if OS.get_cmdline_user_args().has("--profile-dwarf") and \
			(outline_ms > 15.0 or Time.get_ticks_usec() - visual_tick > 15000):
		print("DWARF_PROFILE frame clip=%s frame=%d outline_ms=%.2f attachments_ms=%.2f" % [
			sequence_key, frame_index, outline_ms,
			float(Time.get_ticks_usec() - visual_tick) / 1000.0])


func _show_dwarf_default(dwarf: Node3D) -> void:
	if not dwarf_visuals.has(dwarf):
		return
	var visuals: Dictionary = dwarf_visuals[dwarf]
	var current: Variant = visuals.get("current")
	if current is Node3D:
		(current as Node3D).visible = false
	for default_mesh: MeshInstance3D in visuals["default"]:
		default_mesh.visible = true
	visuals["current"] = null
	_refresh_dwarf_outline(dwarf)
	if _actor_attachments.has(dwarf):
		for attached: Node3D in _actor_attachments[dwarf].values():
			attached.visible = false
			var lamp: OmniLight3D = attached.get_node_or_null("MinerHelmetLight") as OmniLight3D
			if lamp != null:
				lamp.visible = false


## The attachments of a dwarf: the pickaxe and the hat of the miner.
##
## The sockets are the sockets of the model of the original
## (res://models/dwarf_attachments.json), the lamp of the hat belongs to the
## model of the battle scene and burns only while the dwarf digs.
func _update_work_attachments(dwarf: Node3D, clip: String, frame: int) -> void:
	var working: bool = dwarf_dig_jobs.has(dwarf) and str(dwarf_dig_jobs[dwarf]["phase"]) == "work"
	var assigned: bool = dwarf_dig_jobs.has(dwarf)
	if not working and not assigned:
		if _actor_attachments.has(dwarf):
			for attached: Node3D in _actor_attachments[dwarf].values():
				attached.visible = false
				var lamp: OmniLight3D = attached.get_node_or_null("MinerHelmetLight") as OmniLight3D
				if lamp != null:
					lamp.visible = false
		return
	if _attachment_data.is_empty():
		_attachment_data = ATTACHMENT.read_data()
		var textures: Dictionary = ATTACHMENT.decode_textures(_attachment_data)
		for asset: String in ["spitzhacke", "muetze_stein_a"]:
			_attachment_meshes[asset] = ATTACHMENT.build_meshes(
				_attachment_data["assets"][asset]["frames"][0], textures)
	if not _actor_attachments.has(dwarf):
		_actor_attachments[dwarf] = {}
		for asset: String in _attachment_meshes:
			var attached := Node3D.new()
			attached.name = asset
			dwarf.add_child(attached)
			for mesh: ArrayMesh in _attachment_meshes[asset]:
				var visual := MeshInstance3D.new()
				visual.mesh = mesh
				attached.add_child(visual)
			if asset == "muetze_stein_a":
				var lamp := OmniLight3D.new()
				lamp.name = "MinerHelmetLight"
				lamp.position = Vector3(0.0, 0.04, 0.08)
				lamp.light_color = Color(1.0, 0.82, 0.54)
				lamp.light_energy = 1.35
				lamp.omni_range = 2.8
				lamp.shadow_enabled = false
				lamp.visible = false
				attached.add_child(lamp)
			_actor_attachments[dwarf][asset] = attached
	for asset: String in _actor_attachments[dwarf]:
		var slot: int = int(_attachment_data["assets"][asset]["default_slot"])
		var result: Dictionary = ATTACHMENT.sample(_attachment_data, DWARF_MODEL_KEY, clip, frame, slot)
		var attached: Node3D = _actor_attachments[dwarf][asset]
		attached.visible = bool(result["ok"]) and (asset != "spitzhacke" or working)
		if attached.visible:
			attached.transform = result["transform"]
		if asset == "muetze_stein_a":
			var lamp: OmniLight3D = attached.get_node_or_null("MinerHelmetLight") as OmniLight3D
			if lamp != null:
				lamp.visible = attached.visible and working


## The order of the digging: the dwarf walks to the cell of the mark and digs
## it, one strike per clip of the digging.
func _assign_dig(dwarf: Node3D, cell: Vector2i) -> void:
	if walkmap != null:
		_assign_surface_dig(dwarf, cell)
		return
	var stance: Variant = _dig_stance(dwarf, cell)
	if stance == null:
		_set_status("Гном не достаёт до этой клетки")
		print("DWARF_DIG_REJECT reason=out_of_reach cell=%s" % str(cell))
		return
	var level: float = dig.cell_level(stance)
	var path: Array[Vector3] = _walk_path(dwarf, stance, level)
	if path.size() < 2:
		_set_status("Гном не может встать у этой клетки")
		print("DWARF_DIG_REJECT reason=blocked cell=%s" % str(cell))
		return
	dwarf_dig_jobs[dwarf] = {"point": cell, "phase": "approach", "stance": stance}
	_start_walk(dwarf, path)


## ADAPTER: the chapter has no native PMP route cache. Collect legal work
## samples around the mark and reach the nearest one with one source-flag BFS.
## The native FixDig seed remains research evidence, but repeatedly routing
## to every candidate made a single click stall and picked distant stances.
func _assign_surface_dig(dwarf: Node3D, cell: Vector2i) -> void:
	var candidates: Dictionary = {}
	var low: Vector2i = Vector2i(floori((float(cell.x) - DIG_REACH) * 8.0),
		floori((float(cell.y) - DIG_REACH + 0.8) * 8.0))
	var high: Vector2i = Vector2i(ceili((float(cell.x) + DIG_REACH) * 8.0),
		ceili((float(cell.y) + DIG_REACH + 0.8) * 8.0))
	for y: int in range(low.y, high.y):
		for x: int in range(low.x, high.x):
			var sample: Vector2i = Vector2i(x, y)
			if not _dig_sample_reachable(sample, cell):
				continue
			candidates[sample] = true
	var start: Variant = _nearest_surface_sample(Vector2(dwarf.position.x, -dwarf.position.y), 0.3)
	if start is Vector2i and not candidates.is_empty():
		walkmap.set_route_window(start, cell * 8 + Vector2i(4, 4), 4)
		for radius: float in [DIG_PREFERRED_REACH, 2.2, DIG_REACH]:
			var nearby: Dictionary = {}
			for sample: Vector2i in candidates:
				var offset: Vector2 = Vector2(sample) * 0.125 - \
					Vector2(float(cell.x), float(cell.y) + 0.8)
				if offset.length() < radius:
					nearby[sample] = true
			var route: Dictionary = SURFACE_WALK.plan_to_any(start, nearby, walkmap,
				Callable(walkmap, "surface_height"), walkmap.sample_bounds)
			if _start_planned_surface_walk(dwarf, route):
				_cancel_dig(dwarf)
				dwarf_dig_jobs[dwarf] = {"point": cell, "phase": "approach",
					"stance": route["stance_sample"]}
				_set_status("%s идёт к забою" % dwarf.name)
				return
	_set_status("Гном не может добраться до забоя")
	print("DWARF_DIG_REJECT reason=no_surface_route cell=%s" % str(cell))


func _dig_sample_reachable(sample: Vector2i, cell: Vector2i) -> bool:
	var flags: Variant = walkmap.sample(sample)
	if flags == null or (int(flags) & 5) != 1:
		return false
	var offset: Vector2 = Vector2(float(sample.x) * 0.125 - float(cell.x),
		float(sample.y) * 0.125 - float(cell.y) - 0.8)
	return offset.length() < DIG_REACH


## The cell of the board where the dwarf stands to dig a cell.
func _dig_stance(dwarf: Node3D, cell: Vector2i) -> Variant:
	var dwarf_cell := _dwarf_cell(dwarf)
	var best: Variant = null
	var best_distance: float = INF
	for offset: Vector2i in [Vector2i.UP, Vector2i.DOWN, Vector2i.LEFT, Vector2i.RIGHT]:
		var neighbour: Vector2i = cell + offset
		var level: float = dig.cell_level(neighbour)
		if level < 0.0:
			continue
		var distance: float = Vector2(float(neighbour.x - dwarf_cell.x),
			float(neighbour.y - dwarf_cell.y)).length()
		if distance >= DIG_REACH or distance >= best_distance:
			continue
		best_distance = distance
		best = neighbour
	return best


## The clip of the digging of a cell.
##
## ADAPTER: the battle scene picks the clip of the digging by the height of
## the cell of the worker against the cell of the dig (z_dignwalk.tcl:388-420).
## On the board of the chapter the map is seen in plan and the level of a cell
## is its height along Z, so the height of the cell of the dig against the
## worker is the distance of the two on the screen: the rows of the map give
## the vertical of the screen and the level of the cell leans towards the
## camera with the tilt of the native view (Campaign.tcl:10, rx = -0.29).
func _dig_clip(dwarf: Node3D, cell: Vector2i) -> StringName:
	if int(dwarf_surface_modes.get(dwarf, 2)) == 0:
		return DIG_POSE.wall_clip(Vector3(dwarf.position.x, -dwarf.position.y, dwarf.position.z),
			Vector3(float(cell.x), float(cell.y), dig.cell_level(cell)))
	var target: int = dig.mark_target_level(cell)
	var dwarf_cell := _dwarf_cell(dwarf)
	var dwarf_level: float = dig.cell_level(dwarf_cell)
	var height: float = float(dwarf_cell.y - cell.y) * cos(NATIVE_TILT) \
		- float(target - dwarf_level) * sin(NATIVE_TILT)
	if height > 1.6:
		return &"buddeln_oben_normal"
	return &"buddeln_vorn" if height > 0.6 else &"buddeln_unten"


## The start of the clip of the digging.
func _begin_dig_action(dwarf: Node3D) -> void:
	var profile_tick: int = Time.get_ticks_usec()
	if not dwarf_dig_jobs.has(dwarf):
		return
	var job: Dictionary = dwarf_dig_jobs[dwarf]
	var point: Vector2i = job["point"]
	if not dig.is_marked(point):
		_cancel_dig(dwarf)
		return
	var clip: StringName = _dig_clip(dwarf, point)
	if String(clip).begins_with("kletter_"):
		_ensure_surface_clip(dwarf, clip)
	var clip_ms: float = float(Time.get_ticks_usec() - profile_tick) / 1000.0
	var count: int = _sequence_frame_count(dwarf, clip)
	if count == 0:
		_cancel_dig(dwarf)
		return
	var action: RefCounted = SOURCE_ACTION.new()
	var fps: float = float(_dig_action_data.get("clips", {}).get(String(clip), {}).get("adapter_fps", 12.0))
	action.begin(count, fps)
	job["phase"] = "work"
	job["clip"] = clip
	job["action"] = action
	job["frame"] = 0
	# The dwarf turns to the cell that he digs.
	var dwarf_cell := _dwarf_cell(dwarf)
	_set_dwarf_heading(dwarf, _heading_of_direction(Vector2(
		float(point.x - dwarf_cell.x), float(dwarf_cell.y - point.y))))
	_show_dwarf_animation_frame(dwarf, clip, 0)
	if OS.get_cmdline_user_args().has("--profile-dwarf"):
		print("DWARF_PROFILE begin clip=%s load_ms=%.2f total_ms=%.2f" % [
			clip, clip_ms, float(Time.get_ticks_usec() - profile_tick) / 1000.0])
	_set_status("%s копает" % dwarf.name)
	print("DWARF_DIG_ANIMATION %s clip=%s point=%s" % [dwarf.name, clip, point])


## The clock of the digging: the frame of the clip and the strike of the cell.
func _update_dig_jobs(delta: float) -> void:
	for dwarf: Node3D in dwarf_dig_jobs.keys():
		var job: Dictionary = dwarf_dig_jobs[dwarf]
		if str(job["phase"]) != "work":
			continue
		var point: Vector2i = job["point"]
		if not dig.is_marked(point):
			_cancel_dig(dwarf)
			continue
		var action: RefCounted = job["action"]
		var step: Dictionary = action.advance(delta)
		if int(step["frame"]) != int(job["frame"]):
			job["frame"] = step["frame"]
			_show_dwarf_animation_frame(dwarf, job["clip"], int(step["frame"]))
		if not bool(step["complete"]):
			continue
		var strike_tick: int = Time.get_ticks_usec()
		var applied: bool = dig.apply_dwarf_strike(point)
		var strike_ms: float = float(Time.get_ticks_usec() - strike_tick) / 1000.0
		print("DWARF_DIG_CALLBACK %s point=%s accepted=%s" % [dwarf.name, point, applied])
		if applied:
			_spawn_torch(point)
		if OS.get_cmdline_user_args().has("--profile-dwarf"):
			print("DWARF_PROFILE strike cell=%s terrain_ms=%.2f total_ms=%.2f" % [
				point, strike_ms, float(Time.get_ticks_usec() - strike_tick) / 1000.0])
		if dig.is_marked(point):
			_begin_dig_action(dwarf)
		else:
			_continue_digging(dwarf, point)


## ADAPTER: after finishing a cell, keep the same task through adjacent
## marks. The original dig_next trace advances through successive shaft
## cells without a new player click or an idle pose between strikes.
func _continue_digging(dwarf: Node3D, finished: Vector2i) -> void:
	dig.release_dwarf_claim(finished)
	dwarf_dig_jobs.erase(dwarf)
	var next: Variant = _next_nearby_mark(dwarf, finished)
	if next is Vector2i:
		var sample: Variant = _nearest_surface_sample(Vector2(dwarf.position.x,
			-dwarf.position.y), 0.3) if walkmap != null else null
		var from: Vector2 = Vector2(dwarf.position.x, -dwarf.position.y)
		var target: Vector2 = Vector2(float(next.x), float(next.y) + 0.8)
		if sample is Vector2i and from.distance_to(target) < DIG_PREFERRED_REACH \
				and _dig_sample_reachable(sample, next):
			dig.queue.erase(next)
			dig.dwarf_cells[next] = true
			dwarf_dig_jobs[dwarf] = {"point": next, "phase": "work", "stance": sample}
			_begin_dig_action(dwarf)
			return
		_assign_dig(dwarf, next)
		if dwarf_dig_jobs.has(dwarf):
			return
	_show_dwarf_default(dwarf)


func _next_nearby_mark(dwarf: Node3D, finished: Vector2i) -> Variant:
	var best: Variant = null
	var best_cost: float = INF
	for cell: Vector2i in dig.queue:
		if not dig.is_marked(cell) or dig.dwarf_cells.has(cell):
			continue
		var offset: Vector2i = cell - finished
		if absi(offset.x) > 3 or absi(offset.y) > 3:
			continue
		var distance: float = Vector2(float(cell.x) - dwarf.position.x,
			float(cell.y) + dwarf.position.y).length()
		var cost: float = float(absi(offset.x) + absi(offset.y)) * 2.0 + distance
		if cost < best_cost:
			best_cost = cost
			best = cell
	return best


func _cancel_dig(dwarf: Node3D) -> void:
	if not dwarf_dig_jobs.has(dwarf):
		return
	var point: Vector2i = dwarf_dig_jobs[dwarf]["point"]
	dwarf_dig_jobs.erase(dwarf)
	dig.release_dwarf_claim(point)
	_show_dwarf_default(dwarf)


## The torch of the excavation: the dwarves light the passage they open.
##
## The visual of the torch and the light of it are the data of the original
## (res://models/native_torch_visual.json), the flame is the flame of the
## source of the class Misc_Light (res://models/native_flame.json).
func _spawn_torch(cell: Vector2i) -> void:
	if torch_nodes.has(cell) or root == null:
		return
	if _torch_meshes.is_empty():
		var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(TORCH_VISUAL_PATH))
		if not parsed is Dictionary:
			return
		_torch_visual_data = parsed
		var first_frame: Dictionary = _torch_visual_data["asset"]["frames"][0]
		_torch_meshes = _build_model_meshes(first_frame.get("surfaces", []))
	var holder := Node3D.new()
	holder.name = "CampaignTorch_%d_%d" % [cell.x, cell.y]
	var body := Node3D.new()
	body.scale.z = 1.0 / RENDER_DEPTH_SCALE
	holder.add_child(body)
	for mesh: ArrayMesh in _torch_meshes:
		var visual := MeshInstance3D.new()
		visual.mesh = mesh
		body.add_child(visual)
	var spec: Dictionary = _torch_visual_data.get("light", {})
	var offset: Array = spec.get("offset_native", [0.0, 0.0, 0.0])
	var light := OmniLight3D.new()
	light.name = "TorchLight"
	light.position = Vector3(float(offset[0]), -float(offset[1]), float(offset[2]))
	var rgb: Array = spec.get("rgb", [1.0, 0.9, 0.7])
	light.light_color = Color(float(rgb[0]), float(rgb[1]), float(rgb[2]))
	light.omni_range = float(spec.get("range_native", 6.0))
	light.shadow_enabled = false
	holder.add_child(light)
	var level: float = dig.cell_level(cell)
	holder.position = Vector3(float(cell.x) + 0.5, -float(cell.y) - 0.5, level)
	root.add_child(holder)
	torch_nodes[cell] = holder
	_add_source_flame(holder)
	print("CAMPAIGN_TORCH_CREATED cell=%s level=%.1f" % [str(cell), level])


## The flame of the source of the class Misc_Light on the torch.
func _add_source_flame(anchor: Node3D) -> void:
	if _flame_data.is_empty():
		var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(FLAME_PATH))
		if not parsed is Dictionary:
			return
		_flame_data = parsed
	if _flame_emitters.has(anchor):
		return
	if not _flame_data.get("classes", {}).has("Misc_Light"):
		return
	var source: Dictionary = _flame_data.duplicate()
	source["emitter"] = _flame_data["classes"]["Misc_Light"]["emitter"]
	var effect: Node3D = NATIVE_FLAME.new()
	effect.name = "SourceFlame_" + str(anchor.name)
	root.add_child(effect)
	var extent: Vector2 = NATIVE_FLAME.projection_half_extents(source, camera.get_camera_projection())
	var gamma: float = 1.0
	if profile != null and "shader_pipeline" in profile:
		gamma = float(profile.get("shader_pipeline").get("defaults", {}).get("gamma", 1.0))
	var configured: Error = effect.configure(source, Transform3D.IDENTITY, extent, 1, gamma)
	if configured != OK:
		effect.queue_free()
		return
	_flame_emitters[anchor] = effect
	effect.position = anchor.position


## The clock of the flames of the torches.
func _update_flames() -> void:
	if _flame_emitters.is_empty() or camera == null:
		return
	var extent: Vector2 = NATIVE_FLAME.projection_half_extents(_flame_data, camera.get_camera_projection())
	for anchor: Node3D in _flame_emitters.keys():
		if not is_instance_valid(anchor):
			_flame_emitters.erase(anchor)
			continue
		var effect: Node3D = _flame_emitters[anchor]
		effect.position = anchor.position
		effect.set_projection(extent)
		effect.update_native_tick(anchor.is_visible_in_tree(),
			float(_flame_data.get("projection", {}).get("update_scale", 1.0)))
		var inverse: Basis = effect.global_basis.inverse()
		effect.update_visual(inverse * camera.global_basis.x, inverse * camera.global_basis.y)


## The clock of the dwarves of the chapter.
func advance(delta: float) -> void:
	for dwarf: Node3D in dwarf_walk_actions.keys():
		_update_one_dwarf_walk(dwarf, delta)
	_update_dig_jobs(delta)
	_update_idle_animations(delta)
	_update_flames()


## The cell of the board where a dwarf stands.
func _dwarf_cell(dwarf: Node3D) -> Vector2i:
	return Vector2i(floori(dwarf.position.x), floori(-dwarf.position.y))


func _set_status(text: String) -> void:
	if status != null:
		status.text = text
