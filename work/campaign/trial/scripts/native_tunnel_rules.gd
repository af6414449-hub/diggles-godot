extends RefCounted
## Imported facts shared with NativeTerrainState, plus current cave marks.
## EXE 0x5672D0, 0x566870, 0x5968B0; live player/layer byte remains unknown.

const UNKNOWN: int = -1
const REJECT: int = 0
const ACCEPT: int = 1

var data: Dictionary = {}
var bounds: Rect2i


func load_rules(path: String, terrain: Dictionary) -> bool:
	var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(path))
	if not parsed is Dictionary:
		return false
	data = parsed
	if data.get("source_pmp_sha256") != terrain.get("source_pmp_sha256") \
			or data.get("source_bdb_sha256") != terrain.get("source_bdb_sha256"):
		return false
	if int(data.get("width", 0)) != int(terrain["width"]) or int(data.get("height", 0)) != int(terrain["height"]):
		return false
	bounds = Rect2i(Vector2i.ZERO, Vector2i(int(data["width"]), int(data["height"])))
	return data.get("cells", []).size() == bounds.size.x * bounds.size.y


func point_rule(point: Vector2i, cave_here: bool, cave_below: bool, player_byte: int = -1) -> int:
	# Explicit local Godot world, not inferred bounds of the live original map.
	if not bounds.grow(-1).has_point(point) or cave_here or cave_below:
		return REJECT
	if (int(float(point.x - 1) / 2.0) & int(float(point.y - 1) / 2.0) & 1) != 0:
		return REJECT
	var cell: Dictionary = data["cells"][point.y * bounds.size.x + point.x]
	if cell["support_ok"] == false:
		return REJECT
	if cell["support_ok"] == null or cell["material_low"] == null:
		return UNKNOWN
	if player_byte == 0:
		return ACCEPT
	var material: int = int(cell["material_low"])
	if material == 0 or material == 3:
		return REJECT if player_byte > 0 else UNKNOWN
	if cell["next_height"] == null:
		return UNKNOWN
	if int(cell["next_height"]) < 11:
		return REJECT if player_byte > 0 else UNKNOWN
	return ACCEPT
