
undefined4 FUN_10017ea0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  uVar1 = *(undefined4 *)(in_ECX + 8);
  uVar2 = *(undefined4 *)(in_ECX + 0xc);
  uVar3 = *(undefined4 *)(in_ECX + 0x10);
  *param_1 = *(undefined4 *)(in_ECX + 4);
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  param_1[3] = uVar3;
  return 0;
}

