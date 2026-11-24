
void FUN_10007c90(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b79);
  uVar1 = param_2 * 0x10;
  iVar2 = param_1;
  if (0xfff < uVar1) {
    iVar2 = *(int *)(param_1 + -4);
    uVar1 = uVar1 + 0x23;
    if (0x1f < (param_1 - iVar2) - 4U) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
  }
  FUN_100402ac(iVar2,uVar1);
  return;
}

