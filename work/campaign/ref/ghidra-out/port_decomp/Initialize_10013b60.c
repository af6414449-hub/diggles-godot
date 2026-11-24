
/* private: void __thiscall CSdlManager::Initialize(void) */

void __thiscall CSdlManager::Initialize(CSdlManager *this)

{
  HMODULE hModule;
  int iVar1;
  ScreenResolutionManager *this_00;
  undefined4 in_EDX;
  undefined1 local_28 [12];
  FARPROC local_1c;
  HMODULE local_18;
  ScreenResolutionManager *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
                    /* 0x13b60  185  ?Initialize@CSdlManager@@AAEXXZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1004275c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  local_1c = (FARPROC)0x0;
  hModule = LoadLibraryW(L"Shcore.dll");
  local_18 = hModule;
  if (hModule != (HMODULE)0x0) {
    local_1c = GetProcAddress(hModule,"SetProcessDpiAwareness");
    if (local_1c != (FARPROC)0x0) {
      (*local_1c)(2);
      goto LAB_10013bcb;
    }
  }
  SetProcessDPIAware();
LAB_10013bcb:
  local_8 = 0;
  iVar1 = SDL_Init(0x20);
  if (-1 < iVar1) {
    if (ScreenResolutionManager::s_instance == (ScreenResolutionManager *)0x0) {
      this_00 = (ScreenResolutionManager *)FUN_1003ff62(0x2c);
      local_8._0_1_ = 1;
      local_14 = this_00;
      memset(this_00,0,0x2c);
      ScreenResolutionManager::s_instance =
           (ScreenResolutionManager *)ScreenResolutionManager::ScreenResolutionManager(this_00);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    ScreenResolutionManager::FillDisplayBounds(ScreenResolutionManager::s_instance);
    if (hModule != (HMODULE)0x0) {
      FreeLibrary(hModule);
    }
    ExceptionList = local_10;
    return;
  }
  FUN_100052e0("Error init SDL");
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_1004a25c);
}

