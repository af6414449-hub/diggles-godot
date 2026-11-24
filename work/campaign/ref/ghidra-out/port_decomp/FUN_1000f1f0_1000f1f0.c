
void FUN_1000f1f0(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_14 [16];
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (0xff < param_1) {
    _wassert(L"index < DEX_RENDER_STATE_MAX",L"C:\\dev\\wiggles\\port\\src\\RealDx.cpp",0xd3);
  }
  iVar1 = FUN_100192a0(param_1,param_2);
  if (-1 < iVar1) {
    return;
  }
  FUN_100053a0(iVar1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_14,(ThrowInfo *)&DAT_1004a24c);
}

