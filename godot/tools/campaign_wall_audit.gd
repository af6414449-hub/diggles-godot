extends SceneTree
## --headless --path godot --script res://tools/campaign_wall_audit.gd -- x y width height [row]
## Audit of the excavation walls of the campaign chapter.
##
## The region of the map is given as x y width height (the origin and the size
## of a rectangle of cells), not as the two corners of it.
##
## The chapter terrain is a height field: the blocks of the export carry the
## horizontal patches of the surface and the steep ramps between two levels,
## but no vertical face in the planes x = const at all (the export has 9851
## vertical faces in the planes y = const and none in the planes x = const).
## The walls module rebuilds the missing faces from the height field.
##
## The counts of the whole chapter (15709 cells, measured with this tool):
##   42857 horizontal patches, 9851 vertical faces (y = const), 47990 ramps
##   with a total height of 45437.5 units. The ramps are a steep face, not a
##   cliff: the wall of an excavation is a separate face of the walls module.
##
## This tool measures both halves on one region of the map:
##   - the faces the walls module builds (res://scripts/native_campaign_walls.gd),
##   - the ramps and the vertical faces the export carries itself,
## so that a gap between the rebuilt wall and the exported terrain is visible
## as a number and not as an opinion.
##
## Every line of the output says what it counts: "region_" for the cells of the
## given rectangle, "chapter_" for the whole chapter.
const Walls = preload("res://scripts/native_campaign_walls.gd")
const CHAPTER_PATH: String = "res://models/native_campaign_chapter.json"
const ROCK_MASK_PATH: String = "res://models/native_campaign_ground_mask.json"


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var bounds: Rect2i = Rect2i(236, 34, 272, 50)
	if args.size() >= 4:
		bounds = Rect2i(int(args[0]), int(args[1]), int(args[2]), int(args[3]))
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(CHAPTER_PATH))
	if not decoded is Dictionary:
		printerr("WALL_AUDIT_FAIL chapter manifest is missing")
		quit(1)
		return
	var chapter: Dictionary = decoded
	var cells: Array = chapter["cells"]
	var meshes: Dictionary = chapter["meshes"]

	var inside: Array = []
	for entry: Dictionary in cells:
		var cell := Vector2i(int(entry["x"]), int(entry["y"]))
		if bounds.has_point(cell):
			inside.append(entry)
	print("WALL_AUDIT region_rect=%s region_cells=%d" % [str(bounds), inside.size()])

	# --- the free rock of the map in the region -------------------------------
	# The cells of the region that the chapter does not cover are the free rock
	# of the map (the plan of it is in the save, its heights the engine
	# regenerates). They belong to the ground and the rock body of the scene,
	# not to the walls module.
	var rock_cells: int = 0
	var free_cells: int = 0
	var mask: PackedByteArray = _rock_mask()
	var covered: Dictionary = {}
	for entry: Dictionary in inside:
		covered[Vector2i(int(entry["x"]), int(entry["y"]))] = true
	for row in range(bounds.position.y, bounds.position.y + bounds.size.y):
		for column in range(bounds.position.x, bounds.position.x + bounds.size.x):
			if covered.has(Vector2i(column, row)):
				continue
			free_cells += 1
			if _mask_has_rock(mask, column, row):
				rock_cells += 1
	print("WALL_AUDIT region_free_cells=%d region_free_rock_cells=%d" % [free_cells, rock_cells])

	# --- the faces of the walls module ---------------------------------------
	var ground_level: float = _ground_level(cells, meshes)
	# The whole chapter is needed: a cell outside the region would be read as a
	# free cell of the base layer, and the faces of the border would be wrong.
	var quads: Array = Walls.relief_quads(cells, meshes, ground_level)
	# The whole list is kept: a face of the module belongs to the lower side of
	# a border, so the face that closes a border can lie on the neighbour cell
	# outside the region.
	var quads_all: Array = quads
	var in_region: Array = []
	for quad: Dictionary in quads:
		if bounds.has_point(quad["cell"]):
			in_region.append(quad)
	quads = in_region
	# --- the dump of the faces of the module ----------------------------------
	# The measure of the tone of a face needs to know where the face is on the
	# screen, and the faces of the module are not the faces of the export: the
	# dump gives the corners of every face of the module in the space of the
	# cell, so that a tool can project them into a capture of the scene.
	for argument in args:
		if argument.begins_with("--dump="):
			_dump_quads(quads_all, argument.substr(7))
	# The index of the cells of the whole chapter: a neighbour outside the
	# region can still be a cell of the chapter.
	var chapter_index: Dictionary = {}
	for entry: Dictionary in cells:
		chapter_index[Vector2i(int(entry["x"]), int(entry["y"]))] = true
	print("WALL_AUDIT region_module_faces=%d ground_level=%.2f" % [quads.size(), ground_level])
	var by_side: Dictionary = {}
	var total_width: float = 0.0
	var widths: Array[float] = []
	for quad: Dictionary in quads:
		var key: Vector2i = quad["cell"]
		var side: int = int(quad["side"])
		var side_key := "%s|%d" % [str(key), side]
		if not by_side.has(side_key):
			by_side[side_key] = []
		(by_side[side_key] as Array).append(quad)
		var corners: Array = quad["corners"]
		var along: float = absf((corners[1] as Vector3).y - (corners[0] as Vector3).y)
		if side == 2 or side == 3:
			along = absf((corners[1] as Vector3).x - (corners[0] as Vector3).x)
		widths.append(along)
		total_width += along
	print("WALL_AUDIT region_module_faces_sides=%d region_total_width=%.2f" % [by_side.size(), total_width])
	var by_planes: Dictionary = {0: 0, 1: 0, 2: 0, 3: 0}
	for quad: Dictionary in quads:
		by_planes[int(quad["side"])] = int(by_planes[int(quad["side"])]) + 1
	print("WALL_AUDIT region_module_by_side x+=%d x-=%d y+=%d y-=%d in_x_const=%d in_y_const=%d" % [
		int(by_planes[0]), int(by_planes[1]), int(by_planes[2]), int(by_planes[3]),
		int(by_planes[0]) + int(by_planes[1]), int(by_planes[2]) + int(by_planes[3])])
	if not widths.is_empty():
		var minimum: float = widths.min()
		var maximum: float = widths.max()
		var average: float = total_width / float(widths.size())
		print("WALL_AUDIT region_module_face_width min=%.3f avg=%.3f max=%.3f" % [minimum, average, maximum])

	# --- the height of the faces ----------------------------------------------
	var height_histogram: Dictionary = {}
	for quad: Dictionary in quads:
		var bucket: int = int(round(float(quad["height"]) * 2.0))
		height_histogram[bucket] = int(height_histogram.get(bucket, 0)) + 1
	var height_keys: Array = height_histogram.keys()
	height_keys.sort()
	for key: int in height_keys:
		print("WALL_AUDIT region_module_face_height %.1f count=%d" % [float(key) * 0.5,
			int(height_histogram[key])])

	# --- the edge of the island ----------------------------------------------
	# The cells with the flag 0x85 carry no block of the chapter: they are the
	# void around the island, and their mesh is the floor of the base map at
	# the level 7.0. The cliff between the island and the void stands on the
	# border of two cells of the chapter, so the walls module builds it.
	var flags_by_cell: Dictionary = {}
	for entry: Dictionary in cells:
		flags_by_cell[Vector2i(int(entry["x"]), int(entry["y"]))] = int(entry.get("flags", 0))
	var void_edges: int = 0
	var void_edge_height: Dictionary = {}
	var void_edge_width: float = 0.0
	for quad: Dictionary in quads:
		var cell: Vector2i = quad["cell"]
		var side: int = int(quad["side"])
		var other: Vector2i = Walls.neighbour(cell, side)
		if int(flags_by_cell.get(cell, 0)) != 0x85 and int(flags_by_cell.get(other, 0)) != 0x85:
			continue
		void_edges += 1
		var bucket: int = int(round(float(quad["height"]) * 2.0))
		void_edge_height[bucket] = int(void_edge_height.get(bucket, 0)) + 1
		var corners: Array = quad["corners"]
		var along: float = absf((corners[1] as Vector3).y - (corners[0] as Vector3).y)
		if side == 2 or side == 3:
			along = absf((corners[1] as Vector3).x - (corners[0] as Vector3).x)
		void_edge_width += along
	print("WALL_AUDIT region_island_edge_faces=%d region_island_edge_width=%.2f" % [void_edges, void_edge_width])
	var void_keys: Array = void_edge_height.keys()
	void_keys.sort()
	for key: int in void_keys:
		print("WALL_AUDIT region_island_edge_height %.1f count=%d" % [float(key) * 0.5,
			int(void_edge_height[key])])

	# --- the tall faces: where the cliff of the island stands ------------------
	var tall: int = 0
	var tall_at_row_zero: int = 0
	var tall_samples: Array = []
	for quad: Dictionary in quads:
		if float(quad["height"]) < 5.0:
			continue
		tall += 1
		var cell: Vector2i = quad["cell"]
		if int(cell.y) == 0:
			tall_at_row_zero += 1
		if tall_samples.size() < 24:
			tall_samples.append("%s side %d height %.2f lower %.2f upper %.2f" % [
				str(cell), int(quad["side"]), float(quad["height"]),
				float(quad["lower"]), float(quad["upper"])])
	print("WALL_AUDIT region_tall_faces=%d region_tall_faces_at_row_zero=%d" % [tall, tall_at_row_zero])
	for line: String in tall_samples:
		print("WALL_AUDIT tall %s" % line)

	# --- the coverage of every side ------------------------------------------
	# The parts of a side that no face covers are not holes: a side between two
	# cells of the same height needs no wall at all. The holes are counted
	# below, where a face is needed.
	var gaps: int = 0
	for side_key: String in by_side:
		var list: Array = by_side[side_key]
		var spans: Array = []
		for quad: Dictionary in list:
			spans.append(_quad_span(quad, int(quad["side"])))
		spans.sort_custom(func(a: Array, b: Array) -> bool: return float(a[0]) < float(b[0]))
		var cursor: float = 0.0
		for span: Array in spans:
			if float(span[0]) - cursor > 0.0001:
				gaps += 1
			cursor = maxf(cursor, float(span[1]))
		if cursor < 0.9999:
			gaps += 1
	print("WALL_AUDIT region_module_uncovered_side_parts=%d" % gaps)

	# --- the holes of the borders --------------------------------------------
	# A border of two cells is a hole in the rock when the two surfaces of the
	# border differ and no face stands in the gap. The face of the module closes
	# it, and so does a vertical face of the export itself: the export carries
	# its faces in the planes y = const, so a border in the plane x = const has
	# no face of the export and the module has to build one.
	var needed: int = 0
	var closed_by_module: int = 0
	var closed_by_export: int = 0
	var closed_by_both: int = 0
	var holes: int = 0
	var void_needed: int = 0
	var void_closed_module: int = 0
	var void_closed_export: int = 0
	var void_holes: int = 0
	var void_max_height: float = 0.0
	var hole_list: Array = []
	var surfaces: Dictionary = Walls.surface_profiles(cells, meshes)
	var export_faces: Dictionary = _export_faces(cells, meshes)
	var export_border_faces: int = 0
	for cell: Vector2i in export_faces:
		for side: int in (export_faces[cell] as Dictionary):
			export_border_faces += ((export_faces[cell] as Dictionary)[side] as Array).size()
	print("WALL_AUDIT chapter_export_border_faces=%d" % export_border_faces)
	var coverage: Dictionary = _face_spans(quads_all)
	for entry: Dictionary in inside:
		var cell := Vector2i(int(entry["x"]), int(entry["y"]))
		for side in range(4):
			var other_cell: Vector2i = Walls.neighbour(cell, side)
			var free_side: bool = not chapter_index.has(other_cell)
			if free_side and not Walls.inside_map(other_cell):
				# Beyond the edge of the map there is neither ground nor rock.
				continue
			var here: Array = (surfaces[cell] as Dictionary)[side] as Array
			if here.is_empty():
				continue
			var other: Array = []
			if free_side:
				other = [[0.0, 1.0, ground_level, ground_level]]
			else:
				other = (surfaces[other_cell] as Dictionary)[Walls.opposite_side(side)] as Array
				if other.is_empty():
					continue
			var marks: Array = []
			for segment: Array in here + other:
				for value: float in [float(segment[0]), float(segment[1])]:
					if marks.is_empty() or absf(float(marks[marks.size() - 1]) - value) > 0.0001:
						marks.append(value)
			marks.sort()
			for index in range(0, marks.size() - 1):
				var start: float = float(marks[index])
				var stop: float = float(marks[index + 1])
				if stop - start <= 0.0001:
					continue
				var middle: float = (start + stop) * 0.5
				var level_here: float = Walls.surface_height(here, middle)
				var level_other: float = Walls.surface_height(other, middle)
				if is_nan(level_here) or is_nan(level_other):
					continue
				if absf(level_here - level_other) < Walls.MIN_WALL_HEIGHT:
					# The two surfaces meet: no wall is needed here.
					continue
				needed += 1
				# The border of the void around the island: the cliff between the
				# rock of the chapter and the void of the base map.
				var at_void: bool = int(flags_by_cell.get(cell, 0)) == 0x85 \
						or int(flags_by_cell.get(other_cell, 0)) == 0x85
				if at_void:
					void_needed += 1
					var span_height: float = absf(level_here - level_other)
					void_max_height = maxf(void_max_height, span_height)
				var by_module: bool = _spans_cover(coverage, cell, side, middle) \
						or (not free_side and _spans_cover(coverage, other_cell,
							Walls.opposite_side(side), middle))
				var by_export: bool = _export_covers(export_faces, cell, side, other_cell,
					free_side, middle, minf(level_here, level_other), maxf(level_here, level_other))
				if by_module and by_export:
					closed_by_both += 1
					if at_void:
						void_closed_module += 1
					continue
				if by_module:
					closed_by_module += 1
					if at_void:
						void_closed_module += 1
					continue
				if by_export:
					closed_by_export += 1
					if at_void:
						void_closed_export += 1
					continue
				holes += 1
				if at_void:
					void_holes += 1
				hole_list.append("%s|%d %.3f..%.3f %6.3f/%6.3f" % [str(cell), side, start, stop,
					level_here, level_other])
	print("WALL_AUDIT region_border_intervals_needed=%d region_closed_by_module=%d region_closed_by_export=%d region_closed_by_both=%d region_holes=%d" %
		[needed, closed_by_module, closed_by_export, closed_by_both, holes])
	print("WALL_AUDIT region_void_border_needed=%d region_void_closed_by_module=%d region_void_closed_by_export=%d region_void_holes=%d region_void_max_height=%.2f" %
		[void_needed, void_closed_module, void_closed_export, void_holes, void_max_height])
	for line: String in hole_list:
		print("WALL_AUDIT hole %s" % line)

	# --- the geometry the export carries itself ------------------------------
	var horizontal: int = 0
	var vertical: int = 0
	var ramp: int = 0
	var ramp_span: float = 0.0
	var ramp_height: float = 0.0
	for entry: Dictionary in inside:
		for part: Dictionary in meshes.get(str(int(entry["block"])), []):
			var values: Array = part["vertices"]
			var indices: Array = part["indices"]
			for triangle_start in range(0, indices.size(), 3):
				var points: Array[Vector3] = []
				for corner in range(3):
					var offset: int = int(indices[triangle_start + corner]) * 5
					points.append(Vector3(float(values[offset]), float(values[offset + 1]),
						float(values[offset + 2])))
				var low: float = points[0].z
				var high: float = points[0].z
				for point: Vector3 in points:
					low = minf(low, point.z)
					high = maxf(high, point.z)
				if high - low <= 0.0001:
					horizontal += 1
					continue
				var flat_x: bool = true
				var flat_y: bool = true
				for point: Vector3 in points:
					if absf(point.x - points[0].x) > 0.0001:
						flat_x = false
					if absf(point.y - points[0].y) > 0.0001:
						flat_y = false
				if flat_x or flat_y:
					vertical += 1
				else:
					ramp += 1
					ramp_span += 1.0
					ramp_height += high - low
	print("WALL_AUDIT region_export_horizontal=%d region_export_vertical=%d region_export_ramps=%d region_ramp_height_sum=%.1f" %
		[horizontal, vertical, ramp, ramp_height])

	# --- the height of the ramps: a steep face or a micro step of the relief --
	# The counts of this block belong to the whole chapter, not to the region.
	# The heights of the export are multiples of 0.5, so the histogram has the
	# step of 0.5 and not the step of 1.0 of the earlier version.
	var histogram: Dictionary = {}
	var steep_ramps: int = 0
	var cliff_ramps: int = 0
	var cliff_by_height: Dictionary = {}
	for entry: Dictionary in cells:
		for part: Dictionary in meshes.get(str(int(entry["block"])), []):
			var values: Array = part["vertices"]
			var indices: Array = part["indices"]
			for triangle_start in range(0, indices.size(), 3):
				var points: Array[Vector3] = []
				for corner in range(3):
					var offset: int = int(indices[triangle_start + corner]) * 5
					points.append(Vector3(float(values[offset]), float(values[offset + 1]),
						float(values[offset + 2])))
				var low: float = points[0].z
				var high: float = points[0].z
				for point: Vector3 in points:
					low = minf(low, point.z)
					high = maxf(high, point.z)
				var height: float = high - low
				if height <= 0.0001:
					continue
				var flat_x: bool = true
				var flat_y: bool = true
				for point: Vector3 in points:
					if absf(point.x - points[0].x) > 0.0001:
						flat_x = false
					if absf(point.y - points[0].y) > 0.0001:
						flat_y = false
				if flat_x or flat_y:
					continue
				var bucket: int = int(round(height * 2.0))
				histogram[bucket] = int(histogram.get(bucket, 0)) + 1
				if height >= 1.0:
					steep_ramps += 1
				if height >= Walls.CLIFF_HEIGHT:
					cliff_ramps += 1
					var key := "%d,%d" % [int(entry["x"]), int(entry["y"])]
					cliff_by_height[key] = int(cliff_by_height.get(key, 0)) + 1
	var keys: Array = histogram.keys()
	keys.sort()
	for key: int in keys:
		print("WALL_AUDIT chapter_ramp_height %.1f count=%d" % [float(key) * 0.5, int(histogram[key])])
	print("WALL_AUDIT chapter_ramps_ge_1=%d chapter_ramps_ge_2=%d chapter_cells_with_ramps_ge_2=%d" %
		[steep_ramps, cliff_ramps, cliff_by_height.size()])

	# --- the ramps of one row ------------------------------------------------
	if args.size() >= 5:
		var row: int = int(args[4])
		print("WALL_AUDIT row=%d" % row)
		for entry: Dictionary in inside:
			if int(entry["y"]) != row:
				continue
			var cell_x: int = int(entry["x"])
			var spans: Array = []
			for part: Dictionary in meshes.get(str(int(entry["block"])), []):
				var values: Array = part["vertices"]
				var indices: Array = part["indices"]
				for triangle_start in range(0, indices.size(), 3):
					var points: Array[Vector3] = []
					for corner in range(3):
						var offset: int = int(indices[triangle_start + corner]) * 5
						points.append(Vector3(float(values[offset]), float(values[offset + 1]),
							float(values[offset + 2])))
					var low: float = points[0].z
					var high: float = points[0].z
					for point: Vector3 in points:
						low = minf(low, point.z)
						high = maxf(high, point.z)
					if high - low <= 0.0001:
						continue
					var y0: float = points[0].y
					var y1: float = points[1].y
					var x0: float = points[0].x
					var x1: float = points[1].x
					spans.append("x%.2f-%.2f y%.2f-%.2f z%.1f-%.1f" % [x0, x1, y0, y1, low, high])
			print("WALL_AUDIT cell x=%d %s" % [cell_x, str(spans)])
	quit(0)


## The vertical faces of the export itself, per cell and side.
##
## The export carries its vertical faces in the planes y = const and in none of
## the planes x = const. A face on the border of a cell closes that border, so
## the module must not build a second one there.
##
## The result is {cell: {side: [[t0, t1, low, high], ...]}}, where t runs along
## the side of the cell from 0 to 1.
func _export_faces(cells: Array, meshes: Dictionary) -> Dictionary:
	var result: Dictionary = {}
	for entry: Dictionary in cells:
		var cell := Vector2i(int(entry["x"]), int(entry["y"]))
		var sides: Dictionary = {0: [], 1: [], 2: [], 3: []}
		for part: Dictionary in meshes.get(str(int(entry["block"])), []):
			var values: Array = part["vertices"]
			var indices: Array = part["indices"]
			for triangle_start in range(0, indices.size(), 3):
				var points: Array[Vector3] = []
				for corner in range(3):
					var offset: int = int(indices[triangle_start + corner]) * 5
					points.append(Vector3(float(values[offset]), float(values[offset + 1]),
						float(values[offset + 2])))
				var low: float = points[0].z
				var high: float = points[0].z
				for point: Vector3 in points:
					low = minf(low, point.z)
					high = maxf(high, point.z)
				if high - low <= 0.0001:
					# A horizontal patch is the surface of the terrain.
					continue
				var flat_x: bool = true
				var flat_y: bool = true
				for point: Vector3 in points:
					if absf(point.x - points[0].x) > 0.0001:
						flat_x = false
					if absf(point.y - points[0].y) > 0.0001:
						flat_y = false
				if not flat_x and not flat_y:
					# A ramp is a slope, not a face.
					continue
				var side: int = -1
				var t0: float = 0.0
				var t1: float = 0.0
				if flat_y:
					if absf(points[0].y) <= 0.0001:
						side = Walls.SIDE_NEG_Y
					elif absf(points[0].y - 1.0) <= 0.0001:
						side = Walls.SIDE_POS_Y
					else:
						# Inside the cell.
						continue
					t0 = minf(minf(points[0].x, points[1].x), points[2].x)
					t1 = maxf(maxf(points[0].x, points[1].x), points[2].x)
				else:
					if absf(points[0].x) <= 0.0001:
						side = Walls.SIDE_NEG_X
					elif absf(points[0].x - 1.0) <= 0.0001:
						side = Walls.SIDE_POS_X
					else:
						continue
					t0 = minf(minf(points[0].y, points[1].y), points[2].y)
					t1 = maxf(maxf(points[0].y, points[1].y), points[2].y)
				(sides[side] as Array).append([t0, t1, low, high])
		result[cell] = sides
	return result


## The spans of the faces of the module, per cell and side.
##
## The result is {cell: {side: [[t0, t1], ...]}}, where t runs along the side of
## the cell from 0 to 1.
func _face_spans(quads: Array) -> Dictionary:
	var result: Dictionary = {}
	for quad: Dictionary in quads:
		var cell: Vector2i = quad["cell"]
		var side: int = int(quad["side"])
		if not result.has(cell):
			result[cell] = {}
		if not (result[cell] as Dictionary).has(side):
			(result[cell] as Dictionary)[side] = []
		((result[cell] as Dictionary)[side] as Array).append(_quad_span(quad, side))
	return result


## The span of a face along its side, from 0 to 1.
func _quad_span(quad: Dictionary, side: int) -> Array:
	var corners: Array = quad["corners"]
	var start: float = 0.0
	var stop: float = 0.0
	if side == Walls.SIDE_POS_X or side == Walls.SIDE_NEG_X:
		for corner: Vector3 in corners:
			start = minf(start, corner.y)
			stop = maxf(stop, corner.y)
	else:
		for corner: Vector3 in corners:
			start = minf(start, corner.x)
			stop = maxf(stop, corner.x)
	return [minf(start, stop), maxf(start, stop)]


## Whether a face of the module covers the position of a side.
func _spans_cover(coverage: Dictionary, cell: Vector2i, side: int, position: float) -> bool:
	if not coverage.has(cell):
		return false
	var sides: Dictionary = coverage[cell]
	if not sides.has(side):
		return false
	for span: Array in sides[side] as Array:
		if float(span[0]) - 0.0001 <= position and position <= float(span[1]) + 0.0001:
			return true
	return false


## Whether a vertical face of the export closes the border.
##
## The face of the export stands on the border of the cell or on the border of
## the neighbour, and it has to cover the whole gap of the two surfaces.
func _export_covers(export_faces: Dictionary, cell: Vector2i, side: int,
		other_cell: Vector2i, free_side: bool, position: float,
		low: float, high: float) -> bool:
	var lists: Array = []
	if export_faces.has(cell):
		lists.append((export_faces[cell] as Dictionary)[side] as Array)
	if not free_side and export_faces.has(other_cell):
		lists.append((export_faces[other_cell] as Dictionary)[Walls.opposite_side(side)] as Array)
	for list: Array in lists:
		for span: Array in list:
			if float(span[0]) - 0.0001 > position or position > float(span[1]) + 0.0001:
				continue
			if float(span[2]) - 0.0001 <= low and high <= float(span[3]) + 0.0001:
				return true
	return false


func _ground_level(cells: Array, meshes: Dictionary) -> float:
	var highest: float = -INF
	for entry: Dictionary in cells:
		for part: Dictionary in meshes.get(str(int(entry["block"])), []):
			var values: Array = part["vertices"]
			for index in range(0, values.size(), 5):
				highest = maxf(highest, float(values[index + 2]))
	return highest


## The plan of the free rock of the map, read from the save of the original.
## The same source as the scene uses (res://models/native_campaign_ground_mask.json).
func _rock_mask() -> PackedByteArray:
	var mask := PackedByteArray()
	mask.resize(512 * 640)
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(ROCK_MASK_PATH))
	if not decoded is Dictionary:
		return mask
	var index: int = 0
	for run: Array in (decoded as Dictionary).get("runs", []):
		var value: int = int(run[0])
		var count: int = int(run[1])
		for step in range(count):
			if index >= mask.size():
				break
			mask[index] = value
			index += 1
	return mask


## Whether the cell of the map carries the free rock of the original.
func _mask_has_rock(mask: PackedByteArray, x: int, y: int) -> bool:
	if x < 0 or y < 0 or x >= 512 or y >= 640:
		return false
	return mask[y * 512 + x] != 0


## The faces of the module as a JSON file: the cell, the side and the four
## corners of every face, in the space of the cell.  A measure of the tone of a
## face needs the place of the face on the screen, and only the module knows
## where its faces are.
func _dump_quads(quads: Array, path: String) -> void:
	var entries: Array = []
	for quad: Dictionary in quads:
		var cell: Vector2i = quad["cell"]
		var corners: Array = quad["corners"]
		var values: Array = []
		for corner: Vector3 in corners:
			values.append([corner.x, corner.y, corner.z])
		entries.append({
			"cell": [cell.x, cell.y],
			"side": int(quad["side"]),
			"height": float(quad["height"]),
			"corners": values,
		})
	var file := FileAccess.open(path, FileAccess.WRITE)
	if file == null:
		printerr("WALL_AUDIT_FAIL the dump file cannot be written: %s" % path)
		return
	file.store_string(JSON.stringify({"faces": entries}))
	file.close()
	print("WALL_AUDIT dump_faces=%d dump_path=%s" % [entries.size(), path])