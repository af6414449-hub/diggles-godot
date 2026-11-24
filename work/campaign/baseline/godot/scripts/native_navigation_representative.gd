extends RefCounted
## Selection primitive of EXE5A6350; not the complete cell summary writer.
## Caller supplies all64 known current samples; object/unknown gates stay out.

static func choose(flags: PackedByteArray) -> Variant:
	if flags.size()!=64:
		return null
	var chosen: int = 0x24
	var score: int = 0
	var available: int = 0
	for index: int in range(64):
		if (int(flags[index])&1)==0:
			continue
		available += 1
		var candidate: int = 8+((int(flags[index])&2)<<7)-absi((index&7)-4)-absi((index>>3)-4)
		if candidate>score:
			score = candidate
			chosen = index
	if available==64:
		if (score>>8)!=0:
			while chosen+8<64 and (int(flags[chosen+8])&2)!=0:
				chosen += 8
		else:
			chosen = 0x24
	# Native summary has additional coarse gates. This bounded host graph uses
	# only a representative which is itself proven navigable, never its sentinel.
	if (int(flags[chosen])&1)==0:
		return null
	return Vector2i(chosen&7,chosen>>3)
