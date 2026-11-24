
void FUN_100107f0(void)

{
  int in_ECX;
  undefined4 in_EDX;
  uint uVar1;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  local_8 = 0xfffffffe;
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_1005000c ^ 0x10049ae0;
  ExceptionList = &local_14;
  __CheckForDebuggerJustMyCode(&DAT_1417051d,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  for (uVar1 = 0; uVar1 < 7; uVar1 = uVar1 + 1) {
    *(undefined4 *)(in_ECX + uVar1 * 4) = 0;
  }
  local_8 = 0xfffffffe;
  FUN_1001087e();
  ExceptionList = local_14;
  return;
}

