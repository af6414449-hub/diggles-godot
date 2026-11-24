extends RefCounted
## Behaviour of the Raupe class, ported from the original Tcl.
##
## The Raupe is a farmable food creature, not a hostile monster: it is bred by
## the Farm class and it eats the plants of the dig site when it is loose.
##
## Sources (original install, data/Scripts/classes/characters/raupe.tcl):
##   :3         def_class Raupe food material 0 {reproduces lives moves}
##   :6-20     animation aliases: standard (still) and kriechen (crawl)
##   :27-65    obj_init: variant, weight, hitpoints, farm test
##   :67-85    crawl_free
##   :87-115   crawl_farmed
##   :117-146  find_plant
##   :148-164  move and wait
##   :166-178  evt_timer0: the one second farm classification
##   :184-205  methods: die, get_type, set_type
##   :207-216  state free
##   :218-236  state farmed
##   :238-251  state contained
##   :253-319  state plant_attack
##
## The scene dependent parts (object queries, get_place, the move action and
## the particles) stay in the host: native_raupe_actor.gd reaches them through
## an adapter, this module only holds the rules.

# --- variant and class data (raupe.tcl:31-58) --------------------------------
const VARIANT_MIN: int = 1
const VARIANT_MAX: int = 13

## FACT (raupe.tcl:48-52): the original sets attacktyp 1 when the type IS one
## of 02, 06, 07 and 08:
##
##   if {[land $rtyp {02 06 07 08}]==""} { set attacktyp 0 } else { set attacktyp 1 }
##
## `land` is the list intersection of the engine ("list and", the same family as
## `lnand` and `lor`): it answers non-empty when the element IS part of the
## list and empty when it is not. That is proven by the other calls of the
## game: std_ai.tcl:1430 tests `land $item $stealboxlist` for "the item is a
## steal box", std_ai.tcl:1460 takes a gnome into the idle list when
## `land $gnome $UnavailableGnomesList` is empty, and z_spare_talk.tcl:174
## logs an error when `land $starter $talk_partner` is not empty, that is when
## the partner is already in the list.
##
## So the four types 02, 06, 07 and 08 are the plant eaters, the other nine
## types of the thirteen never search for a plant. find_plant returns at once
## for attacktyp 0 (raupe.tcl:119), only the four types reach it.
const PREDATORY_VARIANTS: Array[int] = [2, 6, 7, 8]

const ATTACK_COUNTER_LIMIT: int = 10
const HITPOINTS: float = 0.02
const WEIGHT: float = 0.01
const DEATH_THRESHOLD: float = 0.01

# --- geometry (raupe.tcl:64, :91) ---------------------------------------------
## The obj_query bounding boxes are half extents in x, y and z.
const FARM_BOX: Vector3 = Vector3(2.0, 0.5, 3.0)
const GNOME_BOX: Vector3 = Vector3(3.0, 0.5, 5.0)

# --- free roaming (raupe.tcl:67-85) ------------------------------------------
const MOVE_SPEED: float = 0.03
const YAW_OFFSET: float = 1.57
const TURN_JITTER: float = 1.5
const REVERSE_CHANCE: float = 0.2
const REVERSE_ANGLE: float = 3.14
const FREE_DISTANCE_MIN: float = 2.0
const FREE_DISTANCE_MAX: float = 4.0
const FREE_CIRCLE: float = 3.0
const FREE_RANDOM: float = 2.0
const FOW_MIN: float = 10.0
const WAIT_NO_PLACE: float = 3.0

# --- farm pen (raupe.tcl:87-115) ----------------------------------------------
const FARM_RECT_X_MIN: float = -2.0
const FARM_RECT_X_MAX: float = 1.5
const FARM_RECT_Z_MIN: float = -3.0
const FARM_RECT_Z_MAX: float = 3.0
const FARM_MINDIST: float = 0.6
const FARM_RANDOM: float = 2.0
const FARMED_WAIT_CHANCE: float = 0.05
const WAIT_FARMED: float = 1.0

# --- plant attack (raupe.tcl:117-146, :253-319) -------------------------------
const PLANT_RANGE: float = 8.0
const APPROACH_RANGE: float = 5.0
const APPROACH_MIN_DISTANCE: float = 2.0
const ATTACK_DISTANCE: float = 0.55
const ATTACK_DISTANCE_TOLERANCE: float = 0.1
const ATTACK_FRAMES: Array[int] = [5, 9]
const WINDUP_SHORT: float = 0.5
const WINDUP_LONG: float = 0.9
const PLANT_DAMAGE: float = 0.03
const SELF_DAMAGE: float = 0.05
const PARTICLE_SOURCE: int = 15
const PARTICLE_SCALE: float = 15.0
## The original calls create_particlesource with the five arguments
## 15, position, direction, 16, 1 (raupe.tcl:299). The engine meaning of the
## last two is not documented in the Tcl sources, so they are forwarded as they
## are.
const PARTICLE_AMOUNT: int = 16
const PARTICLE_FLAG: int = 1

# --- waits and states (raupe.tcl:79, :110, :230, :240) -----------------------
const WAIT_CONTAINED: float = 4.0
const STATE_FREE: String = "free"
const STATE_FARMED: String = "farmed"
const STATE_CONTAINED: String = "contained"
const STATE_PLANT_ATTACK: String = "plant_attack"
const ANIM_WAIT: String = "wait"
const ANIM_CRAWL: String = "crawl"


## The two digit type tag of obj_init (raupe.tcl:31-32).
static func variant_tag(draw: int) -> String:
	return "%02d" % draw


## The attacktyp of obj_init (raupe.tcl:48-52).
##
## The attack type is 1 for the four types 02, 06, 07 and 08 and 0 for the
## other nine types.
static func attack_type(variant: int) -> int:
	return 1 if PREDATORY_VARIANTS.has(variant) else 0


## Whether the type may search for a plant (raupe.tcl:119).
static func is_predatory(variant: int) -> bool:
	return attack_type(variant) == 1


## get_vectorxz: a vector in the xz plane (raupe.tcl:70, :76, :282).
static func vector_xz(angle: float, length: float) -> Vector3:
	return Vector3(sin(angle), 0.0, cos(angle)) * length


## get_anglexz: the angle from one point to another in the xz plane
## (raupe.tcl:81, :112, :277).
static func angle_xz(from: Vector3, to: Vector3) -> float:
	return atan2(to.x - from.x, to.z - from.z)


## The model yaw that faces a target (raupe.tcl:81, :112, :315).
##
## The original models face along their local x axis, so the world angle is
## shifted by a quarter turn.
static func yaw_towards(from: Vector3, to: Vector3) -> float:
	return angle_xz(from, to) - YAW_OFFSET


## The model yaw that faces away from a target (raupe.tcl:285).
static func yaw_away(from: Vector3, to: Vector3) -> float:
	return angle_xz(from, to) + YAW_OFFSET


## The turn of crawl_free (raupe.tcl:70-71).
static func free_turn(yaw: float, jitter: float) -> float:
	return yaw + YAW_OFFSET + jitter


## The twenty percent reversal of crawl_free (raupe.tcl:73-75).
static func free_reverse(angle: float, roll: float) -> float:
	if roll < REVERSE_CHANCE:
		return angle + REVERSE_ANGLE
	return angle


## The roaming candidate of crawl_free (raupe.tcl:76).
static func free_candidate(position: Vector3, angle: float, distance: float) -> Vector3:
	return position + vector_xz(angle, distance)


## The get_place request of crawl_free (raupe.tcl:77).
static func free_place_request(position: Vector3, candidate: Vector3) -> Dictionary:
	return {
		"center": candidate,
		"circle": FREE_CIRCLE,
		"nearpos": position,
		"random": FREE_RANDOM,
	}


## The farm rectangle of crawl_farmed (raupe.tcl:98-102).
##
## The original builds the rectangle from the difference between the farm and
## the centre and asks for it relative to the centre, so the rectangle always
## covers the farm area x -2..1.5 and z -3..3 in world coordinates, even when
## the centre is a dwarf next to the farm.
static func farm_rectangle(farm_pos: Vector3, centre: Vector3) -> Array[float]:
	var difference := farm_pos - centre
	var x_min: float = difference.x + FARM_RECT_X_MIN
	var z_min: float = difference.z + FARM_RECT_Z_MIN
	var x_max: float = x_min + (FARM_RECT_X_MAX - FARM_RECT_X_MIN)
	var z_max: float = z_min + (FARM_RECT_Z_MAX - FARM_RECT_Z_MIN)
	var rectangle: Array[float] = [x_min, z_min, x_max, z_max]
	return rectangle


## The get_place request of crawl_farmed (raupe.tcl:104-108).
static func farm_place_request(farm_pos: Vector3, centre: Vector3, has_gnome: bool, own_position: Vector3) -> Dictionary:
	var request: Dictionary = {
		"center": centre,
		"rect": farm_rectangle(farm_pos, centre),
		"mindist": FARM_MINDIST,
		"random": FARM_RANDOM,
	}
	if has_gnome:
		request["nearpos"] = own_position
	return request


## The plant search counts to eleven (raupe.tcl:120-124).
static func attack_counter_step(counter: int) -> Dictionary:
	if counter < ATTACK_COUNTER_LIMIT:
		return {"counter": counter + 1, "search": false}
	return {"counter": 0, "search": true}


## The windup frame of the attack (raupe.tcl:281).
static func attack_frame(draw: int) -> int:
	return ATTACK_FRAMES[draw % ATTACK_FRAMES.size()]


## The windup length of the attack: wait 0.5 or wait 0.9 (raupe.tcl:288).
static func windup_seconds(frame: int) -> float:
	return WINDUP_SHORT if frame == 5 else WINDUP_LONG


## The attack is over when the distance to the plant is 0.55 +- 0.1
## (raupe.tcl:308).
static func approach_finished(distance: float) -> bool:
	return absf(distance - ATTACK_DISTANCE) < ATTACK_DISTANCE_TOLERANCE


## The approach point: 0.55 away from the plant (raupe.tcl:313).
static func approach_point(plant_position: Vector3, angle: float) -> Vector3:
	return plant_position + vector_xz(angle, ATTACK_DISTANCE)


## The particle source of the attack (raupe.tcl:282-284, :299).
static func attack_particle(plant_position: Vector3, angle: float) -> Dictionary:
	var direction := vector_xz(angle, 0.02)
	direction.y = -0.02
	return {
		"source": PARTICLE_SOURCE,
		"position": plant_position + direction * PARTICLE_SCALE,
		"direction": direction,
		"amount": PARTICLE_AMOUNT,
		"flag": PARTICLE_FLAG,
	}


## Five percent of the farmed ticks wait instead of roaming (raupe.tcl:229).
static func farmed_wait(roll: float) -> bool:
	return roll < FARMED_WAIT_CHANCE


## get_place returns a list whose first entry is a status code. The original
## compares that code with 0, 1 or -1 depending on the caller (raupe.tcl:78,
## :109, :132).
static func place_failed(code: int, minimum: int) -> bool:
	return code < minimum


## The obj_query of test_farmed (raupe.tcl:64).
static func farm_query(own_position: Vector3) -> Dictionary:
	return {
		"center": own_position,
		"class": "Farm",
		"box": FARM_BOX,
		"limit": 1,
	}


## The obj_query of crawl_farmed (raupe.tcl:91).
static func dwarf_query(farm_position: Vector3) -> Dictionary:
	return {
		"center": farm_position,
		"class": "Zwerg",
		"box": GNOME_BOX,
		"limit": 1,
	}


## The obj_query of find_plant (raupe.tcl:126).
static func plant_query(own_position: Vector3) -> Dictionary:
	return {
		"center": own_position,
		"class": "Fresspflanze",
		"range": PLANT_RANGE,
		"limit": 1,
	}


## The get_place request of the plant approach (raupe.tcl:131).
static func plant_place_request(plant_position: Vector3, own_position: Vector3) -> Dictionary:
	return {
		"center": plant_position,
		"circle": APPROACH_RANGE,
		"mindist": APPROACH_MIN_DISTANCE,
		"nearpos": own_position,
	}


## The move action of the original (raupe.tcl:151-156).
static func move_request(position: Vector3) -> Dictionary:
	return {"target": position, "speed": MOVE_SPEED}


## The animation aliases of the class (raupe.tcl:8-20): standstill and
## hangstill use standard, every crawl and turn uses kriechen.
static func anim_clip(variant: int, mode: String, frame: int = 0) -> Dictionary:
	var tag := variant_tag(variant)
	if mode == ANIM_CRAWL:
		return {"mode": ANIM_CRAWL, "clip": "raupe%s.kriechen" % tag, "frame": frame}
	return {"mode": ANIM_WAIT, "clip": "raupe%s.standard" % tag, "frame": frame}
