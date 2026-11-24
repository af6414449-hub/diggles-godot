# Задача агенту: регрессия освещения новых факелов

## Симптом

В живом Godot-порте Diggles автоматические факелы появляются в вырытых далеко
от стартовой пещеры коридорах, однако terrain вокруг них остаётся тёмным.
Визуально корректно выглядят только первые один-два факела. Скриншот наблюдения
передан в чат 2026-11-19.

Основной проект:
`C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles`

## Важный текущий контекст

Буквально перед этой задачей в живом проекте был изменён runtime слой света:

- `godot/shaders/native_terrain_pipeline.gdshader`:
  `dynamic_torch_position_range[32]`, `dynamic_torch_color[32]`; вклад
  перенесён из `fragment()` в `vertex()`;
- `godot/scripts/native_scene_profile.gd`:
  `MAX_DYNAMIC_TORCHES=32`, хранится `dynamic_torch_lights`, а новый
  `terrain_material()` вызывает `_apply_dynamic_torch_uniforms()`;
- `godot/scripts/multiplayer_test.gd`:
  автоматические факелы всё ещё регистрируются в `source_profile.terrain_lights`,
  а `_terrain_baked_lights()` исключает их из статической базы;
- `godot/tools/automatic_torch_runtime_self_test.gd` проверяет один и девять
  источников, но не доказывает, что освещение видно на реальном новом дальнем
  terrain-чанке в кадре.

Не предполагать, что эти изменения верны только потому, что self-test зелёный.

## Цель

Найти точную причину, почему третий и последующие факелы не освещают terrain в
реальной сцене, и подготовить минимальный, проверяемый патч. Нужны данные, а не
визуальные догадки.

## Обязательная процедура

1. Не редактировать живой проект. Работать в собственном дереве/копии.
2. Воспроизвести проблему на обычной сцене или через детерминированный test:
   минимум 3 факела в разных вырытых чанках, один далеко от стартовой области.
3. Добавить временную диагностическую инструментализацию в своей копии, которая
   для каждого факела и освещаемого terrain mesh выводит:
   - ID факела, source/render позицию, радиус;
   - `dynamic_torch_count` и первые подходящие uniform-слоты материала;
   - ключ terrain mesh, shader/material RID или идентичность материала;
   - одну исходную вершину рядом с факелом и её vertex-stage source coordinates;
   - подтверждение, что material действительно использует
     `native_terrain_pipeline.gdshader`, а не legacy `native_terrain_detail`.
4. Отдельно проверить гипотезы:
   - материал нового чанка не получает активные uniform-ы;
   - `ShaderMaterial` общий, но uniform изменён не у того экземпляра;
   - shader vertex работает в local/world пространстве, а light в другом;
   - факел есть в runtime-списке, но отсекается/перезаписывается;
   - renderer/Godot не применяет uniform array после hot reload;
   - CPU-тест проходит, но shader-value/рендер не меняется.
5. Сверить формулу и координаты с оригинальными доказательствами:
   `data/Scripts/classes/items/emitter.tcl`, `data/sphere.dat`,
   `docs/reverse-engineering/agent-result-lighting-architecture-2026-11-19.md`.
6. Подготовить минимальный патч только если причина доказана. Не менять walkmap,
   хомяков, APK/экспорт или художественное освещение целиком.
7. Добавить regression self-test, который не может пройти, если третий далёкий
   факел существует, но реальный material/шейдер не получает его света.

## Что прислать

Создай в основном рабочем каталоге только:

`C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\docs\reverse-engineering\agent-result-runtime-torch-regression-2026-11-19.md`

В отчёте обязательно:

- воспроизведение и лог до/после;
- одна доказанная первопричина с file:line;
- список отвергнутых гипотез;
- точный малый unified diff или готовый патч в своём рабочем дереве;
- команды тестов;
- риски merge относительно текущих файлов.

Финальный блок:

```text
INTEGRATION_HANDOFF
root_cause: <одно предложение>
evidence: <file:line и наблюдение>
safe_patch: <файлы/функции>
regression_test: <команда и что доказывает>
do_not_touch: walkmap, hamster, APK/export
```
