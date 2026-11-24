// Headless Ghidra post-script: apply the inferred class layouts and
// re-export the affected functions as typed C.
//
// Background: there is no PDB, so Ghidra knows the classes (RTTI) but not
// their members. A first analysis pass inferred the field layout of every
// class from the raw field accesses in the decompiled code (this->field at
// offset X). This script materialises those layouts as real Ghidra
// structures, attaches them to the `this` pointer (ECX under __thiscall)
// and re-decompiles the affected functions.
//
// Input TSVs:
//   ghidra_structs.tsv  class <TAB> offset <TAB> field <TAB> type
//   ghidra_funcs.tsv    0xADDRESS <TAB> class
//
// Usage:
//   analyzeHeadless <proj> <name> -process Diggles.exe \
//     -postScript ApplyStructs.java structs.tsv funcs.tsv <outDir>
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
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
import ghidra.program.model.data.ShortDataType;
import ghidra.program.model.data.StructureDataType;
import ghidra.program.model.data.Undefined1DataType;
import ghidra.program.model.data.Undefined4DataType;
import ghidra.program.model.data.VoidDataType;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.listing.ParameterImpl;
import ghidra.program.model.listing.Variable;
import ghidra.program.model.symbol.SourceType;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

public class ApplyStructs extends GhidraScript {

    private DataTypeManager dtm;

    @Override
    public void run() throws Exception {
        // Ghidra hands over every trailing argument; keep only the script ones
        List<String> raw = new ArrayList<>();
        for (String a : getScriptArgs()) {
            if (a != null && !a.startsWith("-")) {
                raw.add(a);
            }
        }
        String[] args = raw.toArray(new String[0]);
        String structsTsv = args.length > 0 ? args[0] : "ghidra_structs.tsv";
        String funcsTsv = args.length > 1 ? args[1] : "ghidra_funcs.tsv";
        String outDir = args.length > 2 ? args[2] : "C:/diggles-ghidra/out_typed";
        File dir = new File(outDir);
        dir.mkdirs();

        dtm = currentProgram.getDataTypeManager();

        // ---- 1. build one structure per class --------------------------
        Map<String, StructureDataType> drafts = new LinkedHashMap<>();
        for (String line : Files.readAllLines(Paths.get(structsTsv))) {
            if (line.startsWith("class\t") || line.trim().isEmpty()) {
                continue;
            }
            String[] p = line.split("\t");
            if (p.length < 4) {
                continue;
            }
            String cls = p[0].trim();
            int off = Integer.decode(p[1].trim());
            String field = p[2].trim();
            DataType dt = typeFor(p[3].trim());
            StructureDataType sdt = drafts.get(cls);
            if (sdt == null) {
                sdt = new StructureDataType(cls, 0);
                drafts.put(cls, sdt);
            }
            try {
                sdt.insertAtOffset(off, dt, dt.getLength(), field, "");
            } catch (Exception e) {
                // overlapping or invalid offset - skip that field
            }
        }

        Map<String, DataType> managed = new LinkedHashMap<>();
        for (Map.Entry<String, StructureDataType> e : drafts.entrySet()) {
            try {
                DataType added = dtm.addDataType(e.getValue(), DataTypeConflictHandler.REPLACE_HANDLER);
                managed.put(e.getKey(), added);
            } catch (Exception ex) {
                println("[ApplyStructs] cannot add struct " + e.getKey() + ": " + ex);
            }
        }
        println("[ApplyStructs] structures created: " + managed.size());

        // ---- 2. attach the structure to the `this` pointer --------------
        AddressSpace space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        FunctionManager fm = currentProgram.getFunctionManager();
        int applied = 0;
        int noFunc = 0;
        int noClass = 0;
        int failed = 0;
        List<String> touched = new ArrayList<>();
        for (String line : Files.readAllLines(Paths.get(funcsTsv))) {
            if (line.startsWith("address\t") || line.trim().isEmpty()) {
                continue;
            }
            String[] p = line.split("\t");
            if (p.length < 2) {
                continue;
            }
            DataType clsType = managed.get(p[1].trim());
            if (clsType == null) {
                noClass++;
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
            try {
                DataType ptrType = new PointerDataType(clsType, 4, dtm);
                if (!applyThisType(f, ptrType)) {
                    failed++;
                    println("[ApplyStructs] cannot type this: " + p[0]);
                    continue;
                }
                applied++;
                touched.add(p[0].trim() + "\t" + p[1].trim());
            } catch (Exception e) {
                failed++;
                println("[ApplyStructs] skip " + p[0] + ": " + e);
            }
        }
        println("[ApplyStructs] functions typed: " + applied
                + " (no class: " + noClass + ", no function: " + noFunc + ", failed: " + failed + ")");

        // ---- 3. re-export the touched functions -------------------------
        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.toggleCCode(true);
        ifc.openProgram(currentProgram);

        PrintWriter index = new PrintWriter(new BufferedWriter(
                new FileWriter(new File(dir, "index_typed.tsv"))));
        index.println("func\tentry\tlines\tfile");
        int exported = 0;
        for (String t : touched) {
            String[] p = t.split("\t");
            Address addr = space.getAddress(p[0]);
            Function f = fm.getFunctionAt(addr);
            if (f == null) {
                continue;
            }
            String c = "";
            try {
                DecompileResults res = ifc.decompileFunction(f, 60, monitor);
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
            index.println(f.getName() + "\t" + f.getEntryPoint() + "\t" + c.split("\n", -1).length + "\t" + fname);
            exported++;
        }
        index.flush();
        index.close();
        println("[ApplyStructs] exported: " + exported + " -> " + dir.getAbsolutePath());
        ifc.dispose();
    }

    /**
     * Type the implicit `this` pointer of a MSVC __thiscall method.
     *
     * Ghidra refuses insertParameter(0, ...) on a function that already owns an
     * auto-parameter ("Parameter may not be inserted before auto-parameter"),
     * and __thiscall creates exactly such an auto-parameter for ECX. The
     * parameter therefore has to be retyped in place; only if that is
     * refused do we fall back to rebuilding the whole parameter list.
     */
    private boolean applyThisType(Function f, DataType ptrType) {
        try {
            f.setCallingConvention("__thiscall");
        } catch (Exception e) {
            // convention unsupported - continue with the default one
        }
        Parameter[] ps = f.getParameters();
        if (ps.length > 0) {
            // A) retype the existing first parameter (the auto `this`)
            try {
                ps[0].setDataType(ptrType, SourceType.USER_DEFINED);
                return true;
            } catch (Exception e) {
                // B) rebuild the parameter list, keeping the ECX based storage
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
                    // C) last resort: a plain stack parameter
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

    private DataType typeFor(String name) {
        if ("int".equals(name)) {
            return new IntegerDataType();
        }
        if ("short".equals(name)) {
            return new ShortDataType();
        }
        if ("float".equals(name)) {
            return new FloatDataType();
        }
        if ("double".equals(name)) {
            return new DoubleDataType();
        }
        if ("char".equals(name)) {
            return new CharDataType();
        }
        if ("long long".equals(name)) {
            return new LongLongDataType();
        }
        if ("void *".equals(name)) {
            return new PointerDataType(new VoidDataType(), 4, dtm);
        }
        return new Undefined4DataType();
    }

    private String safe(String s) {
        return s.replaceAll("[^A-Za-z0-9_.-]", "_");
    }
}
