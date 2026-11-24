# -*- coding: utf-8 -*-
"""Рендерит набор иконок ленты крупно в один PNG (визуальная проверка)."""
import io
import os
import re
import subprocess
import sys
import uuid

CHROME = r"C:\Program Files\Google\Chrome\Application\chrome.exe"
TPL = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\tools\dwarf_life_template.html"
OUT = r"C:\Users\frant\Downloads\_icons_big.png"
TMP = r"C:\Users\frant\Downloads\_icons_big.html"
PROFILE = r"C:\Users\frant\Downloads\_chrome_profile_icons"

src = io.open(TPL, encoding="utf-8").read()
pblock = re.search(r"const P = (\{.*?\n\};)", src, re.S).group(1)

# иконки новых кнопок + по одной старой для сравнения
names = ["turnL90", "turnL180", "turnR90", "turnR180",
         "pick", "pickUp", "pickFlat",
         "fighter", "fistHit", "fistUp", "fistDown", "fistSide",
         "bulb", "bulbLoop", "bulbUp", "bulbDbl", "bulbStar", "bulbLit",
         "crank", "boot"]
items = ",".join("P.%s" % n for n in names)

html = """<!DOCTYPE html><html><head><meta charset="utf-8"><style>
body { background:#0d0b09; margin:0; padding:14px; display:flex; flex-wrap:wrap; gap:12px; }
.c { width:104px; height:104px; background:#2c2318; border:1px solid #56462f; border-radius:10px;
     display:grid; place-items:center; color:#cdbd9d; }
.c svg { width:72%; height:72%; fill:none; stroke:currentColor; stroke-width:1.8;
         stroke-linecap:round; stroke-linejoin:round; }
</style></head><body>
<script>
const P = __PBLOCK__;
function svg(parts) {
  const flat = [];
  for (const part of parts) {
    if (Array.isArray(part)) { for (const sub of part) flat.push(sub); }
    else flat.push(part);
  }
  return '<svg viewBox="0 0 24 24" aria-hidden="true">' + flat.join("") + '</svg>';
}
const items = [__ITEMS__];
document.body.insertAdjacentHTML("beforeend",
  items.map(function (e) { return '<div class="c">' + svg(e) + '</div>'; }).join(""));
</script>
</body></html>"""
html = html.replace("__PBLOCK__", pblock).replace("__ITEMS__", items)

io.open(TMP, "w", encoding="utf-8").write(html)
cmd = [CHROME, "--headless=new", "--no-sandbox", "--disable-extensions", "--no-first-run",
       "--user-data-dir=" + PROFILE + "_" + uuid.uuid4().hex[:8],
       "--enable-unsafe-swiftshader", "--use-angle=swiftshader",
       "--virtual-time-budget=2000", "--window-size=780,420",
       "--screenshot=" + OUT, "file:///" + TMP.replace("\\", "/")]
proc = subprocess.run(cmd, capture_output=True, timeout=180)
print("written", OUT, "иконок:", len(names), "rc=", proc.returncode)
