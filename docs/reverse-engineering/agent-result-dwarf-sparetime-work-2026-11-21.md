# Досуг и работа гнома: контракт исходного Tcl и его порт

Дата: 21.11.2026
Блок: M7 — перенос в порт исходного Tcl-контракта машины состояний досуга и
работы гнома.
Источник: установленная игра (read-only)
`C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data`.

## 0. Что это и зачем

В оригинале досуг гнома — это не «подождать, пока понадобится», а отдельная
машина состояний с гистерезисом, планом отдыха и учётом мест. Ключевые
процедуры:

| Процедура | Файл:строки | Что делает |
|---|---|---|
| `sparetime_decide_occup` | `Scripts/classes/zwerg/z_spare_main.tcl:378-710` | решает, чем гному заняться в досуг: еда/сон/развлечение/баня |
| план отдыха | `z_spare_main.tcl:53-68` | последовательность `sparetime_future` на фазу досуга |
| `sparetime_check_in` | `Scripts/classes/zwerg/z_spare_procs.tcl:882-917` | захват места в зале (гостевой столик) |
| `sparetime_find_place` | `z_spare_procs.tcl:851-880` | поиск места для текущего занятия |
| `sparetime_place_find` | `Scripts/classes/zwerg/z_spare_fun.tcl:430-511` | оценка места: расстояние, недавние визиты, избранные места |
| `sparetime_disappoint` / `sparetime_set_disapp` | `z_spare_procs.tcl:10-26` | накопление и затухание разочарования |
| `sparetime_exec_taste` / `sparetime_taste_wish` / `sparetime_eat_judge` | `z_spare_procs.tcl:28-61` | вкус, пожелание по вкусу, оценка еды |
| `state_work_auto/dispatch/idle` | `Scripts/classes/zwerg/z_work_states.tcl:80-301` | машина работы: задача → команда → диспетчеризация → простой |
| `state_work_active/breakable` | `z_work_states.tcl:304-324` | переход из работы в досуг по плану |
| `rotate_toangle` | `Scripts/classes/zwerg/z_dignwalk.tcl:1032-1040` | разворот на угол |
| `stop_prod` | `Scripts/classes/zwerg/z_procs.tcl:1213-1264` | прерывание производства, надбавка настроения по состоянию |

Задача блока: **восстановить этот контракт по оригиналу и перенести его в порт**,
с проверкой на golden-значениях, полученных запуском самих исходных процедур.

## 1. Факты (из установленной игры, read-only)

### 1.1 SHA-256 исходников

Зафиксированы в `godot/models/native_dwarf_sparetime.json` → `sources`:

| Файл | SHA-256 |
|---|---|
| `Scripts/classes/zwerg/z_spare_main.tcl` | `9c3a027c398b78ce70cd26ebb29ff5c21ed80590dcca8d1e97e889290490e581` |
| `Scripts/classes/zwerg/z_spare_procs.tcl` | `40eef7d72f5cb30e4c9b0927f917bc716aecd0010b5f099cc7441840cd9774d5` |
| `Scripts/classes/zwerg/z_spare_fun.tcl` | `5260d026d66b2c7a861eb25a8e64aae06f3662b80f2257324528e5e5dc609cf7` |
| `Scripts/classes/zwerg/z_work_states.tcl` | `568fe691e25933b86f30d7890eece38e6b663298f2ac99ab3e2233c7dc3a15c9` |
| `Scripts/classes/zwerg/z_work_prod.tcl` | `b733ed747e82f328bdcbd4e8d02e9ea5a28c1062bd8f9b15c8ba48f5393c1eb4` |
| `Scripts/classes/zwerg/z_procs.tcl` | `38007f1f56cf8949967f85a12f76bad49c8229d83b5429425acb48cf1bfe23dc` |
| `Scripts/classes/zwerg/z_dignwalk.tcl` | `c0d6f01eade25f6659890bf79debbcfad0eef6d7acc0a8cdb700557bfff93846` |
| `Scripts/misc/sparetimetunes.tcl` | `5f2096ff01a9e654494313e33cdb8f7da0f38e8cec978ee9de13081a23c069f9` |
| `Scripts/misc/genattribs.tcl` | `ba01e173d32105a006f950f4ce5e33a3d6026506a482de200a16031442eb9ab1` |

### 1.2 План отдыха — `z_spare_main.tcl:53-68`

```
set sparetime_rest [hceil [get_remaining_sparetime this]]
if {$last_spareleave<$time_count_start-100||$sparetime_future==""} {
    switch $sparetime_rest {
        0.0 {set sparetime_future ""}
        1.0 {set sparetime_future [lindex {eat slp} [irandom 2]]}
        2.0 {set sparetime_future [lrange {eat slp eat} [expr {$sparetime_initialize-1}] $sparetime_initialize]}
        3.0 {set sparetime_future [lrange {"" eat fun slp eat} $sparetime_initialize [expr {$sparetime_initialize+2}]]}
        4.0 {set sparetime_future {eat fun slp eat}}
        default {set sparetime_future {eat fun slp bth eat}}
    }
    if {$spt_bath_desire<3.0} {set sparetime_future [lnand "bth" $sparetime_future]}
    set spt_fun_stations 0
    ...
}
```

Факты:

* порядок плана зависит от **длительности оставшегося досуга**, а не от текущей
  фазы смены;
* «bth» (баня) выбрасывается из плана, если `spt_bath_desire < 3.0`;
* план пересобирается, если гном давно уходил из досуга
  (`last_spareleave < time_count_start - 100`) или план пуст.

### 1.3 Решение занятия — `z_spare_main.tcl:378-710`

Ключевые наблюдения из оригинала:

* `sparetime_goal_reached` принимает 0 (цель не достигнута), 1 (достигнута
  частично, проверка `goal*0.5`) и 2 (достигнута, проверка `goal`);
* «экстренный» порог: `emergency_value > min(compare_value, 0.5)`, где
  `compare_value` — результат гистерезиса
  (`sparetime_compare_value` / `sparetime_emchange_initial`);
* `emergency_tolerance = 0.3 + sparetime_goal_reached*0.1`;
* `at_Fun = hmin($at_Mo, 1.0-$funlack*0.09)`, где
  `funlack = $spt_fun_needs - <число занятых станций>`;
* `funstations` считается как **popcount** битов 1..16 маски `spt_fun_stations`
  (`z_spare_main.tcl:388-393`);
* цель хранится **строкой выражения** (`$at_Nu- 0.8 >=0.15` и т. п.), а не
  числом: «атрибут вырос на дельту»;
* при смене занятия история (`sparetime_history`) пополняется, а из плана
  (`sparetime_future`) выбрасывается уже выполненное занятие.

Экспортированные значения целей (примеры из oracle, `decide_occup[0]`):

```
sparetime_goal = "$at_Mo- 0.8 >(0.98-0.8)"
```

### 1.4 Сортировка экстренного списка — `z_spare_main.tcl:422`

```
lsort -index 1 {eat $at_Nu} {slp $at_Al} {fun $at_Fun}
```

**Ключевой факт:** `lsort` без `-real` сравнивает **строки**. Значит порядок
зависит от того, как Tcl печатает double (кратчайшее round-trip
представление, экспоненциальная форма при exp < −4 или exp > 16). Поэтому порт
обязан воспроизводить именно текст числа, а не его значение.

### 1.5 Места и гостевые места — `z_spare_procs.tcl:851-917`

`sparetime_check_in` полностью:

```tcl
proc sparetime_check_in {placeref {meth 0}} {
    global sparetime_current_place sparetime_current_place_ref sparetime_seat sparetime_reservation
    set sparetime_reservation 0
    if {$sparetime_current_place_ref} {
        if {[obj_valid $sparetime_current_place_ref]} {
            prod_guest guestremove $sparetime_current_place_ref [get_ref this]
            prod_guest resetorder $sparetime_current_place_ref $sparetime_seat
        }
        set sparetime_current_place_ref 0
        set sparetime_current_place 0
    }
    if {$placeref} {
        if {$meth} {
            if {$meth==-1} {
                set seat [call_method $placeref get_random_seat]
            } else {
                set seat $meth
            }
        } else {
            set seat [prod_guest guestfree $placeref]
        }
        if {$seat != -1} {
            set sparetime_seat $seat
            prod_guest guestset $placeref $seat [get_ref this]
            prod_guest resetorder $placeref $seat
            set sparetime_current_place_ref $placeref
            set sparetime_current_place [get_objclass $placeref]
            return 1
        }
    }
    return 0
}
```

Порядок команд (проверено oracle'ом): при повторном заходе сначала
`guestremove` + `resetorder` старого места, затем `guestfree`/`get_random_seat`,
затем `guestset` + `resetorder` нового.

`sparetime_find_place` (`z_spare_procs.tcl:851-880`): радиус поиска 15 для
«eat» и 60 для остальных; если текущее место подходит (класс в списке, ref
жив, не в ящике, расстояние ≤ 60) — место переиспользуется; для «eat»
дополнительно ставится в очередь `walk_dummy <place> <dummy>`.

### 1.6 Оценка места — `z_spare_fun.tcl:430-511`

```tcl
set pathcosts [expr {abs([get_posx this]-[get_posx $place])+abs([get_posy this]-[get_posy $place])*3.0}]
set da [expr {$spt_place_desire*0.2}]
set da [expr {$da+(1-$da)*0.05*[lcount $sparetime_recent_places $placename]}]
if {[lsearch $spt_favplaces $placename]!=-1} {set da [expr {$da * 2.0}]}
set jm [expr {1-(1-($pathcosts*$pathcosts)/($stt_maxsearch_range*$stt_maxsearch_range))*(1-$da)}]
```

Факты:

* метрика расстояния — манхэттен с весом **3.0** по Y;
* штраф за недавние визиты — `+ (1-da)*0.05*count`; при `da > 1` множитель
  отрицателен, то есть при необычной настройке `spt_place_desire` визиты
  **понижают** желание. Это поведение оригинала, а не опечатка порта;
* избранные места удваивают желание;
* итог `jm` не ограничен сверху единицей.

### 1.7 Машина работы — `z_work_states.tcl`

* `state_work_auto_proc` (`:80-151`): задача → одна команда в очередь:
  `pickup` → `prod_getfromanywhere <class>`,
  `pickupitem` → `pickup <item>`,
  `bringprod` → `prod_transporttoprodlist { <class> } <place>`,
  `transferprod` → `prod_bringtoprod <item> <place>`,
  `work` → `prod_autobuild <class> <place>`,
  `dig` → `dig_starttask {<digpos>}`,
  `pack` → `prod_autopack <place>`,
  `buildup` → `prod_autobuildup <place>`,
  `unpack` → `prod_autounpack <place> {<pos>}`,
  `repair` → `prod_autorepair <place>`;
  неизвестная задача → `state_trigger this work_idle`;
  перед этим всегда `current_occupation = "work"`, `idletimeout = 0`.
* `state_work_dispatch_proc` (`:154-212`): пустой список → `work_idle` и
  обнуление места работы; успех → сброс `prod_failurecount`, удаление первого
  элемента списка, `call_method <workplace> prod_progress`; провал при
  `current_plan == "sparetime"` → `state_triggerfresh this sparetime_dispatch`
  **без** роста счётчика провалов; иначе `incr prod_failurecount`, и пока
  счётчик < 5 — `state_disable` + `action this wait 2`, при 5 — сброс счётчика,
  удаление первого элемента и `state_triggerfresh this work_idle`;
* `state_work_idle_proc` (`:238-301`): `prod_gnome_state this idle`,
  `incr idletimeout`, `current_occupation = "idle"`; при `idletimeout > 3`
  пробуется `act_when_idle`; при `idletimeout > 5` и
  `get_remaining_sparetime > 0` — `state_enable` +
  `state_triggerfresh this sparetime_dispatch`; при `idletimeout > 10` —
  забастовка (`strike`) и/или `prodfill_dispatch`;
* `state_enter_work_idle_proc` (`:215-227`): `stop_prod`, обнуление
  `current_worktask`, `current_workclass`, `last_event`, `event_repeat`,
  затем `gnome_idle this 1`;
* `state_work_active_proc` / `state_work_breakable_proc` (`:304-324`): при
  `current_plan == "sparetime"` — `state_triggerfresh this sparetime_dispatch`.

### 1.8 `rotate_toangle` и `stop_prod`

`z_dignwalk.tcl:1032-1040`: `state_disable this`, затем
`action this rotate <angle>` (или `"<angle> <anim>"`), затем `return true`.

`z_procs.tcl:1213-1264` (`stop_prod`): `beam_back`, обнуление `event_repeat`,
и — если с прошлого прерывания прошло больше 5 секунд — надбавка настроения по
текущему состоянию (`stt_dst_spare = -0.01`, `stt_dst_work = -0.005`,
`stt_dst_talk = -0.02`, `stt_dst_sex = -0.05`, `stt_dst_idle = 0.0`), для
`sparetime_dispatch` дополнительно вызывается `sparetime_<занятие>_end`;
далее `unlock_item`, распаковка инвентаря типов
`production/elevator/energy/store/protection`, `dig_resetid`, два
`placelock_rem`, `enable_auto_fanim`, `dig_endanim`,
`sparetime_reset_clothes`, при `toolchange` — `change_tool 0` и
`change_tool 0 1`, обнуление `current_workplace` и `current_worklist`.

### 1.9 Таблица настроек — `Scripts/misc/sparetimetunes.tcl`

Экспортированы **87** констант секции `"Zwerg"` (`stt_*`). В порт попали через
`native_dwarf_sparetime.constants()`; ключевые для этого блока:
`stt_maxsearch_range = 160.0`, `stt_disapp_max = 0.2`,
`stt_disapp_factor = 0.3`, `stt_dst_*` (см. 1.8).

## 2. Oracle: как получены golden-значения

Экспортёр `tools/export_dwarf_sparetime_contract.py` (918 строк) **выполняет
исходные процедуры** в интерпретаторе Tcl 8.6.12 (`tkinter.Tcl`) со
заглушками нативных команд (`hmin`, `hmax`, `fincr`, `lrem`, `land`, `lnand`,
`lcount`, `obj_query`, `prod_guest`, `call_method`, `state_trigger*`,
`tasklist_add`, `action`, …) и записывает результат в
`godot/models/native_dwarf_sparetime.json` (206 778 байт).

Это не переписывание логики на Python: логика оригинала исполняется как есть,
подменяются только обращения к движку.

Состав oracle (строк):

| Секция | Строк | Что покрывает |
|---|---|---|
| `constants` | 87 | таблица `sparetimetunes.tcl` |
| `double_strings` | 52 | текстовое представление double в Tcl (52 пары) |
| `future_plan` | 504 | план отдыха, 252 кейса × 2 варианта `hceil` |
| `decide_occup` | 21 | полное решение занятия, включая текст цели |
| `work_auto` | 11 | задача → команда |
| `work_dispatch` | 5 | диспетчеризация, успех/провал/план досуга |
| `work_idle` | 8 | состояние простоя, 6 кейсов × 2 |
| `work_plan_switch` | 4 | `work_active` / `work_breakable` |
| `work_enter_leave` | 2 | вход и выход из `work_idle` |
| `rotate` | 3 | `rotate_toangle` |
| `stop_prod` | 5 | прерывание производства, 5 состояний |
| `check_in` | 5 | `sparetime_check_in`, 5 сценариев |
| `place_find` | 6 | `sparetime_place_find`, 6 сценариев |
| `taste` / `taste_wish` / `eat_judge` | 12 / 4 / 5 | вкус и оценка еды |
| `set_disapp` / `disappoint` | 6 / 3 | разочарование и его затухание |
| `eat_variety` / `place_variety` | 3 / 3 | разнообразие еды и мест |
| `fun_check` / `fun_entry` / `fun_history` | 5 / 7 / 3 | битовая маска станций |

Oracle также содержит тексты самих исходных процедур (`*_source`) — по ним
проверяется, что порт соответствует именно этой версии файла.

## 3. Порт: что именно перенесено и что адаптировано

### 3.1 Новые файлы

| Файл | Строк | Роль |
|---|---|---|
| `godot/scripts/native_dwarf_sparetime.gd` | 765 | решение досуга, план, формат чисел Tcl, подмножество `expr` |
| `godot/scripts/native_dwarf_place_registry.gd` | 258 | реестр мест и гостевых мест, `check_in`, штраф за недавние визиты |
| `godot/scripts/native_dwarf_work_states.gd` | 307 | машина work: auto/dispatch/idle/active/breakable, enter/leave, `rotate_toangle`, `stop_prod` |
| `godot/scripts/dwarf_sparetime_runtime.gd` | 220 | хост-адаптер поверх `dwarf_task_runtime` / `dwarf_sleep_runtime` |
| `godot/tools/native_dwarf_sparetime_self_test.gd` | 148 | сверка порта с oracle |
| `godot/tools/native_dwarf_work_states_self_test.gd` | 165 | сверка машины work с oracle |
| `godot/tools/native_dwarf_place_registry_self_test.gd` | 109 | сверка реестра мест с oracle |
| `godot/tools/dwarf_sparetime_runtime_self_test.gd` | 70 | проверка адаптера на живой сцене |
| `tools/export_dwarf_sparetime_contract.py` | 918 | генератор oracle |

### 3.2 Формат чисел Tcl — адаптер, но с доказанной точностью

`printf`-семантика Godot и C различаются в последней цифре (проверено:
`%.16f` в Godot даёт `0.5345454545454546`, C/Tcl — `0.5345454545454545`), а
`String.num` даёт кратчайшее представление, а не `%.Nf`. Поэтому порт
реализует собственную арифметику:

* `_two_sum` / `_two_product` (Dekker) — точное умножение без потери битов;
* `_scaled_integer` — округление half-even к целому для точного `value*10^p`;
* `_format_fixed`, `_decimal_exponent`, `_significant_digits` — сборка текста;
* таблицы `POWERS_POSITIVE` / `POWERS_NEGATIVE`.

Результат сверяется с oracle на 52 парах значений — совпадение байт-в-байт.
Это не «похоже на Tcl», это воспроизведение текста, на который оригинал
опирается при сортировке.

### 3.3 Подмножество `expr`

Оригинал хранит цель строкой и вычисляет её через `expr`. Порт реализует
подмножество выражений Tcl: числа, `$refs`, `+ - *`, сравнения, скобки.
Переменные, встречающиеся в целях (`at_Nu`, `at_Al`, `at_Mo`, `at_Hi`,
`has_bathed`, `funlack`), вычисляются штатно.

### 3.4 Цель как строка, а не число

Это не косметика: `sparetime_goal` сравнивается с текстом goal-строки в
oracle, а масштабирование выполняется как `goal*0.7` / `goal*0.5`. Порт
хранит цель строкой и вычисляет её тем же подмножеством `expr`.

### 3.5 Экранирование goal-строк

Правила экранирования в оригинале **различаются между ветками**:

* `$at_Nu-`, `$at_Al-`, `$at_Hi-`, `$at_Mo-` в большинстве веток
  экранированы (остаётся литерал `$at_...`);
* в ветке с нехваткой развлекательных станций
  (`$at_Mo- $at_Mo >($funlack-$funlack)`) — подставлены, и `funlack`
  подставляется **целым** («7», не «7.0»).

Порт учитывает это раздельно для экстренной и обычной веток; тексты целей
сверяются с oracle байт-в-байт.

### 3.6 Реестр мест

Оригинал держит таблицу мест внутри нативных объектов `prod_guest`. Порт
заводит собственный реестр (`native_dwarf_place_registry.gd`) с той же
семантикой (`guestfree` → первый свободный столик или −1, `guestset`,
`guestremove`, `resetorder`) и **тем же порядком команд**, который фиксирует
oracle. Класс места, случайный столик, поиск места, «в ящике» и расстояние
передаются хостом через `Callable` — порт не ходит в сцену.

### 3.7 Машина work

`native_dwarf_work_states.gd` работает со словарём, который заменяет глобальные
переменные оригинала, и возвращает записанную последовательность команд.
Исполнение самой команды (`eval $currenttask`) — обязанность хоста, поэтому
исполнитель задаётся `Callable`; поведение «команда не вернула boolean»
воспроизведено (только лог, список работ не трогается).

### 3.8 Хост-адаптер

`dwarf_sparetime_runtime.gd`:

* держит состояние досуга каждого гнома (то, что в оригинале лежит в
  глобальных переменных `z_spare_main.tcl:247-257`, `:328-376`);
* пересобирает план отдыха по правилу `:53-68`;
* вызывает `native_dwarf_sparetime.decide_occup` и публикует результат в
  модель гнома (`sparetime_wish`, `sparetime_goal`,
  `sparetime_goal_reached`, `sparetime_emergency`, `sparetime_future`) и в
  метаданные актора;
* **пропускает** гномов, которые заняты очередью задач (`actor_tasks`) или
  спят (`dwarf_life.models[...].is_sleeping`);
* собирает состояние для машины work (`work_state(dwarf)`).

Движковые последствия (еда, кровати, госпитали, реальные столики) **не
имитируются**: адаптер публикует решение, а не подменяет движок.

## 4. Интеграция в сцену

`godot/scripts/multiplayer_test.gd` изменён аддитивно, три точки:

| Место | Изменение |
|---|---|
| `const`/`var` (рядом с `dwarf_sleep`) | `const DWARF_SPARETIME: Script = preload("res://scripts/dwarf_sparetime_runtime.gd")`, `var dwarf_sparetime: RefCounted = DWARF_SPARETIME.new()` |
| `_ready` (рядом с `dwarf_sleep.configure(self)`) | `dwarf_sparetime.configure(self)` |
| `_process` (рядом с `dwarf_sleep.update()`) | `dwarf_sparetime.update()` |

SHA-256 файла:

* **до** правки: `588E5789D9FE6B8F7197B6C63EBE0C318889DCF7F6F29F5617674C8F46D2AA8E`
* **после** правки: `92418445A55CCD70F78AF9A9878C83AEA81A193FCD3051B36F43052CEB26EE4D`

Правка выполнена после того, как SHA был пересчитан непосредственно перед
изменением; других правок в файле не делалось.

## 5. Проверка

| Тест | Проверок | Падений |
|---|---|---|
| `native_dwarf_sparetime_self_test.gd` | 421 | 0 |
| `native_dwarf_work_states_self_test.gd` | 109 | 0 |
| `native_dwarf_place_registry_self_test.gd` | 47 | 0 |
| `dwarf_sparetime_runtime_self_test.gd` | 15 | 0 |
| **Итого по блоку** | **592** | **0** |

Что именно сверяется:

* `native_dwarf_sparetime_self_test` — текст 52 double-чисел Tcl, 87
  констант, план отдыха, 21 кейс решения (включая текст цели, минимальную
  цель, emergency-гистерезис, future/history), вкус, разочарование,
  разнообразие, оценка места;
* `native_dwarf_work_states_self_test` — 11 задач work_auto, 5 сценариев
  work_dispatch, 8 сценариев work_idle, 4 переключения плана, вход/выход из
  work_idle, 3 разворота, 5 прерываний производства — **последовательность
  команд сравнивается поэлементно**;
* `native_dwarf_place_registry_self_test` — 5 сценариев `sparetime_check_in`
  (порядок `guestremove`/`resetorder`/`guestfree`/`guestset`), работа таблицы
  мест, штраф за недавние визиты, избранные места, `place_finished`;
* `dwarf_sparetime_runtime_self_test` — адаптер на живой сцене
  `res://scenes/multiplayer_test.tscn`: по одному состоянию на гнома, публикация
  решения в модель и в метаданные, план построен, рабочий гном решения не
  получает, состояние для машины work собирается и передаёт простой в досуг.

Все четыре теста добавлены в `tools/run_suite.ps1`.

## 6. Что осталось (неизвестно и открытое)

### 6.1 Неизвестно (доказать не удалось)

* **`hceil` — нативная команда.** Её тип возврата восстановить нельзя.
  Если она возвращает целое, то `switch $sparetime_rest` с шаблонами
  `"0.0".."4.0"` **никогда не срабатывает** и всегда берётся ветка `default`
  (`{eat fun slp bth eat}`). Oracle экспортирует оба варианта
  (`ceil_mode`: `"double"` — 252 кейса, `"int"` — 252 кейса); порт реализует
  вариант `"double"`, соответствующий очевидному намерению автора, а расхождение
  документируется здесь. Тест проверяет только вариант `"double"`.
* **`land` / `lnand` — нативные команды.** `land` (пересечение) подтверждён
  экспортёром соседнего блока `export_native_sleep.py`; `lnand` (разность)
  выведен из 40+ мест использования (`lnand "bth" $sparetime_future` должен
  удалять «bth»). Обе операции реализованы в порте согласно этому выводу.
* **Дефект оригинала в `lindex $sparetime_goal 1`.** Для цели «1» или
  `$has_bathed>=5.0` исходный код вызывает `lindex` с индексом 1 при длине 1 —
  Tcl-ошибка. Порт не роняет гнома, а использует `goal_base = 0.0`. Это
  отклонение от оригинала, зафиксированное намеренно.
* **Единицы `get_remaining_sparetime`.** По RE-аудиту соседнего блока
  (`dwarf-work-clock-2026-11-18.md`, адрес `0x6956AC..0x695741`) значение
  возвращается **в часах** до следующего начала смены; порт использует тот же
  `native_work_clock.remaining_spare`. Это согласуется с `hceil` → 0..4.
* **Текст float в `stop_prod`.** Надбавка настроения печатается в Tcl как
  «-0.01» / «0.0»; порт печатает её тем же форматтером.

### 6.2 Открыто (вне этого блока)

* **Движковые последствия решения** — реальная еда, кровати, госпитали,
  разговоры, секс, реальные столики в залах. Адаптер публикует решение
  (`sparetime_wish`, `sparetime_goal`), но не исполняет его. Исполнение
  требует блоков «еда», «сон» (кроме `floor_sleep`), «развлечения».
* **`sparetime_talk`, `sparetime_reprod`, станции развлечений** — в oracle
  покрыты только там, где их касается диспетчер (`fun_check`, `fun_entry`,
  `fun_history`).
* **`sparetime_place_find` целиком** — в oracle покрыта только оценка места
  (путь, штраф, избранные). Ветки `ask_for_seat` / `ask_for_reserve` /
  `placefail` — хостовые и в порте оставлены на адаптер.
* **Алгоритм `irandom`** — нативный; порт использует `RandomNumberGenerator`
  там, где оригинал звал `irandom` (выбор «eat»/«slp» в плане отдыха).
* **Производственный граф предметов** (`prod_getfromanywhere`,
  `prod_autobuild`, …) — команды формируются точно, но исполняет их
  существующий `dwarf_task_runtime`, а не этот блок.

### 6.3 Зависимости от чужих блоков

| Зависимость | Что нужно | Статус |
|---|---|---|
| `dwarf_task_runtime` | исполнение команд work (`pickup`, `prod_*`, `dig_starttask`) | существует, команды формируются корректно |
| `dwarf_sleep_runtime` | занятость гнома во сне | существует, используется как признак «занят» |
| `dwarf_life_runtime` | потребности (`at_*`) и план смены | существует, потребности берутся из модели |
| `native_work_clock` | `remaining_sparetime` в часах | существует, используется как есть |
| Блок «еда» | `sparetime_eat_check`, реальная еда | открыт |
| Блок «сон» | кровати, `sparetime_slp_end` | частично: `floor_sleep` есть, кровати нет |
| Блок «развлечения» | станции, разговоры, места | открыт |
| Блок «производство» | `prod_*` команды, `stop_prod_tasklist` | команды формируются, исполнение — в `dwarf_task_runtime` |

### 6.4 Замеры производительности

Не выполнялись: CPU занят тремя параллельными агентами, замеры запрещены
условиями блока.

## 7. Итог прогона

Полный набор тестов проекта после интеграции блока:

```
powershell -File tools/run_suite.ps1 <godot> <project> `
  out/main-suite-dwarf-sparetime-2026-11-21 main-suite-dwarf-sparetime-2026-11-21
```

```
=== FAILURES ===
=== main-suite-dwarf-sparetime-2026-11-21: 61 tests, 0 failing ===
SUITE_DONE
```

* **61 тест, 0 падений.** Четыре теста этого блока вошли в набор и прошли
  вместе с остальными:
  `native_dwarf_sparetime_self_test` (421),
  `native_dwarf_work_states_self_test` (109),
  `native_dwarf_place_registry_self_test` (47),
  `dwarf_sparetime_runtime_self_test` (15).
* Логи прогонов: `out/main-suite-dwarf-sparetime-2026-11-21/`
  (`<label>-<test>.log`), сводка — `suite_main-suite-dwarf-sparetime-2026-11-21.csv`.
* Интеграция в сцену не сломала существующие сценарные тесты:
  `dwarf_life_runtime_self_test` (27), `dwarf_task_runtime_self_test` (39),
  `dwarf_parallel_work_self_test` (21), `floor_sleep_self_test` (53) — все зелёные.

