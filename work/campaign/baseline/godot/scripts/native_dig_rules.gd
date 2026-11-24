extends RefCounted
## Diggles.exe 0x597430..0x597456 / 0x596C22..0x596C5C.
## A tunnel mark is 3; a cave mark uses bit 8 plus a two-bit depth code.


static func target_height(nibble: int) -> int:
	var mark: int = nibble & 15
	if mark == 0:
		return 15
	if (mark & 8) == 0:
		return 11
	return maxi(0, 4 * (mark & 3) - 1)


static func corridor_indices_allowed(indices: Vector2i) -> bool:
	# Positive native indices, not indices of the old 2.5-unit preview grid.
	# 0x56672B..0x56674D and 0x5668D0..0x5668E7.
	return (indices.x & indices.y & 1) == 0
