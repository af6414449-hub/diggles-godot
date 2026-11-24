# Terrain rendering milestone — 2026-11-18

## Result in the ordinary Godot run

The previous B-only display adapter has been replaced in multiplayer_test by the complete observed two-pass material loader and the source terrain texture compositor. Family A/C transitions now come from the four cell corners and the original Msk images, rather than from a color fitted to screenshots. The right cave opening, floors, collision and movement remain unchanged.

- 1056 PMP samples: 367 material 2, 469 material 0, 107 material 3, 113 unimported samples. All values agree with the independently exported tunnel-validator facts.
- Renderer clears material 3 to A before selection; its three-family branch maps C to A. All 81 four-corner combinations of A/B/C are exported, including this unusual branch.
- Uniform families retain the existing deterministic 1..15 variation. Native live RNG is not known. Mixed surfaces use original A/B/C variant 01, matching the mixed-texture construction path.
- Blend mask is selected by the four corner letters, canonicalized to A/B. Its original BGR first byte (blue in PIL RGB) supplies the low-family weight. Each channel is `(low*m + high*(255-m)) >> 8`, **not** division by 255. Original 64x64 masks and textures are read without recoloring.
- Ordinary scene uses 41 texture resources across 168 grouped surfaces, versus 45 surfaces in the old B-only adapter. 5302 visible triangles / 15906 vertices remain. More groups are a consequence of source transitions and the existing dirty-variant grouping; Android performance has not been measured.

Files: `tools/export_native_terrain_render.py`, `godot/models/native_terrain_render.json`, `godot/scripts/native_scene_profile.gd`, `godot/textures/ground/Native_*.tga`, original A/C TGA copies.

## Light extraction and diagnostic mode

The original terrain diffuse path is now implemented independently of Godot lamps, but is **opt-in**. Select the multiplayer scene root and enable `Native Terrain Lighting Preview`, or pass `--native-terrain-lighting` after Godot's `--`. Ordinary startup retains its earlier lighting adapter while using corrected material families/masks.

Recovered from the SHA-256-pinned EXE:

| Address | Observed rule |
|---|---|
| 0x4CA94B..0x4CA96A and following corner loads | PMP trailing attribute reaches runtime C+7 and is shifted <<8 into the renderer's corner fields. |
| 0x4CC040..0x4CC239 | Quantized XY interpolation uses 256 weights; final >>20 and +64. Constant byte 4 yields base 128. Normal factor is `3.6 - 2.546*Nx - 2.546*Ny`, with original float32 constants. |
| 0x4CC329..0x4CC490 | Strict squared-radius gate; `exp(-2*d²/r²)` times `max(.1,dot(n,dir))`, source RGB and visibility-derived strength. |
| 0x4C462D | Constructor initializes render gain to float32 .1. The constant is an immediate value at 0x4C4633, distinct from the negative-visibility branch's 1/256 constant. |
| 0x4C806E..0x4C80BC | Light Z becomes `nativeZ*.5+7`; radius is squared. Evaluation therefore uses BDB depth coordinates, not the Godot-packed world position. |
| 0x4CAD14..0x4CAD9A | Material 3 is cleared before family selection. |
| 0x4CD020..0x4CD9CB | Family bitsets, mask naming, low/high canonicalization and mixed pixel arithmetic. |
| 0x590E21 | Another world operation writes C+7; importing the initial PMP attribute does not establish its live value after every world update. The writer's complete policy remains to be traced. |

Bounded instruction spans and hashes: `native-terrain-render-2026-11-18.json`. Original exe SHA-256 is 58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74. Exporter --check is read-only and validates all generated data/textures against original files.

The diagnostic evaluator uses nine source lamps and the original sphere.dat normals, writes a color on every terrain vertex and rebuilds those colors with changed terrain. Visibility is explicitly a host assumption: light strength 255 for the imported explored crop. It does not invent runtime C+0x34 owner bytes. The exactly coincident light/vertex singularity uses minimum dot; final rounding is host nearest, not an observed original x87 mode.

**Visual comparison caught an unresolved discrepancy:** the recovered diffuse subset is darker than the supplied original-game view. It is not presented as finished native lighting and is not enabled by default. Specular/secondary color, fixed-function texture stages, current C+7 and owner visibility/fog are still missing. The existing detail multiplier remains an adapter. Prop/dwarf lighting still uses Godot ambient/directional and source OmniLight placements.

Godot color-space behavior was also checked against its [official shading-language documentation](https://docs.godotengine.org/en/4.7/tutorials/shaders/shader_reference/shading_language.html) and [renderer source](https://github.com/godotengine/godot/blob/master/drivers/gles3/shaders/scene.glsl); exact cross-renderer legacy color equivalence has not been established.

## Verification and images

- Python source tests: 4 pass, including all 1056 material entries, original mask orientation, independent mixed pixels, renderer empty/three-family branches.
- Godot terrain-render self-test: 388 assertions, all 15906 terrain vertices carry colors, A/C/mixed resources present, ordinary cull direction retained, native mode unshaded.
- Existing scene-profile test passes with nine lamps and original geometry counts. Surface-count constraint updated because material grouping is intentionally different.
- Excavated walk test: 37 assertions; one assignment produces four mutations, 64 newly navigable samples, actor enters 16 new samples and returns.
- Lint and three scene smoke runs pass. OpenGL ordinary/default and diagnostic modes were both visually inspected. An intermediate cull-mode regression was caught in the rendered frame and fixed before delivery.
- Headless --import completed texture scanning but could not save editor settings outside the sandbox; rendered runtime subsequently loaded the new resources without errors. This is not counted as a successful editor-settings write.
- APK and export settings untouched. No agents were started for this milestone.

Images, same three camera poses:

- Previous B adapter: `lighting-2026-11-18-before/`.
- Native diffuse diagnostic, intentionally not the default: `lighting-2026-11-18-after/`.
- Final ordinary run with corrected A/C and masks: `materials-2026-11-18-final/`.

## Next dependency

Complete the renderer's texture stages and secondary color, and trace the writer at 0x590E21 / current owner-light bytes. Compare a known vertex's full original output, not only the diffuse subset. Then replace the ordinary lighting adapter. Native static/dynamic illumination of props and dwarfs should be ported through their own model renderer path, rather than applying the terrain equation to every mesh.

Crop-edge sampling remains a named host policy: clamp to the imported 44x24 crop; unimported material becomes A. Uniform RNG and some edge materials therefore remain uncertain until the surrounding generated world is available.
