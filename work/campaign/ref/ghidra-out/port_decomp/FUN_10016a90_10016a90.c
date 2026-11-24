
undefined4 FUN_10016a90(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  void *_Dst;
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041aa7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  if (DAT_10050c64 == 0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = FUN_1000e160();
  }
  iVar1 = DAT_10050c64;
  param_1 = param_1 * 0x60;
  switch(param_2) {
  case 1:
    *(undefined4 *)(param_1 + 0x894 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 2:
    *(undefined4 *)(param_1 + 0x898 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 3:
    *(undefined4 *)(param_1 + 0x89c + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 4:
    *(undefined4 *)(param_1 + 0x8a0 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 5:
    *(undefined4 *)(param_1 + 0x8a4 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 6:
    *(undefined4 *)(param_1 + 0x8a8 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 7:
    *(undefined4 *)(param_1 + 0x8ac + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 8:
    *(undefined4 *)(param_1 + 0x8b0 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 9:
    *(undefined4 *)(param_1 + 0x8b4 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 10:
    *(undefined4 *)(param_1 + 0x8b8 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 0xb:
    *(undefined4 *)(param_1 + 0x8bc + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 0xc:
    *(undefined4 *)(param_1 + 0x8c0 + DAT_10050c64) = param_3;
    *(undefined4 *)(param_1 + 0x8c4 + iVar1) = param_3;
    *(undefined4 *)(param_1 + 0x8c8 + iVar1) = param_3;
    ExceptionList = local_10;
    return 0;
  case 0xd:
    *(undefined4 *)(param_1 + 0x8c4 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 0xe:
    *(undefined4 *)(param_1 + 0x8c8 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 0xf:
    *(undefined4 *)(param_1 + 0x8cc + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 0x10:
    *(undefined4 *)(param_1 + 0x8d0 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 0x11:
    *(undefined4 *)(param_1 + 0x8d4 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 0x12:
    *(undefined4 *)(param_1 + 0x8d8 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 0x13:
    *(undefined4 *)(param_1 + 0x8dc + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 0x14:
    *(undefined4 *)(param_1 + 0x8e0 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 0x15:
    *(undefined4 *)(param_1 + 0x8e4 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 0x16:
    *(undefined4 *)(param_1 + 0x8e8 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 0x17:
    *(undefined4 *)(param_1 + 0x8ec + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  case 0x18:
    *(undefined4 *)(param_1 + 0x8f0 + DAT_10050c64) = param_3;
    ExceptionList = local_10;
    return 0;
  default:
    OutputDebugStringA("Unknown SetTextureStage option!\n");
    ExceptionList = local_10;
    return 0;
  }
}

