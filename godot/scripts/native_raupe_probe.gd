extends Node3D
## Probe scene for the Raupe.
##
## One Raupe crawls on a small floor. The probe owns the actor and ticks it,
## so the headless scene test can read the state of the actor.
##
## Run: res://scenes/native_raupe_probe.tscn

const Actor = preload("res://scripts/native_raupe_actor.gd")

var actor: RefCounted = null
var ticks: int = 0


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
	camera.position = Vector3(1.5, 4.0, 8.0)
	add_child(camera)
	camera.look_at_from_position(camera.position, Vector3(1.5, 0.25, 0.0), Vector3.UP)
	camera.make_current()

	actor = Actor.new()
	actor.call("setup", _host(), 20261119)


func _process(delta: float) -> void:
	if actor == null:
		return
	actor.call("tick", delta)
	ticks += 1


## The fake world of the probe: an empty dig site without a farm and without a
## plant, so the Raupe only roams.
func _host() -> Dictionary:
	return {
		"actor_pos": func() -> Vector3: return global_position,
		"max_fow": func() -> float: return 20.0,
		"is_contained": func() -> bool: return false,
		"owner_id": func() -> String: return "probe",
		"query_farm": func(_request: Dictionary) -> Dictionary: return {},
		"farm_state": func(_reference: String) -> Dictionary:
			return {"valid": false, "buildup": false},
		"query_dwarf": func(_request: Dictionary) -> Dictionary: return {},
		"query_plant": func(_request: Dictionary) -> Dictionary: return {},
		"plant_state": func(_reference: String) -> Dictionary:
			return {"valid": false, "position": Vector3.ZERO},
		"pick_place": func(request: Dictionary) -> Dictionary:
			return {"code": 1, "position": request.get("center", Vector3.ZERO)},
		"damage_plant": func(_reference: String, _amount: float) -> void: pass,
		"emit_particles": func(_request: Dictionary) -> void: pass,
		"destroy_actor": func() -> void: pass,
		"move_action": func(params: Dictionary) -> bool:
			_apply_move(params)
			return true,
		"move_complete": func() -> bool: return true,
		"play_clip": func(_request: Dictionary) -> bool: return true,
	}


## Follow the move of the actor, so the picture shows where the Raupe looks.
func _apply_move(params: Dictionary) -> void:
	var target: Variant = params.get("target", null)
	if target is Vector3:
		position = target as Vector3
	if actor != null:
		rotation.y = float(actor.call("get_yaw"))
