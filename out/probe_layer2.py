import json, os
from collections import Counter
ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
ch = json.load(open(os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json"), encoding="utf-8"))
layer2 = ch.get("layer2", {})
words = Counter(layer2.values())
print("cells with layer2 entries:", len(layer2), "of", len(ch["cells"]))
print("distinct layer2 words:", len(words), "top:", words.most_common(6))
dec = ch.get("layer2_decoded", {})
print("layer2_decoded keys:", list(dec.keys())[:8])
for k in list(dec.keys())[:4]:
    print("  word", k, "->", dec[k][:3])
atlas = ch.get("atlas", {})
print("atlas file:", atlas.get("file"), "size:", atlas.get("size"), "slots:", len(atlas.get("slots", {})))
print("detail names:", list(atlas.get("slots", {}).keys())[:20])
