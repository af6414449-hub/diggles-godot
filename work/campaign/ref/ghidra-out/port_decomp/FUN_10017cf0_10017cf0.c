
undefined4 FUN_10017cf0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *(int *)(in_ECX + 0x14);
  *param_1 = iVar1;
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = 0x80004005;
  }
  return uVar2;
}

