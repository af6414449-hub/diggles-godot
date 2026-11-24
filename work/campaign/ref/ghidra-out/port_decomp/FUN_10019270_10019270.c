
int FUN_10019270(int param_1)

{
  int *piVar1;
  int iVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar1 = (int *)(param_1 + 0x2c);
  LOCK();
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  iVar2 = *piVar1;
  if (iVar2 == 0) {
    FUN_100183c0(param_1);
    iVar2 = 0;
  }
  return iVar2;
}

