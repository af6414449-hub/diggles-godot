
void FUN_1000bbd0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  FUN_1000aec0();
  uVar1 = *(uint *)(in_ECX + 0x18);
  if (0xf < uVar1) {
    iVar2 = *(int *)(in_ECX + 4);
    uVar4 = uVar1 + 1;
    iVar3 = iVar2;
    if (0xfff < uVar4) {
      iVar3 = *(int *)(iVar2 + -4);
      uVar4 = uVar1 + 0x24;
      if (0x1f < (iVar2 - iVar3) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_100402ac(iVar3,uVar4);
  }
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined1 *)(in_ECX + 4) = 0;
  return;
}

