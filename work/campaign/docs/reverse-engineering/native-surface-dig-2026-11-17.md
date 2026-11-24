# Подход по стене → исходный удар → следующий забой

17.11.2026. В Godot связаны surface walk и corridor executor: гном с нижнего пола поднимается к верхнему забою, проигрывает исходный настенный удар, применяет source BDB-шаг по четырём углам и продолжает через `dig_next`. Некоторые угловые refs могут остаться прежними. Контрольные точки `(23,2) → (21,2)` дают два callback и две настоящие мутации. APK не собирался.

Предыдущее приращение — `native-surface-walk-2026-11-17.md`. Доказательства новых правил: соседний JSON и воспроизводимый `tools/audit_native_vector_fix.py --check`. Сохраняются прежние ограничения Calc1, object overlays, RNG/ресурсов и часов действий.

## Найденная ошибка цепочки стойки

Раньше runtime останавливался на `vector_fixdig` и проецировал его результат на наш пол. Однако `z_dignwalk.tcl:705–722` сначала вызывает **`vector_fix`**, затем передаёт `-target … -waving 0 -dig 1 -digpos …` в walk-action. Это ещё одно исходное преобразование, не произвольная поправка Y.

Реальный PMP-пример: `vector_fixdig` выдаёт local `(2.875,13.875,12)`, sample `(23,111)` имеет flags=0. `vector_fix` выбирает ближайший `(23,115)`, flags=3, и возвращает `(2.875,14.375,12)`. Таким образом, исходный запрос не следовало напрямую считать позицией подошвы или вручную прибавлять к нему 5/8 клетки.

## Перенесённые правила

Установленный `Diggles.exe`, preferred image base `0x400000`, SHA-256 `58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74`. JSON сохраняет шесть byte-spans, дизассемблирование, Tcl-хеш и source PMP fixture.

| Правило | Источник и точное поведение |
| --- | --- |
| `vector_fix` | Tcl wrapper `0x635940`, вызов `0x635ADB → 0x595770`. XY×8 с явным x87 rounding; world sample margin 48. За margin исходный XYZ возвращается без поиска. Внутри margin samples X<10 или Y<10 дают нулевой XYZ. |
| Начальная точка | Если её bit0 уже установлен, возвращаются округлённые XY/8 и **неизменный Z**, без чтения высоты. |
| Поиск | Квадратная спираль +X,+Y,−X,−Y, старт length1/limit48; строго меньшая квадратная дистанция, ties сохраняют ранний результат. Limit уменьшается по исходной формуле `int(float32(2*float32(sqrt(float32(d²))))+2.1)`. |
| После поиска | Z=`min(14.5,max(inputZ,H(bestX,bestY−1)+1))`. При отсутствии bit0 сохранён исходный fallback, `found_navigation=false`. Здесь нет дополнительного Y−5 и поиска floor anchor из `vector_fixdig`. |
| Режим копания | `0x42260D–0x4226E6`: `-dig` в byte +0x7BC пропускает обычный floor snap `0x423F20`. Object/dummy normalizer `0x424120` — отдельная ветка. |
| Конечная цель | `0x41A33E–0x41A374`: последняя точка берёт controller target XYZ. Surface executor теперь может сохранить нормализованный конечный XYZ; промежуточные точки продолжают использовать source wall/floor-depth. |
| Поза | `get_gnomeposition` проверяет floor bit в Y+1,Y,Y−1. Отсутствие известных входов остаётся unknown; известный floor bit достаточен даже при другом неизвестном probe. |
| Направление удара | `get_angle_num4`, `0x646D48–0x646E0C`, угол `0x40B700`: float32-нормализация, signed acos, исходные константы и trunc/mod4. Tcl `z_dignwalk.tcl:514–546` выбирает up/right/down/left и поворот спиной. |

Live x87 control word по-прежнему не захвачен. Runtime явно использует nearest-even; pure helper без выбранного режима возвращает unknown. Вычисление native XY/rounding выполняется после перевода в выбранные world coordinates.

## Исполнение и ограничения

`native_vector_fix.gd` реализует новое ядро; `native_dig_pose.gd` — направление настенного удара. Для подхода используется цепочка `vector_fixdig → vector_fix → surface route → normalized final XYZ`. История задания имеет planner `source_fixdig_vectorfix_surface_route`, оба запроса и причину нормализации.

Для нижнего пола сохраняется прежний floor adapter. Новый подход включается для актёра на другом уровне/стене либо при отсутствии поддерживаемого floor-подхода; продолжение начатого surface-job остаётся на этой же цепочке. Первую ячейку назначает пользователь напрямую: полный `get_digedge` ещё не перенесён. Последующие кандидаты приходят из native `dig_next`, включая Z clamp и Tcl −1.

До назначения чистый preview применяет настоящий accepted-step kernel к копии BDB facts. Host safety gate требует известный body sample после удара и неизменную source wall-depth стойки. Неподдержанная/неизвестная стойка отклоняется с понятным сообщением; это консервативная политика adapter, не доказанный native алгоритм уступания или падения. Текущая доступность повторно проверяется перед callback. Грунт меняется только после завершения work-клипа.

Добавлены четыре исходных `kletter_hack_oben/rechts/unten/links`, по **10 кадров**. Общий lazy-пакет теперь 16 clips / 192 кадровые ссылки, 9 322 314 bytes, SHA-256 `884a126696020d227113ec23a6cd6f074c9161cad5bf80628caebde39e96ca8c`. Кирка ещё не привязана к руке; проигрываются кадры тела. FPS12, скорость и один accepted step на callback остаются прежними adapter policies.

Переход к следующей точке сохраняет stamp работника: отмена прежнего locomotion-действия больше не сбрасывает принятую группу. Отмена подхода очищает оба действия и оставляет marks/BDB неизменными. Unknown/прерванный surface route также завершает связанный approach-job.

## Проверено

- `native_vector_fix_self_test`: **19 assertions**, initial/search/fallback, margin, unknown/FPU, основные направления и floor-contact probes.
- `native_surface_dig_self_test`: **22 assertions headless** в каждом из `authored_2p` и `authored_4p`; **23 OpenGL** с захватом середины первого work-клипа. Проверены отмена подхода, повторное назначение, две wall mutations, отсутствие ранней мутации, group3 на продолжении, два обновления nav cache, отсутствие утечек действий и сохранённая опора после ударов.
- Первый подход содержит 199 samples. Первый clip — `kletter_hack_rechts`, следующий — `kletter_hack_oben`. Конечные стойки `(21.5,3.25,12)` и `(21.375,3.25,12)` в native local XYZ. После первой мутации обновлено 1070 известных samples, изменены 5 bytes, 18 остались unknown у границы данных; следующая мутация снова обновила cache. Максимальный шаг 0.103568 при delta0.05 соответствует включённому run adapter, без присваивания позиции забоя.
- Регрессии: прежняя очередь 37 / четыре мутации; worker195; parallel21; gestures37; surface walk44. Source exporter `--check`, новый source audit `--check`, lint41 scripts и smoke всех трёх сцен проходят. Проверки runtime logs не содержат ошибок/предупреждений.

Кадры: `native-surface-dig-2026-11-17/wall_dig.png`, три общих ракурса и `scene_space.json`. JSON дополнен normalized target и последними четырьмя ref changes. Крупный план работы просмотрен в desktop OpenGL. Android GPU не проверялся.

Для воспроизведения из workspace:

```powershell
python -B tools/audit_native_vector_fix.py --check
python -B tools/export_dwarf_surface_walk.py --check
& 'C:/Users/frant/OneDrive/Рабочий стол/godot/Godot_v4.7.2-stable_win64_console.exe' --headless --path godot --debug --ignore-error-breaks --script res://tools/native_vector_fix_self_test.gd
& 'C:/Users/frant/OneDrive/Рабочий стол/godot/Godot_v4.7.2-stable_win64_console.exe' --headless --path godot --debug --ignore-error-breaks --script res://tools/native_surface_dig_self_test.gd
```

Следующая приёмка — пройти именно через изменившийся после ударов участок, а затем расширить связный коридор. Native Calc1/owner summaries, object footprints, точная первая кромка `get_digedge`, tool attachment и расписание accepted hits остаются отдельными зависимостями.
