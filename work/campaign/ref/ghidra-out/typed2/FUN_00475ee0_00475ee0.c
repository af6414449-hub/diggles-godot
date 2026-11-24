
void FUN_00475ee0(float *param_1,float *param_2,float param_3,float param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  CMap *pCVar4;
  char cVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  float *pfVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  float *pfVar13;
  bool bVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  double dVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float in_XMM3_Da;
  float fVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  undefined1 local_1c0 [64];
  undefined1 local_180 [64];
  undefined1 local_140 [64];
  float local_100 [6];
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  float local_d0;
  float local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  float local_84;
  float local_80;
  undefined4 local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 *local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float *local_44;
  undefined4 local_40;
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
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  pCVar4 = PTR_0077241c;
  iVar8 = DAT_0076a338;
  puVar6 = (undefined4 *)(DAT_0076a338 + 0x2758);
  uVar1 = *(undefined4 *)(DAT_0076a338 + 0x275c);
  uVar2 = *(undefined4 *)(DAT_0076a338 + 0x2760);
  local_64 = (undefined4 *)(DAT_0076a338 + 0x2754);
  local_14 = (float)DAT_0076a338;
  *(undefined4 *)(DAT_0076a338 + 0x27d4) = *(undefined4 *)(DAT_0076a338 + 0x2754);
  *(undefined4 *)(iVar8 + 0x27d8) = *puVar6;
  *(undefined4 *)(iVar8 + 0x27dc) = uVar1;
  *(undefined4 *)(iVar8 + 0x27e0) = uVar2;
  *(undefined4 *)(iVar8 + 0x27e4) = *(undefined4 *)(iVar8 + 0x2764);
  *(undefined4 *)(iVar8 + 0x27e8) = *(undefined4 *)(iVar8 + 0x2768);
  *(undefined4 *)(iVar8 + 0x27ec) = *(undefined4 *)(iVar8 + 0x276c);
  *(undefined4 *)(iVar8 + 0x27f0) = *(undefined4 *)(iVar8 + 0x2770);
  *(undefined4 *)(iVar8 + 0x27f4) = *(undefined4 *)(iVar8 + 0x2774);
  *(undefined4 *)(iVar8 + 0x27f8) = *(undefined4 *)(iVar8 + 0x2778);
  *(undefined4 *)(iVar8 + 0x27fc) = *(undefined4 *)(iVar8 + 0x277c);
  *(undefined4 *)(iVar8 + 0x2800) = *(undefined4 *)(iVar8 + 0x2780);
  *(undefined4 *)(iVar8 + 0x2804) = *(undefined4 *)(iVar8 + 0x2784);
  *(undefined4 *)(iVar8 + 0x2808) = *(undefined4 *)(iVar8 + 0x2788);
  *(undefined4 *)(iVar8 + 0x280c) = *(undefined4 *)(iVar8 + 0x278c);
  *(undefined4 *)(iVar8 + 0x2810) = *(undefined4 *)(iVar8 + 0x2790);
  *(float *)(iVar8 + 0x2814) = in_XMM3_Da;
  fVar15 = (float)pCVar4->cellX0;
  fVar20 = *param_1;
  if (*param_1 < fVar15) {
    *param_1 = fVar15;
    fVar20 = fVar15;
  }
  fVar16 = (float)pCVar4->cellY0;
  fVar15 = *param_2;
  if (*param_2 < fVar16) {
    *param_2 = fVar16;
    fVar20 = *param_1;
    fVar15 = fVar16;
  }
  fVar16 = (float)pCVar4->cellX1;
  if (fVar16 < fVar20) {
    *param_1 = fVar16;
    fVar15 = *param_2;
    fVar20 = fVar16;
  }
  fVar16 = (float)pCVar4->cellY1;
  if (fVar16 < fVar15) {
    *param_2 = fVar16;
    fVar20 = *param_1;
    fVar15 = fVar16;
  }
  fVar16 = pCVar4->x0f + 0.0;
  if (fVar20 < fVar16) {
    *param_1 = fVar16;
    fVar15 = *param_2;
    fVar20 = fVar16;
  }
  fVar16 = pCVar4->y0f + 0.0;
  if (fVar15 < fVar16) {
    *param_2 = fVar16;
    fVar20 = *param_1;
    fVar15 = fVar16;
  }
  fVar16 = pCVar4->x1f - 0.0;
  if (fVar16 <= fVar20) {
    *param_1 = fVar16 - 1.0;
    fVar15 = *param_2;
  }
  fVar20 = pCVar4->y1f - 0.0;
  if (fVar20 <= fVar15) {
    *param_2 = fVar20 - 1.0;
  }
  *(int *)(iVar8 + 4) = *(int *)(iVar8 + 4) + 1;
  *(float *)(iVar8 + 0x2844) = *param_1;
  *(float *)(iVar8 + 0x2848) = *param_2;
  *(float *)(iVar8 + 0x284c) = in_XMM3_Da * 16.0 + 4.0;
  FUN_00464e30(&param_1,&param_2);
  local_c = (float)param_1 + *(float *)(iVar8 + 0x2844);
  local_18 = *(float *)(iVar8 + 0x2848) + (float)param_2;
  local_34 = local_c - local_c;
  *(float *)(iVar8 + 0x2848) = local_18;
  param_2 = (float *)(local_18 - local_18);
  local_8 = *(float *)(iVar8 + 0x284c) - 14.0;
  fVar20 = param_3;
  FUN_004089d0();
  local_10 = fVar20;
  FUN_004089f0();
  local_60 = param_3 * local_8 - local_10 * (float)param_2;
  fVar20 = param_4;
  FUN_004089d0();
  fVar15 = param_4;
  param_1 = (float *)fVar20;
  FUN_004089f0();
  fVar20 = (float)param_1 * local_34;
  dVar18 = (double)DAT_00c3c980;
  local_34 = (fVar15 * local_34 - (float)param_1 * local_60) + local_c;
  param_1 = (float *)(fVar20 + fVar15 * local_60 + 14.0);
  param_3 = param_3 * (float)param_2 + local_10 * local_8 + local_18;
  *(float *)(iVar8 + 0x2844) = local_34;
  *(float **)(iVar8 + 0x284c) = param_1;
  *(float *)(iVar8 + 0x2848) = param_3;
  FUN_006f6ad0();
  param_4 = (float)dVar18;
  dVar18 = (double)DAT_00c3c980;
  FUN_006f5ae0();
  param_2 = (float *)-(float)dVar18;
  FUN_0044d010();
  puVar6 = (undefined4 *)
           FUN_0044dc80(local_34,param_3,param_1,local_c,local_18,0x41600000,param_4,param_2,0);
  uVar1 = puVar6[1];
  uVar2 = puVar6[2];
  uVar3 = puVar6[3];
  *(undefined4 *)(iVar8 + 0x26d4) = *puVar6;
  *(undefined4 *)(iVar8 + 0x26d8) = uVar1;
  *(undefined4 *)(iVar8 + 0x26dc) = uVar2;
  *(undefined4 *)(iVar8 + 0x26e0) = uVar3;
  uVar1 = puVar6[5];
  uVar2 = puVar6[6];
  uVar3 = puVar6[7];
  *(undefined4 *)(iVar8 + 0x26e4) = puVar6[4];
  *(undefined4 *)(iVar8 + 0x26e8) = uVar1;
  *(undefined4 *)(iVar8 + 0x26ec) = uVar2;
  *(undefined4 *)(iVar8 + 0x26f0) = uVar3;
  uVar1 = puVar6[9];
  uVar2 = puVar6[10];
  uVar3 = puVar6[0xb];
  *(undefined4 *)(iVar8 + 0x26f4) = puVar6[8];
  *(undefined4 *)(iVar8 + 0x26f8) = uVar1;
  *(undefined4 *)(iVar8 + 0x26fc) = uVar2;
  *(undefined4 *)(iVar8 + 0x2700) = uVar3;
  uVar1 = puVar6[0xd];
  uVar2 = puVar6[0xe];
  uVar3 = puVar6[0xf];
  *(undefined4 *)(iVar8 + 0x2704) = puVar6[0xc];
  *(undefined4 *)(iVar8 + 0x2708) = uVar1;
  *(undefined4 *)(iVar8 + 0x270c) = uVar2;
  *(undefined4 *)(iVar8 + 10000) = uVar3;
  param_3 = (float)*(int *)(iVar8 + 0x2830) / (float)*(int *)(iVar8 + 0x2834);
  FUN_0044d010();
  puVar7 = (undefined4 *)FUN_0044dee0(param_3);
  puVar6 = (undefined4 *)(iVar8 + 0x2714);
  uVar1 = puVar7[1];
  uVar2 = puVar7[2];
  uVar3 = puVar7[3];
  *puVar6 = *puVar7;
  *(undefined4 *)(iVar8 + 0x2718) = uVar1;
  *(undefined4 *)(iVar8 + 0x271c) = uVar2;
  *(undefined4 *)(iVar8 + 0x2720) = uVar3;
  uVar1 = puVar7[5];
  uVar2 = puVar7[6];
  uVar3 = puVar7[7];
  *(undefined4 *)(iVar8 + 0x2724) = puVar7[4];
  *(undefined4 *)(iVar8 + 0x2728) = uVar1;
  *(undefined4 *)(iVar8 + 0x272c) = uVar2;
  *(undefined4 *)(iVar8 + 0x2730) = uVar3;
  uVar1 = puVar7[9];
  uVar2 = puVar7[10];
  uVar3 = puVar7[0xb];
  *(undefined4 *)(iVar8 + 0x2734) = puVar7[8];
  *(undefined4 *)(iVar8 + 0x2738) = uVar1;
  *(undefined4 *)(iVar8 + 0x273c) = uVar2;
  *(undefined4 *)(iVar8 + 0x2740) = uVar3;
  uVar1 = puVar7[0xd];
  uVar2 = puVar7[0xe];
  uVar3 = puVar7[0xf];
  *(undefined4 *)(iVar8 + 0x2744) = puVar7[0xc];
  *(undefined4 *)(iVar8 + 0x2748) = uVar1;
  *(undefined4 *)(iVar8 + 0x274c) = uVar2;
  *(undefined4 *)(iVar8 + 0x2750) = uVar3;
  FUN_0047ecf0();
  local_100[1] = 0.0;
  local_100[2] = 0.0;
  local_100[3] = 0.0;
  local_100[4] = 0.0;
  local_d8 = 0x3f800000;
  local_d4 = 0;
  local_cc = (float)*(int *)((int)local_14 + 0x2834) * 0.5;
  local_100[5] = -(float)*(int *)((int)local_14 + 0x2834) * 0.5;
  local_100[0] = (float)*(int *)((int)local_14 + 0x2830) * 0.5;
  local_e8 = 0;
  uStack_e4 = 0;
  uStack_e0 = 0;
  uStack_dc = 0;
  pfVar9 = local_100;
  local_c8 = 0;
  puVar24 = local_1c0;
  local_c4 = 0x3f800000;
  puVar23 = local_140;
  puVar7 = puVar6;
  local_d0 = local_100[0];
  FUN_004156b0(local_180,(int)local_14 + 0x26d4);
  FUN_004156b0(puVar23,puVar7);
  puVar7 = (undefined4 *)FUN_004156b0(puVar24,pfVar9);
  uVar1 = puVar7[1];
  uVar2 = puVar7[2];
  uVar3 = puVar7[3];
  *local_64 = *puVar7;
  local_64[1] = uVar1;
  local_64[2] = uVar2;
  local_64[3] = uVar3;
  uVar1 = puVar7[5];
  uVar2 = puVar7[6];
  uVar3 = puVar7[7];
  local_64[4] = puVar7[4];
  local_64[5] = uVar1;
  local_64[6] = uVar2;
  local_64[7] = uVar3;
  uVar1 = puVar7[9];
  uVar2 = puVar7[10];
  uVar3 = puVar7[0xb];
  local_64[8] = puVar7[8];
  local_64[9] = uVar1;
  local_64[10] = uVar2;
  local_64[0xb] = uVar3;
  uVar1 = puVar7[0xd];
  uVar2 = puVar7[0xe];
  uVar3 = puVar7[0xf];
  local_64[0xc] = puVar7[0xc];
  local_64[0xd] = uVar1;
  local_64[0xe] = uVar2;
  local_64[0xf] = uVar3;
  FUN_0047e3f0((int)local_14 + 0x2794);
  fVar20 = local_14;
  puVar24 = local_180;
  FUN_004156b0(local_140,(int)local_14 + 0x26d4);
  puVar6 = (undefined4 *)FUN_004156b0(puVar24,puVar6);
  FUN_0044d010();
  iVar8 = FUN_00450400();
  uVar1 = puVar6[1];
  uVar2 = puVar6[2];
  uVar3 = puVar6[3];
  *(undefined4 *)(iVar8 + 0x800c) = *puVar6;
  *(undefined4 *)(iVar8 + 0x8010) = uVar1;
  *(undefined4 *)(iVar8 + 0x8014) = uVar2;
  *(undefined4 *)(iVar8 + 0x8018) = uVar3;
  uVar1 = puVar6[5];
  uVar2 = puVar6[6];
  uVar3 = puVar6[7];
  *(undefined4 *)(iVar8 + 0x801c) = puVar6[4];
  *(undefined4 *)(iVar8 + 0x8020) = uVar1;
  *(undefined4 *)(iVar8 + 0x8024) = uVar2;
  *(undefined4 *)(iVar8 + 0x8028) = uVar3;
  uVar1 = puVar6[9];
  uVar2 = puVar6[10];
  uVar3 = puVar6[0xb];
  *(undefined4 *)(iVar8 + 0x802c) = puVar6[8];
  *(undefined4 *)(iVar8 + 0x8030) = uVar1;
  *(undefined4 *)(iVar8 + 0x8034) = uVar2;
  *(undefined4 *)(iVar8 + 0x8038) = uVar3;
  uVar1 = puVar6[0xd];
  uVar2 = puVar6[0xe];
  uVar3 = puVar6[0xf];
  *(undefined4 *)(iVar8 + 0x803c) = puVar6[0xc];
  *(undefined4 *)(iVar8 + 0x8040) = uVar1;
  *(undefined4 *)(iVar8 + 0x8044) = uVar2;
  *(undefined4 *)(iVar8 + 0x8048) = uVar3;
  iVar8 = DAT_00772400;
  fVar15 = 1.0;
  if (*(char *)(DAT_00772400 + 0x8c) == '\0') {
    fVar15 = 0.0;
  }
  fVar16 = *(float *)((int)fVar20 + 0x19f28);
  if (fVar16 < fVar15) {
    fVar17 = fVar16 + 0.125;
    fVar16 = 1.0;
    if (fVar17 <= 1.0) {
      fVar16 = fVar17;
    }
    *(float *)((int)fVar20 + 0x19f28) = fVar16;
  }
  if (fVar15 < fVar16) {
    fVar15 = fVar16 - 0.125;
    fVar16 = 0.0;
    if (0.0 <= fVar15) {
      fVar16 = fVar15;
    }
    *(float *)((int)fVar20 + 0x19f28) = fVar16;
  }
  DAT_0076a328 = 1;
  if (*(char *)(iVar8 + 0x8f) == '\0') {
    *(undefined4 *)((int)fVar20 + 0x19f2c) = 0;
  }
  else {
    *(float *)((int)fVar20 + 0x19f2c) =
         (((float)*(int *)((int)fVar20 + 0x2834) * 76.0) / 600.0) * fVar16;
    if (fVar16 == 1.0) {
      DAT_0076a328 = 0;
    }
  }
  uVar12 = 8;
  param_4 = 0.0;
  pfVar9 = (float *)((int)fVar20 + 0x19ec8);
  param_3 = 0.0;
  local_10 = 1.12104e-44;
  do {
    if (uVar12 - 8 < 0x10) {
      pfVar13 = (float *)((int)param_3 + (int)pfVar9);
      param_1 = (float *)((int)param_4 + (int)fVar20 + 0x19cc8);
      fVar15 = local_14;
      param_2 = pfVar13;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      param_1 = (float *)((int)fVar20 + 0x19cc8);
      pfVar13 = (float *)((int)fVar20 + 0x19ec8);
      pfVar9 = pfVar13;
      fVar15 = fVar20;
    }
    *(float *)((int)param_1 + 4) = *(float *)((int)fVar15 + 0x19f2c) + *pfVar13;
    if (uVar12 < 0x10) {
      param_2 = (float *)((int)param_4 + (int)fVar20 + 0x19dc8);
      fVar15 = local_14;
      param_1 = (float *)((int)param_3 + 0x20 + (int)pfVar9);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      param_2 = (float *)((int)fVar15 + 0x19cc8);
      pfVar9 = (float *)((int)fVar15 + 0x19ec8);
      param_1 = pfVar9;
    }
    fVar20 = local_14;
    param_3 = (float)((int)param_3 + 4);
    param_4 = (float)((int)param_4 + 0x20);
    uVar12 = uVar12 + 1;
    local_10 = (float)((int)local_10 + -1);
    param_2[1] = *param_1 - *(float *)((int)fVar15 + 0x19f2c);
    pCVar4 = PTR_0077241c;
  } while (local_10 != 0.0);
  local_44 = (float *)0x0;
  local_48 = 0.0;
  local_8c = 0;
  local_90 = 0;
  local_98 = 0;
  local_9c = 0;
  local_a4 = 0;
  local_a8 = 0;
  local_b0 = 0;
  local_b4 = 0;
  local_bc = 0;
  local_c0 = 0;
  local_80 = 0.0;
  local_84 = 0.0;
  local_6c = 0.0;
  local_70 = 0.0;
  local_3c = 0.0;
  local_58 = 0.0;
  local_54 = 0.0;
  local_34 = 0.0;
  if ((char)PTR_0077241c->mapFlags == '\0') {
    local_24 = 0.0;
    local_10 = 0.0;
    local_14 = 0.0;
    local_78 = 0.0;
    local_74 = 0.0;
    local_60 = 0.0;
    local_64 = (undefined4 *)0x0;
    local_4c = 0.0;
    local_8 = 0.0;
    param_2 = (float *)0x0;
    param_4 = 0.0;
    param_3 = 0.0;
    local_20 = 0.0;
    local_50 = 0.0;
    local_30 = 0.0;
    local_5c = 0.0;
  }
  else {
    param_3 = *(float *)((int)local_14 + 0x19f2c) + 0.0;
    local_48 = 0.0;
    local_40 = 0x40e00000;
    local_44 = (float *)param_3;
    pfVar9 = (float *)FUN_00479150(&local_84,&local_48);
    local_40 = 0x40e00000;
    local_3c = *pfVar9;
    local_24 = pfVar9[1];
    local_48 = (float)*(int *)((int)fVar20 + 0x2830);
    local_44 = (float *)param_3;
    local_10 = local_3c;
    pfVar9 = (float *)FUN_00479150(&local_84,&local_48);
    local_48 = 0.0;
    local_40 = 0x40e00000;
    local_34 = *pfVar9;
    local_14 = pfVar9[1];
    param_1 = (float *)((float)*(int *)((int)fVar20 + 0x2834) - *(float *)((int)fVar20 + 0x19f2c));
    local_44 = param_1;
    local_20 = local_34;
    pfVar9 = (float *)FUN_00479150(&local_84,&local_48);
    local_40 = 0x40e00000;
    local_74 = *pfVar9;
    local_78 = pfVar9[1];
    local_48 = (float)*(int *)((int)fVar20 + 0x2830);
    local_44 = param_1;
    pfVar9 = (float *)FUN_00479150(&local_84,&local_48);
    local_48 = 0.0;
    local_40 = 0x41680000;
    local_64 = (undefined4 *)*pfVar9;
    local_60 = pfVar9[1];
    local_44 = (float *)param_3;
    pfVar9 = (float *)FUN_00479150(&local_84,&local_48);
    local_58 = *pfVar9;
    local_4c = pfVar9[1];
    local_48 = (float)*(int *)((int)fVar20 + 0x2830);
    local_44 = (float *)param_3;
    local_40 = 0x41680000;
    local_8 = local_58;
    pfVar9 = (float *)FUN_00479150(&local_84,&local_48);
    local_48 = 0.0;
    local_40 = 0x41680000;
    local_54 = *pfVar9;
    param_2 = (float *)pfVar9[1];
    local_44 = param_1;
    local_30 = local_54;
    pfVar9 = (float *)FUN_00479150(&local_84,&local_48);
    local_40 = 0x41680000;
    param_3 = *pfVar9;
    param_4 = pfVar9[1];
    local_48 = (float)*(int *)((int)fVar20 + 0x2830);
    local_44 = param_1;
    pfVar9 = (float *)FUN_00479150(&local_84,&local_48);
    fVar15 = pCVar4->x0f + 3.0;
    local_70 = *pfVar9;
    local_6c = pfVar9[1];
    local_68 = pfVar9[2];
    local_5c = local_70;
    local_50 = local_6c;
    if (((((local_58 < fVar15) || (fVar16 = pCVar4->x1f - 3.0, fVar16 <= local_58)) ||
         (fVar17 = pCVar4->y0f + 3.0, local_4c < fVar17)) ||
        ((fVar22 = pCVar4->y1f - 3.0, fVar22 <= local_4c || (local_54 < fVar15)))) ||
       (((fVar16 <= local_54 || (((float)param_2 < fVar17 || (fVar22 <= (float)param_2)))) ||
        ((param_3 < fVar15 ||
         ((((fVar16 <= param_3 || (param_4 < fVar17)) || (fVar22 <= param_4)) ||
          (cVar5 = FUN_00407eb0(&local_70), cVar5 != '\0')))))))) {
      *(undefined1 *)((int)fVar20 + 0x19f08) = 1;
    }
    else {
      *(undefined1 *)((int)fVar20 + 0x19f08) = 0;
    }
  }
  local_7c = 0x412c0000;
  local_84 = (float)*(int *)((int)fVar20 + 0x2830) * 0.5;
  local_80 = (float)*(int *)((int)fVar20 + 0x2834) * 0.5;
  FUN_00479150(&local_70,&local_84);
  local_2c = local_70 - local_3c;
  param_1 = (float *)(local_6c + 100.0);
  fVar16 = local_14 - local_24;
  local_20 = local_20 - local_10;
  local_38 = (float)param_1 - local_24;
  fVar15 = fVar16 * fVar16 + local_20 * local_20 + 0.0;
  local_10 = fVar16;
  FUN_0040b7e0();
  fVar16 = (local_10 / fVar15) * local_38 + (local_20 / fVar15) * local_2c + (0.0 / fVar15) * 0.0;
  local_2c = local_2c - fVar16 * (local_20 / fVar15);
  local_30 = local_30 - local_8;
  local_38 = local_38 - fVar16 * (local_10 / fVar15);
  local_10 = (float)param_2 - local_4c;
  local_c = 0.0 - fVar16 * (0.0 / fVar15);
  local_20 = local_70 - local_58;
  param_1 = (float *)((float)param_1 - local_4c);
  fVar15 = local_30 * local_30 + local_10 * local_10 + 0.0;
  FUN_0040b7e0();
  fVar16 = local_20 * (local_30 / fVar15) + (local_10 / fVar15) * (float)param_1 +
           (0.0 / fVar15) * 0.0;
  local_20 = local_20 - fVar16 * (local_30 / fVar15);
  param_1 = (float *)((float)param_1 - fVar16 * (local_10 / fVar15));
  local_10 = 0.0 - fVar16 * (0.0 / fVar15);
  fVar15 = local_c * local_c + local_38 * local_38 + local_2c * local_2c;
  FUN_0040b7e0();
  fVar16 = local_10 * local_10 + (float)param_1 * (float)param_1 + local_20 * local_20;
  local_8 = fVar15;
  FUN_0040b7e0();
  if (fVar16 <= local_8) {
    local_20 = local_24;
    local_30 = local_14;
    local_38 = local_3c;
    local_2c = local_34;
  }
  else {
    local_20 = local_4c;
    local_30 = (float)param_2;
    local_38 = local_58;
    local_2c = local_54;
  }
  param_1 = (float *)(local_70 - 100.0);
  local_10 = (float)local_64 - local_34;
  local_8 = local_60 - local_14;
  local_c = (float)param_1 - local_34;
  local_18 = local_6c - local_14;
  fVar15 = local_10 * local_10 + local_8 * local_8 + 0.0;
  FUN_0040b7e0();
  fVar16 = (local_8 / fVar15) * local_18 + (local_10 / fVar15) * local_c + (0.0 / fVar15) * 0.0;
  local_c = local_c - fVar16 * (local_10 / fVar15);
  local_18 = local_18 - fVar16 * (local_8 / fVar15);
  local_28 = local_50 - (float)param_2;
  local_1c = 0.0 - fVar16 * (0.0 / fVar15);
  local_10 = local_5c - local_54;
  param_1 = (float *)((float)param_1 - local_54);
  local_8 = local_6c - (float)param_2;
  fVar15 = local_10 * local_10 + local_28 * local_28 + 0.0;
  FUN_0040b7e0();
  fVar16 = local_8 * (local_28 / fVar15) + (float)param_1 * (local_10 / fVar15) +
           (0.0 / fVar15) * 0.0;
  param_1 = (float *)((float)param_1 - fVar16 * (local_10 / fVar15));
  local_8 = local_8 - fVar16 * (local_28 / fVar15);
  local_28 = 0.0 - fVar16 * (0.0 / fVar15);
  fVar15 = local_1c * local_1c + local_18 * local_18 + local_c * local_c;
  FUN_0040b7e0();
  fVar16 = local_28 * local_28 + local_8 * local_8 + (float)param_1 * (float)param_1;
  local_1c = fVar15;
  FUN_0040b7e0();
  if (fVar16 <= local_1c) {
    param_2 = (float *)local_14;
    local_10 = (float)local_64;
    local_14 = local_60;
    local_54 = local_34;
  }
  else {
    local_10 = local_5c;
    local_14 = local_50;
  }
  param_1 = (float *)(local_70 + 100.0);
  local_1c = local_74 - local_3c;
  local_28 = local_78 - local_24;
  local_c = (float)param_1 - local_3c;
  local_8 = local_6c - local_24;
  fVar15 = local_1c * local_1c + local_28 * local_28 + 0.0;
  FUN_0040b7e0();
  fVar16 = local_c * (local_1c / fVar15) + local_8 * (local_28 / fVar15) + (0.0 / fVar15) * 0.0;
  local_c = local_c - fVar16 * (local_1c / fVar15);
  local_8 = local_8 - fVar16 * (local_28 / fVar15);
  local_28 = param_4 - local_4c;
  local_34 = 0.0 - fVar16 * (0.0 / fVar15);
  local_1c = param_3 - local_58;
  param_1 = (float *)((float)param_1 - local_58);
  local_18 = local_6c - local_4c;
  fVar15 = local_1c * local_1c + local_28 * local_28 + 0.0;
  FUN_0040b7e0();
  fVar16 = local_18 * (local_28 / fVar15) + (float)param_1 * (local_1c / fVar15) +
           (0.0 / fVar15) * 0.0;
  param_1 = (float *)((float)param_1 - fVar16 * (local_1c / fVar15));
  local_18 = local_18 - fVar16 * (local_28 / fVar15);
  local_1c = 0.0 - fVar16 * (0.0 / fVar15);
  fVar15 = local_34 * local_34 + local_8 * local_8 + local_c * local_c;
  FUN_0040b7e0();
  fVar16 = local_1c * local_1c + local_18 * local_18 + (float)param_1 * (float)param_1;
  local_28 = fVar15;
  FUN_0040b7e0();
  if (fVar16 <= local_28) {
    local_4c = local_24;
    local_24 = local_74;
    param_1 = (float *)local_78;
    local_58 = local_3c;
  }
  else {
    local_24 = param_3;
    param_1 = (float *)param_4;
  }
  local_3c = local_6c - 100.0;
  local_c = local_70 - local_74;
  local_28 = local_60 - local_78;
  local_1c = (float)local_64 - local_74;
  local_8 = local_3c - local_78;
  fVar15 = local_28 * local_28 + local_1c * local_1c + 0.0;
  FUN_0040b7e0();
  fVar16 = local_c * (local_1c / fVar15) + (local_28 / fVar15) * local_8 + (0.0 / fVar15) * 0.0;
  local_3c = local_3c - param_4;
  local_c = local_c - fVar16 * (local_1c / fVar15);
  local_8 = local_8 - fVar16 * (local_28 / fVar15);
  local_1c = local_5c - param_3;
  local_34 = 0.0 - fVar16 * (0.0 / fVar15);
  local_28 = local_50 - param_4;
  local_18 = local_70 - param_3;
  fVar15 = local_28 * local_28 + local_1c * local_1c + 0.0;
  FUN_0040b7e0();
  fVar16 = local_18 * (local_1c / fVar15) + (local_28 / fVar15) * local_3c + (0.0 / fVar15) * 0.0;
  local_18 = local_18 - fVar16 * (local_1c / fVar15);
  local_3c = local_3c - fVar16 * (local_28 / fVar15);
  local_1c = 0.0 - fVar16 * (0.0 / fVar15);
  fVar15 = local_34 * local_34 + local_8 * local_8 + local_c * local_c;
  FUN_0040b7e0();
  fVar16 = local_1c * local_1c + local_3c * local_3c + local_18 * local_18;
  local_28 = fVar15;
  FUN_0040b7e0();
  fVar15 = (float)param_2;
  if (fVar16 <= local_28) {
    local_5c = (float)local_64;
    param_3 = local_74;
    param_4 = local_78;
    local_50 = local_60;
  }
  if (((local_58 == local_38) && (local_4c == local_20)) ||
     ((local_58 == local_2c && (local_4c == local_30)))) {
    fVar22 = 0.0;
    fVar16 = local_4c;
    fVar17 = local_58;
  }
  else if (((local_24 == local_38) && ((float)param_1 == local_20)) ||
          ((local_24 == local_2c && ((float)param_1 == local_30)))) {
    fVar22 = 0.0;
    fVar16 = (float)param_1;
    fVar17 = local_24;
  }
  else {
    local_8 = local_24 - local_58;
    fVar16 = local_30 - local_20;
    local_c = (float)param_1 - local_4c;
    local_18 = local_2c - local_38;
    if (fVar16 == 0.0) {
      fVar22 = (((local_58 - local_38) / local_18) * fVar16 + local_20) - local_4c;
      fVar16 = local_c - (fVar16 * local_8) / local_18;
    }
    else {
      fVar22 = (((local_4c - local_20) / fVar16) * local_18 + local_38) - local_58;
      fVar16 = local_8 - (local_18 * local_c) / fVar16;
    }
    fVar22 = fVar22 / fVar16;
    fVar16 = fVar22 * local_c + local_4c;
    fVar17 = fVar22 * local_8 + local_58;
    fVar22 = fVar22 * 0.0 + 0.0;
  }
  fVar21 = 0.0;
  *(float *)((int)fVar20 + 0x19c40) = fVar22;
  *(float *)((int)fVar20 + 0x19c3c) = fVar16;
  *(float *)((int)fVar20 + 0x19c38) = fVar17;
  if (((local_54 == local_38) && ((float)param_2 == local_20)) ||
     ((local_54 == local_2c && ((float)param_2 == local_30)))) {
    fVar22 = 0.0;
    fVar16 = (float)param_2;
    fVar17 = local_54;
  }
  else if (((local_10 == local_38) && (local_14 == local_20)) ||
          ((local_10 == local_2c && (local_14 == local_30)))) {
    fVar22 = 0.0;
    fVar16 = local_14;
    fVar17 = local_10;
  }
  else {
    local_8 = local_10 - local_54;
    local_c = local_14 - (float)param_2;
    local_2c = local_2c - local_38;
    local_30 = local_30 - local_20;
    if (local_30 == 0.0) {
      fVar17 = (local_8 * local_30) / local_2c;
      fVar22 = (((local_54 - local_38) / local_2c) * local_30 + local_20) - (float)param_2;
      fVar16 = local_c;
    }
    else {
      fVar17 = (local_c * local_2c) / local_30;
      fVar22 = ((((float)param_2 - local_20) / local_30) * local_2c + local_38) - local_54;
      fVar16 = local_8;
    }
    fVar22 = fVar22 / (fVar16 - fVar17);
    fVar17 = local_8 * fVar22 + local_54;
    fVar16 = local_c * fVar22 + (float)param_2;
    fVar22 = fVar22 * 0.0 + 0.0;
  }
  *(float *)((int)fVar20 + 0x19c54) = fVar16;
  *(float *)((int)fVar20 + 0x19c50) = fVar17;
  *(float *)((int)fVar20 + 0x19c58) = fVar22;
  if (((local_58 == param_3) && (local_4c == param_4)) ||
     ((local_58 == local_5c && (local_4c == local_50)))) {
    fVar22 = 0.0;
    fVar16 = local_4c;
    fVar17 = local_58;
  }
  else if (((local_24 == param_3) && ((float)param_1 == param_4)) ||
          ((local_24 == local_5c && ((float)param_1 == local_50)))) {
    fVar22 = 0.0;
    fVar16 = (float)param_1;
    fVar17 = local_24;
  }
  else {
    local_8 = local_5c - param_3;
    local_24 = local_24 - local_58;
    param_1 = (float *)((float)param_1 - local_4c);
    param_2 = (float *)(local_50 - param_4);
    if ((float)param_2 == 0.0) {
      fVar16 = ((local_58 - param_3) / local_8) * (float)param_2;
      param_2 = (float *)(((float)param_2 * local_24) / local_8);
      fVar17 = (fVar16 + param_4) - local_4c;
      fVar16 = (float)param_1 - (float)param_2;
    }
    else {
      fVar17 = (((local_4c - param_4) / (float)param_2) * local_8 + param_3) - local_58;
      fVar16 = local_24 - (local_8 * (float)param_1) / (float)param_2;
    }
    fVar17 = fVar17 / fVar16;
    fVar22 = fVar17 * 0.0 + 0.0;
    fVar16 = local_4c + fVar17 * (float)param_1;
    fVar17 = local_58 + fVar17 * local_24;
  }
  *(float *)((int)fVar20 + 0x19c4c) = fVar22;
  *(float *)((int)fVar20 + 0x19c44) = fVar17;
  *(float *)((int)fVar20 + 0x19c48) = fVar16;
  fVar16 = fVar15;
  fVar17 = local_54;
  if (((((local_54 != param_3) || (fVar15 != param_4)) &&
       ((local_54 != local_5c || (fVar15 != local_50)))) &&
      ((fVar16 = local_14, fVar17 = local_10, local_10 != param_3 || (local_14 != param_4)))) &&
     ((local_10 != local_5c || (local_14 != local_50)))) {
    fVar17 = local_5c - param_3;
    fVar16 = local_50 - param_4;
    local_14 = local_14 - fVar15;
    fVar22 = local_10 - local_54;
    if (fVar16 == 0.0) {
      fVar19 = (((local_54 - param_3) / fVar17) * fVar16 + param_4) - fVar15;
      fVar16 = local_14 - (fVar16 * fVar22) / fVar17;
    }
    else {
      fVar19 = (((fVar15 - param_4) / fVar16) * fVar17 + param_3) - local_54;
      fVar16 = fVar22 - (fVar17 * local_14) / fVar16;
    }
    fVar19 = fVar19 / fVar16;
    fVar17 = local_54 + fVar22 * fVar19;
    fVar21 = fVar19 * 0.0 + 0.0;
    fVar16 = fVar15 + local_14 * fVar19;
  }
  *(float *)((int)fVar20 + 0x19c5c) = fVar17;
  *(float *)((int)fVar20 + 0x19c60) = fVar16;
  *(float *)((int)fVar20 + 0x19c64) = fVar21;
  FUN_004756a0();
  if (DAT_0076839d != '\0') {
    uVar12 = 0x3c;
    piVar10 = (int *)((int)fVar20 + 0x2754);
    piVar11 = (int *)((int)fVar20 + 0x27d4);
    do {
      if (*piVar11 != *piVar10) {
        *(undefined1 *)((int)fVar20 + 0x19f18) = 1;
        return;
      }
      piVar11 = piVar11 + 1;
      piVar10 = piVar10 + 1;
      bVar14 = 3 < uVar12;
      uVar12 = uVar12 - 4;
    } while (bVar14);
  }
  *(undefined1 *)((int)fVar20 + 0x19f18) = 0;
  return;
}

