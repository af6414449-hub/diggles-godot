# PE и платформенный слой

Дата: 2026-11-14

## Подтверждено

- `Diggles.exe`: PE32, x86, 3,813,376 байт.
- `DigglesPort.dll`: PE32, x86, 340,480 байт.
- Локальные `SDL2.dll`, `steam_api.dll`, `tcl83.dll` и `DigglesPort.dll` также 32-битные.
- SHA-256 `Diggles.exe`: `58A01D3D80670A6042C66A82684397C98E39C503E00A6E2C2C511F338A30ED74`.
- SHA-256 `DigglesPort.dll`: `ACE39618AC4946454EADAF35A824144C67B525CCAFFFAD8A19AD200B3FDB6CF3`.

## Зависимости

`Diggles.exe` импортирует `DigglesPort.dll`, SDL2, Tcl, DirectSound/WinMM, WinAPI и Winsock.

`DigglesPort.dll` зависит от:

- SDL2;
- Direct3D 11 и DXGI;
- D3DCompiler 47;
- Steam API;
- Media Foundation;
- WinMM и Windows API;
- MSVC runtime.

Экспортируемые подсистемы включают `CSdlWindow`, `CSdlManager`, управление дисплеем и разрешением, SoLoud-аудио, Steam-достижения, `CPlayer`, `TimeManager` и post-process/gamma.

## Вывод

Прямой перенос Windows-бинарников на Android не является рабочим направлением: это x86 PE с Windows/Direct3D-зависимостями.

`DigglesPort.dll` полезен как документация архитектурных абстракций, но Android-реализация должна заменить его платформенные части:

- D3D11/DXGI → SDL2 + OpenGL ES/Vulkan;
- Media Foundation → Android Media APIs или SDL-аудио;
- Steam API → заглушка/абстракция сервисов;
- Windows input/window → SDL touch events;
- Tcl runtime → совместимый Tcl или слой совместимых команд.
