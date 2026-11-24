
undefined4 FUN_10038bd0(void)

{
  int in_ECX;
  uint in_EDX;
  uint uVar1;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if (*(char *)(in_ECX + 0x3c) == '\0') {
    *(undefined4 *)(in_ECX + 0x6c) = 0;
    if (*(int *)(in_ECX + 0x2c) == 0) {
      uVar1 = *(int *)(in_ECX + 0x24) + in_EDX;
      if ((uVar1 < in_EDX) || (0x7fffffff < in_EDX)) {
        uVar1 = 0x7fffffff;
        *(undefined4 *)(in_ECX + 0x6c) = 1;
      }
      (**(code **)(**(int **)(in_ECX + 0x20) + 0x10))(uVar1);
      return 1;
    }
    uVar1 = *(uint *)(in_ECX + 0x30) + in_EDX;
    if ((uVar1 < *(uint *)(in_ECX + 0x34)) && (*(uint *)(in_ECX + 0x30) <= uVar1)) {
      *(uint *)(in_ECX + 0x2c) = uVar1;
      return 1;
    }
    *(uint *)(in_ECX + 0x2c) = *(uint *)(in_ECX + 0x34);
    *(undefined4 *)(in_ECX + 0x6c) = 1;
  }
  return 0;
}

