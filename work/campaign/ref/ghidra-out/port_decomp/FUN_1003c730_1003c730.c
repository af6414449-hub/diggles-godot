
void FUN_1003c730(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int in_ECX;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar1 = FUN_1003ba30(&local_c,param_2,&local_8,&local_10);
  if (iVar1 == 0) {
    return;
  }
  FUN_1003bc80(in_ECX + (local_10 * 3 + 0xd4) * 2,*param_1,local_c,*param_2,local_8,param_1);
  return;
}

