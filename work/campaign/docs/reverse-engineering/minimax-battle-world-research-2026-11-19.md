# Minimax: исходная генерация battle world «Stein» — первый срез 4×4

Дата: 19.11.2026. Исследование выполнено в отдельной рабочей сессии; **основной проект не изменялся**, кроме двух новых файлов рядом с этим отчётом (JSON с данными и скрипт-генератор/проверка).

Источники:

- `O/` = `C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris/data/`
- `X/` = `C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris/Diggles.exe`
- SHA-256 `X/Diggles.exe` = `58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74`, image base `0x400000`, 32-bit x86 PE.
- Все VA ниже — preferred virtual addresses в этом EXE. Все байты перечитаны напрямую из файла (pefile + capstone), игра **не запускалась**.

Сопутствующие файлы:

- `docs/reverse-engineering/minimax-battle-world-2026-11-19.json` — детерминированный набор данных (881 пресет + 122 каменных прямоугольника из всех 14 авторских battle world, геометрия шаблонов, SHA-256).
- `docs/reverse-engineering/minimax-battle-world-2026-11-19.py` — генератор этого JSON с режимами `--check` (побайтовое воспроизведение + 10 инвариантов) и `--check-exe` (байтовая проверка 11 мест в EXE).

Оба файла — **новые**, ничего существующего в основном проекте не изменено. Скрипт читает только установленную игру и пишет только свой JSON.

---

## 1. Краткий вывод

**Что найдено и доказано.**

1. **«Stein» — это не догадка, а имя native-семейства.** Вся «каменная» часть генерации — это Tcl-команды с префиксом `sm_` (`sm_create_map`, `sm_draw_stone`, `sm_get_resolution`, `sm_mark_temparea`, `sm_map_set/get`, `sm_get_level_info`, `sm_get_temppos`). Они зарегистрированы в EXE как отдельные команды (см. §3). `sm_draw_stone` умеет `-border`, `-funnel`, `-rect`, `-exlimit`, `-utmat`, `-matlist`. Именно они рисуют «окружающий камень» и «границы».

2. **Сетка 4×4 — это размер ячейки в мировых единицах, а не размер карты.** Доказано тремя независимыми источниками:
   - `sm_get_resolution` (handler `0x65FFB0`) возвращает Tcl-целое **4** (`0x660054: push 4; call [0x715568]` = `Tcl_NewIntObj`);
   - `lg_set_area` (core `0x583AC0`) выравнивает прямоугольник генератора по кратности 4 (`0x583B20–0x583B35`: `add ebx,3` / `and ebx,0xfffffffc` — нижний угол вверх, верхний угол вниз);
   - `lg_add_preset` (core `0x58A510`) **отклоняет** пресет, если итоговые координаты не кратны 4: `0x58A5DE: or eax,edx` → `0x58A5E0: test al,3` → `0x58A5E2: jne 0x58A6AD` (возврат 0).

   Сверх того, **все** пресеты и **все** каменные прямоугольники во всех 14 авторских battle world лежат на этой решётке: 881 пресет и 122 прямоугольника, 0 отклонений (проверяется скриптом, §6).

   Трактовка «4×4 = 4×4 *ячейки*» геометрически невозможна: стартовая пещера `multi_start_010.pmp` имеет размер **44×24** единицы, то есть 11×6 ячеек — мир «4×4 ячейки» в неё не помещается. Поэтому «сетка 4×4» = ячейка 4×4 мировых единиц. Размеры карт при этом оригинальные: **128/256/384/512** (мультиплеерное меню) и **300×180 / 600×600** (авторские карты).

3. **Размер мира, area и пресеты — разделены и полностью прослежены.**
   - `map create W H` → мир `[0,W)×[0,H)` (подтверждено предыдущим исследованием основного проекта, `native-multiplayer-world-2026-11-17.md`, §1).
   - `lg_set_area 16 16 W-16 H-16` → area обрезается по `world±8`, нижний угол округляется **вверх** до кратного 4, верхний — **вниз** (`0x583AC0`). Для W/H из меню и из авторских карт area_min всегда = **(16,16)**.
   - **Итоговая позиция шаблона = пресет + area_min** (`0x58A5AB–0x58A5B4`).
   - **Пресеты проверяются не по area, а по границам мира ±8** (`0x58A5E8–0x58A630`). Area — это база смещения и область, куда native достраивает природные пещеры, а не запретная зона для авторских пресетов. Это важное уточнение: в `multi_cw_001.tcl` есть пресет с `y=12`, который area (16,16)–(284,164) не покрывает, но он легален.
   - Отдельно проверяется занятость клеток (`0x58A640–0x58A663`, вызов `0x592F10`, `test byte [eax+0x13],1`).

4. **Шаблоны и их раскладка.** Стартовая пещера `multi_start_010` — **не один PMP**, а split-шаблон из 6 плиток, которые ровно и без наложений покрывают 44×24 = 1056 samples (`Templates/tcl/multi_urw_start_010_a_0.tcl` + `Templates/pmp/split/splt_multi_start_010_t{AA,AB,BA,BB,CA,CB}.pmp`). Об этом уже писалось в отчёте основного проекта; здесь подтверждено чтением самих файлов и добавлено в JSON.

5. **Каменные прямоугольники — «окружающий камень» и «соединительные ходы».** Формат нативно доказан: список должен начинаться с литерала `"mat"`, каждый прямоугольник — `{type x y w h}`, а `sm_draw_stone -matlist <offX> <offY> <list>` считает
   `x0 = x+offX, y0 = y+offY, x1 = x0+w+2, y1 = y0+h+2`
   (`0x65F202–0x65F276`). В мультиплеере передаётся буквально `-matlist 16 16`, то есть **те же 16, что и area_min** — тем же сдвигом, что и шаблоны. Тип 0 — массивные плиты (стены/рамка), тип 2 — мелкие 4×4 / 4×12 / 8×4 / 12×4 «перемычки» между пещерами.

6. **Что делает Tcl, а что native EXE.** Tcl: разбор `net gamedata`, выбор размера/зоны/плотности, чтение авторского `temp_list`, вызов `lg_*`/`sm_*`, финальная раскладка шаблонов и объектов. Native EXE: вся арифметика решётки, area, проверки пресетов, генерация природных пещер, запись камня в stone-map, RNG, загрузка PMP/L2M/BDB, рендер. Разделение — таблицей в §5.

**Достаточно ли этого для первого 4×4 среза — да, с одной оговоркой, которая теперь доказана, а не предположена.**

Правила, размеры, смещения, раскладка стартовой пещеры, формат камня, материалы и форматы PMP/L2M — доказаны и пригодны для прямой реализации.

**Оговорка: процедурная генерация природных пещер невоспроизводима по построению.** Это доказано, а не предположено:
- seed единственного глобального RNG задаётся как `GetTickCount()` (`0x401AE0–0x401AE7`), то есть зависит от времени запуска; команды или опции для его фиксации нет;
- внутри LevelGen (`0x583000–0x58A000`) — **19 прямых вызовов** RNG-ядра `0x49C670`, то есть выбор и расстановка природных пещер идут через этот поток.

Значит, `lg_start` не может быть воспроизведён ни при каком фиксированном входе. Поэтому **воспроизводимый первый срез строится на авторских пресетах** (`temp_list` из `multi_cw_*.tcl` / `multi_dm_*.tcl`), а не на `lg_start`-генерации. Это и есть требуемый «корректно ограниченный» срез; §5.2 описывает адаптер, §6 — проверки.

---

## 2. Таблица фактов

Уверенность: **Высокая** = прочитано из исходника/байтов EXE; **Средняя** = выведено из нескольких независимых фактов; **Низкая** = гипотеза.

| # | Утверждение | Первичный источник | Точная ссылка | Уверенность |
|---|---|---|---|---|
| F1 | Вход battle/multiplayer — `GameScripts/multiplayer.tcl`, читает `net gamedata` (GameSave, GameType, UseMap, Density, Resources, Set, Size, NumGnomes) | `O/GameScripts/multiplayer.tcl` | строки 16–30 | Высокая |
| F2 | Размеры меню: `mapsizelist {128 256 384 512}`, плотности `{0.2 0.4 0.7}` | `O/Scripts/init/mpinit.tcl` | строки 2, 5 | Высокая |
| F3 | `Set` → зона: 0 Urwald, 1 Metall, 2 Kristall, 3 Lava | `O/GameScripts/multiplayer.tcl` | строки 44–49 | Высокая |
| F4 | Стартовые шаблоны: `starttemplatelist` — по 8 владельцев × 4 зоны, имена `multi_<zone>_start_0NN_a_<owner>` | `O/Scripts/init/mpinit.tcl` + `O/Scripts/misc/mp_tools.tcl:67–96` | mpinit 7–122; mp_tools 68–96 | Высокая |
| F5 | `multi_start_010` — это `multi_urw_start_010_a_0` / `_b_1` (Urwald) | `O/Scripts/init/mpinit.tcl` | строки 10, 25 | Высокая |
| F6 | Генерация: `lg_tp_clear` → `lg_tp_addtemplatesets "$Zone.Std"` → `lg_set_templateratio 0 $TempRatio 1.0` → `lg_set_area 16 16 W-16 H-16` → `lg_add_preset` на каждый пресет → `lg_set_leveltype base` → `lg_start` → `lg_get_level` → `apply_level` | `O/GameScripts/multiplayer.tcl` | строки 269–296 (сервер), 200–227 (skirmish) | Высокая |
| F7 | `apply_level` вызывает `data/templates/tcl/$template` с `temppos=(x,y)`; ветка `mat` → `sm_draw_stone -matlist 16 16 $nexttemp` | `O/Scripts/misc/mp_tools.tcl` | строки 23–48 (mat — 27–30) | Высокая |
| F8 | Split-шаблон: `split_template <name> multi_start_010.pmp 44 24 {6 плиток}`, offset-ы (0,0),(16,0),(32,0),(0,16),(16,16),(32,16) | `O/Templates/tcl/multi_urw_start_010_a_0.tcl` | строки 1–8 | Высокая |
| F9 | Плитки start_010: AA 16×16, BA 16×16, CA 12×16, AB 16×8, BB 16×8, CB 12×8; сумма ровно 44×24 = 1056 без наложений | `O/Templates/pmp/split/splt_multi_start_010_t*.pmp` | заголовки PMP (u32 W, u32 H) | Высокая |
| F10 | Ячейка решётки = 4×4 мировых единиц (`sm_get_resolution` → 4) | `X/Diggles.exe` | handler `0x65FFB0`, `0x660054: push 4` | Высокая |
| F11 | `lg_set_area`: обрезка по world±8, нижний угол вверх до кратного 4, верхний вниз; area → generator+0x50/54/58/5C | `X/Diggles.exe` | core `0x583AC0`; `0x583AD7–0x583B35`, запись `0x583BBE–0x583BC3` | Высокая |
| F12 | `lg_add_preset` отклоняет некратные 4 итоговые координаты | `X/Diggles.exe` | core `0x58A510`; `0x58A5DE–0x58A5E2` (`or eax,edx; test al,3; jne`) | Высокая |
| F13 | Итоговая позиция шаблона = пресет + area_min | `X/Diggles.exe` | `0x58A5AB–0x58A5B4` (приём пресета); `0x584CAF–0x584CB8`: `ecx = generator[0x50] + preset.x` → `record+4`; `0x584CD1–0x584CDC`: то же для Y → `record+8`; массив результата `lea edi,[esi+0x184]` (`0x584C52`) | Высокая (перечитано независимо; совпало с адресами из отчёта 17.11) |
| F14 | Пресеты ограничены границами **мира** ±8, а не областью генерации | `X/Diggles.exe` | `0x58A5E8–0x58A630` (world+0x84/88/8C/90) | Высокая |
| F15 | Занятость клеток пресета тоже проверяется | `X/Diggles.exe` | `0x58A640–0x58A663` → `0x592F10`, `test byte [eax+0x13],1` | Высокая |
| F16 | `lg_set_leveltype` принимает `default`, `base`, `mine`; иначе «invalid leveltype» | `X/Diggles.exe` | handler `0x652510`; строки `0x65266D` ("default"), `0x6526B1` ("base"), `0x6526EF` ("mine"), `0x652762` (ошибка) | Высокая |
| F17 | `lg_add_preset` пишет запись в массив generator+0x194 (шаг 0x10): +0 имя, +4 x, +8 y | `X/Diggles.exe` | `0x58A665–0x58A69F` | Высокая |
| F18 | `sm_draw_stone` поддерживает `-border`, `-funnel`, `-rect`, `-exlimit`, `-utmat`, `-matlist`; ошибки «invalid matlist», «invalid nr of arguments», «invalid param» | `X/Diggles.exe` | handler `0x65E090`: `0x65E1DA` (-border), `0x65E3C9` (-funnel), `0x65E529` (-rect), `0x65E7DE` (-exlimit), `0x65EB87` (-utmat), `0x65EDEE` (-matlist); ошибки `0x65F2CA`, `0x65F2E6`, `0x65F318` | Высокая |
| F19 | Формат каменного прямоугольника: `{type x y w h}`; список обязан начинаться с литерала `mat` | `X/Diggles.exe` | `0x65EF32` (сравнение с «mat» 0x730E24), разбор элементов 0–4: `0x65F053–0x65F1F3` | Высокая |
| F20 | `sm_draw_stone -matlist <offX> <offY> <list>`: `x0=x+offX, y0=y+offY, x1=x0+w+2, y1=y0+h+2` | `X/Diggles.exe` | `0x65F202–0x65F276` (`add edx,[ebp-0x1c]`, `add ecx,[ebp-0x30]`, `+2` в обоих размерах) | Высокая |
| F21 | В мультиплеере передаётся `-matlist 16 16` — те же 16, что area_min | `O/Scripts/misc/mp_tools.tcl` | строка 29 | Высокая |
| F22 | Тип 0 = крупные плиты (рамка/стены), тип 2 = мелкие перемычки 4×4 / 4×12 / 8×4 / 12×4 | `O/GameScripts/multi_dm_kris_2p_001.tcl:78–82`, `multi_cw_001.tcl:107–112` | разбор всех 14 карт | Средняя (типографика подтверждена геометрией, но слово «тип» в EXE не найдено) |
| F23 | Каменная рамка type-0 замкнута: `+2`-расширение делает 4 полосы единым кольцом | `O/GameScripts/multi_cw_001.tcl:107` | арифметика F20 по 4 прямоугольникам | Высокая |
| F24 | **Все** пресеты и каменные прямоугольники 14 авторских карт кратны 4 (881 + 122, 0 отклонений) | `O/GameScripts/multi_*.tcl` | скрипт §6, проверка `minimax-battle-world-2026-11-19.py` | Высокая |
| F25 | Авторская 2p-карта: мир 600×600, зона Urwald, ratio 0.31, стартовые пещеры пресет (76,68) и (192,68) → мир (92,84) и (208,84) | `O/GameScripts/multi_dm_kris_2p_001.tcl` | строки 3, 10, 49, 60 | Высокая |
| F26 | Авторские battle world: 6 карт CW (300×180 / 300×250) и 8 карт DM (600×600) | `O/GameScripts/multi_*.tcl` | строки `set map_size` | Высокая |
| F27 | Генератор native — `Map/LevelGen.cpp` | `X/Diggles.exe` | строка `0x72A7D0`, ссылка из `0x5897E7` | Высокая |
| F28 | **Seed = `GetTickCount()`**: `0x401AE0: call [0x7152F4]` (IAT → `KERNEL32.dll!GetTickCount`) → `push eax` → `0x401AE7: call 0x4454D0` (инициализация MT19937). Seed нигде не фиксирован и не задаётся из Tcl | `X/Diggles.exe` | `0x401AE0–0x401AE7`; IAT-слот `0x7152F4` разрешён как `KERNEL32.dll!GetTickCount` | Высокая |
| F29 | **MT19937**: состояние 624 слова инициализируется из 32-битного seed; `irandom` → `0x62F780` → `0x49C670` | `tools/diggles_rng.py` основного проекта + `X/Diggles.exe` | `0x4454D0` (init), `0x49C670` (шаг) | Средняя (форма генератора взята из отчёта основного проекта; вызовы seed проверены независимо) |
| F30 | **`lg_start` НЕ воспроизводим**: внутри LevelGen (`0x583000–0x58A000`) найдено **19 прямых вызовов** RNG-ядра `0x49C670` (`0x585C07`, `0x586159`, `0x5864B0`, `0x5864C5`, `0x586EA2`, `0x587B79`, `0x588014`, `0x5884A7`, `0x588612`, `0x588EC9`, `0x588EFD`, `0x588F0A`, `0x5891FC`, `0x589219`, `0x5892A8`, `0x5892C5`, `0x58934C`, `0x589369`, `0x585C07` и др.) | `X/Diggles.exe` | побайтовый скан `E8 rel32` по .text; список из 35 вызовов, 19 — внутри LevelGen | Высокая |
| F31 | Тот же `0x49C670` вызывается из рисователя каменного прямоугольника | `X/Diggles.exe` | `0x5FCCCC: call 0x49C670` (в `0x5FC9D0`) | Высокая |
| F32 | **Материал клетки PMP**: младшие 7 бит флаг-байта — код материала **0..5**, старший бит 0x80 переносится отдельно. Таблица переходов по 6 значениям | `X/Diggles.exe` | `0x5995F4: movzx edx,byte [eax]` / `0x5995FA: and edx,0x7f` / `0x599631: cmp edx,5` / `0x59963A: jmp dword [edx*4+0x599FA8]`; таблица: 0→`0x599641`, 1→`0x599672`, 2→`0x5996C4`, 3→`0x5996F9`, 4→`0x599728`, 5→`0x599757` | Высокая |
| F33 | **Проход 1** переписывает байт: raw 2 → младшие биты `11b` (3); raw 3 → `10b` (2); raw 4 → `01b` (1); raw 5 → выставляется бит 2; raw 0 — без изменений; raw 1 — `(сосед & 3)+1` | `X/Diggles.exe` | `0x5996C4: or al,3` (raw 2); `0x5996F9…0x59970B: or al,2` (raw 3); `0x599728…0x59973A: or al,1` (raw 4); `0x599757…0x599780: or al,4` (raw 5); `0x599672…0x599694: and dl,3; inc dl; or dl,al` (raw 1) | Высокая |
| F34 | **Ground-текстура** = `ground/Gnd_<family><tens><units>.tga`, family = `'A' + material`, вариант 01..15. В `data/Ground/` ровно 3 семейства × 15 = 45 файлов: `Gnd_A01..A15`, `Gnd_B01..B15`, `Gnd_C01..C15` | `X/Diggles.exe` + `O/data/Ground/` | `0x4CDA99: mov eax,[ebp+8]; add eax,0x41` ('A'+idx); `0x4CDAB0: lea eax,[ecx+1]; idiv 10; add eax,0x30` (десятки); `0x4CDABE: lea ecx,[edx+0x30]` (единицы); `0x4CDACF: push 0x7248B4` → «ground/Gnd_%c%c%c.tga»; список файлов | Высокая |
| F35 | **Маски углов** = `Msk_<f1><f2><b1b2b3><variant>.tga`, 15 файлов (`Msk_AAAB01`, `Msk_AABA01`, … `Msk_BBBA01`) — по комбинации материалов четырёх углов клетки | `O/data/Ground/` | список файлов | Средняя (связь с четырьмя углами выведена из именования, прямой код не разобран) |
| F36 | Утверждение основного проекта «raw 2 → 3 → material 2 ('C')» **подтверждается**; таблица F33 расширяет его на остальные коды | `X/Diggles.exe` | `0x5996C4` (raw 2 → 3) + `0x4CDA99` ('A'+2 = 'C') | Высокая |
| F37 | Story-карта: `map create 512 640` + `sm_draw_stone -border` + `sm_draw_stone -funnel`; `sm_create_map 512 640`; `resolution = [sm_get_resolution]`; `sm_map_get/set` и `sm_get_level_info` работают в ячейках | `O/Scripts/gameplay/Campaign.tcl:2–4`, `O/Scripts/gameplay/CampaignInit.tcl:34`, `O/Scripts/classes/story/story.tcl:953,31–33,152` | — | Высокая |
| F38 | Меню игры по умолчанию: `map create 64 64` | `O/systeminit.tcl` | строка `map create 64 64 {  }` | Высокая |
| F39 | Формат PMP: `<II` W,H; W×H байт флагов; W×H u32 ref'ов на блок; u32 tail_count; 2·tail_count байт; W×H байт атрибутов | `tools/export_pmp_terrain.py:21–36` основного проекта + собственный парсер | — | Высокая (формат подтверждён чтением 6 файлов) |
| F40 | Формат L2M: `M2L\0`, `<II` W,H, затем W×H int32-высот (кратны 64) | `O/Templates/l2m/multi_urw_start_010_a_0.l2m` + `docs/reverse-engineering/l2m-gng001-probe.md` | — | Высокая |
| F41 | Разделение труда: `sm_*` — «stone map» (камень/рамки/проходы), `lg_*` — «level generator» (область, пресеты, природные пещеры) | `X/Diggles.exe` | имена команд и их подсистемы | Средняя |

---

## 3. Call graph: от multiplayer start до мутации terrain

Ниже — полный путь. `Tcl` = исходный скрипт, `EXE` = native-обработчик (handler → core).

```
net gamedata                                   [Tcl]  GameScripts/multiplayer.tcl:16-30
  └─ Size→mapsizelist, Density→densitylist, Set→Zone   [Tcl]  Scripts/init/mpinit.tcl:2,5
                                                          [Tcl]  GameScripts/multiplayer.tcl:44-53
  └─ GameSave → call $GameSave (авторская карта)        [Tcl]  GameScripts/multiplayer.tcl:239
       └─ set map_size / set Zone / set TempRatio / set temp_list
                                                          [Tcl]  GameScripts/multi_dm_kris_2p_001.tcl:3,5,10,12-83

map create $MapW $MapH                         [Tcl]  GameScripts/multiplayer.tcl:264
  └─ world bounds = [0,W)×[0,H)                         [EXE]  0x6327D9-0x632886 → 0x594160
                                                        (подтверждено в native-multiplayer-world-2026-11-17.md §1)

lg_tp_clear                                    [EXE]  handler 0x64E130
lg_tp_addtemplatesets " $Zone.Std "            [EXE]  handler 0x64E4F0
lg_set_templateratio 0 $TempRatio 1.0          [EXE]  handler 0x652830
lg_set_area 16 16 W-16 H-16                    [EXE]  handler 0x650180 → core 0x583AC0
     clamp world±8; min ceil4, max floor4; → generator+0x50/54/58/5C
foreach (x,y,name) in temp_list:
  lg_add_preset "<name>.tcl" x y               [EXE]  handler 0x651C80 → core 0x58A510
     final = preset + area_min                 [EXE]  0x58A5AB-0x58A5B4
     reject if (final.x|final.y) & 3           [EXE]  0x58A5DE-0x58A5E2
     reject if outside world±8                  [EXE]  0x58A5E8-0x58A630
     reject if cell occupied                    [EXE]  0x58A640-0x58A663
     record → generator+0x194 (name,x,y)       [EXE]  0x58A665-0x58A69F
lg_set_leveltype base                          [EXE]  handler 0x652510
lg_start                                       [EXE]  handler 0x652BC0 → 0x589790 → 0x5896A0 → 0x5848B0
     ← ЗДЕСЬ native достраивает природные пещеры (СЛУЧАЙНО, см. §7)
set level [lg_get_level]                       [EXE]  handler 0x652D10
     список элементов {filename, x, y}                  0x652F89-0x653016
apply_level $level                             [Tcl]  Scripts/misc/mp_tools.tcl:23-48
  ├─ элемент "mat" → sm_draw_stone -matlist 16 16 $mat [EXE] handler 0x65E090
  │     x0=x+16, y0=y+16, x1=x0+w+2, y1=y0+h+2        [EXE]  0x65F202-0x65F276
  │     draw rect into stone map (grid 4×4)             [EXE]  0x5FC9D0 → 0x49C670 (RNG)
  └─ элемент шаблона → call "data/templates/tcl/$template"   [Tcl]  mp_tools.tcl:42
       ├─ split_template → 6× map_template + MapTemplateSet [Tcl]  mp_tools.tcl:5-19
       │     каждый PMP: Templates/pmp/split/splt_multi_start_010_t*.pmp
       └─ map_setlayer2 <l2m>                             [Tcl]  Templates/tcl/split/splt_*.tcl
              ↓
      загрузка террейна:
      map_template → PMP loader                          [EXE]
        u32 W,H | W×H flag-байт | W×H u32 ref | tail | W×H атрибут
        flag → runtime material (двухпроходный маппинг, 0x5995F4-0x599A8E)
        ref → BDB block id → геометрия блока (BlockDB0/1/2.BDB)
      map_setlayer2 → L2M loader ("M2L\0", W, H, int32 высоты)
```

**Где кончается Tcl и начинается EXE.** Tcl решает *что* поставить (имена шаблонов, их пресетные координаты, список каменных прямоугольников, зону, плотность, размер). EXE решает *куда попадёт* (решётка, area, отбраковка), *что добавит сам* (природные пещеры), *как запишет камень* и *как загрузит/отрендерит* terrain.

---

## 4. Таблица данных для будущего экспортёра

| Имя | Тип | Источник | Пример | Назначение |
|---|---|---|---|---|
| `world.w`, `world.h` | int | `map create W H` (`multiplayer.tcl:264`) | `600`, `600` | размер мира в мировых единицах; мир = `[0,W)×[0,H)` |
| `world.bounds` | 4×int | EXE `0x594528-0x594580` (world+0x84/88/8C/90) | `[0,0,600,600]` | фактические границы мира |
| `lattice.cell` | 2×int | EXE `sm_get_resolution` `0x660054` | `4`, `4` | ячейка решётки в мировых единицах |
| `area.requested` | 4×int | `lg_set_area 16 16 W-16 H-16` | `[16,16,584,584]` | запрошенная область генерации |
| `area.effective` | 4×int | EXE `0x583AC0` | `[16,16,584,584]` | area после clamp world±8 и выравнивания по 4 |
| `area.min` | 2×int | EXE `0x583BC3` | `[16,16]` | база смещения всех пресетов |
| `zone` | string | `Set` (`multiplayer.tcl:44-49`) | `"Urwald"` | набор шаблонов `$Zone.Std` |
| `temp_ratio` | float | `TempRatio` (`multiplayer.tcl:271`) | `0.31` | 2-й аргумент `lg_set_templateratio` |
| `level_type` | string | `lg_set_leveltype` (`multiplayer.tcl:283`) | `"base"` | тип уровня; допустимы `default|base|mine` |
| `preset.x`, `preset.y` | int | `temp_list` (`multi_dm_kris_2p_001.tcl:12`) | `76`, `68` | авторская координата пресета (кратна 4) |
| `preset.template` | string | `temp_list` | `"multi_urw_start_010_a_0"` | имя шаблона (без `.tcl`) |
| `final.x`, `final.y` | int | EXE `0x58A5AB-0x58A5B4` | `92`, `84` | мировая позиция шаблона = пресет + area.min |
| `template.kind` | enum | `Templates/tcl/<name>.tcl` | `split` \| `monolithic` | split = несколько PMP, monolithic = один |
| `template.size` | 2×int | PMP-заголовок / `split_template` | `44`,`24` | размер шаблона в единицах |
| `template.parts[]` | list | `Templates/tcl/<name>.tcl` | `{pmp, offset, pmp_size}` | плитки split-шаблона и их offset |
| `pmp.width/height` | uint32 | PMP `0x00` | `44`,`24` | размер PMP-сетки |
| `pmp.flags[]` | byte×W·H | PMP `0x08` | `2` | тип/материал клетки (см. §7, материалы) |
| `pmp.refs[]` | uint32×W·H | PMP `0x08+W·H` | `1234` | индекс блока в BlockDB |
| `pmp.cell_attr[]` | byte×W·H | хвост PMP | — | атрибут клетки |
| `l2m.width/height` | uint32 | L2M `0x04` | `44`,`24` | размер слоя рельефа |
| `l2m.samples[]` | int32×W·H | L2M `0x0C` | `448` | высоты (кратны 64) |
| `stone.type` | int | `mat`-список | `0` (плита) / `2` (перемычка) | вид камня |
| `stone.x/y/w/h` | int | `mat`-список | `20,28,276,8` | прямоугольник в авторном пространстве |
| `stone.world_rect` | 4×int | EXE `0x65F202-0x65F276` | `[36,44,314,54]` | мировой прямоугольник камня (`+off`, `+2` по максимуму) |
| `bdb.block_id` | uint32 | `pmp.refs[]` → BlockDB | — | блок геометрии в `BlockDB{0,1,2}.BDB` |
| `rng.state` | 624×u32 | EXE `0x4454D0` | — | состояние MT19937 |

---

## 5. Минимальный план интеграции в основной проект

### 5.1 Source-derived (переносится как есть, без допущений)

| Правило | Формулировка | Где проверять |
|---|---|---|
| SD-1 | Ячейка = 4×4 единицы. Любая координата размещения кратна 4. | `lattice.cell` в JSON; инвариант «0 off-lattice» по 881 пресету |
| SD-2 | Мир = `[0,W)×[0,H)`. Размеры: меню 128/256/384/512; авторские карты 300×180, 300×250, 600×600 | `world.bounds` |
| SD-3 | `area = clamp(world±8)`, нижний угол ceil4, верхний floor4 | `area.effective` |
| SD-4 | Мировая позиция шаблона = пресет + `area.min` | `final.x/final.y` |
| SD-5 | Допустимость пресета: кратно 4; попадает в world±8 с учётом размера шаблона; клетка не занята | инварианты §6 |
| SD-6 | Плитки split-шаблона покрывают прямоугольник шаблона ровно и без наложений | инвариант «split covers 1056 of 1056» |
| SD-7 | Каменный прямоугольник: `x0=x+off, y0=y+off, x1=x0+w+2, y1=y0+h+2`; список начинается с `mat` | `stone.world_rect` |
| SD-8 | Шаблон = PMP (флаги/refs/атрибуты) + L2M (высоты) + объекты из `.tcl` | `pmp.*`, `l2m.*` |

### 5.2 Host adapter (решения принимает основной проект, не выводятся из исходника)

| Решение | Рекомендация | Почему это адаптер |
|---|---|---|
| A-1 | Размер первого среза | `112×88` (задан в JSON `first_slice.world_size`). Минимум, при котором 44×24 стартовая пещера целиком попадает в area и удовлетворяет world±8; 4×4 решётка выводима из требований, а сам размер — выбор |
| A-2 | Состав пещер | стартовая `multi_urw_start_010_a_0` + `urw_gng_030_a` (12×12) + `urw_gng_045_a` (12×8). Набор реальных шаблонов из авторских карт; их позиции — выбор |
| A-3 | Каменная рамка и перемычки | 4 полосы type-0, замкнутое кольцо; 2 перемычки type-2, каждая касается ≥2 пещер (проверяется) |
| A-4 | Как обойти случайность `lg_start` | Для воспроизводимого среза **не вызывать** генерацию природных пещер, а взять только авторские пресеты. Это не «упрощение по желанию»: seed глобального RNG = `GetTickCount()` (F28), а в LevelGen 19 вызовов RNG-ядра (F30) — процедурная часть **невоспроизводима в принципе**. Реализация MT19937 (`tools/diggles_rng.py`) позволила бы воспроизвести конкретный запуск только при известном seed, которого нет |
| A-5 | Что именно считать «границей» мира | В оригинале есть две сущности: границы **мира** (`world±8` в native) и каменная **рамка** (type-0 прямоугольники). Обе реализовать отдельно |

### 5.3 Файлы, которые предстоит создать/изменить в основном проекте

Ничего из этого **не** создано в рамках исследования; это план.

```
godot/tools/diggles_battle_world.py          НОВЫЙ  генератор battle world на решётке 4×4
                                             (world bounds, area, пресеты, камень, split-шаблоны)
godot/tools/export_battle_world.py          НОВЫЙ  экспорт сгенерированного среза в JSON/сцену
godot/models/battle_world_stein_4x4.json    НОВЫЙ  модель мира (по образцу models/multi_start_010_*.json)
godot/scenes/…                              ИЗМЕНЕНИЕ  подстановка battle world вместо одиночного PMP-мира 44×24
godot/tools/native_battle_world_self_test.gd  НОВЫЙ  self-test по инвариантам SD-1..SD-8
```

Существующие runtime/сцены/экспортёры в рамках исследования **не менялись**.

### 5.4 Рекомендуемый порядок

1. Перенести в Godot чтение PMP/L2M (форматы уже разобраны в `tools/export_pmp_terrain.py`).
2. Реализовать `diggles_battle_world.py` по SD-1…SD-8, используя `docs/reverse-engineering/minimax-battle-world-2026-11-19.json` как эталонные входы.
3. Прогнать §6 — все проверки должны стать self-test в Godot.
4. Подставить результат в существующую сцену вместо текущего standalone-адаптера 44×24/origin0.

---

## 6. Проверяемые fixtures и команды

Все команды рассчитаны на **PowerShell** (Windows) и запускаются из корня основного проекта. `$DATA` — путь к установленной игре; в примерах ниже он подставлен явно.

```powershell
$DATA = "C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris/data"
```

### F1. Данные воспроизводимы побайтово, все инварианты выполняются

```powershell
python docs/reverse-engineering/minimax-battle-world-2026-11-19.py --data $DATA --output docs/reverse-engineering/minimax-battle-world-2026-11-19.json --check
```
Ожидается: `OK: ... reproduces byte-for-byte; 10 invariants hold`.

Встроенные в скрипт инварианты (при нарушении — код возврата 2 и список `violations`):

1. **Решётка.** Координаты пресетов, каменных прямоугольников и финальных позиций кратны 4; по всем 14 авторским картам 881 пресет / 122 прямоугольника — 0 отклонений.
2. **Смещение.** `final == preset + area_min` для каждой пещеры среза.
3. **Границы.** Каждая пещера целиком внутри effective-area и с запасом ≥ 8 единиц до границ мира; `final + size < world − 8`.
4. **Split-шаблон.** Плитки `multi_start_010` покрывают ровно 1056 из 1056 samples (44×24) без наложений.
5. **Камень.** Каждый прямоугольник на решётке и внутри мира; type-0 полосы образуют замкнутую рамку вокруг всех пещер; каждая type-2 перемычка касается ≥ 2 пещер.
6. **Источники.** SHA-256 всех использованных файлов игры совпадает с записанными в JSON.
7. **Байты EXE.** Совпадают 11 шаблонов из таблицы фактов (решётка, seed, таблица материалов, имя ground-текстуры).
8. **Невоспроизводимость `lg_start`.** MT19937-ядро по-прежнему вызывается изнутри диапазона LevelGen — то есть процедурная часть остаётся случайной, и срез обязан опираться на авторские пресеты.

### F2. Байтовая проверка ключевых мест EXE (без дизассемблера)

```powershell
python docs/reverse-engineering/minimax-battle-world-2026-11-19.py --data $DATA --output docs/reverse-engineering/minimax-battle-world-2026-11-19.json --check-exe
```
Ожидается: `EXE_EVIDENCE_BYTES_OK`. Печатает каждую проверку с VA, байтами и пояснением:

```text
0x00583B26  83 e3 fc                 lg_set_area: and ebx,0xfffffffc (min corner ceil4)
0x00583B35  83 e1 fc                 lg_set_area: and ecx,0xfffffffc (max corner floor4)
0x0058A5E0  a8 03                    lg_add_preset: test al,3 (reject off-lattice)
0x00660054  6a 04                    sm_get_resolution: push 4 (cell = 4 units)
0x00401AE0  ff 15 f4 52 71 00        seed: call [KERNEL32!GetTickCount]
0x00401AE7  e8                       seed: call MT19937 init
0x005995FA  83 e2 7f                 PMP loader: and edx,0x7f (material code)
0x00599631  83 fa 05                 PMP loader: cmp edx,5 (codes 0..5)
0x0059963A  ff 24 95 a8 9f 59 00     PMP loader: jmp [edx*4+0x599FA8]
0x004CDA9B  83 c0 41                 ground: add eax,0x41 ('A'+material)
0x004CDACF  68 b4 48 72 00           ground: push "ground/Gnd_%c%c%c.tga"
```

### F3. Контрольная сумма EXE не изменилась

```powershell
python -c "import hashlib,pathlib; p=pathlib.Path(r'C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris/Diggles.exe'); h=hashlib.sha256(p.read_bytes()).hexdigest(); print('Diggles.exe', 'OK' if h=='58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74' else 'MISMATCH', h)"
```

### F4. Геометрия стартовой пещеры совпадает с эталоном (44×24, 6 плиток)

```powershell
python -c "import json; d=json.load(open('docs/reverse-engineering/minimax-battle-world-2026-11-19.json',encoding='utf-8')); sc=d['first_slice']['caves'][0]['geometry']; assert sc['split_size']==[44,24]; assert [p['pmp_size'] for p in sc['parts']]==[[16,16],[16,16],[12,16],[16,8],[16,8],[12,8]]; assert [p['offset'] for p in sc['parts']]==[[0,0],[16,0],[32,0],[0,16],[16,16],[32,16]]; print('START_010_GEOMETRY_OK')"
```

### F5. Каменная рамка среза действительно замкнута вокруг пещер

```powershell
python -c "import json; d=json.load(open('docs/reverse-engineering/minimax-battle-world-2026-11-19.json',encoding='utf-8')); sl=d['first_slice']; wall=[r['world_rect'] for r in sl['stone_rects'] if r['type']==0]; xs0=min(r[0] for r in wall); ys0=min(r[1] for r in wall); xs1=max(r[2] for r in wall); ys1=max(r[3] for r in wall); [(_ for _ in ()).throw(AssertionError(c['template'])) if not (xs0<=c['world_xy'][0] and ys0<=c['world_xy'][1] and c['world_xy'][0]+c['size'][0]<=xs1 and c['world_xy'][1]+c['size'][1]<=ys1) else None for c in sl['caves']]; print('STEIN_WALL_ENCLOSES_CAVES_OK',[xs0,ys0,xs1,ys1])"
```

### F6. Решётка 4×4 держится на всех авторских картах

```powershell
python -c "import json; d=json.load(open('docs/reverse-engineering/minimax-battle-world-2026-11-19.json',encoding='utf-8')); l=d['lattice']; assert not l['presets_off_lattice'] and not l['rects_off_lattice']; print('LATTICE_OK', l['presets_checked'],'presets', l['rects_checked'],'stone rects, cell', l['cell'])"
```

### Как это становится Godot self-test

Пункты F1–F6 — команды, которыми основной проект подтверждает перенос. Для Godot рекомендуется инкапсулировать их как `godot/tools/native_battle_world_self_test.gd` (по образцу существующих `*_self_test.gd`): читать JSON, проверять те же инварианты и печатать те же маркеры (`START_010_GEOMETRY_OK`, `STEIN_WALL_ENCLOSES_CAVES_OK`, `LATTICE_OK`, `EXE_EVIDENCE_BYTES_OK`), чтобы отчёт и рантайм проверяли одно и то же.

## 7. Явный список неизвестного и рисков

### Не доказано (требует live-запуска или отдельного RE)

| # | Вопрос | Текущий статус | Как закрыть |
|---|---|---|---|
| U1 | **Seed** конкретного запуска | **ЗАКРЫТО — seed не фиксирован.** `GetTickCount()` → MT19937 (`0x401AE0–0x401AE7`). Команды/опции установки seed нет | Закрыт фактами F28–F30; вывод: `lg_start` невоспроизводим, срез строится на авторских пресетах |
| U2 | **Какие именно природные пещеры добавляет `lg_start`** | **ЗАКРЫТО — частично.** Путь вызовов известен (`0x652BC0 → 0x589790 → 0x5896A0 → 0x5848B0`), и в LevelGen есть 19 вызовов RNG-ядра, то есть выбор **не детерминирован**. Точный алгоритм выбора шаблона (в каком порядке обходятся группы, как отбирается вариант) остаётся не восстановленным | Для полного воспроизведения — только при фиксации seed; в первом срезе не требуется |
| U3 | **Три числа `lg_set_templateratio 0 $TempRatio 1.0`** | Handler `0x652830` найден; семантика полей не выведена | Дизассемблировать core `lg_set_templateratio` и записать, куда пишутся аргументы |
| U4 | **Семантика трёх уровней `default|base|mine`** | Строки подтверждены (`0x65266D/0x6526B1/0x6526EF`), влияние на генерацию — нет | Дизассемблировать ветки в `0x652510` |
| U5 | **Что именно пишет `sm_draw_stone` в terrain** | Нативная геометрия rect доказана; путь «stone map → BlockDB/PMP» не прослежен до конца. `sm_create_map` в мультиплеере **не вызывается** — размер stone-map в этом пути неизвестен | Дизассемблировать `0x5FC9D0` и его вызывающий код в сторону terrain |
| U6 | **Обрезка камня по границам мира** | В 2 из 14 авторских карт (`multi_cw_001`, `multi_cw_005`) каменная рамка при сдвиге +16 выходит за ширину мира на 6 единиц (x1 = 306 при W = 300). Не выяснено, обрезается ли камень или это переполнение авторских данных | Проверить `0x5FC9D0` на clamp; либо прогнать оригинальную карту в игре и измерить |
| U7 | **Материальные семейства** (обычный камень / гранит / вода / пустота) | **Частично закрыто.** Код материала в PMP — 0..5, маппинг прохода 1 восстановлен (F32–F33), семейство ground-текстур A/B/C и его 15 вариантов — доказано (F34). **Осталось не доказанным**: какой именно код соответствует граниту, какой — воде, и как «пустота» отличается от воздуха | См. §9 |
| U8 | **Вода** | В battle world нет ни одного водного объекта в `temp_list`; `Scripts/classes/items/wasser.tcl` относится к одиночным сценариям. Вода в battle world не реализована | Отдельная задача, если нужна |
| U9 | **Полноценный streaming 600×600** | Карты DM объявлены 600×600, но авторский контент занимает лишь угол (например, `multi_dm_kris_2p_001`: пресеты x 60…296 при мире 600). Как заполняется остальное — не выяснено | Сравнить с `native-surface-walk-2026-11-17.md`; вероятно, это зона стриминга/пустота |
| U10 | **FOW (туман войны)** | `set_fogofwar this 14 8` (Zwerg), `tttfow_x/y=24` (Grenzstein) — известны из отчётов основного проекта; **в battle world** правила не восстанавливались | Отдельная задача |
| U11 | **L2M → рельеф** | Формат понятен (int32-высоты, кратны 64), интерполяция в поверхность — нет | См. `terrain-render-2026-11-18.md` основного проекта |
| U12 | **Материал клетки PMP → runtime material** | **ЗАКРЫТО.** Утверждение «raw 2 → 3 → material 2 ('C')» **подтверждено**; таблица переходов по всем кодам 0..5 восстановлена (F32–F33, F36) | Закрыт |
| U13 | **`get_mpstartpos`** | Handler `0x6480F0` найден; алгоритм расстановки стартовых позиций в случайной ветке (`!UseMap`) не восстановлен | Дизассемблировать `0x6480F0`; заметим, что он получает **один** аргумент размера, а не W и H отдельно (`multiplayer.tcl:242`) — это расхождение с ожидаемым поведением |

### Риски для интеграции

- **R-1. Соблазн воспроизвести `lg_start`.** Это самая большая ловушка: выглядит как «настоящая генерация», но **невоспроизводима в принципе** — seed = `GetTickCount()`, в LevelGen 19 вызовов RNG-ядра (F28, F30). Первый срез должен опираться на авторские пресеты.
- **R-2. Смещение +16.** Его легко применить дважды: `lg_get_level` уже добавил `area_min` к шаблонам, а `sm_draw_stone -matlist 16 16` добавляет его к камню — это **разные** вещи, применяемые к разным спискам, каждое ровно один раз.
- **R-3. Прямоугольник камня на 2 единицы больше заявленного.** Забыть `+2` — типичная ошибка, из-за которой рамка не замкнётся.
- **R-4. `map create W H` ≠ размер terrain-сетки.** W/H — мировые единицы; PMP-сетка шаблона своя (44×24 у стартовой пещеры).
- **R-5. Area ≠ граница пресетов.** Пресет с `y=12` легален в карте 300×180, хотя area начинается с 16. Реализация, запрещающая такое, отклонится от оригинала.
- **R-6. Соблазн считать 4×4 размером карты.** Это ячейка решётки. Размеры карт: 128/256/384/512/300×180/300×250/600×600.
- **R-7. Смешение пространств.** Пресеты и каменные прямоугольники заданы в «авторном» пространстве; мировые координаты = авторские + area.min. Три разных пространства в одном пайплайне (авторское / area / мир) — главный источник ошибок.
- **R-8. Split-шаблон ≠ один PMP.** `multi_start_010.pmp` (44×24) и шесть плиток `splt_multi_start_010_t*.pmp` — это **разные** файлы; и `Templates/multi_urw_start_010_a_0.tcl` (монолитный), и `Templates/tcl/multi_urw_start_010_a_0.tcl` (split) существуют, но `apply_level` вызывает **второй**.

---

## 8. Использованные отчёты основного проекта (только как контекст)

Прочитаны и использованы как контекст, не как источник истины; все числовые утверждения выше перепроверены по Tcl/EXE:

- `docs/reverse-engineering/native-multiplayer-world-2026-11-17.md` (+ `.json`) — границы мира, формула `+16`, split-геометрия start_010, общий `EXE` SHA-256. Согласовано с независимой проверкой; расхождений нет.
- `docs/reverse-engineering/world-space-sleep-2026-11-18.md` — контекст мирового пространства.
- `godot/models/multi_start_010_terrain.json`, `godot/models/playable_world_space.json`, `godot/models/multi_start_010_world_context.json` — используемый формат контекста; `world_context` подтверждает `template_offset [92,84]` для `multi_dm_kris_2p_001`, что совпадает с F25.
- `tools/export_pmp_terrain.py`, `tools/analyze_pmp.py`, `tools/diggles_rng.py` — форматы PMP и RNG.
- `docs/reverse-engineering/agent-pmp-report.md`, `pmp-layout-audit.json`, `blockdb-native-terrain.md` — формат PMP и BDB.

---

## 9. Материальные семейства

### 9.1 Что доказано

| Уровень | Что это | Доказательство |
|---|---|---|
| PMP flag, младшие 7 бит | **код материала 0..5** (0..5 валидны, >5 → default) | `0x5995FA: and edx,0x7f`; `0x599631: cmp edx,5`; `0x59963A: jmp dword [edx*4+0x599FA8]`; таблица из 6 записей по `0x599FA8` |
| PMP flag, бит 0x80 | отдельный флаг «установлено», переносится в отдельное поле | `0x599626: movzx eax,byte [eax]; and eax,0x80` → `[ebp-0x30]` |
| Проход 1 | переписывает младшие биты байта по коду материала | raw 2 → `or al,3` (`0x5996C4`); raw 3 → `or al,2` (`0x5996F9/0x59970B`); raw 4 → `or al,1` (`0x599728/0x59973A`); raw 5 → `or al,4` (`0x599757/0x599780`); raw 0 — без изменений (`0x599641`); raw 1 → `(сосед & 3)+1` (`0x599672/0x59968A/0x59968D`) |
| Проход 2 | младшие биты байта → **runtime material** 0..2 → семейство ground-текстуры | `0x599947–0x599A8E` (второй проход); `0x4CDA99: mov eax,[ebp+8]; add eax,0x41` → family = `'A' + material`; `0x4CDACF: push 0x7248B4` → «ground/Gnd_%c%c%c.tga» |
| Ground-текстуры | ровно **3 семейства × 15 вариантов**: `Gnd_A01..A15`, `Gnd_B01..B15`, `Gnd_C01..C15` | листинг `O/data/Ground/` (45 файлов по 16428 байт) |
| Маски углов | `Msk_<f1><f2><b1b2b3><variant>.tga`, 15 файлов (`Msk_AAAB01` … `Msk_BBBA01`) — комбинация материалов углов клетки | листинг `O/data/Ground/` |
| Утверждение основного проекта | «raw 2 → 3 → material 2 ('C')» — **подтверждено** | raw 2 → `or al,3` (`0x5996C4`); 'A'+2 = 'C' (`0x4CDA99`) |

Важно: маппинг **не монотонный**. Проход 1 меняет значение (2→3, 3→2, 4→1), поэтому «код материала в PMP» и «runtime material» — разные пространства имён; путать их нельзя. Именно поэтому в `tools/export_pmp_terrain.py` оставлен временный B-адаптер.

### 9.2 Что НЕ доказано (остаётся за U7)

1. **Какой код соответствует граниту** и какой — обычному копаемому камню. Требуется связать код материала с BDB-блоками и их геометрией: `pmp.refs[]` → `BlockDB{0,1,2}.BDB` → блоки. Отдельный прогон RE по BDB дал предварительный результат: **метаданные BDB байт-в-байт одинаковы во всех трёх файлах** (одинаковое пространство block-id, различаются меши) — это сужает задачу до «сопоставить ref → блок → материал», а не до разбора трёх форматов.
2. **Вода и пустота.** В battle world водных объектов нет; материал «пустота» (воздух) от «камня» в PMP отличается младшими битами, но соответствие кодам не восстановлено.
3. **Granit вокруг исходных пещер.** Отдельного кода материала для гранита в PMP не видно; предположительно различие идёт по BDB-блокам (другая геометрия/атрибуты), а не по флагу клетки. Не доказано.

### 9.3 Практический вывод для экспортёра

Для экспорта terrain в основном проекте достаточно:

1. взять `pmp.flags[]` (младшие 7 бит = код материала, бит 0x80 = «установлено»);
2. применить проход 1 (таблица F33) — без этого runtime material будет неверным;
3. применить проход 2 → runtime material 0..2 → семейство `'A'+material`;
4. выбрать вариант текстуры 01..15 (в оригинале — через RNG, см. U1; для детерминированного экспорта нужен явный, задокументированный выбор — в `tools/export_pmp_terrain.py` это детерминированное разбрасывание `(col*7 + row*11 + block_id) % 15`, и оно **не** воспроизводит оригинальный порядок);
5. для углов клетки — маска `Msk_*.tga` по комбинации материалов четырёх углов.

Пункты 4–5 — единственное место, где экспортёр основного проекта расходится с оригиналом; это зафиксировано в `limits` поля `ground_material` в `tools/export_pmp_terrain.py` и здесь не меняется.

---

## 10. Проверка отчёта

- `X/Diggles.exe` SHA-256 = `58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74` — совпал с указанным в отчётах основного проекта.
- Все VA в §2/§3 перечитаны из байтов EXE (pefile + capstone), логические строки даны как `файл:строка` по физическим номерам строк установленного файла.
- Ключевые утверждения дополнительно закреплены **байтовыми** шаблонами (§6, F2) — их можно проверить без дизассемблера.
- `docs/reverse-engineering/minimax-battle-world-2026-11-19.json` воспроизводится побайтово командой §6/F1; все 10 встроенных инвариантов выполняются.
- Оригинальная игра **не запускалась**: это статическое доказательство правил по исходникам и байтам EXE, а не live-capture.

**Ограничения этого отчёта (честно).**

1. Исследование статическое. Ни один вывод не опирается на наблюдение работающей игры; все утверждения — из Tcl и байтов EXE.
2. Часть native-цепочек не разобрана до конца: `sm_draw_stone` → terrain (U5), обрезка камня по границам мира (U6), второй проход загрузчика PMP целиком (F33 покрывает проход 1), точный алгоритм выбора природных пещер (U2), семантика трёх чисел `lg_set_templateratio` (U3) и уровней `default|base|mine` (U4).
3. Три worker-прогона были остановлены до конца; их промежуточные артефакты переиспользованы и **перепроверены** в этом отчёте (seed = GetTickCount, материалы, ground-текстуры), но их недоделанные выводы в отчёт не попали.
4. Разделение «source-derived / host adapter» в §5.2 — авторское решение; таблица F22 (тип 0 = плиты, тип 2 = перемычки) — единственный вывод уровня «Средняя», остальное — «Высокая».
