
undefined4 FUN_10017260(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 in_EDX;
  undefined1 local_24 [16];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042967;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  if (DAT_10050c64 == 0) {
    local_14 = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(local_14,0,0xcbc);
    DAT_10050c64 = FUN_1000e160();
    local_8 = 0xffffffff;
  }
  if (0xff < param_1) {
    _wassert(L"index < DEX_RENDER_STATE_MAX",L"C:\\dev\\wiggles\\port\\src\\RealDx.cpp",0xdb);
  }
  iVar1 = FUN_10019800(param_1,param_2);
  if (-1 < iVar1) {
    ExceptionList = local_10;
    return 0;
  }
  FUN_100053a0(iVar1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_24,(ThrowInfo *)&DAT_1004a24c);
}

