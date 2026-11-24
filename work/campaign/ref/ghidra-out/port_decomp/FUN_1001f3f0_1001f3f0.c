
int FUN_1001f3f0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int in_ECX;
  void *in_EDX;
  int iVar1;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (0 < param_3) {
    if (param_3 - param_4 < param_1) {
      param_1 = param_3 - param_4;
    }
    iVar1 = 0;
    if (0 < param_5) {
      do {
        memcpy(in_EDX,(void *)(*(int *)(in_ECX + iVar1 * 4) + param_4 * 4),param_1 << 2);
        in_EDX = (void *)((int)in_EDX + param_2 * 4);
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_5);
    }
    return param_1;
  }
  return 0;
}

