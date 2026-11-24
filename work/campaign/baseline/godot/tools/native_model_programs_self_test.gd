extends SceneTree
var checks: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func check(value: bool, message: String) -> void:
	checks += 1
	if not value:
		failures += 1
		push_error("NATIVE_MODEL_PROGRAM_FAILED "+message)


func _run() -> void:
	var data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_model_programs.json"))
	var light: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_world_model_lighting.json"))
	var gain: Dictionary = light["gain"]
	check(int(gain["terrain_subobject_offset"])+int(gain["terrain_gain_offset"])==int(gain["manager_gain_offset"]),"terrain and model gain address identity")
	check(float(gain["default"])==PackedFloat32Array([0.1])[0],"source float32 constructor gain")
	var floor_program: Dictionary = data["objects"]["wandboden.3db::boden_kaserne_c"][0]["program"]
	var wall_program: Dictionary = data["objects"]["wandboden.3db::wand_kaserne_j"][0]["program"]
	check(floor_program["slot"]==1.0 and floor_program["name"]=="model_solid" and floor_program["alpha_ref"]==127.0,"original floor link selects solid, not alpha statistics")
	check(wall_program["slot"]==3.0 and wall_program["name"]=="model_blend" and wall_program["alpha_ref"]==0.0,"original wall link selects blend")
	check(floor_program["color_op"]==4.0 and wall_program["color_op"]==4.0 and wall_program["color_arg2"]==1.0,"source texture times current vertex diffuse")
	check(wall_program["alpha_arg2"]==3.0 and wall_program["texture_factor"]==4294967295.0,"alpha uses original white texture factor")
	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	subject.set_process(false)
	var solid: int = 0
	var blended: int = 0
	var consistent: bool = true
	var materials: Dictionary = {}
	for record: Dictionary in subject.model_light_records:
		var program: Dictionary = record["program"]
		var material: ShaderMaterial = record["material"]
		var shader: Shader = material.shader
		var expected_path: String = "res://shaders/native_world_model_blend.gdshader" if program["name"]=="model_blend" else "res://shaders/native_world_model.gdshader"
		consistent = consistent and shader.resource_path==expected_path \
			and bool(material.get_shader_parameter("alpha_cutout")) \
			and absf(float(material.get_shader_parameter("alpha_threshold"))-float(program["alpha_ref"])/255.0)<0.000001
		if program["name"]=="model_blend":
			blended += 1
		else:
			solid += 1
		materials[str(program["name"])] = material
	check(consistent,"every production surface receives its own source program and alpha reference")
	check(solid>0 and blended>0 and solid+blended==32,"both source modes integrated without losing surfaces")
	check(subject.source_profile.world_model_lighting["gain"]["default"]==subject.source_profile.terrain_render["constants"]["gain"],"scene shares the original gain input")
	print("NATIVE_MODEL_PROGRAM_SCENE solid=%d blend=%d" % [solid,blended])
	subject.queue_free()
	await process_frame
	if OS.get_cmdline_user_args().has("--gpu"):
		await _gpu()
	print("NATIVE_MODEL_PROGRAM_SELF_TEST checks=%d failures=%d" % [checks,failures])
	quit(0 if failures==0 else 1)


func _gpu() -> void:
	var scene: Node3D = Node3D.new()
	root.add_child(scene)
	var camera: Camera3D = Camera3D.new()
	camera.position.z = 2.0
	camera.projection = Camera3D.PROJECTION_ORTHOGONAL
	camera.size = 2.0
	camera.current = true
	scene.add_child(camera)
	var arrays: Array = []
	arrays.resize(Mesh.ARRAY_MAX)
	arrays[Mesh.ARRAY_VERTEX] = PackedVector3Array([Vector3(-1,-1,0),Vector3(1,-1,0),Vector3(1,1,0),Vector3(-1,-1,0),Vector3(1,1,0),Vector3(-1,1,0)])
	var colors: PackedColorArray = PackedColorArray()
	var secondary: PackedFloat32Array = PackedFloat32Array()
	var uvs: PackedVector2Array = PackedVector2Array()
	for index: int in range(6):
		colors.append(Color.WHITE)
		secondary.append_array(PackedFloat32Array([0,0,0,1]))
		uvs.append(Vector2.ZERO)
	arrays[Mesh.ARRAY_COLOR] = colors
	arrays[Mesh.ARRAY_CUSTOM0] = secondary
	arrays[Mesh.ARRAY_TEX_UV] = uvs
	var mesh: ArrayMesh = ArrayMesh.new()
	mesh.add_surface_from_arrays(Mesh.PRIMITIVE_TRIANGLES,arrays,[],{},Mesh.ARRAY_CUSTOM_RGBA_FLOAT<<Mesh.ARRAY_FORMAT_CUSTOM0_SHIFT)
	var instance: MeshInstance3D = MeshInstance3D.new()
	instance.mesh = mesh
	instance.visible = false
	scene.add_child(instance)
	var background: Color = await _pixel()
	var material: ShaderMaterial = ShaderMaterial.new()
	material.shader = load("res://shaders/native_world_model.gdshader") as Shader
	material.set_shader_parameter("native_gamma",1.0)
	material.set_shader_parameter("alpha_cutout",true)
	material.set_shader_parameter("alpha_threshold",127.0/255.0)
	instance.material_override = material
	instance.visible = true
	material.set_shader_parameter("albedo_texture",_tex(127))
	check((await _pixel()).is_equal_approx(background),"GPU GREATER127 rejects exact alpha127")
	material.set_shader_parameter("albedo_texture",_tex(128))
	var solid: Color = await _pixel()
	check(solid.r>0.98 and solid.g<0.01 and solid.b<0.01,"GPU solid alpha128 writes full RGB, not fractional mix")
	material.shader = load("res://shaders/native_world_model_blend.gdshader") as Shader
	material.set_shader_parameter("alpha_threshold",0.0)
	material.set_shader_parameter("albedo_texture",_tex(127))
	var blended: Color = await _pixel()
	var weight: float = 127.0/255.0
	var expected: Vector3 = Vector3(1,0,0)*weight+Vector3(background.r,background.g,background.b)*(1.0-weight)
	check(Vector3(blended.r,blended.g,blended.b).distance_to(expected)<3.0/255.0,"GPU SRCALPHA/INVSRCALPHA preserves intermediate alpha127")
	material.set_shader_parameter("albedo_texture",_tex(0))
	check((await _pixel()).is_equal_approx(background),"GPU GREATER0 discards fully transparent blend texel")
	print("NATIVE_MODEL_PROGRAM_GPU background=",background," solid128=",solid," blend127=",blended," expected=",expected)
	scene.queue_free()
	await process_frame


func _tex(alpha_byte: int) -> ImageTexture:
	var source: Image = Image.create_empty(1,1,false,Image.FORMAT_RGBA8)
	source.set_pixel(0,0,Color(1,0,0,float(alpha_byte)/255.0))
	return ImageTexture.create_from_image(source)


func _pixel() -> Color:
	await process_frame
	await RenderingServer.frame_post_draw
	var frame: Image = root.get_texture().get_image()
	return frame.get_pixel(frame.get_width()>>1,frame.get_height()>>1)
