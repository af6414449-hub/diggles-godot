extends SceneTree
## --headless --path godot --script res://tools/native_level_generator_dump.gd -- \
##   --zone Urwald --seed 12345 --area 300,0,160,96 --output res://models/native_generated_level_plan.json
## Writes the plan of a generated level, so the exporter can stamp the templates
## of the original into a map.
const Generator = preload("res://scripts/native_level_generator.gd")


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var zone: String = "Urwald"
	var seed_value: int = 12345
	var area := Rect2i(300, 0, 160, 96)
	# CampaignInit.tcl:34 - sm_create_map 512 640: the map holds 512x640 cells
	# and the resolution of the map is four cells of the generator.
	var map_bounds := Rect2i(0, 0, 2048, 2560)
	var output: String = "res://models/native_generated_level_plan.json"

	var zone_index: int = args.find("--zone")
	if zone_index >= 0 and zone_index + 1 < args.size():
		zone = args[zone_index + 1]
	var seed_index: int = args.find("--seed")
	if seed_index >= 0 and seed_index + 1 < args.size():
		seed_value = int(args[seed_index + 1])
	var area_index: int = args.find("--area")
	if area_index >= 0 and area_index + 1 < args.size():
		var parts: PackedStringArray = args[area_index + 1].split(",")
		if parts.size() == 4:
			area = Rect2i(int(parts[0]), int(parts[1]), int(parts[2]), int(parts[3]))
	var output_index: int = args.find("--output")
	if output_index >= 0 and output_index + 1 < args.size():
		output = args[output_index + 1]
	var map_index: int = args.find("--map")
	if map_index >= 0 and map_index + 1 < args.size():
		var parts: PackedStringArray = args[map_index + 1].split(",")
		if parts.size() == 4:
			map_bounds = Rect2i(int(parts[0]), int(parts[1]), int(parts[2]), int(parts[3]))

	var generator: RefCounted = Generator.new()
	if not generator.call("load_inventory"):
		printerr("NATIVE_LEVEL_GENERATOR_DUMP_FAIL reason=inventory")
		quit(1)
		return
	var plan: Dictionary = generator.call("generate", seed_value, zone, area, map_bounds)
	if plan.is_empty():
		printerr("NATIVE_LEVEL_GENERATOR_DUMP_FAIL reason=empty_plan")
		quit(1)
		return

	var file: FileAccess = FileAccess.open(output, FileAccess.WRITE)
	if file == null:
		printerr("NATIVE_LEVEL_GENERATOR_DUMP_FAIL reason=output")
		quit(1)
		return
	file.store_string(JSON.stringify(plan))
	file.close()
	print("NATIVE_LEVEL_GENERATOR_DUMP_OK zone=%s seed=%d placements=%d resources=%d fill=%d free=%d output=%s" % [
		zone, seed_value, (plan["placements"] as Array).size(),
		(plan["resources"] as Array).size(), int(plan.get("fill", 0)),
		int(plan.get("free_cells", 0)), output])
	quit(0)
