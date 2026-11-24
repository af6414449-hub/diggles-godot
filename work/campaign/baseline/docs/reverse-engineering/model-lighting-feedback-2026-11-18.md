# Feedback 3/5: masonry and model lighting, 2026-11-18

Later continuation: the actual world-model color producer4856E0 has now been recovered and integrated for a bounded static subset, separately from this preview RGB555 audit. See [world-model lighting and horizon](world-model-lighting-2026-11-18.md) for captures, source evidence and remaining gain/owner/stage adapters.

Integration update: original sphere normals are now used by production `_build_model_meshes`; the fake brightness multiplier was removed. The diagnostic stage shader remains separate, and full native model lighting is still missing. The source audit below describes the pre-integration state. See [current result](feedback-2026-11-18.md).

## Result and scope

**Confirmed bug in the data interpretation:** the model export's `brightness[]`
is a stream of **sphere normal indices**, not baked vertex brightness. Expanding
the existing `Trollh_Wandschmuck` `/255` exception to masonry would manufacture a
darkening factor from a direction index. This report does not recommend that.

**Confirmed renderer mismatch:** terrain uses recovered source channels and a
legacy texture-stage/gamma shader, while models in `_build_model_meshes` use
`StandardMaterial3D`, generated face normals, white Godot ambient energy 0.3,
directional energy 0.6 and Godot OmniLights. These are different lighting
equations. The existing code itself identifies the model path as an adapter.
This explains why importing the correct texture does not establish lighting
parity. It does not establish how much of feedback 3/5 each omission causes.

Delivered a narrow, reusable correction: source normal decoding, nine masonry
fixtures with original geometry/materials/UVs, a bounded RGB555 color-split
primitive, and an explicitly diagnostic single-texture stage shader. The full
model light solver is not implemented. No production integration was made.

Only these new files were authored:

- `godot/scripts/native_model_material.gd`
- `godot/shaders/native_model_material.gdshader`
- `godot/models/native_model_material.json`
- `tools/export_native_model_material.py`
- `godot/tools/native_model_material_self_test.gd`
- this report

Existing main, profiles, shaders, JSON, textures, APK and export settings were
not edited by this work. Other concurrent workspace work is outside this report.

## Which original models are involved

The active template is `data/Templates/multi_urw_start_010_a_0.tcl`:

| Template lines | Class/model in `wandboden.3db` | Original texture | Normal indices |
|---|---|---|---|
| 533, 563 | Dummy_Wand_kaserne_j / wand_kaserne_j | trollh_4_wand_b.tga | 183 |
| 539, 545 | Dummy_Wand_kaserne_k / wand_kaserne_k | trollh_4_wand_b.tga | 183 |
| 551, 575, 581 | Dummy_Wand_kaserne_l / wand_kaserne_l | trollh_4_wand_b.tga | 183 |
| 557, 569 | Dummy_Wand_kaserne_a / wand_kaserne_a | obw_4_boden_c.tga | 183 |
| 726–734 | Dummy_Boden_kaserne_c/d/e | trollh_4_wand_b.tga | 168 |
| 736–760 | Dummy_Abschluss_kaserne_a | trollh_4_boden_a.tga | 44, 175, 186, 229 |
| 766–796 | Dummy_Ecke_kaserne_a | trollh_4_boden_a.tga | 91, 97, 104, 168, 200, 214 |

`Scripts/classes/deco/dummy_wandboden.tcl` lines 70/72/81/90–92/205–207
bind these names through `SetFrontDummyClassesNoPhys`.
`Scripts/init/animinit.tcl:198–255` creates the Dummy class and selects
`$animname.standard`, with `class_viewinfog 1`. The fixture preserves original
lines, hashes, positions and rotations, including the rotated wall at line 545.
It does not evaluate the game's live object state or fog policy.

No `feucht...` string was found in the installed 3DB packages or TGA names;
the exact proposed name therefore remains unconfirmed. `feuerkelch_b` is a
separate torch bowl model, not the masonry. Screen1/screen2 were described in
the request but were not attached to this worker chat; no new image comparison
or pixel-matching claim is made.

The flat stone floor really uses the **wall-named** texture. Do not replace it
with an invented floor albedo based on its filename. All selected source TGA
bytes match `godot/textures/models` exactly. `trollh_4_wand_b.tga` is 256×256,
mean RGB approximately (94.05, 88.07, 76.29); `obw_4_boden_c.tga` is
(143.93, 129.48, 106.58). These means are diagnostics, never correction gains.
Texture selection follows the existing exporter's largest-resolution/m256 rule;
the original game's live texture-quality setting is not captured.

Native wall bounds are approximately x=[−200,200], y=[−400,0], z=0;
floor bounds x=[−200,200], y=−10, z=[−400,0]. The fixture retains full float
bounds and normalized u16/65536 points. No recentering, geometry replacement or
change of the existing 16384×0.005 displacement scale is proposed.

## EXE evidence: index, direction, then lighting

Source installation:
`C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris`.
EXE SHA-256:
`58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74`.
The exporter pins this EXE and the port DLL through the existing shader-contract
probe; the new fixture embeds bounded Capstone disassembly and hashes.

1. **0x463C35–0x463C81:** allocates 0x100 elements for global table
   `0xB9BED0`, opens filename at `0x7243D0` (`data\\sphere.dat`), and reads
   256 records of 12 bytes. The actual file is 3072 bytes, 256 little-endian
   float32 XYZ vectors.
2. **0x488C10:** `movzx eax, byte ptr [esi + eax]` reads the per-vertex byte.
   **0x488C83–0x488CB2:** bounds-checks it against `0xB9BED4`, computes
   `index*3*4`, and looks up that vector in `0xB9BED0`.
3. **0x488CB2–0x488D87:** transforms the vector through renderer rows
   `+0x90/+0xA0/+0xB0`, forms a weighted intensity using caller parameters,
   then calls color helper `0x484CD0`. The fixture records the complete bounded
   lookup/intensity span. Caller parameters and live branch selection remain
   a dependency; this is not the terrain equation.
4. **0x484CD0–0x484DD9:** multiplies intensity by source constant 256,
   rounds via x87, clamps weight to 0..256, extracts RGB555 components,
   computes `(component*weight)>>5`, adds per-channel globals, clamps to
   0..511, splits at 255 into diffuse and overflow. Overflow can reach 256,
   unlike the terrain path's cap of 64. Subsequent visibility/fog arithmetic
   is deliberately not included in the helper's `rgb555_pre_visibility` API.
5. There are also constant-color renderer paths: **0x48D141–0x48D173**
   copies caller colors into the output vertex. Thus the existence of the
   lit normal lookup does not prove that every dummy placement takes it.
   Link fields 1 and 3 are retained as `link_flags`, without assigning an
   unproven lighting meaning to them.

Actual table entries:

| Index | Source XYZ | Meaning |
|---|---|---|
| 168 | (−0.036280885, −0.998481154, −0.041460399) | nearly −Y floor normal |
| 183 | (0.053791925, −0.080048554, 0.995338500) | nearly +Z wall normal |

Using 168/255 or 183/255 as an albedo multiplier discards the vector, its
instance rotation and its directional response. It would also darken two
otherwise equivalent normal-table permutations differently.

## Material stages and gamma

The existing shader/terrain reports were read, along with the current
`native_scene_profile.gd`, `native_terrain_illumination.gd`,
`native_terrain_pipeline.gdshader` and `native_terrain_detail.gdshader`.
There is no file named `native_terrain_illumination.gdshader` in this checkout.

Original `Shaders/Common.fxh` unpacks ARGB by /255 and performs texture-stage
operations on diffuse/current/texture arguments. `UL2CS.fx` adds enabled
secondary RGB after staging; `Gamma.fxh` then applies `pow(rgb,1/gamma)` and
brightness/clamp. Existing source evidence derives fallback gamma
1.2999999523162842 and brightness 0. These defaults brighten midtones, so gamma
alone is not a supported explanation for dark original masonry. The original
user settings are unknown.

The new shader tests a deliberately limited program:
stage0(texture,diffuse), stage1 disabled, supplied secondary enabled, then
source gamma/brightness. Caller must explicitly choose the operation; 4 means
MODULATE. It is unshaded, preventing Godot ambient/directional/Omni light from
being applied again to colors already calculated by the native renderer.
No `source_color` texture conversion is requested: this reproduces legacy byte
arithmetic in the project's Compatibility renderer, as verified by pixels.
Other renderers, alpha test/blending, fog, bloom, composition, selection state,
arbitrary stage arguments and second texture stages are not implemented here.
Negative-result operations have a host guard before pow; parity for negative
shader inputs is not claimed. Do not use this diagnostic program as an
automatically discovered production material state.

## Integration API

Immediate, independently usable correction in the model mesh builder:

```gdscript
const MODEL_MATERIAL: Script = preload("res://scripts/native_model_material.gd")
var model_material: RefCounted = MODEL_MATERIAL.new()
# Once at startup; fail integration explicitly if this is false.
model_material.load_fixture()
var normals: PackedVector3Array = model_material.godot_local_normals(source_surface)
# Verify normals.size() == source_surface["points"].size().
# In the existing triangle-index loop, before add_vertex:
surface_tool.set_normal(normals[index])
# Remove generate_normals for surfaces using this complete source stream.
# Keep vertex_color_use_as_albedo false for these normal-index bytes.
```

`source_normals(surface)` returns the original float32 XYZ for native light
evaluation. `godot_local_normals(surface)` mirrors Y exactly as the existing
point decoder does; the existing MeshInstance basis then rotates both. Do not
apply the instance rotation twice. Invalid/incomplete streams return an empty
array; there is no silently invented normal or brightness fallback.

`rgb555_pre_visibility(packed, intensity, additive_rgb)` takes **explicit
original-renderer inputs**, not a world position or a torch color. It returns
diffuse and secondary only up to 0x484DD9. It uses host ties-to-even rounding;
original x87 control word and bit-exact float operation rounding are unverified.
Do not pass these pre-visibility outputs off as final source lighting.

`single_texture_preview(texture, color_op)` constructs the diagnostic shader.
Supply final source diffuse through vertex COLOR and source secondary through
CUSTOM0 with `CUSTOM_RGBA_FLOAT`. Values above one must survive in CUSTOM0;
do not pack model overflow into an 8-bit custom field. The shader expects opaque
RGB, with secondary already gated by the source enable state. This API is ready
for the integrator's future model-light evaluator; no fitted ambient term or
brightness coefficient has been inserted.

## Validation and remaining work

- `python tools/export_native_model_material.py --check`: regenerates and
  compares the entire fixture without writing; pins EXE/DLL/shaders, all nine
  original meshes, 256 normals, texture hashes, bounds and Tcl references.
  It also independently compares geometry, UVs, triangles and the legacy
  `brightness` bytes against the existing active model JSON.
- Godot 4.7.2 headless self-test: **208 assertions passed**. Checks legacy/new
  field compatibility, all selected normal vectors, reflection, unmodified
  albedo hashes, malformed streams, RGB555 channel order and model overflow.
- OpenGL Compatibility self-test (`-- --gpu`): **213 assertions passed**.
  Actual pixel `(0.3451,0.2,0.2,1)` agrees within 2/255 with independently
  computed texture×diffuse + red secondary, followed by original gamma.
  The environment denied creation of the `user://` shader cache directory;
  rendering and pixel readback still completed successfully, exit 0.
- Skill lint before/after: zero errors/warnings. No main-scene visual A/B was
  performed because this worker does not integrate production files.

**What this fixes now:** source normal meaning and preservation, prevention of
an index-as-brightness regression, and a tested stage/gamma destination for
real model colors. It does **not** yet guarantee darker or visually matched
masonry. Replacing generated normals alone only restores the quantized source
directions; its photometric effect can be small.

**Next evidence required for full feedback 3/5:** identify which model draw path
the Dummy classes actually reach, capture its caller intensity/RGB555/additive
and visibility inputs for a known wall/floor vertex, then capture actual stage
opcodes/arguments and secondary enable. Integrate that model solver with the
same dynamic lamps and source visibility as terrain, then compare screen1 and
screen2 at the same camera/torch state. Terrain's 31×0.5 light conversion and
normal/gain formula cannot simply be copied into the model branch.
