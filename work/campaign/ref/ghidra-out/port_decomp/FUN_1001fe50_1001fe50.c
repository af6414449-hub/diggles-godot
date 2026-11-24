
void FUN_1001fe50(byte param_1)

{
  undefined4 *in_ECX;
  int *piVar1;
  int iVar2;
  
  iVar2 = 8;
  *in_ECX = SoLoud::AudioSourceInstance::vftable;
  piVar1 = in_ECX + 0x61;
  do {
    if ((int *)*piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 0x20))(1);
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if ((param_1 & 1) != 0) {
    FUN_100402ac();
  }
  return;
}

