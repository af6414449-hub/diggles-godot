extends RefCounted
## Runtime embedding only. Source PMP/BDB/profile assets remain immutable.


static func apply(scene: Node3D, terrain: Dictionary) -> Vector2i:
	var config: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/playable_world_space.json"))
	assert(config["source_pmp_sha256"] == terrain["source_pmp_sha256"])
	assert(config["source_bdb_sha256"] == terrain["source_bdb_sha256"])
	var shift: Vector2i = Vector2i(config["template_shift"][0], config["template_shift"][1])
	var size: Vector2i = Vector2i(config["size"][0], config["size"][1])
	var old_size: Vector2i = Vector2i(terrain["width"], terrain["height"])
	var old_facts: Array = scene.terrain_state.facts["cells"]
	var old_render: Dictionary = scene.source_profile.terrain_render
	var old_materials: Array = old_render["materials"]
	var old_attributes: Array = old_render["attributes"]
	var layer: Dictionary = scene.source_profile.data["layer2"]
	var old_words: Array = layer["words"]
	var facts: Array[Dictionary] = []
	var materials: Array = []
	var attributes: Array = []
	var words: Array = []
	var cells: Array[Dictionary] = []
	var imported: Dictionary = {}
	for cell: Dictionary in terrain["cells"]:
		var moved: Dictionary = cell.duplicate()
		moved["x"] = int(cell["x"]) + shift.x
		moved["y"] = int(cell["y"]) + shift.y
		imported[Vector2i(moved["x"], moved["y"])] = moved
	for y: int in range(size.y):
		for x: int in range(size.x):
			var point: Vector2i = Vector2i(x,y)
			var old_point: Vector2i = point-shift
			var inside: bool = Rect2i(Vector2i.ZERO,old_size).has_point(old_point)
			var old_index: int = old_point.y*old_size.x+old_point.x
			var fact: Dictionary = config["solid_fact"].duplicate()
			if inside and old_facts[old_index]["material_low"] != null:
				fact = old_facts[old_index].duplicate()
			facts.append(fact)
			materials.append(old_materials[old_index] if inside else config["material"])
			attributes.append(old_attributes[old_index] if inside else config["attribute"])
			words.append(old_words[old_index] if inside else config["detail_word"])
			if imported.has(point):
				cells.append(imported[point])
			else:
				var solid: Dictionary = config["solid_cell"].duplicate()
				solid["x"] = x
				solid["y"] = y
				solid["ground_variant"] = 1 + ((x*7+y*11)%15)
				cells.append(solid)
	var bounds: Rect2i = Rect2i(Vector2i.ZERO,size)
	scene.tunnel_rules.data["width"] = size.x
	scene.tunnel_rules.data["height"] = size.y
	scene.tunnel_rules.data["cells"] = facts
	scene.tunnel_rules.bounds = bounds
	scene.terrain_state.bounds = bounds
	var all_points: Array[Vector2i] = []
	for y: int in range(size.y):
		for x: int in range(size.x):
			all_points.append(Vector2i(x,y))
	scene.terrain_state.refresh_rules(all_points)
	old_render["width"] = size.x
	old_render["height"] = size.y
	old_render["materials"] = materials
	old_render["attributes"] = attributes
	layer["width"] = size.x
	layer["height"] = size.y
	layer["words"] = words
	var old_flags: PackedByteArray = scene.native_walkmap.flags
	var flags: PackedByteArray = PackedByteArray()
	flags.resize(size.x*size.y*64)
	flags.fill(0) # Verified full-solid BDB surface contains no traversable volume.
	for y: int in range(old_size.y*8):
		for x: int in range(old_size.x*8):
			flags[(y+shift.y*8)*size.x*8+x+shift.x*8] = old_flags[y*old_size.x*8+x]
	scene.native_walkmap.data["flags"] = flags.duplicate()
	scene.native_walkmap.data["width"] = size.x*8
	scene.native_walkmap.data["height"] = size.y*8
	scene.native_walkmap.flags = flags
	scene.native_walkmap.unknown_samples.resize(flags.size())
	scene.native_walkmap.unknown_samples.fill(0)
	scene.native_walkmap.sample_bounds = Rect2i(Vector2i.ZERO,size*8)
	terrain["source_template_summary"] = terrain["summary"].duplicate(true)
	terrain["runtime_extension"] = config
	terrain["width"] = size.x
	terrain["height"] = size.y
	terrain["cells"] = cells
	var triangles: int = 0
	for cell: Dictionary in cells:
		for part: Dictionary in terrain["meshes"][str(int(cell["block"]))]:
			triangles += int(part["indices"].size()/3.0)
	terrain["summary"]["triangles"] = triangles
	terrain["summary"]["cells"] = cells.size()
	# This changes the local embedding origin, not the authored world placement.
	scene.native_world.template_offset -= shift
	for spec: Dictionary in scene.source_profile.data["lights"]:
		spec["position"][0] += shift.x
		spec["position"][1] += shift.y
	for spec: Dictionary in scene.source_profile.data["horizons"]:
		spec["position"][0] += shift.x
		spec["position"][1] += shift.y
	for light: Dictionary in scene.source_profile.terrain_lights:
		light["position"] += Vector3(shift.x,shift.y,0)
	return shift
