
uint FUN_1000b850(uint param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b79);
  if (param_1 < 0x80000000) {
    param_1 = param_1 * 2;
    if (param_1 < 0x1000) {
      if (param_1 != 0) {
        uVar3 = FUN_1003ff62(param_1);
        return uVar3;
      }
      return 0;
    }
    if (param_1 < param_1 + 0x23) {
      iVar2 = FUN_1003ff62(param_1 + 0x23);
      if (iVar2 != 0) {
        uVar3 = iVar2 + 0x23U & 0xffffffe0;
        *(int *)(uVar3 - 4) = iVar2;
        return uVar3;
      }
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
  }
  FUN_10002a00();
  pcVar1 = (code *)swi(3);
  uVar3 = (*pcVar1)();
  return uVar3;
}

