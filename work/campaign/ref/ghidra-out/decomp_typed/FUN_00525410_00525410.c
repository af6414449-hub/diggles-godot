
void FUN_00525410(void)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int this;
  int iVar5;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00702535;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_11 = 0;
  piVar3 = (int *)FUN_006ba810(0x19);
  piVar3[1] = 0x14;
  piVar3[2] = -1;
  *piVar3 = 0;
  *(undefined1 *)(piVar3 + 3) = 0;
  piVar3[3] = 0x706f7250;
  piVar3[4] = 0x69747265;
  *(undefined2 *)(piVar3 + 5) = 0x7365;
  *(undefined1 *)((int)piVar3 + 0x16) = 0;
  piVar3[2] = 10;
  if (piVar3 != (int *)0x0) {
    *piVar3 = *piVar3 + 1;
  }
  uVar4 = FUN_0050e8e0(piVar3,uVar2);
  this->i_50 = uVar4;
  local_30 = 0;
  local_2c = 0x14;
  FUN_00504a70(&local_30);
  local_30 = 300;
  local_2c = 0x14;
  FUN_00504ba0(&local_30);
  iVar5 = this->i_50;
  uVar2 = *(uint *)(iVar5 + 0x24) | 1;
  if (uVar2 != *(uint *)(iVar5 + 0x24)) {
    *(uint *)(iVar5 + 0x24) = uVar2;
    FUN_00504ee0();
    iVar5 = this->i_50;
  }
  uVar2 = *(uint *)(iVar5 + 0x24) | 2;
  if (uVar2 != *(uint *)(iVar5 + 0x24)) {
    *(uint *)(iVar5 + 0x24) = uVar2;
    FUN_00504ee0();
  }
  local_20 = (int *)0x0;
  if (0 < this->i_58) {
    local_38 = 100;
    local_34 = 0x19;
    local_18 = 0;
    do {
      piVar3 = *(int **)(this + 0x58);
      if (piVar3 <= local_20) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar3 = *(int **)(this + 0x58);
      }
      piVar1 = local_20;
      local_1c = *(int **)(this + 0x54);
      local_24 = (int *)(*(int *)((int)local_1c + local_18 + 0xc) + 0xc);
      if (piVar3 <= local_20) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        local_1c = *(int **)(this + 0x54);
      }
      uVar4 = FUN_0054cd20(&local_38,local_24);
      *(undefined4 *)(local_18 + 4 + (int)local_1c) = uVar4;
      if (*(int **)(this + 0x58) <= piVar1) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar5 = *(int *)(this->i_54 + 4 + local_18);
      uVar2 = *(uint *)(iVar5 + 0x24) | 0x10;
      if (uVar2 != *(uint *)(iVar5 + 0x24)) {
        *(uint *)(iVar5 + 0x24) = uVar2;
        FUN_00504ee0();
      }
      if (*(int **)(this + 0x58) <= piVar1) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar5 = *(int *)(this->i_54 + 0x14 + local_18);
      if (iVar5 == 0) {
        local_28 = (int *)FUN_006ba810(0x19);
        local_28[1] = 0x14;
        local_28[2] = -1;
        *local_28 = 0;
        *(undefined1 *)(local_28 + 3) = 0;
        local_28[3] = 0x61746164;
        local_28[4] = 0x4955472f;
        local_28[5] = 0x7261422f;
        local_28[6] = 0x6167742e;
        *(undefined1 *)(local_28 + 7) = 0;
        local_28[2] = 0x10;
        *local_28 = 1;
        local_8 = 0;
        local_1c = local_28;
        local_24 = (int *)FUN_006ba810(0x19);
        local_24[1] = 0x14;
        local_24[2] = -1;
        *local_24 = 0;
        *(undefined1 *)(local_24 + 3) = 0;
        local_24[3] = 0x61746164;
        local_24[4] = 0x4955472f;
        local_24[5] = 0x7261422f;
        local_24[6] = 0x742e4742;
        *(undefined2 *)(local_24 + 7) = 0x6167;
        *(undefined1 *)((int)local_24 + 0x1e) = 0;
        local_24[2] = 0x12;
        *local_24 = 1;
        local_8 = CONCAT31(local_8._1_3_,1);
        local_20 = local_24;
        local_24 = (int *)FUN_00506d20(0x87,0x38,0x80,0xe,&local_28);
        if (*(int **)(this + 0x58) <= piVar1) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        *(int **)(local_18 + this->i_54) = local_24;
        local_8 = CONCAT31(local_8._1_3_,2);
        *local_20 = *local_20 + -1;
        if (*local_20 == 0) {
          FUN_006ba940();
        }
        local_8 = 3;
        piVar3 = local_1c;
LAB_00525873:
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
          FUN_006ba940();
        }
        local_8 = 0xffffffff;
      }
      else if (iVar5 == 1) {
        local_28 = (int *)FUN_006ba810(0x19);
        local_28[1] = 0x14;
        local_28[2] = -1;
        *local_28 = 0;
        *(undefined1 *)(local_28 + 3) = 0;
        local_28[3] = 0x61746164;
        local_28[4] = 0x4955472f;
        local_28[5] = 0x7261422f;
        local_28[6] = 0x67742e32;
        *(undefined2 *)(local_28 + 7) = 0x61;
        local_28[2] = 0x11;
        *local_28 = 1;
        local_8 = 4;
        local_24 = local_28;
        local_20 = (int *)FUN_006ba810(0x19);
        local_20[1] = 0x14;
        local_20[2] = -1;
        *local_20 = 0;
        *(undefined1 *)(local_20 + 3) = 0;
        local_20[3] = 0x61746164;
        local_20[4] = 0x4955472f;
        local_20[5] = 0x7261422f;
        local_20[6] = 0x742e4742;
        *(undefined2 *)(local_20 + 7) = 0x6167;
        *(undefined1 *)((int)local_20 + 0x1e) = 0;
        local_20[2] = 0x12;
        *local_20 = 1;
        local_8 = CONCAT31(local_8._1_3_,5);
        local_1c = local_20;
        local_20 = (int *)FUN_00506d20(0x87,0x38,0x80,0xe,&local_24);
        if (*(int **)(this + 0x58) <= piVar1) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        *(int **)(local_18 + this->i_54) = local_20;
        local_8 = CONCAT31(local_8._1_3_,6);
        *local_1c = *local_1c + -1;
        if (*local_1c == 0) {
          FUN_006ba940();
        }
        local_8 = 7;
        piVar3 = local_28;
        goto LAB_00525873;
      }
      if (*(int **)(this + 0x58) <= piVar1) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar5 = *(int *)(local_18 + this->i_54);
      if ((*(float *)(iVar5 + 0x44) != 0.0) || (*(float *)(iVar5 + 0x48) != 1.0)) {
        *(undefined4 *)(iVar5 + 0x44) = 0;
        *(undefined4 *)(iVar5 + 0x48) = 0x3f800000;
        FUN_00504ee0();
      }
      local_20 = (int *)((int)piVar1 + 1);
      local_18 = local_18 + 0x18;
    } while ((int)local_20 < this->i_58);
  }
  if (this->c_1c != '\0') {
    FUN_00504ee0();
    this->c_1c = 0;
  }
  FUN_00504ee0();
  ExceptionList = local_10;
  return;
}

