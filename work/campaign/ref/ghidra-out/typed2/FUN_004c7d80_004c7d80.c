
/* WARNING: Removing unreachable block (ram,0x004c7dde) */

void __thiscall FUN_004c7d80(CSceneRenderer *this)

{
  int *piVar1;
  uint uVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  bool bVar7;
  float *in_stack_00000004;
  float local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  uint local_48;
  float local_44;
  float local_40;
  uint local_3c;
  float *local_38;
  float *local_34;
  int local_30;
  int local_2c;
  float *local_28;
  float *local_24;
  CSceneRenderer *local_20;
  uint local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fea2d;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = this->statB;
  piVar1 = &this->statA;
  local_20 = this;
  if (iVar4 < 0) {
    FUN_00491e00(-iVar4);
  }
  else if (0 < iVar4) {
    this->statB = this->statB - iVar4;
  }
  if (local_20->flag2 != '\0') {
    local_24 = (float *)FUN_00592d70(uVar2);
    FUN_0040ba00();
    local_8 = 0;
    local_40 = in_stack_00000004[1];
    DAT_00772dd8 = (uint)ROUND(local_40);
    local_5c = (float)(((int)ROUND(*in_stack_00000004) & 0xfffffff8U) - 8);
    local_50 = (DAT_00772dd8 & 0xfffffff8) + 0x10;
    local_58 = (DAT_00772dd8 & 0xfffffff8) - 8;
    local_54 = ((int)ROUND(*in_stack_00000004) & 0xfffffff8U) + 0x10;
    FUN_0047e7b0(&local_5c,0);
    local_30 = local_58;
    iVar4 = local_54;
    if (local_58 < local_50) {
      do {
        local_40 = local_5c;
        if ((int)local_5c < iVar4) {
          do {
            FUN_005645f0(&local_4c,local_40,local_30);
            local_3c = 0;
            if (0 < (int)local_48) {
              bVar7 = local_48 != 0;
              do {
                uVar2 = local_3c;
                if (!bVar7) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                local_1c = *(uint *)(local_4c + uVar2 * 4);
                local_2c = local_1c * 0x24;
                if (local_1c < 0x800) {
                  pfVar3 = local_24 + local_1c * 9;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar3 = local_24;
                }
                pfVar5 = local_24;
                local_38 = (float *)pfVar3[6];
                if (0.0 < (float)local_38) {
                  if (local_1c < 0x800) {
                    pfVar3 = (float *)(local_2c + (int)local_24);
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar3 = pfVar5;
                  }
                  local_28 = (float *)(local_2c + (int)pfVar5);
                  if ((pfVar3[1] - in_stack_00000004[1]) * (pfVar3[1] - in_stack_00000004[1]) +
                      (*pfVar3 - *in_stack_00000004) * (*pfVar3 - *in_stack_00000004) <
                      ((float)local_38 + 1.0) * ((float)local_38 + 1.0)) {
                    FUN_00491e00(1);
                    uVar2 = this->statB;
                    local_14 = uVar2 - 1;
                    pfVar3 = local_28;
                    if (0x7ff < local_1c) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      uVar2 = local_20->statB;
                      pfVar3 = pfVar5;
                    }
                    local_34 = (float *)*pfVar3;
                    local_18 = pfVar3[1];
                    local_44 = pfVar3[2];
                    if (uVar2 <= local_14) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    iVar4 = *piVar1;
                    iVar6 = local_14 * 0x1c;
                    *(float **)(iVar4 + iVar6) = local_34;
                    *(float *)(iVar4 + 4 + iVar6) = local_18;
                    *(float *)(iVar4 + 8 + iVar6) = local_44;
                    local_34 = (float *)this->statB;
                    local_18 = (float)iVar6;
                    if (local_34 <= local_14) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      local_34 = (float *)local_20->statB;
                    }
                    iVar4 = *piVar1;
                    local_44 = (float)(iVar4 + (int)local_18);
                    if (local_34 <= local_14) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      iVar4 = *piVar1;
                    }
                    pfVar3 = local_24;
                    *(float *)(iVar4 + 8 + (int)local_18) =
                         *(float *)((int)local_44 + 8) * 0.5 + 7.0;
                    if ((uint)this->statB <= local_14) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    *(float *)(*piVar1 + 0xc + (int)local_18) = (float)local_38 * (float)local_38;
                    pfVar5 = local_28;
                    if (0x7ff < local_1c) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      local_28 = pfVar3;
                      pfVar5 = (float *)(local_2c + (int)pfVar3);
                    }
                    local_34 = pfVar5;
                    if ((uint)this->statB <= local_14) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    *(float *)((int)local_18 + 0x10 + *piVar1) = (float)(int)local_28[3] * 0.5;
                    if (local_1c < 0x800) {
                      local_38 = (float *)(local_2c + (int)pfVar3);
                    }
                    else {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      local_38 = pfVar3;
                    }
                    if ((uint)this->statB <= local_14) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    *(float *)((int)local_18 + 0x14 + *piVar1) = (float)(int)local_38[4] * 0.5;
                    pfVar5 = local_34;
                    if (0x7ff < local_1c) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      pfVar5 = pfVar3;
                    }
                    if ((uint)this->statB <= local_14) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    *(float *)(*piVar1 + 0x18 + (int)local_18) = (float)(int)pfVar5[5] * 0.5;
                  }
                }
                local_3c = local_3c + 1;
                bVar7 = local_3c < local_48;
              } while ((int)local_3c < (int)local_48);
            }
            local_40 = (float)((int)local_40 + 8);
            iVar4 = local_54;
          } while ((int)local_40 < local_54);
        }
        local_30 = local_30 + 8;
      } while (local_30 < local_50);
    }
    local_8 = 1;
    FUN_0040b980(0);
    if (local_4c != 0) {
      FUN_006ba940();
    }
  }
  ExceptionList = local_10;
  return;
}

