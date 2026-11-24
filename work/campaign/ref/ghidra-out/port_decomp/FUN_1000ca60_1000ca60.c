
void FUN_1000ca60(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b81);
  iVar2 = *in_ECX;
  piVar3 = *(int **)(iVar2 + 4);
  if (*(char *)((int)*(int **)(iVar2 + 4) + 0xd) == '\0') {
    do {
      FUN_1000cab0(in_ECX,piVar3[2]);
      piVar1 = (int *)*piVar3;
      FUN_100402ac(piVar3,0x14);
      piVar3 = piVar1;
    } while (*(char *)((int)piVar1 + 0xd) == '\0');
    iVar2 = *in_ECX;
  }
  FUN_100402ac(iVar2,0x14);
  return;
}

