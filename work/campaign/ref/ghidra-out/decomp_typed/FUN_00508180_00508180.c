
undefined1 FUN_00508180(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  int this;
  undefined4 uVar6;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00700f85;
  local_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar5 = this->i_58;
  if (iVar5 == 5) {
    if (param_1 != (undefined4 *)0x0) {
      LOCK();
      param_1[1] = param_1[1] + 1;
      UNLOCK();
    }
    piVar1 = param_1 + 1;
    if (param_1[2] == DAT_007723ec) {
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = iVar5 + -1;
      UNLOCK();
      if (iVar5 + -1 == 0) {
        (**(code **)*param_1)(1);
      }
    }
    else {
      if (param_1[2] != DAT_007723e8) {
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = iVar5 + -1;
        UNLOCK();
        if (iVar5 + -1 == 0) {
          (**(code **)*param_1)(1);
        }
        uVar3 = 0;
        goto LAB_0050858b;
      }
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = iVar5 + -1;
      UNLOCK();
      if (iVar5 + -1 == 0) {
        (**(code **)*param_1)(1);
        uVar3 = 1;
        goto LAB_0050858b;
      }
    }
    uVar3 = 1;
    goto LAB_0050858b;
  }
  iVar2 = param_1[2];
  if ((iVar2 == DAT_007723e4) && (iVar5 == 0)) {
    uVar4 = 1;
    if (this->c_2c != '\0') {
      iVar5 = FUN_00501450();
      if ((*(int *)(iVar5 + 0x8198) == this) &&
         (iVar5 = FUN_00501450(), *(int *)(iVar5 + 0x81a4) != 0)) {
        FUN_00501450();
      }
      iVar5 = FUN_00501450();
      uVar4 = (uint)(*(int *)(iVar5 + 0x819c) == this);
      FUN_00501450();
    }
    if (uVar4 != this->i_58) {
      this->i_58 = uVar4;
      FUN_00504ee0();
    }
    if (this->c_5e == '\0') {
      uVar3 = 1;
      goto LAB_0050858b;
    }
LAB_00508572:
    if (param_1 != (undefined4 *)0x0) {
      LOCK();
      param_1[1] = param_1[1] + 1;
      UNLOCK();
    }
  }
  else {
    if ((iVar2 != DAT_007723e0) || (iVar5 != 1)) {
      if ((iVar2 == DAT_007723c4) && (iVar5 == 1)) {
        if (this->c_5e == '\0') {
          iVar5 = FUN_00501450();
          uVar4 = FUN_0042f510();
          if (*(uint *)(iVar5 + 0xc) <= uVar4) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(int *)(*(int *)(iVar5 + 8) + uVar4 * 4) = this;
          *(int *)(iVar5 + 0x81a4) = this;
          FUN_00507fe0(2);
          FUN_004ed780(DAT_007723a0);
          local_8 = CONCAT31(local_8._1_3_,1);
          if (uVar4 != 0) {
            LOCK();
            *(int *)(uVar4 + 4) = *(int *)(uVar4 + 4) + 1;
            UNLOCK();
          }
          FUN_00501450(uVar4);
          FUN_005016e0(uVar4);
          FUN_00406f00();
          uVar3 = 1;
          goto LAB_0050858b;
        }
      }
      else {
        if ((iVar2 != DAT_007723cc) || ((iVar5 != 1 || (this->c_5c == '\0')))) {
          if ((iVar2 == DAT_007723c8) && ((iVar5 == 2 || (iVar5 == 1)))) {
            FUN_00507fe0(0);
            if (this->c_5e == '\0') {
              uVar6 = 0;
              FUN_00501450(0);
              FUN_00501f80(uVar6);
              FUN_004ed780(DAT_00772388);
              local_8 = CONCAT31(local_8._1_3_,3);
              if (local_14 != 0) {
                LOCK();
                *(int *)(local_14 + 4) = *(int *)(local_14 + 4) + 1;
                UNLOCK();
              }
              FUN_00501450(local_14);
              FUN_005016e0(local_14);
              FUN_00406f00();
              uVar3 = 1;
              goto LAB_0050858b;
            }
          }
          else {
            if ((iVar2 == DAT_007723d0) && ((this->c_5c != '\0' && (iVar5 == 3)))) {
              if (this->c_5e == '\0') {
                uVar6 = 0;
                FUN_00501450(0,uVar4);
                FUN_00501f80(uVar6);
                FUN_004ed780(DAT_00772394);
                local_8._0_1_ = 4;
                if (local_14 != 0) {
                  LOCK();
                  *(int *)(local_14 + 4) = *(int *)(local_14 + 4) + 1;
                  UNLOCK();
                }
                iVar5 = local_14;
                FUN_00501450(local_14);
                FUN_005016e0(iVar5);
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_00406f00();
              }
              FUN_00507fe0(0);
            }
            if ((param_1[2] != DAT_007723c8) || (this->i_58 != 0)) goto LAB_00508572;
            if (this->c_5e == '\0') {
              uVar6 = 0;
              FUN_00501450(0,uVar4);
              FUN_00501f80(uVar6);
              FUN_004ed780(DAT_0077239c);
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
            FUN_00507fe0(0);
            if (this->c_5e == '\0') {
              uVar3 = 1;
              goto LAB_0050858b;
            }
          }
          if (param_1 != (undefined4 *)0x0) {
            LOCK();
            param_1[1] = param_1[1] + 1;
            UNLOCK();
          }
          goto LAB_0050857f;
        }
        if (this->c_5e == '\0') {
          iVar5 = FUN_00501450();
          uVar4 = FUN_0042f510();
          if (*(uint *)(iVar5 + 0xc) <= uVar4) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(int *)(*(int *)(iVar5 + 8) + uVar4 * 4) = this;
          *(int *)(iVar5 + 0x81a4) = this;
          FUN_00507fe0(3);
          FUN_004ed780(DAT_00772398);
          local_8 = CONCAT31(local_8._1_3_,2);
          if (uVar4 != 0) {
            LOCK();
            *(int *)(uVar4 + 4) = *(int *)(uVar4 + 4) + 1;
            UNLOCK();
          }
          FUN_00501450(uVar4);
          FUN_005016e0(uVar4);
          FUN_00406f00();
          uVar3 = 1;
          goto LAB_0050858b;
        }
      }
      goto LAB_00508572;
    }
    FUN_00507fe0(0);
    if (this->c_5e == '\0') {
      uVar3 = 1;
      goto LAB_0050858b;
    }
    if (param_1 != (undefined4 *)0x0) {
      LOCK();
      param_1[1] = param_1[1] + 1;
      UNLOCK();
    }
  }
LAB_0050857f:
  uVar3 = FUN_00505d60(param_1);
LAB_0050858b:
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
  return uVar3;
}

