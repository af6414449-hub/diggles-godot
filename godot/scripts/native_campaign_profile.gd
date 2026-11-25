class_name NativeCampaignProfile
extends RefCounted
## Presentation rules for the campaign chapter map.
##
## The shared battle-scene profile (scripts/native_scene_profile.gd) is bound to
## one reference level: it checks the source PMP digest and reads a layer grid
## whose size must equal the terrain size. The campaign chapter is a different
## map (512x640, assembled from the chapter templates), so it needs its own
## presentation module. The renderer rules themselves are the source ones and
## are shared: the ground patterns and the shader constants come from the
## project-wide terrain render profile, the per-cell ground material and the
## attribute bytes come from the chapter export.
##
## It creates no Nodes and calls no game API.

const ILLUMINATION: Script = preload("res://scripts/native_terrain_illumination.gd")
const WORLD_MODEL_LIGHT: Script = preload("res://scripts/native_world_model_light.gd")
const GROUND: Script = preload("res://scripts/native_campaign_ground.gd")
const SHARED_TERRAIN_RENDER: String = "res://models/native_terrain_render.json"
## The native ground tiles of the original: the files of the game itself
## (Gnd_*.tga and the mixed Native_*.tga). The battle scene reads the same
## directory (native_scene_profile.gd:terrain_material).
const NATIVE_GROUND_DIR: String = "res://textures/ground/"
const SHADER_PIPELINE: String = "res://models/native_shader_pipeline.json"
const SHARED_WORLD_LIGHTING: String = "res://models/native_world_model_lighting.json"
const CAMPAIGN_LIGHTS: String = "res://models/native_campaign_lights.json"

var data: Dictionary = {}
var terrain_render: Dictionary = {}
var shader_pipeline: Dictionary = {}
var world_model_lighting: Dictionary = {}
var material_cache: Dictionary = {}

## A switch of the map view: the excavation under the surface of the map is lit
## like the day surface of the map. The attribute bytes of the original mark
## the dug cells with a light of their own (1 against the 4 of the surface), so
## the floor of a tunnel reads as a black slot along every corridor of the map.
## The owner took the lit excavation for the map of the game (23.11.2026), so it
## is the normal state; the flag --dark-excavation brings the old one back for
## an A/B capture.
var _lit_excavation: bool = true


func set_lit_excavation(value: bool) -> void:
	_lit_excavation = value

## The native light sources of the chapter, in the source space of the blocks.
## The battle scene has the same list for its level
## (scripts/native_scene_profile.gd), and the light of the terrain is the
## diffuse of these sources over the attribute bytes of the cell.
var terrain_lights: Array = []
var _active_templates: Dictionary = {}
var lights_data: Dictionary = {}
## The base material of every cell, reconstructed by the original border and
## funnel commands before any cave template is stamped onto the map.
var ground_materials: PackedByteArray = PackedByteArray()
var _active_cells: Dictionary = {}
var _filter_cells: bool = false
## The light sources per tile of the map.
##
## The chapter has a hundred and twenty two sources and the terrain has a
## hundred thousand vertices, so the sources of a vertex are looked up in a
## coarse grid instead of walking the whole list every time. The cell of the
## grid is wider than the widest source of the chapter (eight units), so the
## three by three neighbourhood of a point holds every source that can reach
## it.
const LIGHT_GRID_CELL: float = 16.0
var light_grid: Dictionary = {}

var _width: int = 0
var _height: int = 0


func load_chapter(path: String) -> bool:
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(path))
	if not decoded is Dictionary:
		push_error("Campaign chapter manifest is missing or invalid: " + path)
		return false
	data = decoded
	var size: Dictionary = data.get("map_size", {})
	_width = int(size.get("width", 0))
	_height = int(size.get("height", 0))
	if _width <= 0 or _height <= 0:
		push_error("Campaign chapter manifest has no map size")
		return false
	terrain_render = JSON.parse_string(FileAccess.get_file_as_string(SHARED_TERRAIN_RENDER))
	shader_pipeline = JSON.parse_string(FileAccess.get_file_as_string(SHADER_PIPELINE))
	world_model_lighting = JSON.parse_string(FileAccess.get_file_as_string(SHARED_WORLD_LIGHTING))
	if not terrain_render.has("patterns") or not terrain_render.has("constants"):
		push_error("Shared terrain render profile is incomplete")
		return false
	if float(world_model_lighting["gain"]["default"]) != float(terrain_render["constants"]["gain"]):
		push_error("World model lighting and terrain render gains differ")
		return false
	_load_lights()
	# The saved run already contains its old template stamps and excavated air.
	# Build the untouched map from the native border/funnel commands before
	# placing this chapter's templates, so no old cave footprint shows through.
	ground_materials = GROUND.generator_material_map()
	return true


func set_active_templates(templates: Dictionary) -> void:
	_active_templates = templates
	_load_lights()


func set_active_cells(cells: Array) -> void:
	_filter_cells = true
	_active_cells.clear()
	_cell_blocks.clear()
	_cell_levels.clear()
	for entry: Dictionary in cells:
		_active_cells[Vector2i(int(entry["x"]), int(entry["y"]))] = true


## The light sources of the chapter, in the source space of the blocks.
##
## The position of a source is the position of the object plus the offset of
## its class definition (the class_light rule of the original), and its depth
## is unpacked the same way as the depth of a block: the source space stores
## the depth as (game_z + 14) / 2. The colour of the source is the colour of
## the class, converted for the renderer the same way as in the battle scene.
func _load_lights() -> void:
	terrain_lights.clear()
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(CAMPAIGN_LIGHTS))
	if not decoded is Dictionary:
		push_warning("Campaign light sources are missing: " + CAMPAIGN_LIGHTS)
		return
	lights_data = decoded
	var constants: Dictionary = terrain_render["constants"]
	for spec: Dictionary in lights_data.get("lights", []):
		if not _light_is_active(spec):
			continue
		var position: Vector3 = _source_light_point(spec)
		position.z = position.z * float(constants["depth_half"]) + float(constants["depth_offset"])
		var color: Array = spec["color"]
		terrain_lights.append({"position": position, "range": float(spec["range"]),
			"color": ILLUMINATION.class_light_color(color, shader_pipeline["light_conversion"])})
	_build_light_grid()


func _light_is_active(spec: Dictionary) -> bool:
	if _active_templates.is_empty():
		return true
	var source: Dictionary = spec.get("placement_source", {})
	return _active_templates.has(str(source.get("template", "")))


## The sources that can reach a point of the map.
func lights_near(point: Vector3) -> Array:
	return _lights_near(point)


## The sources of the light in the grid of the map.
func _build_light_grid() -> void:
	light_grid.clear()
	for index in range(terrain_lights.size()):
		var position: Vector3 = (terrain_lights[index] as Dictionary)["position"]
		var key := Vector2i(int(floor(position.x / LIGHT_GRID_CELL)),
			int(floor(position.y / LIGHT_GRID_CELL)))
		if not light_grid.has(key):
			light_grid[key] = []
		(light_grid[key] as Array).append(index)


## The sources that can reach a point of the map.
func _lights_near(point: Vector3) -> Array:
	var result: Array = []
	var base := Vector2i(int(floor(point.x / LIGHT_GRID_CELL)),
		int(floor(point.y / LIGHT_GRID_CELL)))
	for offset_y in range(-1, 2):
		for offset_x in range(-1, 2):
			var key: Vector2i = base + Vector2i(offset_x, offset_y)
			if not light_grid.has(key):
				continue
			for index: int in light_grid[key]:
				result.append(terrain_lights[index])
	return result


## The point of a light source in the source space of the blocks.
func _source_light_point(spec: Dictionary) -> Vector3:
	var pos: Array = spec["position"]
	var offset: Array = spec["offset"]
	var rotation: Array = spec["rotation"]
	var basis: Basis = Basis(Vector3.UP, -float(rotation[1])) \
		* Basis(Vector3.RIGHT, -float(rotation[0])) * Basis(Vector3.BACK, -float(rotation[2]))
	return Vector3(float(pos[0]), float(pos[1]), float(pos[2])) \
		+ basis * Vector3(float(offset[0]), float(offset[1]), float(offset[2]))


## The light sources of the chapter as omni lights of the scene.
##
## The terrain carries the light of the sources in its vertex colour, the same
## way as the battle scene does; the omni lights light the models of the
## chapter. The colour of the source is the raw colour of the class here and
## the converted one in the light of the terrain, exactly as in the battle scene.
func add_lights(parent: Node3D) -> int:
	var active_count: int = 0
	for spec: Dictionary in lights_data.get("lights", []):
		if not _light_is_active(spec):
			continue
		active_count += 1
		var light: OmniLight3D = OmniLight3D.new()
		light.name = "SourceLight_%s_%03d" % [str(spec["class"]), int(spec["ordinal"])]
		var point: Vector3 = _source_light_point(spec)
		light.position = Vector3(point.x, -point.y, point.z)
		var color: Array = spec["color"]
		light.light_color = Color(float(color[0]), float(color[1]), float(color[2]))
		light.omni_range = float(spec["range"])
		light.light_energy = 1.0
		light.shadow_enabled = false
		light.set_meta("native_class_source", spec.get("class_source", {}))
		light.set_meta("native_placement_source", spec.get("placement_source", {}))
		parent.add_child(light)
	return active_count


func map_size() -> Vector2i:
	return Vector2i(_width, _height)


## The ground material of a cell, or null when the chapter has no cell there.
##
## The cells of the chapter carry their own material in the export. The free
## cells of the map are not in the export. Their material comes from the
## original map generator (native_campaign_map_material.gd). The archived save
## is a comparison source, not the live base map: it already contains old
## cave stamps and excavated air from another playthrough.
func cell_material(cell: Vector2i) -> Variant:
	var value: Variant = null
	if not _filter_cells or _active_cells.has(cell):
		value = (data.get("materials", {}) as Dictionary).get("%d,%d" % [cell.x, cell.y], null)
	if value == null:
		var free: int = GROUND.free_material(ground_materials, cell.x, cell.y)
		if free >= 0:
			return free
		return GROUND.base_material(cell)
	return value


func cell_attribute(cell: Vector2i) -> int:
	if _filter_cells and not _active_cells.has(cell):
		return 0
	return int((data.get("attributes", {}) as Dictionary).get("%d,%d" % [cell.x, cell.y], 0))


func layer2_word(cell: Vector2i) -> int:
	if _filter_cells and not _active_cells.has(cell):
		return 0
	return int((data.get("layer2", {}) as Dictionary).get("%d,%d" % [cell.x, cell.y], 0))


## The continuous ground field of a native family.
##
## The original draws the ground of a cell with one native tile of its family
## (the local UV of the cell are 0..1), and the free ground of the map is
## drawn the same way. The field is the continuous texture of the family
## (tools/build_ground_field.py): it is kept as the texture of the family and
## as the fallback of the terrain material, but the ground of the map does not
## use it - the field averages the fifteen tiles of the family into a flat
## grey, and the ground of the map read as a smooth blur.
func field_ground_file(cell: Vector2i, _variant: int, family: String = "") -> String:
	if family.is_empty():
		var value: Variant = cell_material(cell)
		var material: int = 0 if value == null else int(value)
		if material == 3:
			material = 0
		if material == 1:
			family = "B"
		elif material == 2:
			family = "C"
		else:
			family = "A"
	return "ground_field_%s.png" % family


## The ground texture of a cell of the chapter.
##
## The native loader blends the ground of the four corners of a cell: the table
## of the patterns of the original (native_terrain_render.json, the same file
## the battle scene reads) names the mixed tile of every combination of the four
## corner materials, and for a cell whose four corners are the same it names
## the plain tile of the family. The port used one of the fifteen plain tiles
## of the family per cell, and the border of every tile showed over the ground
## of the chapter as a grid of rectangles.
##
## The rule is the rule of the battle scene (native_scene_profile.gd:ground_file).
func ground_file(cell: Vector2i, variant: int) -> String:
	var signature: String = ""
	for offset: Vector2i in [Vector2i.ZERO, Vector2i.RIGHT, Vector2i.DOWN, Vector2i.ONE]:
		var value: Variant = cell_material(cell + offset)
		var material: int = 0 if value == null else int(value)
		if material == 3:
			material = 0
		signature += str(material)
	var patterns: Dictionary = terrain_render.get("patterns", {}) as Dictionary
	var pattern: Variant = patterns.get(signature, null)
	if pattern == null:
		return "Gnd_A%02d.tga" % (variant + 1)
	var entry: Dictionary = pattern as Dictionary
	if bool(entry.get("mixed", false)):
		return str(entry.get("file", "Gnd_A%02d.tga" % (variant + 1)))
	return "Gnd_%s%02d.tga" % [str(entry.get("family", "A")), variant + 1]


## Detail texture of a cell for one mesh part.
func detail_texture(cell: Vector2i, part: int) -> String:
	var word: int = layer2_word(cell)
	if word == 0:
		return "50PGray.tga"
	var decoded: Variant = (data.get("layer2_decoded", {}) as Dictionary).get(str(word), [])
	if not decoded is Array or (decoded as Array).is_empty() or part >= (decoded as Array).size():
		return "50PGray.tga"
	return str(((decoded as Array)[part] as Dictionary).get("texture", "50PGray.tga"))


func detail_slot(detail: String) -> Vector2:
	var slot: Array = ((data.get("atlas", {}) as Dictionary).get("slots", {}) as Dictionary).get(detail, [0, 0])
	return Vector2(float(slot[0]), float(slot[1]))


## The mean attribute of the chapter, the value four of eight.
const ATTRIBUTE_MEAN: int = 4

## The radial normals of the sphere of the original.
##
## The models of the overworld that are drawn as a patch of texture (the turf,
## the meadow) take their normals from the table of the sphere
## (sphere.dat, 256 entries), not from their own surface: those normals are
## the radial ones of the sphere and say nothing about the orientation of the
## patch. The models with a real geometry (the rocks, the trees) have their
## own normals, and the sky falls on them by those.
var _radial_normals: Dictionary = {}


## Whether a normal of a model comes from the radial table of the sphere.
func is_radial_normal(normal: Vector3) -> bool:
	if _radial_normals.is_empty():
		var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(
			"res://models/native_model_material.json"))
		if decoded is Dictionary:
			for entry: Array in (decoded as Dictionary).get("normal_table", []):
				if entry.size() >= 3:
					var key: String = "%.3f,%.3f,%.3f" % [float(entry[0]), float(entry[1]), float(entry[2])]
					_radial_normals[key] = true
	if _radial_normals.is_empty():
		return false
	var rounded := Vector3(snappedf(normal.x, 0.001), snappedf(normal.y, 0.001),
		snappedf(normal.z, 0.001))
	return _radial_normals.has("%.3f,%.3f,%.3f" % [rounded.x, rounded.y, rounded.z])


## The gain of the daylight on the surface of the map.##
## The surface of the original is a day surface: the grass of the plateau of
## the chapter in the frame of the owner is (99,94,44), the same ground of the
## port is (57,51,27) - the port reads as the underground of the original
## (1..45 in the unlit places of steam_02, steam_04, steam_12). The measured
## factor of the surface is 1.75 in the final picture; the shader applies the
## gamma of the original (1.3) after the light, so the gain of the light
## itself is 1.75^1.3 = 2.07.
const DAYLIGHT_GAIN: float = 2.07

# The multiplayer key points into the scene from (-0.36, +0.53, +0.77).
# Flip Y to match campaign source normals. Bake the key and skylight into
# the unshaded world-model material so they reach the same vertices as lamps.
const CLEARING_SUN: Vector3 = Vector3(-0.36, -0.53, 0.77)
const CLEARING_AMBIENT: float = 0.43
const CLEARING_KEY: float = 0.34


static func model_is_in_clearing(placement: Dictionary, edge: Variant) -> bool:
	if not edge is Vector3 or placement.get("template") != "urw_unq_start":
		return false
	# A placement takes the sky of its foot row, including tall objects that
	# cross cell boundaries. The extra row includes the exterior mountain.
	return float(placement.get("y", INF)) <= -edge.y + 1.05


static func clearing_model_diffuse(diffuse: Color, normal: Vector3) -> Color:
	var sun: float = maxf(normal.dot(CLEARING_SUN), 0.0)
	var daylight: float = CLEARING_AMBIENT + CLEARING_KEY * sun
	return diffuse.lerp(Color.WHITE, daylight)

## The surface level of every cell of the chapter and the block of every cell.
var _cell_levels: Dictionary = {}
var _cell_blocks: Dictionary = {}


func terrain_base_byte(cell: Vector2i, local_point: Vector2) -> int:
	if _lit_excavation and _is_excavation_cell(cell):
		# The excavation takes the light of the day surface of the map, so the
		# floor of a tunnel reads like the ground around it and not like a
		# black slot along every corridor.
		return ILLUMINATION.base_byte([ATTRIBUTE_MEAN, ATTRIBUTE_MEAN, ATTRIBUTE_MEAN, ATTRIBUTE_MEAN],
			local_point)
	return ILLUMINATION.base_byte(cell_attributes(cell), local_point)


## A cell of the excavation: its surface lies under the surface of the map.
func _is_excavation_cell(cell: Vector2i) -> bool:
	if cell.x < 0 or cell.y < 0:
		return false
	return absf(cell_surface_level(cell) - GROUND.MAP_GROUND_LEVEL) > 0.0001


## The four attribute bytes of a cell, in the order of the native corners.
##
## The attribute zero is the empty cell of the export and not a light level:
## the 1050 cells with it are spread over every level of the chapter, so they
## carry the mean of the chapter and not the half of it.
func cell_attributes(cell: Vector2i) -> Array:
	var attributes: Array = []
	for offset: Vector2i in [Vector2i.ZERO, Vector2i.RIGHT, Vector2i.DOWN, Vector2i.ONE]:
		var value: int = cell_attribute(cell + offset)
		attributes.append(ATTRIBUTE_MEAN if value == 0 else value)
	return attributes


## The light map of a cell for the world model path of the models.
##
## The battle scene takes the same four corners of the cell and the same
## interpolation (multiplayer_test.gd:1289-1300). The owner bytes of the live
## map are not in the export, so the host owner of 255 is used, the same as in
## the battle scene.
func model_light_fields(point: Vector3) -> Dictionary:
	var cell := Vector2i(floori(point.x), floori(point.y))
	return WORLD_MODEL_LIGHT.interpolate(cell_attributes(cell), [255, 255, 255, 255],
		Vector2(point.x - float(cell.x), point.y - float(cell.y)))


## The native light of a cell of the terrain.
##
## The native world model turns the attribute bytes of the PMP into the vertex
## colour of the terrain (native_terrain_illumination.base_byte) and adds the
## light of the native sources of the chapter to it. The chapter has its own
## sources, so the light of its terrain is the same path as the light of the
## battle scene, with the sources of the chapter instead of the sources of the
## battle level.
##
## The surface of the map is a day surface: the engine lights it with the sky.
## The cells under the surface are the underground of the original and stay
## dark.
##
## "sky" is how much of the sky falls on the face: one for a horizontal
## surface, the vertical part of the geometric normal for a slope and zero for
## a vertical face. It is not the smoothed normal of the rock of the export:
## that one says nothing about the orientation of the face.
func terrain_channels(cell: Vector2i, local_point: Vector3, source_normal: Array,
		sky: float = 1.0) -> Dictionary:
	var normal: Vector3 = Vector3(float(source_normal[0]), float(source_normal[1]), float(source_normal[2]))
	var point: Vector3 = local_point + Vector3(cell.x, cell.y, 0)
	var channels: Dictionary = ILLUMINATION.channels(point, normal,
		terrain_base_byte(cell, Vector2(local_point.x, local_point.y)),
		_lights_near(point), terrain_render["constants"])
	return _with_daylight(channels, cell, sky)


## The native light of a free cell of the map.
##
## The free cells of the map are not in the export: they have no attribute
## bytes and carry the mean of the chapter. Their surface is flat, so the
## normal of the source space is the up axis, and their depth is the depth of
## the ground level in the source space: the blocks encode the depth as
## (game_z + 14) / 2.
##
## The light sources of the chapter DO fall on the surface of the map: in the
## frame of the owner the ground next to the chapter is warmer and brighter
## than the ground at the other edge of the map (R−B = +16.7 against +10.8
## without the light of the torches). The engine bakes the light per cell and
## the surface of the map is lit like every other cell of the chapter.
func free_ground_channels(cell: Vector2i, local_point: Vector2, level: float) -> Dictionary:
	var point: Vector3 = Vector3(cell.x + local_point.x, cell.y + local_point.y, (level + 14.0) * 0.5)
	# The native free-ground run takes the map brightness set by SetBrightness.
	# Cave sources illuminate the placed cave geometry, not the untouched map
	# plane. Sampling a cave source at the first cell of a run spread its light
	# across the whole rectangular filler area around the cave.
	var channels: Dictionary = ILLUMINATION.channels(point, Vector3(0.0, 0.0, 1.0),
		terrain_base_byte(cell, local_point), [], terrain_render["constants"])
	return _with_daylight(channels, Vector2i(-1, -1), 1.0)


## The daylight of the sky on a face of the surface of the map.
##
## The surface of the original is a day surface: the grass of the plateau of
## the chapter in the frame of the owner is (99,94,44), the same ground of the
## port is (57,51,27) - the port reads as the underground of the original
## (1..45 in the unlit places of steam_02, steam_04, steam_12). The measured
## factor of the surface is 1.75 in the final picture; the shader applies the
## gamma of the original (1.3) after the light, so the gain of the light
## itself is 1.75^1.3 = 2.07.
##
## The sky falls on a face by its geometric orientation, so a vertical face of
## the rock stays as dark as the underground, and only the cells whose surface
## is the surface of the map get the daylight: the excavations under it are the
## underground.
func _with_daylight(channels: Dictionary, cell: Vector2i, sky: float) -> Dictionary:
	var gain: float = 1.0
	if _lit_excavation and _is_excavation_cell(cell):
		gain += (DAYLIGHT_GAIN - 1.0) * clampf(sky, 0.0, 1.0)
	elif cell.x >= 0 and absf(cell_surface_level(cell) - GROUND.MAP_GROUND_LEVEL) < 0.0001:
		gain += (DAYLIGHT_GAIN - 1.0) * clampf(sky, 0.0, 1.0)
	elif cell.x < 0:
		gain = DAYLIGHT_GAIN
	if absf(gain - 1.0) < 0.0001:
		return channels
	var diffuse: Color = channels["diffuse"]
	channels["diffuse"] = Color(diffuse.r * gain, diffuse.g * gain, diffuse.b * gain)
	return channels


## The surface level of a cell of the chapter: the highest point of its block.
func cell_surface_level(cell: Vector2i) -> float:
	if _cell_levels.has(cell):
		return float(_cell_levels[cell])
	if _cell_blocks.is_empty():
		for entry: Dictionary in data.get("cells", []):
			var position := Vector2i(int(entry["x"]), int(entry["y"]))
			if not _filter_cells or _active_cells.has(position):
				_cell_blocks[position] = int(entry["block"])
	var level: float = GROUND.MAP_GROUND_LEVEL
	var block: int = int(_cell_blocks.get(cell, -1))
	if block >= 0:
		var highest: float = -INF
		for part: Dictionary in data.get("meshes", {}).get(str(block), []):
			var values: Array = part["vertices"]
			for index in range(2, values.size(), 5):
				highest = maxf(highest, float(values[index]))
		level = highest
	_cell_levels[cell] = level
	return level


## The native tile of a cell of the chapter.
##
## The original draws the ground of a cell with one native tile of 64x64
## (Gnd_A01 … Gnd_C15) and the cells of the chapter keep their own UV of the
## export: on the ground of a cell u and v are the local coordinates of the
## cell, on a wall v runs along the depth. The tiles are written out by
## tools/build_ground_field.py.
func tile_file(cell: Vector2i, variant: int) -> String:
	var value: Variant = cell_material(cell)
	var material: int = 0 if value == null else int(value)
	if material == 3:
		material = 0
	var family: String = "A"
	if material == 1:
		family = "B"
	elif material == 2:
		family = "C"
	return "Gnd_%s%02d.png" % [family, (variant % 15) + 1]


## Terrain material of one ground family and detail atlas.
##
## The flat ground of the map is drawn with no_depth_write: the plane is drawn
## before the terrain of the chapter and does not write depth. In the original
## the ground of the map hides nothing of the rock of the chapter - the camera
## looks at the map under 16.6 degrees and the plane is seen edge on - and the
## board of the port is seen face on, where a plane in front of the rock would
## close the view of every excavation below it.
func terrain_material(variant: int, double_sided: bool, cull_front: bool, file: String = "",
		no_depth_write: bool = false, texture_dir: String = "res://textures/ground_field/",
		uv_local: bool = false, variation: Texture2D = null) -> ShaderMaterial:
	if file.is_empty():
		file = "ground_field_C.png"
	# The native tiles of the original are the files of the game itself
	# (Gnd_*.tga, Native_*.tga); the continuous fields and the tiles written out
	# by the tools are PNG. The directory follows the file, so that a caller
	# that names a native tile does not have to know the directory.
	var directory: String = texture_dir
	if file.ends_with(".tga"):
		directory = NATIVE_GROUND_DIR
	var key: String = "%s:%s:%s:%s:%s:%s:%s" % [directory, file, str(double_sided), str(cull_front),
		str(no_depth_write), str(uv_local), str(variation != null)]
	if material_cache.has(key):
		return material_cache[key] as ShaderMaterial
	var material: ShaderMaterial = ShaderMaterial.new()
	var shader: Shader = load("res://shaders/native_campaign_terrain.gdshader") as Shader
	if double_sided or cull_front or no_depth_write:
		shader = shader.duplicate() as Shader
		var mode: String = "cull_back"
		if double_sided:
			mode = "cull_disabled"
		elif cull_front:
			mode = "cull_front"
		if no_depth_write:
			mode += ", depth_draw_never"
		shader.code = shader.code.replace("cull_back", mode)
	material.shader = shader
	# The ground of the map is seen under a very grazing angle when the whole
	# chapter is in the frame: the anisotropic filtering of the default draws
	# the texture along that angle and smears the ground and the rock into
	# streaks. The original does not filter that way, so the anisotropy of the
	# project is switched off (project.godot:
	# rendering/textures/default_filters/anisotropic_filtering_level = 0).
	if no_depth_write:
		material.render_priority = -1
	material.set_shader_parameter("ground_texture", load(directory + file))
	var atlas: Dictionary = data.get("atlas", {})
	material.set_shader_parameter("detail_texture", load("res://assets/terrain_detail/" + str(atlas.get("file", ""))))
	material.set_shader_parameter("atlas_size", Vector2(float(atlas.get("size", [1, 1])[0]), float(atlas.get("size", [1, 1])[1])))
	material.set_shader_parameter("tile_size", float(atlas.get("tile_size", 64)))
	material.set_shader_parameter("tile_padding", float(atlas.get("padding", 8)))
	material.set_shader_parameter("tile_stride", float(atlas.get("stride", 80)))
	material.set_shader_parameter("field_cells", GROUND.FIELD_CELLS)
	# The UV of the native tiles are the local coordinates of the cell, and the
	# ground of the map is one continuous field with the coordinates of the map:
	# the detail of a cell is taken from its own place in both cases.
	material.set_shader_parameter("uv_local", uv_local)
	# The colour variation of the ground of the map: the original generates it
	# over the whole map, a tint of every cell (Campaign.tcl:6
	# generate_color_variation 0 0 512 640 0). The map of the variation is
	# sampled by the cell of the ground in the shader.
	if variation != null:
		material.set_shader_parameter("variation_map", variation)
		material.set_shader_parameter("variation_map_size",
			Vector2(float(GROUND.MAP_WIDTH), float(GROUND.MAP_HEIGHT)))
	material.set_shader_parameter("use_variation", variation != null)
	# The stage program of the original (native_shader_pipeline.json): the
	# ground texture times the light, the detail times the result times two, the
	# gamma and the brightness at the end.
	material.set_shader_parameter("ground_op", int(shader_pipeline["host_program"]["ground_op"]))
	material.set_shader_parameter("detail_op", int(shader_pipeline["host_program"]["detail_op"]))
	material.set_shader_parameter("secondary_enabled", bool(shader_pipeline["host_program"]["secondary_enabled"]))
	material.set_shader_parameter("native_gamma", float(shader_pipeline["defaults"]["gamma"]))
	material.set_shader_parameter("native_brightness", float(shader_pipeline["defaults"]["brightness"]))
	material_cache[key] = material
	return material
