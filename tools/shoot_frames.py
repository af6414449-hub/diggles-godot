# -*- coding: utf-8 -*-
"""Делает кадры страницы на указанных клипах/кадрах (для визуальной проверки кирки)."""
import io, os, subprocess, sys

CHROME = r"C:\Program Files\Google\Chrome\Application\chrome.exe"
SRC = r"C:\Users\frant\Downloads\dwarf_life.html"
TMP = r"C:\Users\frant\Downloads\_frame_shot.html"

shots = [
    ("buddeln_oben_normal", 0, "_pick_f0.png"),
    ("buddeln_oben_normal", 6, "_pick_f6.png"),
    ("werkzeug_raus_a", 2, "_pick_take.png"),
    ("kletter_hack_oben", 4, "_pick_hack.png"),
]

for clip, frame, out in shots:
    with io.open(SRC, encoding="utf-8") as f:
        html = f.read()
    inject = """
<script>
window.addEventListener("load", function () {
  setTimeout(function () {
    paused = true;
    scene.clipName = "%s";
    player.frame = %d;
    player.current = "%s";
  }, 200);
});
</script>
</body>
""" % (clip, frame, clip)
    html = html.replace("</body>", inject)
    with io.open(TMP, "w", encoding="utf-8") as f:
        f.write(html)
    cmd = [CHROME, "--headless=new", "--no-sandbox", "--disable-extensions",
           "--enable-unsafe-swiftshader", "--use-angle=swiftshader",
           "--virtual-time-budget=3000", "--window-size=900,900",
           "--screenshot=" + os.path.join(r"C:\Users\frant\Downloads", out),
           "file:///" + TMP.replace("\\", "/")]
    subprocess.run(cmd, capture_output=True, timeout=180)
    print("ok", clip, frame, "->", out)
