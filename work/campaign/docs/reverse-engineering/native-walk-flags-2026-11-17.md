# Производитель navigation bits 0/1 — 17.11.2026

**Подтверждено:** найден terrain-производитель `0x5A6B40`; его целочисленное правило восстановлено для положительных samples с готовыми native bounds. Созданы чистые `godot/scripts/native_walk_flags.gd` и `godot/tools/native_walk_flags_self_test.gd`. Исследовательская подзадача установила контракт байтов. Последующая runtime-интеграция с TerrainState и dirty cache описана в [native-fix-dig-2026-11-17.md](native-fix-dig-2026-11-17.md); object overlays ещё не подключены.

Адреса — preferred VA установленного `Diggles.exe`, image base `0x400000`, SHA-256 `58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74`. Источники, все 31 адрес сравнения и fixtures — в соседнем JSON. Прочитаны EXE через pefile/Capstone, `tools/.cache/diggles-text-disassembly.txt`, исходные `data/Templates/multi_start_010.pmp` и `data/BlockDB2.BDB`. APK не собирался; чужие runtime/controller/exporter-файлы не менялись.

## Источник данных и единицы

**Подтверждено:** sample XY = map XY × 8. Искомый byte: `C(sx>>3,sy>>3)+0x3C+(sy&7)*8+(sx&7)`, runtime stride клетки `0x7C`. Writer `0x596550` выбирает `C+0x3C` в `0x59669A–0x5966C1`, записывает byte в `0x596703–0x596709`. Это **замена**, не OR со старым состоянием.

**Подтверждено:** reader `0x595E40` строит временную карту **текущих** высот: берёт `C+0`, индексирует BDB metadata stride `0x59` (`0x595F41–0x595F55`), копирует первые 64 bytes построчно (`0x595FA8–0x595FEA`; полный блок — `0x596014–0x596177`). Формула:

`H(sx,sy) = M[current_ref(sx>>3,sy>>3)][(sy&7)*8+(sx&7)]`.

Это не next-height, mark или PMP trailing attribute. Подготовка буфера и вызов reader из производителя — `0x5A6BD7–0x5A6C3B`.

## Initial и dirty — разные пути

**Подтверждено:** PMP содержит готовые navigation bytes. `0x599D80–0x599DC2` раскодирует counted-U16 RLE: `value=word&3`, `count=word>>2`, нулевой count означает `0x4000`; `0x599E50` вызывает writer `0x596550`. После этого `0x599E82–0x599E9D` запрашивает `0x40000`.

**Подтверждено:** `0x40000` в dispatcher `0x5A3FD0` разворачивается в `6`, `0x10`, `0x40` (`0x5A403B–0x5A4090`). Здесь очереди **2+4**, без очереди 1. Начальную RLE-карту нельзя молча заменять новым terrain-пересчётом: сам этот путь его не вызывает.

**Подтверждено:** после принятого strike `0x5972BF` инвалидирует `(8x−8,8y−8,8x+8,8y+8)` с `0x10040`; `0x5972FF` — меньшую область `(8x−4,8y−4,8x+4,8y+4)` с `0x200`. Флаг `0x10000` расширяет первую область до `(L−8,T−2,R+8,B+16)` и запрашивает mask `7` (`0x5A409E–0x5A40CE`). Dispatcher клипует вход и рекурсивные запросы; producer дополнительно клипует регион. Значения world bounds здесь намеренно не исследовались.

**Подтверждено:** зависимости 1→2→4 задаются в `0x5A41AE–0x5A421F`. Consumer `0x5A46D0` вызывает:

| Queue flag | Call VA → функция | Значение для этого контракта |
| --- | --- | --- |
| `1` | `0x5A495E → 0x5A6B40` | Пересчитать и заменить terrain sample bytes |
| `2` | `0x5A4A8C → 0x5A5DA0` | Объектные маски поверх samples |
| `4` | `0x5A4BBC → 0x5A6350` | Читает samples и пишет сводку `C+6`, `C+0x12` (`0x5A64B0–0x5A6527`, `0x5A6814–0x5A6850`) |

Queue flags — маска обновлений, **не** биты внутри sample byte. `0x200` и остальные подсистемы dirty-dispatch здесь не подменяются искусственным обновлением bits 0/1.

## Точная формула `0x5A6B40`

**Подтверждено:** перед высотами проверяется `C((sx+4)>>3,(sy+4)>>3)+0x18`. Если bit 7 установлен, результат 0 (`0x5A6D76–0x5A6DC8`). Сдвиг `+4` относится только к gate-клетке; H берётся по самим sample XY. Начальный bit 7 происходит из high bit соответствующего PMP cell byte (`0x599947–0x599950`, записи `0x5999C2–0x5999C5` / `0x599A8B–0x599A8E`).

**Подтверждено:** все 31 перечисленные высоты должны быть **строго меньше 14**, unsigned byte. Отрицательные dy — выше по native map Y. Это дискретные probes, не заполненный прямоугольник/капсула.

| dy | dx | VA сравнения в порядке dx |
| ---: | --- | --- |
| −8 | 0 | `0x5A6E0A` |
| −15 | −7, +7, 0 | `0x5A6E59`, `0x5A6E93`, `0x5A6ECC` |
| −1 | 0 | `0x5A6F10` |
| −8 | −7, +7 | `0x5A6F4A`, `0x5A6F7D` |
| −3 | −4, +4 | `0x5A6FC5`, `0x5A7005` |
| −5 | −7, +7 | `0x5A7051`, `0x5A7087` |
| −12 | −7, +7 | `0x5A70DA`, `0x5A7116` |
| −15 | −4, +4 | `0x5A7154`, `0x5A718B` |
| −12, −4 | 0 | `0x5A71C7`, `0x5A7202` |
| −8 | −4, +4 | `0x5A723E`, `0x5A7271` |
| −13 | −3, +3 | `0x5A72B9`, `0x5A72ED` |
| −11 | −5, +5 | `0x5A733E`, `0x5A7374` |
| −10 | −2, +2 | `0x5A73C1`, `0x5A73FD` |
| −6 | −2, +2 | `0x5A7441`, `0x5A7481` |
| −5 | −5, +5 | `0x5A74BB`, `0x5A74F5` |
| −2 | −2, +2 | `0x5A7539`, `0x5A7575` |

**Подтверждено:** после probes устанавливается 1 (`0x5A7588`), затем возможна замена на 3:

```text
if gate_byte & 0x80: return 0
if any(H(s + offset) >= 14 for offset in probes31): return 0
if H(x,y-1)+2 < H(x,y) and H(x,y-11)+2 < H(x,y):
    return 3                  # 0x5A75E1..0x5A765B
if H(x,y)+2 < H(x,y+1) and H(x,y-10)+2 < H(x,y+1):
    return 3                  # 0x5A7665..0x5A76E7
return 1
```

`H(x,y)` сам по себе **не** входит в clearance probes. Результат 3 при текущей высоте 15 возможен и подтверждён исходным PMP sample `(180,84)`.

Важная проверка стека: `0x5A76B8` делает `push edi` перед `mov [esp+0x1B],al` в `0x5A76C2`. Это запись в прежний `[esp+0x17]`, заменяющая сохранённый `H(y+1)` на `H(y−10)`. Без учёта PUSH нижняя ветка ошибочно выглядит невозможным сравнением высоты с собой. `0x41FAD0` — checked byte-array accessor, `ret 4`.

## Объектная поправка

**Подтверждено:** `0x5A5DA0` обходит active objects. Нужны `(obj+0x268 != 0 OR obj+0x264 == INT_MAX)` и `(obj+0x3D0 & 0x400001)==0x400001` (`0x5A5F1B–0x5A5F40`). Для пересечения исходного object rect с dirty rect:

```text
keep = 0 if obj.value264 == 0x7FFFFFFF else 0xF3
sample_byte = (sample_byte & keep) | uint8(obj.value268)
```

Построение маски — `0x5A6106–0x5A6158`, bulk/scalar записи — `0x5A6180–0x5A61EF`, writer вызывается в `0x5A621E`. Обычная маска сохраняет bits 0/1, INT_MAX очищает их; OR-байт может выставить их явно. Поэтому одного terrain predicate недостаточно для полных current flags при наличии таких объектов.

**Подтверждено:** object rect использует `round_native(8*positionX/Y)` и offsets `+0x254,+0x258,+0x25C,+0x260`, затем пересекается с dirty rect (`0x5A5F46–0x5A60C3`). **Неизвестно в этом результате:** actual snapshot объектов текущего запуска и режим округления FPU. `object_overlay` переносит только byte-operation; footprint, eligibility и исходный порядок передаёт вызывающий код. Привязки моделей не придумывались.

## Контракт и проверка

`terrain_sample(sample, surface_samples, cell_byte18)` возвращает 0/1/3. Оба Dictionary имеют `Vector2i` keys: первый — sample XY и актуальные BDB bytes; второй — map-cell XY и фактический runtime byte `C+0x18`. Отсутствующие данные вызывают assert. `rebuild_terrain(rect, …)` возвращает replacements внутри **half-open**, заранее native-clipped rect. `terrain_dependency_rect` выполняет только доказанное расширение до clipping. `object_overlay` — операция для уже выбранного source object.

Вся математика модуля целочисленная. Для положительной bounded карты 44×24 нет расхождения float32 против GD double. Исходное float/FPU округление object placement специально не моделируется.

**Подтверждено:** counted-U16 RLE multi_start_010 даёт 67584 bytes: 65544×0, 1473×1, 567×3. Независимые fixtures из установленных PMP refs и BDB metadata:

| Native sample | Map XY | Terrain rule | Stored initial RLE |
| --- | --- | ---: | ---: |
| (55,33) | (6.875,4.125) | 0 | 0 |
| (171,33) | (21.375,4.125) | 1 | 1 |
| (180,84) | (22.5,10.5) | 3 | 3 |

JSON содержит 34 реально читаемые высоты на fixture в сжатой форме: default + overrides. Остальные заполненные тестом точки не участвуют в формуле. Три совпавших samples не доказывают равенства всей serialized карты новому пересчёту.

Независимый малый интерпретатор воспроизвёл инструкции `0x5A6DBE–0x5A76EB` с checked-array accessor на **4419** случаях: 918 одиночных возмущений высоты (13/14/15), 3000 наборов с высотами ниже 14, 500 смешанных наборов/gate и один плоский случай. Seed `0x5A6B40`; расхождений с формулой нет. Это проверка потока исходных инструкций, не запуск native EXE. Интерпретатор использовался только в ходе аудита; воспроизводимые fixtures и Godot test сохранены.

**Проверено:** Godot **4.7.2.stable.official.ed1daf0bf**, standalone headless: первоначально 125 assertions; после добавления nullable queries — `NATIVE_WALK_FLAGS_SELF_TEST_OK assertions=131`. Покрыты все 31 порога 13/14/15, обе ветки bit1 и строгий delta>2, gate с +4, half-open rect, чистота данных, object masks и три source fixtures. Дополнительные шесть проверок различают отсутствующие входы, доказанный блокирующий probe и достаточную нижнюю slope-ветку. Команда из корня проекта:

```powershell
& 'C:/Users/frant/OneDrive/Рабочий стол/godot/Godot_v4.7.2-stable_win64_console.exe' --headless --path godot --script res://tools/native_walk_flags_self_test.gd
```

Минимальное подключение: сохранить initial RLE bytes → после strike построить native-clipped dependency rect → прочитать **новые** BlockDB refs/64 samples → заменить bytes этого rect → наложить eligible objects в исходном порядке → дать consumer читать обновлённые bits. Initial `0x40000` пропускает terrain-rebuild.

**Неизвестно:** live frame завершения dirty queues относительно конкретного `vector_fixdig`; actual object footprints текущего запуска. World bounds, full graph/pathfinding и attachments вне задачи. Гипотетических формул в модуле нет. Измеримая сквозная приёмка для интегратора: после одного принятого strike сравнить каждый byte всего затронутого native-clipped rect с этим predicate плюс исходными object masks; вне rect bytes должны сохраниться. Pure tests сами по себе runtime-интеграцию не подтверждают.
