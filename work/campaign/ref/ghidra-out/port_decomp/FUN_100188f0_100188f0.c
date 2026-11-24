
undefined4 FUN_100188f0(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  puVar2 = (undefined4 *)(in_ECX + 0x50);
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(in_ECX + 0x58);
  iVar1 = *(int *)(in_ECX + 0xa4);
  *(int *)(in_ECX + 0x3c) = iVar1;
  *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x5c);
  *(int *)(in_ECX + 0xf4) = ((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3) * *(int *)(in_ECX + 0x5c);
  return 0;
}

