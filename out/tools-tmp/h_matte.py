import importlib.util
spec = importlib.util.spec_from_file_location("bmv", r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\tools-tmp\build_matte_variant.py")
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
from PIL import Image
base = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
STR = [(1, 200), (2, 235), (3, 265), (4, 298)]
# H: земля - луг оригинала, яркий (как в игре), без приглушения
m.build(1.0, STR, "zz-matte-H-meadow-bright.png", ground_mode="stretch", ground_source="meadow", ground_gain=1.45)
im = Image.open(base + r"\zz-matte-H-meadow-bright.png").convert("RGB")
im.crop((0, 320, 2048, 1152)).resize((1280, 520), Image.LANCZOS).save(base + r"\zz-matte-H-ground.png")
im.crop((0, 0, 2048, 320)).resize((1280, 200), Image.LANCZOS).save(base + r"\zz-matte-H-band.png")
print("ok")
