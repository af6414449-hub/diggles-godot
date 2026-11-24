
undefined1 FUN_0050a560(undefined4 *param_1)

{
  int *piVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int this;
  undefined4 *puVar5;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00701235;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar4 = param_1[2];
  if (iVar4 != DAT_00772384) {
    if (iVar4 == DAT_007723d8) {
      if (param_1[0x10] == 0x1b) {
        FUN_004ed780(DAT_00772390,uVar3);
        local_8 = CONCAT31(local_8._1_3_,1);
        if (local_14 != (undefined4 *)0x0) {
          LOCK();
          local_14[1] = local_14[1] + 1;
          UNLOCK();
        }
        puVar5 = local_14;
        FUN_00501450(local_14);
        FUN_005016e0(puVar5);
        this->c_2d = 1;
        iVar4 = FUN_00501450();
        if ((*(int *)(iVar4 + 0x81a0) != 0) && (*(int *)(iVar4 + 0x81a0) == this)) {
          iVar4 = FUN_00501450();
          *(undefined4 *)(iVar4 + 0x81a0) = 0;
        }
LAB_0050a60e:
        if (local_14 != (undefined4 *)0x0) {
          LOCK();
          iVar4 = local_14[1] + -1;
          local_14[1] = iVar4;
          UNLOCK();
          if (iVar4 == 0) {
            (**(code **)*local_14)(1);
          }
        }
      }
    }
    else if (iVar4 != DAT_007723c4) {
      if (iVar4 == DAT_007723c8) {
        FUN_004ed780(DAT_00772390,uVar3);
        local_8 = CONCAT31(local_8._1_3_,2);
        if (local_14 != (undefined4 *)0x0) {
          LOCK();
          local_14[1] = local_14[1] + 1;
          UNLOCK();
        }
        puVar5 = local_14;
        FUN_00501450(local_14);
        FUN_005016e0(puVar5);
        FUN_00504a40();
        goto LAB_0050a60e;
      }
      if (iVar4 != DAT_007723cc) {
        if (iVar4 != DAT_007723d0) {
          if (param_1 != (undefined4 *)0x0) {
            LOCK();
            param_1[1] = param_1[1] + 1;
            UNLOCK();
          }
          uVar2 = FUN_00505d60(param_1);
          goto LAB_0050a629;
        }
        FUN_004ed780(DAT_00772390,uVar3);
        local_8 = CONCAT31(local_8._1_3_,3);
        if (local_14 != (undefined4 *)0x0) {
          LOCK();
          local_14[1] = local_14[1] + 1;
          UNLOCK();
        }
        FUN_00501450(local_14);
        FUN_005016e0(local_14);
        FUN_00504a40();
        FUN_00406f00();
      }
    }
  }
  uVar2 = 1;
LAB_0050a629:
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    piVar1 = param_1 + 1;
    iVar4 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar4 == 1) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  ExceptionList = local_10;
  return uVar2;
}

