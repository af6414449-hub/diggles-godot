
void FUN_100081a0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b08);
  if (param_1 != param_2) {
    do {
      uVar2 = param_1[1];
      uVar3 = param_1[2];
      uVar4 = param_1[3];
      *param_3 = *param_1;
      param_3[1] = uVar2;
      param_3[2] = uVar3;
      param_3[3] = uVar4;
      puVar1 = param_1 + 4;
      uVar2 = param_1[5];
      uVar3 = param_1[6];
      uVar4 = param_1[7];
      param_1 = param_1 + 8;
      param_3[4] = *puVar1;
      param_3[5] = uVar2;
      param_3[6] = uVar3;
      param_3[7] = uVar4;
      param_3 = param_3 + 8;
    } while (param_1 != param_2);
  }
  return;
}

