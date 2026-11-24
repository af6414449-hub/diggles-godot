
void FUN_10038a40(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_9;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  uVar1 = *(uint *)(in_ECX + 0x2c);
  if (uVar1 == 0) {
    piVar2 = *(int **)(in_ECX + 0x20);
    iVar3 = (**(code **)(*piVar2 + 4))();
    if (iVar3 == 0) {
      local_9 = 0;
      (**(code **)(*piVar2 + 8))(&local_9,1);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  else if (uVar1 < *(uint *)(in_ECX + 0x34)) {
    *(uint *)(in_ECX + 0x2c) = uVar1 + 1;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(undefined4 *)(in_ECX + 0x6c) = 1;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

