extends RefCounted
## Guest seat bookkeeping for the sparetime places.
##
## Source of truth (installed game, read only):
##   data/Scripts/classes/zwerg/z_spare_procs.tcl:851-880  sparetime_find_place
##   data/Scripts/classes/zwerg/z_spare_procs.tcl:882-917  sparetime_check_in
##   data/Scripts/classes/zwerg/z_spare_fun.tcl:430-511    sparetime_place_find
##   data/Scripts/classes/zwerg/z_spare_fun.tcl:604-613    sparetime_place_finished
##
## The original keeps the seat table inside the native `prod_guest` objects.
## This registry owns an equivalent table and reproduces the command order of
## `sparetime_check_in` exactly, because res://models/native_dwarf_sparetime.json
## records that order and the self test compares it call by call.
##
## Adapter boundary: the host supplies the object class, the random seat, the
## place query and the seat link through callables. The registry itself never
## touches the scene graph.

const Sparetime: Script = preload("res://scripts/native_dwarf_sparetime.gd")

## z_spare_procs.tcl:857 - the eat search radius is much tighter than the rest.
const EAT_RANGE: float = 15.0
## z_spare_procs.tcl:857 - every other occupation searches this far.
const DEFAULT_RANGE: float = 60.0
## z_spare_procs.tcl:856 - a place further away than this is not reused.
const MAX_REUSE_DISTANCE: float = 60.0
## z_spare_fun.tcl:610 - the recent fun list keeps ten entries.
const RECENT_FUN_LIMIT: int = 10

## z_spare_procs.tcl:883 - sparetime_current_place_ref
var current_place_ref: int = 0
## z_spare_procs.tcl:883 - sparetime_current_place
var current_place: String = ""
## z_spare_procs.tcl:883 - sparetime_seat
var seat: int = 0
## z_spare_procs.tcl:883 - sparetime_reservation
var reservation: int = 0

## place id -> {"class": String, "seats": Dictionary, "order": Array}
var _places: Dictionary = {}
## z_spare_fun.tcl:431 - sparetime_recent_places
var _recent_places: Array[String] = []
## z_spare_fun.tcl:606 - sparetime_recent_fun
var _recent_fun: Array[String] = []
## z_spare_fun.tcl:606 - sparetime_avoid_place
var _avoid_place_ref: int = 0
var _avoid_place_time: float = 0.0

## (place_id: int) -> String
var object_class: Callable = Callable()
## (place_id: int) -> int, the host answer for `get_random_seat`
var random_seat: Callable = Callable()
## (occupation: String, range: float) -> Array of place ids
var place_query: Callable = Callable()
## (place_id: int, seat: int) -> String, the host answer for `prod_guest getlink`
var seat_link: Callable = Callable()
## (place_id: int) -> bool, the host answer for `get_boxed`
var is_boxed: Callable = Callable()
## (place_id: int) -> float, the host answer for the distance to the dwarf
var distance_to: Callable = Callable()
## (place_id: int) -> int, the host answer for `get_prod_slot_cnt`
var slot_count: Callable = Callable()


# --------------------------------------------------------------------------- #
# place table
# --------------------------------------------------------------------------- #
func register_place(place_id: int, place_class: String, seat_count: int) -> void:
	_places[place_id] = {"class": place_class, "seats": {}, "order": []}
	for index: int in range(maxi(0, seat_count)):
		_places[place_id]["seats"][index] = 0


func remove_place(place_id: int) -> void:
	_places.erase(place_id)


func has_place(place_id: int) -> bool:
	return _places.has(place_id)


func place_class(place_id: int) -> String:
	if not _places.has(place_id):
		return ""
	return str(_places[place_id]["class"])


func seat_count(place_id: int) -> int:
	if not _places.has(place_id):
		return 0
	return (_places[place_id]["seats"] as Dictionary).size()


func occupied_seats(place_id: int) -> int:
	if not _places.has(place_id):
		return 0
	var count: int = 0
	for guest: Variant in (_places[place_id]["seats"] as Dictionary).values():
		if int(guest) != 0:
			count += 1
	return count


## z_spare_procs.tcl:903 - `prod_guest guestfree` returns the first free seat.
func free_seat(place_id: int) -> int:
	if not _places.has(place_id):
		return -1
	var seats: Dictionary = _places[place_id]["seats"]
	var index: int = -1
	for key: Variant in seats.keys():
		var seat_index: int = int(key)
		if int(seats[key]) == 0:
			if index == -1 or seat_index < index:
				index = seat_index
	return index


## z_spare_procs.tcl:908 - `prod_guest guestset`.
func claim(place_id: int, seat_index: int, guest_ref: int) -> bool:
	if not _places.has(place_id):
		return false
	var seats: Dictionary = _places[place_id]["seats"]
	if not seats.has(seat_index):
		return false
	seats[seat_index] = guest_ref
	return true


## z_spare_procs.tcl:887 - `prod_guest guestremove` returns the released seat.
func release(place_id: int, guest_ref: int) -> int:
	if not _places.has(place_id):
		return -1
	var seats: Dictionary = _places[place_id]["seats"]
	for key: Variant in seats.keys():
		if int(seats[key]) == guest_ref:
			var seat_index: int = int(key)
			seats[key] = 0
			return seat_index
	return -1


func guest_at(place_id: int, seat_index: int) -> int:
	if not _places.has(place_id):
		return 0
	var seats: Dictionary = _places[place_id]["seats"]
	if not seats.has(seat_index):
		return 0
	return int(seats[seat_index])


# --------------------------------------------------------------------------- #
# sparetime_check_in
# --------------------------------------------------------------------------- #
## z_spare_procs.tcl:882-917 - the whole procedure, command order preserved.
func check_in(place_id: int, method: int = 0, self_ref: int = 7) -> Dictionary:
	var calls: Array = []
	reservation = 0
	if current_place_ref != 0:
		if has_place(current_place_ref):
			calls.append(["prod_guest", "guestremove", str(current_place_ref), str(self_ref)])
			release(current_place_ref, self_ref)
			calls.append(["prod_guest", "resetorder", str(current_place_ref), str(seat)])
		current_place_ref = 0
		current_place = ""
	if place_id != 0:
		var chosen: int = -1
		if method != 0:
			if method == -1:
				calls.append(["call_method", "get_random_seat"])
				chosen = _pick_random_seat(place_id)
			else:
				chosen = method
		else:
			calls.append(["prod_guest", "guestfree", str(place_id), "None"])
			chosen = free_seat(place_id)
		if chosen != -1:
			seat = chosen
			calls.append(["prod_guest", "guestset", str(place_id), str(seat)])
			claim(place_id, seat, self_ref)
			calls.append(["prod_guest", "resetorder", str(place_id), str(seat)])
			current_place_ref = place_id
			current_place = _class_of(place_id)
			return _check_in_result(1, calls)
	return _check_in_result(0, calls)


func _check_in_result(result: int, calls: Array) -> Dictionary:
	return {"result": result, "calls": calls, "place_ref": current_place_ref,
		"place_class": current_place, "seat": seat}


func _class_of(place_id: int) -> String:
	if object_class.is_valid():
		return str(object_class.call(place_id))
	return place_class(place_id)


func _pick_random_seat(place_id: int) -> int:
	if random_seat.is_valid():
		return int(random_seat.call(place_id))
	return free_seat(place_id)


# --------------------------------------------------------------------------- #
# sparetime_find_place
# --------------------------------------------------------------------------- #
## z_spare_procs.tcl:851-880 - the place lookup for eat/fun/slp/bth.
func find_place(occupation: String, place_classes: Array, self_ref: int = 7) -> Dictionary:
	var calls: Array = []
	var reusable: bool = place_classes.has(current_place) and has_place(current_place_ref) \
		and not _boxed(current_place_ref) and _distance(current_place_ref) <= MAX_REUSE_DISTANCE
	if not reusable:
		var search_range: float = EAT_RANGE if occupation == "eat" else DEFAULT_RANGE
		for place_id: int in _query(occupation, search_range):
			var usable: bool = place_id != 0
			if usable and occupation == "fun":
				usable = _slots(place_id) != 0
			if not usable:
				continue
			var check: Dictionary = check_in(place_id, 0, self_ref)
			calls.append_array(check["calls"])
			if int(check["result"]) != 0:
				if occupation == "eat":
					calls.append(["tasklist_add", _walk_dummy()])
				return {"result": 1, "calls": calls, "place_ref": current_place_ref, "seat": seat}
		return {"result": 0, "calls": calls, "place_ref": current_place_ref, "seat": seat}
	if occupation == "eat":
		calls.append(["tasklist_add", _walk_dummy()])
		return {"result": 1, "calls": calls, "place_ref": current_place_ref, "seat": seat}
	return {"result": 0, "calls": calls, "place_ref": current_place_ref, "seat": seat}


func _query(occupation: String, search_range: float) -> Array:
	if not place_query.is_valid():
		return []
	var raw: Variant = place_query.call(occupation, search_range)
	var result: Array = []
	if raw is Array:
		for item: Variant in raw:
			result.append(int(item))
	return result


func _walk_dummy() -> String:
	var link: String = ""
	if seat_link.is_valid():
		link = str(seat_link.call(current_place_ref, seat))
	return "walk_dummy %d %s" % [current_place_ref, link]


func _boxed(place_id: int) -> bool:
	if is_boxed.is_valid():
		return bool(is_boxed.call(place_id))
	return false


func _distance(place_id: int) -> float:
	if distance_to.is_valid():
		return float(distance_to.call(place_id))
	return 0.0


func _slots(place_id: int) -> int:
	if slot_count.is_valid():
		return int(slot_count.call(place_id))
	return 1


# --------------------------------------------------------------------------- #
# recent places
# --------------------------------------------------------------------------- #
## z_spare_fun.tcl:604-613 - a finished visit is remembered and the place is
## avoided for fifty seconds.
func place_finished(place_name: String, place_id: int, now: float) -> Dictionary:
	var calls: Array = []
	if now - _avoid_place_time > 50.0:
		calls.append(["sparetime_fun_entry", "place"])
		_recent_fun.append(place_name)
		if _recent_fun.size() > RECENT_FUN_LIMIT:
			_recent_fun.remove_at(0)
		_avoid_place_ref = place_id
		_avoid_place_time = now
	return {"calls": calls, "recent_fun": _recent_fun.duplicate(),
		"avoid_place_ref": _avoid_place_ref, "avoid_place_time": _avoid_place_time}


## z_spare_fun.tcl:480 - the number of recent visits of that place class.
func recent_count(place_name: String) -> int:
	return _recent_places.count(place_name)


## z_spare_fun.tcl:480 - records a visit of a place class.
func note_visit(place_name: String) -> void:
	_recent_places.append(place_name)


func recent_places() -> Array[String]:
	return _recent_places.duplicate()


func recent_fun() -> Array[String]:
	return _recent_fun.duplicate()


func avoid_place() -> Dictionary:
	return {"ref": _avoid_place_ref, "time": _avoid_place_time}


## z_spare_fun.tcl:480 - the dissatisfaction penalty for a recently used place.
func place_penalty(desire: float, place_name: String) -> float:
	return Sparetime.recent_place_penalty(desire, recent_count(place_name))


## z_spare_fun.tcl:487 - the favourite places double the desire.
func desire_with_favourites(desire: float, place_name: String, favourites: Array) -> float:
	var value: float = place_penalty(desire, place_name)
	if favourites.has(place_name):
		value *= 2.0
	return value
