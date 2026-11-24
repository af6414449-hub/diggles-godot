import difflib, io
live = r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot\scripts\native_scene_profile.gd"
repro = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\repro\godot\scripts\native_scene_profile.gd"
a = open(live, encoding="utf-8").read().splitlines(keepends=True)
b = open(repro, encoding="utf-8").read().splitlines(keepends=True)
d = difflib.unified_diff(a, b, fromfile="a/godot/scripts/native_scene_profile.gd", tofile="b/godot/scripts/native_scene_profile.gd", n=4)
print("".join(d))
