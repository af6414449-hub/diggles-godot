
void FUN_10038b80(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  int in_EDX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if (*(int *)(in_ECX + 0x2c) == 0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x14))();
    (**(code **)(**(int **)(in_ECX + 0x20) + 0x10))(iVar2 + in_EDX);
  }
  else {
    uVar1 = *(int *)(in_ECX + 0x2c) + in_EDX;
    *(uint *)(in_ECX + 0x2c) = uVar1;
    if (*(uint *)(in_ECX + 0x34) <= uVar1) {
      *(undefined4 *)(in_ECX + 0x6c) = 1;
      return;
    }
  }
  return;
}

