class_name NativeCampaignLevel
extends RefCounted
## Data-only model of the original Urwald campaign chapter level.
##
## The original chapter is not a map file: `Scripts/gameplay/Campaign.tcl`
## assembles it from templates at load time. This is a faithful port of the
## `first_level` procedure (Campaign.tcl:22-191) plus the chapter prologue and
## epilogue that surround it (Campaign.tcl:1-20, 195-216).
##
## It creates no Nodes and calls no game API. `generate()` returns the ordered
## template placement list; a scene adapter turns it into meshes and objects.
##
## Source of truth: the installed game, read-only:
##   C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data
##
## RNG: the engine `irandom` command is a native routine, not a Tcl procedure.
## The stream below is the MT19937 variant recovered from Diggles.exe
## (0x61afc8 registers irandom -> 0x62f780 -> 0x49c670; 0x4454d0 seeds the
## 624-word state). The engine seeds it from a wall-clock value, so the seed
## of a recorded chapter is unknown; a seed given here reproduces the exact
## placement sequence for that seed.

const SOURCE_FILE: String = "Scripts/gameplay/Campaign.tcl"

const MAP_WIDTH: int = 512
const MAP_HEIGHT: int = 640

## Campaign.tcl:12-13, 20 - the two templates placed before first_level runs.
const PROLOGUE_TEMPLATES: Array[Dictionary] = [
	{"template": "urw_unq_start", "x": 208, "y": 0, "role": "chapter_start"},
	{"template": "urw_unq_hoehlenmalerei", "x": 30, "y": 23, "role": "layer_only"},
]

## Campaign.tcl:10 - the initial camera of the chapter.
const INITIAL_VIEW: Dictionary = {"x": 246.7, "y": 28.8, "zoom": 1.478, "rx": -0.29, "ry": 0.05}

## Campaign.tcl:206-209 - the fog rectangle removed at the end of the chapter.
const FOG_REMOVER: Dictionary = {"class": "FogRemover", "position": Vector3(239.0, 14.0, 15.0),
	"fog_remove": [0, 46, 22], "undeletable": true}

## Campaign.tcl:198-203 - every object of this class is deleted after assembly.
const DELETED_CLASS: String = "Wuker"

## Campaign.tcl:25-30
const CAVE_LIST: Array[Dictionary] = [
	{"name": "urw_hol_001_a", "x_offset": 20, "y_offset": 4},
	{"name": "urw_hol_014_b", "x_offset": 20, "y_offset": 12},
	{"name": "urw_hol_018_c", "x_offset": 28, "y_offset": 16},
	{"name": "urw_hol_019_b", "x_offset": 24, "y_offset": 16},
	{"name": "urw_hol_027_a", "x_offset": 16, "y_offset": 4},
]

## Campaign.tcl:33-46. `y_list` holds the optional vertical shift of the pair.
const COMB_LIST: Array[Dictionary] = [
	{"left": 0, "right": 1, "y_list": [0]},
	{"left": 0, "right": 2, "y_list": [0]},
	{"left": 0, "right": 4, "y_list": [0]},
	{"left": 1, "right": 0, "y_list": [4]},
	{"left": 1, "right": 3, "y_list": [4]},
	{"left": 4, "right": 0, "y_list": [0]},
	{"left": 4, "right": 2, "y_list": [0]},
	{"left": 4, "right": 3, "y_list": [0]},
]

## Campaign.tcl:50-52
const TUNNEL_LIST: Array[Dictionary] = [
	{"name": "urw_gng_013_", "x_offset": 4, "y_offset": 0},
	{"name": "urw_gng_002_", "x_offset": 8, "y_offset": 0},
	{"name": "urw_gng_003_", "x_offset": 12, "y_offset": 0},
]

## Campaign.tcl:55-60. The first element is the horizontal shift of the whole
## level; the remaining three are the tunnel sequence.
const CONNECTION_LIST: Array[Dictionary] = [
	{"x_shift": 0, "tunnels": [0, 0, 1, 2]},
	{"x_shift": 0, "tunnels": [0, 0, 2, 1]},
	{"x_shift": 0, "tunnels": [0, 1, 0, 2]},
	{"x_shift": 4, "tunnels": [4, 2, 0, 1]},
	{"x_shift": 4, "tunnels": [4, 2, 1, 0]},
	{"x_shift": 4, "tunnels": [4, 1, 2, 0]},
]

## Campaign.tcl:64-85 - voodoo template prefixes and their letter variants.
const VODO_LIST: Array[Dictionary] = [
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

## Campaign.tcl:88-95
const VODO_CHAINS_LEFT: Array[Array] = [
	[[3, 20, 0], [8, 8, 12], [5, 20, 12], [6, 24, 12], [16, -24, 12]],
	[[1, 20, 0], [13, 4, 16], [7, 4, 28], [9, 12, 4], [16, -28, 12]],
	[[2, 20, 0], [5, 20, 8], [6, 24, 8], [15, 8, 8], [12, 4, 16], [6, 16, 24], [16, -28, 12]],
	[[2, 20, 0], [14, 12, 8], [4, 8, 12], [13, 0, 16], [7, 0, 28], [16, -32, 12]],
	[[2, 20, 0], [11, 0, 16], [15, 8, 8], [5, 20, 8], [6, 24, 8], [7, 8, 28], [16, -32, 12]],
	[[1, 20, 0], [6, 16, 20], [4, 8, 8], [14, 12, 4], [10, 4, 12], [16, -28, 12]],
]

## Campaign.tcl:98-100
const VODO_CHAINS_RIGHT: Array[Array] = [
	[[18, 20, 0], [0, 20, 20], [10, 24, 12], [6, 36, 20], [16, -12, 12]],
	[[20, 20, 0], [21, 32, 4], [17, 20, 20], [10, 36, 12], [6, 48, 20], [16, -12, 12]],
	[[19, 20, 0], [1, 24, 12], [14, 16, 16], [6, 32, 8], [16, -16, 12]],
]

## Campaign.tcl:102-103 - the letter sets of the two end pieces.
const LEFT_LETTER_SETS: Array[String] = ["abdef", "cgih"]
const RIGHT_LETTER_SETS: Array[String] = ["cfkh", "abdeg"]

## Campaign.tcl:195 - the only call site of first_level in the chapter.
const CHAPTER_START: Dictionary = {"x": 208, "y": 0}

var _rng: DigglesRandom


## Builds the template placement list of one chapter level.
## `seed` selects the random choices; the original seeds the engine from a
## wall-clock value, so a recorded chapter needs its own seed to match.
func generate(seed_value: int, start_x: int = CHAPTER_START["x"], start_y: int = CHAPTER_START["y"]) -> Dictionary:
	_rng = DigglesRandom.new(seed_value)
	var placements: Array[Dictionary] = []
	for prologue: Dictionary in PROLOGUE_TEMPLATES:
		placements.append(prologue.duplicate(true))

	# Campaign.tcl:101-125 - the random choices, in the original order.
	var present_side: int = _rng.irandom(2)
	var left_letters: String = LEFT_LETTER_SETS[present_side]
	var right_letters: String = RIGHT_LETTER_SETS[present_side]
	var std_x: int = int(start_x) + 36
	var std_y: int = int(start_y) + 40

	var comb_index: int = _rng.irandom(COMB_LIST.size())
	var comb: Dictionary = COMB_LIST[comb_index]
	var y_list: Array = comb["y_list"]
	std_y += int(y_list[_rng.irandom(y_list.size())])

	var conn_index: int = _rng.irandom(CONNECTION_LIST.size())
	var connection: Dictionary = CONNECTION_LIST[conn_index]
	var tunnels: Array = (connection["tunnels"] as Array).duplicate()
	# Campaign.tcl:114 - lrem conn 0 consumes the first element as x shift.
	std_x += int(tunnels[0])
	tunnels.remove_at(0)

	var chains: Array = _voodoo_chains(conn_index)
	var chain: Array = chains[_rng.irandom(chains.size())]

	# Campaign.tcl:128-134 - left cave and its end piece.
	var left: Dictionary = CAVE_LIST[int(comb["left"])]
	var left_x: int = std_x - int(left["x_offset"])
	var left_y: int = std_y - int(left["y_offset"])
	placements.append({"template": String(left["name"]), "x": left_x, "y": left_y, "role": "cave"})
	var left_letter: String = left_letters[_rng.irandom(left_letters.length())]
	placements.append({"template": "urw_gng_021_" + left_letter,
		"x": left_x - 4, "y": std_y, "role": "cave_end"})

	# Campaign.tcl:137-143 - right cave and its end piece.
	var right: Dictionary = CAVE_LIST[int(comb["right"])]
	var right_x: int = std_x + 24
	var right_y: int = std_y - int(right["y_offset"])
	placements.append({"template": String(right["name"]), "x": right_x, "y": right_y, "role": "cave"})
	var right_letter: String = right_letters[_rng.irandom(right_letters.length())]
	placements.append({"template": "urw_gng_022_" + right_letter,
		"x": std_x + int(right["x_offset"]) + 24, "y": std_y, "role": "cave_end"})

	# Campaign.tcl:146-163 - the tunnel chain. vodo_x is fixed when the chain
	# contains tunnel 0, at the x the chain has reached by then.
	var x: int = std_x
	var vodo_x: int = 0
	var vodo_y: int = 0
	for tunnel_id: int in tunnels:
		if tunnel_id == 0:
			vodo_x = x - 20
			vodo_y = std_y + 4
		var tunnel: Dictionary = TUNNEL_LIST[tunnel_id]
		var prefix: String = String(tunnel["name"])
		var letters: String = "ab" if prefix == "urw_gng_002_" else "abc"
		placements.append({"template": prefix + letters[_rng.irandom(letters.length())],
			"x": x, "y": std_y + int(tunnel["y_offset"]), "role": "tunnel"})
		x += int(tunnel["x_offset"])

	# Campaign.tcl:166-174 - the voodoo chain.
	for item: Array in chain:
		var voodoo: Dictionary = VODO_LIST[int(item[0])]
		var variants: String = String(voodoo["letters"])
		var name: String = String(voodoo["name"]) + variants[_rng.irandom(variants.length())]
		placements.append({"template": name, "x": vodo_x + int(item[1]), "y": vodo_y + int(item[2]),
			"role": "voodoo"})

	return {
		"seed": seed_value,
		"map_size": Vector2i(MAP_WIDTH, MAP_HEIGHT),
		"start": Vector2i(int(start_x), int(start_y)),
		"present_side": present_side,
		"left_letters": left_letters,
		"right_letters": right_letters,
		"combination_index": comb_index,
		"connection_index": conn_index,
		"voodoo_chain_count": chains.size(),
		"voodoo_chain_length": chain.size(),
		"initial_view": INITIAL_VIEW.duplicate(true),
		"fog_remover": FOG_REMOVER.duplicate(true),
		"deleted_class": DELETED_CLASS,
		"placements": placements,
		"source": SOURCE_FILE + ":first_level",
	}


## Campaign.tcl:115-124 - the chain table depends on the connection index.
func _voodoo_chains(conn_index: int) -> Array:
	if conn_index < 2:
		return VODO_CHAINS_RIGHT
	if conn_index < 4:
		return VODO_CHAINS_LEFT + VODO_CHAINS_RIGHT
	return VODO_CHAINS_LEFT


## The engine random stream recovered from Diggles.exe.
## 0x4454d0 seeds 624 words, 0x49c670 produces the next word.
class DigglesRandom:
	var _state: PackedInt64Array = PackedInt64Array()
	var _index: int = 624

	const MASK: int = 0xFFFFFFFF
	const STATE_SIZE: int = 624

	func _init(seed_value: int) -> void:
		_state.resize(STATE_SIZE)
		var value: int = seed_value & MASK
		for index: int in range(STATE_SIZE):
			var first: int = (value * 69069 + 1) & MASK
			_state[index] = (value & 0xFFFF0000) | (first >> 16)
			value = (first * 69069 + 1) & MASK
		_index = STATE_SIZE

	func next_u32() -> int:
		if _index >= STATE_SIZE:
			for index: int in range(STATE_SIZE):
				var mixed: int = (_state[index] & 0x80000000) | (_state[(index + 1) % STATE_SIZE] & 0x7FFFFFFF)
				var value: int = _state[(index + 397) % STATE_SIZE] ^ (mixed >> 1)
				if mixed & 1:
					value ^= 0x9908B0DF
				_state[index] = value
			_index = 0
		var result: int = _state[_index]
		_index += 1
		result ^= result >> 11
		result ^= (result << 7) & 0x9D2C5680
		result ^= (result << 15) & 0xEFC60000
		result ^= result >> 18
		return result & MASK

	## 0x49c670 masks to 31 bits and takes the remainder by the argument.
	func irandom(limit: int) -> int:
		if limit <= 0:
			push_error("irandom limit must be positive")
			return 0
		return (next_u32() & 0x7FFFFFFF) % limit
