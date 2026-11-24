"""Поиск команд bash в журнале сессии MiniMax Code (JSONL-снапшоты).

Нужен, чтобы восстановить исходную команду упавшей/зависшей фоновой задачи
(её описание генерируется рантаймом и в логе не сохраняется).

    python sessioncmd.py <подстрока> [--all]
    python sessioncmd.py --tasks          # только список фоновых задач
"""
import datetime
import glob
import json
import os
import sys

ROOT = (r"C:\Users\frant\.minimax\v2\sessions\2026\11\22"
        r"\15-04-11-220-session_bXZzXzI2ZmVhODI0YTZhZjQ5YjlhYjVjYTAwZDdkMTU5NGMx")


def iter_calls():
    """Отдаёт (timestamp, tool, arguments) всех toolCall из снапшотов + messages.jsonl."""
    files = sorted(glob.glob(os.path.join(ROOT, "snapshots", "g*.jsonl")))
    files.append(os.path.join(ROOT, "messages.jsonl"))
    for f in files:
        if not os.path.exists(f):
            continue
        with open(f, "r", encoding="utf-8", errors="replace") as fh:
            for ln in fh:
                ln = ln.strip()
                if not ln:
                    continue
                try:
                    o = json.loads(ln)
                except Exception:
                    continue
                msg = o.get("message") or {}
                ts = o.get("timestamp") or msg.get("timestamp")
                for c in (msg.get("content") or []):
                    if isinstance(c, dict) and c.get("type") == "toolCall":
                        args = c.get("arguments")
                        if not isinstance(args, dict):
                            args = {}
                        yield ts, c.get("name", ""), args


def main():
    if "--tasks" in sys.argv:
        seen = {}
        for ts, tool, args in iter_calls():
            desc = args.get("description") or args.get("task_description") or ""
            if not desc:
                continue
            key = desc
            seen.setdefault(key, []).append(ts)
        for desc, tss in sorted(seen.items()):
            stamps = [t for t in tss if t]
            t = (datetime.datetime.fromtimestamp(min(stamps) / 1000).strftime("%d.%m %H:%M")
                 if stamps else "??")
            print("%s  x%-3d %s" % (t, len(tss), desc[:110]))
        return 0

    needle = sys.argv[1] if len(sys.argv) > 1 else ""
    limit = 400
    for a in sys.argv[2:]:
        if a.startswith("--limit="):
            limit = int(a.split("=", 1)[1])
    rows = []
    for ts, tool, args in iter_calls():
        blob = json.dumps(args, ensure_ascii=False)
        if needle and needle not in blob:
            continue
        rows.append((ts or 0, tool, args))
    rows.sort(key=lambda r: r[0])
    for ts, tool, args in rows:
        t = datetime.datetime.fromtimestamp(ts / 1000).strftime("%d.%m %H:%M:%S")
        print("=== %s | %s | %s" % (t, tool, args.get("description", "")))
        cmd = args.get("command") or json.dumps(args, ensure_ascii=False)
        print(cmd[:limit])
        print()
    return 0


if __name__ == "__main__":
    sys.exit(main())
