
undefined4 FUN_10016810(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  uVar3 = param_1[3];
  *(undefined4 *)(in_ECX + 0xc) = *param_1;
  *(undefined4 *)(in_ECX + 0x10) = uVar1;
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  *(undefined4 *)(in_ECX + 0x18) = uVar3;
  *(undefined8 *)(in_ECX + 0x1c) = *(undefined8 *)(param_1 + 4);
  return 0;
}

