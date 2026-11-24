import sys, io, os, re
sys.path.insert(0, r'C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp')
import z31_shaders as Z
gs = Z.parse_groups()
for g in gs:
    print(g['name'], sorted(g['slots'].items()))
