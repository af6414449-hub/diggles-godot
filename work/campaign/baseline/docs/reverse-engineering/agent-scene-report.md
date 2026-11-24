# gng_001: Tcl / ENT scene report

Дата анализа: 2026-11-15  
Источник: `C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data`

## Краткий вывод

`gng_001` — не одна сцена, а шаблон PMP с набором вариантов оформления/содержимого. Каждый Tcl-шаблон вызывает один и тот же `gng_001.pmp`, подключает собственный `*.l2m`, а затем создаёт декорации, ресурсы и противников через `new`. Суффиксы `a..f` — варианты последовательных участков/состояний кампании, а префиксы (`kris`, `lava`, `swf`, `urw`) — тематические наборы.

Android-код в рамках анализа не изменялся.

## Базовые ресурсы

| Ресурс | Размер | Наблюдение |
|---|---:|---|
| `Templates/pmp/gng_001.pmp` | 146 B | Заголовок `4×4`; 16 байт материала `02`; далее индексы/таблица PMP |
| `Templates/ent/gng_001.ent` | 37 B | Две записи `map_entry 1 0 16` и `map_entry 1 32 16` |
| `Templates/tcl/*gng_001*.tcl` | 24 файла | Все вызывают `map_template gng_001.pmp` и `map_setlayer2` |
| `Templates/l2m/*gng_001*.l2m` | 24 файла по 44 B | По одному L2M на каждый Tcl-вариант |

`gng_001.ent` не содержит экземпляры объектов. Это компактная таблица входов/сегментов карты: две записи с одинаковым размером `16`, но смещениями `0` и `32`. Поэтому объекты сцены находятся в Tcl, а `.ent` следует трактовать как карту входных/связанных участков, не как полноценный object placement-файл.

## Tcl-структура

Каждый файл определяет `proc MapTemplateSet {xoffset yoffset}`:

1. задаёт уровень детализации через `loading_objdetail`;
2. вызывает `map_template gng_001.pmp $xoffset $yoffset`;
3. подключает слой `map_setlayer2 $xoffset $yoffset <variant>.l2m`;
4. создаёт объекты `new Class "" "x y z" "rx ry rz"`;
5. выставляет owner/physics/light/boxed-флаги;
6. иногда вызывает `Editor_Set_Info` с параметрами поведения.

Все координаты в отчёте ниже указаны как локальные координаты до добавления `$xoffset/$yoffset`. Поворот — Euler-тройка из Tcl.

## Варианты Kris

| Файл | Объекты и локальные координаты (x, y, z) | Роль |
|---|---|---|
| `kris_gng_001_a.tcl` | `Dummy_Kris_uv_a` (2.93274, 2.5, 15); `Dummy_Kris_ov_a` (2.90378, 0.0499992, 15); `Dummy_Kris_glassplitter_p` (1.70024, 2.5, 11.02); `Dummy_Kris_um_m` (2.58415, 2.5, 13) | кристаллическая декорация/фон |
| `kris_gng_001_b.tcl` | `Dummy_Kris_ov_b` (1.25738, -0.101705, 15); `Dummy_Kris_uv_b` (3.0375, 2.5, 15); `Dummy_Kris_glassplitter_l` (2.18848, 2.5, 11.02); `Dummy_Kris_um_i` (2.40717, 2.5, 12.1) | кристаллическая декорация |
| `kris_gng_001_c.tcl` | `Dummy_Kris_uv_c` (2.49641, 2.5, 15); `Kristallerz` (2.30156, 2.5, 14.1), rotY=6.00327; `Dummy_Kris_ov_c` (2.44572, 0.120399, 15.02); `Dummy_Kris_glassplitter_c` (1.32037, 2.5, 11.02); `Dummy_Kris_um_i` (1.04135, 2.5, 12.3), rotY=1.59999 | кристалл и руда |

`Kristallerz` — игровой ресурсный объект (`items/rohstoffe.tcl`), а `Dummy_Kris_*` — визуальные dummy-декорации.

## Варианты Lava

Ключевые объекты:

- `lava_gng_001_a`: `Dummy_Lava_seule_i` (2.09592, 2.5, 15), `Lavabrut` (2.85012, 2.5, 12.7), `Dummy_Lava_krst_ov_b` (1.89147, -0.375072, 15.02), `Dummy_Lava_krst_um_a` (1.90281, 2.5, 13.5), `Dummy_Lava_moos_oh_e` (3.01349, 0.342766, 11.02). `Lavabrut`: `prisoned=0`, `aggr=0.8`, physics выключена.
- `lava_gng_001_b`: `Dummy_Lava_moos_uh_a` (1.1615, 2.54, 10.92), `Lavabrut` (1.34893, 2.5, 12.9), `Dummy_Lava_seule_g` (3.09653, 2.5, 15), `Dummy_Lava_krst_o_f` (1.05115, 0.209267, 12.44), `Dummy_Lava_moos_hm_a` (2.31078, 1.22528, 10.96). Агрессия `0.9`.
- `lava_gng_001_c`: `Dummy_Lava_seule_h` (1.29546, 2.5, 15), `Schatztonne` (2.65473, 2.5, 12.31), `Schatzbuch` (2.65772, 2.5, 12.31), `Lavabrut` (1.90113, 2.5, 12.9), плюс `Dummy_Lava_moos_uh_f` и `Dummy_Lava_krst_o_n`. Агрессия `0.95`; сундук/книга дают experience-бонусы ресурсов.

`Lavabrut` — персонаж/монстр из `classes/characters/brut.tcl`; `Schatztonne` — material-класс из `items/misc_items.tcl`.

## Варианты Swf

### a

Декорации `Dummy_Swf_krst_uv_o` (3.12414, 2.5, 15), `Dummy_Swf_sta_u_b_1` (3.10897, 2.5, 14.48), `Dummy_Swf_krst_ov_b` (3.02445, -0.089317, 15.02), `Dummy_Swf_sta_o_d` (3.11644, 0.283241, 13.48), `Dummy_Swf_krst_um_a` (1.36449, 2.5, 12.88).

### b

`Dummy_Swf_krst_uv_p` (1.12526, 2.5, 15), `Dummy_Swf_sta_u_a` (1.33801, 2.5, 14.94), `Dummy_Swf_krst_uh_a` (3.04238, 2.5, 11.16), `Dummy_Swf_sta_vorne_u_e` (3.31214, 2.5, 11.82), `Dummy_Swf_krst_um_a` (3.06449, 2.5, 12.76), `Dummy_Swf_krst_ov_a` (2.9576, 0.0376587, 15.02).

### c–f: игровые объекты

- `c`: два `Schwefelwuker` (3.24166/2.30709, z=13.1), `Troll` (1.20515, z=13.1, weapon=`Lanze_2`), плюс деревянные стены и Swf-декорации.
- `d`: `Schatztonne` (1.5, 2.5, 12.21), `Kleiner_Heiltrank` в той же позиции, `Schwefelwuker` (2.49257, z=12.61), `Troll` (0.867313, z=13.61, weapon=`Streitkolben`, shield=`Trollschild_1`), деревянные стены.
- `e`: `Schatztonne` (1.21034, 2.5, 12.1), три `Grillhamster` в (1.21291, 2.39626, 12.1) с разными rotY, деревянные стены и кристаллическая декорация.
- `f`: `Schatztonne` (2.67031, 2.5, 12.2), `Schatzbuch` там же, деревянные стены и Swf-декорация; `Schatzbuch` настроен experience-бонусами `Nahrung`, `Metall`, `F_Kungfu`, `Service` по `0.03`.

`Schwefelwuker` и `Troll` — полноценные character-классы с AI/боевыми параметрами; это не просто модели.

## Варианты Urw

- `urw_gng_001_a`: `Dummy_Multi_Holzstuetze_a` (3.09607, 2.5, 15.04), `Info_Coll_e` (3.18866, 2.5, 14.64), две `Dummy_Holzwand_*` около y=1.53.
- `urw_gng_001_b`: `Info_Coll_e` (3.31265, 2.5, 14.64), `Dummy_Multi_Holzstuetze_g` (3.16968, 2.5, 15.04), стены `Dummy_Holzwand_e/g`.
- `urw_gng_001_c`: `Dummy_Moos_um_a` (2.13665, 2.5, 13.18), `Wuker` (1.6293, 2.5, 13.4, aggr=`0.48`, aggrmax=`0.55`), `Dummy_Wiese_oval` (2.22135, 2.5, 12.34), два `Dummy_Moos_hm_*` на (2.48627,1.78499,11.02) и (1.67533,2.09507,11.02).

## Модели и материалы

В Tcl нет прямых имён `.3db`/текстур: они скрыты за классами `Dummy_*` и базовой системой object-detail. Поэтому надёжно извлечённая семантика такая:

- `Dummy_Kris_*` — кристаллические/минеральные декоративные модели;
- `Dummy_Lava_*` — лавовые/каменные/моховые декоративные модели;
- `Dummy_Swf_*` — болотные/каменные/растительные декоративные модели;
- `Dummy_Holzwand_*`, `Dummy_Multi_Holzstuetze_*` — деревянные стены/опоры;
- `Kristallerz`, `Schatztonne`, `Schatzbuch`, `Kleiner_Heiltrank` — предметные material/tool-объекты;
- `Lavabrut`, `Wuker`, `Schwefelwuker`, `Troll`, `Grillhamster` — интерактивные персонажи/животные.

Для следующего шага портирования нужно разрешить `Dummy_*` через их `def_class` и вызываемые в них `set_model`/`set_texture`/`new_visual`-операции. Простого поиска по Tcl-сцене недостаточно: часть классов собирается через include/шаблоны декораций.

## Практический вывод для импорта

1. Сначала импортировать `.ent` как две точки входа/сегмента (`offset=0`, `offset=32`, length `16`), а не как список объектов.
2. Для каждой сцены хранить `pmp`, один выбранный `l2m` и Tcl-вариант.
3. Парсер Tcl должен вычислять `x/y` с учётом offsets и сохранять `z` и rotation.
4. Игровые классы и декоративные dummy-классы разделить: первые требуют поведения, вторые — только визуального прокси.
5. Для Android-первого вертикального среза наиболее информативен `swf_gng_001_d/e`: там уже есть противники, предметы, стены и параметры AI/инвентаря.

## Ограничения анализа

- `.ent` здесь текстовый и очень мал; он не содержит моделей/координат объектов.
- Точное соответствие `Dummy_* → .3db/.tga/.material` не восстановлено в этом отчёте.
- `PMP` и `L2M` только связаны с объектами через Tcl-команды; их геометрический формат остаётся отдельной задачей.
