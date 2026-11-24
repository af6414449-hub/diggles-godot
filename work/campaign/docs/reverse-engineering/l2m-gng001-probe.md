# L2M probe: gng_001

`kris_gng_001_a.l2m` has the header `M2L\0`, dimensions `4 x 4`, and 16 little-endian signed samples. The samples are non-negative and mostly multiples of 64:

```text
448 1472 1088 0
4288 20928 17856 1216
192 4544 21696 16576
192 4288 16576 0
```

Dividing by 64 produces compact height-like values (`7, 23, 17, ...`), which is a stronger hypothesis than a signed passability mask. Variants `a`, `b`, and `c` retain the same 4x4 structure but alter the samples, consistent with alternative layer geometry or orientation.

The current white cell boundaries are therefore only a diagnostic grid. The renderer should next interpolate these samples into a height surface and use PMP references to choose material/visibility, rather than treating L2M sign changes as tunnels.
