extends RefCounted
## Loader for the Urwald template manifest of the campaign level generator.
##
## The manifest is produced offline from the original game data by
## `tools/extract_campaign_templates.py` in the campaign work tree. It holds,
## per template, the PMP geometry reference, the L2M material layer and the
## object declarations of `data/Templates/<name>.tcl`.
##
## FACT (source: data/Templates/urw_*.tcl): a template is
##   `map_template <pmp> $xoffset $yoffset`   -> geometry grid,
##   `map_setlayer2 $xoffset $yoffset <l2m>`   -> material layer,
##   plus a list of `[new <Class> ...]` objects with local coordinates, rotation
##   and the owner/physic/autolight/boxed flags.

const MANIFEST_PATH: String = "res://models/campaign_urwald_first_level.json"

var _templates: Dictionary = {}
var _missing: Array[String] = []
var _loaded: bool = false


func load_manifest(path: String = MANIFEST_PATH) -> bool:
	var decoded: Variant = JSON.parse_string(FileAccess.get_file_as_string(path))
	if not decoded is Dictionary:
		push_error("Campaign template manifest is missing: " + path)
		return false
	var manifest: Dictionary = decoded
	var entries: Dictionary = manifest.get("templates", {})
	for key: Variant in entries.keys():
		_templates[str(key)] = entries[key]
	var missing: Array = manifest.get("missing_templates", [])
	for name: Variant in missing:
		_missing.append(str(name))
	_loaded = true
	return true


func is_loaded() -> bool:
	return _loaded


func get_template_count() -> int:
	return _templates.size()


func has_template(name: String) -> bool:
	return _templates.has(name)


## Templates that the original table references but the game data does not ship.
func missing_templates() -> Array[String]:
	return _missing.duplicate()


## Decoded template description: pmp/l2m grids plus the object list.
func get_template(name: String) -> Dictionary:
	if not _templates.has(name):
		return {}
	var raw: Dictionary = _templates[name]
	var result: Dictionary = {
		"name": name,
		"source": str(raw.get("source", "")),
		"kind": str(raw.get("kind", "direct")),
		"objects": raw.get("objects", []),
	}
	if raw.has("pmp"):
		var pmp: Dictionary = raw["pmp"]
		result["pmp"] = {
			"file": str(pmp["file"]),
			"width": int(pmp["width"]),
			"height": int(pmp["height"]),
			"sha256": str(pmp["sha256"]),
			"flags": Marshalls.base64_to_raw(str(pmp["flags_b64"])),
			"blocks": Marshalls.base64_to_raw(str(pmp["blocks_b64"])).to_int32_array(),
			"attributes": Marshalls.base64_to_raw(str(pmp["attributes_b64"])),
		}
	if raw.has("l2m"):
		var l2m: Dictionary = raw["l2m"]
		result["l2m"] = {
			"file": str(l2m["file"]),
			"width": int(l2m["width"]),
			"height": int(l2m["height"]),
			"sha256": str(l2m["sha256"]),
			"words": Marshalls.base64_to_raw(str(l2m["words_b64"])).to_int32_array(),
		}
	return result
