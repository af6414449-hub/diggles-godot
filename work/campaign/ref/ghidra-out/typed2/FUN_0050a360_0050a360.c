
undefined1 __thiscall FUN_0050a360(ViWinClickLayoutBox *this)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 *in_stack_00000004;
  undefined4 *puVar4;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007011ed;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar3 = in_stack_00000004[2];
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
        if (in_stack_00000004 != (undefined4 *)0x0) {
          LOCK();
          in_stack_00000004[1] = in_stack_00000004[1] + 1;
          UNLOCK();
        }
        uVar2 = FUN_00505d60((ViWin *)this);
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
    this->c_2d = '\x01';
    iVar3 = FUN_00501450();
    if ((*(ViWinClickLayoutBox **)(iVar3 + 0x81a0) != (ViWinClickLayoutBox *)0x0) &&
       (*(ViWinClickLayoutBox **)(iVar3 + 0x81a0) == this)) {
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
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    piVar1 = in_stack_00000004 + 1;
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar3 == 1) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar2;
}

