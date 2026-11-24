extends SceneTree

const Sequencer = preload("res://scripts/native_story_sequencer.gd")

func _init() -> void:
	var source: String = """
show_loading yes
obj_clear
map create 300 300
sel /obj
set_view 62.2 22.1 1.5 -0.3 0.0
call templates/urw_unq_vodo_001_a.tcl
MapTemplateSet 12 12
call templates/urw_gng_004_a.tcl
MapTemplateSet 44 20
call templates/zwerg_exit_left.tcl
MapTemplateSet 60 20
show_loading no
sm_def_temp_group temp_name { 12 12 urw_unq_vodo_001_a.tcl 44 20 urw_gng_004_a.tcl 60 20 zwerg_exit_left.tcl }
sq_actor find 100 Zwerg
sq_actor express 0 0 Happy
sq_text file Seq_FirstContact
sq_audio open FirstContact
sq_camera move 0 1.0
sq_screenvibe ring
do_wait time 0.5
do_text 100 0
call_method $fr fog_remove 0 -120 -15
timer_event [obj_query this -class Trigger_Tutorial] evt_timer0 -repeat 0 -userid 0 -attime 13
keybind set F6 s2010
"""
	var sequencer: RefCounted = Sequencer.new()
	var result: Array[Dictionary] = sequencer.execute(source)
	_assert(result.size() == 24, "expected 24 executable commands")
	_assert(sequencer.map_size == Vector2i(300, 300), "map size")
	_assert(sequencer.camera.get("zoom", 0.0) == 1.5, "camera zoom")
	_assert(sequencer.loading == false, "loading flag")
	_assert(sequencer.actors.size() == 1, "actor find")
	_assert(sequencer.skipped_commands.is_empty(), "no unknown commands")
	var received: Array[Dictionary] = []
	var dispatched: int = sequencer.dispatch_trace(func(event: Dictionary) -> void: received.append(event))
	_assert(dispatched == result.size(), "adapter dispatch count")
	_assert(received[0].get("command", "") == "show_loading", "adapter first event")
	print("STORY_SEQUENCER_SELF_TEST_OK commands=%d dispatched=%d actors=%d map=%s camera=%s" % [result.size(), dispatched, sequencer.actors.size(), sequencer.map_size, sequencer.camera])
	quit(0)

func _assert(condition: bool, message: String) -> void:
	if not condition:
		push_error("STORY_SEQUENCER_SELF_TEST_FAIL: " + message)
		quit(1)
