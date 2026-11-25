extends RefCounted
## The generator of the material of the map of the original.
const MAP_MATERIAL = preload("res://scripts/native_campaign_map_material.gd")
## The base ground of the campaign map.
##
## The original creates the whole map with "map create 512 640" and draws the
## ground over it, so the free cells of the map are the rock around the
## chapter. The export keeps only the cells of the placed templates, so the
## base layer is rebuilt here.
##
## The free cells are not in the chapter export. Their material is rebuilt by
## native_campaign_map_material.gd using the original border and funnel
## commands. The saved map is kept as a reference, but its old cave stamps and
## excavated air cannot serve as the live base map. Material 0 is stone
## (family A), 1 is sand
## (family B), and 2 is earth (family C).
##   - The texture of a cell is one of the fifteen native tiles of its family
##     (Gnd_A01..Gnd_A15 and so on), the way the original draws the ground of a
##     cell: one quad with the local UV of the cell (0..1). The port drew the
##     ground of the map with the continuous field of the family before
##     (tools/build_ground_field.py), and the field averages the fifteen tiles
##     into a flat grey: the measured standard deviation of the field was 11.8
##     against 27 of Gnd_A01, so the granite of the barrier read as a smooth
##     blur against the sharp tiles of the chapter.
##   - The tint of a cell is the colour variation of the original
##     (Campaign.tcl:6 generate_color_variation), a tint of every cell of the
##     map, and not a new texture per cell.
##
## Sources (original install, read-only):
##   data/Scripts/gameplay/Campaign.tcl:2    map create 512 640
##   data/Scripts/gameplay/Campaign.tcl:6    generate_color_variation 0 0 512 640 0
##   tools/export_campaign_chapter.py         the export of the chapter
##   tools/build_ground_field.py              the ground field of the map

## The depth of the funnel of the map.
##
## The plan of the rock of the saved game says where the map has ground at
## all: the rest of the map is the funnel (the command sm_draw_stone -funnel
## of the original), a crater in the surface of the map. The port fills it with
## the rock of the crater: its floor a cell below the surface of the map and
## the rim between the ground of the map and the floor.
const FUNNEL_DEPTH: float = 1.0

## The bottom of the rock. The blocks of the original reach down to it, so it
## is the lower bound of the body of the terrain.
const ROCK_BOTTOM: float = 0.25

## The level of the ground of the map of the original.
##
## The original creates the map flat (data/Scripts/gameplay/Campaign.tcl:2
## "map create 512 640"), and the ground of the map is the level zero of the
## engine. The corners of the exported blocks carry the depth as
## (game_z + 14) / 2, so the ground of the map is the exported depth 7.0.
const BASE_MAP_LEVEL: float = 7.0

## The level of the flat ground of the map of the original.
##
## The engine draws the ground of the map as one four-sided polygon per run of
## free cells (FUN_004cca20:41-109) and writes the height of every vertex of
## the polygon as 0x41680000, that is the world Z 14.5 - the level of the
## surface of the chapter, and the level at which the engine puts an object on
## the ground (FUN_00568410) and clamps the height of an object
## (FUN_00420840). The ground of the map is therefore coplanar with the
## surface of the chapter.
const MAP_GROUND_LEVEL: float = 14.5

## The flag of a cell that carries no block of the chapter: the void around
## the island of the chapter. The battle scene reads the same flag for its
## backdrop samples (scripts/multiplayer_test.gd:1653).
const BACKDROP_FLAG: int = 0x85

## Whether a cell of the chapter carries no block: the void around the island.
static func is_backdrop(flags: int) -> bool:
	return flags == BACKDROP_FLAG


## Whether a face of a block is the floor of the void around the island.
##
## The battle scene omits the same face (scripts/multiplayer_test.gd:1696-1707):
## the deepest flat face of a cell that touches the void. The floor of the void
## belongs to the base map of the original and not to the rock of the chapter.
## In the native view of the original it is hidden behind the island, and the
## board of the port looks at the map face on, so that floor would close the
## view behind the island as a granite plane in the axes Y and X.
static func is_void_floor(part: int, depth: float) -> bool:
	return part == 0 and absf(depth - BASE_MAP_LEVEL) <= 0.0001

## The size of a patch of the ground material, in map cells.
##
## The patch is large on purpose: the native map is one rock mass with patches
## of sand in it, so the borders of the patches are long curves, not a speckle
## of one cell each.
const MATERIAL_PATCH: float = 26.0

## The number of the ground textures of one family.
const VARIANT_COUNT: int = 15

## The number of map cells that one tile of the ground field covers.
##
## The field texture is 512 pixels wide and one native tile is 64 pixels, so
## the field keeps the native scale of 64 pixels per cell and covers eight
## cells.
const FIELD_CELLS: float = 16.0

## The length of a piece of the free ground of the map, in map cells.
##
## The tone of the ground of the original is flat inside a run of the free
## cells (the colour of the polygon of the run lies in its four vertices), so
## the pieces of a run carry one colour. The pieces are the pieces of the
## collision of the ground and the place where the family of the ground may
## change.
const LIGHT_SEGMENT_CELLS: int = 8

## The strength of the colour variation of the free ground.
##
## The original generates a colour variation over the whole map
## (Campaign.tcl:6 generate_color_variation 0 0 512 640 0): a tint of every
## cell, not a different texture. The port writes the tint into the vertex
## colour of the ground, so the field of the map is not one flat tone.
const VARIATION_STRENGTH: float = 0.07

## The size of the map of the chapter.
const MAP_WIDTH: int = 512
const MAP_HEIGHT: int = 640

## The ground of the map that the engine did not reset.
##
## The original draws the rock of the map with the engine command
## "sm_draw_stone -border" and "sm_draw_stone -funnel"
## (data/Scripts/gameplay/Campaign.tcl:3-4). The command is C++: it resets the
## material of a band of cells at the edge of the map to stone, with a random
## falloff towards the edge. It does NOT change the geometry - the map of the
## original is flat, and the band is ground of another material and not a hole
## of the map.
##
## The material of every cell of the map is in the saved game of the owner:
## the map grid of the save keeps a byte per cell, whose low two bits are the
## code of the material (tools/export_campaign_ground_mask.py).
##
## ADAPTER: the HEIGHT of the free ground is not in the save - the engine
## regenerates it - so the ground of the map is drawn at the surface level of
## the chapter. The material of the ground is the fact of the save.
static func load_rock_mask() -> PackedByteArray:
	var mask := PackedByteArray()
	mask.resize(MAP_WIDTH * MAP_HEIGHT)
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(
		"res://models/native_campaign_ground_mask.json"))
	if not decoded is Dictionary:
		return mask
	var report: Dictionary = decoded
	var index: int = 0
	for run: Array in report.get("runs", []):
		var value: int = int(run[0])
		var count: int = int(run[1])
		for step in range(count):
			if index >= mask.size():
				break
			mask[index] = value
			index += 1
	return mask

## The material of every cell of the map of the original.
##
## The codes are the native ones: 0 is stone, 1 is sand, 2 is earth, 3 is
## untouched rock. Zero and three are rock and cannot be tunnelled through,
## one and two are diggable (data/Scripts/ai/std_ai.tcl:2991).
##
## FACT (Diggles.exe, decompilation of 2026-11-24): the material of a cell is
## the low two bits of the word of the cell (the engine writes it in
## FUN_00598f10:149 and FUN_005fc9d0:110), and the saved game keeps the word of
## the cell. The material of the map of the original is therefore the material
## of the saved game of the owner - and not a noise of the port.
static func load_material_map() -> PackedByteArray:
	var materials := PackedByteArray()
	materials.resize(MAP_WIDTH * MAP_HEIGHT)
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(
		"res://models/native_campaign_ground_material.json"))
	if not decoded is Dictionary:
		return materials
	var report: Dictionary = decoded
	var index: int = 0
	for run: Array in report.get("runs", []):
		var value: int = int(run[0]) & 3
		var count: int = int(run[1])
		for step in range(count):
			if index >= materials.size():
				break
			materials[index] = value
			index += 1
	return materials


## The material of the cells that the saved game does not cover, by the
## generator of the original (scripts/native_campaign_map_material.gd).
##
## The map of the generator is built once: the generator walks 327 680 cells
## and draws the stone of the border and of the funnel.
static var _generator_materials: PackedByteArray = PackedByteArray()

static func generator_material_map() -> PackedByteArray:
	if _generator_materials.is_empty():
		var generated: Dictionary = MAP_MATERIAL.generate(MAP_WIDTH, MAP_HEIGHT)
		_generator_materials = generated.get("materials", PackedByteArray()) as PackedByteArray
	return _generator_materials


## The material of a free cell of the map by the generator of the original.
static func generator_material(x: int, y: int) -> int:
	if x < 0 or y < 0 or x >= MAP_WIDTH or y >= MAP_HEIGHT:
		return -1
	var materials: PackedByteArray = generator_material_map()
	if materials.is_empty():
		return -1
	return int(materials[y * MAP_WIDTH + x])


## The material of a free cell of the map, or -1 when the map has no data.
static func free_material(materials: PackedByteArray, x: int, y: int) -> int:
	if x < 0 or y < 0 or x >= MAP_WIDTH or y >= MAP_HEIGHT:
		return -1
	if materials.is_empty():
		return -1
	return int(materials[y * MAP_WIDTH + x])


## Whether a cell of the map carries the rock of the original.
static func mask_has_rock(mask: PackedByteArray, x: int, y: int) -> bool:
	if x < 0 or y < 0 or x >= MAP_WIDTH or y >= MAP_HEIGHT:
		return false
	return mask[y * MAP_WIDTH + x] != 0


## The free intervals of every map row, without the cells of the chapter.
##
## The result is {row: [[x_min, x_max], ...]}, the intervals in x that are not
## covered by a cell of the chapter.
static func free_strips(cells: Array, map_size: Vector2i) -> Dictionary:
	var rows: Dictionary = {}
	for entry: Dictionary in cells:
		var row: int = int(entry["y"])
		if not rows.has(row):
			rows[row] = []
		(rows[row] as Array).append(int(entry["x"]))
	var strips: Dictionary = {}
	for row_index in range(map_size.y):
		var covered: Array = rows.get(row_index, [])
		covered.sort()
		var intervals: Array = []
		var cursor: int = 0
		for column: int in covered:
			if column >= map_size.x:
				break
			if column > cursor:
				intervals.append([cursor, column - 1])
			cursor = maxi(cursor, column + 1)
		if cursor < map_size.x:
			intervals.append([cursor, map_size.x - 1])
		strips[row_index] = intervals
	return strips


## The level of the untouched rock.
##
## The ground of the chapter is the highest surface of the exported cells: the
## caves are dug below it.
static func ground_level(cells: Array, meshes: Dictionary) -> float:
	var highest: float = -INF
	for entry: Dictionary in cells:
		var parts: Array = meshes.get(str(int(entry["block"])), [])
		for part: Dictionary in parts:
			var values: Array = part["vertices"]
			for index in range(0, values.size(), 5):
				highest = maxf(highest, float(values[index + 2]))
	return highest


## The material of a cell of the free ground that the saved game does not
## cover.
##
## The free cells of the map are not in the export of the chapter, but their
## material is in the saved game of the owner: byte 28 of the record of the
## cell is the material of the cell of the original (the engine writes it in
## FUN_00598f10:149 and FUN_005fc9d0:110). The saved game is the map of the
## original itself, so the free cells take their material from it.
##
## The port used a smooth noise here, with the shares of the surface of the
## chapter, and the belt of granite of the edge of the map on top of it
## (native_campaign_first_level.gd, the function of the band of the edge).
## Both were inventions of the port: the original has no noise of the material
## and no band of granite around the island. The original has one belt of
## stone - at the edge of the map and in the walls of the funnel - and the
## earth everywhere else.
##
## The material code follows the native one: 0 is stone and cannot be
## tunnelled through, 1 and 2 are the two diggable kinds of sand and earth.
static func base_material(cell: Vector2i) -> int:
	var material: int = generator_material(cell.x, cell.y)
	if material >= 0:
		return material
	return MAP_MATERIAL.MATERIAL_EARTH


## The texture coordinates of a point of the map in the ground field.
##
## One tile of the field covers FIELD_CELLS map cells, so the coordinates of
## the field are the coordinates of the map divided by that number. The free
## ground and the cells of the chapter use the same coordinates, so the ground
## of the map is one continuous surface and the two parts fit together.
static func field_uv(world_x: float, world_y: float) -> Vector2:
	return Vector2(world_x / FIELD_CELLS, world_y / FIELD_CELLS)


## The colour variation of a cell of the free ground.
##
## The original generates a colour variation over the whole map
## (Campaign.tcl:6 generate_color_variation 0 0 512 640 0): a tint per cell of
## the same ground, not a different texture. The port writes that tint into
## the vertex colour of the ground, so the free ground is not one flat tone.
static func base_variation(cell: Vector2i) -> float:
	var value: float = value_noise(float(cell.x) / MATERIAL_PATCH + 11.0,
		float(cell.y) / MATERIAL_PATCH + 7.0)
	return 1.0 + (value - 0.5) * 2.0 * VARIATION_STRENGTH


## The map of the colour variation of the ground of the map.
##
## The variation of the original is a tint of every cell of the map, so it has
## to be sampled by the cell of the ground: the free ground is built in pieces
## of several cells, and a tint in the vertices of a piece would be smeared over
## the whole piece. The map is a texture of one byte per cell: the value is
## stored as (tint - VARIATION_BASE) / VARIATION_RANGE, so the shader can read
## it back without a rounding of the range.
static func build_variation_map() -> ImageTexture:
	var image: Image = Image.create(MAP_WIDTH, MAP_HEIGHT, false, Image.FORMAT_RGBA8)
	for row in range(MAP_HEIGHT):
		for column in range(MAP_WIDTH):
			var tint: float = base_variation(Vector2i(column, row))
			var value: float = int(round(clampf(
				(tint - VARIATION_BASE) / VARIATION_RANGE, 0.0, 1.0) * 255.0))
			image.set_pixel(column, row, Color(float(value) / 255.0, 0.0, 0.0, 1.0))
	return ImageTexture.create_from_image(image)


## The base of the colour variation and its range: the tint of a cell lies
## between the base and the base plus the range.
const VARIATION_BASE: float = 0.9
const VARIATION_RANGE: float = 0.2


## The variant of the ground texture of a cell.
##
## The native staging picks one of the fifteen textures of a family per cell
## from the live random stream. The static export uses a deterministic spread
## of the same fifteen source textures instead.
static func base_variant(cell: Vector2i) -> int:
	return absi(hash_value(cell.x, cell.y)) % VARIANT_COUNT


## The turn of the texture of a cell of the free ground.
##
## The texture of a cell is drawn once per cell, so the turn breaks the
## repetition of the pattern without changing the scale of the texture.
static func base_turn(cell: Vector2i) -> Vector2:
	var code: int = absi(hash_value(cell.x + 8191, cell.y + 4093)) & 3
	return Vector2(float(code & 1), float((code >> 1) & 1))


## A smooth noise over the map, between zero and one.
static func value_noise(x: float, y: float) -> float:
	var cell_x: int = int(floor(x))
	var cell_y: int = int(floor(y))
	var fraction_x: float = x - float(cell_x)
	var fraction_y: float = y - float(cell_y)
	var smooth_x: float = fraction_x * fraction_x * (3.0 - 2.0 * fraction_x)
	var smooth_y: float = fraction_y * fraction_y * (3.0 - 2.0 * fraction_y)
	var top: float = lerpf(hash2(cell_x, cell_y), hash2(cell_x + 1, cell_y), smooth_x)
	var bottom: float = lerpf(hash2(cell_x, cell_y + 1), hash2(cell_x + 1, cell_y + 1), smooth_x)
	return lerpf(top, bottom, smooth_y)


## The hash of a point of the noise, between zero and one.
static func hash2(x: int, y: int) -> float:
	return float(absi(hash_value(x, y)) % 1000003) / 1000003.0


## The hash of a point of the map, an integer of any sign.
static func hash_value(x: int, y: int) -> int:
	var hash_result: int = (x * 73856093) ^ (y * 19349663) ^ 0x5f356495
	hash_result = (hash_result ^ (hash_result >> 13)) * 1274126177
	return hash_result ^ (hash_result >> 16)
