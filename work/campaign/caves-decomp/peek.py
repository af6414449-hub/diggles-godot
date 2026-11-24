import re
f = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp\report.md"
text = open(f, "rb").read().decode("utf-8-sig")
for i, l in enumerate(text.splitlines(), 1):
    if "иначе если" in l or ("11" in l and "сосед" in l and "фильтр" not in l):
        print(f"{i}: {l!r}")
