# Результат: блок «ИИ червя (Raupe)» — реимплементация на Godot 4.7.2

**Дата:** 2026-11-19
**Исполнитель:** Worker (сессия `mvs_e7dabdf0027c407db6bbc314aae77275`), родитель `mvs_a4418a32369d4b81afea291081b4dd63`
**Дерево:** `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot` (основной проект — изменения только здесь)
**Сверенная спецификация проекта:** `docs/plan/raupe-ai-2026-11-19.md`
**Оригинал (только чтение):** `data/Scripts/classes/characters/raupe.tcl`, `data/Scripts/classes/work/farm.tcl`,
`data/Scripts/ai/std_ai.tcl`, `data/Scripts/classes/zwerg/z_spare_talk.tcl`

---

## 1. Краткий итог

Блок закрыт: правила состояний червя вынесены в отдельный модуль, актёр-обёртка переиспользует
навигационно-taskный адаптер хомяка, поведение проверено на фейковом адаптере без сцены, а
headless-сцена мультиплеера грузится без ошибок и печатает состояние актора. Свободные черви на
карте не создаются.

| Что | Итог |
|---|---|
| Модуль правил | `scripts/native_raupe_ai.gd` — чистые правила, 4 состояния, 11-тиковый цикл поиска растения |
| Актёр | `scripts/native_raupe_actor.gd` — обёртка (НЕ subclass хомяка), очередь действий на `native_tasklist.gd` |
| Правила фермы | `scripts/native_farm_raupe.gd` — счётчик, корм, замок, кулдаун, лимит |
| RNG | `scripts/diggles_irandom.gd` — MT19937 оригинала, сидируемый, состояние сериализуется |
| Self-test на фейке | `tools/native_raupe_ai_self_test.gd` — **143 проверки**, зелёные |
| Self-test актёра | `tools/native_raupe_actor_self_test.gd` — **58 проверок**, зелёные |
| Self-test фермы | `tools/native_farm_raupe_self_test.gd` — **41 проверка**, зелёные |
| Headless-сцена | `tools/native_raupe_scene_self_test.gd` — **14 проверок**, зелёные |
| **Итого по блоку** | **256 проверок, 0 падений** |
| Полный прогон | раннер `MiniMax\Diggles\tools\run_suite.ps1`: **53 уникальных набора, 0 падений** |
| Свободные черви на карте | не создаются (проверено текстом сцены/скрипта и обходом дерева) |

### 1.1. Важное расхождение с заданием: хищных вариантов четыре, а не девять

В постановке задачи стоит: «`attacktyp = 0`, если `rtyp` НЕ входит в `{02, 06, 07, 08}`;
иначе `attacktyp = 1` (то есть хищными являются 9 вариантов из 13, а не 4)» и приёмочный пункт
«ровно `02/06/07/08` никогда не входят в `plant_attack`». Эти два утверждения противоречат друг
другу, и **оба расходятся с оригиналом**. Порт сделан по оригиналу:

```tcl
# raupe.tcl:48-52
if {[land $rtyp {02 06 07 08}]==""} {
    set attacktyp 0
} else {
    set attacktyp 1
}
```

`land` — пересечение списков движка («list and», родственник `lnand`/`lor`): **непусто, когда
элемент ЕСТЬ в списке**. Это доказывается другими вызовами игры:

| Вызов | Что проверяет | Вывод |
|---|---|---|
| `std_ai.tcl:1430` — `if {[land $item $stealboxlist]!="" ...}` | «предмет — ящик для воровства» | непусто ⇒ элемент **найден** |
| `std_ai.tcl:1460` — `if {[land $gnome $UnavailableGnomesList]==""}` | гном добавляется в список свободных, если его **нет** в списке недоступных | пусто ⇒ элемент **не найден** |
| `std_ai.tcl:2148` — `if {[land $gnome $idlegnomelist]!=""}` | гном уже в списке простаивающих | непусто ⇒ элемент **найден** |
| `z_spare_talk.tcl:174, :188` — `if {[land $starter $talk_partner]!=""}` | «FEHLER» при повторном партнёре | непусто ⇒ элемент **найден** |
| `fallen.tcl:125`, `lager.tcl:129`, `spinne.tcl:578` | пересечение двух списков | `land A B = A ∩ B` |

Значит `land $rtyp {02 06 07 08}` пусто **тогда и только тогда, когда типа НЕТ в списке**, то есть
`attacktyp = 1` получают ровно типы **02, 06, 07, 08** — **четыре** хищных варианта из тринадцати.
Это подтверждается и `find_plant`, который выходит сразу при `attacktyp == 0` (`raupe.tcl:119`):
искать растение могут только четыре типа.

Проектная спецификация `docs/plan/raupe-ai-2026-11-19.md` уже содержит эту поправку
(«❌ ИНверсия: хищные — это 02/06/07/08 (4 из 13)»). Порт, тесты и отчёт следуют оригиналу:
**02/06/07/08 едят растения, остальные девять — никогда.**

---

## 2. Проверенный контракт (правила со ссылками на строки оригинала)

Все правила выверены построчно. Колонка «Порт» указывает функцию модуля правил или актёра.

### 2.1. Создание и класс

| Правило | Оригинал | Порт |
|---|---|---|
| Вариант `irandom(1,13)`, при длине < 2 дописывается ведущий ноль → `01`..`13` | `raupe.tcl:31-32` | `RaupeAi.variant_tag`, `Actor.setup` |
| `attacktyp = 1` для `02/06/07/08` (четыре хищных), иначе `0` | `raupe.tcl:48-52` | `RaupeAi.attack_type` / `is_predatory` |
| `weight 0.01`, `hitpoints 0.02`, случайный yaw | `raupe.tcl:40-41, :60` | `RaupeAi.HITPOINTS/WEIGHT`, `Actor.setup` |
| `attack_counter = 0`, `attackplant = 0`, `approached = 0`, `attackanim = 5` | `raupe.tcl:53-56` | поля состояния актёра |
| Класс `Raupe food material 0 {reproduces lives moves}` | `raupe.tcl:3` | заголовок модуля |
| Анимации: `standstill`/`hangstill` → `raupeNN.standard`; `crawl*`/`turn*` → `raupeNN.kriechen` | `raupe.tcl:6-20` | `RaupeAi.anim_clip`, `Actor._set_anim` |
| Порядок порта ведём как `anim_mode` (`wait`/`crawl`): перед `move` — `kriechen`, перед `wait` — `standard` | `raupe.tcl:148-164` | `Actor._start_move` / `_wait_idle` |
| Скорость движения `0.03` | `raupe.tcl:155` | `RaupeAi.MOVE_SPEED` |

### 2.2. Таймер и переходы

| Правило | Оригинал | Порт |
|---|---|---|
| Таймер `evt_timer0`, интервал 1 с | `raupe.tcl:166` | `Actor.TIMER_INTERVAL` |
| Каждый тик: `test_farmed` → свежий переход в `free` (фермы нет) или `farmed` | `raupe.tcl:169-178` | `Actor._timer_event` + `_apply_pending` |
| Переход — новый триггер состояния, а не падение сквозь состояние | `raupe.tcl:172, :175` | `Actor._trigger`: имя состояния меняется сразу, тело нового состояния стартует со следующего шага |
| `test_farmed`: поиск `Farm` в боксе `(-2,-0.5,-3)..(2,0.5,3)` | `raupe.tcl:62-65` | `RaupeAi.farm_query`, `Actor._classify_farm` |

### 2.3. Состояние `free` (`raupe.tcl:207-216` + `crawl_free` `67-85`)

| Правило | Оригинал | Порт |
|---|---|---|
| `is_contained` → переход в `contained`, анимация `standard`, `anim = wait` | `raupe.tcl:208-212` | `Actor._free_proc` |
| `get_max_fow < 10` → **ничего не делать** (не идти в туман); гейт стоит **до** `find_plant` | `raupe.tcl:68` | `Actor._crawl_free` |
| `crot = roty + 1.57`; `nrot = crot + rand()*3 - 1.5` | `raupe.tcl:70-71` | `RaupeAi.free_turn`, `Actor._crawl_free` |
| **Сначала** `find_plant()`: если цель найдена — блуждание не выполняется | `raupe.tcl:72` | `Actor._crawl_free` |
| `rand() < 0.2` → `nrot += 3.14` (разворот) | `raupe.tcl:73-75` | `RaupeAi.free_reverse` |
| `npos = rpos + get_vectorxz(nrot, random(2.0, 4.0))` | `raupe.tcl:76` | `RaupeAi.free_candidate` |
| `get_place(center=npos, circle=3, nearpos=rpos, random=2)` | `raupe.tcl:77` | `RaupeAi.free_place_request` |
| `place[0] < 0` → `wait 3`; иначе `roty = get_anglexz(rpos,place)-1.57` и `move(place)` | `raupe.tcl:78-84` | `Actor._crawl_free` (`PLACE_MIN_FREE = 0`) |

### 2.4. Состояние `farmed` (`raupe.tcl:218-236` + `crawl_farmed` `87-115`)

| Правило | Оригинал | Порт |
|---|---|---|
| `is_contained` → `contained` | `raupe.tcl:219-223` | `Actor._farmed_proc` |
| Ферма невалидна (`!obj_valid` **или** `!get_buildupstate`) → немедленно `free` | `raupe.tcl:225-227` | `Actor._farm_is_valid` |
| `rand() < 0.05` → `wait 1` | `raupe.tcl:229-230` | `RaupeAi.farmed_wait`, `WAIT_FARMED` |
| Гном рядом с фермой (`±3, ±5`), иначе центр = позиция червя | `raupe.tcl:91-97` | `RaupeAi.dwarf_query`, `Actor._crawl_farmed` |
| `xn = dx-2`, `zn = dz-3`, `xp = xn+3.5`, `zp = zn+6` (прямоугольник относительно центра) | `raupe.tcl:98-102` | `RaupeAi.farm_rectangle` |
| `get_place(center, rect, mindist 0.6, nearpos=поз.червя только если есть гном, random 2)` | `raupe.tcl:104-108` | `RaupeAi.farm_place_request` |
| `place[0] < 1` → `wait 3`; иначе поворот и `move` | `raupe.tcl:109-114` | `Actor._crawl_farmed` (`PLACE_MIN_FARM = 1`) |
| **В состоянии `farmed` атака по растению не выполняется** | ветки атаки в `raupe.tcl:218-236` нет | `Actor._farmed_proc` не вызывает `_find_plant` |

### 2.5. Состояние `contained` (`raupe.tcl:238-251`)

| Правило | Оригинал | Порт |
|---|---|---|
| Пока в инвентаре → `wait 4` и снова | `raupe.tcl:239-240` | `Actor._contained_proc` (`WAIT_CONTAINED = 4`) |
| Иначе — пересчёт `test_farmed`: нет фермы → `free`, есть → `farmed` | `raupe.tcl:241-250` | `Actor._contained_proc` |

### 2.6. Состояние `plant_attack` (`raupe.tcl:253-319`)

| Правило | Оригинал | Порт |
|---|---|---|
| `hitpoints < 0.01` → `destruct` + `del` | `raupe.tcl:254-258` | `Actor._plant_attack_proc` → `_destroy` |
| `is_contained` → сброс цели и `approached`, переход в `contained` | `raupe.tcl:259-266` | `Actor._plant_attack_proc` → `_clear_target` |
| Цель невалидна → сброс цели и `approached`, переход в `free`, анимация `kriechen` | `raupe.tcl:267-273` | `Actor._plant_attack_proc` |
| `angle = get_anglexz(ppos, mpos)` | `raupe.tcl:277` | `RaupeAi.angle_xz` |
| `approached == 0`: `abs(dist3d-0.55) < 0.1` → `approached = 1` (выход) | `raupe.tcl:307-312` | `RaupeAi.approach_finished` |
| `approached == 0`: иначе `place = ppos + get_vectorxz(angle, 0.55)`, поворот к растению, `move` | `raupe.tcl:313-317` | `RaupeAi.approach_point`, `Actor._plant_attack_proc` |
| `approached == 1`: `approached = 2`; `attackanim = lindex {5 9} [irandom 2]` | `raupe.tcl:279-281` | `RaupeAi.attack_frame`, `Actor._plant_attack_proc` |
| `particledir = get_vectorxz(angle,0.02)` с `y = -0.02`; `particlepos = ppos + particledir*15.0` | `raupe.tcl:282-284` | `RaupeAi.attack_particle` |
| `roty = angle + 1.57` (смотрит на растение) | `raupe.tcl:285` | `RaupeAi.yaw_away` |
| Анимация `kriechen` разово, пауза `0.5`/`0.9` (`wait 0.$attackanim`), затем кадр `attackanim` и пауза 1 с | `raupe.tcl:286-293` | очередь шагов `anim 0` → `wait` → `anim N` → `wait 1.0` |
| `approached >= 2`: урон растению `-0.03` | `raupe.tcl:295` | `Actor._plant_attack_proc` → `_damage_plant` |
| Кадр `attackanim-1`, пауза `0.2` → `create_particlesource 15 pos dir 16 1` → свои hitpoints `-0.05` → кадр `attackanim` → пауза 1 с | `raupe.tcl:296-305` | шаги `anim` → `wait 0.2` → `strike` → `anim` → `wait 1.0` |
| Итого урон — раз в **1.2 с** (0.2 + 1.0), первый «замах» — 0.5/0.9 с + пауза 1 с | вывод из `raupe.tcl:295-305` | очередь шагов актёра |

### 2.7. `find_plant` (`raupe.tcl:117-146`)

| Правило | Оригинал | Порт |
|---|---|---|
| `attacktyp == 0` → сразу 0 | `raupe.tcl:119` | `Actor._find_plant` |
| `attack_counter < 10` → `+= 1` и 0; иначе сброс в 0 и поиск → **реальный поиск на 11-м вызове** | `raupe.tcl:120-124` | `RaupeAi.attack_counter_step` |
| `get_owner(this) == -1` → 0 (нужен валидный владелец) | `raupe.tcl:125` | `Actor._find_plant` (`owner_id`) |
| `obj_query(this, -class Fresspflanze, -range 8, -limit 1)` | `raupe.tcl:126` | `RaupeAi.plant_query` |
| Растение дальше 5.0 → `get_place(center=растение, circle 5.0, mindist 2.0, nearpos=поз.червя)`; при `place[0] > 0` цель найдена | `raupe.tcl:130-137` | `RaupeAi.plant_place_request`, `PLACE_MIN_PLANT = 1` |
| Растение ближе 5.0 → цель найдена сразу | `raupe.tcl:138-143` | `Actor._find_plant` |
| Переход в `plant_attack` — свежий триггер | `raupe.tcl:135, :141` | `Actor._trigger` |
| Цель назначается **только** при фактическом переходе | `raupe.tcl:134, :140` (`set attack_plant` стоит внутри веток с `state_triggerfresh`) | `Actor._find_plant` |

### 2.8. Правила фермы (`farm.tcl`)

| Правило | Оригинал | Порт |
|---|---|---|
| Кандидаты: `Raupe` в боксе `x ±2`, `z ±3`, исключая `contained` | `farm.tcl:245` | `Farm.candidate_request` (`CANDIDATE_BOX = (2, 0.5, 3)`) |
| Максимум **6** червей на ферму (`if {$rl<6}`) | `farm.tcl:248` | `Farm.MAX_WORMS` |
| Пересоздание только если `gnomewashere` | `farm.tcl:250` | `Farm.production_plan` (`reason = "no_dwarf"`) |
| Порог `farmcounter > 60 - material*12 + rand()*5` (строгое `>`) | `farm.tcl:251` | `Farm.threshold` |
| При успехе `wormfodder -= 30`, `farmcounter = 0` | `farm.tcl:252-255` | `Farm.apply_creation` (`WORM_FODDER_COST = 30`) |
| Счётчик растёт, только если гном был, порог не пересечён и черви в ферме есть | `farm.tcl:248-259` | `Farm.production_plan` (`reason = "counter"`) |
| `actualize_worm`: сохранить замок на `originalworm`, иначе взять первого с `get_lock == 0` | `farm.tcl:470-481` | `Farm.actualize_worm` |
| `free_originalworm`: `set_lock originalworm 0`, `originalworm = 0` | `farm.tcl:354-358` | `Farm.free_original_worm` |
| `remove_from_inv_raupe`: взять тип из инвентаря, удалить, пересоздать того же типа | `farm.tcl:334-343` | `Farm.inventory_removal` |
| `recreate_raupe`: общий кулдаун `gettime - lastcreation < 50` → отказ | `farm.tcl:500` (общий с хомяком, `farm.tcl:484`) | `Farm.can_recreate` (`CREATION_COOLDOWN = 50`) |
| `recreate_raupe`: `get_place(center=farm, rect -1.7 -2.5 1.7 2.5, random 2)` | `farm.tcl:502` | `Farm.recreate_request` |
| `recreate_raupe {typ 0}`: `set_type typ` | `farm.tcl:507-509` | `Farm.inventory_removal` → `recreate` |
| `farmcounter` стартует с 50, `wormfodder` ветки Raupe — со 100, `lastcreation` — с 0.0 | `farm.tcl:74, :79, :140` | `Farm.INITIAL_FARM_COUNTER/INITIAL_WORM_FODDER/last_creation` |

---

## 3. Файлы

### 3.1. Файлы блока в дереве `MiniMax\Diggles\godot`

| Файл | Роль |
|---|---|
| `scripts/native_raupe_ai.gd` | модуль правил: варианты, геометрия, все запросы `get_place`/`obj_query`, значения таймеров, пороги атаки, правила фермы |
| `scripts/native_raupe_actor.gd` | актёр-обёртка: конечный автомат 4 состояний, очередь действий на `native_tasklist.gd`, адаптеры мира, сериализуемое состояние |
| `scripts/native_farm_raupe.gd` | правила ветки «Raupe» фермы: кандидаты, лимит, порог, корм, замок, кулдаун |
| `scripts/diggles_irandom.gd` | MT19937 оригинала (по дизассемблированию), сидируемый, `get_state`/`set_state` |
| `scripts/native_raupe_probe.gd`, `scenes/native_raupe_probe.tscn` | пробная сцена: один червь ползает по полу, состояние читается тестом |
| `tools/native_raupe_ai_self_test.gd` | self-test правил и поведения на фейковом адаптере (143 проверки) |
| `tools/native_raupe_actor_self_test.gd` | self-test актёра (58 проверок) |
| `tools/native_farm_raupe_self_test.gd` | self-test правил фермы (41 проверка) |
| `tools/native_raupe_scene_self_test.gd` | headless-сцена: мультиплеер грузится, печатается состояние актора, нет свободных червей (14 проверок) |

### 3.2. Изменённые существующие файлы

Существующие модули проекта **не переписывались**. Правки — только в файлах этого же блока:

| Файл | Правка | Обоснование |
|---|---|---|
| `scripts/native_raupe_actor.gd` | `find_plant`: `attack_plant` присваивается **только** при фактическом переходе | оригинал ставит `set attack_plant $plant` только в ветках с `state_triggerfresh` (`raupe.tcl:134, :140`); прежняя версия оставляла «протухшую» цель при неудачном `get_place` |
| `scripts/native_raupe_actor.gd` | очередь действий переведена на `native_tasklist.gd` (шаги `wait`/`anim`/`strike`) вместо цепочки `_after_wait` | прямое требование задания: актёр переиспользует task-адаптер хомяка; очередь становится наблюдаемой (`get_queue_commands()`) |
| `scripts/native_raupe_actor.gd` | шаг `wait` не «съедает» весь кадр: остаток времени переносится на следующий шаг | иначе ветер 0.5+1.0 истекал за один кадр и укус наносился раньше замаха |
| `scripts/native_raupe_actor.gd` | классификация таймера запоминается (`_pending_classification`) и применяется в ближайший свободный момент; освобождение из инвентаря замечается таймером в течение секунды | см. §5.2 «Инженерный адаптер» |
| `scripts/native_raupe_actor.gd` | в снимок добавлены `variant_id`, `attack_plant_id`, `contained`, `next_decision_time` | список сериализуемого состояния из задания |
| `tools/native_raupe_ai_self_test.gd` | переписан: был набор проверок только чистых функций (85) — стало 143 проверки на фейковом адаптере по списку приёмки | требование задания: «Self-test … на фейковом адаптере, без сцены» |
| `tools/native_raupe_scene_self_test.gd` | мультиплеер теперь реально **инстанцируется** и прогоняется, печатается состояние актора; добавлена проверка «в дереве сцены нет узла со скриптом Raupe» | требование задания: «сцена мультиплеера грузится без ошибок и печатает состояние актора» |

Файлы вне дерева `godot` не менялись, кроме этого отчёта и его копии. Раннер
`MiniMax\Diggles\tools\run_suite.ps1` уже содержит четыре набора червя — список не редактировался.

---

## 4. Архитектура

```
native_raupe_ai.gd          native_raupe_actor.gd            мир (хост)
─────────────────────       ────────────────────────         ──────────────────
правила, запросы,           конечный автомат,                 ферма, гном, растение,
значения оригинала          очередь действий (TaskList),       видимость, get_place,
                            адаптеры, снимок состояния        навигация, частицы
        │                          │                                 ▲
        └──────────────────────────┴─────────────────────────────────┘
                            native_farm_raupe.gd  ──► правила ветки Raupe фермы
```

**Адаптерный контракт актёра** (`native_raupe_actor.gd`, все вызовы необязательны):

| Ключ | Сигнатура | Назначение |
|---|---|---|
| `actor_pos` | `() -> Vector3` | позиция червя |
| `max_fow` | `() -> float` | `get_max_fow` (порог 10) |
| `is_contained` | `() -> bool` | наличие в инвентаре |
| `owner_id` | `() -> String` | `get_owner` (нужен валидный владелец) |
| `query_farm` | `(Dictionary) -> Dictionary` | `test_farmed` |
| `farm_state` | `(String) -> Dictionary` | `obj_valid` + `get_buildupstate` |
| `query_dwarf` | `(Dictionary) -> Dictionary` | гном в боксе фермы |
| `query_plant` | `(Dictionary) -> Dictionary` | `Fresspflanze` в радиусе 8 |
| `plant_state` | `(String) -> Dictionary` | `obj_valid` растения + позиция |
| `pick_place` | `(Dictionary) -> Dictionary` | `get_place` → `{code, position}` |
| `damage_plant` | `(String, float) -> void` | `set_damage` |
| `emit_particles` | `(Dictionary) -> void` | `create_particlesource` |
| `destroy_actor` | `() -> void` | `destruct` + `del` |
| `move_action` / `move_complete` | `(Dictionary) -> bool` / `() -> bool` | навигационный `move` |
| `play_clip` | `(Dictionary) -> bool` | привязка клипа (`raupeNN.standard` / `raupeNN.kriechen`) |

Форма `get_place` в оригинале — список, чей первый элемент — код (`raupe.tcl:78, :109, :132`).
Порт сохраняет эти пороги: `≥ 0` для `free`, `≥ 1` для `farmed` и подхода к растению.

Публичные методы актёра: `setup(adapters, seed)`, `tick(delta)`, `get_state`, `get_variant`,
`get_variant_tag`, `get_attack_type`, `get_hitpoints`, `get_anim_mode`, `get_attack_plant`,
`get_approached`, `get_yaw`, `get_farm_id`, `get_next_decision_time`, `is_contained`,
`get_queue_commands`, `get_trace`, `set_variant`, `set_owner`, `set_farm`, `set_contained`,
`get_state_snapshot`, `restore_from_snapshot`. Червяк **не** является подклассом хомяка: своя
машина состояний, свой анимационный контракт (`standard`/`kriechen`), свой адаптер.

---

## 5. Факт / инженерный адаптер / неизвестное

### 5.1. Факт (выверено по оригиналу)

Всё, что перечислено в §2, взято построчно из `raupe.tcl`, `farm.tcl` и снабжено ссылкой на
строки. Отдельно подтверждено по исходникам оригинала:

* вариант `01..13` и правило хищности через семантику `land` (`raupe.tcl:31-32, :48-52`;
  `std_ai.tcl:1430, :1460, :2148`; `z_spare_talk.tcl:174, :188`);
* четыре состояния и их выходы (`raupe.tcl:207-319`);
* 11-тиковый цикл поиска растения (`raupe.tcl:120-124`);
* урон растению `0.03`, самоурон `0.05`, смерть ниже `0.01` (`raupe.tcl:254, :295, :300`);
* частицы `15 / позиция / направление / 16 / 1` (`raupe.tcl:299`);
* пределы и пороги фермы (`farm.tcl:245, :248, :251, :254, :500, :502`);
* гейт видимости стоит **до** `find_plant` (`raupe.tcl:68`).

### 5.2. Инженерный адаптер (выбор порта, а не факт из оригинала)

| Решение | Почему так | Что в оригинале известно |
|---|---|---|
| Классификация таймера **запоминается** и применяется в ближайший момент, когда актёр свободен от действия | `state_triggerfresh`/`state_enable` в Tcl-исходниках не описаны; при «переключении всегда» ветка атаки по растению становится мёртвым кодом (таймер уводил бы состояние в `free` до куса) | `raupe.tcl:169-178` (таймер), `:286-305` (цикл укуса с `state_disable`/`state_enable`) |
| Состояние `plant_attack` владеет собой, пока цель жива | иначе укус не завершается никогда | `raupe.tcl:253-319` (три выхода: контейнер, невалидное растение, смерть) |
| Освобождение из инвентаря замечается **таймером** (в течение секунды) | приёмка требует и «классификация/освобождение по 1-секундному таймеру», и «contained ждёт интервалами по 4 с»; в оригинале проверка `is_contained` живёт в теле `contained` раз в 4 с | `raupe.tcl:238-251` |
| Пока содержимое инвентаря не меняется, интервал проверки — 4 с | совпадает с оригиналом | `raupe.tcl:240` (`wait 4`) |
| Знак урона: порт передаёт **модуль** величины (`0.03`, `0.05`), оригинал — `-0.03`, `-0.05` | знак — свойство адаптера (`set_damage`/`add_attrib` в движке) | `raupe.tcl:295, :300` |
| `roty` оригинала = заголовок − π/2; порт хранит именно `roty` и даёт `heading()` | `get_anglexz`/`get_vectorxz` — встроенные функции движка; конвенция `atan2(dx,dz)` совпадает с уже принятой в проекте для хомяка (`native_wild_hamster.gd`) | `raupe.tcl:70-81, :112, :277-285` |
| Очередь действий актёра — `native_tasklist.gd` | прямое требование задания (переиспользование task-адаптера хомяка) | — |
| RNG — MT19937 оригинала (`diggles_irandom.gd`), сид выбирает хост | оригинальный движок сеет генератор временем старта, поэтому побайтовое совпадение невозможно, но **последовательность вызовов** совпадает | `irandom`/`rand` — встроенные функции движка |
| Условие «гном был» задаётся адаптером | в оригинале это флаг `gnomewashere` фермы | `farm.tcl:73, :250` |

### 5.3. Неизвестное (не утверждается)

* Бой с гномами, лазание по стенам, сетевая репликация и команды игрока червя — **в оригинале не
  найдены**. `aggr_events.tcl` подключается классом (`raupe.tcl:25, :29`), но конкретного вызова
  `check_for_player_contact` в классе нет; червя **не** делаем враждебным юнитом.
* Точная семантика `state_triggerfresh`/`state_enable`/`state_disable` движка (виден только по
  последствиям, см. §5.2).
* Смысл чисел `16` и `1` в `create_particlesource 15 pos dir 16 1` — переносятся как есть.
* Собственная геометрия вариантов: ASCII-скан пакета `rohstoffe.3db` даёт имена
  `raupe01`…`raupe12` (12 объектов); `raupe13` в строках не найден — проверять инспектором
  пакетов (`tools/inspect_3db.py`) перед привязкой клипов.

---

## 6. Проверки

### 6.1. Блок червя (256 проверок, 0 падений)

| Набор | Проверок | Итог |
|---|---|---|
| `tools/native_raupe_ai_self_test.gd` | **143** | `NATIVE_RAUPE_AI_SELF_TEST_OK assertions=143` |
| `tools/native_raupe_actor_self_test.gd` | **58** | `NATIVE_RAUPE_ACTOR_SELF_TEST_OK assertions=58` |
| `tools/native_farm_raupe_self_test.gd` | **41** | `NATIVE_FARM_RAUPE_SELF_TEST_OK assertions=41` |
| `tools/native_raupe_scene_self_test.gd` | **14** | `NATIVE_RAUPE_SCENE_SELF_TEST_OK assertions=14` |

Разбивка `native_raupe_ai_self_test.gd` по пунктам приёмки:

| Пункт приёмки | Проверок | Как проверяется |
|---|---|---|
| Все 13 вариантов выбираются | 3 + 17 | прогон 120 сидов собирает все теги `01..13`; `is_predatory`/`attack_type` для каждого из 13 |
| Хищны ровно 4 типа, остальные девять никогда не входят в `plant_attack` | 4 + 9×3 | типы `02/06/07/08` — `attack_type == 1`; каждый из девяти остальных прогоняется 20 тиков с растением рядом: состояние остаётся `free`, урон не наносится |
| Видимость < 10 → нет навигационного запроса | 3 | `max_fow = 9.9`: ни одного `pick_place`, нет `move`, состояние `free` |
| Неудачный `get_place` → ожидание 3 с | 4 | `code = -1`: нет `move`, ровно одно ожидание длиной 3.0, анимация `wait` |
| Классификация фермы и освобождение по 1-секундному таймеру | 6 | 0.5 с → ещё `free`; 1.0 с → `farmed`; прямоугольник фермы `x −2..1.5`, `z −3..3`; ферма без `buildup` → `free`; освобождение из инвентаря → `free` за один тик |
| `contained` ждёт интервалами по 4 с | 4 | за 10 с ровно три ожидания по 4.0 с |
| Поиск растения на 11-м тике | 4 | 10 тиков → `free` и 10 запросов места без поиска; 11-й → `plant_attack` с целью |
| Подход до `0.55 ± 0.1` | 5 | цель подхода на расстоянии 0.55 от растения; `approached` 0 → 1 при попадании в допуск |
| Урон и самоурон только после замаха | 8 | во время замаха `damages` пуст и hitpoints 0.02; после замаха — ровно один урон 0.03; затем частицы источника 15 и hitpoints −0.03 |
| Смерть при HP < 0.01 | 3 | после самоурона hitpoints < 0.01 → `destroy_actor` вызван ровно один раз |
| Исчезновение растения / невалидная ферма / инвентарь / снятие lock — нет протухшей цели | 11 | пропавшее растение → `free`, цель пуста, `approached = 0`; инвентарь во время атаки → `contained`, цель пуста; растение без подходящего места → цель не назначается; `free_original_worm` → замок снят |
| Повтор с тем же seed → та же последовательность | 4 | одинаковый тип, одинаковый trace, одинаковые цели движения, одинаковые запросы места |
| Снимок состояния | 6 | `variant_id`, `contained`, `next_decision_time`, RNG; восстановление сохраняет тип, состояние и hitpoints |
| Правила фермы: 6, порог, корм, кулдаун, прямоугольник | 20 | лимит 6, `60 − material*12 + rand()*5`, расход 30, кулдаун 50 с, прямоугольник `±1.7 / ±2.5`, бокс кандидатов `±2 / ±3`, `actualize_worm`, снятие замка |

### 6.2. Полный прогон существующих наборов

Раннер: `MiniMax\Diggles\tools\run_suite.ps1` (Godot 4.7.2 stable, `--headless`).
Логи: `out/raupe-ai-2026-11-19/raupe-final-<набор>.log`, CSV: `out/raupe-ai-2026-11-19/suite_raupe-final.csv`.

**Итог: 53 уникальных набора, 53 зелёных, 0 падений** (в раннере 57 записей; повторы
`native_model_programs_self_test`, `native_autolight_self_test`, `native_torch_placement_self_test`
дедуплицируются скриптом). Состав: 45 базовых наборов проекта + 4 набора генератора кампании +
4 набора червя.

Ключевые строки прогона:

```
[raupe-final] native_hamster_ai_self_test       exit=0 :: NATIVE_HAMSTER_AI_SELF_TEST_OK assertions=69
[raupe-final] native_hamster_actor_self_test    exit=0 :: NATIVE_HAMSTER_ACTOR_SELF_TEST_OK assertions=66
[raupe-final] native_wild_hamster_self_test     exit=0 :: NATIVE_WILD_HAMSTER_SELF_TEST_OK assertions=57
[raupe-final] native_raupe_ai_self_test         exit=0 :: NATIVE_RAUPE_AI_SELF_TEST_OK assertions=143
[raupe-final] native_raupe_actor_self_test      exit=0 :: NATIVE_RAUPE_ACTOR_SELF_TEST_OK assertions=58
[raupe-final] native_farm_raupe_self_test       exit=0 :: NATIVE_FARM_RAUPE_SELF_TEST_OK assertions=41
[raupe-final] native_raupe_scene_self_test      exit=0 :: NATIVE_RAUPE_SCENE_SELF_TEST_OK assertions=14
=== FAILURES ===
=== raupe-final: 53 tests, 0 failing ===
```

Предупреждений GDScript в логах блока нет. Сообщение `ObjectDB instances were leaked at exit`
(20) в сценовом наборе — общий для проекта паттерн: в baseline-прогонах
(`out/live-suite-2026-11-19`) тот же счётчик дают 18–33 (у `native_hamster_actor_self_test` — 66).

---

## 7. Что осталось открытым

| Пункт | Состояние | Почему не сделано |
|---|---|---|
| Клипы `raupeNN.standard` / `raupeNN.kriechen` | **не привязаны** | геометрия вариантов не извлечена: в проекте есть только `rohstoffe.3db::raupe01` в манифесте (`models/multi_start_010_models.json`) с одной анимацией `standard`; клипа `kriechen` и вариантов `02..13` в проекте нет. По заданию привязка отложена до инвентаризации исходных ассетов; состояния при этом полные — анимация идёт через `anim_mode` (`wait`/`crawl`) и `play_clip` |
| Свободные черви на карте | **не создаются** | по заданию сцену нельзя наполнять «тихим» спавном; карта уже содержит два статичных объекта класса `Raupe` (строки 315 и 321 исходного `multi_start_010.tcl`), они рендерятся как декорации и акторами не являются |
| Сетевая репликация | **не реализована** | в оригинале не найдена; в порте есть только сериализуемый снимок состояния (`get_state_snapshot` / `restore_from_snapshot`) |
| Команды игрока червя, бой с гномами, лазание | **не реализовано** | в оригинале не найдено (`aggr_events.tcl` подключён, но вызова `check_for_player_contact` в классе нет) |
| Ферма как объект сцены | **только правила** | `native_farm_raupe.gd` содержит правила ветки «Raupe» (лимит, порог, корм, замок, кулдаун); сам объект `Farm` в порте пока не вызывает их — это отдельная задача |
| Связь с `Fresspflanze` | **только адаптер** | класс растения в порте не реализован; используются `query_plant` / `plant_state` / `damage_plant` |

---

## 8. Конкурентная работа в дереве

Во время выполнения задачи в том же дереве `MiniMax\Diggles\godot` параллельно работал другой
агент над тем же блоком: он создал `native_raupe_ai.gd`, `native_raupe_actor.gd`,
`native_farm_raupe.gd`, `diggles_irandom.gd`, пробную сцену, четыре self-test'а и черновик этого
отчёта (23:03–23:24). Эта работа **не выброшена**: она взята за основу; исправлены «протухшая»
цель в `find_plant` и ошибка тайминга шага ожидания, очередь действий переведена на
`native_tasklist.gd`, классификация таймера перестала теряться во время действия, а тесты
дополнены до приёмки задания (143 + 58 + 41 + 14 проверок). Каталог
`MiniMax\Diggles\work\campaign\` не трогался. Дерево Codex и оригинальная игра — только чтение.

Проектная спецификация `docs/plan/raupe-ai-2026-11-19.md` уже содержит поправку про
`attacktyp` (§1.1) — порт следует ей и оригиналу.

---

INTEGRATION_HANDOFF: docs/reverse-engineering/agent-result-raupe-ai-2026-11-19.md
