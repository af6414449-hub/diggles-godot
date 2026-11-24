// Headless Ghidra post-script: apply the map/scene layouts, type the global
// singletons and re-export every function that touches them as typed C.
//
// Background
// ----------
// ApplyStructs.java types the implicit `this` of a method and works well, but
// only for the 935 functions whose class could be recovered from RTTI/vtable
// evidence. The whole map subsystem is reached through the global map pointer
// (DAT_0077241c) instead of through a `this`, so none of it was typed.
//
// This script therefore adds three things on top of ApplyStructs:
//   1. richer field types (uint, byte, ushort, arrays, pointers to structs);
//   2. two-phase struct construction, so a field may point at another struct
//      that is defined further down the TSV;
//   3. global typing: a global can be declared as `CMap *`, after which every
//      `*(int *)(DAT_0077241c + 0x18)` becomes `map->cellCount` in the
//      decompilation, and every function referencing that global is re-exported.
//
// Usage:
//   analyzeHeadless <proj> <name> -process Diggles.exe \
//     -postScript ApplyMapTypes.java structs.tsv funcs.tsv globals.tsv <outDir>
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.data.ArrayDataType;
import ghidra.program.model.data.BooleanDataType;
import ghidra.program.model.data.ByteDataType;
import ghidra.program.model.data.CharDataType;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.DataTypeConflictHandler;
import ghidra.program.model.data.DataTypeManager;
import ghidra.program.model.data.DoubleDataType;
import ghidra.program.model.data.FloatDataType;
import ghidra.program.model.data.IntegerDataType;
import ghidra.program.model.data.LongLongDataType;
import ghidra.program.model.data.PointerDataType;
import ghidra.program.model.data.Pointer;
import ghidra.program.model.data.ShortDataType;
import ghidra.program.model.data.Structure;
import ghidra.program.model.data.StructureDataType;
import ghidra.program.model.data.Undefined1DataType;
import ghidra.program.model.data.Undefined4DataType;
import ghidra.program.model.data.UnsignedCharDataType;
import ghidra.program.model.data.UnsignedIntegerDataType;
import ghidra.program.model.data.UnsignedShortDataType;
import ghidra.program.model.data.VoidDataType;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.listing.ParameterImpl;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class ApplyMapTypes extends GhidraScript {

    private DataTypeManager dtm;
    private final Map<String, DataType> arrayCache = new LinkedHashMap<>();

    @Override
    public void run() throws Exception {
        List<String> raw = new ArrayList<>();
        for (String a : getScriptArgs()) {
            if (a != null && !a.startsWith("-")) {
                raw.add(a);
            }
        }
        String[] args = raw.toArray(new String[0]);
        String structsTsv = args.length > 0 ? args[0] : "ghidra_structs.tsv";
        String funcsTsv = args.length > 1 ? args[1] : "ghidra_funcs.tsv";
        String globalsTsv = args.length > 2 ? args[2] : "ghidra_globals.tsv";
        String outDir = args.length > 3 ? args[3] : "C:/diggles-ghidra/out_typed2";
        File dir = new File(outDir);
        dir.mkdirs();

        dtm = currentProgram.getDataTypeManager();
        AddressSpace space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        FunctionManager fm = currentProgram.getFunctionManager();
        SymbolTable st = currentProgram.getSymbolTable();
        Listing listing = currentProgram.getListing();
        ReferenceManager rm = currentProgram.getReferenceManager();

        // ---- 1. structures, two phases (so pointers may target each other)
        List<String[]> srows = readRows(structsTsv);
        Map<String, DataType> managed = new LinkedHashMap<>();
        for (String[] p : srows) {
            String cls = p[0].trim();
            if (cls.isEmpty() || cls.equals("class")) {
                continue;
            }
            if (managed.containsKey(cls)) {
                continue;
            }
            try {
                StructureDataType sdt = new StructureDataType(cls, 0);
                managed.put(cls, dtm.addDataType(sdt, DataTypeConflictHandler.REPLACE_HANDLER));
            } catch (Exception ex) {
                println("[ApplyMapTypes] cannot create struct " + cls + ": " + ex);
            }
        }
        int fields = 0;
        int skipped = 0;
        int shown = 0;
        for (String[] p : srows) {
            if (p.length < 4) {
                continue;
            }
            String cls = p[0].trim();
            DataType sdt = managed.get(cls);
            if (sdt == null) {
                continue;
            }
            int off;
            try {
                off = Integer.decode(p[1].trim());
            } catch (Exception e) {
                continue;
            }
            DataType dt = typeFor(p[3].trim(), managed);
            try {
                ((Structure) sdt).insertAtOffset(off, dt, dt.getLength(), p[2].trim(), "");
                fields++;
            } catch (Exception e) {
                skipped++;
                if (shown < 10) {
                    shown++;
                    println("[ApplyMapTypes] field " + cls + "+0x" + Integer.toHexString(off) + " ("
                            + p[3].trim() + ") failed: " + e);
                }
            }
        }
        println("[ApplyMapTypes] structures: " + managed.size() + ", fields applied: " + fields
                + ", skipped: " + skipped);

        // ---- 2. type the `this` pointer of known methods ------------------
        Set<String> touched = new LinkedHashSet<>();
        int applied = 0;
        int noClass = 0;
        int noFunc = 0;
        int failed = 0;
        int reset = 0;
        for (String[] p : readRows(funcsTsv)) {
            if (p.length < 2) {
                continue;
            }
            Address addr;
            try {
                addr = space.getAddress(p[0].trim());
            } catch (Exception e) {
                noFunc++;
                continue;
            }
            Function f = fm.getFunctionAt(addr);
            if (f == null) {
                noFunc++;
                continue;
            }
            DataType clsType = managed.get(p[1].trim());
            if (clsType == null) {
                noClass++;
                // класс снят в этом проходе — старый тип this надо убрать,
                // иначе он останется в базе от предыдущего прогона
                if (resetThisType(f, managed)) {
                    reset++;
                }
                // функцию с явно снятым классом надо перевыгрузить: на диске
                // может лежать старый файл с прежним (неверным) типом this
                if (p[1].trim().endsWith("Unassigned")) {
                    touched.add(f.getEntryPoint().toString());
                }
                continue;
            }
            try {
                DataType ptrType = new PointerDataType(clsType, 4, dtm);
                if (!applyThisType(f, ptrType)) {
                    failed++;
                    continue;
                }
                applied++;
                touched.add(f.getEntryPoint().toString());
            } catch (Exception e) {
                failed++;
            }
        }
        println("[ApplyMapTypes] functions typed: " + applied
                + " (no class: " + noClass + ", no function: " + noFunc + ", failed: " + failed
                + ", this reset: " + reset + ")");

        // ---- 3. type the global singletons -------------------------------
        int globalsDone = 0;
        int globalsMiss = 0;
        for (String[] p : readRows(globalsTsv)) {
            if (p.length < 2) {
                continue;
            }
            Address addr;
            try {
                addr = space.getAddress(p[0].trim());
            } catch (Exception e) {
                globalsMiss++;
                continue;
            }
            DataType target = managed.get(p[1].trim());
            if (target == null) {
                globalsMiss++;
                continue;
            }
            DataType ptrType = new PointerDataType(target, 4, dtm);
            try {
                Symbol sym = st.getPrimarySymbol(addr);
                if (sym == null) {
                    st.createLabel(addr, "g_" + p[1].trim().replace("*", "").trim().toLowerCase(),
                            SourceType.USER_DEFINED);
                }
                listing.clearCodeUnits(addr, addr, false);
                listing.createData(addr, ptrType);
                globalsDone++;
            } catch (Exception e) {
                println("[ApplyMapTypes] cannot type global " + p[0] + ": " + e);
                globalsMiss++;
            }
        }
        println("[ApplyMapTypes] globals typed: " + globalsDone + " (missed: " + globalsMiss + ")");

        // ---- 4. every function that references a typed global -------------
        int refFuncs = 0;
        for (String[] p : readRows(globalsTsv)) {
            if (p.length < 2) {
                continue;
            }
            Address addr;
            try {
                addr = space.getAddress(p[0].trim());
            } catch (Exception e) {
                continue;
            }
            ReferenceIterator refs = rm.getReferencesTo(addr);
            while (refs.hasNext()) {
                Reference r = refs.next();
                Function f = fm.getFunctionContaining(r.getFromAddress());
                if (f != null) {
                    if (touched.add(f.getEntryPoint().toString())) {
                        refFuncs++;
                    }
                }
            }
        }
        println("[ApplyMapTypes] functions referencing typed globals: " + refFuncs
                + " (total touched: " + touched.size() + ")");

        // ---- 5. re-export -----------------------------------------------
        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.toggleCCode(true);
        ifc.openProgram(currentProgram);

        PrintWriter index = new PrintWriter(new BufferedWriter(
                new FileWriter(new File(dir, "index_typed2.tsv"))));
        index.println("func\tentry\tlines\tfile");
        Set<String> written = new LinkedHashSet<>();
        int exported = 0;
        for (String entry : touched) {
            Address addr = space.getAddress(entry);
            Function f = fm.getFunctionAt(addr);
            if (f == null) {
                continue;
            }
            String c = "";
            try {
                DecompileResults res = ifc.decompileFunction(f, 90, monitor);
                if (res != null && res.decompileCompleted() && res.getDecompiledFunction() != null) {
                    c = res.getDecompiledFunction().getC();
                }
            } catch (Exception e) {
                c = "";
            }
            String fname = safe(f.getName()) + "_" + f.getEntryPoint() + ".c";
            try (PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter(new File(dir, fname))))) {
                w.print(c);
            }
            written.add(fname);
            index.println(f.getName() + "\t" + f.getEntryPoint() + "\t" + c.split("\n", -1).length + "\t" + fname);
            exported++;
        }
        index.flush();
        index.close();
        // выходная папка - сборочный артефакт: файлы от прошлых прогонов
        // (с другим набором функций) там оставаться не должны
        int stale = 0;
        File[] leftovers = dir.listFiles();
        if (leftovers != null) {
            for (File f : leftovers) {
                if (f.isFile() && f.getName().endsWith(".c") && !written.contains(f.getName())) {
                    if (f.delete()) {
                        stale++;
                    }
                }
            }
        }
        println("[ApplyMapTypes] exported: " + exported + " (stale removed: " + stale + ") -> "
                + dir.getAbsolutePath());
        ifc.dispose();
    }

    private List<String[]> readRows(String path) throws Exception {
        List<String[]> out = new ArrayList<>();
        if (!Files.exists(Paths.get(path))) {
            return out;
        }
        for (String line : Files.readAllLines(Paths.get(path))) {
            if (line.trim().isEmpty() || line.startsWith("#")) {
                continue;
            }
            out.add(line.split("\t"));
        }
        return out;
    }

    private DataType typeFor(String name, Map<String, DataType> managed) {
        String n = name.trim();
        int br = n.indexOf('[');
        if (br > 0 && n.endsWith("]")) {
            String base = n.substring(0, br).trim();
            int count;
            try {
                count = Integer.parseInt(n.substring(br + 1, n.length() - 1).trim());
            } catch (Exception e) {
                return new Undefined4DataType();
            }
            // identical shapes must share one instance: the Data Type Manager
            // names arrays "type[count]" and a second instance of the same shape
            // would replace the first one in the manager
            String key = base + "[" + count + "]";
            DataType cached = arrayCache.get(key);
            if (cached != null) {
                return cached;
            }
            DataType bt = typeFor(base, managed);
            DataType arr = new ArrayDataType(bt, count, bt.getLength());
            arrayCache.put(key, arr);
            return arr;
        }
        if (n.endsWith("*")) {
            String target = n.substring(0, n.length() - 1).trim();
            DataType t = managed.get(target);
            if (t != null) {
                return new PointerDataType(t, 4, dtm);
            }
            return new PointerDataType(new VoidDataType(), 4, dtm);
        }
        if ("int".equals(n)) {
            return new IntegerDataType();
        }
        if ("uint".equals(n)) {
            return new UnsignedIntegerDataType();
        }
        if ("short".equals(n)) {
            return new ShortDataType();
        }
        if ("ushort".equals(n)) {
            return new UnsignedShortDataType();
        }
        if ("byte".equals(n)) {
            return new UnsignedCharDataType();
        }
        if ("char".equals(n)) {
            return new CharDataType();
        }
        if ("bool".equals(n)) {
            return new BooleanDataType();
        }
        if ("float".equals(n)) {
            return new FloatDataType();
        }
        if ("double".equals(n)) {
            return new DoubleDataType();
        }
        if ("long long".equals(n)) {
            return new LongLongDataType();
        }
        if ("byte1".equals(n)) {
            return new Undefined1DataType();
        }
        return new Undefined4DataType();
    }

    /**
     * Type the implicit `this` pointer of a MSVC __thiscall method.
     *
     * Ghidra refuses insertParameter(0, ...) on a function that already owns an
     * auto-parameter ("Parameter may not be inserted before auto-parameter"),
     * and __thiscall creates exactly such an auto-parameter for ECX. The
     * parameter therefore has to be retyped in place; only if that is refused
     * do we fall back to rebuilding the whole parameter list.
     */
    private boolean applyThisType(Function f, DataType ptrType) {
        try {
            f.setCallingConvention("__thiscall");
        } catch (Exception e) {
            // convention unsupported - continue with the default one
        }
        Parameter[] ps = f.getParameters();
        if (ps.length > 0) {
            try {
                ps[0].setDataType(ptrType, SourceType.USER_DEFINED);
                return true;
            } catch (Exception e) {
                try {
                    Register ecx = currentProgram.getRegister("ECX");
                    ParameterImpl typed = new ParameterImpl("this", ptrType, ecx, currentProgram);
                    List<Parameter> repl = new ArrayList<>();
                    repl.add(typed);
                    for (int i = 1; i < ps.length; i++) {
                        repl.add(ps[i]);
                    }
                    f.replaceParameters(FunctionUpdateType.CUSTOM_STORAGE, true,
                            SourceType.USER_DEFINED, repl.toArray(new Parameter[0]));
                    return true;
                } catch (Exception e2) {
                    try {
                        f.insertParameter(0, new ParameterImpl("this", ptrType, currentProgram),
                                SourceType.USER_DEFINED);
                        return true;
                    } catch (Exception e3) {
                        return false;
                    }
                }
            }
        }
        try {
            f.insertParameter(0, new ParameterImpl("this", ptrType, currentProgram),
                    SourceType.USER_DEFINED);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    /**
     * Снимает тип `this`, оставшийся от прошлого прохода, если класс функции
     * больше не входит в список типизируемых.
     */
    private boolean resetThisType(Function f, Map<String, DataType> managed) {
        try {
            Parameter[] ps = f.getParameters();
            if (ps.length == 0) {
                return false;
            }
            DataType dt = ps[0].getDataType();
            if (!(dt instanceof Pointer)) {
                return false;
            }
            DataType target = ((Pointer) dt).getDataType();
            if (target == null || !managed.containsValue(target)) {
                return false;
            }
            ps[0].setDataType(Undefined4DataType.dataType, SourceType.USER_DEFINED);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    private String safe(String s) {
        return s.replaceAll("[^A-Za-z0-9_.-]", "_");
    }
}
