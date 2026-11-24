extends RefCounted
## The material of the map of the original, by the generator of the original.
##
## The original does not keep the material of the map in the saved game: it
## generates it when the map is created, and the engine regenerates it again
## every time the map is loaded. The generator is in the scripts of the game
## (data/Scripts/gameplay/Campaign.tcl:2-5):
##
##     map create 512 640
##     sm_draw_stone -border
##     sm_draw_stone -funnel
##     generate_color_variation 0 0 512 640 0
##
## FACT (Diggles.exe, decompilation of 2026-11-24, CTclGlobalMethods::SMDrawStone,
## 0065e090): `sm_draw_stone` resets the material of the cells of a rectangle to
## stone. A cell is reset only when its material is a loose ground (1 or 2), and
## the probability of the reset falls off from the middle of the rectangle to its
## edge:
##
##     w = x2 - x1;  h = y2 - y1;  s = strength / (min(w, h) * 0.2)
##     cx = x1 + w / 2;  cy = y1 + h / 2
##     p = 1.0
##     if (flags & 4) and x > cx:  p -= ((cx - x) / w) * ((cx - x) / w) / s
##     if (flags & 8) and x < cx:  p -= ((cx - x) / w) * ((cx - x) / w) / s
##     if (flags & 1) and y > cy:  p -= ((cy - y) / h) * ((cy - y) / h) / s
##     if (flags & 2) and y < cy:  p -= ((cy - y) / h) * ((cy - y) / h) / s
##     if the material of the cell is 1 or 2:
##         r = rng.next() & 0x7fff
##         if r <= p * 32768.0: the material of the cell is stone
##
## The order of the cells of the rectangle is the outer loop over x and the inner
## loop over y, and the random number is taken only for a cell of a loose
## ground, so the stream of the engine depends on the order of the cells. The
## last row and the last column of the rectangle are not drawn at all: the
## engine walks the cells up to x2 - 2 and y2 - 2.
##
## The two calls of the chapter (Campaign.tcl:3-4):
##
##   -border: three bands, the lower one is not drawn at all:
##     the top:   rect(0, 0, 512, 32)      flags 1, strength 3.0
##     the left:  rect(0, 0, 32, 644)      flags 4, strength 1.0
##     the right: rect(480, 0, 512, 644)    flags 8, strength 1.0
##   -funnel: thirty horizontal bands of six rows, y = 16 + 4k, k = 0..29,
##   the width of the walls w = 236 - 8k. The right wall is drawn first:
##     the right wall: rect(512 - w, y, 512, y + 6) flags 8, strength 1.0
##     the left wall:  rect(0, y, w, y + 6)       flags 4, strength 1.0
##
## FACT (the same decompilation): the random stream of the engine is an
## MT19937 with a state of 624 words, seeded by the engine itself with 0x1105 on
## the first use, and with a tempering that is NOT the standard one:
##
##     y ^= y >> 11
##     y ^= (y & 0xFF3A58AD) << 7
##     y ^= (y & 0xFFFFDF8C) << 15
##     y ^= y >> 18
##
## The place of the stream at the moment of the stone is the number of the
## numbers that the game had taken before it: the creation of the map takes one
## number per cell (327 680 for the map of the chapter), the menu map of
## systeminit.tcl takes 4096, and the menu, the AI and the level generator of
## the game take the rest. That number is not in the files of the game - it
## depends on the run - so the port does not use this generator for the cells
## of the chapter: the saved game of the owner holds the material of the
## original itself, cell by cell, and that is the material the port draws. This
## generator is the rule of the original and the fallback of the port for the
## cells that the saved game does not cover.

const WIDTH: int = 512
const HEIGHT: int = 640

## The codes of the material of the original: 0 is stone, 1 and 2 are the two
## loose grounds (sand and earth), 3 is the rock of the templates.
const MATERIAL_STONE: int = 0
const MATERIAL_SAND: int = 1
const MATERIAL_EARTH: int = 2
const MATERIAL_ROCK: int = 3

## The seed of the random stream of the engine (FUN_004454d0: the first call
## initialises the state with 0x1105).
const RNG_SEED: int = 0x1105

## The multiplier of the seed of the state of the engine (0x10dcd = 69069).
const RNG_MULTIPLIER: int = 69069

const MASK32: int = 0xffffffff

## The place of the stream at the moment of the stone of the chapter.
##
## The place is NOT in the files of the game: the engine takes one number for
## every cell when the map is created (327 680 for the map of the chapter), the
## menu map of systeminit.tcl takes 4096, and the menu, the AI and the level
## generator of the game take the rest - and how much they take depends on the
## run. The search against the saved game of the owner (the decision of a cell
## of the border of the map against the stream) covered thirty million places
## of the stream and did not find the place: the best of them agrees with the
## saved game on the level of chance.
##
## The value below is the best candidate of that search. The shape of the belt
## (the band of the border and the walls of the funnel) does not depend on it,
## only the random fringe of the belt does - and the port takes the material of
## the saved game itself for the cells of the chapter, which is the map of the
## original cell by cell.
const STREAM_PLACE: int = 2158435


## The random stream of the engine: MT19937 with a tempering of its own.
##
## FACT (the decompilation of 2026-11-24): the state is 624 words, the lag is
## 397, the twist is the standard one and the tempering is
##
##     y ^= y >> 11
##     y ^= (y & 0xFF3A58AD) << 7
##     y ^= (y & 0xFFFFDF8C) << 15
##     y ^= y >> 18
##
## The state is initialised by the engine itself on the first use: the seed
## walks through the state with the multiplier 69069.
class Mt19937:
	const N: int = 624
	const M: int = 397
	const MATRIX_A: int = 0x9908b0df
	const UPPER_MASK: int = 0x80000000
	const LOWER_MASK: int = 0x7fffffff

	var _state: PackedInt32Array = PackedInt32Array()
	var _index: int = 0x270
	## The number of the numbers taken out of the stream (diagnostic).
	var drawn: int = 0

	func _init(seed_value: int = 0x1105) -> void:
		_state.resize(N)
		_seed(seed_value)

	## The seed of the state (FUN_004454d0).
	func _seed(seed_value: int) -> void:
		var value: int = seed_value & MASK32
		for index in range(N):
			var high: int = value & 0xffff0000
			var first: int = (value * RNG_MULTIPLIER + 1) & MASK32
			_state[index] = high | ((first >> 16) & 0xffff)
			value = (first * RNG_MULTIPLIER + 1) & MASK32
		_index = 0x270

	## The next number of the stream.
	func next() -> int:
		if _index >= N:
			_twist()
			_index = 0
		var value: int = _state[_index] & MASK32
		_index += 1
		drawn += 1
		value = (value ^ (value >> 11)) & MASK32
		value = (value ^ ((value & 0xff3a58ad) << 7)) & MASK32
		value = (value ^ ((value & 0xffffdf8c) << 15)) & MASK32
		value = (value ^ (value >> 18)) & MASK32
		return value

	## Takes count numbers out of the stream without using them.
	func skip(count: int) -> void:
		for step in range(count):
			next()

	## The twist of the state.
	func _twist() -> void:
		var state: PackedInt32Array = _state
		# The first 227 words take their partner from the upper half of the
		# state, the rest from the lower half: the engine splits the loop the
		# same way to avoid the modulo.
		for index in range(227):
			_mix(state, index, index + M)
		for index in range(227, N - 1):
			_mix(state, index, index - 227)
		# The last word of the state: the engine mixes the old word 623 and the
		# new word 0 the other way round than the loop above (FUN_0049c670).
		var last: int = N - 1
		var mixed: int = (((state[0] & MASK32) ^ (state[last] & MASK32)) & LOWER_MASK) \
			^ (state[last] & MASK32)
		mixed &= MASK32
		var value: int = ((state[M - 1] & MASK32) ^ (mixed >> 1)) & MASK32
		if (mixed & 1) != 0:
			value ^= MATRIX_A
		state[last] = value & MASK32

	func _mix(state: PackedInt32Array, index: int, partner: int) -> void:
		var current: int = state[index] & MASK32
		var next_word: int = state[index + 1] & MASK32
		var mixed: int = (((current ^ next_word) & LOWER_MASK) ^ current) & MASK32
		var value: int = ((state[partner] & MASK32) ^ (mixed >> 1)) & MASK32
		if (mixed & 1) != 0:
			value ^= MATRIX_A
		state[index] = value & MASK32


## The material of every cell of the map, by the generator of the original.
##
## The result is {"materials": PackedByteArray}: the material of every cell of
## the map. The creation of the map of the original (the command "map create")
## gives every cell the earth, and the stone is drawn on top of it.
static func generate(width: int = WIDTH, height: int = HEIGHT,
		stream_place: int = STREAM_PLACE) -> Dictionary:
	var materials := PackedByteArray()
	materials.resize(width * height)
	materials.fill(MATERIAL_EARTH)
	var rng := Mt19937.new()
	# Everything the game took before the stone of the chapter: the creation of
	# the map of the chapter and of the menu map, the menu, the AI and the level
	# generator of the game.
	rng.skip(stream_place)
	# sm_draw_stone -border: the top band, the left band, the right band. The
	# lower band of the map is not drawn at all.
	draw_stone(rng, materials, width, height, Rect2i(0, 0, width, 32), 1, 3.0)
	draw_stone(rng, materials, width, height, Rect2i(0, 0, 32, height + 4), 4, 1.0)
	draw_stone(rng, materials, width, height,
		Rect2i(width - 32, 0, 32, height + 4), 8, 1.0)
	# sm_draw_stone -funnel: thirty bands of six rows, the right wall first.
	var band_width: int = 2 * (width / 4) - 20
	var band_y: int = 16
	while band_width > 0:
		draw_stone(rng, materials, width, height,
			Rect2i(width - band_width, band_y, band_width, 6), 8, 1.0)
		draw_stone(rng, materials, width, height,
			Rect2i(0, band_y, band_width, 6), 4, 1.0)
		band_width -= 8
		band_y += 4
	return {"materials": materials}


## Draws the stone into a rectangle of the map (FUN_005fc9d0).
##
## The rectangle is cut by the border of the map, and the last row and the last
## column of it are not drawn at all: the engine walks the cells with the outer
## loop over x and the inner loop over y, up to x2 - 2 and y2 - 2.
##
## The cells are taken with the outer loop over x and the inner loop over y, and
## the random number is taken only for a cell of a loose ground - and it is
## taken even when the probability is below zero.
static func draw_stone(rng: Mt19937, materials: PackedByteArray, width: int, height: int,
		rect: Rect2i, flags: int, strength: float) -> void:
	var x1: int = maxi(rect.position.x, 0)
	var y1: int = maxi(rect.position.y, 0)
	var x2: int = mini(rect.position.x + rect.size.x, width)
	var y2: int = mini(rect.position.y + rect.size.y, height)
	if x1 >= x2 or y1 >= y2:
		return
	var span_x: float = float(x2 - x1)
	var span_y: float = float(y2 - y1)
	var falloff: float = strength / (minf(span_x, span_y) * 0.2)
	var centre_x: int = x1 + (x2 - x1) / 2
	var centre_y: int = y1 + (y2 - y1) / 2
	for x in range(x1, x2 - 1):
		for y in range(y1, y2 - 1):
			var probability: float = 1.0
			if (flags & 4) != 0 and x > centre_x:
				var distance: float = float(centre_x - x)
				probability = 1.0 - ((distance / span_x) * distance / span_x) / falloff
			if (flags & 8) != 0 and x < centre_x:
				var distance2: float = float(centre_x - x)
				probability -= ((distance2 / span_x) * distance2 / span_x) / falloff
			if (flags & 1) != 0 and y > centre_y:
				var distance3: float = float(centre_y - y)
				probability -= ((distance3 / span_y) * distance3 / span_y) / falloff
			if (flags & 2) != 0 and y < centre_y:
				var distance4: float = float(centre_y - y)
				probability -= ((distance4 / span_y) * distance4 / span_y) / falloff
			var index: int = y * width + x
			var material: int = int(materials[index])
			if material != MATERIAL_SAND and material != MATERIAL_EARTH:
				continue
			var number: int = rng.next() & 0x7fff
			if float(number) <= probability * 32768.0:
				materials[index] = MATERIAL_STONE
