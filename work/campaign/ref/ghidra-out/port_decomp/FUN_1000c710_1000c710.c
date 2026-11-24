
void FUN_1000c710(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *in_ECX;
  uint uVar4;
  undefined4 extraout_EDX;
  undefined4 unaff_ESI;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b79);
  piVar2 = (int *)*in_ECX;
  if (piVar2 == (int *)0x0) {
    return;
  }
  __CheckForDebuggerJustMyCode(&DAT_14170b08,extraout_EDX,unaff_ESI);
  if (*piVar2 != 0) {
    FUN_1000c690(*piVar2);
    iVar1 = *piVar2;
    uVar4 = (piVar2[2] - iVar1 >> 3) * 8;
    iVar3 = iVar1;
    if (0xfff < uVar4) {
      iVar3 = *(int *)(iVar1 + -4);
      uVar4 = uVar4 + 0x23;
      if (0x1f < (iVar1 - iVar3) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_100402ac(iVar3,uVar4);
    *piVar2 = 0;
    piVar2[1] = 0;
    piVar2[2] = 0;
  }
  return;
}

