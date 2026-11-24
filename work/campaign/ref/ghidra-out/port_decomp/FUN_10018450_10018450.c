
int FUN_10018450(CSdlWindowHandle *param_1,undefined4 param_2,undefined4 param_3)

{
  HWND__ *pHVar1;
  void *_Dst;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042ab7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  if (DAT_1416ead0 == '\0') {
    pHVar1 = CSdlWindowHandle::GetHWnd(param_1);
    uVar3 = extraout_ECX;
    if (DAT_10050c64 == 0) {
      _Dst = (void *)FUN_1003ff62(0xcbc);
      local_8 = 0;
      memset(_Dst,0,0xcbc);
      DAT_10050c64 = FUN_1000e160();
      local_8 = 0xffffffff;
      uVar3 = extraout_ECX_00;
    }
    iVar2 = FUN_1000f900(pHVar1,uVar3,param_3);
    DAT_1416ead0 = -1 < iVar2;
    ExceptionList = local_10;
    return iVar2;
  }
  WindowResourcesRecreate(param_1);
  ExceptionList = local_10;
  return 0;
}

