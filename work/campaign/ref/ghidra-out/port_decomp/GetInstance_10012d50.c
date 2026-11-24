
/* public: static class ScreenResolutionManager * __cdecl ScreenResolutionManager::GetInstance(void)
    */

ScreenResolutionManager * __cdecl ScreenResolutionManager::GetInstance(void)

{
  ScreenResolutionManager *this;
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x12d50  152  ?GetInstance@ScreenResolutionManager@@SAPAV1@XZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042644;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  if (s_instance == (ScreenResolutionManager *)0x0) {
    this = (ScreenResolutionManager *)FUN_1003ff62(0x2c);
    local_8 = 0;
    memset(this,0,0x2c);
    s_instance = (ScreenResolutionManager *)ScreenResolutionManager(this);
  }
  ExceptionList = local_10;
  return s_instance;
}

