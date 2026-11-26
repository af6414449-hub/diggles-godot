extends SceneTree
## The diagnostic frame of the heading of the dwarves of the campaign.
##
## The frame shows one dwarf per route of the board. The green bar is the
## rendered movement of the dwarf, the red bar is the rendered front of its
## body. The gap between the two bars is the divergence of the chapter from
## the scene of the multiplayer, where the front of the body is always the
## movement.
##
## The scene runs windowed and saves the frame by itself:
##   Godot_v4.7.2-stable_win64_console.exe --path godot \
##       --script res://tools/native_campaign_heading_overlay.gd -- \
##       --capture-path <absolute path>

const DWARF: Script = preload("res://scripts/native_campaign_dwarf.gd")
const DIG: Script = preload("res://scripts/native_campaign_dig_test.gd")

const STEP: float = 1.0 / 60.0
const RENDER_DEPTH_SCALE: float = 0.5
const START_CELL: Vector2i = Vector2i(10, 10)
## The routes of the frame: the name, the cell of the order and the shift of
## the dwarf on the screen.
const ROUTES: Array = [
	["+X", Vector2i(14, 10)],
	["-X", Vector2i(6, 10)],
	["Y down", Vector2i(10, 14)],
	["Y up", Vector2i(10, 6)],
	["diagonal", Vector2i(13, 7)],
]


class FakeProfile:
	extends RefCounted
	var data: Dictionary = {"normals": []}
	func cell_material(_cell: Vector2i) -> int:
		return 2
	func ground_file(_cell: Vector2i, _variant: int) -> String:
		return "Gnd_A01.tga"
	func detail_texture(_cell: Vector2i, _part: int) -> String:
		return "50PGray.tga"
	func detail_slot(_detail: String) -> Vector2:
		return Vector2.ZERO
	func terrain_material(_variant: int, _a: bool, _b: bool, _file: String, _c: bool,
			_dir: String, _d: bool) -> Material:
		return StandardMaterial3D.new()
	func terrain_channels(_cell: Vector2i, _local: Vector3, _normal: Array,
			_sky: float) -> Dictionary:
		return {"diffuse": Color.WHITE, "secondary": Color(0.0, 0.0, 0.0, 1.0)}


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	var args: PackedStringArray = OS.get_cmdline_user_args()
	var capture_index: int = args.find("--capture-path")
	var capture_path: String = args[capture_index + 1] if capture_index >= 0 else ""

	var root := Node3D.new()
	root.name = "CampaignRenderSpace"
	root.scale.z = RENDER_DEPTH_SCALE
	root.position.z = 7.0
	get_root().add_child(root)
	var camera := Camera3D.new()
	camera.name = "ChapterCamera"
	camera.current = true
	camera.fov = 42.0
	camera.near = 0.05
	camera.far = 3000.0
	root.add_child(camera)
	var light := DirectionalLight3D.new()
	light.rotation = Vector3(deg_to_rad(-40.0), deg_to_rad(30.0), 0.0)
	light.light_energy = 1.6
	root.add_child(light)
	var world := WorldEnvironment.new()
	var environment := Environment.new()
	environment.background_mode = Environment.BG_COLOR
	environment.background_color = Color(0.12, 0.13, 0.16)
	environment.ambient_light_source = Environment.AMBIENT_SOURCE_COLOR
	environment.ambient_light_color = Color(0.6, 0.62, 0.68)
	environment.ambient_light_energy = 0.9
	world.environment = environment
	root.add_child(world)

	var hud := CanvasLayer.new()
	get_root().add_child(hud)
	var dig: RefCounted = DIG.new()
	var profile := FakeProfile.new()
	dig.setup(root, camera, profile, [], {}, hud, Label.new())
	var dwarfs: RefCounted = DWARF.new()
	dwarfs.setup(root, camera, dig, profile, Label.new())

	for index: int in range(ROUTES.size()):
		_build_route(dwarfs, root, hud, ROUTES[index][0], ROUTES[index][1], index)

	var focus := Vector3(float(ROUTES.size() - 1) * 6.0, -float(START_CELL.y) - 0.5, 15.0)
	camera.position = focus + Vector3(0.0, sin(0.29), cos(0.29)) * 34.0
	camera.look_at(focus)

	for frame: int in range(6):
		await process_frame
	if capture_path.is_empty():
		print("CAMPAIGN_HEADING_OVERLAY_READY path=none")
		quit(0)
		return
	var image: Image = get_root().get_texture().get_image()
	var error: int = image.save_png(capture_path)
	print("CAMPAIGN_HEADING_OVERLAY_READY path=%s error=%d size=%s" % [capture_path, error,
		str(image.get_size())])
	quit(0 if error == OK else 1)


## One dwarf of the frame: the body of the original, the bar of the movement
## and the bar of the front of the body.
func _build_route(dwarfs: RefCounted, root: Node3D, hud: CanvasLayer, route_name: String,
		cell: Vector2i, index: int) -> void:
	var shift: float = float(index) * 6.0
	var dwarf := Node3D.new()
	dwarf.name = "Zwerg_%d" % index
	dwarf.position = Vector3(float(START_CELL.x) + 0.5 + shift, -float(START_CELL.y) - 0.5, 15.0)
	root.add_child(dwarf)
	dwarfs.register_dwarf(dwarf)

	# The direction of the route of the dwarf: the same rule as the chapter.
	var direction := Vector2(float(cell.x - START_CELL.x), float(START_CELL.y - cell.y))
	if direction.length_squared() <= 0.0:
		direction = Vector2.RIGHT
	direction = direction.normalized()
	dwarfs.call("_set_dwarf_heading", dwarf, float(dwarfs.call("_heading_of_direction", direction)))
	dwarfs.call("_show_dwarf_animation_frame", dwarf, &"gehen_loop", 0)

	# The rendered movement of the dwarf and the rendered front of its body.
	# The rows of the board grow downwards, the world Y grows upwards: the
	# movement of the board is (dx, dy) with dy = the row of the start minus
	# the row of the target (native_campaign_dwarf.gd:_walk_heading_delta).
	var rendered_movement := Vector3(direction.x, direction.y, 0.0).normalized()
	var front: Vector3 = dwarf.global_transform.basis.z.normalized()
	var angle: float = rad_to_deg(acos(clampf(rendered_movement.dot(front), -1.0, 1.0)))
	_bar(root, dwarf.global_position + Vector3(0.0, 0.12, 0.0), rendered_movement, Color(0.25, 0.9, 0.3))
	_bar(root, dwarf.global_position + Vector3(0.0, 1.15, 0.0), front, Color(0.95, 0.25, 0.2))

	var label := Label.new()
	label.text = "%s: %.0f deg" % [route_name, angle]
	label.position = Vector2(20.0 + float(index) * 150.0, 20.0)
	label.add_theme_color_override("font_color", Color(0.95, 0.95, 0.95))
	hud.add_child(label)
	print("HEADING_OVERLAY route=%s angle=%.1f move=%s front=%s" % [route_name, angle,
		str(rendered_movement), str(front)])


## A bar of the frame: a thin box along the direction.
func _bar(root: Node3D, origin: Vector3, direction: Vector3, color: Color) -> void:
	var holder := Node3D.new()
	holder.position = origin
	holder.basis = Basis.looking_at(direction, Vector3.UP)
	root.add_child(holder)
	var bar := MeshInstance3D.new()
	var box := BoxMesh.new()
	box.size = Vector3(0.12, 0.12, 1.6)
	bar.mesh = box
	var material := StandardMaterial3D.new()
	material.albedo_color = color
	material.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
	bar.material_override = material
	holder.add_child(bar)
	holder.position += direction * 0.8
