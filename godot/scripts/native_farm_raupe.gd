extends RefCounted
## The worm side of the Farm class, ported from the original Tcl.
##
## The farm itself lives in the host scene. This module holds the rules of the
## Raupe production branch and the worm bookkeeping of one farm: the counter,
## the fodder, the lock on the original worm and the shared creation cooldown.
##
## Sources (original install, data/Scripts/classes/work/farm.tcl):
##   :72-79    obj_init: wormfodder, farmcounter and the class branch
##   :131-140  the production reset and the initial value of lastcreation
##   :243-270  the Raupe production branch
##   :251      the threshold 60 - material*12 + rand()*5
##   :254-255  the fodder and the counter reset
##   :334-343  remove_from_inv_raupe
##   :354-357  free_original_worm
##   :470-481  actualize_worm
##   :498-513  recreate_raupe

# --- production (farm.tcl:243-270) --------------------------------------------
const MAX_WORMS: int = 6
const THRESHOLD_BASE: float = 60.0
const MATERIAL_FACTOR: float = 12.0
const THRESHOLD_JITTER: float = 5.0
const WORM_FODDER_COST: float = 30.0
const PLACE_RANDOM: int = 2

# --- creation (farm.tcl:498-513) ----------------------------------------------
const CREATION_COOLDOWN: float = 50.0
const CREATE_RECT_X: float = 1.7
const CREATE_RECT_Z: float = 2.5

# --- candidates (farm.tcl:245) ------------------------------------------------
const CANDIDATE_BOX: Vector3 = Vector3(2.0, 0.5, 3.0)

## FACT (farm.tcl:74): a fresh farm starts with a counter of fifty.
const INITIAL_FARM_COUNTER: int = 50
## FACT (farm.tcl:79): the Raupe branch starts with a hundred fodder.
const INITIAL_WORM_FODDER: float = 100.0

var farm_counter: int = INITIAL_FARM_COUNTER
var worm_fodder: float = INITIAL_WORM_FODDER
var original_worm: String = ""
## FACT (farm.tcl:140): the shared creation cooldown starts at zero, so the
## first creation of a farm has to wait for the fifty seconds of the cooldown.
var last_creation: float = 0.0


## The candidate query of the Raupe branch (farm.tcl:245).
static func candidate_request(farm_position: Vector3) -> Dictionary:
	return {
		"center": farm_position,
		"class": "Raupe",
		"box": CANDIDATE_BOX,
		"flagneg": ["contained"],
		"limit": 0,
	}


## The recreation threshold of the Raupe branch (farm.tcl:251).
static func threshold(material: int, roll: float) -> float:
	return THRESHOLD_BASE - float(material) * MATERIAL_FACTOR + roll * THRESHOLD_JITTER


## The inventory hand in (farm.tcl:334-343): the Raupe is taken out of the
## inventory and recreated with the same type.
static func inventory_removal(rtyp: int) -> Dictionary:
	return {"remove": true, "type": rtyp, "recreate": true}


## actualize_worm (farm.tcl:470-481).
##
## The worm that is already locked keeps the lock as long as it is still a
## candidate, otherwise the first free candidate is locked.
func actualize_worm(candidates: Array, locked_ref: String) -> String:
	for entry: Variant in candidates:
		var candidate: Dictionary = entry
		var reference := String(candidate.get("ref", ""))
		if reference != "" and reference == locked_ref:
			original_worm = reference
			return reference
	for entry: Variant in candidates:
		var candidate: Dictionary = entry
		if not bool(candidate.get("locked", false)):
			var reference := String(candidate.get("ref", ""))
			original_worm = reference
			return reference
	original_worm = ""
	return ""


## The production plan of the Raupe branch (farm.tcl:243-270).
##
## A farm with six Raupen does nothing, an empty farm waits for its schedule,
## and a farm that a dwarf visited counts up until it crosses the threshold.
func production_plan(count: int, counter: int, material: int, roll: float, dwarf_present: bool) -> Dictionary:
	if count >= MAX_WORMS:
		return {"recreate": false, "counter": counter, "counter_before": counter, "fodder": 0.0, "reason": "full"}
	if count == 0:
		return {"recreate": false, "counter": counter, "counter_before": counter, "fodder": 0.0, "reason": "empty"}
	if not dwarf_present:
		return {"recreate": false, "counter": counter, "counter_before": counter, "fodder": 0.0, "reason": "no_dwarf"}
	var limit := threshold(material, roll)
	if counter > limit:
		return {
			"recreate": true,
			"counter": 0,
			"counter_before": counter,
			"fodder": WORM_FODDER_COST,
			"reason": "recreate",
			"threshold": limit,
		}
	return {
		"recreate": false,
		"counter": counter + 1,
		"counter_before": counter,
		"fodder": 0.0,
		"reason": "counter",
		"threshold": limit,
	}


## Applying the result of a creation (farm.tcl:252-255).
##
## A failed creation changes nothing: the counter keeps its value and no
## fodder is spent.
func apply_creation(plan: Dictionary, created: bool) -> Dictionary:
	if not bool(plan.get("recreate", false)):
		return {"counter": farm_counter, "fodder": 0.0}
	if not created:
		return {"counter": int(plan.get("counter_before", farm_counter)), "fodder": 0.0}
	farm_counter = 0
	var cost := float(plan.get("fodder", 0.0))
	worm_fodder -= cost
	return {"counter": farm_counter, "fodder": cost}


## The creation cooldown (farm.tcl:500).
##
## The cooldown is shared with the hamster recreation of the same farm.
func can_recreate(now: float) -> bool:
	return now - last_creation >= CREATION_COOLDOWN


## Remember a successful creation (farm.tcl:505).
func register_creation(now: float) -> void:
	last_creation = now


## The get_place request of recreate_raupe (farm.tcl:502).
func recreate_request(farm_position: Vector3) -> Dictionary:
	return {
		"center": farm_position,
		"rect": [-CREATE_RECT_X, -CREATE_RECT_Z, CREATE_RECT_X, CREATE_RECT_Z],
		"random": PLACE_RANDOM,
	}


## Releasing the worm lock (farm.tcl:354-357).
func free_original_worm() -> void:
	original_worm = ""
