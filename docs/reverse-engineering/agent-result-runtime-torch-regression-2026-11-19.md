# Результат: регрессия освещения terrain автоматическими факелами

Дата: 2026-11-19 (второй прогон верификации, 18:00–18:40)

Живой проект: `C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles`
Рабочее дерево агента: `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\repro\godot`
Готовый патч: `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\torch_regression\torch-terrain-light-gain.patch`

> **СТАТУС ИНТЕГРАЦИИ: фикс НЕ применён в живом проекте.**
> На момент этого отчёта живой `godot/scripts/native_scene_profile.gd` не изменён
> (SHA-256 `B0AB5ED4439F3920796410DCE774902F`, строка 152 всё ещё содержит
> `/ 255.0`). Патч проверен и готов к применению; решение о применении —
> за владельцем проекта (см. §11).

---

## 1. Итог одной строкой

Факелы **не гасли terrain вообще** — не «третий и далее». Вклад факела в albedo
terrain был ровно в **255 раз меньше** исходного уравнения, потому что цвет света
в uniform-пуле делился на 255 лишний раз.

**Первопричина:** `godot/scripts/native_scene_profile.gd:152`

```gdscript
var gain: float = float(terrain_render["constants"]["gain"]) / 255.0
```

→ должно быть `float(terrain_render["constants"]["gain"])`.

Механика пула (32 слота, uniform при создании материала, перенос оценки в
`vertex()`) **корректна** и остаётся нетронутой. Регрессия внесена только
единичным множителем.

Этот отчёт **перепроверяет** вывод первого прогона независимо и **добавляет
 недостающее**: render-visible доказательство (§4) — попиксельное сравнение
одного и того же кадра с включённым и выключенным пулом факелов, а не только
сравнение CPU-математики.

---

## 2. Воспроизведение

### 2.1 Изоляция и актуальность

Живой проект **не редактировался**. Рабочее дерево `repro/godot` — полное
зеркало живого `godot/` (882 файла), сверено по SHA-256:

| проверка | результат |
|---|---|
| файлов в живом дереве / в зеркале | 882 / 884 |
| файлов только в живом дереве | 0 |
| файлов только в зеркале | `tools/torch_regression_probe.gd`, `tools/torch_terrain_light_regression_self_test.gd` (+ `tools/torch_render_visible_self_test.gd` в этом прогоне) |
| файлов с отличающимся содержимым | 1 — `scripts/native_scene_profile.gd` (ровно патч) |

Дополнительно сверено, что живой `native_scene_profile.gd` **не менялся** с
момента первого прогона: SHA-256 совпадает с зафиксированным ранее
(`B0AB5ED4439F3920…`).

Инструмент: `Godot_v4.7.2-stable_win64_console.exe`
(`godot --version` → `4.7.2.stable.official.ed1daf0bf`).

### 2.2 Диагностическая инструментация

`repro/godot/tools/torch_regression_probe.gd` — зонд. Он поднимает реальную сцену
`res://scenes/multiplayer_test.tscn`, копает разнесённые коридоры, даёт штатным
правилам размещения (`native_torch_runtime.gd` → `native_autolight.gd` →
`native_torch_policy.gd`) завести настоящие автоматические факелы и для каждого
печатает: ID, source/local-позицию, радиус, цвет; `dynamic_torch_count` и
первые слоты uniform-пула **реального** материала; `shader.resource_path` и RID
каждого материала из `material_cache`; ключ terrain-чанка; одну исходную вершину
рядом с факелом и её vertex-stage source coordinates; вклад шейдера против вклада
промышленной функции `TERRAIN_ILLUMINATION.channels()`.

Зонд читает `dynamic_torch_color` **из uniform реального материала**, а не
моделирует его.

### 2.3 Факелы в разных чанках, один далеко от старта

`PROBE_TORCH_COUNT created=5 runtime_torches=5 terrain_lights=14`

| torch | chunk (8×8) | local x,y | удалённость от старта |
|---|---|---|---|
| 1109 | (0, 1) | 1.56, 15.30 | стартовая область |
| 1110 | (1, 2) | 9.51, 18.59 | средняя |
| 1111 | (1, 0) | 13.17, 3.15 | средняя |
| 1112 | (4, 0) | 37.38, 3.29 | **далеко** |
| 1113 | (5, 1) | 41.66, 11.13 | **далеко** |

Требование задачи (≥3 факела в разных вырытых чанках, один далеко от стартовой
области) выполнено. Факелы 1112 и 1113 — в чанках (4,0) и (5,1), то есть за
пределами всех девяти статических ламп.

---

## 3. Доказанная первопричина

### 3.1 Формула

Промышленный CPU-путь (`godot/scripts/native_terrain_illumination.gd:33-35`):

```gdscript
float factor: float = exp(-2.0 * squared / radius_squared) * maxf(float(constants["min_dot"]), cosine)
rgb += Vector3(light["color"]) * factor * float(mini(visibility,255))   # visibility = 255
rgb *= float(constants["gain"])                                        # gain = 0.1
```

Итоговый вклад источника в 0..1 albedo:

```
color * factor * 255 * gain / 255  ==  color * factor * gain
```

Шейдер (`godot/shaders/native_terrain_pipeline.gdshader:41`) складывает
`dynamic_torch_color[index].rgb * exp(...) * facing` в `COLOR.rgb`, то есть в
тот же 0..1 albedo. Значит uniform-цвет **обязан** нести `color * gain`.

Фактически в `native_scene_profile.gd:152` он нёс `color * gain / 255`.

Подтверждённые значения из живого проекта
(`godot/models/native_terrain_render.json` → `constants`):
`gain = 0.1`, `min_dot = 0.1`, `depth_half = 0.5`, `depth_offset = 7.0`.
Цвет факела (`godot/models/native_torch_visual.json` → `light`):
`offset_native {0,-0.5,1}`, `range_native 6`, `rgb {0.9,0.9,0.8}` →
через `class_light_color()` = `(13.5, 13.5, 12.0)`.

**Дефицит ровно ×255.**

### 3.2 Наблюдение на реальном материале

`before.log` — реальный uniform на реальном материале:

```
PROBE_VERTEX id=1109 uniform_colour=(0.005294, 0.005294, 0.004706)
                     shader_delta=(0.003644, ...) cpu_delta=(0.815686, ...) ratio=232.0997
PROBE_VERTEX id=1111 uniform_colour=(0.005294, 0.005294, 0.004706)
                     shader_delta=(0.000518, ...) cpu_delta=(0.133333, ...) ratio=256.9499
PROBE_VERTEX id=1112 uniform_colour=(0.005294, 0.005294, 0.004706)
                     shader_delta=(0.001726, ...) cpu_delta=(0.439216, ...) ratio=254.7454
PROBE_VERTEX id=1113 uniform_colour=(0.005294, 0.005294, 0.004706)
                     shader_delta=(0.003715, ...) cpu_delta=(0.815686, ...) ratio=227.6973
```

`0.005294 = 13.5 × 0.1 / 255` — ровно то самое лишнее деление.

После патча:

```
PROBE_VERTEX id=1112 uniform_colour=(1.35, 1.35, 1.2)
                     shader_delta=(0.440211, ...) cpu_delta=(0.439216, ...) ratio=0.9990
```

Отношение 227…257 (вместо ровно 255) объясняется 8-битной квантизацией и
клиппингом в CPU-пути (`clampi(roundi(rgb.x),0,255)/255`), а не разбросом
формулы.

### 3.3 Что это даёт на экране

`albedo_shader` — что получит terrain, `albedo_cpu` — что требует исходное
уравнение, `albedo_no_torch` — запечённая база без факела:

| torch | albedo_shader (до) | albedo_cpu | albedo_no_torch | albedo_shader (после) |
|---|---|---|---|---|
| 1109 | 0.187958 | 1.000000 | 0.184314 | 1.000000 |
| 1110 | 0.106810 | 0.341176 | 0.105882 | 0.342464 |
| 1111 | 0.012283 | 0.145098 | 0.011765 | 0.143811 |
| 1112 | **0.013491** | **0.450980** | 0.011765 | **0.451976** |
| 1113 | 0.188028 | 1.000000 | 0.184314 | 1.000000 |

Факел добавлял к terrain 2…4 % вместо того, чтобы осветить коридор. В
тёмном выработанном коридоре (albedo 0.0118) итог — 0.0123: **визуально
terrain остаётся тёмным**. Это и есть наблюдаемый симптом.

---

## 4. Render-visible доказательство (новое в этом прогоне)

Предыдущие прогоны доказывали только CPU-математику. Задача требует проверки,
видимой в кадре (§4 задачи: «Нужен render-visible regression test, не только CPU
array test»), поэтому добавлен отдельный тест.

`repro/godot/tools/torch_render_visible_self_test.gd` рендерит **одну и ту же
сцену** дважды из **одной и той же камеры**:

* **кадр ON** — факел присутствует в runtime uniform-пуле;
* **кадр OFF** — тот же кадр после `set_dynamic_torch_lights([])`.

Запечённые vertex-цвета при этом не пересчитываются, поэтому между кадрами
различается **только** динамический свет факела.

Запуск (нужен реальный GPU-контекст, не `--headless`):

```powershell
& $godot --path $repro --rendering-driver opengl3 --resolution 640x360 `
  --script res://tools/torch_render_visible_self_test.gd
```

Контекст: `OpenGL API 3.3.13596 Core Profile Forward-Compatible Context 20.10.44
27.20.11044.7 - AMD Radeon(TM) Vega 8 Graphics` — тот же драйвер, что и в
штатных визуальных прогонах проекта (`tmp_feedback_visual_opengl.log`).

Камера наведена на реальную вершину terrain рядом с **дальним** факелом 1113
(чанк (5,1), local x = 41.66 — то есть далеко за пределами девяти статических
ламп):

```
camera=(47.69541, -9.1126, 12.5) focus=(42.0, -11.0, 12.5)
torch_world=(41.66302, -11.13377, 12.5)
```

Результат (метрика — средняя яркость brightest-дециля центральной области кадра):

| код | lit_top | dark_top | lift | exit |
|---|---|---|---|---|
| **непатченный** | 0.401636 | 0.401634 | **0.000003** | 1 (failures=1) |
| **патченный** | 0.606452 | 0.401634 | **0.204818** | 0 (failures=0) |

На непатченном коде два кадра **попиксельно идентичны** (lift = 3e-6) — факел не
даёт ровно ничего. На патченном коде коридор освещён (lift = 0.205 при пороге
0.02), разница в ~68 000 раз.

Кадры сохранены и кладутся рядом с отчётом:

| файл | что на нём |
|---|---|
| `far_torch_lit.png` | кадр ON на патченном коде — коридор освещён |
| `far_torch_dark.png` | кадр OFF на патченном коде — тот же кадр без света факела |
| `far_torch_unpatched_lit.png` | кадр ON на непатченном коде — темно, как `dark` |

Путь: `repro/docs/reverse-engineering/torch-render-visible/`
(и копии в `out/torch_regression/verify-2026-11-19/`).

---

## 5. Отвергнутые гипотезы

| # | Гипотеза | Вердикт | Доказательство |
|---|---|---|---|
| 1 | Материал нового чанка не получает активные uniform-ы | **отвергнута** | `PROBE_MATERIAL_SUMMARY stage=AFTER shader_pipeline=41 shader_detail=0 count_values={ 5: 41 }` — все 41 материал (включая созданные при раскопке) имеют `dynamic_torch_count = 5` |
| 2 | `ShaderMaterial` общий, но uniform изменён не у того экземпляра | **отвергнута** | `materials_holding_torch=41` для каждого факела; RID материалов стабильны между BEFORE и AFTER |
| 3 | Shader vertex работает в local/world пространстве, а light в другом | **отвергнута** | `space_match=true` для всех 5 факелов: `shader_source_point == cpu_source_point` до 1e-4. Шейдер восстанавливает ровно ту source-точку, которую использует CPU (`VERTEX.x`, `-VERTEX.y`, `(VERTEX.z+14)*0.5` ↔ `values+cell`, `bdb_z`). Отдельно проверено: `BDB_DEPTH_SCALE = 2.0`, `BDB_DEPTH_OFFSET = -14.0`, поэтому `VERTEX.z = 2·bdb_z − 14` и обратное преобразование шейдера `(VERTEX.z+14)·0.5` точно даёт `bdb_z` |
| 4 | Факел есть в runtime-списке, но отсекается/перезаписывается | **отвергнута** | `baked_excluded=true` для всех; слот uniform-а содержит точное `light.position` факела |
| 5 | Renderer/Godot не применяет uniform array после hot reload | **отвергнута** | RID материалов не меняются, `get_shader_parameter` на реальном материале возвращает заполненные слоты; рендер-тест §4 показывает, что значение **доходит до кадра** (lift 0.205). Проблема была в ЗНАЧЕНИИ массива, а не в его доставке |
| 6 | CPU-тест проходит, но shader-value/рендер не меняется | **подтверждена как причина слепоты** | `automatic_torch_runtime_self_test` на непатченном коде: `checks=36 failures=0`. Он проверяет только `dynamic_torch_count` и факт присутствия слота (`automatic_torch_runtime_self_test.gd:100,102,108`) — то есть проходимость, но **не модуль света** |
| 7 | Material использует legacy `native_terrain_detail` вместо pipeline | **отвергнута** | `shader_pipeline=41 shader_detail=0`; `use_native_diffuse=true` (дефолт `multiplayer_test.gd:155`) |
| 8 | Упёрлись в лимит пула 32 слота | **отвергнута** | 5 факелов → слоты 0…4; существующий self-test дополнительно покрывает 9 источников |
| 9 | Дефект появляется «с третьего факела» | **отвергнута** | Дефицит ×255 одинаков для **всех** факелов, включая первый (1109: ratio 232.1). Счётчик ни при чём. Первые факелы выглядят «правильно» только потому, что стоят в стартовой пещере, уже освещённой девятью запечёнными статическими лампами (albedo 0.184 против 0.012 в тёмных коридорах) |

---

## 6. Патч

Малый unified diff. Меняется **одна** смысловая строка + поясняющий комментарий.
Файл шейдера не трогается.

```diff
--- a/godot/scripts/native_scene_profile.gd
+++ b/godot/scripts/native_scene_profile.gd
@@ -149,7 +149,11 @@
 
 func _apply_dynamic_torch_uniforms(material: ShaderMaterial, lights: Array) -> void:
 	var positions: PackedVector4Array = PackedVector4Array()
 	var colors: PackedVector4Array = PackedVector4Array()
-	var gain: float = float(terrain_render["constants"]["gain"]) / 255.0
+	# The CPU path applies the light as color*factor*visibility*gain and then
+	# divides the 0..255 result by 255, so the contribution that reaches the
+	# 0..1 albedo is color*factor*gain. The uniform must carry color*gain.
+	# Dividing by 255 here as well made every torch 255 times too dim.
+	var gain: float = float(terrain_render["constants"]["gain"])
 	for index: int in range(MAX_DYNAMIC_TORCHES):
 		if index < lights.size():
 			var light: Dictionary = lights[index]
```

### Готовый файл патча

`C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\torch_regression\torch-terrain-light-gain.patch`
(SHA-256 `7922DC45D2976315325C7AF9DA108166`, 3 hunk-а, 516 строк)

```
--- a/godot/scripts/native_scene_profile.gd                          | 4 +++-
--- /dev/null
+++ b/godot/tools/torch_terrain_light_regression_self_test.gd        | 238 +++++++++
--- /dev/null
+++ b/godot/tools/torch_render_visible_self_test.gd                   | 257 +++++++++
```

Пути в патче — forward-slash, от корня проекта (`godot/`), поэтому применяется так:

```powershell
cd 'C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles'
git apply -p1 --check 'C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\torch_regression\torch-terrain-light-gain.patch'
git apply -p1 'C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\torch_regression\torch-terrain-light-gain.patch'
```

**Патч проверен программно:** применение hunk-а к живому файлу даёт результат,
**побайтово совпадающий** с подготовленным деревом агента; оба новых файла в
patче — побайтово те же, что в подготовленном дереве.

Все файлы патча — **CRLF, без BOM**, как и остальные `.gd` в проекте
(в живом проекте 158 файлов с CRLF; проверено, что `scripts/`, `tools/`,
`scenes/` и `project.godot` используют CRLF).

### Что НЕ меняется

* `godot/shaders/native_terrain_pipeline.gdshader` — без изменений.
* `godot/scripts/multiplayer_test.gd` — без изменений.
* Статические лампы: они запекаются в `COLOR` на CPU по тому же уравнению и
  патчем не затрагиваются.
* Walkmap, хомяки, APK/экспорт, художественное освещение — не затронуты.

---

## 7. Regression self-test-ы

### 7.1 `godot/tools/torch_terrain_light_regression_self_test.gd` (новый)

Существующий `automatic_torch_runtime_self_test.gd` зелёный и на сломанном коде
поэтому и не поймал регрессию: он проверяет проходимость uniform-а, а не модуль
света. Новый тест закрывает именно эту дыру.

1. Копает разнесённые коридоры, доводит штатными правилами размещения до
   **реальных** автоматических факелов; требует ≥3 факелов, ≥3 разных чанков и
   ≥1 факела далеко от старта.
2. Для каждого факела берёт **материал реального terrain-чанка** этого факела
   (`node.mesh.surface_get_material(0)`) и проверяет, что он использует
   `native_terrain_pipeline.gdshader`.
3. Проверяет, что факел занимает **живой** слот uniform-а этого материала и что
   `dynamic_torch_count` больше номера слота.
4. Проверяет, что цвет в uniform-е равен `class_light_color * gain` —
   с допуском 1e-6. Это ловит именно деление на 255.
5. Проверяет end-to-end: albedo, который посчитает vertex-stage шейдера для
   реальной вершины terrain рядом с факелом, совпадает с результатом
   промышленной функции `TERRAIN_ILLUMINATION.channels()` (допуск 3/255 — счёт
   8-битной квантизации CPU-пути), и что факел **видимо** поднимает albedo над
   запечённой базой.

### 7.2 `godot/tools/torch_render_visible_self_test.gd` (новый)

Попиксельный A/B-тест кадра, описанный в §4. Проверяет, что реально
отрендеренный terrain вокруг **дальнего** факела становится светлее, когда
uniform-пул заполнен, и остаётся тем же, когда пул пуст.

### 7.3 Доказательство, что тесты ловят регрессию

Непатченный код:

```
$ godot --headless --path godot --script res://tools/torch_terrain_light_regression_self_test.gd
ERROR: TORCH_TERRAIN_LIGHT_FAILED torch 1109 uniform colour (0.005294, 0.005294, 0.004706)
       equals native colour (13.5, 13.5, 12.0) scaled by gain 0.100000
ERROR: TORCH_TERRAIN_LIGHT_FAILED torch 1109 shader albedo 0.187958
       matches the source equation 1.000000 (baked 0.184314)
ERROR: TORCH_TERRAIN_LIGHT_FAILED torch 1109 visibly lifts the terrain albedo above the baked value 0.184314
   ... (по 3 проверки на каждый факел)
TORCH_TERRAIN_LIGHT_SELF_TEST torches=4 checks=39 failures=12
exit=1

$ godot --path godot --rendering-driver opengl3 --script res://tools/torch_render_visible_self_test.gd
ERROR: TORCH_RENDER_VISIBLE_FAILED the torch visibly lifts the rendered terrain
       lift 0.000003 exceeds 0.020000 (lit 0.401636, dark 0.401634)
TORCH_RENDER_VISIBLE_SELF_TEST torches=5 checks=9 failures=1
exit=1
```

Патченный код:

```
TORCH_TERRAIN_LIGHT_SELF_TEST torches=4 checks=39 failures=0    exit=0
TORCH_RENDER_VISIBLE_SELF_TEST torches=5 checks=9 failures=0     exit=0
```

---

## 8. Команды тестов

```powershell
$godot = 'C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe'
$proj  = 'C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\repro\godot'   # или живой godot\

# 1. Новый regression self-test (должен дать failures=0 на патченном коде)
& $godot --headless --path $proj --script res://tools/torch_terrain_light_regression_self_test.gd

# 2. Новый render-visible self-test (нужен реальный GPU-контекст)
& $godot --path $proj --rendering-driver opengl3 --resolution 640x360 `
  --script res://tools/torch_render_visible_self_test.gd

# 3. Существующий self-test факелов (должен остаться зелёным)
& $godot --headless --path $proj --script res://tools/automatic_torch_runtime_self_test.gd

# 4. Диагностический зонд (до/после; печатает uniform_colour и ratio)
& $godot --headless --path $proj --script res://tools/torch_regression_probe.gd

# 5. Linter (до и после правки .gd)
python 'C:\Users\frant\.codex\skills\godot\scripts\debug\lint_project.py' $proj --pretty
```

Логи: `out/torch_regression/verify-2026-11-19/`
(`before.log`, `after.log`, `render_patched.log`, `render_unpatched.log`,
`regression_unpatched.log`, `regression_patched.log`, `suite_summary.csv`).

> При запуске из **изолированной копии** проекта нужно положить рядом с каталогом
> проекта папку `docs/reverse-engineering/` — часть self-test-ов читает фикстуры
> через `res://../docs/reverse-engineering/...`. Без них эти тесты падают на
> `JSON.parse_string` и **не завершаются** — это артефакт изоляции, а не дефект
> проекта. В живом каталоге они проходят.

---

## 9. Полный прогон: patched против unpatched

25 self-test-ов прогнаны на **обоих** деревьях (50 прогонов), чтобы отделить
baseline-падения от внесённых патчем.

| self-test | patched | unpatched |
|---|---|---|
| `torch_terrain_light_regression_self_test` **(новый)** | **exit=0**, `checks=39 failures=0` | **exit=1**, `failures=12` |
| `torch_render_visible_self_test` **(новый, GPU)** | **exit=0**, `checks=9 failures=0` | **exit=1**, `failures=1` |
| `automatic_torch_runtime_self_test` | exit=0, `checks=36` | exit=0, `checks=36` |
| `native_torch_policy_self_test` | exit=0, `checks=17` | exit=0, `checks=17` |
| `native_torch_placement_self_test` | exit=0, `checks=70` | exit=0, `checks=70` |
| `native_autolight_self_test` | exit=0, `checks=33` | exit=0, `checks=33` |
| `native_scene_profile_self_test` | exit=0, `lights=9 terrain_surfaces=793` | exit=0, то же |
| `native_shader_pipeline_self_test` | exit=0, `assertions=7` | exit=0, то же |
| `native_terrain_render_self_test` | exit=0, `assertions=2431` | exit=0, то же |
| `terrain_refresh_self_test` | exit=0, `checks=8` | exit=0, `checks=8` |
| `world_model_light_self_test` | exit=0, `checks=31` | exit=0, `checks=31` |
| `native_model_material_self_test` | exit=0, `assertions=208` | exit=0, то же |
| `native_model_programs_self_test` | exit=0, `checks=9` | exit=0, то же |
| `native_walk_flags_self_test` | exit=0, `assertions=131` | exit=0, то же |
| `native_flame_self_test` | exit=0 | exit=0 |
| `native_hamster_ai_self_test` | exit=0, `assertions=69` | exit=0, то же |
| `native_hamster_actor_self_test` | exit=0, `assertions=66` | exit=0, то же |
| `native_wild_hamster_self_test` | exit=0, `assertions=57` | exit=0, то же |
| `native_terrain_state_self_test` | exit=0, `assertions=76` | exit=0, то же |
| `native_surface_walk_self_test` | exit=0, `assertions=45` | exit=0, то же |
| `native_fix_dig_self_test` | exit=0, `assertions=104` | exit=0, то же |
| `native_dig_next_self_test` | exit=0, `assertions=101` | exit=0, то же |
| `native_dig_groups_self_test` | exit=0, `assertions=27` | exit=0, то же |
| `native_corridor_input_self_test` | exit=0, `assertions=85` | exit=0, то же |
| `navigation_representative_self_test` | exit=0, `checks=11` | exit=0, то же |
| `excavated_walk_self_test` | **exit=1** | **exit=1** |

**Единственное расхождение между деревьями — два новых теста.** Все 23
остальных self-test-а ведут себя идентично.

`excavated_walk_self_test` падает с
`EXCAVATED_WALK_SELF_TEST_FAILED new navigation floor lacks terrain collision`
(`excavated_walk_self_test.gd:70`) **на обоих** деревеьях — это **существующий**
дефект текущего живого проекта (walkmap/collision), а не регрессия от патча.
Патч в `native_walkmap.gd` / `native_walk_flags.gd` / `native_terrain_state.gd` не
заходит.

### Linter

```
python 'C:\Users\frant\.codex\skills\godot\scripts\debug\lint_project.py' <proj> --pretty
→ exit 0
```

Единственная диагностика — уже известная и не связанная с патчем:
`res_path_missing` для `res://../docs/reverse-engineering/minimax-battle-world-2026-11-19.json`
в `godot/tools/native_battle_world_self_test.gd:18` (внешняя фикстура старого
пути).

### Чистота «до/после»

`before.log` и `after.log` отличаются **ровно 10 строками** — по две на каждый
факел (`uniform_colour`/`shader_delta`/`ratio` и `albedo_shader`). Идентичность
факелов, их позиций, ключей чанков, RID материалов, `dynamic_torch_count`,
`space_match` и `baked_excluded` совпадает. Остальные различия между прогонами —
известный шум: счётчики утечек `ObjectDB`/ресурсов при выходе и фаза анимации
хомяков (RNG-часы).

---

## 10. Риски merge относительно текущих файлов

1. **Живой проект меняется параллельно.** Рабочее дерево агента пересинхронизировано
   с живым проектом и сверено по SHA-256 (882 файла, 0 расхождений), и все
   измерения выше переполучены на актуальном коде. Перед merge стоит
   перепроверить, что строка 152 всё ещё содержит `/ 255.0` и что
   SHA-256 `native_scene_profile.gd` = `B0AB5ED4439F3920796410DCE774902F`.
2. **Патч локализован одной функцией** `_apply_dynamic_torch_uniforms`
   (`native_scene_profile.gd:149-165`). Ни один из параллельных walkmap-файлов
   эту функцию не трогает → конфликт при merge не ожидается.
3. **Значения uniform-а теперь > 1.0** (`1.35, 1.35, 1.2` при gain 0.1).
   Это штатно: `ALBEDO` клиппится в конце шейдера
   (`native_terrain_pipeline.gdshader:73`), а исходное уравнение тоже
   насыщается. Диапазон `PackedVector4Array` не меняется.
4. **Обратная совместимость формата.** `dynamic_torch_color` остаётся
   `PackedVector4Array` длиной 32 с тем же смыслом полей. Единственный писатель
   uniform-ов во всём проекте — `native_scene_profile.gd:163-165`; читателей два —
   шейдер (`native_terrain_pipeline.gdshader:34-41`) и существующий
   `automatic_torch_runtime_self_test.gd:100-108`. Других потребителей нет,
   поэтому смена величины ничего не ломает извне.
5. **Визуальный эффект будет заметным.** Восстановленный свет — это ~255-кратное
   увеличение вклада факела. В тёмных коридорах terrain будет освещён так же,
   как в оригинале. Возможна «резкая» вспышка при появлении факела — это
   корректное поведение, а не артефакт, но его стоит посмотреть глазами в игре.
6. **`data/Scripts/classes/items/emitter.tcl` и `data/sphere.dat` в живом
   проекте отсутствуют** — сверить формулу напрямую с оригиналом не удалось.
   Формула сверена с `docs/reverse-engineering/agent-result-lighting-architecture-2026-11-19.md:79,86`
   (`class_light {0 -0.5 1.0} 6 {0.9 0.9 0.8}`) и с `models/native_torches.json`
   (`light_offset [0,-0.5,1]`, `light_range 6.0`, `light_color [0.9,0.9,0.8]`),
   а также с действующей CPU-функцией, которая является эталоном.
7. **Новый render-visible тест требует GPU-контекст** и не пройдёт под
   `--headless` (там нет кадра). Его нужно запускать с
   `--rendering-driver opengl3`. Остальные тесты — обычные headless-прогоны.
   Сам тест **не** входит в «зелёный список» CI-подобных проверок, пока
   владелец проекта не решит, запускается ли он в его окружении.
8. **В текущем живом проекте уже есть падающий тест**, не связанный с
   освещением: `excavated_walk_self_test` →
   `EXCAVATED_WALK_SELF_TEST_FAILED new navigation floor lacks terrain collision`.
   Он воспроизводится и без патча (§9). При merge его не следует приписывать
   этому изменению.

---

## 11. Наблюдение по производительности (не связано с патчем)

`terrain_refresh_self_test` на патченном и непатченном дереве даёт
сопоставимые значения стоимости удара:

| прогон | strike_ms |
|---|---|
| patched | `[72.9, 55.9, 84.6]`, `[65.2, 60.3, 83.3]`, `[62.6, 58.1, 78.6]`, `[68.9, 62.2, 80.8]` |
| unpatched | `[69.5, 56.5, 79.9]` |

Разброс в пределах шума → **патч освещения на стоимость перестройки
terrain-геометрии не влияет**.

Однако сами эти числа (≈58–85 ms на удар) заметно выше, чем зафиксированные в
handoff «24–34 ms» на живой headless-сцене. Расхождение может объясняться
разным состоянием машины и тем, что измерение шло в изолированной копии на
OneDrive. **Требуется перезамер на живом дереве в редакторе** — это отдельная
открытая проблема handoff §5.2, и данный отчёт её не закрывает.

---

## 12. Файлы в рабочем дереве агента

| Файл | Статус | SHA-256 (первые 32) |
|---|---|---|
| `repro/godot/scripts/native_scene_profile.gd` | **изменён** — патч (§6) | `019CD5C4C6306A832FB3E5D80C597B8E` |
| `repro/godot/tools/torch_terrain_light_regression_self_test.gd` | **новый** — regression self-test (§7.1) | `E74736F4321462003C15AA45F7695202` |
| `repro/godot/tools/torch_render_visible_self_test.gd` | **новый** — render-visible self-test (§7.2) | `B342C3BADE96EDC068E7A5E7D19E24ED` |
| `repro/godot/tools/torch_regression_probe.gd` | **новый** — диагностический зонд (§2.2) | — |
| `out/torch_regression/torch-terrain-light-gain.patch` | **новый** — готовый unified diff (§6) | `7922DC45D2976315325C7AF9DA108166` |
| `out/torch_regression/verify-2026-11-19/` | логи до/после, suite_summary.csv, кадры | — |
| `repro/docs/reverse-engineering/torch-render-visible/` | кадры lit/dark | — |

Зонд `torch_regression_probe.gd` — диагностический инструмент. В живой проект
его переносить необязательно; два regression self-test-а — обязательно.

---

```text
INTEGRATION_HANDOFF
root_cause: native_scene_profile.gd:152 divided the dynamic torch light colour by 255 a second time, so every torch reached the terrain shader 255x too dim and lit nothing.
evidence: native_scene_profile.gd:152 `var gain ... / 255.0` vs native_terrain_illumination.gd:33-35 (color*factor*visibility*gain, /255) -> uniform_colour (0.005294,...) instead of (1.35,1.35,1.2); probe ratio 227.7-256.9 for torches 1109-1113; albedo_shader 0.0123 vs albedo_cpu 0.1451 on the real distant chunk (4,0) vertex; render A/B on the real GPU: unpatched lift 0.000003 (frames pixel-identical) vs patched lift 0.204818.
safe_patch: godot/scripts/native_scene_profile.gd _apply_dynamic_torch_uniforms() - drop the "/ 255.0" from the gain line; plus new godot/tools/torch_terrain_light_regression_self_test.gd and godot/tools/torch_render_visible_self_test.gd. Ready-to-apply diff: Minimax\Diggles\out\torch_regression\torch-terrain-light-gain.patch (verified to reproduce the prepared tree byte-for-byte). No shader, walkmap, hamster, APK/export or art change.
regression_test: godot --headless --path godot --script res://tools/torch_terrain_light_regression_self_test.gd -> failures=0 on patched (12 failures on unpatched); godot --path godot --rendering-driver opengl3 --script res://tools/torch_render_visible_self_test.gd -> failures=0 on patched (1 failure on unpatched); existing automatic_torch_runtime_self_test stays at failures=0.
do_not_touch: walkmap, hamster, APK/export
status: NOT APPLIED to the live project - native_scene_profile.gd is still SHA256 B0AB5ED4439F3920796410DCE774902F with "/ 255.0" on line 152. Awaiting an explicit instruction to merge.
```
