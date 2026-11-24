
void FUN_100040d0(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b81);
  cVar1 = *(char *)((int)param_2 + 0xd);
  while (cVar1 == '\0') {
    FUN_100040d0(param_1,param_2[2]);
    piVar2 = (int *)*param_2;
    FUN_100402ac(param_2,0x18);
    param_2 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0xd);
  }
  return;
}

