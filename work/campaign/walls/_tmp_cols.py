import json, math, sys, os
import numpy as np
from PIL import Image
sys.path.insert(0, r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\walls")
import wall_screen
root=r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
s=root+r"\out\campaign-shots"
a=np.asarray(Image.open(s+r"\v106-wide.png").convert("RGB")).astype(np.float32)
b=np.asarray(Image.open(s+r"\v106-wide-novert.png").convert("RGB")).astype(np.float32)
export=np.abs(a-b).max(axis=2)>6
fr=wall_screen.wide_camera(root+r"\godot\models\native_campaign_chapter.json",(1280,720),0.29)
m=wall_screen.wall_mask(root+r"\work\campaign\walls\module_faces.json",(1280,720),fr["focus_map"],fr["distance"],0.29,fr["yaw"])
for x in (440,470,500,530):
    rows=np.where(m[:,x])[0]
    erows=np.where(export[:,x])[0]
    lum=0.299*a[:,x,0]+0.587*a[:,x,1]+0.114*a[:,x,2]
    print("column x=%d" % x)
    print("   module rows: %s" % (rows.tolist() if rows.size else "none"))
    print("   export rows: %s" % (erows.tolist() if erows.size else "none"))
    for y in range(296,330):
        print("      y=%3d lum=%6.2f module=%s export=%s" % (y, lum[y], bool(m[y,x]), bool(export[y,x])))