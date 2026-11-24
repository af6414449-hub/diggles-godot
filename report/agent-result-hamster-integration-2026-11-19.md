# Результат: интеграционный пакет диких хомяков

**Дата:** 2026-11-19
**Исполнитель:** агент MCode (сессия `mvs_bbf5a1f0562d4e98b53a6f6f584273a6`)
**Задача:** `docs/reverse-engineering/agent-task-hamster-integration-2026-11-19.md`

---

## 1. Краткий итог

Пакет интеграции подготовлен, применён в собственном рабочем дереве агента и проверен
headless-прогонами. Основной проект не редактировался: единственный созданный в нём файл —
этот отчёт.

| Что | Итог |
|---|---|
| Переносимых модулей/данных/тестов | 21 файл, скопированы как есть (sha256 совпадает со снимком) |
| Патч `scripts/native_tasklist.gd` | 5 совместимых имён поверх живых — поведение гномов не меняется |
| Патч `scripts/multiplayer_test.gd` | 4 якорные вставки + блок функций хоста (274 строки, дословно из снимка) |
| Наборы тестов хомяка | 3/3 зелёные, 192 проверки (69 + 66 + 57) |
| Регрессия живых наборов | 44/48 зелёных против 42/45 у baseline; три падения общие и существующие в живом проекте |
| Round-trip патча | оба патча применены к свежей копии живого проекта без конфликта; интеграционные блоки совпадают побайтово |
| Сцена headless | `WILD_HAMSTER_NAV_READY level=58.50 size=53x25`, 4 хомяка, поворот перед ходьбой, еда съедена, ошибок нет |

### Ключевые находки, меняющих план переноса

1. **Снимок MCode — это проект ДО появления `WORLD_SPACE`.** В снимке нет ни
   `template_shift`, ни `WORLD_SPACE.apply`, ни `WALKABLE_FLOOR_Y -= template_shift.y`.
   Значит координаты хомяков в снимке несдвинутые, а в живом проекте мир сдвинут на
   `(40, 40)`. Блок спавна хомяка **обязан** вставляться после сдвига
   `position_data`, иначе хомяк встанет на несдвинутую точку.
2. **`WORLD_SPACE.apply()` мутирует `terrain["cells"]` на месте** (`playable_world_space.gd:86`),
   поэтому `load_terrain(data)` после вызова читает уже сдвинутый рельеф. Уровни в сцене —
   54.5 (пол) и 58.5 (терраса), а не 14.5/18.5.
3. **`native_tasklist.gd` живого проекта не эквивалентен снимку**, но и не конфликтует с ним:
   живых потребителей (`count()`, `remove(0)`) можно сохранить, добавив Tcl-имена.
4. **Живой `remove()` уже безопасен на пустой очереди** (в отличие от утверждения
   передаточной инструкции): `remove(index)` возвращает `""` и ничего не удаляет при
   выходе за границы. Поэтому `pop_front()` семантически равен `remove(0)` — отдельная
   реализация нужна только для читаемости, а не как исправление бага.
5. **Текстура `Character_Hamster_a_128.tga` уже есть** в живом проекте (65 580 Б, с `.import`)
   в трёх местах — копировать не нужно.
6. **Живой проект правится параллельно, и это видно в тестах.** За время работы над
   задачей в нём изменились `project.godot`, `scripts/native_battle_world.gd` и
   `tools/native_battle_world_self_test.gd`. Из-за этого в первом сравнительном прогоне
   `native_battle_world_self_test` выглядел как регрессия интеграции; после синхронизации
   этих трёх файлов набор зелёный, то есть падение вызвано правкой живого проекта, а не
   хомяком (§5.3). `multiplayer_test.gd` и `native_tasklist.gd` живой проект за это время
   **не менялся** — все номера строк в §4 действительны.

### Источники и доказательства

| Источник | Роль | Как использовано |
|---|---|---|
| `C:\Users\frant\.minimax\sessions\mvs_e213cb8b6788404489ad3b0b5c39827f\workspace\Diggles-mcode\work\godot` | снимок MCode: код, данные, тесты | источник всех 21 переносимого файла; эталон поведения |
| `...\Diggles-mcode\notes\2026-11-19-hamster-integration-codex.md` | передаточная инструкция | карта файлов, якоря, ловушки; **две позиции устарели** (см. §7) |
| `C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot` | живой проект | цель интеграции; только чтение |
| `C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data` | оригинал игры | сверка фактов (класс `hamster.tcl`, пакет `hamster.3db`) |
| `C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe` | Godot 4.7.2 | все headless-прогоны |

Факты по манифесту сцены получены прямым разбором
`godot/models/multi_start_010_models.json` (sha256 `ce6e427c96b862ec584336f5256ab0d5b22c17b7c237c5bc95793e5be5ea2822`):
4 плейсмента класса `Hamster` (ordinal 23, 24, 38, 39), 3 плейсмента `Grillpilz`
(ordinal 46, 47, 48), объект `hamster.3db::hamster` с 2 поверхностями — то есть ранний
`continue` по отсутствию модели плейсмент хомяка **не** отбрасывает.

---

## 2. Таблица файлов

### 2.1 Копировать как есть (`copy as-is`)

Все файлы скопированы из снимка байт в байт; sha256 сверен после копирования.

| Файл | Байт | SHA-256 (первые 16) | Назначение |
|---|---|---|---|
| `scripts/native_wild_hamster.gd` | 20 418 | `11358450c8e8b3ba` | узел хомяка: ходьба, поворот, визуал, датчик гнома |
| `scripts/native_hamster_actor.gd` | 20 494 | `c5820f19f090bd27` | порт `hamster.tcl`: idle/task, таблица активностей, побег, еда |
| `scripts/native_hamster_ai.gd` | 8 813 | `16b64b1ea420c392` | чистые правила класса: дальности, активности, параметры команд |
| `scripts/native_hamster_animations.gd` | 4 445 | `f5225720781768e2` | таблица алиасов и анимсетов **класса `Hamster`** (собственный JSON) |
| `scripts/native_hamster_clips.gd` | 6 536 | `71e379741b8bb654` | геометрия 28 клипов `hamster.3db` |
| `scripts/native_level_ground.gd` | 4 890 | `5514383dbe218a83` | пол уровня по высоте из рельефа (новый модуль) |
| `scripts/native_command_dispatcher.gd` | 6 016 | `b9206f63f24891ae` | выполнение команд из очереди хомяка |
| `scripts/native_command_handlers.gd` | 15 010 | `e59ec130bc48c58a` | обработчики команд; хомяку нужен `parse_position` |
| `scripts/native_hamster_actor_3d.gd` | 13 400 | `181042a75841c185` | 3D-вариант актора (демо/проба, необязателен) |
| `scripts/native_hamster_demo.gd` | 5 301 | `e0f82a7d4096e064` | демо-сцена хомяка (необязательна) |
| `scripts/native_wild_hamster_probe.gd` | 2 562 | `f9adc6d83a3f74af` | рантайм-проба (необязательна) |
| `models/native_hamster_clips.json` | 5 019 627 | `a7cf980f8275dd47` | кадры 28 клипов `hamster.3db` |
| `models/native_hamster_animations.json` | 6 492 | `d9183f91f8a54dde` | 27 алиасов и 3 анимсета класса `Hamster` |
| `models/native_tasklist_commands.json` | 24 729 | `ab01b666ed40ac38` | словарь команд для диспетчера |
| `tools/native_wild_hamster_self_test.gd` | 13 266 | `ca99270f6bb316ea` | набор 1: клипы, поворот, побег, пол |
| `tools/native_hamster_actor_self_test.gd` | 15 581 | `e890e28be863f731` | набор 2: актор, очередь, еда, паралич |
| `tools/native_hamster_ai_self_test.gd` | 9 323 | `af11093608e419b4` | набор 3: чистые правила ИИ |
| `tools/hamster_texture_orientation_probe.gd` | 2 261 | `8553b83dd2d95bae` | проба ориентации текстуры (справочная) |
| `tools/native_hamster_probe.gd` | 1 537 | `b6d05b33a949a9a8` | проба (справочная) |
| `scenes/native_hamster_demo.tscn` | 213 | `58d1feb15b3bf60e` | демо-сцена |
| `scenes/native_wild_hamster_probe.tscn` | 197 | `2c40122c99d8129d` | проба-сцена |

Полные sha256 — в §5.3 и в выводе `scripts/build_patch.py`.

### 2.2 Требует адаптера (`requires adapter`)

| Файл | Байт до / после | Что сделано |
|---|---|---|
| `scripts/native_tasklist.gd` | 860 → 2 022 | добавлены 5 совместимых имён: `cnt()`, `rem()`, `list()`, `pop_front()`, `has_pending()`. Живые `count()`, `remove()`, `commands()`, `get_command()`, `add()`, `add_front()`, `clear()`, `find()` не тронуты |
| `scripts/multiplayer_test.gd` | 174 995 → 188 641 | 4 якорные вставки + блок функций хоста (см. §4) |

### 2.3 Уже совместимо (`already compatible`) — не копировать

| Файл | Почему совместим |
|---|---|
| `scripts/native_animation_aliases.gd` (живая 1 846 Б) | переносимый код зовёт из него только `get_clip`, `get_frame_count`, `get_face_anim` — все три в живой версии есть. Модуль `native_hamster_animations.gd` использует **собственную** таблицу класса `Hamster` и глобальный модуль не трогает |
| `scripts/source_animation_action.gd` | отличается от снимка только текстом комментария (дифф — 4 строки) |
| `scripts/native_terrain_state.gd` | живая версия новее (`cell_overrides`), на путь хомяка не выходит |
| `textures/models/Character_Hamster_a_128.tga` | уже есть (65 580 Б + `.import`); путь в клипах абсолютный `res://textures/models/Character_Hamster_a_128.tga` |
| `godot/models/multi_start_010_models.json` | sha256 совпадает со снимком — манифест не менялся, плейсменты хомяков и еды те же |
| `godot/models/multi_start_010_terrain.json` | тот же файл, что использует `native_level_ground.gd` |

### 2.4 Не переносить (`do not copy`)

| Файл | Причина |
|---|---|
| `scripts/multiplayer_test.gd` (целиком) | в живом проекте он новее и правится параллельно — патчится по якорям (§4) |
| `scripts/native_tasklist.gd` (целиком) | перезапись сломала бы очередь задач гномов: `native_actor_tasks.gd:17,19` зовёт `queue.count()` и `queue.remove(0)` |
| `scripts/native_animation_aliases.gd` (целиком) | живая версия новее; совместимости достаточно (§2.3) |
| `scripts/native_riesenhamster_ai.gd`, `native_riesenhamster_animations.gd`, `models/native_riesenhamster_animations.json`, `tools/native_riesenhamster_self_test.gd` | класс `Riesenhamster` не входит в путь хомяка; в живом проекте нет |
| `scripts/native_dwarf_utility.gd` | не входит в путь хомяка |
| `tools/native_tasklist_self_test.gd`, `tools/native_command_handlers_self_test.gd`, `tools/native_command_dispatcher_self_test.gd`, `tools/native_dwarf_ai_loop_self_test.gd` | тесты только снимка, к сцене хомяка не относятся |
| все `*.gd.uid` | Godot 4.7 создаёт их сам при первом открытии проекта |
| `models/native_hamster_clips.json` в unified diff | 5 МБ минифицированного JSON в одну строку — вынесен в отдельный патч-файл (§3.2) |

---
