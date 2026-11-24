extends SceneTree
## --headless --path godot --script res://tools/surface_tool_probe.gd
## Prints the signatures of the drawing methods of SurfaceTool, so that the
## calls of the backdrop module fit the API of the engine in use.

func _initialize() -> void:
	for method: Dictionary in ClassDB.class_get_method_list("SurfaceTool"):
		var names: Array = []
		for argument: Dictionary in method.get("args", []):
			names.append("%s:%s" % [argument.get("name", "?"), argument.get("type", "?")])
		print("%s(%s) defaults=%s" % [
			method.get("name", "?"),
			", ".join(names),
			str(method.get("default_args", [])),
		])
	quit()
