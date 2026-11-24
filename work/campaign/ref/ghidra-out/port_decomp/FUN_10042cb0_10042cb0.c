
void FUN_10042cb0(void)

{
  uint uVar1;
  uint uVar2;
  
  if (0xf < DAT_10050124) {
    uVar2 = DAT_10050124 + 1;
    uVar1 = DAT_10050110;
    if (0xfff < uVar2) {
      uVar1 = *(uint *)(DAT_10050110 - 4);
      uVar2 = DAT_10050124 + 0x24;
      if (0x1f < (DAT_10050110 - uVar1) - 4) {
                    /* WARNING: Could not recover jumptable at 0x10042cdc. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
        _invalid_parameter_noinfo_noreturn();
        return;
      }
    }
    FUN_100402ac(uVar1,uVar2);
  }
  DAT_10050120 = 0;
  DAT_10050124 = 0xf;
  DAT_10050110 = DAT_10050110 & 0xffffff00;
  return;
}

