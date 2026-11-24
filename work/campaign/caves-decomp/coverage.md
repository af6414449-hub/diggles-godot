# Карта покрытия декомпиляции Diggles (v3)

Сгенерировано `coverage_map3.py`. Корпус: `C:\diggles-ghidra\out\decomp` (Diggles.exe) и `C:\diggles-ghidra\out_port\decomp` (DigglesPort.dll).

Типы: `pseudo` — псевдофункции раскрутки SEH (не код); `crt` — статически прилинкованный UCRT/MSVC-runtime; `game` — код игры.

Атрибуция: BFS вверх по графу вызовов (до 6 уровней) до ближайшей именованной функции; `якорь` — эта функция.

Тиры покрытия: 0 — не упомянута; 1 — упомянута один раз; 2 — 2 раза; 3 — цитируется со ссылкой `файл:строка`.


## Diggles.exe

- записей в корпусе: **11373**
- псевдофункций SEH (`Unwind_*` и пр.): **6105**
- реальных функций: **5268**
- из них распознано как UCRT/runtime: **654**
- из них код игры: **4614**
- покрыто отчётом (тир ≥ 1): **183** (1.6 % корпуса, 3.5 % реальных функций)
- тир 3 (разобрано детально, со ссылками): **168**

| подсистема | функций | тир0 | тир1 | тир2 | тир3 |
|---|---:|---:|---:|---:|---:|
| pseudo/SEH-unwind | 6105 | 6105 | 0 | 0 | 0 |
| unattributed | 2002 | 1981 | 1 | 2 | 18 |
| scripting/Tcl (global cmds) | 1019 | 936 | 3 | 7 | 73 |
| runtime/UCRT | 654 | 654 | 0 | 0 | 0 |
| scripting/Tcl (object cmds) | 566 | 556 | 0 | 1 | 9 |
| app/lifecycle | 525 | 485 | 0 | 0 | 40 |
| rendering/display | 221 | 209 | 0 | 0 | 12 |
| world/terrain | 129 | 122 | 0 | 0 | 7 |
| objects/AI | 49 | 49 | 0 | 0 | 0 |
| scripting/Tcl (class defs) | 49 | 48 | 0 | 0 | 1 |
| rendering | 19 | 16 | 1 | 0 | 2 |
| other:FindHandler_class | 14 | 14 | 0 | 0 | 0 |
| world/3db | 9 | 5 | 0 | 0 | 4 |
| audio | 4 | 4 | 0 | 0 | 0 |
| fluids | 2 | 0 | 0 | 0 | 2 |
| rendering/dxexec | 1 | 1 | 0 | 0 | 0 |
| scripting/Tcl | 1 | 1 | 0 | 0 | 0 |
| other:FindHandlerForForeignException_class | 1 | 1 | 0 | 0 | 0 |
| other:input_processor_char_class | 1 | 1 | 0 | 0 | 0 |
| other:make_input_adapter_character_source | 1 | 1 | 0 | 0 | 0 |
| other:RenderJob | 1 | 1 | 0 | 0 | 0 |


## DigglesPort.dll

- записей в корпусе: **1114**
- псевдофункций SEH (`Unwind_*` и пр.): **173**
- реальных функций: **941**
- из них распознано как UCRT/runtime: **87**
- из них код игры: **854**
- покрыто отчётом (тир ≥ 1): **7** (0.6 % корпуса, 0.7 % реальных функций)
- тир 3 (разобрано детально, со ссылками): **7**

| подсистема | функций | тир0 | тир1 | тир2 | тир3 |
|---|---:|---:|---:|---:|---:|
| unattributed | 707 | 701 | 0 | 0 | 6 |
| pseudo/SEH-unwind | 173 | 173 | 0 | 0 | 0 |
| runtime/UCRT | 87 | 87 | 0 | 0 | 0 |
| app/lifecycle | 72 | 72 | 0 | 0 | 0 |
| scripting/Tcl (global cmds) | 57 | 56 | 0 | 0 | 1 |
| scripting/Tcl (object cmds) | 10 | 10 | 0 | 0 | 0 |
| audio | 6 | 6 | 0 | 0 | 0 |
| other:FindHandler_class | 1 | 1 | 0 | 0 | 0 |
| world/terrain | 1 | 1 | 0 | 0 | 0 |

