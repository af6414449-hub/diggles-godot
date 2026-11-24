
undefined4 FUN_10016e80(void)

{
  int iVar1;
  void *_Dst;
  int in_ECX;
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041aa7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  iVar1 = DAT_10050c64;
  *(undefined1 *)(in_ECX + 0x68) = 1;
  if (iVar1 == 0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = FUN_1000e160();
    local_8 = 0xffffffff;
  }
  FUN_1000fe70();
  ExceptionList = local_10;
  return 0;
}

