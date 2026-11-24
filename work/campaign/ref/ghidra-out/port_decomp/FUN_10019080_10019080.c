
void FUN_10019080(undefined4 param_1,int param_2,undefined4 param_3,uint param_4,int param_5)

{
  int iVar1;
  void *_Dst;
  int *in_ECX;
  undefined4 in_EDX;
  undefined1 local_10c [36];
  void *local_e8;
  undefined1 local_90 [104];
  uint local_28;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042b8a;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if (DAT_10050c64 == 0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = FUN_1000e160();
    local_8 = 0xffffffff;
  }
  iVar1 = DAT_10050c64;
  (**(code **)(*in_ECX + 0x18))(local_90);
  if (param_2 == 0) {
    if ((param_4 & 0x400) != 0) {
      (**(code **)(*in_ECX + 0x40))(0,local_10c,0,0);
      memset(local_e8,*(int *)(param_5 + 0x50),
             ((int)(in_ECX[0xf] + (in_ECX[0xf] >> 0x1f & 7U)) >> 3) * in_ECX[0xe] * in_ECX[0xd]);
      (**(code **)(*in_ECX + 0x44))(0);
      FUN_1000ff00();
    }
  }
  else if ((local_28 & 0x200) != 0) {
    (**(code **)(*in_ECX + 0x7c))(param_2);
    *(undefined1 *)(iVar1 + 0xcb9) = 1;
    if (*(char *)(iVar1 + 0xcb8) != '\0') {
      FUN_1000ff90();
      *(undefined1 *)(iVar1 + 0xcb8) = 0;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

