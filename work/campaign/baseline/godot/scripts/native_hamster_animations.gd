## Hamster animation table (class scoped).
##
## The hamster is a separate class with its own alias table, its own animsets
## and its own 3DB package. Alias names are class scoped in the original game:
## `standstill` means `mann.standard` for a dwarf and `hamster.stand_anim` for
## a hamster, so a global alias table is not enough.
##
## Source: data/Scripts/classes/characters/hamster.tcl (27 aliases, 3 animsets)
## Package: data/3db/hamster.3db (28 clips)
##
## Data: res://models/native_hamster_animations.json
extends RefCounted

const DATA_PATH := "res://models/native_hamster_animations.json"

static var _cache: Dictionary = {}


static func _load_table() -> Dictionary:
	if not _cache.is_empty():
		return _cache
	if not FileAccess.file_exists(DATA_PATH):
		push_error("[native_hamster_animations] missing %s" % DATA_PATH)
		_cache = {}
		return _cache
	var file := FileAccess.open(DATA_PATH, FileAccess.READ)
	if file == null:
		push_error("[native_hamster_animations] cannot open %s" % DATA_PATH)
		_cache = {}
		return _cache
	var parsed: Variant = JSON.parse_string(file.get_as_text())
	file.close()
	if typeof(parsed) != TYPE_DICTIONARY:
		push_error("[native_hamster_animations] malformed table")
		_cache = {}
		return _cache
	_cache = parsed
	return _cache


static func _class_data(class_id: String) -> Dictionary:
	var table := _load_table()
	var classes: Dictionary = table.get("classes", {})
	if not classes.has(class_id):
		return {}
	return classes[class_id]


## Alias -> clip name without the package prefix, or "" when unknown.
static func get_clip(class_id: String, alias_name: String) -> String:
	var data := _class_data(class_id)
	var aliases: Dictionary = data.get("aliases", {})
	if not aliases.has(alias_name):
		return ""
	var entry: Dictionary = aliases[alias_name]
	var target: String = entry.get("target", "")
	var dot := target.rfind(".")
	if dot < 0:
		return target
	return target.substr(dot + 1)


## Full target as written in the original ("hamster.laufen_loop").
static func get_target(class_id: String, alias_name: String) -> String:
	var data := _class_data(class_id)
	var aliases: Dictionary = data.get("aliases", {})
	if not aliases.has(alias_name):
		return ""
	var entry: Dictionary = aliases[alias_name]
	return entry.get("target", "")


## Frame count of the clip behind the alias, or -1 when unknown.
static func get_frame_count(class_id: String, alias_name: String) -> int:
	var data := _class_data(class_id)
	var aliases: Dictionary = data.get("aliases", {})
	if not aliases.has(alias_name):
		return -1
	var entry: Dictionary = aliases[alias_name]
	return int(entry.get("frames", -1))


static func has_alias(class_id: String, alias_name: String) -> bool:
	var data := _class_data(class_id)
	return (data.get("aliases", {}) as Dictionary).has(alias_name)


static func alias_count(class_id: String) -> int:
	var data := _class_data(class_id)
	return (data.get("aliases", {}) as Dictionary).size()


## Role -> clip for one animset of the class.
static func get_animset_role(class_id: String, set_id: String, role: String) -> String:
	var data := _class_data(class_id)
	var animsets: Dictionary = data.get("animsets", {})
	if not animsets.has(set_id):
		return ""
	var entries: Dictionary = animsets[set_id].get("entries", {})
	return entries.get(role, "")


static func animset_ids(class_id: String) -> Array:
	var data := _class_data(class_id)
	return (data.get("animsets", {}) as Dictionary).keys()


## The clip behind a role of an animset, without the package prefix.
##
## The walk animset of the hamster uses the walk clips, the hop animset the
## hop clips. The native walk action of the original plays the animset of the
## walk, so the host needs the clip of the role.
static func get_animset_clip(class_id: String, set_id: String, role: String) -> String:
	var target := get_animset_role(class_id, set_id, role)
	if target == "":
		return ""
	var dot := target.rfind(".")
	if dot < 0:
		return target
	return target.substr(dot + 1)


## Frame count of a clip in the class package, or -1.
static func get_clip_frames(class_id: String, clip_name: String) -> int:
	var table := _load_table()
	if class_id != "Hamster":
		return -1
	var clips: Dictionary = table.get("clips", {})
	return int(clips.get(clip_name, -1))


## All clip names of the class package with their frame counts.
static func get_clips() -> Dictionary:
	var table := _load_table()
	return table.get("clips", {})
