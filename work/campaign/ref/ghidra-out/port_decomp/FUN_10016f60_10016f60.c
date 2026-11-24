
void FUN_10016f60(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5
                 )

{
  int iVar1;
  void *pvVar2;
  undefined4 in_EDX;
  undefined4 uVar3;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1004291b;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if ((param_3 & 1) != 0) {
    local_1c = ((float)(param_4 & 0xff) + 0.0) * 0.00390625;
    local_20 = ((float)(param_4 >> 8 & 0xff) + 0.0) * 0.00390625;
    local_24 = ((float)(param_4 >> 0x10 & 0xff) + 0.0) * 0.00390625;
    local_18 = ((float)(param_4 >> 0x18) + 0.0) * 0.00390625;
    if (DAT_10050c64 == (int *)0x0) {
      pvVar2 = (void *)FUN_1003ff62(0xcbc);
      local_8 = 0;
      memset(pvVar2,0,0xcbc);
      DAT_10050c64 = (int *)FUN_1000e160();
      local_8 = 0xffffffff;
    }
    iVar1 = *DAT_10050c64;
    if (*(char *)(iVar1 + 0xc5) == '\0') {
      uVar3 = *(undefined4 *)(iVar1 + 0x1c);
    }
    else {
      uVar3 = *(undefined4 *)(iVar1 + 0x40);
    }
    (**(code **)(**(int **)(iVar1 + 8) + 200))(*(int **)(iVar1 + 8),uVar3,&local_24);
  }
  if ((param_3 & 4) != 0) {
    if (DAT_10050c64 == (int *)0x0) {
      pvVar2 = (void *)FUN_1003ff62(0xcbc);
      local_8 = 1;
      memset(pvVar2,0,0xcbc);
      DAT_10050c64 = (int *)FUN_1000e160();
      local_8 = 0xffffffff;
    }
    iVar1 = *DAT_10050c64;
    if (*(char *)(iVar1 + 0xc5) == '\0') {
      uVar3 = *(undefined4 *)(iVar1 + 0x20);
    }
    else {
      uVar3 = *(undefined4 *)(iVar1 + 0x4c);
    }
    (**(code **)(**(int **)(iVar1 + 8) + 0xd4))(*(int **)(iVar1 + 8),uVar3,2,param_5,0xff);
  }
  if ((param_3 & 2) != 0) {
    if (DAT_10050c64 == (int *)0x0) {
      pvVar2 = (void *)FUN_1003ff62(0xcbc);
      local_8 = 2;
      memset(pvVar2,0,0xcbc);
      DAT_10050c64 = (int *)FUN_1000e160();
      local_8 = 0xffffffff;
    }
    iVar1 = *DAT_10050c64;
    if (*(char *)(iVar1 + 0xc5) == '\0') {
      uVar3 = *(undefined4 *)(iVar1 + 0x20);
    }
    else {
      uVar3 = *(undefined4 *)(iVar1 + 0x4c);
    }
    (**(code **)(**(int **)(iVar1 + 8) + 0xd4))(*(int **)(iVar1 + 8),uVar3,1,param_5,0xff);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

