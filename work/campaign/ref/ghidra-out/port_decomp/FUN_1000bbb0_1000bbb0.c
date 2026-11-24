
void FUN_1000bbb0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 *in_ECX;
  undefined4 extraout_EDX;
  undefined4 unaff_ESI;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b79);
  piVar3 = (int *)*in_ECX;
  if (piVar3 == (int *)0x0) {
    return;
  }
  __CheckForDebuggerJustMyCode(&DAT_14170b7b,extraout_EDX,unaff_ESI);
  if (7 < (uint)piVar3[5]) {
    iVar2 = *piVar3;
    iVar1 = piVar3[5] * 2;
    uVar5 = iVar1 + 2;
    iVar4 = iVar2;
    if (0xfff < uVar5) {
      iVar4 = *(int *)(iVar2 + -4);
      uVar5 = iVar1 + 0x25;
      if (0x1f < (iVar2 - iVar4) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_100402ac(iVar4,uVar5);
  }
  piVar3[4] = 0;
  piVar3[5] = 7;
  *(undefined2 *)piVar3 = 0;
  return;
}

