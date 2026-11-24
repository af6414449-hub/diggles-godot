
undefined1 __thiscall FUN_00506230(ViWinAutoPopup *this)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *in_stack_00000004;
  undefined4 uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006fc57d;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar3 = in_stack_00000004[8];
  if (iVar3 == 1) {
    if (in_stack_00000004[2] != DAT_00772388) goto LAB_005064ae;
    FUN_00501450(1,uVar2);
    FUN_00504260(iVar3);
  }
  else if (iVar3 == 2) {
    if (in_stack_00000004[2] != DAT_00772388) goto LAB_005064ae;
    uVar4 = 1;
    FUN_00501450(1,uVar2);
    FUN_00504260(uVar4);
    iVar3 = FUN_00501450();
    *(undefined4 *)(*(int *)(iVar3 + 0x81a8) + 0xb8) = 8;
  }
  else if (iVar3 == 3) {
    if (in_stack_00000004[2] != DAT_00772388) goto LAB_005064ae;
    uVar4 = 1;
    FUN_00501450(1,uVar2);
    FUN_00504260(uVar4);
    iVar3 = FUN_00501450();
    *(undefined4 *)(*(int *)(iVar3 + 0x81a8) + 0xb8) = 3;
  }
  else if (iVar3 == 4) {
    if (in_stack_00000004[2] != DAT_00772388) goto LAB_005064ae;
    uVar4 = 1;
    FUN_00501450(1,uVar2);
    FUN_00504260(uVar4);
    iVar3 = FUN_00501450();
    *(undefined4 *)(*(int *)(iVar3 + 0x81a8) + 0xb8) = 4;
  }
  else if (iVar3 == 5) {
    if (in_stack_00000004[2] != DAT_00772388) goto LAB_005064ae;
    FUN_00556280();
  }
  else if (iVar3 == 10) {
    if (in_stack_00000004[2] != DAT_00772388) goto LAB_005064ae;
    FUN_00501450();
    FUN_00531fb0("gnomes");
  }
  else if (iVar3 == 0xb) {
    if (in_stack_00000004[2] != DAT_00772388) goto LAB_005064ae;
    FUN_00501450();
    FUN_00531fb0("techtree");
  }
  else if (iVar3 == 0xc) {
    if (in_stack_00000004[2] != DAT_00772388) goto LAB_005064ae;
    FUN_00501450();
    FUN_00531fb0("prods");
  }
  else if (iVar3 == 0xd) {
    if (in_stack_00000004[2] != DAT_00772388) goto LAB_005064ae;
    FUN_00501450();
    FUN_00531fb0("pedigree");
  }
  else if (iVar3 == 0xe) {
    if (in_stack_00000004[2] != DAT_00772388) goto LAB_005064ae;
    FUN_00501450();
    FUN_00531fb0("questlog");
  }
  else if (iVar3 == 0x14) {
    if (in_stack_00000004[2] != DAT_00772388) {
LAB_005064ae:
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        in_stack_00000004[1] = in_stack_00000004[1] + 1;
        UNLOCK();
      }
      uVar1 = FUN_00505d60((ViWin *)this);
      goto LAB_005064c4;
    }
    FUN_00501450();
    FUN_00531fb0(&DAT_00725b34);
  }
  else {
    if ((iVar3 != 100) || (in_stack_00000004[2] != DAT_00772388)) goto LAB_005064ae;
    uVar4 = 1;
    FUN_00501450(1,uVar2);
    FUN_00504260(uVar4);
    iVar3 = FUN_00501450();
    *(undefined4 *)(*(int *)(iVar3 + 0x81a8) + 0xb8) = 0xf;
  }
  if (this->c_1c != '\0') {
    FUN_00504ee0();
    this->c_1c = '\0';
  }
  uVar1 = 1;
LAB_005064c4:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    iVar3 = in_stack_00000004[1] + -1;
    in_stack_00000004[1] = iVar3;
    UNLOCK();
    if ((iVar3 == 0) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar1;
}

