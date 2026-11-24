# Генератор уровня кампании — контракт из оригинала (заметка к задаче A)

**Дата:** 2026-11-19
**Источник:** `C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data`
**Цель:** перенести в Godot-проект процедуру `first_level` из
`data/Scripts/gameplay/Campaign.tcl`, чтобы уровень главы собирался из
оригинальных шаблонов, а не вручную.

Это разблокирует главы: без генератора каждый уровень — ручная работа,
а кампания состоит из процедурных уровней.

---

## 1. Что такое уровень в оригинале

Уровень — **не готовый файл**, а результат сборки шаблонов:

```
map create 512 640
sm_draw_stone -border
sm_draw_stone -funnel
generate_color_variation 0 0 512 640 0
set_light_begin 33
set_view_begin 23
set_view 246.7 28.8 1.478 -0.29 0.05

set temppos {208 0}; call templates/tcl/urw_unq_start.tcl
set temppos {260 12}; call templates/tcl/kris_gng_024_a.tcl; MapTemplateSet 260 12   # (кристальный мир, для сравнения)
set temppos {30 23}; call templates/tcl/urw_unq_hoehlenmalerei.tcl
map_setlayer2 30 23 data/templates/urw_unq_hoehlenmalerei.l2m
```

Мир Urwald: стартовый шаблон `urw_unq_start` в (208, 0), «пещерная живопись»
`urw_unq_hoehlenmalerei` в (30, 23) — **только слой материала** (`map_setlayer2`
без `map_template`, то есть без геометрии).

Миры кампании: **Urwald → Schwefel → Metall → Lava → Kristall → 6000**.
У каждого мира свой `Campaign*.tcl` со своей процедурой сборки.

## 2. Процедура `first_level` (Campaign.tcl:22-191)

Собирает уровень из пяти таблиц; выбор делает собственный RNG игры `irandom`.

| Таблица | Состав |
|---|---|
| `cavelist` | 5 пещер: `urw_hol_001_a` (20,4), `urw_hol_014_b` (20,12), `urw_hol_018_c` (28,16), `urw_hol_019_b` (24,16), `urw_hol_027_a` (16,4) — имя + смещение x,y |
| `comblist` | 8 комбинаций пар пещер; третий элемент — список y-сдвигов |
| `tunnlist` | 3 перехода: `urw_gng_013_` (4,0), `urw_gng_002_` (8,0), `urw_gng_003_` (12,0) — имя + смещение x,y |
| `conlist` | 6 схем соединений: например `{0 0 1 2}` — последовательность переходов |
| `vodolist` | 22 вудо-шаблона `urw_gng_001_`…`urw_gng_045_` с наборами букв-вариантов (`ab`, `abcd`, `abc`…) |
| `voconlist1` / `voconlist2` | 6 и 3 цепочки вудо-проходов: списки `{индекс_шаблона, dx, dy}` |

Порядок выбора (Campaign.tcl:101-175):

1. `set present_side [irandom 2]` — сторона; от неё зависят наборы букв:
   `left_letters = {abdef cgih}`, `right_letters = {cfkh abdeg}`.
2. `std_x = startx + 36`, `std_y = starty + 40`.
3. `comb = comblist[irandom 8]`; `std_y += ylist[irandom(len(ylist))]`.
4. `conn = conlist[irandom 6]`; `std_x += conn[0]` (первый элемент сдвигает x).
5. Набор вудо-цепочек зависит от `conn`: `idx<2` → только `voconlist2` (3),
   `idx<4` → обе (9), иначе только `voconlist1` (6); затем
   `vodo = voconlist[irandom(voconlen)]`.
6. Левая пещера: `cavelist[comb[0]]` → позиция `(std_x - xoffset, std_y - yoffset)`;
   затем «конец» `urw_gng_021_$letter` в `(std_x - xoffset - 4, std_y)`,
   буква из `left_letters`.
7. Правая пещера: `cavelist[comb[1]]` → `(std_x + 24, std_y - yoffset)`;
   затем `urw_gng_022_$letter` в `(std_x + xoffset + 24, std_y)`.
8. Переходы: для каждого элемента `conn` — шаблон `tunnlist[itemp]` в
   `(x, std_y + yoffset)`, `x += xoffset`; суффикс буквы — `irandom 2` для
   `urw_gng_002_` (`a`/`b`), иначе `irandom 3` (`a`/`b`/`c`).
9. Вудо-цепочка: для каждого элемента — шаблон `vodolist[itemp[0]]` + буква из
   набора вариантов, позиция `(vodo_x + dx, vodo_y + dy)`, где
   `vodo_x = x - 20`, `vodo_y = std_y + 4`.

Размещение (Campaign.tcl:178-190):

```
foreach nexttemp $temp_list {
    set template [lindex $nexttemp 0]
    set x [lindex $nexttemp 1]
    set y [lindex $nexttemp 2]
    sm_mark_temparea $x $y $template
    call "data/templates/$template.tcl"
    MapTemplateSet $x $y
}
```

После сборки (Campaign.tcl:198-216): удаляются все объекты класса `Wuker`,
создаётся `FogRemover` в (239, 14, 15) с `fog_remove 0 46 22`
(`set_undeletable 1`), `show_loading 0`.

## 3. Контракт шаблона (.tcl)

Каждый шаблон мира Urwald — файл `data/Templates/urw_*.tcl` с процедурой
`MapTemplateSet {xoffset yoffset}`:

```tcl
proc MapTemplateSet {xoffset yoffset} {
	 loading_objdetail high
	map_template data/templates/hol_001.pmp $xoffset $yoffset
	map_setlayer2 $xoffset $yoffset data/templates/urw_hol_001_a.l2m
	sel /obj
	set objhandle [new Dummy_Moos_uh_a "" "[expr {12.7888 + $xoffset}] [expr {6.5 + $yoffset}] 2.98" "0 0 0"]
	set_owner $objhandle -1
	set_physic $objhandle false
	set_autolight $objhandle false
	set_boxed $objhandle false
	... [new Pilz ...] [new Raupe ...] [new Stein ...] ...
	call_method $objhandle Editor_Set_Info {{age 3}}
}
```

То есть шаблон = **геометрия** (`map_template <pmp> x y`) + **слой материала**
(`map_setlayer2 x y <l2m>`) + **список объектов** (класс, локальные координаты,
поворот, флаги `owner`/`physic`/`autolight`/`boxed`, атрибуты вида `Editor_Set_Info`).

Инвентарь: в `data/Templates` — **874 файла `urw_*` (450 `.tcl` + 424 `.l2m`)**,
геометрия лежит отдельно в `.pmp` (например `hol_001.pmp`).

Важно: **гномы игрока тоже приходят из шаблона** — `urw_unq_start.tcl` создаёт
объекты `Zwerg` с `set_owner 0`, `set_autolight true`. Значит перенос шаблонов
закрывает и старт главы, а не только рельеф.

## 4. Что уже есть в проекте, чего не хватает

| Есть | Файл в живом проекте |
|---|---|
| Разбор PMP (рельеф) и L2M (слой материала) | `scripts/native_scene_profile.gd`, `models/*_profile.json` |
| Мир со сдвигом и подстановкой материала | `scripts/playable_world_space.gd` (`models/playable_world_space.json`) |
| Состояние грунта и мутации BDB | `scripts/native_terrain_state.gd`, `native_dig_*.gd` |
| Навигация и walkmap | `scripts/native_walkmap.gd`, `native_walk_flags.gd`, `native_navigation_representative.gd` |
| Спавн объектов сцены | `scripts/multiplayer_test.gd` (ветка `Hamster`, плейсменты из манифеста) |
| Манифест моделей и текстур | `models/multi_start_010_models.json` |

| Не хватает | Что нужно |
|---|---|
| **Композитор шаблонов** | разбор `urw_*.tcl` → (pmp, l2m, список объектов), наложение PMP и L2M по смещению, размещение объектов |
| **Генератор `first_level`** | перенос таблиц и порядка выбора, сборка списка `(шаблон, x, y)` |
| **RNG `irandom`** | воспроизведение исходного генератора; иначе — свой детерминированный RNG, помеченный как адаптер |
| **Карта 512×640** | сейчас поле 128×128 (`playable_world_space.json`, сдвиг (40,40)) — нужен составной уровень произвольного размера |
| **Туман по `FogRemover`** | прямоугольник `fog_remove 0 46 22` в (239,14,15) |
| **Удаление `Wuker`** | класс `Wuker` в размещаемых шаблонах |

## 5. Главный неизвестный: `irandom`

Проект (ROADMAP, фаза 5) прямо называет `irandom` предметом исследования.
Если RNG оригинала не воспроизведён, генератор даёт **процедуру** оригинала,
но не **те же** уровни. Тогда:

- вариант А (факт): найти реализацию `irandom` в EXE/Tcl и повторить её;
- вариант Б (адаптер): свой детерминированный RNG по seed, помеченный как адаптер,
  уровни становятся «в духе оригинала», но не те же.

Оба варианта допустимы, но выбор должен быть явным в отчёте.

## 6. Приёмка

1. Из оригинала извлечены таблицы `first_level` и формат шаблона — с точными
   строками.
2. Генератор по seed даёт **список `(шаблон, x, y)`** плюс список объектов
   (класс, позиция, флаги) — совпадающий с процедурой оригинала.
3. Собранный уровень: рельеф и слой материала совпадают с наложением шаблонов;
   гномы стоят на стартовом шаблоне, ресурсы (`Pilz`, `Raupe`, `Stein`) — на своих
   местах.
4. Проверка детерминизма: один seed → один и тот же уровень (побайтово/покомпонентно).
5. Уровень грузится в сцене без ошибок, гномы стоят на земле, ресурсы видны,
   туман снят в правильном прямоугольнике.
6. `multiplayer_test.gd` и существующие наборы не сломаны (регрессия).

## 7. Связанные файлы

- Оригинал: `data/Scripts/gameplay/Campaign.tcl`, `data/Templates/urw_*.tcl|l2m`,
  `data/Templates/*.pmp`.
- Живой проект: `godot/scripts/native_scene_profile.gd`,
  `godot/scripts/playable_world_space.gd`, `godot/scripts/native_terrain_state.gd`,
  `godot/scripts/multiplayer_test.gd`, `godot/models/playable_world_space.json`.
- Очередь: `MiniMax\Diggles\docs\plan\queue-2026-11-19.md` (§0, шаг A).
- Промпт: `ChatGPT\Diggles\docs\reverse-engineering\agent-task-campaign-level-generator-2026-11-19.md`.
