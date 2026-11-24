
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10001710(void)

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
  memset(&DAT_10050ec8,0,0x84);
  local_18 = 0;
  local_14 = 0xf;
  local_28[0] = local_28[0] & 0xffffff00;
  FUN_10003a00("ResolveDepthBuffer.fx",0x15);
  local_8 = 0;
  FUN_10008a90(local_28);
  _DAT_10050ef0 = 0;
  _DAT_10050ef4 = 0;
  _DAT_10050f20 = 0;
  DAT_10050f24 = 0;
  _DAT_10050f28 = 0;
  _DAT_10050ee0 = 0;
  uRam10050ee4 = 0;
  uRam10050ee8 = 0;
  uRam10050eec = 0xffffffff;
  _DAT_10050f10 = 0;
  uRam10050f14 = 0;
  DAT_10050f18 = 0;
  uRam10050f1c = 0;
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
  _atexit(FUN_10042da0);
  ExceptionList = local_10;
  return;
}

