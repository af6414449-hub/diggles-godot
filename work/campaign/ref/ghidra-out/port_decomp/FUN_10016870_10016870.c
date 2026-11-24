
undefined4 FUN_10016870(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  uVar3 = param_1[3];
  *(undefined4 *)(in_ECX + 0x24) = *param_1;
  *(undefined4 *)(in_ECX + 0x28) = uVar1;
  *(undefined4 *)(in_ECX + 0x2c) = uVar2;
  *(undefined4 *)(in_ECX + 0x30) = uVar3;
  uVar1 = param_1[5];
  uVar2 = param_1[6];
  uVar3 = param_1[7];
  *(undefined4 *)(in_ECX + 0x34) = param_1[4];
  *(undefined4 *)(in_ECX + 0x38) = uVar1;
  *(undefined4 *)(in_ECX + 0x3c) = uVar2;
  *(undefined4 *)(in_ECX + 0x40) = uVar3;
  uVar1 = param_1[9];
  uVar2 = param_1[10];
  uVar3 = param_1[0xb];
  *(undefined4 *)(in_ECX + 0x44) = param_1[8];
  *(undefined4 *)(in_ECX + 0x48) = uVar1;
  *(undefined4 *)(in_ECX + 0x4c) = uVar2;
  *(undefined4 *)(in_ECX + 0x50) = uVar3;
  uVar1 = param_1[0xd];
  uVar2 = param_1[0xe];
  uVar3 = param_1[0xf];
  *(undefined4 *)(in_ECX + 0x54) = param_1[0xc];
  *(undefined4 *)(in_ECX + 0x58) = uVar1;
  *(undefined4 *)(in_ECX + 0x5c) = uVar2;
  *(undefined4 *)(in_ECX + 0x60) = uVar3;
  *(undefined4 *)(in_ECX + 100) = param_1[0x10];
  return 0;
}

