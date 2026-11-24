# -*- coding: utf-8 -*-
"""Fix the paragraph about the light of the surface of the map in the report."""
import io

PATH = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\docs\reverse-engineering\agent-result-campaign-map-2026-11-20.md"

OLD = """**Свет поверхности земли карты.** `FUN_004cca20` пишет цвет вершин полигона
прогона как одно и то же `uVar8`, собранное из трёх глобалов, единственный
писатель которых — `SetBrightness:90-93`: одна яркость на всю карту. Факелы
главы под породой и на поверхность земли карты не падают. Порт давал им падать
(`native_campaign_profile.gd:free_ground_channels` брал `_lights_near`) — тёплое
зарево уходило от главы к краю карты. Исправлено: список источников пуст."""

NEW = """**Свет поверхности земли карты.** `FUN_004cca20` пишет цвет вершин полигона
прогона как одно и то же `uVar8`, собранное из трёх глобалов, единственный
писатель которых — `SetBrightness:90-93`: яркость полигона одна. Но свет
факелов главы на поверхность земли карты **падает**: в кадре владельца земля у
главы теплее и светлее, чем у другого края карты (R−B = +16.7 против +10.8 без
света факелов и +12.4 с ним). Порт даёт факелам падать
(`native_campaign_profile.gd:free_ground_channels` берёт `_lights_near`) — и
попытка убрать их («свет только неба») была неверна: тон земли у главы уехал с
+12.4 на +10.8 и разошёлся с оригиналом."""

text = io.open(PATH, encoding="utf-8", newline="").read()
if OLD not in text:
    raise SystemExit("paragraph not found")
text = text.replace(OLD, NEW, 1)
io.open(PATH, "w", encoding="utf-8", newline="").write(text)
print("report updated")
