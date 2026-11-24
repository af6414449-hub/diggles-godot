"""Сверка: полный прогон по hol_raetsel_001.pmp + клетка (15,18)."""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import z16_chapter_test as T  # noqa: E402  (переиспользуем parse_pmp/predict/grid_from_template)

GAME = T.GAME
p = os.path.join(GAME, "Templates", "hol_raetsel_001.pmp")
if not os.path.exists(p):
    p = os.path.join(GAME, "data", "templates", "hol_raetsel_001.pmp")
W, H, mat, blocks, rle = T.parse_pmp(p)
g, gw, gx0, gy0 = T.grid_from_template(W, H, blocks)
pred = T.predict(W, H, mat, blocks, g, gw, gx0, gy0)
same = sum(1 for a, b in zip(rle, pred) if a == b)
print(f"{os.path.basename(p)} {W}x{H}: совпадение {same}/{len(rle)} = {100.0*same/len(rle):.3f}%")
idx = 18 * W + 15
print("RLE клетки (15,18):", sorted(T.Counter(rle[idx*64:(idx+1)*64]).items()))
print("пред клетки (15,18):", sorted(T.Counter(pred[idx*64:(idx+1)*64]).items()))
for r in range(8):
    print("  ", " ".join(f"{rle[idx*64+r*8+c]:3d}" for c in range(8)), "  |  ",
          " ".join(f"{pred[idx*64+r*8+c]:3d}" for c in range(8)))
