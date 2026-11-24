# Исходные программы материалов и проверка результатов Minimax — 18.11.2026

Подключены два исходных режима материалов выбранной кладки/фона: 21 поверхность `model_solid` и 11 `model_blend`. Прежний общий порог прозрачности 0.35 заменён параметрами исходного material slot каждой поверхности. Числовой коэффициент света моделей теперь читается из подтверждённого общего поля с грунтом.

Из параллельного проекта Minimax использованы кандидатная таблица алиасов и идея API. Его проект читался только; его скрипты не запускались. В нашем проекте таблица независимо пересобрана из оригинальных Tcl/3DB, проверена и подключена к контролю анимаций копания. Диспетчер/ИИ Minimax пока не подключены: выявлены конкретные расхождения семантики Tcl.

## Общий gain моделей и грунта

Первичный источник: установленный `Diggles.exe`, SHA-256 `58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74`.

Конструктор manager передаёт `manager+0x28B0` конструктору terrain (`0x464979..0x464988`). Terrain пишет float32 `0.10000000149011612` в своё поле `+0x1034` (`0x4C462D..0x4C4637`). Сумма адресов:

```text
manager + 0x28B0 + 0x1034 = manager + 0x38E4
```

Model renderer копирует именно `manager+0x38E4` в свой gain (`0x48603E..0x486044`). Таким образом, прежнее значение 0.1 было правильным численно, но его обоснование как отдельного host input было неполным. Теперь поле, значение float32 и адресное тождество извлекаются и проверяются экспортёром. `native_scene_profile.gd` проверяет согласованность с terrain gain; world-model refresh использует экспортированное значение.

Найденный ранее callback `set_brightness` (`0x63CCE0`) принимает один аргумент Tcl и меняет в том числе это поле. Полное воспроизведение live setter, transient modifiers и захват состояния запущенного оригинала ещё не выполнены. Извлечён именно constructor default.

Данные и доказательства: `godot/models/native_world_model_lighting.json`, `tools/export_world_model_lighting.py` — теперь 12 диапазонов инструкций и 10 числовых констант.

## Link slot → material group → shader

3DB link содержит шесть uint16. Его второе слово — slot, а не неизвестный флаг. Reader `0x402443..0x402502` переносит его в runtime link+0; первое слово переносится в material index link+4. Dispatch `0x4860C0..0x486189` использует slot при выборе shader из material group.

Default group устанавливается в `0x45A1EC..0x45A24B`. Для выбранных объектов используются:

| Исходный slot | Shader | Alpha test | Смешение RGB | Depth write |
| --- | --- | --- | --- | --- |
| 1 | 7 / model_solid | GREATER 127 | ONE / ZERO | включён |
| 3 | 6 / model_blend | GREATER 0 | SRCALPHA / INVSRCALPHA | включён |

`model_solid` наследует `model_blend` и переопределяет ref/src/dst (`0x458367..0x458397`). `model_blend` задаётся в `0x458252..0x4582A1`, а наследуемые defaults — в `0x4557FD..0x455875`. Render-state binder подтверждает назначение полей (`0x45E46C..0x45E592`).

Оба используют model stage2: RGB texture × CURRENT; alpha texture × белый TFACTOR. Отдельный secondary добавляется до gamma, как в `Shaders/UL2CS.fx`; GREATER отвергает равенство порогу, как в `Shaders/Common.fxh`. Поэтому в обоих новых shader-путях discard использует `<=`, а не `<`.

Tcl `animinit.tcl`, `dummy_hinterlegung.tcl`, `dummy_wandboden.tcl` проверены на material override. Эта выборка использует default/zwrite context. Решение не распространено на произвольные animated actors и классы с динамической заменой материалов.

Экспортёр `tools/export_native_model_programs.py` читает исходные два 3DB, сопоставляет 12 уже используемых объектов с текущим manifest и проверяет неизменность points/UV перед экспортом slot. `godot/models/native_model_programs.json` содержит hashes, raw links, программы и 11 диапазонов инструкций. В main shader выбирается отдельно для каждой поверхности; blend shader сохраняет исходный depth write.

Ограничения: Godot transparent packet sorting не повторяет native batching/sort; culling/reflection остаётся прежним адаптером. Полный live owner/FOW и динамические TFACTOR/material changes не восстановлены. Остальные классы всё ещё используют прежний путь освещения.

## Проверенные результаты Minimax

Источник кандидата: `C:\Users\frant\.minimax\sessions\mvs_e213cb8b6788404489ad3b0b5c39827f\workspace\Diggles-mcode`. Снимок/файлы в этой папке не редактировались. Ни собственные тесты агента, ни скопированные им прежние файлы основного проекта не считаются новой проверкой нашей сцены.

`tools/export_native_animation_aliases.py` использует безопасный Tcl interpreter для исходного `z_anims.tcl`: callbacks только собирают `set_class_anim`/`set_class_animset`, `member` игнорируется. Geometry не загружается; Reader проходит до animation records `mann.3db` и проверяет именно пары object/clip и валидность индексов кадров.

Подтверждены 926 конечных aliases, 20 animsets и 884 уникальных targets. Все literal targets этой таблицы — `mann.*`. Gender DB substitution не выдумывается и не выполняется автоматически. Два повторных определения `bedsleepstart` сохраняют последнее значение `mann.schlafen_bett_end`; отсутствующий `bedsleeploop` не добавляется как будто он есть в оригинале.

В кандидатной таблице шесть face descriptors содержали исходные фигурные скобки. Наш экспорт сохраняет значение аргумента после Tcl decoding. Остальные aliases/frames/roles совпали. Аудит с hash кандидата: [minimax-alias-audit-2026-11-18.json](minimax-alias-audit-2026-11-18.json).

Runtime API переработан: `has_target` требует точный адрес и не принимает `hamster.gehen_start` из-за наличия `mann.gehen_start`; `get_animset` возвращает независимую копию. Main проверяет имя и число кадров pick-feedback clip по общей таблице перед загрузкой meshes. Никакие 884 клипа целиком в память сцены не загружаются.

## Почему диспетчер/ИИ агента требуют следующего приращения

В заметке агента сказано, что подстановки всегда выполняются до постановки в tasklist. Контрпример прямо в оригинале: `z_spare_fun.tcl:299`:

```tcl
tasklist_add this {play_anim standloop[string index abcd [irandom 4]]}
```

Фигурные скобки откладывают `[irandom 4]` до `eval` извлечённой команды. Проверка реальным Tcl8.6.12 со stub `irandom` показала 0 вызовов при постановке и 1 при eval. Обычный split/tokenize без подстановок этого не воспроизводит. В `z_work_states.tcl:13..22` команда извлекается, удаляется, затем исполняется через `eval`.

Вторая заявленная эквивалентность — «false прекращает цепочку» — не является общим правилом Tcl: `return 0` с успешным completion code позволяет выполнить следующую команду. Нужны отдельные contracts для ошибок/control codes конкретных native-команд. Доказательство с исходной строкой, hash и результатами: [minimax-dispatch-semantics-2026-11-18.json](minimax-dispatch-semantics-2026-11-18.json).

Материалы агента по потребностям/сменам пригодны для дальнейшей сверки. Следующий AI шаг должен связать actor queue, callbacks/interruptions, часы и только затем выбор занятий. Его числовая сортировка потребностей уже отличается от исходного `lsort -index 1`; это также нельзя считать принятым native поведением. Речь, сон и автономная работа пока не объявляются перенесёнными.

## Проверки и пределы приёмки

Все три source exporters проходят `--check`. Headless Godot4.7.2: 11 сценариев, 1564 проверки — aliases23, material programs9, world light31, terrain556, automatic torches33, feedback visual13, hanging branch16/12 mutations, depth route19, manual region27, model normals208, mining feedback629. Lint: 0 errors/0 warnings. Smoke: 3 сцены, 0 errors/0 warnings.

Логи и сводка: [validation.json](model-programs-2026-11-18/validation.json), [lint.json](model-programs-2026-11-18/lint.json), [smoke.json](model-programs-2026-11-18/smoke.json).

**Новая GPU-приёмка не выполнена.** Автоматическая проверка разрешения OpenGL-команд завершилась ошибкой лимита использования; команды не запускались. Это ошибка механизма проверки, не заключение о небезопасности. Подготовлены четыре GPU-теста alpha127/128, промежуточного blending и alpha0 в `native_model_programs_self_test.gd -- --gpu`, а также отдельный capture directory для world-light comparison (`--capture-world-light --capture-model-programs`). Их результат пока неизвестен. Старые 37 GPU checks относятся к предыдущему этапу и не подтверждают новые material shaders.

APK не пересобирался. Совпадение итогового освещения с оригиналом и FPS телефона этим этапом не доказаны.
