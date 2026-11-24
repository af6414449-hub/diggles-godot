extends Node3D
## The preview of a level of the level generator of the original.
##
## The generator (scripts/native_level_generator.gd) writes the plan of a level:
## the templates of the original and the number of the objects of every
## resource class. tools/export_generated_level.py stamps those templates into
## a map in the format of the campaign chapter, and this scene draws it with
## the same terrain code, so a generated level can be looked at.
##
## The level of the preview is the generated one alone: the free ground of the
## map around it (the rock of the funnel) belongs to the chapter and is drawn
## by the chapter scene, not here.
##
## Source of truth, read-only:
##   C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data

const PROFILE: Script = preload("res://scripts/native_campaign_profile.gd")
const MODEL_MATERIAL: Script = preload("res://scripts/native_model_material.gd")
const WALLS: Script = preload("res://scripts/native_campaign_walls.gd")
const GROUND: Script = preload("res://scripts/native_campaign_ground.gd")
const CAMERA: Script = preload("res://scripts/native_campaign_camera.gd")
const LEVEL_PATH: String = "res://models/native_generated_level.json"
const MODELS_PATH: String = "res://models/native_generated_level_scene_models.json"
const MANIFEST_PATH: String = "res://models/native_generated_level_models.json"

const NATIVE_POINT_SCALE: float = 16384.0
const OBJECT_WORLD_SCALE: float = 0.005
const BDB_DEPTH_SCALE: float = 2.0
const BDB_DEPTH_OFFSET: float = -14.0
const RENDER_DEPTH_SCALE: float = 0.5
const RENDER_DEPTH_OFFSET: float = 7.0

## The layer of the walls of the excavations.
const WALL_LAYER: int = 2

var profile: RefCounted = null
var native_model_material: RefCounted = null
var level: Dictionary = {}
var scene_root: Node3D = null
var camera: Camera3D = null
var controller: RefCounted = null
var status: Label = null

var triangle_count: int = 0
var surface_count: int = 0
var wall_count: int = 0
var object_count: int = 0
var light_count: int = 0

var _capture_path: String = ""
var _capture_frames: int = -1
var _capture_region: Vector4 = Vector4.ZERO
var _capture_tilt: float = -10.0
var _capture_distance: float = 0.0


func _ready() -> void:
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var capture_index: int = args.find("--capture-path")
	if capture_index >= 0 and capture_index + 1 < args.size():
		_capture_path = args[capture_index + 1]
		_capture_frames = 8
	var region_index: int = args.find("--capture-region")
	if region_index >= 0 and region_index + 1 < args.size():
		var parts: PackedStringArray = str(args[region_index + 1]).split(",")
		if parts.size() == 4:
			_capture_region = Vector4(float(parts[0]), float(parts[1]), float(parts[2]), float(parts[3]))
	var tilt_index: int = args.find("--capture-tilt")
	if tilt_index >= 0 and tilt_index + 1 < args.size():
		_capture_tilt = float(args[tilt_index + 1])
	var distance_index: int = args.find("--capture-distance")
	if distance_index >= 0 and distance_index + 1 < args.size():
		_capture_distance = float(args[distance_index + 1])

	native_model_material = MODEL_MATERIAL.new()
	if not native_model_material.call("load_fixture"):
		push_error("Original model normal table is missing")
		get_tree().quit(1)
		return
	profile = PROFILE.new()
	if not profile.call("load_chapter", LEVEL_PATH):
		get_tree().quit(1)
		return
	level = profile.data
	scene_root = Node3D.new()
	scene_root.name = "GeneratedLevelRenderSpace"
	scene_root.scale.z = RENDER_DEPTH_SCALE
	scene_root.position.z = RENDER_DEPTH_OFFSET
	add_child(scene_root)

	_build_geometry()
	_build_objects()
	_build_camera_and_light()
	_build_caption()
	print("GENERATED_LEVEL_READY cells=%d objects=%d lights=%d surfaces=%d walls=%d triangles=%d" % [
		(level["cells"] as Array).size(), object_count, light_count, surface_count, wall_count, triangle_count])


## The terrain of the level: the cells of the templates of the original.
func _build_geometry() -> void:
	var tools: Dictionary = {}
	var materials: Dictionary = {}
	var meshes: Dictionary = level["meshes"]
	var normals: Array = level["normals"]
	for entry: Dictionary in level["cells"]:
		var block_parts: Array = meshes[str(int(entry["block"]))]
		var cell_origin: Vector2i = Vector2i(int(entry["x"]), int(entry["y"]))
		var variant_index: int = GROUND.base_variant(cell_origin)
		for part: Dictionary in block_parts:
			var values: Array = part["vertices"]
			var indices: Array = part["indices"]
			var normal_indices: Array = part["attributes"]
			var part_number: int = int(part["part"])
			var detail: String = profile.call("detail_texture", cell_origin, part_number)
			var ground_file: String = profile.call("ground_file", cell_origin, variant_index)
			var key: String = "%02d:%d:%s" % [variant_index, part_number, ground_file]
			if not tools.has(key):
				var new_surface: SurfaceTool = SurfaceTool.new()
				new_surface.begin(Mesh.PRIMITIVE_TRIANGLES)
				new_surface.set_custom_format(0, SurfaceTool.CUSTOM_RGBA_FLOAT)
				tools[key] = new_surface
				materials[key] = profile.call("terrain_material", variant_index, true, false, ground_file)
			var surface: SurfaceTool = tools[key] as SurfaceTool
			for triangle_start in range(0, indices.size(), 3):
				var triangle_points: Array[Vector3] = []
				for corner in range(3):
					var offset: int = int(indices[triangle_start + corner]) * 5
					triangle_points.append(Vector3(float(values[offset]) + float(entry["x"]),
						-(float(values[offset + 1]) + float(entry["y"])),
						BDB_DEPTH_SCALE * float(values[offset + 2]) + BDB_DEPTH_OFFSET))
				var low_z: float = triangle_points[0].z
				var high_z: float = triangle_points[0].z
				for point: Vector3 in triangle_points:
					low_z = minf(low_z, point.z)
					high_z = maxf(high_z, point.z)
				var flat: bool = high_z - low_z <= 0.01
				for corner in range(3):
					var vertex_index: int = int(indices[triangle_start + corner])
					var offset: int = vertex_index * 5
					var source_normal: Array = normals[int(normal_indices[vertex_index])]
					surface.set_normal(Vector3(float(source_normal[0]), -float(source_normal[1]),
						float(source_normal[2]) / BDB_DEPTH_SCALE).normalized())
					var field: Vector2 = GROUND.field_uv(float(values[offset]) + float(entry["x"]),
						float(values[offset + 1]) + float(entry["y"]))
					var uv: Vector2 = field
					if not flat:
						uv.y += (triangle_points[corner].z - low_z) / GROUND.FIELD_CELLS
					surface.set_uv(uv)
					surface.set_uv2(profile.call("detail_slot", detail))
					var source_local: Vector3 = Vector3(values[offset], values[offset + 1], values[offset + 2])
					var channels: Dictionary = profile.call("terrain_channels", cell_origin,
						source_local, source_normal)
					surface.set_color(channels["diffuse"])
					surface.set_custom(0, channels["secondary"])
					surface.add_vertex(triangle_points[corner])
					triangle_count += 1
	for key: String in tools:
		var terrain_mesh: ArrayMesh = (tools[key] as SurfaceTool).commit()
		if terrain_mesh == null or terrain_mesh.get_surface_count() == 0:
			continue
		terrain_mesh.surface_set_material(0, materials[key] as Material)
		var instance: MeshInstance3D = MeshInstance3D.new()
		instance.name = "GeneratedTerrain_" + key.replace(":", "_").replace(".tga", "")
		instance.mesh = terrain_mesh
		scene_root.add_child(instance)
		surface_count += 1
	_build_walls()


## The walls between the cells of a different height: the faces of the tunnels.
func _build_walls() -> void:
	var ground_level: float = GROUND.ground_level(level["cells"], level["meshes"])
	var quads: Array = WALLS.relief_quads(level["cells"], level["meshes"], ground_level)
	if quads.is_empty():
		return
	var cell_index: Dictionary = {}
	for entry: Dictionary in level["cells"]:
		cell_index[Vector2i(int(entry["x"]), int(entry["y"]))] = entry
	var tools: Dictionary = {}
	var materials: Dictionary = {}
	for wall: Dictionary in quads:
		var cell: Vector2i = wall["cell"]
		var side: int = int(wall["side"])
		var owner_cell: Vector2i = cell
		var higher: Vector2i = WALLS.neighbour(cell, side)
		if cell_index.has(higher):
			owner_cell = higher
		var entry: Dictionary = cell_index[owner_cell]
		var cell_origin := Vector2i(int(entry["x"]), int(entry["y"]))
		var variant_index: int = GROUND.base_variant(cell_origin)
		var ground_file: String = profile.call("ground_file", cell_origin, variant_index)
		var detail: String = profile.call("detail_texture", cell_origin, 0)
		var key: String = "%02d:%s" % [variant_index, ground_file]
		if not tools.has(key):
			var new_surface: SurfaceTool = SurfaceTool.new()
			new_surface.begin(Mesh.PRIMITIVE_TRIANGLES)
			new_surface.set_custom_format(0, SurfaceTool.CUSTOM_RGBA_FLOAT)
			tools[key] = new_surface
			materials[key] = profile.call("terrain_material", variant_index, false, false, ground_file)
		var surface: SurfaceTool = tools[key] as SurfaceTool
		var corners: Array = wall["corners"]
		var lower: float = float(wall["lower"])
		var normal: Vector3 = wall["normal"]
		var along_x: bool = side == WALLS.SIDE_POS_X or side == WALLS.SIDE_NEG_X
		for triangle_start in range(0, 6, 3):
			for corner_index in range(3):
				var corner_index_value: int = [0, 1, 2, 0, 2, 3][triangle_start + corner_index]
				var corner: Vector3 = corners[corner_index_value]
				var world_x: float = corner.x + float(cell.x)
				var world_y: float = corner.y + float(cell.y)
				var up: float = corner.z - lower
				surface.set_normal(normal)
				var span: float = world_y if along_x else world_x
				surface.set_uv(Vector2(up / GROUND.FIELD_CELLS, span / GROUND.FIELD_CELLS))
				surface.set_uv2(profile.call("detail_slot", detail))
				var source_local: Vector3 = Vector3(corner.x, corner.y, corner.z)
				var light_normal: Vector3 = Vector3(normal.x, -normal.y, normal.z * BDB_DEPTH_SCALE)
				var channels: Dictionary = profile.call("terrain_channels", cell_origin, source_local,
					[light_normal.x, light_normal.y, light_normal.z])
				surface.set_color(channels["diffuse"])
				surface.set_custom(0, channels["secondary"])
				surface.add_vertex(Vector3(corner.x + float(cell.x), -(corner.y + float(cell.y)),
					BDB_DEPTH_SCALE * corner.z + BDB_DEPTH_OFFSET))
	wall_count += quads.size()
	for key: String in tools:
		var wall_mesh: ArrayMesh = (tools[key] as SurfaceTool).commit()
		if wall_mesh == null or wall_mesh.get_surface_count() == 0:
			continue
		wall_mesh.surface_set_material(0, materials[key] as Material)
		var instance: MeshInstance3D = MeshInstance3D.new()
		instance.name = "GeneratedWalls_" + key.replace(":", "_").replace(".tga", "")
		instance.mesh = wall_mesh
		instance.layers = WALL_LAYER
		scene_root.add_child(instance)
		triangle_count += wall_mesh.get_faces().size() / 3


## The objects of the level: the models of the templates of the original.
func _build_objects() -> void:
	if not FileAccess.file_exists(MODELS_PATH):
		push_warning("The models of the generated level are missing: " + MODELS_PATH)
		return
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(MODELS_PATH))
	if not decoded is Dictionary:
		push_error("The model manifest of the generated level is invalid")
		return
	var manifest: Dictionary = decoded
	var model_data: Dictionary = manifest.get("objects", {})
	var mesh_cache: Dictionary = {}
	for key: String in model_data:
		mesh_cache[key] = _build_model_meshes(model_data[key]["surfaces"])
	for placement: Dictionary in manifest.get("placements", []):
		var placement_class: String = str(placement["class"])
		var key: String = str(placement.get("model_package", "")).to_lower() \
			+ "::" + str(placement.get("model_object", "")).to_lower()
		if not mesh_cache.has(key):
			continue
		var instance_root: Node3D = Node3D.new()
		instance_root.name = "%s_%03d" % [placement_class, object_count]
		var game_to_godot: Basis = Basis(Vector3.RIGHT, Vector3.DOWN, Vector3.BACK)
		var rotation_data: Array = placement.get("rotation", [0.0, 0.0, 0.0])
		var source_rotation: Basis = Basis(Vector3.UP, -float(rotation_data[1])) \
			* Basis(Vector3.RIGHT, -float(rotation_data[0])) \
			* Basis(Vector3.BACK, -float(rotation_data[2]))
		var mapped_rotation: Basis = game_to_godot * source_rotation * game_to_godot.inverse()
		var render_to_logical: Basis = Basis(Vector3.RIGHT, Vector3.UP,
			Vector3(0.0, 0.0, 1.0 / RENDER_DEPTH_SCALE))
		instance_root.transform = Transform3D(render_to_logical * mapped_rotation,
			Vector3(float(placement["x"]), -float(placement["y"]), float(placement["z"])))
		instance_root.set_meta("native_class", placement_class)
		for mesh: ArrayMesh in mesh_cache[key]:
			var mesh_instance: MeshInstance3D = MeshInstance3D.new()
			mesh_instance.mesh = mesh
			instance_root.add_child(mesh_instance)
		scene_root.add_child(instance_root)
		object_count += 1
	_add_light_sources()


## The light sources of the level.
##
## A light source of the original is no model, so it is not in the model
## export. The manifest of the level keeps its place, and the colour and the
## range of the source are the native ones, taken from the classes of the
## original (models/native_campaign_lights.json).
func _add_light_sources() -> void:
	if not FileAccess.file_exists(MANIFEST_PATH):
		return
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(MANIFEST_PATH))
	if not decoded is Dictionary:
		return
	var manifest: Dictionary = decoded
	var lights_data: Dictionary = profile.get("lights_data")
	for item: Dictionary in manifest.get("objects", []):
		var object_class: String = str(item.get("class", ""))
		if "LightSrc" not in object_class and "Feuerstelle" not in object_class:
			continue
		var light: OmniLight3D = OmniLight3D.new()
		light.name = "GeneratedLight_" + object_class + "_%03d" % light_count
		light.position = Vector3(float(item.get("x", 0.0)), -float(item.get("y", 0.0)),
			float(item.get("z", 0.0)))
		for spec: Dictionary in lights_data.get("lights", []):
			if str(spec.get("class", "")) != object_class:
				continue
			var color: Array = spec["color"]
			light.light_color = Color(float(color[0]), float(color[1]), float(color[2]))
			light.omni_range = float(spec["range"])
			break
		light.light_energy = 1.0
		light.shadow_enabled = false
		scene_root.add_child(light)
		light_count += 1


## A light source of the level as an omni light of the scene.
##
## The colour and the range of a source are the native ones, taken from the
## classes of the original (models/native_campaign_lights.json).
func _add_source_light(placement_class: String, origin: Vector3) -> void:
	var light: OmniLight3D = OmniLight3D.new()
	light.name = "GeneratedLight_" + placement_class + "_%03d" % light_count
	light.position = origin
	var lights_data: Dictionary = profile.get("lights_data")
	for spec: Dictionary in lights_data.get("lights", []):
		if str(spec.get("class", "")) != placement_class:
			continue
		var color: Array = spec["color"]
		light.light_color = Color(float(color[0]), float(color[1]), float(color[2]))
		light.omni_range = float(spec["range"])
		break
	light.light_energy = 1.0
	light.shadow_enabled = false
	scene_root.add_child(light)
	light_count += 1


func _build_model_meshes(surfaces: Array, texture_directory: String = "res://textures/models") -> Array[ArrayMesh]:
	var meshes: Array = []
	for source_surface: Dictionary in surfaces:
		var vertices: Array = source_surface["points"]
		var uvs: Array = source_surface["uvs"]
		var indices: Array = source_surface["triangles"]
		var source_normals: PackedVector3Array = native_model_material.call("godot_local_normals", source_surface)
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
			surface_tool.set_normal(source_normals[index])
			surface_tool.set_uv(Vector2(float(uv[0]), float(uv[1])))
			surface_tool.add_vertex(Vector3(float(raw_point[0]), float(raw_point[1]), float(raw_point[2])))
		var mesh: ArrayMesh = surface_tool.commit()
		if mesh == null:
			continue
		var material: StandardMaterial3D = StandardMaterial3D.new()
		material.albedo_texture = load(texture_directory + "/" + str(source_surface.get("texture", ""))) as Texture2D
		material.vertex_color_use_as_albedo = true
		material.roughness = 1.0
		material.cull_mode = BaseMaterial3D.CULL_DISABLED
		material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA_SCISSOR
		material.alpha_scissor_threshold = 0.35
		mesh.surface_set_material(0, material)
		meshes.append(mesh)
	return meshes


func _build_camera_and_light() -> void:
	controller = CAMERA.new()
	controller.call("setup", {"x": 0.0, "y": 0.0, "zoom": 1.0, "rx": -0.29, "ry": 0.0})
	if _capture_tilt > -10.0:
		controller.call("set_tilt", _capture_tilt)
	var box_min := Vector2(INF, INF)
	var box_max := Vector2(-INF, -INF)
	for entry: Dictionary in level["cells"]:
		var position := Vector2(float(entry["x"]), float(entry["y"]))
		box_min = box_min.min(position)
		box_max = box_max.max(position)
	if box_min.x <= box_max.x:
		var viewport: Vector2 = get_viewport().get_visible_rect().size
		var aspect: float = 1.0
		if viewport.y > 0.0:
			aspect = viewport.x / viewport.y
		var tilt: float = float(controller.call("get", "tilt"))
		if _capture_region.z > _capture_region.x:
			var region_min := Vector2(_capture_region.x, _capture_region.y)
			var region_max := Vector2(_capture_region.z, _capture_region.w)
			var region_size := region_max - region_min + Vector2.ONE
			controller.call("focus_on", (region_min + region_max) * 0.5)
			controller.call("frame", CAMERA.projected_size(region_size, 14.5, tilt), 0.05, aspect)
		else:
			var content_size := box_max - box_min + Vector2.ONE
			controller.call("focus_on", (box_min + box_max) * 0.5)
			controller.call("frame", CAMERA.projected_size(content_size, 14.5, tilt), 0.12, aspect)
	if _capture_distance > 0.0:
		controller.call("set", "distance", _capture_distance)
	camera = Camera3D.new()
	camera.name = "GeneratedLevelCamera"
	camera.current = true
	camera.fov = float(CAMERA.FOV_DEGREES)
	camera.near = 0.05
	camera.far = 3000.0
	add_child(camera)
	var environment: Environment = Environment.new()
	environment.background_mode = Environment.BG_COLOR
	environment.background_color = Color(0.035, 0.045, 0.055)
	environment.ambient_light_source = Environment.AMBIENT_SOURCE_COLOR
	environment.ambient_light_color = Color.WHITE
	environment.ambient_light_energy = 0.3
	var world_environment: WorldEnvironment = WorldEnvironment.new()
	world_environment.environment = environment
	add_child(world_environment)
	var key: DirectionalLight3D = DirectionalLight3D.new()
	key.rotation_degrees = Vector3(-32.0, -25.0, 0.0)
	key.light_energy = 0.6
	key.shadow_enabled = false
	add_child(key)
	_update_camera()


func _update_camera() -> void:
	if controller == null or camera == null:
		return
	camera.position = controller.call("camera_position") as Vector3
	camera.look_at(controller.call("look_target") as Vector3)


func _build_caption() -> void:
	var layer: CanvasLayer = CanvasLayer.new()
	layer.name = "HUDLayer"
	add_child(layer)
	status = Label.new()
	status.name = "Status"
	status.position = Vector2(18.0, 14.0)
	status.add_theme_color_override("font_color", Color(0.92, 0.94, 0.96))
	status.add_theme_font_size_override("font_size", 16)
	status.text = "Generated level - Urwald\n%d cells | %d objects | %d light sources" % [
		(level["cells"] as Array).size(), object_count, light_count]
	layer.add_child(status)


func _process(_delta: float) -> void:
	if _capture_frames < 0:
		return
	_capture_frames -= 1
	if _capture_frames > 0:
		return
	_capture_frames = -1
	var image: Image = get_viewport().get_texture().get_image()
	var error: int = image.save_png(_capture_path)
	print("GENERATED_LEVEL_CAPTURE_READY path=%s error=%d size=%s" % [
		_capture_path, error, str(image.get_size())])
	get_tree().quit()
