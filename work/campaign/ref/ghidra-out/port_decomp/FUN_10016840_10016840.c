
undefined4 FUN_10016840(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  uVar1 = *(undefined4 *)(in_ECX + 0x10);
  uVar2 = *(undefined4 *)(in_ECX + 0x14);
  uVar3 = *(undefined4 *)(in_ECX + 0x18);
  *param_1 = *(undefined4 *)(in_ECX + 0xc);
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  param_1[3] = uVar3;
  *(undefined8 *)(param_1 + 4) = *(undefined8 *)(in_ECX + 0x1c);
  return 0;
}

