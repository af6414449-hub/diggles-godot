# PMP pattern probe: early GNG templates

Comparing the early campaign templates shows that the first two unsigned little-endian values are dimensions, not arbitrary metadata:

| File | Size | Dimensions |
|---|---:|---:|
| `gng_001.pmp` | 146 | 4 x 4 |
| `gng_002.pmp` | 230 | 8 x 4 |
| `gng_003.pmp` | 330 | 12 x 4 |
| `gng_004.pmp` | 432 | 16 x 4 |
| `gng_008.pmp` | 462 | 4 x 8 |
| `gng_025.pmp` | 1162 | 12 x 12 |

The byte immediately after the 8-byte header is a material-like cell stream: many templates contain repeated `02` values there. The remaining payload is structured and grows with the template, but is not a simple one-byte-per-cell bitmap. In `gng_001`, the first post-cell values include the sequential words `0x4c` through `0x51`, suggesting an index/reference table rather than world coordinates.

Conclusion: the current floating diamonds were not a valid geometry reconstruction. Keep cell/material indices and reference records separate. A later audit found a second candidate structure in the counted u16 array; see the addendum below.

## Addendum: counted u16 sequence

Across all 90 top-level PMP resources, the byte-size invariant is `u32 count + count u16 values + width*height trailing bytes` after the cell/reference arrays. Pairing consecutive u16 values as `(x,y)` at 32 units per cell fits 96.9% of GNG pairs and 95.7% of GSG pairs, but only 68.8% of `caves_*` pairs. Repeated values such as `0x00090078` correspond to the pair `(120,9)`. Seventy-nine of the 90 arrays contain an odd final u16 that does not fit this pairing.

This is a candidate coordinate stream, not a confirmed vertex/index format. Cell references are not direct indices into the same local u16 array: most nonzero references exceed its length. Verify point connectivity and the exceptional values before building terrain geometry. Full counts are in `pmp-layout-audit.json`.
