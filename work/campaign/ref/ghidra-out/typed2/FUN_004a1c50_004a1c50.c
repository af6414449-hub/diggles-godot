
void FUN_004a1c50(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int in_ECX;
  int iVar8;
  uint uVar9;
  float *pfVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  double dVar14;
  double dVar15;
  float fVar16;
  float in_XMM2_Da;
  uint local_40;
  int local_30;
  
  iVar1 = DAT_00767980 * 0x343fd + 0x269ec3;
  iVar2 = iVar1 * 0x343fd + 0x269ec3;
  DAT_00767980 = iVar2 * 0x343fd + 0x269ec3;
  uVar3 = DAT_00767980 >> 0x10;
  *(float *)(in_ECX + 0x24) =
       (*(float *)(in_ECX + 0x24) + (float)(int)((iVar1 >> 0x10 & 0xfU) - 8) / 8200.0) * 0.9;
  *(float *)(in_ECX + 0x28) =
       (*(float *)(in_ECX + 0x28) + (float)(int)((iVar2 >> 0x10 & 0xfU) - 8) / 9500.0) * 0.9;
  *(float *)(in_ECX + 0x2c) =
       (*(float *)(in_ECX + 0x2c) + (float)(int)((uVar3 & 0xf) - 8) / 8200.0) * 0.9;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc));
      iVar1 = FUN_00592f10(PTR_0077241c);
      pbVar4 = (byte *)(iVar1 + 0x34);
      if (param_1 < 8) {
        pbVar4 = pbVar4 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar4 < 0x81) {
        DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc));
        uVar3 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar4 = (byte *)FUN_00423700(uVar3);
        if (*pbVar4 < 0x81) {
          DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar3 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar4 = (byte *)FUN_00423700(uVar3);
          if (*pbVar4 < 0x81) {
            DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar4 = (byte *)FUN_00423700(param_1);
            if (*pbVar4 < 0x81) goto LAB_004a2442;
          }
        }
      }
    }
    local_30 = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar1 = FUN_00492f80();
        iVar8 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar2 = iVar8 * 0x343fd + 0x269ec3;
        fVar16 = ((float)((iVar8 >> 0x10 & 0x7fffU) % 0x168) / 180.0) * 3.1415927;
        DAT_00767980 = iVar2 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        fVar11 = (float)((iVar2 >> 0x10 & 0x7fffU) % 100) / 850.0;
        dVar14 = (double)fVar16;
        FUN_006f6ad0();
        fVar12 = *(float *)(in_ECX + 0xc);
        fVar13 = *(float *)(in_ECX + 0x10);
        dVar15 = (double)fVar16;
        FUN_006f5ae0();
        fVar16 = *(float *)(in_ECX + 0x14);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar10 = (float *)(*(int *)(in_ECX + 0x54) + iVar1 * 0x44);
        }
        iVar2 = iVar1 * 0x44;
        *pfVar10 = (float)dVar14 * fVar11 + fVar12;
        pfVar10[1] = (float)((uVar3 & 0x7fff) % 10) / 200.0 + fVar13;
        iVar8 = DAT_00767980 * 0x343fd + 0x269ec3;
        pfVar10[2] = (float)dVar15 * fVar11 + fVar16;
        iVar5 = iVar8 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar5 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        fVar12 = *(float *)(in_ECX + 0x1c);
        fVar13 = *(float *)(in_ECX + 0x18);
        fVar16 = *(float *)(in_ECX + 0x20);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(float *)(iVar6 + 0xc) = (float)(int)((iVar8 >> 0x10 & 0xfU) - 8) / 800.0 + fVar13;
        *(float *)(iVar6 + 0x10) =
             fVar12 + -((float)((iVar5 >> 0x10 & 0x7fffU) % 10) / 600.0 + 0.008);
        *(float *)(iVar6 + 0x14) = fVar16 + (float)(int)((uVar3 & 0xf) - 8) / 800.0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        fVar12 = *(float *)(in_ECX + 0x1c);
        fVar13 = *(float *)(in_ECX + 0x20);
        fVar11 = (float)(DAT_00767980 >> 0x10 & 0x7fff);
        fVar16 = *(float *)(in_ECX + 0x18);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar10 = (float *)(*(int *)(in_ECX + 0x54) + iVar2);
        }
        *pfVar10 = *pfVar10 + fVar11 * fVar16 * 3.0517578e-05;
        pfVar10[1] = pfVar10[1] + fVar12 * fVar11 * 3.0517578e-05;
        pfVar10[2] = pfVar10[2] + fVar13 * fVar11 * 3.0517578e-05;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar8 + 0x28) = 0x3f933333;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar8 + 0x2c) = 0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar8 + 0x34) = 0xffffffff;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar8 + 0x38) = 0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar8 + 0x30) = 0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(uint *)(iVar8 + 0x3c) = ((uVar3 & 0x7fff) % 3) * 0x10000;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined1 *)(iVar2 + 0x40) = 0;
        local_30 = local_30 + 1;
      } while (local_30 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004a2442:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar1 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_40 = 0xff;
    do {
      if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar2 = *(int *)(in_ECX + 0x54);
        iVar8 = iVar2;
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        iVar8 = *(int *)(in_ECX + 0x54);
      }
      if (*(int *)(iVar2 + 0x2c) != -10000) {
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar2;
        }
        else {
          iVar2 = iVar8 + iVar1 * 0x44;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar10 = (float *)(iVar8 + iVar1 * 0x44);
        }
        *pfVar10 = *(float *)(iVar2 + 0xc) + *pfVar10;
        pfVar10[1] = *(float *)(iVar2 + 0x10) + pfVar10[1];
        pfVar10[2] = *(float *)(iVar2 + 0x14) + pfVar10[2];
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = *(float **)(in_ECX + 0x54);
          pfVar7 = pfVar10;
        }
        else {
          pfVar10 = *(float **)(in_ECX + 0x54) + iVar1 * 0x11;
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        fVar12 = *pfVar10;
        fVar13 = *(float *)(in_ECX + 0xc);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = pfVar7 + iVar1 * 0x11;
        }
        *pfVar7 = (fVar13 * 8.0 + fVar12 * 92.0) / 100.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = iVar8 + iVar1 * 0x44;
        }
        *(float *)(iVar8 + 8) =
             (*(float *)(iVar2 + 8) * 92.0 + *(float *)(in_ECX + 0x14) * 8.0) / 100.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar5;
        }
        else {
          iVar5 = iVar8 + iVar1 * 0x44;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar6;
        }
        else {
          iVar6 = iVar8 + iVar1 * 0x44;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = iVar8 + iVar1 * 0x44;
        }
        iVar5 = *(int *)(iVar6 + 0x2c) * *(int *)(iVar5 + 0x2c);
        iVar5 = 0x1f - ((int)((iVar5 >> 0x1f & 0x1fU) + iVar5) >> 5);
        *(uint *)(iVar8 + 0x3c) =
             (int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2 | *(uint *)(iVar2 + 0x3c) & 0xffff0000;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        *(float *)(iVar2 + 0x30) = in_XMM2_Da * 0.2 + *(float *)(iVar2 + 0x30);
        fVar12 = *(float *)(in_ECX + 0x24);
        fVar13 = *(float *)(in_ECX + 0x28);
        fVar16 = *(float *)(in_ECX + 0x2c);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        *(float *)(iVar2 + 0xc) = *(float *)(iVar2 + 0xc) + fVar12 * 0.1 * in_XMM2_Da;
        *(float *)(iVar2 + 0x10) = *(float *)(iVar2 + 0x10) + fVar13 * 0.1 * in_XMM2_Da;
        *(float *)(iVar2 + 0x14) = *(float *)(iVar2 + 0x14) + fVar16 * 0.1 * in_XMM2_Da;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        if (*(int *)(iVar2 + 0x2c) < 6) {
          DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
          uVar3 = DAT_00767980 >> 0x10;
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar2 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
          }
          *(float *)(iVar2 + 0x10) =
               ((float)(uVar3 & 0x7fff) + 32768.0) * -0.0008 * 1.5258789e-05 +
               *(float *)(iVar2 + 0x10);
          *(float *)(iVar2 + 0xc) = *(float *)(iVar2 + 0xc) + 0.0;
          *(float *)(iVar2 + 0x14) = *(float *)(iVar2 + 0x14) + 0.0;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        *(undefined4 *)(iVar2 + 0x34) = 0xffffffff;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        *(undefined4 *)(iVar2 + 0x38) = 0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = *(float **)(in_ECX + 0x54);
          pfVar7 = pfVar10;
        }
        else {
          pfVar10 = *(float **)(in_ECX + 0x54) + iVar1 * 0x11;
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        fVar12 = ABS(*pfVar10 - *(float *)(in_ECX + 0xc));
        if (0.1 < fVar12) {
          fVar12 = 0.1;
        }
        fVar12 = (0.1 - fVar12) * 8.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = pfVar7 + iVar1 * 0x11;
        }
        iVar2 = 0x10 - (int)pfVar7[0xb];
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        if (5 < iVar2) {
          iVar2 = 5;
        }
        iVar8 = (int)ROUND((float)iVar2 * fVar12);
        uVar9 = iVar8 * -0x14;
        DAT_00772dd8 = (uint)ROUND(fVar12);
        iVar2 = uVar9 + 0xff;
        uVar3 = iVar8 * 0x1e;
        if (0xff < (int)uVar9) {
          uVar9 = local_40;
        }
        if ((int)uVar9 < 0) {
          uVar9 = 0;
        }
        if (0xff < (int)uVar3) {
          uVar3 = 0xff;
        }
        if ((int)uVar3 < 0) {
          uVar3 = 0;
        }
        if (0xff < iVar2) {
          iVar2 = 0xff;
        }
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        *(uint *)(iVar8 + 0x38) = (uVar9 << 8 | uVar9) << 8 | uVar3;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        fVar12 = ((float)*(int *)(iVar8 + 0x2c) - 16.0) * 0.0625;
        if (0.0 <= fVar12) {
          if (1.0 < fVar12) {
            fVar12 = 1.0;
          }
        }
        else {
          fVar12 = 0.0;
        }
        fVar13 = (float)iVar2 * (1.0 - fVar12);
        uVar3 = (uint)ROUND((1.0 - fVar12) * 255.0);
        DAT_00772dd8 = uVar3;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        *(uint *)(iVar2 + 0x34) = ((int)ROUND(fVar13) << 8 | (int)ROUND(fVar13)) << 8 | uVar3;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        *(int *)(iVar2 + 0x2c) = *(int *)(iVar2 + 0x2c) + 1;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar2 + 0x2c) < 0x20) {
          fVar12 = *(float *)(in_ECX + 0x60);
          if (fVar12 != 0.0) {
            if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar10 = *(float **)(in_ECX + 0x54);
              fVar12 = *(float *)(in_ECX + 0x60);
            }
            else {
              pfVar10 = (float *)(iVar8 + iVar1 * 0x44);
            }
            fVar11 = *(float *)(in_ECX + 0x10) - pfVar10[1];
            fVar16 = *(float *)(in_ECX + 0xc) - *pfVar10;
            fVar13 = *(float *)(in_ECX + 0x14) - pfVar10[2];
            if (fVar12 < fVar11 * fVar11 + fVar16 * fVar16 + fVar13 * fVar13) goto LAB_004a2d0d;
          }
        }
        else {
LAB_004a2d0d:
          FUN_00493010(iVar1);
        }
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

