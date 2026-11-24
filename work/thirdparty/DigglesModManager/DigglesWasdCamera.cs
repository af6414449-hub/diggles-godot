// Diggles WASD camera helper.
//
// The original Diggles (2001) scrolls the camera with the arrow keys.
// This helper watches W/A/S/D and injects the matching arrow key into the
// Diggles window, so WASD scrolls the camera exactly like the arrows.
//
// Build:  csc /platform:x64 /optimize+ /out:DigglesWasdCamera.exe DigglesWasdCamera.cs
// Usage:  DigglesWasdCamera.exe            normal mode
//         DigglesWasdCamera.exe --selftest verify that key injection works
//         DigglesWasdCamera.exe --diag     print foreground window info only
//
// The arrow key is HELD down while the matching WASD key is held (and a
// keydown is repeated), because the engine may poll the key state instead of
// reacting to single keydown events.

using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Threading;

internal static class Program
{
    private const int VK_LEFT = 0x25;
    private const int VK_UP = 0x26;
    private const int VK_RIGHT = 0x27;
    private const int VK_DOWN = 0x28;

    private const int VK_A = 0x41;
    private const int VK_D = 0x44;
    private const int VK_S = 0x53;
    private const int VK_W = 0x57;

    private const int INPUT_KEYBOARD = 1;
    private const int KEYEVENTF_KEYUP = 0x0002;

    private const int REPEAT_MS = 40;      // repeat the arrow keydown while held
    private const int KEY_DOWN_DELAY = 80; // how long the arrow stays pressed

    [StructLayout(LayoutKind.Sequential)]
    private struct KEYBDINPUT
    {
        public ushort wVk;
        public ushort wScan;
        public uint dwFlags;
        public uint time;
        public IntPtr dwExtraInfo;
    }

    [StructLayout(LayoutKind.Sequential)]
    private struct INPUT
    {
        public uint type;
        public INPUTUNION U;
    }

    [StructLayout(LayoutKind.Sequential)]
    private struct MOUSEINPUT
    {
        public int dx;
        public int dy;
        public uint mouseData;
        public uint dwFlags;
        public uint time;
        public IntPtr dwExtraInfo;
    }

    [StructLayout(LayoutKind.Sequential)]
    private struct HARDWAREINPUT
    {
        public uint uMsg;
        public ushort wParamL;
        public ushort wParamH;
    }

    [StructLayout(LayoutKind.Explicit)]
    private struct INPUTUNION
    {
        [FieldOffset(0)] public MOUSEINPUT mi;
        [FieldOffset(0)] public KEYBDINPUT ki;
        [FieldOffset(0)] public HARDWAREINPUT hi;
    }

    [DllImport("user32.dll")]
    private static extern short GetAsyncKeyState(int vKey);

    [DllImport("user32.dll")]
    private static extern IntPtr GetForegroundWindow();

    [DllImport("user32.dll", CharSet = CharSet.Unicode)]
    private static extern int GetWindowTextW(IntPtr hWnd, System.Text.StringBuilder text, int count);

    [DllImport("user32.dll")]
    private static extern uint GetWindowThreadProcessId(IntPtr hWnd, out uint processId);

    [DllImport("user32.dll", SetLastError = true)]
    private static extern uint SendInput(uint nInputs, INPUT[] pInputs, int cbSize);

    private static string logPath = @"C:\Users\frant\AppData\Local\Temp\diggles-wasd.log";
    private static System.IO.StreamWriter logWriter = null;
    private static DateTime lastLog = DateTime.MinValue;

    private static void OpenLog()
    {
        try
        {
            logWriter = new System.IO.StreamWriter(logPath, true);
            logWriter.AutoFlush = true;
            Log("helper started");
        }
        catch { }
    }

    public static void Log(string text)
    {
        if (logWriter == null) return;
        try
        {
            logWriter.WriteLine(DateTime.Now.ToString("HH:mm:ss.fff") + "  " + text);
        }
        catch { }
    }

    private static int heldArrow = 0;      // arrow key currently held down
    private static DateTime heldSince = DateTime.MinValue;

    private static bool KeyDown(int vk)
    {
        return (GetAsyncKeyState(vk) & 0x8000) != 0;
    }

    private static uint SendKey(int vk, bool up)
    {
        INPUT[] inputs = new INPUT[1];
        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].U.ki.wVk = (ushort)vk;
        inputs[0].U.ki.wScan = 0;
        inputs[0].U.ki.dwFlags = up ? (uint)KEYEVENTF_KEYUP : (uint)0;
        inputs[0].U.ki.time = 0;
        inputs[0].U.ki.dwExtraInfo = IntPtr.Zero;
        uint sent = SendInput(1, inputs, Marshal.SizeOf(typeof(INPUT)));
        if (sent != 1)
        {
            Console.WriteLine("SendInput failed (sent " + sent + " of 1), error " +
                Marshal.GetLastWin32Error());
        }
        return sent;
    }

    private static void ReleaseHeld()
    {
        if (heldArrow != 0)
        {
            SendKey(heldArrow, true);
            heldArrow = 0;
        }
    }

    private static string ForegroundInfo(out bool isDiggles)
    {
        isDiggles = false;
        IntPtr hwnd = GetForegroundWindow();
        if (hwnd == IntPtr.Zero) return "<none>";
        uint pid;
        GetWindowThreadProcessId(hwnd, out pid);
        string proc = "?";
        try { proc = Process.GetProcessById((int)pid).ProcessName; }
        catch { }
        System.Text.StringBuilder sb = new System.Text.StringBuilder(256);
        GetWindowTextW(hwnd, sb, sb.Capacity);
        string title = sb.ToString();
        if (proc.Equals("Diggles", StringComparison.OrdinalIgnoreCase) ||
            title.IndexOf("Diggles", StringComparison.OrdinalIgnoreCase) >= 0)
        {
            isDiggles = true;
        }
        return proc + " / [" + title + "]";
    }

    private delegate IntPtr WndProcDelegate(IntPtr hWnd, uint msg, IntPtr wParam, IntPtr lParam);

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
    private struct WNDCLASSEX
    {
        public uint cbSize;
        public uint style;
        [MarshalAs(UnmanagedType.FunctionPtr)] public WndProcDelegate lpfnWndProc;
        public int cbClsExtra;
        public int cbWndExtra;
        public IntPtr hInstance;
        public IntPtr hIcon;
        public IntPtr hCursor;
        public IntPtr hbrBackground;
        [MarshalAs(UnmanagedType.LPWStr)] public string lpszMenuName;
        [MarshalAs(UnmanagedType.LPWStr)] public string lpszClassName;
        public IntPtr hIconSm;
    }

    [DllImport("user32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
    private static extern ushort RegisterClassEx(ref WNDCLASSEX wc);

    [DllImport("user32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
    private static extern IntPtr CreateWindowExW(uint ex, string cls, string title, uint style,
        int x, int y, int w, int h, IntPtr parent, IntPtr menu, IntPtr inst, IntPtr param);

    [DllImport("user32.dll")]
    private static extern IntPtr DefWindowProcW(IntPtr h, uint msg, IntPtr w, IntPtr l);

    [DllImport("user32.dll")]
    private static extern bool SetForegroundWindow(IntPtr h);

    [DllImport("user32.dll")]
    private static extern bool ShowWindow(IntPtr h, int cmd);

    [DllImport("user32.dll")]
    private static extern bool IsWindowVisible(IntPtr h);

    [DllImport("user32.dll")]
    private static extern IntPtr GetMessageW(out MSG msg, IntPtr h, uint min, uint max);

    [DllImport("user32.dll")]
    private static extern bool TranslateMessage(ref MSG msg);

    [DllImport("user32.dll")]
    private static extern IntPtr DispatchMessageW(ref MSG msg);

    [DllImport("user32.dll")]
    private static extern bool PeekMessageW(out MSG msg, IntPtr h, uint min, uint max, uint remove);

    [StructLayout(LayoutKind.Sequential)]
    private struct MSG
    {
        public IntPtr hwnd;
        public uint message;
        public IntPtr wParam;
        public IntPtr lParam;
        public uint time;
        public int pt_x;
        public int pt_y;
    }

    private static WndProcDelegate keepDelegate;
    private static int testKeyDowns = 0;
    private static uint testLastVk = 0;

    private static IntPtr TestWndProc(IntPtr h, uint msg, IntPtr w, IntPtr l)
    {
        if (msg == 0x0100) // WM_KEYDOWN
        {
            testKeyDowns++;
            testLastVk = (uint)w.ToInt64();
        }
        return DefWindowProcW(h, msg, w, l);
    }

    private static int SelfTest()
    {
        int size = Marshal.SizeOf(typeof(INPUT));
        Console.WriteLine("INPUT struct size: " + size + " bytes (expected 40 on x64)");

        keepDelegate = new WndProcDelegate(TestWndProc);
        WNDCLASSEX wc = new WNDCLASSEX();
        wc.cbSize = (uint)Marshal.SizeOf(typeof(WNDCLASSEX));
        wc.lpfnWndProc = keepDelegate;
        wc.hInstance = Process.GetCurrentProcess().Handle;
        wc.lpszClassName = "DigglesWasdTest";
        ushort cls = RegisterClassEx(ref wc);
        Console.WriteLine("RegisterClassEx -> " + cls + " (err " + Marshal.GetLastWin32Error() + ")");
        if (cls == 0) return 2;

        IntPtr hwnd = CreateWindowExW(0, "DigglesWasdTest", "test", 0x00CF0000,
            100, 100, 200, 100, IntPtr.Zero, IntPtr.Zero, wc.hInstance, IntPtr.Zero);
        Console.WriteLine("CreateWindowExW -> 0x" + hwnd.ToString("X"));
        if (hwnd == IntPtr.Zero) return 3;
        ShowWindow(hwnd, 5);
        SetForegroundWindow(hwnd);
        Thread.Sleep(300);

        SendKey(VK_LEFT, false);
        MSG m;
        DateTime until = DateTime.Now.AddMilliseconds(600);
        while (DateTime.Now < until)
        {
            while (PeekMessageW(out m, IntPtr.Zero, 0, 0, 1))
            {
                TranslateMessage(ref m);
                DispatchMessageW(ref m);
            }
            Thread.Sleep(10);
        }
        SendKey(VK_LEFT, true);
        Thread.Sleep(100);
        while (PeekMessageW(out m, IntPtr.Zero, 0, 0, 1))
        {
            TranslateMessage(ref m);
            DispatchMessageW(ref m);
        }

        Console.WriteLine("window received " + testKeyDowns + " WM_KEYDOWN, last vk=0x" +
                          testLastVk.ToString("X"));
        if (testKeyDowns > 0 && testLastVk == VK_LEFT)
        {
            Console.WriteLine("SELFTEST OK - injected key reaches a window.");
            return 0;
        }
        Console.WriteLine("SELFTEST FAILED - injected key did not reach the window.");
        return 1;
    }

    private static int Main(string[] args)
    {
        bool selftest = false, diag = false, sendarrow = false;
        int arrowVk = 0x25, arrowMs = 1000;
        for (int i = 0; i < args.Length; i++)
        {
            if (args[i] == "--selftest") selftest = true;
            if (args[i] == "--diag") diag = true;
            if (args[i] == "--sendarrow") { sendarrow = true; }
            if (args[i] == "--vk" && i + 1 < args.Length) { int.TryParse(args[++i], out arrowVk); }
            if (args[i] == "--ms" && i + 1 < args.Length) { int.TryParse(args[++i], out arrowMs); }
        }

        if (selftest) return SelfTest();

        OpenLog();

        if (sendarrow)
        {
            Log("sendarrow mode: vk=0x" + arrowVk.ToString("X") + " for " + arrowMs + " ms");
            SendKey(arrowVk, false);
            Thread.Sleep(arrowMs);
            SendKey(arrowVk, true);
            Log("sendarrow done");
            Thread.Sleep(300);
            return 0;
        }

        Console.WriteLine("Diggles WASD camera helper");
        Console.WriteLine("  W = up, A = left, S = down, D = right (camera scroll)");
        Console.WriteLine("  keys are injected only while the Diggles window has focus");
        Console.WriteLine("  log file: " + logPath);
        Console.WriteLine("  press Ctrl+C to quit");
        Console.WriteLine();

        if (diag)
        {
            while (true)
            {
                bool isD;
                string info = ForegroundInfo(out isD);
                Console.WriteLine(DateTime.Now.ToString("HH:mm:ss") + " foreground: " + info +
                                  (isD ? "   <== DIGGLES" : ""));
                Thread.Sleep(1000);
            }
        }

        long injected = 0;
        while (true)
        {
            bool isD;
            ForegroundInfo(out isD);

            int arrow = 0;
            if (isD)
            {
                if (KeyDown(VK_W)) arrow = VK_UP;
                else if (KeyDown(VK_S)) arrow = VK_DOWN;
                else if (KeyDown(VK_A)) arrow = VK_LEFT;
                else if (KeyDown(VK_D)) arrow = VK_RIGHT;
            }

            if (arrow == 0)
            {
                ReleaseHeld();
                Thread.Sleep(20);
                continue;
            }

            if (arrow != heldArrow)
            {
                ReleaseHeld();
                heldArrow = arrow;
                heldSince = DateTime.Now;
                SendKey(arrow, false);
                injected++;
            }
            else if ((DateTime.Now - heldSince).TotalMilliseconds >= KEY_DOWN_DELAY)
            {
                // repeat the keydown so engines that react to keydown events
                // keep scrolling while the key is held
                SendKey(arrow, false);
                heldSince = DateTime.Now;
                injected++;
            }

            if (injected % 20 == 0)
            {
                Console.WriteLine("injected " + injected + " arrow keydowns");
            }
            Thread.Sleep(REPEAT_MS);
        }
    }
}
