extends RefCounted
## Pure arithmetic for the audited EXE; all times are game seconds.
## This does not choose routes, transform vec_a directions, or own an actor.
## See docs/reverse-engineering/native-animation-timing-2026-11-17.md.

enum X87Rounding { NEAREST_EVEN, DOWN, UP, TOWARD_ZERO }

const FRAMES_PER_GAME_SECOND: float = 10.0
const SIMULATION_STEP_GAME_SECONDS: float = 0.1
const VEC_A_TO_SLOT_SPEED: float = 0.05000000074505806
const FRAME_BIAS: float = 0.05000000074505806


static func slot_speed(vec_a: Vector3) -> float:
	# 0x42290E..0x42293E; direction comes from the route, not this vector.
	return PackedFloat32Array([vec_a.length() * VEC_A_TO_SLOT_SPEED])[0]


static func distance_for_game_seconds(vec_a: Vector3, delta_game_seconds: float) -> float:
	assert(is_finite(delta_game_seconds) and delta_game_seconds >= 0.0)
	return slot_speed(vec_a) * delta_game_seconds


static func frame_at_tick(tick: int, frame_count: int, looping: bool) -> int:
	# Discrete nominal ticks avoid inventing a wall-clock or FPU rounding mode.
	assert(tick >= 0 and frame_count > 0)
	return tick % frame_count if looping else mini(tick, frame_count - 1)


static func new_clock(frame_count: int, start_game_seconds: float, playback_mode: int, start_frame: int = 0) -> Dictionary:
	# Native modes: 0 = fixed, 1 = once, 2 = loop. +0x1C starts at -1.
	assert(frame_count > 0 and playback_mode >= 0 and playback_mode <= 2)
	assert(start_frame >= 0 and start_frame < frame_count and is_finite(start_game_seconds))
	return {"frame_count": frame_count, "start_game_seconds": start_game_seconds,
		"mode": playback_mode, "start_frame": start_frame, "last_frame": -1}


static func sample_clock(state: Dictionary, game_seconds: float, x87_rounding: X87Rounding) -> Dictionary:
	# 0x462040. Return a new state: the caller retains independent actor clocks.
	assert(is_finite(game_seconds) and game_seconds >= float(state["start_game_seconds"]))
	var result: Dictionary = state.duplicate()
	if int(state["mode"]) == 0:
		result["frame_index"] = int(state["start_frame"])
		return result
	var elapsed: float = game_seconds - float(state["start_game_seconds"])
	var counter: float = PackedFloat32Array([elapsed * FRAMES_PER_GAME_SECOND + FRAME_BIAS])[0]
	var frame: int = int(state["start_frame"]) + _fistp(counter, x87_rounding)
	if int(state["last_frame"]) == -1:
		frame = 0
	if int(state["mode"]) == 1 and frame >= int(state["frame_count"]):
		result["mode"] = 0
		result["start_frame"] = int(state["frame_count"]) - 1
		result["frame_index"] = int(result["start_frame"])
		return result
	if int(state["mode"]) == 2:
		frame %= int(state["frame_count"])
	result["last_frame"] = frame
	result["frame_index"] = maxi(0, frame)
	return result


static func _fistp(value: float, rounding_mode: X87Rounding) -> int:
	match rounding_mode:
		X87Rounding.DOWN:
			return int(floorf(value))
		X87Rounding.UP:
			return int(ceilf(value))
		X87Rounding.TOWARD_ZERO:
			return int(value)
		X87Rounding.NEAREST_EVEN:
			var lower: float = floorf(value)
			var fraction: float = value - lower
			if fraction == 0.5:
				return int(lower) if int(lower) % 2 == 0 else int(lower) + 1
			return int(lower) if fraction < 0.5 else int(lower) + 1
	assert(false, "Supply an observed x87 rounding mode")
	return 0
