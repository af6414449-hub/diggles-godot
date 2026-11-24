// Headless Ghidra post-script: export decompiled C for every function and
// build an index. Optionally rename functions from a "name<TAB>va" TSV so the
// exported C carries meaningful names (native Tcl commands, RTTI classes).
//
// Usage:
//   analyzeHeadless <proj> <name> -import Diggles.exe \
//     -postScript ExportDiggles.java <outDir> [<names.tsv>]
//
// Output:
//   <outDir>/decomp/<func>.c      one file per function
//   <outDir>/index.tsv            name, entry, size, lines, file
//   <outDir>/strings.tsv          defined strings with addresses
//   <outDir>/classes.txt          RTTI classes detected by Ghidra
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.DataIterator;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ExportDiggles extends GhidraScript {

    private static final int MAX_C_BYTES = 400_000;

    private DecompInterface ifc;

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
        String outDir = args.length > 0 ? args[0] : "C:/ghidra-out";
        File dir = new File(outDir);
        File decompDir = new File(dir, "decomp");
        decompDir.mkdirs();
        boolean onlyNamed = args.length > 3 && "ONLY".equalsIgnoreCase(args[3]);
        println("[ExportDiggles] output: " + dir.getAbsolutePath() + (onlyNamed ? " (named only)" : ""));

        applyNames(args.length > 1 ? args[1] : null);
        applyMethodNames(args.length > 2 ? args[2] : null);

        ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.toggleCCode(true);
        ifc.toggleSyntaxTree(true);
        ifc.setSimplificationStyle("decompile");
        ifc.openProgram(currentProgram);

        PrintWriter index = new PrintWriter(new BufferedWriter(
                new FileWriter(new File(dir, onlyNamed ? "index_named.tsv" : "index.tsv"))));
        index.println("func\tentry\tsize\tlines\tfile\tstatus");

        FunctionIterator funcs = currentProgram.getFunctionManager().getFunctions(true);
        int count = 0;
        int failed = 0;
        while (funcs.hasNext() && !monitor.isCancelled()) {
            Function f = funcs.next();
            if (onlyNamed && f.getName().startsWith("FUN_")) {
                continue;
            }
            count++;
            String c = "";
            String status = "ok";
            try {
                DecompileResults res = ifc.decompileFunction(f, 60, monitor);
                if (res != null && res.decompileCompleted() && res.getDecompiledFunction() != null) {
                    c = res.getDecompiledFunction().getC();
                } else {
                    status = "decompile-failed";
                }
            } catch (Exception e) {
                status = "error:" + e.getClass().getSimpleName();
            }
            if (c.length() > MAX_C_BYTES) {
                status = status + ",truncated";
                c = c.substring(0, MAX_C_BYTES);
            }
            String fname = safeName(f.getName()) + "_" + f.getEntryPoint();
            if (onlyNamed) {
                // drop the stale default-named file for the same address
                String suffix = "_" + f.getEntryPoint() + ".c";
                File[] stale = decompDir.listFiles((d, n) -> n.endsWith(suffix) && !n.equals(fname + ".c"));
                if (stale != null) {
                    for (File sf : stale) {
                        sf.delete();
                    }
                }
            }
            File cf = new File(decompDir, fname + ".c");
            try (PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter(cf)))) {
                w.print(c);
            }
            int lines = c.isEmpty() ? 0 : c.split("\n", -1).length;
            index.println(f.getName() + "\t" + f.getEntryPoint() + "\t" + f.getBody().getNumAddresses()
                    + "\t" + lines + "\t" + fname + ".c\t" + status);
            if (status.startsWith("error") || status.startsWith("decompile-failed")) {
                failed++;
            }
            if (count % 500 == 0) {
                index.flush();
                println("[ExportDiggles] " + count + " functions, " + failed + " failed");
            }
        }
        index.flush();
        index.close();
        println("[ExportDiggles] done: " + count + " functions, " + failed + " failed");

        exportStrings(dir, onlyNamed);
        exportClasses(dir, onlyNamed);
        ifc.dispose();
    }

    /** Rename functions from a TSV "name<TAB>0xVA" list (native Tcl commands). */
    private void applyNames(String tsv) throws Exception {
        if (tsv == null) {
            return;
        }
        List<String> lines = Files.readAllLines(Paths.get(tsv));
        int renamed = 0;
        for (String line : lines) {
            if (line.startsWith("#") || line.trim().isEmpty()) {
                continue;
            }
            String[] parts = line.split("\t");
            if (parts.length < 2) {
                continue;
            }
            String name = parts[0].trim();
            String va = parts[1].trim();
            try {
                Address addr = currentProgram.getAddressFactory().getDefaultAddressSpace()
                        .getAddress(va.startsWith("0x") ? va.substring(2) : va);
                Function f = currentProgram.getFunctionManager().getFunctionAt(addr);
                if (f != null) {
                    f.setName("TclCmd_" + name, SourceType.USER_DEFINED);
                    renamed++;
                }
            } catch (Exception e) {
                // address not mapped / no function there
            }
        }
        println("[ExportDiggles] renamed " + renamed + " functions from " + tsv);
    }

    /**
     * Rename functions using the engine's own assert strings:
     * "prefix<TAB>class<TAB>method<TAB>func_va<TAB>..." -> Class::method.
     */
    private void applyMethodNames(String tsv) throws Exception {
        if (tsv == null) {
            return;
        }
        List<String> lines = Files.readAllLines(Paths.get(tsv));
        Map<String, String> wanted = new HashMap<>();
        for (String line : lines) {
            if (line.startsWith("prefix") || line.trim().isEmpty()) {
                continue;
            }
            String[] p = line.split("\t");
            if (p.length < 4 || p[3] == null || p[3].isEmpty()) {
                continue;
            }
            String cls = p[1].trim();
            String method = p[2].trim();
            String funcVa = p[3].trim();
            String name = cls.replaceAll("[^A-Za-z0-9_]", "_") + "__"
                    + method.replaceAll("[^A-Za-z0-9_]", "_");
            // first match wins: assert strings are ordered by address
            wanted.putIfAbsent(funcVa, name);
        }
        int renamed = 0;
        for (Map.Entry<String, String> e : wanted.entrySet()) {
            try {
                Address addr = currentProgram.getAddressFactory().getDefaultAddressSpace()
                        .getAddress(e.getKey().startsWith("0x") ? e.getKey().substring(2) : e.getKey());
                Function f = currentProgram.getFunctionManager().getFunctionAt(addr);
                if (f != null) {
                    f.setName(e.getValue(), SourceType.USER_DEFINED);
                    renamed++;
                }
            } catch (Exception ex) {
                // skip unmapped
            }
        }
        println("[ExportDiggles] renamed " + renamed + " methods from " + tsv);
    }

    private void exportStrings(File dir, boolean suffix) throws Exception {
        PrintWriter w = new PrintWriter(new BufferedWriter(
                new FileWriter(new File(dir, suffix ? "strings_named.tsv" : "strings.tsv"))));
        w.println("address\tlength\ttext");
        Memory mem = currentProgram.getMemory();
        DataIterator it = currentProgram.getListing().getDefinedData(true);
        while (it.hasNext()) {
            Data d = it.next();
            if (d.getLength() < 4) {
                continue;
            }
            Object v = null;
            try {
                v = d.getValue();
            } catch (Exception e) {
                v = null;
            }
            String text = null;
            if (v instanceof String) {
                text = (String) v;
            } else {
                try {
                    byte[] bytes = new byte[d.getLength()];
                    mem.getBytes(d.getAddress(), bytes);
                    StringBuilder sb = new StringBuilder();
                    boolean printable = true;
                    for (byte b : bytes) {
                        int c = b & 0xFF;
                        if (c == 0) {
                            break;
                        }
                        if (c < 32 || c > 126) {
                            printable = false;
                            break;
                        }
                        sb.append((char) c);
                    }
                    if (printable && sb.length() >= 4) {
                        text = sb.toString();
                    }
                } catch (Exception e) {
                    // unreadable
                }
            }
            if (text != null && !text.isEmpty()) {
                w.println(d.getAddress() + "\t" + d.getLength() + "\t" + text.replace("\t", " "));
            }
        }
        w.flush();
        w.close();
    }

    private void exportClasses(File dir, boolean suffix) throws Exception {
        PrintWriter w = new PrintWriter(new BufferedWriter(
                new FileWriter(new File(dir, suffix ? "classes_named.txt" : "classes.txt"))));
        Map<String, Integer> classes = new HashMap<>();
        SymbolIterator syms = currentProgram.getSymbolTable().getAllSymbols(true);
        while (syms.hasNext()) {
            Symbol s = syms.next();
            String name = s.getName();
            if (name.startsWith("class ")) {
                String cls = name.substring(6).trim();
                classes.merge(cls, 1, Integer::sum);
            }
        }
        classes.forEach((k, v) -> w.println(k + "\t" + v));
        w.flush();
        w.close();
    }

    private String safeName(String s) {
        return s.replaceAll("[^A-Za-z0-9_.-]", "_");
    }
}
