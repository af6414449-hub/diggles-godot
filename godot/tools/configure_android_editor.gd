@tool
extends SceneTree


func _init() -> void:
	set_auto_accept_quit(false)


func _process(_delta: float) -> bool:
	var settings: EditorSettings = EditorInterface.get_editor_settings()
	if settings == null:
		return false
	settings.set_setting("export/android/android_sdk_path", "C:/Users/frant/AppData/Local/Android/Sdk")
	settings.set_setting("export/android/java_sdk_path", "C:/Program Files/Microsoft/jdk-21.0.13.21-hotspot")
	settings.set_setting("export/android/debug_keystore", "C:/Users/frant/AppData/Roaming/Godot/keystores/debug.keystore")
	settings.set_setting("export/android/debug_keystore_user", "androiddebugkey")
	settings.set_setting("export/android/debug_keystore_pass", "android")
	print("ANDROID_EDITOR_SETTINGS_READY")
	quit()
	return true
