# Misc_Light: исходные render assets — 2026-11-18

Подготовлены отдельные данные для интегратора placement logic. Исходники прочитаны из `C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris/data`. Записи ограничены новым экспортёром, новым visual JSON, каталогом его текстур и этим документом. APK и запуск Godot для импорта ресурсов не требуются.

Файлы:

* `tools/export_native_torch_visual.py` — воспроизводимый экспорт, Pillow + pefile + capstone.
* `godot/models/native_torch_visual.json` — schema `diggles.native_torch_visual.v1`.
* `godot/textures/native_torch/Metall_Werkzeuge_a_128.tga` — побайтовая копия оригинала.

Из корня workspace:

```powershell
python -B tools/export_native_torch_visual.py
python -B tools/export_native_torch_visual.py --check
```

Для другой установки используется `--data-root <каталог data>`; `Diggles.exe` читается из родительского каталога. Экспортёр проверяет известный SHA-256 EXE перед применением адресов. `--check` полностью пересобирает данные в памяти, сравнивает байты JSON, набор TGA и байты каждой текстуры; каталогов, файлов и Python bytecode не создаёт. В самом экспортёре также установлен `sys.dont_write_bytecode=True`. В JSON есть SHA-256 экспортёра, трёх используемых Python helpers, всех исходных Tcl/3DB, кандидатов текстуры, EXE и каждого диапазона инструкций. При изменении helper нужно снова экспортировать JSON.

## Контракт интеграции

`asset.key = licht.3db::fackel`, `asset.animation = standard`, `asset.animation_index = 0`, `asset.mesh_indices = [0,1]`. Порядок `asset.frames` соответствует исходной последовательности. Оба mesh сохранены, включая source file offsets, bounds и исходные link tuples. В `asset.extra` сохранены исходные `u16=0`, `f32=0`, путь `fackel_standard.sex`, нулевые `vec_a/vec_b`; поле `f32` не интерпретируется как FPS или duration.

Каждый frame имеет `mesh_index`, `bounds`, `surfaces`, `source_file_offset`, `source_links`. Surface соответствует существующему `export_demo_start_models.export_mesh`: `material`, `texture`, `points`, `uvs`, `triangles`, `brightness`, плюс `alpha_range` и `texture_resource`. Функция используется через `export_dwarf_attachments.mesh_exporter`, который компилирует существующий `export_mesh` из AST без запуска main экспортёра.

| Данные на кадр | Значение |
| --- | --- |
| surfaces | 1 |
| points / uvs / brightness | 7 / 7 / 7 |
| triangle indices | 18 = 6 треугольников |
| texture | `Metall_Werkzeuge_a_128.tga` |
| alpha_range | `[0,255]` |

`asset.frames_geometry_equal=true`: исходные links обоих meshes равны `(0,3,0,0,0,0)` и ссылаются на одинаковые массивы геометрии. Два кадра сами по себе не доказывают анимацию пламени.

`points` — тройки `u16/65536`, без центрирования по bounds. Декодирование native координаты: `m = 16384*(point-0.5)`. Для локальных render displacement применяется native row rotation `Rz*Rx*Ry`, scale `.005`, отражение Y. Исходный порядок треугольников, float32 UV и u8 brightness сохранены. Перестановки UV или индексов экспортёр не делает. Parent pose, world depth packing и shader policy принадлежат интегратору; локальный displacement уже в render units. `bounds` остаются исходными двумя тройками float32 и не являются pivot.

`textures` — словарь по исходному имени TGA. Surface содержит готовый путь `res://textures/native_torch/Metall_Werkzeuge_a_128.tga`. Выбран `Texture/m128/Metall_Werkzeuge_a_128.tga`, 128×128, 65580 bytes. Кандидаты Gray 32×32 и m064 64×64 перечислены с hashes в JSON. Правило выбора детерминировано: максимум `(area, parent==m256, relative_path)`. Alpha получена из фактического A-канала; `[0,255]` требует поддержки прозрачности при интеграции материала. Конкретная blend/depth политика здесь не назначается. `asset.source_materials` сохраняет имя, оригинальный material path и raw `unknown=1`.

`light` фиксирует `offset_native=[0,-0.5,1]`, `range_native=6`, `rgb=[0.9,0.9,0.8]`. `provenance.class_lines` сохраняет полный блок `emitter.tcl:3–11`, включая `class_snaptowall 1`, `class_viewinfog 1` и `class_disablescripting`.

## Доказанный timing и режим исходного автофакела

**Исходный `Misc_Light` использует `ANIM_STILL`, кадр 0, удерживаемый без ограничения времени.** Для самого клипа контроллер имеет номинальную частоту **10 кадров на игровую секунду**, шаг **0.1 игровой секунды**; два кадра дают **0.2 игровой секунды при проигрывании**. Эти числа находятся в `playback.nominal_*`. Они не включают автоматическое проигрывание: `mode=0`, `loop=false`, `default_still_duration_game_seconds=null` с явным смыслом «held indefinitely».

Цепочка проверена непосредственно в оригинальном EXE:

1. `emitter.tcl:8` вызывает `class_defaultanim fackel.standard` с одним аргументом. `animinit.tcl:4–6` и `animclassinit.tcl:6–8` задают STILL=0, ONCE=1, LOOP=2.
2. Регистрация `class_defaultanim` указывает callback `0x613520` (`push 0x613520` по `0x6105BC`). В callback `0x613623` обнуляет EDI; только argc=3 разбирает второй аргумент как mode (`0x613625–0x613668`). При argc=2 mode остаётся 0. `0x6137A9` сохраняет EDI в class+0x20.
3. В native autolight после создания объекта проверяется отсутствие анимации (`0x5D46AD`). При необходимости используются class default arrays, затем `0x5D473C` передаёт class+0x20 как mode; `0x5D4741` передаёт start=0 в `0x5CDAE0`. Этот путь получен из native candidate consumer, исследованного также в `automatic-torches-2026-11-18.md`.
4. `0x5CDC57` читает mode из `[ebp+0x14]`; `0x5CDD4E` передаёт его в `0x461B90`; `0x461D2C` сохраняет controller+0x30. Start frame сохраняется по `0x461D37` в controller+0x34.
5. `0x462044–0x462050` при mode=0 возвращает сохранённый кадр. Продвижение времени для STILL не вычисляется.
6. При проигрывании `0x462056–0x462073` вычисляет `float32((game_time-start_time)*10 + bias)`; double по `0x7373F0` содержит ровно `10.0`, double по `0x737190` содержит `0.05000000074505806`. Далее `FISTP` по `0x462085`; ONCE зажимает конец, LOOP берёт остаток по числу кадров. Начальный guard controller+0x1c=-1 даёт первый sample 0.

В `provenance.native_evidence` сохранены 9 полных диапазонов инструкций (end exclusive), raw instruction bytes и SHA-256:

| Назначение | Диапазон VA |
| --- | --- |
| Регистрация class_defaultanim | `0x61054E..0x6105DF` |
| Default mode и optional argument | `0x61360A..0x61366A` |
| Запись class mode | `0x613794..0x6137B2` |
| Autolight default animation | `0x5D46A3..0x5D474C` |
| Передача аргументов set_anim | `0x5CDC46..0x5CDD76` |
| Начальное состояние контроллера | `0x461CFE..0x461D58` |
| Выбор frame и timing | `0x462040..0x4620DE` |
| Загрузка animation extra | `0x402AF9..0x402B99` |
| Game clock update | `0x5653F0..0x565483` |

Экспортёр проверяет полное дизассемблирование каждого диапазона и hashes исходного EXE. Это статическое доказательство в домене game seconds. Wall-clock capture и live x87 control word не получены: точные границы переходов frame через FISTP не подменяются предположением о floor/round. Pause и time factor должен предоставлять вызывающий код. Общий timing профиль и существующие scripts не менялись.

## Частицы: зафиксированный source contract

`emitter.tcl:9`:

```tcl
class_particle 2 {0 -0.1 0.2} {0 0 0} 32 1 0 0 -1
```

В `particles` сохранены точная команда, type literal 2, две векторные группы и остальные литералы `[32,1,0,0,-1]`. Реализация частиц требует декодирования type 2 и параметров `class_particle`, их единиц, emitter transform, spawn/lifetime clock, случайности, движения, particle texture/material, blend/depth и fog policy. Число 32 не объявляется emission rate или lifetime. Эти параметры не выводятся из количества mesh frames и не заменяются придуманными Godot настройками.

## Hashes исходников

| Источник | SHA-256 |
| --- | --- |
| `3db/licht.3db` | `9e0b4ae24f844c50113089221337969e88a9601d8a0814c7168857071ab62e59` |
| `Scripts/classes/items/emitter.tcl` | `6dc7926fcb783a4c26f00f5f787d262b1b18c723d91d6d422545f086ced09590` |
| `Scripts/init/animinit.tcl` | `6851e03b0c7f2e69c6eeec6c8ba3a8c2cf46ffad0cc42ffe4957c3598c8f2f9d` |
| `Scripts/misc/animclassinit.tcl` | `bcffe05e23ba6e8acc8df55a40542984840aa5521b28569eee5abb77b1279ade` |
| `Texture/m128/Metall_Werkzeuge_a_128.tga` | `ab649e54fe5a62fafbee7c7b961f4b0cd1620ab66389173565dbb6d749975d57` |
| `../Diggles.exe` | `58a01d3d80670a6042c66a82684397c98e39c503e00a6e2c2c511f338a30ed74` |

## Проверка результата

Экспорт и `--check` завершились успешно: `NATIVE_TORCH_VISUAL_EXPORTED`, `NATIVE_TORCH_VISUAL_CHECK_OK`. JSON повторно прочитан; оба кадра сопоставлены с decoded source arrays, индексы и UV проверены, TGA перечитана с проверкой dimensions/alpha и hash. Проверка read-only выполнена сравнением bytes и mtime выходных файлов до/после `--check`. Исходный 3DB полностью прочитан: 16994/16994 bytes. Runtime визуальная интеграция остаётся работой интегратора.
