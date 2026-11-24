
void FUN_1003f880(int *param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  undefined4 local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if (*(char *)(in_ECX + 0x3c) != '\0') {
    *(undefined4 *)(in_ECX + 0x70) = 2;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  iVar1 = FUN_1003c730(&local_10,&local_14);
  if (iVar1 != 0) {
    local_c = FUN_1003c7b0(local_10,local_14);
    iVar1 = 0;
    if (0 < *(int *)(in_ECX + 4)) {
      piVar2 = (int *)(in_ECX + 0x36c);
      do {
        iVar1 = iVar1 + 1;
        *piVar2 = piVar2[-0x10] + local_10 * 4;
        piVar2 = piVar2 + 1;
      } while (iVar1 < *(int *)(in_ECX + 4));
    }
    *(int *)(in_ECX + 0x5ec) = local_10;
    *(int *)(in_ECX + 0x5f0) = local_c + local_10;
    if (param_1 != (int *)0x0) {
      *param_1 = in_ECX + 0x36c;
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(undefined4 *)(in_ECX + 0x5f0) = 0;
  *(undefined4 *)(in_ECX + 0x5ec) = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

