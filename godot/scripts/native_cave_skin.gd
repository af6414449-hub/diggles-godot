extends RefCounted
## The cave skins of the original game, as the resources of the port.
##
## The skins are the original models of `auskleidung.3db`, exported as JSON by
## `tools/export_campaign_cave_skins.py`: `urw_caves_{1..4}_a_a.json`. The name
## carries the three parameters of `SetCaveSkinClasses`
## (`data/Scripts/init/animinit.tcl:382-428`): the prefix Urw selects set 0,
## Size (1..4) maps to 0..3, and the penultimate suffix a/b/c selects detail
## 2/1/0. The port currently exports the Urw detail-a variant of four sizes.
##
## The mesh building is the one of the battle scene
## (`scripts/multiplayer_test.gd:_build_cave_skin_meshes`); this module exists so
## that the campaign can use the skins without the battle scene and without a
## change of its public behaviour.

const SKIN_DIRECTORY: String = "res://models/cave_skins/"
const TEXTURE_DIRECTORY: String = "res://assets/textures/"
## The models of the original are in the units of the game; a cell of the map of
## the port is one unit.
const OBJECT_WORLD_SCALE: float = 0.005
const SIZE_COUNT: int = 4
const DETAIL_SUFFIX: Array = ["c", "b", "a"]


## The name of the skin of a cave of the given brush size.
## The size of the brush chooses the size of the frame (p. 4 of the work order).
static func skin_key(brush_number: int, detail: int = 2) -> String:
	var size_index: int = clampi(brush_number, 1, SIZE_COUNT)
	var detail_index: int = clampi(detail, 0, 2)
	return "urw_caves_%d_a_%s" % [size_index, DETAIL_SUFFIX[detail_index]]


## The path of the exported skin of a cave of the given brush size.
static func skin_path(brush_number: int) -> String:
	return SKIN_DIRECTORY + skin_key(brush_number) + ".json"


## Reads the four exported skins. The result maps the size of the brush to the
## array of the meshes of that skin. A missing or broken skin is skipped: the
## caller decides what to do without a frame.
func load_skins() -> Dictionary:
	var resources: Dictionary = {}
	for size: int in range(1, SIZE_COUNT + 1):
		var resource_path: String = skin_path(size)
		if not FileAccess.file_exists(resource_path):
			continue
		var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(resource_path))
		if not decoded is Dictionary:
			continue
		var surfaces_variant: Variant = (decoded as Dictionary).get("surfaces", [])
		if not surfaces_variant is Array:
			continue
		var meshes: Array[ArrayMesh] = build_meshes(surfaces_variant)
		if meshes.is_empty():
			continue
		resources[size] = meshes
	return resources


## The meshes of one skin: one mesh per surface of the export.
func build_meshes(surfaces: Array) -> Array[ArrayMesh]:
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
			surface_tool.add_vertex(Vector3(float(point[0]), -float(point[1]),
				float(point[2])) * OBJECT_WORLD_SCALE)
		surface_tool.generate_normals()
		var mesh: ArrayMesh = surface_tool.commit()
		if mesh == null:
			continue
		var material: StandardMaterial3D = StandardMaterial3D.new()
		material.cull_mode = BaseMaterial3D.CULL_DISABLED
		material.roughness = 0.95
		var texture_name: String = str(surface_data.get("texture", "Holz_Standard_a_256.tga"))
		var texture_path: String = TEXTURE_DIRECTORY + texture_name
		if ResourceLoader.exists(texture_path):
			material.albedo_texture = load(texture_path) as Texture2D
		mesh.surface_set_material(0, material)
		meshes.append(mesh)
	return meshes


## The node of the frame of a cave. The caller places it; the module only
## builds the original meshes.
func build_frame(resources: Dictionary, brush_number: int, frame_name: String) -> Node3D:
	var frame: Node3D = Node3D.new()
	frame.name = frame_name
	var meshes_variant: Variant = resources.get(clampi(brush_number, 1, SIZE_COUNT), [])
	if not meshes_variant is Array:
		return frame
	for mesh_variant: Variant in meshes_variant:
		if not mesh_variant is ArrayMesh:
			continue
		var mesh_instance: MeshInstance3D = MeshInstance3D.new()
		mesh_instance.mesh = mesh_variant
		frame.add_child(mesh_instance)
	return frame
