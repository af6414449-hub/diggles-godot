import json
root=r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
d=json.load(open(root+r"\work\campaign\walls\module_faces.json",encoding="utf-8"))
for face in d["faces"]:
    if face["cell"]==[127,84]:
        print("cell", face["cell"], "side", face["side"])
        for c in face["corners"]:
            print("   corner (%.2f, %.2f, %.2f)" % (c[0],c[1],c[2]))
print("--- all faces of the cells 127,84 / 127,85 / 127,86 ---")
for face in d["faces"]:
    if face["cell"][0]==127 and face["cell"][1] in (84,85,86):
        print("cell", face["cell"], "side", face["side"], "corners", [(round(c[0],2),round(c[1],2),round(c[2],2)) for c in face["corners"]])