
void __thiscall FUN_00519300(ViWinNewsTicker *this)

{
  float *pfVar1;
  float fVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  int *in_stack_00000004;
  undefined4 uVar10;
  int *local_4c [3];
  int local_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int local_30;
  int *local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  int *local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00701e15;
  local_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004ef7b0(in_stack_00000004 + 4);
  local_8 = 0;
  iStack_38 = (this->i_14 - this->i_0c) + -2;
  iStack_3c = 1;
  local_40 = 1;
  iStack_34 = (this->i_18 - this->i_10) + -2;
  local_1c = (int *)0xbe141414;
  FUN_004fdf50(&local_40,&local_1c);
  local_1c = (int *)0x78c8c8c8;
  FUN_004fdc40(&local_40,&local_1c);
  local_20 = this->i_5c;
  uVar9 = 0;
  if (0 < local_20) {
    local_1c = (int *)0x0;
    pcVar7 = RaiseException_exref;
    do {
      if ((uint)this->i_5c <= uVar9) {
        (*pcVar7)(0xc000008c,1,0,0,uVar4);
        pcVar7 = RaiseException_exref;
      }
      *(undefined1 *)((int)local_1c + this->i_58 + 0x24) = 0;
      if ((uint)this->i_5c <= uVar9) {
        (*pcVar7)(0xc000008c,1,0,0);
      }
      pcVar7 = RaiseException_exref;
      uVar9 = uVar9 + 1;
      *(undefined1 *)(this->i_58 + 0x25 + (int)local_1c) = 1;
      local_1c = local_1c + 0x10;
    } while ((int)uVar9 < local_20);
  }
  local_14 = this->i_78;
  this->f_84 = 10000.0;
  this->f_88 = -10000.0;
  FUN_00504c80(&local_40);
  uVar4 = 0;
  iStack_3c = iStack_3c + 3;
  iStack_34 = iStack_34 + -3;
  local_40 = local_40 + 6;
  iStack_38 = iStack_38 + -6;
  iVar5 = *in_stack_00000004;
  *(int *)(iVar5 + 0xc) = local_40;
  *(int *)(iVar5 + 0x10) = iStack_3c;
  *(int *)(iVar5 + 0x14) = iStack_38;
  *(int *)(iVar5 + 0x18) = iStack_34;
  if (0 < (int)local_14) {
    do {
      if ((uint)this->i_78 <= uVar4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_1c = (int *)FUN_00519e20(*(undefined4 *)(this->i_74 + uVar4 * 8));
      if (local_1c != (int *)0x0) {
        if ((uint)this->i_78 <= uVar4) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (0.0 < *(float *)(this->i_74 + 4 + uVar4 * 8)) {
          *(undefined1 *)((int)local_1c + 0x25) = 0;
        }
        fVar2 = this->f_84;
        if ((float)local_1c[5] <= this->f_84) {
          fVar2 = (float)local_1c[5];
        }
        this->f_84 = fVar2;
        fVar2 = this->f_88;
        if (this->f_88 <= (float)local_1c[5]) {
          fVar2 = (float)local_1c[5];
        }
        this->f_88 = fVar2;
        local_18 = local_1c[1];
        iVar5 = this->i_7c;
        if ((iVar5 == -1) || (-1 < this->i_80)) {
LAB_005195bc:
          local_20 = *local_1c + 0xc;
          local_18 = CONCAT13(0xcd,(undefined3)local_18);
          if ((uint)this->i_78 <= uVar4) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar10 = 1;
          local_24 = 0x14;
          local_28 = (int)*(float *)(this->i_74 + 4 + uVar4 * 8);
          piVar6 = &local_28;
        }
        else {
          if ((uint)this->i_78 <= uVar4) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar5 = this->i_7c;
          }
          iVar8 = this->i_74;
          pfVar1 = (float *)(iVar8 + 4 + uVar4 * 8);
          if ((float)iVar5 < *pfVar1 || (float)iVar5 == *pfVar1) goto LAB_005195bc;
          if ((uint)this->i_78 <= uVar4) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar5 = this->i_7c;
            iVar8 = this->i_74;
          }
          if ((float)local_1c[3] + *(float *)(iVar8 + 4 + uVar4 * 8) <= (float)iVar5)
          goto LAB_005195bc;
          local_20 = *local_1c + 0xc;
          if ((uint)this->i_78 <= uVar4) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar10 = 3;
          local_2c = (int *)0x14;
          local_30 = (int)*(float *)(this->i_74 + 4 + uVar4 * 8);
          piVar6 = &local_30;
        }
        FUN_004fdff0(piVar6,local_20,&local_18,local_4c,uVar10,uVar4 * 8);
        *(undefined1 *)(local_1c + 9) = 1;
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < (int)local_14);
  }
  if (this->c_6c != '\0') {
    local_24 = this->i_64;
    local_14 = 0;
    if (0 < local_24) {
      local_1c = (int *)0x0;
      local_18 = 0x2d;
      do {
        if (0xcc < local_18) break;
        if ((uint)this->i_64 <= local_14) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if ((this->i_68 & 1 << ((byte)*(undefined4 *)((int)local_1c + this->i_60 + 0xc) & 0x1f)) !=
            0) {
          if ((uint)this->i_64 <= local_14) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          piVar6 = *(int **)((int)local_1c + this->i_60);
          if (piVar6 != (int *)0x0) {
            *piVar6 = *piVar6 + 1;
          }
          local_8._0_1_ = 1;
          local_2c = piVar6;
          if ((uint)this->i_64 <= local_14) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iStack_38 = 5;
          uVar3 = 0xcd;
          if (local_14 == this->i_80) {
            uVar3 = 0xff;
          }
          iStack_34 = local_18;
          local_20 = CONCAT13(uVar3,(int3)*(undefined4 *)((int)local_1c + this->i_60 + 4));
          FUN_004fdff0(&iStack_38,piVar6 + 3,&local_20,local_4c,1,local_18);
          local_18 = local_18 + 0x14;
          local_8 = CONCAT31(local_8._1_3_,2);
          if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 == 0)) {
            FUN_006ba940();
          }
        }
        local_1c = local_1c + 5;
        local_14 = local_14 + 1;
      } while ((int)local_14 < local_24);
    }
  }
  local_8 = 3;
  if ((local_4c[0] != (int *)0x0) && (*local_4c[0] = *local_4c[0] + -1, *local_4c[0] == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

