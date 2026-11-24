
int FUN_1003f1e0(void)

{
  int iVar1;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if (*(char *)(in_ECX + 0x3c) != '\0') {
    return 0;
  }
  if (*(int *)(in_ECX + 0x2c) != 0) {
    return *(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x30);
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x14))();
  return iVar1 - *(int *)(in_ECX + 0x24);
}

