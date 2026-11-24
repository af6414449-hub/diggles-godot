
void FUN_0049f790(uint param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int *piVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  int in_ECX;
  uint uVar12;
  code *pcVar13;
  float fVar14;
  float fVar15;
  double dVar16;
  double dVar17;
  float fVar18;
  float in_XMM2_Da;
  float fVar19;
  int local_44;
  int local_40;
  float local_3c;
  uint local_38;
  float local_34;
  
  pcVar13 = RaiseException_exref;
  iVar2 = DAT_00767980 * 0x343fd + 0x269ec3;
  iVar3 = iVar2 * 0x343fd + 0x269ec3;
  DAT_00767980 = iVar3 * 0x343fd + 0x269ec3;
  uVar4 = DAT_00767980 >> 0x10;
  *(float *)(in_ECX + 0x24) =
       (*(float *)(in_ECX + 0x24) + (float)(int)((iVar2 >> 0x10 & 0xfU) - 8) / 8200.0) * 0.9;
  *(float *)(in_ECX + 0x28) =
       (*(float *)(in_ECX + 0x28) + (float)(int)((iVar3 >> 0x10 & 0xfU) - 8) / 9500.0) * 0.9;
  *(float *)(in_ECX + 0x2c) =
       (*(float *)(in_ECX + 0x2c) + (float)(int)((uVar4 & 0xf) - 8) / 8200.0) * 0.9;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc));
      iVar2 = FUN_00592f10(PTR_0077241c);
      pbVar5 = (byte *)(iVar2 + 0x34);
      if (param_1 < 8) {
        pbVar5 = pbVar5 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar5 < 0x81) {
        DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc));
        uVar4 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar5 = (byte *)FUN_00423700(uVar4);
        if (*pbVar5 < 0x81) {
          DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar4 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar5 = (byte *)FUN_00423700(uVar4);
          if (*pbVar5 < 0x81) {
            DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar5 = (byte *)FUN_00423700(param_1);
            if (*pbVar5 < 0x81) goto LAB_0049ffd3;
          }
        }
      }
    }
    uVar4 = *(uint *)(in_ECX + 0x70);
    if (uVar4 != 0xffffffff) {
      piVar6 = (int *)(DAT_0077244c + 0x488);
      if (uVar4 < 0x2000) {
        piVar6 = piVar6 + uVar4;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar2 = *piVar6;
      if (((iVar2 != 0) &&
          (cVar1 = FUN_0049aaa0(iVar2,*(undefined4 *)(in_ECX + 0x50),*(undefined4 *)(in_ECX + 0x74))
          , cVar1 == '\0')) || (iVar2 == 0)) {
        FUN_0049aa20();
        *(undefined4 *)(in_ECX + 0x70) = 0xffffffff;
      }
    }
    local_44 = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      local_40 = 0;
      do {
        iVar2 = FUN_00492f80();
        if ((*(int *)(in_ECX + 0x70) == -1) || (*(int *)(in_ECX + 0x7c) <= local_44)) {
          local_34 = *(float *)(in_ECX + 0x14);
          local_3c = *(float *)(in_ECX + 0x10);
          fVar14 = *(float *)(in_ECX + 0xc);
        }
        else {
          if ((local_44 < 0) || (*(int *)(in_ECX + 0x7c) <= local_44)) {
            (*pcVar13)(0xc000008c,1,0,0);
            pfVar7 = *(float **)(in_ECX + 0x78);
          }
          else {
            pfVar7 = (float *)(*(int *)(in_ECX + 0x78) + local_40);
          }
          local_34 = pfVar7[2];
          local_3c = pfVar7[1];
          fVar14 = *pfVar7;
        }
        iVar3 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar8 = iVar3 * 0x343fd + 0x269ec3;
        fVar15 = ((float)((iVar3 >> 0x10 & 0x7fffU) % 0x168) / 180.0) * 3.1415927;
        DAT_00767980 = iVar8 * 0x343fd + 0x269ec3;
        uVar4 = DAT_00767980 >> 0x10;
        fVar18 = (float)((iVar8 >> 0x10 & 0x7fffU) % 100) / 350.0;
        dVar16 = (double)fVar15;
        FUN_006f6ad0();
        dVar17 = (double)fVar15;
        FUN_006f5ae0();
        pcVar13 = RaiseException_exref;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = (float *)(*(int *)(in_ECX + 0x54) + iVar2 * 0x44);
        }
        iVar3 = iVar2 * 0x44;
        *pfVar7 = (float)dVar16 * fVar18 + fVar14;
        pfVar7[1] = (float)((uVar4 & 0x7fff) % 10) / 200.0 + local_3c;
        iVar8 = DAT_00767980 * 0x343fd + 0x269ec3;
        pfVar7[2] = (float)dVar17 * fVar18 + local_34;
        iVar9 = iVar8 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar9 * 0x343fd + 0x269ec3;
        uVar4 = DAT_00767980 >> 0x10;
        fVar14 = *(float *)(in_ECX + 0x18);
        fVar15 = *(float *)(in_ECX + 0x20);
        fVar18 = *(float *)(in_ECX + 0x1c);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar10 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar10 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(float *)(iVar10 + 0xc) = fVar14 + (float)(int)((iVar8 >> 0x10 & 0xfU) - 8) / 800.0;
        *(float *)(iVar10 + 0x10) =
             -((float)((iVar9 >> 0x10 & 0x7fffU) % 10) / 600.0 + 0.006) + fVar18;
        *(float *)(iVar10 + 0x14) = fVar15 + (float)(int)((uVar4 & 0xf) - 8) / 800.0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar8 + 0x28) = 0x40ce6666;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar8 + 0x2c) = 0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar8 + 0x34) = 0xffffffff;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar8 + 0x38) = 0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar4 = DAT_00767980 >> 0x10;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(float *)(iVar8 + 0x30) = (float)(uVar4 & 0x7fff) / 5215.0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar4 = DAT_00767980 >> 0x10;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_34 = *(float *)(in_ECX + 0x54);
        }
        else {
          local_34 = (float)(*(int *)(in_ECX + 0x54) + iVar3);
        }
        *(uint *)((int)local_34 + 0x3c) = uVar4 & 3;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        local_40 = local_40 + 0xc;
        *(undefined1 *)(iVar3 + 0x40) = 0;
        local_44 = local_44 + 1;
      } while (local_44 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_0049ffd3:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar2 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_38 = 0xff;
    do {
      if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar3 = *(int *)(in_ECX + 0x54);
        iVar8 = iVar3;
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x54) + iVar2 * 0x44;
        iVar8 = *(int *)(in_ECX + 0x54);
      }
      if (*(int *)(iVar3 + 0x2c) != -10000) {
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar3;
        }
        else {
          iVar3 = iVar8 + iVar2 * 0x44;
        }
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = (float *)(iVar8 + iVar2 * 0x44);
        }
        *pfVar7 = *pfVar7 + *(float *)(iVar3 + 0xc);
        pfVar7[1] = *(float *)(iVar3 + 0x10) + pfVar7[1];
        pfVar7[2] = *(float *)(iVar3 + 0x14) + pfVar7[2];
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
          pfVar11 = pfVar7;
        }
        else {
          pfVar7 = *(float **)(in_ECX + 0x54) + iVar2 * 0x11;
          pfVar11 = *(float **)(in_ECX + 0x54);
        }
        fVar14 = *pfVar7;
        fVar15 = *(float *)(in_ECX + 0xc);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar11 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar11 = pfVar11 + iVar2 * 0x11;
        }
        *pfVar11 = (fVar15 * 8.0 + fVar14 * 92.0) / 100.0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar3;
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar2 * 0x44;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = iVar8 + iVar2 * 0x44;
        }
        *(float *)(iVar8 + 8) =
             (*(float *)(iVar3 + 8) * 92.0 + *(float *)(in_ECX + 0x14) * 8.0) / 100.0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar2 * 0x44;
        }
        *(float *)(iVar3 + 0x30) = in_XMM2_Da * 0.2 + *(float *)(iVar3 + 0x30);
        fVar14 = *(float *)(in_ECX + 0x24);
        fVar15 = *(float *)(in_ECX + 0x2c);
        fVar18 = *(float *)(in_ECX + 0x28);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar2 * 0x44;
        }
        *(float *)(iVar3 + 0xc) = *(float *)(iVar3 + 0xc) + fVar14 * 0.1 * in_XMM2_Da;
        *(float *)(iVar3 + 0x14) = fVar15 * 0.1 * in_XMM2_Da + *(float *)(iVar3 + 0x14);
        *(float *)(iVar3 + 0x10) = *(float *)(iVar3 + 0x10) + fVar18 * 0.1 * in_XMM2_Da;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar2 * 0x44;
        }
        if (*(int *)(iVar3 + 0x2c) < 0x10) {
          DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
          uVar4 = DAT_00767980 >> 0x10;
          if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar3 = *(int *)(in_ECX + 0x54) + iVar2 * 0x44;
          }
          *(float *)(iVar3 + 0x10) =
               ((float)(uVar4 & 0x7fff) + 32768.0) * -0.0008 * 1.5258789e-05 +
               *(float *)(iVar3 + 0x10);
          *(float *)(iVar3 + 0xc) = *(float *)(iVar3 + 0xc) + 0.0;
          *(float *)(iVar3 + 0x14) = *(float *)(iVar3 + 0x14) + 0.0;
        }
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar2 * 0x44;
        }
        *(undefined4 *)(iVar3 + 0x34) = 0xffffffff;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar2 * 0x44;
        }
        *(undefined4 *)(iVar3 + 0x38) = 0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
          pfVar11 = pfVar7;
        }
        else {
          pfVar7 = *(float **)(in_ECX + 0x54) + iVar2 * 0x11;
          pfVar11 = *(float **)(in_ECX + 0x54);
        }
        fVar14 = ABS(*pfVar7 - *(float *)(in_ECX + 0xc));
        if (0.1 < fVar14) {
          fVar14 = 0.1;
        }
        fVar14 = (0.1 - fVar14) * 8.0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar11 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar11 = pfVar11 + iVar2 * 0x11;
        }
        iVar3 = 0x10 - (int)pfVar11[0xb];
        if (iVar3 < 0) {
          iVar3 = 0;
        }
        if (5 < iVar3) {
          iVar3 = 5;
        }
        iVar8 = (int)ROUND((float)iVar3 * fVar14);
        uVar12 = iVar8 * -0x14;
        DAT_00772dd8 = (uint)ROUND(fVar14);
        iVar3 = uVar12 + 0xff;
        uVar4 = iVar8 * 0x1e;
        if (0xff < (int)uVar12) {
          uVar12 = local_38;
        }
        if ((int)uVar12 < 0) {
          uVar12 = 0;
        }
        if (0xff < (int)uVar4) {
          uVar4 = 0xff;
        }
        if ((int)uVar4 < 0) {
          uVar4 = 0;
        }
        if (0xff < iVar3) {
          iVar3 = 0xff;
        }
        if (iVar3 < 0) {
          iVar3 = 0;
        }
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar2 * 0x44;
        }
        *(uint *)(iVar8 + 0x38) = (uVar12 << 8 | uVar12) << 8 | uVar4;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar2 * 0x44;
        }
        fVar14 = ((float)*(int *)(iVar8 + 0x2c) - 16.0) * 0.0625;
        if (0.0 <= fVar14) {
          if (1.0 < fVar14) {
            fVar14 = 1.0;
          }
        }
        else {
          fVar14 = 0.0;
        }
        fVar15 = (float)iVar3 * (1.0 - fVar14);
        uVar4 = (uint)ROUND((1.0 - fVar14) * 255.0);
        DAT_00772dd8 = uVar4;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar2 * 0x44;
        }
        *(uint *)(iVar3 + 0x34) = ((int)ROUND(fVar15) << 8 | (int)ROUND(fVar15)) << 8 | uVar4;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar2 * 0x44;
        }
        *(int *)(iVar3 + 0x2c) = *(int *)(iVar3 + 0x2c) + 1;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar3;
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar2 * 0x44;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar3 + 0x2c) < 0x20) {
          fVar14 = *(float *)(in_ECX + 0x60);
          if (fVar14 != 0.0) {
            if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar7 = *(float **)(in_ECX + 0x54);
              fVar14 = *(float *)(in_ECX + 0x60);
            }
            else {
              pfVar7 = (float *)(iVar8 + iVar2 * 0x44);
            }
            fVar19 = *(float *)(in_ECX + 0x10) - pfVar7[1];
            fVar18 = *(float *)(in_ECX + 0xc) - *pfVar7;
            fVar15 = *(float *)(in_ECX + 0x14) - pfVar7[2];
            if (fVar14 < fVar19 * fVar19 + fVar18 * fVar18 + fVar15 * fVar15) goto LAB_004a07a2;
          }
        }
        else {
LAB_004a07a2:
          FUN_00493010(iVar2);
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

