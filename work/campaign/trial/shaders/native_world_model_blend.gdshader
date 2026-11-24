shader_type spatial;
render_mode unshaded, cull_disabled, fog_disabled, blend_mix, depth_draw_always;

// Source default material slot3/model_blend: SRCALPHA/INVSRCALPHA,
// GREATER0, original default ZWRITE on. Native packet sort remains separate.
uniform sampler2D albedo_texture : filter_linear_mipmap, repeat_enable;
uniform float native_gamma = 1.3;
uniform float native_brightness = 0.0;
uniform bool alpha_cutout = true;
uniform float alpha_threshold = 0.0;
varying vec3 secondary_color;

void vertex() {
	secondary_color = CUSTOM0.rgb;
}

void fragment() {
	vec4 texel = texture(albedo_texture, UV);
	if (alpha_cutout && texel.a <= alpha_threshold) {
		discard;
	}
	vec3 result = texel.rgb * COLOR.rgb + secondary_color;
	ALBEDO = clamp(pow(max(result, vec3(0.0)), vec3(1.0/native_gamma))
		+ vec3(native_brightness), vec3(0.0), vec3(1.0));
	ALPHA = texel.a;
}
