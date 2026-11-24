extends SceneTree
## --headless --path godot --script res://tools/native_campaign_ground_self_test.gd
## Checks the base ground of the campaign map: the free intervals of the map
## rows and the level of the untouched rock.
const Ground = preload("res://scripts/native_campaign_ground.gd")

var _checks: int = 0
var _failures: Array[String] = []


func _initialize() -> void:
	call_deferred("_run")


func _check(condition: bool, message: String) -> void:
	_checks += 1
	if not condition:
		_failures.append(message)
		printerr("FAIL: " + message)


func _quad(z: float) -> Dictionary:
	return {
		"part": 0,
		"vertices": [
			0.0, 0.0, z, 0.0, 0.0,
			1.0, 0.0, z, 1.0, 0.0,
			0.0, 1.0, z, 0.0, 1.0,
			1.0, 1.0, z, 1.0, 1.0,
		],
		"indices": [0, 1, 2, 1, 3, 2],
	}


func _run() -> void:
	# --- the free intervals --------------------------------------------------
	var map_size := Vector2i(8, 3)
	var cells: Array = [
		{"x": 3, "y": 1, "block": 1},
		{"x": 4, "y": 1, "block": 1},
		{"x": 0, "y": 0, "block": 1},
	]
	var strips: Dictionary = Ground.free_strips(cells, map_size)
	_check(strips.size() == 3, "every row has its intervals")
	var row0: Array = strips[0]
	_check(row0.size() == 1 and int(row0[0][0]) == 1 and int(row0[0][1]) == 7, "a cell at the edge leaves one interval")
	var row1: Array = strips[1]
	_check(row1.size() == 2, "two cells in the middle leave two intervals")
	_check(int(row1[0][0]) == 0 and int(row1[0][1]) == 2, "the first interval ends before the cells")
	_check(int(row1[1][0]) == 5 and int(row1[1][1]) == 7, "the second interval starts after the cells")
	var row2: Array = strips[2]
	_check(row2.size() == 1 and int(row2[0][0]) == 0 and int(row2[0][1]) == 7, "an empty row is one interval")
	var total: int = 0
	for row_index: int in strips:
		for interval: Array in strips[row_index]:
			total += int(interval[1]) - int(interval[0]) + 1
	_check(total == 8 * 3 - 3, "the free cells are the map without the chapter cells")

	# --- the ground level ----------------------------------------------------
	var meshes: Dictionary = {"1": [_quad(14.5)], "2": [_quad(7.0)]}
	_check(absf(Ground.ground_level(cells, meshes) - 14.5) < 0.0001, "the ground is the highest surface")
	var mixed: Array = [{"x": 0, "y": 0, "block": 2}]
	_check(absf(Ground.ground_level(mixed, meshes) - 7.0) < 0.0001, "a low chapter keeps its own level")

	# --- the material of the free ground -------------------------------------
	# The material of a free cell of the map is the material of the map of the
	# original: the saved game of the owner keeps a byte per cell of the map,
	# whose low two bits are the code of the material (0 stone, 1 sand, 2
	# earth, 3 untouched rock). The engine resets the material of a band of
	# cells at the edge of the map to stone ("sm_draw_stone -border/-funnel"),
	# so the ground of the map is diggable earth with a stone band at the edge.
	# The generator of the original is the fallback, when the map has no data.
	var materials: PackedByteArray = Ground.load_material_map()
	_check(materials.size() == 512 * 640, "the material map covers the whole map")
	_check(Ground.free_material(materials, 50, 50) == 0, "the stone band of the map is stone")
	_check(Ground.free_material(materials, 100, 85) == 2, "the ground below the band is earth")
	_check(Ground.free_material(materials, 246, 200) == 2, "the south of the chapter is earth")
	_check(Ground.free_material(materials, -1, 0) == -1, "the map has no material outside of it")
	var stone: int = 0
	var earth: int = 0
	for x in range(44, 308):
		for y in range(0, 232):
			var material: int = Ground.free_material(materials, x, y)
			if material == 0:
				stone += 1
			elif material == 2:
				earth += 1
	_check(stone == 14256, "the stone band of the original covers 14256 cells of the map")
	_check(earth == 45694, "the diggable earth of the original covers 45694 cells of the map")
	# The generator of the original (scripts/native_campaign_map_material.gd) is
	# the rule that produced that material: the belt of stone at the edge of
	# the map and the walls of the funnel, the earth everywhere else. The
	# cells below are in the firm part of the belt and of the funnel, so they
	# do not depend on the place of the random stream of the session.
	_check(Ground.base_material(Vector2i(0, 0)) == 0, "the cell at the origin is stone")
	_check(Ground.base_material(Vector2i(44, 0)) == 0, "the cell at 44,0 is stone")
	_check(Ground.base_material(Vector2i(77, 126)) == 2, "the cell at 77,126 is earth")
	_check(Ground.base_material(Vector2i(511, 639)) == 2, "the south east corner is earth")

	# --- the ground field ----------------------------------------------------
	# The ground field of a family is one continuous texture: the coordinates
	# of the field are the coordinates of the map divided by the number of
	# cells that one tile of the field covers. The ground of the map itself is
	# drawn with one native tile per cell and does not use the field.
	_check(Ground.FIELD_CELLS == 16.0, "the field covers sixteen cells")
	# The tone of the ground of the map is one colour per run of free cells
	# (FUN_004cca20 writes the same colour into the four vertices of the
	# polygon of the run), and the run is cut into pieces of eight cells for
	# the collision of the ground and for the change of the family.
	_check(Ground.LIGHT_SEGMENT_CELLS == 8, "a piece of the ground covers eight cells")
	_check(Ground.field_uv(0.0, 0.0) == Vector2(0.0, 0.0), "the field starts at the origin")
	_check(Ground.field_uv(16.0, 32.0) == Vector2(1.0, 2.0), "the field repeats every sixteen cells")
	_check(Ground.field_uv(8.0, 8.0) == Vector2(0.5, 0.5), "the field is linear in the map")
	_check(absf(Ground.base_variation(Vector2i(0, 0)) - 1.048171) < 0.000001,
		"the colour variation of the origin is stable")
	_check(absf(Ground.base_variation(Vector2i(100, 0)) - 1.051814) < 0.000001,
		"the colour variation of the cell at 100,0 is stable")
	var variations: Array = []
	for x in range(0, 120, 7):
		for y in range(0, 120, 7):
			variations.append(Ground.base_variation(Vector2i(x, y)))
	var smallest: float = 1.0
	var largest: float = 1.0
	for value: float in variations:
		smallest = minf(smallest, value)
		largest = maxf(largest, value)
	_check(smallest > 0.93 and largest < 1.07, "the colour variation stays in its band")

	# --- the plan of the rock of the map ---------------------------------------
	# The original draws the rock of the map with the engine command
	# "sm_draw_stone -funnel": the plan of it is in the saved game of the owner,
	# not in the export of the chapter. The rock is a mass with a funnel shaped
	# upper edge: the throat of it holds the island of the chapter.
	var mask: PackedByteArray = Ground.load_rock_mask()
	_check(mask.size() == 512 * 640, "the mask covers the whole map")
	var rock_cells: int = 0
	for value: int in mask:
		if value != 0:
			rock_cells += 1
	_check(rock_cells == 267777, "the rock of the map covers 267777 cells of the save")
	_check(Ground.mask_has_rock(mask, 0, 1), "the border column of the map is rock")
	_check(Ground.mask_has_rock(mask, 0, 500), "the border column reaches the south of the map")
	_check(Ground.mask_has_rock(mask, 0, 0), "the corner of the border is rock")
	_check(not Ground.mask_has_rock(mask, 10, 5), "the north of the map is air")
	_check(not Ground.mask_has_rock(mask, 100, 30), "the air above the funnel is air")
	_check(Ground.mask_has_rock(mask, 100, 200), "the mass of the rock is below the funnel")
	_check(not Ground.mask_has_rock(mask, 300, 10), "the east of the throat is air")
	_check(Ground.mask_has_rock(mask, 246, 200), "the south of the chapter is rock")
	_check(not Ground.mask_has_rock(mask, -1, 0), "the map has no rock outside of it")

	# --- the variant of the ground texture -----------------------------------
	# The native staging takes one of the fifteen textures of a family per cell
	# from the live random stream; the static export spreads them deterministically.
	_check(Ground.base_variant(Vector2i(0, 0)) == 10, "the variant of the origin is stable")
	_check(Ground.base_variant(Vector2i(1, 0)) == 3, "the variant next to the origin is stable")
	_check(Ground.base_variant(Vector2i(7, 7)) == 8, "the variant at 7,7 is stable")
	_check(Ground.base_variant(Vector2i(100, 100)) == 9, "the variant at 100,100 is stable")
	var variants: Dictionary = {}
	for x in range(0, 60):
		for y in range(0, 60):
			variants[Ground.base_variant(Vector2i(x, y))] = true
	_check(variants.size() == 15, "all fifteen textures of a family are used")

	# --- the noise of the material -------------------------------------------
	var noise: float = Ground.value_noise(0.5, 0.5)
	_check(absf(noise - 0.509175) < 0.000001, "the noise of the material is stable")
	_check(absf(Ground.value_noise(3.25, 7.75) - 0.498478) < 0.000001, "the noise is stable in the map")
	_check(Ground.value_noise(0.0, 0.0) >= 0.0 and Ground.value_noise(0.0, 0.0) <= 1.0,
		"the noise stays between zero and one")

	# --- the turn of the texture ---------------------------------------------
	_check(Ground.base_turn(Vector2i(0, 0)) == Vector2(0.0, 1.0), "the cell at the origin is turned")
	_check(Ground.base_turn(Vector2i(1, 0)) == Vector2(1.0, 0.0), "the turn next to the origin is stable")
	_check(Ground.base_turn(Vector2i(7, 7)) == Vector2(1.0, 0.0), "the turn at 7,7 is stable")
	_check(Ground.base_turn(Vector2i(100, 100)) == Vector2(1.0, 1.0), "the turn at 100,100 is stable")
	var turns: Dictionary = {}
	for x in range(0, 40):
		for y in range(0, 40):
			turns[Ground.base_turn(Vector2i(x, y))] = true
	_check(turns.size() == 4, "all four turns of the texture are used")

	# --- the void around the island -------------------------------------------
	# The cells that carry no block of the chapter are the void around the
	# island, and their floor is the floor of the base map of the original.
	# The battle scene omits the same face (scripts/multiplayer_test.gd:1696).
	_check(Ground.is_backdrop(0x85), "the flag 0x85 marks the void")
	_check(not Ground.is_backdrop(0x84), "the flag 0x84 is rock, not the void")
	_check(not Ground.is_backdrop(0x82), "the flag 0x82 is rock, not the void")
	_check(not Ground.is_backdrop(0), "an empty flag is not the void")
	_check(absf(Ground.BASE_MAP_LEVEL - 7.0) < 0.0001, "the ground of the map is the exported depth 7.0")
	_check(absf(Ground.MAP_GROUND_LEVEL - 14.5) < 0.0001,
		"the flat ground of the map is the world Z 14.5, coplanar with the surface of the chapter")
	_check(Ground.is_void_floor(0, 7.0), "the floor of the void is part 0 at the level of the map")
	_check(not Ground.is_void_floor(1, 7.0), "a side face of the void is not its floor")
	_check(not Ground.is_void_floor(0, 14.5), "the surface of the island is not the floor of the void")
	_check(not Ground.is_void_floor(0, 8.5), "a bevel of the void is not its floor")

	# --- the void of the exported chapter -------------------------------------
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(
		"res://models/native_campaign_chapter.json"))
	if decoded is Dictionary:
		var chapter: Dictionary = decoded
		var chapter_meshes: Dictionary = chapter["meshes"]
		# The contract of the seam: the plane of the ground of the map and the
		# faces of the excavations against it stand at the same level, and that
		# level is the surface of the chapter. If a new export moves the
		# surface, the plane and the faces would move silently away from it.
		_check(absf(Ground.MAP_GROUND_LEVEL
			- Ground.ground_level(chapter["cells"], chapter_meshes)) < 0.0001,
			"the level of the ground plane is the surface of the chapter")
		var void_cells: Dictionary = {}
		for cell: Dictionary in chapter["cells"]:
			if Ground.is_backdrop(int(cell.get("flags", 0))):
				void_cells[Vector2i(int(cell["x"]), int(cell["y"]))] = true
		_check(void_cells.size() == 1416,
			"the chapter has 1416 cells of the void, found %d" % void_cells.size())
		var omitted: int = 0
		for cell: Dictionary in chapter["cells"]:
			if bool(cell.get("story", false)):
				continue
			var origin := Vector2i(int(cell["x"]), int(cell["y"]))
			var borders: bool = false
			for neighbour: Vector2i in [Vector2i.ZERO, Vector2i.RIGHT, Vector2i.DOWN, Vector2i.ONE]:
				if void_cells.has(origin + neighbour):
					borders = true
			if not borders:
				continue
			for part: Dictionary in chapter_meshes[str(int(cell["block"]))]:
				var values: Array = part["vertices"]
				var indices: Array = part["indices"]
				for start in range(0, indices.size(), 3):
					var is_floor: bool = true
					for tip in range(3):
						var depth: float = float(values[int(indices[start + tip]) * 5 + 2])
						if not Ground.is_void_floor(int(part["part"]), depth):
							is_floor = false
					if is_floor:
						omitted += 1
		_check(omitted == 2711, "the rule omits 2711 faces of the void, found %d" % omitted)
	else:
		_check(false, "the chapter export is missing")

	if _failures.is_empty():
		print("NATIVE_CAMPAIGN_GROUND_SELF_TEST_OK assertions=%d" % _checks)
	else:
		printerr("NATIVE_CAMPAIGN_GROUND_SELF_TEST_FAIL failures=%d" % _failures.size())
	quit(0 if _failures.is_empty() else 1)
