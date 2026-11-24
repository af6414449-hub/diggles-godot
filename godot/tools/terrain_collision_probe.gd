extends SceneTree
## Terrain collision probe.
##
## _flush_terrain_refresh() calls
##   _build_geometry(manifest, variants, changed_cells, changed_cells.is_empty())
## so every rebuild triggered by a dig passes build_collision = false. The
## rebuilt chunk therefore gets no StaticBody3D / CollisionShape3D, while the
## old chunk (with its collision body) was freed at the start of the rebuild.
##
## This probe counts the terrain chunks that carry a collision body before and
## after a dig and dumps the child list of one terrain instance.
##
## Usage:
##   godot --headless --path godot --script res://tools/terrain_collision_probe.gd

var subject: Node3D = null


func _initialize() -> void:
	call_deferred("_run")


func _run() -> void:
	subject = load("res://scenes/multiplayer_test.tscn").instantiate() as Node3D
	subject.extended_world = false
	subject.autonomous_dwarf_work = false
	root.add_child(subject)
	subject.set_process(false)
	await process_frame

	var before: Dictionary = _collision_state()
	print("COLLISION_PROBE before chunks=%d with_body=%d without_body=%d" % [
		before["chunks"], before["with_body"], before["without_body"]])
	_dump_one_instance()

	# Dig one cell in a chunk far from the start cave.
	var point: Vector2i = Vector2i(9, 19)
	var marked: bool = subject.native_mark_corridor_cell(0, point)
	var applied: bool = marked and subject.native_dig_apply_cell(0, point)
	print("COLLISION_PROBE dig %s marked=%s applied=%s" % [str(point), str(marked), str(applied)])
	await process_frame

	var after: Dictionary = _collision_state()
	print("COLLISION_PROBE after chunks=%d with_body=%d without_body=%d" % [
		after["chunks"], after["with_body"], after["without_body"]])

	var lost: Array[String] = []
	var gained: Array[String] = []
	for key: String in before["bodies"].keys():
		if bool(before["bodies"][key]) and not bool(after["bodies"].get(key, false)):
			lost.append(key)
	for key: String in after["bodies"].keys():
		if bool(after["bodies"][key]) and not bool(before["bodies"].get(key, false)):
			gained.append(key)
	print("COLLISION_PROBE chunks_that_lost_collision=%s" % str(lost))
	print("COLLISION_PROBE chunks_that_gained_collision=%s" % str(gained))
	print("COLLISION_PROBE collision_bodies_before=%d after=%d" % [
		int(before["with_body"]), int(after["with_body"])])

	subject.queue_free()
	await process_frame
	quit(0)


## Per terrain chunk: does the MeshInstance3D still carry a usable collision
## body? The CollisionShape3D node has no explicit name, so it must be found
## by class, not by name.
func _collision_state() -> Dictionary:
	var bodies: Dictionary = {}
	var with_body: int = 0
	for key: String in subject.terrain_mesh_nodes.keys():
		var node: MeshInstance3D = subject.terrain_mesh_nodes[key] as MeshInstance3D
		if node == null or not is_instance_valid(node):
			continue
		var has_body: bool = false
		for child: Node in node.get_children():
			if not child is StaticBody3D:
				continue
			for shape: Node in (child as StaticBody3D).get_children():
				if shape is CollisionShape3D and (shape as CollisionShape3D).shape != null:
					has_body = true
					break
			if has_body:
				break
		if has_body:
			with_body += 1
		bodies[key] = has_body
	return {"chunks": bodies.size(), "with_body": with_body,
		"without_body": bodies.size() - with_body, "bodies": bodies}


func _dump_one_instance() -> void:
	var keys: Array = subject.terrain_mesh_nodes.keys()
	if keys.is_empty():
		print("COLLISION_PROBE no terrain instances")
		return
	var key: String = str(keys[0])
	var node: MeshInstance3D = subject.terrain_mesh_nodes[key] as MeshInstance3D
	var children: Array[String] = []
	for child: Node in node.get_children():
		children.append(str(child.name))
	print("COLLISION_PROBE sample key=%s children=%s" % [key, str(children)])
	for child: Node in node.get_children():
		var grandchildren: Array[String] = []
		for grandchild: Node in child.get_children():
			var detail: String = str(grandchild.name)
			if grandchild is CollisionShape3D:
				var shape_node: CollisionShape3D = grandchild as CollisionShape3D
				detail += "(shape=%s" % ("null" if shape_node.shape == null else shape_node.shape.get_class())
				detail += ",disabled=%s" % str(shape_node.disabled)
				detail += ")"
			grandchildren.append(detail)
		print("COLLISION_PROBE sample body=%s children=%s" % [str(child.name), str(grandchildren)])
		print("COLLISION_PROBE sample body class=%s layer=%d" % [
			str(child.get_class()), int((child as CollisionObject3D).collision_layer)])
