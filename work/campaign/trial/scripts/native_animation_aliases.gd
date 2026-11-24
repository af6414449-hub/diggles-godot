extends RefCounted
## Candidate catalog/API contributed by the read-only Minimax project.
## Rebuilt from original Tcl + exact mann.3db object records by our exporter.
## Metadata lookup only: callers still own gender substitution and clip loading.

const DATA_PATH: String = "res://models/native_animation_aliases.json"
static var _cache: Dictionary = {}


static func _table() -> Dictionary:
	if _cache.is_empty():
		var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(DATA_PATH))
		if parsed is Dictionary and parsed.get("schema") == "diggles.native_animation_aliases.v1":
			_cache = parsed
		else:
			push_error("Invalid source animation alias catalog")
	return _cache


static func get_target(alias_name: String) -> String:
	return str(_table()["aliases"].get(alias_name, {}).get("target", ""))


static func get_clip(alias_name: String) -> String:
	return get_target(alias_name).get_slice(".", 1)


static func get_frame_count(alias_name: String) -> int:
	return int(_table()["aliases"].get(alias_name, {}).get("frames", -1))


static func get_face_anim(alias_name: String) -> String:
	return str(_table()["aliases"].get(alias_name, {}).get("face_anim", ""))


static func has_target(target: String) -> bool:
	# Never accept a foreign package or an ambiguous bare clip by stripping it.
	return _table()["targets"].has(target)


static func get_animset(set_name: String) -> Dictionary:
	# Caller edits must not change the authoritative cached role table.
	return _table()["animsets"].get(set_name, {}).duplicate(true)


static func get_animset_role(set_name: String, role: String) -> String:
	return str(_table()["animsets"].get(set_name, {}).get("entries", {}).get(role, ""))


static func alias_count() -> int:
	return _table()["aliases"].size()


static func animset_count() -> int:
	return _table()["animsets"].size()
