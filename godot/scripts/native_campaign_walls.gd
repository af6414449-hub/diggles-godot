extends RefCounted
## The excavation walls of the campaign chapter.
##
## The exported chapter keeps the horizontal patches of every block: the ground
## surface of the untouched rock and the floor of a dug tunnel. The blocks of
## the original carry the vertical faces only in one direction - the export has
## no face in a plane x = constant at all - so the faces between two cells of
## different height are missing and a tunnel reads as a flat sheet in the
## background instead of a hole in the rock.
##
## This module rebuilds those faces from the height field of the chapter. There
## are three kinds of face:
##
##   - the face of a pair of flat cells, built from the flat profiles of the two
##     sides (the horizontal patches of the blocks);
##   - the face of a cliff, built from the ramps of a cell (see cliff_quads);
##   - the face of a border, built from the surface of the two sides - the flat
##     patches and the ramps of the cell (see border_quads).
##
## The third kind is needed because a cell without a flat patch is a steep slope
## inside one cell: it has no flat profile, so the pair of the flat profiles
## cannot build the face against it, and the border of such a cell stays open.
## The export carries no vertical face in the planes x = constant, so nobody
## else closes it either and the rock shows the background of the scene through
## the gap.
##
## ADAPTER: the geometry is derived from the exported cell heights, the texture
## and the detail slot of the higher cell. The base layer of the map, which the
## original creates with map create, is not part of the export: the free cells
## of the map are read as the ground level. Beyond the edge of the map there is
## neither ground nor rock, so a face is not built there at all.
##
## FACT (Diggles.exe): the engine draws the ground of the map as one polygon per
## run of free cells, at the world Z 14.5 - the same level as the surface of the
## chapter (FUN_004cca20: the height of every vertex of that polygon is the
## float 0x41680000, which is 14.5; the same value is the ground of the engine
## everywhere else - the placement of the objects, the clamp of the height of a
## dwarf, the ground polygon of the battle scene). So the free cells of the map
## are at the level of the surface of the chapter, and a face against them ends
## exactly at that level.
##
## FACT (Diggles.exe): the engine builds a wall only where a cell of the chapter
## is dug out; the border of the rectangle of a template is not a wall by
## itself. The port has no marks of the excavation in the export, so it rebuilds
## the faces from the height field: the face of a dug cell is exactly the face
## where its height differs from the height of the neighbour. The free cells of
## the map are at the ground level, so a chapter cell below that level gets its
## wall against the free ground, and a chapter cell at that level gets none.
##
## Sources (original install, read-only):
##   data/Scripts/gameplay/Campaign.tcl:2   map create 512 640
##   data/Scripts/gameplay/Campaign.tcl:22-191   the chapter assembly
##   tools/export_campaign_chapter.py            the export of the chapter

## The rounding noise of the export is not a step of the terrain.
const EPS: float = 0.0001

## Adapter: a smaller difference is not drawn, the export rounds the heights to
## half a unit and the rounding must not become a wall.
const MIN_WALL_HEIGHT: float = 0.25

## Adapter: the height of a cliff that the original draws as a wall.
##
## The export carries the sides of the terrain as slanted ramps (47990 of them in
## the chapter, 45437 units of height in total) and as vertical faces in the
## planes y = const (9851 of them). A ramp is the transition between two levels
## of the height field: it descends over a quarter of a cell, so the cliff of an
## excavation is a slope of 82 degrees and the edge of a tunnel reads as a row
## of separate dark panels instead of one rock wall.
##
## The engine builds the walls of the map itself (see the facts below): it marks
## the face of a cell when the cell is dug out, so the cliff of an excavation is
## a wall and not a slope. The port has no such marks in the export and rebuilds
## the wall from the height field: the face stands on the lower edge of the ramp
## and covers the ramp behind it. ADAPTER: the height of the original is not in
## the export, and the placement of the face follows the lower edge of the ramp.
##
## FACT (Diggles.exe): the threshold of the engine is the drop of the step
## inside a cell: the geometry of a pit is created when the central sample of
## the 8x8 grid of the cell is at least four levels (a level is half a cell)
## below or above a corner sample of the same cell
## (FUN_004ca830:399-427, FUN_004ca080). Four levels of half a cell are 2.0
## cells, so the threshold of the module is the threshold of the engine. The
## threshold belongs to the step and not to a part of it: a step that reaches
## 2.0 is drawn as a whole.
##
## FACT (Diggles.exe): the engine has no face of forty five degrees. A wall is a
## vertical plane between two neighbours of a different height, and a face on an
## edge is built only when both ends of that edge are solid stone; a diagonal
## edge gets no face at all (FUN_004ca080:264-298). So this module does not
## build a face on a diagonal edge.
##
## FACT (BlockDB2.BDB): the slanted triangles with a diagonal lower edge (3625 of
## them in the chapter) are the geometry of the game itself - the exporter reads
## the blocks of the chapter from BlockDB2.BDB
## (tools/export_campaign_chapter.py:514). Their lower edge lies inside the
## cell: none of them is the diagonal of a cell and none lies on the border of a
## cell. They are a chamfer on the diagonal seam of a block and not the corner
## of an excavation, and the port draws them as part of the terrain mesh exactly
## as the original does.
##
## FACT (Diggles.exe): the world height of the engine is the same as the height
## of the export. The engine keeps the height of a sample of a cell as a byte
## and reads it as a level: world-Z = 7.0 + 0.5 * level, the range of the map
## is 7.0 to 14.5 cells (FUN_004c8220:33,44). The surface 14.5 of the export
## is the level 15, the floor of an excavation 12.5 is the level 11 and the
## bottom of the rock 7.0 is the level 0. The grid of 8x8 samples of a cell is
## the logical map of the engine - the support of the dwarfs, the pathfinding
## and the base light - and not the geometry of the surface.
##
## FACT (Diggles.exe): the material of a cell is in the two low bits of the
## ushort at the offset 0x18 of the record of the cell: 0 and 3 are rock, 1
## and 2 are diggable soil. The code of the material is never a mark of an
## excavation: an excavated cell keeps the material of its soil.
##
## FACT (Diggles.exe): the edge of the stone of the map is eroded at runtime as
## well. The command sm_draw_stone -border and -funnel walk the outer band of
## the cells of the map and reset the material of a cell to stone with a
## probability that falls off towards the edge, so the rim of the map is ragged
## and not a straight line. The strengths of that falloff are 4.0 and 1.0 for
## the border and 1.0 for the funnel.
const CLIFF_HEIGHT: float = 2.0

const SIDE_POS_X: int = 0
const SIDE_NEG_X: int = 1
const SIDE_POS_Y: int = 2
const SIDE_NEG_Y: int = 3

## The size of the map of the original.
##
## FACT: the original creates the map of the campaign with "map create 512 640"
## (data/Scripts/gameplay/Campaign.tcl:2). Beyond the edge of the map there is
## neither ground nor rock: the free cells of the map inside it are the rock
## around the chapter, and the wall of the original stops at the edge of the
## map. A face against the void beyond the map is an artifact of the port: at
## the northern edge of the chapter it is a granite wall of seven and a half
## units right across the mouth of the start excavation.
const MAP_WIDTH: int = 512
const MAP_HEIGHT: int = 640


## Whether a cell lies inside the map of the original.
static func inside_map(cell: Vector2i) -> bool:
	return cell.x >= 0 and cell.y >= 0 and cell.x < MAP_WIDTH and cell.y < MAP_HEIGHT

## The foot of a cliff lies in a plane of constant y: the face runs along x.
const CLIFF_PLANE_Y: int = 0
## The foot of a cliff lies in a plane of constant x: the face runs along y.
const CLIFF_PLANE_X: int = 1


## The switch of the comparison render.
##
## The flag --no-cliffs on the command line of the scene turns the faces of the
## cliffs off, so the same scene can be captured with and without them in one
## run and under the same light. It is a switch of the tool, not of the game:
## the flag is absent in a normal run and the faces are always built.
static func cliffs_enabled() -> bool:
	return not OS.get_cmdline_user_args().has("--no-cliffs")


## The neighbour cell of one side.
static func neighbour(cell: Vector2i, side: int) -> Vector2i:
	match side:
		SIDE_POS_X:
			return cell + Vector2i(1, 0)
		SIDE_NEG_X:
			return cell + Vector2i(-1, 0)
		SIDE_POS_Y:
			return cell + Vector2i(0, 1)
		_:
			return cell + Vector2i(0, -1)


## The side of a cell that faces the given side.
static func opposite_side(side: int) -> int:
	match side:
		SIDE_POS_X:
			return SIDE_NEG_X
		SIDE_NEG_X:
			return SIDE_POS_X
		SIDE_POS_Y:
			return SIDE_NEG_Y
		_:
			return SIDE_POS_Y


## The horizontal direction of a side, from the cell to its neighbour.
static func side_direction(side: int) -> Vector2i:
	match side:
		SIDE_POS_X:
			return Vector2i(1, 0)
		SIDE_NEG_X:
			return Vector2i(-1, 0)
		SIDE_POS_Y:
			return Vector2i(0, 1)
		_:
			return Vector2i(0, -1)


## The profile of every side of every cell.
##
## The result is {cell: {side: [[t0, t1, z], ...]}}, where t runs along the
## side of the cell from 0 to 1. Only the horizontal patches of a block carry
## the surface of the terrain, the vertical faces of the block are skipped.
static func side_profiles(cells: Array, meshes: Dictionary) -> Dictionary:
	var profiles: Dictionary = {}
	for entry: Dictionary in cells:
		var cell := Vector2i(int(entry["x"]), int(entry["y"]))
		var sides: Dictionary = {}
		for side in range(4):
			sides[side] = []
		for part: Dictionary in meshes.get(str(int(entry["block"])), []):
			var values: Array = part["vertices"]
			var indices: Array = part["indices"]
			for triangle_start in range(0, indices.size(), 3):
				var points: Array[Vector3] = []
				for corner in range(3):
					var offset: int = int(indices[triangle_start + corner]) * 5
					points.append(Vector3(float(values[offset]), float(values[offset + 1]),
						float(values[offset + 2])))
				if not is_flat(points):
					continue
				for corner in range(3):
					var a: Vector3 = points[corner]
					var b: Vector3 = points[(corner + 1) % 3]
					var side: int = side_of(a, b)
					if side < 0:
						continue
					var along_x: bool = side == SIDE_POS_X or side == SIDE_NEG_X
					var t0: float = a.y if along_x else a.x
					var t1: float = b.y if along_x else b.x
					(sides[side] as Array).append([minf(t0, t1), maxf(t0, t1), a.z])
		profiles[cell] = sides
	return profiles


## The surface of every side of every cell.
##
## The result is {cell: {side: [[t0, t1, z0, z1], ...]}}, where t runs along the
## side of the cell from 0 to 1. The edges of the triangles of the block that
## lie on the side give the profile: a flat patch gives a horizontal segment, a
## ramp a sloped one. The vertical face of the block gives a fold in it, and
## the highest patch wins, so the two sides of a face of the export meet.
static func surface_profiles(cells: Array, meshes: Dictionary) -> Dictionary:
	var profiles: Dictionary = {}
	for entry: Dictionary in cells:
		var cell := Vector2i(int(entry["x"]), int(entry["y"]))
		var sides: Dictionary = {}
		for side in range(4):
			sides[side] = []
		for part: Dictionary in meshes.get(str(int(entry["block"])), []):
			var values: Array = part["vertices"]
			var indices: Array = part["indices"]
			for triangle_start in range(0, indices.size(), 3):
				var points: Array[Vector3] = []
				for corner in range(3):
					var offset: int = int(indices[triangle_start + corner]) * 5
					points.append(Vector3(float(values[offset]), float(values[offset + 1]),
						float(values[offset + 2])))
				for corner in range(3):
					var a: Vector3 = points[corner]
					var b: Vector3 = points[(corner + 1) % 3]
					var side: int = side_of(a, b)
					if side < 0:
						continue
					var along_x: bool = side == SIDE_POS_X or side == SIDE_NEG_X
					var t0: float = a.y if along_x else a.x
					var t1: float = b.y if along_x else b.x
					var z0: float = a.z
					var z1: float = b.z
					if t0 > t1:
						var swap_t: float = t0
						t0 = t1
						t1 = swap_t
						var swap_z: float = z0
						z0 = z1
						z1 = swap_z
					(sides[side] as Array).append([t0, t1, z0, z1])
		profiles[cell] = sides
	return profiles


## The height of the surface along a profile at the given position.
##
## The highest patch wins: the face of the terrain is what is seen from above.
static func surface_height(profile: Array, position: float) -> float:
	var height: float = NAN
	for segment: Array in profile:
		var t0: float = float(segment[0])
		var t1: float = float(segment[1])
		if position < t0 - EPS or position > t1 + EPS:
			continue
		var value: float = float(segment[2])
		var span: float = t1 - t0
		if span > EPS:
			value += (float(segment[3]) - float(segment[2])) * (position - t0) / span
		if is_nan(height) or value > height:
			height = value
	return height


## True when the three points of a patch lie in one horizontal plane.
static func is_flat(points: Array[Vector3]) -> bool:
	for corner in range(1, points.size()):
		if absf(points[corner].z - points[0].z) > EPS:
			return false
	return true


## The side of a cell an edge of a patch lies on, or -1 when the edge is inside
## the cell or diagonal.
static func side_of(a: Vector3, b: Vector3) -> int:
	if absf(a.y - b.y) <= EPS:
		if absf(a.y) <= EPS:
			return SIDE_NEG_Y
		if absf(a.y - 1.0) <= EPS:
			return SIDE_POS_Y
		return -1
	if absf(a.x - b.x) <= EPS:
		if absf(a.x) <= EPS:
			return SIDE_NEG_X
		if absf(a.x - 1.0) <= EPS:
			return SIDE_POS_X
		return -1
	return -1


## The height of the terrain along a profile at the given position.
##
## The highest patch wins: the face of the terrain is what is seen from above.
static func level_at(profile: Array, position: float) -> float:
	var level: float = NAN
	for segment: Array in profile:
		if position >= float(segment[0]) - EPS and position <= float(segment[1]) + EPS:
			var value: float = float(segment[2])
			if is_nan(level) or value > level:
				level = value
	return level


## The vertical faces of the chapter.
##
## Every face carries the four corners in the cell space, the normal that
## points into the lower side, the cell that owns the face and the height of
## the face.
static func relief_quads(cells: Array, meshes: Dictionary, ground_level: float) -> Array:
	var profiles: Dictionary = side_profiles(cells, meshes)
	var index: Dictionary = {}
	for entry: Dictionary in cells:
		index[Vector2i(int(entry["x"]), int(entry["y"]))] = true
	var quads: Array = []
	for cell: Vector2i in profiles:
		var sides: Dictionary = profiles[cell]
		for side in range(4):
			var here: Array = sides[side]
			if here.is_empty():
				continue
			var other_cell: Vector2i = neighbour(cell, side)
			var other: Array = []
			var free_side: bool = not index.has(other_cell)
			if not free_side:
				var other_sides: Dictionary = profiles[other_cell]
				other = other_sides[opposite_side(side)] as Array
				if other.is_empty():
					continue
			elif not inside_map(other_cell):
				# Beyond the edge of the map there is no ground and no rock.
				continue
			else:
				# The free cells of the map carry the base layer of the original,
				# which the export does not keep.
				other = [[0.0, 1.0, ground_level]]
			quads.append_array(pair_profiles(cell, side, here, other, free_side))
	quads.append_array(border_quads(cells, meshes, ground_level))
	if cliffs_enabled():
		quads.append_array(cliff_quads(cells, meshes))
	return quads


## The vertical faces at the border of the cells, where the pair of the flat
## profiles cannot build them.
##
## This rule is the one of the module: the base layer of the scene builds no
## vertical face of its own, so every face of the excavation comes from here.
## The self test fixes its numbers (162 faces of the borders in the chapter, and
## the face against the free ground of the map ends at the level 14.5, the level
## of the ground plane of the map).
##
## FACT: the export carries the vertical faces of the blocks in the planes
## y = const only: 880 of them on the border of a cell and 8971 inside a cell,
## and not one in the planes x = const. A face of the export closes the border
## it stands on, and the module must not build a second one there.
##
## A cell whose mesh carries no horizontal patch is a steep slope inside one
## cell: it has no flat profile, so the pair of the flat profiles cannot build
## the face against it and the border of such a cell stays open. The surface of
## the cell along the border is known from the ramps of its mesh, and the face
## is the vertical plane between that surface and the surface of the neighbour.
##
## ADAPTER: the face of the port stands on the border of the cell and follows
## the slope of the neighbour. The engine builds the wall of a step from its
## height grid, and the grid of the port is the corner height of the cell.
static func border_quads(cells: Array, meshes: Dictionary, ground_level: float) -> Array:
	var surfaces: Dictionary = surface_profiles(cells, meshes)
	var flats: Dictionary = side_profiles(cells, meshes)
	var index: Dictionary = {}
	for entry: Dictionary in cells:
		index[Vector2i(int(entry["x"]), int(entry["y"]))] = true
	var quads: Array = []
	for cell: Vector2i in surfaces:
		var sides: Dictionary = surfaces[cell]
		var flat_sides: Dictionary = flats[cell]
		for side in range(4):
			var here: Array = sides[side]
			if here.is_empty():
				continue
			var other_cell: Vector2i = neighbour(cell, side)
			var other: Array = []
			var flat_other: Array = []
			var free_side: bool = not index.has(other_cell)
			if free_side:
				if not inside_map(other_cell):
					# Beyond the edge of the map there is no ground and no rock.
					continue
				# The free cells of the map carry the base layer of the original,
				# which the export does not keep.
				other = [[0.0, 1.0, ground_level, ground_level]]
			else:
				var other_sides: Dictionary = surfaces[other_cell]
				other = other_sides[opposite_side(side)] as Array
				if other.is_empty():
					continue
				var other_flats: Dictionary = flats[other_cell]
				flat_other = other_flats[opposite_side(side)] as Array
			quads.append_array(border_pair(cell, side, here, other, free_side,
				flat_sides[side] as Array, flat_other, ground_level))
	return quads


## The faces between the surface of a cell and the surface of its neighbour,
## where the pair of the flat profiles has no face.
static func border_pair(cell: Vector2i, side: int, here: Array, other: Array,
		free_side: bool, flat_here: Array, flat_other: Array, ground_level: float) -> Array:
	var points: Array = []
	for segment: Array in here:
		points.append(float(segment[0]))
		points.append(float(segment[1]))
	for segment: Array in other:
		points.append(float(segment[0]))
		points.append(float(segment[1]))
	points.sort()
	var breaks: Array = []
	for value: float in points:
		if breaks.is_empty() or absf(float(breaks[breaks.size() - 1]) - value) > EPS:
			breaks.append(value)
	var quads: Array = []
	for index in range(0, breaks.size() - 1):
		var start: float = float(breaks[index])
		var stop: float = float(breaks[index + 1])
		if stop - start <= EPS:
			continue
		var middle: float = (start + stop) * 0.5
		var level_here: float = surface_height(here, middle)
		var level_other: float = surface_height(other, middle)
		if is_nan(level_here) or is_nan(level_other):
			continue
		if absf(level_here - level_other) < MIN_WALL_HEIGHT:
			continue
		# The pair of the flat profiles builds the face where it can.
		var flat_level_here: float = level_at(flat_here, middle)
		var flat_level_other: float = ground_level if free_side else level_at(flat_other, middle)
		if not is_nan(flat_level_here) and not is_nan(flat_level_other) \
				and absf(flat_level_here - flat_level_other) >= MIN_WALL_HEIGHT:
			continue
		if not free_side and level_here > level_other:
			# The face belongs to the lower neighbour.
			continue
		quads.append_array(border_face(cell, side, start, stop, here, other))
	return quads


## One vertical face between the surface of a cell and the surface of its
## neighbour.
##
## The face stands on the border of the cell and follows the two surfaces: its
## lower edge is the lower of them and its upper edge the higher one. The two
## surfaces can cross inside the interval, and then the face is split at the
## crossing, so that it never twists.
static func border_face(cell: Vector2i, side: int, start: float, stop: float,
		here: Array, other: Array) -> Array:
	var difference_start: float = _difference(here, other, start)
	var difference_stop: float = _difference(here, other, stop)
	if difference_start * difference_stop < 0.0:
		var crossing: float = _crossing(here, other, start, stop)
		return border_face(cell, side, start, crossing, here, other) \
			+ border_face(cell, side, crossing, stop, here, other)
	var here_start: float = surface_height(here, start)
	var here_stop: float = surface_height(here, stop)
	var other_start: float = surface_height(other, start)
	var other_stop: float = surface_height(other, stop)
	var lower_start: float = minf(here_start, other_start)
	var lower_stop: float = minf(here_stop, other_stop)
	var upper_start: float = maxf(here_start, other_start)
	var upper_stop: float = maxf(here_stop, other_stop)
	# The face belongs to the lower side: the cell or its neighbour.
	var cell_is_lower: bool = difference_start <= 0.0
	var corners: Array[Vector3] = []
	if cell_is_lower:
		corners = [
			_corner(side, start, here_start), _corner(side, stop, here_stop),
			_corner(side, stop, other_stop), _corner(side, start, other_start)]
	else:
		corners = [
			_corner(side, start, other_start), _corner(side, stop, other_stop),
			_corner(side, stop, here_stop), _corner(side, start, here_start)]
	var direction := side_direction(side)
	var normal := Vector3(float(direction.x), float(direction.y), 0.0)
	if cell_is_lower:
		# The normal points into the lower side, as it does for the face of a
		# pair of two flat cells.
		normal = -normal
	var facing: Vector3 = (corners[1] - corners[0]).cross(corners[2] - corners[0])
	if facing.dot(normal) < 0.0:
		var swapped: Array[Vector3] = [corners[0], corners[3], corners[2], corners[1]]
		corners = swapped
	var lower: float = minf(lower_start, lower_stop)
	var upper: float = maxf(upper_start, upper_stop)
	return [{
		"corners": corners,
		"cell": cell,
		"side": side,
		"lower": lower,
		"upper": upper,
		"height": upper - lower,
		"normal": normal,
	}]


## The difference of the two surfaces at a position.
static func _difference(here: Array, other: Array, position: float) -> float:
	var first: float = surface_height(here, position)
	var second: float = surface_height(other, position)
	if is_nan(first) or is_nan(second):
		return 0.0
	return first - second


## The place where the two surfaces cross inside an interval.
static func _crossing(here: Array, other: Array, start: float, stop: float) -> float:
	var low: float = start
	var high: float = stop
	for _step in range(16):
		var middle: float = (low + high) * 0.5
		if _difference(here, other, middle) * _difference(here, other, low) <= 0.0:
			high = middle
		else:
			low = middle
	return (low + high) * 0.5


## The vertical faces of the cliffs of the chapter.
##
## Every ramp of the export is a transition of the height field between two
## levels. The face of the cliff stands on the lower edge of the ramp and covers
## the ramp behind it, so the edge of an excavation reads as one rock wall and
## not as a row of separate panels.
##
## ADAPTER: one face per ramp triangle is wrong. The exporter splits the ramp of
## a step into several triangles, and the face of one triangle is a plate that
## is a quarter of a cell wide and two cells high: a picket standing in front
## of the slope. The faces are therefore collected per step - per plane they
## stand in - and the covered intervals of the plane are merged into one
## continuous wall, which is split only where the height of the crest changes.
##
## FACT (Diggles.exe): the engine creates the geometry of a pit when the drop
## inside a cell reaches four levels of half a cell, that is 2.0 cells
## (FUN_004ca830:399-427, the central sample of the 8x8 grid against the
## corners). The threshold belongs to the step and not to a part of it: a step
## that reaches 2.0 is drawn as a whole, so that it has no gap in it.
static func cliff_quads(cells: Array, meshes: Dictionary, min_height: float = CLIFF_HEIGHT) -> Array:
	var steps: Array = []
	var level_counts: Dictionary = {}
	for entry: Dictionary in cells:
		var cell := Vector2i(int(entry["x"]), int(entry["y"]))
		var groups: Dictionary = {}
		var levels: Dictionary = {}
		for part: Dictionary in meshes.get(str(int(entry["block"])), []):
			var values: Array = part["vertices"]
			var indices: Array = part["indices"]
			for triangle_start in range(0, indices.size(), 3):
				var points: Array[Vector3] = []
				for corner in range(3):
					var offset: int = int(indices[triangle_start + corner]) * 5
					points.append(Vector3(float(values[offset]), float(values[offset + 1]),
						float(values[offset + 2])))
				var level: float = points[0].z
				var flat: bool = true
				for point: Vector3 in points:
					if absf(point.z - level) > EPS:
						flat = false
				if flat:
					# The levels of the terrain of the cell: the surface of the
					# map and the floor of the excavation are read from them.
					levels[int(round(level * 1024.0))] = true
					continue
				var foot: Dictionary = cliff_foot(points)
				if foot.is_empty():
					continue
				var key: int = cliff_step_key(foot)
				if not groups.has(key):
					groups[key] = {
						"cell": cell,
						"orientation": int(foot["orientation"]),
						"position": float(foot["position"]),
						"side": int(foot["side"]),
						"normal": foot["normal"],
						"feet": [],
					}
				(groups[key] as Dictionary)["feet"].append([float(foot["t0"]), float(foot["t1"]),
					float(foot["lower"]), float(foot["upper"])])
		for key: int in groups:
			steps.append(groups[key])
		for key: int in levels:
			level_counts[key] = int(level_counts.get(key, 0)) + 1
	var floor_level: float = cliff_floor_level(level_counts)
	var quads: Array = []
	for step: Dictionary in steps:
		quads.append_array(cliff_step_quads(step, floor_level, min_height))
	return quads


## The floor of the excavation of the chapter.
##
## The export has no mark of the excavation, so the floor is read from the
## terrain itself: the surface of the map is the level that most of the cells
## carry, and the floor is the level that most of the cells below the surface
## carry. The height grid of the engine of this chapter has the same two levels
## as its two modes, the level 15 of the surface and the level 11 of the floor.
static func cliff_floor_level(level_counts: Dictionary) -> float:
	var surface_key: int = -1
	for key: int in level_counts:
		if surface_key < 0 or float(key) > float(surface_key):
			surface_key = key
	var floor_key: int = -1
	var floor_count: int = -1
	for key: int in level_counts:
		if float(key) >= float(surface_key) - EPS:
			continue
		if int(level_counts[key]) > floor_count:
			floor_count = int(level_counts[key])
			floor_key = key
	if floor_key < 0:
		return float(surface_key) / 1024.0
	return float(floor_key) / 1024.0


## The foot of a step, or an empty dictionary.
##
## A flat patch is the surface of the terrain and a face in a plane x = const or
## y = const is already in the export, so only a ramp gets a face. The foot of
## the step is the lower edge of the ramp: the edge whose two ends are at the
## lowest level of the triangle. The ramp is the rock above that edge, so the
## normal of the face points away from it, into the lower side.
static func cliff_foot(points: Array[Vector3]) -> Dictionary:
	if points.size() != 3:
		return {}
	var low: float = points[0].z
	var high: float = points[0].z
	for point: Vector3 in points:
		low = minf(low, point.z)
		high = maxf(high, point.z)
	if high - low < EPS:
		return {}
	var flat_x: bool = true
	var flat_y: bool = true
	for point: Vector3 in points:
		if absf(point.x - points[0].x) > EPS:
			flat_x = false
		if absf(point.y - points[0].y) > EPS:
			flat_y = false
	if flat_x or flat_y:
		# The export carries this face already.
		return {}
	var edge: Array[Vector3] = []
	var third: Vector3 = Vector3.ZERO
	for corner in range(3):
		var a: Vector3 = points[corner]
		var b: Vector3 = points[(corner + 1) % 3]
		if absf(a.z - b.z) > EPS or a.z > low + EPS:
			continue
		edge = [a, b]
		for other: Vector3 in points:
			if other != a and other != b:
				third = other
		break
	if edge.is_empty():
		# The triangle has no lower edge: its lowest corner is a single point.
		return {}
	var first: Vector3 = edge[0]
	var second: Vector3 = edge[1]
	# The engine has no face of forty five degrees: a wall is a vertical plane
	# between two neighbours of a different height, and a diagonal edge is a step
	# that the engine splits into vertical planes along its grid. A face on the
	# diagonal edge itself would be a face of the port and not of the original.
	if absf(first.x - second.x) > EPS and absf(first.y - second.y) > EPS:
		return {}
	# The foot lies in a plane of constant x or of constant y. A foot on the
	# border of the cell is the face of the neighbour: the pair of the profiles
	# builds it.
	var along_x: bool = absf(first.y - second.y) <= EPS
	var position: float = first.y if along_x else first.x
	if absf(position) <= EPS or absf(position - 1.0) <= EPS:
		return {}
	var t0: float = minf(first.x, second.x) if along_x else minf(first.y, second.y)
	var t1: float = maxf(first.x, second.x) if along_x else maxf(first.y, second.y)
	if t1 - t0 <= EPS:
		return {}
	var normal := Vector3.ZERO
	var side: int = SIDE_NEG_Y
	if along_x:
		if third.y > position:
			normal = Vector3(0.0, -1.0, 0.0)
			side = SIDE_NEG_Y
		else:
			normal = Vector3(0.0, 1.0, 0.0)
			side = SIDE_POS_Y
	else:
		if third.x > position:
			normal = Vector3(-1.0, 0.0, 0.0)
			side = SIDE_NEG_X
		else:
			normal = Vector3(1.0, 0.0, 0.0)
			side = SIDE_POS_X
	return {
		"orientation": CLIFF_PLANE_Y if along_x else CLIFF_PLANE_X,
		"position": position,
		"t0": t0,
		"t1": t1,
		"lower": low,
		"upper": high,
		"normal": normal,
		"side": side,
	}


## The key of the step a foot belongs to: the plane it stands in and the side of
## the rock that it separates.
static func cliff_step_key(foot: Dictionary) -> int:
	return (int(round(float(foot["position"]) * 1024.0)) * 2 \
		+ int(foot["orientation"])) * 4 + int(foot["side"])


## The wall of one step: the feet of the step are merged into one wall.
##
## The step reaches the threshold of the engine, so it is drawn as a whole. Its
## parts are drawn from the smallest wall height, so that a step has no gap in
## it, and the wall is split only where the height of the crest changes. A step
## that stands on the rock of the map and not on the floor of the excavation is
## a slope of the rock and gets no wall at all.
static func cliff_step_quads(step: Dictionary, floor_level: float, min_height: float) -> Array:
	var quads: Array = []
	var feet: Array = step["feet"]
	if feet.is_empty():
		return quads
	var step_drop: float = 0.0
	var step_lower: float = INF
	for foot: Array in feet:
		step_drop = maxf(step_drop, float(foot[3]) - float(foot[2]))
		step_lower = minf(step_lower, float(foot[2]))
	if step_drop < min_height:
		return quads
	if absf(step_lower - floor_level) > EPS:
		return quads
	var marks: Array = []
	for foot: Array in feet:
		marks.append(float(foot[0]))
		marks.append(float(foot[1]))
	marks.sort()
	var breaks: Array = []
	for value: float in marks:
		if breaks.is_empty() or absf(float(breaks[breaks.size() - 1]) - value) > EPS:
			breaks.append(value)
	for index in range(0, breaks.size() - 1):
		var start: float = float(breaks[index])
		var stop: float = float(breaks[index + 1])
		if stop - start <= EPS:
			continue
		var middle: float = (start + stop) * 0.5
		var lower: float = INF
		var upper: float = -INF
		var found: bool = false
		for foot: Array in feet:
			if float(foot[0]) - EPS > middle or middle > float(foot[1]) + EPS:
				continue
			found = true
			lower = minf(lower, float(foot[2]))
			upper = maxf(upper, float(foot[3]))
		if not found:
			continue
		if upper - lower < MIN_WALL_HEIGHT:
			continue
		quads.append(cliff_face(step, start, stop, lower, upper))
	return quads


## One vertical face of a step of a cliff.
##
## The corners are in the cell space. The face stands on the foot of the step
## and spans the part of the step that lies under the given interval.
static func cliff_face(step: Dictionary, start: float, stop: float,
		lower: float, upper: float) -> Dictionary:
	var cell: Vector2i = step["cell"]
	var position: float = float(step["position"])
	var normal: Vector3 = step["normal"]
	var corners: Array[Vector3] = []
	if int(step["orientation"]) == CLIFF_PLANE_Y:
		corners = [
			Vector3(start, position, lower), Vector3(stop, position, lower),
			Vector3(stop, position, upper), Vector3(start, position, upper)]
	else:
		corners = [
			Vector3(position, start, lower), Vector3(position, stop, lower),
			Vector3(position, stop, upper), Vector3(position, start, upper)]
	var facing: Vector3 = (corners[1] - corners[0]).cross(corners[2] - corners[0])
	if facing.dot(normal) < 0.0:
		# The winding of the face must show it from the lower side. The two lower
		# corners stay the two first ones, so the face keeps its shape.
		var swapped: Array[Vector3] = [corners[1], corners[0], corners[3], corners[2]]
		corners = swapped
	return {
		"corners": corners,
		"cell": cell,
		"side": int(step["side"]),
		"lower": lower,
		"upper": upper,
		"height": upper - lower,
		"normal": normal,
	}


## One vertical face on the lower edge of a ramp, or an empty dictionary.
##
## A flat patch is the surface of the terrain and a face in a plane x = const or
## y = const is already in the export, so only a ramp gets a face. The face
## stands on the lower edge of the ramp: the edge whose two ends are at the
## lowest level of the triangle. The ramp is the rock above that edge, so the
## normal of the face points away from it, into the lower side.
static func cliff_quad(cell: Vector2i, points: Array[Vector3], min_height: float) -> Dictionary:
	var foot: Dictionary = cliff_foot(points)
	if foot.is_empty():
		return {}
	if float(foot["upper"]) - float(foot["lower"]) < min_height:
		return {}
	var step: Dictionary = {
		"cell": cell,
		"orientation": int(foot["orientation"]),
		"position": float(foot["position"]),
		"side": int(foot["side"]),
		"normal": foot["normal"],
	}
	return cliff_face(step, float(foot["t0"]), float(foot["t1"]),
		float(foot["lower"]), float(foot["upper"]))


## The faces between the profile of a cell and the profile of its neighbour.
##
## A face between two cells belongs to the lower one, so it is built once. The
## face against the base layer of the map belongs to the cell, because the free
## cells have no side of their own.
static func pair_profiles(cell: Vector2i, side: int, here: Array, other: Array, free_side: bool) -> Array:
	var points: Array = []
	for segment: Array in here:
		points.append(float(segment[0]))
		points.append(float(segment[1]))
	for segment: Array in other:
		points.append(float(segment[0]))
		points.append(float(segment[1]))
	points.sort()
	var breaks: Array = []
	for value: float in points:
		if breaks.is_empty() or absf(float(breaks[breaks.size() - 1]) - value) > EPS:
			breaks.append(value)
	var quads: Array = []
	for index in range(0, breaks.size() - 1):
		var start: float = float(breaks[index])
		var stop: float = float(breaks[index + 1])
		if stop - start <= EPS:
			continue
		var middle: float = (start + stop) * 0.5
		var level_here: float = level_at(here, middle)
		var level_other: float = level_at(other, middle)
		if is_nan(level_here) or is_nan(level_other):
			continue
		if absf(level_here - level_other) < MIN_WALL_HEIGHT:
			continue
		if not free_side and level_here > level_other:
			# The face belongs to the lower neighbour.
			continue
		quads.append(wall_quad(cell, side, start, stop, level_here, level_other))
	return quads


## One vertical face between a cell and its neighbour.
##
## The corners are in the cell space: the cell of the face is at the origin,
## the face lies on the side of the cell and runs along the side from start to
## stop. The normal points into the lower side, so the face is seen from the
## excavation and not from the rock above it.
static func wall_quad(cell: Vector2i, side: int, start: float, stop: float,
		level_here: float, level_other: float) -> Dictionary:
	var lower: float = minf(level_here, level_other)
	var upper: float = maxf(level_here, level_other)
	var direction := side_direction(side)
	var normal := Vector3(float(direction.x), float(direction.y), 0.0)
	if level_here < level_other:
		normal = -normal
	var corners: Array[Vector3] = []
	corners.append(_corner(side, start, lower))
	corners.append(_corner(side, stop, lower))
	corners.append(_corner(side, stop, upper))
	corners.append(_corner(side, start, upper))
	# The winding of the face must show it from the lower side.
	var facing: Vector3 = (corners[1] - corners[0]).cross(corners[2] - corners[0])
	if facing.dot(normal) < 0.0:
		corners = [corners[0], corners[3], corners[2], corners[1]]
	return {
		"corners": corners,
		"cell": cell,
		"side": side,
		"lower": lower,
		"upper": upper,
		"height": upper - lower,
		"normal": normal,
	}


## One corner of a face in the cell space.
static func _corner(side: int, position: float, height: float) -> Vector3:
	match side:
		SIDE_POS_X:
			return Vector3(1.0, position, height)
		SIDE_NEG_X:
			return Vector3(0.0, position, height)
		SIDE_POS_Y:
			return Vector3(position, 1.0, height)
		_:
			return Vector3(position, 0.0, height)


## The texture coordinates of a face.
##
## The vertical coordinate follows the height of the face, so the ground
## texture keeps its world scale instead of being stretched.
static func wall_uv(height: float) -> Vector2:
	return Vector2(1.0, maxf(height, 0.0))
