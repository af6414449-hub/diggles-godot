extends RefCounted
## Diggles.exe `irandom` stream, recovered from the native binary.
##
## FACT (Diggles.exe disassembly, read-only source of truth):
##   * `irandom` is a native Tcl command. Its name is registered at 0x61AFC8 and
##     the handler lives at 0x62F780.
##   * The handler draws one 32 bit value from the generator at 0x49C670, masks
##     it with 0x7FFFFFFF and returns the remainder of the Tcl argument:
##     `irandom n` == `(draw & 0x7FFFFFFF) % n`. A limit of 1 (or 0) divides by
##     0x7FFFFFFF instead.
##   * The generator is a Mersenne Twister: 624 state words, the classic mag01
##     table {0x0, 0x9908B0DF}, tempering masks 0x9D2C5680 and 0xEFC60000.
##     The state is *not* filled by the standard MT19937 initialiser; the native
##     seeding routine at 0x4454D0 derives it from an LCG with the multiplier
##     69069.
##   * Diggles.exe seeds the generator once at start-up with `GetTickCount()`
##     (0x401AE0 -> 0x4454D0), so the original campaign level depends on the
##     moment the game started. The algorithm is reproduced here; the seed value
##     is chosen by the host.
##
## The draw order therefore matches the original. Only the seed differs from a
## recorded original session.

const STATE_SIZE: int = 624
const LAST_INDEX: int = 623
const MATRIX_A: int = 0x9908B0DF
const TEMPER_B: int = 0x9D2C5680
const TEMPER_C: int = 0xEFC60000
const LCG_MULTIPLIER: int = 69069
const UINT32: int = 0xFFFFFFFF
const SIGN_CLEARED: int = 0x7FFFFFFF
const FIRST_LOOP_END: int = 227
const MATRIX_LAG: int = 397
const SECOND_LOOP_LAG: int = 227
const LAST_ELEMENT_SOURCE: int = 396

var _state: PackedInt32Array = PackedInt32Array()
var _index: int = 0


func _init(seed_value: int = 0) -> void:
	seed_with(seed_value)


## Fill the 624 word state exactly like the native routine at 0x4454D0.
func seed_with(seed_value: int) -> void:
	_state.resize(STATE_SIZE)
	var value: int = seed_value & UINT32
	for index: int in range(STATE_SIZE):
		var high: int = value & 0xFFFF0000
		var next_value: int = ((value * LCG_MULTIPLIER) + 1) & UINT32
		_state[index] = high | (next_value >> 16)
		value = ((next_value * LCG_MULTIPLIER) + 1) & UINT32
	_index = STATE_SIZE


## One tempered 32 bit draw, identical to the native generator at 0x49C670.
func next_u32() -> int:
	var value: int = 0
	if _index >= STATE_SIZE:
		_twist()
		_index = 1
		value = _state[0] & UINT32
	else:
		value = _state[_index] & UINT32
		_index += 1
	return _temper(value)


## The native `irandom n` command.
##
## The handler reads the argument with `Tcl_GetIntFromObj` into a local int,
## divides the masked draw by that value and keeps the remainder. A limit of
## zero is replaced by 0x7FFFFFFF; a limit of one therefore yields zero, which
## is what Campaign.tcl relies on for its single element shift lists.
func irandom(limit: int) -> int:
	var value: int = next_u32() & SIGN_CLEARED
	if limit == 0:
		return value % SIGN_CLEARED
	return value % limit


func _temper(value: int) -> int:
	var result: int = value & UINT32
	result = (result ^ (result >> 11)) & UINT32
	result = (result ^ ((result << 7) & TEMPER_B)) & UINT32
	result = (result ^ ((result << 15) & TEMPER_C)) & UINT32
	result = (result ^ (result >> 18)) & UINT32
	return result


## The native state is unsigned. GDScript integers are signed, so every word is
## masked back into the 0..0xFFFFFFFF range before it is shifted.
func _twist() -> void:
	for index: int in range(0, FIRST_LOOP_END):
		var current: int = _state[index] & UINT32
		var following: int = _state[index + 1] & UINT32
		var mixed: int = (((current ^ following) & SIGN_CLEARED) ^ current) & UINT32
		mixed = ((mixed >> 1) ^ (MATRIX_A if (mixed & 1) != 0 else 0)) & UINT32
		_state[index] = (mixed ^ (_state[index + MATRIX_LAG] & UINT32)) & UINT32
	for index: int in range(FIRST_LOOP_END, LAST_INDEX):
		var current: int = _state[index] & UINT32
		var following: int = _state[index + 1] & UINT32
		var mixed: int = (((current ^ following) & SIGN_CLEARED) ^ current) & UINT32
		mixed = ((mixed >> 1) ^ (MATRIX_A if (mixed & 1) != 0 else 0)) & UINT32
		_state[index] = (mixed ^ (_state[index - SECOND_LOOP_LAG] & UINT32)) & UINT32
	# Native index 623: the engine's bounds guard falls back to state[0].
	var tail_current: int = _state[LAST_INDEX] & UINT32
	var tail_next: int = _state[0] & UINT32
	var tail: int = (((tail_current ^ tail_next) & SIGN_CLEARED) ^ tail_current) & UINT32
	tail = ((tail >> 1) ^ (MATRIX_A if (tail & 1) != 0 else 0)) & UINT32
	_state[LAST_INDEX] = (tail ^ (_state[LAST_ELEMENT_SOURCE] & UINT32)) & UINT32
	# Native post-twist step at 0x49C87A: one further state[623] update.
	var previous: int = _state[LAST_INDEX] & UINT32
	var first: int = _state[0] & UINT32
	var post: int = (((first ^ previous) & SIGN_CLEARED) ^ previous) & UINT32
	post = ((post >> 1) ^ (MATRIX_A if (post & 1) != 0 else 0)) & UINT32
	_state[LAST_INDEX] = (post ^ (_state[LAST_ELEMENT_SOURCE] & UINT32)) & UINT32
