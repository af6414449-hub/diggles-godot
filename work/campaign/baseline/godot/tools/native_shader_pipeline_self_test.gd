extends SceneTree
const LIGHT: Script = preload("res://scripts/native_terrain_illumination.gd")
var assertions: int = 0
var failures: int = 0

func _initialize() -> void:
	call_deferred("_run")

func check(value: bool, message: String) -> void:
	assertions += 1
	if not value:
		failures += 1
		push_error("NATIVE_SHADER_PIPELINE_FAILED " + message)

func _run() -> void:
	var pipeline: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_shader_pipeline.json"))
	var terrain: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://models/native_terrain_render.json"))
	check(absf(float(pipeline["defaults"]["gamma"])-1.3)<0.000001,"original fallback gamma")
	check(float(pipeline["defaults"]["brightness"])==0.0,"original fallback brightness")
	check(LIGHT.class_light_color([0.6,0.6,0.5],pipeline["light_conversion"])==Vector3(9,9,7.5),"source class RGB to renderer units")
	check(LIGHT.class_light_color([0.7,0.6,0.4],pipeline["light_conversion"])==Vector3(10.5,9,6),"source fire bowl RGB")
	var normal: Vector3 = Vector3.DOWN
	var ordinary: Dictionary = LIGHT.channels(Vector3.ZERO,normal,128,[],terrain["constants"])
	check(ordinary["secondary"]==Color(0,0,0),"unclipped source vertex has no secondary color")
	var bright: Dictionary = LIGHT.channels(Vector3.ZERO,normal,1024,[],terrain["constants"])
	check(bright["diffuse"]==Color.WHITE,"diffuse bytes saturate")
	var secondary: Color = bright["secondary"]
	check(absf(secondary.r-64.0/255.0)<0.000001,"secondary bounded at source 64")
	var gpu: bool = OS.get_cmdline_user_args().has("--gpu")
	if gpu:
		await _test_gpu(pipeline)
	print("NATIVE_SHADER_PIPELINE_SELF_TEST_%s assertions=%d gpu=%s" % ["OK" if failures==0 else "FAILED",assertions,gpu])
	quit(0 if failures==0 else 1)

func _test_gpu(pipeline: Dictionary) -> void:
	var scene: Node3D = Node3D.new()
	root.add_child(scene)
	var camera: Camera3D = Camera3D.new()
	camera.position.z = 2.0
	camera.projection = Camera3D.PROJECTION_ORTHOGONAL
	camera.size = 2.0
	scene.add_child(camera)
	var pixels: Image = Image.create_empty(1,1,false,Image.FORMAT_RGBA8)
	pixels.set_pixel(0,0,Color(128.0/255.0,128.0/255.0,128.0/255.0,1.0))
	var texture: ImageTexture = ImageTexture.create_from_image(pixels)
	var shader: Shader = load("res://shaders/native_terrain_pipeline.gdshader").duplicate()
	shader.code = shader.code.replace("cull_back","cull_disabled")
	var material: ShaderMaterial = ShaderMaterial.new()
	material.shader = shader
	material.set_shader_parameter("ground_texture",texture)
	material.set_shader_parameter("detail_texture",texture)
	material.set_shader_parameter("atlas_size",Vector2.ONE)
	material.set_shader_parameter("tile_size",1.0)
	material.set_shader_parameter("tile_padding",0.0)
	material.set_shader_parameter("tile_stride",1.0)
	material.set_shader_parameter("native_gamma",float(pipeline["defaults"]["gamma"]))
	var surface: SurfaceTool = SurfaceTool.new()
	surface.begin(Mesh.PRIMITIVE_TRIANGLES)
	surface.set_custom_format(0,SurfaceTool.CUSTOM_RGBA_FLOAT)
	for point: Vector3 in [Vector3(-1,-1,0),Vector3(1,-1,0),Vector3(1,1,0),Vector3(-1,-1,0),Vector3(1,1,0),Vector3(-1,1,0)]:
		surface.set_uv(Vector2.ZERO)
		surface.set_uv2(Vector2.ZERO)
		surface.set_color(Color(64.0/255.0,64.0/255.0,64.0/255.0))
		surface.set_custom(0,Color(32.0/255.0,0,0))
		surface.add_vertex(point)
	var mesh: MeshInstance3D = MeshInstance3D.new()
	mesh.mesh = surface.commit()
	mesh.material_override = material
	scene.add_child(mesh)
	await process_frame
	await RenderingServer.frame_post_draw
	var frame: Image = root.get_texture().get_image()
	var pixel: Color = frame.get_pixel(frame.get_width() >> 1,frame.get_height() >> 1)
	var staged: float = pow(128.0/255.0,2.0) * (64.0/255.0) * 2.0
	var gamma: float = float(pipeline["defaults"]["gamma"])
	check(absf(pixel.r-pow(staged+32.0/255.0,1.0/gamma))<=2.0/255.0,"GPU adds secondary before gamma")
	check(absf(pixel.g-pow(staged,1.0/gamma))<=2.0/255.0,"GPU two texture stages and fallback gamma")
	check(absf(pixel.b-pixel.g)<=1.0/255.0,"GPU keeps zero-secondary channels equal")
	print("NATIVE_SHADER_GPU_PIXEL ",pixel)
	scene.queue_free()
