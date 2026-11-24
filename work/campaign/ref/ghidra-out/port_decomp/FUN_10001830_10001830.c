
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10001830(void)

{
  uint uVar1;
  undefined4 in_EDX;
  uint uVar2;
  uint local_28 [4];
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041af0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  memset(&DAT_10050e38,0,0x84);
  local_18 = 0;
  local_14 = 0xf;
  local_28[0] = local_28[0] & 0xffffff00;
  FUN_10003a00("SceneBrightness.fx",0x12);
  local_8 = 0;
  FUN_10008a90(local_28);
  FUN_1000adb0(&DAT_10050d9c);
  _DAT_10050e5c = 0x102;
  _DAT_10050e60 = 0;
  _DAT_10050e64 = 0;
  _DAT_10050e90 = 0;
  _DAT_10050e94 = 0;
  _DAT_10050e98 = 0;
  _DAT_10050e80 = 0;
  uRam10050e84 = 0;
  uRam10050e88 = 0;
  uRam10050e8c = 0;
  if (0xf < local_14) {
    uVar2 = local_14 + 1;
    uVar1 = local_28[0];
    if (0xfff < uVar2) {
      uVar1 = *(uint *)(local_28[0] - 4);
      uVar2 = local_14 + 0x24;
      if (0x1f < (local_28[0] - uVar1) - 4) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_100402ac(uVar1,uVar2);
  }
  _atexit(FUN_10042db0);
  ExceptionList = local_10;
  return;
}

