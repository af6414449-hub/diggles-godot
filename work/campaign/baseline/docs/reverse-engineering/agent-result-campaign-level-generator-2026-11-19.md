# Генератор уровня кампании — отчёт исполнителя

**Дата:** 2026-11-19
**Задача:** блок «генератор уровня кампании», реимплементация Diggles The Myth of Fenris на Godot 4.7.2
**Исходники (только чтение):** `C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data`
**Рабочая копия:** `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\`
**Живой проект:** `C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot` — не изменялся, кроме этого файла отчёта.

---

## 0. Короткий ответ

| Вопрос | Ответ |
|---|---|
| `irandom` найден в оригинале? | **Да.** Нативная Tcl-команда в `Diggles.exe`, восстановлена по дизассемблированию. Это **факт**, не адаптер. |
| Уровни совпадают с оригиналом? | **Процедура совпадает** (порядок розыгрышей, таблицы, формула `irandom`). **Не совпадают конкретные уровни**, потому что оригинал засевает RNG значением `GetTickCount()` при старте игры — внешнего seed у него нет. |
| Формат результата генератора по seed | список `(шаблон, x, y)` + список объектов; см. §4. |
| Проверок | self-test: **450 assertions, 0 failures, exit 0**; полный набор проекта: см. §6. |
| Отчёт / патч | этот файл; `work\campaign\campaign-level-generator.patch` (8 новых файлов, +22 550 строк). |

---

## 1. Ответ по `irandom` — НАЙДЕНО (факт)

`irandom` — не Tcl-процедура, а **нативная команда**, зарегистрированная в `Diggles.exe`.
Разбор выполнен без дизассемблера (Ghidra/Hopper/IDA на хосте недоступны), собственным
PE-парсером + capstone (`work\campaign\ref\pe_irandom.py`, `disasm.py`, `dump_iat.py`).

### 1.1 Цепочка вызовов

| Адрес | Что там | Источник |
|---|---|---|
| `0x61AFC8` | регистрация команды: `push <"irandom">`, затем `push 0x62F780` (обработчик), затем вызов регистратора | дизасм `0x61AFC8..0x61AFEE` |
| `0x62F780` | обработчик `irandom` | дизасм `0x62F780..0x62F91D` |
| `0x49C670` | генератор 32-битных значений | дизасм `0x49C670..0x49C91D` |
| `0x4454D0` | посев состояния по 32-битному seed | дизасм `0x4454D0..0x44555C` |
| `0x401AE0` | стартовый посев: `call [GetTickCount]` → `push eax` → `call 0x4454D0` | дизасм `0x401AE0..0x401AEC` |
| `0x724484` | таблица `mag01` = `{0x00000000, 0x9908B0DF}` | дамп `.rdata` |

Импорт `0x715340` = **KERNEL32!RaiseException**, `0x7152F4` = **KERNEL32!GetTickCount**,
`0x715574` = **tcl83!Tcl_GetIntFromObj**, `0x715540` = **tcl83!TclFreeObj**
(подтверждено разбором таблицы импортов PE).

### 1.2 Формула `irandom`

Обработчик `0x62F780`:

```
0x62F838: call 0x49C670          ; один розыгрыш, ДО разбора аргумента
0x62F83D: mov ebx, eax
0x62F83F: and ebx, 0x7fffffff    ; 31 бит
...
0x62F8AE: call [0x715574]        ; Tcl_GetIntFromObj -> целое n пишется в [ebp+0x10]
0x62F8B7: lea edi, [eax-1]      ; eax = TCL_OK (0), НЕ значение n
0x62F8BA: neg edi
0x62F8BC: sbb edi, edi           ; edi = -1
0x62F8C0: and edi, [ebp+0x10]    ; edi = n
0x62F8D3: test edi, edi
0x62F8D5: jne 0x62F8DC
0x62F8D7: mov edi, 0x7fffffff    ; n == 0 -> делитель 0x7FFFFFFF
0x62F8DC: mov eax, ebx
0x62F8DE: cdq
0x62F8DF: idiv edi               ; ebx = ebx % edi
```

**Итог: `irandom n` == `(розыгрыш & 0x7FFFFFFF) % n`**, при `n == 0` — `% 0x7FFFFFFF`.
Следствие, на которое опирается сам оригинал: **`irandom 1` всегда даёт 0**
(`Campaign.tcl:111` использует `irandom [llength $ylist]` при списке длины 1).

> Первый вариант разбора (деление на `0x7FFFFFFF` при `n == 1`) был **ошибочным**:
> он принял `eax` — код возврата `Tcl_GetIntFromObj` — за значение аргумента.
> Ошибка поймана кросс-проверкой GDScript ↔ независимая Python-реализация.

### 1.3 Алгоритм генератора

`0x49C670` — это **Mersenne Twister** со **нестандартным посевом**:

* состояние: 624 32-битных слова;
* перекрутка (twist) — стандартная MT19937: первый цикл `i = 0..226` с лагом `+397`,
  второй цикл `i = 227..622` с лагом `-227`, элемент 623 берёт `state[0]` (wraparound MT);
* tempering — стандартный MT19937: `y^=y>>11; y^=(y<<7)&0x9D2C5680; y^=(y<<15)&0xEFC60000; y^=y>>18`;
  в дизассемблировании маски записаны «до сдвига» (`and eax,0xff3a58ad; shl eax,7`),
  что даёт тот же результат, так как `0xFF3A58AD & 0x1FFFFFF = 0x013A58AD` и `0x9D2C5680 = 0x013A58AD << 7`;
* **посев — не стандартный**: `0x4454D0` заполняет состояние из LCG с множителем **69069**:

```
L(0) = seed
L(k+1) = (L(k) * 69069 + 1) mod 2^32
state[k] = (L(k) & 0xFFFF0000) | ((L(k+1) >> 16) & 0xFFFF)
```

* дополнительный шаг после перекрутки (`0x49C87A`): ещё одно обновление `state[623]`.
  На **первые 623 розыгрыша** он не влияет; расхождение с «чистым» MT19937 появляется
  ровно на **624-м розыгрыше** (проверено численно: `seed 0/1/123456789` — первое расхождение
  на розыгрыше №624). Глава использует ~10 розыгрышей, поэтому на результат главы это не влияет.
* ветка «пересев» `counter == 0x271` (посев 0x1105) — **мёртвый код**: счётчик циклит 1..624
  и значения 625 не достигает.

### 1.4 Что это значит для воспроизводимости

Оригинал засевает RNG **значением `GetTickCount()`** (`0x401AE0`), т.е. моментом старта игры.
Внешнего, публикуемого seed у оригинала нет ⇒ **конкретные уровни оригинала не воспроизводятся
по фиксированному seed**.

Реализация в проекте (`scripts/diggles_irandom.gd`) — **факт по алгоритму**: при том же
значении seed она даёт ту же последовательность, что и оригинал. Различается только *выбор*
значения seed: хост задаёт его явно.

**Отдельно, независимая проверка:** в живом проекте уже есть `tools/diggles_rng.py`
(стандартная формулировка MT19937 + LCG-посев). Моя независимая реализация по дизассемблированию
совпала с ней на первых 623 розыгрышах для всех проверенных seed — т.е. существующая в проекте
реализация корректна, и расхождение живого `parse_campaign_map.py` с `Campaign.tcl` — не в RNG,
а в логике переноса (см. §2).

---

## 2. Три ошибки в ранее сделанном разборе (факт → исправлено)

Эти места найдены сверкой с оригиналом; в реализацию перенесены **правила оригинала**.

### 2.1 `lrem conn 0` — список соединений мутируется

`Campaign.tcl:114` — `incr std_x [lrem conn 0]`. Tcl-команда `lrem` **удаляет первый элемент
из списка** и возвращает его. Поэтому после этой строки `conn` содержит **три** индекса тоннелей,
а не четыре:

| `conlist` (строка) | `std_x +=` | индексы тоннелей после `lrem` |
|---|---|---|
| `{0 0 1 2}` | 0 | 0, 1, 2 |
| `{0 0 2 1}` | 0 | 0, 2, 1 |
| `{0 1 0 2}` | 0 | 1, 0, 2 |
| `{4 2 0 1}` | 4 | 2, 0, 1 |
| `{4 2 1 0}` | 4 | 2, 1, 0 |
| `{4 1 2 0}` | 4 | 1, 2, 0 |

Следствие: условие `if {$itemp==0}` (`Campaign.tcl:148`) — это **позиция элемента `0`
в укороченном списке**, а не «первый элемент». От неё зависит начало вудо-цепочки:

* `conn = 0,1,2` и `0,2,1` → `vodo_x = std_x - 20`;
* `conn = 1,0,2` → `vodo_x = std_x + 8 - 20 = std_x - 12`;
* `conn = 2,0,1` → `vodo_x = std_x + 12 - 20 = std_x - 8`;
* `conn = 2,1,0` и `1,2,0` → `vodo_x = std_x + 20 - 20 = std_x`.

Живой `tools/parse_campaign_map.py` считает `vodo_x = sx - 20` **всегда** — это расхождение
в 4 случаях из 6. Исправлено в `scripts/diggles_campaign_generator.gd` и в
`tools/reference_first_level.py`.

### 2.2 Наборы вудо-цепочек по индексу соединения

`Campaign.tcl:115-124`: `conn_idx < 2` → **только `voconlist2`** (3 цепочки);
`conn_idx < 4` → `concat $voconlist1 $voconlist2` (9); иначе — **только `voconlist1`** (6).

Живой `parse_campaign_map.py` использует общий список из 9 цепочек и для `conn_idx < 2`, и для
`conn_idx >= 4` — то есть выбирает не тот набор. Исправлено.

### 2.3 `irandom 1` = 0

См. §1.2. Живой `diggles_rng.py` здесь прав (делит на сам аргумент).

---

## 3. Таблица шаблонов первой главы (Urwald)

Источник: `data/Templates/urw_*.tcl` (плоские, «развёрнутые» файлы верхнего уровня
`data/Templates/`), геометрия `data/Templates/*.pmp`, материал `data/Templates/*.l2m`.
Извлечено **88 шаблонов** (все, к которым может обратиться `first_level`), **981 объект**.

> В `data/Templates/` есть две формы шаблонов: плоские (`urw_*.tcl` верхнего уровня —
> геометрия + материал + объекты) и исходники редактора (`data/Templates/tcl/urw_*.tcl`,
> где часть шаблонов описана через `split_template`). Плоская форма — это ровно тот контракт,
> который описан в задании, и её использует движок (`map_template` + `map_setlayer2` + `[new ...]`).

### 3.1 Старт и «пещерная живопись»

| Шаблон | pmp | размер | l2m | размер | объектов | содержимое |
|---|---|---|---|---|---|---|
| `urw_unq_start` | `unq_start.pmp` | 60×36 | `urw_unq_start.l2m` | 60×36 | 81 | **5 × `Zwerg`** (owner 0, autolight true), 11 `Grillpilz`, 5 `Stein`, 5 `Pilzstamm`, 5 `Dummy_Moos_uv_g` |
| `urw_unq_hoehlenmalerei` | `leer9x9.pmp` | 36×36 | `urw_unq_hoehlenmalerei.l2m` | 36×36 | 24 | `Dummy_Hoehlenmalerei_a`, `Info_Pos_Spinne`, 7 `Lava_LightSrc_g`, 5 `Lava_LightSrc_g`, 6 `Kris_LightSrc_b`, 4 `Lava_LightSrc_red1` |

`Campaign.tcl:12` — стартовый шаблон в **(208, 0)**;
`Campaign.tcl:13-15` — «пещерная живопись»: **только слой материала** в (30, 23), без геометрии.

### 3.2 Пещеры (`cavelist`, `Campaign.tcl:26-30`)

| Шаблон | pmp | размер | l2m | размер | объектов | содержимое (топ) |
|---|---|---|---|---|---|---|
| `urw_hol_001_a` | `hol_001.pmp` | 20×8 | `urw_hol_001_a.l2m` | 20×8 | 49 | **4 × `Wuker`**, 3 `Raupe`, 3 `Hamster`, 2 `Pilz`, 2 `Info_Coll_e`, `Stein` |
| `urw_hol_014_b` | `hol_014.pmp` | 20×20 | `urw_hol_014_b.l2m` | 20×20 | 30 | 3 `Pilz`, 3 `Dummy_Moos_uh_e`, 2 `Hamster` |
| `urw_hol_018_c` | `hol_018.pmp` | 28×24 | `urw_hol_018_c.l2m` | 28×24 | 52 | 7 `Info_Coll_a`, 3 `Pilz`, 3 `Dummy_Holzwand_g` |
| `urw_hol_019_b` | `hol_019.pmp` | 24×24 | `urw_hol_019_b.l2m` | 24×24 | 31 | 8 `Info_Coll_a`, 3 `Hamster`, 3 `Dummy_Liane_d`, 2 `Raupe` |
| `urw_hol_027_a` | `hol_027.pmp` | 16×12 | `urw_hol_027_a.l2m` | 16×12 | 38 | 2 `Pilz`, 2 `Dummy_Moos_uh_e`, 2 `Hamster` |

### 3.3 Переходы (`tunnlist`, `Campaign.tcl:50-52`)

| Шаблон | pmp | размер | l2m | размер | объектов |
|---|---|---|---|---|---|
| `urw_gng_013_a/b/c` | `gng_013.pmp` | 4×4 | `urw_gng_013_*.l2m` | 4×4 | 2 / 5 / 7 |
| `urw_gng_002_a/b` | `gng_002.pmp` | 8×4 | `urw_gng_002_*.l2m` | 8×4 | 7 / 7 |
| `urw_gng_003_a/b/c` | `gng_003.pmp` | 12×4 | `urw_gng_003_*.l2m` | 12×4 | 9 / 9 / 8 |

### 3.4 «Конец» тоннеля (`urw_gng_021_*`, `urw_gng_022_*`)

18 шаблонов, все 4×4 (`gng_021.pmp` / `gng_022.pmp`). Содержимое — лут и декор:
`Schatztonne`, `Grillpilz`, `Grillhamster`, `Schatzbuch`, `Stein`, `Pilzstamm`, `Zelt`, `Leiter`,
`Keule`, `Bier`, `Steinschleuder`, `Dummy_Moos_*`, `Dummy_Gras_*`.

Наборы букв — `left_letters = {abdef cgih}` и `right_letters = {cfkh abdeg}`
(`Campaign.tcl:102-103`), поэтому в игре используются `urw_gng_021_a..i`, `urw_gng_021_k`,
`urw_gng_022_a..h`, `urw_gng_022_k`.

### 3.5 Вудо-шаблоны (`vodolist`, `Campaign.tcl:64-85`)

22 префикса, 55 вариантов после раскрытия наборов букв (`ab`, `abcd`, `abc`, `abdeg`,
`bcd`, `a`, `acdfhk`, …). Геометрия — от 4×4 (`gng_007/008/009/012/019/023`) до 32×16
(`unq_vodo_001.pmp`, 92 объекта).

**Дефект оригинала (факт):** `vodolist[12] = {urw_gng_034_ acdfhk}` — в игре нет
`urw_gng_034_h.tcl` и `urw_gng_034_k.tcl` (есть только `a,b,c,d,e,f`). При выборе буквы
`h`/`k` оригинал упадёт с ошибкой загрузки шаблона. Порт это воспроизводит: композитор
помечает такое размещение как неразрешённое (`resolved: false`).

**Ещё один факт:** `urw_gng_039_a.l2m` в данных игры — **пустой файл (0 байт)**,
т.е. у этого варианта нет слоя материала. Порт трактует это как «слой отсутствует»
(аналог `map_setlayer2` с пустым файлом), а не как ошибку.

---

## 4. Формат результата генератора по seed

`DigglesCampaignGenerator.first_level(start_x: int, start_y: int, seed_value: int) -> Dictionary`

```jsonc
{
  "seed": 1,
  "start": { "x": 208, "y": 0 },          // аргументы first_level (Campaign.tcl:195)
  "placements": [                          // порядок = порядок lappend в оригинале
    { "template": "urw_hol_027_a", "x": 232, "y": 36 },
    { "template": "urw_gng_021_c", "x": 228, "y": 40 },
    ...
  ],
  "selection": {                           // промежуточные розыгрыши (для проверки)
    "present_side": 1, "comb_index": 7, "conn_index": 5,
    "vodo_chain_count": 6,
    "vodo_chain": [[2,20,0], [11,0,16], ...]
  }
}
```

Порядок `placements` (1:1 с `Campaign.tcl:128-174`):

1. левая пещера `(std_x - xoffset, std_y - yoffset)`;
2. «конец» `urw_gng_021_<left_letter>` `(std_x - xoffset - 4, std_y)`;
3. правая пещера `(std_x + 24, std_y - yoffset)`;
4. «конец» `urw_gng_022_<right_letter>` `(std_x + xoffset + 24, std_y)`;
5. цепочка переходов (по 3 индексам тоннелей после `lrem`), позиция `(x, std_y + yoffset)`, `x += xoffset`;
6. вудо-цепочка, позиция `(vodo_x + dx, vodo_y + dy)`.

Композитор (`DigglesCampaignComposer.compose`) возвращает:

```jsonc
{
  "size": Vector2i(512, 640),              // Campaign.tcl:2
  "cells": [ { "x":.., "y":.., "block":.., "flags":.., "cell_attribute":.., "template":.. } ],
  "layer2_words": PackedInt32Array(512*640),   // L2M-слои всех шаблонов
  "objects": [ { "class":.., "x":.., "y":.., "z":.., "rotation":[..],
                 "owner":.., "physic":.., "autolight":.., "boxed":..,
                 "info":{..}, "template":.. } ],
  "removed_objects": [ ... ],              // удалённые `Wuker` (Campaign.tcl:198-203)
  "placements": [ { "template":.., "x":.., "y":.., "resolved":true } ],
  "fog": { "position": Vector3i(239,14,15), "rect": Vector3i(0,46,22), "undeletable": true }
}
```

### 4.1 Примеры для трёх seed

**seed = 1** (side 1, comb 7, conn 5 → 14 размещений)

```
urw_hol_027_a        232  36      urw_gng_008_b      268  44
urw_gng_021_c        228  40      urw_gng_032_b      248  60
urw_hol_019_b        272  24      urw_gng_045_a      256  52
urw_gng_022_a        296  40      urw_gng_019_a      268  52
urw_gng_002_b        248  40      urw_gng_022_e      272  52
urw_gng_003_c        256  40      urw_gng_023_a      256  72
urw_gng_013_c        268  40      urw_unq_vodo_001_a 216  56
```

**seed = 4357** (side 1, comb 2, conn 1 → 13 размещений)

```
urw_hol_001_a        224  36      urw_gng_043_b      244  44
urw_gng_021_c        220  40      urw_gng_044_b      256  48
urw_hol_027_a        268  36      urw_gng_004_b      244  64
urw_gng_022_e        284  40      urw_gng_030_a      260  56
urw_gng_013_a        244  40      urw_gng_022_a      272  64
urw_gng_003_b        248  40      urw_unq_vodo_001_a 212  56
urw_gng_002_b        260  40
```

**seed = 123456789** (side 0, comb 2, conn 0 → 13 размещений)

```
urw_hol_001_a        224  36      urw_gng_036_a      244  44
urw_gng_021_e        220  40      urw_gng_007_a      248  56
urw_hol_027_a        268  36      urw_gng_042_a      240  60
urw_gng_022_f        284  40      urw_gng_022_d      256  52
urw_gng_013_c        244  40      urw_unq_vodo_001_a 208  56
urw_gng_002_a        248  40
urw_gng_003_c        256  40
```

Полные списки — в `godot/models/campaign_urwald_first_level_golden.json` (эталон,
сгенерирован **независимой** Python-реализацией `tools/reference_first_level.py`).

---

## 5. Unified diff относительно живого дерева

Патч: `C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\campaign-level-generator.patch`
(575 630 байт, unified diff, собран через `difflib`, без git).

Интеграция **чисто аддитивная** — 8 новых файлов, ни один существующий файл живой папки
не меняется. Заголовки патча:

```
diff --git a/models/campaign_urwald_first_level.json b/models/campaign_urwald_first_level.json
new file mode 100644
diff --git a/models/campaign_urwald_first_level_golden.json b/models/campaign_urwald_first_level_golden.json
new file mode 100644
diff --git a/scripts/diggles_campaign_composer.gd b/scripts/diggles_campaign_composer.gd
new file mode 100644
diff --git a/scripts/diggles_campaign_generator.gd b/scripts/diggles_campaign_generator.gd
new file mode 100644
diff --git a/scripts/diggles_campaign_scene.gd b/scripts/diggles_campaign_scene.gd
new file mode 100644
diff --git a/scripts/diggles_campaign_templates.gd b/scripts/diggles_campaign_templates.gd
new file mode 100644
diff --git a/scripts/diggles_irandom.gd b/scripts/diggles_irandom.gd
new file mode 100644
diff --git a/tools/campaign_level_generator_self_test.gd b/tools/campaign_level_generator_self_test.gd
new file mode 100644
```

Каждый файл further содержит полный unified diff (`@@`-хунки) в файле патча; тело патча
не дублируется в отчёте, потому что это 575 КБ машинных данных.

Статистика по файлам:

```
 models/campaign_urwald_first_level.json              +21319  -0
 models/campaign_urwald_first_level_golden.json       +277    -0
 scripts/diggles_campaign_composer.gd                 +181    -0
 scripts/diggles_campaign_generator.gd                +222    -0
 scripts/diggles_campaign_scene.gd                    +108    -0
 scripts/diggles_campaign_templates.gd                +86     -0
 scripts/diggles_irandom.gd                           +118    -0
 tools/campaign_level_generator_self_test.gd          +274    -0
```

Итого **+22 585 строк, −0**, патч — 576 737 байт.
Проверка round-trip: `scripts/verify_campaign_patch.py` применяет патч к **чистой копии
живого дерева** и сравнивает результат с рабочей копией —
`PATCH ROUND TRIP OK: patching the live project reproduces the verified work tree`
(8 файлов, 0 расхождений по SHA-256).

> **Важно:** `scripts/multiplayer_test.gd` в живой папке отличается от моего снимка —
> его параллельно правит другой исполнитель. В патч он **намеренно не включён**
> (иначе патч откатил бы чужую работу). Сборщик патча печатает такие файлы как
> `live drift not patched`.

### 5.1 Что добавлено

| Файл | Назначение |
|---|---|
| `scripts/diggles_irandom.gd` | порт `irandom` (§1) |
| `scripts/diggles_campaign_generator.gd` | порт `first_level` (§4) |
| `scripts/diggles_campaign_templates.gd` | загрузчик манифеста шаблонов |
| `scripts/diggles_campaign_composer.gd` | композитор: PMP-геометрия + L2M + объекты + `Wuker` + туман |
| `scripts/diggles_campaign_scene.gd` | сборка сцены Godot из скомпонованного уровня |
| `tools/campaign_level_generator_self_test.gd` | self-test |
| `models/campaign_urwald_first_level.json` | данные 88 шаблонов первой главы |
| `models/campaign_urwald_first_level_golden.json` | эталонные значения по 3 seed |

Офлайн-инструменты (вне дерева Godot, в рабочей копии):
`work\campaign\tools\extract_campaign_templates.py` (шаблоны → манифест),
`work\campaign\tools\reference_first_level.py` (независимая эталонная реализация),
`work\campaign\ref\*.py` (PE/дизассемблер для §1),
`work\campaign\scripts\{build,verify}_campaign_patch.py`, `run_suites.py`.

---

## 6. Прогоны

### 6.1 Self-test нового блока

```
Godot Engine v4.7.2.stable.official.ed1daf0bf
CAMPAIGN_LEVEL_GENERATOR_SELF_TEST_OK assertions=450 templates=88 seeds=3
exit=0
```

Покрыто 450 проверками:

* **RNG**: 3 seed × 8 эталонных розыгрышей (24), `irandom(1) == 0` (1),
  диапазон `irandom(n) ∈ [0, n)` для 7 лимитов × 32 (224);
* **генератор**: 3 seed × (список размещений: имя/x/y) (3 × 13..14 × 3 = 120),
  детерминизм (3), различие разных seed (1);
* **композиция**: размер карты, число клеток, размер слоя материала,
  послойное наложение L2M стартового шаблона (60×36),
  «пещерной живописи» (36×36), пещеры (20×8),
  5 гномов с `owner = 0` и `autolight = true`, наличие ресурсов,
  **точное сохранение позиции и флага `physic` каждого объекта пещеры**
  относительно шаблона (39 объектов `urw_hol_027_a` — все, кроме `Wuker`),
  удаление `Wuker` (0 в итоге при 15+ в сырых шаблонах),
  позиция ресурса относительно шаблона,
  туман: позиция (239,14,15), прямоугольник (0,46,22), `undeletable`;
* **сцена**: узлы `CampaignTerrain` / `CampaignObjects` / `FogRemover`,
  число узлов объектов, 5 узлов гномов, 0 узлов `Wuker`, прямоугольник тумана.

### 6.2 Полный набор self-test проекта (регрессии)

Запуск в **моей копии** (`work\campaign\godot`) всех `tools/*self_test*.gd`:

<!--SUITE_RESULT-->

---

## 7. План интеграции и отката

### 7.1 Интеграция

1. Взять `work\campaign\campaign-level-generator.patch`.
2. Применить в корне `ChatGPT\Diggles\godot`: `git apply campaign-level-generator.patch`
   (или `patch -p1`). Патч проверен на чистой копии живого дерева.
3. Прогнать `tools/campaign_level_generator_self_test.gd` и полный набор self-test.
4. Godot сам создаст `.uid`-сайдкары для новых скриптов при первом импорте —
   в патч они не включены (согласуется с практикой проекта).

Ни один существующий файл проекта не меняется ⇒ риск регрессий ограничен новыми
именами скриптов и новыми ресурсами в `models/`.

### 7.2 Откат

Полное удаление — одна команда (в корне `godot`):

```
git apply -R campaign-level-generator.patch
```

или удалением 8 перечисленных в §5 файлов. Так как изменения аддитивные, откат
не затрагивает ни один существующий модуль проекта.

### 7.3 Что НЕ входит в интеграцию

* BDB-меши блоков (1229 block id) — в проект не переносятся, см. §8.2.
* `data/Templates/**` оригинала — не копируются; в проекте лежит только извлечённый
  манифест данных одного уровня (530 968 байт) и композитор.

---

## 8. Факт / адаптер / неизвестное

### 8.1 Факт (проверено по оригиналу)

* `irandom` — нативная команда; формула `(draw & 0x7FFFFFFF) % n` (§1.2).
* Генератор — MT19937 (624 слова, mag01, tempering) с LCG-посевом (множитель 69069) (§1.3).
* Стартовый посев оригинала — `GetTickCount()` (§1.4) ⇒ уровни оригинала не привязаны к seed.
* Таблицы `first_level` и порядок розыгрышей — построчно из `Campaign.tcl:22-191` (§2, §4).
* `lrem conn 0` мутирует список соединений (§2.1).
* Наборы вудо-цепочек зависят от индекса соединения (§2.2).
* Формат шаблона: `map_template` + `map_setlayer2` + `[new ...]` + флаги
  `owner/physic/autolight/boxed` + `Editor_Set_Info` (§3).
* Старт: `urw_unq_start` в (208,0), 5 `Zwerg` с `owner 0`, `autolight true`;
  «пещерная живопись» — только L2M в (30,23) (§3.1).
* Удаление всех `Wuker` и `FogRemover` в (239,14,15) с `fog_remove 0 46 22`
  (`Campaign.tcl:198-212`) (§4).
* Дефекты данных оригинала: отсутствуют `urw_gng_034_h/k`,
  `urw_gng_039_a.l2m` пустой (§3.5).

### 8.2 Адаптер (инженерное решение, помечено в коде)

* **Seed задаёт хост.** Оригинал берёт `GetTickCount()`; порт принимает seed явно,
  чтобы уровень был воспроизводим. Алгоритм при этом — оригинальный.
* **Превью-геометрия в сцене.** `scripts/diggles_campaign_scene.gd` рисует по одному
  квадрату на клетку, подкрашенному словом L2M-слоя. Нативные меши блоков BDB
  (1229 разных block id; в живом проекте есть только 238 мешей для его собственного
  стартового шаблона) не переносятся — это отдельная задача объёма ~25 МБ.
  Квадрат — **адаптер превью**, а не рендер нативной геометрии.
* **Шаг после перекрутки** (`0x49C87A`) реализован как в бинаре; на первых 623
  розыгрышах он не влияет, но на 624-м расходится с «чистым» MT19937 — учтено в §1.3.
* **`urw_gng_039_a` без L2M** трактуется как «слой отсутствует» (§3.5).
* **Границы карты** 512×640 (Campaign.tcl:2) приняты как есть; поле за пределами
  размещений остаётся пустым (как в оригинале, где пустоту заполняет `sm_draw_stone`).

### 8.3 Неизвестное

* **Реальные уровни оригинала.** Seed оригинала (`GetTickCount()`) и число розыгрышей
  до `first_level` неизвестны ⇒ воспроизвести конкретную записанную главу нельзя.
  (Живой `parse_campaign_map.py` это уже отмечает.)
* **Поведение `RaiseException` в границе перекрутки.** В `0x49C8DC` (индекс 623,
  чтение `state[624]`) стоит `RaiseException(STATUS_ARRAY_BOUNDS_EXCEEDED,
  EXCEPTION_NONCONTINUABLE)`; путь продолжения в коде использует `state[0]`
  (это wraparound MT19937). Реальное поведение процесса (перехват исключения или
  авария) без запуска игры не проверяется. Порт следует **пути продолжения**
  (`state[0]`), т.е. поведению MT19937.
* **Разрешение BDB-блоков в сцене** (§8.2) — не реализовано.
* **Миры Schwefel / Metall / Lava / Kristall / 6000** — не трогались: у них свои
  `Campaign*.tcl` и свои таблицы.

---

## 9. Что осталось открытым (следующие шаги)

1. Вынести seed главы в отдельный конфиг и дать игроку выбор/сохранение seed'а.
2. Извлечь BDB-меши для 1229 блоков и заменить превью-квадраты нативной геометрией.
3. Перенести `sm_draw_stone -border/-funnel` и `generate_color_variation`
   (`Campaign.tcl:3-6`) в композитор — сейчас карта за пределами шаблонов пустая.
4. Подключить сцену главы к `multiplayer_test.tscn` (вместо ручного поля 128×128).
5. Перенести сборку остальных миров кампании по их `Campaign*.tcl`.
6. Заменить превью тумана `FogRemover` на реальный fog-of-war.

---

INTEGRATION_HANDOFF: docs/reverse-engineering/agent-result-campaign-level-generator-2026-11-19.md
