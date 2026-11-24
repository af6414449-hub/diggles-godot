extends RefCounted
## One actor's floor-navigation adapter, not the native action-walk planner.

var path: Array[Vector3] = []
var path_index: int = 1
var target: Vector3 = Vector3.ZERO
var state: StringName = &"idle"
var elapsed: float = 0.0
var frame: int = -1
var fast: bool = false
var pending_heading: float = 0.0
var barrel: Node3D = null
