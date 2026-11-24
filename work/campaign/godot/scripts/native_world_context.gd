extends RefCounted
## Rendering uses template-local coordinates. Native math receives the actual
## authored world coordinates, including float32 rounding after translation.
## Choosing a test context never asserts which map ran in the original chat.

var id: String = ""
var bounds: Rect2i
var template_offset: Vector2i


func load_context(path: String, context_id: String, terrain: Dictionary) -> bool:
	var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(path))
	if not parsed is Dictionary or parsed.get("source_pmp_sha256") != terrain.get("source_pmp_sha256"):
		return false
	for context: Dictionary in parsed["contexts"]:
		if str(context["id"]) != context_id:
			continue
		var rect: Array = context["world_bounds"]
		var offset: Array = context["template_offset"]
		bounds = Rect2i(int(rect[0]), int(rect[1]), int(rect[2]), int(rect[3]))
		template_offset = Vector2i(int(offset[0]), int(offset[1]))
		id = context_id
		return true
	return false


func to_source(local: Vector3) -> Vector3:
	return local + Vector3(template_offset.x, template_offset.y, 0)


func to_local(source: Vector3) -> Vector3:
	return source - Vector3(template_offset.x, template_offset.y, 0)


func local_sample_bounds() -> Rect2i:
	return Rect2i((bounds.position - template_offset) * 8, bounds.size * 8)
