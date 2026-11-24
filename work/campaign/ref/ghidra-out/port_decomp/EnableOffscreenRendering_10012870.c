
/* public: void __thiscall ScreenResolutionManager::EnableOffscreenRendering(bool) */

void __thiscall
ScreenResolutionManager::EnableOffscreenRendering(ScreenResolutionManager *this,bool param_1)

{
  void *_Dst;
  int iVar1;
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x12870  120  ?EnableOffscreenRendering@ScreenResolutionManager@@QAEX_N@Z */
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041aa7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  if (DAT_10050c64 == (int *)0x0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    iVar1 = *DAT_10050c64;
  }
  else {
    iVar1 = *DAT_10050c64;
  }
  *(bool *)(iVar1 + 0xc5) = param_1;
  ExceptionList = local_10;
  return;
}

