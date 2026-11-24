# Multiplayer world: реальные bounds и размещение start_010

17.11.2026. **Подтверждено исходниками и EXE:** `multi_start_010.pmp` 44×24 — шаблон внутри отдельно созданного мира. Multiplayer-origin по обычному `map create W H` равен **(0,0)**. Позиция шаблона приходит из **итогового level**, а не из PMP. У пресетов есть существенное преобразование: **level_xy = preset_xy + generation_area_min**, здесь +(16,16). Единственного offset для текущего/исторического запуска оригинала без его GameData/level **не установлено**.

Результат исследовательской подзадачи — этот отчёт и соседний JSON с источниками, вариантами и fixtures. В самой подзадаче runtime, существующие экспортёры, STATUS, APK и preset не менялись. Последующая интеграция двух явных тестовых контекстов в Godot описана в [native-fix-dig-2026-11-17.md](native-fix-dig-2026-11-17.md). Оригинальная игра не запускалась; это статическое доказательство условных путей, не live-capture.

## 1. Откуда берутся W/H и параметры

`O/` = `C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris/data/`. Все строки ниже — физические номера в установленном файле. SHA-256 ключевых источников сохранены в JSON. VA относятся к соседнему `Diggles.exe`, image base0x400000, SHA-256 `58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74`.

| Источник | Подтверждённые входы и действия |
| --- | --- |
| `O/GameScripts/multiplayer.tcl:1–2` | Загружает `Scripts/misc/mp_tools.tcl`, затем `Scripts/init/mpinit.tcl`. |
| `multiplayer.tcl:16–30` | Читает `GameData=net gamedata`: `[0]` GameSave, `[1]` GameType, `[2]` UseMap, `[3]` Density, `[4]` Resources, `[5]` Set, `[6]` Size, `[7]` NumGnomes. GameSave получает префикс `Data/GameScripts/`; возможный второй элемент `skirmish` выбирает отдельную ветку (`:29–35`). Начальные константы `:7–11` затем переопределены; считать их live-options нельзя. |
| `Scripts/init/mpinit.tcl:1–5`; `multiplayer.tcl:44–53` | Для обычной генерации `S=mapsizelist[Size]`, список **[128,256,384,512]**; `map_size=(S,S)`. Set0→Urwald,1→Metall,2→Kristall,3→Lava. Density выбирает [0.2,0.4,0.7]. |
| `multiplayer.tcl:60–80` | Из `net playerdata` формирует ordered teamlist: team поля[3] каждого player, у которого type поля[0] !=0. |
| `multiplayer.tcl:154–155,234–264` | Server — localid0. При UseMap загружает GameSave **до** чтения итогового map_size; скрипт карты может заменить размеры/Zone/TempRatio. Без UseMap строит start presets через get_mpstartpos. Затем `map create $MapW $MapH`. |
| `multiplayer.tcl:269–285` | Очищает каталог генератора, подключает `$Zone.Std`, задаёт density и **area=(16,16,W−16,H−16)**. Для каждого `(x,y,name)` из temp_list вызывает `lg_add_preset name.tcl x y`, затем lg_start и lg_get_level. |
| `multiplayer.tcl:193–227` | Skirmish также сначала загружает GameSave, создаёт W/H и тот же area; presets проходят тот же генератор, затем apply_level. |
| `multiplayer.tcl:160–175,292,296` | Server передаёт **`level W H level_list`**; клиент создаёт именно полученные W/H и вызывает apply_level. На сервере apply_level получает свой итоговый список. |

**Native origin/bounds, подтверждено:** callback `map/0x6325F0` распознаёт строку `create` по `0x72C964`. `0x6327D9–0x6327E0` обнуляет два optional origin; только argv4/argv5 могут их заменить (`0x6327E7–0x632844`). Обычный Tcl-вызов имеет только W/H. `0x63286E–0x632886` передаёт W,H,originX,originY в `0x6B4440`; тот без подмены передаёт эти четыре аргумента в `0x594160` (`0x6B4533–0x6B4545`). `0x594481–0x5944BC` записывает W/H в world+0x44/48, origin в +0x74/78. `0x594528–0x594580` формирует и пишет **[minX,minY,maxX,maxY]=[originX,originY,originX+W,originY+H]** в +0x84..90. Max исключён. Размеры не берутся из PMP и в этом участке не округляются до размеров шаблона.

Следовательно, для показанного двухаргументного map create world sample domain — **[0,W)×[0,H)**. Area с отступом16 — область генерации, **не world bounds**. Native interior валидатора точек `[min+1,max−1)` и окно dig_next с margin2 применяются к миру, не к каждому вставленному шаблону; сами валидаторы этим исследованием не менялись.

## 2. Пресет → итоговый offset: доказанный +16

**Подтверждено EXE**, не предположение по скриншоту:

1. `lg_set_area/0x650180` → `0x583AC0` (`0x65046B–0x650493`). Rect ограничивается world±8 и выравнивается до кратности4 (`0x583AD7–0x583B35`), затем пишется в generator+0x50/54/58/5C (`0x583BBE–0x583BC3`). Для W/H=128/256/384/512/600 и Tcl area16..W−16 эти операции оставляют **area_min=(16,16)**.
2. `lg_add_preset/0x651C80` → `0x58A510` (`0x651F73–0x651F78`). Успешная ветка сохраняет **исходные** x/y в preset record+4/+8 (`0x58A68E–0x58A69F`); при проверках учитывает area_min (`0x58A5AB–0x58A630`). Есть отказы при неизвестном имени, отсутствии area, некратных4 координатах, выходе за границы/занятых клетках; сам Tcl результат этого вызова здесь не проверяет.
3. `lg_start/0x652BC0` → `0x589790` (`0x652C6D`); тот вызывает `0x5896A0` (`0x58980D`). Пресеты передаются в `0x5848B0` с сохранёнными x/y (`0x589745–0x589754`).
4. Успешный preset добавляет record в итоговый массив generator+0x184 (`0x584C52–0x584C95`). **`0x584CAF–0x584CB8`: output.x=generator[0x50]+preset.x; `0x584CD1–0x584CDC`: output.y=generator[0x54]+preset.y.** Обычная постановка generated-template имеет то же прибавление (`0x5847DF–0x58480B`).
5. `lg_get_level/0x652D10` читает этот итоговый массив (`0x652EA7–0x652EB0`) и кладёт record+4 и +8 в Tcl-list напрямую (`0x652F89–0x652F8F`, `0x653010–0x653016`), без следующего смещения. Итоговый item имеет порядок **`(filename,x,y)`**, тогда как исходный temp_list имеет `(x,y,name)`.

Это формула **успешно принятого placement**; наличие конкретного record в конкретном итоговом level без capture не утверждается. В JSON исходные preset_xy и вычисленные conditional level_xy разделены. Не следует прибавлять ещё16 после получения level.

## 3. Как реально загружается именно start_010

`O/Scripts/misc/mp_tools.tcl:23–46`: apply_level берёт filename/x/y из итогового item, задаёт `temppos=(x,y)` и вызывает **`data/templates/tcl/$template`** (`:35–42`). Если шаблон не split — вызывает MapTemplateSet с этими же x/y (`:44`). Ветка `mat` отдельно рисует материалы с offset16 (`:27–30`), она не меняет template offset.

Для цели есть два разных файла:

- `O/Templates/multi_urw_start_010_a_0.tcl:1–4` — монолитный MapTemplateSet: `map_template multi_start_010.pmp xoffset yoffset`, затем L2M с тем же offset. Этот root-файл читали прежние экспорты, но **apply_level вызывает другой путь**.
- **`O/Templates/tcl/multi_urw_start_010_a_0.tcl:1–8`** — вызов split_template с размером44×24 и шестью частями. `mp_tools.tcl:8–15` вызывает PMP и MapTemplateSet каждой части по **P+tile_offset**, где P=temppos из level. Здесь split применяется без проверки bSplit; флаг wassplit подавляет повторный монолитный вызов (`:17–18,44–46`).

| Часть | Локальный tile_offset | PMP W×H | Строка wrapper |
| --- | --- | --- | --- |
| AA | (0,0) | 16×16 | `Templates/tcl/multi_urw_start_010_a_0.tcl:2` |
| BA | (16,0) | 16×16 | `:3` |
| CA | (32,0) | 12×16 | `:4` |
| AB | (0,16) | 16×8 | `:5` |
| BB | (16,16) | 16×8 | `:6` |
| CB | (32,16) | 12×8 | `:7` |

PMP пути: `O/Templates/pmp/split/splt_multi_start_010_t{part}.pmp`; Tcl: `O/Templates/tcl/split/splt_multi_urw_start_010_a_0_t{part}.tcl`. В частях BA/CA/BB/CB после L2M координаты object placement возвращаются к P вычитанием локального tile offset (`BA:4`, `CA:4`, `BB:4–5`, `CB:4–5`); это не второй глобальный сдвиг. AA не требует коррекции; AB объектов не размещает.

**Проверено по файлам:** шесть прямоугольников покрывают ровно44×24=1056 samples без пересечений. При сборке в общий local grid **все1056 flags,1056 refs и1056 trailing attributes совпали** с `Templates/multi_start_010.pmp`. SHA-256 PMP `b6fc5ef7b1800dce9fb0dd4a42de879b8198f25ac84eb82b524266378ddb7807`. Это проверка исходных полей, не полная симуляция границ загрузки/материалов шести map_template. Размер44×24 не изменяет уже созданные W/H.

## 4. Извлекаемые варианты и неизвестный live-call

При поиске точного имени в установленных Tcl найдены два явных authored GameScripts и один random start pool. Название файла `kris` ниже **не** задаёт Zone: оба файла явно ставят **Urwald** в строке5.

| Условный путь | World size | Исходный preset_xy | Offset принятого record P | Source |
| --- | --- | --- | --- | --- |
| UseMap/GameSave=`multi_dm_kris_2p_001.tcl` (либо его skirmish-ветка) | 600×600 | (76,68) | **(92,84)** | `O/GameScripts/multi_dm_kris_2p_001.tcl:3,49`; +16 по EXE выше |
| UseMap/GameSave=`multi_dm_kris_4p_001.tcl` (либо его skirmish-ветка) | 600×600 | (184,92) | **(200,108)** | `O/GameScripts/multi_dm_kris_4p_001.tcl:3,55`; +16 по EXE выше |
| Server, !UseMap, Set0, первый start item, выбран target | S×S; S из Size | `stposlist[0]` | **stposlist[0]+(16,16)** при принятом preset | `multiplayer.tcl:242–255`; `Scripts/init/mpinit.tcl:7–12` |

Оба authored-файла заменяют map_size на600×600, TempRatio на0.31 (`:3,10`), поэтому UI Size/Density в этих ветках не остаются окончательными значениями. Для них начальные world bounds — **[0,600)²**, generation area=[16,584)². Extent шаблона: при P=(92,84) это [92,136)×[84,108); при P=(200,108) — [200,244)×[108,132). Исходная точка(9,3) становится соответственно **(101,87)** или **(209,111)**.

В random-ветке Tcl буквально вызывает `get_mpstartpos(S−32,S−32,teamlist)`, не W−32/H−32 по отдельности (`:242`; обычный random-мир квадратный). Затем pool выбирается по порядковому iCnt и Set (`:247–250`). Для iCnt0/Set0 список `[multi_urw_start_010_a_0,multi_urw_start_011_a_0]`; `idx=irandom(2)` и выбранное имя попадают в temp_list (`:251–253`). Wrapper get_mpstartpos зарегистрирован на **0x6480F0** (`0x61C756–0x61C77E`), но его алгоритм/результат этой ограниченной задачей не воспроизводились. **Неизвестны** реальные GameData, PlayerData/teamlist, состояние RNG/seed, выбранный вариант и итоговые координаты конкретного запуска. В перечисленных Tcl явной установки seed нет; делать вывод о конкретных позициях из одного Size нельзя.

## 5. Контракт для интеграции

Для соответствия конкретному original multiplayer запуску нужны **W,H из map create/network level** и **P из matching record итогового level**. После этого world_point=P+PMP_local_point; для tile_sample — P+tile_offset+tile_local_point. Origin мира и P шаблона — разные значения. Достаточный исходный capture: GameData/PlayerData и серверный `Level:` (`multiplayer.tcl:291`) либо сетевое сообщение `level W H list` (`:292`). Последнее уже содержит W/H и конечные offsets, не требует угадывать seed. Если нужного record нет или их несколько, нельзя молча выбрать единственный P.

Текущий отдельный PMP-мир44×24/origin0 может оставаться **явным standalone-адаптером**. Два найденных600×600-пресета не доказывают, что именно один из них был выбран в исходном запуске. При переносе bounds большого мира также нужны данные окружающих samples; вставка1056 samples не создаёт доказанного содержимого остальных клеток. Невосстановленные генератор/RNG и полный generated world не экспортировались как готовое состояние; JSON содержит только проверенные source facts и условные профили. Гипотетический единственный live-offset не назначен. Vector_fixdig, attachments и лазание в этой работе не исследовались.

**Проверка:** `NATIVE_MULTIPLAYER_WORLD_EVIDENCE_OK`: 7 Tcl-хешей и SHA EXE совпали с установкой; 7 byte-spans EXE совпали; 2 профиля сверены с физическими строками GameScripts и формулой +16; 6 tiles покрыли1056 samples, все три проверенных поля каждого sample совпали с монолитом. Проверка была read-only; runtime-проверка запуска/интеграции этим результатом не заявляется.
