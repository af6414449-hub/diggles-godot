
/* public: int __thiscall ScreenResolutionManager::GetPrevInCycle(void) */

int __thiscall ScreenResolutionManager::GetPrevInCycle(ScreenResolutionManager *this)

{
  void *_Dst;
  int iVar1;
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x12580  168  ?GetPrevInCycle@ScreenResolutionManager@@QAEHXZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_100425c7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  if (DAT_10050c64 == 0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = FUN_1000e160();
    local_8 = 0xffffffff;
  }
  iVar1 = FUN_10010190(*(undefined4 *)(this + 8),0);
  *(int *)(this + 8) = iVar1;
  ExceptionList = local_10;
  return iVar1;
}

