# BDB axis and depth evidence audit

Date: 2026-11-15. Scope: existing EXE disassembly, original BDB/PMP bytes, and the normal-vector resource referenced by the EXE. No Tcl setter/creation analysis, main-code changes, or rendering.

## Finding

**The statement that caller `0x4097b0` proves “BDB Z is world vertical” must be withdrawn.** It proves a comparison between the third **logical** coordinate and a scalar field sampled over map X/Y. It establishes neither gravity nor a vertical direction. In this side-on map, PMP X/Y are the horizontal/vertical terrain layout axes; the third coordinate is depth through that layout.

**Raw BDB Z is already in the renderer's depth representation:**

```text
render_depth = 7.0 + 0.5 * logical_depth
logical_depth = 2.0 * (render_depth - 7.0)

BDB vertex -> logical map position:
    (cell_x + raw_x, cell_y + raw_y, 2 * raw_z - 14)

BDB vertex -> native terrain render buffer, before optional deformation:
    (cell_x + raw_x, cell_y + raw_y, raw_z)
```

The EXE contains both arithmetic directions. This is stronger than a relation inferred only from mesh bounds. The formulas describe depth units, without exchanging Y and Z. The audit does not derive the camera's screen-axis signs or its culling state. Calling map Y vertical here uses the supplied side-on frame; the independent native facts are the X/Y cell placement, the separate encoded third coordinate, and the surface orientations below.

For the follow-up example, logical depth `1.01` becomes render depth `7.505`; the BDB plane at raw Z `7.5` represents logical depth `1`. The proposed `7.5 + depth/2` would introduce an extra `0.5` renderer unit. Comparing unchanged logical object depths directly with raw BDB Z mixes representations. Applying the inverse to BDB, or the forward transform to logical points, reconciles these units; the eventual visual occlusion still depends on the camera and object geometry.

## Source identity and address conventions

Original files were read from `C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris`. EXE addresses below are image virtual addresses, not file offsets. For this EXE, `.text` VA minus `0x400c00` gives its file offset; `.rdata` VA minus `0x401200` gives its file offset.

| Source | SHA-256 |
| --- | --- |
| `Diggles.exe` | `58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74` |
| `data/BlockDB2.BDB` | `13d06172ae42a42657c10fe6007c8213fc525a7fde8132fe0041f48c9507b856` |
| `data/Templates/hol_024.pmp` | `4f776b6bec0d0b85f667b24ff408e7ad67776ce295cf0825e12744ce373202c0` |
| `data/sphere.dat` | `044611f98f3dd48ba14c939151c209499e1918c40ed30765142b00ff282a7360` |

All three original BDB hashes also matched `blockdb-layout-audit.json`. The saved disassembly used was `tools/.cache/diggles-text-disassembly.txt`; critical arithmetic and copy instructions were additionally checked against the actual EXE bytes. Persistent code/layout references: `tools/inspect_bdb.py`, `tools/export_pmp_terrain.py`, `blockdb-loader-disassembly.txt`, `pmp-loader-tail-disassembly.txt`, and `pmp-block-reference-access.txt` in this directory.

## What the collision caller actually proves

`0x4097b0..0x40982c` does the following, using `trunc` for SSE conversion toward zero:

```text
sx = trunc(argument_1 * 8)
sy = trunc(argument_2 * 8)
reject outside the map's inset bounds
sample = unsigned_byte(0x4093f0(sx, sy))
return sample <= trunc(argument_3)
```

Evidence: second argument conversion at `0x4097b3..0x4097c7`, first at `0x4097d4..0x4097e1`, call at `0x409810..0x409812`, and comparison at `0x409817..0x409828`. Constant `0x73752c` is float32 `8.0` at EXE file offset `0x33632c`. The compared third argument is **not** multiplied by 8 or converted into BDB render depth here.

The sampled function `0x4093f0` selects the cell with arithmetic shifts by 3 (`0x4093fe..0x40940a`). It reads that runtime cell's first dword as the block ID (`0x409412`), selects a BDB metadata record with stride `0x59 = 89` (`0x40941d..0x409420`), and returns byte `((sy & 7) << 3) | (sx & 7)` (`0x409439..0x409444`). The map-cell accessor uses `row * width + column` at `0x592f4f..0x592f53` before wrapping into its runtime storage.

This is a depth-threshold/occupancy test compatible with a side-on relief surface. Calling the 8×8 array a “height map” does not make its sampled scalar the game's physical vertical. The old deduction also skipped the distinction between logical depth and the encoded depth in BDB vertices.

## Direct EXE proof of the depth packing

| Operation | Instruction locations | Actual values / effect |
| --- | --- | --- |
| Save third logical input in routine `0x409830` | `0x409ac1..0x409ac9` | Third argument `[ebp+0x10]` becomes local `[ebp-0x14]`. |
| Prepare and encode emitted third component | `0x409b5e..0x409b67`, `0x409baf..0x409bbf` | Read that local, subtract the component offset, multiply by `0.5`, add `7.0`. In this path the component offset `xmm3` was zeroed at `0x409b0d`. |
| Emit the point | `0x409beb..0x409bfe` | Copy the first two components to output `+0/+4`; store the encoded component at `+8`. |
| Test a logical point in the same routine | `0x409e93..0x409eb5` | Pass locals for first/second/third components to `0x4097b0`; the third is read directly from `[ebp-0x14]` at `0x409eab`. Thus the predicate takes the unencoded representation. |
| Further forward conversion | `0x64c611..0x64c626` | Third local `*= 0.5; += 7`, immediately before call `0x479150` at `0x64c62b`. |
| Inverse conversion | `0x64c646..0x64c65b` | Read returned component `+8`; subtract `7`; add the result to itself; store it as the third local. |

The routine at `0x409830` is evidence of native logical-point emission, **not a BDB loader that repacks BDB vertices**. Its original function name is not established here. No claim about every object class's complete transform is needed for this evidence.

The exact constant bytes are:

| Constant VA | EXE file offset | Little-endian bytes | float32 |
| --- | --- | --- | --- |
| `0x73708c` | `0x335e8c` | `00 00 00 3f` | `0.5` |
| `0x737520` | `0x336320` | `00 00 e0 40` | `7.0` |

At EXE file offset `0x8faf` / VA `0x409baf`, the consecutive instructions are literally:

```text
f3 0f 59 05 8c 70 73 00   mulss xmm0, [0x73708c]
f3 0f 58 05 20 75 73 00   addss xmm0, [0x737520]
```

The inverse subtraction/doubling is at EXE file offsets `0x24ba4e` / `0x24ba57`, VAs `0x64c64e` / `0x64c657`.

## What the BDB terrain emitter does

The loader at `0x565e61..0x565e72` establishes global vertex-pool pointer `0xb836a4`, with stride 20 bytes. In `0x462b74..0x462b87`, the part's u16 vertex ID selects that `<5f>` record. At `0x462b9f..0x462baf`, its first three dwords are copied directly to output offsets `0`, `4`, `8`. There is **no Y/Z exchange, Z sign change, or Z scale/offset** in this reader. EXE file offset for the copy sequence: `0x61f9f`.

The native terrain construction path is identified by the embedded `Engine\ScapeRenderer.cpp` string at VA `0x724814`, file offset `0x323614`, referenced at `0x4ca2a2`. Routine `0x4ca080` selects the cell's BDB block (`0x4ca0b1..0x4ca0d8`), loops over its three parts (`0x4ca10f..0x4ca12d`, `0x4ca805..0x4ca812`), and calls the raw vertex reader at `0x4ca3d3`.

At `0x4ca62e..0x4ca64a` it converts integer cell column/row to float. At `0x4ca658..0x4ca670`, it adds the column to vertex component `+0` and the row to component `+4`. Component `+8` receives neither cell coordinate. The buffer is passed to `0x45fd00` at `0x4ca731..0x4ca73e`. This directly links PMP column/row to BDB X/Y, with raw BDB Z carried as the separate renderer coordinate.

Qualification: the intervening `0x4cc040` call processes lighting and can additionally deform the surface when global byte `0x768381` is nonzero (`0x4cc758..0x4cca0e`). For example, `0x4cc864..0x4cc87a` adds a displacement to the existing Z. That conditional deformation does not provide a universal `7.5` offset or swap the map axes. The undeformed source vertices are already packed. Therefore a claim that every final vertex always remains bit-identical would also be too strong.

An independent native triangle-output path provides a useful additional bound: `0x668146..0x668182` calculates `(raw_x * 200, raw_y * 200, (14.5 - raw_z) * 200)`, then adds its cell offsets to the first two coordinates at `0x6682d6..0x66831a`. Constants `200.0` and `14.5` are at VAs `0x737644` / `0x737564`, file offsets `0x336444` / `0x336364`. This is a separate output representation, **not** the main render-buffer transform above; its output purpose was not pursued in this bounded audit.

## Original BDB/PMP contradictions to “Z is vertical”

`hol_024.pmp` has width 24 and height 16 at file offsets `0` and `4`. Its 384 u32 block IDs start at `0x188`; cell `(x,y)` therefore selects the dword at `0x188 + 4*(24*y+x)`.

For `BlockDB2.BDB`, the catalog starts at `0x1c`, with block `b`, part `p` at `0x1c + 18*b + 6*p`. Metadata starts at `0x20995c`, with block record at `0x20995c + 89*b`. The vertex pool starts at `0x14e8700`, with vertex `v` at `0x14e8700 + 20*v`. Offsets below are BDB file offsets.

| Block | Metadata record offset | First 64 sample bytes | Raw Z evidence |
| --- | --- | --- | --- |
| `0` | `0x20995c` | All `15` | Four part-0 vertices at `14.5`; parts 1/2 empty. |
| `1647` | `0x22d5f3` | All `1` | Four part-0 vertices at `7.5`; parts 1/2 empty. |
| `80` | `0x20b52c` | All `11` | Four part-0 vertices at `12.5`; parts 1/2 empty. |
| `3449` | `0x25486d` | `1` and `2` | Vertices across the parts span `7.5..8.0`. |
| `81` | `0x20b585` | Top four rows `11`, bottom four `15` | Part-0 sheets at `12.5` and `14.5`; part 1 connects them. |
| `2601` | `0x24219d` | Top four rows `1`, bottom four `15` | Part-0 sheets at `7.5` and `14.5`; part 1 connects them. |

Uniform part-0 surfaces among the 115 referenced IDs were checked separately in BDB0, BDB1, BDB2: respectively 7, 6, 7 eligible blocks; **zero disagreements** with `raw_z = 7 + sample/2`. This is an endpoint/uniform-surface check, not a claim that every vertex equals one metadata sample: sloped/beveled surfaces and connecting strips contain intermediate positions. Block 2310 is a concrete warning: its metadata samples are all 15, its part-0 sheet is at 14.5, but its parts 1/2 include bevel vertices at 14.0.

The strongest floor contradiction is block 2601. It is placed at `(5..16,10)` in the PMP. All 16 vertices of its part 1 have **raw Y = 0.5**, X spans `0..1`, and raw Z spans `7.5..14.5`. Consequently the emitted strip lies at **map Y = 10.5**, spans 12 adjacent columns, and extends through logical depths `1..15`. Making raw Z vertical would rotate this cross-depth floor strip into an upright curtain and make the PMP rows act as depth. The native cell translation above contains no such rotation. This geometry independently reproduces the supplied floor level without reading Tcl placements.

For direct byte inspection of that strip: block-2601 part-1 catalog entry `0xb704` is `<HI> = (16,150)`; u16 vertex IDs start at `0x152fde9`, its 16 attribute bytes start at `0x152fe09`, topology 150 is at `0x141d7f0`, and its 42 u16 triangle indices start at `0xc1e626`. The first vertex ID is 265, whose `<5f>` record at `0x14e9bb4` is `(0,0.5,10.5,0,3.5)`.

Across all 384 cell occurrences, original geometry gives 1,056 / 1,256 / 488 triangles in parts 0/1/2, totaling 2,800. Across only the 115 distinct block IDs, those counts are 487 / 1,089 / 486. These are different populations and must not be mixed.

## Parts and the formerly opaque attribute bytes

**The per-vertex u8 field is a normal-vector lookup index in the native terrain path.** At `0x4ca3fa..0x4ca43c`, the byte indexes the table at `0xb9bed0` with stride 12; its three floats are passed as the second argument to `0x4cc040` at `0x4ca464..0x4ca491`. The latter uses them in a directional light expression at `0x4cc1e3..0x4cc224` and light-vector dot products at `0x4cc3a1..0x4cc3cd`.

The table loader `0x492060..0x4920aa` allocates 256 entries, opens `data\sphere.dat` (filename VA `0x7243d0`, file offset `0x3231d0`), and reads 256 records of 12 bytes. The file is exactly 3,072 bytes; all decoded vectors have lengths within approximately `7.1e-8` of 1. This establishes the normal role, rather than inferring a material or a visibility flag from the byte values.

| Attribute | `sphere.dat` file offset | Decoded vector, rounded | BDB example |
| --- | --- | --- | --- |
| `183` (`0xb7`) | `0x894` | `(0.053792,-0.080049,0.995338)` | All four vertices on block-0 and block-1647 part-0 planes. |
| `168` (`0xa8`) | `0x7e0` | `(-0.036281,-0.998481,-0.041460)` | All 16 vertices on block-2601 part-1 strip at map Y 10.5. |
| `38` (`0x26`) | `0x1c8` | `(-0.033185,0.967961,0.248899)` | Appears on many oppositely Y-facing sloped part-1 surfaces. |

Cross products from unchanged triangle indices agree with those broad orientations. For the distinct hol_024 blocks, part 0 has 445 triangles with exact geometric normal `+Z` and another 42 beveled triangles with positive Z component. Part 1 contains 89 exact `-Y` triangles and, among other slopes, 309 with normalized normal approximately `(0,+0.894427,+0.447214)`. Part 2's most frequent normals are approximately `(+0.894427,0,+0.447214)` (174 triangles) and `(-0.894427,0,+0.447214)` (81 triangles).

Thus part 0 contains depth-facing sheets; part 1 contains both floor-like and ceiling-like connections/bevels across depth; part 2 contains many left/right-facing bevels. **“Part 1 = upper, part 2 = lower” and “part 0 = expendable exterior only” are not supported.** Block 1647's part 0 is also the inner sheet at logical depth 1. The measured subset does not establish an exhaustive naming scheme or a universal front/rear visibility selector. The final 25 metadata bytes remain undecoded here.

For winding reference, flat block-0 and block-1647 part-0 indices are `[0,1,2, 1,3,2]`, yielding `+Z`, consistent with normal index 183. Unpacking depth alone has positive determinant `+2`, so it does not reverse winding; a coordinate reflection changes orientation. This arithmetic does not establish the original graphics API's cull mode.

## Consequences for existing claims and audit boundary

`blockdb-native-terrain.md` promotes the comparison at `0x4097b0` to proof of physical vertical, and its later axis paragraph exchanges BDB Y/Z. `tools/export_pmp_terrain.py` copies XYZ faithfully but its `coordinates` string labels Y “map depth” and Z “vertical”; its `vertical_range` is actually a range of packed depth values. These labels are contradicted by the native placement and packing evidence above. `inspect_bdb.py` itself preserves raw values and appropriately avoids imposing axes. Those existing files were intentionally left unchanged for the parent task to reconcile.

This audit establishes the native depth encoding and X/Y terrain placement. It does not settle Tcl parsing/creation, model-local axes or scale, camera matrices, material assignment, runtime deformation state, or the exact final visibility of the torch. All arithmetic/statistics used read-only Python invocations with `-B`; no images, meshes, exports, or cache files were generated.

Only file created by this audit: `docs/reverse-engineering/bdb-axis-evidence-audit.md`.

## Follow-up: native mesh basis, complete-geometry depth conversion, and Euler sign

This bounded extension follows `0x5e9700` and its adjacent initializer, the matrix helpers they actually call, and the matching mesh-frame draw path. It extends the original scope to those native model transforms. Tcl setters and rendering remain outside the work performed.

### The supplied `0x5e9a72` matrix is a collision-space conversion

The four independently loaded rows are **not contiguous rows of a single rdata matrix**:

| Row VA | EXE file offset | Four float32 values |
| --- | --- | --- |
| `0x737800` | `0x336600` | `(1,0,0,0)` |
| `0x737830` | `0x336630` | `(0,1,0,0)` |
| `0x737870` | `0x336670` | `(0,0,2,0)` |
| `0x7378b0` | `0x3366b0` | `(0,0,0,1)` |

Together they form `D = diag(1,1,2,1)`. There is no translation, `7`, or `-14` in this matrix. The third-row load is at VA `0x5e9a95`, EXE file offset `0x1e8e95`, with bytes `0f 28 05 70 78 73 00`.

`0x4156b0` uses row-major storage and computes `output = this * argument_2`, where the first stack argument is the output pointer. Its loops at `0x4156e0..0x41573a` compute `out[i,j] += this[i,k] * argument_2[k,j]`. Points elsewhere in the same caller multiply as **row vectors**, with translation in the fourth row. This establishes multiplication direction without guessing it from a graphics convention.

The data flow in `0x5e9700` is:

| Location | Native operation |
| --- | --- |
| `0x5e9813..0x5e982b` | Multiply the Euler matrix at `edi+0x138` by the auxiliary matrix at `edi+0x18`; save the result. |
| `0x5e9a11..0x5e9a35` | Construct uniform scale `S = diag(k,k,k,1)`, `k = float32(0.005)`, and multiply it by the saved matrix. |
| `0x5e9a78..0x5e9ab1` | Postmultiply that **complete basis** by `D`. Thus the basis is `S * R * A * D`, not a translation-only adjustment. |
| `0x5e9aca..0x5e9bd0` | Transform the recovered model center by that basis, including its affine row. |
| `0x5e9b81..0x5e9bee` | Subtract that transformed center from the desired center, component by component. |
| `0x5e9bf6..0x5e9c09` | Build a translation using `0x47e910` and postmultiply it into the basis. |
| `0x5e9d23..0x5e9e12` | Transform all eight model-bounds corners by the resulting matrix. |
| `0x5e9e74..0x5e9efc` | Index BDB metadata with stride 89, read the 8×8 sample, compare `sample + 0.1` against the transformed corner's third component, and save a per-corner boolean. |

Consequently **`0x5e9700` is a collision/motion path, not the final mesh-frame draw call**. It later updates the owner through `0x5cd8e0` (`0x5ea6a8`, `0x5ea7b1`). Treating `0x5e9ab1` as the final render matrix would incorrectly put the doubling on the renderer side of the conversion.

The translation calculation is also more specific than “position goes through the same matrix.” The cached matrix at `edi+0xf8` is copied and inverted (`0x5e98fb..0x5e9939`, wrapper `0x4fd850`). The center in `edi+0x68/+0x6c/+0x70` is transformed by that inverse at `0x5e9954..0x5e9a04`, recovering its model-space center. The new matrix transforms that center, and a final translation aligns it with the desired center. The factor of two therefore acts on the rotated geometry before recentering; there is no standalone `7` offset needed in this collision matrix, whose target center is already logical.

### `[edi+0x18]` is not the owner's source Euler matrix

The adjacent initializer identifies the structures. At `0x5ea85e`, `edx = [edi+0x14]` is the owner. Its three angle components at `owner+0x40/+0x44/+0x48` are copied at `0x5ea90c..0x5ea926` and passed to `0x47ec30` at `0x5ea952..0x5ea960`, which writes `edi+0x138`. The subsequent cached transform is built with uniform `0.005` scale and the same `D`, plus the owner's position (`0x5ea965..0x5eaa14`). Mesh-frame min/max bounds are fetched at `0x5eaa8a..0x5eaad3`.

The auxiliary matrix at `edi+0x18` is initialized to identity by `0x5eb524..0x5eb52a`, calling `0x47ecf0`. A conditional path uses the result of `0x6d46ea`, the length of the owner's movement vector, and `0x415750` to give it a random Z rotation (`0x5eb57a..0x5eb5d2`). Thus it is additional motion state. Its use in `0x5e9813` does not establish the source Euler sign; the owner-angle builder does.

### Applicability to an actual mesh-frame draw: native scale is nominally 81.92

There is direct draw-side evidence, independent of the collision routine. The code identifies itself as `Engine\ModelRenderer.cpp` at VA `0x7242e0`, EXE file offset `0x3230e0` (referenced, for example, at `0x488a7b` and `0x48ce7f`). The mesh label at VA `0x724318`, offset `0x323118`, is `MR DB %s Mesh %d`.

One concrete native instance path packs a point's third component at `0x46c05b..0x46c079`, using the established `0.5` and `7`. It passes that position and the angle pointer to mesh-frame draw routine `0x487430` at `0x46c17c..0x46c196`. Inside that draw routine:

1. `0x487493..0x48749e` builds the Euler basis with `0x47ec30`.
2. `0x4874a3..0x4874b7` builds uniform scale `0.005` and composes it with that basis.
3. `0x4874bc..0x487500` adds the supplied position to the affine translation. This position is already packed by the caller.
4. `0x487508..0x487511` selects the mesh-frame record; `0x487541` precomposes the point decoder through `0x484c10`.
5. `0x48773d` invokes per-part emitter `0x48cda0`, then `0x48774d` submits the resulting item through `0x450570`. The emitter reads actual u16 point triples and multiplies them through the basis at `renderer+0x50` (`0x48cff0..0x48d0af`). It allocates the vertex buffer through `0x45fd00` at `0x48cef4`.

This is a real mesh-frame-to-vertex-buffer path, not an unrelated use of `0.005` in physics. The parameterized sibling `0x488270` uses `k = scale_argument * 0.005` (`0x4882da..0x4882f2`) and reaches emitter `0x488980` at `0x4884cb`; its point multiplication and XYZ stores are at `0x488bb0..0x488c7e` and `0x488d94..0x488dac`.

Constant `0x736fcc`, EXE file offset `0x335dcc`, is `0a d7 a3 3b`, float32 `0.004999999888241291`. The source point decoder provides the remaining factor:

```text
At 0x48cff0..0x48d02c, or 0x488bb0..0x488be7:
    f = bitcast_float32(0x43800000 | unsigned_u16)
      = 256 + unsigned_u16 / 32768

0x484c10 loads decoder rows at 0x737820 / 0x737850 / 0x737890 / 0x7378f0:
    diag = (8192,8192,8192)
    translation = (-2105344,-2105344,-2105344)

0x484ad0 precomposes decoder * instance_matrix, giving:
    model_coordinate = 8192*f - 2105344
                     = (unsigned_u16 - 32768) / 4
                     = 16384 * (unsigned_u16/65536 - 0.5)

For normalized p = unsigned_u16/65536 and unit instance scale:
    render-local coordinate = 81.92 * (p - 0.5), before Euler rotation
```

The decoder row file offsets are `0x336620`, `0x336650`, `0x336690`, `0x3366f0`. The last constant row is `(-2105344,-2105344,-2105344,1)`. Thus **81.92 replaces provisional 100 for this unit-scale native mesh path**, subject to the float32 scale constant. If an importer normalizes by 65535, the exact u16 formula above avoids its small endpoint/centering discrepancy. The parameterized sibling proves that instance-specific scale may additionally apply; this audit does not assign that argument for every class.

There are branch-specific constant output shifts: emitter `0x48cda0` subtracts `0.005` from Y at `0x48d106..0x48d113` and adds `0.04` to Z at `0x48d141..0x48d151` (`0x737008`, file offset `0x335e08`). These do not change the basis or the 81.92 factor. The sibling emitter's cited XYZ stores have no such shifts. The basis formulas below are before these branch-specific constants.

### Full geometry and translation must use the same final representation

Let `m` be a decoded model point in bounds units, `R` the native Euler matrix below, and `p` the logical placement. Row-vector notation gives the native draw result:

```text
q = (m * k) * R
render_point = (p.x + q.x, p.y + q.y, 7 + p.z/2 + q.z)

The identical complete point expressed in logical coordinates is:
logical_point = (p.x + q.x, p.y + q.y, p.z + 2*q.z)
```

**Yes, conversion between renderer and logical space applies to the complete geometry as well as its origin.** The native renderer achieves this by using model displacements already measured in renderer units and packing the placement separately. The collision basis explicitly supplies the corresponding post-rotation `D` for geometry. It does not establish an additional `0.5` on native decoded mesh Z: halving `q.z` again while merely packing `p.z` would make that mesh too shallow relative to the native draw.

For a shared logical-coordinate implementation, double the **rotated world-Z displacement** before using the common forward depth transform on the assembled point. In matrix terms the logical basis is `k * R * D`, and the renderer basis is `k * R`. Multiplying only model-local Z by two **before** a general Euler rotation is a different operation when X/Y rotations mix axes. This distinction is immaterial for a pure Z rotation but matters for general poses.

### Exact source Euler order and Z sign

`0x47ec30` first reads angle `+8` and calls `0x47ea20` (`0x47ec44..0x47ec49`), then angle `+0` through `0x4155e0` (`0x47ec70..0x47ec7c`), then angle `+4` through `0x415510` (`0x47ec81..0x47ec92`). The intervening `0x47eaf0` calls postmultiply. Hence:

```text
R = Rz(z) * Rx(x) * Ry(y)     # row-vector multiplication

Rz(z) = [ cos(z)  -sin(z)   0 ]
        [ sin(z)   cos(z)   0 ]
        [   0        0     1 ]

Rx(x) = [   1        0        0   ]
        [   0      cos(x)  -sin(x) ]
        [   0      sin(x)   cos(x) ]

Ry(y) = [ cos(y)    0      sin(y) ]
        [   0      1        0    ]
        [-sin(y)   0      cos(y) ]

For a pure source Z rotation:
    x' = x*cos(z) + y*sin(z)
    y' = -x*sin(z) + y*cos(z)
    z' = z_local
```

The sine sign is explicit: `0x47ea8d` stores `+sin` at matrix offset `+0x10`; `0x47ea92` flips its sign bit with `0x737970`; `0x47ea9d` stores `-sin` at offset `+4`. VAs `0x47ea92` / `0x47ea9d` have file offsets `0x7de92` / `0x7de9d`. The trigonometric helpers take the angle directly in radians: `0x6f6ad0` falls back to x87 `fsin` at `0x6f772d`, and `0x6f5ae0` to `fcos` at `0x6f739d`. No degree conversion or source-angle negation occurs in this builder.

For the supplied root05 angle, converted to float32 as the native input would be, `z = 5.723189830780029`, `cos(z) = 0.847257514`, `sin(z) = -0.531182365`. With X/Y Euler angles zero, the native basis sends:

```text
local +X -> (+0.847257514, +0.531182365, 0)
local +Y -> (-0.531182365, +0.847257514, 0)
```

In the supplied X-right/Y-down map frame, local +Y therefore points left/down. This proves the source basis; it does not assume which signed local axis is the root mesh's long axis. A column-vector implementation in unchanged native XYZ must use the transpose, equivalently `Ry_standard(-y) * Rx_standard(-x) * Rz_standard(-z)`. After converting coordinates with a basis change `F`, use `F * transpose(R) * inverse(F)`. In particular, reflecting Y on both positions and mesh-local coordinates changes the required Z-angle convention; simply negating an angle without specifying that basis change is not established by the native evidence.

Follow-up verification: original EXE constant rows, scale bytes, arithmetic instructions and sine sign-mask instruction were checked; all 65,536 u16 values were checked against the decoder formula; matrix composition was checked with a pose containing nonzero X/Y/Z angles and nonzero placement. No runtime drawing or code edits were performed. Only this audit Markdown file was changed.
