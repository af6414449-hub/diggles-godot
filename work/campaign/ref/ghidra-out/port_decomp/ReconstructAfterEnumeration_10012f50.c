
/* public: void __thiscall ScreenResolutionManager::ReconstructAfterEnumeration(unsigned
   int,unsigned int,int) */

void __thiscall
ScreenResolutionManager::ReconstructAfterEnumeration
          (ScreenResolutionManager *this,uint param_1,uint param_2,int param_3)

{
  void *_Dst;
  undefined4 uVar1;
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x12f50  221  ?ReconstructAfterEnumeration@ScreenResolutionManager@@QAEXIIH@Z
                        */
  local_8 = 0xffffffff;
  puStack_c = &LAB_100425c7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  FillResolutions(this,param_3);
  *(uint *)(this + 0x14) = param_1;
  *(uint *)(this + 0x18) = param_2;
  if (DAT_10050c64 == 0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = FUN_1000e160();
    local_8 = 0xffffffff;
  }
  uVar1 = FUN_100078b0(param_1,param_2,param_3);
  *(undefined4 *)(this + 8) = uVar1;
  *(undefined4 *)(this + 0xc) = 0xffffffff;
  Update(this);
  ExceptionList = local_10;
  return;
}

