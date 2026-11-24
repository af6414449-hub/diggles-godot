
void FUN_10025720(int param_1,int param_2)

{
  int iVar1;
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
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  float fVar45;
  float fVar46;
  float fVar47;
  float fVar48;
  float fVar49;
  float fVar50;
  float fVar51;
  float fVar52;
  float fVar53;
  float fVar54;
  float fVar55;
  float fVar56;
  float fVar57;
  float fVar58;
  float fVar59;
  float fVar60;
  float fVar61;
  float fVar62;
  float fVar63;
  float fVar64;
  float fVar65;
  float fVar66;
  float fVar67;
  float fVar68;
  float fVar69;
  float fVar70;
  float fVar71;
  float fVar72;
  float fVar73;
  float fVar74;
  float fVar75;
  float fVar76;
  float fVar77;
  float fVar78;
  float fVar79;
  float fVar80;
  float fVar81;
  float fVar82;
  float fVar83;
  float fVar84;
  float fVar85;
  float fVar86;
  float fVar87;
  float *pfVar88;
  float *pfVar89;
  float *pfVar90;
  float *pfVar91;
  float *pfVar92;
  float *pfVar93;
  float *pfVar94;
  float *pfVar95;
  float *pfVar96;
  float *pfVar97;
  float *pfVar98;
  float fVar99;
  float fVar100;
  float fVar101;
  float fVar102;
  float fVar103;
  float fVar104;
  float fVar105;
  float fVar106;
  float fVar107;
  float fVar108;
  float fVar109;
  float fVar110;
  float fVar111;
  float fVar112;
  float fVar113;
  float fVar114;
  float fVar115;
  float fVar116;
  float fVar117;
  float fVar118;
  float fVar119;
  float fVar120;
  float fVar121;
  float fVar122;
  float fVar123;
  float fVar124;
  float fVar125;
  int iVar126;
  undefined4 *in_ECX;
  float *pfVar127;
  float *pfVar128;
  int in_EDX;
  int iVar129;
  undefined4 *puVar130;
  int local_5c;
  float *local_54;
  float *local_4c;
  float *local_48;
  float *local_44;
  float *local_40;
  float *local_3c;
  float *local_30;
  float *local_2c;
  float *local_18;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  local_2c = (float *)&DAT_10047100;
  puVar130 = in_ECX + param_1 * 0x240 + -0x240;
  local_44 = (float *)(in_EDX + param_1 * 4);
  *(undefined4 *)(param_2 + 0xff0) = in_ECX[0x120];
  *(undefined4 *)(param_2 + 0xff4) = puVar130[0x120];
  *(undefined4 *)(param_2 + 0xff8) = *in_ECX;
  *(undefined4 *)(param_2 + 0xffc) = *puVar130;
  *(undefined4 *)(param_2 + 0x10f0) = in_ECX[0x121];
  *(undefined4 *)(param_2 + 0x10f4) = puVar130[0x121];
  *(undefined4 *)(param_2 + 0x10f8) = in_ECX[1];
  *(undefined4 *)(param_2 + 0x10fc) = puVar130[1];
  FUN_10025580(param_2 + 0xf4);
  FUN_10025580(param_2 + 500);
  FUN_10025580(param_2 + 0xf0);
  FUN_10025580(param_2 + 0x1f0);
  local_48 = (float *)(in_ECX + 0x10e);
  pfVar128 = (float *)(puVar130 + 0x10f);
  local_54 = (float *)(param_1 * 0xfc + in_EDX);
  local_18 = (float *)(param_1 * 0x7c + in_EDX);
  iVar1 = (int)local_44 + (-4 - in_EDX);
  local_3c = (float *)(puVar130 + 0x133);
  local_40 = (float *)(puVar130 + 0x132);
  iVar129 = (int)in_ECX - (int)puVar130;
  local_4c = (float *)(param_1 * 0x84 + in_EDX);
  iVar126 = FUN_10021470();
  if (iVar126 != 0) {
    pfVar127 = (float *)(param_2 + 0xfe8);
    local_30 = (float *)0xe;
    do {
      pfVar127[-2] = *(float *)(iVar129 + (int)local_40);
      pfVar127[-1] = *local_40;
      *pfVar127 = *(float *)(iVar129 + (int)local_3c);
      pfVar127[1] = *local_3c;
      pfVar127[0x3e] = *(float *)(iVar129 + (int)pfVar128);
      pfVar127[0x3f] = *pfVar128;
      pfVar127[-0x40] = *local_48;
      pfVar127[-0x3f] = pfVar128[-1];
      fVar18 = pfVar127[-0x382];
      fVar19 = pfVar127[-0x381];
      fVar20 = pfVar127[-0x380];
      fVar21 = pfVar127[-0x37f];
      fVar22 = pfVar127[-0x182];
      fVar23 = pfVar127[-0x181];
      fVar24 = pfVar127[-0x180];
      fVar25 = pfVar127[-0x17f];
      fVar2 = *local_2c;
      fVar3 = local_2c[1];
      fVar4 = local_2c[2];
      fVar5 = local_2c[3];
      fVar6 = local_2c[4];
      fVar7 = local_2c[5];
      fVar8 = local_2c[6];
      fVar9 = local_2c[7];
      fVar10 = local_2c[8];
      fVar11 = local_2c[9];
      fVar12 = local_2c[10];
      fVar13 = local_2c[0xb];
      fVar14 = local_2c[0xe];
      fVar15 = local_2c[0xf];
      fVar16 = local_2c[0xc];
      fVar26 = pfVar127[-0x242];
      fVar27 = pfVar127[-0x241];
      fVar28 = pfVar127[-0x240];
      fVar29 = pfVar127[-0x23f];
      fVar30 = pfVar127[-0x1c2];
      fVar31 = pfVar127[-0x1c1];
      fVar32 = pfVar127[-0x1c0];
      fVar33 = pfVar127[-0x1bf];
      fVar34 = pfVar127[-0x202];
      fVar35 = pfVar127[-0x201];
      fVar36 = pfVar127[-0x200];
      fVar37 = pfVar127[-0x1ff];
      fVar17 = local_2c[0xd];
      local_2c = local_2c + 0x10;
      fVar38 = pfVar127[-0x42];
      pfVar88 = pfVar127 + -0x41;
      fVar39 = pfVar127[-0x40];
      fVar40 = pfVar127[-0x3f];
      fVar41 = pfVar127[-0x3c2];
      pfVar89 = pfVar127 + -0x3c1;
      fVar42 = pfVar127[-0x3c0];
      fVar43 = pfVar127[-0x3bf];
      fVar44 = pfVar127[-2];
      pfVar90 = pfVar127 + -1;
      fVar45 = *pfVar127;
      fVar46 = pfVar127[1];
      fVar47 = pfVar127[-0x82];
      pfVar91 = pfVar127 + -0x81;
      fVar48 = pfVar127[-0x80];
      fVar49 = pfVar127[-0x7f];
      fVar50 = pfVar127[-0x342];
      pfVar92 = pfVar127 + -0x341;
      fVar51 = pfVar127[-0x340];
      fVar52 = pfVar127[-0x33f];
      fVar53 = pfVar127[-0xc2];
      pfVar93 = pfVar127 + -0xc1;
      fVar54 = pfVar127[-0xc0];
      fVar55 = pfVar127[-0xbf];
      fVar56 = pfVar127[-0x302];
      pfVar94 = pfVar127 + -0x301;
      fVar57 = pfVar127[-0x300];
      fVar58 = pfVar127[-0x2ff];
      fVar59 = pfVar127[-0x2c2];
      pfVar95 = pfVar127 + -0x2c1;
      fVar60 = pfVar127[-0x2c0];
      fVar61 = pfVar127[-0x2bf];
      fVar62 = pfVar127[-0x102];
      pfVar96 = pfVar127 + -0x101;
      fVar63 = pfVar127[-0x100];
      fVar64 = pfVar127[-0xff];
      fVar65 = pfVar127[-0x142];
      pfVar97 = pfVar127 + -0x141;
      fVar66 = pfVar127[-0x140];
      fVar67 = pfVar127[-0x13f];
      fVar68 = pfVar127[-0x282];
      pfVar98 = pfVar127 + -0x281;
      fVar69 = pfVar127[-0x280];
      fVar70 = pfVar127[-0x27f];
      fVar71 = pfVar127[-0x42];
      fVar72 = pfVar127[-0x41];
      fVar73 = pfVar127[-0x40];
      fVar74 = pfVar127[-0x3f];
      fVar75 = pfVar127[-0x3c2];
      fVar76 = pfVar127[-0x3c1];
      fVar77 = pfVar127[-0x3c0];
      fVar78 = pfVar127[-0x3bf];
      fVar79 = pfVar127[-2];
      fVar80 = pfVar127[-1];
      fVar81 = *pfVar127;
      fVar82 = pfVar127[1];
      fVar83 = pfVar127[-0x82];
      fVar84 = pfVar127[-0x81];
      fVar85 = pfVar127[-0x80];
      fVar86 = pfVar127[-0x7f];
      fVar87 = pfVar127[-0x342];
      fVar99 = pfVar127[-0x341];
      fVar100 = pfVar127[-0x340];
      fVar101 = pfVar127[-0x33f];
      fVar102 = pfVar127[-0xc2];
      fVar103 = pfVar127[-0xc1];
      fVar104 = pfVar127[-0xc0];
      fVar105 = pfVar127[-0xbf];
      fVar106 = pfVar127[-0x302];
      fVar107 = pfVar127[-0x301];
      fVar108 = pfVar127[-0x300];
      fVar109 = pfVar127[-0x2ff];
      pfVar128 = pfVar128 + -0x12;
      local_30 = (float *)((int)local_30 + -1);
      local_3c = local_3c + 0x12;
      local_48 = local_48 + -0x12;
      fVar110 = pfVar127[-0x2c2];
      fVar111 = pfVar127[-0x2c1];
      fVar112 = pfVar127[-0x2c0];
      fVar113 = pfVar127[-0x2bf];
      fVar114 = pfVar127[-0x102];
      fVar115 = pfVar127[-0x101];
      fVar116 = pfVar127[-0x100];
      fVar117 = pfVar127[-0xff];
      fVar118 = pfVar127[-0x142];
      fVar119 = pfVar127[-0x141];
      fVar120 = pfVar127[-0x140];
      fVar121 = pfVar127[-0x13f];
      fVar122 = pfVar127[-0x282];
      fVar123 = pfVar127[-0x281];
      fVar124 = pfVar127[-0x280];
      fVar125 = pfVar127[-0x27f];
      pfVar127 = pfVar127 + -4;
      *(float *)(iVar1 + (int)local_44) =
           ((fVar19 * fVar5 - *pfVar88 * fVar4) + (*pfVar90 * fVar2 - *pfVar89 * fVar3) +
            (*pfVar91 * fVar6 - *pfVar92 * fVar7) + (*pfVar94 * fVar9 - *pfVar93 * fVar8) +
            (*pfVar96 * fVar10 - *pfVar95 * fVar11) + (*pfVar98 * fVar13 - *pfVar97 * fVar12) +
            (fVar23 * fVar16 - fVar27 * fVar17) + (fVar35 * fVar15 - fVar31 * fVar14)) *
           3.0517578e-05;
      *(float *)(iVar1 + (int)local_18) =
           (fVar19 * fVar4 + fVar72 * fVar5 + fVar80 * fVar3 + fVar76 * fVar2 +
            fVar84 * fVar7 + fVar99 * fVar6 + fVar107 * fVar8 + fVar103 * fVar9 +
            fVar115 * fVar11 + fVar111 * fVar10 + fVar123 * fVar12 + fVar119 * fVar13 +
            fVar23 * fVar17 + fVar27 * fVar16 + fVar35 * fVar14 + fVar31 * fVar15) * 3.0517578e-05;
      *local_44 = ((fVar18 * fVar5 - fVar38 * fVar4) + (fVar44 * fVar2 - fVar41 * fVar3) +
                   (fVar47 * fVar6 - fVar50 * fVar7) + (fVar56 * fVar9 - fVar53 * fVar8) +
                   (fVar62 * fVar10 - fVar59 * fVar11) + (fVar68 * fVar13 - fVar65 * fVar12) +
                   (fVar22 * fVar16 - fVar26 * fVar17) + (fVar34 * fVar15 - fVar30 * fVar14)) *
                  3.0517578e-05;
      *local_18 = (fVar18 * fVar4 + fVar71 * fVar5 + fVar79 * fVar3 + fVar75 * fVar2 +
                   fVar83 * fVar7 + fVar87 * fVar6 + fVar106 * fVar8 + fVar102 * fVar9 +
                   fVar114 * fVar11 + fVar110 * fVar10 + fVar122 * fVar12 + fVar118 * fVar13 +
                   fVar22 * fVar17 + fVar26 * fVar16 + fVar34 * fVar14 + fVar30 * fVar15) *
                  3.0517578e-05;
      *(float *)(iVar1 + (int)local_4c) =
           ((fVar21 * fVar5 - fVar40 * fVar4) + (fVar46 * fVar2 - fVar43 * fVar3) +
            (fVar49 * fVar6 - fVar52 * fVar7) + (fVar58 * fVar9 - fVar55 * fVar8) +
            (fVar64 * fVar10 - fVar61 * fVar11) + (fVar70 * fVar13 - fVar67 * fVar12) +
            (fVar25 * fVar16 - fVar29 * fVar17) + (fVar37 * fVar15 - fVar33 * fVar14)) *
           3.0517578e-05;
      *(float *)(iVar1 + (int)local_54) =
           (fVar21 * fVar4 + fVar74 * fVar5 + fVar82 * fVar3 + fVar78 * fVar2 +
            fVar86 * fVar7 + fVar101 * fVar6 + fVar109 * fVar8 + fVar105 * fVar9 +
            fVar117 * fVar11 + fVar113 * fVar10 + fVar125 * fVar12 + fVar121 * fVar13 +
            fVar25 * fVar17 + fVar29 * fVar16 + fVar37 * fVar14 + fVar33 * fVar15) * 3.0517578e-05;
      *local_4c = ((fVar20 * fVar5 - fVar39 * fVar4) + (fVar45 * fVar2 - fVar42 * fVar3) +
                   (fVar48 * fVar6 - fVar51 * fVar7) + (fVar57 * fVar9 - fVar54 * fVar8) +
                   (fVar63 * fVar10 - fVar60 * fVar11) + (fVar69 * fVar13 - fVar66 * fVar12) +
                   (fVar24 * fVar16 - fVar28 * fVar17) + (fVar36 * fVar15 - fVar32 * fVar14)) *
                  3.0517578e-05;
      local_40 = local_40 + 0x12;
      local_18 = local_18 + -param_1;
      *local_54 = (fVar20 * fVar4 + fVar73 * fVar5 + fVar81 * fVar3 + fVar77 * fVar2 +
                   fVar85 * fVar7 + fVar100 * fVar6 + fVar108 * fVar8 + fVar104 * fVar9 +
                   fVar116 * fVar11 + fVar112 * fVar10 + fVar124 * fVar12 + fVar120 * fVar13 +
                   fVar24 * fVar17 + fVar28 * fVar16 + fVar36 * fVar14 + fVar32 * fVar15) *
                  3.0517578e-05;
      local_54 = local_54 + -param_1;
      local_44 = local_44 + param_1;
      local_4c = local_4c + param_1;
    } while (-1 < (int)local_30);
    return;
  }
  local_30 = (float *)(param_2 + 0xe8);
  local_5c = 0xe;
  do {
    fVar2 = *(float *)(iVar129 + (int)local_40);
    local_30[0x3be] = fVar2;
    fVar3 = *local_40;
    local_30[0x3bf] = fVar3;
    fVar4 = *(float *)(iVar129 + (int)local_3c);
    local_30[0x3c0] = fVar4;
    fVar5 = *local_3c;
    local_30[0x3c1] = fVar5;
    local_30[0x3fe] = *(float *)(iVar129 + (int)pfVar128);
    local_30[0x3ff] = *pfVar128;
    fVar6 = *local_48;
    local_30[0x380] = fVar6;
    fVar7 = pfVar128[-1];
    local_30[0x381] = fVar7;
    fVar8 = *local_2c;
    fVar9 = local_2c[1];
    fVar10 = local_30[-2];
    fVar11 = local_30[-1];
    fVar12 = *local_30;
    fVar13 = local_30[1];
    fVar14 = *local_30;
    fVar15 = local_2c[2];
    fVar16 = local_30[0x3e];
    fVar17 = local_2c[3];
    fVar18 = local_30[0x37e];
    fVar19 = local_30[0x3e];
    fVar20 = local_30[0x37f];
    fVar21 = local_30[0x3f];
    fVar22 = local_30[0x40];
    fVar23 = local_30[0x41];
    fVar24 = local_2c[5];
    fVar25 = local_2c[4];
    fVar26 = local_30[0x7e];
    fVar27 = local_30[0x33e];
    fVar28 = local_30[0x33f];
    fVar29 = local_30[0x33e];
    fVar30 = local_30[0x7f];
    fVar31 = local_30[0x340];
    fVar32 = local_30[0x80];
    fVar33 = local_30[0x81];
    fVar34 = local_30[0x341];
    fVar35 = local_2c[7];
    fVar36 = local_2c[6];
    fVar37 = local_30[0x2fe];
    fVar38 = local_30[0xbe];
    fVar39 = local_30[0x2ff];
    fVar40 = local_30[0xbf];
    fVar41 = local_30[0xc0];
    pfVar127 = local_30 + 0xbf;
    fVar42 = local_30[0x300];
    fVar43 = local_30[0xc0];
    fVar44 = local_30[0x301];
    fVar45 = local_30[0xc1];
    fVar46 = local_2c[9];
    fVar47 = local_2c[8];
    fVar48 = local_30[0xfe];
    fVar49 = local_30[0x2be];
    fVar50 = local_30[0xff];
    fVar51 = local_30[0x2bf];
    fVar52 = local_30[0x100];
    fVar53 = local_30[0x2c0];
    fVar54 = local_30[0x2c0];
    fVar55 = local_30[0x101];
    fVar56 = local_30[0x2c1];
    fVar57 = local_30[0x13e];
    fVar58 = local_30[0x2c1];
    fVar59 = local_2c[10];
    fVar60 = local_30[0x27e];
    fVar61 = local_2c[0xb];
    fVar62 = local_30[0x13f];
    fVar63 = local_30[0x27f];
    fVar64 = local_30[0x140];
    fVar65 = local_30[0x280];
    fVar66 = local_30[0x141];
    fVar67 = local_30[0x281];
    fVar68 = local_30[0x17e];
    fVar69 = local_2c[0xc];
    fVar70 = local_2c[0xd];
    fVar71 = local_30[0x23e];
    fVar72 = local_30[0x23f];
    fVar73 = local_30[0x17f];
    fVar74 = local_30[0x240];
    fVar75 = local_30[0x180];
    fVar76 = local_30[0x241];
    fVar77 = local_30[0x181];
    fVar78 = local_30[0x1be];
    fVar79 = local_30[0x1fe];
    fVar80 = local_2c[0xe];
    fVar81 = local_2c[0xf];
    local_2c = local_2c + 0x10;
    fVar82 = local_30[0x1bf];
    fVar83 = local_30[0x1ff];
    fVar84 = local_30[0x1c0];
    fVar85 = local_30[0x200];
    fVar86 = local_30[0x201];
    pfVar128 = pfVar128 + -0x12;
    fVar87 = local_30[0x1c1];
    local_5c = local_5c + -1;
    local_3c = local_3c + 0x12;
    local_48 = local_48 + -0x12;
    local_30 = local_30 + -4;
    local_40 = local_40 + 0x12;
    *(float *)(iVar1 + (int)local_44) =
         ((fVar81 * fVar82 - fVar80 * fVar83) +
         (fVar69 * fVar72 - fVar70 * fVar73) +
         (fVar61 * fVar62 - fVar63 * fVar59) +
         (fVar51 * fVar47 - fVar50 * fVar46) +
         (*pfVar127 * fVar35 - fVar39 * fVar36) +
         (fVar28 * fVar25 - fVar30 * fVar24) +
         (fVar21 * fVar17 - fVar20 * fVar15) + (fVar8 * fVar3 - fVar11 * fVar9)) * 3.0517578e-05;
    *(float *)(iVar1 + (int)local_18) =
         (fVar80 * fVar82 + fVar81 * fVar83 +
         fVar69 * fVar73 + fVar70 * fVar72 +
         fVar63 * fVar61 + fVar59 * fVar62 +
         fVar50 * fVar47 + fVar51 * fVar46 +
         fVar40 * fVar36 + fVar39 * fVar35 +
         fVar30 * fVar25 + fVar28 * fVar24 +
         fVar21 * fVar15 + fVar20 * fVar17 + fVar9 * fVar3 + fVar11 * fVar8) * 3.0517578e-05;
    *local_44 = ((fVar78 * fVar81 - fVar79 * fVar80) +
                (fVar71 * fVar69 - fVar68 * fVar70) +
                (fVar57 * fVar61 - fVar60 * fVar59) +
                (fVar49 * fVar47 - fVar48 * fVar46) +
                (fVar38 * fVar35 - fVar37 * fVar36) +
                (fVar29 * fVar25 - fVar26 * fVar24) +
                (fVar19 * fVar17 - fVar18 * fVar15) + (fVar8 * fVar2 - fVar10 * fVar9)) *
                3.0517578e-05;
    *local_18 = (fVar78 * fVar80 + fVar79 * fVar81 +
                fVar68 * fVar69 + fVar71 * fVar70 +
                fVar57 * fVar59 + fVar60 * fVar61 +
                fVar48 * fVar47 + fVar49 * fVar46 +
                fVar38 * fVar36 + fVar37 * fVar35 +
                fVar26 * fVar25 + fVar27 * fVar24 +
                fVar16 * fVar15 + fVar18 * fVar17 + fVar9 * fVar2 + fVar10 * fVar8) * 3.0517578e-05;
    local_18 = local_18 + -param_1;
    *(float *)(iVar1 + (int)local_4c) =
         ((fVar81 * fVar87 - fVar80 * fVar86) +
         (fVar69 * fVar76 - fVar70 * fVar77) +
         (fVar61 * fVar66 - fVar59 * fVar67) +
         (fVar58 * fVar47 - fVar55 * fVar46) +
         (fVar45 * fVar35 - fVar44 * fVar36) +
         (fVar34 * fVar25 - fVar33 * fVar24) +
         (fVar23 * fVar17 - fVar7 * fVar15) + (fVar5 * fVar8 - fVar13 * fVar9)) * 3.0517578e-05;
    *(float *)(iVar1 + (int)local_54) =
         (fVar80 * fVar87 + fVar81 * fVar86 +
         fVar69 * fVar77 + fVar70 * fVar76 +
         fVar59 * fVar66 + fVar61 * fVar67 +
         fVar55 * fVar47 + fVar56 * fVar46 +
         fVar45 * fVar36 + fVar44 * fVar35 +
         fVar33 * fVar25 + fVar34 * fVar24 +
         fVar23 * fVar15 + fVar7 * fVar17 + fVar13 * fVar8 + fVar5 * fVar9) * 3.0517578e-05;
    local_44 = local_44 + param_1;
    *local_4c = ((fVar81 * fVar84 - fVar80 * fVar85) +
                (fVar69 * fVar74 - fVar70 * fVar75) +
                (fVar61 * fVar64 - fVar59 * fVar65) +
                (fVar54 * fVar47 - fVar52 * fVar46) +
                (fVar43 * fVar35 - fVar42 * fVar36) +
                (fVar31 * fVar25 - fVar32 * fVar24) +
                (fVar22 * fVar17 - fVar6 * fVar15) + (fVar4 * fVar8 - fVar9 * fVar14)) *
                3.0517578e-05;
    local_4c = local_4c + param_1;
    *local_54 = (fVar80 * fVar84 + fVar81 * fVar85 +
                fVar70 * fVar74 + fVar69 * fVar75 +
                fVar59 * fVar64 + fVar61 * fVar65 +
                fVar52 * fVar47 + fVar53 * fVar46 +
                fVar41 * fVar36 + fVar42 * fVar35 +
                fVar32 * fVar25 + fVar31 * fVar24 +
                fVar22 * fVar15 + fVar6 * fVar17 + fVar8 * fVar12 + fVar4 * fVar9) * 3.0517578e-05;
    local_54 = local_54 + -param_1;
  } while (-1 < local_5c);
  return;
}

