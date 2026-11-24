# Tcl dependency and command index

Дата: 2026-11-14

## Получено

- 3824 Tcl-файла;
- 3822 непустых;
- 3223 файла содержат объявления `proc`;
- `Templates` — 3295 файлов;
- `Scripts` — 479 файлов;
- `GameScripts` — 48 файлов.

Индекс сохранён в `tcl-index.json`.

## Наиболее частые игровые команды

| Команда | Вхождения |
|---|---:|
| `sel` | 67966 |
| `set_physic` | 63563 |
| `set_owner` | 63496 |
| `set_boxed` | 63436 |
| `set_autolight` | 63411 |
| `map_setlayer2` | 2971 |
| `map_template` | 1574 |
| `tasklist_add` | 1521 |
| `sq_camera` | 944 |
| `sq_actor` | 1058 |
| `set_class_anim` | 1838 |
| `do_action` | 2595 |
| `fight_action` | 377 |
| `trigger` | 439 |
| `def_event` | 372 |
| `handle_event` | 371 |
| `timer_event` | 364 |

## Архитектурный вывод

Tcl нельзя переносить как пассивные данные. Он обращается к большому встроенному API движка: объектам, картам, физике, анимациям, событиям, заданиям, камере и боевым действиям.

Наиболее перспективная стратегия — восстановить минимальный движковый API и исполнять оригинальные Tcl-шаблоны, вместо ручной переписи тысяч файлов.

## Первый API-контур

1. `new`, `sel`, `call_method`;
2. `map_template`, `map_setlayer2`;
3. `set_owner`, `set_physic`, `set_boxed`, `set_autolight`;
4. `set_class_anim`, `set_anim`;
5. `sq_camera`, `sq_actor`, `sq_object`;
6. `do_action`, `tasklist_add`, базовые события.

Именно этот контур следует проверять на вертикальном срезе одной карты.
