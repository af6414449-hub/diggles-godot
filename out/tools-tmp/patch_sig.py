import re, io, os
p = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\tools-tmp\build_matte_variant.py"
s = io.open(p, encoding="utf-8").read()
s = s.replace("def build(slice_fraction: float, strips, name: str, ground_mode: str = \"stretch\") -> str:",
              "def build(slice_fraction: float, strips, name: str, ground_mode: str = \"stretch\",\n          ground_source: str = \"tile\", ground_gain: float = 1.0) -> str:")
io.open(p, "w", encoding="utf-8").write(s)
print("patched")
