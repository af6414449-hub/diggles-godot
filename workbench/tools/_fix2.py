REPORT = r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\docs\reverse-engineering\agent-result-walkmap-performance-2026-11-19.md"
with open(REPORT, "r", encoding="utf-8", newline="") as f:
    text = f.read()
pairs = [
 ("(медиана из 3 повторов, 273 принятых удара, из них", "(медиана из 5 повторов, 273 принятых удара, из них"),
 ("`workbench/tools/walkmap_bench_compare.gd`, 3 повтора каждого варианта", "`workbench/tools/walkmap_bench_compare.gd`, 5 повторов каждого варианта"),
]
for old, new in pairs:
    assert text.count(old) == 1, (text.count(old), old)
    text = text.replace(old, new)
with open(REPORT, "w", encoding="utf-8", newline="") as f:
    f.write(text)
print("OK")