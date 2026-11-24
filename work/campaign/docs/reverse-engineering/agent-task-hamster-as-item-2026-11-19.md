# Задача агенту: хомяк как предмет, еда и производственный слот

## Цель

Закрыть два белых пятна отчёта об интеграции хомяков:

- **№4** — гномы не берут хомяка как предмет: в живом проекте есть только датчик
  близости ≤ 2, то есть решение принимает расстояние, а не гном;
- **№5** — класса `Pilzhut` в манифесте сцены нет; еда сцены — `Grillpilz`
  (3 плейсмента) и `Pilz` (3).

Задача — восстановить исходный контракт и перенести его: хомяк это **предмет,
который занимает производственный слот фермы**, а не «объект рядом».

Это исследование и подготовка интеграции. Основной проект не редактировать.

## Контекст и источники

- Основной проект, **только чтение**:
  `C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles`
- Снимок MCode (единственное место записи):
  `C:\Users\frant\.minimax\sessions\mvs_e213cb8b6788404489ad3b0b5c39827f\workspace\Diggles-mcode`
- Исходная игра, только чтение:
  `C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris`
- Godot 4.7.2:
  `C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe`

## Уже установлено в оригинале (проверено 19.11)

`data/Scripts/ai/std_ai.tcl`:

- 1873 — `set farms [land $prodlist [prod_get_task_all_places $populationowner Hamster]]`:
  места ферм, производящих `Hamster`.
- 1875–1879 — состав `farmitems`: `{Pilz Pilz}` плюс повторы
  `" Hamster Raupe Pilz"` по `farmcount/3+1`; лишние отбрасываются.
- 1901–1904 — `lappend forbidden Pilzhut` и `lappend inventlist {Pilz 1.0}`:
  **`Pilzhut` в оригинале — производимое изделие кланового ИИ, а не класс
  уровня**. Значит « Pilzhut нет в манифесте» — не белое пятно, а факт:
  в этой сцене еда и изделия — `Pilz`, `Grillpilz`, а `Pilzhut` был бы продуктом
  фермы, если есть производство.
- 1907–1916 — `foreach farmclass {Hamster Raupe}`: ферме нужен свой класс.
- 1936–1950 — **ключевое правило**: если слот фермы уже занят (`get_prod_slot_cnt`
  = 1) предметом из `{Pilz Hamster Raupe}`, ферма считается занятой и под новый
  класс не переводится.
- 1957–1968 — решение о постройке принимает клановый ИИ:
  `get_owner_attrib`, `get_prod_slot_buildable`, `set_prod_slot_cnt $farm $item 10`.
  То есть «взять хомяка» — это **решение гнома/клана**, а не близость.
- 3219 — `lappend productlist {Reithamster -1 1.00 0.7 exp_Transport 0}`:
  верховая езда на хомяке = транспортная способность.
- 1180 — `set eatclasses {Grillpilz Grillhamster Pilzbrot Raupensuppe
  Raupenschleimkuchen Hamstershake}`: что гном ест.

`data/Scripts/classes/characters/hamster.tcl`:

- 2 — `def_class Hamster food material 0 {reproduces lives moves}`:
  класс хомяка — еда/материал, который размножается.
- 34 — `set_class_anim goteaten hamster.gefressen_werden`;
  62 — `{walk_loop_wave hamster.gefressen_werden}`.
- 216 — `get_place -center {$preft} $clipping -circle 8 -mindist 0`:
  как хомяк ищет место.

## Что сделать

1. Прочитать `std_ai.tcl` вокруг строк 1850–1990 и 3200–3230 целиком и выписать
   контракт «ферма → предмет → слот» по шагам: что значит `prod_get_task_all_places`,
   `get_prod_slot_cnt`, `get_prod_slot_buildable`, `set_prod_slot_cnt`, как считается
   `farmitems`, что делает `forbidden`.
2. Разобрать `hamster.tcl` целиком: что значит `reproduces`, `lives`, `moves`,
   как хомяк становится предметом (`goteaten`, `gefressen_werden`), где порог
   питания 50 и паралич 1800 с — сверить с уже закрытым `native_hamster_ai.gd`
   в снимке MCode.
3. Определить по манифесту сцены, что реально доступно:
   `godot/models/multi_start_010_models.json` — 4 плейсмента `Hamster`,
   3 `Grillpilz`, 3 `Pilz`; никаких `Pilzhut`/`Grillhamster` в сцене нет.
   Зафиксировать это как факт и отдельно — как неизвестное (есть ли
   `Grillhamster` в других уровнях).
4. Спроектировать перенос: датчик хомяка у гнома должен срабатывать **по решению
   гнома** (производственный план/цель), а proximity остаться только как
   ограничение радиуса. Описать, где это живёт в коде живого проекта
   (`godot/scripts/native_actor_tasks.gd`, `native_dwarf_utility.gd`,
   `multiplayer_test.gd`) и что именно нужно перенести.
5. Сделать в своём дереве self-test с golden-значениями: правило «слот занят →
   ферма не переводится», состав `farmitems`, приоритет `Pilz`/`Hamster`/`Raupe`,
   запрет `Pilzhut` без производства.
6. Подготовить unified diff и отчёт.

## Ограничения

- Основной проект не редактировать.
- Не подменять клановое решение proximity-датчиком и наоборот: proximity —
  ограничение радиуса, решение — в плане гнома.
- `Pilzhut` не выдумывать: если для этого сценария его нет, зафиксировать как
  отсутствующий продукт, а не создавать класс.
- Факт / инженерный адаптер / неизвестное — раздельно.
- GDScript-предупреждения считаются ошибками: типы явно, неиспользуемые
  параметры с `_`, никаких `Variant` без типа.
- Godot запускать через `Start-Process` + `WaitForExit`, иначе он зависает до `quit()`.

## Результат

Создай в основном проекте только один новый файл:

`docs/reverse-engineering/agent-result-hamster-as-item-2026-11-19.md`

В нём должны быть:

1. Исходный контракт с точными строками `std_ai.tcl` и `hamster.tcl`.
2. Таблица «что есть в сцене / чего нет» по манифесту.
3. Схема переноса: где принимается решение гнома и где остаётся proximity.
4. Unified diff и новый self-test из рабочего дерева агента.
5. Результаты прогонов (число проверок, exit 0) и прежних наборов без регрессий.
6. Что осталось адаптером, а что факт; список белых пятен после блока.

В конце добавь строку:

`INTEGRATION_HANDOFF: docs/reverse-engineering/agent-result-hamster-as-item-2026-11-19.md`
