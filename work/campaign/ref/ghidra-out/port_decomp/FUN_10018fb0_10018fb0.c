
undefined4 FUN_10018fb0(undefined4 param_1)

{
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(undefined4 *)(in_ECX + 4 + *(int *)(in_ECX + 0x24) * 4) = param_1;
  *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  return 0;
}

