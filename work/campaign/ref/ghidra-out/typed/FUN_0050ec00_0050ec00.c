
undefined1 __thiscall FUN_0050ec00(ViWinDragBar *this)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  undefined4 *in_stack_00000004;
  undefined4 uVar7;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007014dd;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((in_stack_00000004[2] == DAT_00772388) && (in_stack_00000004[6] == this->i_58)) {
    if (this->c_5c == '\0') {
      FUN_00505ed0(uVar3);
      iVar4 = this->i_34;
      local_18 = 0x18;
      iVar5 = *(int *)(iVar4 + 0x14);
      iVar2 = *(int *)(iVar4 + 0xc);
      this->i_64 = *(int *)(iVar4 + 0x18) - *(int *)(iVar4 + 0x10);
      this->i_60 = iVar5 - iVar2;
      local_1c = *(int *)(this->i_34 + 0x14) - *(int *)(this->i_34 + 0xc);
      FUN_00504ba0(&local_1c);
      FUN_006b9200(&DAT_00721e4c);
      this->c_5c = '\x01';
    }
    else {
      FUN_00505ed0(uVar3);
      FUN_00504ba0(&this->i_60);
      FUN_006b9200(&DAT_00721e44);
      this->c_5c = '\0';
    }
  }
  if (in_stack_00000004[2] == DAT_007723c4) {
    FUN_00505ed0(uVar3);
    this->c_44 = '\x01';
    iVar4 = FUN_00501450();
    local_18 = iVar4;
    local_14 = FUN_0042f510();
    if (*(uint *)(iVar4 + 0xc) <= local_14) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    *(ViWinDragBar **)(*(int *)(iVar4 + 8) + local_14 * 4) = this;
    *(ViWinDragBar **)(local_18 + 0x81a4) = this;
    iVar5 = FUN_00501450();
    uVar6 = 1;
    iVar4 = *(int *)(iVar5 + 0x101d4);
    this->i_4c = *(int *)(iVar5 + 0x101d8);
    this->i_48 = iVar4;
    iVar4 = *(int *)(this->i_34 + 0x10);
    this->i_50 = *(int *)(this->i_34 + 0xc);
    this->i_54 = iVar4;
    goto LAB_0050edc5;
  }
  if ((in_stack_00000004[2] == DAT_007723c8) && (this->c_44 != '\0')) {
    uVar7 = 0;
    FUN_00501450(0);
    FUN_00501f80(uVar7);
    this->c_44 = '\0';
  }
  else {
    piVar1 = in_stack_00000004 + 1;
    LOCK();
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if (in_stack_00000004[2] == DAT_007723ec) {
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = iVar4 + -1;
        UNLOCK();
        if (iVar4 + -1 == 0) {
          (**(code **)*in_stack_00000004)(1);
          uVar6 = 1;
          goto LAB_0050edc5;
        }
      }
    }
    else {
      if (in_stack_00000004[2] != DAT_007723e8) {
        if (in_stack_00000004 != (undefined4 *)0x0) {
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = iVar4 + -1;
          UNLOCK();
          if (iVar4 + -1 == 0) {
            (**(code **)*in_stack_00000004)(1);
          }
        }
        uVar6 = 0;
        goto LAB_0050edc5;
      }
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = iVar4 + -1;
        UNLOCK();
        if (iVar4 + -1 == 0) {
          (**(code **)*in_stack_00000004)(1);
          uVar6 = 1;
          goto LAB_0050edc5;
        }
      }
    }
  }
  uVar6 = 1;
LAB_0050edc5:
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
  return uVar6;
}

