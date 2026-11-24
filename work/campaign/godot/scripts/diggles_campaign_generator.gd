extends RefCounted
## Urwald campaign level generator, ported from `Campaign.tcl:first_level`.
##
## FACT (source: data/Scripts/gameplay/Campaign.tcl, read-only):
##   * lines 22-191 define `proc first_level {startx starty}` and build the level
##     from five tables plus a random draw order.
##   * The tables below are transcribed verbatim from lines 24-100.
##   * The draw order below follows lines 101-175 exactly, including the order
##     in which the random values are consumed.
##   * The random values come from the native `irandom` command, reproduced by
##     `res://scripts/diggles_irandom.gd`.
##
## Every table entry keeps the original comment marker index where the source
## carries one, so a reader can match the port against the original file.

const RNG := preload("res://scripts/diggles_irandom.gd")

## Campaign.tcl:26-30 - cave templates with their x/y offset.
const CAVE_LIST: Array = [
	{"name": "urw_hol_001_a", "x": 20, "y": 4},
	{"name": "urw_hol_014_b", "x": 20, "y": 12},
	{"name": "urw_hol_018_c", "x": 28, "y": 16},
	{"name": "urw_hol_019_b", "x": 24, "y": 16},
	{"name": "urw_hol_027_a", "x": 16, "y": 4},
]

## Campaign.tcl:33-46 - cave pairs and their y shift list.
const COMB_LIST: Array = [
	{"left": 0, "right": 1, "y_offsets": [0]},
	{"left": 0, "right": 2, "y_offsets": [0]},
	{"left": 0, "right": 4, "y_offsets": [0]},
	{"left": 1, "right": 0, "y_offsets": [4]},
	{"left": 1, "right": 3, "y_offsets": [4]},
	{"left": 4, "right": 0, "y_offsets": [0]},
	{"left": 4, "right": 2, "y_offsets": [0]},
	{"left": 4, "right": 3, "y_offsets": [0]},
]

## Campaign.tcl:50-52 - tunnel templates with their x/y offset.
const TUNN_LIST: Array = [
	{"name": "urw_gng_013_", "x": 4, "y": 0},
	{"name": "urw_gng_002_", "x": 8, "y": 0},
	{"name": "urw_gng_003_", "x": 12, "y": 0},
]

## Campaign.tcl:55-60 - connection schemes; the first element shifts std_x.
const CON_LIST: Array = [
	[0, 0, 1, 2],
	[0, 0, 2, 1],
	[0, 1, 0, 2],
	[4, 2, 0, 1],
	[4, 2, 1, 0],
	[4, 1, 2, 0],
]

## Campaign.tcl:64-85 - voodoo templates with their variant letters.
const VODO_LIST: Array = [
	{"name": "urw_gng_001_", "letters": "ab"},
	{"name": "urw_gng_007_", "letters": "abcd"},
	{"name": "urw_gng_008_", "letters": "abc"},
	{"name": "urw_gng_009_", "letters": "abcd"},
	{"name": "urw_gng_012_", "letters": "abcd"},
	{"name": "urw_gng_019_", "letters": "abc"},
	{"name": "urw_gng_022_", "letters": "abdeg"},
	{"name": "urw_gng_023_", "letters": "abc"},
	{"name": "urw_gng_026_", "letters": "abc"},
	{"name": "urw_gng_028_", "letters": "bcd"},
	{"name": "urw_gng_030_", "letters": "a"},
	{"name": "urw_gng_032_", "letters": "ab"},
	{"name": "urw_gng_034_", "letters": "acdfhk"},
	{"name": "urw_gng_039_", "letters": "ab"},
	{"name": "urw_gng_042_", "letters": "ab"},
	{"name": "urw_gng_045_", "letters": "ab"},
	{"name": "urw_unq_vodo_001_", "letters": "a"},
	{"name": "urw_gng_004_", "letters": "ab"},
	{"name": "urw_gng_027_", "letters": "abc"},
	{"name": "urw_gng_036_", "letters": "ab"},
	{"name": "urw_gng_043_", "letters": "ab"},
	{"name": "urw_gng_044_", "letters": "ab"},
]

## Campaign.tcl:88-95 - voodoo chains used when the connection index is >= 4.
const VOCON_LIST_1: Array = [
	[[3, 20, 0], [8, 8, 12], [5, 20, 12], [6, 24, 12], [16, -24, 12]],
	[[1, 20, 0], [13, 4, 16], [7, 4, 28], [9, 12, 4], [16, -28, 12]],
	[[2, 20, 0], [5, 20, 8], [6, 24, 8], [15, 8, 8], [12, 4, 16], [6, 16, 24], [16, -28, 12]],
	[[2, 20, 0], [14, 12, 8], [4, 8, 12], [13, 0, 16], [7, 0, 28], [16, -32, 12]],
	[[2, 20, 0], [11, 0, 16], [15, 8, 8], [5, 20, 8], [6, 24, 8], [7, 8, 28], [16, -32, 12]],
	[[1, 20, 0], [6, 16, 20], [4, 8, 8], [14, 12, 4], [10, 4, 12], [16, -28, 12]],
]

## Campaign.tcl:98-100 - voodoo chains used when the connection index is < 2.
const VOCON_LIST_2: Array = [
	[[18, 20, 0], [0, 20, 20], [10, 24, 12], [6, 36, 20], [16, -12, 12]],
	[[20, 20, 0], [21, 32, 4], [17, 20, 20], [10, 36, 12], [6, 48, 20], [16, -12, 12]],
	[[19, 20, 0], [1, 24, 12], [14, 16, 16], [6, 32, 8], [16, -16, 12]],
]

## Campaign.tcl:102 - letter pool of the left tunnel end, indexed by present_side.
const LEFT_LETTERS: Array = ["abdef", "cgih"]

## Campaign.tcl:103 - letter pool of the right tunnel end, indexed by present_side.
const RIGHT_LETTERS: Array = ["cfkh", "abdeg"]

## Campaign.tcl:156-160 - the tunnel suffix uses two letters only for urw_gng_002_.
const TWO_LETTER_TUNNEL: String = "urw_gng_002_"
const LETTERS_AB: String = "ab"
const LETTERS_ABC: String = "abc"


## Build the template placement list of one Urwald level.
##
## `start_x` and `start_y` are the `first_level` arguments; the original calls
## `first_level 208 0` (Campaign.tcl:195).
func first_level(start_x: int, start_y: int, seed_value: int) -> Dictionary:
	var rng: RNG = RNG.new(seed_value)
	var placements: Array[Dictionary] = []

	# Campaign.tcl:101-103 - present side and its letter pools.
	var present_side: int = rng.irandom(2)
	var left_letters: String = LEFT_LETTERS[present_side]
	var right_letters: String = RIGHT_LETTERS[present_side]

	# Campaign.tcl:104-105 - the standard placement origin.
	var std_x: int = start_x + 36
	var std_y: int = start_y + 40

	# Campaign.tcl:109-111 - cave pair and its y shift.
	var comb_index: int = rng.irandom(COMB_LIST.size())
	var comb: Dictionary = COMB_LIST[comb_index]
	var y_offsets: Array = comb["y_offsets"]
	std_y += int(y_offsets[rng.irandom(y_offsets.size())])

	# Campaign.tcl:112-114 - connection scheme; `lrem conn 0` removes the first
	# element, shifts std_x by it and leaves the three tunnel indices behind.
	var conn_index: int = rng.irandom(CON_LIST.size())
	var conn_entry: Array = CON_LIST[conn_index]
	var conn: Array = conn_entry.duplicate()
	std_x += int(conn.pop_front())

	# Campaign.tcl:115-124 - the voodoo chain pool depends on the connection.
	var vocon_list: Array = []
	if conn_index < 2:
		vocon_list = VOCON_LIST_2
	elif conn_index < 4:
		vocon_list = VOCON_LIST_1.duplicate()
		vocon_list.append_array(VOCON_LIST_2)
	else:
		vocon_list = VOCON_LIST_1
	var vodo: Array = vocon_list[rng.irandom(vocon_list.size())]

	# Campaign.tcl:128-134 - left cave plus its tunnel end.
	var left_cave: Dictionary = CAVE_LIST[int(comb["left"])]
	placements.append({
		"template": str(left_cave["name"]),
		"x": std_x - int(left_cave["x"]),
		"y": std_y - int(left_cave["y"]),
	})
	var left_letter: String = left_letters[rng.irandom(left_letters.length())]
	placements.append({
		"template": "urw_gng_021_" + left_letter,
		"x": std_x - int(left_cave["x"]) - 4,
		"y": std_y,
	})

	# Campaign.tcl:137-143 - right cave plus its tunnel end.
	var right_cave: Dictionary = CAVE_LIST[int(comb["right"])]
	placements.append({
		"template": str(right_cave["name"]),
		"x": std_x + 24,
		"y": std_y - int(right_cave["y"]),
	})
	var right_letter: String = right_letters[rng.irandom(right_letters.length())]
	placements.append({
		"template": "urw_gng_022_" + right_letter,
		"x": std_x + int(right_cave["x"]) + 24,
		"y": std_y,
	})

	# Campaign.tcl:146-163 - the tunnel chain. The voodoo origin is taken from
	# the first connection element, where x is still the unshifted std_x.
	var tunnel_x: int = std_x
	var vodo_x: int = std_x - 20
	var vodo_y: int = std_y + 4
	for element: int in conn:
		if element == 0:
			vodo_x = tunnel_x - 20
			vodo_y = std_y + 4
		var tunnel: Dictionary = TUNN_LIST[element]
		var template_name: String = str(tunnel["name"])
		var suffix_pool: String = LETTERS_AB if template_name == TWO_LETTER_TUNNEL else LETTERS_ABC
		var suffix: String = suffix_pool[rng.irandom(suffix_pool.length())]
		placements.append({
			"template": template_name + suffix,
			"x": tunnel_x,
			"y": std_y + int(tunnel["y"]),
		})
		tunnel_x += int(tunnel["x"])

	# Campaign.tcl:166-174 - the voodoo chain.
	for entry: Array in vodo:
		var voodoo: Dictionary = VODO_LIST[int(entry[0])]
		var letters: String = str(voodoo["letters"])
		var letter: String = letters[rng.irandom(letters.length())]
		placements.append({
			"template": str(voodoo["name"]) + letter,
			"x": vodo_x + int(entry[1]),
			"y": vodo_y + int(entry[2]),
		})

	return {
		"seed": seed_value,
		"start": {"x": start_x, "y": start_y},
		"placements": placements,
		"selection": {
			"present_side": present_side,
			"comb_index": comb_index,
			"conn_index": conn_index,
			"vodo_chain_count": vocon_list.size(),
			"vodo_chain": vodo,
		},
	}
