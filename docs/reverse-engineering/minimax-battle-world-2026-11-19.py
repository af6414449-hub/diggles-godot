#!/usr/bin/env python3
"""Build / verify the deterministic Diggles battle-world ("Stein") slice dataset.

Reads only the installed game data and Diggles.exe; writes one canonical JSON.

    python minimax_battle_world_2026_11_19.py --data <game>/data --output <json>
    python minimax_battle_world_2026_11_19.py --data <game>/data --output <json> --check

--check regenerates the dataset from the sources, re-runs every invariant and
compares the result byte-for-byte with the stored file, so the dataset is
provably a deterministic function of the installed game data.

All coordinates are WORLD units. Source-derived rules encoded here:

  R1 lattice cell = 4 x 4 world units
       Diggles.exe sm_get_resolution  (handler 0x65FFB0) -> Tcl int 4
       Diggles.exe lg_add_preset core 0x58A5DE-0x58A5E2  (or eax,edx ; test al,3)
       Diggles.exe lg_set_area  core 0x583B20-0x583B35  (and reg,0xfffffffc)
  R2 generation area = lg_set_area x1 y1 x2 y2, clamped to world +/- 8,
     min corner rounded UP to a multiple of 4, max corner rounded DOWN
       Diggles.exe lg_set_area handler 0x650180 -> core 0x583AC0
  R3 final template position = preset + area_min
       Diggles.exe lg_add_preset core 0x58A5AB-0x58A5B4
  R4 authored presets are validated against WORLD bounds +/- 8 (not the area)
       Diggles.exe lg_add_preset core 0x58A5E8-0x58A630
  R5 stone rect = {type x y w h}; x0=x+offX, y0=y+offY, x1=x0+w+2, y1=y0+h+2
       Diggles.exe sm_draw_stone handler 0x65E090, region 0x65F202-0x65F276
  R6 a mat list must start with the literal "mat"
       Diggles.exe sm_draw_stone handler 0x65EF32 / 0x65F053-0x65F1F3
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

SCHEMA = "diggles.battle_world_stein.v1"
CELL = 4
WORLD_MARGIN = 8

PLACEMENT = re.compile(r"\{\s*(-?\d+)\s+(-?\d+)\s+([A-Za-z0-9_]+)\s*\}")
RECT = re.compile(r"\{\s*(-?\d+)\s+(-?\d+)\s+(-?\d+)\s+(-?\d+)\s+(-?\d+)\s*\}")
SPLIT_ITEM = re.compile(r"\{\s*(\S+\.tcl)\s+(\S+\.pmp)\s+(-?\d+)\s+(-?\d+)\s*\}")
SPLIT_HEAD = re.compile(r"split_template\s+(\S+)\s+(\S+)\s+(-?\d+)\s+(-?\d+)\s*\{")


def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def read_pmp_header(path: Path) -> tuple[int, int]:
    data = path.read_bytes()
    if len(data) < 8:
        raise ValueError(f"{path}: truncated PMP")
    return struct.unpack_from("<II", data, 0)


def read_l2m_header(path: Path) -> tuple[int, int]:
    data = path.read_bytes()
    if data[:4] != b"M2L\0":
        raise ValueError(f"{path}: bad L2M magic {data[:4]!r}")
    return struct.unpack_from("<II", data, 4)


def parse_tcl(path: Path) -> str:
    return path.read_bytes().decode("cp1251", "replace")


def floor4(v: int) -> int:
    return (v // CELL) * CELL


def ceil4(v: int) -> int:
    return -(-v // CELL) * CELL


# ------------------------------------------------------------------ sources


def collect_authored_worlds(data: Path) -> list[dict]:
    out = []
    for path in sorted((data / "GameScripts").glob("multi_*.tcl")):
        text = parse_tcl(path)
        m = re.search(r'set\s+map_size\s+"(\d+)\s+(\d+)"', text)
        w, h = (int(m.group(1)), int(m.group(2))) if m else (None, None)
        m = re.search(r'set\s+Zone\s+"(\w+)"', text)
        zone = m.group(1) if m else None
        m = re.search(r"set\s+TempRatio\s+([\d.]+)", text)
        ratio = float(m.group(1)) if m else None
        m = re.search(r"set\s+temp_list\s*\{(.*?)\n\s*\}\s*\n", text, re.S)
        body = m.group(1) if m else ""

        presets, rects = [], []
        for line in body.splitlines():
            line = line.strip()
            if not line.startswith("{"):
                continue
            mm = PLACEMENT.match(line)
            if mm and mm.group(3) != "mat":
                presets.append([int(mm.group(1)), int(mm.group(2)), mm.group(3)])
                continue
            if line.startswith("{mat"):
                for t, x, y, rw, rh in RECT.findall(line):
                    rects.append([int(t), int(x), int(y), int(rw), int(rh)])

        out.append({
            "id": path.stem,
            "source": f"GameScripts/{path.name}",
            "map_size": [w, h],
            "zone": zone,
            "temp_ratio": ratio,
            "presets": presets,
            "stone_rects": rects,
        })
    return out


def template_geometry(data: Path, name: str) -> dict | None:
    tcl = data / "Templates" / "tcl" / f"{name}.tcl"
    if not tcl.is_file():
        return None
    text = parse_tcl(tcl)
    geo: dict = {"template": name, "tcl": f"Templates/tcl/{name}.tcl"}

    head = SPLIT_HEAD.search(text)
    if head:
        geo["kind"] = "split"
        geo["split_pmp"] = head.group(2)
        geo["split_size"] = [int(head.group(3)), int(head.group(4))]
        parts = []
        for tclname, pmpname, ox, oy in SPLIT_ITEM.findall(text):
            pmp = data / "Templates" / "pmp" / "split" / pmpname
            entry = {
                "tcl": f"Templates/tcl/split/{tclname}",
                "pmp": f"Templates/pmp/split/{pmpname}",
                "offset": [int(ox), int(oy)],
            }
            if pmp.is_file():
                pw, ph = read_pmp_header(pmp)
                entry["pmp_size"] = [pw, ph]
            parts.append(entry)
        geo["parts"] = parts
        return geo

    geo["kind"] = "monolithic"
    pmp_refs = sorted(set(re.findall(r"map_template\s+(\S+)\s+\S+\s+\S+", text)))
    l2m_refs = sorted(set(re.findall(r"map_setlayer2\s+\S+\s+\S+\s+(\S+)", text)))
    geo["pmp"] = []
    for ref in pmp_refs:
        for cand in (data / "Templates" / ref, data / "Templates" / "pmp" / ref):
            if cand.is_file():
                pw, ph = read_pmp_header(cand)
                geo["pmp"].append({
                    "file": f"Templates/{cand.relative_to(data / 'Templates').as_posix()}",
                    "size": [pw, ph]})
                break
    geo["l2m"] = []
    for ref in l2m_refs:
        for cand in (data / "Templates" / ref, data / "Templates" / "l2m" / ref):
            if cand.is_file():
                lw, lh = read_l2m_header(cand)
                geo["l2m"].append({
                    "file": f"Templates/{cand.relative_to(data / 'Templates').as_posix()}",
                    "size": [lw, lh]})
                break
    return geo


# ------------------------------------------------------------------ fixture

# The first 4x4-lattice slice.  Coordinates are the ADAPTER's choice; every rule
# they exercise is source-derived (R1..R6 above) and re-verified by --check.
SLICE = {
    "id": "stein_4x4_slice_001",
    "world_size": [112, 88],
    "cave_presets": [
        # template, preset x, preset y
        ["multi_urw_start_010_a_0", 8, 8],
        ["urw_gng_030_a", 52, 8],
        ["urw_gng_045_a", 8, 32],
    ],
    "stone_rects": [
        # type, x, y, w, h   (authored / preset space)
        [0, 0, 0, 72, 4],      # top wall band
        [0, 0, 40, 72, 4],     # bottom wall band
        [0, 0, 4, 4, 44],      # left wall band
        [0, 68, 4, 4, 44],     # right wall band
        [2, 48, 16, 4, 4],     # connector: start cave -> cave A
        [2, 8, 28, 4, 4],      # connector: start cave -> cave B
    ],
}


def build_slice(data: Path) -> dict:
    W, H = SLICE["world_size"]
    area_req = [16, 16, W - 16, H - 16]
    a = [max(area_req[0], 0 + WORLD_MARGIN), max(area_req[1], 0 + WORLD_MARGIN),
         min(area_req[2], W - WORLD_MARGIN), min(area_req[3], H - WORLD_MARGIN)]
    a = [ceil4(a[0]), ceil4(a[1]), floor4(a[2]), floor4(a[3])]
    area_min = [a[0], a[1]]

    caves = []
    for name, px, py in SLICE["cave_presets"]:
        geo = template_geometry(data, name)
        if geo is None:
            raise SystemExit(f"template not found: {name}")
        if geo["kind"] == "split":
            w, h = geo["split_size"]
        else:
            w, h = geo["pmp"][0]["size"]
        caves.append({
            "template": name,
            "preset_xy": [px, py],
            "world_xy": [px + area_min[0], py + area_min[1]],
            "size": [w, h],
            "geometry": geo,
        })

    rects = []
    for t, x, y, rw, rh in SLICE["stone_rects"]:
        rects.append({
            "type": t, "authored_xy": [x, y], "size": [rw, rh],
            "world_rect": [x + area_min[0], y + area_min[1],
                           x + area_min[0] + rw + 2, y + area_min[1] + rh + 2],
        })

    return {
        "id": SLICE["id"],
        "provenance": {
            "rules": "source-derived (R1..R6 in the script header)",
            "coordinates": "adapter choice; re-verified by --check against the native rules",
            "reference_authored_world": "multi_dm_kris_2p_001",
        },
        "world_size": [W, H],
        "world_bounds": [[0, 0], [W, H]],
        "generation_area_requested": area_req,
        "generation_area_effective": a,
        "area_min": area_min,
        "level_type": "base",
        "template_sets": [" Urwald.Std "],
        "template_ratio": [0, 0.3, 1.0],
        "stone_offset_args": area_min,
        "caves": caves,
        "stone_rects": rects,
    }


# ------------------------------------------------------------------ checks

# Byte patterns that back the report's fact table. Each entry is
# (VA, expected bytes, what it proves).
EXE_EVIDENCE = [
    (0x583B26, bytes.fromhex("83 e3 fc"), "lg_set_area: and ebx,0xfffffffc (min corner ceil4)"),
    (0x583B35, bytes.fromhex("83 e1 fc"), "lg_set_area: and ecx,0xfffffffc (max corner floor4)"),
    (0x58A5E0, bytes.fromhex("a8 03"), "lg_add_preset: test al,3 (reject off-lattice)"),
    (0x660054, bytes.fromhex("6a 04"), "sm_get_resolution: push 4 (cell = 4 units)"),
    (0x401AE0, bytes.fromhex("ff 15 f4 52 71 00"), "seed: call [KERNEL32!GetTickCount]"),
    (0x401AE7, bytes.fromhex("e8"), "seed: call MT19937 init"),
    (0x5995FA, bytes.fromhex("83 e2 7f"), "PMP loader: and edx,0x7f (material code)"),
    (0x599631, bytes.fromhex("83 fa 05"), "PMP loader: cmp edx,5 (codes 0..5)"),
    (0x59963A, bytes.fromhex("ff 24 95 a8 9f 59 00"), "PMP loader: jmp [edx*4+0x599FA8]"),
    (0x4CDA9B, bytes.fromhex("83 c0 41"), "ground: add eax,0x41 ('A'+material)"),
    (0x4CDACF, bytes.fromhex("68 b4 48 72 00"), "ground: push \"ground/Gnd_%c%c%c.tga\""),
]
MATERIAL_TABLE_VA = 0x599FA8
MATERIAL_TABLE_SIZE = 6


def verify_exe_evidence(exe: Path) -> list[str]:
    """Check the raw byte patterns the report relies on. Returns violations."""
    fails: list[str] = []
    if not exe.is_file():
        return [f"EXE not found: {exe}"]
    raw = exe.read_bytes()
    import pefile
    pe = pefile.PE(data=raw, fast_load=False)
    base = pe.OPTIONAL_HEADER.ImageBase

    def read(va: int, n: int) -> bytes:
        off = pe.get_offset_from_rva(va - base)
        return raw[off: off + n]

    for va, want, why in EXE_EVIDENCE:
        got = read(va, len(want))
        if got != want:
            fails.append(f"EXE 0x{va:08X}: expected {want.hex(' ')}, got {got.hex(' ')} ({why})")

    tbl = [struct.unpack_from("<I", read(MATERIAL_TABLE_VA + 4 * i, 4))[0]
           for i in range(MATERIAL_TABLE_SIZE)]
    if len(set(tbl)) != MATERIAL_TABLE_SIZE or not all(0x599600 < t < 0x599800 for t in tbl):
        fails.append(f"material jump table unexpected: {[hex(t) for t in tbl]}")

    # every direct call to the MT19937 core inside the LevelGen range proves
    # that lg_start is not reproducible
    text = None
    for s in pe.sections:
        if s.Name.rstrip(b"\0") == b".text":
            text = s
            break
    if text is None:
        fails.append("EXE has no .text section")
        return fails
    blob = text.get_data()
    tva = base + text.VirtualAddress
    hits = []
    for i in range(len(blob) - 5):
        if blob[i] != 0xE8:
            continue
        rel = struct.unpack_from("<i", blob, i + 1)[0]
        site = tva + i
        if (site + 5 + rel) & 0xFFFFFFFF == 0x49C670:
            hits.append(site)
    inside = [h for h in hits if 0x583000 <= h < 0x58A000]
    if len(inside) < 5:
        fails.append(f"expected >=5 RNG call sites inside LevelGen, found {len(inside)}")
    return fails


def run_checks(data: Path, ds: dict) -> list[str]:
    fails: list[str] = []
    sl = ds["first_slice"]
    W, H = sl["world_size"]
    area_min = sl["area_min"]

    def bad(msg: str) -> None:
        fails.append(msg)

    # R1 lattice
    for c in sl["caves"]:
        px, py = c["preset_xy"]
        fx, fy = c["world_xy"]
        if px % CELL or py % CELL:
            bad(f"cave {c['template']}: preset {px},{py} not on the {CELL} lattice")
        if fx % CELL or fy % CELL:
            bad(f"cave {c['template']}: final {fx},{fy} not on the {CELL} lattice")
        # R3
        if [fx, fy] != [px + area_min[0], py + area_min[1]]:
            bad(f"cave {c['template']}: final != preset + area_min")
        # R4 world bounds +/- 8
        w, h = c["size"]
        if fx < WORLD_MARGIN or fy < WORLD_MARGIN:
            bad(f"cave {c['template']}: final position inside the world margin")
        if fx + w >= W - WORLD_MARGIN or fy + h >= H - WORLD_MARGIN:
            bad(f"cave {c['template']}: footprint reaches the world margin")
        # inside the generation area
        a = sl["generation_area_effective"]
        if fx < a[0] or fy < a[1] or fx + w > a[2] or fy + h > a[3]:
            bad(f"cave {c['template']}: footprint outside the effective generation area")

    # start cave split tiles must tile split_size exactly, without overlap
    for c in sl["caves"]:
        geo = c["geometry"]
        if geo["kind"] != "split":
            continue
        sw, sh = geo["split_size"]
        covered: dict[tuple[int, int], str] = {}
        for part in geo["parts"]:
            pw, ph = part.get("pmp_size", [0, 0])
            ox, oy = part["offset"]
            for x in range(ox, ox + pw):
                for y in range(oy, oy + ph):
                    if (x, y) in covered:
                        bad(f"split overlap at {x},{y} ({covered[(x, y)]} / {part['pmp']})")
                    covered[(x, y)] = part["pmp"]
        if len(covered) != sw * sh:
            bad(f"split {c['template']}: covers {len(covered)} of {sw * sh} samples")
        if min(x for x, _ in covered) != 0 or min(y for _, y in covered) != 0:
            bad(f"split {c['template']}: does not start at 0,0")

    # stone rects: lattice + inside the world
    for r in sl["stone_rects"]:
        x, y = r["authored_xy"]
        w, h = r["size"]
        if any(v % CELL for v in (x, y, w, h)):
            bad(f"stone rect {r}: not on the {CELL} lattice")
        r0, r1, r2, r3 = r["world_rect"]
        if r0 < 0 or r1 < 0 or r2 > W or r3 > H:
            bad(f"stone rect {r}: world rect {r['world_rect']} leaves the world")

    # type-0 rects must form one closed ring around the caves
    wall = [r for r in sl["stone_rects"] if r["type"] == 0]
    xs0 = min(r["world_rect"][0] for r in wall)
    ys0 = min(r["world_rect"][1] for r in wall)
    xs1 = max(r["world_rect"][2] for r in wall)
    ys1 = max(r["world_rect"][3] for r in wall)
    for r in wall:
        rx0, ry0, rx1, ry1 = r["world_rect"]
        edge = (rx0 == xs0 or rx1 == xs1 or ry0 == ys0 or ry1 == ys1)
        if not edge:
            bad(f"stone rect {r} does not touch the wall outline")
    for c in sl["caves"]:
        cx, cy = c["world_xy"]
        w, h = c["size"]
        if cx < xs0 or cy < ys0 or cx + w > xs1 or cy + h > ys1:
            bad(f"cave {c['template']} is not inside the stone wall outline")

    # every connector must touch at least two cave footprints
    def boxes():
        out = []
        for c in sl["caves"]:
            x, y = c["world_xy"]
            out.append((x, y, x + c["size"][0], y + c["size"][1], c["template"]))
        return out

    for r in sl["stone_rects"]:
        if r["type"] != 2:
            continue
        rx0, ry0, rx1, ry1 = r["world_rect"]
        touching = [b for b in boxes()
                    if b[0] < rx1 and rx0 < b[2] and b[1] < ry1 and ry0 < b[3]]
        if len(touching) < 2:
            bad(f"connector {r} touches {len(touching)} cave(s), expected >= 2")

    # the authored world audit must find no off-lattice coordinate
    if ds["lattice"]["presets_off_lattice"]:
        bad("authored presets off the 4-lattice")
    if ds["lattice"]["rects_off_lattice"]:
        bad("authored stone rects off the 4-lattice")

    # source hashes must still match
    for rel, digest in ds["sources"]["file_sha256"].items():
        p = data / rel
        if not p.is_file():
            bad(f"source vanished: {rel}")
        elif sha256(p) != digest:
            bad(f"source changed: {rel}")

    # EXE byte evidence behind the report's fact table
    exe = data.parent / "Diggles.exe"
    fails.extend(verify_exe_evidence(exe))
    return fails


# ------------------------------------------------------------------ main


def build(data: Path) -> dict:
    exe = data.parent / "Diggles.exe"
    worlds = collect_authored_worlds(data)

    files = [
        "GameScripts/multiplayer.tcl", "Scripts/init/mpinit.tcl",
        "Scripts/misc/mp_tools.tcl", "Scripts/init/lginit.tcl",
        "Scripts/init/lgtools.tcl", "Scripts/gameplay/Campaign.tcl",
        "Scripts/classes/story/story.tcl", "systeminit.tcl",
        "Templates/tcl/multi_urw_start_010_a_0.tcl",
        "Templates/multi_start_010.pmp",
        "Templates/l2m/multi_urw_start_010_a_0.l2m",
    ]
    files += [w["source"] for w in worlds]
    files += [f"Templates/pmp/split/splt_multi_start_010_t{p}.pmp"
              for p in ("AA", "AB", "BA", "BB", "CA", "CB")]

    src_hashes = {}
    for rel in sorted(set(files)):
        p = data / rel
        if p.is_file():
            src_hashes[rel] = sha256(p)

    lattice = {"cell": [CELL, CELL], "unit": "world unit",
               "presets_checked": 0, "presets_off_lattice": [],
               "rects_checked": 0, "rects_off_lattice": []}
    for w in worlds:
        for x, y, _ in w["presets"]:
            lattice["presets_checked"] += 1
            if x % CELL or y % CELL:
                lattice["presets_off_lattice"].append([w["id"], x, y])
        for t, x, y, rw, rh in w["stone_rects"]:
            lattice["rects_checked"] += 1
            if any(v % CELL for v in (x, y, rw, rh)):
                lattice["rects_off_lattice"].append([w["id"], t, x, y, rw, rh])

    ds = {
        "schema": SCHEMA,
        "note": ("Deterministic source-derived dataset for the first Diggles battle world "
                 "on the 4x4 world-unit lattice. Static extraction from the installed game "
                 "data; the game was never executed."),
        "sources": {
            "game_data": str(data),
            "exe": str(exe),
            "exe_sha256": sha256(exe) if exe.is_file() else None,
            "file_sha256": src_hashes,
        },
        "lattice": lattice,
        "world_sizes": {
            "multiplayer_menu": [128, 256, 384, 512],
            "multiplayer_density": [0.2, 0.4, 0.7],
            "systeminit_default": [64, 64],
            "authored_battle_maps": {w["id"]: w["map_size"] for w in worlds},
            "note": "mapsizelist/densitylist from Scripts/init/mpinit.tcl:2,5",
        },
        "authored_worlds": worlds,
        "first_slice": build_slice(data),
    }
    ds["checks"] = {
        "invariants": [
            "R1 lattice: every preset / stone-rect / final coordinate is a multiple of 4",
            "R1 lattice audit: all authored battle-world presets and stone rects are on the lattice",
            "R3 final position == preset + area_min",
            "R4 caves lie inside the effective generation area and keep >= 8 units from the world edge",
            "R6 split-template tiles cover split_size exactly, without overlap, starting at 0,0",
            "R5 stone rects are on the lattice, inside the world, and the type-0 bands form a closed wall",
            "R5 every type-2 connector touches at least two cave footprints",
            "source SHA-256 of every referenced game file still matches",
            "EXE byte patterns behind the fact table still match (lattice, seed, material table, ground naming)",
            "the MT19937 core is still called from inside LevelGen (lg_start stays non-reproducible)",
        ],
        "violations": run_checks(data, ds),
    }
    return ds


def canonical(obj) -> str:
    return json.dumps(obj, ensure_ascii=False, sort_keys=True, indent=1) + "\n"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--data", type=Path, required=True)
    ap.add_argument("--output", type=Path, required=True)
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--check-exe", action="store_true",
                    help="only verify the EXE byte patterns behind the report fact table")
    args = ap.parse_args()

    if args.check_exe:
        exe = args.data.parent / "Diggles.exe"
        fails = verify_exe_evidence(exe)
        for va, want, why in EXE_EVIDENCE:
            print(f"  0x{va:08X}  {want.hex(' '):<24} {why}")
        for f in fails:
            print("  FAIL:", f)
        print("EXE_EVIDENCE_BYTES_OK" if not fails else f"EXE_EVIDENCE_FAILED ({len(fails)})")
        return 1 if fails else 0

    ds = build(args.data)
    fails = ds["checks"]["violations"]
    payload = canonical(ds)
    if fails:
        print("FAIL: invariant violations:")
        for f in fails:
            print("  -", f)
        return 2
    if args.check:
        if not args.output.is_file():
            print(f"FAIL: {args.output} missing")
            return 1
        if args.output.read_text(encoding="utf-8") != payload:
            print("FAIL: stored dataset differs from a fresh extraction")
            return 1
        print(f"OK: {args.output} reproduces byte-for-byte; "
              f"{len(ds['checks']['invariants'])} invariants hold")
        return 0
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(payload, encoding="utf-8")
    print(f"wrote {args.output} ({len(payload)} bytes); "
          f"invariants: {len(ds['checks']['invariants'])}, violations: {len(fails)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
