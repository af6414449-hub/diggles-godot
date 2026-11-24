
void FUN_100266f0(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  iVar3 = param_2;
  if (0 < param_2) {
    do {
      FUN_100240b0();
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  puVar2 = in_ECX;
  puVar4 = param_4;
  for (iVar3 = 0x3c0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  if (0 < param_1) {
    local_8 = (param_1 - 1U >> 1) + 1;
    puVar2 = param_4;
    do {
      FUN_10025720(param_2,puVar2);
      puVar2 = puVar2 + 0x80;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  param_4 = param_4 + param_1 * 0x40;
  if (param_2 != 1) {
    for (iVar3 = 0x3c0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *in_ECX = *param_4;
      param_4 = param_4 + 1;
      in_ECX = in_ECX + 1;
    }
    return;
  }
  iVar3 = 0;
  do {
    uVar1 = *param_4;
    param_4 = param_4 + 2;
    in_ECX[iVar3] = uVar1;
    iVar3 = iVar3 + 2;
  } while (iVar3 < 0x3c0);
  return;
}

