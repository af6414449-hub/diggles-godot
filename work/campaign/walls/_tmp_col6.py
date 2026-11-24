import numpy as np, os, sys
from PIL import Image
sys.path.insert(0, r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\walls")
import wall_screen
root=r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
s=root+r"\out\campaign-shots"
a=np.asarray(Image.open(os.path.join(s,"v110-wide.png")).convert("RGB")).astype(np.float32)
fr=wall_screen.wide_camera(root+r"\godot\models\native_campaign_chapter.json",(1280,720),0.29)
m=wall_screen.wall_mask(root+r"\work\campaign\walls\module_faces.json",(1280,720),fr["focus_map"],fr["distance"],0.29,fr["yaw"])
def lum(x,y): return 0.299*a[y,x,0]+0.587*a[y,x,1]+0.114*a[y,x,2]
for x in (470,500,530,560):
    print("column x=%d" % x)
    for y in range(300,316):
        print("   y=%3d lum %6.2f  module=%s" % (y, lum(x,y), bool(m[y,x])))