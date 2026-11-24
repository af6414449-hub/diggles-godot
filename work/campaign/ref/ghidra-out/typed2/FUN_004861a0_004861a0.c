
/* WARNING: Removing unreachable block (ram,0x004861ef) */

void FUN_004861a0(float *param_1,float *param_2)

{
  float fVar1;
  uint uVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  uint local_50;
  float local_4c;
  float local_48;
  int local_44;
  int local_40;
  uint local_3c;
  float *local_38;
  float *local_34;
  float *local_30;
  int local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  uint local_18;
  float *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fde6d;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar8 = *(int *)(in_ECX + 0xc);
  local_2c = in_ECX;
  if (iVar8 < 0) {
    FUN_00491e00(-iVar8);
  }
  else if (0 < iVar8) {
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) - iVar8;
  }
  uVar6 = 0;
  local_24 = 3.4028235e+38;
  local_28 = 3.4028235e+38;
  local_1c = -3.4028235e+38;
  local_20 = -3.4028235e+38;
  do {
    pfVar3 = param_2;
    if ((uVar6 & 1) == 0) {
      pfVar3 = param_1;
    }
    if ((uVar6 & 2) == 0) {
      fVar10 = param_1[1];
    }
    else {
      fVar10 = param_2[1];
    }
    if ((uVar6 & 4) == 0) {
      fVar12 = param_1[2];
    }
    else {
      fVar12 = param_2[2];
    }
    fVar11 = *(float *)(in_ECX + 0x50) * *pfVar3 + fVar10 * *(float *)(in_ECX + 0x60) +
             *(float *)(in_ECX + 0x70) * fVar12 + *(float *)(in_ECX + 0x80);
    fVar10 = *(float *)(in_ECX + 0x54) * *pfVar3 + *(float *)(in_ECX + 100) * fVar10 +
             *(float *)(in_ECX + 0x74) * fVar12 + *(float *)(in_ECX + 0x84);
    if (fVar11 < local_24) {
      local_24 = fVar11;
    }
    if (local_1c < fVar11) {
      local_1c = fVar11;
    }
    if (fVar10 < local_28) {
      local_28 = fVar10;
    }
    if (local_20 < fVar10) {
      local_20 = fVar10;
    }
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 8);
  fVar10 = ROUND(local_24);
  fVar12 = ROUND(local_1c);
  fVar11 = ROUND(local_28);
  fVar1 = ROUND(local_20);
  DAT_00772dd8 = (int)fVar1;
  local_30 = (float *)FUN_00592d70(uVar2);
  FUN_0040ba00();
  local_8 = 0;
  local_58 = ((int)fVar1 + 7U & 0xfffffff8) + 8;
  local_64 = ((int)fVar10 & 0xfffffff8U) - 8;
  local_60 = ((int)fVar11 & 0xfffffff8U) - 8;
  local_5c = ((int)fVar12 + 7U & 0xfffffff8) + 8;
  FUN_0047e7b0(&local_64,0);
  local_44 = local_60;
  iVar8 = local_5c;
  iVar5 = local_60;
  if (local_60 < local_58) {
    do {
      local_40 = local_64;
      local_44 = iVar5;
      if (local_64 < iVar8) {
        do {
          FUN_005645f0(&local_54,local_40,iVar5);
          local_3c = 0;
          pfVar3 = local_30;
          if (0 < (int)local_50) {
            do {
              uVar2 = local_3c;
              if (local_50 <= local_3c) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              local_18 = *(uint *)(local_54 + uVar2 * 4);
              pfVar9 = (float *)(local_18 * 0x24);
              local_38 = pfVar9;
              if (local_18 < 0x800) {
                pfVar4 = (float *)((int)pfVar9 + (int)pfVar3);
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pfVar4 = pfVar3;
              }
              fVar10 = *pfVar4;
              fVar12 = pfVar4[1];
              if (local_18 < 0x800) {
                pfVar4 = (float *)((int)pfVar9 + (int)pfVar3);
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pfVar4 = pfVar3;
              }
              iVar8 = local_2c;
              local_14 = (float *)((int)pfVar9 + (int)pfVar3);
              local_4c = pfVar4[6];
              if ((((0.0 < local_4c) && (local_24 - local_4c <= fVar10)) &&
                  (local_28 - local_4c <= fVar12)) &&
                 ((fVar10 < local_1c + local_4c && (fVar12 < local_20 + local_4c)))) {
                FUN_00491e00(1);
                uVar6 = *(uint *)(iVar8 + 0xc);
                uVar2 = uVar6 - 1;
                pfVar9 = local_14;
                if (0x7ff < local_18) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  uVar6 = *(uint *)(iVar8 + 0xc);
                  pfVar9 = pfVar3;
                }
                fVar10 = *pfVar9;
                local_34 = (float *)pfVar9[1];
                local_48 = pfVar9[2];
                if (uVar6 <= uVar2) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                iVar5 = *(int *)(iVar8 + 8);
                iVar7 = uVar2 * 0x1c;
                *(float *)(iVar5 + iVar7) = fVar10;
                *(float **)(iVar5 + 4 + iVar7) = local_34;
                *(float *)(iVar5 + 8 + iVar7) = local_48;
                local_34 = *(float **)(iVar8 + 0xc);
                if (local_34 <= uVar2) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  local_34 = *(float **)(iVar8 + 0xc);
                }
                iVar5 = *(int *)(iVar8 + 8);
                local_48 = (float)(iVar5 + iVar7);
                if (local_34 <= uVar2) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar5 = *(int *)(iVar8 + 8);
                }
                pfVar3 = local_30;
                *(float *)(iVar7 + 8 + iVar5) = *(float *)((int)local_48 + 8) * 0.5 + 7.0;
                if (*(uint *)(iVar8 + 0xc) <= uVar2) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                *(float *)(iVar7 + 0xc + *(int *)(iVar8 + 8)) = local_4c * local_4c;
                pfVar9 = local_14;
                if (0x7ff < local_18) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  local_14 = pfVar3;
                  pfVar9 = (float *)((int)local_38 + (int)pfVar3);
                }
                local_34 = pfVar9;
                if (*(uint *)(iVar8 + 0xc) <= uVar2) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                *(float *)(iVar7 + 0x10 + *(int *)(iVar8 + 8)) = (float)(int)local_14[3] * 0.5;
                if (local_18 < 0x800) {
                  local_38 = (float *)((int)local_38 + (int)pfVar3);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  local_38 = pfVar3;
                }
                if (*(uint *)(iVar8 + 0xc) <= uVar2) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                *(float *)(iVar7 + 0x14 + *(int *)(iVar8 + 8)) = (float)(int)local_38[4] * 0.5;
                if (0x7ff < local_18) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  local_34 = pfVar3;
                }
                if (*(uint *)(iVar8 + 0xc) <= uVar2) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                *(float *)(iVar7 + 0x18 + *(int *)(iVar8 + 8)) = (float)(int)local_34[5] * 0.5;
              }
              local_3c = local_3c + 1;
              iVar5 = local_44;
            } while ((int)local_3c < (int)local_50);
          }
          local_40 = local_40 + 8;
          iVar8 = local_5c;
        } while (local_40 < local_5c);
      }
      local_44 = iVar5 + 8;
      iVar5 = local_44;
    } while (local_44 < local_58);
  }
  local_8 = 1;
  FUN_0040b980(0);
  if (local_54 != 0) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

