"""Разбор minidump: модули, exception stream, контекст потока.

Использование: python dumpinfo.py <файл.dmp> [--asm]

Защита от зависания (бывший баг, 24.11.2026):
инлайн-скрипт читал имя модуля поиском "00 00" до конца файла и на EOF
цикл не завершался -> процесс висел до срабатывания watchdog (1 час),
а список модулей ещё и брался из ThreadListStream (тип 3) вместо
ModuleListStream (тип 4). Здесь имя читается по структуре MINIDUMP_STRING
(4-байтовая длина + UTF-16LE) с проверкой границ файла.
"""
import struct
import sys

CTX32 = {
    "Edi": 0x2C, "Esi": 0x30, "Ebx": 0x34, "Edx": 0x38, "Ecx": 0x3C,
    "Eax": 0x40, "Ebp": 0x44, "Eip": 0x48, "EFlags": 0x50, "Esp": 0x54,
}

# типы потоков minidump (ModuleListStream = 4, ThreadListStream = 3)
ST_MODULE_LIST = 4


def u32(d, o):
    return struct.unpack_from("<I", d, o)[0]


def u64(d, o):
    return struct.unpack_from("<Q", d, o)[0]


def read_minidump_string(d, rva):
    """MINIDUMP_STRING: u32 length_bytes + UTF-16LE payload. Без бесконечных циклов."""
    if rva + 4 > len(d):
        return "<rva %08X вне файла>" % rva
    n = u32(d, rva)
    if n > 0x10000 or rva + 4 + n > len(d):
        return "<битое имя: rva %08X len %d>" % (rva, n)
    return d[rva + 4:rva + 4 + n].decode("utf-16-le", "replace")


def main():
    path = sys.argv[1]
    d = open(path, "rb").read()
    assert d[:4] == b"MDMP", d[:4]
    n = u32(d, 8)
    dir_rva = u32(d, 12)
    streams = {}
    for i in range(n):
        o = dir_rva + i * 12
        st, size, rva = u32(d, o), u32(d, o + 4), u32(d, o + 8)
        streams.setdefault(st, []).append((size, rva))

    print("streams:", {k: v for k, v in sorted(streams.items())})

    base = None
    modules = []
    if ST_MODULE_LIST in streams:
        size, rva = streams[ST_MODULE_LIST][0]
        cnt = u32(d, rva)
        print("modules:", cnt)
        for i in range(cnt):
            o = rva + 4 + i * 108
            if o + 108 > len(d):
                print("  <список модулей обрезан на %d>" % i)
                break
            b = u64(d, o)
            sz = u32(d, o + 8)
            namerva = u32(d, o + 20)
            name = read_minidump_string(d, namerva)
            modules.append((b, sz, name))
            print("  base=%08X size=%08X  %s" % (b, sz, name))
            if name.lower().endswith("diggles.exe"):
                base = b

    # база образа exe и смещение ASLR (нужно для реверса: VA_в_игре = RVA + base)
    if base:
        try:
            import pefile
            exe = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
            pe = pefile.PE(exe)
            pref = pe.OPTIONAL_HEADER.ImageBase
            pe.close()
            print("EXE load base   = %08X" % base)
            print("EXE image base  = %08X (предпочтительный ImageBase в файле)" % pref)
            print("ASLR delta      = %08X" % (base - pref))
        except Exception as e:  # noqa: BLE001
            print("EXE load base   = %08X (ImageBase не прочитан: %s)" % (base, e))

    if 6 in streams:
        size, rva = streams[6][0]
        tid = u32(d, rva)
        code = u32(d, rva + 8)
        flags = u32(d, rva + 12)
        excrec = u64(d, rva + 16)
        exaddr = u64(d, rva + 24)
        nparams = u32(d, rva + 32)
        print("EXCEPTION tid=%d code=%08X flags=%08X record=%016X addr=%016X nparams=%d"
              % (tid, code, flags, excrec, exaddr, nparams))
        info = []
        for i in range(min(nparams, 15)):
            info.append(u64(d, rva + 40 + i * 8))
        print("  info:", " ".join("%016X" % v for v in info))
        if code == 0xC0000005 and len(info) >= 2:
            # ExceptionInformation[0]: 0=READ, 1=WRITE, 8=EXECUTE
            op = {0: "READ", 1: "WRITE", 8: "EXECUTE"}.get(info[0], "op=%d" % info[0])
            print("  op=%s fault_addr=%016X" % (op, info[1]))
        ctx_size = u32(d, rva + 160)
        ctx_rva = u32(d, rva + 164)
        ctx = d[ctx_rva:ctx_rva + ctx_size]
        print("  ctx size", ctx_size, "flags=%08X" % u32(ctx, 0))
        regs = {k: u32(ctx, v) for k, v in CTX32.items()}
        for k in ("Eip", "Esp", "Ebp", "Eax", "Ebx", "Ecx", "Edx", "Esi", "Edi"):
            print("   %-4s %08X" % (k, regs[k]))

        # Контекст потока может быть недоступен (заполнен 0xAAAAAAAA) - тогда
        # Eip/Esp мусорные, и опираться надо на адрес исключения.
        ctx_ok = regs["Eip"] not in (0, 0xAAAAAAAA) and regs["Eip"] < 0x80000000
        if not ctx_ok:
            print("  ! контекст потока недоступен (0xAAAAAAAA) - берём адрес из ExceptionStream")
        if base:
            fault = regs["Eip"] if ctx_ok else (exaddr or 0)
            rva_eip = (fault - base) & 0xFFFFFFFF
            print("  RIP rva = %08X (адрес %08X, base %08X)" % (rva_eip, fault, base))
            if not ctx_ok:
                print("  (RVA взят из адреса исключения, а не из Eip)")
            sp = regs["Esp"]
            if ctx_ok and 0 < sp < len(d) - 32:
                print("  stack top:", end=" ")
                for i in range(8):
                    print("%08X" % u32(d, sp + i * 4), end=" ")
                print()
            else:
                print("  stack top: недоступен (Esp=%08X)" % sp)
            if "--asm" in sys.argv:
                # ищем модуль-владелец адреса падения
                owner = None
                for b, sz, nm in modules:
                    if b <= fault < b + sz:
                        owner = (b, sz, nm)
                        break
                if owner is None:
                    print("  адрес %08X не принадлежит ни одному модулю "
                          "(мусорный адрес перехода - 'выстрел в молоко')" % fault)
                else:
                    ob, osz, onm = owner
                    orva = fault - ob
                    print("  FAULT в модуле: %s" % onm)
                    print("    RVA в модуле = %08X (модуль %08X..%08X)"
                          % (orva, ob, ob + osz))
                    try:
                        import pefile
                        pe = pefile.PE(onm)
                        fo = pe.get_offset_from_rva(orva)
                        raw = open(onm, "rb").read()
                        blk = raw[fo - 64: fo + 64]
                        pe.close()
                        import capstone
                        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
                        md.detail = True
                        for ins in md.disasm(blk, fault - 64):
                            mark = "  <<< FAULT" if ins.address == fault else ""
                            print("  %08X  %-28s %s%s" % (ins.address, ins.bytes.hex(" "),
                                                         ins.mnemonic + " " + ins.op_str, mark))
                    except Exception as e:  # noqa: BLE001
                        print("    дизасм не сделан: %s" % e)


if __name__ == "__main__":
    main()
