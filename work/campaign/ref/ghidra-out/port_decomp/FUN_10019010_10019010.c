
undefined4 FUN_10019010(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  uVar1 = *(undefined4 *)(in_ECX + 0x9c);
  uVar2 = *(undefined4 *)(in_ECX + 0xa0);
  uVar3 = *(undefined4 *)(in_ECX + 0xa4);
  *param_1 = *(undefined4 *)(in_ECX + 0x98);
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  param_1[3] = uVar3;
  uVar1 = *(undefined4 *)(in_ECX + 0xac);
  uVar2 = *(undefined4 *)(in_ECX + 0xb0);
  uVar3 = *(undefined4 *)(in_ECX + 0xb4);
  param_1[4] = *(undefined4 *)(in_ECX + 0xa8);
  param_1[5] = uVar1;
  param_1[6] = uVar2;
  param_1[7] = uVar3;
  return 0;
}

