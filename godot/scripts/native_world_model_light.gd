extends RefCounted
## World-model producer4856E0, not the RGB555 preview producer484CD0.
## Caller owns cell selection, live owner bytes, gain, lights and horizon.
## Host arithmetic uses double and ties-to-even; live x87 mode is uncaptured.


static func nearest_even(value: float) -> int:
	var low: int = floori(value)
	var part: float = value-float(low)
	return low+1 if part>0.5 or (part==0.5 and (low&1)!=0) else low


static func horizon_rgb(raw: Array) -> Vector3i:
	#HorizonSet64261E/642648/642672 multiplies float32 Tcl RGB by256.
	var result: Vector3i = Vector3i.ZERO
	for channel: int in range(3):
		var source: float = PackedFloat32Array([float(raw[channel])])[0]
		result[channel] = clampi(nearest_even(source*256.0),0,255)
	return result


static func owner_fields(value: int) -> Vector2:
	#485417..4854A1, repeated at the other three corners.
	if value>0 and value<128:
		return Vector2(0.0,1.0)
	var raw: int = value-128
	if raw>0:
		raw = mini(128,int(float(raw)*1.3))
	var doubled: int = mini(255,raw*2) if raw>0 else raw*2
	return Vector2(float(raw),float(maxi(0,255-absi(doubled)))/255.0)


static func interpolate(attributes: Array, owners: Array, fraction: Vector2) -> Dictionary:
	if attributes.size()!=4 or owners.size()!=4 or not fraction.is_finite() \
			or fraction.x<0.0 or fraction.x>1.0 or fraction.y<0.0 or fraction.y>1.0:
		return {}
	for index: int in range(4):
		if float(attributes[index])!=float(int(attributes[index])) or int(attributes[index])<0 or int(attributes[index])>255 \
				or float(owners[index])!=float(int(owners[index])) or int(owners[index])<0 or int(owners[index])>255:
			return {}
	var x: int = nearest_even(fraction.x*256.0)
	var y: int = nearest_even(fraction.y*256.0)
	var base_rows: Array[int] = []
	var visibility_rows: Array[int] = []
	var haze_rows: Array[float] = []
	for row: int in range(2):
		var index: int = row*2
		var a: Vector2 = owner_fields(int(owners[index]))
		var b: Vector2 = owner_fields(int(owners[index+1]))
		base_rows.append((int(attributes[index])*(256-x)+int(attributes[index+1])*x)<<8)
		visibility_rows.append(int(a.x)*(256-x)+int(b.x)*x)
		haze_rows.append(lerpf(a.y,b.y,fraction.x))
	return {"base":64+((base_rows[0]*(256-y)+base_rows[1]*y)>>20),
		"visibility":(visibility_rows[0]*(256-y)+visibility_rows[1]*y)>>15,
		"haze":lerpf(haze_rows[0],haze_rows[1],fraction.y)}


static func channels(point: Vector3, normal: Vector3, fields: Dictionary, lights: Array,
		gain: float, horizon: Dictionary = {}) -> Dictionary:
	if fields.is_empty():
		return {}
	var level: float = (3.5999999046325684-2.5460000038146973*normal.x \
		-2.5460000038146973*normal.y)*float(fields["base"])
	var rgb: Vector3 = Vector3.ONE*level
	var visibility: int = int(fields["visibility"])
	if visibility>0:
		var contribution: Vector3 = Vector3.ZERO
		for light: Dictionary in lights:
			var direction: Vector3 = Vector3(light["position"])-point
			var squared: float = direction.length_squared()
			var radius_squared: float = float(light["range"])*float(light["range"])
			if squared>=radius_squared:
				continue
			# EXE coincident direction is undefined; host uses minimum dot there.
			var cosine: float = normal.dot(direction/sqrt(squared)) if squared>0.0 else 0.0
			contribution += Vector3(light["color"])*exp(-2.0*squared/radius_squared)*maxf(0.10000000149011612,cosine)
		rgb += contribution*float(mini(visibility,255))
	elif visibility<0:
		rgb *= 1.0+float(visibility)*0.00390625
	var diffuse: Vector3i = Vector3i.ZERO
	var secondary: Vector3i = Vector3i.ZERO
	for channel: int in range(3):
		var byte: int = nearest_even(rgb[channel]*gain)
		diffuse[channel] = mini(byte,255)
		secondary[channel] = clampi(byte-255,0,64)
	var fog_weight: int = 0
	if point.z<0.0 and float(horizon.get("distance",0.0))!=0.0:
		fog_weight = nearest_even(clampf(-point.z/float(horizon["distance"]),0.0,1.0)*65536.0)
		var remain: int = 65536-fog_weight
		var color: Vector3i = horizon["rgb_bytes"]
		#485C61..485CAA reuses attenuated RED for G/B and new secondary R
		#for secondary G/B. Preserve those instructions, not a generic RGB lerp.
		diffuse.x = (diffuse.x*remain)>>16
		diffuse.y = (diffuse.x*remain)>>16
		diffuse.z = diffuse.y
		secondary.x = (secondary.x*remain+color.x*fog_weight)>>16
		secondary.y = (secondary.x*remain+color.y*fog_weight)>>16
		secondary.z = (secondary.x*remain+color.z*fog_weight)>>16
	elif float(fields["haze"])!=0.0:
		fog_weight = nearest_even(clampf((1.0-(point.z-7.0)*0.125*1.0199999809265137)*float(fields["haze"]),0.0,1.0)*65536.0)
		var remain: int = 65536-fog_weight
		for channel: int in range(3):
			diffuse[channel] = (diffuse[channel]*remain)>>16
			secondary[channel] += (secondary[channel]*remain+(155 if channel==2 else 170)*fog_weight)>>16
	var diff: Color = Color(float(clampi(diffuse.x,0,255))/255.0,float(clampi(diffuse.y,0,255))/255.0,float(clampi(diffuse.z,0,255))/255.0)
	var spec: Color = Color(float(clampi(secondary.x,0,255))/255.0,float(clampi(secondary.y,0,255))/255.0,float(clampi(secondary.z,0,255))/255.0)
	return {"diffuse":diff,"secondary":spec,"fog_weight":fog_weight}
