
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10018be0(int param_1)

{
  int iVar1;
  int *in_ECX;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (((in_ECX[0x2e] & 0x200U) != 0) && (param_1 == 0)) {
    local_c = 0;
    uRam1416f064 = 0;
    uRam1416f068 = 0;
    uRam1416f06c = 0;
    _DAT_1416f060 = 4;
    (**(code **)(*in_ECX + 0x20))(&DAT_1416f060,&local_c);
    iVar1 = FUN_1000ece0();
    (**(code **)(*in_ECX + 0x7c))(local_c);
    *(undefined1 *)(iVar1 + 0xcb9) = 1;
    if (*(char *)(iVar1 + 0xcb8) != '\0') {
      FUN_1000ff90();
      *(undefined1 *)(iVar1 + 0xcb8) = 0;
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

