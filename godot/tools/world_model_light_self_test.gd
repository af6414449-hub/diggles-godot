extends SceneTree
const LIGHT: Script = preload("res://scripts/native_world_model_light.gd")
const CAMPAIGN_PROFILE: Script = preload("res://scripts/native_campaign_profile.gd")
const BACKDROP: Script = preload("res://scripts/native_campaign_backdrop.gd")
var checks: int = 0
var failures: int = 0


func _initialize() -> void:
	call_deferred("_run")


func check(value: bool, message: String) -> void:
	checks += 1
	if not value:
		failures += 1
		push_error("WORLD_MODEL_LIGHT_FAILED "+message)


func rgb(value: Color) -> Vector3i:
	return Vector3i(roundi(value.r*255.0),roundi(value.g*255.0),roundi(value.b*255.0))


func _check_campaign_clearing() -> void:
	var chapter: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(
		"res://models/native_campaign_chapter.json"))
	var edge: Variant = BACKDROP.clearing_edge(chapter["objects"], 14.5)
	var sunlit_dwarves: int = 0
	var underground_dwarves: int = 0
	for placement: Dictionary in chapter["objects"]:
		if placement["class"] == "Zwerg":
			if CAMPAIGN_PROFILE.model_is_in_clearing(placement, edge):
				sunlit_dwarves += 1
			else:
				underground_dwarves += 1
	check(sunlit_dwarves == 5 and underground_dwarves == 11,
		"only the five outdoor dwarves receive the clearing fill")
	check(not CAMPAIGN_PROFILE.model_is_in_clearing(
		{"template": "urw_unq_start", "y": 34.0}, edge), "the excavation below the clearing stays shaded")
	var lamp_diffuse: Color = Color(0.13, 0.09, 0.05)
	var shadow: Color = CAMPAIGN_PROFILE.clearing_model_diffuse(lamp_diffuse, Vector3.FORWARD)
	var key: Color = CAMPAIGN_PROFILE.clearing_model_diffuse(lamp_diffuse, Vector3.BACK)
	check(shadow.b > 0.4 and key.b > shadow.b, "daylight fills shadows and preserves directional relief")
	check(key.r > key.g and key.g > key.b and key.r < 1.0, "daylight preserves warm local lighting and highlights")


func _run() -> void:
	_check_campaign_clearing()
	var fields: Dictionary = LIGHT.interpolate([4,4,4,4],[255,255,255,255],Vector2(0.5,0.5))
	check(fields["base"]==128 and fields["visibility"]==256 and fields["haze"]==0.0,"fully visible corner fields")
	check(LIGHT.interpolate([0,4,8,0],[255,255,255,255],Vector2(0.5,0.5))["base"]==112,"source fixed-point corner order")
	check(LIGHT.interpolate([],[],Vector2.ZERO).is_empty(),"missing corners stay unknown")
	check(LIGHT.interpolate([4,4,4,4],[255,255,-1,255],Vector2.ZERO).is_empty(),"invalid owner is not treated as explored")
	check(LIGHT.interpolate([4,4,4,4],[255,255,255,255],Vector2(-0.1,0.0)).is_empty(),"no extrapolation")
	check(LIGHT.nearest_even(2.5)==2 and LIGHT.nearest_even(3.5)==4 and LIGHT.nearest_even(-1.5)==-2,"explicit host rounding policy")
	check(LIGHT.owner_fields(0)==Vector2(-128,0),"owner0 is negative-light branch")
	check(LIGHT.owner_fields(1)==Vector2(0,1) and LIGHT.owner_fields(127)==Vector2(0,1),"owner1..127 haze branch")
	check(LIGHT.owner_fields(128)==Vector2(0,1),"owner128 zero visibility haze")
	check(LIGHT.owner_fields(255)==Vector2(128,0),"owner255 is fully lit")
	check(LIGHT.horizon_rgb([0.305,0.375,0.429])==Vector3i(78,96,110),"HorizonSet uses256 not255 with float32 input")
	var wall: Dictionary = LIGHT.channels(Vector3.ZERO,Vector3.BACK,fields,[],0.1)
	check(rgb(wall["diffuse"])==Vector3i(46,46,46),"world source base and normal")
	check(rgb(LIGHT.channels(Vector3.ZERO,Vector3.DOWN,fields,[],0.1)["diffuse"])==Vector3i(79,79,79),"floor normal response")
	var hidden: Dictionary = LIGHT.interpolate([4,4,4,4],[0,0,0,0],Vector2.ZERO)
	check(rgb(LIGHT.channels(Vector3.ZERO,Vector3.BACK,hidden,[],0.1)["diffuse"])==Vector3i.ZERO,"negative owner lighting can become black")
	var lamps: Array = [{"position":Vector3(0,0,1),"range":2.0,"color":Vector3(1,0,0)}]
	var lit: Dictionary = LIGHT.channels(Vector3.ZERO,Vector3.BACK,fields,lamps,0.1)
	check(lit["diffuse"].r>wall["diffuse"].r and lit["diffuse"].g==wall["diffuse"].g,"original exponential colored lamp")
	lamps[0]["position"] = Vector3(0,0,2)
	check(LIGHT.channels(Vector3.ZERO,Vector3.BACK,fields,lamps,0.1)["diffuse"]==wall["diffuse"],"strict original light radius")
	var clipped: Dictionary = LIGHT.channels(Vector3.ZERO,Vector3.BACK,fields,[],10.0)
	check(rgb(clipped["diffuse"])==Vector3i(255,255,255) and rgb(clipped["secondary"])==Vector3i(64,64,64),"world overflow cap64, not preview cap256")
	var horizon: Dictionary = {"distance":32.0,"rgb_bytes":Vector3i(78,96,110)}
	var half: Dictionary = LIGHT.channels(Vector3(0,0,-16),Vector3.BACK,fields,[],0.1,horizon)
	check(rgb(half["diffuse"])==Vector3i(23,11,11),"EXE half-horizon reuses attenuated red")
	check(rgb(half["secondary"])==Vector3i(39,67,74),"EXE half-horizon secondary uses updated red")
	var full: Dictionary = LIGHT.channels(Vector3(0,0,-32),Vector3.BACK,fields,[],0.1,horizon)
	check(rgb(full["diffuse"])==Vector3i.ZERO and rgb(full["secondary"])==Vector3i(78,96,110),"full horizon independent of albedo")
	check(LIGHT.channels(Vector3.ZERO,Vector3.BACK,fields,[],0.1,horizon)["diffuse"]==wall["diffuse"],"foreground does not receive background fog")
	var haze: Dictionary = LIGHT.interpolate([4,4,4,4],[128,128,128,128],Vector2.ZERO)
	var hazed: Dictionary = LIGHT.channels(Vector3(0,0,7),Vector3.BACK,haze,[],0.1)
	check(rgb(hazed["diffuse"])==Vector3i.ZERO and rgb(hazed["secondary"])==Vector3i(170,170,155),"separate source owner haze")
	var subject: Node3D = load("res://scenes/multiplayer_test.tscn").instantiate()
	subject.extended_world = false # Keep the authored-template fixture.
	root.add_child(subject)
	subject.set_process(false)
	subject.automatic_torches = false
	check(subject.model_light_records.size()>10,"production enables known masonry/background surfaces")
	check(subject.model_light_updates==1,"initial model lighting evaluated once")
	var geometry: bool = true
	var normal_delta: float = 0.0
	var color_changes: bool = false
	var vertices: int = 0
	var backgrounds: int = 0
	var negative_depth: int = 0
	for record: Dictionary in subject.model_light_records:
		var current: Array = record["visual"].mesh.surface_get_arrays(0)
		var original: Array = record["arrays"]
		geometry = geometry and current[Mesh.ARRAY_VERTEX]==original[Mesh.ARRAY_VERTEX] and current[Mesh.ARRAY_TEX_UV]==original[Mesh.ARRAY_TEX_UV]
		for index: int in range(current[Mesh.ARRAY_NORMAL].size()):
			normal_delta = maxf(normal_delta,current[Mesh.ARRAY_NORMAL][index].distance_to(original[Mesh.ARRAY_NORMAL][index]))
		vertices += current[Mesh.ARRAY_VERTEX].size()
		if str(record["visual"].get_parent().name).begins_with("Dummy_Urw_"):
			backgrounds += 1
		for point: Vector3 in record["points"]:
			if point.z<0:
				negative_depth += 1
	check(geometry,"source vertices and UVs retained exactly")
	check(normal_delta<0.0002,"normal re-encoding stays within renderer octahedral quantization")
	check(backgrounds>0 and negative_depth>0,"background has actual negative-Z vertices for horizon fog")
	var updates: int = subject.model_light_updates
	for frame: int in range(30):
		subject._update_camera()
	check(subject.model_light_updates==updates,"unchanged horizon does not rebuild each frame")
	check(subject._model_light_fields(Vector3(-1,0,0)).is_empty(),"unimported vertex does not clamp to invented crop lighting")
	var unchanged_mesh: Mesh = subject.model_light_records[0]["visual"].mesh
	subject._refresh_model_lighting([{"position":Vector3(1000,1000,1000),"range":1.0}])
	check(subject.model_light_records[0]["visual"].mesh==unchanged_mesh,"distant lamp keeps unaffected model buffers")
	var before: Array = []
	for record: Dictionary in subject.model_light_records:
		before.append(record["visual"].mesh.surface_get_arrays(0)[Mesh.ARRAY_COLOR])
	var first: Dictionary = subject.model_light_records[0]
	subject.source_profile.terrain_lights.append({"position":first["points"][0]+Vector3(0,0,1),"range":10.0,"color":Vector3(10,0,0)})
	subject._refresh_model_lighting()
	for index: int in range(before.size()):
		color_changes = color_changes or before[index]!=subject.model_light_records[index]["visual"].mesh.surface_get_arrays(0)[Mesh.ARRAY_COLOR]
	check(color_changes,"new local source lamp updates actual model vertex colors")
	subject.source_profile.terrain_lights.pop_back()
	subject._refresh_model_lighting()
	if OS.get_cmdline_user_args().has("--capture-world-light"):
		for frame: int in range(64):
			subject._update_source_flames()
		subject.focus = Vector3(19,-12,11)
		subject.distance = 36.0
		subject.pitch = 0.0
		subject.yaw = 0.0
		subject._update_camera()
		await _capture("native_front.png")
		for record: Dictionary in subject.model_light_records:
			record["visual"].mesh = record["source_mesh"]
		await _capture("legacy_front.png")
		subject._refresh_model_lighting()
		subject.yaw = -0.35
		subject._update_camera()
		await _capture("native_oblique.png")
		subject.focus = Vector3(23,-14,11)
		subject.distance = 15.0
		subject.yaw = 0.0
		subject._update_camera()
		await _capture("native_close.png")
	print("WORLD_MODEL_LIGHT_SCENE surfaces=%d vertices=%d skipped=%d background_surfaces=%d negative_depth=%d normal_delta=%f" % [subject.model_light_records.size(),vertices,subject.model_light_skipped,backgrounds,negative_depth,normal_delta])
	subject.queue_free()
	await process_frame
	if OS.get_cmdline_user_args().has("--capture-world-light"):
		await _gpu_pixel(half)
	print("WORLD_MODEL_LIGHT_SELF_TEST checks=%d failures=%d" % [checks,failures])
	quit(0 if failures==0 else 1)


func _capture(file_name: String) -> void:
	await process_frame
	await RenderingServer.frame_post_draw
	var folder: String = ProjectSettings.globalize_path("res://").path_join("../docs/reverse-engineering/world-model-lighting-2026-11-18")
	if OS.get_cmdline_user_args().has("--capture-model-programs"):
		folder = ProjectSettings.globalize_path("res://").path_join("../docs/reverse-engineering/model-programs-2026-11-18")
	DirAccess.make_dir_recursive_absolute(folder)
	var frame: Image = root.get_texture().get_image()
	check(frame.save_png(folder.path_join(file_name))==OK,"capture "+file_name)


func _gpu_pixel(half: Dictionary) -> void:
	var scene: Node3D = Node3D.new()
	root.add_child(scene)
	var camera: Camera3D = Camera3D.new()
	camera.position.z = 2.0
	camera.projection = Camera3D.PROJECTION_ORTHOGONAL
	camera.size = 2.0
	camera.current = true
	scene.add_child(camera)
	var texture_image: Image = Image.create_empty(1,1,false,Image.FORMAT_RGBA8)
	texture_image.set_pixel(0,0,Color(128.0/255.0,128.0/255.0,128.0/255.0))
	var material: ShaderMaterial = ShaderMaterial.new()
	material.shader = load("res://shaders/native_world_model.gdshader") as Shader
	material.set_shader_parameter("albedo_texture",ImageTexture.create_from_image(texture_image))
	var arrays: Array = []
	arrays.resize(Mesh.ARRAY_MAX)
	arrays[Mesh.ARRAY_VERTEX] = PackedVector3Array([Vector3(-1,-1,0),Vector3(1,-1,0),Vector3(1,1,0),Vector3(-1,-1,0),Vector3(1,1,0),Vector3(-1,1,0)])
	var colors: PackedColorArray = PackedColorArray()
	var secondary: PackedFloat32Array = PackedFloat32Array()
	var uv: PackedVector2Array = PackedVector2Array()
	var spec: Color = half["secondary"]
	for index: int in range(6):
		colors.append(half["diffuse"])
		secondary.append_array(PackedFloat32Array([spec.r,spec.g,spec.b,1.0]))
		uv.append(Vector2.ZERO)
	arrays[Mesh.ARRAY_COLOR] = colors
	arrays[Mesh.ARRAY_TEX_UV] = uv
	arrays[Mesh.ARRAY_CUSTOM0] = secondary
	var mesh: ArrayMesh = ArrayMesh.new()
	mesh.add_surface_from_arrays(Mesh.PRIMITIVE_TRIANGLES,arrays,[],{},Mesh.ARRAY_CUSTOM_RGBA_FLOAT<<Mesh.ARRAY_FORMAT_CUSTOM0_SHIFT)
	var instance: MeshInstance3D = MeshInstance3D.new()
	instance.mesh = mesh
	instance.material_override = material
	scene.add_child(instance)
	await process_frame
	await RenderingServer.frame_post_draw
	var frame: Image = root.get_texture().get_image()
	var pixel: Color = frame.get_pixel(frame.get_width()>>1,frame.get_height()>>1)
	var expected: Vector3 = Vector3(pow((128.0*23.0/255.0+39.0)/255.0,1.0/1.3),
		pow((128.0*11.0/255.0+67.0)/255.0,1.0/1.3),pow((128.0*11.0/255.0+74.0)/255.0,1.0/1.3))
	check(Vector3(pixel.r,pixel.g,pixel.b).distance_to(expected)<3.0/255.0,"GPU original vertex fog precedes texture/gamma with separate secondary")
	print("WORLD_MODEL_LIGHT_GPU pixel=",pixel," expected=",expected)
	texture_image.set_pixel(0,0,Color(1,1,1,0))
	material.set_shader_parameter("albedo_texture",ImageTexture.create_from_image(texture_image))
	material.set_shader_parameter("alpha_cutout",true)
	await process_frame
	await RenderingServer.frame_post_draw
	frame = root.get_texture().get_image()
	check(frame.get_pixel(frame.get_width()>>1,frame.get_height()>>1)==frame.get_pixel(0,0),"fog does not fill discarded transparent texels")
	scene.queue_free()
	await process_frame
