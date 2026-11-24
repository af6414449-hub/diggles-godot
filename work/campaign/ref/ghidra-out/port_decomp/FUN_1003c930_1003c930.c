
void FUN_1003c930(void)

{
  int iVar1;
  int in_ECX;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14 [2];
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar1 = FUN_1003ba30(&local_1c,local_14,&local_18,&local_20);
  if (iVar1 == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  iVar1 = FUN_1003bc80(in_ECX + (local_20 * 3 + 0xd4) * 2,local_c,local_1c,local_14[0],local_18,
                       &local_c);
  if (iVar1 != 0) {
    FUN_1003c7b0(local_c,local_14[0]);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

