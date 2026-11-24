
void FUN_10010f40(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_ECX;
  uint uVar3;
  int iVar4;
  
  __CheckForDebuggerJustMyCode(&DAT_14170af7);
  iVar4 = in_ECX[4];
  if (iVar4 != 0) {
    do {
      iVar4 = iVar4 + -1;
      in_ECX[4] = iVar4;
    } while (iVar4 != 0);
    in_ECX[3] = 0;
  }
  iVar4 = in_ECX[2];
  while (iVar4 != 0) {
    iVar4 = iVar4 + -1;
    iVar2 = *(int *)(in_ECX[1] + iVar4 * 4);
    if (iVar2 != 0) {
      FUN_100402ac(iVar2,0x10);
    }
  }
  iVar4 = in_ECX[1];
  if (iVar4 != 0) {
    uVar3 = in_ECX[2] * 4;
    iVar2 = iVar4;
    if (0xfff < uVar3) {
      iVar2 = *(int *)(iVar4 + -4);
      uVar3 = uVar3 + 0x23;
      if (0x1f < (iVar4 - iVar2) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_100402ac(iVar2,uVar3);
  }
  uVar1 = *in_ECX;
  in_ECX[2] = 0;
  in_ECX[1] = 0;
  *in_ECX = 0;
  FUN_100402ac(uVar1,8);
  return;
}

