import io
p = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\tools-tmp\build_matte_variant.py"
s = io.open(p, encoding="utf-8").read()
old = """    if ground_source == "meadow":
        # Земля мира за краем карты - луг оригинала: в игре он яркий,
        # кислотно-желто-зеленый (до 213,192,47 в кадре владельца)."""
new = """    if ground_source == "meadow_tile":
        # Земля мира за краем карты - луг оригинала плиткой: террасы луга
        # остаются, а растяжения в 6.5 раза нет.
        block = piece.resize((WIDTH, GROUND_ROWS * (WIDTH // meadow.width)), Image.LANCZOS)
        target = HEIGHT - HORIZON_ROW
        ground = Image.new("RGB", (WIDTH, target))
        y = 0
        while y < target:
            ground.paste(block.convert("RGB"), (0, y))
            y += block.size[1]
        ground = ground.crop((0, 0, WIDTH, target))
    elif ground_source == "meadow":
        # Земля мира за краем карты - луг оригинала: в игре он яркий,
        # кислотно-желто-зеленый (до 213,192,47 в кадре владельца)."""
assert old in s
s = s.replace(old, new)
s = s.replace('if ground_source == "meadow":\n        array = np.asarray', 'if ground_source in ("meadow", "meadow_tile"):\n        array = np.asarray')
io.open(p, "w", encoding="utf-8").write(s)
print("patched")
