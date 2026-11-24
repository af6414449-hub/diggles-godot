extends Node

const Sequencer = preload("res://scripts/native_story_sequencer.gd")

func _ready() -> void:
	var sequencer: RefCounted = Sequencer.new()
	var source: String = "show_loading yes\nmap create 300 300\nset_view 62.2 22.1 1.5 -0.3 0.0\nshow_loading no"
	var trace: Array[Dictionary] = sequencer.execute(source)
	var dispatched: int = sequencer.dispatch_trace(_receive_event)
	print("STORY_SCENE_READY commands=%d dispatched=%d map=%s camera=%s" % [trace.size(), dispatched, sequencer.map_size, sequencer.camera])
	get_tree().quit(0)

func _receive_event(_event: Dictionary) -> void:
	pass
