
undefined4 FUN_10038b20(uint param_1)

{
  void *_Src;
  uint uVar1;
  int in_ECX;
  void *in_EDX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  _Src = *(void **)(in_ECX + 0x2c);
  if (_Src == (void *)0x0) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x20) + 8))();
    if (uVar1 / param_1 != 1) goto LAB_10038b71;
  }
  else {
    if (*(uint *)(in_ECX + 0x34) < (int)_Src + param_1) {
LAB_10038b71:
      *(undefined4 *)(in_ECX + 0x6c) = 1;
      return 0;
    }
    memcpy(in_EDX,_Src,param_1);
    *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + param_1;
  }
  return 1;
}

