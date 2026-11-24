// Verify the DigglesPort.dll scancode -> VK mapping by calling GetVKScanCode.
// Usage: WasdVerify.exe <path-to-DigglesPort.dll>
using System;
using System.Runtime.InteropServices;

class WasdVerify
{
    [UnmanagedFunctionPointer(CallingConvention.StdCall)]
    delegate uint GetVKDelegate(uint code);

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Ansi)]
    static extern IntPtr LoadLibrary(string path);

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Ansi)]
    static extern IntPtr GetProcAddress(IntPtr h, string name);

    [DllImport("kernel32.dll")]
    static extern uint GetLastError();

    static string Name(uint vk)
    {
        switch (vk)
        {
            case 0x25: return "VK_LEFT";
            case 0x26: return "VK_UP";
            case 0x27: return "VK_RIGHT";
            case 0x28: return "VK_DOWN";
            case 0x41: return "VK_A";
            case 0x44: return "VK_D";
            case 0x53: return "VK_S";
            case 0x57: return "VK_W";
            case 0x30: return "VK_0";
            case 0x31: return "VK_1";
            case 0x70: return "VK_F1";
            default: return "";
        }
    }

    static int Main(string[] args)
    {
        string path = args.Length > 0 ? args[0] : "DigglesPort.dll";
        IntPtr h = LoadLibrary(path);
        if (h == IntPtr.Zero)
        {
            Console.WriteLine("LoadLibrary failed: " + GetLastError());
            return 1;
        }
        IntPtr fn = GetProcAddress(h, "?GetVKScanCode@@YAGG@Z");
        if (fn == IntPtr.Zero)
        {
            Console.WriteLine("GetVKScanCode not found");
            return 1;
        }
        GetVKDelegate getvk = (GetVKDelegate)Marshal.GetDelegateForFunctionPointer(fn, typeof(GetVKDelegate));

        int[] scancodes = { 4, 7, 22, 26, 79, 80, 81, 82, 30, 58 };
        string[] labels = { "A", "D", "S", "W", "Right", "Left", "Down", "Up", "1", "F1" };
        Console.WriteLine("file: " + path);
        for (int i = 0; i < scancodes.Length; i++)
        {
            uint vk = getvk((uint)scancodes[i]);
            Console.WriteLine("  scancode {0,-3} ({1,-5}) -> VK 0x{2:X2} {3}",
                scancodes[i], labels[i], vk, Name(vk));
        }
        return 0;
    }
}
