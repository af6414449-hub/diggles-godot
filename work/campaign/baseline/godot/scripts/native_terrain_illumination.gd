extends RefCounted
## Terrain diffuse path 0x4CC040, with explicit host full-visibility input.
## The second color stores bounded channel overflow, not a Phong highlight.
## No fog reconstruction or claim about native owner-byte production.

static func base_byte(attributes: Array, local_xy: Vector2) -> int:
	# Source byte C+7 is shifted <<8, interpolated with 8-bit fixed weights,
	# then >>20 and +64. Corner order NW,NE,SW,SE.
	var x: int = roundi(local_xy.x * 256.0)
	var y: int = roundi(local_xy.y * 256.0)
	var top: int = (int(attributes[0]) * (256-x) + int(attributes[1]) * x) << 8
	var bottom: int = (int(attributes[2]) * (256-x) + int(attributes[3]) * x) << 8
	return 64 + ((top * (256-y) + bottom * y) >> 20)

static func diffuse(point_bdb: Vector3, normal: Vector3, base: int, lights: Array,
		constants: Dictionary, visibility: int = 255) -> Color:
	return channels(point_bdb,normal,base,lights,constants,visibility)["diffuse"]

static func channels(point_bdb: Vector3, normal: Vector3, base: int, lights: Array,
		constants: Dictionary, visibility: int = 255) -> Dictionary:
	var level: float = float(base) * (float(constants["normal_base"])
		+ float(constants["normal_x"]) * normal.x - float(constants["normal_y_subtract"]) * normal.y)
	var rgb: Vector3 = Vector3.ONE * level
	for light: Dictionary in lights:
		var direction: Vector3 = light["position"] - point_bdb
		var squared: float = direction.length_squared()
		var radius_squared: float = float(light["range"]) * float(light["range"])
		if squared >= radius_squared:
			continue
		# Exactly coincident source yields undefined direction in the EXE;
		# use the minimum dot only in that singular host case.
		var cosine: float = normal.dot(direction / sqrt(squared)) if squared > 0.0 else 0.0
		var factor: float = exp(-2.0 * squared / radius_squared) * maxf(float(constants["min_dot"]), cosine)
		rgb += Vector3(light["color"]) * factor * float(mini(visibility,255))
	rgb *= float(constants["gain"])
	# Native x87 mode unobserved: explicit host nearest rounding and byte clamp.
	var diffuse_color: Color = Color(float(clampi(roundi(rgb.x),0,255))/255.0,
		float(clampi(roundi(rgb.y),0,255))/255.0, float(clampi(roundi(rgb.z),0,255))/255.0)
	var secondary: Color = Color(float(clampi(roundi(rgb.x)-255,0,64))/255.0,
		float(clampi(roundi(rgb.y)-255,0,64))/255.0,float(clampi(roundi(rgb.z)-255,0,64))/255.0)
	return {"diffuse":diffuse_color,"secondary":secondary}


static func class_light_color(color: Array, conversion: Dictionary) -> Vector3:
	var converted: Array[float] = []
	for value: Variant in color:
		var input: float = PackedFloat32Array([float(value)])[0]
		var product: float = PackedFloat32Array([input * float(conversion["class_multiplier"])])[0]
		converted.append(float(int(product)) * float(conversion["renderer_multiplier"]))
	return Vector3(converted[0],converted[1],converted[2])
