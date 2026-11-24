# -*- coding: utf-8 -*-
"""Extract the embedded PNG textures from the built page for inspection."""
import base64, io, json, os, re

HTML = r"C:\Users\frant\Downloads\dwarf_life.html"
OUT = r"C:\Users\frant\Downloads\_tex_dump"
os.makedirs(OUT, exist_ok=True)

raw = io.open(HTML, encoding="utf-8").read()
payload = json.loads(re.search(r'const PAYLOAD = (\{.*?\});\n', raw, re.S).group(1))
for t in payload["textures"]:
    data = t["png"].split(",", 1)[1]
    raw_png = base64.b64decode(data)
    path = os.path.join(OUT, t["name"].replace(".tga", ".png"))
    with open(path, "wb") as f:
        f.write(raw_png)
    print("%-28s %dx%d  %d bytes -> %s" % (t["name"], t["width"], t["height"], len(raw_png), path))
