
undefined4 FUN_10018ce0(int *param_1,int param_2)

{
  void *_Dst;
  int iVar1;
  int *in_ECX;
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
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
  (**(code **)(*in_ECX + 100))(param_2);
  *(int *)(param_2 + 0x24) = in_ECX[0x33];
  *(int *)(param_2 + 0x10) = in_ECX[0x3d];
  if (param_1 == (int *)0x0) {
    in_ECX[0x43] = in_ECX[0xe];
    iVar1 = in_ECX[0xd];
    in_ECX[0x41] = 0;
    in_ECX[0x40] = 0;
  }
  else {
    in_ECX[0x41] = param_1[1];
    in_ECX[0x43] = param_1[3];
    in_ECX[0x40] = *param_1;
    iVar1 = param_1[2];
  }
  in_ECX[0x42] = iVar1;
  ExceptionList = local_10;
  return 0;
}

