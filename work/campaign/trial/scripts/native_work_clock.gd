extends RefCounted
## Audited gethours / work membership arithmetic. Float32 boundaries match SSE.
## Session start/pause/time-scale are host inputs; no wall-clock reads.

const SECONDS_PER_HOUR: float = 150.0
const CYCLE_HOURS: float = 12.0
var seconds: float = 0.0
var paused: bool = false
var time_scale: float = 1.0


static func f32(value: float) -> float:
	return PackedFloat32Array([value])[0]


func advance(delta: float) -> float:
	assert(is_finite(delta) and delta >= 0.0 and is_finite(time_scale) and time_scale >= 0.0)
	var game_delta: float = 0.0 if paused else delta * time_scale
	seconds += game_delta
	return game_delta


static func hours(game_seconds: float) -> float:
	return f32(f32(game_seconds) / SECONDS_PER_HOUR)


static func quantize_shift(value: float) -> float:
	# Native floor(2*x + 0.05)*0.5, not rounding to the nearest half hour.
	return f32(floorf(2.0 * f32(value) + 0.05) * 0.5)


static func phase(hour: float) -> float:
	return f32(f32(fmod(f32(hour), CYCLE_HOURS)) / CYCLE_HOURS)


static func working(game_seconds: float, start: float, duration: float) -> bool:
	var now: float = phase(hours(game_seconds))
	var begin: float = phase(quantize_shift(start))
	var length: float = phase(quantize_shift(duration))
	if length <= 0.0:
		return false
	var end: float = f32(begin + length)
	if end > 1.0:
		return now >= begin or end > f32(now + 1.0)
	return now >= begin and end > now


static func remaining_spare(game_seconds: float, start: float, is_working: bool) -> float:
	if is_working:
		return 0.0
	var now: float = phase(hours(game_seconds))
	var begin: float = phase(quantize_shift(start))
	if begin < now:
		begin = f32(begin + 1.0)
	return f32(f32(begin - now) * CYCLE_HOURS)
