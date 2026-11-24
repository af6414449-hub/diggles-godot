extends SceneTree
## Verifies the fixed scenery geometry using the opening and the campaign camera.
const Backdrop = preload("res://scripts/native_campaign_backdrop.gd")
const CampaignCamera = preload("res://scripts/native_campaign_camera.gd")

var _failures: int = 0
var _checks: int = 0


func _initialize() -> void:
	call_deferred("_run")


func _check(condition: bool, message: String) -> void:
	_checks += 1
	if not condition:
		_failures += 1
		printerr("FAIL: " + message)


func _run() -> void:
	var chapter: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(
		"res://models/native_campaign_chapter.json"))
	var edge: Vector3 = Backdrop.clearing_edge(chapter["objects"], 14.5)
	_check(edge.is_equal_approx(Vector3(241.16667, -30.5, 14.5)),
		"world anchor is the turf line of the start clearing")
	_check(Backdrop.clearing_edge([], 14.5) == null, "missing turf does not create scenery")
	var backdrop = Backdrop.new()
	var stage: Node3D = Node3D.new()
	root.add_child(stage)
	var scenery: Node3D = backdrop.build(edge, stage)
	_check(scenery.get_child_count() == 5, "four flats and one meadow")
	var view = CampaignCamera.new()
	view.setup(chapter["initial_view"])
	var camera: Camera3D = Camera3D.new()
	camera.fov = CampaignCamera.FOV_DEGREES
	root.add_child(camera)
	camera.position = view.camera_position()
	camera.look_at(view.look_target())
	var last_depth: float = -INF
	var last_shift: float = INF
	var original: Array[Transform3D] = []
	for index in range(4):
		var plan: MeshInstance3D = scenery.get_child(index) as MeshInstance3D
		original.append(plan.global_transform)
		_check(plan.global_position.z > last_depth and plan.global_position.z < edge.z,
			"%s sits behind the opening in depth order" % plan.name)
		last_depth = plan.global_position.z
		_check(is_zero_approx(plan.mesh.get_aabb().size.z), "%s is one flat" % plan.name)
		var material: StandardMaterial3D = plan.material_override as StandardMaterial3D
		_check(material.albedo_texture != null and material.albedo_texture.resource_path
			== "res://textures/backdrop/Panorama_layer_%d.tga" % (index + 2),
			"%s uses the corresponding source panorama texture" % plan.name)
		var bounds: AABB = plan.mesh.get_aabb()
		var top: Vector2 = camera.unproject_position(plan.to_global(Vector3(0, bounds.end.y, 0)))
		var bottom: Vector2 = camera.unproject_position(plan.global_position)
		_check(bottom.y - top.y > root.get_visible_rect().size.y * 0.1,
			"%s projects to a visible height from the opening" % plan.name)
		print("CAMPAIGN_PIT_LAYER name=%s y=%.3f..%.3f z=%.2f" % [
			plan.name, top.y / root.get_visible_rect().size.y,
			bottom.y / root.get_visible_rect().size.y, last_depth])
	var meadow: MeshInstance3D = scenery.get_child(4) as MeshInstance3D
	_check(is_zero_approx(meadow.mesh.get_aabb().end.z), "meadow reaches the turf line")
	var meadow_bounds: AABB = meadow.mesh.get_aabb()
	_check(is_zero_approx(meadow_bounds.size.y), "meadow is level from the clearing to the mountain")
	var turf: StandardMaterial3D = meadow.material_override as StandardMaterial3D
	_check(turf.albedo_texture == Backdrop.MEADOW_TEXTURE, "meadow uses the original turf texture")
	for placement: Dictionary in chapter["objects"]:
		var object_class: String = str(placement.get("class", ""))
		if placement.get("template") != "urw_unq_start" or not (
				object_class.begins_with("Dummy_Obw_baum_") or object_class == "Dummy_Obw_berg_a"):
			continue
		var centre: Vector3 = Vector3(float(placement["x"]), -float(placement["y"]),
			7.0 + 0.5 * float(placement["z"])) - edge
		var back_ratio: float = centre.z / meadow_bounds.position.z
		var front_width: float = Backdrop.MEADOW_FRONT_RIGHT if centre.x > 0 else Backdrop.MEADOW_FRONT_HALF_WIDTH
		var half_width: float = lerpf(front_width,
			Backdrop.MEADOW_BACK_HALF_WIDTH, back_ratio)
		_check(back_ratio >= 0.0 and back_ratio <= 1.0 and absf(centre.x) < half_width
			and absf(centre.y - meadow_bounds.position.y) < 1.1,
			"meadow reaches the base of %s" % object_class)
	var meadow_transform: Transform3D = meadow.global_transform
	camera.position = view.look_target() + (camera.position - view.look_target()) * 1.65
	camera.fov = 53.0
	backdrop.update(0.0)
	for index in range(4):
		var plan: Node3D = scenery.get_child(index) as Node3D
		_check(plan.global_transform.is_equal_approx(original[index]),
			"%s keeps its size and placement after zoom" % plan.name)
	backdrop.update(12.0)
	for index in range(4):
		var plan: Node3D = scenery.get_child(index) as Node3D
		var shift: Vector3 = plan.global_position - original[index].origin
		_check(shift.x > 0.0 and shift.x < last_shift and is_zero_approx(shift.y)
			and is_zero_approx(shift.z), "%s pans laterally at its own rate" % plan.name)
		last_shift = shift.x
	_check(meadow.global_transform.is_equal_approx(meadow_transform), "meadow stays joined during pan")
	print("NATIVE_CAMPAIGN_BACKDROP_SELF_TEST assertions=%d failures=%d" % [_checks, _failures])
	quit(0 if _failures == 0 else 1)
