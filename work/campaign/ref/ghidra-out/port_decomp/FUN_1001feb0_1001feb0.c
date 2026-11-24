
void FUN_1001feb0(void)

{
  undefined4 *in_ECX;
  int *piVar1;
  int iVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *in_ECX = SoLoud::AudioSourceInstance::vftable;
  iVar2 = 8;
  piVar1 = in_ECX + 0x61;
  do {
    if ((int *)*piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 0x20))(1);
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

