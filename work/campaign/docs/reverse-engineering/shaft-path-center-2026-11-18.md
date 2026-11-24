# Центр пути в шахте и условия floor Z — 18.11.2026

## Вывод

В оригинале есть **общее предпочтение центра map-клетки при построении её navigation summary**, затем Calc1 использует выбранные local XY для промежуточных узлов. Это конкретный источник центрирования, отсутствующий у BFS по отдельным samples. **Отдельный shaft-only snap не подтверждён.** Нельзя из этого аудита вывести обязательное движение по геометрической средней линии любой шахты: выбор зависит от доступных samples, floor bit, разбиения мира на клетки и ветки Calc1.

Уточнение для текущего floorZ исправления: `12.5/14.5` действительно присутствуют в оригинале, но **не являются правилом всех floor-waypoints**. Перед ними есть расчёт постоянной глубины floor-действия по двум BDB probes; последняя точка сохраняет target XYZ. Continuous valid 3D floor segment — разумная политика host, но полное совпадение её интерполяции с оригиналом этим аудитом не доказано.

Main/Godot/exporter scripts не менялись. Записаны только этот документ и read-only `tools/audit_shaft_path_center.py`. APK, запуск оригинала, захват live FPU и реализация полного Calc1 не выполнялись. Изменения пользователя floorZ/dig rebase не затрагивались.

## Первичный источник и воспроизведение

EXE: `C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris/Diggles.exe`; preferred image base `0x400000`; SHA-256:

`58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74`.

Все адреса ниже — preferred VA, не file offset. Инструкции и float32 constants повторно прочитаны из установленного EXE через pefile/Capstone. Существующий `tools/.cache/diggles-text-disassembly.txt` использовался для поиска границ, ключевые участки перепроверены из EXE. Это статический разбор, не трасса конкретного гнома.

```powershell
python -B tools/audit_shaft_path_center.py --check
python -B tools/audit_shaft_path_center.py --span 0x5a6497:0x5a6529 --span 0x5a673d:0x5a6853
python -B tools/audit_shaft_path_center.py --span 0x59e4b5:0x59e4fe --span 0x59e83a:0x59e883
python -B tools/audit_shaft_path_center.py --span 0x415f40:0x416114 --span 0x41a2f0:0x41a46c
python -B tools/audit_shaft_path_center.py --span 0x4163a0:0x416527
```

Проверка `--check` прошла: `SHAFT_PATH_SOURCE_OK spans=8 constants=7`. Она сверяет SHA всего EXE, восемь сохранённых диапазонов и семь constants, ничего не записывает. Произвольный `--span` требует известной границы инструкции; xref byte scan выдаёт кандидаты, которые надо подтверждать дизассемблированием. Хеши диапазонов сохранены в самом audit script.

## Кто строит путь

| Участок | Первичное свидетельство |
| --- | --- |
| Tcl `data/Scripts/classes/zwerg/z_dignwalk.tcl:705–721` | `walk_pos_dig` вызывает `vector_fix`, затем `walk_action -target ... -waving 0 -dig 1 -digpos ...`; при условии `get_gnomeposition`/height выбирает speedtype. Центрирующей X-формулы здесь нет. |
| `0x415910–0x415983` | Обычный native walk передаёт actual start XYZ актёра и target XYZ `+0x7A4/+0x7A8/+0x7AC` в `0x59D440`. `push 0` в `0x415920` задаёт `bLines=false`; canclimb берётся из `+0x7B0`, owner передаётся отдельно. |
| `0x59D4DC–0x59D574` | CVec3D wrapper умножает четыре XY-компоненты на 8, округляет через x87 FISTP и вызывает CKPoint-вариант `0x59D640`. Это общая sample quantization, без `+0.5` и без shaft gate. Live rounding mode здесь не установлен. |
| `0x59D640` | В EXE присутствуют строки сигнатур `CPathPtr CMapPathfinder::Calc1(CVec3D v1,CVec3D v2,int iOwner, bool bLines,bool bCanClimb)` и CKPoint-перегрузки. Работа со summaries и path points находится в этом ядре. |
| `0x59E4B5–0x59E4FA`, повтор `0x59E83A–0x59E87F` | Чтение `cell+0x12`, unpack local XY и добавление `8*cellXY`, затем запись пары int в path. |
| `0x59EB23–0x59EB5C`, `0x59EE05–0x59EE0D` | Post-pass применяет `0x59A5B0` к исходным и дополнительно вставляемым samples. Helper меняет Y по flags, сохраняет X; это не горизонтальное центрирование шахты. |
| `0x41A2F0–0x41A46B` | Позже выбранные int path XY становятся map XY `/8`; отдельно выбирается Z. Этот consumer не строит центрирующую X-проекцию. |

Точное имя `get_gnomewalk` не найдено в NUL-terminated ASCII EXE или исходных Tcl по поиску `get_gnome.*walk/get_gnomewalk`. `get_gnomeposition` — другой predicate. `tools/inspect_native_commands.py` сейчас содержит map dig callbacks, а не доказательство walk-construction; запускать его с default output значило бы перезаписать посторонний JSON. Поэтому для этой проверки добавлен отдельный stdout-only инструмент. Отсутствие строки само по себе не исключает иной spelling/динамический command.

## Источник центра: producer summary `0x5A6350`

`cell+0x3C` — 64 current navigation bytes, runtime cell stride `0x7C`. Consumer queue 4 вызывает `0x5A6350` (`0x5A4BBC`); зависимости dirty queues и object-overlay описаны в `native-walk-flags-2026-11-17.md`. Здесь разобрана ранее не перенесённая сводка `cell+6`, `cell+0x12`.

В каждой клетке цикл `0x5A64B0–0x5A6527` перебирает `i=0..63`, `x=i&7`, `y=i>>3`. Для samples с `flags&1` считает:

```text
score = 8 + ((flags & 2) << 7) - abs(4-y) - abs(4-x)
      = 8 + (256 if floor else 0) - Manhattan((x,y),(4,4))
```

Начальные `best_score=0`, `chosen=0x24` (= local `(4,4)`): `0x5A643E`, `0x5A6450`. Новая точка принимается только при **строго большем** score: `cmp/cmovge` в `0x5A6505–0x5A650C` сохраняет прежний index при равенстве. Порядок — сначала X внутри строки, затем Y. Константа 4 и floor bonus происходят из инструкций, это не подобранные host tolerances.

Уточнения, важные для переноса:

- Это центр **map-клетки** `(cellX+0.5,cellY+0.5)`, не midpoint найденного поперечного сечения шахты. В полосе одинаковых wall-flags выбирается доступный sample, ближайший к этому центру. Если шахта не совпадает с сеткой, гарантии её геометрической оси нет.
- Floor sample всегда выигрывает у wall sample. Широкие body probes только ограничивают кандидатов; summary дополнительно выбирает представителя среди них.
- У единственного wall-кандидата `(0,0)` score=0: начальный chosen `(4,4)` не заменится. Поэтому нельзя обещать валидность argmax без отдельной проверки. Нулевая/неполная клетка требует исходных gates.
- При отсутствии bit0 ставится `cell+6=0xFF` (`0x5A673D–0x5A6741`, `0x5A6848–0x5A6850`). Дополнительный gate использует четыре cell high-bits и наличие `sample_flags&8`; не сводить весь producer к одному argmax.
- В частично доступной клетке ветка `0x5A681E–0x5A6835` пишет выбранный index в младшие 6 bits `cell+0x12`; bit6 происходит из summary score/class, не является X.
- В полностью доступной клетке есть отдельная ветка `0x5A6767–0x5A6814`. Для класса с ненулевым `score>>8` она продвигает выбранную точку вниз по непрерывным `flags&2` внутри клетки до local row 7 (`0x5A6798–0x5A67E3`). В нулевом классе используется `0x24` (`0x5A67FD–0x5A6803`). Нельзя терять этот floor-Y pass, выдавая argmax за полный summary writer.

Primary consumer formula в `0x59E4B5–0x59E4FA`:

```text
packed = cell.byte12
sampleX = 8*cellX + (packed & 7)
sampleY = 8*cellY + ((packed >> 3) & 7)
```

В обоих проверенных intercell участках formula одинакова. Порядок выбора клеток, accelerated search, owner cost, соединение сегментов и все варианты endpoint recovery не восстановлены целиком. Эти адреса доказывают использование представителей, но не что **каждый** native waypoint всегда обязан быть таким представителем.

## Floor Z: условие, которое терял host planner

`0x4163A0` группирует path по mode: 0 wall, 1 ladder, 2 floor. Смена mode обнаруживается в `0x416473–0x416479`; следующий mode сохраняется в `edx` (`0x4164C0`). Для mode 2 dispatcher вызывает `0x415F40` (`0x416505–0x41650A`), передавая начало, конец и следующий mode. Последний mode на исчерпании scan может остаться 2: не подменять аргумент утверждением «всегда 0 в конце пути».

В `0x415F40` начальное `segment_depth` читается из meta-action `+0x24`. Автоматический расчёт выполняется только если:

1. Третий аргумент (`[ebp+0x10]`, следующий mode в разобранном вызове) равен 0.
2. Исходный `segment_depth == -1.0`.
3. Индекс конца сегмента `< meta-action[+0x1C]`.

Проверки: `0x415F46–0x415F76`. Далее `end=[ebp+0x0C]`, `N=path.count`, `p=path[min(end,N-1)]`, `q=path[min(end+1,N-1)]`. Из двух **прямых** BDB heights `H(p.x,p.y)`, `H(q.x,q.y)` выбирается меньшее (`0x415FF4–0x416031`), затем:

```text
segment_depth = min(15.0, float(min(H(p), H(q))) + 1.0)
```

Это не `wall_depth` с пробой `y-1`/cross fallback. Constants: `[0x737568]=15.0`, `[0x737138]=1.0`. Constructor `0x41A910` получает depth последним аргументом: `0x4160D0–0x4160D9` → `0x41A997/0x41A9B0` → `[walk_subaction+0x44]`.

В `0x41A2F0` полная логика Z для рассматриваемых точек:

```text
if cursor == path.count:                   # 0x41A33E–0x41A372
    return action.targetXYZ               # +0x7A4/+0x7A8/+0x7AC
xy = path[cursor-1] / 8
if subaction.depth != -1.0:                # 0x41A38B–0x41A3C9
    z = subaction.depth
else:
    if mode == 0: z = wall_depth(sample)   # 0x41A43F
    elif mode in [1,2]:                    # 0x41A3CF–0x41A3DC
        z = 12.5 if path_dx_helper(cursor-1) < 0 else 14.5
```

`0x423BE0` выбирает соседнюю пару с учётом границ: при count<=1/индексе вне верхнего предела возвращает 0; terminal index прижимает к предыдущей паре, index0 использует пару 0→1. Поэтому даже знак нельзя автоматически считать `route[i].x-route[max(0,i-1)].x` на всех endpoints. Constants: `[0x737548]=12.5`, `[0x737564]=14.5`, sentinel `[0x73773C]=-1.0`.

**Практическое следствие:** автоматический depth floor-сегмента перед wall может не зависеть от направления X и обходит lane fallback. Присвоение fallback всем узлам BFS действительно теряет эту ветку и target exception. Однако конкретный визуальный detour текущей сцены требует runtime-проверки после локального изменения; статический аудит подтверждает потерю условий, а не единственную причину наблюдавшегося обхода.

## Конкретный контракт для host без полного Calc1

1. Сохранить current source bit0/bit1 и unknown, не менять clearance/body probes. Строить cell representatives из **world sample coordinates**: cell=`sample>>3`, local=`sample&7`. После dirty flags/object overlays обновлять затронутые summaries; при неизвестном обязательном sample результат summary — unknown. Для точного writer нужны перечисленные gates/full-cell branch.
2. Для обычного частичного wall-cell использовать приведённый score и tie order. Проверять полученный representative на bit0. Для регулярной шахты с доступным `(4,4)` получаем X=`cellX+0.5`; дополнительного shaft-width threshold или «прижми X к красивой линии» не требуется.
3. Если BFS пока остаётся, использовать представителей как **промежуточные цели** и прокладывать существующим валидатором достижимые соединения. Сохранять actual start/target и проверять каждый переход, включая 3D depth. При недостижимом/unknown представителе не телепортировать actor и не объявлять route нативным. Такой graph/search остаётся host adapter; простая подмена X в уже готовом BFS может пробить препятствие.
4. Разделить XY route, mode-runs и segment-depth. Применять source floor-depth override лишь при доказанных выше условиях, endpoint XYZ отдельно. Continuous valid floor segment через actual start/target можно оставить явно заявленной host политикой; fallback lane formula не должна становиться глобальной floor projection.
5. Приёмочные случаи для интегратора: обычная частичная wall-клетка с доступным центром; центр недоступен; равные score слева/справа; floor sample рядом с wall center; шахта со сдвигом world origin; floor→wall с автоматическим override; terminal target с произвольным допустимым Z. Центрирование не должно менять dig target, dirty flags или вводить требование `before_depth==after_depth`.

`_surface_dig_supports_next` и strict before/after wall-depth equality в этом аудите не пересматривались: их исправляет пользователь. Ни source summary, ни разобранный waypoint consumer не дают основания выводить такое равенство как общее требование к пути после удара.
