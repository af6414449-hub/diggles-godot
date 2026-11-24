"""Decode the observed Diggles BDB v11 layout without expanding every block.

Layout source: docs/reverse-engineering/blockdb-loader-disassembly.txt,
LoadDB at 0x565ab0. All integers/floats are little endian:
    <7I header: version, u1, block_count, u3, index_count,
                u8_record_count (number of <II topology records), vertex_count
    block_count * 3 * <HI: vertexCount, topologyId
    block_count * 89 opaque bytes
    index_count * U16 local triangle indices
    u8_record_count * <II: firstIndex, indexCount (both in index elements)
    vertex_count * <5f: x, y, z, u, v
    for each block, for each of its three parts:
        vertexCount * U16 global vertex IDs, then vertexCount * U8 attributes

The metadata, part meanings and U8 attribute meanings remain unresolved.
vertex_pool and index_pool are read-only, lazy sequences over the raw bytes;
indexing/slicing returns tuples/ints and lists respectively. get_block() alone
materializes the three requested part dictionaries. Coordinates, UVs and triangle
winding are never transformed.

Examples:
    python -B tools/inspect_bdb.py BlockDB0.BDB --summary
    python -B tools/inspect_bdb.py BlockDB0.BDB --block 0 --output block0.obj
    python -B tools/inspect_bdb.py BlockDB0.BDB BlockDB1.BDB BlockDB2.BDB \
        --audit docs/reverse-engineering/blockdb-layout-audit.json
"""
from __future__ import annotations

import argparse
from array import array
from collections.abc import Iterator, Sequence
import hashlib
import json
import math
import operator
from pathlib import Path
import struct


_HEADER = struct.Struct("<7I")
_CATALOG = struct.Struct("<HI")
_TOPOLOGY = struct.Struct("<II")
_VERTEX = struct.Struct("<5f")
_U16 = struct.Struct("<H")
_HEADER_FIELDS = (
    "version", "u1", "block_count", "u3", "index_count",
    "u8_record_count", "vertex_count",
)
_PARTS = 3
_METADATA_BYTES = 89


class BdbFormatError(ValueError):
    """A file or requested block violates the observed BDB v11 layout."""


class _PackedPool(Sequence):
    """A read-only sequence that decodes individual records on demand."""

    def __init__(self, data: bytes, offset: int, count: int, record: struct.Struct):
        self._data = data
        self.offset = offset
        self._count = count
        self._record = record
        self._scalar = record is _U16

    def __len__(self) -> int:
        return self._count

    def __getitem__(self, key):
        if isinstance(key, slice):
            return [self[i] for i in range(*key.indices(self._count))]
        key = operator.index(key)
        if key < 0:
            key += self._count
        if not 0 <= key < self._count:
            raise IndexError("BDB pool index out of range")
        value = self._record.unpack_from(self._data, self.offset + key * self._record.size)
        return value[0] if self._scalar else value

    def __iter__(self) -> Iterator:
        end = self.offset + self._count * self._record.size
        for value in self._record.iter_unpack(memoryview(self._data)[self.offset:end]):
            yield value[0] if self._scalar else value


class BdbDatabase:
    """Keep raw bytes and compact block offsets; decode only requested parts.

    Construction checks section bounds and exact EOF. validate() additionally
    checks every topology, every part reference and all five vertex components.
    Block IDs and returned triangle indices are zero based.
    """

    def __init__(self, path: Path):
        self.path = Path(path)
        self.data = self.path.read_bytes()
        if len(self.data) < _HEADER.size:
            raise BdbFormatError(f"truncated header: {len(self.data)} bytes, need {_HEADER.size}")
        self.header = dict(zip(_HEADER_FIELDS, _HEADER.unpack_from(self.data)))
        if self.header["version"] != 11:
            raise BdbFormatError(f"unsupported BDB version {self.header['version']}; expected 11")
        self.block_count = self.header["block_count"]
        self.index_count = self.header["index_count"]
        self.u8_record_count = self.header["u8_record_count"]
        self.vertex_count = self.header["vertex_count"]
        self.sections = {"header": {"offset": 0, "size": _HEADER.size}}
        cursor = _HEADER.size
        for name, size in (
            ("part_catalog", self.block_count * _PARTS * _CATALOG.size),
            ("opaque_block_metadata", self.block_count * _METADATA_BYTES),
            ("index_pool", self.index_count * _U16.size),
            ("topology_table", self.u8_record_count * _TOPOLOGY.size),
            ("vertex_pool", self.vertex_count * _VERTEX.size),
        ):
            end = cursor + size
            if end > len(self.data):
                raise BdbFormatError(f"truncated {name}: need end {end}, file ends at {len(self.data)}")
            self.sections[name] = {"offset": cursor, "size": size}
            cursor = end

        self.index_pool = _PackedPool(self.data, self.sections["index_pool"]["offset"],
                                      self.index_count, _U16)
        self.vertex_pool = _PackedPool(self.data, self.sections["vertex_pool"]["offset"],
                                       self.vertex_count, _VERTEX)
        # One U64 offset per block, plus an EOF sentinel: no per-part objects.
        self._block_offsets = array("Q")
        payload_cursor = cursor
        for entry, (count, _) in enumerate(_CATALOG.iter_unpack(self._view("part_catalog"))):
            if entry % _PARTS == 0:
                self._block_offsets.append(payload_cursor)
            payload_cursor += count * 3  # U16 IDs followed by U8 attributes.
        self._block_offsets.append(payload_cursor)
        self.end_offset = payload_cursor
        self.part_vertex_references = (payload_cursor - cursor) // 3
        if payload_cursor != len(self.data):
            raise BdbFormatError(
                f"part payload end {payload_cursor} != file size {len(self.data)} "
                f"(file minus expected: {len(self.data) - payload_cursor})"
            )
        self.sections["part_payloads"] = {"offset": cursor, "size": payload_cursor - cursor}

    def _view(self, name: str) -> memoryview:
        section = self.sections[name]
        return memoryview(self.data)[section["offset"]:section["offset"] + section["size"]]

    def _topology(self, topology_id: int) -> tuple[int, int]:
        if not 0 <= topology_id < self.u8_record_count:
            raise BdbFormatError(f"topology ID {topology_id} >= {self.u8_record_count}")
        offset = self.sections["topology_table"]["offset"] + topology_id * _TOPOLOGY.size
        first, count = _TOPOLOGY.unpack_from(self.data, offset)
        if first > self.index_count or first + count > self.index_count:
            raise BdbFormatError(f"topology {topology_id}: index range [{first}, {first + count}) out of bounds")
        if count % 3:
            raise BdbFormatError(f"topology {topology_id}: {count} indices is not a triangle list")
        return first, count

    def get_block(self, block_id: int) -> list[dict]:
        """Return three {part, vertices, indices, attributes} dictionaries.

        vertices contains (x, y, z, u, v) tuples in part-local order; indices
        references that list, and attributes contains one uninterpreted U8 per
        vertex. Empty parts are included. Invalid block IDs raise IndexError.
        """
        block_id = operator.index(block_id)
        if not 0 <= block_id < self.block_count:
            raise IndexError(f"block ID {block_id} outside [0, {self.block_count})")
        cursor = self._block_offsets[block_id]
        catalog = self.sections["part_catalog"]["offset"] + block_id * _PARTS * _CATALOG.size
        parts = []
        for part in range(_PARTS):
            count, topology_id = _CATALOG.unpack_from(self.data, catalog + part * _CATALOG.size)
            first, index_count = self._topology(topology_id)
            indices = self.index_pool[first:first + index_count]
            if max(indices, default=-1) >= count:
                raise BdbFormatError(f"block {block_id} part {part}: local index >= vertexCount {count}")
            ids_end = cursor + count * _U16.size
            vertex_ids = [value[0] for value in _U16.iter_unpack(memoryview(self.data)[cursor:ids_end])]
            if max(vertex_ids, default=-1) >= self.vertex_count:
                raise BdbFormatError(f"block {block_id} part {part}: vertex ID >= {self.vertex_count}")
            vertices = [self.vertex_pool[vertex_id] for vertex_id in vertex_ids]
            if any(not math.isfinite(value) for vertex in vertices for value in vertex):
                raise BdbFormatError(f"block {block_id} part {part}: nonfinite vertex component")
            parts.append({
                "part": part,
                "vertices": vertices,
                "indices": indices,
                "attributes": list(self.data[ids_end:ids_end + count]),
            })
            cursor = ids_end + count
        return parts

    def summary(self) -> dict:
        return {
            "path": str(self.path.resolve()),
            "size_bytes": len(self.data),
            "sha256": hashlib.sha256(self.data).hexdigest(),
            "header": self.header.copy(),
            "sections": {name: section.copy() for name, section in self.sections.items()},
            "part_vertex_references": self.part_vertex_references,
            "end_offset": self.end_offset,
        }

    def validate(self) -> dict:
        """Exhaustively validate content, keeping at most eight error examples.

        U16 indices/IDs are unsigned, so comparing each range's maximum proves
        the bound for every element. Topology maxima are cached in a compact
        array, then checked against vertexCount for EVERY referencing part.
        """
        errors = dict.fromkeys((
            "topology_bounds", "topology_triangle_counts", "part_topology_ids",
            "part_local_indices", "part_vertex_ids", "nonfinite_floats",
        ), 0)
        examples = []

        def error(kind: str, message: str, count: int = 1):
            errors[kind] += count
            if len(examples) < 8:
                examples.append({"check": kind, "detail": message})

        maxima = array("i")
        topology_sizes = array("I")
        indices = self._view("index_pool")
        for topology_id, (first, count) in enumerate(_TOPOLOGY.iter_unpack(self._view("topology_table"))):
            topology_sizes.append(count)
            if count % 3:
                error("topology_triangle_counts", f"topology {topology_id}: {count} indices")
            if first > self.index_count or first + count > self.index_count:
                error("topology_bounds", f"topology {topology_id}: [{first}, {first + count})")
                maxima.append(-2)  # Distinct from a valid empty range's -1.
            else:
                values = _U16.iter_unpack(indices[first * _U16.size:(first + count) * _U16.size])
                maxima.append(max((value[0] for value in values), default=-1))

        cursor = self.sections["part_payloads"]["offset"]
        raw = memoryview(self.data)
        referenced = bytearray(self.u8_record_count)
        local_index_references = 0
        parts_checked = 0
        vertex_ids_checked = 0
        for entry, (count, topology_id) in enumerate(_CATALOG.iter_unpack(self._view("part_catalog"))):
            block_id, part = divmod(entry, _PARTS)
            location = f"block {block_id} part {part}"
            if topology_id >= self.u8_record_count:
                error("part_topology_ids", f"{location}: topology {topology_id}")
            else:
                referenced[topology_id] = 1
                if maxima[topology_id] != -2:
                    local_index_references += topology_sizes[topology_id]
                    if maxima[topology_id] >= count:
                        error("part_local_indices", f"{location}: max index {maxima[topology_id]} >= {count}")
            ids_end = cursor + count * _U16.size
            max_id = max((value[0] for value in _U16.iter_unpack(raw[cursor:ids_end])), default=-1)
            if max_id >= self.vertex_count:
                error("part_vertex_ids", f"{location}: max vertex ID {max_id} >= {self.vertex_count}")
            cursor = ids_end + count
            parts_checked += 1
            vertex_ids_checked += count

        for vertex_id, vertex in enumerate(self.vertex_pool):
            bad_components = sum(not math.isfinite(value) for value in vertex)
            if bad_components:
                error("nonfinite_floats", f"vertex {vertex_id}: {vertex}", bad_components)
        exact_end = cursor == self.end_offset == len(self.data)
        result = {
            "valid": exact_end and not any(errors.values()),
            "exact_end": exact_end,
            "trailing_bytes": len(self.data) - cursor,
            "checked": {
                "topology_records": len(maxima),
                "referenced_topologies": sum(referenced),
                "parts": parts_checked,
                "local_index_references": local_index_references,
                "vertex_ids": vertex_ids_checked,
                "float_components": self.vertex_count * 5,
            },
            "errors": errors,
        }
        if examples:
            result["error_examples"] = examples
        return result


def export_obj(database: BdbDatabase, block_id: int, output: Path) -> dict:
    """Export one block with raw XYZ/UV/winding and one OBJ group per part."""
    output = Path(output)
    if output.resolve() == database.path.resolve():
        raise ValueError("OBJ output must differ from the input database")
    parts = database.get_block(block_id)
    lines = ["# Diggles BDB: raw XYZ, UV and triangle winding", f"o block_{block_id}"]
    base = 1
    triangles = 0
    for part in parts:
        lines.append(f"g block_{block_id}_part_{part['part']}")
        # Nine significant digits round-trip every finite source float32.
        for x, y, z, _, _ in part["vertices"]:
            lines.append(f"v {x:.9g} {y:.9g} {z:.9g}")
        for _, _, _, u, v in part["vertices"]:
            lines.append(f"vt {u:.9g} {v:.9g}")
        indices = part["indices"]
        for i in range(0, len(indices), 3):
            face = [base + index for index in indices[i:i + 3]]
            lines.append("f " + " ".join(f"{index}/{index}" for index in face))
            triangles += 1
        base += len(part["vertices"])
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text("\n".join(lines) + "\n", encoding="utf-8")
    return {"block": block_id, "obj": str(output.resolve()), "vertices": base - 1, "triangles": triangles}


def main(argv: Sequence[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("databases", nargs="+", type=Path, help="one or more BlockDB*.BDB files")
    parser.add_argument("--summary", action="store_true", help="print a JSON summary (the default)")
    parser.add_argument("--validate", action="store_true", help="validate all topology/vertex references and floats")
    parser.add_argument("--audit", type=Path, help="save JSON summaries with full validation; implies --validate")
    parser.add_argument("--block", type=int, help="zero-based block ID to export from a single database")
    parser.add_argument("--output", type=Path, help="OBJ output for --block; preserves raw XYZ and UV")
    args = parser.parse_args(argv)
    if (args.block is None) != (args.output is None):
        parser.error("--block and --output must be supplied together")
    if args.output is not None and len(args.databases) != 1:
        parser.error("OBJ export requires exactly one input database")
    if args.output is not None and args.output.suffix.lower() != ".obj":
        parser.error("--output must have an .obj extension")
    input_paths = {path.resolve() for path in args.databases}
    for output in (args.output, args.audit):
        if output is not None and output.resolve() in input_paths:
            parser.error("output must differ from every input database")
    if args.output is not None and args.audit is not None and args.output.resolve() == args.audit.resolve():
        parser.error("OBJ output and audit output must differ")

    report = {
        "format": "Diggles BDB v11 (little endian)",
        "layout_source": "docs/reverse-engineering/blockdb-loader-disassembly.txt: LoadDB 0x565ab0",
        "section_ranges": "offset and size in bytes; end is exclusive",
        "unresolved": ["89-byte block metadata", "three part meanings", "per-vertex U8 attribute meaning"],
        "files": [],
    }
    valid = True
    try:
        for path in args.databases:
            database = BdbDatabase(path)
            summary = database.summary()
            if args.validate or args.audit is not None:
                summary["validation"] = database.validate()
                valid = valid and summary["validation"]["valid"]
            if args.output is not None and valid:
                summary["export"] = export_obj(database, args.block, args.output)
            report["files"].append(summary)
        serialized = json.dumps(report, indent=2, ensure_ascii=False, allow_nan=False) + "\n"
        if args.audit is not None:
            args.audit.parent.mkdir(parents=True, exist_ok=True)
            args.audit.write_text(serialized, encoding="utf-8")
        print(serialized, end="")
    except (OSError, ValueError, IndexError) as error:
        parser.exit(1, f"BDB: {error}\n")
    return 0 if valid else 1


if __name__ == "__main__":
    raise SystemExit(main())
