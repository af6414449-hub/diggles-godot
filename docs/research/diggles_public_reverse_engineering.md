# Diggles / Wiggles (2001–2002): публичное техническое исследование

**Дата:** 19 ноября 2026 г.  
**Цель:** найти пригодные для независимой реализации игры в Godot инструменты, спецификации форматов и источники поведения оригинала.

## Главный результат

Повторять reverse engineering с нуля не требуется. Найдены два публичных проекта 2026 года с лицензией MIT: **Diggles-Unity** (C#, анализ EXE, игровая логика) и **Wiggles Viewer** (C++, парсеры форматов, экспорт GLB, экспериментальное восстановление поведения). Вместе они покрывают модели, покадровые анимации, карты, текстуры, сохранения, Tcl, инвентарь, движение, освещение, туман, жидкости и часть игровой логики.

| Приоритет | Источник | Основная ценность |
|---|---|---|
| 1 | [Wiggles Viewer](https://github.com/mztulip/wiggles_viewer) | Импорт ресурсов, .glb с анимацией, спецификации бинарных форматов |
| 2 | [Diggles-Unity](https://github.com/Zimennik/Diggles-Unity) | Адреса функций EXE, механики, Tcl API, UI, тесты |
| 3 | [Game Scripting with Tcl, 2001](https://www.eurotcl.eu/presentations/EuroTcl2001-AllPresentations.pdf) | Оригинальная архитектура от руководителя разработки SEK-Ost |
| 4 | [Wiggles Tcl Commands](https://wiggles.ruka.at/tipstricks/wiggles_tcl.html) | Справочник встроенных команд движка |
| 5 | [DigglesMods](https://github.com/DigglesMods) | Tcl-патчи и примеры реальных игровых сценариев |
| 6 | [Diggles SDK / barnacle](https://github.com/ktksgit/barnacle) | ABI, адреса функций, инструменты исследования работающего EXE |

## Метод и шкала надёжности

Использовались только публичные веб-страницы и репозитории. Частный проект пользователя и его данные не открывались. Ключевые GitHub-репозитории получены через публичный git; проверены деревья файлов, конкретные функции, документация и LICENSE. PDF доклада и HTML справочника Tcl прочитаны непосредственно. Для некоторых форумных веток использованы индексированные сообщения авторов (прямое открытие поисковым инструментом возвращало 403).

- **A — высокая:** непосредственно проверенный код, документация автора оригинала, установленная лицензия, либо выполненный тест. Это не означает независимой проверки всех заявлений автора репозитория.
- **B — средняя/высокая:** конкретный RE-вывод автора с адресом, тестом или описанием эксперимента, но не перепроверенный мною на оригинальном EXE.
- **C — ограниченная:** форумное заявление, README без подтверждающего теста, не прочитанный архив, открытый вопрос.

В этом исследовании оригинальный EXE не декомпилировался и не запускался. Полный игровой набор ресурсов не использовался. Публичный образец модели проверен отдельно.

---

# Готово к применению

## 1. Wiggles Viewer / libwiggles — основная база импортёров

**Источник:** [репозиторий](https://github.com/mztulip/wiggles_viewer), [зафиксированная версия 663995e](https://github.com/mztulip/wiggles_viewer/tree/663995e926c8e08429bdb4f7dcda456cc573864a) (26.10.2026), [LICENSE](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/LICENSE), [индекс документации](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/docs/README.md).

**Лицензия:** MIT, copyright 2026 Mateusz. Ассеты оригинала требуются из собственной копии игры. **Надёжность A** для существования кода; **B** для игровых закономерностей в документации.

Инструменты:

- `wigview` — просмотр моделей, кадра/анимации, текстур и альфы, карт, сохранений, звуков, эффектов, структуры файлов.
- `export_gltf` — экспорт выбранных объектов/анимаций в GLB.
- `test3db` — проверка форматов и индексов на оригинальных данных.
- `owscript` — выполнение скриптов класса без графики с журналом отсутствующих команд.
- `libwiggles` — библиотека C++17; Tcl, парсеры и симуляция отделены от графического слоя Vulkan/OpenGL.

### 1.1 Модели и анимации

| Данные | Первичный источник (реализация и спецификация) | Применение в Godot |
|---|---|---|
| .3db, заголовок, материалы, меши, объекты, анимации | [docs/formaty/3db.md](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/docs/formaty/3db.md); `src/lib/model3db.cpp`, `model3db.h`, `binreader.h` | Импорт моделей и кадров, проверка границ секций |
| GLB | [src/lib/gltf_export.h](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/src/lib/gltf_export.h), [gltf_export.cpp](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/src/lib/gltf_export.cpp), `src/tools/export_gltf.cpp` | Готовый путь в Godot через glTF 2.0, затем оптимизация |
| Нормали | [docs/formaty/sphere_dat.md](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/docs/formaty/sphere_dat.md), `src/lib/sphere.cpp` | Восстановление нормалей по индексам |
| Материалы, тени, collision map, links | `docs/formaty/3db.md` §§3.3–3.7, 9; `src/lib/render/model_renderer.cpp`, `src/shaders/model.frag` | Шейдеры прозрачности/свечения, точки крепления, маски и тени |

**Подтверждённое в коде:** экспортёр создаёт отдельный узел для анимации, morph targets относительно первого кадра и каналы glTF с анимируемыми весами (`gltf_export.cpp`, около строк 260–384). В `gltf_export.h` значение fps по умолчанию — 10, масштаб — 0.01, интерполяция LINEAR. Это настройки данного экспортёра, а не доказательство универсальной скорости всех анимаций оригинала.

**По спецификации автора:** строковый заголовок `3DDB 1.0`, поле имя базы, материалы, массив мешей, таблица объектов → индексы анимаций, анимации → индексы мешей. Перемещения и повороты за кадр извлекаются из записей анимаций. Нормали — байтовые индексы в `SPHERE.DAT` (256 векторов float32, размер 3072 байта). Поля, обозначенные в старых парсерах как brightness, автор исследует как индексы нормалей. Формат содержит квантованные координаты, bbox, 32 точки крепления, маски и 32×32 тени. Не все интерпретации одинаково доказаны: смотреть условные обозначения источника.

**Особенно важно:** в отличие от старого Python-конвертера, этот экспортёр действительно записывает `animations` в glTF. Поле `GltfExportStats::incompatibleFrames` указывает, что топология отдельных кадров может быть несовместима с morph targets. Нужен fallback и контроль отсутствующих кадров.

Команды из README (пример для собственной установленной копии):

```bash
build/release/export_gltf "/path/to/Wiggles" MANN mann gehen_loop -o walk.glb
build/release/export_gltf "/path/to/Wiggles" BABY
build/release/test3db "/path/to/Wiggles"
build/release/wigview --model MANN --anim gehen_loop
```

Команды и бинарники проекта в этом исследовании не запускались. Godot-импорт предлагается проверить на одном статическом объекте и нескольких анимациях до массовой конвертации.

### 1.2 Текстуры, карты, сохранения

| Формат/данные | Спецификация и код | Что известно по исследованию авторов |
|---|---|---|
| TGA | [tekstury.md](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/docs/formaty/tekstury.md), `src/lib/tga.cpp`, `texture_find.cpp` | В обследованном наборе Data/Texture — 32-bit BGRA TGA type 2; ориентация определяется битом 5 заголовка |
| TEXMAPS.BIN | `docs/formaty/tekstury.md`, секция TEXMAPS.BIN | Описана сигнатура TexC, таблица имён, ARGB4444 и mipmaps; это конкретный найденный контейнер текстур, не универсальный архив игры |
| Texlevels | `docs/formaty/tekstury.md`, `Data/Texture/texlevels.txt` в игре | Таблица разрешений и порядок поиска текстуры |
| BDB | [blockdb.md](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/docs/formaty/blockdb.md), `src/lib/blockdb.cpp` | Три BlockDB, 118688 вариантов геометрии блока; секции индексов, палитры, 89-байтовых записей блоков |
| PMP | [szablony.md](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/docs/formaty/szablony.md), `src/lib/map_template.cpp` | Ширина/высота, типы ячеек, индексы блоков, RLE-плоскость навигации, базовый свет |
| L2M | тот же файл, §2 | Сигнатура M2L с нулём, размеры, u16-значения деталей; назначение части младших битов ещё неизвестно |
| TCL шаблон | тот же файл, §3; `src/lib/level_script.cpp` | `MapTemplateSet`, `map_template`, `map_setlayer2`, размещение объектов по координатам |
| SAV | [sav.md](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/docs/formaty/sav.md), `src/lib/save_game.cpp` | Чтение сохранений и построение мира из их данных |
| Локализация | `docs/formaty/teksty.md`, `src/lib/messages.cpp`, `text.cpp` | MESSAGES.TXT, QUOTES.TXT, LOCALE.TXT; можно строить каталог строк по ID |

**Для Godot:** сначала отдельный офлайн-импортёр из C++/Python/C#, затем импорт готовых ресурсов; либо GDExtension для чтения исходных данных во время запуска. Геометрию мира собирать из BDB+PMP, а не рисовать произвольными кубами. L2M — отдельный слой деталей. Проверять систему координат, масштаб, winding, UV, фактические коллизии.

### 1.3 Механики и движок

| Подсистема | Спецификация | Файл реализации |
|---|---|---|
| Tcl, объекты, события, таймеры | [docs/silnik/11_obiekty_tcl_i_petla.md](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/docs/silnik/11_obiekty_tcl_i_petla.md) | `src/lib/script/engine.cpp`, `cmd_object.cpp` |
| Инвентарь | тот же документ; [cmd_inventory.cpp](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/src/lib/script/cmd_inventory.cpp) | `inv_add`, `inv_rem`, `inv_getsize`, `is_wearing_pannier` |
| Камера | `docs/silnik/06_kamera.md` | `src/lib/map_scene.cpp` |
| Свет | `docs/silnik/07_oswietlenie.md` | `src/lib/render/game_lighting.cpp`, `src/shaders/game_lighting.glsl` |
| Туман | `docs/silnik/10_nieodkryty_teren.md` | `src/lib/map_scene.cpp`, `terrain_renderer.cpp` в render/ |
| Частицы | `docs/silnik/12_czasteczki.md` | `src/lib/particles.cpp`, `render/particle_renderer.cpp` |
| Жидкости | `docs/silnik/13_plyny.md` | `src/lib/fluid_sim.cpp`, `render/fluid_renderer.cpp` |
| Навигация | `docs/silnik/17_ruch.md` | `src/lib/nav.cpp`, `nav_world.cpp`, `walk_plan.cpp` |
| Копание | `docs/silnik/19_kopanie.md` | `src/lib/dig_terrain.cpp` |
| Производство | `docs/silnik/20_planista.md` | `src/lib/prod_planner.cpp`, `script/cmd_prod.cpp` |
| Звуки | `docs/silnik/15_dzwiek.md` | `src/lib/sound.cpp`, `sound_refs.cpp` |

Автор явно разделяет подтверждённые сведения, гипотезы, неизвестное и намеренные изменения оригинала. См. [дневник экспериментов](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/docs/BAZA_WIEDZY.md), [перечень неизвестного](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/docs/silnik/niewiadome.md), [статус Tcl-команд](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/docs/tcl_komendy_stan.md). Авторы объясняют, что исследуют данные и наблюдают оригинал под Wine, а не самостоятельно дизассемблируют EXE. Часть выводов заимствована из Diggles-Unity, поэтому совпадение этих двух источников не всегда независимое подтверждение.

## 2. Diggles-Unity — наиболее ценная документация по EXE и логике

**Источник:** [репозиторий](https://github.com/Zimennik/Diggles-Unity), [версия 9835230](https://github.com/Zimennik/Diggles-Unity/tree/983523017b43e9e5385e620e9fbfed979c65030c) от 05.09.2026, [Docs/README.md](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Docs/README.md), [LICENSE](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/LICENSE).

**Лицензия:** MIT (код и документация). README отдельно оговаривает права на ресурсы игры, исключение для использованных UI-иконок и шрифта, а также сторонние компоненты. Это не лицензия на распространение оригинальных моделей, звуков или скриптов.

**Надёжность:** A для наличия кода, документации, тестового каркаса; B для выводов из Ghidra и оригинальных скриптов, которые я не мог сам повторить. Проект описывает себя как играбельный, но незавершённый порт Unity 6 на оригинальных данных Steam/GOG. Не следует выдавать все заявленные механизмы за полностью работающие.

### 2.1 Инвентарь, маленькая и большая корзины/рюкзаки

**Опорные файлы:**

- [Docs/BOTTOM_MENU_RE.md](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Docs/BOTTOM_MENU_RE.md), §4 Inventory window (ViWinInventory).
- [Assets/Diggles/Runtime/Tcl/Engine/DigglesTclEngine.cs](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Assets/Diggles/Runtime/Tcl/Engine/DigglesTclEngine.cs), строки 1168–1374, 11982–12034.
- [InventoryPanelController.cs](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Assets/Diggles/Runtime/UI/InventoryPanelController.cs) и `InventoryPanelModel.cs`, `InventoryPanelView.cs`, `InventorySlotView.cs` в том же каталоге.
- [Docs/ITEM_PLACEMENT_RE.md](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Docs/ITEM_PLACEMENT_RE.md).

| Утверждение | Доказательство/привязка | Надёжность |
|---|---|---|
| Базовый инвентарь взрослого гнома — 6 мест | InvGetSize, FUN_005cde10; BOTTOM_MENU_RE §4; DigglesTclEngine.cs:11982 | B |
| Holzkiepe прибавляет 4 места; Grosse_Holzkiepe — 8; Schubkarren/Hamsterkarren — 6 | DigglesTclEngine.cs:11988–12001; таблица FUN_005c7410:49–60 | B |
| Контейнер сам занимает слот | DigglesTclEngine.cs:12001 и Wiggles Viewer, cmd_inventory.cpp:4–9 | B |
| Сетка основного инвентаря и дополнительная сетка контейнера разделены | InventoryPanelModel.cs:24–30. Сверить внешний вид с оригиналом | A для модели порта, B для оригинала |
| При подборе предмет становится невидимым, исключается из пространственного поиска, позиция обнуляется | InvAdd FUN_0069bd30:132,145–147; DigglesTclEngine.cs:1204–1222 | B |
| При извлечении default-позиция — место владельца, а не прежнего расположения предмета | InvRem FUN_0069c0f0; DigglesTclEngine.cs:1304 | B |
| Размещение свободного предмета ищет get_place/вектор позиции | GetPlace FUN_00656560 → CPlaceFinder::FindPlace FUN_005a9700; ITEM_PLACEMENT_RE §1 | B |
| События клика по инвентарю, выбрасывания и выбора места можно восстановить по eventgen | InventoryPanelController.cs:130–173; ссылки на FUN_00530b90, FUN_00531310, eventgen.tcl | B; контроллер порта заменяет нативный drag-and-drop кликовым аналогом |

**Рекомендация Godot:** использовать идентификатор игрового предмета, а не копию его вида в GUI; отдельно хранить принадлежность контейнеру, видимость, позицию, возможность взаимодействия и состояние слота. UI должен отображать состояние, а не быть источником данных. Воссоздать две сетки, команды выбора места, сброс под ноги и возврат предмета в мир. Размерные категории отдельных предметов, порядок перераспределения слотов при смене контейнера и исходные жесты проверять отдельно.

### 2.2 Гномы, очередь команд, движение, работа, отдых

**Основной документ:** [GNOME_BEHAVIOR_COMPLETE_RE.md](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Docs/GNOME_BEHAVIOR_COMPLETE_RE.md), [папка исходных исследований](https://github.com/Zimennik/Diggles-Unity/tree/983523017b43e9e5385e620e9fbfed979c65030c/Docs/re_parts).

Автор выделяет четыре взаимосвязанных слоя:

1. Объектная Tcl-машина состояний, FIFO tasklist, события evt_task_* и evt_autoprod_*.
2. Нативный стек движения: CActWalk → AutoRetry → MetaWalk, разбиение маршрута на пол/стену/воду; CAct_WalkAnim управляет перемещением.
3. Копание: Tcl вызывает get_digedge, dig_next, vector_fixdig, dig_apply; после изменения рельефа переоценивается проходимость.
4. Состояние сущности: позиция, опорная точка, гравитация, направление.

Адрес общего тика по документу: FUN_006b4a30 (CGameThread::SrvDoThink). Полезные дополнительные файлы: `Docs/ORIGINAL_PATHFINDING_RE.md`, `Docs/WORK_DISPATCHER_NATIVE.md`, `Docs/re_parts/sparetime-idle.md`, `tcl-work-layer.md`, `walk-lifecycle.md`, `calc1-confirm.md`. Для кода — `Assets/Diggles/Runtime/Navigation/`, `Runtime/Engine/Sim/`, `Runtime/Tcl/Engine/EntityActions.cs`, `Runtime/Tcl/Engine/DigglesTclEngine.cs`.

**Надёжность B:** это RE-спецификация с нативными адресами; часть старых путей/проблем уже не актуальна в текущем Unity-коде. Сам документ предупреждает читать актуальный §11, а не считать старую таблицу пробелов в §10 текущим состоянием.

**Godot:** фиксированный шаг симуляции, независимый от кадров рендера, явная очередь команд, диспетчер автономной работы и отдельные примитивные действия с финишными и аварийными обработчиками. Не пытаться заменить всё одним AnimationTree или набором таймеров UI.

### 2.3 Таблицы анимаций

[Docs/re_parts/animsets.md](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Docs/re_parts/animsets.md) — конкретные таблицы соответствий классов, состояний и походок с адресами EXE:

| Tcl-команда | По RE автора |
|---|---|
| class_defaultanim | FUN_00613520 |
| set_class_anim | FUN_00615650 |
| set_class_animset | FUN_00616d30 |

Документ описывает runtime-сет из 24 слотов, соответствия gehen/laufen/drehen/kletter/leiter/buddeln/kiste/kiepe, root motion и кадровую интерполяцию. Дополнительно [Docs/ANIMATION_CONTROLLER.md](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Docs/ANIMATION_CONTROLLER.md), `FACE_ANIMATION.md`, `HAT_LINK_SYSTEM.md`, `Assets/Diggles/Runtime/Model/ThreeDbParser.cs`, `ThreeDbData.cs`. Надёжность B; код файлов существует.

**Godot:** импортировать имена клипов и таблицы их ролей отдельно, связывая UI/события с логическими состояниями. Не предполагать человеческий скелет или автоматически считать скорость экспортируемого FBX скоростью оригинального клипа.

### 2.4 Освещение, жидкости, пещеры

| Найденный документ | Что восстановлено автором | Применение |
|---|---|---|
| [TUNNEL_TORCH_LIGHTING_RE.md](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Docs/TUNNEL_TORCH_LIGHTING_RE.md) | Факелы Misc_Light, Autolight-флаг FUN_0068ad00, создание света FUN_005cd520, базовый свет тайла | Отдельная модель факела, генерация объектов света и слой тумана |
| [FOG_OF_WAR_RE.md](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Docs/FOG_OF_WAR_RE.md) | Открытие и затухание видимости | Сетка видимости, шейдер и состояние исследования |
| [RENDERING_PIPELINE_COMPLETE.md](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Docs/RENDERING_PIPELINE_COMPLETE.md) | Трёхмерный рельеф BDB/PMP/L2M | Геометрия и материалы уровня |
| [FLUID_SYSTEM_RE.md](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Docs/FLUID_SYSTEM_RE.md), `WATER_PHASE1_RE.md` | Дескриптор жидкости в последних 4 байтах 89-байтовой BDB-записи, объём, тип, источники и апертуры | Реализовать клеточную симуляцию воды/серы/лавы |
| [WORLDGEN_ORIGINAL_RE.md](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Docs/WORLDGEN_ORIGINAL_RE.md), `worldgen-re-reports/` | Сборка мира из шаблонов и порядок генерации | Воспроизведение генерации кампании |

В RE факелов автор предлагает важное объяснение: потускнение факела при уходе гнома связано с туманом и правилами видимости, а не обязательно с уничтожением/выключением факела. Это проверяемая гипотеза для наблюдения, хотя автор формулирует её как вывод анализа EXE (B). Вода в README порта названа незавершённой, несмотря на подробную спецификацию и наличие кода. Не путать декодированные поля и полностью рабочую игровую механику.

### 2.5 Сохранения и инструменты Ghidra

[Docs/ORIGINAL_SAVE_FORMAT_RE.md](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Docs/ORIGINAL_SAVE_FORMAT_RE.md), [Tools/SaveFormatResearch](https://github.com/Zimennik/Diggles-Unity/tree/983523017b43e9e5385e620e9fbfed979c65030c/Tools/SaveFormatResearch), `Docs/save-re-reports/` и `Assets/Diggles/Runtime/Save/`.

Автор указывает оригинальные функции записи FUN_00557170, загрузки FUN_00556570, открытия gzip-стрима FUN_006bccf0/FUN_006bcc50, передачу примитивов FUN_006bce60. По его анализу сохранение — gzip, внутри последовательно упакованные little-endian данные; основной исследованный вариант — 0xA5. Автор сообщает об анализе 98 сохранений.

В публичном дереве реально присутствуют `Tools/SaveFormatResearch/Ghidra/SaveFormatDump.java` и `VtableDump.java` — скрипты получения результатов анализа, а также Python-утилиты `parse_a5_object_bodies.py`, `dump_a5_details.py`, `scan_walks.py`, `minidump_triage.py`. Это не полный декомпилированный EXE.

**Godot:** использовать парсер как независимый инструмент сверки мира, имён классов, координат и состояний. Запись в оригинальный SAV откладывать до тестов полного цикла и проверки версий. Надёжность B.

## 3. Доклад оригинального разработчика — Game Scripting with Tcl (2001)

[Carsten Orthbandt, Director Development, SEK-Ost, EuroTcl 2001](https://www.eurotcl.eu/presentations/EuroTcl2001-AllPresentations.pdf), раздел 7, печатные страницы 117–125; §§3.1, 3.2.1, 3.2.2, 3.4, 3.6. Прочитан PDF.

**Надёжность A.** Исторический первичный источник, не reverse engineering. Лицензия на повторное использование исходного текста/кода не указана.

Ключевое подтверждение: «For every object there is a Tcl class that defines states, methods and event handlers.»

- В C++-ядре находятся команды, простые действия и свойства объектов; логика сложного поведения задаётся скриптами.
- Активный объект имеет отдельный Tcl-интерпретатор. Декорации без обработчиков могут обходиться без него.
- Состояние может временно отключаться до завершения нативного действия; у действий есть обработчики успеха и ошибки.
- У скриптов нестандартный препроцессор для строковых комментариев // и условных директив //#if, //#else, //#endif. Команда call загружает скрипты через препроцессор; есть кэш Tcl bytecode.
- В §3.4.2 упомянуто более 600 нативных команд и автоматическая генерация HTML-справочника из C++ комментариев.
- В §3.6 подтверждены встроенная игровая консоль и веб-сервер для диагностики.

**Для Godot:** архитектурный контракт, с которым нужно сверять как Unity, так и C++ порты. При прямом выполнении оригинальных скриптов обычной Tcl-совместимости недостаточно: необходимы препроцессор, объектный контекст this, команды классов, событий и действий.

## 4. Справочник Tcl-команд

**Источник:** [Wiggles Tcl Commands](https://wiggles.ruka.at/tipstricks/wiggles_tcl.html), HTML непосредственно получен и прочитан. Связь с генератором документации из доклада правдоподобна, но происхождение конкретной копии не доказано. **Надёжность A** для сигнатур на странице, B для полноты и соответствия каждой версии игры. Явная лицензия не обнаружена.

| Команда | Ссылка | Применение |
|---|---|---|
| inv_add | [#inv_add](https://wiggles.ruka.at/tipstricks/wiggles_tcl.html#inv_add) | Добавление объекта, скрытие, получение индекса |
| inv_rem | [#inv_rem](https://wiggles.ruka.at/tipstricks/wiggles_tcl.html#inv_rem) | Извлечение по индексу/ссылке, опциональная позиция |
| inv_getsize | [#inv_getsize](https://wiggles.ruka.at/tipstricks/wiggles_tcl.html#inv_getsize) | Ёмкость |
| tasklist_add | [#tasklist_add](https://wiggles.ruka.at/tipstricks/wiggles_tcl.html#tasklist_add) | Добавление в конец очереди |
| tasklist_addfront | [#tasklist_addfront](https://wiggles.ruka.at/tipstricks/wiggles_tcl.html#tasklist_addfront) | В начало очереди |
| get_place | [#get_place](https://wiggles.ruka.at/tipstricks/wiggles_tcl.html#get_place) | Поиск свободного места |
| set_anim | [#set_anim](https://wiggles.ruka.at/tipstricks/wiggles_tcl.html#set_anim) | Имя клипа, стартовый кадр, режим воспроизведения |
| set_autolight | [#set_autolight](https://wiggles.ruka.at/tipstricks/wiggles_tcl.html#set_autolight) | Флаг автосвета |
| set_textureanimation | [#set_textureanimation](https://wiggles.ruka.at/tipstricks/wiggles_tcl.html#set_textureanimation) | Анимация текстуры отдельной под-сетки |

Дополнительная копия команд и список реализации: `Docs/ENGINE_TCL_API.txt` и `Docs/ENGINE_COMMAND_GAP.md` в Diggles-Unity; `docs/natywne_komendy_gry.txt` в Viewer.

## 5. DigglesMods — патчи Tcl как документация реальных правил

[Организация](https://github.com/DigglesMods), [каталог модов и релизы](https://digglesmods.github.io/DigglesModManager/), [менеджер](https://github.com/DigglesMods/DigglesModManager), [Wiki формата патчей](https://github.com/DigglesMods/DigglesModManager/wiki/Mod-Developing).

Менеджер C# и перечисленные ниже моды содержат GPL-3.0 LICENSE. Исходники проверены. GPL-код не следует автоматически объединять с MIT-реализацией без учёта условий лицензии. Изучение интерфейсов и сравнительный анализ поведения возможны независимо от копирования кода.

| Мод | Прямой указатель на код | Что использовать | Надёжность |
|---|---|---|---|
| [BetterStorage](https://github.com/DigglesMods/BetterStorage) | `Data/Scripts/classes/items/change_transport.tcl`, `change_misc_items.tcl`, `classes/work/change_lager.tcl`, `init/change_animinit.tcl` | Holzkiepe/Grosse_Holzkiepe, объекты их визуальных представлений, размещение, склад и категории, иконки | A код / B исходная механика |
| [CommandF9](https://github.com/DigglesMods/CommandF9) | [change_z_procs.tcl](https://github.com/DigglesMods/CommandF9/blob/460e570d8d7563792c42ecd68bff53d44dadf437/Data/Scripts/classes/zwerg/change_z_procs.tcl) | beamto_world_all, inv_list, inv_find_obj, выбор экипировки, сохранение рюкзака и транспорта | A/B |
| [BugFix](https://github.com/DigglesMods/BugFix) | `Data/Scripts/ai/change_std_ai.tcl`; `classes/characters/change_raupe.tcl`, `change_fenris.tcl`; `classes/zwerg/change_z_events.tcl`, `change_z_spare_reprod.tcl`, `change_z_work_prod.tcl`, `change_z_methods.tcl` | Ошибки и исправления ИИ, воспроизводства, работы, опыта, персонажей; важны как дифф к исходнику | A/B |
| [DroppingResources](https://github.com/DigglesMods/DroppingResources) | [change_z_dignwalk.tcl](https://github.com/DigglesMods/DroppingResources/blob/e428eea22c4dd6042c85af493fb6978291c8d7ac/Data/Scripts/classes/zwerg/change_z_dignwalk.tcl) | Вероятности выпадения при копании и зависимость от уровня развития | A/B |
| [SwitcherGeneratorDungeon](https://github.com/DigglesMods/SwitcherGeneratorDungeon) | `Data/Scripts/classes/story/change_story.tcl`; `gameplay/change_CampaignKris.tcl`, `change_CampaignLava.tcl`, `change_CampaignMet.tcl` | Какие скрипты и настройки контролируют генерацию типов пещер | A/B |
| [WigSound](https://github.com/DigglesMods/WigSound) | `Files/Data/Scripts/classes/story/sequencer.tcl`, `Trigger_Tournament.tcl`, `Trigger_Tutorial.tcl`, `WigSound/Program.cs` | Источники проблемы звука, сценарная последовательность | A код; GPL-3.0, вложенный madplay.exe требует отдельной проверки условий |
| [RareResources](https://github.com/DigglesMods/RareResources), [Barrow](https://github.com/DigglesMods/Barrow), [StoneDoor](https://github.com/DigglesMods/StoneDoor), [ProductionStatistics](https://github.com/DigglesMods/ProductionStatistics) | Корневые репозитории; перечислены авторами менеджера | Дополнительные примеры технологий, транспорта, дверей, производства | C: отдельно не проверены |

**Важный факт по CommandF9:** в старом фрагменте патча есть повторная проверка inv_find_obj перед beamto_world, поскольку выгрузка корзины с содержимым может выложить сразу несколько предметов. Это свидетельство взаимодействия, но не исчерпывающая спецификация штатной корзины.

В BetterStorage патчатся связанные визуальные классы корзин и используются команды tasklist_add и get_related_pannier. Числа ёмкости склада в README этого мода (9 против 3) относятся к изменению мода, не к рюкзаку гнома.

Формат менеджера: обычный файл копируется поверх соответствующего пути; файл с префиксом change_ описывает изменение существующего файла; блоки $start/$end и инструкции замены, вставки и т. п. разбираются менеджером. Это **формат мод-менеджера, не формат исходных Tcl игры**. Оригинальные строки внутри секций поиска/замены особенно полезны как свидетельство структуры штатного кода, но добавленные строки не надо переносить как поведение ванили.

## 6. Diggles SDK / barnacle — native ABI и исследовательские hooks

[Репозиторий](https://github.com/ktksgit/barnacle), [версия e69c456](https://github.com/ktksgit/barnacle/tree/e69c456ae21d8b76dd72a6a341bfb921475833c4), [релизы](https://github.com/ktksgit/barnacle/releases), [сообщение автора zed2000](https://wiggles.ruka.at/forum/viewtopic.php?t=315).

**Лицензия:** в корне текст MIT-style разрешения; сторонние библиотеки имеют собственные лицензии. **Надёжность A** для наличия исходников, B для работоспособности на соответствующих билдах.

[scripts/abi.py](https://github.com/ktksgit/barnacle/blob/e69c456ae21d8b76dd72a6a341bfb921475833c4/scripts/abi.py) содержит две реальные таблицы адресов:

| Имя функции | 1.0.844 build 59495 | 2.1.1.10 |
|---|---:|---:|
| findFileLocation | 0x46A150 | 0x4402C0 |
| CObj_tclEval | 0x483710 | 0x555A00 |
| script_call | 0x592560 | 0x6313A0 |
| sTclObject_preprocessFile | 0x6A4708 | 0x6BB140 |
| TclCache_get | 0x6A538F | 0x6BBB00 |
| g_tclCache | 0xECAE80 | 0xA42DD0 |

Код учитывает image base 0x400000 и сигнатуры сборок; calling conventions отличаются. `examples/hook.py` описывает вызовы нативных функций, типы и структуры (BuiltinTclData, StringRef); `examples/bootstrap.tcl`, `examples/test_python.tcl`, `scripts/pytcl.py` — связка Python/Tcl. README указывает сборку с Python 3.6 x86 и SCons.

**Godot:** SDK полезен прежде всего для лаборатории оригинала, получения событий и исследования Tcl/native boundary, а не как обязательная зависимость нового движка. Адреса не универсальны для оригинальных релизов 2001–2002, Steam, GOG и локализаций. Прежде чем применять их, определить точный билд и хэш EXE.

---

# Требует проверки

## 7. Старые распаковщики и конвертеры 3DB

### djunkles/Diggles3db

[Репозиторий](https://github.com/djunkles/Diggles3db), [версия c1a4aec](https://github.com/djunkles/Diggles3db/tree/c1a4aeccad8d8aa54847b21531a01774689f0332).

В репозитории есть `python2.7/3dbScript.py`, `c-sharp/Wiggles3db/3DDB.cs`, `Animation.cs`, `Material.cs`, `Mesh.cs`, `CMap.cs`, `python3/lib/parse_3db.py`, `python3/lib/export.py`. Есть публичный пример `assets/baby.3db`; автор признавал в 2022 году ограничение: первый объект, без извлечения анимаций ([форум](https://wiggles.ruka.at/forum/viewtopic.php?p=4188)).

**Надёжность A** для наличия файлов. **Лицензия:** отдельного LICENSE в проверенном дереве нет; нельзя автоматически считать исходный код свободно лицензированным для распространения. Образец модели не следует распространять отдельно без разрешения.

**Godot:** исторический reference/parser, особенно если современный импортёр не справляется с конкретным файлом. Не приоритетный производственный конвертер.

### Zimennik/Diggles3db-Converter

[Репозиторий](https://github.com/Zimennik/Diggles3db-Converter), [версия fb38967](https://github.com/Zimennik/Diggles3db-Converter/tree/fb3896779ba4e8baa01312afc330ae5c4ce6a7fc). Форк предыдущего парсера; Python, Blender, glTF/FBX. Файлы: [parse_3db.py](https://github.com/Zimennik/Diggles3db-Converter/blob/fb3896779ba4e8baa01312afc330ae5c4ce6a7fc/python3/lib/parse_3db.py), [export.py](https://github.com/Zimennik/Diggles3db-Converter/blob/fb3896779ba4e8baa01312afc330ae5c4ce6a7fc/python3/lib/export.py), `python3/check_animations.py`, `run_with_mapping.py`, `Unity/Editor/DigglesAnimationSetup.cs`.

**Лицензия/статус:** README ограничивает использование некоммерческими целями сообщества Diggles/Wiggles; отдельного LICENSE в проверенном дереве нет. Не включать в коммерческий проект без уточнения прав.

**Надёжность A для кода и проверенного ниже результата.** Не надо слепо доверять обещанию README о полном сохранении анимаций: `export.py:607–763` создаёт узлы для кадров, а `GLTFModel` на строках 769–784 не получает список animations. Поэтому исходный glTF сам по себе не содержит полноценных анимационных треков; FBX-путь использует переключение видимости кадров. Кроме того, старый parser пропускает тени и cmap (строки 178–191), часть полей помечены unknown, координаты читаются как нормализованные u16. Новый Viewer даёт более детализированные трактовки.

**Выполненная проверка:** запущена только функция parse_3db_file на публичном `assets/baby.3db` из djunkles/Diggles3db, без исходной игры и без экспорта:

| Показатель | Получено |
|---|---:|
| Заголовок | 3DDB 1.0 |
| Имя | baby |
| Материалы | 2 |
| Меши | 479 |
| Объекты | 1 |
| Записи анимаций | 48 |

Примеры реально извлечённых записей (число ссылок на кадры/меши): aufwachen — 11, einschlafen — 9, essen_start — 8, essen_loop — 8, essen_end — 5, krabbeln_loop — 8, laufen_loop — 8, schlafen_loop — 7, drehen_links — 13, drehen_rechts — 13. Это не длительности в секундах и не полный каталог игры.

**Godot:** полезно извлечение списка имён и тестовый fixture для сверки парсера; предпочтительнее MIT Viewer для настоящего GLB с весами морфов.

### Историческая ветка форума 3D model edit

[Участники и ранний код](https://wiggles.ruka.at/forum/viewtopic.php?t=105), [архив Python 2.7](https://wiggles.ruka.at/forum/viewtopic.php?p=1136), [ссылка авторов на GitLab](https://gitlab.ruka.at/Wiggles/3DB), [новые форки и сообщения 2025](https://wiggles.ruka.at/forum/viewtopic.php?p=4188).

Форумное сообщение zed2000 от 28.12.2016 описывает 3dbparser.7z и получение Wavefront OBJ из baby.3db. В 2025 tilk сообщал о поддержке текстур и анимаций не во всех файлах и указал на более продвинутый форк Zimennik. **Надёжность C/B**; архив и GitLab-версию не удалось независимо проверить как рабочие. Нет подтверждённой лицензии.

Не считать формат 3DB из Freelancer тем же форматом: форумный участник прямо сообщал о невозможности открытия моделей Wiggles соответствующим инструментом ([обсуждение](https://wiggles.ruka.at/forum/viewtopic.php?start=20&t=105)).

## 8. Хомяки, черви и другие существа

**Найденные источники:**

- [Diggles-Unity, COMBAT_SYSTEM_RE.md](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Docs/COMBAT_SYSTEM_RE.md): боевая логика, Wuker и Zwerg, реакции, таблица fight.tcl; в районе строк 215–245 описаны анимации попаданий, атаки и ссылки на конкретные .3db.
- [BugFix, change_raupe.tcl](https://github.com/DigglesMods/BugFix/blob/141e1e5e580f6b0eb1c3f454e73028ca2e07f8b9/Data/Scripts/classes/characters/change_raupe.tcl): исправления type и get_place для объекта Raupe; есть `change_fenris.tcl`.
- [Wiggles Viewer, world_sim.cpp](https://github.com/mztulip/wiggles_viewer/blob/663995e926c8e08429bdb4f7dcda456cc573864a/src/lib/world_sim.cpp): распознаёт Zwerg, Wuker, Schwefelwuker, в частности устанавливает модель Wuker из скриптовой инициализации, поддерживает тестовое заселение. Некоторые ручные способы управления в Viewer — специально добавленные средства тестирования, отсутствующие в оригинале.
- Diggles-Unity `Docs/ITEM_PLACEMENT_RE.md` ссылается на `wuker.tcl:206` и find_free_place при спавне червя.
- [Diggles-Unity BACKLOG](https://github.com/Zimennik/Diggles-Unity/blob/983523017b43e9e5385e620e9fbfed979c65030c/Docs/BACKLOG.md): разведение хомяков отмечено как открытая работа; бегство хомяка и движение червей названы внешне корректными, но не считать это полной реализацией.

**Лицензии:** MIT для обоих портов, GPL-3.0 для BugFix; оригинальные скрипты и модели не перелицензированы. **Надёжность B** для конкретных отсылок и C для полного игрового поведения. По README Unity большая часть боя и поведения монстров ещё не завершена.

**Для Godot:** извлечь из данных собственной копии классы существ, их события, начальные атрибуты, состояния, ссылки на клипы, питание, размножение, фильтры целей и отношения. Не задавать на глаз способы питания, агрессии, радиусы преследования и дамаг. Тестировать отдельных существ в малой пещере. Не смешивать разные классы Wuker и Raupe.

## 9. Мод HD и текстуры

[ZarfaZ/DigglesHDmod](https://github.com/ZarfaZ/DigglesHDmod), [форк DigglesMods](https://github.com/DigglesMods/DigglesHDmod), [релизы форка](https://github.com/DigglesMods/DigglesHDmod/releases).

Выявлены авторский высокотекстурный мод и файл Documentation.txt. Viewer использует его в качестве источника по структуре Texture/Ground и поддерживает overlay ресурса. Сам большой архив текстур в рамках исследования не проверен целиком; точную лицензию на модифицированную графику не подтвердил. **Надёжность B** для существования, C для полноты и прав на перепубликацию.

**Godot:** использовать как пример имён, каталожной структуры, прозрачности и экспериментов с большей текстурой; не распространять автоматически исходные/улучшенные ассеты, пока не установлены права.

## 10. Эксперименты с multiplayer и Tcl-логированием

- [Wiggles Coop-/Multiplayer Mod](https://wiggles.ruka.at/forum/viewtopic.php?t=2374): сообщения phantom, включая 08.01.2025. Автор описывает перекомпиляцию Tcl 8.3, изменение Tcl_EvalEx для чтения внешних команд и сервер TCP. Упоминает нестабильность варианта с многопоточностью. [Вспомогательный WigglesTestServer](https://github.com/itsme12345678910/WigglesTestServer) существует: `src/main/java/TCPClient.java`, `UDPClient.java`, `server.java`. Отдельный LICENSE в дереве сервера не найден. **B/C**, не проверена работа.
- [Вывод Tcl-логов в консоль](https://wiggles.ruka.at/forum/viewtopic.php?t=266): автор описывает модифицированную tcl83.dll и start.exe, включая изменение Data/systeminit.tcl. Наличие рабочего релиза и лицензия не подтверждены. **C**.

**Godot:** использовать идеи инструментирования и регистрации команд для локального тестирования оригинала, а не считать их готовым сетевым кодом новой игры. Старый доклад упоминает статическую линковку Tcl, а моддеры более поздних сборок говорят о DLL — это повод проверять версию.

## 11. Патчи, редакторы и современные издания

| Находка | Прямой источник | Применение и ограничение | Статус |
|---|---|---|---|
| Исторические патчи Wiggles 1.0.707 / .814 / .844 | [архив](https://wiggles.ruka.at/downloads/index.php?c=updates); [707 changelog](https://wiggles.ruka.at/data/Wiggles_Patch_1_0_707.txt), [814](https://wiggles.ruka.at/data/Wiggles_Patch_1_0_814.txt), [844](https://wiggles.ruka.at/data/Wiggles_Patch_1_0_844.txt) | Изолированные эталоны исправленных версий; сравнение скриптов до/после. Архив указывает цепочку обновления .707 → .814 → .844 | A для ссылок на странице; EXE не запускались; лицензия исходников не установлена |
| SetMode_Win7 | [немецкая версия](https://wiggles.ruka.at/downloads/SetMode_Win7.exe), [международная](https://wiggles.ruka.at/downloads/int/SetMode_Win7.exe) | Настройка разрешения оригинала для записи тестов. Архив заявляет исправление OK/поиска актуальных разрешений | B для описания; бинарники не тестировались |
| WigglesCommunityPatch | [форум установки Windows 10](https://wiggles.ruka.at/forum/viewtopic.php?t=267) | Возможный набор исправлений для старого EXE; не смешивать с Steam/GOG | C, содержимое и лицензия не подтверждены |
| Map Editor | [Tutorial Map-Editor](https://wiggles.ruka.at/forum/viewtopic.php?p=867), [создание шаблонов](https://wiggles.ruka.at/forum/viewtopic.php?p=321) | Флаг -mapedit оригинального EXE; позволяет создавать тестовые карты и изучать шаблоны. Отдельный LevelEditor упоминается в ветке | B/C; не проверен запуск, исходники не найдены |
| Официальное переиздание 2020 | [страница исполнителя General Arcade](https://generalarcade.com/projects/diggles-the-myth-of-fenris/), [страница издателя Steam](https://store.steampowered.com/app/1478650/Wiggles/) | Современная тестовая среда, Win7+, без старого DRM, снято ограничение FPS, дополнительные DirectX11-настройки. Не source release | A для заявленного на странице; коммерческая игра |

Цель патчей — запуск и наблюдение, а не перенос платформенного кода Windows в Godot. Старые адреса функций и реестр не переносить автоматически на новые билды.

---

# Не найдено / не подтверждено

Отсутствие найденного материала не означает его несуществования.

1. **Официально опубликованный полный исходный код SEK-Ost** или лицензия, разрешающая перенос и перепубликацию всех игровых данных. Доклад даёт архитектуру и небольшие примеры, не полный движок.
2. **Публичная полная декомпиляция EXE** в виде репозитория с полным Ghidra/IDA-проектом или всех восстановленных функций. Diggles-Unity публикует документы с адресами, собственную реализацию и скрипты Ghidra; цитируемые авторами сырые результаты re/decompiled в публичном дереве не обнаружены.
3. **Публичный отдельный OpenWiggles engine**: Wiggles Viewer описывает такой репозиторий, но проверенная попытка получить mztulip/openwiggles не удалась. Не утверждать, что он удалён или закрыт; проверить ссылку у автора. Библиотека и Viewer доступны.
4. **Официальный 3DB packer / exporter** исходной студии, удостоверенный рабочий обратный импорт всех современных моделей в оригинал. Найденные конвертеры ориентированы прежде всего на чтение.
5. **Полный каталог всех анимаций** с именами, точным таймингом и ролями каждой сущности, добытый из всех оригинальных моделей. Есть инструмент, формат и таблицы гномов; массовый каталог нужно построить на данных собственной копии.
6. **Спецификация всех полей всех форматов без unknown**. В частности, младшие биты L2M и часть полей/особых случаев остаются предметом исследования. Не переносить названия unknown из старого скрипта как семантику.
7. **Универсальный архиватор для всех ресурсов игры.** Найдены конкретные парсеры .3db/.bdb/.pmp/.l2m/.sav/TGA и описание TEXMAPS.BIN; доказательств универсальной WAD/PAK-схемы нет.
8. **Полная реализация ИИ хомяка, червей и всех монстров** со всеми атаками, едой и размножением. Есть фрагменты и открытые задачи, но не достаточно для точной реализации всего поведения.
9. **Гарантированная совместимость сохранений между изданиями 2001–2002 и Steam/GOG.** Структуры в RE проверялись на конкретных данных; нельзя считать результаты универсальными для каждого билда.

## Практический план применения для Godot

| Этап | Что сделать | Критерий проверки |
|---|---|---|
| 1. Версии и права | Идентифицировать билды оригинала, хэш EXE и исходные данные; каталог источников MIT/GPL/неясных | Не смешивать ассеты с лицензионным кодом, зафиксировать версии |
| 2. Экспорт моделей | Использовать MIT GLB exporter; начать с BABY, MANN, корзин и одного существа | Сравнить число клипов, кадры, нормали, материалы, переходы, root motion |
| 3. Мир | Импорт BDB+PMP+L2M и Tcl-шаблонов | Одна исходная пещера визуально и пространственно совпадает; проходы и стены правильны |
| 4. Инвентарь | Реализовать объекты предметов, две сетки слотов, команды inv_* и get_place | Подбор, малый/большой рюкзак, выгрузка и размещение по эталонным сценариям |
| 5. Tcl / поведение | Реализовать объектные контексты, события, очередь, фиксированный тик и команды | Та же последовательность действий и состояний при одинаковом вводе |
| 6. Свет и туман | Отдельные состояния света и FoW, факелы, флаги материалов | Сравнить одну пещеру до/после прихода и ухода гнома |
| 7. Существа и жидкости | Восстановить неподтверждённые состояния на оригинале, тесты на минимальных сценах | Не заполнять пробелы произвольно |

**Итоговая рекомендация:** опираться на документацию Diggles-Unity как карту нативных функций и логики, а на Wiggles Viewer — как источник спецификаций и рабочего кода импорта. В спорных случаях сверяться с докладом 2001 года, реальными скриптами собственной копии и воспроизводимым экспериментом. Для первой версии порта гораздо полезнее корректный импорт, инвентарь и событийный механизм, чем перенос всего Windows-движка или зависимость от старого EXE.
