
void * FUN_10037f70(void)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int in_ECX;
  int in_EDX;
  uint _Size;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  _Size = in_EDX + 7U & 0xfffffff8;
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + _Size;
  if (*(int *)(in_ECX + 0x5c) == 0) {
    if (_Size != 0) {
      pvVar3 = malloc(_Size);
      return pvVar3;
    }
  }
  else {
    iVar2 = *(int *)(in_ECX + 100);
    iVar1 = iVar2 + _Size;
    if (iVar1 <= *(int *)(in_ECX + 0x68)) {
      *(int *)(in_ECX + 100) = iVar1;
      return (void *)(iVar2 + *(int *)(in_ECX + 0x5c));
    }
  }
  return (void *)0x0;
}

