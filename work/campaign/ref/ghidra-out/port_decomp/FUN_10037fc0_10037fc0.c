
void FUN_10037fc0(int param_1)

{
  int in_ECX;
  void *in_EDX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if (*(int *)(in_ECX + 0x5c) != 0) {
    *(int *)(in_ECX + 0x68) = *(int *)(in_ECX + 0x68) + (param_1 + 3U & 0xfffffffc);
    return;
  }
  free(in_EDX);
  return;
}

