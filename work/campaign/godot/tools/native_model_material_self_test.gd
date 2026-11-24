extends SceneTree

const MODEL: Script = preload("res://scripts/native_model_material.gd")
var assertions: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func check(value: bool, message: String) -> void:
	assertions += 1
	if not value:
		failures += 1
		push_error("NATIVE_MODEL_MATERIAL_FAILED " + message)


func _run() -> void:
	var helper: RefCounted = MODEL.new()
	check(helper.load_fixture(), "load source fixture")
	if helper.data.is_empty():
		quit(1)
		return
	var legacy: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/multi_start_010_models.json"))
	for object_name: String in helper.data["objects"]:
		var object_data: Dictionary = helper.data["objects"][object_name]
		var surfaces: Array = object_data["surfaces"]
		for surface_index: int in range(surfaces.size()):
			var surface: Dictionary = surfaces[surface_index]
			var old: Dictionary = legacy["objects"]["wandboden.3db::" + object_name]["surfaces"][surface_index]
			var normals: PackedVector3Array = helper.source_normals(surface)
			check(normals == helper.source_normals(old), "legacy brightness decodes as indices " + object_name)
			check(normals.size() == surface["points"].size(), "one source normal per vertex")
			var reflected: PackedVector3Array = helper.godot_local_normals(surface)
			for index: int in range(normals.size()):
				check(absf(normals[index].length() - 1.0) < 0.00001, "sphere unit vector")
				check(reflected[index] == Vector3(normals[index].x,-normals[index].y,normals[index].z), "point/normal same reflection")
			var bytes: PackedByteArray = FileAccess.get_file_as_bytes("res://textures/models/" + str(surface["texture"]))
			var hash_context: HashingContext = HashingContext.new()
			hash_context.start(HashingContext.HASH_SHA256)
			hash_context.update(bytes)
			check(hash_context.finish().hex_encode() == str(surface["texture_sha256"]), "unmodified original albedo")
	var wall: Dictionary = helper.data["objects"]["wand_kaserne_j"]["surfaces"][0]
	var floor_surface: Dictionary = helper.data["objects"]["boden_kaserne_c"]["surfaces"][0]
	check(helper.source_normals(wall)[0].z > 0.99, "183 means +Z wall normal")
	check(helper.source_normals(floor_surface)[0].y < -0.99, "168 means -Y floor normal")
	check(helper.source_normals({"points":[[0,0,0]],"normal_indices":[256]}).is_empty(), "reject bad normal index")
	check(helper.source_normals({"points":[[0,0,0]],"normal_indices":[1.5]}).is_empty(), "reject fractional normal index")
	check(helper.source_normals({"points":[[0,0,0]],"normal_indices":[]}).is_empty(), "reject missing stream")
	var packed: Dictionary = MODEL.rgb555_pre_visibility(31 << 10, 1.0, Vector3i.ZERO)
	check(packed["diffuse"] == Color(248.0/255.0,0,0), "RGB555 red packing, not grayscale")
	check(packed["secondary"] == Color.BLACK, "no overflow")
	var overflow: Dictionary = MODEL.rgb555_pre_visibility(0x7fff, 1.0, Vector3i(300,0,-300))
	check(overflow["diffuse"] == Color(1,248.0/255.0,0), "per-channel additive and clamps")
	check(is_equal_approx(overflow["secondary"].r,256.0/255.0), "model overflow is not terrain's 64 cap")
	check(MODEL.rgb555_pre_visibility(0x7fff,0.0,Vector3i.ZERO)["diffuse"] == Color.BLACK, "zero input intensity")
	if OS.get_cmdline_user_args().has("--gpu"):
		await _gpu(helper)
	print("NATIVE_MODEL_MATERIAL_SELF_TEST_%s assertions=%d" % ["OK" if failures==0 else "FAILED",assertions])
	quit(0 if failures==0 else 1)


func _gpu(helper: RefCounted) -> void:
	var scene: Node3D = Node3D.new()
	root.add_child(scene)
	var camera: Camera3D = Camera3D.new()
	camera.position.z = 2.0
	camera.projection = Camera3D.PROJECTION_ORTHOGONAL
	camera.size = 2.0
	scene.add_child(camera)
	var image: Image = Image.create_empty(1,1,false,Image.FORMAT_RGBA8)
	image.set_pixel(0,0,Color(128.0/255.0,128.0/255.0,128.0/255.0))
	var material: ShaderMaterial = helper.single_texture_preview(ImageTexture.create_from_image(image),4)
	check(material != null, "explicit MODULATE material")
	check(helper.single_texture_preview(null,24) == null, "unsupported stage rejected")
	var builder: SurfaceTool = SurfaceTool.new()
	builder.begin(Mesh.PRIMITIVE_TRIANGLES)
	builder.set_custom_format(0,SurfaceTool.CUSTOM_RGBA_FLOAT)
	for point: Vector3 in [Vector3(-1,-1,0),Vector3(1,-1,0),Vector3(1,1,0),Vector3(-1,-1,0),Vector3(1,1,0),Vector3(-1,1,0)]:
		builder.set_uv(Vector2.ZERO)
		builder.set_color(Color(64.0/255.0,64.0/255.0,64.0/255.0))
		builder.set_custom(0,Color(32.0/255.0,0,0))
		builder.add_vertex(point)
	var instance: MeshInstance3D = MeshInstance3D.new()
	instance.mesh = builder.commit()
	instance.material_override = material
	scene.add_child(instance)
	await process_frame
	await RenderingServer.frame_post_draw
	var frame: Image = root.get_texture().get_image()
	var pixel: Color = frame.get_pixel(frame.get_width()>>1,frame.get_height()>>1)
	var gamma: float = float(helper.data["gamma_defaults"]["gamma"])
	var staged: float = (128.0/255.0) * (64.0/255.0)
	check(absf(pixel.r - pow(staged+32.0/255.0,1.0/gamma)) < 2.0/255.0, "GPU secondary before gamma")
	check(absf(pixel.g - pow(staged,1.0/gamma)) < 2.0/255.0, "GPU byte albedo times actual diffuse")
	check(absf(pixel.g-pixel.b) < 1.0/255.0, "GPU channel separation")
	print("NATIVE_MODEL_MATERIAL_GPU_PIXEL ",pixel)
	scene.queue_free()
