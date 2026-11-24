extends RefCounted
## Builds a Godot scene from a composed Urwald campaign level.
##
## The scene presents three things:
##   * the composed terrain cell grid, one quad per native cell, tinted by the
##     L2M material word that the composer wrote into the layer,
##   * one node per composed template object, carrying the native class, the
##     owner/physic/autolight/boxed flags and the source template,
##   * the `FogRemover` of Campaign.tcl:205-209.
##
## The native block meshes of the BlockDB are not part of this module: the
## composed level references 1229 native block ids and the live project only
## carries the mesh table of its own start template. The terrain quads are a
## level-preview adapter, not a renderer of the native geometry.


static func build(level: Dictionary) -> Node3D:
	var root: Node3D = Node3D.new()
	root.name = "CampaignLevel"
	root.add_child(_build_terrain(level))
	root.add_child(_build_objects(level))
	root.add_child(_build_fog(level))
	return root


static func _build_terrain(level: Dictionary) -> MeshInstance3D:
	var size: Vector2i = level["size"]
	var layer2: PackedInt32Array = level["layer2_words"]
	var cells: Array = level["cells"]
	var positions: PackedVector3Array = PackedVector3Array()
	var colors: PackedColorArray = PackedColorArray()
	var indices: PackedInt32Array = PackedInt32Array()
	for cell: Dictionary in cells:
		var cell_x: int = int(cell["x"])
		var cell_y: int = int(cell["y"])
		var index: int = cell_y * size.x + cell_x
		var word: int = layer2[index] if index < layer2.size() else 0
		var corner: int = indices.size()
		positions.append(Vector3(cell_x, -cell_y, 0.0))
		positions.append(Vector3(cell_x + 1.0, -cell_y, 0.0))
		positions.append(Vector3(cell_x, -cell_y - 1.0, 0.0))
		positions.append(Vector3(cell_x + 1.0, -cell_y - 1.0, 0.0))
		var tint: Color = material_tint(word)
		for _corner: int in range(4):
			colors.append(tint)
		indices.append(corner)
		indices.append(corner + 2)
		indices.append(corner + 1)
		indices.append(corner + 1)
		indices.append(corner + 2)
		indices.append(corner + 3)
	var arrays: Array = []
	arrays.resize(Mesh.ARRAY_MAX)
	arrays[Mesh.ARRAY_VERTEX] = positions
	arrays[Mesh.ARRAY_COLOR] = colors
	arrays[Mesh.ARRAY_INDEX] = indices
	var mesh: ArrayMesh = ArrayMesh.new()
	mesh.add_surface_from_arrays(Mesh.PRIMITIVE_TRIANGLES, arrays)
	var instance: MeshInstance3D = MeshInstance3D.new()
	instance.name = "CampaignTerrain"
	instance.mesh = mesh
	instance.set_meta("native_cell_count", cells.size())
	return instance


## Preview tint of one L2M word. A zero word is plain ground; every other
## word carries a nonzero 4-bit detail mask in one of its nibbles.
static func material_tint(word: int) -> Color:
	if word == 0:
		return Color(0.45, 0.42, 0.38)
	var mask: int = 0
	for nibble: int in range(4):
		if ((word >> (4 * nibble)) & 0xF) != 0:
			mask = mask | (1 << nibble)
	var red: float = 0.30 + 0.12 * float(mask & 1)
	var green: float = 0.32 + 0.10 * float((mask >> 1) & 1)
	var blue: float = 0.34 + 0.08 * float((mask >> 2) & 1)
	return Color(red, green, blue)


static func _build_objects(level: Dictionary) -> Node3D:
	var parent: Node3D = Node3D.new()
	parent.name = "CampaignObjects"
	var index: int = 0
	for object: Dictionary in level["objects"]:
		var node: Node3D = Node3D.new()
		node.name = "%s_%03d" % [str(object["class"]), index]
		node.position = Vector3(float(object["x"]), -float(object["y"]), float(object["z"]))
		node.set_meta("native_class", str(object["class"]))
		node.set_meta("native_owner", object["owner"])
		node.set_meta("native_physic", object["physic"])
		node.set_meta("native_autolight", object["autolight"])
		node.set_meta("native_boxed", object["boxed"])
		node.set_meta("native_template", str(object["template"]))
		parent.add_child(node)
		index += 1
	return parent


static func _build_fog(level: Dictionary) -> Node3D:
	var fog: Dictionary = level["fog"]
	var position: Vector3i = fog["position"]
	var node: Node3D = Node3D.new()
	node.name = "FogRemover"
	node.position = Vector3(float(position.x), -float(position.y), float(position.z))
	node.set_meta("native_fog_remove", fog["rect"])
	node.set_meta("native_undeletable", fog["undeletable"])
	return node
