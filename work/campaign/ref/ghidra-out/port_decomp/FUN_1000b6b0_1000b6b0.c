
void FUN_1000b6b0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b7b);
  if (7 < (uint)in_ECX[5]) {
    iVar2 = *in_ECX;
    iVar1 = in_ECX[5] * 2;
    uVar4 = iVar1 + 2;
    iVar3 = iVar2;
    if (0xfff < uVar4) {
      iVar3 = *(int *)(iVar2 + -4);
      uVar4 = iVar1 + 0x25;
      if (0x1f < (iVar2 - iVar3) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_100402ac(iVar3,uVar4);
  }
  in_ECX[4] = 0;
  in_ECX[5] = 7;
  *(undefined2 *)in_ECX = 0;
  return;
}

