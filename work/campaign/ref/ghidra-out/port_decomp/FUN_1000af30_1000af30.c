
void FUN_1000af30(uint param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  uint *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b08);
  if (param_1 < 0x924924a) {
    param_1 = param_1 * 0x1c;
    if (param_1 < 0x1000) {
      if (param_1 != 0) {
        uVar3 = FUN_1003ff62(param_1);
        *in_ECX = uVar3;
        in_ECX[1] = uVar3;
        in_ECX[2] = uVar3 + param_1;
        return;
      }
      *in_ECX = 0;
      in_ECX[1] = 0;
      in_ECX[2] = 0;
      return;
    }
    if (param_1 < param_1 + 0x23) {
      iVar2 = FUN_1003ff62(param_1 + 0x23);
      if (iVar2 != 0) {
        uVar3 = iVar2 + 0x23U & 0xffffffe0;
        *(int *)(uVar3 - 4) = iVar2;
        *in_ECX = uVar3;
        in_ECX[1] = uVar3;
        in_ECX[2] = uVar3 + param_1;
        return;
      }
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
  }
  FUN_10002a00();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

