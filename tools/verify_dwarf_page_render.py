# -*- coding: utf-8 -*-
"""
Проверка собранной страницы dwarf_life.html в headless Chrome:
  * каждый клип отрисовывается и даёт ненулевое число закрашенных пикселей;
  * лента иконок укладывается в экран: иконки не выходят за края, полоса не скроллится;
  * кнопок 13, анимаций 34, все клипы задействованы и существуют;
  * циклические кнопки идут по своей схеме, проскакивающего кадра нет;
  * изобретение действительно обходит по кругу (центр гнома смещается);
  * в консоли нет ошибок, gl.getError() == 0.

Страница проверяется как есть — тестовый скрипт подключается к копии файла.
"""
import io
import os
import re
import subprocess
import sys

CHROME = r"C:\Program Files\Google\Chrome\Application\chrome.exe"
SRC = r"C:\Users\frant\Downloads\dwarf_life.html"
TMP = r"C:\Users\frant\Downloads\_dwarf_verify.html"

TEST_JS = r"""
<script>
/* Останавливаем штатный цикл кадров: при виртуальном времени он успевает отрисовать
   сотни кадров в software-рендере и страница становится нечитаемо slow.
   Тест запускаем в настоящем rAF: буфер кадра в нём гарантированно ещё не очищен. */
var realRaf = window.requestAnimationFrame.bind(window);
var pending = null;
window.requestAnimationFrame = function (cb) { pending = cb; return 1; };

function whenReady(cb) {
  var tries = 0;
  (function check() {
    var boot = document.getElementById("boot");
    if ((boot && boot.style.display === "none") || ++tries > 300) { cb(); return; }
    realRaf(check);
  })();
}

whenReady(function () {
  realRaf(function () {
  var lines = [];
  lines.push("DIAG canvas=" + canvas.width + "x" + canvas.height +
             " lost=" + gl.isContextLost() +
             " tex=" + textures.map(function (t) { return t.image.naturalWidth + "x" + t.image.naturalHeight; }).join(","));
  var vw = window.innerWidth, vh = window.innerHeight;
  var sr = strip.getBoundingClientRect();
  var minL = 1e9, maxR = -1e9, minT = 1e9, maxB = -1e9, outside = 0, rows = {};
  for (var i = 0; i < buttons.length; i++) {
    var r = buttons[i].getBoundingClientRect();
    minL = Math.min(minL, r.left); maxR = Math.max(maxR, r.right);
    minT = Math.min(minT, r.top); maxB = Math.max(maxB, r.bottom);
    if (r.left < -0.5 || r.right > vw + 0.5 || r.top < -0.5 || r.bottom > vh + 0.5) outside++;
    var key = Math.round(r.top);
    rows[key] = (rows[key] || 0) + 1;
  }
  lines.push("LAYOUT vw=" + vw + " vh=" + vh + " icons=" + buttons.length +
             " rows=" + Object.keys(rows).length +
             " bbox=" + minL.toFixed(1) + "," + minT.toFixed(1) + "," +
             maxR.toFixed(1) + "," + maxB.toFixed(1) +
             " outside=" + outside +
             " stripH=" + sr.height.toFixed(1) +
             " stripBottom=" + sr.bottom.toFixed(1) +
             " scrollY=" + (strip.scrollHeight > strip.clientHeight + 1) +
             " scrollX=" + (strip.scrollWidth > strip.clientWidth + 1));

  /* Зазор между соседними кнопками должен быть одинаковым. */
  var rects = [];
  for (var gi = 0; gi < buttons.length; gi++) {
    var gr = buttons[gi].getBoundingClientRect();
    rects.push({left: gr.left, right: gr.right, top: gr.top, bottom: gr.bottom});
  }
  rects.sort(function (a, b) { return (a.top - b.top) || (a.left - b.left); });
  var gaps = [];
  for (var gj = 1; gj < rects.length; gj++) {
    if (Math.abs(rects[gj].top - rects[gj - 1].top) < 2) {
      gaps.push(Math.round((rects[gj].left - rects[gj - 1].right) * 10) / 10);
    }
  }
  var gapSet = {};
  for (var gk = 0; gk < gaps.length; gk++) gapSet[gaps[gk]] = 1;
  lines.push("GAPS count=" + gaps.length + " distinct=" + Object.keys(gapSet).length +
             " values=" + Object.keys(gapSet).join(",") +
             " min=" + Math.min.apply(null, gaps) + " max=" + Math.max.apply(null, gaps));

  paused = true;
  var width = canvas.width, height = canvas.height;
  var regionW = Math.min(width, 760), regionH = Math.min(height, 700);
  var offX = Math.floor((width - regionW) / 2);
  var buf = new Uint8Array(regionW * regionH * 4);
  var names = Object.keys(CLIPS);
  for (var c = 0; c < names.length; c++) {
    var name = names[c], clip = CLIPS[name];
    scene.clipName = name;
    player.current = name;
    player.frame = 0;
    drawScene();
    gl.readPixels(offX, 0, regionW, regionH, gl.RGBA, gl.UNSIGNED_BYTE, buf);
    var painted = 0, peak = 0;
    for (var p = 0; p < buf.length; p += 4) {
      var d = Math.abs(buf[p] - 14) + Math.abs(buf[p + 1] - 12) + Math.abs(buf[p + 2] - 11);
      if (d > 24) painted++;
      if (d > peak) peak = d;
    }
    lines.push("CLIP " + name + " frames=" + clip.frameCount + " painted=" + painted + " peak=" + peak);
  }
  lines.push("GLERROR " + gl.getError());
  lines.push("JSERRORS " + (window.__errors || []).length);

  /* Кнопки ленты: каждая анимация должна быть закреплена за кнопкой, все
     клипы из seq должны существовать, лишних клипов остаться не должно. */
  var missing = [], wrong = [];
  var used = {};
  used[IDLE_CLIP] = 1;
  function resetToIdle() {
    pendingQueue.length = 0;
    player.activeId = null;
    player.finished = false;
    player.queue = [{clip: IDLE_CLIP, repeat: Infinity}];
    player.current = null;
    player.frame = 0;
    player.time = 0;
    player.turn = null;
    player.exit = false;
    for (var g in cyclePos) cyclePos[g] = 0;
    syncButtons();
  }
  for (var a = 0; a < ANIMATIONS.length; a++) {
    var anim = ANIMATIONS[a];
    for (var s = 0; s < anim.seq.length; s++) {
      var clipName = anim.seq[s][0];
      used[clipName] = 1;
      if (!CLIPS[clipName]) missing.push(anim.id + ":" + clipName);
    }
    var reachable = false;
    for (var bi = 0; bi < buttons.length; bi++) {
      if (buttons[bi].dataset.anim === anim.id) { reachable = true; break; }
      var group = CYCLE_GROUPS[buttons[bi].dataset.anim];
      if (group && group.indexOf(anim.id) >= 0) { reachable = true; break; }
    }
    if (!reachable) wrong.push("нет кнопки " + anim.id);
  }
  /* Каждая кнопка запускает свою (у циклических — текущий вариант) анимацию. */
  for (var bk = 0; bk < buttons.length; bk++) {
    resetToIdle();
    var b = buttons[bk];
    var expect = buttonAnim(b);
    b.click();
    if (!expect || player.activeId !== expect.id) {
      wrong.push("клик не запустил " + (expect ? expect.id : b.dataset.anim));
    } else if (!player.queue.length || player.queue[0].clip !== expect.seq[0][0]) {
      wrong.push("плохая очередь " + expect.id);
    }
  }
  resetToIdle();
  var orphan = 0;
  for (var cn in CLIPS) { if (!used[cn]) orphan++; }
  lines.push("BUTTONS animations=" + ANIMATIONS.length + " buttons=" + buttons.length +
             " missingClips=" + missing.length + " wrong=" + wrong.length +
             " orphanClips=" + orphan);
  for (var mi = 0; mi < missing.length; mi++) lines.push("MISSING " + missing[mi]);
  for (var wi = 0; wi < wrong.length; wi++) lines.push("WRONG " + wrong[wi]);

  /* На странице не должно быть видимого текста (кроме атрибутов подсказок). */
  var texts = [];
  function walkText(node) {
    for (var n = node.firstChild; n; n = n.nextSibling) {
      if (n.nodeType === 3) {
        var t = n.nodeValue.replace(/\s+/g, " ");
        if (t.trim()) {
          var owner = n.parentNode ? n.parentNode.nodeName : "?";
          var html = n.parentNode ? String(n.parentNode.outerHTML || "").slice(0, 160) : "";
          texts.push(owner + ":" + JSON.stringify(t) + " in " + html);
        }
      } else if (n.nodeType === 1 && n.tagName !== "SCRIPT" && n.tagName !== "TITLE") {
        walkText(n);
      }
    }
  }
  walkText(document.body);
  lines.push("TEXTS " + texts.length);
  for (var ti = 0; ti < texts.length; ti++) lines.push("TEXT " + texts[ti]);

  /* Анимация должна проигрываться: кадры и клипы меняются со временем. */
  buttons[0].click();
  var frames = {}, clips = {};
  for (var t = 0; t < 60; t++) {
    updatePlayer(0.05);
    frames[player.frame] = 1;
    clips[player.current] = 1;
  }
  lines.push("PLAY frames=" + Object.keys(frames).length + " clips=" + Object.keys(clips).length +
             " last=" + player.current + ":" + player.frame);

  /* После отработки конечной анимации гном не должен прятаться. */
  function countPainted() {
    drawScene();
    gl.readPixels(offX, 0, regionW, regionH, gl.RGBA, gl.UNSIGNED_BYTE, buf);
    var n = 0;
    for (var p = 0; p < buf.length; p += 4) {
      if (Math.abs(buf[p] - 14) + Math.abs(buf[p + 1] - 12) + Math.abs(buf[p + 2] - 11) > 24) n++;
    }
    return n;
  }
  var bTurn = null, bTurn2 = null, bDig = null;
  for (var qi = 0; qi < buttons.length; qi++) {
    if (buttons[qi].dataset.anim === "turnL") bTurn = buttons[qi];
    if (buttons[qi].dataset.anim === "turnL2") bTurn2 = buttons[qi];
    if (buttons[qi].dataset.anim === "dig") bDig = buttons[qi];
  }
  bTurn.click();
  for (var t2 = 0; t2 < 300; t2++) updatePlayer(0.05);
  var after = countPainted();
  lines.push("AFTER_END clip=" + player.current + " painted=" + after +
             " visible=" + (after > 100 ? "yes" : "NO"));

  /* Очередь: клик по второй анимации не прерывает текущую, а ждёт её конца. */
  resetToIdle();
  bTurn.click();
  bDig.click();
  var queuedFlag = bDig.classList.contains("is-queued");
  var activeMid = player.activeId;
  for (var t3 = 0; t3 < 45; t3++) updatePlayer(0.05);
  lines.push("QUEUE queuedFlag=" + queuedFlag + " activeDuring=" + activeMid +
             " activeAfter=" + player.activeId + " pending=" + pendingQueue.length);

  /* Повторный клик: останавливает играющую анимацию / снимает её из очереди. */
  resetToIdle();
  bDig.click();
  bDig.click();                       /* тот же клик — остановка */
  var stopActive = player.activeId;
  var stopVisible = countPainted() > 100;
  resetToIdle();
  bTurn.click();                      /* играет turnL2 (разворот) */
  bDig.click();                       /* digUp уходит в очередь */
  var qBefore = pendingQueue.length;
  bDig.click();                       /* тот же клик — снятие из очереди */
  var qAfter = pendingQueue.length;
  var stillQueued = bDig.classList.contains("is-queued");
  lines.push("REPEAT stopActive=" + stopActive + " visibleAfterStop=" + stopVisible +
             " queueBefore=" + qBefore + " queueAfter=" + qAfter +
             " stillQueued=" + stillQueued);

  /* Поворот: отдельные кнопки на 90° и на разворот 180°, направление сохраняется. */
  resetToIdle();
  scene.heading = 0;
  bTurn.click();
  for (var t4 = 0; t4 < 300; t4++) updatePlayer(0.05);
  var heading90 = Math.round(scene.heading * 180 / Math.PI);
  bTurn2.click();
  for (var t4b = 0; t4b < 300; t4b++) updatePlayer(0.05);
  var headingAll = Math.round(scene.heading * 180 / Math.PI);
  lines.push("TURN heading90=" + heading90 + " headingAll=" + headingAll +
             " visible=" + (countPainted() > 100 ? "yes" : "NO"));
  scene.heading = 0;

  /* Прерывание на стене: гном сначала спрыгивает вниз, потом останавливается. */
  var bWall = null, bSleep = null;
  for (var wi2 = 0; wi2 < buttons.length; wi2++) {
    if (buttons[wi2].dataset.anim === "wall") bWall = buttons[wi2];
    if (buttons[wi2].dataset.anim === "sleep") bSleep = buttons[wi2];
  }
  resetToIdle();
  bWall.click();
  for (var t5 = 0; t5 < 10; t5++) updatePlayer(0.05);
  bWall.click();
  var wallExit = player.exit;
  var wallClip = player.queue.length ? player.queue[0].clip : "none";
  for (var t6 = 0; t6 < 300; t6++) updatePlayer(0.05);
  lines.push("EXIT_WALL exit=" + wallExit + " first=" + wallClip +
             " activeAfter=" + player.activeId + " visible=" + (countPainted() > 100 ? "yes" : "NO"));

  /* Прерывание сна: гном сначала встаёт, потом останавливается. */
  resetToIdle();
  bSleep.click();
  for (var t7 = 0; t7 < 10; t7++) updatePlayer(0.05);
  bSleep.click();
  var sleepExit = player.exit;
  var sleepClip = player.queue.length ? player.queue[0].clip : "none";
  for (var t8 = 0; t8 < 300; t8++) updatePlayer(0.05);
  lines.push("EXIT_SLEEP exit=" + sleepExit + " first=" + sleepClip +
             " activeAfter=" + player.activeId + " visible=" + (countPainted() > 100 ? "yes" : "NO"));

  /* Проскакивающий кадр: при спрыгивании со стены показываемый кадр должен
     принадлежать играющему клипу — первый кадр «слезания» не должен
     проскакивать повторно в конце цепочки. */
  resetToIdle();
  bWall.click();
  for (var t9 = 0; t9 < 10; t9++) updatePlayer(0.05);
  bWall.click();
  var exitFrames = [];
  for (var t10 = 0; t10 < 400; t10++) {
    updatePlayer(0.05);
    if (scene.clipName === "kletterstand_zu_stand") {
      var key = scene.clipName + ":" + scene.frame;
      if (exitFrames.length === 0 || exitFrames[exitFrames.length - 1] !== key) exitFrames.push(key);
    }
  }
  var firstFrames = 0;
  for (var zi = 0; zi < exitFrames.length; zi++) {
    if (exitFrames[zi] === "kletterstand_zu_stand:0") firstFrames++;
  }
  lines.push("FLASH frames=" + exitFrames.join(",") + " firstFrames=" + firstFrames);

  /* Циклические кнопки: после выполнения анимации кнопка показывает
     следующий вариант по своей схеме. */
  resetToIdle();
  var bCycle = null;
  for (var cy = 0; cy < buttons.length; cy++) {
    if (buttons[cy].dataset.anim === "wall") bCycle = buttons[cy];
  }
  var cycleSeen = [];
  for (var cr = 0; cr < 9; cr++) {
    var cur = buttonAnim(bCycle);
    cycleSeen.push(cur.id);
    bCycle.click();
    for (var ct = 0; ct < 400; ct++) updatePlayer(0.05);
  }
  lines.push("CYCLE " + cycleSeen.join(">") + " after=" + buttonAnim(bCycle).id);

  /* Цикл кирки: копание вверх/вперёд/вниз и два застревания, без стены. */
  resetToIdle();
  var bPick = null;
  for (var py = 0; py < buttons.length; py++) {
    if (buttons[py].dataset.anim === "dig") bPick = buttons[py];
  }
  var pickSeen = [];
  for (var pr = 0; pr < 6; pr++) {
    var curP = buttonAnim(bPick);
    pickSeen.push(curP.id);
    bPick.click();
    for (var pt = 0; pt < 400; pt++) updatePlayer(0.05);
  }
  lines.push("PICKCYCLE " + pickSeen.join(">"));

  /* Циклы боя и изобретения: четыре удара и четыре варианта изобретения. */
  resetToIdle();
  var bFight = null, bInvent = null;
  for (var fc = 0; fc < buttons.length; fc++) {
    if (buttons[fc].dataset.anim === "fight") bFight = buttons[fc];
    if (buttons[fc].dataset.anim === "invent") bInvent = buttons[fc];
  }
  var fightSeen = [];
  for (var fr = 0; fr < 5; fr++) {
    fightSeen.push(buttonAnim(bFight).id);
    bFight.click();
    for (var ft = 0; ft < 200; ft++) updatePlayer(0.05);
  }
  lines.push("FIGHTCYCLE " + fightSeen.join(">"));
  var invSeen = [];
  for (var ir = 0; ir < 6; ir++) {
    invSeen.push(buttonAnim(bInvent).id);
    bInvent.click();
    for (var it = 0; it < 400; it++) updatePlayer(0.05);
  }
  lines.push("INVCYCLE " + invSeen.join(">"));

  /* «Гуляние по кругу» при изобретении: центр гнома в клипе erfinden_a за 31 кадр
     обходит полный круг — считаем центр закрашенных пикселей по кадрам. */
  resetToIdle();
  function paintedCentroid(clipName, frameIndex) {
    scene.clipName = clipName;
    scene.frame = frameIndex;
    player.current = clipName;
    player.frame = frameIndex;
    drawScene();
    gl.readPixels(offX, 0, regionW, regionH, gl.RGBA, gl.UNSIGNED_BYTE, buf);
    var sx = 0, sy = 0, n = 0;
    for (var p = 0; p < buf.length; p += 4) {
      var d = Math.abs(buf[p] - 14) + Math.abs(buf[p + 1] - 12) + Math.abs(buf[p + 2] - 11);
      if (d > 24) {
        var idx = p >> 2;
        sx += idx % regionW;
        sy += Math.floor(idx / regionW);
        n++;
      }
    }
    if (!n) return null;
    return {x: sx / n, y: sy / n, n: n};
  }
  var circleFrames = [0, 8, 16, 24, 30];
  var circlePts = [];
  for (var cf = 0; cf < circleFrames.length; cf++) {
    circlePts.push(paintedCentroid("erfinden_a", circleFrames[cf]));
  }
  var circleMax = 0, circleBack = 0;
  if (circlePts[0]) {
    for (var cp = 1; cp < circlePts.length; cp++) {
      if (!circlePts[cp]) { circleMax = -1; break; }
      var dist = Math.hypot(circlePts[cp].x - circlePts[0].x, circlePts[cp].y - circlePts[0].y);
      if (dist > circleMax) circleMax = dist;
    }
    if (circlePts[circlePts.length - 1]) {
      circleBack = Math.hypot(circlePts[circlePts.length - 1].x - circlePts[0].x,
                              circlePts[circlePts.length - 1].y - circlePts[0].y);
    }
  }
  lines.push("CIRCLE maxMove=" + circleMax.toFixed(1) + " backToStart=" + circleBack.toFixed(1) +
             " pts=" + circlePts.map(function (c) { return c ? (c.x.toFixed(0) + "," + c.y.toFixed(0)) : "none"; }).join(" | "));

  /* Повороты и развороты — отдельные кнопки, у каждой своя анимация. */
  var turnButtons = [];
  for (var tbi = 0; tbi < buttons.length; tbi++) {
    var tid = buttons[tbi].dataset.anim;
    if (tid === "turnL" || tid === "turnL2" || tid === "turnR" || tid === "turnR2") {
      turnButtons.push(tid);
    }
  }
  lines.push("TURNBUTTONS " + turnButtons.join(","));

  /* В цепочках подъёма на стену кирка не достаётся и не убирается. */
  var toolInWall = [];
  for (var wa = 0; wa < ANIMATIONS.length; wa++) {
    var an = ANIMATIONS[wa];
    if (an.id.indexOf("cl") !== 0 && an.id.indexOf("wd") !== 0) continue;
    for (var ws = 0; ws < an.seq.length; ws++) {
      if (an.seq[ws][0].indexOf("werkzeug") === 0) toolInWall.push(an.id + ":" + an.seq[ws][0]);
    }
  }
  lines.push("WALLTOOL toolClipsInWallChains=" + toolInWall.length);

  var pre = document.createElement("pre");
  pre.id = "__test";
  pre.textContent = lines.join("\n");
  document.body.appendChild(pre);
  });
});
</script>
"""


def main():
    size = sys.argv[1] if len(sys.argv) > 1 else "1600,900"
    with io.open(SRC, encoding="utf-8") as f:
        html = f.read()
    if "__test" in html:
        print("В исходнике уже есть тестовый блок — пересобери страницу", file=sys.stderr)
        return 2
    html = html.replace("</body>", TEST_JS + "\n</body>")
    with io.open(TMP, "w", encoding="utf-8") as f:
        f.write(html)

    cmd = [
        CHROME, "--headless=new", "--no-sandbox", "--disable-extensions",
        "--enable-unsafe-swiftshader", "--use-angle=swiftshader",
        "--virtual-time-budget=12000", "--window-size=" + size,
        "--dump-dom", "file:///" + TMP.replace("\\", "/"),
    ]
    proc = subprocess.run(cmd, capture_output=True, text=True, encoding="utf-8",
                          errors="replace", timeout=240)
    dom = proc.stdout
    m = re.search(r'<pre id="__test">([\s\S]*?)</pre>', dom)
    if not m:
        print("Тестовый блок не найден в DOM", file=sys.stderr)
        print(dom[:2000], file=sys.stderr)
        return 2
    body = m.group(1)
    body = body.replace("&lt;", "<").replace("&gt;", ">").replace("&amp;", "&")
    print(body)

    clips = [l for l in body.splitlines() if l.startswith("CLIP ")]
    empty = [l for l in clips if l.endswith("painted=0")]
    layout = [l for l in body.splitlines() if l.startswith("LAYOUT ")]
    gl_error = [l for l in body.splitlines() if l.startswith("GLERROR ")]
    js_errors = [l for l in body.splitlines() if l.startswith("JSERRORS ")]

    ok = True
    for line in layout:
        print("\n" + line)
        if " outside=0" not in line:
            print("  ОШИБКА: иконки выходят за края экрана", file=sys.stderr)
            ok = False
        if " scrollY=true" in line:
            print("  ОШИБКА: лента не помещается по высоте", file=sys.stderr)
            ok = False
        if " scrollX=true" in line:
            print("  ОШИБКА: лента не помещается по ширине", file=sys.stderr)
            ok = False
    if empty:
        ok = False
        print("\nПустые клипы: %d" % len(empty), file=sys.stderr)
        for l in empty:
            print("  " + l, file=sys.stderr)
    for line in gl_error + js_errors:
        print("\n" + line)
        if not line.endswith(" 0"):
            print("  ОШИБКА", file=sys.stderr)
            ok = False
    for line in body.splitlines():
        if line.startswith("BUTTONS "):
            print("\n" + line)
            if "missingClips=0" not in line or "wrong=0" not in line:
                print("  ОШИБКА: лента ссылается на несуществующие клипы", file=sys.stderr)
                ok = False
            if "orphanClips=0" not in line:
                print("  ОШИБКА: есть клипы, которых не использует ни одна кнопка", file=sys.stderr)
                ok = False
            if "buttons=13 " not in line:
                print("  ОШИБКА: кнопок должно быть 13 (циклические схемы)", file=sys.stderr)
                ok = False
        if line.startswith("MISSING ") or line.startswith("WRONG "):
            print("  " + line, file=sys.stderr)
            ok = False
        if line.startswith("TEXTS "):
            print("\n" + line)
            if not line.startswith("TEXTS 0"):
                print("  ОШИБКА: на странице есть видимый текст", file=sys.stderr)
                ok = False
        if line.startswith("PLAY "):
            print("\n" + line)
            if "frames=1 " in line or "clips=1 " in line:
                print("  ОШИБКА: анимация не проигрывается", file=sys.stderr)
                ok = False
        if line.startswith("AFTER_END "):
            print("\n" + line)
            if "visible=yes" not in line:
                print("  ОШИБКА: после завершения анимации гном исчезает", file=sys.stderr)
                ok = False
        if line.startswith("GAPS "):
            print("\n" + line)
            if "distinct=1 " not in line:
                print("  ОШИБКА: расстояние между кнопками разное", file=sys.stderr)
                ok = False
        if line.startswith("QUEUE "):
            print("\n" + line)
            if "queuedFlag=true" not in line or "activeDuring=turnL" not in line \
               or "activeAfter=digUp" not in line:
                print("  ОШИБКА: очередь анимаций не работает", file=sys.stderr)
                ok = False
        if line.startswith("TURN "):
            print("\n" + line)
            if "heading90=90" not in line or "headingAll=270" not in line \
               or "visible=yes" not in line:
                print("  ОШИБКА: поворот не сохраняет направление", file=sys.stderr)
                ok = False
        if line.startswith("EXIT_WALL "):
            print("\n" + line)
            if "exit=true" not in line or "first=kletter_runter_loop" not in line \
               or "activeAfter=null" not in line or "visible=yes" not in line:
                print("  ОШИБКА: прерывание на стене не спрыгивает вниз", file=sys.stderr)
                ok = False
        if line.startswith("EXIT_SLEEP "):
            print("\n" + line)
            if "exit=true" not in line or "first=schlafen_zu_stand" not in line \
               or "activeAfter=null" not in line or "visible=yes" not in line:
                print("  ОШИБКА: прерывание сна не поднимает гнома", file=sys.stderr)
                ok = False
        if line.startswith("REPEAT "):
            print("\n" + line)
            if "stopActive=null" not in line or "visibleAfterStop=true" not in line \
               or "queueBefore=1" not in line or "queueAfter=0" not in line \
               or "stillQueued=false" not in line:
                print("  ОШИБКА: повторное нажатие не работает", file=sys.stderr)
                ok = False
        if line.startswith("FLASH "):
            print("\n" + line)
            if "firstFrames=1" not in line:
                print("  ОШИБКА: проскакивает кадр другой анимации", file=sys.stderr)
                ok = False
        if line.startswith("CYCLE "):
            print("\n" + line)
            if "clUp>clDown>clLeft>clRight>clUpF>clDownF>clLftF>clRgtF>clUp" not in line \
               or "after=clDown" not in line:
                print("  ОШИБКА: кнопки не заменяются по схеме", file=sys.stderr)
                ok = False
        if line.startswith("PICKCYCLE "):
            print("\n" + line)
            if "digUp>digFr>digDn>accUp>accDn>digUp" not in line:
                print("  ОШИБКА: цикл кирки идёт не по порядку", file=sys.stderr)
                ok = False
        if line.startswith("FIGHTCYCLE "):
            print("\n" + line)
            if "hitBox>hitA>hitC>hitSide>hitBox" not in line:
                print("  ОШИБКА: цикл боя идёт не по порядку", file=sys.stderr)
                ok = False
        if line.startswith("INVCYCLE "):
            print("\n" + line)
            if "invA>invBrain>invB>invC>invDone>invA" not in line:
                print("  ОШИБКА: цикл изобретения идёт не по порядку", file=sys.stderr)
                ok = False
        if line.startswith("CIRCLE "):
            print("\n" + line)
            if "maxMove=" not in line:
                print("  ОШИБКА: не удалось посчитать движение гнома", file=sys.stderr)
                ok = False
            else:
                move = float(re.search(r"maxMove=(-?[\d.]+)", line).group(1))
                back = float(re.search(r"backToStart=(-?[\d.]+)", line).group(1))
                if move < 20:
                    print("  ОШИБКА: гном не обходит по кругу при изобретении", file=sys.stderr)
                    ok = False
                if back > move / 2:
                    print("  ОШИБКА: круг изобретения не замыкается", file=sys.stderr)
                    ok = False
        if line.startswith("TURNBUTTONS "):
            print("\n" + line)
            if "turnL,turnL2,turnR,turnR2" not in line:
                print("  ОШИБКА: повороты и развороты должны быть отдельными кнопками", file=sys.stderr)
                ok = False
        if line.startswith("WALLTOOL "):
            print("\n" + line)
            if "toolClipsInWallChains=0" not in line:
                print("  ОШИБКА: в цепочках стены осталась работа с киркой", file=sys.stderr)
                ok = False
    print("\n%s (%d клипов)" % ("OK" if ok else "ПРОВАЛ", len(clips)))
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
