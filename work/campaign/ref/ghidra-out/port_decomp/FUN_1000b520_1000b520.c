
undefined4 FUN_1000b520(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  void *_Dst;
  int in_ECX;
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041f97;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  if (DAT_10050c64 == (int *)0x0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  piVar2 = *(int **)(*DAT_10050c64 + 8);
  puVar1 = (undefined4 *)(in_ECX + (param_2 + 0x19) * 4);
  *puVar1 = param_1;
  (**(code **)(*piVar2 + 0x28))(piVar2,param_2,1,puVar1);
  ExceptionList = local_10;
  return 0;
}

