
void FUN_1000c610(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  uint uVar3;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b08);
  if (*in_ECX != 0) {
    FUN_1000c690(*in_ECX);
    iVar1 = *in_ECX;
    uVar3 = (in_ECX[2] - iVar1 >> 3) * 8;
    iVar2 = iVar1;
    if (0xfff < uVar3) {
      iVar2 = *(int *)(iVar1 + -4);
      uVar3 = uVar3 + 0x23;
      if (0x1f < (iVar1 - iVar2) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_100402ac(iVar2,uVar3);
    *in_ECX = 0;
    in_ECX[1] = 0;
    in_ECX[2] = 0;
  }
  return;
}

