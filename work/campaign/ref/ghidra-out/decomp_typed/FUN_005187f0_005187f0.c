
undefined1 FUN_005187f0(undefined4 *param_1)

{
  undefined1 *puVar1;
  int this;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  uint local_2c;
  int local_28;
  undefined1 local_21;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  puStack_18 = &LAB_00701d70;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  local_14 = 0;
  iVar2 = param_1[2];
  if (iVar2 == DAT_0077238c) {
    puStack_20 = &stack0xfffffffc;
    FUN_00504ee0();
    local_21 = 1;
  }
  else if ((((iVar2 == DAT_007723c8) || (iVar2 == DAT_007723c4)) ||
           ((this->c_54 != '\0' && (iVar2 == DAT_007723d4)))) &&
          (this->c_56 != '\0')) {
    uVar3 = 0;
    uVar4 = this->i_50;
    local_28 = -*(int *)(this->i_48 + 0x68);
    local_30 = param_1[10];
    local_2c = uVar4;
    puStack_20 = &stack0xfffffffc;
    puVar1 = &stack0xfffffffc;
    if (0 < (int)uVar4) {
      do {
        if (this->i_50 <= uVar3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar4 = local_2c;
        }
        iVar2 = *(int *)(this->i_4c + uVar3 * 4);
        local_28 = local_28 + (*(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x10));
        if (local_30 < local_28) {
          FUN_00518100(uVar3);
          uVar4 = local_2c;
          uVar3 = local_2c;
        }
        uVar3 = uVar3 + 1;
        puVar1 = puStack_20;
      } while ((int)uVar3 < (int)uVar4);
    }
    puStack_20 = puVar1;
    if ((param_1[2] == DAT_007723c8) && (this->c_54 != '\0')) {
      local_21 = 0;
    }
    else {
      local_21 = 1;
    }
  }
  else if (iVar2 == DAT_007723bc) {
    uVar4 = 0;
    local_2c = 999999999;
    local_40 = *(undefined4 *)(this->i_48 + 100);
    local_30 = *(int *)(this->i_48 + 0x68);
    local_38 = param_1[0x10];
    local_34 = this->i_50;
    local_28 = 1;
    puStack_20 = &stack0xfffffffc;
    puVar1 = &stack0xfffffffc;
    if (0 < local_34) {
      do {
        if (this->i_50 <= uVar4) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar2 = this->i_4c;
        uVar3 = (uint)ABS((double)(*(int *)(*(int *)(iVar2 + uVar4 * 4) + 0x10) - local_30));
        if ((int)uVar3 < (int)local_2c) {
          local_2c = uVar3;
          if (this->i_50 <= uVar4) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar2 = this->i_4c;
          }
          iVar2 = *(int *)(iVar2 + uVar4 * 4);
          local_28 = ((*(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x10)) * 10) / 0xf;
        }
        uVar4 = uVar4 + 1;
        puVar1 = puStack_20;
      } while ((int)uVar4 < local_34);
    }
    puStack_20 = puVar1;
    local_3c = local_30 - local_28 * local_38;
    FUN_00538b40(&local_40,1);
    local_21 = 1;
  }
  else {
    if (param_1 != (undefined4 *)0x0) {
      LOCK();
      param_1[1] = param_1[1] + 1;
      UNLOCK();
    }
    local_21 = FUN_00505d60(param_1);
  }
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    iVar2 = param_1[1] + -1;
    param_1[1] = iVar2;
    UNLOCK();
    if ((iVar2 == 0) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  ExceptionList = local_1c;
  return local_21;
}

