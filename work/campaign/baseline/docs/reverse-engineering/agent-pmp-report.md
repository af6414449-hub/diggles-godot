# PMP structure hypothesis: `gng_001` and neighbouring `gng_*.pmp`

## Scope

Static comparison of the files in `data/Templates/pmp`, without changing Android code. The duplicated files under `data/Templates/` have the same sizes/content and were treated as copies.

## Observed layout

All inspected files begin with two little-endian `uint32` values:

```text
0x00  uint32 width
0x04  uint32 height
0x08  byte[width * height] cell-kind/type values
0x08 + width*height  uint32[width * height] cell references/IDs
...   variable tail
```

The second table therefore starts at `0x08 + W*H`, not universally at offset `0x18`. For `gng_001` (`4x4`) it starts at `0x18`; for `gng_002` (`8x4`) at `0x28`; for `gng_025` (`12x12`) at `0x98`.

### `gng_001.pmp`

```text
size       146 bytes (0x92)
dimensions 4 x 4
types      16 bytes, all 0x02
refs       16 little-endian uint32 values, offset 0x18..0x57:
           0x4c, 0x4d, 0x4e, 0x4f,
           0x50, 0x50, 0x50, 0x50,
           0x51, 0x51, 0x51, 0x51,
           0x00, 0x00, 0x00, 0x00
tail       starts at 0x58; 58 bytes, not aligned to a simple uint32 array
```

The tail begins with `uint32 0x13`, followed by packed-looking 16-bit pairs such as `05 00 09 00`, `04 00 0D 00`, and ends with compact byte values. This strongly suggests a count plus a variable-length list of geometry/placement records, followed by a small footer or palette/encoding block.

## Cross-file evidence

The file size is not just `24 + 4*W*H`; the extra tail varies by map and carries the important geometry parameters.

| file | W×H | type bytes | ref-table start | ref-table end | tail start |
|---|---:|---:|---:|---:|---:|
| `gng_001.pmp` | 4×4 | 16 | `0x18` | `0x57` | `0x58` |
| `gng_002.pmp` | 8×4 | 32 | `0x28` | `0xA7` | `0xA8` |
| `gng_007.pmp` | 4×4 | 16 | `0x18` | `0x57` | `0x58` |
| `gng_025.pmp` | 12×12 | 144 | `0x98` | `0x2D7` | `0x2D8` |

Large rectangular families (`gng_001..004`, `gng_007..010`, `gng_025+`) preserve the same header/type/ref-table pattern. The type plane is often all `0x02`, but later files contain `0x00` and other small values, so it should be retained as semantic data rather than discarded.

The reference table contains low integer IDs and repeated values (`0x50`, `0x51`, etc.). This is consistent with references to reusable tile/sector templates or material primitives. It is not plausible as packed screen coordinates: dimensions grow while the values remain small and repeat by rows/regions.

## Hypothesis for fields after offset 24

For a 4×4 file, offset `0x18` is the beginning of the **cell-reference table**, not the beginning of a coordinate record. More generally:

```text
ref_table = uint32[W*H] at 0x08 + W*H
tail      = bytes after ref_table
```

For `gng_001`, the first tail word `0x13` is likely a record count, section tag, or version/count field. The following bytes appear to be a packed stream of 16-bit values, often in pairs. A useful working interpretation is:

```text
uint32 tail_count_or_section;
record[] geometry_or_anchor_records; // likely uint16 fields, variable count
byte[] footer_or_compact_flags;
```

The exact record width is not yet proven. The repeating `0x0009`, `0x0004`, `0x0008`, and `0x0005` values in `gng_001`, and the long repeated `0x00090078` pattern in `gng_007`, suggest quantised local coordinates, dimensions, material IDs, or edge/height samples rather than arbitrary compression.

## Recommended intermediate model

Represent PMP losslessly first:

```text
PmpMap {
  width: u32,
  height: u32,
  cell_types: u8[width*height],
  cell_refs: u32[width*height],
  tail: byte[],
}
```

Add a second, explicitly provisional layer:

```text
PmpDecodedHints {
  ref_id_histogram,
  ref_id_grid,
  candidate_tail_count,
  candidate_u16_stream,
  candidate_records, // only when validated by cross-file invariants
}
```

Do not render `cell_refs` as coordinates or turn the tail into tunnel polygons yet. The safe next experiment is to parse candidate 16-bit pairs from the tail, compare them against the corresponding `.l2m` dimensions/values and Tcl `map_template` offsets, and validate whether the same IDs/records recur across maps. Keep raw bytes and offsets alongside every decoded field so a wrong hypothesis is reversible.

## Confidence

- Header and type-plane boundaries: **high**.
- `uint32[W*H]` reference table: **high**.
- Reference IDs being reusable tile/sector references: **medium**.
- Tail beginning with a count/tag and containing packed 16-bit records: **medium-low**.
- Any direct interpretation as screen coordinates or playable geometry: **not established**.

