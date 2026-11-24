# -*- coding: utf-8 -*-
"""Снимает кадры страницы: поворот, прыжок со стены, подъём после сна."""
import io, os, subprocess, sys

CHROME = r"C:\Program Files\Google\Chrome\Application\chrome.exe"
SRC = r"C:\Users\frant\Downloads\dwarf_life.html"
TMP = r"C:\Users\frant\Downloads\_frame_shot.html"
OUT = r"C:\Users\frant\Downloads"

shots = []
for frame in range(0, 5):
    shots.append(("drehen_ganz_links", frame, "_turnL_f%d.png" % frame, "turnL2"))
for frame in range(0, 5):
    shots.append(("drehen_ganz", frame, "_turnR_f%d.png" % frame, "turnR2"))
shots.append(("kletter_runter_loop", 3, "_exit_wall.png", ""))
shots.append(("schlafen_zu_stand", 3, "_exit_sleep.png", ""))
shots.append(("werkzeug_raus_a", 2, "_pick_take.png", ""))

for clip, frame, out, anim in shots:
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
    %s
  }, 200);
});
</script>
</body>
""" % (clip, frame, clip,
       ('player.activeId = "%s"; player.turn = {angle: %s * Math.PI, clip: "%s"};'
        % (anim, "1" if anim == "turnL2" else "-1", clip)) if anim else "")
    html = html.replace("</body>", inject)
    with io.open(TMP, "w", encoding="utf-8") as f:
        f.write(html)
    cmd = [CHROME, "--headless=new", "--no-sandbox", "--disable-extensions",
           "--enable-unsafe-swiftshader", "--use-angle=swiftshader",
           "--virtual-time-budget=3000", "--window-size=900,900",
           "--screenshot=" + os.path.join(OUT, out),
           "file:///" + TMP.replace("\\", "/")]
    subprocess.run(cmd, capture_output=True, timeout=180)
    print("ok", clip, frame, "->", out)
