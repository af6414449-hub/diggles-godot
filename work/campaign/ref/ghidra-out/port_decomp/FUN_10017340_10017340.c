
undefined4 FUN_10017340(uint param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  void *_Dst;
  undefined4 in_EDX;
  int iVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100425c7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  if (DAT_10050c64 == 0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = FUN_1000e160();
  }
  iVar5 = DAT_10050c64;
  if (0x1f < param_1) {
    _wassert(L"index < DEX_TRANSFORM_MAX",L"C:\\dev\\wiggles\\port\\src\\RealDx.cpp",0xe3);
  }
  iVar6 = param_1 * 0x40;
  uVar2 = param_2[1];
  uVar3 = param_2[2];
  uVar4 = param_2[3];
  puVar1 = (undefined4 *)(iVar6 + 0x14 + iVar5);
  *puVar1 = *param_2;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  puVar1[3] = uVar4;
  uVar2 = param_2[5];
  uVar3 = param_2[6];
  uVar4 = param_2[7];
  puVar1 = (undefined4 *)(iVar6 + 0x24 + iVar5);
  *puVar1 = param_2[4];
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  puVar1[3] = uVar4;
  uVar2 = param_2[9];
  uVar3 = param_2[10];
  uVar4 = param_2[0xb];
  puVar1 = (undefined4 *)(iVar6 + 0x34 + iVar5);
  *puVar1 = param_2[8];
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  puVar1[3] = uVar4;
  uVar2 = param_2[0xd];
  uVar3 = param_2[0xe];
  uVar4 = param_2[0xf];
  puVar1 = (undefined4 *)(iVar6 + 0x44 + iVar5);
  *puVar1 = param_2[0xc];
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  puVar1[3] = uVar4;
  ExceptionList = local_10;
  return 0;
}

