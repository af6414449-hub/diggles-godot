
void FUN_10017920(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  void *_Dst;
  undefined4 extraout_ECX;
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041aa7;
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
  iVar1 = DAT_10050c64;
  FUN_1000f260();
  FUN_1000f890();
  FUN_1000f550();
  *(undefined4 *)(iVar1 + 0xc80) = 0;
  FUN_1000f0a0(param_1,param_2,param_3,param_4,param_5,param_6,extraout_ECX);
  ExceptionList = local_10;
  return;
}

