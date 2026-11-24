
size_t FUN_1003fc70(void *param_1,size_t param_2)

{
  int iVar1;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *(int *)(in_ECX + 0xc);
  if (*(uint *)(in_ECX + 8) <= iVar1 + param_2) {
    param_2 = *(uint *)(in_ECX + 8) - iVar1;
  }
  memcpy(param_1,(void *)(*(int *)(in_ECX + 4) + iVar1),param_2);
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + param_2;
  return param_2;
}

