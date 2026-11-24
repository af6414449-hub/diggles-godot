
void FUN_0052d170(float param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6)

{
  char cVar1;
  SHORT SVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined1 local_17c [12];
  undefined1 local_170 [12];
  undefined1 local_164 [12];
  undefined1 local_158 [12];
  undefined1 local_14c [12];
  undefined1 local_140 [4];
  undefined4 local_13c;
  undefined1 local_134 [4];
  undefined4 local_130;
  float local_128;
  float local_124;
  undefined4 local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float *local_c4;
  float *local_c0;
  float *local_bc;
  float *local_b8;
  int local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  int local_a4;
  int local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  int local_70;
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
  undefined4 local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  int *local_14;
  float local_10;
  float local_c;
  float local_8;
  
  SVar2 = GetAsyncKeyState(0x10);
  if (-1 < SVar2) {
    FUN_0040b980(0);
  }
  fVar14 = param_2 * *(float *)(DAT_0076a338 + 0x2770) + *(float *)(DAT_0076a338 + 0x2760) * param_1
           + param_3 * *(float *)(DAT_0076a338 + 0x2780) + *(float *)(DAT_0076a338 + 0x2790);
  iVar7 = (int)((param_2 * *(float *)(DAT_0076a338 + 0x2764) +
                 *(float *)(DAT_0076a338 + 0x2754) * param_1 +
                 param_3 * *(float *)(DAT_0076a338 + 0x2774) + *(float *)(DAT_0076a338 + 0x2784)) /
               fVar14);
  iVar9 = (int)((param_2 * *(float *)(DAT_0076a338 + 0x2768) +
                 *(float *)(DAT_0076a338 + 0x2758) * param_1 +
                 param_3 * *(float *)(DAT_0076a338 + 0x2778) + *(float *)(DAT_0076a338 + 0x2788)) /
               fVar14);
  fVar14 = param_5 * *(float *)(DAT_0076a338 + 0x2770) + *(float *)(DAT_0076a338 + 0x2760) * param_4
           + param_6 * *(float *)(DAT_0076a338 + 0x2780) + *(float *)(DAT_0076a338 + 0x2790);
  iVar8 = (int)((param_5 * *(float *)(DAT_0076a338 + 0x2764) +
                 *(float *)(DAT_0076a338 + 0x2754) * param_4 +
                 param_6 * *(float *)(DAT_0076a338 + 0x2774) + *(float *)(DAT_0076a338 + 0x2784)) /
               fVar14);
  local_70 = (int)((param_5 * *(float *)(DAT_0076a338 + 0x2768) +
                    *(float *)(DAT_0076a338 + 0x2758) * param_4 +
                    param_6 * *(float *)(DAT_0076a338 + 0x2778) + *(float *)(DAT_0076a338 + 0x2788))
                  / fVar14);
  local_a0 = iVar7;
  if (iVar8 < iVar7) {
    local_a0 = iVar8;
    iVar8 = iVar7;
  }
  iVar7 = iVar9;
  if (local_70 < iVar9) {
    iVar7 = local_70;
    local_70 = iVar9;
  }
  local_124 = 0.0;
  local_2c = 0.0;
  local_130 = 0;
  local_13c = 0;
  local_94 = 0.0;
  local_80 = 0.0;
  local_d0 = 0.0;
  local_e0 = 0.0;
  local_1c = 0.0;
  local_98 = 0.0;
  local_ac = 0.0;
  local_74 = 0.0;
  local_8c = 0.0;
  local_84 = 0.0;
  local_d8 = 0.0;
  local_88 = 0.0;
  local_a8 = 0.0;
  local_90 = 0.0;
  local_b0 = 0.0;
  local_7c = 0.0;
  local_4c = 0.0;
  local_50 = 0.0;
  local_54 = 0.0;
  local_3c = 0.0;
  local_ec = 0.0;
  local_c8 = 0.0;
  local_d4 = 0.0;
  local_cc = 0.0;
  local_68 = 0.0;
  local_11c = 0.0;
  local_48 = 0.0;
  local_24 = 0.0;
  local_f8 = 0.0;
  local_f4 = 0.0;
  local_fc = 0.0;
  local_38 = 0.0;
  local_60 = 0.0;
  local_100 = 0.0;
  local_6c = 0.0;
  local_104 = 0.0;
  local_f0 = 0.0;
  local_110 = 0.0;
  local_44 = 0.0;
  local_40 = 0.0;
  local_114 = 0.0;
  local_e8 = 0.0;
  local_118 = 0.0;
  local_10 = 0.0;
  local_b8 = (float *)0x0;
  local_e4 = 0.0;
  local_bc = (float *)0x0;
  local_9c = 0.0;
  local_c = 0.0;
  local_c0 = (float *)0x0;
  local_dc = 0.0;
  local_c4 = (float *)0x0;
  local_b4 = iVar7;
  local_a4 = iVar8;
  if ((char)PTR_0077241c->mapFlags == '\0') {
    local_108 = 0.0;
    local_10c = 0.0;
    local_58 = 0.0;
  }
  else {
    local_30 = (float)local_a0;
    local_28 = 0x40e00000;
    local_2c = (float)iVar7;
    pfVar3 = (float *)FUN_00479150(local_140,&local_30);
    local_28 = 0x40e00000;
    local_80 = *pfVar3;
    local_c8 = pfVar3[1];
    local_30 = (float)iVar8;
    local_2c = (float)iVar7;
    local_84 = local_c8;
    pfVar4 = (float *)FUN_00479150(local_134,&local_30);
    local_28 = 0x40e00000;
    local_94 = *pfVar4;
    local_cc = pfVar4[1];
    local_30 = (float)local_a0;
    local_2c = (float)local_70;
    local_98 = local_cc;
    pfVar5 = (float *)FUN_00479150(&local_128,&local_30);
    local_28 = 0x40e00000;
    local_8c = *pfVar5;
    local_108 = pfVar5[1];
    local_30 = (float)local_a4;
    local_2c = (float)local_70;
    local_90 = local_108;
    local_c = local_108;
    local_bc = (float *)FUN_00479150(local_14c,&local_30);
    local_1c = *local_bc;
    local_10c = local_bc[1];
    local_30 = (float)local_a0;
    local_2c = (float)local_b4;
    local_28 = 0x41680000;
    local_a8 = local_10c;
    local_60 = local_10c;
    local_c4 = (float *)FUN_00479150(local_158,&local_30);
    local_28 = 0x41680000;
    local_e0 = *local_c4;
    local_88 = local_c4[1];
    local_30 = (float)local_a4;
    local_2c = (float)local_b4;
    local_50 = local_88;
    local_c0 = (float *)FUN_00479150(local_164,&local_30);
    local_28 = 0x41680000;
    local_d0 = *local_c0;
    local_74 = local_c0[1];
    local_30 = (float)local_a0;
    local_2c = (float)local_70;
    local_3c = local_74;
    local_b8 = (float *)FUN_00479150(local_170,&local_30);
    local_28 = 0x41680000;
    local_d8 = *local_b8;
    local_7c = local_b8[1];
    local_30 = (float)local_a4;
    local_2c = (float)local_70;
    local_58 = local_7c;
    local_40 = local_7c;
    pfVar6 = (float *)FUN_00479150(local_17c,&local_30);
    local_24 = pfVar6[1];
    local_48 = *pfVar6;
    local_4c = *local_c4;
    local_54 = *local_c0;
    local_ec = *pfVar3;
    local_d4 = *pfVar4;
    local_38 = *local_bc;
    local_44 = *local_b8;
    local_10 = local_c8;
    local_9c = *pfVar5;
  }
  local_120 = 0x412c0000;
  local_128 = (float)(local_a4 + local_a0) * 0.5;
  local_124 = (float)(local_70 + local_b4) * 0.5;
  local_11c = local_3c;
  local_118 = local_40;
  local_114 = local_40;
  local_110 = local_50;
  local_104 = local_50;
  local_100 = local_60;
  local_fc = local_cc;
  local_f8 = local_24;
  local_f4 = local_cc;
  local_f0 = local_50;
  local_e8 = local_40;
  local_e4 = local_10;
  local_dc = local_c;
  local_c8 = local_10;
  local_c4 = (float *)local_c;
  local_c0 = (float *)local_c;
  local_bc = (float *)local_10;
  local_b8 = (float *)local_10;
  local_b0 = local_24;
  local_ac = local_48;
  local_6c = local_50;
  local_68 = local_3c;
  local_5c = local_24;
  FUN_00479150(&local_30,&local_128);
  local_34 = local_30 - local_80;
  local_8 = local_2c + 100.0;
  local_78 = local_98 - local_84;
  local_18 = local_94 - local_80;
  local_64 = local_8 - local_84;
  fVar14 = local_78 * local_78 + local_18 * local_18 + 0.0;
  FUN_0040b7e0();
  fVar12 = local_34 * (local_18 / fVar14) + (local_78 / fVar14) * local_64 + (0.0 / fVar14) * 0.0;
  local_34 = local_34 - fVar12 * (local_18 / fVar14);
  local_64 = local_64 - fVar12 * (local_78 / fVar14);
  local_78 = local_d0 - local_e0;
  local_14 = (int *)(0.0 - fVar12 * (0.0 / fVar14));
  local_18 = local_30 - local_e0;
  local_20 = local_74 - local_88;
  local_8 = local_8 - local_88;
  fVar14 = local_78 * local_78 + local_20 * local_20 + 0.0;
  FUN_0040b7e0();
  fVar12 = local_18 * (local_78 / fVar14) + (local_20 / fVar14) * local_8 + (0.0 / fVar14) * 0.0;
  local_18 = local_18 - fVar12 * (local_78 / fVar14);
  local_8 = local_8 - fVar12 * (local_20 / fVar14);
  local_20 = 0.0 - fVar12 * (0.0 / fVar14);
  fVar14 = (float)local_14 * (float)local_14 + local_64 * local_64 + local_34 * local_34;
  FUN_0040b7e0();
  fVar12 = local_20 * local_20 + local_8 * local_8 + local_18 * local_18;
  local_14 = (int *)fVar14;
  FUN_0040b7e0();
  if (fVar12 <= (float)local_14) {
    local_34 = local_ec;
    local_50 = local_c8;
    local_64 = local_d4;
    local_3c = local_cc;
    local_24 = local_f8;
    local_f4 = local_fc;
    local_60 = local_100;
    local_f0 = local_110;
    local_40 = local_114;
    local_e8 = local_118;
    local_10 = (float)local_b8;
    local_e4 = (float)local_bc;
    local_68 = local_11c;
    local_c = (float)local_c0;
    local_6c = local_104;
    local_dc = (float)local_c4;
  }
  else {
    local_34 = local_4c;
    local_64 = local_54;
  }
  local_8 = local_30 - 100.0;
  local_14 = (int *)(local_1c - local_94);
  local_20 = local_a8 - local_98;
  local_94 = local_8 - local_94;
  local_98 = local_2c - local_98;
  fVar14 = local_20 * local_20 + (float)local_14 * (float)local_14 + 0.0;
  FUN_0040b7e0();
  fVar12 = ((float)local_14 / fVar14) * local_94 + local_98 * (local_20 / fVar14) +
           (0.0 / fVar14) * 0.0;
  local_94 = local_94 - fVar12 * ((float)local_14 / fVar14);
  local_98 = local_98 - fVar12 * (local_20 / fVar14);
  local_14 = (int *)(local_ac - local_d0);
  local_78 = 0.0 - fVar12 * (0.0 / fVar14);
  local_8 = local_8 - local_d0;
  local_20 = local_b0 - local_74;
  local_74 = local_2c - local_74;
  fVar14 = (float)local_14 * (float)local_14 + local_20 * local_20 + 0.0;
  FUN_0040b7e0();
  fVar12 = local_74 * (local_20 / fVar14) + ((float)local_14 / fVar14) * local_8 +
           (0.0 / fVar14) * 0.0;
  local_8 = local_8 - fVar12 * ((float)local_14 / fVar14);
  local_74 = local_74 - fVar12 * (local_20 / fVar14);
  local_14 = (int *)(0.0 - fVar12 * (0.0 / fVar14));
  fVar14 = local_78 * local_78 + local_98 * local_98 + local_94 * local_94;
  FUN_0040b7e0();
  fVar12 = (float)local_14 * (float)local_14 + local_74 * local_74 + local_8 * local_8;
  local_20 = fVar14;
  FUN_0040b7e0();
  if (fVar12 <= local_20) {
    local_54 = local_d4;
    local_18 = local_38;
    local_24 = local_60;
    local_40 = local_e8;
    local_68 = local_f4;
    local_10 = local_e4;
    local_6c = local_f0;
    local_c = local_dc;
  }
  else {
    local_18 = local_48;
  }
  local_8 = local_30 + 100.0;
  local_14 = (int *)(local_8c - local_80);
  local_20 = local_90 - local_84;
  local_80 = local_8 - local_80;
  local_84 = local_2c - local_84;
  fVar14 = local_20 * local_20 + (float)local_14 * (float)local_14 + 0.0;
  FUN_0040b7e0();
  fVar12 = local_84 * (local_20 / fVar14) + ((float)local_14 / fVar14) * local_80 +
           (0.0 / fVar14) * 0.0;
  local_80 = local_80 - fVar12 * ((float)local_14 / fVar14);
  local_84 = local_84 - fVar12 * (local_20 / fVar14);
  local_14 = (int *)(local_d8 - local_e0);
  local_78 = 0.0 - fVar12 * (0.0 / fVar14);
  local_8 = local_8 - local_e0;
  local_20 = local_7c - local_88;
  local_88 = local_2c - local_88;
  fVar14 = (float)local_14 * (float)local_14 + local_20 * local_20 + 0.0;
  FUN_0040b7e0();
  fVar12 = local_88 * (local_20 / fVar14) + ((float)local_14 / fVar14) * local_8 +
           (0.0 / fVar14) * 0.0;
  local_8 = local_8 - fVar12 * ((float)local_14 / fVar14);
  local_88 = local_88 - fVar12 * (local_20 / fVar14);
  local_14 = (int *)(0.0 - fVar12 * (0.0 / fVar14));
  fVar14 = local_78 * local_78 + local_84 * local_84 + local_80 * local_80;
  FUN_0040b7e0();
  fVar12 = (float)local_14 * (float)local_14 + local_88 * local_88 + local_8 * local_8;
  local_20 = fVar14;
  FUN_0040b7e0();
  if (fVar12 <= local_20) {
    local_4c = local_ec;
    local_8 = local_9c;
    local_6c = local_10;
    local_40 = local_c;
  }
  else {
    local_8 = local_44;
  }
  local_c = local_2c - 100.0;
  local_1c = local_1c - local_8c;
  local_a8 = local_a8 - local_90;
  local_90 = local_c - local_90;
  fVar14 = local_a8 * local_a8 + local_1c * local_1c + 0.0;
  local_8c = local_30 - local_8c;
  FUN_0040b7e0();
  fVar12 = (local_a8 / fVar14) * local_90 + (local_1c / fVar14) * local_8c + (0.0 / fVar14) * 0.0;
  local_8c = local_8c - fVar12 * (local_1c / fVar14);
  local_90 = local_90 - fVar12 * (local_a8 / fVar14);
  local_14 = (int *)(0.0 - fVar12 * (0.0 / fVar14));
  local_ac = local_ac - local_d8;
  local_b0 = local_b0 - local_7c;
  local_c = local_c - local_7c;
  fVar14 = local_ac * local_ac + local_b0 * local_b0 + 0.0;
  local_7c = local_30 - local_d8;
  FUN_0040b7e0();
  fVar12 = (local_b0 / fVar14) * local_c + (local_ac / fVar14) * local_7c + (0.0 / fVar14) * 0.0;
  local_7c = local_7c - fVar12 * (local_ac / fVar14);
  local_c = local_c - fVar12 * (local_b0 / fVar14);
  local_20 = 0.0 - fVar12 * (0.0 / fVar14);
  fVar14 = (float)local_14 * (float)local_14 + local_90 * local_90 + local_8c * local_8c;
  FUN_0040b7e0();
  fVar12 = local_20 * local_20 + local_c * local_c + local_7c * local_7c;
  local_14 = (int *)fVar14;
  FUN_0040b7e0();
  if (fVar12 <= (float)local_14) {
    local_58 = local_108;
    local_5c = local_10c;
    local_44 = local_9c;
    local_48 = local_38;
  }
  local_c = local_6c;
  local_1c = local_4c;
  if (((((local_4c != local_34) || (local_6c != local_50)) &&
       ((local_4c != local_64 || (local_6c != local_3c)))) &&
      ((local_c = local_40, local_1c = local_8, local_8 != local_34 || (local_40 != local_50)))) &&
     ((local_8 != local_64 || (local_40 != local_3c)))) {
    fVar15 = local_8 - local_4c;
    fVar14 = local_64 - local_34;
    fVar13 = local_40 - local_6c;
    fVar12 = local_3c - local_50;
    if (fVar12 == 0.0) {
      fVar16 = (((local_4c - local_34) / fVar14) * fVar12 + local_50) - local_6c;
      fVar14 = fVar13 - (fVar12 * fVar15) / fVar14;
    }
    else {
      fVar16 = (((local_6c - local_50) / fVar12) * fVar14 + local_34) - local_4c;
      fVar14 = fVar15 - (fVar14 * fVar13) / fVar12;
    }
    local_c = fVar13 * (fVar16 / fVar14) + local_6c;
    local_1c = fVar15 * (fVar16 / fVar14) + local_4c;
  }
  if (((local_54 == local_34) && (local_68 == local_50)) ||
     ((local_54 == local_64 && (local_68 == local_3c)))) {
    local_38 = local_54;
    fVar14 = local_68;
  }
  else if (((local_18 == local_34) && (local_24 == local_50)) ||
          ((local_18 == local_64 && (local_24 == local_3c)))) {
    local_38 = local_18;
    fVar14 = local_24;
  }
  else {
    local_3c = local_3c - local_50;
    fVar14 = local_18 - local_54;
    local_9c = local_24 - local_68;
    fVar12 = local_64 - local_34;
    if (local_3c == 0.0) {
      fVar13 = (((local_54 - local_34) / fVar12) * local_3c + local_50) - local_68;
      local_3c = (local_3c * fVar14) / fVar12;
      fVar12 = local_9c - local_3c;
    }
    else {
      fVar13 = (((local_68 - local_50) / local_3c) * fVar12 + local_34) - local_54;
      fVar12 = fVar14 - (fVar12 * local_9c) / local_3c;
    }
    local_38 = (fVar13 / fVar12) * fVar14 + local_54;
    fVar14 = (fVar13 / fVar12) * local_9c + local_68;
  }
  fVar13 = local_6c;
  fVar12 = local_4c;
  if (((((local_4c != local_44) || (local_6c != local_58)) &&
       ((local_4c != local_48 || (local_6c != local_5c)))) &&
      ((fVar13 = local_40, local_8 != local_44 || (fVar12 = local_8, local_40 != local_58)))) &&
     ((local_8 != local_48 || (fVar12 = local_8, local_40 != local_5c)))) {
    local_60 = local_48 - local_44;
    local_8 = local_8 - local_4c;
    fVar12 = local_5c - local_58;
    local_40 = local_40 - local_6c;
    if (fVar12 == 0.0) {
      fVar13 = (local_8 * fVar12) / local_60;
      fVar15 = (((local_4c - local_44) / local_60) * fVar12 + local_58) - local_6c;
      fVar12 = local_40;
    }
    else {
      fVar15 = (((local_6c - local_58) / fVar12) * local_60 + local_44) - local_4c;
      fVar13 = (local_40 * local_60) / fVar12;
      fVar12 = local_8;
    }
    fVar15 = fVar15 / (fVar12 - fVar13);
    fVar13 = local_6c + local_40 * fVar15;
    fVar12 = local_4c + local_8 * fVar15;
  }
  local_4c = fVar12;
  fVar12 = local_54;
  fVar15 = local_68;
  if (((((local_54 != local_44) || (local_68 != local_58)) &&
       ((local_54 != local_48 || (local_68 != local_5c)))) &&
      ((fVar12 = local_18, fVar15 = local_24, local_18 != local_44 || (local_24 != local_58)))) &&
     ((local_18 != local_48 || (local_24 != local_5c)))) {
    local_18 = local_18 - local_54;
    local_24 = local_24 - local_68;
    local_48 = local_48 - local_44;
    local_5c = local_5c - local_58;
    if (local_5c == 0.0) {
      fVar16 = (local_5c * local_18) / local_48;
      fVar15 = (((local_54 - local_44) / local_48) * local_5c + local_58) - local_68;
      fVar12 = local_24;
    }
    else {
      fVar16 = (local_48 * local_24) / local_5c;
      fVar15 = (((local_68 - local_58) / local_5c) * local_48 + local_44) - local_54;
      fVar12 = local_18;
    }
    fVar15 = fVar15 / (fVar12 - fVar16);
    fVar12 = local_54 + fVar15 * local_18;
    fVar15 = local_68 + fVar15 * local_24;
  }
  local_54 = local_1c;
  if (local_4c < local_1c) {
    local_54 = local_4c;
  }
  local_10 = local_c;
  if (fVar13 < local_c) {
    local_10 = fVar13;
  }
  if (local_1c < local_4c) {
    local_1c = local_4c;
  }
  if (local_c < fVar13) {
    local_c = fVar13;
  }
  if (local_38 < local_54) {
    local_54 = local_38;
  }
  if (fVar14 < local_10) {
    local_10 = fVar14;
  }
  if (local_1c < local_38) {
    local_1c = local_38;
  }
  if (local_c < fVar14) {
    local_c = fVar14;
  }
  if (fVar12 < local_54) {
    local_54 = fVar12;
  }
  if (fVar15 < local_10) {
    local_10 = fVar15;
  }
  if (local_1c < fVar12) {
    local_1c = fVar12;
  }
  if (local_c < fVar15) {
    local_c = fVar15;
  }
  uVar10 = 2;
  local_14 = (int *)(DAT_0077244c + 0x488);
  do {
    piVar11 = local_14;
    if (uVar10 < 0x2000) {
      piVar11 = local_14 + uVar10;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar7 = DAT_00772400;
    iVar8 = *piVar11;
    if ((iVar8 != 0) &&
       ((*(char *)(DAT_00772400 + 0x590) != '\0' ||
        (((*(int *)(iVar8 + 0x36c) == *(int *)(DAT_00772400 + 100) &&
          ((*(uint *)(iVar8 + 0x3d0) & 0x200) != 0)) &&
         ((((iVar9 = *(int *)(iVar8 + 0xe8), iVar9 == 1 ||
            (((iVar9 == 0xb || (iVar9 == 2)) || (iVar9 == 5)))) ||
           (((iVar9 == 10 || (iVar9 == 8)) || (iVar9 == 6)))) || (iVar9 == 7)))))))) {
      fVar14 = *(float *)(iVar8 + 0xc);
      fVar12 = *(float *)(iVar8 + 0x10);
      if (((local_54 < fVar14) && (fVar14 < local_1c)) &&
         ((local_10 < fVar12 && (fVar12 < local_c)))) {
        fVar16 = *(float *)(iVar8 + 0x14) * 0.5 + 7.0;
        fVar13 = *(float *)(DAT_0076a338 + 0x2770) * fVar12 +
                 *(float *)(DAT_0076a338 + 0x2760) * fVar14 +
                 *(float *)(DAT_0076a338 + 0x2780) * fVar16 + *(float *)(DAT_0076a338 + 0x2790);
        fVar15 = (*(float *)(DAT_0076a338 + 0x2764) * fVar12 +
                  *(float *)(DAT_0076a338 + 0x2754) * fVar14 +
                  *(float *)(DAT_0076a338 + 0x2774) * fVar16 + *(float *)(DAT_0076a338 + 0x2784)) /
                 fVar13;
        fVar13 = (*(float *)(DAT_0076a338 + 0x2768) * fVar12 +
                  *(float *)(DAT_0076a338 + 0x2758) * fVar14 +
                  *(float *)(DAT_0076a338 + 0x2778) * fVar16 + *(float *)(DAT_0076a338 + 0x2788)) /
                 fVar13;
        if (((((float)local_a0 < fVar15) && (fVar15 < (float)local_a4)) &&
            ((float)local_b4 < fVar13)) && (fVar13 < (float)local_70)) {
          if (*(int *)(DAT_00772400 + 0xa0c8) < 1) goto LAB_0052ecdd;
          if (0 < *(int *)(DAT_00772400 + 0xa0c8)) {
            if (*(int *)(DAT_00772400 + 0xa0c8) == 0) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            piVar11 = (int *)(DAT_0077244c + 0x488);
            if (**(uint **)(iVar7 + 0xa0c4) < 0x2000) {
              piVar11 = piVar11 + **(uint **)(iVar7 + 0xa0c4);
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            if (*piVar11 != 0) {
              if ((*(char *)(DAT_00772400 + 0x590) == '\0') &&
                 (cVar1 = FUN_005e32b0(iVar8), cVar1 == '\0')) {
                if (*(int *)(iVar8 + 0xe8) != 1) goto LAB_0052ece8;
                FUN_0040b980(0);
              }
LAB_0052ecdd:
              FUN_005e3350(*(undefined4 *)(iVar8 + 0xdc));
            }
          }
        }
      }
    }
LAB_0052ece8:
    uVar10 = uVar10 + 1;
    if (0x1fff < (int)uVar10) {
      return;
    }
  } while( true );
}

