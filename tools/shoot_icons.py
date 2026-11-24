# -*- coding: utf-8 -*-
"""Рендерит все иконки ленты крупно в отдельный PNG (для визуальной проверки)."""
import io, os, re, subprocess

CHROME = r"C:\Program Files\Google\Chrome\Application\chrome.exe"
TPL = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\tools\dwarf_life_template.html"
OUT = r"C:\Users\frant\Downloads\_icons_big.png"
TMP = r"C:\Users\frant\Downloads\_icons_big.html"

src = io.open(TPL, encoding="utf-8").read()
icons = re.findall(r'icon:(\[[^\]]*\]|FIG_[A-Z]+)', src)
pblock = re.search(r"const P = (\{.*?\n\};)", src, re.S).group(1)
fig = re.search(r"const FIG_STAND = \[(.*?)\];", src, re.S).group(1)
figw = re.search(r"const FIG_WALK = \[(.*?)\];", src, re.S).group(1)

html = """<!DOCTYPE html><html><head><meta charset="utf-8"><style>
body { background:#0d0b09; margin:0; padding:14px; display:flex; flex-wrap:wrap; gap:10px; }
.c { width:104px; height:104px; background:#2c2318; border:1px solid #56462f; border-radius:10px;
     display:grid; place-items:center; color:#cdbd9d; }
.c svg { width:72%; height:72%; fill:none; stroke:currentColor; stroke-width:1.8;
         stroke-linecap:round; stroke-linejoin:round; }
</style></head><body>
<script>
const P = __PBLOCK__;
const FIG_STAND = [__FIG__];
const FIG_WALK = [__FIGW__];
function svg(parts) {
  const flat = [];
  for (const part of parts) {
    if (Array.isArray(part)) { for (const sub of part) flat.push(sub); }
    else flat.push(part);
  }
  return '<svg viewBox="0 0 24 24" aria-hidden="true">' + flat.join("") + '</svg>';
}
const items = __ITEMS__;
document.body.insertAdjacentHTML("beforeend",
  items.map(function (e) { return '<div class="c">' + svg(e) + '</div>'; }).join(""));
</script>
</body></html>"""
html = (html.replace("__PBLOCK__", pblock).replace("__FIG__", fig)
            .replace("__FIGW__", figw).replace("__ITEMS__", "[" + ",".join(icons) + "]"))

io.open(TMP, "w", encoding="utf-8").write(html)
subprocess.run([CHROME, "--headless=new", "--no-sandbox", "--disable-extensions",
                "--enable-unsafe-swiftshader", "--use-angle=swiftshader",
                "--virtual-time-budget=2000", "--window-size=1180,400",
                "--screenshot=" + OUT, "file:///" + TMP.replace("\\", "/")],
               capture_output=True, timeout=180)
print("written", OUT, "иконок:", len(icons))
