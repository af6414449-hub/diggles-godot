shader_type spatial;
// The terrain of the campaign chapter.
//
// The light of the chapter is the native light of the original, so this shader
// is the stage program of the battle scene
// (shaders/native_terrain_pipeline.gdshader) and not a lit shader:
//
//   - the terrain is UNSHADED: the light of the original is baked into the
//     vertex colour of the terrain by the CPU path
//     (scripts/native_terrain_illumination.gd), the same way the battle scene
//     does it. The lights of the scene only light the models.
//   - the albedo is the stage program of the original: the ground texture
//     times the baked light, then the detail layer times the result times two,
//     because the detail atlas holds a neutral fifty percent gray.
//   - the gamma of the original (Gamma.fxh) and its brightness (UL2CS.fx) are
//     applied at the end.
//
// The difference to the battle scene is the ground texture: the native tiles
// are not seamless, so every cell of the ground carries the border of its own
// tile, the way the original draws the ground of a cell (one quad with the
// local UV of the cell, 0..1). The UV of a cell are the local coordinates of
// the cell, so the detail layer of a cell is taken from its own place in the
// atlas of the details.
render_mode unshaded, cull_back;

uniform sampler2D ground_texture : filter_linear_mipmap_anisotropic, repeat_enable;
// Detail contains a neutral 50% gray. Keep its values numeric so that the
// renderer's sRGB conversion does not turn neutral gray into a dark multiplier.
// A neutral 50PGray tile sits next to dark tiles in the atlas. Mipmapped
// anisotropic footprints cross its padding at cell boundaries and draw dark
// L-shaped marks on otherwise continuous free ground.
uniform sampler2D detail_texture : filter_linear, repeat_disable;
uniform vec2 atlas_size;
uniform float tile_size;
uniform float tile_padding;
uniform float tile_stride;
// The number of map cells that one tile of the ground field covers. The
// ground texture is sampled with the continuous coordinates of the field, so
// the detail of a cell is the fractional part of the field coordinates times
// that number.
uniform float field_cells = 8.0;
// The stage program of the original (native_shader_pipeline.json).
uniform int ground_op = 4;
uniform int detail_op = 5;
uniform bool secondary_enabled = true;
// Gamma.fxh and UL2CS.fx.
uniform float native_gamma = 1.3;
uniform float native_brightness = 0.0;
// The UV of the native tiles are the local coordinates of the cell, and the
// ground of the map is one continuous field with the coordinates of the map.
uniform bool uv_local = false;
// The colour variation of the ground of the map: the original generates it over
// the whole map (Campaign.tcl:6 generate_color_variation 0 0 512 640 0), a tint
// of every cell. The map of the variation is sampled by the cell of the ground,
// so every cell of the map carries its own tint like in the original.
uniform sampler2D variation_map : filter_nearest, repeat_disable;
uniform vec2 variation_map_size = vec2(512.0, 640.0);
uniform bool use_variation = false;
varying vec3 secondary_color;

void vertex() {
	secondary_color = CUSTOM0.rgb;
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
	if (use_variation) {
		// The ground of the map is textured with the continuous field, so the
		// cell of the ground is the fractional part of the field coordinates
		// times the number of cells of the field.
		vec2 cell = floor(UV * field_cells);
		float stored = texture(variation_map, (cell + 0.5) / variation_map_size).r;
		ground *= 0.9 + stored * 0.2;
	}
	vec3 detail = texture(detail_texture, (UV2 * tile_stride + vec2(tile_padding)
		+ (uv_local ? fract(UV) : fract(UV * field_cells)) * tile_size) / atlas_size).rgb;
	// The light of the cell is in COLOR, the overflow of the native light is in
	// CUSTOM0. The ground of the map is one continuous field, so the free
	// ground around the chapter carries the same light as the cells.
	vec3 result = stage(ground_op, ground, COLOR.rgb, COLOR.rgb);
	result = stage(detail_op, detail, result, result);
	if (secondary_enabled) { result += secondary_color; }
	ALBEDO = clamp(pow(max(result, vec3(0.0)), vec3(1.0 / native_gamma)) + vec3(native_brightness), vec3(0.0), vec3(1.0));
}
