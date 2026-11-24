
undefined1 __thiscall FUN_0050a560(ViWinClickPicBox *this)

{
  int *piVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *in_stack_00000004;
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
  iVar4 = in_stack_00000004[2];
  if (iVar4 != DAT_00772384) {
    if (iVar4 == DAT_007723d8) {
      if (in_stack_00000004[0x10] == 0x1b) {
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
        this->c_2d = '\x01';
        iVar4 = FUN_00501450();
        if ((*(ViWinClickPicBox **)(iVar4 + 0x81a0) != (ViWinClickPicBox *)0x0) &&
           (*(ViWinClickPicBox **)(iVar4 + 0x81a0) == this)) {
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
          if (in_stack_00000004 != (undefined4 *)0x0) {
            LOCK();
            in_stack_00000004[1] = in_stack_00000004[1] + 1;
            UNLOCK();
          }
          uVar2 = FUN_00505d60((ViWin *)this);
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
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    piVar1 = in_stack_00000004 + 1;
    iVar4 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar4 == 1) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar2;
}

