import difflib
liveRoot = r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot"
reproRoot = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\repro\godot"
for rel in [r"scripts\multiplayer_test.gd", r"scripts\native_terrain_state.gd", r"scripts\native_walkmap.gd", r"scripts\native_walk_flags.gd"]:
    a = open(liveRoot + "\\" + rel, encoding="utf-8").read().splitlines(keepends=True)
    b = open(reproRoot + "\\" + rel, encoding="utf-8").read().splitlines(keepends=True)
    d = list(difflib.unified_diff(a, b, fromfile="live/" + rel, tofile="repro/" + rel, n=1))
    print("=" * 70)
    print(rel, " diff lines:", len(d))
    print("".join(d[:60]))
