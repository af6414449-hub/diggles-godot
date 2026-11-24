
void FUN_10017d30(undefined4 param_1,undefined4 *param_2)

{
  void *_Dst;
  int in_ECX;
  undefined4 in_EDX;
  undefined4 local_20 [3];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042a37;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if (DAT_10050c64 == (int *)0x0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  (**(code **)(**(int **)(*DAT_10050c64 + 8) + 0x38))
            (*(int **)(*DAT_10050c64 + 8),*(undefined4 *)(in_ECX + 0x14),0,4,0,local_20);
  *param_2 = local_20[0];
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

