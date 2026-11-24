
void FUN_1003fcc0(uint param_1)

{
  uint uVar1;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if ((int)param_1 < 0) {
    param_1 = param_1 + *(int *)(in_ECX + 8);
  }
  uVar1 = *(int *)(in_ECX + 8) - 1;
  if (uVar1 < param_1) {
    param_1 = uVar1;
  }
  *(uint *)(in_ECX + 0xc) = param_1;
  return;
}

