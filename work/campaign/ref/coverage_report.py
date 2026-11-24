import io, collections, os

ref = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref"

def rows(path):
    out = []
    with io.open(path, encoding="utf-8", errors="replace") as f:
        for line in f:
            line = line.rstrip("\n").rstrip("\r")
            if not line.strip():
                continue
            out.append(line.split("\t"))
    return out

st = rows(os.path.join(ref, "ghidra_structs.tsv"))
fn = rows(os.path.join(ref, "ghidra_funcs.tsv"))
lay = rows(os.path.join(ref, "struct_layouts.tsv"))

print("ghidra_structs.tsv rows:", len(st))
print("  header:", st[0])
cls_fields = collections.Counter(r[0] for r in st[1:] if r and r[0] != "class")
print("  classes:", len(cls_fields))
print("  top:", cls_fields.most_common(12))

print()
print("ghidra_funcs.tsv rows:", len(fn))
print("  header:", fn[0])
fcls = collections.Counter(r[1] for r in fn[1:] if len(r) > 1)
print("  classes:", len(fcls), " funcs:", sum(fcls.values()))
print("  top:", fcls.most_common(12))

print()
print("struct_layouts.tsv rows:", len(lay))
print("  header:", lay[0])
lcls = collections.Counter(r[0] for r in lay[1:] if r and r[0] != "class")
print("  classes:", len(lcls))
print("  top:", lcls.most_common(12))

# classes that have a layout but are not in the applied struct set
applied = set(cls_fields)
laid = set(lcls)
print()
print("layout classes NOT applied:", len(laid - applied))
print("  ", sorted(laid - applied)[:40])
print("applied classes not in layouts:", sorted(applied - laid)[:10])

# functions with no class at all
nocls = [r for r in fn[1:] if len(r) < 2 or not r[1].strip()]
print()
print("funcs rows without class:", len(nocls))

# how many functions does the whole corpus have
outdir = r"C:\diggles-ghidra\out\decomp"
allf = [f for f in os.listdir(outdir) if f.endswith(".c")]
print("total decompiled functions in corpus:", len(allf))
typed = set()
for r in fn[1:]:
    if len(r) > 1:
        typed.add(r[0].strip().lower())
print("funcs map covers", len(typed), "addresses")
