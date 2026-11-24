extends SceneTree

const Aliases: Script = preload("res://scripts/native_animation_aliases.gd")
const Feedback: Script = preload("res://scripts/native_dig_feedback.gd")
var checks: int = 0
var failures: int = 0


func check(condition: bool, label: String) -> void:
	checks += 1
	if not condition:
		failures += 1
		printerr("FAIL ", label)


func _init() -> void:
	check(Aliases.alias_count() == 926 and Aliases.animset_count() == 20, "source table complete")
	check(Aliases.get_clip("walkstart") == "gehen_start", "semantic name")
	check(Aliases.get_frame_count("walkstart") == 3, "native walk frames")
	check(Aliases.get_clip("digupaccident") == "buddeln_oben_norm_unfall", "accident name")
	check(Aliases.get_frame_count("digupaccident") == 29, "native accident duration")
	check(Aliases.get_clip("bedsleepstart") == "schlafen_bett_end", "Tcl last definition wins")
	check(Aliases.get_target("bedsleeploop").is_empty(), "do not repair original duplicate implicitly")
	check(Aliases.get_face_anim("djhigh").begins_with("eyes "), "Tcl argument delimiters removed")
	check(Aliases.get_animset_role("ANIMSET_RUN", "walk_loop") == "mann.laufen_schnell_loop", "run role")
	check(Aliases.get_animset_role("ANIMSET_RUN", "climb_left") == "mann.kletter_links_schnell", "wall role")
	check(Aliases.has_target("mann.gehen_start"), "exact object target")
	check(not Aliases.has_target("hamster.gehen_start"), "reject cross-package false positive")
	check(not Aliases.has_target("gehen_start"), "reject unqualified target")
	check(not Aliases.has_target("frau.gehen_start"), "gender substitution is not implicit")
	check(Aliases.get_frame_count("unknown") == -1 and Aliases.get_clip("unknown").is_empty(), "unknown alias")
	var copy: Dictionary = Aliases.get_animset("ANIMSET_RUN")
	copy["entries"]["walk_loop"] = "invalid"
	check(Aliases.get_animset_role("ANIMSET_RUN", "walk_loop") == "mann.laufen_schnell_loop", "cache isolation")
	check(Aliases.get_animset("unknown").is_empty(), "unknown set")
	check(Aliases.get_animset_role("ANIMSET_RUN", "unknown").is_empty(), "unknown role")
	var feedback: Dictionary = Feedback.read_data()
	for alias: String in ["digup", "digfront", "digdown", "digupaccident", "digdownaccident"]:
		check(Aliases.get_frame_count(alias) == feedback["clips"][alias]["frames"].size()
			and Aliases.get_clip(alias) == feedback["aliases"][alias], "exported mining clip "+alias)
	print("NATIVE_ANIMATION_ALIASES_SELF_TEST checks=", checks, " failures=", failures)
	quit(0 if failures == 0 else 1)
