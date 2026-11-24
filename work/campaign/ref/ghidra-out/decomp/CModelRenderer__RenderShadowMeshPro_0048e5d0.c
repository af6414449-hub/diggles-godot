
void CModelRenderer__RenderShadowMeshPro
               (undefined4 *param_1,int param_2,float *param_3,float *param_4,float param_5,
               float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined4 uVar14;
  uint uVar15;
  int *piVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  int iVar20;
  float *pfVar21;
  float *pfVar22;
  float *pfVar23;
  int iVar24;
  undefined4 *puVar25;
  float *pfVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float *pfVar33;
  undefined8 uVar34;
  float *local_9c;
  float *local_94;
  float *local_90;
  float local_8c;
  int local_88;
  float *local_84;
  float local_80;
  float *local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006fe1eb;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_90 = param_3;
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c8ae98) &&
     (FUN_006cebf4(&DAT_00c8ae98,local_14), iVar20 = DAT_00783650, DAT_00c8ae98 == -1)) {
    iVar24 = DAT_00783650 * 0x40;
    DAT_00c8ae9c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar24) = "CModelRenderer::RenderShadowMeshPro";
    *(int *)(&DAT_00773650 + iVar24) = iVar20;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00c8ae98);
  }
  iVar24 = DAT_00c8ae9c;
  uVar14 = *(undefined4 *)(&DAT_00773650 + DAT_00c8ae9c * 0x40);
  iVar20 = FUN_0043fcc0();
  *(undefined4 *)(iVar20 + *(int *)(iVar20 + 0x8000) * 4) = uVar14;
  *(int *)(iVar20 + 0x8000) = *(int *)(iVar20 + 0x8000) + 1;
  iVar20 = (&DAT_00773654)[iVar24 * 0x10];
  if (iVar20 == 0) {
    uVar34 = FUN_006bd180();
    iVar20 = (&DAT_00773654)[iVar24 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar24 * 0x10) = uVar34;
  }
  (&DAT_00773654)[iVar24 * 0x10] = iVar20 + 1;
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar20 = *(int *)(local_88 + 0x110);
  if ((param_2 < 0) || (*(int *)(iVar20 + 0x38) <= param_2)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iVar20 = *(int *)(iVar20 + 0x34);
  }
  else {
    iVar20 = *(int *)(iVar20 + 0x34) + param_2 * 0xe8;
  }
  local_8c = (float)(param_2 * 0xe8);
  uVar15 = *(uint *)(iVar20 + 4);
  if (uVar15 == 0xffffffff) {
    FUN_0043fd30();
    if (param_1 != (undefined4 *)0x0) {
      LOCK();
      iVar20 = param_1[1] + -1;
      param_1[1] = iVar20;
      UNLOCK();
      if ((iVar20 == 0) && (param_1 != (undefined4 *)0x0)) {
        (**(code **)*param_1)(1);
      }
    }
  }
  else {
    iVar20 = *(int *)(local_88 + 0x110);
    if ((param_2 < 0) || (*(int *)(iVar20 + 0x38) <= param_2)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar20 = *(int *)(iVar20 + 0x34);
    }
    else {
      iVar20 = *(int *)(iVar20 + 0x34) + (int)local_8c;
    }
    _eh_vector_constructor_iterator_(&local_80,0xc,9,FUN_00405b50,guard_check_icall);
    local_8 = CONCAT31(local_8._1_3_,2);
    local_84 = *(float **)(iVar20 + 8);
    local_7c = *(float **)(iVar20 + 0xc);
    fVar31 = *(float *)(iVar20 + 0x10);
    fVar1 = *(float *)(iVar20 + 0x14);
    fVar30 = *local_90 - *param_4;
    local_70 = *(float *)(iVar20 + 0x18);
    fVar2 = *(float *)(iVar20 + 0x1c);
    local_8c = local_90[2] - param_4[2];
    fVar3 = *(float *)(iVar20 + 0x20);
    local_64 = *(float *)(iVar20 + 0x24);
    fVar32 = *(float *)(iVar20 + 0x28);
    fVar4 = *(float *)(iVar20 + 0x2c);
    local_58 = *(float *)(iVar20 + 0x30);
    fVar5 = *(float *)(iVar20 + 0x34);
    fVar27 = fVar30 * fVar30 + (local_90[1] - param_4[1]) * (local_90[1] - param_4[1]) +
             local_8c * local_8c;
    local_80 = (float)local_84;
    local_78 = fVar31;
    local_74 = fVar1;
    local_6c = fVar2;
    local_68 = fVar3;
    local_60 = fVar32;
    local_5c = fVar4;
    FUN_0040b7e0();
    if (fVar27 <= 0.0) {
      fVar27 = 0.0;
      fVar28 = 0.0;
    }
    else {
      fVar28 = fVar30 / fVar27;
      fVar27 = local_8c / fVar27;
    }
    fVar28 = fVar28 * fVar28 + 0.0 + fVar27 * fVar27;
    FUN_0040b7e0();
    fVar27 = 0.1;
    if (0.1 <= fVar28) {
      fVar27 = fVar28;
    }
    local_80 = (float)local_84;
    local_7c = (float *)0xc1400000;
    local_70 = -12.0;
    local_64 = -12.0;
    local_58 = -12.0;
    local_60 = (fVar28 + 0.5) * fVar32;
    local_54 = (fVar28 + 0.5) * fVar5;
    local_68 = fVar3 * (1.5 / fVar27) + fVar30 * 100.0;
    local_5c = fVar4 * (1.5 / fVar27) + fVar30 * 100.0;
    if (((int)uVar15 < 0) ||
       (local_78 = fVar31, local_74 = fVar1, local_6c = fVar2,
       *(int *)(*(int *)(local_88 + 0x110) + 0x20) <= (int)uVar15)) {
      local_78 = fVar31;
      local_74 = fVar1;
      local_6c = fVar2;
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar20 = FUN_006ba810(0x94c);
    if (iVar20 == 0) {
      puVar25 = (undefined4 *)param_1[0x11];
      param_1[0x11] = 0;
    }
    else {
      iVar20 = FUN_0045fae0();
      puVar25 = (undefined4 *)param_1[0x11];
      param_1[0x11] = iVar20;
      if (iVar20 != 0) {
        LOCK();
        *(int *)(iVar20 + 4) = *(int *)(iVar20 + 4) + 1;
        UNLOCK();
      }
    }
    if (puVar25 != (undefined4 *)0x0) {
      LOCK();
      iVar20 = puVar25[1] + -1;
      puVar25[1] = iVar20;
      UNLOCK();
      if (iVar20 == 0) {
        (**(code **)*puVar25)(1);
      }
    }
    pfVar21 = (float *)FUN_006ba810(0x94e);
    *(undefined4 *)(param_1[0x11] + 0x28) = 0;
    param_1[2] = 0x19;
    param_1[4] = 0x1a;
    param_1[5] = (int)(param_6 * 255.0) & 0xff;
    if (*(uint *)(local_88 + 0x128) <= uVar15) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    pfVar22 = local_90;
    param_1[0xf] = *(undefined4 *)(*(int *)(local_88 + 0x124) + uVar15 * 4);
    param_1[3] = 4;
    param_1[6] = *local_90;
    param_1[7] = local_90[1];
    param_1[8] = local_90[2];
    local_90 = local_7c;
    local_4c = (local_70 + (float)local_7c) * 0.5;
    local_50 = (local_74 + local_80) * 0.5;
    local_48 = (local_6c + local_78) * 0.5;
    local_44 = (local_68 + local_80) * 0.5;
    local_40 = (local_64 + (float)local_7c) * 0.5;
    local_3c = (local_78 + local_60) * 0.5;
    local_24 = (local_6c + local_54) * 0.5;
    local_28 = (local_58 + local_70) * 0.5;
    local_2c = (local_5c + local_74) * 0.5;
    local_20 = (local_5c + local_68) * 0.5;
    local_1c = (local_58 + local_64) * 0.5;
    local_18 = (local_54 + local_60) * 0.5;
    param_5 = param_5 + 0.025;
    pfVar23 = pfVar21 + 7;
    local_84 = pfVar21 + 0xe;
    local_34 = (local_40 + local_4c + local_28 + local_1c) * 0.25;
    local_30 = (local_3c + local_48 + local_24 + local_18) * 0.25;
    local_38 = (local_44 + local_50 + local_2c + local_20) * 0.25;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[5] = 0.0;
    pfVar21[6] = 0.0;
    *pfVar21 = (local_80 * 0.005 + fVar31) - 0.0;
    pfVar21[1] = ((float)local_7c * 0.005 + fVar1) - param_5;
    pfVar21[2] = (local_78 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[2];
    fVar2 = pfVar22[1];
    pfVar21[0xc] = 0.5;
    pfVar21[0xd] = 0.0;
    pfVar21[9] = (local_48 * 0.005 + fVar1) - 0.0;
    pfVar21[8] = (local_4c * 0.005 + fVar2) - param_5;
    *pfVar23 = (fVar31 + local_50 * 0.005) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[2];
    fVar2 = pfVar22[1];
    pfVar21[0x13] = 0.0;
    pfVar21[0x14] = 0.5;
    pfVar21[0x10] = (local_3c * 0.005 + fVar1) - 0.0;
    pfVar21[0xf] = (local_40 * 0.005 + fVar2) - param_5;
    *local_84 = (fVar31 + local_44 * 0.005) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x1a] = 0.5;
    pfVar21[0x1b] = 0.0;
    pfVar21[0x15] = (local_50 * 0.005 + fVar31) - 0.0;
    pfVar21[0x16] = (local_4c * 0.005 + fVar1) - param_5;
    pfVar21[0x17] = (local_48 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x21] = 0.5;
    pfVar21[0x22] = 0.5;
    pfVar21[0x1c] = (local_38 * 0.005 + fVar31) - 0.0;
    pfVar21[0x1d] = (local_34 * 0.005 + fVar1) - param_5;
    pfVar21[0x1e] = (local_30 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x28] = 0.0;
    pfVar21[0x29] = 0.5;
    pfVar21[0x23] = (local_44 * 0.005 + fVar31) - 0.0;
    pfVar21[0x24] = (local_40 * 0.005 + fVar1) - param_5;
    pfVar21[0x25] = (local_3c * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x2f] = 0.5;
    pfVar21[0x30] = 0.0;
    pfVar21[0x2a] = (local_50 * 0.005 + fVar31) - 0.0;
    pfVar21[0x2b] = (local_4c * 0.005 + fVar1) - param_5;
    pfVar21[0x2c] = (local_48 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x36] = 1.0;
    pfVar21[0x37] = 0.0;
    pfVar21[0x31] = (local_74 * 0.005 + fVar31) - 0.0;
    pfVar21[0x32] = (local_70 * 0.005 + fVar1) - param_5;
    pfVar21[0x33] = (local_6c * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x3d] = 0.5;
    pfVar21[0x3e] = 0.5;
    pfVar21[0x38] = (local_38 * 0.005 + fVar31) - 0.0;
    pfVar21[0x39] = (local_34 * 0.005 + fVar1) - param_5;
    pfVar21[0x3a] = (local_30 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x44] = 1.0;
    pfVar21[0x45] = 0.0;
    pfVar21[0x3f] = (local_74 * 0.005 + fVar31) - 0.0;
    pfVar21[0x40] = (local_70 * 0.005 + fVar1) - param_5;
    pfVar21[0x41] = (local_6c * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x4b] = 1.0;
    pfVar21[0x4c] = 0.5;
    pfVar21[0x46] = (local_2c * 0.005 + fVar31) - 0.0;
    pfVar21[0x47] = (local_28 * 0.005 + fVar1) - param_5;
    pfVar21[0x48] = (local_24 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x52] = 0.5;
    pfVar21[0x53] = 0.5;
    pfVar21[0x4d] = (local_38 * 0.005 + fVar31) - 0.0;
    pfVar21[0x4e] = (local_34 * 0.005 + fVar1) - param_5;
    pfVar21[0x4f] = (local_30 * 0.005 + fVar2) - 0.0;
    fVar31 = pfVar22[1];
    fVar1 = pfVar22[2];
    pfVar21[0x54] = (local_44 * 0.005 + *pfVar22) - 0.0;
    pfVar21[0x55] = (local_40 * 0.005 + fVar31) - param_5;
    pfVar21[0x56] = (local_3c * 0.005 + fVar1) - 0.0;
    pfVar21[0x59] = 0.0;
    pfVar21[0x5a] = 0.5;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x60] = 0.5;
    pfVar21[0x61] = 0.5;
    pfVar21[0x5b] = (local_38 * 0.005 + fVar31) - 0.0;
    pfVar21[0x5c] = (local_34 * 0.005 + fVar1) - param_5;
    pfVar21[0x5d] = (local_30 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x67] = 0.0;
    pfVar21[0x68] = 1.0;
    pfVar21[0x62] = (local_68 * 0.005 + fVar31) - 0.0;
    pfVar21[99] = (local_64 * 0.005 + fVar1) - param_5;
    pfVar21[100] = (local_60 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x6e] = 0.5;
    pfVar21[0x6f] = 0.5;
    pfVar21[0x69] = (local_38 * 0.005 + fVar31) - 0.0;
    pfVar21[0x6a] = (local_34 * 0.005 + fVar1) - param_5;
    pfVar21[0x6b] = (local_30 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x75] = 0.5;
    pfVar21[0x76] = 1.0;
    pfVar21[0x70] = (local_20 * 0.005 + fVar31) - 0.0;
    pfVar21[0x71] = (local_1c * 0.005 + fVar1) - param_5;
    pfVar21[0x72] = (local_18 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x7c] = 0.0;
    pfVar21[0x7d] = 1.0;
    pfVar21[0x77] = (local_68 * 0.005 + fVar31) - 0.0;
    pfVar21[0x78] = (local_64 * 0.005 + fVar1) - param_5;
    pfVar21[0x79] = (local_60 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x83] = 0.5;
    pfVar21[0x84] = 0.5;
    pfVar21[0x7e] = (local_38 * 0.005 + fVar31) - 0.0;
    pfVar21[0x7f] = (local_34 * 0.005 + fVar1) - param_5;
    pfVar21[0x80] = (local_30 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x8a] = 1.0;
    pfVar21[0x8b] = 0.5;
    pfVar21[0x85] = (local_2c * 0.005 + fVar31) - 0.0;
    pfVar21[0x86] = (local_28 * 0.005 + fVar1) - param_5;
    pfVar21[0x87] = (local_24 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x91] = 0.5;
    pfVar21[0x92] = 1.0;
    pfVar21[0x8c] = (local_20 * 0.005 + fVar31) - 0.0;
    pfVar21[0x8d] = (local_1c * 0.005 + fVar1) - param_5;
    pfVar21[0x8e] = (local_18 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0x98] = 1.0;
    pfVar21[0x99] = 0.5;
    pfVar21[0x93] = (local_2c * 0.005 + fVar31) - 0.0;
    pfVar21[0x94] = (local_28 * 0.005 + fVar1) - param_5;
    pfVar21[0x95] = (local_24 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    local_88 = 0x18;
    fVar2 = pfVar22[2];
    pfVar21[0x9f] = 1.0;
    pfVar21[0xa0] = 1.0;
    pfVar21[0x9a] = (local_5c * 0.005 + fVar31) - 0.0;
    pfVar21[0x9b] = (local_58 * 0.005 + fVar1) - param_5;
    pfVar21[0x9c] = (local_54 * 0.005 + fVar2) - 0.0;
    fVar31 = *pfVar22;
    fVar1 = pfVar22[1];
    fVar2 = pfVar22[2];
    pfVar21[0xa6] = 0.5;
    pfVar21[0xa7] = 1.0;
    iVar20 = 0x18;
    pfVar21[0xa1] = (local_20 * 0.005 + fVar31) - 0.0;
    pfVar21[0xa2] = (local_1c * 0.005 + fVar1) - param_5;
    pfVar21[0xa3] = (local_18 * 0.005 + fVar2) - 0.0;
    pfVar22 = pfVar21 + 4;
    do {
      pfVar22[-1] = -NAN;
      *pfVar22 = 0.0;
      iVar20 = iVar20 + -1;
      pfVar22 = pfVar22 + 7;
    } while (iVar20 != 0);
    pfVar26 = pfVar21 + 0xa8;
    param_1[6] = ((float)param_1[9] + (float)param_1[0xc]) * 0.5;
    param_1[7] = ((float)param_1[0xd] + (float)param_1[10]) * 0.5;
    param_1[8] = ((float)param_1[0xe] + (float)param_1[0xb]) * 0.5;
    local_94 = pfVar21 + 0xaf;
    local_9c = pfVar21 + 0xb6;
    local_8c = 0.0;
    pfVar22 = pfVar21;
    do {
      pfVar33 = (float *)pfVar22[2];
      if (((14.5 < (float)pfVar33) || (14.5 < pfVar22[9])) || (14.5 < pfVar22[0x10])) {
        if ((((float)pfVar33 <= 14.5) || (pfVar22[9] <= 14.5)) || (pfVar22[0x10] <= 14.5)) {
          fVar31 = pfVar22[9];
          if (fVar31 < (float)pfVar33) {
            fVar2 = pfVar23[1];
            fVar3 = pfVar23[2];
            fVar32 = pfVar23[3];
            fVar31 = pfVar22[6];
            fVar4 = *pfVar22;
            fVar5 = pfVar22[1];
            fVar27 = pfVar22[2];
            fVar30 = pfVar22[3];
            fVar1 = pfVar23[6];
            uVar34 = *(undefined8 *)(pfVar22 + 4);
            *pfVar22 = *pfVar23;
            pfVar22[1] = fVar2;
            pfVar22[2] = fVar3;
            pfVar22[3] = fVar32;
            *(undefined8 *)(pfVar22 + 4) = *(undefined8 *)(pfVar23 + 4);
            *pfVar23 = fVar4;
            pfVar23[1] = fVar5;
            pfVar23[2] = fVar27;
            pfVar23[3] = fVar30;
            pfVar22[6] = fVar1;
            pfVar33 = (float *)pfVar22[2];
            *(undefined8 *)(pfVar23 + 4) = uVar34;
            pfVar23[6] = fVar31;
            fVar31 = pfVar22[9];
          }
          if (pfVar22[0x10] <= fVar31 && fVar31 != pfVar22[0x10]) {
            fVar2 = *pfVar23;
            fVar3 = pfVar23[1];
            fVar32 = pfVar23[2];
            fVar4 = pfVar23[3];
            fVar1 = pfVar23[6];
            uVar34 = *(undefined8 *)(pfVar23 + 4);
            fVar31 = local_84[1];
            fVar5 = local_84[2];
            fVar27 = local_84[3];
            *pfVar23 = *local_84;
            pfVar23[1] = fVar31;
            pfVar23[2] = fVar5;
            pfVar23[3] = fVar27;
            fVar31 = local_84[6];
            *(undefined8 *)(pfVar23 + 4) = *(undefined8 *)(local_84 + 4);
            pfVar23[6] = fVar31;
            fVar31 = pfVar22[9];
            *local_84 = fVar2;
            local_84[1] = fVar3;
            local_84[2] = fVar32;
            local_84[3] = fVar4;
            *(undefined8 *)(local_84 + 4) = uVar34;
            local_84[6] = fVar1;
          }
          local_90 = pfVar33;
          if (fVar31 < (float)pfVar33) {
            fVar2 = pfVar23[1];
            fVar3 = pfVar23[2];
            fVar32 = pfVar23[3];
            fVar31 = pfVar22[6];
            fVar4 = *pfVar22;
            fVar5 = pfVar22[1];
            fVar27 = pfVar22[2];
            fVar30 = pfVar22[3];
            fVar1 = pfVar23[6];
            uVar34 = *(undefined8 *)(pfVar22 + 4);
            *pfVar22 = *pfVar23;
            pfVar22[1] = fVar2;
            pfVar22[2] = fVar3;
            pfVar22[3] = fVar32;
            *(undefined8 *)(pfVar22 + 4) = *(undefined8 *)(pfVar23 + 4);
            *pfVar23 = fVar4;
            pfVar23[1] = fVar5;
            pfVar23[2] = fVar27;
            pfVar23[3] = fVar30;
            pfVar22[6] = fVar1;
            local_90 = (float *)pfVar22[2];
            *(undefined8 *)(pfVar23 + 4) = uVar34;
            pfVar23[6] = fVar31;
            fVar31 = pfVar22[9];
          }
          fVar1 = pfVar22[8];
          fVar2 = pfVar22[0xc];
          fVar32 = 14.5 - (float)local_90;
          fVar3 = *pfVar23;
          if (fVar31 <= 14.5) {
            fVar4 = pfVar22[0xf];
            fVar5 = pfVar22[0x14];
            local_88 = local_88 + 3;
            fVar27 = pfVar22[0xd];
            fVar29 = (14.5 - fVar31) / (pfVar22[0x10] - fVar31);
            fVar31 = *local_84;
            fVar30 = pfVar22[6];
            fVar28 = pfVar22[0xd];
            fVar6 = *pfVar22;
            fVar7 = pfVar22[0x13];
            fVar32 = fVar32 / (pfVar22[0x10] - (float)local_90);
            fVar8 = pfVar22[1];
            fVar9 = *pfVar22;
            fVar10 = pfVar22[6];
            fVar11 = pfVar22[5];
            fVar12 = pfVar22[1];
            fVar17 = pfVar22[1];
            fVar18 = pfVar22[2];
            fVar19 = pfVar22[3];
            fVar13 = pfVar22[5];
            *pfVar26 = *pfVar22;
            pfVar26[1] = fVar17;
            pfVar26[2] = fVar18;
            pfVar26[3] = fVar19;
            *(undefined8 *)(pfVar26 + 4) = *(undefined8 *)(pfVar22 + 4);
            pfVar26[6] = pfVar22[6];
            pfVar26[8] = (fVar4 - fVar1) * fVar29 + fVar1;
            pfVar26[9] = 14.5;
            pfVar26[0xc] = (fVar7 - fVar2) * fVar29 + fVar2;
            *local_94 = (fVar31 - fVar3) * fVar29 + fVar3;
            pfVar26[0xd] = (fVar5 - fVar27) * fVar29 + fVar28;
            pfVar26[10] = -NAN;
            *local_9c = (fVar31 - fVar6) * fVar32 + fVar9;
            pfVar26[0xb] = 0.0;
            pfVar26[0xf] = (fVar4 - fVar8) * fVar32 + fVar12;
            pfVar26[0x10] = 14.5;
            fVar31 = *local_94;
            fVar1 = local_94[1];
            fVar2 = local_94[2];
            fVar3 = local_94[3];
            pfVar26[0x11] = -NAN;
            pfVar26[0x13] = (fVar7 - fVar11) * fVar32 + fVar13;
            pfVar26[0x14] = (fVar5 - fVar30) * fVar32 + fVar10;
            pfVar26[0x12] = 0.0;
            pfVar26 = pfVar26 + 0x15;
            *local_84 = fVar31;
            local_84[1] = fVar1;
            local_84[2] = fVar2;
            local_84[3] = fVar3;
            fVar31 = local_94[5];
            local_84[4] = local_94[4];
            local_84[5] = fVar31;
            local_84[6] = local_94[6];
            local_9c = local_9c + 0x15;
            local_94 = local_94 + 0x15;
          }
          else {
            fVar4 = pfVar22[5];
            pfVar22[9] = 14.5;
            fVar28 = fVar32 / (fVar31 - (float)local_90);
            fVar31 = *local_84;
            fVar5 = *pfVar22;
            pfVar22[8] = (fVar1 - pfVar22[1]) * fVar28 + pfVar22[1];
            fVar1 = pfVar22[0xd];
            *pfVar23 = (fVar3 - *pfVar22) * fVar28 + *pfVar22;
            fVar3 = pfVar22[6];
            pfVar22[0xc] = (fVar2 - fVar4) * fVar28 + fVar4;
            fVar2 = pfVar22[0xf];
            fVar27 = pfVar22[0x13];
            fVar30 = pfVar22[1];
            pfVar22[0xd] = (fVar1 - fVar3) * fVar28 + fVar3;
            fVar1 = pfVar22[0x10];
            pfVar22[0x10] = 14.5;
            fVar32 = fVar32 / (fVar1 - (float)local_90);
            fVar1 = pfVar22[0x14];
            fVar28 = pfVar22[1];
            *local_84 = (fVar31 - fVar5) * fVar32 + *pfVar22;
            pfVar22[0xf] = (fVar2 - fVar30) * fVar32 + fVar28;
            pfVar22[0x13] = (fVar27 - fVar4) * fVar32 + fVar4;
            pfVar22[0x14] = (fVar1 - fVar3) * fVar32 + fVar3;
          }
        }
        else {
          fVar31 = pfVar26[-0x14];
          fVar1 = pfVar26[-0x13];
          fVar2 = pfVar26[-0x12];
          *pfVar22 = pfVar26[-0x15];
          pfVar22[1] = fVar31;
          pfVar22[2] = fVar1;
          pfVar22[3] = fVar2;
          local_88 = local_88 + -3;
          *(undefined8 *)(pfVar22 + 4) = *(undefined8 *)(pfVar26 + -0x11);
          pfVar22[6] = pfVar26[-0xf];
          pfVar22 = pfVar22 + -0x15;
          local_8c = (float)((int)local_8c + -3);
          fVar31 = local_94[-0x14];
          fVar1 = local_94[-0x13];
          fVar2 = local_94[-0x12];
          *pfVar23 = local_94[-0x15];
          pfVar23[1] = fVar31;
          pfVar23[2] = fVar1;
          pfVar23[3] = fVar2;
          *(undefined8 *)(pfVar23 + 4) = *(undefined8 *)(local_94 + -0x11);
          pfVar23[6] = local_94[-0xf];
          pfVar23 = pfVar23 + -0x15;
          fVar31 = local_9c[-0x14];
          fVar1 = local_9c[-0x13];
          fVar2 = local_9c[-0x12];
          *local_84 = local_9c[-0x15];
          local_84[1] = fVar31;
          local_84[2] = fVar1;
          local_84[3] = fVar2;
          fVar31 = local_9c[-0x10];
          local_84[4] = local_9c[-0x11];
          local_84[5] = fVar31;
          local_84[6] = local_9c[-0xf];
          local_84 = local_84 + -0x15;
          pfVar26 = pfVar26 + -0x15;
          local_9c = local_9c + -0x15;
          local_94 = local_94 + -0x15;
        }
      }
      iVar20 = local_88;
      local_84 = local_84 + 0x15;
      local_8c = (float)((int)local_8c + 3);
      pfVar22 = pfVar22 + 0x15;
      pfVar23 = pfVar23 + 0x15;
    } while ((int)local_8c < local_88);
    if (0 < local_88) {
      FUN_0045fd00(0x1c2,local_88,0);
      iVar24 = param_1[0x11];
      *(int *)(iVar24 + 0x10) = *(int *)(iVar24 + 0x10) + 1;
      if ((0 < *(int *)(iVar24 + 0x10)) && (*(int **)(iVar24 + 0x14) != (int *)0x0)) {
        piVar16 = (int *)**(int **)(iVar24 + 0x14);
        if (piVar16 == (int *)0x0) {
          pfVar23 = (float *)0x0;
        }
        else {
          local_90 = (float *)0x0;
          (**(code **)(*piVar16 + 0x10))(0x1821,&local_90,0);
          pfVar23 = local_90;
        }
        *(float **)(iVar24 + 0xc) = pfVar23;
        *(undefined4 *)(iVar24 + 0x34) = 0;
      }
      FUN_006d2250(*(undefined4 *)(iVar24 + 0xc),pfVar21,iVar20 * 0x1c);
      iVar20 = param_1[0x11];
      piVar16 = (int *)(iVar20 + 0x10);
      *piVar16 = *piVar16 + -1;
      if ((*piVar16 == 0) && (*(int **)(iVar20 + 0x14) != (int *)0x0)) {
        piVar16 = (int *)**(int **)(iVar20 + 0x14);
        if (piVar16 != (int *)0x0) {
          (**(code **)(*piVar16 + 0x18))();
        }
        *(undefined4 *)(iVar20 + 0xc) = 0;
      }
    }
    thunk_FUN_0060fc30(pfVar21);
    local_8 = CONCAT31(local_8._1_3_,1);
    _eh_vector_destructor_iterator_(&local_80,0xc,9,guard_check_icall);
    FUN_0043fd30();
    if (param_1 != (undefined4 *)0x0) {
      LOCK();
      iVar20 = param_1[1] + -1;
      param_1[1] = iVar20;
      UNLOCK();
      if ((iVar20 == 0) && (param_1 != (undefined4 *)0x0)) {
        (**(code **)*param_1)(1);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

