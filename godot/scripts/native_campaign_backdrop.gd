extends RefCounted
## Start clearing scenery. Flats face +Z. The meadow lies in XZ at the turf row.

const SKY_COLOUR: Color = Color(0.843137, 0.901961, 0.988235)
const PANORAMA_DIR: String = "res://textures/backdrop/"
# Reuse the grass image from the source texture set for the continuous
# extension. The authored turf sections retain their obw_4_boden_* materials.
const MEADOW_TEXTURE: Texture2D = preload("res://textures/backdrop/Panorama_layer_6.tga")
const PANORAMA_SIDE_MARGIN: float = 106.0
# The contact sheet starts at 1. Its 3, 4, 5, 6 are TGA layers 2 through 5.
# Dimensions fit the campaign camera and stay fixed in world units.
const SCENERY: Array[Dictionary] = [
	{"name": "FarMountains", "texture": 2, "depth": 126.0, "width": 218.0, "base": -39.0,
		"height": 94.0, "follow": 0.55},
	{"name": "LowerMountains", "texture": 3, "depth": 88.0, "width": 168.0, "base": -26.0,
		"height": 59.0, "follow": 0.38},
	{"name": "Forest", "texture": 4, "depth": 66.0, "width": 123.0, "base": -18.0,
		"height": 52.0, "follow": 0.18},
	{"name": "Hills", "texture": 5, "depth": 54.0, "width": 96.0, "base": -14.0,
		"height": 28.0, "follow": 0.06},
]
# Original turf meshes sit at edge.y + 0.05. This patch runs slightly below
# them and continues behind the existing trees to the back of the mountain.
const MEADOW_Y: float = -0.02
const MEADOW_BACK: float = -53.9
const MEADOW_FRONT_HALF_WIDTH: float = 19.5
const MEADOW_FRONT_RIGHT: float = 12.0
const MEADOW_BACK_HALF_WIDTH: float = 33.0


var _planes: Array[MeshInstance3D] = []


static func clearing_edge(objects: Array, face_depth: float) -> Variant:
	var edge: Vector2 = Vector2.ZERO
	var count: int = 0
	for placement: Dictionary in objects:
		var class_name_text: String = str(placement.get("class", ""))
		if placement.get("template") == "urw_unq_start" and class_name_text.begins_with("Dummy_Multi_Obw_rasen_"):
			edge += Vector2(float(placement["x"]), -float(placement["y"]))
			count += 1
	if count == 0:
		return null
	edge /= float(count)
	return Vector3(edge.x, edge.y, face_depth)


func build(clearing_edge: Vector3, parent: Node3D) -> Node3D:
	var scenery_root: Node3D = Node3D.new()
	scenery_root.name = "CampaignBackdrop"
	parent.add_child(scenery_root)
	scenery_root.global_position = clearing_edge
	for index in range(SCENERY.size()):
		var layer: Dictionary = SCENERY[index]
		var texture_path: String = PANORAMA_DIR + "Panorama_layer_%d.tga" % int(layer["texture"])
		var material: StandardMaterial3D = StandardMaterial3D.new()
		material.albedo_texture = load(texture_path) as Texture2D
		material.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
		material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA
		material.depth_draw_mode = BaseMaterial3D.DEPTH_DRAW_DISABLED
		material.render_priority = -100 + index
		material.texture_filter = BaseMaterial3D.TEXTURE_FILTER_LINEAR
		material.texture_repeat = true
		var half_width: float = float(layer["width"]) * 0.5
		var height: float = float(layer["height"])
		var projection_half_width: float = half_width + PANORAMA_SIDE_MARGIN
		var uv_margin: float = PANORAMA_SIDE_MARGIN / float(layer["width"])
		# Repeat horizontally. Keep the vertical samples within the first and
		# last texel centres so the opaque bottom cannot wrap onto the top.
		var v_inset: float = 0.5 / float(material.albedo_texture.get_height())
		var mesh: ArrayMesh = _make_quad(
			Vector3(-projection_half_width, 0, 0), Vector3(projection_half_width, 0, 0),
			Vector3(-projection_half_width, height, 0), Vector3(projection_half_width, height, 0),
			Vector2(-uv_margin, 1 - v_inset), Vector2(1 + uv_margin, v_inset))
		var plan: MeshInstance3D = _add_mesh(scenery_root, str(layer["name"]), mesh, material)
		plan.position = Vector3(0.0, float(layer["base"]), -float(layer["depth"]))
		_planes.append(plan)

	var meadow_material: StandardMaterial3D = StandardMaterial3D.new()
	meadow_material.albedo_texture = MEADOW_TEXTURE
	meadow_material.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
	meadow_material.albedo_color = Color(0.7, 0.7, 0.7)
	# The ground stays level under the trees. At the far edge its source image
	# fades into the hills plane, avoiding a straight cut across the valley.
	meadow_material.transparency = BaseMaterial3D.TRANSPARENCY_ALPHA
	meadow_material.vertex_color_use_as_albedo = true
	var meadow: ArrayMesh = _make_meadow()
	_add_mesh(scenery_root, "MeadowToClearing", meadow, meadow_material)
	return scenery_root


func _make_meadow() -> ArrayMesh:
	var surface := SurfaceTool.new()
	surface.begin(Mesh.PRIMITIVE_TRIANGLES)
	var rows: Array[float] = [0.0, -18.0, -29.0, -41.0, MEADOW_BACK]
	var opacity: Array[float] = [1.0, 1.0, 0.84, 0.42, 0.0]
	for row in range(rows.size() - 1):
		var a: float = -rows[row] / -MEADOW_BACK
		var b: float = -rows[row + 1] / -MEADOW_BACK
		var left_a: float = lerpf(MEADOW_FRONT_HALF_WIDTH, MEADOW_BACK_HALF_WIDTH, a)
		var left_b: float = lerpf(MEADOW_FRONT_HALF_WIDTH, MEADOW_BACK_HALF_WIDTH, b)
		var right_a: float = lerpf(MEADOW_FRONT_RIGHT, MEADOW_BACK_HALF_WIDTH, a)
		var right_b: float = lerpf(MEADOW_FRONT_RIGHT, MEADOW_BACK_HALF_WIDTH, b)
		var points: Array[Vector3] = [
			Vector3(-left_a, MEADOW_Y, rows[row]),
			Vector3(right_a, MEADOW_Y, rows[row]),
			Vector3(-left_b, MEADOW_Y, rows[row + 1]),
			Vector3(right_b, MEADOW_Y, rows[row + 1])]
		for index in [0, 2, 1, 1, 2, 3]:
			var point: Vector3 = points[index]
			var fraction: float = a if index < 2 else b
			surface.set_color(Color(1.0, 1.0, 1.0, opacity[row] if index < 2 else opacity[row + 1]))
			surface.set_uv(Vector2(0.5 + point.x / (2.0 * MEADOW_BACK_HALF_WIDTH),
			lerpf(0.99, 0.30, fraction)))
			surface.add_vertex(point)
	return surface.commit()


func update(pan_x: float) -> void:
	# Use the controller's focus, which is independent of zoom and orbit.
	# Perspective supplies most of the parallax. This bounded shift keeps the
	# distant ridges steadier while the near meadow stays joined to the floor.
	for index in range(_planes.size()):
		_planes[index].position.x = clampf(pan_x * float(SCENERY[index]["follow"]), -22.0, 22.0)



func _add_mesh(parent: Node3D, node_name: String, mesh: ArrayMesh,
		material: StandardMaterial3D) -> MeshInstance3D:
	var instance: MeshInstance3D = MeshInstance3D.new()
	instance.name = node_name
	instance.mesh = mesh
	instance.material_override = material
	instance.cast_shadow = GeometryInstance3D.SHADOW_CASTING_SETTING_OFF
	parent.add_child(instance)
	return instance


func _make_quad(a: Vector3, b: Vector3, c: Vector3, d: Vector3,
		uv_a: Vector2, uv_d: Vector2, meadow: bool = false) -> ArrayMesh:
	var surface: SurfaceTool = SurfaceTool.new()
	surface.begin(Mesh.PRIMITIVE_TRIANGLES)
	var points: Array[Vector3] = [a, c, b, b, c, d]
	var uv_b: Vector2 = Vector2(uv_d.x, uv_a.y)
	var uv_c: Vector2 = Vector2(uv_a.x, uv_d.y)
	var uvs: Array[Vector2] = [uv_a, uv_c, uv_b, uv_b, uv_c, uv_d]
	for index in range(points.size()):
		var point: Vector3 = points[index]
		# World-aligned U preserves scale across the widening patch.
		var uv: Vector2 = Vector2(0.5 + point.x / (2.0 * MEADOW_BACK_HALF_WIDTH),
			uvs[index].y) if meadow else uvs[index]
		surface.set_uv(uv)
		surface.add_vertex(point)
	return surface.commit()
