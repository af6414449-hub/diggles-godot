extends SceneTree
## The self-test of the excavation of the campaign.
##
## The checks are deterministic: they build their own map of blocks and never
## read the position of the mouse.
const DIG = preload("res://scripts/native_campaign_dig_test.gd")
const CAVE_SKIN = preload("res://scripts/native_cave_skin.gd")
const RULES = preload("res://scripts/native_dig_rules.gd")
const NORMALS_PATH := "res://models/native_model_material.json"


class FakeProfile:
	extends RefCounted
	## The profile of the terrain of the test map. The material of the cell
	## (12, 12) is granite, every other cell is earth.
	var data: Dictionary = {"normals": []}

	func cell_material(cell: Vector2i) -> int:
		return 0 if cell == Vector2i(12, 12) else 2
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
	var root := Node3D.new()
	get_root().add_child(root)
	var camera := Camera3D.new()
	root.add_child(camera)
	var hud := CanvasLayer.new()
	get_root().add_child(hud)
	var label := Label.new()
	hud.add_child(label)
	var dig: RefCounted = DIG.new()
	var profile := FakeProfile.new()
	profile.data["normals"] = _normal_table()
	# An original frame of wood far away from the cells of the test, so that
	# the module has a model to copy for the frames of the new tunnels.
	var original := Node3D.new()
	original.name = "OriginalHolzstuetze"
	original.position = Vector3(200.0, -200.0, 15.0)
	original.set_meta("native_class", "Dummy_Multi_Holzstuetze_a")
	root.add_child(original)
	dig.setup(root, camera, profile, [], {}, hud, label)
	assert(dig.support_sources.size() == 1)
	assert(dig.original_supports.size() == 1)

	_check_toolbar(dig)
	_check_granite(dig)
	_check_erase_corridor(dig)
	_check_dig_flow(dig)
	_check_template_support_survives_tunnel(dig)
	_check_support_below_open_shaft_disappears(dig)
	_check_open_cell_not_marked_again(dig)
	_check_hover(dig)
	_check_right_click_clears_tool(dig)
	_check_corridor_supports_are_sparse(dig)
	_check_corridor_support_blocked_by_open_upper_space(dig)
	_check_joined_corridor_has_no_duplicate_supports(dig)
	_check_cave_requires_tunnel(dig)
	_check_cave_skin_size_matches_brush(dig)
	_check_cave_frame_appears_after_completion(dig)
	_check_cave_uses_separate_skin(dig)
	_check_cave_frame_stands_on_the_dug_floor(dig)
	_check_falling_object_reaches_solid_floor(dig)
	_check_object_without_ground_is_hidden(dig)
	_check_attachment_is_removed(dig)

	print("CAMPAIGN_DIG_TEST_OK icons=1 granite_protected=1 erase_corridor=1 erase_cave=1 " \
		+ "native_strike=1 open_cell_not_marked_again=1 corridor_supports_are_sparse=1 " \
		+ "corridor_support_blocked_by_open_upper_space=1 joined_corridor_has_no_duplicate_supports=1 " \
		+ "cave_requires_connection=1 cave_skin_size_matches_brush=1 cave_frame_appears_after_completion=1 " \
		+ "cave_uses_separate_skin=1 falling_object_reaches_solid_floor=1 object_without_ground_is_hidden=1 " \
		+ "moss_removed=1 source_support_survives_tunnel=1 source_support_removed_by_cave=1 " \
		+ "support_below_shaft_removed=1 cave_touches_tunnel=1 cave_frame_on_dug_floor=1 " \
		+ "right_click_clears_tool=1 hover_tracks_mouse=1")
	quit(0)


## The toolbar of the original: seven icons of 40x40, no other button.
func _check_toolbar(dig: RefCounted) -> void:
	assert(dig.toolbar.get_child_count() == 7)
	assert((dig.toolbar.get_child(0) as TextureButton).texture_normal.get_size() == Vector2(40, 40))
	assert((dig.toolbar.get_child(6) as TextureButton).texture_normal.get_size() == Vector2(40, 40))


## The granite of the map is not diggable.
func _check_granite(dig: RefCounted) -> void:
	assert(dig.can_dig(Vector2i(10, 10)))
	assert(not dig.can_dig(Vector2i(12, 12)))


## The erasure of a tunnel takes the mark away.
func _check_erase_corridor(dig: RefCounted) -> void:
	dig._mark_corridor([Vector2i(10, 10)] as Array[Vector2i])
	assert(dig.marked_count() == 1)
	dig.eraser.begin(Vector3(10, 10, 15), Rect2i(0, 0, 512, 640))
	dig._erase(Vector2(10, 10))
	assert(dig.marked_count() == 0)
	assert(dig.queue.is_empty())


## The native transition of the blocks opens the cell and the mark is done.
func _check_dig_flow(dig: RefCounted) -> void:
	dig._mark_corridor([Vector2i(10, 10)] as Array[Vector2i])
	dig.start_digging()
	for step: int in range(40):
		if dig.queue.is_empty():
			break
		dig.advance(0.25)
	assert(dig.excavated_cells.has(Vector2i(10, 10)))
	assert(dig.marked_count() == 0)
	assert(dig.can_dig(Vector2i(11, 10)))


## The original chapter places the support before digging. Opening its
## tunnel must reveal it rather than deleting it.
func _check_template_support_survives_tunnel(dig: RefCounted) -> void:
	var support := Node3D.new()
	support.name = "TemplateSupportTunnelTest"
	support.position = Vector3(10.5, -10.5, 15.04)
	support.set_meta("native_class", "Dummy_Multi_Holzstuetze_a")
	dig.root.add_child(support)
	dig.newly_open.clear()
	dig.newly_open[Vector2i(10, 10)] = true
	dig._settle_objects()
	assert(support.visible)
	support.queue_free()


## The crossing of a horizontal and a vertical tunnel takes the support of the
## horizontal tunnel away: the shaft opens the space above it.
func _check_support_below_open_shaft_disappears(dig: RefCounted) -> void:
	var support := Node3D.new()
	support.name = "TemplateSupportShaftTest"
	support.position = Vector3(24.5, -24.5, 15.04)
	support.set_meta("native_class", "Dummy_Multi_Holzstuetze_a")
	dig.root.add_child(support)
	dig.newly_open.clear()
	dig.newly_open[Vector2i(24, 23)] = true
	dig._settle_objects()
	assert(not support.visible)
	support.queue_free()


## An open cell is not marked a second time.
func _check_open_cell_not_marked_again(dig: RefCounted) -> void:
	assert(dig._is_open(Vector2i(10, 10)))
	dig._mark_corridor([Vector2i(10, 10)] as Array[Vector2i])
	assert(dig.marked_count() == 0)
	assert(dig.queue.is_empty())


## The preview follows the mouse.
func _check_hover(dig: RefCounted) -> void:
	dig._choose(true, "Туннель")
	dig._update_hover_at(Vector2(20, 20))
	assert(dig.hover_mesh.mesh != null)
	var first_hover: AABB = dig.hover_mesh.mesh.get_aabb()
	dig._update_hover_at(Vector2(28, 20))
	assert(dig.hover_mesh.mesh != null)
	assert(dig.hover_mesh.mesh.get_aabb().position != first_hover.position)


## The right mouse button clears the tool and the button of the toolbar.
func _check_right_click_clears_tool(dig: RefCounted) -> void:
	dig._choose(true, "Туннель")
	assert(dig.tool == "Туннель")
	var event := InputEventMouseButton.new()
	event.button_index = MOUSE_BUTTON_RIGHT
	event.pressed = true
	event.position = Vector2(100, 100)
	assert(dig.handle_input(event))
	assert(dig.tool.is_empty())
	for child: Node in dig.toolbar.get_children():
		if child is TextureButton:
			assert(not (child as TextureButton).button_pressed)


## The frames of wood of a tunnel are rare: much less than the cells.
func _check_corridor_supports_are_sparse(dig: RefCounted) -> void:
	_clear_supports(dig)
	dig.excavated_cells.clear()
	_open_row(dig, 40, 59, 30)
	dig._decorate_new_passages()
	var generated: int = _count_supports(dig)
	assert(generated >= 1)
	assert(generated * 4 < 20)
	assert(generated * 4 < dig.excavated_cells.size())


## A tunnel under an open space carries no frame of wood.
func _check_corridor_support_blocked_by_open_upper_space(dig: RefCounted) -> void:
	var before: int = _count_supports(dig)
	assert(before >= 1)
	var support_cell: Vector2i = _first_support_cell(dig)
	_open_row(dig, support_cell.x - 1, support_cell.x + 1, support_cell.y - 1)
	dig._revalidate_supports()
	assert(_count_supports(dig) == before - 1)
	# The frame does not come back under the open space above it.
	dig._decorate_new_passages()
	assert(_count_supports(dig) == before - 1)


## A tunnel that joins another one does not put a second row of frames next to
## the frames of the original.
func _check_joined_corridor_has_no_duplicate_supports(dig: RefCounted) -> void:
	_clear_supports(dig)
	dig.excavated_cells.clear()
	_open_row(dig, 40, 59, 30)
	var original := Node3D.new()
	original.name = "OriginalHolzstuetze"
	original.position = Vector3(50.0, -30.0, 15.0)
	original.set_meta("native_class", "Dummy_Multi_Holzstuetze_a")
	dig.root.add_child(original)
	dig.support_sources.append(original)
	dig.original_supports.append(Vector2(50.0, 30.0))
	dig._decorate_new_passages()
	assert(_count_supports(dig) == 0)
	# A second row of the tunnel that joins the first one.
	_open_row(dig, 40, 59, 32)
	dig._decorate_new_passages()
	for cell: Vector2i in dig.decorated:
		var support: Node3D = dig.decorated[cell]
		var distance: float = Vector2(support.position.x, -support.position.y).distance_to(Vector2(50.0, 30.0))
		assert(distance >= dig.SUPPORT_MIN_DISTANCE)
	_clear_supports(dig)


## A cave without a tunnel is refused, a cave that touches a tunnel is not.
func _check_cave_requires_tunnel(dig: RefCounted) -> void:
	var cave_cells: Array[Vector3i] = dig._cave_cells(3, Vector2i(100, 100))
	assert(not cave_cells.is_empty())
	dig._mark_cave(3, Vector2i(100, 100))
	assert(dig.marked_cave_cells.is_empty())
	assert(dig.cave_groups.is_empty())
	var bottom: int = -1
	for sample: Vector3i in cave_cells:
		bottom = maxi(bottom, sample.z)
	var min_x: int = 9999
	var max_x: int = -9999
	for sample: Vector3i in cave_cells:
		if sample.z == bottom:
			min_x = mini(min_x, sample.x)
			max_x = maxi(max_x, sample.x)
	# A partial support row must still be refused.
	dig.marked_corridor_cells[Vector2i(min_x, bottom + 1)] = true
	dig._mark_cave(3, Vector2i(100, 100))
	assert(dig.marked_cave_cells.is_empty())
	dig.marked_corridor_cells.clear()
	# The complete legal horizontal base is accepted.
	for x: int in range(min_x, max_x + 1):
		dig.marked_corridor_cells[Vector2i(x, bottom + 1)] = true
	dig._mark_cave(3, Vector2i(100, 100))
	assert(dig.marked_cave_cells.size() > 0)
	assert(dig.cave_groups.size() == 1)
	# The accepted cave touches the tunnel it is cut from.
	assert(dig._touches_tunnel(cave_cells))


## The size of the brush chooses the size of the frame of the cave.
func _check_cave_skin_size_matches_brush(dig: RefCounted) -> void:
	for brush: int in range(1, 5):
		assert(CAVE_SKIN.skin_key(brush) == "urw_caves_%d_a_a" % brush)
		assert(dig.cave_skin_resources.has(brush))
		assert(not (dig.cave_skin_resources[brush] as Array).is_empty())


## The frame of the cave appears only when the cave is dug to the end.
func _check_cave_frame_appears_after_completion(dig: RefCounted) -> void:
	assert(dig.finished_caves.is_empty())
	assert(dig.cave_frames.is_empty())
	var support := Node3D.new()
	support.name = "TemplateSupportCaveTest"
	var support_cell: Vector2i = dig.marked_cave_cells.keys()[0]
	support.position = Vector3(float(support_cell.x) + 0.5,
		-(float(support_cell.y) + 0.5), 15.04)
	support.set_meta("native_class", "Dummy_Multi_Holzstuetze_a")
	dig.root.add_child(support)
	for cell: Vector2i in dig.marked_cave_cells.keys():
		dig._clear_mark(cell)
	dig._finish_caves()
	assert(not support.visible)
	support.queue_free()
	assert(dig.finished_caves.size() == 1)
	assert(dig.cave_frames.size() == 1)
	var frame: Node3D = dig.cave_frames[0]
	assert(frame.name.begins_with("CaveFrame_"))
	assert(frame.get_child_count() >= 1)
	assert(dig.excavated_cave_cells.size() > 0)
	# The frame stands in the middle of the cave that was dug.
	var center: Vector2 = dig.finished_caves[0]["center"]
	assert(center.x > 80.0 and center.x < 120.0)
	assert(center.y > 60.0 and center.y < 100.0)


## The cells of a cave are not dressed by the rule of the corridors.
func _check_cave_uses_separate_skin(dig: RefCounted) -> void:
	_clear_supports(dig)
	dig.excavated_cells.clear()
	for cell: Vector2i in dig.excavated_cave_cells.keys():
		dig.excavated_cells[cell] = true
	dig._decorate_new_passages()
	for cell: Vector2i in dig.decorated:
		assert(not dig.excavated_cave_cells.has(cell))
	assert(dig.cave_frames.size() == 1)


## The frame of the cave stands on the floor that was really dug, not on the
## depth that the brush asked for.
func _check_cave_frame_stands_on_the_dug_floor(dig: RefCounted) -> void:
	var record: Dictionary = dig.finished_caves[0]
	var cells: Array = record["cells"]
	var frame: Node3D = dig.cave_frames[0]
	# The cave was finished without a dig: the depth of the brush decides.
	assert(is_equal_approx(frame.position.z, float(record["chamber_level"])))
	# After the dig the frame follows the floor that the transition left.
	dig.excavated_cells.clear()
	for cell: Vector2i in cells:
		dig.excavated_cells[cell] = true
	dig.block_overrides[cells[0]] = 80
	var floor_level: float = dig._cave_floor_level(cells)
	assert(floor_level > 0.0)
	dig._spawn_cave_frame(record)
	var frames: Array = dig.cave_frames
	var dug_frame: Node3D = frames[frames.size() - 1]
	assert(is_equal_approx(dug_frame.position.z, floor_level))
	dig.cave_frames.remove_at(dig.cave_frames.size() - 1)
	dug_frame.queue_free()


## A free object falls to the ground of its cell and stays there.
func _check_falling_object_reaches_solid_floor(dig: RefCounted) -> void:
	var stone := Node3D.new()
	stone.name = "SteinTest"
	stone.position = Vector3(20.0, -20.0, 14.5)
	stone.set_meta("native_class", "Stein")
	dig.root.add_child(stone)
	dig.block_overrides[Vector2i(20, 20)] = 80
	dig.newly_open.clear()
	dig.newly_open[Vector2i(20, 20)] = true
	dig._settle_objects()
	assert(dig.falling_objects.has(stone))
	var target: float = float(dig.falling_objects[stone])
	assert(target < 14.5)
	for step: int in range(80):
		dig._step_falling(0.1)
	assert(is_equal_approx(stone.position.z, target))
	assert(dig.falling_objects.is_empty())
	# The object is not handled a second time.
	dig.newly_open.clear()
	dig.newly_open[Vector2i(20, 20)] = true
	dig._settle_objects()
	assert(dig.falling_objects.is_empty())


## An object without a ground of the map leaves the world instead of falling
## for ever.
func _check_object_without_ground_is_hidden(dig: RefCounted) -> void:
	var lost := Node3D.new()
	lost.name = "SteinLost"
	lost.position = Vector3(300.0, -300.0, 14.5)
	lost.set_meta("native_class", "Stein")
	dig.root.add_child(lost)
	dig.block_overrides[Vector2i(300, 300)] = 999999
	dig.newly_open.clear()
	dig.newly_open[Vector2i(300, 300)] = true
	dig._settle_objects()
	assert(not lost.visible)


## The moss of the original disappears with the cell it lies on.
func _check_attachment_is_removed(dig: RefCounted) -> void:
	var moss := Node3D.new()
	moss.name = "MoosTest"
	moss.position = Vector3(22.0, -22.0, 15.0)
	moss.set_meta("native_class", "Dummy_Moos_hm_d")
	dig.root.add_child(moss)
	dig.newly_open.clear()
	dig.newly_open[Vector2i(22, 22)] = true
	dig._settle_objects()
	assert(not moss.visible)


## A row of cells that the excavation opened.
func _open_row(dig: RefCounted, x0: int, x1: int, y: int) -> void:
	for x: int in range(x0, x1 + 1):
		var cell := Vector2i(x, y)
		dig.block_overrides[cell] = 80
		dig.excavated_cells[cell] = true


func _clear_supports(dig: RefCounted) -> void:
	for cell: Vector2i in dig.decorated.keys():
		var support: Node3D = dig.decorated[cell]
		if is_instance_valid(support):
			dig.root.remove_child(support)
			support.queue_free()
	dig.decorated.clear()


func _count_supports(dig: RefCounted) -> int:
	var count: int = 0
	for child: Node in dig.root.get_children():
		if child.name.begins_with("DugHolzstuetze_"):
			count += 1
	return count


func _first_support_cell(dig: RefCounted) -> Vector2i:
	for cell: Vector2i in dig.decorated:
		return cell
	return Vector2i(-1, -1)


func _normal_table() -> Array:
	var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string(NORMALS_PATH))
	if not parsed is Dictionary:
		return []
	return (parsed as Dictionary).get("normal_table", [])
