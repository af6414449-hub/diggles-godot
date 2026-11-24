
undefined1 FUN_0050a360(undefined4 *param_1)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  int this;
  undefined4 *puVar4;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007011ed;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar3 = param_1[2];
  if (iVar3 == DAT_007723c4) {
    uVar2 = 1;
  }
  else {
    if (iVar3 == DAT_007723c8) {
      FUN_004ed780(DAT_00772390,DAT_0076700c ^ (uint)&stack0xfffffffc);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    else {
      if (iVar3 != DAT_007723d0) {
        if (param_1 != (undefined4 *)0x0) {
          LOCK();
          param_1[1] = param_1[1] + 1;
          UNLOCK();
        }
        uVar2 = FUN_00505d60(param_1);
        goto LAB_0050a45c;
      }
      FUN_004ed780(DAT_00772390,DAT_0076700c ^ (uint)&stack0xfffffffc);
      local_8 = CONCAT31(local_8._1_3_,2);
    }
    if (local_14 != (undefined4 *)0x0) {
      LOCK();
      local_14[1] = local_14[1] + 1;
      UNLOCK();
    }
    puVar4 = local_14;
    FUN_00501450(local_14);
    FUN_005016e0(puVar4);
    this->c_2d = 1;
    iVar3 = FUN_00501450();
    if ((*(int *)(iVar3 + 0x81a0) != 0) && (*(int *)(iVar3 + 0x81a0) == this)) {
      iVar3 = FUN_00501450();
      *(undefined4 *)(iVar3 + 0x81a0) = 0;
    }
    if (local_14 != (undefined4 *)0x0) {
      LOCK();
      iVar3 = local_14[1] + -1;
      local_14[1] = iVar3;
      UNLOCK();
      if (iVar3 == 0) {
        (**(code **)*local_14)(1);
      }
    }
    uVar2 = 1;
  }
LAB_0050a45c:
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    piVar1 = param_1 + 1;
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar3 == 1) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  ExceptionList = local_10;
  return uVar2;
}

