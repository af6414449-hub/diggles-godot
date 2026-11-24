
undefined1 FUN_00526b90(undefined4 *param_1)

{
  int *piVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int this;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0070263d;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar5 = param_1[2];
  if ((iVar5 == DAT_007723e4) && (this->i_48 == 0)) {
    FUN_00526a80(1);
    uVar2 = 1;
    goto LAB_00526f43;
  }
  if ((iVar5 == DAT_007723e0) && (this->i_48 == 1)) {
    FUN_00526a80(0);
    uVar2 = 1;
    goto LAB_00526f43;
  }
  if ((iVar5 == DAT_007723c4) && (this->i_48 == 1)) {
    puVar4 = (undefined4 *)FUN_00501450();
    uVar3 = FUN_0042f510();
    if ((uint)puVar4[3] <= uVar3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    *(int *)(puVar4[2] + uVar3 * 4) = this;
    puVar4[0x2069] = this;
    FUN_00526a80(2);
    FUN_004ed780(DAT_007723a0);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (puVar4 != (undefined4 *)0x0) {
      LOCK();
      puVar4[1] = puVar4[1] + 1;
      UNLOCK();
    }
    puVar7 = puVar4;
    FUN_00501450(puVar4);
    FUN_005016e0(puVar7);
    if (puVar4 != (undefined4 *)0x0) {
      LOCK();
      iVar5 = puVar4[1] + -1;
      puVar4[1] = iVar5;
      UNLOCK();
      if (iVar5 == 0) {
        (**(code **)*puVar4)(1);
        uVar2 = 1;
        goto LAB_00526f43;
      }
    }
  }
  else {
    if ((iVar5 == DAT_007723cc) &&
       ((this->i_48 == 1 && (this->c_4c != '\0')))) {
      iVar5 = FUN_00501450();
      local_18 = (undefined4 *)FUN_0042f510();
      if (*(undefined4 **)(iVar5 + 0xc) <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(int *)(*(int *)(iVar5 + 8) + (int)local_18 * 4) = this;
      *(int *)(iVar5 + 0x81a4) = this;
      FUN_00526a80(3);
      FUN_004ed780(DAT_00772398);
      local_8 = CONCAT31(local_8._1_3_,2);
    }
    else {
      if ((iVar5 != DAT_007723c8) || (this->i_48 != 2)) {
        if ((iVar5 == DAT_007723c4) && (this->i_48 == 5)) {
          iVar5 = FUN_00501450();
          puVar4 = (undefined4 *)FUN_0042f510();
          if (*(undefined4 **)(iVar5 + 0xc) <= puVar4) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(int *)(*(int *)(iVar5 + 8) + (int)puVar4 * 4) = this;
          *(int *)(iVar5 + 0x81a4) = this;
          FUN_004ed780(DAT_007723a0);
          local_8 = CONCAT31(local_8._1_3_,4);
          if (puVar4 != (undefined4 *)0x0) {
            LOCK();
            puVar4[1] = puVar4[1] + 1;
            UNLOCK();
          }
          puVar7 = puVar4;
          FUN_00501450(puVar4);
          FUN_005016e0(puVar7);
          if (puVar4 != (undefined4 *)0x0) {
            LOCK();
            iVar5 = puVar4[1] + -1;
            puVar4[1] = iVar5;
            UNLOCK();
            if (iVar5 == 0) {
              (**(code **)*puVar4)(1);
              uVar2 = 1;
              goto LAB_00526f43;
            }
          }
        }
        else {
          if ((iVar5 != DAT_007723c8) || (this->i_48 != 5)) {
            if (((iVar5 == DAT_007723d0) && (this->c_4c != '\0')) &&
               (this->i_48 == 3)) {
              uVar6 = 0;
              FUN_00501450(0,uVar3);
              FUN_00501f80(uVar6);
              if (this->i_48 == 3) {
                FUN_004ed780(DAT_00772394);
                local_8._0_1_ = 6;
                if (local_14 != 0) {
                  LOCK();
                  *(int *)(local_14 + 4) = *(int *)(local_14 + 4) + 1;
                  UNLOCK();
                }
                FUN_00501450(local_14);
                FUN_005016e0(local_14);
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_00406f00();
              }
              FUN_00526a80(0);
            }
            if (param_1 != (undefined4 *)0x0) {
              LOCK();
              param_1[1] = param_1[1] + 1;
              UNLOCK();
            }
            uVar2 = FUN_00505d60(param_1);
            goto LAB_00526f43;
          }
          uVar6 = 0;
          FUN_00501450(0,uVar3);
          FUN_00501f80(uVar6);
          if (this->c_4d == '\0') {
            FUN_004ed780(DAT_00772388);
            local_8._0_1_ = 5;
            if (local_14 != 0) {
              LOCK();
              *(int *)(local_14 + 4) = *(int *)(local_14 + 4) + 1;
              UNLOCK();
            }
            FUN_00501450(local_14);
            FUN_005016e0(local_14);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00406f00();
          }
          if ((this->c_24 & 2) != 0) {
            FUN_00526a80(0);
          }
        }
        goto LAB_00526eb7;
      }
      uVar6 = 0;
      FUN_00501450(0,uVar3);
      FUN_00501f80(uVar6);
      FUN_00526a80(-((this->c_24 & 3) != 0) & 5);
      FUN_004ed780(DAT_00772388);
      local_8 = CONCAT31(local_8._1_3_,3);
    }
    if (local_18 != (undefined4 *)0x0) {
      LOCK();
      local_18[1] = local_18[1] + 1;
      UNLOCK();
    }
    puVar4 = local_18;
    FUN_00501450(local_18);
    FUN_005016e0(puVar4);
    if (local_18 != (undefined4 *)0x0) {
      LOCK();
      iVar5 = local_18[1] + -1;
      local_18[1] = iVar5;
      UNLOCK();
      if (iVar5 == 0) {
        (**(code **)*local_18)(1);
        uVar2 = 1;
        goto LAB_00526f43;
      }
    }
  }
LAB_00526eb7:
  uVar2 = 1;
LAB_00526f43:
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
  return uVar2;
}

