import importlib.util
spec = importlib.util.spec_from_file_location("bmv", r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\tools-tmp\build_matte_variant.py")
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
from PIL import Image
# D3 с полосой по горизонту + земля плиткой
m.build(1.0, [(1, 200), (2, 235), (3, 265), (4, 298)], "zz-matte-F-final.png", ground_mode="tile")
WINDOW_TOP = 320 - int(0.151*720)
im = Image.open(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots\zz-matte-F-final.png").convert("RGB")
im.crop((0, WINDOW_TOP, 2048, WINDOW_TOP+720)).resize((1280, 450), Image.LANCZOS).save(
    r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots\zz-matte-F-window.png")
print("ok")
