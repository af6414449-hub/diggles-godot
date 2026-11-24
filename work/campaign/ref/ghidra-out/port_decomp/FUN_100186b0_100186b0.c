
int FUN_100186b0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar1 = (int *)(param_1 + 4);
  LOCK();
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  iVar2 = *piVar1;
  if (iVar2 == 0) {
    FUN_1000ed60();
    FUN_100402ac(param_1,8);
    iVar2 = 0;
  }
  return iVar2;
}

