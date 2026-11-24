
void __thiscall FUN_00525e90(ViWinProperties *this)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  code *pcVar7;
  bool bVar8;
  undefined1 in_XMM0 [16];
  undefined1 auVar9 [16];
  undefined4 local_4c;
  int local_48;
  int *local_44;
  undefined4 local_40;
  int *local_3c;
  undefined4 local_38;
  int *local_34;
  uint local_30;
  int *local_2c;
  int *local_28;
  char local_22;
  char local_21;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  iVar4 = DAT_00772400;
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_00702580;
  local_1c = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  this->i_48 = this->i_48 + 1;
  pcVar7 = RaiseException_exref;
  local_21 = '\0';
  if (*(int *)(iVar4 + 0xa0c8) == 0) {
    iVar4 = 0;
    cVar2 = '\0';
    puStack_20 = &stack0xfffffffc;
  }
  else {
    if (*(int *)(iVar4 + 0xa0c8) < 1) {
      iVar4 = 0;
      puStack_20 = &stack0xfffffffc;
    }
    else {
      local_34 = (int *)(DAT_0077244c + 0x488);
      if (**(uint **)(iVar4 + 0xa0c4) < 0x2000) {
        local_34 = local_34 + **(uint **)(iVar4 + 0xa0c4);
        puStack_20 = &stack0xfffffffc;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar4 = *local_34;
    }
    cVar2 = local_21;
    if ((*(int *)(iVar4 + 0xe8) != 1) && (cVar2 = '\0', *(int *)(iVar4 + 0xe8) != 0xb)) {
      iVar4 = 0;
    }
  }
  if (iVar4 != this->i_5c) {
    cVar2 = '\x01';
    this->i_5c = iVar4;
    local_21 = '\x01';
  }
  if ((iVar4 != 0) && (local_34 = (int *)0x0, 0 < this->i_58)) {
    bVar8 = this->i_58 != 0;
    local_2c = (int *)0x0;
    do {
      auVar9 = in_XMM0;
      if (!bVar8) {
        (*pcVar7)(0xc000008c,1,0,0,uVar3);
        auVar9 = in_XMM0;
      }
      local_44 = (int *)(this->i_5c + 0x21c);
      local_3c = (int *)(*(int *)(this->i_54 + 8 + (int)local_2c) + 0xc);
      if (*local_44 == 0) {
        FUN_005da0f0();
        local_30 = 0xffffffff;
        FUN_006b8fb0(local_3c);
        local_22 = FUN_00444990(&local_28,&local_30);
        local_14 = 0;
        if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
          FUN_006ba940();
        }
        local_14 = 0xffffffff;
        uVar6 = 0xffffffff;
        if (local_22 != '\0') {
          uVar6 = local_30;
        }
        pcVar7 = RaiseException_exref;
        if (*local_44 == 0) {
          if (uVar6 < 0x200) {
            iVar4 = FUN_005da0f0();
            auVar9 = ZEXT416(*(uint *)(iVar4 + 0x1804 + uVar6 * 4));
            pcVar7 = RaiseException_exref;
          }
          else {
LAB_00526045:
            auVar9 = ZEXT816(0);
          }
        }
        else {
          if (0x1ff < uVar6) goto LAB_00526045;
          auVar9 = ZEXT416(*(uint *)(*local_44 + uVar6 * 4));
        }
      }
      else {
        FUN_005da900(local_3c);
      }
      local_30 = auVar9._0_4_;
      if ((int *)this->i_58 <= local_34) {
        (*pcVar7)(0xc000008c,1,0,0);
        auVar9 = ZEXT416(local_30);
      }
      iVar4 = this->i_54;
      in_XMM0._0_8_ = ABS((double)(auVar9._0_4_ - *(float *)((int)local_2c + 0x10U + iVar4)));
      in_XMM0._8_4_ = auVar9._8_4_;
      in_XMM0._12_4_ = auVar9._12_4_ & 0x7fffffff;
      if (0.004999999888241291 <= in_XMM0._0_8_) {
        if ((int *)this->i_58 <= local_34) {
          (*pcVar7)(0xc000008c,1,0,0);
          iVar4 = this->i_54;
        }
        in_XMM0 = ZEXT416(local_30);
        *(uint *)((int)local_2c + 0x10U + iVar4) = local_30;
        local_21 = '\x01';
      }
      local_34 = (int *)((int)local_34 + 1);
      local_2c = (int *)((int)local_2c + 0x18);
      bVar8 = local_34 < (int *)this->i_58;
      cVar2 = local_21;
    } while ((int)local_34 < this->i_58);
  }
  if ((cVar2 == '\0') && (this->i_48 < 0x15)) {
    ExceptionList = local_1c;
    return;
  }
  local_34 = (int *)this->i_5c;
  this->i_48 = 0;
  if ((local_34 == (int *)0x0) || (this->c_4c == '\0')) {
    if (this->c_1c != '\0') {
      FUN_00504ee0();
      this->c_1c = '\0';
    }
    goto LAB_0052669b;
  }
  local_30 = this->i_50;
  cVar2 = FUN_006b97f0(local_34 + 0x36);
  if (cVar2 == '\0') {
    piVar5 = *(int **)(local_30 + 0x20);
    piVar1 = (int *)local_34[0x36];
    *(int **)(local_30 + 0x20) = piVar1;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
      FUN_006ba940();
    }
    *(undefined4 *)(*(int *)(local_30 + 0x20) + 8) = *(undefined4 *)(local_34[0x36] + 8);
    FUN_00504ee0();
  }
  local_40 = 0x23;
  local_30 = 0;
  local_28 = (int *)0x0;
  local_38 = 0x87;
  local_2c = (int *)0x0;
  uVar3 = local_30;
  do {
    local_30 = uVar3;
    local_3c = (int *)(local_30 + 0x2c);
    if ((int *)this->i_58 <= local_28) {
      (*pcVar7)(0xc000008c,1,0,0);
    }
    FUN_00504a70(&local_40);
    if ((int *)this->i_58 <= local_28) {
      (*pcVar7)(0xc000008c,1,0,0);
    }
    iVar4 = *(int *)((int)local_2c + 4 + this->i_54);
    if (*(char *)(iVar4 + 0x1c) != '\x01') {
      *(undefined1 *)(iVar4 + 0x1c) = 1;
      FUN_00504ee0();
    }
    piVar5 = (int *)this->i_58;
    if (piVar5 <= local_28) {
      (*pcVar7)(0xc000008c,1,0,0);
      piVar5 = (int *)this->i_58;
    }
    local_44 = (int *)(this->i_54 + (int)local_2c);
    if (piVar5 <= local_28) {
      (*pcVar7)(0xc000008c,1,0,0);
    }
    iVar4 = *(int *)((int)local_2c + this->i_54);
    piVar5 = *(int **)(iVar4 + 0x58);
    if ((float)piVar5 != (float)local_44[4]) {
      *(int *)(iVar4 + 0x58) = local_44[4];
      FUN_00504ee0();
    }
    local_34 = (int *)(local_30 + 0x38);
    if ((int *)this->i_58 <= local_28) {
      (*pcVar7)(0xc000008c,1,0,0);
    }
    FUN_00504a70(&local_38);
    if ((int *)this->i_58 <= local_28) {
      (*pcVar7)(0xc000008c,1,0,0);
    }
    iVar4 = *(int *)((int)local_2c + this->i_54);
    if (*(char *)(iVar4 + 0x1c) != '\x01') {
      *(undefined1 *)(iVar4 + 0x1c) = 1;
      FUN_00504ee0();
    }
    local_2c = (int *)((int)local_2c + 0x18);
    local_28 = (int *)((int)local_28 + 1);
    uVar3 = local_30 + 0x13;
  } while ((int)local_2c < 0x60);
  local_30 = local_30 + 0x18;
  local_2c = (int *)(this->i_5c + 0x21c);
  if (*local_2c == 0) {
    FUN_005da0f0();
    local_34 = (int *)0xffffffff;
    local_44 = (int *)FUN_006ba810(0x19);
    local_44[1] = 0x14;
    local_44[2] = -1;
    *local_44 = 0;
    *(undefined1 *)(local_44 + 3) = 0;
    local_44[3] = 0x5f727461;
    local_44[4] = 0x4d707845;
    *(undefined2 *)(local_44 + 5) = 0x7861;
    *(undefined1 *)((int)local_44 + 0x16) = 0;
    local_44[2] = 10;
    *local_44 = 1;
    local_3c = local_44;
    local_22 = FUN_00444990(&local_44,&local_34);
    local_14 = 1;
    *local_3c = *local_3c + -1;
    if (*local_3c == 0) {
      FUN_006ba940();
    }
    local_14 = 0xffffffff;
    piVar5 = (int *)0xffffffff;
    if (local_22 != '\0') {
      piVar5 = local_34;
    }
    if (*local_2c == 0) {
      if (piVar5 < (int *)0x200) {
        iVar4 = FUN_005da0f0();
        piVar5 = *(int **)(iVar4 + 0x1804 + (int)piVar5 * 4);
      }
      else {
LAB_005263a1:
        piVar5 = (int *)0x0;
      }
    }
    else {
      if ((int *)0x1ff < piVar5) goto LAB_005263a1;
      piVar5 = *(int **)(*local_2c + (int)piVar5 * 4);
    }
  }
  else {
    FUN_005da900("atr_ExpMax");
  }
  local_2c = (int *)0x4;
  local_34 = piVar5;
  if (4 < this->i_58) {
    local_28 = (int *)0x60;
    do {
      if ((uint)this->i_58 <= local_2c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar4 = *(int *)((int)local_28 + this->i_54);
      if (*(float *)(iVar4 + 0x4c) != 100.0) {
        *(undefined4 *)(iVar4 + 0x4c) = 0x42c80000;
        FUN_00504ee0();
      }
      if ((uint)this->i_58 <= local_2c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar4 = *(int *)((int)local_28 + this->i_54);
      if ((*(float *)(iVar4 + 0x44) != 0.0) || (*(float *)(iVar4 + 0x48) != (float)local_34)) {
        *(undefined4 *)(iVar4 + 0x44) = 0;
        *(int **)(iVar4 + 0x48) = local_34;
        if ((float)local_34 < 0.0) {
          *(int **)(iVar4 + 0x44) = local_34;
        }
        FUN_00504ee0();
      }
      if ((uint)this->i_58 <= local_2c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar4 = this->i_54;
      if (*(float *)((int)local_28 + iVar4 + 0x10) <= 0.005) {
        if ((uint)this->i_58 <= local_2c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar4 = this->i_54;
        }
        local_44 = *(int **)((int)local_28 + iVar4);
        if ((char)local_44[7] != '\0') {
          FUN_00504ee0();
          *(undefined1 *)(local_44 + 7) = 0;
        }
        if ((uint)this->i_58 <= local_2c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar4 = *(int *)((int)local_28 + this->i_54 + 4);
        if (*(char *)(iVar4 + 0x1c) != '\0') {
          FUN_00504ee0();
          *(undefined1 *)(iVar4 + 0x1c) = 0;
        }
      }
      else {
        local_3c = (int *)(local_30 + 0x2c);
        local_40 = 0x23;
        if ((uint)this->i_58 <= local_2c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        FUN_00504a70(&local_40);
        if ((uint)this->i_58 <= local_2c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar4 = *(int *)((int)local_28 + this->i_54 + 4);
        if (*(char *)(iVar4 + 0x1c) != '\x01') {
          *(undefined1 *)(iVar4 + 0x1c) = 1;
          FUN_00504ee0();
        }
        uVar3 = this->i_58;
        if (uVar3 <= local_2c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar3 = this->i_58;
        }
        local_44 = (int *)((int)local_28 + this->i_54);
        if (uVar3 <= local_2c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar4 = *(int *)((int)local_28 + this->i_54);
        if (*(float *)(iVar4 + 0x58) != (float)local_44[4]) {
          *(int *)(iVar4 + 0x58) = local_44[4];
          FUN_00504ee0();
        }
        local_48 = local_30 + 0x38;
        local_4c = 0x87;
        if ((uint)this->i_58 <= local_2c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        FUN_00504a70(&local_4c);
        if ((uint)this->i_58 <= local_2c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar4 = *(int *)((int)local_28 + this->i_54);
        if (*(char *)(iVar4 + 0x1c) != '\x01') {
          *(undefined1 *)(iVar4 + 0x1c) = 1;
          FUN_00504ee0();
        }
        local_30 = local_30 + 0x13;
      }
      local_28 = local_28 + 6;
      local_2c = (int *)((int)local_2c + 1);
    } while ((int)local_2c < this->i_58);
  }
  local_48 = local_30 + 0x5e;
  local_4c = 300;
  FUN_00504ba0(&local_4c);
  if (this->c_1c != '\x01') {
    this->c_1c = '\x01';
    FUN_00504ee0();
  }
LAB_0052669b:
  FUN_00504ee0();
  ExceptionList = local_1c;
  return;
}

