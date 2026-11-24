# Campaign scene audit: gng_001

The first campaign scene is represented by a compact resource bundle:

- `gng_001.pmp` — 146 bytes, header dimensions `4 x 4`;
- `kris_gng_001_a.l2m` — 44 bytes;
- `kris_gng_001_a.tcl` — places four scene objects and binds both binary layers.

The Tcl scene confirms that the runtime must load the PMP and L2M together, then instantiate objects at world coordinates. The Android prototype now uses this real `gng_001` pair instead of the earlier `gng_023` diagnostic sample.

This is not yet a decoded renderer: the PMP payload still needs field-level interpretation. The next safe step is to render its 4x4 tile/material records and correlate them with the L2M bytes and object positions from Tcl.
