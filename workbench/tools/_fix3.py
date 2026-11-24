REPORT = r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\docs\reverse-engineering\agent-result-walkmap-performance-2026-11-19.md"
with open(REPORT, "r", encoding="utf-8", newline="") as f:
    text = f.read()
old = "* `godot/scripts/native_walkmap.gd` \u2014 \u043a\u044d\u0448, \u0441\u0443\u0436\u0435\u043d\u0438\u0435, \u0434\u0438\u0430\u0433\u043d\u043e\u0441\u0442\u0438\u043a\u0430 (+307 / \u22124)"
new = "* `godot/scripts/native_walkmap.gd` \u2014 \u043a\u044d\u0448, \u0441\u0443\u0436\u0435\u043d\u0438\u0435, \u0434\u0438\u0430\u0433\u043d\u043e\u0441\u0442\u0438\u043a\u0430 (+313 / \u22124)"
assert text.count(old) == 1, text.count(old)
text = text.replace(old, new)
with open(REPORT, "w", encoding="utf-8", newline="") as f:
    f.write(text)
print("OK")