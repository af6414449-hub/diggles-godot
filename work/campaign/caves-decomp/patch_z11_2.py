import io, sys, os

base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp"
rp = os.path.join(base, "report.md")

raw = open(rp, "rb").read()
bom = raw.startswith(b"\xef\xbb\xbf")
text = raw.decode("utf-8-sig")
print("BOM:", bom, "len:", len(text))

SECTION = """
---

## З11.2. Порядок вызова загрузчика `.pmp` (`FUN_005992b0`) и beautifier'а (`FUN_005a6b40`); что такое `FUN_0041fad0`

Подробно — `z11-pmp-vs-beautifier.md`. Все адреса сверены по дизассемблеру (`work/campaign/ref/disasm.py`).

### ФАКТ (Diggles.exe)

1. **Карту суб-клеток (`cell+0x3c…0x7b`) перезаписывает ровно одна функция — `FUN_00596550`**, и у неё ровно три вызова: `FUN_005992b0:563` (загрузчик `.pmp`), `FUN_005a6b40:518` (beautifier), `FUN_005a5da0:148` (штамп теней объектов). `FUN_00596550_00596550.c:56,62` — клетка = `index * 0x7c + base` ⇒ **размер клетки 0x7c = 124 байта**; `:67-102,114` — 64 байта = **карта 8×8 по 1 байту на суб-клетку**; прямоугольник задаётся **в суб-клеточных координатах** (`:28,29,32`).
2. **Beautifier `FUN_005a6b40` считает эту карту по высотам**: `:78` `FUN_00595e40` заполняет локальную сетку высот; `:120-130, 434-469` — сравнение высот соседей с порогом **«+2»** ⇒ байт ∈ {0,1,3} (нет земли / земля / земля+ступенька); `:503-512` — запись **по одному байту на суб-клетку**; `:518` — слив в карту через `FUN_00596550`.
3. **`FUN_0041fad0` — это НЕ глобальная карта высот, а `std::vector<uint8>::at(int)`.** Дизасм 0x41fad0: `mov esi,ecx` (this) → `mov ecx,[ebp+8]` (индекс) → `test/cmp` границ → `mov eax,[esi]; add eax,ecx`; вне диапазона — `RaiseException(0xc000008c)` (0x41FAEB). Вызовов ровно 4, все в beautifier'е (`:458,460,462,464`; VA 0x5A7679/0x5A7694/0x5A76B3/0x5A76C6), причём `this` берётся **из стека**: `0x5A7669: lea ecx,[esp+0x88]`, `0x5A76AC: lea ecx,[esp+0x8c]` ⇒ это аксессор к двум **локальным векторам сетки высот самого beautifier'а**.
4. **`.pmp`-загрузчик `FUN_005992b0` пишет в карту суб-клеток RLE-данные файла**: `:534-546` — 16-битное слово `v` → длина `v >> 2` (0 → 0x4000), **значение = `v & 3`** (0/1/2/3 — это и есть байт суб-клетки); `:529-547` — декодирование в буфер `W*H`; `:549-565` — `FUN_00596550(iVar6, {x0*8, y0*8, x1*8, y1*8})`.
5. **Кто запускает beautifier.** `FUN_005a46d0` = `World::GetMapValidator().Service()` (строка-имя в `CGameThread__SrvDoThink_006b4a30.c:424`); `:132-157` — цикл по списку `validator+0x00`, для каждого ректа `:153` `FUN_005a6b40(&local_24)`. Список `validator+0x00` наполняется из 13 очередей `validator+0x9c + type*0xc` (`:59-98`; дизасм `0x5A472B: lea eax,[edi+0x9c]`, `0x5A47CD: lea ecx,[edi+esi]`). Очередь `type` наполняет `FUN_005a3fd0(validator, x0,y0,x1,y1, flags)` (thiscall; дизасм `0x5A3FDD: mov esi,ecx`): бит `k` флага → очередь `type=k` (`0x5A41A3: lea ecx,[esi+0x9c]` для бита 1, `0x5A41F9: lea ecx,[esi+0xa8]` для бита 2). **Beautifier = тип 0 = флаг `0x1`.**
6. **Флаги в реальных вызывающих:**

   | место | флаг | бит `0x1`? | beautifier? |
   |---|---|---|---|
   | `CGameThread__CreateMap_006b4440.c:145-146` (создание карты) | `0x10` | нет | **нет** |
   | `FUN_004f7c30_004f7c30.c:368` | `0x10` | нет | нет |
   | `FUN_005931f0_005931f0.c:243-244` («World validate») | `0x5f` | **да** | **да, по всей карте** |
   | `CTclObjMethods__SetPFInfluenceRect_0068f430.c:336,352` | `7` | **да** | **да, на PF-ректах** |
   | `FUN_005992b0:576-602` (загрузчик `.pmp`) | `0x40000`, `0x400`, `8` | нет | **нет** |

   `0x5f` = 0b1011111; `0x40000` раскладывается внутри `FUN_005a3fd0` в 6/0x10/0x40 (`FUN_005a3fd0_005a3fd0.c:31-36`) ⇒ типы 1,2,4,6 — бита `0x1` нет.
   Схема вызова подтверждена дизасмом `CGameThread__CreateMap`: `0x6B46E8: call 0x5a3dd0` (взять валидатор) → `0x6B46EF: call 0x5a3fd0` (AddRect) → `0x6B46F9: call 0x5a3dd0` → `0x6B4700: call 0x5a46d0` (Service). `FUN_005a3dd0` (0x5a3dd0) — **get-or-create синглтона**, стек он не читает.
7. **Порядок вызовов по путям:**

   | путь | последовательность | кто последним пишет `cell+0x3c` |
   |---|---|---|
   | Редактор: `FUN_005992b0:74-86` | `CGameThread__CreateMap` (`:84`) → файл → `FUN_00596550` (`:563`) | **`.pmp`** |
   | Загрузка `.pmp` как карты: `FUN_004faa70:71-88` | `CGameThread__CreateMap` (`:83`) → `FUN_005992b0` (`:88`) | **`.pmp`** |
   | Игра, старт главы: `map create` → `map_template` | `CreateMap` (beautifier **не** запускается — флаг `0x10`) → `CTclGlobalMethods__MapTemplate:260,271` → `FUN_005992b0:563` | **`.pmp`** |
   | Игра, «World validate»: `FUN_005931f0:243-247` | флаг `0x5f` ⇒ beautifier по **всей карте** | **beautifier** |
   | Игра, PF-ректы: `SetPFInfluenceRect:336,352` | флаг `7` ⇒ beautifier на этих ректах | **beautifier** |
   | Каждый тик: `CGameThread__SrvDoThink:441-444` → `FUN_005a46d0` | если очередь типа 0 не пуста — перезапись **каждый кадр** | **beautifier** |

   `FUN_005931f0` («World validate») вызывается из `FUN_00556570:177` (метки «Loading/World/Objects/Control/Graphics/Logic/Validate»), а `FUN_00556570` — из `CTclGlobalMethods__GameLoad_006310f0.c:71` (команда `game_load`), `FUN_00541650:104`, `FUN_0053f0a0:105`.

### Что это меняет для порта

* **Бит 1 «ступенька» приходит из файла `.pmp`** (RLE-код `v & 3` = 3), если `.pmp` не перебит прогоном «World validate». Порт, строящий откосы по разности высот соседей (З1/З3), **не может воспроизвести исходные уступы без чтения `.pmp`** — нужен ридер RLE-части `.pmp`.
* В оригинале карта суб-клеток — общий буфер с тремя независимыми писателями ⇒ воспроизводить надо **не конечное состояние, а порядок операций**: сначала высоты/блоки, затем карта суб-клеток из `.pmp`.
* Если порт будет поддерживать загрузку сохранений — учесть, что «World validate» перезаписывает карту суб-клеток по всей карте.

### Что осталось неизвестным

* **Точный момент «World validate» относительно `map_template` в игре.** Цепочка `FUN_0053f0a0 → FUN_00541650 → FUN_00556570 → FUN_005931f0` установлена, но не доказано, что она выполняется **после** `Campaign.tcl` (`map create` на `:2`, `MapTemplateSet` на `:12,20,195`). Проверка: breakpoint на `FUN_005a6b40` и `FUN_00596550` при запуске главы и сравнение порядка вызовов; либо трассировка `single_CampaignX.tcl:3-4` (`call_method $sm load_level Campaign`).
* **Семантика остальных 12 типов очередей валидатора** — установлено только соответствие «бит флага → номер очереди».
* **Полная формула beautifier'а** — восстановлен порог «+2» (`FUN_005a6b40:120-130, 434-469`), формула целиком не выписана (`:120-500`).
* **Кто владеет списком `validator+0x00` и очищается ли он** после прогона — видно только наполнение.
* `FUN_005a6b40:105` — 7-й бит байта `cell+0x18` используется как «существует земля»; его связь с портовым `cell[0x18]>>8` (вариация) не проверена.

---

"""

# 1) вставка раздела перед "## З9.6"
anchor = "## З9.6 Уточнение:"
assert text.count(anchor) == 1, text.count(anchor)
assert "## З11.2." not in text
text = text.replace(anchor, SECTION.lstrip("\n") + anchor)

# 2) строка в таблице документов
row_anchor = "| `work/campaign/caves-decomp/z10-cell-fow-and-subcell-map.md` | З10–З11 — `cell+0x34` (туман войны по игрокам) и `cell+0x3c` (карта суб-клеток) |\n"
assert text.count(row_anchor) == 1
newrow = row_anchor + "| `work/campaign/caves-decomp/z11-pmp-vs-beautifier.md` | З11.2 — порядок вызова `.pmp`-загрузчика и beautifier'а; что такое `FUN_0041fad0` |\n"
text = text.replace(row_anchor, newrow)

out = text.encode("utf-8")
if bom:
    out = b"\xef\xbb\xbf" + out
open(rp, "wb").write(out)
print("OK, bytes:", len(out))
