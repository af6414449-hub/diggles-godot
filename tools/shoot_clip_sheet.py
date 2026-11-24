# -*- coding: utf-8 -*-
"""Собирает контактный лист кадров страницы (по клипам и кадрам) в один PNG.

Список кадров задаётся JSON-файлом: [{"clip":..,"frame":..,"dist":..,"ty":..,"yaw":..}, ...]
"""
import io
import json
import os
import subprocess
import sys
import uuid

CHROME = r"C:\Program Files\Google\Chrome\Application\chrome.exe"
SRC = r"C:\Users\frant\Downloads\dwarf_life.html"
TMP = r"C:\Users\frant\Downloads\_clip_sheet.html"
OUT = r"C:\Users\frant\Downloads\_clip_sheet.png"
PROFILE = r"C:\Users\frant\Downloads\_chrome_profile_sheet"

COLS = 4
CELL = 300


def main() -> None:
    spec_path = sys.argv[1]
    out_path = sys.argv[2] if len(sys.argv) > 2 else OUT
    with io.open(spec_path, encoding="utf-8") as f:
        spec = json.load(f)
    shots = spec["shots"]
    cols = spec.get("cols", COLS)
    cell = spec.get("cell", CELL)
    rows = (len(shots) + cols - 1) // cols
    with io.open(SRC, encoding="utf-8") as f:
        html = f.read()
    inject = """
<script>
window.addEventListener("load", function () {
  setTimeout(function () {
    paused = true;
    var SHOTS = __SHOTS__;
    var COLS = __COLS__, CELL = __CELL__, ROWS = Math.ceil(SHOTS.length / COLS);
    document.getElementById("strip").style.display = "none";
    canvas.style.width = (COLS * CELL) + "px";
    canvas.style.height = (ROWS * CELL) + "px";
    canvas.width = COLS * CELL;
    canvas.height = ROWS * CELL;
    gl.enable(gl.DEPTH_TEST);
    gl.depthFunc(gl.LEQUAL);
    gl.disable(gl.CULL_FACE);
    gl.enable(gl.SCISSOR_TEST);
    for (var i = 0; i < SHOTS.length; i++) {
      var s = SHOTS[i];
      var col = i % COLS, row = Math.floor(i / COLS);
      var x = col * CELL, y = (ROWS - 1 - row) * CELL;
      gl.viewport(x, y, CELL, CELL);
      gl.scissor(x, y, CELL, CELL);
      gl.clearColor(0.055, 0.048, 0.042, 1.0);
      gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
      var yaw = (s.yaw === undefined ? -0.55 : s.yaw);
      var pitch = (s.pitch === undefined ? 0.22 : s.pitch);
      var target = {x: 0, y: s.ty, z: 0};
      var eye = {x: target.x + Math.sin(yaw) * Math.cos(pitch) * s.dist,
                 y: target.y + Math.sin(pitch) * s.dist,
                 z: target.z + Math.cos(yaw) * Math.cos(pitch) * s.dist};
      var aspect = CELL / CELL;
      var fovy = Math.max(0.75, 2 * Math.atan(Math.tan(1.02 / 2) / aspect));
      var projection = mat4Perspective(fovy, aspect, 0.02, 100.0);
      var view = mat4LookAt(eye, target, {x: 0, y: 1, z: 0});
      var floorNdc = projectNdc(mat4Multiply(projection, view), scene.pos.x, 0, scene.pos.z);
      if (floorNdc) projection[9] = floorNdc.y - (-1 + 2 * 0.07);
      scene.clipName = s.clip;
      scene.frame = s.frame;
      player.current = s.clip;
      player.frame = s.frame;
      drawDwarf(mat4Multiply(projection, view));
    }
    gl.disable(gl.SCISSOR_TEST);
    drawScene = function () {};
    document.title = "sheet-ready";
  }, 400);
});
</script>
</body>
"""
    inject = (inject.replace("__SHOTS__", json.dumps(shots))
                      .replace("__COLS__", str(cols))
                      .replace("__CELL__", str(cell)))
    html = html.replace("</body>", inject)
    with io.open(TMP, "w", encoding="utf-8") as f:
        f.write(html)
    cmd = [CHROME, "--headless=new", "--no-sandbox", "--disable-extensions", "--no-first-run",
           "--user-data-dir=" + PROFILE + "_" + uuid.uuid4().hex[:8],
           "--enable-unsafe-swiftshader", "--use-angle=swiftshader",
           "--virtual-time-budget=6000",
           "--window-size=%d,%d" % (cols * cell, rows * cell),
           "--screenshot=" + out_path, "file:///" + TMP.replace("\\", "/")]
    proc = subprocess.run(cmd, capture_output=True, timeout=300)
    print("written", out_path, "shots=", len(shots), "rc=", proc.returncode)


if __name__ == "__main__":
    main()
