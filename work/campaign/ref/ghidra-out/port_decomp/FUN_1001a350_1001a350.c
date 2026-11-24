
int FUN_1001a350(uint param_1)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (((((param_1 & 0xfffff000) == 0xfffff000) && ((param_1 & 0xfff) < *(uint *)(in_ECX + 0x1bda0)))
      && (iVar1 = *(int *)(*(int *)(in_ECX + 0x1bd9c) + (param_1 & 0xfff) * 4), iVar1 != 0)) &&
     (puVar2 = (uint *)(iVar1 + 4), puVar2 != (uint *)0x0)) {
    param_1 = *puVar2;
  }
  if (param_1 != 0) {
    iVar3 = (param_1 & 0xfff) - 1;
    iVar1 = *(int *)(in_ECX + 0x40 + iVar3 * 4);
    if ((iVar1 != 0) && ((*(uint *)(iVar1 + 8) & 0xfffff) == param_1 >> 0xc)) {
      return iVar3;
    }
  }
  return -1;
}

