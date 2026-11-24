
bool CAct_Lore__GetPosRotSpeed
               (int param_1,float *param_2,undefined4 *param_3,float *param_4,float *param_5,
               float *param_6)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float in_XMM2_Da;
  float fVar11;
  float fVar12;
  undefined8 uVar13;
  undefined1 local_5c [12];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  uint local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  uint local_c;
  float local_8;
  
                    /* WARNING: Load size is inaccurate */
  local_1c = in_XMM2_Da;
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c3ca9c) &&
     (FUN_006cebf4(&DAT_00c3ca9c), iVar3 = DAT_00783650, DAT_00c3ca9c == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00c3caa0 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "CAct_Lore::GetPosRotSpeed()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00c3ca9c);
  }
  iVar4 = DAT_00c3caa0;
  uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00c3caa0 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar2;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar13 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar13;
  }
  fVar8 = 0.0;
  if (0.0 <= local_1c) {
    fVar8 = local_1c;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  fVar1 = *(float *)(param_1 + 0x10);
  local_8 = fVar8;
  if (fVar1 < fVar8) {
    local_8 = fVar1;
  }
  local_c = 0;
  if (1 < *(int *)(param_1 + 8)) {
    uVar7 = 1;
    iVar3 = 0;
    do {
      uVar6 = *(uint *)(param_1 + 8);
      if (uVar6 <= local_c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar6 = *(uint *)(param_1 + 8);
      }
      fVar9 = *(float *)(param_1 + 4);
      local_18 = *(float *)((int)fVar9 + 8 + iVar3) * 0.5;
      local_1c = *(float *)((int)fVar9 + iVar3);
      local_14 = *(float *)((int)fVar9 + 4 + iVar3);
      if (uVar6 <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        fVar9 = *(float *)(param_1 + 4);
      }
      fVar10 = local_1c - *(float *)((int)fVar9 + 0x20 + iVar3);
      fVar12 = local_14 - *(float *)((int)fVar9 + 0x24 + iVar3);
      fVar11 = local_18 - *(float *)((int)fVar9 + 0x28 + iVar3) * 0.5;
      fVar10 = fVar10 * fVar10 + fVar12 * fVar12 + fVar11 * fVar11;
      local_10 = fVar9;
      FUN_0040b7e0();
      uVar6 = local_c;
      if (local_8 < fVar10) {
        if (fVar10 != 0.0) {
          local_8 = local_8 / fVar10;
          uVar7 = *(uint *)(param_1 + 8);
          fVar9 = local_10;
          if (uVar7 <= local_c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar7 = *(uint *)(param_1 + 8);
            fVar9 = *(float *)(param_1 + 4);
          }
          local_c = uVar6 * 0x20;
          local_10 = *(float *)(local_c + (int)fVar9);
          local_14 = *(float *)(local_c + 4 + (int)fVar9);
          local_18 = *(float *)(local_c + 8 + (int)fVar9);
          local_20 = uVar6 + 1;
          if (uVar7 <= local_20) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            fVar9 = *(float *)(param_1 + 4);
          }
          iVar3 = (uVar6 + 1) * 0x20;
          local_24 = *(float *)(iVar3 + (int)fVar9);
          local_28 = *(float *)(iVar3 + 4 + (int)fVar9);
          local_2c = *(float *)(iVar3 + 8 + (int)fVar9);
          local_30 = local_24 - local_10;
          local_1c = local_28 - local_14;
          local_34 = local_2c - local_18;
          *param_2 = local_30 * local_8 + local_10;
          param_2[1] = local_1c * local_8 + local_14;
          param_2[2] = local_34 * local_8 + local_18;
          uVar7 = *(uint *)(param_1 + 8);
          if (uVar7 <= uVar6) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar7 = *(uint *)(param_1 + 8);
          }
          iVar3 = *(int *)(param_1 + 4);
          local_50 = *(undefined4 *)(iVar3 + 0xc + local_c);
          local_4c = *(undefined4 *)(iVar3 + 0x10 + local_c);
          local_48 = *(undefined4 *)(iVar3 + 0x14 + local_c);
          if (uVar7 <= uVar6 + 1) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(param_1 + 4);
          }
          iVar4 = (uVar6 + 1) * 0x20;
          local_44 = *(undefined4 *)(iVar4 + 0xc + iVar3);
          local_40 = *(undefined4 *)(iVar4 + 0x10 + iVar3);
          local_3c = *(undefined4 *)(iVar4 + 0x14 + iVar3);
          puVar5 = (undefined4 *)FUN_00413c70(local_5c,&local_50,&local_44,local_8);
          *param_3 = *puVar5;
          param_3[1] = puVar5[1];
          param_3[2] = puVar5[2];
          uVar7 = *(uint *)(param_1 + 8);
          if (uVar7 <= uVar6) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar7 = *(uint *)(param_1 + 8);
          }
          iVar3 = *(int *)(param_1 + 4);
          fVar9 = *(float *)(iVar3 + 0x18 + local_c);
          if (uVar7 <= uVar6 + 1) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(param_1 + 4);
          }
          fVar10 = 1.0 - local_8;
          *param_5 = *(float *)((uVar6 + 1) * 0x20 + 0x18 + iVar3) * local_8 + fVar10 * fVar9;
          uVar7 = *(uint *)(param_1 + 8);
          if (uVar7 <= uVar6) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar7 = *(uint *)(param_1 + 8);
          }
          uVar6 = local_20;
          iVar3 = *(int *)(param_1 + 4);
          fVar9 = *(float *)(iVar3 + 0x1c + local_c);
          if (uVar7 <= local_20) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(param_1 + 4);
          }
          *param_6 = *(float *)(uVar6 * 0x20 + 0x1c + iVar3) * local_8 + fVar10 * fVar9;
          param_1._3_1_ = fVar8 <= fVar1;
          if (((local_10 != local_24) || (local_14 != local_28)) || (local_18 != local_2c)) {
            fVar9 = local_1c * local_1c + local_30 * local_30 + local_34 * local_34;
            FUN_0040b7e0();
            *param_4 = ((local_1c / fVar9) * *(float *)(local_38 + 0x1c) * 0.1) /
                       (float)(*(int *)(local_38 + 0x28) + 1) + *param_4;
          }
          goto LAB_0041403c;
        }
        break;
      }
      local_8 = local_8 - fVar10;
      local_c = local_c + 1;
      uVar7 = uVar7 + 1;
      iVar3 = iVar3 + 0x20;
    } while ((int)uVar7 < *(int *)(param_1 + 8));
  }
  param_1._3_1_ = false;
LAB_0041403c:
  FUN_0043fd30();
  return param_1._3_1_;
}

