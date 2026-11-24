
void FUN_1000c790(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b81);
  cVar1 = *(char *)((int)param_2 + 0xd);
  while (cVar1 == '\0') {
    FUN_1000c790(param_1,param_2[2]);
    piVar2 = (int *)*param_2;
    iVar3 = param_2[5];
    if (iVar3 != 0) {
      FUN_100095b0();
      FUN_100402ac(iVar3,0x84);
    }
    FUN_100402ac(param_2,0x18);
    param_2 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0xd);
  }
  return;
}

