
void FUN_1000f890(void)

{
  int *piVar1;
  int *in_ECX;
  int *piVar2;
  int iVar3;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar3 = 0;
  piVar2 = in_ECX + 0x20d;
  piVar1 = *(int **)(*in_ECX + 8);
  do {
    if (piVar2[-8] != 0) {
      (**(code **)(*piVar1 + 0x20))(piVar1,iVar3,1,piVar2);
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar3 < 8);
  (**(code **)(*piVar1 + 0x1c))(piVar1,1,1,in_ECX + 0x329);
  (**(code **)(*piVar1 + 0x40))(piVar1,1,1,in_ECX + 0x329);
  return;
}

