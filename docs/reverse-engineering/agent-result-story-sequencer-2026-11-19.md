# Story sequencer — результат первого прохода

Источник фактов: установленная игра, read-only каталог
`C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data`.
Снимок `MiniMax` в качестве источника не использовался.

## Фаза 1

Добавлен data-only модуль `godot/scripts/native_story_sequencer.gd`.
Он не создаёт `Node3D` и не вызывает игровые API. Состояние хранит:

- `actors`, `objects`, `enabled`;
- `map_size`, `camera`, `loading`;
- журнал нормализованных команд `trace`;
- список команд, оставленных адаптером как неизвестные.

Таблица формата команд вынесена в `godot/models/native_story_sequencer_commands.json`.

Поддержаны подтверждённые команды формата сценария: `show_loading`, `obj_clear`,
`map create`, `sel`, `set_view`, `call`, `MapTemplateSet`, `sm_def_temp_group`,
`sequence_enable` и `sequence_disable`. Tcl-комментарии, пустые строки и префиксы
`+`/`-` разбираются отдельно; команды не подменяются эвристическими аналогами.

## Разбор оригинального Tcl

Оригинал: `Scripts/classes/story/sequencer.tcl`, 60 920 байт.
Ключевые процедуры и строки:

| Область | Процедуры | Строки |
|---|---|---:|
| состояние и lifecycle | `reset`, `sequencer_activate`, `init_sequencer`, `shut_sequencer` | 355–426, 526–555 |
| включение веток | `reset_enablelist`, `sequence_enable`, `sequence_disable` | 451–466, 557–586 |
| интерпретация строк | `parse_next` | 588–638 |
| актёры | `add_actor`, `parse_actors`, `sq_actor`, `do_idle` | 467–508, 807–832, 974–1080 |
| позиции/объекты | `parse_pos`, `parse_pen`, `parse_objects`, `sq_object` | 780–930 |
| текст/звук | `parse_text`, `sq_text`, `parse_audio_file`, `sq_audio`, `sq_music`, `sq_sound` | 748–778, 1082–1157, 1544–1581 |
| камера/экран | `init_camsets`, `add_camset`, `sel_camset`, `sq_camera`, `sq_screenvibe` | 1214–1303, 1239–1260 |
| ожидание | `sq_wait`, `do_wait` | 1305–1398 |

`parse_next` читает строки до EOF, пропускает пустые строки и комментарии,
распознаёт префиксы `+`/`-`, исполняет разрешённые строки через Tcl `eval` и
останавливается после `do_*`, если не установлен `dontwait` (строки 588–638).
Полная native-семантика ожиданий, объектов, звука и Tcl-подстановок пока остаётся
адаптером следующей фазы.

## Golden-трасса

Для `GameScripts\single_Seq_FirstContact.tcl` (установленная игра) выбран golden
на 13 исполняемых команд:

1. `show_loading yes`
2. `obj_clear`
3. `map create 300 300`
4. `sel /obj`
5. `set_view 62.2 22.1 1.5 -0.3 0.0`
6. `call templates/urw_unq_vodo_001_a.tcl`
7. `MapTemplateSet 12 12`
8. `call templates/urw_gng_004_a.tcl`
9. `MapTemplateSet 44 20`
10. `call templates/zwerg_exit_left.tcl`
11. `MapTemplateSet 60 20`
12. `show_loading no`
13. `sm_def_temp_group temp_name {...}`

Строки оригинала: `single_Seq_FirstContact.tcl:1–22`.

Тест: `godot/tools/native_story_sequencer_self_test.gd`.
Запуск Godot 4.7.2 headless:
`STORY_SEQUENCER_SELF_TEST_OK commands=24 dispatched=24 actors=1 map=(300, 300)`.

Тест содержит 13 команд golden-трассы FirstContact плюс 11 Tutorial-команд
(`sq_actor`, `sq_text`, `sq_audio`, `sq_camera`, `sq_screenvibe`, `do_wait`,
`do_text`, `call_method`, `timer_event`, `keybind`), итого 24 исполняемые команды.
`skipped_commands` пуст — ни одна команда не реализована предположением.

В golden-тест также включены проверки записи actor/text/audio/camera/screen/wait
команд и Tutorial-команд `call_method`, `timer_event`, `keybind` как data-only
событий; реальное исполнение этих подсистем остаётся adapter.

## Фазы 2–3 и ограничения

Подключение к существующим гномам, реальные реплики/аудиомаркеры, камера сцены и
полное прохождение истории ещё не выполнены. Это намеренно не маскируется
заглушками: добавлена изолированная `godot/scenes/story_sequencer_test.tscn` с
минимальным scene-level smoke harness, но пока отсутствует story-сцена и адаптер игровых
акторов, а `single_Tutorial.tcl` зависит от `oberwelt.tcl`, триггеров и timer API.
Код MCode и запрещённые файлы не изменялись. Кодировка оригинальных Tcl-файлов
для прочитанного FirstContact — ASCII-совместимый UTF-8 набор без кириллических
реплик; каталог локализованных текстов ещё требует отдельной проверки cp1251.

Следующий шаг: вынести command schema в отдельные данные, добавить Tcl-подстановки
для `do_*`/`sq_*`, затем подключить actor/camera adapters и headless-сцену.
Переходный интерфейс для этого уже добавлен: `dispatch_trace(adapter: Callable)`.

## Перенос в основной проект MiniMax

Перенос выполнен 2026-11-19 из рабочего дерева
`C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles` в основной проект
`C:\Users\frant\OneDrive\Документы\MiniMax\Diggles`.

Перенесены только перечисленные story-файлы, относительные пути сохранены:

```text
godot/scripts/native_story_sequencer.gd
godot/tools/native_story_sequencer_self_test.gd
godot/tools/story_sequencer_test_scene.gd
godot/scenes/story_sequencer_test.tscn
godot/models/native_story_sequencer_commands.json
docs/reverse-engineering/agent-result-story-sequencer-2026-11-19.md
docs/plan/story-sequencer-integration-handoff-2026-11-19.md
```

Перед копированием проверено состояние цели: в MiniMax ни одного из этих файлов
не было, поэтому ручное слияние не потребовалось. Копирование побайтовое —
хеши источника и назначения совпадают.

Добавлено в дерево `godot/` — 8 файлов, 0 изменённых, 0 удалённых (сверка по
хешам со снимком до переноса):

```text
models/native_story_sequencer_commands.json
scenes/story_sequencer_test.tscn
scripts/native_story_sequencer.gd
scripts/native_story_sequencer.gd.uid
tools/native_story_sequencer_self_test.gd
tools/native_story_sequencer_self_test.gd.uid
tools/story_sequencer_test_scene.gd
tools/story_sequencer_test_scene.gd.uid
```

Три `.uid` — сайдкары, созданные штатным импортом Godot 4.7.2; в исходном
рабочем дереве они отсутствовали.

### Проверки в MiniMax

Godot 4.7.2, headless, проект `MiniMax/Diggles/godot`:

```text
STORY_SEQUENCER_SELF_TEST_OK commands=24 dispatched=24 actors=1 map=(300, 300)
camera={ "x": 62.2, "y": 22.1, "zoom": 1.5, "rx": -0.3, "ry": 0.0 }   exit=0
STORY_SCENE_READY commands=4 dispatched=4 map=(300, 300)
camera={ "x": 62.2, "y": 22.1, "zoom": 1.5, "rx": -0.3, "ry": 0.0 }   exit=0
```

stderr пуст в обоих запусках, ошибок и предупреждений нет.

Существующие MCode self-tests после переноса — без изменений и зелёные:

```text
native_hamster_actor_self_test     exit=0  assertions=66
native_hamster_ai_self_test        exit=0  assertions=69
native_wild_hamster_self_test      exit=0  assertions=57
native_battle_world_self_test      exit=0  checks=8 failures=0
native_torch_placement_self_test   exit=0  checks=70 failures=0
native_dig_next_self_test          exit=0  assertions=101 fixtures=22
```

`multiplayer_test.tscn` и `scripts/multiplayer_test.gd` не изменялись — battle-сцена
не тронута. Файлы из запрещённого списка не трогались. APK не пересобирался.

INTEGRATION_HANDOFF: docs/plan/story-sequencer-integration-handoff-2026-11-19.md
