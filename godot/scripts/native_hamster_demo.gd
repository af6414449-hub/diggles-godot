## Demo of the autonomous hamster.
##
## Two hamsters with the original behaviour: a wild one that fears the dwarf
## and eats the mushroom hat, and a farmed one that stays in the pen and
## ignores the dwarf. The dwarf walks past on its own, so everything on
## screen is driven by the hamster logic.
extends Node3D

const HamsterActor3D = preload("res://scripts/native_hamster_actor_3d.gd")

const WILD_START := Vector3(7.0, 0.0, 8.0)
const FARM_POSITION := Vector3(12.5, 0.0, 8.0)
const FOOD_POSITION := Vector3(7.0, 0.0, 10.2)
const DWARF_START := Vector3(3.5, 0.0, 9.0)
const DWARF_END := Vector3(9.5, 0.0, 9.6)

var _wild: Node3D = null
var _farmed: Node3D = null
var _dwarf: Node3D = null
var _food: Node3D = null
var _farm: Node3D = null
var _status: Label = null
var _dwarf_direction: float = 1.0
var _reported: Dictionary = {}


func _ready() -> void:
	_build_world()
	_build_hud()


func _process(delta: float) -> void:
	_move_dwarf(delta)
	_report_changes()
	_update_hud()


func _build_world() -> void:
	var light := DirectionalLight3D.new()
	light.rotation_degrees = Vector3(-55.0, -35.0, 0.0)
	light.light_energy = 1.1
	add_child(light)

	var floor_mesh := MeshInstance3D.new()
	var plane := PlaneMesh.new()
	plane.size = Vector2(18.0, 12.0)
	floor_mesh.mesh = plane
	var floor_material := StandardMaterial3D.new()
	floor_material.albedo_color = Color(0.32, 0.29, 0.25)
	floor_mesh.mesh.material = floor_material
	floor_mesh.position = Vector3(10.0, 0.0, 9.0)
	add_child(floor_mesh)

	_farm = MeshInstance3D.new()
	var pen := BoxMesh.new()
	pen.size = Vector3(3.5, 0.2, 5.0)
	_farm.mesh = pen
	var pen_material := StandardMaterial3D.new()
	pen_material.albedo_color = Color(0.45, 0.35, 0.2)
	_farm.mesh.material = pen_material
	_farm.position = FARM_POSITION + Vector3(0.0, 0.05, 0.0)
	_farm.add_to_group("farm")
	add_child(_farm)

	_wild = _make_hamster("WildHamster", WILD_START)
	# the original counts the nutrition up to fifty before it looks for food;
	# the demo starts at the limit so the feeding happens right away
	(_wild.get("actor") as RefCounted).call("set_nutrition", 49)
	_farmed = _make_hamster("FarmHamster", FARM_POSITION)
	(_farmed.get("actor") as RefCounted).call("set_farmhamster",
		{"ref": "Farm", "position": FARM_POSITION})

	_food = MeshInstance3D.new()
	_food.name = "Pilzhut"
	var cap := SphereMesh.new()
	cap.radius = 0.22
	cap.height = 0.44
	_food.mesh = cap
	var food_material := StandardMaterial3D.new()
	food_material.albedo_color = Color(0.85, 0.35, 0.3)
	_food.mesh.material = food_material
	_food.position = FOOD_POSITION + Vector3(0.0, 0.22, 0.0)
	_food.add_to_group("food")
	add_child(_food)

	_dwarf = MeshInstance3D.new()
	_dwarf.name = "Dwarf"
	var body := CapsuleMesh.new()
	body.radius = 0.3
	body.height = 1.2
	_dwarf.mesh = body
	var dwarf_material := StandardMaterial3D.new()
	dwarf_material.albedo_color = Color(0.8, 0.7, 0.4)
	_dwarf.mesh.material = dwarf_material
	_dwarf.position = DWARF_START + Vector3(0.0, 0.6, 0.0)
	_dwarf.add_to_group("dwarf")
	add_child(_dwarf)

	var camera := Camera3D.new()
	camera.position = Vector3(10.0, 2.6, 15.2)
	add_child(camera)
	camera.look_at_from_position(camera.position, Vector3(9.5, 0.25, 9.0), Vector3.UP)
	camera.make_current()


func _make_hamster(node_name: String, spawn_position: Vector3) -> Node3D:
	var hamster: Node3D = HamsterActor3D.new()
	hamster.name = node_name
	hamster.position = spawn_position
	add_child(hamster)
	hamster.call("setup", {})
	return hamster


func _move_dwarf(delta: float) -> void:
	if _dwarf == null:
		return
	var target := DWARF_END if _dwarf_direction > 0.0 else DWARF_START
	_dwarf.position.x += _dwarf_direction * 1.2 * delta
	if _dwarf_direction > 0.0 and _dwarf.position.x > target.x:
		_dwarf_direction = -1.0
	elif _dwarf_direction < 0.0 and _dwarf.position.x < target.x:
		_dwarf_direction = 1.0


## Print what changed, so the output panel shows the hamster acting.
func _report_changes() -> void:
	for hamster: Node3D in [_wild, _farmed]:
		if hamster == null:
			continue
		var actor: RefCounted = hamster.get("actor")
		if actor == null:
			continue
		var key := String(hamster.name)
		var signature := "%s|%s|%d" % [
			String(actor.call("get_current_alias")),
			String(actor.call("get_current_clip")),
			int(actor.call("get_queue_size"))]
		if String(_reported.get(key, "")) == signature:
			continue
		_reported[key] = signature
		print("HAMSTER_DEMO %s t=%.1f alias=%s clip=%s pos=%s" % [
			key,
			float(actor.call("get_time")),
			String(actor.call("get_current_alias")),
			String(actor.call("get_current_clip")),
			str((hamster as Node3D).position)])


func _build_hud() -> void:
	var layer := CanvasLayer.new()
	add_child(layer)
	_status = Label.new()
	_status.position = Vector2(16.0, 12.0)
	_status.add_theme_font_size_override("font_size", 15)
	layer.add_child(_status)


func _update_hud() -> void:
	if _status == null:
		return
	_status.text = "%s\n%s\ndwarf x=%.1f" % [
		_describe(_wild), _describe(_farmed), _dwarf.position.x]


func _describe(hamster: Node3D) -> String:
	var actor: RefCounted = hamster.get("actor")
	if actor == null:
		return "no actor"
	return "%s: %s / %s / queue %d" % [
		String(hamster.name),
		String(actor.call("get_current_alias")),
		String(actor.call("get_current_clip")),
		int(actor.call("get_queue_size"))]
