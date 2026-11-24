shader_type spatial;
render_mode unshaded, cull_back;

uniform sampler2D ground_texture : filter_linear_mipmap_anisotropic, repeat_enable;
uniform sampler2D detail_texture : filter_linear_mipmap_anisotropic, repeat_disable;
uniform vec2 atlas_size;
uniform float tile_size;
uniform float tile_padding;
uniform float tile_stride;
// Stage program remains an explicit host assumption until its draw-state is traced.
uniform int ground_op = 4;
uniform int detail_op = 5;
uniform float native_gamma = 1.3;
uniform float native_brightness = 0.0;
uniform bool secondary_enabled = true;
// Runtime torches are intentionally material-wide: one update lights every
// terrain chunk sharing this source material, without rebuilding those meshes.
uniform int dynamic_torch_count = 0;
uniform vec4 dynamic_torch_position_range[32];
uniform vec4 dynamic_torch_color[32];
varying vec3 secondary_color;
varying vec3 dynamic_torch_light;

void vertex() {
	secondary_color = CUSTOM0.rgb;
	// Terrain is rendered with Y flipped and BDB depth unpacked. Reconstruct the
	// compact source-light coordinate space used by native_terrain_illumination.
	vec3 source_light_point = vec3(VERTEX.x, -VERTEX.y, (VERTEX.z + 14.0) * 0.5);
	vec3 source_light_normal = normalize(vec3(NORMAL.x, -NORMAL.y, NORMAL.z * 2.0));
	dynamic_torch_light = vec3(0.0);
	// Diggles computes the lamp contribution per source vertex before texture
	// staging. Doing the same here makes the runtime pool cheap on mobile.
	for (int index = 0; index < 32; index++) {
		if (index >= dynamic_torch_count) { break; }
		vec3 direction = dynamic_torch_position_range[index].xyz - source_light_point;
		float squared_distance = dot(direction, direction);
		float radius = dynamic_torch_position_range[index].w;
		float radius_squared = radius * radius;
		if (squared_distance > 0.0 && squared_distance < radius_squared) {
			float facing = max(0.1, dot(source_light_normal, direction / sqrt(squared_distance)));
			dynamic_torch_light += dynamic_torch_color[index].rgb
				* exp(-2.0 * squared_distance / radius_squared) * facing;
		}
	}
}

vec3 stage(int op, vec3 first, vec3 second, vec3 previous) {
	// Common.fxh ApplyTexOp; no invented clamp between stages.
	switch (op) {
		case 1: return previous;
		case 2: return first;
		case 3: return second;
		case 4: return first * second;
		case 5: return first * second * 2.0;
		case 6: return first * second * 4.0;
		case 7: return first + second;
		case 8: return first + second - vec3(0.5);
		case 9: return (first + second - vec3(0.5)) * 2.0;
		case 10: return first - second;
		case 11: return first + second * (vec3(1.0) - first);
	}
	return vec3(1.0,0.2,0.5);
}

void fragment() {
	vec3 ground = texture(ground_texture, UV).rgb;
	vec2 detail_uv = (UV2 * tile_stride + vec2(tile_padding) + fract(UV) * tile_size) / atlas_size;
	vec3 detail = texture(detail_texture, detail_uv).rgb;
	vec3 result = stage(ground_op, ground, COLOR.rgb + dynamic_torch_light, COLOR.rgb + dynamic_torch_light);
	result = stage(detail_op, detail, result, result);
	if (secondary_enabled) { result += secondary_color; }
	// UL2CS.fx then Gamma.fxh. Imported geometry has no negative channel inputs.
	ALBEDO = clamp(pow(max(result,vec3(0.0)),vec3(1.0 / native_gamma)) + vec3(native_brightness),vec3(0.0),vec3(1.0));
}
