# -*- coding: utf-8 -*-
import io, os

P = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\docs\reverse-engineering\agent-result-keybind-camera-2026-11-22.md"

TEXT = u"""
---

## 14. WASD-камера: найден реальный конвейер ввода, патч в `DigglesPort.dll` (РЕШЕНО)

### 14.1 Как на самом деле устроен ввод (факт)

1. `Diggles.exe` (32 бит, PE32, base `0x400000`) импортирует из `SDL2.dll` **только `SDL_PollEvent`**;
   весь ввод с клавиатуры идёт через собственный обработчик событий движка.
2. Обработчик — `FUN_0054e470` (VA `0x0054E470`, 1008 байт). Он вызывается из `0x006B5A37`
   (`lea ecx, [ecx+0x368]; call 0x54e470`, где `ecx = *DAT_00772400` — глобальный объект игры).
3. Обработчик работает со **структурой `SDL_Event`**:
   `type` по смещению `0x00` (`0x300` = SDL_KEYDOWN, `0x301` = SDL_KEYUP),
   `keysym.scancode` по смещению `0x10` (тип `SDL_KeyboardEvent`).
4. **Ключевая точка:** `keysym.scancode` передаётся в импортированную из `DigglesPort.dll`
   функцию `?GetVKScanCode@@YAGG@Z` (IAT `0x00715038`), и результат — **Windows VK-код** —
   сравнивается с константами `0x25/0x26/0x27/0x28` (VK_LEFT/UP/RIGHT/DOWN) в VA `0x54E669…0x54E740`.
   То есть движок оперирует **VK-кодами**, а не SDL-символами.
5. Реестр подтверждает, что это именно камера: `HKCU\\Software\\SekOst\\Diggles\\Input\\KeyScroll = 1`
   (рядом `MouseScroll`, `BorderScroll`).

### 14.2 Таблица scancode → VK (факт)

`GetVKScanCode` (`DigglesPort.dll`, RVA `0x11650`, 1141 байт) строит `std::map<uint16,uint16>`:
* **ключ** = SDL-сканкод (младшие 16 бит константы),
* **значение** = Windows VK-код (старшие 16 бит константы),
* константы упакованы как `(vk << 16) | scancode` и лежат как **непосредственные значения
  (`mov dword ptr [ebp-0xNN], imm32`) внутри самой функции** — то есть таблицы в `.data` нет,
  она собирается на стеке при первом вызове.

Найденные записи (файл-офсеты в `DigglesPort.dll`):

| сканкод | клавиша | было | стало | офсет |
|---|---|---|---|---|
| 4  | A | `0x00410004` (VK_A=0x41)   | `0x00250004` (VK_LEFT=0x25)  | `0x010CB6` |
| 7  | D | `0x00440007` (VK_D=0x44)   | `0x00270007` (VK_RIGHT=0x27) | `0x010CD4` |
| 22 | S | `0x00530016` (VK_S=0x53)   | `0x00280016` (VK_DOWN=0x28)  | `0x010D6A` |
| 26 | W | `0x0057001A` (VK_W=0x57)   | `0x0026001A` (VK_UP=0x26)    | `0x010D92` |

Стрелки (сканкоды 79/80/81/82 → 0x27/0x25/0x28/0x26) и остальные клавиши не тронуты.
Побочный эффект: A/S/D/W больше не приходят в движок как буквы (текстовых полей ввода в игре нет —
в `Diggles.exe` нет ни одного `EditField`/`TextField`).

### 14.3 Проверка (факт, автотест)

`work/thirdparty/DigglesModManager/WasdVerify.cs` грузит DLL через `LoadLibrary` и вызывает
`GetVKScanCode` по mangled-имени `?GetVKScanCode@@YAGG@Z`:

```
оригинал:  scancode 4 (A) -> VK 0x41      scancode 80 (Left) -> VK 0x25
после:     scancode 4 (A) -> VK 0x25      scancode 80 (Left) -> VK 0x25
            scancode 7 (D) -> VK 0x27      scancode 26 (W)    -> VK 0x26
            scancode 22(S) -> VK 0x28      scancode 30 (1)    -> VK 0x31 (без изменений)
```

### 14.4 Что установлено в папку игры

| файл | назначение |
|---|---|
| `DigglesPort.dll` | пропатченная (SHA256 `358B12A6…FC7BF`) |
| `DigglesPort.dll.orig` | бэкап оригинала (SHA256 `ACE39618…6CF3`) |
| `apply-wasd-camera.ps1` | переустановщик патча (идемпотентный) — на случай, если Steam вернёт оригинал |
| `WASD camera.cmd` | лаунчер: переустанавливает патч и запускает игру |
| `Diggles.exe` | **не изменялся** (SHA256 `58A01D3D…0ED74`, совпадает с эталоном) |

Откат: `copy /Y DigglesPort.dll.orig DigglesPort.dll`.

### 14.5 Почему не сработали прежние подходы (факт)

* **Патч `Diggles.exe`** (code cave в INT3-padding'е, VA `0x401F23`) — хук цеплялся к
  обработчику клавиш **текстового поля** (`GetKeyState(VK_SHIFT)` + `MapVirtualKeyA` по пути `0x54E5C9`),
  а не к обработчику камеры. Реальная точка сравнения VK-кодов — `0x54E669`, но она
  сравнивает уже **преобразованный** движком код, а не «сырое» нажатие.
* **Внешний перехватчик (`SendInput`)** — в принципе не нужен: сценарий «WASD → стрелка»
  делается нативно, без подмены ввода. Перехватчик оставлен в `work/thirdparty/DigglesModManager/archive/`.
* **`keybind`** — по-прежнему мёртвый код (§9), Tcl-путь закрыт.
"""

with io.open(P, "a", encoding="utf-8") as f:
    f.write(TEXT)

print("appended, size:", os.path.getsize(P))
