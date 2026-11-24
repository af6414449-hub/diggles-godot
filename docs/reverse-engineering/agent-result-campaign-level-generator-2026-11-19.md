# Генератор уровня кампании — первая глава Urwald

**Дата:** 2026-11-19
**Проект:** `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles` (основной)
**Источник фактов:** установленная игра, только чтение:
`C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data`

## 1. Зачем эта работа

В проекте не было режима кампании вообще. Единственная собранная карта — режим
**сражений**: `Templates/multi_urw_start_010_a_0.tcl` (128×128, эталон
`multi_start_010`), см. `godot/models/multi_source_manifest.json`. В её
манифесте ноль упоминаний кампании, сюжета или триггеров. Кампания и сражения
в оригинале — разные режимы с разными картами:

| Режим оригинала | Карта | Где в проекте |
|---|---|---|
| Туториал | `single_Tutorial.tcl` | нет |
| Кампания | `Campaign.tcl` → `first_level` | **создано этой работой** |
| Сражения | `multi_cw_*` / `multi_start_010` | `scenes/multiplayer_test.tscn` |

Карты кампании в оригинале **не существует как файла**: глава собирается
процедурой из шаблонов. Теперь в проекте есть её собственный рендер, своя
сцена и своя точка входа. Сцена сражений не тронута.

## 2. Первоисточник

`data/Scripts/gameplay/Campaign.tcl` (7120 байт):

| Строка | Что |
|---|---|
| 2 | `map create 512 640` — размер карты главы |
| 10 | `set_view 246.7 28.8 1.478 -0.29 0.05` — стартовая камера |
| 12 | `set temppos {208 0}; call templates/tcl/urw_unq_start.tcl` — старт области |
| 13 | `set temppos {30 23}; call templates/tcl/urw_unq_hoehlenmalerei.tcl` |
| 14 | `//MapTemplateSet 40 30` — **закомментировано**, геометрии у этого шаблона нет |
| 15 | `map_setlayer2 30 23 data/templates/urw_unq_hoehlenmalerei.l2m` — только слой материала |
| 22–191 | `proc first_level {startx starty}` — процедурная сборка главы |
| 195 | `first_level 208 0` — единственный вызов |
| 198–203 | удаление всех объектов класса `Wuker` |
| 206–209 | `FogRemover` в (239,14,15), `fog_remove 0 46 22` |

Таблицы `first_level` перенесены дословно (cavelist 5, comblist 8, tunnlist 3,
conlist 6, vodolist 22, voconlist1 6, voconlist2 3) — см.
`godot/scripts/native_campaign_level.gd` с указанием строк оригинала.

## 3. RNG: `irandom`

`irandom` — **не** Tcl-процедура, а нативная команда движка: во всех
`Scripts/**/*.tcl` определения `proc irandom` нет, есть только вызовы.
Алгоритм восстановлен из EXE и уже лежит в проекте:
`tools/diggles_rng.py` (перенесён из рабочего дерева Codex).

- `0x61afc8` регистрирует `irandom` → `0x62f780` → `0x49c670`: маска 31 бита,
  затем остаток от деления на аргумент;
- `0x4454d0` инициализирует 624-словное состояние из 32-битного seed;
- генератор — MT19937 с нестандартным посевом.

**Это факт, а не адаптер.** Адаптером остаётся только одно: движок засевает
`irandom` значением wall-clock, поэтому seed записанной главы неизвестен.
Заданный seed даёт точную последовательность размещений для этого seed.

## 4. Что сделано

### 4.1 Генератор (data-only, без Node3D)

`godot/scripts/native_campaign_level.gd` — порт `first_level` на GDScript:
восстановленный `irandom` (вложенный класс `DigglesRandom`), таблицы
оригинала, `generate(seed, start_x, start_y)` → список размещений шаблонов с
ролями (`chapter_start`, `layer_only`, `cave`, `cave_end`, `tunnel`, `voodoo`).

### 4.2 Экспортёр главы

`tools/export_campaign_chapter.py` — собирает главу в одну сетку 512×640:

- читает плоские шаблоны из `Templates/` (именно их зовёт `first_level` через
  `data/templates/$template.tcl`; в `Templates/tcl/` лежат исходники, включая
  разбитую на 12 частей `urw_unq_start`);
- читает PMP (геометрия ячеек из BlockDB2) и L2M (слой материала) каждого
  шаблона, накладывает их по смещению размещения;
- парсит объявления `[new <Класс> ...]` вместе с флагами `set_owner`,
  `set_physic`, `set_autolight`, `set_boxed`;
- собирает атлас детальных текстур главы.

Результат: `godot/models/native_campaign_chapter.json` (3447 ячеек, 651 блок,
19129 вершин, 11918 треугольников, 14 размещений, 354 объекта).

### 4.3 Сцена кампании

- `godot/scripts/native_campaign_profile.gd` — правила показа для главы.
  Общий `native_scene_profile.gd` привязан к одному эталону (сверка sha256
  PMP, размер слоя = размер ландшафта), поэтому у главы свой модуль. Общие
  правила рендера (паттерны грунта, константы шейдера, освещение) переиспользуются.
- `godot/scripts/native_campaign_first_level.gd` — сборка сцены: геометрия
  ландшафта, коллизия, объекты главы, камера по стартовому `set_view`, HUD.
- `godot/scenes/campaign_first_level.tscn` — **отдельная сцена**; сцена
  сражений `multiplayer_test.tscn` не изменена и не удалена.

Запуск (headless, Godot 4.7.2):

```text
CAMPAIGN_FIRST_LEVEL_READY seed=0 cells=3447 templates=14 placements=14 objects=277 dwarfs=5 deleted_wuker=6 surfaces=209 triangles=56529
CAMPAIGN_CHAPTER_SOURCE Campaign.tcl:22-191 first_level seed=0 map=512x640 view={ "x": 246.7, "y": 28.8, "zoom": 1.478, "rx": -0.29, "ry": 0.05 }
```

Визуальная проверка (снимок сцены, `out/campaign-capture2.png`): поверхность
Urwald со стартовым шаблоном, пятью гномами, грибами и бочками; ниже — левая
пещера `urw_hol_027_a` (228,36), цепочка переходов `urw_gng_013_c`,
`urw_gng_003_b`, `urw_gng_002_b`, правая пещера `urw_hol_001_a` (268,36) и
комнаты вудо. Форма совпадает с `first_level` для seed 0.

Камера сцены — адаптер хоста: нативный вид главы горизонтальный (2.5D), но у
карты 512×640 массивное тело породы, и при горизонтальной камере в кадр
попадает в основном камень. Адаптер смотрит сверху (pitch 0.62, дистанция 78),
нативные значения `set_view` остаются в подписи сцены.

### 4.4 Регрессия

Полный набор self-test-ов проекта (`tools/run_suite.ps1`, 49 тестов, включая
четыре кампанийных — генератор Codex, главу MCode, сверку портов и движок
сюжета) после всех изменений:

```text
=== final2: 49 tests, 0 failing ===
SUITE_DONE
```

Ни один существующий тест не сломан.

### 4.5 Точка входа

`run/main_scene` переведён на `res://scenes/campaign_first_level.tscn`. Теперь
проект открывается с первой карты кампании, а не с карты сражений. Сцена
сражений остаётся в `scenes/` и доступна как отдельная сцена.

## 5. Проверка

`godot/tools/native_campaign_chapter_self_test.gd`:

```text
CAMPAIGN_CHAPTER_SELF_TEST_OK checks=64
```

Ключевая проверка — **два независимых порта** `first_level` (GDScript в
`scripts/native_campaign_level.gd` и Python в `tools/export_campaign_chapter.py`)
должны совпасть по каждому шаблону и каждой координате. Тест сравнивает их
пошагово, а не только по количеству.

Также проверяются: размер карты 512×640; детерминированность (два прогона
одного seed); различие разных seed'ов; наличие гномов игрока в пределах
стартового шаблона; наличие и удаление класса `Wuker`; попадание всех
размещений в границы карты; непустота ландшафта, слоя материала и мешей.

### Найденная и исправленная ошибка

Самопроверка поймала расхождение портов: Python-экспортёр не удалял первый
элемент соединения. В оригинале `Campaign.tcl:114` — `incr std_x [lrem conn 0]`,
то есть первый элемент списка соединения расходуется как горизонтальный сдвиг,
а цикл `foreach itemp $conn` идёт по оставшимся трём. Из-за этого экспортёр
ставил лишний переход и уходил за границы `tunnlist` на seed'ах с сдвигом 4
(в исходной таблице `conlist` есть `{4 2 0 1}`, `{4 2 1 0}`, `{4 1 2 0}`).
GDScript-порт был прав, ошибка исправлена в экспортёре.

## 6. Факт / адаптер / неизвестно

| Свойство | Статус | Основание |
|---|---|---|
| Таблицы `first_level` | **факт** | `Campaign.tcl:25-100` |
| Порядок и правила выбора | **факт** | `Campaign.tcl:101-174` |
| Алгоритм `irandom` | **факт** | EXE `0x49c670`, `0x4454d0` |
| Seed записанной главы | **неизвестно** | движок сеет от wall-clock |
| Геометрия шаблонов | **факт** | PMP + BlockDB2.BDB |
| Слой материала | **факт** | L2M + `0x4C4C50` |
| Объекты и их флаги | **факт** | `[new ...]` + `set_*` в шаблонах |
| Разброс варианта грунта | **адаптер** | в оригинале вариант зависит от живого RNG; здесь детерминированная раскладка по координатам карты |
| Материалы семейства B | **адаптер** | тот же адаптер, что и в эталонной сцене |
| Камера (дистанция, угол) | **адаптер** | нативный вид горизонтальный (2.5D); адаптер смотрит сверху, нативные значения `set_view` сохранены в подписи |
| Туман `FogRemover` | **не реализовано** | прямоугольник `fog_remove 0 46 22` зафиксирован в данных, визуальный туман не воспроизведён |
| Группы `sm_def_temp_group` | **не включены** | это статические группы сюжетных объектов мира Urwald (`urw_kif_4`, `urw_der_einsiedler`, `urw_trollburg_ring` из `CampaignInit.tcl`), то есть более поздние части мира, а не первая глава |
| Сценарий главы | **не включено** | `single_Campaign.tcl` и `single_Seq_FirstContact.tcl` — следующий этап; движок последовательностей уже перенесён (`native_story_sequencer.gd`) |

## 7. Параллельная реализация и сверка

Пока эта работа шла, **второй агент (Codex) добавил в тот же проект свою
реализацию кампании** — по заданию «Рабочее дерево MiniMax (единственное
место записи)». Его файлы (20:57–21:14):

```text
scripts/diggles_irandom.gd
scripts/diggles_campaign_templates.gd
scripts/diggles_campaign_generator.gd
scripts/diggles_campaign_composer.gd
scripts/diggles_campaign_scene.gd
models/campaign_urwald_first_level.json
models/campaign_urwald_first_level_golden.json
tools/campaign_level_generator_self_test.gd
```

Его генератор тоже порт `first_level`, и он корректен: `lrem conn 0`
выполнен как `conn.pop_front()`, ветвление `voconlist1/voconlist2` по
`conn_index` выполнено как в оригинале. Его self-test проходит:
`CAMPAIGN_LEVEL_GENERATOR_SELF_TEST_OK assertions=450 templates=88 seeds=3`.

Его сцена (`diggles_campaign_scene.gd`) **не подключена**: `.tscn` на неё нет,
`run/main_scene` он не менял.

Обе реализации оставлены. Чтобы это не осталось двумя непроверенными
правдоподобными версиями, добавлена постоянная сверка
`godot/tools/native_campaign_cross_check.gd`: она сравнивает порт A
(`native_campaign_level.gd`) и порт B (`diggles_campaign_generator.gd`) по
каждому шаблону и каждой координате на нескольких seed'ах, и порт A с
экспортированной главой.

```text
CAMPAIGN_CROSS_CHECK_OK checks=121 seeds=4
```

Разница в 2 размещения между портами — это пролог главы (`urw_unq_start` и
слой `urw_unq_hoehlenmalerei`, `Campaign.tcl:12-15`): порт A включает его в
список, порт B покрывает только саму `first_level`. Расхождений в самой
процедуре нет.

Также его версия `scripts/multiplayer_test.gd` синхронизирована с живым
деревом (файл совпадает с копией в рабочем дереве Codex, отличий 0) —
сцена сражений по содержанию не менялась.

## 8. Следующий шаг

Слой сценария кампании: `GameScripts/single_Campaign.tcl` +
`single_Seq_FirstContact.tcl` через уже перенесённый
`godot/scripts/native_story_sequencer.gd`, с привязкой к триггерам
`CampaignInit.tcl` (`Trigger_FirstContact`, `Trigger_Voodoo_Lager`,
`Trigger_urw_unq_troll_005_Betreten`). Первая вертикаль — `FirstContact` от
начала до конца, без изменения сцены сражений.

## 9. Файлы

Новые:

```text
godot/scripts/native_campaign_level.gd
godot/scripts/native_campaign_profile.gd
godot/scripts/native_campaign_first_level.gd
godot/scenes/campaign_first_level.tscn
godot/tools/native_campaign_chapter_self_test.gd
godot/tools/native_campaign_cross_check.gd
godot/models/native_campaign_chapter.json
godot/models/native_campaign_models.json
godot/models/native_campaign_model_manifest.json
godot/assets/terrain_detail/native_campaign_detail_atlas.png
tools/export_campaign_chapter.py
tools/diggles_rng.py
tools/inspect_bdb.py
tools/extract_template_objects.py
tools/export_demo_start_models.py
tools/inspect_3db.py
```

Изменены:

```text
godot/project.godot          run/main_scene -> campaign_first_level.tscn
tools/run_suite.ps1          добавлены два кампанийных теста
```

Не тронуты: `scenes/multiplayer_test.tscn`, `scripts/native_scene_profile.gd`,
шейдеры, walkmap, факелы, APK. `scripts/multiplayer_test.gd` синхронизирован
с живым деревом другим агентом, по содержанию совпадает с ним байт в байт.

## 10. Дублирование, которое осталось

В проекте теперь две реализации генератора (`native_campaign_*` и
`diggles_campaign_*`). Они согласованы между собой, но дублируют друг друга.
Свести к одной — решение владельца проекта; данные (`campaign_urwald_first_level.json`,
127 моделей, атлас) при сведении нужно перегенерировать, а не копировать.

## 11. Связанный отчёт

Полный отчёт исполнителя по разбору `irandom`, таблицам шаблонов Urwald,
unified diff и прогонам (522 строки) лежит рядом:
`docs/reverse-engineering/agent-result-campaign-level-generator-execution-2026-11-19.md`
(в дереве Codex он называется `agent-result-campaign-level-generator-2026-11-19.md`).

Состояние на 2026-11-19: обе реализации в основном дереве зелёные —
`campaign_level_generator_self_test` (450 проверок) и
`native_campaign_chapter_self_test` (64 проверки), полный набор 53/53.

INTEGRATION_HANDOFF: генератор уровня первой главы Urwald реализован в основном дереве Minimax двумя согласованными реализациями (native_campaign_* и diggles_campaign_*), обе зелёные; полный отчёт-исследование с разбором irandom лежит в agent-result-campaign-level-generator-execution-2026-11-19.md; открытым остаётся сведение двух реализаций в одну (нужно перегенерировать данные, а не копировать) и выгрузка геометрии raupeNN для ИИ червя.
