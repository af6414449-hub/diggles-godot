
void __thiscall FUN_00538f50(ViWinSlider *this)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *in_stack_00000004;
  undefined4 uVar6;
  undefined4 *puVar7;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined1 local_15;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  iVar1 = DAT_00772378;
  puStack_c = &LAB_00702e3d;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar5 = in_stack_00000004[2];
  local_14 = uVar2;
  if ((iVar5 < 0) || (*(int *)(DAT_00772378 + 0xc) <= iVar5)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar3 = *(int **)(iVar1 + 8);
  }
  else {
    piVar3 = (int *)(*(int *)(DAT_00772378 + 8) + iVar5 * 4);
  }
  if (*(int *)(*piVar3 + 8) != 0) {
    if (in_stack_00000004 != (undefined4 *)0x0) {
      LOCK();
      in_stack_00000004[1] = in_stack_00000004[1] + 1;
      UNLOCK();
    }
    piVar3 = in_stack_00000004 + 1;
    if (in_stack_00000004[2] == DAT_007723ec) {
      LOCK();
      iVar5 = *piVar3;
      *piVar3 = iVar5 + -1;
      UNLOCK();
      if (iVar5 + -1 == 0) {
        (**(code **)*in_stack_00000004)(1);
      }
    }
    else {
      if (in_stack_00000004[2] != DAT_007723e8) {
        LOCK();
        iVar5 = *piVar3;
        *piVar3 = iVar5 + -1;
        UNLOCK();
        if (iVar5 + -1 == 0) {
          (**(code **)*in_stack_00000004)(1,uVar2);
        }
        local_15 = 0;
        goto LAB_00539281;
      }
      LOCK();
      iVar5 = *piVar3;
      *piVar3 = iVar5 + -1;
      UNLOCK();
      if (iVar5 + -1 == 0) {
        (**(code **)*in_stack_00000004)(1);
        local_15 = 1;
        goto LAB_00539281;
      }
    }
    local_15 = 1;
    goto LAB_00539281;
  }
  local_1c = (undefined4 *)this->i_50;
  local_24 = this->i_4c;
  iVar5 = this->i_48 + (int)local_1c;
  local_20 = (undefined4 *)(this->i_44 + local_24);
  if (this->c_54 == '\0') {
    iVar1 = in_stack_00000004[9];
    if ((((iVar1 < local_24) || ((int)local_20 <= iVar1)) ||
        ((int)in_stack_00000004[10] < (int)local_1c)) || (iVar5 <= (int)in_stack_00000004[10])) {
      if (in_stack_00000004[2] == DAT_007723c4) {
        local_2c = this->i_64;
        local_28 = this->i_68;
        if (iVar1 < local_24) {
          local_2c = local_2c - this->i_84;
        }
        if ((int)local_20 < iVar1) {
          local_2c = local_2c + this->i_84;
        }
        if ((int)in_stack_00000004[10] < (int)local_1c) {
          local_28 = local_28 - this->i_88;
        }
        if (iVar5 < (int)in_stack_00000004[10]) {
          local_28 = local_28 + this->i_88;
        }
        goto LAB_00539217;
      }
    }
    else if (in_stack_00000004[2] == DAT_007723c4) {
      this->c_54 = '\x01';
      puVar4 = (undefined4 *)FUN_00501450();
      local_20 = puVar4;
      uVar2 = FUN_0042f510();
      if ((uint)puVar4[3] <= uVar2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(ViWinSlider **)(puVar4[2] + uVar2 * 4) = this;
      local_20[0x2069] = this;
      uVar6 = DAT_007723b4;
      iVar5 = in_stack_00000004[9];
      this->i_5c = in_stack_00000004[10] - (int)local_1c;
      this->i_58 = iVar5 - local_24;
      FUN_004ed780(uVar6);
      puVar4 = local_20;
      local_8 = CONCAT31(local_8._1_3_,2);
      local_20[9] = this->i_64;
      local_20[10] = this->i_68;
      if (local_20 != (undefined4 *)0x0) {
        LOCK();
        local_20[1] = local_20[1] + 1;
        UNLOCK();
      }
      puVar7 = local_20;
      FUN_00501450(local_20);
      FUN_005016e0(puVar7);
      if (puVar4 != (undefined4 *)0x0) {
        LOCK();
        iVar5 = puVar4[1] + -1;
        puVar4[1] = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (**(code **)*puVar4)(1);
          local_15 = 1;
          goto LAB_00539281;
        }
      }
    }
  }
  else {
    if (in_stack_00000004[2] == DAT_007723c8) {
      uVar6 = 0;
      this->c_54 = '\0';
      FUN_00501450(0);
      FUN_00501f80(uVar6);
      FUN_004ed780(DAT_007723b0);
      puVar4 = local_1c;
      local_8._0_1_ = 1;
      local_1c[9] = this->i_64;
      local_1c[10] = this->i_68;
      if (local_1c != (undefined4 *)0x0) {
        LOCK();
        local_1c[1] = local_1c[1] + 1;
        UNLOCK();
      }
      puVar7 = local_1c;
      FUN_00501450(local_1c);
      FUN_005016e0(puVar7);
      local_8 = (uint)local_8._1_3_ << 8;
      if (puVar4 != (undefined4 *)0x0) {
        LOCK();
        iVar5 = puVar4[1] + -1;
        puVar4[1] = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (**(code **)*puVar4)(1);
        }
      }
    }
    if (in_stack_00000004[2] == DAT_007723d4) {
      local_1c = (undefined4 *)(in_stack_00000004[9] - this->i_58);
      local_24 = in_stack_00000004[10] - this->i_5c;
      local_2c = this->i_64;
      local_28 = this->i_68;
      uVar2 = this->i_24;
      if ((uVar2 & 1) != 0) {
        local_2c = ((this->i_74 - this->i_6c) * (int)local_1c) /
                   ((this->i_14 - this->i_44) - this->i_0c) + this->i_6c;
        uVar2 = this->i_24;
      }
      if ((uVar2 & 2) != 0) {
        local_28 = ((this->i_78 - this->i_70) * local_24) / ((this->i_18 - this->i_48) - this->i_10)
                   + this->i_70;
      }
LAB_00539217:
      FUN_00538b40(&local_2c,1);
    }
  }
  local_15 = 1;
LAB_00539281:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    piVar3 = in_stack_00000004 + 1;
    iVar5 = *piVar3;
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if ((iVar5 == 1) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

