## 5. Команды проверок и фактические результаты

Все прогоны — headless, Godot **4.7.2.stable**, движок
`C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe`.

### 5.1 Команды

```powershell
# Наборы тестов хомяка
python C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\scripts\run_hamster_suites.py

# Все наборы проекта (patched и baseline)
python ...\scripts\run_all_suites.py --project ...\Diggles\godot      --out ...\out\patched
python ...\scripts\run_all_suites.py --project ...\Diggles\baseline\godot --out ...\out\baseline

# Вердикт по логам (три разных формата маркеров успеха)
python ...\scripts\judge_suites.py --logdir ...\out\patched

# Сцена
python ...\scripts\run_scene_headless.py --project ...\Diggles\godot --out ...\out\scene --seconds 240

# Дифф
python ...\scripts\build_patch.py
```

Низкоуровневый запуск одного набора (эквивалент, которым пользуется раннер):

```powershell
& 'C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe' `
  --headless --path <project> --script res://tools/<suite>.gd
```

### 5.2 Наборы тестов хомяка — 3/3 зелёные

```
OK   native_hamster_ai_self_test                  69 assertions  exit=0
OK   native_hamster_actor_self_test               66 assertions  exit=0
OK   native_wild_hamster_self_test                57 assertions  exit=0
```

**Итого 192 проверки, 3/3 набора зелёные.** Что именно покрыто:

| Требование задачи | Где проверяется | Проверка |
|---|---|---|
| четыре хомяка | `models/multi_start_010_models.json` (ordinal 23, 24, 38, 39) + лог сцены | `WILD_HAMSTER Hamster_023/024/038/039` в логе |
| исходные клипы | `native_hamster_actor_self_test.gd:131-136` | 28 клипов в пакете, `stand_anim` 12 кадров, `maennchen` 17, `sterben` 21, `getroffen` 15; 27 алиасов, все указывают на экспортированный клип |
| два уровня пола | `native_wild_hamster_self_test.gd:199-217` | уровни 14.5 и 18.5 есть, пол под хомяком пола есть, пол под хомяком террасы есть, и наоборот — нет |
| отсутствие левитации | `native_wild_hamster_self_test.gd:171-197` + лог сцены | «the hamster does not walk into the void», «the walk does not start without ground»; в логе сцены Y хомяков не меняется: −54.5 / −58.5 |
| поворот до ходьбы | `native_wild_hamster_self_test.gd:116-138` | «a quarter turn shows the turn clip of the original», «the turn does not jump to the direction», «the hamster waits for the turn»; в логе сцены `drehen_rechts_90`/`drehen_links_90` идут **до** `laufen_start` |
| реакция на близкого гнома | `native_wild_hamster_self_test.gd:219-235`, `:90-95` | «the wild hamster runs away from the dwarf»; радиус датчика 2.0 (1.9 — срабатывает, 2.1 — нет) |
| поиск/исчезновение еды | `native_hamster_actor_self_test.gd:275-283` | «the hamster picks up the food», «the food object is removed»; в логе сцены есть клип `gefressen_werden` у `Hamster_023` на позиции еды (72.0, −58.5, 5.5) |

### 5.3 Регрессия: patched против baseline

Baseline — копия живого проекта **без** интеграции, снятая параллельно. Оба дерева прогнаны
одним и тем же раннером.

| | patched (живой + интеграция) | baseline (живой, без интеграции) |
|---|---|---|
| наборов | 48 | 45 |
| зелёных | 44 | 42 |
| проверок | 5 005 | 4 821 |
| падающих | `excavated_walk`, `native_battle_world`, `native_dig_queue`, `native_dwarf_dig` | `excavated_walk`, `native_dig_queue`, `native_dwarf_dig` |

Разница в проверках сходится точно: `4 821 + 192 (хомяк) − 8 (battle-world, см. ниже) = 5 005`.

**Три падения общие для обоих деревьев — то есть существующие в живом проекте и не связанные
с интеграцией:**

| Набор | Ошибка |
|---|---|
| `excavated_walk_self_test` | `EXCAVATED_WALK_SELF_TEST_FAILED new navigation floor lacks terrain collision` |
| `native_dig_queue_self_test` | `NATIVE_DIG_QUEUE_SELF_TEST_FAILED queue selected an extra or missing point` |
| `native_dwarf_dig_self_test` | `NATIVE_DWARF_DIG_SELF_TEST_FAILED rebuilt terrain has no physics hit` |

Очередь задач гномов после патча `native_tasklist.gd` — зелёная:

```
OK   native_actor_tasks_self_test                  76 checks  failures=0
OK   dwarf_task_runtime_self_test                   39 checks  failures=0
```

#### Четвёртое падение — дрейф живого проекта, а не интеграция

`native_battle_world_self_test` упал только в patched-дереве. Расследование:

1. `diff_trees.py` показал, что между деревьями различаются **три** файла, не относящиеся к
   интеграции: `project.godot`, `scripts/native_battle_world.gd`,
   `tools/native_battle_world_self_test.gd`.
2. Живой проект правился параллельно: в `native_battle_world.gd` сравнение
   `world_size != [112,88]` (JSON-парсер Godot отдаёт числа как float, поэтому массив
   `[112.0, 88.0]` не равен `[112, 88]`) заменено на покомпонентное
   `int(world_size[0]) != 112`. Тест поправлен так же.
3. После синхронизации этих трёх файлов из живого проекта в patched-дерево набор стал зелёным:
   ```
   NATIVE_BATTLE_WORLD_SELF_TEST checks=8 failures=0
   ```
4. Дрейф `project.godot` — одна строка рендера: `anti_aliasing/quality/msaa_3d=0`.

**Вывод:** падение `native_battle_world` вызвано правкой живого проекта, произошедшей между
моментом копирования (14:10) и снятием baseline (14:28), и к интеграции отношения не имеет.
Якоря интеграции при этом не пострадали: `scripts/multiplayer_test.gd` и
`scripts/native_tasklist.gd` в живом проекте с момента копирования **не менялись**
(их sha256 совпадает с baseline), то есть все номера строк в §4 остаются действительными.

### 5.4 Сцена headless

```
WILD_HAMSTER_NAV_READY level=58.50 size=53x25 blocked=475
WILD_HAMSTER Hamster_023 clip=hoppeln_start pos=(77.7272, -58.5, 12.26)
WILD_HAMSTER Hamster_024 clip=hoppeln_start pos=(56.0321, -54.5, 5.95995)
WILD_HAMSTER Hamster_038 clip=stand_anim   pos=(49.74837, -54.5, 5.95995)
WILD_HAMSTER Hamster_039 clip=hoppeln_start pos=(76.9994, -58.5, 5.95995)
```

Совпадает с прогнозом передаточной инструкции:

| Что | Ожидалось | Факт |
|---|---|---|
| уровень террасы | 58.50 | **58.50** |
| размер сетки террасы | 53×25 | **53×25** |
| число хомяков | 4 | **4** |
| позиции после сдвига | 77.727 / 56.032 / 49.748 / 76.999 | **совпадают** |
| ошибки сцены | нет | **нет** (в логе 927 строк, ни одного `SCRIPT ERROR`/`Parse Error`) |

Наблюдённое поведение (по логу, 927 строк):

* **Поворот до ходьбы** — `drehen_rechts_90`/`drehen_links_90` на месте, затем `laufen_start`
  и `laufen_loop` в ту же сторону:
  ```
  WILD_HAMSTER Hamster_023 clip=drehen_rechts_90 pos=(68.5, -58.5, 3.0)
  WILD_HAMSTER Hamster_023 clip=laufen_start      pos=(68.5, -58.5, 3.0)
  WILD_HAMSTER Hamster_023 clip=laufen_loop       pos=(68.86465, -58.5, 3.364652)
  ```
* **Без левитации** — Y хомяков не меняется за весь прогон: −54.5 и −58.5.
* **Два хомяка идут в разные стороны** — `Hamster_023` уходит к X≈68, `Hamster_024` к X≈53,
  `Hamster_039` к X≈70; `Hamster_038` остаётся на месте (49.74837) и чистит шерсть.
* **Еда** — `Hamster_023` доходит до еды и получает клип `gefressen_werden`:
  ```
  WILD_HAMSTER Hamster_023 clip=gefressen_werden pos=(72.0, -58.5, 5.5)
  ```
  (позиция еды `Grillpilz` после сдвига — 71.959, 58.5, 5.42).
* **Оригинальные клипы класса** — `stand_anim`, `maennchen`, `putzen_start/loop/end`,
  `schlafen_start/loop/end`, `hoppeln_start/loop/end`, `laufen_start/loop/end`,
  `drehen_links_90`, `drehen_rechts_90`, `gefressen_werden`.

Отдельно: в наборах, которые запускают сцену с `extended_world = false`
(`native_dig_queue_self_test.gd:16`, `native_scene_profile_self_test.gd`), уровни
`14.5/18.5` и несдвинутые позиции — там мир не сдвинут, и интеграция даёт корректные
значения именно для этого мира. Оба случая проверены.

### 5.5 Round-trip проверка патча на текущем живом проекте

Оба патча применены к **свежей копии живого проекта** (актуальной на момент проверки):

```
hamster-integration.patch: 20 file hunks applied without conflict
hamster-integration-data.patch: 1 file hunks applied without conflict
total files touched by the patches: 21
```

Контекст ни одного hunka не конфликтует: якоря интеграции в живом проекте не тронуты
параллельной работой. Сравнение интеграционных областей патченого живого проекта с
проверенным рабочим деревом:

| Область | trial (живой + патч) | рабочее дерево | Вердикт |
|---|---|---|---|
| A1 константы | `01ab5f946e6d3641` | `01ab5f946e6d3641` | **совпадает** |
| A2 загрузка рельефа | `39b769f10edab60f` | `39b769f10edab60f` | **совпадает** |
| A3 спавн хомяка | `e9157c4662134686` | `e9157c4662134686` | **совпадает** |
| A4 сбор еды | `5bab610dd2e56b97` | `5bab610dd2e56b97` | **совпадает** |
| A5 блок функций хоста | `65345f55de9fe1cc` | `65345f55de9fe1cc` | **совпадает** |

**Важно про номер строк в §4.** За время работы живой `scripts/multiplayer_test.gd` вырос
с 3 905 до **3 922 строк** (правки по факельному освещению: `_terrain_baked_lights`,
`_automatic_torch_lights`). Номера строк в §4 даны для версии от 14:10 и к моменту
проверки уже сдвинуты на +17. **Ориентироваться надо на текст якорей** — именно поэтому
патч сделан текстовым, и именно поэтому он применился без конфликта. Правки живого
проекта затронули `_build_geometry` и конец файла, то есть ни один из пяти якорей.

### 5.6 Контрольный список приёмки
| Пункт | Статус |
|---|---|
| в `godot/scripts` нет файлов модулей хомяка, в `godot/models` — файлов данных хомяка | ✅ было до интеграции, проверено до копирования |
| `native_tasklist.gd` живого проекта сохраняет живые вызовы (`count()`, `remove(0)`) | ✅ файл не перезаписан, только дополнен; `native_actor_tasks_self_test` (76) и `dwarf_task_runtime_self_test` (39) зелёные |
| в `_build_static_objects` есть ветка `Hamster` после сдвига `template_shift` | ✅ якорь A3, подтверждено логом сцены (позиции сдвинуты) |
| в логе есть `WILD_HAMSTER_NAV_READY level=58.50` | ✅ |
| хомяк на террасе не падает в пустоту и не проходит сквозь край | ✅ Y стабилен −58.5; `hoppeln`/`laufen` идут в пределах своей сетки |
| при резкой смене цели хомяк сначала доворочивает (`drehen_*_90`), потом идёт | ✅ подтверждено логом |
| два хомяка, идущие в разные стороны, не поворачиваются одновременно | ✅ в логе повороты разнесены по времени |
| набор тестов хомяка зелёный, число проверок совпадает с ожидаемым | ✅ 192 проверки (69 + 66 + 57); инструкция ожидала 65 в акторе — фактически 66, файл теста в снимке вырос |

### 5.7 Что проверено и что осталось непроверенным

**Проверено фактически:** сборка и парсинг всех перенесённых скриптов, три набора тестов
хомяка, полный прогон 48 наборов проекта, сравнение с baseline, реальный запуск сцены в
headless с разбором лога по всем требуемым поведениям, round-trip применение обоих
патчей к свежей копии живого проекта с побайтовым сравнением интеграционных областей.

**Не проверено (нужен рендер, а не headless):** визуальное качество модели хомяка
(текстура, глаза, ориентация UV) и вид сцены с четырьмя хомяками в окне. В headless
геометрия и клипы проверяются на уровне данных (28 клипов, 17 кадров в клипе поворота,
сетка, UV-конвенция — по §9 передаточной инструкции), но не на уровне картинки.
Отдельно: в HTML-стенде `work/hamster_web/hamster_life.html` текстура проверена вручную
(это было сделано в снимке MCode, в рамки этой задачи стенд не пересобирался).

---
