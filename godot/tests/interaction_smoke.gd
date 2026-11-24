extends SceneTree

func _initialize() -> void:
	call_deferred("_check")

func _check() -> void:
	root.size = Vector2i(1280, 720)
	change_scene_to_file("res://scenes/terrain_reference.tscn")
	await process_frame
	await process_frame
	var scene: Node3D = current_scene
	assert(scene != null)
	assert(scene.dwarf_nodes.size() > 0)
	var dwarf: Node3D = scene.dwarf_nodes[0]
	var visible_mesh: MeshInstance3D = null
	for mesh_node: Node in dwarf.find_children("*", "MeshInstance3D", true, false):
		if (mesh_node as MeshInstance3D).is_visible_in_tree():
			visible_mesh = mesh_node as MeshInstance3D
			break
	assert(visible_mesh != null)
	var point: Vector2 = scene.camera.unproject_position(visible_mesh.global_transform * visible_mesh.get_aabb().get_center())
	var click: InputEventMouseButton = InputEventMouseButton.new()
	click.button_index = MOUSE_BUTTON_LEFT
	click.pressed = true
	click.position = point
	scene.get_viewport().push_input(click, true)
	print("DWARF_CLICK_CHECK selected=%s point=%s" % [scene.selected_dwarf == dwarf, point])
	assert(scene.selected_dwarf == dwarf)
	click.pressed = false
	scene.get_viewport().push_input(click, true)
	scene._handle_tap(Vector2(10, 10))
	assert(scene.selected_dwarf == dwarf)
	scene._mark_corridor_from(Vector2i(28, 9))
	scene._mark_corridor_from(Vector2i(31, 9))
	print("CORRIDOR_CHECK cells=%d" % scene.corridor_marked_cells.size())
	assert(scene.corridor_marked_cells.size() == 2)
	var first: MeshInstance3D = scene.corridor_marker_nodes[Vector2i(11, 3)]
	var second: MeshInstance3D = scene.corridor_marker_nodes[Vector2i(12, 3)]
	assert(first.get_aabb().size.x >= 2.5)
	assert((first.material_override as ShaderMaterial).get_shader_parameter("exposed_edges").y == 0.0)
	assert((second.material_override as ShaderMaterial).get_shader_parameter("exposed_edges").x == 0.0)
	var barrel: Node3D = scene.barrels.back()
	scene._command_selected_dwarf(scene.camera.unproject_position(barrel.global_position + Vector3.UP * 0.25))
	for tick in range(1200):
		scene._update_dwarf_locomotion(1.0 / 60.0)
	assert(not scene.barrels.has(barrel))
	print("BARREL_OPEN_CHECK passed")
	quit()
