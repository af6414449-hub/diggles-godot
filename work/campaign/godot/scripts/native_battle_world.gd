extends RefCounted
## Source-derived authored battle-world slice. This does not emulate lg_start:
## its cave selection is seeded from GetTickCount and is not reproducible.

const LATTICE_SIZE: int = 4
const STONE_EXPANSION: int = 2

var data: Dictionary = {}


func load_first_slice(path: String) -> bool:
	var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(path))
	if not parsed is Dictionary or not parsed.has("first_slice"):
		return false
	var slice: Variant = parsed["first_slice"]
	if not slice is Dictionary or str(slice.get("id","")) != "stein_4x4_slice_001":
		return false
	data = slice.duplicate(true)
	return validate().is_empty()


func validate() -> PackedStringArray:
	var errors: PackedStringArray = PackedStringArray()
	if data.is_empty():
		errors.append("missing_slice")
		return errors
	var world_size: Array = data.get("world_size",[])
	var bounds: Array = data.get("world_bounds",[])
	if world_size.size() != 2 or int(world_size[0]) != 112 or int(world_size[1]) != 88 \
			or bounds.size() != 2 or int(bounds[0][0]) != 0 or int(bounds[0][1]) != 0 \
			or int(bounds[1][0]) != 112 or int(bounds[1][1]) != 88:
		errors.append("unexpected_world_bounds")
	var area: Array = data.get("generation_area_effective",[])
	if area.size() != 4 or int(area[0]) != 16 or int(area[1]) != 16 \
			or int(area[2]) != 96 or int(area[3]) != 72:
		errors.append("unexpected_generation_area")
	for cave: Dictionary in data.get("caves",[]):
		var preset: Array = cave.get("preset_xy",[])
		var world: Array = cave.get("world_xy",[])
		var size: Array = cave.get("size",[])
		if not _on_lattice(preset) or not _on_lattice(world):
			errors.append("cave_off_lattice_"+str(cave.get("template","")))
			continue
		if world.size() != 2 or preset.size() != 2 or int(world[0]) != int(preset[0])+16 \
				or int(world[1]) != int(preset[1])+16:
			errors.append("bad_area_offset_"+str(cave.get("template","")))
		if size.size() != 2 or int(world[0]) < 8 or int(world[1]) < 8 \
				or int(world[0])+int(size[0]) > 104 or int(world[1])+int(size[1]) > 80:
			errors.append("cave_outside_world_margin_"+str(cave.get("template","")))
	for stone: Dictionary in data.get("stone_rects",[]):
		var authored: Array = stone.get("authored_xy",[])
		var size: Array = stone.get("size",[])
		var rect: Array = stone.get("world_rect",[])
		if not _on_lattice(authored) or not _on_lattice(size):
			errors.append("stone_off_lattice")
			continue
		if rect.size() != 4 or int(rect[0]) != int(authored[0])+16 \
				or int(rect[1]) != int(authored[1])+16 \
				or int(rect[2]) != int(rect[0])+int(size[0])+STONE_EXPANSION \
				or int(rect[3]) != int(rect[1])+int(size[1])+STONE_EXPANSION:
			errors.append("bad_stone_rect")
	return errors


func cave_world_rects() -> Array[Rect2i]:
	var result: Array[Rect2i] = []
	for cave: Dictionary in data.get("caves",[]):
		var point: Array = cave["world_xy"]
		var size: Array = cave["size"]
		result.append(Rect2i(int(point[0]),int(point[1]),int(size[0]),int(size[1])))
	return result


func stone_world_rects(stone_type: int = -1) -> Array[Rect2i]:
	var result: Array[Rect2i] = []
	for stone: Dictionary in data.get("stone_rects",[]):
		if stone_type >= 0 and int(stone["type"]) != stone_type:
			continue
		var rect: Array = stone["world_rect"]
		result.append(Rect2i(int(rect[0]),int(rect[1]),int(rect[2])-int(rect[0]),int(rect[3])-int(rect[1])))
	return result


func _on_lattice(values: Array) -> bool:
	if values.size() < 2:
		return false
	return int(values[0]) % LATTICE_SIZE == 0 and int(values[1]) % LATTICE_SIZE == 0
