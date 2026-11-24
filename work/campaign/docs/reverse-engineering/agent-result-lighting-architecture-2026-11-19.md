# Освещение без фризов: модель оригинала и двухслойная архитектура для Godot-порта

Дата: 19.11.2026. Задача: `agent-task-lighting-architecture-2026-11-19.md`.
Правки в `godot/` и в игровом коде **не вносились** — этот документ содержит только исследование и план.

---

## 0. Итог

1. **Оригинал не запекает свет.** В оригинальных шейдерах (`data/Shaders/*.fx`, `*.fxh`) нет ни массивов
   источников света, ни какой-либо формулы освещения: пиксельный шейдер берёт готовый цвет вершины,
   гонит его через эмуляцию D3D texture-staging и применяет гамму. Свет считает нативный рендерер
   `Diggles.exe` — **на вершине, в рантайме, из зарегистрированного пула ламп** (`confidence: high`).
2. **Значит «фоновое запекание» оригиналу не нужно.** Оригинал после раскопки не выполняет отдельного
   шага «перезапечь свет»: вскрытая геометрия просто освещается заново при следующей отрисовке
   (`confidence: medium-high` — вывод следует из отсутствия lightmap и из draw-time vertex-производителя,
   отдельного трассирования цикла «раскопка → перерисовка» не проводилось).
3. **В порту «мгновенный слой» уже существует**, и постановка задачи его не заметила: путь
   «перекрасить вершины по чанкам» для факелов **уже заменён** на uniform-массив в шейдере
   (`godot/scripts/multiplayer_test.gd:3687-3691` — в коде это зафиксировано комментарием).
   То есть описанная в задаче очередь по чанкам сегодня не является рантайм-путём.
4. **Но у текущего мгновенного слоя два конкретных дефекта**, которые как раз дают «свет появляется
   медленно / не появляется»: жёсткий лимит 8 источников с **тихой** потерей 9-го и далее, и дыра в
   кэше материалов, из-за которой новые вскрытые варианты грунта вообще не получают uniform-ов света.
5. **Рекомендация (одна стратегия): runtime-пул источников света в шейдере, с оценкой на вершине.**
   Существующий uniform-массив расширяется до 32 слотов, выбор источников делается на CPU,
   оценка переносится из fragment-стадии в vertex-стадию (это и есть семантика оригинала),
   а «фоновое уточнение» остаётся **необязательным fallback’ом** на случай переполнения бюджета.
   Пересборка terrain mesh из-за света не требуется ни в одном из слоёв.

---

## 1. Оригинальных `*.cpp` / `*.h` нет — что вместо них

Задача требует искать в «оригинальных `*.cpp`, `*.h`». Проверено: таких файлов нет нигде.

| Что проверялось | Результат |
|---|---|
| Рекурсивный поиск `*.cpp`, `*.h`, `*.hpp`, `*.pdb`, `*.map` в установке игры | Ни одного файла |
| Строка `.pdb` внутри `Diggles.exe` | Не найдена → отладочных символов нет |
| `C:\Users\frant\OneDrive\Документы\ChatGPT\` (верхний уровень) | Только `Diggles/` и `Гайды/`; дерева декомпиляции нет |
| `*.cpp` в проекте | Только `android/app/src/main/cpp/command_registry.cpp` — JNI-шим Android-порта, не оригинал; плюс build-артефакты `.cxx` |

Оригинал состоит из трёх частей:

* **Tcl-скрипты** — `data/Scripts/` (589 файлов), `data/GameScripts/`, `data/Templates/`,
  `data/systeminit.tcl`. Это уровень поведения и, важно, **описание источников света**.
* **Нативное ядро** — `Diggles.exe` (3 813 376 байт, SHA-256
  `58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74`) + `DigglesPort.dll`
  (SHA-256 `ace39618ac4946454eadaf35a824144c67b525ccafffad8a19ad200b3fdb6cf3`).
  Доступно только через дизассемблирование; в проекте это делают экспортёры
  `tools/export_world_model_lighting.py` и `tools/export_native_shader_pipeline.py`.
* **Бинарные данные** — `data/3db/*.3db` (модели, включая `licht.3db` с факелом),
  `data/Templates/*.pmp`/`*.l2m`, `data/Ground/*.tga`, `data/Texture/**`, `data/BlockDB*.BDB`,
  `data/sphere.dat` (таблица нормалей).

Оба EXE-производителя проверены мной на текущей машине и проходят:

```text
python -B tools\export_world_model_lighting.py --check  -> {"ok": true, "check": true, "spans": 12, "constants": 10}, EXIT=0
python -B tools\export_native_shader_pipeline.py --check -> NATIVE_SHADER_PIPELINE_CHECK_OK, EXIT=0
```

То есть все EXE-адреса и константы, приведённые ниже, воспроизводимы этими двумя командами.

---

## 2. Что установлено об оригинале

### 2.1 Источники света объявлены в Tcl

`data/Scripts/classes/items/emitter.tcl` — исходное объявление факела:

```tcl
def_class Misc_Light none dummy 0 {} {
	call scripts/misc/animclassinit.tcl
	class_disablescripting
	class_viewinfog 1
	class_light {0 -0.5 1.0} 6 {0.9 0.9 0.8}
	class_defaultanim fackel.standard
	class_particle 2 {0 -0.1 0.2} {0 0 0} 32 1 0 0 -1
	class_snaptowall 1
}
```

Формат `class_light {offset} {radius} {rgb}`: смещение `{0 -0.5 1.0}`, **радиус 6**, цвет `{0.9 0.9 0.8}`.
Это и есть «факел»: модель `licht.3db::fackel`, частицы type-2, прилипание к стенам.
Тот же факт независимо подтверждён в `docs/reverse-engineering/digging-and-cave-system.md:206-216`.

Рядом — семейство статических источников с разными радиусами (`emitter.tcl:13-58`):

```tcl
def_class Misc_LightSrc_a ... { class_light {0 -0.5 0} 2 {0.6 0.6 0.5} -1 }
def_class Misc_LightSrc_b ... { class_light {0 -0.5 0} 3 {0.6 0.6 0.5} -1 }
def_class Misc_LightSrc_c ... { class_light {0 -0.5 0} 4 {0.6 0.6 0.5} -1 }
def_class Misc_LightSrc_d ... { class_light {0 -0.5 0} 5 {0.6 0.6 0.5} -1 }
def_class Misc_LightSrc_e ... { class_light {0 -0.5 0} 6 {0.7 0.7 0.6} -1 }
def_class Misc_LightSrc_f ... { class_light {0 -0.5 0} 8 {0.7 0.7 0.6} -1 }
```

Радиус — это **число клеток исходной карты**, а не метры: в порту он переносится без единиц измерения
(`native_scene_profile.gd:51-52` кладёт `spec["range"]` в запись лампы «как есть»).

Прочие источники (лава, кристалл, Urwald, Swf) объявлены там же — `emitter.tcl:132-583`.
Это доказывает: **источники света в оригинале — обычные объекты сцены**, а не отдельная карта света.

### 2.2 В шейдерах оригинала света нет вообще

`data/Shaders/Common.fxh:187-200` — эмуляция fixed-function staging, вход = цвет вершины:

```hlsl
float4 TextureStaging(float2 uv[USED_STAGES_COUNT], float4 diff, float4 spec)
{
	float4 prev = diff;
	{ tex = textureStages[0].Sample(...); prev = ApplyTextureStage(texStageOptions[0], tex, prev, diff, spec); }
	{ tex = textureStages[1].Sample(...); prev = ApplyTextureStage(texStageOptions[1], tex, prev, diff, spec); }
	return prev;
}
```

`data/Shaders/UL2CS.fx:37-43` — весь пиксельный шейдер:

```hlsl
float4 PS(PS_INPUT input) : SV_Target
{
	float4 spec = CheckSpecularEnabled(input.specular);
	float4 color = TextureStaging(input.uv, input.diffuse, spec);
	color.rgb += spec.rgb;
	return ApplyGamma(AlphaTest(color));
}
```

Ни в `Common.fxh`, ни в `UL2CS.fx`/`TL1CS.fx`/`TL2CS.fx`/`UL1CS.fx`/`UL2CS.fx`/`Composition.fx` нет
ни `uniform` с источниками света, ни цикла по лампам, ни формулы затухания. Вход пиксельного шейдера —
`COLOR0` (цвет вершины) и `COLOR1` (specular).

**Вывод (confidence: high):** источники света не «проецируются» шейдером. Шейдер только переносит
уже вычисленный рендерером цвет вершины через staging → gamma. Любая схема «массив источников в
шейдере» — это **адаптер порта**, а не воспроизведение оригинального шейдера.

### 2.3 Нативный рендерер считает свет на вершине, из пула зарегистрированных ламп

Восстановленные проектом цепочки (адреса — из `godot/models/native_world_model_lighting.json`,
проверяются `--check`):

```text
model dispatch 0x486AD0..0x486C7D
    material/program classification
    un-interpolated normal branch 0x48A240
    point + source normal transform 0x48A533..0x48A626
    world color producer 0x4856E0
        four map probes/cache 0x485370
        fixed-point C+7 / owner interpolation
        directional base + registered point lamps
        diffuse + bounded secondary
```

* **Нормаль вершины** берётся из таблицы `data/sphere.dat` (256 записей float32 XYZ, загружается
  `0x463C35..0x463C81`), затем поворачивается instance-rotation. Это **индекс на вершину**,
  а не «яркость» — важная поправка, зафиксированная в
  `docs/reverse-engineering/model-lighting-feedback-2026-11-18.md:9-12`.
* **База** — `level = (3.5999999046 - 2.546*Nx - 2.546*Ny) * base`, где `base` — интерполяция четырёх
  байт `C+7` с фиксированными весами и `+64`.
* **Лампа** — вклад зарегистрированной точечной лампы со **строгим радиусом**:
  `exp(-2*d²/r²) * max(0.1, dot(N,L))`, отсечка по `d² >= r²`.
* **Цвет лампы** проходит цепочку единиц:
  `class_light` (Tcl RGB) → ×31 и truncate в int (`0x614CBC..0x614CD1`) → object `+0x298`
  (`0x5C7CF9..0x5C7D14`) → пул `0x591A20` и 36-байтная запись лампы (`0x5CC0D0..0x5CC112`,
  `0x591CF3..0x591D05`) → в рендерере ×0.5 (`0x4C80FD..0x4C81A9`).
  То есть `{.6,.6,.5}` доходит до расчёта как `{9,9,7.5}`.
* **Разделение на каналы** — `0x4CC52C..0x4CC5C2`: округлённые значения делятся на diffuse (0…255)
  и overflow/secondary (0…64). Это **до** texture-staging и gamma.
* **Terrain diffuse path** — `0x4CC040`.

Ключевое: всё это — **vertex color producer**. Считается один раз на вершину при отрисовке,
интерполируется по треугольнику, уходит в `COLOR0`/`COLOR1` шейдера.

### 2.4 Что оригинал делает после раскопки

Отдельного «шага пересчёта света» в оригинале нет: зарегистрированные лампы живут в пуле
(`0x591A20`), а цвет вершины вычисляется в момент отрисовки. После раскопки меняется геометрия
BlockDB, и вскрытые вершины получают цвет из того же пула ламп при следующей отрисовке.

* Уверенность **medium-high**: это вывод из отсутствия lightmap/lightmap-ресурсов в `data/`,
  из draw-time производителя цвета и из того, что пул ламп — единственный источник света.
* Уверенность **low** по конкретной частоте/порядку перерисовки после раскопки: live-трассировка
  цикла «раскопка → перерисовка» не выполнялась, EXE-спан для native-ядра раскопки
  (`0x596B80`) в этом отчёте не разбирался.

### 2.5 Чего установить не удалось

* `class_light` 4-й аргумент (`-1` у `Misc_LightSrc_*`, отсутствует у `Misc_Light` и `Dummy_*`) —
  семантика не восстановлена.
* Owner/FOW-байты (`C+34`) и их производство — не перенесены (`world-model-lighting-2026-11-18.md:69`).
* Реальные пользовательские настройки gamma/brightness оригинала не захвачены; используются
  дефолты EXE: gamma `1.2999999523162842`, brightness `0.0`.
* Live-момент включения/выключения лампы и её enable-state — не разбирались.

---

## 3. Что реально в порту сейчас (проверено по коду)

### 3.1 Расхождение с постановкой задачи

Постановка говорит: «текущая реализация перекрашивает вершины terrain mesh по чанкам в очереди».
**В текущем коде этого уже нет** для света факелов:

```gdscript
# godot/scripts/multiplayer_test.gd:3687-3691
func _queue_torch_terrain_lighting(_changes: Array) -> void:
	# Automatic torches are a shared shader uniform. Rebuilding vertex colours
	# here caused both a stall and a visible chunk-by-chunk lighting wave.
	# Keep this entry point for tools/tests, but intentionally schedule no mesh work.
	source_profile.set_dynamic_torch_lights(_automatic_torch_lights())
```

Механика «очередь по чанкам» сохранилась в коде как инструмент для тестов
(`_step_torch_terrain_lighting` — `multiplayer_test.gd:3712-3717`,
`_refresh_torch_terrain_lighting_bucket` — `multiplayer_test.gd:3727-3764`), но в рантайме
не вызывается. `automatic_torch_runtime_self_test.gd:98,113,117` это фиксирует:
`torch_terrain_lighting_queue` пуста, `torch_lighting_updates == 0`, цвета вершин не меняются.

### 3.2 Фактические слои света в порту

| Слой | Где | Что делает | Когда считается |
|---|---|---|---|
| **База (запечённая)** | `multiplayer_test.gd:1437-1440` → `native_terrain_illumination.gd:19-41` | Полное исходное уравнение света на вершину: `C+7` → base, направленная база, **9 статических ламп**; результат в `COLOR` + `CUSTOM0` (secondary) | При сборке меша; пересчёт только для пересобираемых чанков |
| **Мгновенный (uniform)** | `native_terrain_pipeline.gdshader:18-20, 55-67` | Динамические факелы: `dynamic_torch_position_range[8]`, `dynamic_torch_color[8]`, та же формула `exp(-2d²/r²)*max(0.1,dot(N,L))` | Каждый кадр, **на фрагменте**, для всех чанков сразу (uniform общий на материал) |
| **Модели** | `native_scene_profile.gd:162-184`, `multiplayer_test.gd:3629-3637` | `OmniLight3D` на источник | Godot-свет, только для lit-моделей |
| **Пламя** | `native_flame_emitter.gd:5-16, 79-81` | Частицы type-2, свой unlit-шейдер (`blend_mix`, `depth_draw_never`) | Источником света **не является** |

Террейн — `render_mode unshaded` (`native_terrain_pipeline.gdshader:2`), поэтому Godot-свет на него не
влияет: весь свет приходит из `COLOR`/`CUSTOM0` и uniform-ов.

### 3.3 Раскладка света по слоям и их стоимость

* Чанк = **8×8 клеток** (`multiplayer_test.gd:106`, `TERRAIN_CHUNK_CELLS = 8`), terrain 44×24 клетки
  → 18 чанков; меш-бакетов 168, вершин 15 906, треугольников 5 302 (по
  `docs/reverse-engineering/runtime-performance-2026-11-18.md`).
* Пересборка при раскопке **уже ограничена** грязными чанками и вариантами грунта:
  `dirty_chunks` — `multiplayer_test.gd:1323-1326`, отбор клеток — `:1359, :1365`,
  освобождение только нужных бакетов — `:1338-1342`.
* Очередь отложенного refresh существует, но при наличии `changed_cells` flush происходит
  **немедленно и синхронно** в кадре удара (`multiplayer_test.gd:622-631`), счётчик и тайминги —
  `:659-661` (`NATIVE_TERRAIN_REFRESH batches=… geometry_ms=…`).

---

## 4. Найденные дефекты текущей реализации

### D1. Лимит 8 источников с тихой потерей света — `confidence: high`

```gdscript
# godot/scripts/native_scene_profile.gd:14
const MAX_DYNAMIC_TORCHES: int = 8
# godot/scripts/native_scene_profile.gd:157
material.set_shader_parameter("dynamic_torch_count", mini(lights.size(), MAX_DYNAMIC_TORCHES))
```

Слоты заполняются из `_automatic_torch_lights()` (`multiplayer_test.gd:3665-3671`) в порядке
создания факелов. Одновременно `_terrain_baked_lights()` (`multiplayer_test.gd:3674-3684`)
**исключает все автоматические факелы** из запекаемой базы. Итог: факел №9 и далее не освещает
terrain **вообще** — ни в uniform-слое (обрезан), ни в запечённом (исключён).
В оригинале пул ламп ограничен только самой сценой; в текущей карте уже 9 статических `Misc_LightSrc_*`
плюс автоматические факелы, так что ограничение достижимо.

### D2. Дыра в кэше материалов: новый грунт не получает uniform-ов света — `confidence: high`

`terrain_material()` (`native_scene_profile.gd:112-136`) создаёт `ShaderMaterial` и **не выставляет**
`dynamic_torch_count/position_range/color`. Uniform-ы проставляются только в
`set_dynamic_torch_lights()` (`:139-159`), который обходит уже существующий `material_cache`.

Материалы создаются лениво при сборке геометрии (`multiplayer_test.gd:1390`), то есть **после**
последнего вызова `set_dynamic_torch_lights()`. Следствие: вскрытый при раскопке новый вариант грунта
(`Gnd_*.tga` → новый ключ кэша) получает `dynamic_torch_count = 0` → факелы на нём не светят,
пока не произойдёт следующего события источника.

### D3. Разрыв семантики «динамика против запечённого света» — `confidence: high`

* Запечённый свет проходит нативное разделение на diffuse/secondary (`native_terrain_illumination.gd:37-40`),
  secondary уходит в `CUSTOM0` и прибавляется после staging (`native_terrain_pipeline.gdshader:70`).
* Динамический свет добавляется **после** этого разделения, прямо в staging-вход
  (`native_terrain_pipeline.gdshader:68`: `stage(ground_op, ground, COLOR.rgb + dynamic_torch, ...)`).
  Значит вклад факела **никогда не может дать native overflow-канал** (0…64) и не проходит через
  тот же путь округления/клиппинга.
* Динамика считается **на фрагменте**, а оригинал — **на вершине** (см. §2.3). Расстояние и нормаль
  интерполируются по треугольнику, результат не совпадает с исходной семантикой (в оригинале вершина
  имеет одну нормаль из `sphere.dat` и одну позицию).

### D4. Мёртвый путь и неверная посылка в постановке — `confidence: high`

`_queue_torch_terrain_lighting` не планирует mesh-работу (`multiplayer_test.gd:3688-3690`), но рядом
остались `TORCH_TERRAIN_LIGHTING_BUCKETS_PER_FRAME`, очередь `torch_terrain_lighting_queue` и
точный per-bucket пересчёт вершин (`multiplayer_test.gd:3727-3764`). Код читается как «реализованная
очередь по чанкам», хотя в рантайме она выключена. Любой интегратор, идущий по постановке задачи,
будет чинить несуществующий рантайм-баг.

---

## 5. Сравнение вариантов

| Критерий | **A. Uniform-пул в шейдере, оценка на вершине** | **B. Overlay / light-volume** | **C. Godot `Light3D` (Omni/Spot)** |
|---|---|---|---|
| Совместимость с оригиналом | **Высокая.** Та же формула `exp(-2d²/r²)*max(0.1,dot(N,L))`, тот же строгий радиус, тот же источник нормали (`sphere.dat`), та же цепочка единиц цвета | **Низкая.** Нет `N·L`, нет per-vertex семантики; свет не знает о геометрии — проходит сквозь стены | **Низкая.** Аттенюация Godot (`omni_range` + кривая) ≠ `exp(-2d²/r²)`; light считается per-pixel иначе |
| Стоимость на один факел | O(V) на вершинах (15 906 вершин) + O(материалы) на выгрузку uniform-ов. Пересборки меша нет | Прозрачная геометрия поверх сцены: overdraw на весь экран, сортировка, лишние draw calls | +1 `OmniLight3D` на источник: узлы, сортировка, ограничение числа источников на объект |
| Лимит числа источников | Размер uniform-массива (32 — практический предел; 64 — верхняя граница для vec4-массива) | Формально нет, но каждый источник = геометрия/шейдер | Лимит движка на объект (omni/spot), плюс стоимость прохода по всем объектам |
| Совместимость с source-координатами | **Полная.** Шейдер уже восстанавливает исходное пространство света: `source_light_point = vec3(VERTEX.x, -VERTEX.y, (VERTEX.z+14.0)*0.5)` (`native_terrain_pipeline.gdshader:29`) и `source_light_normal` из `NORMAL` (`:30`) | Требует собственной проекции в source-пространство; неочевидно | Работает в Godot-пространстве; исходная семантика радиуса (в клетках) теряется |
| Артефакты на стенах | **Нет.** Используется исходная нормаль вершины и строгий радиус; те же условия, что в оригинале | Свет сквозь стены, z-fighting с полом, order-dependent blending | Иная кривая затухания, «пятно» на полу, тени отключены |
| Мгновенность появления | **Да** — uniform обновляется в том же кадре | Да | Да, но только для lit-объектов; terrain `unshaded` → **не работает без смены конвейера** |
| Требует пересборки terrain mesh | **Нет** | Нет | Нет, но требует перевода terrain с `unshaded` на lit, что ломает vertex-color/gamma-пайплайн |
| Итог | **Рекомендуется** | Отклоняется (артефакты + overdraw) | Отклоняется для terrain (несовместимость пайплайна); остаётся только для моделей |

---

## 6. Рекомендация: одна стратегия

**Стратегия: единый runtime-пул источников света в шейдере terrain, с оценкой на вершине;
запекание остаётся только для базы (C+7, направленная база, статические лампы) и служит
fallback’ом при переполнении бюджета uniform-пула.**

### Слой 0 — база (запечённая, без изменений)

Остаётся как есть: `C+7` → base byte → направленная база от нормали → 9 статических ламп,
результат в `COLOR` + `CUSTOM0`. Пересчитывается только для пересобираемых при раскопке чанков
(уже так и есть, `multiplayer_test.gd:1323-1326, 1359, 1365`).

### Слой 1 — мгновенный (рекомендуемый, ядро решения)

* Uniform-пул источников: расширить массивы `dynamic_torch_position_range[N]` /
  `dynamic_torch_color[N]` с 8 до **32** слотов (`native_terrain_pipeline.gdshader:18-20`).
* Оценка переносится из `fragment()` в `vertex()`: считаем вклад пула один раз на вершину,
  передаём в varying и складываем с запечённой базой. Это (а) совпадает с оригиналом,
  (б) дешевле в 10-100 раз, чем per-fragment (15 906 вершин против миллионов фрагментов).
* Отбор источников на CPU: в слоты попадают ближайшие к камере/фокусу N источников;
  «первые 8 в порядке создания» (сейчас) заменяется на осмысленный выбор.
* Uniform-ы выставляются **при создании материала** и при каждом изменении пула —
  это закрывает D2.
* Динамический вклад складывается **до** разделения на diffuse/secondary, как в оригинале
  (требует вычисления суммарного цвета в varying и разделения в шейдере) — закрывает D3.

### Слой 2 — фоновое уточнение (необязательно, по умолчанию выключено)

В оригинале запекания нет (§2.4), поэтому отдельный «фоновый проход запекания» **не нужен для
паритета**. Он имеет смысл только как аварийный режим, когда число активных источников
превышает бюджет uniform-пула:

* Тогда включается существующий точный per-bucket пересчёт вершин
  (`multiplayer_test.gd:3727-3764`), уже умеющий ограничивать работу одним бакетом за кадр
  (`TORCH_TERRAIN_LIGHTING_BUCKETS_PER_FRAME`).
* Включение — только флагом, с ограничением по кадрам; никакого синхронного flush.
* Правило выбора: слой 1 работает всегда; слой 2 включается, только если `источников > 32`.

### Почему не «сначала перекрасить всё, потом уточнять»

Потому что оригинал так не делает. Перекраска вершин по чанкам — это попытка сэмулировать
отсутствующий в оригинале bake; она даёт и фриз, и волну по чанкам (что и зафиксировано
в комментарии `multiplayer_test.gd:3688-3690`). Правильная адаптация оригинала — **считать
свет в шейдере в момент отрисовки**, а не воспроизводить несуществующий в оригинале этап.

---

## 7. Минимальный план интеграции

> Ни один шаг не выполнен в этом отчёте. Правки в `godot/` не вносились.

### Шаг 1 — закрыть «свет не появляется» (малый, обратимый)

* `godot/shaders/native_terrain_pipeline.gdshader`: расширить массивы до 32 слотов.
* `godot/scripts/native_scene_profile.gd`: `MAX_DYNAMIC_TORCHES` 8 → 32; выставлять
  `dynamic_torch_*` сразу при создании материала в `terrain_material()`; в
  `set_dynamic_torch_lights()` выбирать ближайшие к камере источники вместо первых N.
* `godot/tools/automatic_torch_runtime_self_test.gd`: добавить проверку, что **девятый**
  факел получает слот и что новый материал получает `dynamic_torch_count > 0`.

### Шаг 2 — привести к семантике оригинала

* Перенести расчёт вклада пула из `fragment()` в `vertex()`.
* Складывать динамический вклад до разделения diffuse/secondary; для этого хранить
  исходный base byte вершины в отдельном атрибуте (`CUSTOM1`) при сборке меша
  (`multiplayer_test.gd:1436-1440`).
* Проверить, что вклад факела умеет давать overflow-канал (0…64), как в оригинале
  (`0x4CC52C..0x4CC5C2`).

### Шаг 3 — аварийный fallback (опционально)

* Вернуть использование `_step_torch_terrain_lighting` / `_refresh_torch_terrain_lighting_bucket`
  только при `источников > 32`, с ограничением по кадрам; без синхронного flush.

---

## 8. Точки интеграции

| Файл | Функция / строки | Что меняется |
|---|---|---|
| `godot/shaders/native_terrain_pipeline.gdshader` | `:18-20` uniform-ы; `:25-31` vertex; `:51-72` fragment | Размер пула; перенос оценки в vertex; сложение до split |
| `godot/scripts/native_scene_profile.gd` | `:14` `MAX_DYNAMIC_TORCHES`; `:112-136` `terrain_material()`; `:139-159` `set_dynamic_torch_lights()` | Новый бюджет; uniform-ы при создании материала; CPU-отбор источников |
| `godot/scripts/multiplayer_test.gd` | `:3665-3671` `_automatic_torch_lights()`; `:3674-3684` `_terrain_baked_lights()`; `:3687-3691` `_queue_torch_terrain_lighting()`; `:3712-3717`, `:3727-3764` | Сбор пула; отключённый/аварийный bake-путь |
| `godot/scripts/native_terrain_illumination.gd` | `:19-41` `channels()`; `:44-50` `class_light_color()` | Единая формула/единицы для слоя 1 (чтобы не разошлись с оригиналом) |
| `godot/scripts/native_flame_emitter.gd` | `:5-16`, `:79-81` | **Не трогать**: пламя — не источник света |
| `godot/scripts/terrain_reference.gd` | `:789` `_add_template_light()` | Только если статические лампы переводятся в runtime-пул |

---

## 9. Проверки

Готовые команды (проверены мной на текущей машине, где отмечено ✔):

```powershell
# ✔ выполнено, exit 0
python -B tools\export_world_model_lighting.py --check     # {"ok": true, "spans": 12, "constants": 10}
python -B tools\export_native_shader_pipeline.py --check    # NATIVE_SHADER_PIPELINE_CHECK_OK

# существующие headless-проверки (не выполнялись в этом отчёте)
godot --headless --path godot --script res://tools\automatic_torch_runtime_self_test.gd
godot --headless --path godot --script res://tools\native_shader_pipeline_self_test.gd
godot --headless --path godot --script res://tools\terrain_refresh_self_test.gd
godot --path godot --script res://tools\native_shader_pipeline_self_test.gd -- --gpu
godot --path godot --script res://tools\runtime_performance_probe.gd -- --probe-frames 360
```

Наблюдения, которые должны выполняться после шага 1–2:

1. `automatic_torch_runtime_self_test`: `dynamic_torch_count == 1` и очередь пуста — **уже проверяется**
   (`automatic_torch_runtime_self_test.gd:98,100`); добавить проверку девятого факела и нового материала.
2. `torch_lighting_updates == 0` и `torch_lighting_vertices == 0` при активации факела —
   **уже проверяется** (`:117`); должно остаться верным и после шага 2.
3. Геометрия/коллизия вершин не меняются при появлении факела — **уже проверяется** (`:112`).
4. В логе `NATIVE_TERRAIN_REFRESH batches=… geometry_ms=…` (`multiplayer_test.gd:661`)
   `geometry_ms` не должен зависеть от числа источников света.
5. GPU-пиксель terraina в зоне нового факела должен измениться сразу, без пересборки меша
   (проверка `--gpu` в `native_shader_pipeline_self_test.gd`).
6. Отсутствие регрессии: `native_terrain_render_self_test.gd` (556 проверок),
   `automatic_torch_runtime_self_test.gd` (33), `world_model_light_self_test.gd` (31).

---

## 10. Ограничения и уровни уверенности

| Утверждение | Уверенность | Почему |
|---|---|---|
| В оригинальных шейдерах нет расчёта света и массивов источников | high | Прочитаны `Common.fxh`, `UL2CS.fx`; остальные `.fx` того же набора следуют той же схеме |
| Свет в оригинале считается на вершине в рантайме из пула ламп | high | Восстановленные цепочки EXE + верифицированные `--check` фикстуры |
| В оригинале нет отдельного шага «перезапечь свет» после раскопки | medium-high | Вывод по отсутствию lightmap; live-трассировка цикла раскопки не проводилась |
| Факел = `Misc_Light`, радиус 6, цвет `{0.9 0.9 0.8}` | high | `emitter.tcl:7` + `digging-and-cave-system.md:206-216` |
| Факелы №9+ не освещают terrain в порту | high | `MAX_DYNAMIC_TORCHES=8` + исключение автофакелов из баки |
| Новый вариант грунта не получает uniform-ов света | high | `terrain_material()` не выставляет uniform-ы; вызывается при `_build_geometry` |
| Расчёт динамики на фрагменте расходится с оригиналом | high | Шейдер `:55-67` против per-vertex семантики оригинала |
| «Очередь по чанкам» сегодня не в рантайме | high | Прямой код `multiplayer_test.gd:3687-3691` + self-test `:98` |

Не входит в задачу и не менялось: оптимизация walkmap, хомяки, APK/экспорт, игровой код.

---

## 11. Использованные источники

Оригинал (установка `C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris`):

* `data/Scripts/classes/items/emitter.tcl` — `Misc_Light:3-11`, `Misc_LightSrc_a..f:13-58`,
  `Kris/Urwald/Lava/Swf_LightSrc_*:132-583`.
* `data/Shaders/Common.fxh:145-200` — `ApplyTexOp`, `TextureStaging`.
* `data/Shaders/UL2CS.fx:21-43` — `VS`/`PS`.
* `data/3db/licht.3db` — модель факела (`fackel`).
* `data/sphere.dat` — 256 нормалей (256 × 12 байт).

Проект (вторичные документы, использованы как указатели, а не как доказательство):

* `docs/reverse-engineering/world-model-lighting-2026-11-18.md` — производитель цвета `0x4856E0`,
  цепочка нормалей `0x48A533..0x48A626`, fog/horizon.
* `docs/reverse-engineering/shader-pipeline-2026-11-18.md` — цепочка единиц лампы,
  split `0x4CC52C..0x4CC5C2`, gamma.
* `docs/reverse-engineering/model-lighting-feedback-2026-11-18.md` — «brightness[] = индексы нормалей».
* `docs/reverse-engineering/digging-and-cave-system.md:206-216` — параметры факела.
* `docs/reverse-engineering/runtime-performance-2026-11-18.md` — счётчики сцены и draw calls.

Код порта (проверено чтением):

* `godot/shaders/native_terrain_pipeline.gdshader`, `godot/scripts/native_scene_profile.gd`,
  `godot/scripts/multiplayer_test.gd`, `godot/scripts/native_terrain_illumination.gd`,
  `godot/scripts/native_flame_emitter.gd`, `godot/scripts/native_world_context.gd`,
  `godot/tools/automatic_torch_runtime_self_test.gd`, `godot/models/native_terrain_render.json`
  (константы: `depth_half=0.5`, `depth_offset=7.0`, `gain=0.1`, `min_dot=0.1`,
  `normal_base=3.6`, `normal_x=-2.546`, `normal_y_subtract=2.546`).

---

## 12. Отдельно: файл из постановки, которого нет

В задаче указан `godot/shaders/native_terrain.gdshader` — **такого файла в порту нет**.
Реальные шейдеры terrain: `godot/shaders/native_terrain_pipeline.gdshader` (используется при
`use_native_diffuse`, выбор — `native_scene_profile.gd:119`) и
`godot/shaders/native_terrain_detail.gdshader` (legacy-адаптер). Все ссылки в отчёте даны по
фактическим файлам.

```text
INTEGRATION_HANDOFF
recommended: Runtime-пул источников света в шейдере terrain с оценкой на вершине (uniform-массив 32 слота, CPU-отбор ближайших), база C+7+статика остаётся запечённой, а существующий per-chunk пересчёт — только аварийный fallback при числе источников > 32.
original_evidence: data/Scripts/classes/items/emitter.tcl:3-58 (class_light: offset/radius/color, напр. Misc_Light radius 6 color {0.9 0.9 0.8}); data/Shaders/Common.fxh:145-200 (TextureStaging берёт цвет вершины, света в шейдере нет); data/Shaders/UL2CS.fx:37-43 (PS = staging + specular + gamma); data/sphere.dat (256 нормалей); EXE-продюсеры: terrain diffuse 0x4CC040, split diffuse/secondary 0x4CC52C..0x4CC5C2, world color 0x4856E0, нормаль 0x48A533..0x48A626, пул ламп 0x591A20, цепочка единиц 0x614CBC/0x5C7CF9/0x5CC0D0/0x4C80FD — проверено: python -B tools/export_world_model_lighting.py --check и tools/export_native_shader_pipeline.py --check (exit 0).
godot_touchpoints: godot/shaders/native_terrain_pipeline.gdshader:18-20,25-31,51-72 (uniform-пул, vertex-оценка, сложение до split); godot/scripts/native_scene_profile.gd:14 (MAX_DYNAMIC_TORCHES), :112-136 (terrain_material — uniform-ы при создании), :139-159 (set_dynamic_torch_lights); godot/scripts/multiplayer_test.gd:3665-3671 (_automatic_torch_lights), :3674-3684 (_terrain_baked_lights), :3687-3691 (_queue_torch_terrain_lighting), :3712-3717 и :3727-3764 (fallback per-bucket); godot/scripts/native_terrain_illumination.gd:19-41,44-50 (общая формула и единицы).
safe_first_step: Поднять бюджет пула 8→32 в native_scene_profile.gd:14 и native_terrain_pipeline.gdshader:18-20, выставлять dynamic_torch_* сразу в terrain_material() (native_scene_profile.gd:112-136) и выбирать в set_dynamic_torch_lights() ближайшие к камере источники вместо первых N; добавить в automatic_torch_runtime_self_test.gd проверки «девятый факел получает слот» и «новый материал получает dynamic_torch_count>0». Правки только в godot/scripts/native_scene_profile.gd, godot/shaders/native_terrain_pipeline.gdshader, godot/tools/automatic_torch_runtime_self_test.gd.
validation: python -B tools/export_world_model_lighting.py --check и tools/export_native_shader_pipeline.py --check (ожидается ok/exit 0); godot --headless --path godot --script res://tools/automatic_torch_runtime_self_test.gd (ожидается dynamic_torch_count==1 для нового факела, очередь пуста, torch_lighting_updates==0, torch_lighting_vertices==0, geometry_preserved=true); godot --headless --path godot --script res://tools/native_shader_pipeline_self_test.gd и -- --gpu (GPU-пиксель в зоне факела меняется сразу); godot --headless --path godot --script res://tools/terrain_refresh_self_test.gd; godot --path godot --script res://tools/runtime_performance_probe.gd -- --probe-frames 360 (draw calls/primitives без роста, geometry_ms в NATIVE_TERRAIN_REFRESH не зависит от числа источников).
```
