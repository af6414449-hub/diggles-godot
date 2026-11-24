from PIL import Image
p = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\backdrop\campaign_panorama.png"
im = Image.open(p)
print("matte:", im.size, im.mode)
im.convert("RGB").resize((1024, 576), Image.LANCZOS).save(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots\zz-matte.png")
