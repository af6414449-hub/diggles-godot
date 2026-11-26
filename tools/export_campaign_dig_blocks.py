"""Export the native BDB next-ref closure needed by campaign digging."""
import json
import struct
from pathlib import Path
from inspect_bdb import BdbDatabase

PROJECT = Path(__file__).resolve().parents[1]
CHAPTER = PROJECT / "godot/models/native_campaign_chapter.json"
OUTPUT = PROJECT / "godot/models/native_campaign_dig_blocks.json"
SOURCE = Path(r"C:/Program Files (x86)/Steam/steamapps/common/Diggles The Myth of Fenris/data/BlockDB2.BDB")

def main() -> None:
    chapter = json.loads(CHAPTER.read_text(encoding="utf-8"))
    db = BdbDatabase(SOURCE)
    data = db.data
    first = db.sections["opaque_block_metadata"]["offset"]
    seeds = {0} | {int(cell["block"]) for cell in chapter["cells"] if not cell.get("story", False)}
    seen = set(seeds)
    frontier = set(seeds)
    while frontier:
        later = set()
        for block in frontier:
            offset = first + 89 * block
            for child in struct.unpack_from("<4i", data, offset + 64):
                if 0 <= child < db.block_count and child not in seen:
                    later.add(child)
        seen.update(later)
        frontier = later
    records = {}
    meshes = {}
    for block in sorted(seen):
        offset = first + 89 * block
        records[str(block)] = {
            "next": struct.unpack_from("<4i", data, offset + 64),
            "heights": list(data[offset + 80:offset + 84]),
            # SOURCE: native_terrain_state.gd reads these 64 bytes as the
            # original 8x8 surface depth samples preceding the next refs.
            "surface_samples": list(data[offset:offset + 64]),
        }
        parts = db.get_block(block)
        for part in parts:
            part["vertices"] = [value for vertex in part["vertices"] for value in vertex]
        meshes[str(block)] = parts
    result = {
        "source": "BlockDB2.BDB original install, exact next-ref closure of initial campaign cells",
        "source_bdb_sha256": db.summary()["sha256"],
        "initial_block_count": len(seeds),
        "block_count": len(seen),
        "blocks": records,
        "meshes": meshes,
    }
    OUTPUT.write_text(json.dumps(result, separators=(",", ":")), encoding="utf-8")
    print(f"CAMPAIGN_DIG_BLOCKS source={len(seeds)} closure={len(seen)} bytes={OUTPUT.stat().st_size}")

if __name__ == "__main__":
    main()
