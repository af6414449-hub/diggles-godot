# DigglesModManager — локальная установка

Оригинал: <https://github.com/DigglesMods/DigglesModManager> (GPL-3.0), релиз v1.3.1.
Полный разбор и результаты измерений: `docs/research/Diggles_modding-2026-11-22.md`.

## Состав

| Путь | Что это |
|---|---|
| `app/` | распакованный релиз v1.3.1: EXE, `Newtonsoft.Json.dll`, 17 модов |
| `source/` | исходники `master` (для изучения, не для сборки) |
| `sandbox/Diggles/` | песочница: копия игры + менеджер; моды применены |
| `apply-mods.ps1` | применение модов реальным кодом менеджера, без GUI |
| `restore-mods.ps1` | откат через `ModdingService.Restore()` |
| `diff-mods.py` | сравнение песочницы с эталоном Steam → `mods-diff.md` |
| `mods-diff.md`, `mods-diff.json` | результат последнего измерения |

## Запуск

```powershell
# GUI: менеджер обязан стартовать из папки игры (Paths.ExePath = ".")
cd sandbox\Diggles
.\DigglesModManager.exe

# пакетное применение всех модов
cd ..
powershell -NoProfile -STA -File .\apply-mods.ps1

# откат
powershell -NoProfile -STA -File .\restore-mods.ps1
```

## Важно

- Эталонная установка в Steam (`...\steamapps\common\Diggles The Myth of Fenris`)
  **не изменяется** — всё работает в песочнице. Менеджер пишет прямо в `Data/`
  игры, а проект использует установку как источник фактов.
- Релизная сборка — .NET Framework 4.0, дополнительных рантаймов не требует.
- Скрипты `.ps1` сохранены в UTF-8 с BOM (PowerShell 5.1 иначе ломает кириллицу).
