import difflib, os, sys
main = r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot\scripts"
wb   = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\workbench"
def rd(p):
    with open(p, "r", encoding="utf-8") as f:
        return f.read().splitlines(keepends=True)
for name in ["native_walkmap.gd", "native_walk_flags.gd", "native_terrain_state.gd"]:
    a = rd(os.path.join(main, name))
    b = rd(os.path.join(wb, "baseline", "scripts", name))
    d = list(difflib.unified_diff(a, b, fromfile="main/"+name, tofile="wb-baseline/"+name, n=0))
    print("=== %s : main vs wb-baseline : %d diff lines" % (name, len(d)))
    for line in d[:40]:
        print("   " + line.rstrip("\n"))
