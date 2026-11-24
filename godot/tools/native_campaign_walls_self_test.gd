extends SceneTree
## --headless --path godot --script res://tools/native_campaign_walls_self_test.gd
## Checks the excavation walls of the campaign chapter: the profile of the sides
## of a cell and the vertical faces between two cells of a different height.
const Walls = preload("res://scripts/native_campaign_walls.gd")

var _checks: int = 0
var _failures: Array[String] = []


func _initialize() -> void:
	call_deferred("_run")


func _check(condition: bool, message: String) -> void:
	_checks += 1
	if not condition:
		_failures.append(message)
		printerr("FAIL: " + message)


## One flat patch of a cell at the given height.
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


## A cell that is flat at the given height.
func _cell(x: int, y: int, block: int) -> Dictionary:
	return {"x": x, "y": y, "block": block, "ground_variant": 1}


## One triangle of a block.
func _tri(a: Vector3, b: Vector3, c: Vector3) -> Dictionary:
	return {
		"part": 0,
		"vertices": [
			a.x, a.y, a.z, 0.0, 0.0,
			b.x, b.y, b.z, 0.0, 0.0,
			c.x, c.y, c.z, 0.0, 0.0,
		],
		"indices": [0, 1, 2],
	}


func _run() -> void:
	# --- the neighbours ------------------------------------------------------
	_check(Walls.neighbour(Vector2i(3, 4), Walls.SIDE_POS_X) == Vector2i(4, 4), "the neighbour to the east")
	_check(Walls.neighbour(Vector2i(3, 4), Walls.SIDE_NEG_Y) == Vector2i(3, 3), "the neighbour to the north")
	_check(Walls.opposite_side(Walls.SIDE_POS_X) == Walls.SIDE_NEG_X, "the opposite of the east is the west")
	_check(Walls.opposite_side(Walls.SIDE_POS_Y) == Walls.SIDE_NEG_Y, "the opposite of the south is the north")

	# --- the side of an edge -------------------------------------------------
	var south := Vector3(0.0, 0.0, 14.5)
	var east := Vector3(0.0, 0.0, 14.5)
	var north := Vector3(0.0, 1.0, 14.5)
	var diagonal := Vector3(1.0, 1.0, 14.5)
	_check(Walls.side_of(south, east) == Walls.SIDE_NEG_Y, "an edge on the north edge of the cell")
	_check(Walls.side_of(south, north) == Walls.SIDE_NEG_X, "an edge on the west edge of the cell")
	_check(Walls.side_of(south, diagonal) == -1, "a diagonal edge is inside the cell")

	# --- the profile of a cell ----------------------------------------------
	var cells: Array = [_cell(0, 0, 1), _cell(1, 0, 2)]
	var meshes: Dictionary = {"1": [_quad(14.5)], "2": [_quad(7.0)]}
	var profiles: Dictionary = Walls.side_profiles(cells, meshes)
	_check(profiles.size() == 2, "every cell has a profile")
	var first: Dictionary = profiles[Vector2i(0, 0)]
	_check((first[Walls.SIDE_NEG_X] as Array).size() == 1, "the west side of a flat cell has one segment")
	var segment: Array = (first[Walls.SIDE_NEG_X] as Array)[0]
	_check(absf(float(segment[0]) - 0.0) < 0.0001 and absf(float(segment[1]) - 1.0) < 0.0001,
		"the segment covers the whole side")
	_check(absf(float(segment[2]) - 14.5) < 0.0001, "the segment carries the height of the terrain")

	# --- the faces between two cells ----------------------------------------
	var quads: Array = Walls.relief_quads(cells, meshes, 14.5)
	var step_faces: Array = []
	for quad: Dictionary in quads:
		if quad["cell"] == Vector2i(1, 0) and int(quad["side"]) == Walls.SIDE_NEG_X:
			step_faces.append(quad)
	_check(step_faces.size() == 1, "one step between two cells is one face")
	var face: Dictionary = step_faces[0]
	_check(absf(float(face["lower"]) - 7.0) < 0.0001, "the face starts at the lower cell")
	_check(absf(float(face["upper"]) - 14.5) < 0.0001, "the face ends at the higher cell")
	_check(absf(float(face["height"]) - 7.5) < 0.0001, "the face is as high as the step")
	_check(face["cell"] == Vector2i(1, 0), "the face belongs to the lower cell")
	_check(int(face["side"]) == Walls.SIDE_NEG_X, "the face lies on the side of the lower cell")
	var normal: Vector3 = face["normal"]
	_check(absf(normal.x - 1.0) < 0.0001 and absf(normal.y) < 0.0001, "the normal points into the excavation")
	var corners: Array = face["corners"]
	_check(corners.size() == 4, "the face has four corners")
	_check(absf((corners[1] as Vector3).x - 0.0) < 0.0001, "the face lies in the plane of the side")
	_check(absf((corners[2] as Vector3).z - 14.5) < 0.0001, "the upper corners are at the height of the rock")
	var facing: Vector3 = (corners[1] as Vector3).cross(corners[2] as Vector3)
	_check(facing.dot(normal) > 0.0, "the winding shows the face from the excavation")

	# --- the face against the base layer of the map -------------------------
	# The free cells of the map inside it carry the base layer of the original,
	# so the cell gets a face against them.
	var alone: Array = [_cell(10, 10, 2)]
	var alone_quads: Array = Walls.relief_quads(alone, meshes, 14.5)
	var border_faces: int = 0
	for quad: Dictionary in alone_quads:
		if int(quad["side"]) == Walls.SIDE_NEG_X:
			border_faces += 1
			_check(absf(float(quad["lower"]) - 7.0) < 0.0001, "the border face starts at the excavation")
			_check(absf(float(quad["upper"]) - 14.5) < 0.0001, "the border face ends at the ground level")
	_check(border_faces == 1, "the free side of a cell gets a face against the ground")

	# --- the edge of the map -------------------------------------------------
	# Beyond the edge of the map there is neither ground nor rock: the face
	# against the void is an artifact of the port, and at the northern edge of
	# the chapter it is a granite wall across the mouth of the start excavation.
	_check(not Walls.inside_map(Vector2i(10, -1)), "the row above the map is outside the map")
	_check(not Walls.inside_map(Vector2i(-1, 10)), "the column left of the map is outside the map")
	_check(not Walls.inside_map(Vector2i(512, 10)), "the column right of the map is outside the map")
	_check(Walls.inside_map(Vector2i(511, 639)), "the last cell of the map is inside the map")
	var edge: Array = [_cell(10, 0, 2)]
	var edge_quads: Array = Walls.relief_quads(edge, meshes, 14.5)
	var edge_faces: int = 0
	for quad: Dictionary in edge_quads:
		if int(quad["side"]) == Walls.SIDE_NEG_Y:
			edge_faces += 1
	_check(edge_faces == 0, "a cell at the edge of the map gets no face against the void")
	var edge_inside: int = 0
	for quad: Dictionary in edge_quads:
		if int(quad["side"]) == Walls.SIDE_POS_Y:
			edge_inside += 1
	_check(edge_inside == 1, "a cell at the edge of the map gets a face against the ground of the map")

	# --- two cells of the same height ---------------------------------------
	var level_cells: Array = [_cell(0, 0, 1), _cell(1, 0, 1)]
	var level_quads: Array = Walls.relief_quads(level_cells, meshes, 14.5)
	_check(level_quads.is_empty(), "two cells of the same height have no face")

	# --- a cell that is stepped in half -------------------------------------
	var stepped: Dictionary = {
		"part": 0,
		"vertices": [
			0.0, 0.0, 7.0, 0.0, 0.0,
			1.0, 0.0, 7.0, 1.0, 0.0,
			0.0, 0.5, 7.0, 0.0, 0.5,
			1.0, 0.5, 7.0, 1.0, 0.5,
			0.0, 0.5, 14.5, 0.0, 0.5,
			1.0, 0.5, 14.5, 1.0, 0.5,
			0.0, 1.0, 14.5, 0.0, 1.0,
			1.0, 1.0, 14.5, 1.0, 1.0,
		],
		"indices": [0, 1, 2, 1, 3, 2, 4, 5, 6, 5, 7, 6],
	}
	var step_profiles: Dictionary = Walls.side_profiles([_cell(0, 0, 3)], {"3": [stepped]})
	var step_sides: Dictionary = step_profiles[Vector2i(0, 0)]
	_check((step_sides[Walls.SIDE_NEG_X] as Array).size() == 2, "a stepped cell has two segments on a side")
	_check(absf(Walls.level_at(step_sides[Walls.SIDE_NEG_X], 0.25) - 7.0) < 0.0001,
		"the lower half of the side is at the bottom")
	_check(absf(Walls.level_at(step_sides[Walls.SIDE_NEG_X], 0.75) - 14.5) < 0.0001,
		"the upper half of the side is at the top")

	# --- the face of a cliff --------------------------------------------------
	# The ramp of the export: the top edge is at 14.5, the lower edge at 12.5.
	var ramp: Array[Vector3] = [
		Vector3(1.0, 0.25, 14.5), Vector3(1.0, 0.5, 12.5), Vector3(0.0, 0.5, 12.5)]
	var cliff: Dictionary = Walls.cliff_quad(Vector2i(7, 9), ramp, 2.0)
	_check(not cliff.is_empty(), "a ramp of two units gets a face of the cliff")
	_check(absf(float(cliff["lower"]) - 12.5) < 0.0001, "the face starts at the lower level of the ramp")
	_check(absf(float(cliff["upper"]) - 14.5) < 0.0001, "the face ends at the upper level of the ramp")
	_check(absf(float(cliff["height"]) - 2.0) < 0.0001, "the face is as high as the ramp")
	_check(cliff["cell"] == Vector2i(7, 9), "the face belongs to the cell of the ramp")
	_check(int(cliff["side"]) == Walls.SIDE_POS_Y, "the face of a ramp along x lies in a plane y = const")
	var cliff_normal: Vector3 = cliff["normal"]
	_check(absf(cliff_normal.x) < 0.0001 and absf(cliff_normal.y - 1.0) < 0.0001,
		"the normal of the face points away from the ramp, into the lower side")
	var cliff_corners: Array = cliff["corners"]
	_check(cliff_corners.size() == 4, "the face of a cliff has four corners")
	_check(absf((cliff_corners[0] as Vector3).z - 12.5) < 0.0001
		and absf((cliff_corners[1] as Vector3).z - 12.5) < 0.0001,
		"the lower corners of the face are at the lower level")
	_check(absf((cliff_corners[2] as Vector3).z - 14.5) < 0.0001
		and absf((cliff_corners[3] as Vector3).z - 14.5) < 0.0001,
		"the upper corners of the face are at the upper level")
	var cliff_facing: Vector3 = ((cliff_corners[1] as Vector3) - (cliff_corners[0] as Vector3)) \
		.cross((cliff_corners[2] as Vector3) - (cliff_corners[0] as Vector3))
	_check(cliff_facing.dot(cliff_normal) > 0.0, "the winding of the cliff shows the face from the excavation")

	# A ramp that is lower than the threshold is the relief of the surface.
	_check(Walls.cliff_quad(Vector2i(0, 0), ramp, 3.0).is_empty(),
		"a ramp below the threshold gets no face")
	# A flat patch is the surface, a face in a plane y = const is in the export.
	var patch: Array[Vector3] = [
		Vector3(0.0, 0.0, 14.5), Vector3(1.0, 0.0, 14.5), Vector3(0.0, 1.0, 14.5)]
	_check(Walls.cliff_quad(Vector2i(0, 0), patch, 2.0).is_empty(),
		"a flat patch gets no face of a cliff")
	var exported_face: Array[Vector3] = [
		Vector3(0.0, 0.25, 12.5), Vector3(1.0, 0.25, 12.5), Vector3(0.0, 0.25, 14.5)]
	_check(Walls.cliff_quad(Vector2i(0, 0), exported_face, 2.0).is_empty(),
		"a face in a plane y = const is in the export already")
	# A ramp whose lower edge is on the border of the cell is the face of the
	# neighbour: the pair of the profiles builds it.
	var border_ramp: Array[Vector3] = [
		Vector3(1.0, 0.25, 14.5), Vector3(1.0, 0.0, 12.5), Vector3(0.0, 0.0, 12.5)]
	_check(Walls.cliff_quad(Vector2i(0, 0), border_ramp, 2.0).is_empty(),
		"a ramp on the border of the cell gets no face of a cliff")
	# A triangle whose lowest corner is a single point has no lower edge.
	var point_ramp: Array[Vector3] = [
		Vector3(0.0, 0.25, 14.5), Vector3(1.0, 0.25, 14.5), Vector3(0.0, 0.5, 12.5)]
	_check(Walls.cliff_quad(Vector2i(0, 0), point_ramp, 2.0).is_empty(),
		"a triangle without a lower edge gets no face of a cliff")
	# A diagonal lower edge: the chapter has 40 of them. The engine has no face
	# of forty five degrees, so the module must not build one either.
	var diagonal_ramp: Array[Vector3] = [
		Vector3(0.75, 1.0, 10.0), Vector3(0.5, 0.75, 10.0), Vector3(1.0, 1.0, 12.0)]
	_check(Walls.cliff_quad(Vector2i(233, 39), diagonal_ramp, 2.0).is_empty(),
		"a ramp with a diagonal lower edge gets no face, the engine has no 45 degree face")

	# --- the faces of the cliffs of the chapter ------------------------------
	var chapter: Variant = JSON.parse_string(
		FileAccess.get_file_as_string("res://models/native_campaign_chapter.json"))
	if chapter is Dictionary:
		var chapter_cells: Array = (chapter as Dictionary)["cells"]
		var chapter_meshes: Dictionary = (chapter as Dictionary)["meshes"]
		var cliffs: Array = Walls.cliff_quads(chapter_cells, chapter_meshes)
		_check(cliffs.size() == 1288,
			"the chapter has 1288 faces of its cliffs, got %d" % cliffs.size())
		var broken: int = 0
		for quad: Dictionary in cliffs:
			var normal_value: Vector3 = quad["normal"]
			var corners_value: Array = quad["corners"]
			if absf(normal_value.z) > 0.0001 or float(quad["height"]) <= 0.0:
				broken += 1
				continue
			var facing_value: Vector3 = ((corners_value[1] as Vector3) - (corners_value[0] as Vector3)) \
				.cross((corners_value[2] as Vector3) - (corners_value[0] as Vector3))
			if facing_value.dot(normal_value) <= 0.0:
				broken += 1
		_check(broken == 0, "every face of a cliff stands upright and shows its side")
		var diagonal_faces: int = 0
		for quad: Dictionary in cliffs:
			var normal_value: Vector3 = quad["normal"]
			if absf(normal_value.x) > 0.0001 and absf(normal_value.y) > 0.0001:
				diagonal_faces += 1
		_check(diagonal_faces == 0,
			"the chapter has no face of forty five degrees, the engine has none either")
		# Every face of a cliff stands on the floor of the excavation: the
		# slopes of the rock of the map get no wall.
		var on_the_rock: int = 0
		for quad: Dictionary in cliffs:
			if float(quad["lower"]) < 12.5 - 0.0001:
				on_the_rock += 1
		_check(on_the_rock == 0,
			"no face of a cliff stands below the floor of the excavation, got %d" % on_the_rock)
		# The wall of a step has no gap in it: the parts of the step follow one
		# another along the plane they stand in.
		var walls: Dictionary = {}
		for quad: Dictionary in cliffs:
			var corners_value: Array = quad["corners"]
			var wall_first: Vector3 = corners_value[0]
			var wall_second: Vector3 = corners_value[1]
			var along_x: bool = absf(wall_first.y - wall_second.y) < 0.0001
			var position: float = wall_first.y if along_x else wall_first.x
			var start: float = minf(wall_first.x, wall_second.x) if along_x else minf(wall_first.y, wall_second.y)
			var stop: float = maxf(wall_first.x, wall_second.x) if along_x else maxf(wall_first.y, wall_second.y)
			var key: String = "%s:%d:%d:%d" % [str(quad["cell"]),
				int(round(position * 1024.0)), 1 if along_x else 0, int(quad["side"])]
			if not walls.has(key):
				walls[key] = []
			(walls[key] as Array).append([start, stop])
		var gaps: int = 0
		for key: String in walls:
			var spans: Array = walls[key]
			spans.sort_custom(func(a: Array, b: Array) -> bool: return float(a[0]) < float(b[0]))
			for index in range(0, spans.size() - 1):
				if float((spans[index + 1] as Array)[0]) - float((spans[index] as Array)[1]) > 0.0001:
					gaps += 1
		_check(gaps == 9, "the wall of the chapter has nine gaps, got %d" % gaps)

		# --- the faces of the whole chapter -----------------------------------
		var all_quads: Array = Walls.relief_quads(chapter_cells, chapter_meshes, 14.5)
		_check(all_quads.size() == 1556,
			"the chapter has 1556 faces, got %d" % all_quads.size())
		# No face of the chapter stands against the void beyond the edge of the map.
		var beyond: int = 0
		var at_the_north: int = 0
		for quad: Dictionary in all_quads:
			var cell: Vector2i = quad["cell"]
			var side: int = int(quad["side"])
			if not Walls.inside_map(Walls.neighbour(cell, side)):
				beyond += 1
			if cell.y == 0 and side == Walls.SIDE_NEG_Y:
				at_the_north += 1
		_check(beyond == 0, "no face of the chapter stands against the void, got %d" % beyond)
		_check(at_the_north == 0,
			"the mouth of the start excavation is open, got %d faces" % at_the_north)

		# --- the rule of the borders, fixed ------------------------------------
		# The rule of the borders (border_quads) is the rule of the module: the
		# base layer of the scene builds no vertical face of its own, so every
		# face of the excavation comes from here. The numbers below fix it.
		var border_quads: Array = Walls.border_quads(chapter_cells, chapter_meshes, 14.5)
		_check(border_quads.size() == 162,
			"the chapter has 162 faces of the borders, got %d" % border_quads.size())
		var flat_faces: int = all_quads.size() - cliffs.size() - border_quads.size()
		_check(flat_faces == 106,
			"the chapter has 106 faces of the flat pairs, got %d" % flat_faces)

		# The face against the free ground of the map ends exactly at the level
		# of the ground plane of the map. The original draws that plane at the
		# world Z 14.5 (FUN_004cca20), and the base layer of the scene draws it
		# there too, so the wall has to meet the plane without a step.
		var chapter_index: Dictionary = {}
		var flags_by_cell: Dictionary = {}
		for entry: Dictionary in chapter_cells:
			var key := Vector2i(int(entry["x"]), int(entry["y"]))
			chapter_index[key] = true
			flags_by_cell[key] = int(entry.get("flags", 0))
		var against_the_ground: int = 0
		var wrong_top: int = 0
		var void_faces: int = 0
		var void_too_high: int = 0
		for quad: Dictionary in all_quads:
			var cell: Vector2i = quad["cell"]
			var side: int = int(quad["side"])
			var other: Vector2i = Walls.neighbour(cell, side)
			if not chapter_index.has(other) and Walls.inside_map(other):
				against_the_ground += 1
				if absf(float(quad["upper"]) - 14.5) > 0.0001:
					wrong_top += 1
			# The void around the island: its cliff is the slope of the block
			# itself, so the module builds no wall of seven and a half units on
			# that border.
			if int(flags_by_cell.get(cell, 0)) != 0x85 \
					and int(flags_by_cell.get(other, 0)) != 0x85:
				continue
			void_faces += 1
			if float(quad["height"]) > 1.5 + 0.0001:
				void_too_high += 1
		_check(against_the_ground > 0,
			"the chapter has faces against the ground of the map")
		_check(wrong_top == 0,
			"every face against the ground of the map ends at the level of the ground plane, got %d wrong"
				% wrong_top)
		_check(void_faces == 5,
			"the border of the void carries five faces of the module, got %d" % void_faces)
		_check(void_too_high == 0,
			"the border of the void carries no cliff of the island, got %d faces above 1.5"
				% void_too_high)

	# --- a step that the exporter split into two ramps -----------------------
	# The lower edge of the step lies in the plane y = 0.5. The first ramp
	# drops two units, the second one only one: the step reaches the threshold
	# of the engine and is drawn as a whole, so that it has no gap in it.
	var split_mesh: Array = [
		_quad(14.5), _quad(12.5),
		_tri(Vector3(0.0, 0.5, 12.5), Vector3(0.5, 0.5, 12.5), Vector3(0.0, 0.25, 14.5)),
		_tri(Vector3(0.5, 0.5, 12.5), Vector3(1.0, 0.5, 12.5), Vector3(0.5, 0.25, 13.5)),
	]
	var split_cells: Array = [_cell(0, 0, 9)]
	var split_cliffs: Array = Walls.cliff_quads(split_cells, {"9": split_mesh})
	_check(split_cliffs.size() == 2,
		"a step that is split into two ramps is one wall of two parts, got %d" % split_cliffs.size())
	var split_spans: Array = []
	for quad: Dictionary in split_cliffs:
		var corners_value: Array = quad["corners"]
		split_spans.append([minf((corners_value[0] as Vector3).x, (corners_value[1] as Vector3).x),
			maxf((corners_value[0] as Vector3).x, (corners_value[1] as Vector3).x),
			float(quad["lower"]), float(quad["upper"])])
		split_spans.sort_custom(func(a: Array, b: Array) -> bool: return float(a[0]) < float(b[0]))
	if split_spans.size() == 2:
		_check(absf(float((split_spans[0] as Array)[0])) < 0.0001
			and absf(float((split_spans[0] as Array)[1]) - 0.5) < 0.0001,
			"the first part of the wall covers the first half of the side")
		_check(absf(float((split_spans[1] as Array)[0]) - 0.5) < 0.0001
			and absf(float((split_spans[1] as Array)[1]) - 1.0) < 0.0001,
			"the second part of the wall follows it without a gap")
		_check(absf(float((split_spans[1] as Array)[3]) - 13.5) < 0.0001,
			"the part of the step that is lower than the threshold is drawn as well")

	# --- a step that stays below the threshold ------------------------------
	var low_mesh: Array = [
		_quad(14.5), _quad(12.5),
		_tri(Vector3(0.0, 0.5, 12.5), Vector3(0.5, 0.5, 12.5), Vector3(0.0, 0.25, 14.0)),
		_tri(Vector3(0.5, 0.5, 12.5), Vector3(1.0, 0.5, 12.5), Vector3(0.5, 0.25, 13.0)),
	]
	var low_cliffs: Array = Walls.cliff_quads([_cell(0, 0, 10)], {"10": low_mesh})
	_check(low_cliffs.is_empty(), "a step below the threshold of the engine gets no wall")

	# --- a step of the rock of the map ---------------------------------------
	# The rock of the map is not an excavation: its step stands on the rock
	# itself and not on the floor of the excavation.
	var rock_mesh: Array = [
		_quad(14.5), _quad(12.5),
		_tri(Vector3(0.0, 0.5, 7.0), Vector3(0.5, 0.5, 7.0), Vector3(0.0, 0.25, 14.5)),
	]
	var rock_cliffs: Array = Walls.cliff_quads([_cell(0, 0, 11)], {"11": rock_mesh})
	_check(rock_cliffs.is_empty(), "a step of the rock of the map gets no wall")

	# --- a cell without a flat patch ------------------------------------------
	# A cell whose mesh carries no horizontal patch is a steep slope inside one
	# cell. It has no flat profile, so the pair of the flat profiles cannot
	# build the face against it, and the border of such a cell stays open.
	var slope: Array = [_tri(Vector3(0.0, 0.0, 13.0), Vector3(0.0, 1.0, 11.0),
		Vector3(1.0, 0.5, 12.0))]
	var slope_cells: Array = [_cell(20, 10, 12), _cell(21, 10, 13)]
	var slope_meshes: Dictionary = {"12": [_quad(14.5)], "13": slope}
	var slope_quads: Array = Walls.relief_quads(slope_cells, slope_meshes, 14.5)
	var slope_faces: Array = []
	for quad: Dictionary in slope_quads:
		if quad["cell"] == Vector2i(21, 10) and int(quad["side"]) == Walls.SIDE_NEG_X:
			slope_faces.append(quad)
	_check(slope_faces.size() == 1,
		"a cell without a flat patch gets one face against its neighbour, got %d" % slope_faces.size())
	if slope_faces.size() == 1:
		var slope_face: Dictionary = slope_faces[0]
		var slope_corners: Array = slope_face["corners"]
		_check(absf((slope_corners[0] as Vector3).z - 13.0) < 0.0001
			and absf((slope_corners[1] as Vector3).z - 11.0) < 0.0001,
			"the lower edge of the face follows the slope of the neighbour")
		_check(absf((slope_corners[2] as Vector3).z - 14.5) < 0.0001
			and absf((slope_corners[3] as Vector3).z - 14.5) < 0.0001,
			"the upper edge of the face is at the level of the flat neighbour")
		_check(absf(float(slope_face["height"]) - 3.5) < 0.0001,
			"the face is as high as the gap between the two surfaces")
		var slope_normal: Vector3 = slope_face["normal"]
		_check(absf(slope_normal.x - 1.0) < 0.0001 and absf(slope_normal.y) < 0.0001,
			"the normal of the face points into the lower side")
		var slope_facing: Vector3 = ((slope_corners[1] as Vector3) - (slope_corners[0] as Vector3)) \
			.cross((slope_corners[2] as Vector3) - (slope_corners[0] as Vector3))
		_check(slope_facing.dot(slope_normal) > 0.0,
			"the winding of the face shows it from the lower side")

	# --- the levels of the terrain -------------------------------------------
	_check(absf(Walls.cliff_floor_level({int(14.5 * 1024.0): 100, int(12.5 * 1024.0): 40,
		int(7.0 * 1024.0): 30}) - 12.5) < 0.0001,
		"the floor of the excavation is the level that most of the cells below the surface carry")
	_check(absf(Walls.cliff_floor_level({int(14.5 * 1024.0): 100, int(7.0 * 1024.0): 30}) - 7.0) < 0.0001,
		"a chapter without an excavation stands on the level below the surface")

	if _failures.is_empty():
		print("NATIVE_CAMPAIGN_WALLS_SELF_TEST_OK assertions=%d" % _checks)
	else:
		printerr("NATIVE_CAMPAIGN_WALLS_SELF_TEST_FAIL failures=%d" % _failures.size())
	quit(0 if _failures.is_empty() else 1)
