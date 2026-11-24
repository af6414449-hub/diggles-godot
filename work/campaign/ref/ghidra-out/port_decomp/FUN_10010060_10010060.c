
void FUN_10010060(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *in_ECX;
  *(undefined4 *)(iVar1 + 0x70) = 0;
  *(undefined4 *)(iVar1 + 0x6c) = 0;
  *(undefined4 *)(iVar1 + 0x74) = param_1;
  *(undefined4 *)(iVar1 + 0x78) = param_2;
  FUN_10005e40();
  iVar1 = *in_ECX;
  FUN_10009bc0(param_1,param_2,*(undefined1 *)(iVar1 + 0xd0),*(undefined4 *)(iVar1 + 0x54),
               *(undefined4 *)(iVar1 + 0x58));
  iVar1 = *in_ECX;
  if (*(char *)(iVar1 + 0xc5) == '\0') {
    local_c = *(undefined4 *)(iVar1 + 0x1c);
  }
  else {
    local_c = *(undefined4 *)(iVar1 + 0x40);
  }
  if (*(char *)(iVar1 + 0xc5) == '\0') {
    uVar2 = *(undefined4 *)(iVar1 + 0x20);
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x4c);
  }
  (**(code **)(**(int **)(iVar1 + 8) + 0x84))(*(int **)(iVar1 + 8),1,&local_c,uVar2);
  FUN_1000ff00();
  *(undefined1 *)(in_ECX + 0x32e) = 1;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

