# Handoff для Minimax: Diggles Godot port

Дата: 2026-11-19. Этот файл предназначен для копирования/объединения работы в
проекте Minimax. Он описывает **актуальное живое дерево Codex**, а не только
исследовательские отчёты.

## 1. Главные пути и доступы

| Что | Путь / значение | Примечание |
|---|---|---|
| Живой основной проект Codex | `C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles` | Основной writable проект пользователя |
| Godot-проект | `C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot` | Редактируется Codex и пользователем |
| Ваш Minimax workspace | `C:\Users\frant\.minimax\sessions\mvs_e213cb8b6788404489ad3b0b5c39827f\workspace\Diggles-mcode` | **Read-only для Codex**; не ожидайте, что Codex туда пишет |
| Внешнее дерево/артефакты Minimax | `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles` | Здесь лежат подготовленные патчи и workbench |
| Оригинальная игра/data | `C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data` | Только чтение; первичный источник для механик |
| Godot 4.7.2 | `C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe` | Использовать для headless-тестов |
| Java/Android | `C:\Program Files\Microsoft\jdk-21.0.13.21-hotspot` | APK сейчас **не собирать**, пользователь тестирует в редакторе |

### Политика совместной работы

- Не заменять целиком `godot/scripts/multiplayer_test.gd`, `native_tasklist.gd`,
  `native_walkmap.gd` или другие живые файлы копией из старого snapshot.
- Интегрировать только небольшими патчами по текстовым якорям и сначала проверять
  актуальное содержимое (`rg`, `git apply --check` либо эквивалент).
- У Codex нет права редактировать Minimax workspace. Minimax может читать живой
  проект, готовить работу у себя и выдавать в основной проект только отчёт/патч.
- Не выполнять destructive git-команды (`reset --hard`, checkout с потерей изменений).
- Не собирать APK по умолчанию. После gameplay-изменений достаточно Godot headless
  и теста в редакторе пользователем.

## 2. Навыки и правила Codex, которые надо учитывать

В окружении Codex доступен обязательный skill `godot`:

`C:\Users\frant\.codex\skills\godot\SKILL.md`

Он требует перед правкой `.gd`/`.gdshader`:

1. читать `references/gdscript_conventions.md`;
2. запускать `lint_project.py` до/после;
3. после shader-правок запускать `check_project` (shader compile проверяется только там);
4. для новых Godot-сцен/ресурсов проверять загрузку headless.

Полезные команды (из `C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles`):

```powershell
$godot = 'C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe'
python 'C:\Users\frant\.codex\skills\godot\scripts\debug\lint_project.py' .\godot --pretty
& $godot --headless --debug --ignore-error-breaks --path .\godot --script 'C:\Users\frant\.codex\skills\godot\scripts\core\dispatcher.gd' check_project '{}'
```

Уже известные нефатальные diagnostics:

- linter предупреждает о `res://../docs/reverse-engineering/minimax-battle-world-2026-11-19.json` в
  `godot/tools/native_battle_world_self_test.gd`; это старый путь внешнего fixture,
  а не текущая gameplay-регрессия;
- headless self-tests, вручную создающие 3D меши, могут печатать resource/RID leak
  при завершении. Считать важным `SCRIPT ERROR`, `Parse Error`, падение assertion;
  сам exit-leak не равен ошибке механики.

## 3. Цель проекта и принципы

Порт Diggles в Godot, source-first. Приоритеты пользователя:

1. корректная карта/раскопка/коридоры/пещеры;
2. естественное движение гномов, навигация, добыча, каски/кирки/эффекты;
3. свет, похожий на оригинал;
4. животные и ИИ (хомяки уже интегрированы);
5. генерация battle-world.

Не подменять неизвестные механики догадками. Для оригинала сначала читать Tcl,
модели/карты/шейдеры и существующие RE-документы; выводы маркировать уровнем
доказанности.

## 4. Текущее состояние: важные интеграции Codex

### 4.1 Terrain, раскопка и navigation

Ключевые файлы:

- `godot/scripts/multiplayer_test.gd` — основная сцена/интеграционный хост;
- `godot/scripts/native_terrain_state.gd` — mutable BlockDB terrain;
- `godot/scripts/native_walkmap.gd` — native-style walkmap;
- `godot/scripts/native_walk_flags.gd` — producer bytes 0/1/3;
- `godot/scripts/native_dig_rules.gd`, `native_dig_next.gd`, `native_fix_dig.gd`.

#### Последняя оптимизация walkmap (встроена)

Встроен проверенный Minimax патч из:

`C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\workbench\walkmap-performance.patch`

Изменённые файлы:

- `godot/scripts/native_walkmap.gd` — кэш height/gate, narrowed dirty samples,
  cached producer;
- `godot/scripts/native_walk_flags.gd` — `terrain_sample_query_cached()`;
- `godot/scripts/native_terrain_state.gd` — `cell_surface_samples(map_cell)` bulk
  accessor;
- `godot/scripts/multiplayer_test.gd` — передаёт `_native_cell_surface_samples`
  как пятый аргумент `rebuild_after_strike`.

Причина фриза: прежний код читал 31 clearance probe на sample через host callback;
серия 273 ударов делала 1 804 460 height calls. Оптимизация доказана
`WALKMAP_EQUIVALENCE_SELF_TEST_OK assertions=4369` в workbench Minimax:

`C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\workbench\tools\walkmap_equivalence_self_test.gd`

Измерение Minimax (реальные данные `multi_start_010`): full 35.858 ms/удар;
cached 6.172 ms; bulk 5.658 ms (6.34×). На текущей живой headless-сцене
`terrain_refresh_self_test` показал strike `24–34 ms` вместо предыдущих примерно
`75–140 ms` смешанной стоимости. Полный user-editor тест всё ещё нужен.

Проверки после интеграции:

```powershell
& $godot --headless --path .\godot --script res://tools/native_walk_flags_self_test.gd
# NATIVE_WALK_FLAGS_SELF_TEST_OK assertions=131
& $godot --headless --path .\godot --script res://tools/terrain_refresh_self_test.gd
# TERRAIN_REFRESH_SELF_TEST checks=8 failures=0
```

Предусловие оптимизации: `assume_static_gate = true`; в текущем порту gate берётся
из статического manifest. Если gate станет runtime/mutable, отключить это
предположение и перепроверить equivalence.

### 4.2 Runtime освещение terrain/факелы

Исследование:

`docs/reverse-engineering/agent-result-lighting-architecture-2026-11-19.md`

Факты оригинала:

- `data/Scripts/classes/items/emitter.tcl`: `Misc_Light` = offset `{0 -0.5 1}`, radius 6,
  RGB `{0.9 0.9 0.8}`;
- оригинальный D3D shader получает готовый vertex color, а point-light вычисляется
  native renderer-ом на вершинах из light pool;
- отдельной lightmap/bake-процедуры после удара не доказано.

Текущая Codex-реализация:

- `godot/shaders/native_terrain_pipeline.gdshader` содержит общий runtime pool:
  `dynamic_torch_position_range[32]`, `dynamic_torch_color[32]`;
- динамическая оценка перенесена в `vertex()` (не во fragment), аналогично
  vertex-color семантике оригинала;
- `godot/scripts/native_scene_profile.gd`: `MAX_DYNAMIC_TORCHES=32`,
  `dynamic_torch_lights`, `set_dynamic_torch_lights()`,
  `_apply_dynamic_torch_uniforms()`;
- важная исправленная деталь: `terrain_material()` применяет активные torch uniforms
  к **новому** `ShaderMaterial`, чтобы раскопанные далеко чанки не оставались без
  параметров света;
- `godot/scripts/multiplayer_test.gd` исключает automatic torch lights из baked
  terrain base (`_terrain_baked_lights()`), чтобы не было двойного света;
- очередной per-chunk rebake факелов не используется в обычном runtime.

Тест:

```powershell
& $godot --headless --path .\godot --script res://tools/automatic_torch_runtime_self_test.gd
# AUTOMATIC_TORCH_RUNTIME_SELF_TEST checks=36 failures=0
```

Тест доказывает: mesh/vertex color не меняются, новый ShaderMaterial получает
active light, девятый light не теряется из runtime pool.

#### ВАЖНО: открытая регрессия света

Пользователь прислал screenshot: новые факелы за пределами начальной области
видны как объекты, но не дают нормального освещения terrain; визуально первые
один-два выглядят лучше. Это не считать решённым, даже при зелёном CPU self-test.

Для другой модели уже создана диагностическая задача:

`docs/reverse-engineering/agent-task-runtime-torch-regression-2026-11-19.md`

Она требует воспроизвести минимум 3 дальних факела и вывести per material / per
uniform / source-vertex evidence. Ожидаемый результат:

`docs/reverse-engineering/agent-result-runtime-torch-regression-2026-11-19.md`

Не заменять механику света до доказательства причины. Вероятные классы причины:
материал/экземпляр uniform, local-vs-world coordinates, hot reload, либо выбранный
terrain shader/renderer. Нужен render-visible regression test, не только CPU array test.

### 4.3 Автоматические факелы и пламя

- `godot/scripts/native_torch_runtime.gd` — source-driven placement;
- `godot/scripts/native_flame_emitter.gd` — original type-2 particle adapter;
- `godot/models/native_torch_visual.json` — `Misc_Light` data;
- `godot/tools/native_flame_self_test.gd`.

Недавно исправлено: flame atlas загружается как импортированный `Texture2D`, а не
raw `Image.load_from_file()`. Это устраняет editor-only warning и проблему в export.
`native_flame_self_test` — 52 assertions green.

### 4.4 Хомяки (интегрированы)

Исходный handoff:

`docs/reverse-engineering/agent-result-hamster-integration-2026-11-19.md`

Подготовленный патч Minimax был:

`C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\hamster-integration.patch`

и data patch:

`C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\hamster-integration-data.patch`

Патчи применены в живой проект. Интегрировано:

- `native_wild_hamster.gd`, `native_hamster_actor.gd`, `native_hamster_ai.gd`,
  `native_hamster_animations.gd`, `native_hamster_clips.gd`,
  `native_level_ground.gd`, command dispatcher/handlers;
- animation/clip/task data and self-tests;
- аддитивные Tcl-compatible методы в `native_tasklist.gd`:
  `cnt`, `rem`, `list`, `pop_front`, `has_pending`;
- host insertion blocks in `multiplayer_test.gd`:
  spawn AFTER `template_shift`, terrain-level ground loading AFTER world apply,
  food collection, navigation / callbacks.

Пользователь/agent зафиксировали source map shift `(40,40)`: не переносить старый
snapshot code до `WORLD_SPACE`; иначе животные висят на старых высотах.

Ключевые JSON-документы не оказались в supplied main patch, поэтому Codex добавил
их из проверенного Minimax tree:

- `godot/models/native_hamster_animations.json`;
- `godot/models/native_tasklist_commands.json`.

Проверки:

```text
NATIVE_HAMSTER_AI_SELF_TEST_OK assertions=69
NATIVE_HAMSTER_ACTOR_SELF_TEST_OK assertions=66
NATIVE_WILD_HAMSTER_SELF_TEST_OK assertions=57
```

Main-scene headless выводил:

```text
WILD_HAMSTER_NAV_READY level=58.50 size=53x25 blocked=475
WILD_HAMSTER Hamster_023 ... pos=(77.7272, -58.5, ...)
WILD_HAMSTER Hamster_024 ... pos=(56.0321, -54.5, ...)
WILD_HAMSTER Hamster_038 ... pos=(49.74837, -54.5, ...)
WILD_HAMSTER Hamster_039 ... pos=(76.9994, -58.5, ...)
```

Визуальная проверка в открытом editor window ещё нужна: UV/масштаб/естественность.

### 4.5 Battle world: только source-first foundation

Codex добавил только data-level foundation:

- `godot/scripts/native_battle_world.gd`;
- `godot/tools/native_battle_world_self_test.gd`.

Модель использует исследование:

`docs/reverse-engineering/minimax-battle-world-research-2026-11-19.md`

и JSON fixture рядом с ним (обращать внимание на linter path warning).

Пока это **не** подключённый игровой генератор: проверяется Stein 4×4 lattice,
authored presets, offset/stone rules. Не смешивать эту работу с terrain performance,
пока не будет отдельного source-backed шага интеграции.

## 5. Активные проблемы от пользователя

1. **Факелы далеко от стартовой зоны визуально не освещают terrain.** Срочно;
   см. §4.2 и отдельную активную diagnostic task.
2. Проверить, что минимальная задержка после удара реально ушла в Godot editor/на телефоне;
   walkmap оптимизация встроена, но terrain geometry rebuild ещё может стоить заметно.
3. Гномы: ранее замечены движение боком/пятясь вдоль Z, скольжение при беге и лазании,
   неидеальная навигация правой пещеры. Это отдельная система `surface_walk_action`,
   `native_walk_pose`, `native_walkmap`, path action; не смешивать с новой walkmap cache
   без reproducer.
4. Lighting визуально пока отличается от оригинала: FOW/owner bytes, gamma и secondary
   overflow не полностью восстановлены.
5. Пещеры/коридоры: части поверхностей, лесенчатые края, cave frame placement раньше
   были источником регрессий. Всегда проверять реальные screenshot/editor после geometry changes.

## 6. Последние пользовательские визуальные наблюдения

- Появившиеся far-corridor torches не освещают землю/стены достаточным образом.
- Сам факт наличия torch model/огня не доказывает terrain lighting.
- Original lighting мягче/локальнее и визуально значительно темнее, чем ранние Godot
  версии; не повышать просто global ambient как «исправление».

## 7. Рекомендуемый порядок дальнейшей работы

1. Выполнить и вернуть `agent-result-runtime-torch-regression-2026-11-19.md`.
2. Сначала исправить доказанную причину света, добавить render-visible regression test;
   потом вручную проверить 3+ факела далеко от initial cave.
3. Замерить real editor/mobile mining after walkmap cache. Если фриз остаётся,
   профилировать `_build_geometry` и GPU uploads отдельно, не ослабляя correctness walkmap.
4. Визуально проверить интегрированных хомяков; затем переходить к их полноценной
   игре/ИИ (питание, страх гномов, еда) только после подтверждения модели/поз.
5. Продолжить source-first battle-world generation отдельно от authored start map.

## 8. Ключевые тесты

```powershell
$godot = 'C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe'

& $godot --headless --path .\godot --script res://tools/native_walk_flags_self_test.gd
& $godot --headless --path .\godot --script res://tools/terrain_refresh_self_test.gd
& $godot --headless --path .\godot --script res://tools/automatic_torch_runtime_self_test.gd
& $godot --headless --path .\godot --script res://tools/native_flame_self_test.gd
& $godot --headless --path .\godot --script res://tools/native_hamster_ai_self_test.gd
& $godot --headless --path .\godot --script res://tools/native_hamster_actor_self_test.gd
& $godot --headless --path .\godot --script res://tools/native_wild_hamster_self_test.gd
```

Main scene minimal headless smoke (output should include four hamsters):

```powershell
& $godot --headless --path .\godot --quit-after 360 2>&1 |
  Select-String -Pattern 'WILD_HAMSTER_NAV_READY|WILD_HAMSTER Hamster_|SCRIPT ERROR|Parse Error'
```

## 9. Important reverse-engineering/docs index

- `docs/reverse-engineering/digging-and-cave-system.md`
- `docs/reverse-engineering/native-terrain-strike-2026-11-17.md`
- `docs/reverse-engineering/native-walk-flags-2026-11-17.md`
- `docs/reverse-engineering/world-model-lighting-2026-11-18.md`
- `docs/reverse-engineering/shader-pipeline-2026-11-18.md`
- `docs/reverse-engineering/runtime-performance-2026-11-18.md`
- `docs/reverse-engineering/minimax-battle-world-research-2026-11-19.md`
- `docs/reverse-engineering/agent-result-hamster-integration-2026-11-19.md`
- `docs/reverse-engineering/agent-result-walkmap-performance-2026-11-19.md`
- `docs/reverse-engineering/agent-result-lighting-architecture-2026-11-19.md`
- `docs/reverse-engineering/agent-task-runtime-torch-regression-2026-11-19.md`

## 10. Delivery contract for Minimax

When returning work to Codex:

1. Do not patch the live project directly unless user explicitly asks.
2. Write an `agent-result-<topic>-2026-11-19.md` in
   `C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\docs\reverse-engineering\`.
3. Include original evidence, exact current-file anchors, changed files, tests, known
   limitations and an `INTEGRATION_HANDOFF` block.
4. If supplying code, provide a small unified diff/patch relative to current live tree;
   never a full overwrite of `multiplayer_test.gd`.
5. Validate on Godot 4.7.2 headless; distinguish baseline failures from introduced ones.
