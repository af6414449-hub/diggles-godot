
void FUN_1000a620(int param_1)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 in_EDX;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041dfb;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if (DAT_10050c64 == (int *)0x0) {
    pvVar3 = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(pvVar3,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
    if (DAT_10050c64 == (int *)0x0) {
      pvVar3 = (void *)FUN_1003ff62(0xcbc);
      local_8 = 1;
      memset(pvVar3,0,0xcbc);
      DAT_10050c64 = (int *)FUN_1000e160();
      local_8 = 0xffffffff;
    }
  }
  piVar1 = *(int **)(*DAT_10050c64 + 8);
  (**(code **)(**(int **)(param_1 + 8) + 0xe4))
            (*(int **)(param_1 + 8),*(undefined4 *)(in_ECX + 0x68),0,*(undefined4 *)(param_1 + 0x3c)
             ,0,*(undefined4 *)(in_ECX + 4));
  if (DAT_10050c64 == (int *)0x0) {
    pvVar3 = (void *)FUN_1003ff62(0xcbc);
    local_8 = 2;
    memset(pvVar3,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  (**(code **)(**(int **)(*DAT_10050c64 + 8) + 0x114))
            (*(int **)(*DAT_10050c64 + 8),DAT_10050f24,0,0);
  local_18 = *(undefined4 *)(param_1 + 0x40);
  local_1c = *(undefined4 *)(param_1 + 0x50);
  (**(code **)(*piVar1 + 0x84))(piVar1,1,&local_18,0);
  (**(code **)(*piVar1 + 0x10c))(piVar1,0,1,&local_1c);
  (**(code **)(*piVar1 + 0x110))(piVar1,0,1,in_ECX + 0x74,0);
  iVar2 = *piVar1;
  uVar4 = FUN_10041270(1);
  uVar4 = FUN_10041270(uVar4);
  (**(code **)(iVar2 + 0xa4))(piVar1,uVar4);
  (**(code **)(*piVar1 + 0x10c))(piVar1,0,1,&DAT_10043854);
  (**(code **)(*piVar1 + 0x110))(piVar1,1,1,&DAT_10043858,0);
  (**(code **)(*piVar1 + 0xbc))
            (piVar1,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(in_ECX + 0x70));
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

