
void FUN_1000b5d0(void)

{
  int *piVar1;
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
  piVar1 = *(int **)(*DAT_10050c64 + 8);
  (**(code **)(*piVar1 + 0x2c))(piVar1,*(undefined4 *)(in_ECX + 0x54),0,0);
  (**(code **)(*piVar1 + 0x24))(piVar1,*(undefined4 *)(in_ECX + 0x58),0,0);
  (**(code **)(*piVar1 + 0x44))(piVar1,*(undefined4 *)(in_ECX + 0x60));
  ExceptionList = local_10;
  return;
}

