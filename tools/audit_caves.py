# -*- coding: utf-8 -*-
"""Аудит дефектов генерации пещер главы кампании.

Считает по сырой выгрузке главы то, что видно на экране:

  1. клетки без плоской поверхности (только наклонные треугольники) — из-за них
     модуль стен не может построить грань ни у самой клетки, ни у соседей,
     и в породе получается дыра;
  2. рёбра стены, на которых грань построена быть не может (дыры в стене);
  3. клинья — наклонные треугольники с диагональным нижним ребром: угол
     выработки в оригинале это две вертикальные плоскости, а не клин;
  4. связность выработок: сколько изолированных карманов;
  5. декор, который стоит выше поверхности своей клетки.

Запуск:
    python tools/audit_caves.py [godot/models/native_campaign_chapter.json]
"""
from __future__ import annotations

import json
import sys
from collections import Counter
from pathlib import Path

EPS = 1e-4
ROOT = Path(__file__).resolve().parent.parent
DEFAULT_CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"
DEFAULT_MODELS = ROOT / "godot" / "models" / "native_campaign_models.json"

DECOR_PREFIXES = (
    "Dummy_Moos", "Dummy_Liane", "Dummy_Grass", "Dummy_Wurzel", "Dummy_Stein",
)


def load_cells(chapter_path: Path):
    """Плоские уровни и наклонные треугольники каждой клетки главы."""
    data = json.loads(chapter_path.read_text(encoding="utf-8"))
    meshes = data["meshes"]
    flat_levels: dict[tuple[int, int], set[float]] = {}
    wedges: dict[tuple[int, int], int] = {}
    for entry in data["cells"]:
        cell = (int(entry["x"]), int(entry["y"]))
        levels: set[float] = set()
        wedge_count = 0
        for part in meshes[str(int(entry["block"]))]:
            values = part["vertices"]
            indices = part["indices"]
            for start in range(0, len(indices), 3):
                points = []
                for corner in range(3):
                    offset = int(indices[start + corner]) * 5
                    points.append((values[offset], values[offset + 1], values[offset + 2]))
                heights = [point[2] for point in points]
                if max(heights) - min(heights) <= EPS:
                    levels.add(round(heights[0], 3))
                    continue
                low = min(heights)
                low_points = [p for p in points if abs(p[2] - low) <= EPS]
                if len(low_points) == 2:
                    a, b = low_points
                    if abs(a[0] - b[0]) > EPS and abs(a[1] - b[1]) > EPS:
                        wedge_count += 1
        flat_levels[cell] = levels
        wedges[cell] = wedge_count
    return data, flat_levels, wedges


def neighbour(cell, side):
    x, y = cell
    return ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1))[side]


def main() -> int:
    chapter_path = Path(sys.argv[1]) if len(sys.argv) > 1 else DEFAULT_CHAPTER
    data, flat_levels, wedges = load_cells(chapter_path)
    surface = {cell: (max(levels) if levels else None) for cell, levels in flat_levels.items()}
    cells = list(surface)

    zero_flat = [cell for cell in cells if not flat_levels[cell]]
    print("=== 1. клетки без плоской поверхности ===")
    print(f"клеток главы: {len(cells)}")
    print(f"клеток без плоского участка (только наклон): {len(zero_flat)}")
    zero_set = set(zero_flat)

    print()
    print("=== 2. рёбра стены, на которых плоскими профилями грань построена быть не может ===")
    print("ВНИМАНИЕ: это метрика СЫРОЙ ВЫГРУЗКИ, а не геометрии модуля стен.")
    print("Она меряет, у скольких клеток нет плоского участка и сколько рёбер стены")
    print("из-за этого не может закрыть пара плоских профилей. Правка модуля стен")
    print("(v5, border_quads) закрывает такие рёбра по профилю поверхности обеих сторон,")
    print("поэтому эти числа НЕ МЕНЯЮТСЯ после правки — это свойство выгрузки.")
    print("Фактические дыры меряют:")
    print("  work/campaign/walls/border_check.py  — независимая реализация правила")
    print("  godot/tools/campaign_wall_audit.gd     — аудит граней самого модуля")
    blocked = 0
    blocked_detail = Counter()
    for cell in cells:
        if not flat_levels[cell]:
            continue
        here = surface[cell]
        for side in range(4):
            other = neighbour(cell, side)
            if other not in surface:
                continue
            if flat_levels[other]:
                continue
            blocked += 1
            blocked_detail[other] += 1
    print(f"потенциально незакрытые рёбра в выгрузке: {blocked}")
    print(f"из них клеток-источников: {len(blocked_detail)}")
    if blocked_detail:
        worst = blocked_detail.most_common(5)
        print("  самые частые:", ", ".join(f"{c}={n}" for c, n in worst))

    print()
    print("=== 2b. вертикальные грани в выгрузке, по плоскостям ===")
    print("Ключевой факт: в выгрузке вертикальные грани есть ТОЛЬКО в плоскостях")
    print("y = const, а в плоскостях x = const их НОЛЬ. Поэтому на границе, где скат")
    print("сходит к краю клетки в направлении x, грань не несёт ни экспорт, ни пара")
    print("плоских профилей модуля.")
    planes = Counter()
    for entry in data["cells"]:
        for part in data["meshes"][str(int(entry["block"]))]:
            values = part["vertices"]
            indices = part["indices"]
            for start in range(0, len(indices), 3):
                points = []
                for corner in range(3):
                    offset = int(indices[start + corner]) * 5
                    points.append((values[offset], values[offset + 1], values[offset + 2]))
                heights = [point[2] for point in points]
                if max(heights) - min(heights) <= EPS:
                    continue
                xs = {round(point[0], 4) for point in points}
                ys = {round(point[1], 4) for point in points}
                if len(xs) == 1 and len(ys) == 1:
                    continue
                if len(xs) == 1:
                    planes["x = const"] += 1
                elif len(ys) == 1:
                    planes["y = const"] += 1
                else:
                    planes["наклон (скат)"] += 1
    for name, count in planes.most_common():
        print(f"  {name:22s} {count}")

    print()
    print("=== 3. клинья (диагональное нижнее ребро на наклонном треугольнике) ===")
    total_wedges = sum(wedges.values())
    cells_with_wedges = sum(1 for value in wedges.values() if value)
    print(f"клиньев: {total_wedges} в {cells_with_wedges} клетках")
    print("в оригинале угол выработки — две вертикальные плоскости (x=const и y=const),")
    print("а не самостоятельная наклонная грань: клин должен быть заменён двумя плоскостями.")

    print()
    print("=== 4. связность выработок ===")
    top = max((v for v in surface.values() if v is not None), default=0.0)
    low = {cell for cell in cells if surface[cell] is not None and surface[cell] < top - EPS}
    seen: set[tuple[int, int]] = set()
    components = []
    for cell in low:
        if cell in seen:
            continue
        stack = [cell]
        seen.add(cell)
        part = []
        while stack:
            current = stack.pop()
            part.append(current)
            for side in range(4):
                other = neighbour(current, side)
                if other in low and other not in seen:
                    seen.add(other)
                    stack.append(other)
        components.append(part)
    components.sort(key=len, reverse=True)
    print(f"выработок (поверхность ниже {top}): {len(low)} клеток")
    print(f"компонент связности: {len(components)}")
    print(f"  крупнейшие: {[len(c) for c in components[:10]]}")
    print(f"  одиночных клеток: {sum(1 for c in components if len(c) == 1)}")
    print(f"  карманов 2..9 клеток: {sum(1 for c in components if 2 <= len(c) <= 9)}")

    models_path = DEFAULT_MODELS
    if not models_path.is_file():
        print()
        print("=== 5. декор ===")
        print("нет файла моделей:", models_path)
        return 0
    models = json.loads(models_path.read_text(encoding="utf-8"))
    total = Counter()
    above = Counter()
    for placement in models.get("placements", []):
        name = str(placement["class"])
        if not name.startswith(DECOR_PREFIXES):
            continue
        total[name] += 1
        cell = (int(placement["x"]), int(placement["y"]))
        ground = surface.get(cell)
        if ground is None:
            continue
        if float(placement.get("z", 0.0)) > ground + 0.51:
            above[name] += 1
    print()
    print("=== 5. декор выше поверхности своей клетки ===")
    print(f"всего объектов декора: {sum(total.values())}")
    print(f"выше поверхности клетки больше чем на 0.5: {sum(above.values())}")
    for name, count in above.most_common(10):
        print(f"  {name:32s} {count}/{total[name]}")

    print()
    print("=== сводка ===")
    print(f"дыры в породе (рёбер без грани): {blocked}")
    print(f"клинья угла выработки: {total_wedges}")
    print(f"изолированные карманы выработок: "
          f"{sum(1 for c in components if len(c) <= 9)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
