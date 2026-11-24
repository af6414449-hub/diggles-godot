
undefined1 FUN_0050ec00(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int this;
  undefined1 uVar6;
  undefined4 uVar7;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007014dd;
  local_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((param_1[2] == DAT_00772388) && (param_1[6] == this->i_58)) {
    if (this->c_5c == '\0') {
      FUN_00505ed0(uVar4);
      iVar5 = this->i_34;
      local_18 = 0x18;
      iVar2 = *(int *)(iVar5 + 0x14);
      iVar3 = *(int *)(iVar5 + 0xc);
      this->i_64 = *(int *)(iVar5 + 0x18) - *(int *)(iVar5 + 0x10);
      this->i_60 = iVar2 - iVar3;
      local_1c = *(int *)(this->i_34 + 0x14) - *(int *)(this->i_34 + 0xc);
      FUN_00504ba0(&local_1c);
      FUN_006b9200(&DAT_00721e4c);
      this->c_5c = 1;
    }
    else {
      FUN_00505ed0(uVar4);
      FUN_00504ba0(this + 0x60);
      FUN_006b9200(&DAT_00721e44);
      this->c_5c = 0;
    }
  }
  if (param_1[2] == DAT_007723c4) {
    FUN_00505ed0(uVar4);
    this->c_44 = 1;
    iVar5 = FUN_00501450();
    local_18 = iVar5;
    local_14 = FUN_0042f510();
    if (*(uint *)(iVar5 + 0xc) <= local_14) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    *(int *)(*(int *)(iVar5 + 8) + local_14 * 4) = this;
    *(int *)(local_18 + 0x81a4) = this;
    iVar5 = FUN_00501450();
    uVar6 = 1;
    uVar7 = *(undefined4 *)(iVar5 + 0x101d4);
    this->i_4c = *(undefined4 *)(iVar5 + 0x101d8);
    this->i_48 = uVar7;
    uVar7 = *(undefined4 *)(this->i_34 + 0x10);
    this->i_50 = *(undefined4 *)(this->i_34 + 0xc);
    this->i_54 = uVar7;
    goto LAB_0050edc5;
  }
  if ((param_1[2] == DAT_007723c8) && (this->c_44 != '\0')) {
    uVar7 = 0;
    FUN_00501450(0);
    FUN_00501f80(uVar7);
    this->c_44 = 0;
  }
  else {
    piVar1 = param_1 + 1;
    LOCK();
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if (param_1[2] == DAT_007723ec) {
      if (param_1 != (undefined4 *)0x0) {
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = iVar5 + -1;
        UNLOCK();
        if (iVar5 + -1 == 0) {
          (**(code **)*param_1)(1);
          uVar6 = 1;
          goto LAB_0050edc5;
        }
      }
    }
    else {
      if (param_1[2] != DAT_007723e8) {
        if (param_1 != (undefined4 *)0x0) {
          LOCK();
          iVar5 = *piVar1;
          *piVar1 = iVar5 + -1;
          UNLOCK();
          if (iVar5 + -1 == 0) {
            (**(code **)*param_1)(1);
          }
        }
        uVar6 = 0;
        goto LAB_0050edc5;
      }
      if (param_1 != (undefined4 *)0x0) {
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = iVar5 + -1;
        UNLOCK();
        if (iVar5 + -1 == 0) {
          (**(code **)*param_1)(1);
          uVar6 = 1;
          goto LAB_0050edc5;
        }
      }
    }
  }
  uVar6 = 1;
LAB_0050edc5:
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    piVar1 = param_1 + 1;
    iVar5 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar5 == 1) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  ExceptionList = local_10;
  return uVar6;
}

