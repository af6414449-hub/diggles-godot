extends Node3D
## Probe scene for the wild hamster.
##
## One hamster walks to the right (+X). The camera looks from the front, so a
## hamster that faces its direction of travel looks to the right of the screen
## and a hamster that walks sideways looks into the camera.
##
## Run: res://scenes/native_wild_hamster_probe.tscn

const Hamster = preload("res://scripts/native_wild_hamster.gd")

var _hamster: Node3D = null
var headings: Array[float] = []
var _last_heading: float = -99.0
var _last_clip: String = ""


func _ready() -> void:
	var light := DirectionalLight3D.new()
	light.rotation_degrees = Vector3(-55.0, -35.0, 0.0)
	light.light_energy = 1.1
	add_child(light)

	var floor_mesh := MeshInstance3D.new()
	var plane := PlaneMesh.new()
	plane.size = Vector2(12.0, 8.0)
	floor_mesh.mesh = plane
	var floor_material := StandardMaterial3D.new()
	floor_material.albedo_color = Color(0.32, 0.29, 0.25)
	floor_mesh.mesh.material = floor_material
	floor_mesh.position = Vector3(1.5, 0.0, 0.0)
	add_child(floor_mesh)

	var camera := Camera3D.new()
	camera.position = Vector3(1.5, 2.2, 6.5)
	add_child(camera)
	camera.look_at_from_position(camera.position, Vector3(1.5, 0.25, 0.0), Vector3.UP)
	camera.make_current()

	_hamster = Hamster.new()
	_hamster.name = "ProbeHamster"
	_hamster.position = Vector3.ZERO
	add_child(_hamster)
	_hamster.call("setup", _probe_host())
	# A fixed walk to the right, so the picture shows where the hamster looks.
	var actor: RefCounted = _hamster.get("actor")
	actor.call("_start_walk", {"target": Vector3(3.0, 0.0, 0.0), "animsets": "1"})


func _probe_host() -> Dictionary:
	return {
		"dwarf_positions": func() -> Array: return [],
		"food_entries": func() -> Array: return [],
		"walk_path": func(_from: Vector3, to: Vector3) -> Array: return [to],
		"free_spot": func(center: Vector3, _radius: float, _mindist: float, _clip: Array) -> Variant:
			return center,
		"apply_heading": func(_node: Node3D, heading: float) -> void:
			headings.append(heading)
			_hamster.transform.basis = Basis(Vector3.UP, heading),
		"depth_scale": func() -> float: return 1.0,
	}


func _process(_delta: float) -> void:
	if _hamster == null:
		return
	if (headings as Array).is_empty():
		return
	var heading := float((headings as Array)[(headings as Array).size() - 1])
	var clip := String(_hamster.call("get_current_clip"))
	if absf(heading - _last_heading) < 0.0001 and clip == _last_clip:
		return
	_last_heading = heading
	_last_clip = clip
	print("PROBE_HAMSTER heading=%.3f pos=%s clip=%s" % [heading,
		str(_hamster.position), clip])
