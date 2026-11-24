# -*- coding: utf-8 -*-
REPORT = r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\docs\reverse-engineering\agent-result-walkmap-performance-2026-11-19.md"
with open(REPORT, "r", encoding="utf-8", newline="") as f:
    text = f.read()
i = text.find("Разброс")
print(repr(text[i:i+240]))
j = text.find("Рекомендация")
print(repr(text[j:j+240]))
k = text.find("gate_calls` \u2014")
print(repr(text[k-2:k+160]))
