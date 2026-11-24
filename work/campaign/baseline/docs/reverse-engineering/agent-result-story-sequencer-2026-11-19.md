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
Запуск Godot 4.7.2 headless: `STORY_SEQUENCER_SELF_TEST_OK commands=21 actors=1`.

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

INTEGRATION_HANDOFF: docs/reverse-engineering/agent-result-story-sequencer-2026-11-19.md
