# Story sequencer — инструкция переноса в основной проект

Этот файл переносит текущие изменения из рабочего дерева
`C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles` в основной проект
`C:\Users\frant\OneDrive\Документы\MiniMax\Diggles`.

## Что переносится

Скопировать только эти новые файлы:

```text
godot/scripts/native_story_sequencer.gd
godot/tools/native_story_sequencer_self_test.gd
godot/tools/story_sequencer_test_scene.gd
godot/scenes/story_sequencer_test.tscn
godot/models/native_story_sequencer_commands.json
docs/reverse-engineering/agent-result-story-sequencer-2026-11-19.md
docs/plan/story-sequencer-integration-handoff-2026-11-19.md
```

## Статус переноса: выполнен 2026-11-19

Перенос в `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles` выполнен, все семь
файлов на месте (хеши источника и назначения совпадают). В `MiniMax` до
переноса ни одного из этих файлов не было, поэтому ручное слияние не
потребовалось. Остальные файлы проекта не синхронизировались.

В дерево `godot/` добавлено 8 файлов, 0 изменённых, 0 удалённых: пять
перенесённых и три `.uid`-сайдкара, созданных штатным импортом Godot 4.7.2.
`multiplayer_test.tscn` и `scripts/multiplayer_test.gd` не тронуты.

Проверки в целевом дереве (headless, exit=0, stderr пуст):

```text
STORY_SEQUENCER_SELF_TEST_OK commands=24 dispatched=24 actors=1 map=(300, 300)
STORY_SCENE_READY commands=4 dispatched=4 map=(300, 300)
```

Существующие MCode self-tests после переноса — зелёные, без изменений:
`native_hamster_actor_self_test` (66), `native_hamster_ai_self_test` (69),
`native_wild_hamster_self_test` (57), `native_battle_world_self_test` (8 checks),
`native_torch_placement_self_test` (70), `native_dig_next_self_test` (101).

Ниже — инструкция для повторного переноса, если story-файлы снова появятся
в рабочем дереве. Существующие файлы проекта не заменять и не выполнять полную
синхронизацию каталогов.

## Безопасный перенос PowerShell

Перед копированием убедиться, что параллельная работа сохранена. Команды ниже
не удаляют файлы и не затрагивают зоны MCode.

```powershell
$src = 'C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles'
$dst = 'C:\Users\frant\OneDrive\Документы\MiniMax\Diggles'
$files = @(
  'godot\scripts\native_story_sequencer.gd',
  'godot\tools\native_story_sequencer_self_test.gd',
  'godot\tools\story_sequencer_test_scene.gd',
  'godot\scenes\story_sequencer_test.tscn',
  'godot\models\native_story_sequencer_commands.json',
  'docs\reverse-engineering\agent-result-story-sequencer-2026-11-19.md',
  'docs\plan\story-sequencer-integration-handoff-2026-11-19.md'
)
foreach ($f in $files) {
  $target = Join-Path $dst $f
  New-Item -ItemType Directory -Force -Path (Split-Path -Parent $target) | Out-Null
  Copy-Item -LiteralPath (Join-Path $src $f) -Destination $target -Force
}
```

Если какой-либо файл уже появился в `MiniMax`, сначала сравнить его вручную:

```powershell
Compare-Object `
  (Get-Content -LiteralPath (Join-Path $src 'godot\scripts\native_story_sequencer.gd')) `
  (Get-Content -LiteralPath (Join-Path $dst 'godot\scripts\native_story_sequencer.gd'))
```

## Проверка после переноса

Запустить Godot из основного дерева:

```powershell
$godot = 'C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe'
$project = 'C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot'
$log = Join-Path $env:TEMP 'minimax_story_sequencer_selftest.log'
$p = Start-Process -FilePath $godot -ArgumentList @('--headless','--path',$project,'--script','res://tools/native_story_sequencer_self_test.gd') -RedirectStandardOutput $log -RedirectStandardError ($log + '.err') -PassThru -NoNewWindow
if (-not $p.WaitForExit(120000)) { Stop-Process -Id $p.Id -Force; throw 'TIMEOUT' }
Get-Content $log
Get-Content ($log + '.err') -ErrorAction SilentlyContinue
```

Ожидаемая строка:

```text
STORY_SEQUENCER_SELF_TEST_OK commands=24 dispatched=24
```

Для проверки именно как сцены запускать отдельную сцену, не battle-сцену:

```powershell
$p = Start-Process -FilePath $godot -ArgumentList @('--headless','--path',$project,'--scene','res://scenes/story_sequencer_test.tscn') -RedirectStandardOutput $log -RedirectStandardError ($log + '.err') -PassThru -NoNewWindow
if (-not $p.WaitForExit(120000)) { Stop-Process -Id $p.Id -Force; throw 'TIMEOUT' }
Get-Content $log
```

Ожидается `STORY_SCENE_READY commands=4 dispatched=4`. Сцена изолирована и не
меняет `multiplayer_test.tscn`.

## Что именно реализовано

`native_story_sequencer.gd` — чистая модель без `Node3D`. Она разбирает Tcl-подобные
строки и фиксирует в trace команды `show_loading`, `obj_clear`, `map create`,
`sel`, `set_view`, `call`, `MapTemplateSet`, `sm_def_temp_group`,
`sequence_enable` и `sequence_disable`. Неизвестные команды не исполняются и
попадают в `skipped_commands`.

Команды `sq_actor`, `sq_object`, `sq_text`, `sq_audio`, `sq_music`, `sq_camera`,
`sq_screenvibe`, `do_wait`, `do_text`, `call_method`, `timer_event` и `keybind`
тоже реализованы — они фиксируются как нормализованные события trace и
передаются в adapter, но игровые объекты не вызывают.

`native_story_sequencer_self_test.gd` — golden-тест для
`single_Seq_FirstContact.tcl`: 13 исполняемых команд плюс 11 Tutorial-команд,
итого 24; карта 300×300, камера `62.2 22.1 1.5 -0.3 0.0`, финальный
`show_loading no`, `skipped_commands` пуст.

`models/native_story_sequencer_commands.json` — таблица формата команд, категорий,
аргументов и статусов реализации.

Последнее расширение добавило команды Tutorial-сценария `call_method`,
`timer_event` и `keybind`; они фиксируются как события адаптера и не вызывают
игровые объекты в data-only фазе.

Добавлен `dispatch_trace(adapter: Callable)`: он передаёт нормализованные
события внешнему runtime-адаптеру, куда в основном проекте подключаются гномы,
анимации, звук, камера и таймеры.

`story_sequencer_test.tscn` + `tools/story_sequencer_test_scene.gd` — отдельная
минимальная scene-level smoke-сцена. Она изолирована и не меняет
`multiplayer_test.tscn`.

## Не переносить и не изменять

Не затрагивать файлы MCode:

```text
scripts/native_hamster_*.gd
scripts/native_wild_hamster*.gd
scripts/native_hamster_clips.gd
scripts/native_hamster_ai.gd
scripts/native_hamster_actor*.gd
scripts/native_hamster_animations.gd
models/native_hamster_*
tools/native_hamster*
tools/native_wild_hamster*
scripts/native_dwarf_needs.gd
scripts/dwarf_life_runtime.gd
scripts/dwarf_sleep_runtime.gd
scripts/native_actor_tasks.gd
scripts/native_task_eval.gd
scripts/native_work_clock.gd
scripts/native_command_dispatcher.gd
scripts/native_command_handlers.gd
scripts/native_tasklist.gd
```

Не собирать APK в рамках этого переноса.

## Следующий этап после интеграции

Data-only фаза завершена: все команды из модели уже разбираются и уходят в
`skipped_commands` только если не распознаны. Дальше нужен runtime adapter
отдельным файлом, не трогая `native_story_sequencer.gd`:

```text
godot/scripts/native_story_scene_adapter.gd
godot/scenes/story_first_contact_test.tscn
godot/tools/story_first_contact_self_test.gd
```

Требования к адаптеру:

- принимает события через `dispatch_trace`;
- не меняет `native_story_sequencer.gd` для доступа к `Node3D`;
- находит существующих гномов сцены через явный scene contract;
- переводит `sq_actor` в actor operations;
- переводит `do_text` в очередь реплик с номером строки;
- переводит `sq_camera`/`set_view` в camera operations;
- `sq_audio`/`sq_music` пока может выдавать documented adapter event, если
  аудио ещё не подключено;
- завершает сцену детерминированно и выдаёт итоговый trace.

Первая вертикальная история — `single_Seq_FirstContact.tcl`. Не начинать с
полной `single_Tutorial.tcl`: Tutorial зависит от `oberwelt.tcl`, триггеров,
таймеров и input bindings.

Tcl-источник читать только из установленной игры:
`C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data`.

