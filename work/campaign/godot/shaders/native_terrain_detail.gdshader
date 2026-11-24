shader_type spatial;
render_mode cull_back, specular_disabled;

uniform sampler2D ground_texture : filter_linear_mipmap_anisotropic, repeat_enable;
// Detail contains a neutral 50% gray. Keep its values numeric so that the
// renderer's sRGB conversion does not turn neutral gray into a dark multiplier.
uniform sampler2D detail_texture : filter_linear_mipmap_anisotropic, repeat_disable;
uniform vec2 atlas_size;
uniform float tile_size;
uniform float tile_padding;
uniform float tile_stride;

void fragment() {
	vec3 ground = texture(ground_texture, UV).rgb;
	vec2 detail_uv = (UV2 * tile_stride + vec2(tile_padding) + fract(UV) * tile_size) / atlas_size;
	vec3 detail = texture(detail_texture, detail_uv).rgb;
	// Adapter for the legacy detail layer. Native texture selection is verified;
	// the complete fixed-function texture-stage equation remains to be traced.
	ALBEDO = clamp(ground * detail * 2.0, vec3(0.0), vec3(1.0));
	ROUGHNESS = 1.0;
}
