shader_type spatial;
render_mode unshaded, cull_disabled;

// Diagnostic single-texture Common.fxh subset. Input COLOR is real diffuse,
// CUSTOM0 is real secondary, never a sphere index or index/255.
// No source_color decoding: reproduce arithmetic on legacy texture bytes.
// Currently verified for Compatibility only. Stage1 explicitly disabled.
uniform sampler2D albedo_texture : filter_linear_mipmap, repeat_enable;
uniform int color_op;
uniform float native_gamma;
uniform float native_brightness;
varying vec3 secondary_color;

void vertex() {
	secondary_color = CUSTOM0.rgb;
}

void fragment() {
	vec3 tex = texture(albedo_texture, UV).rgb;
	vec3 diff = COLOR.rgb;
	vec3 result = vec3(1.0, 0.0, 1.0);
	switch (color_op) {
		case 2: result = tex; break;
		case 3: result = diff; break;
		case 4: result = tex * diff; break;
		case 5: result = tex * diff * 2.0; break;
		case 6: result = tex * diff * 4.0; break;
		case 7: result = tex + diff; break;
		case 8: result = tex + diff - vec3(0.5); break;
		case 9: result = (tex + diff - vec3(0.5)) * 2.0; break;
		case 10: result = tex - diff; break;
		case 11: result = tex + diff * (vec3(1.0) - tex); break;
	}
	result += secondary_color;
	ALBEDO = clamp(pow(max(result,vec3(0.0)),vec3(1.0/native_gamma))
		+ vec3(native_brightness),vec3(0.0),vec3(1.0));
}
