
void FUN_004a2d30(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  int in_ECX;
  int iVar9;
  float *pfVar10;
  double dVar11;
  double dVar12;
  float fVar13;
  float fVar14;
  float in_XMM2_Da;
  float fVar15;
  float fVar16;
  int local_34;
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
            if (*pbVar4 < 0x81) goto LAB_004a3448;
          }
        }
      }
    }
    local_30 = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar1 = FUN_00492f80();
        iVar9 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar2 = iVar9 * 0x343fd + 0x269ec3;
        fVar14 = ((float)((iVar9 >> 0x10 & 0x7fffU) % 0x168) / 180.0) * 3.1415927;
        DAT_00767980 = iVar2 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        fVar16 = (float)((iVar2 >> 0x10 & 0x7fffU) % 100) / 180.0;
        dVar11 = (double)fVar14;
        FUN_006f6ad0();
        fVar15 = *(float *)(in_ECX + 0xc);
        fVar13 = *(float *)(in_ECX + 0x10);
        dVar12 = (double)fVar14;
        FUN_006f5ae0();
        fVar14 = *(float *)(in_ECX + 0x14);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar10 = (float *)(*(int *)(in_ECX + 0x54) + iVar1 * 0x44);
        }
        iVar2 = iVar1 * 0x44;
        *pfVar10 = (float)dVar11 * fVar16 + fVar15;
        pfVar10[1] = (float)((uVar3 & 0x7fff) % 10) / 200.0 + fVar13;
        iVar9 = DAT_00767980 * 0x343fd + 0x269ec3;
        pfVar10[2] = (float)dVar12 * fVar16 + fVar14;
        iVar5 = iVar9 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar5 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        fVar15 = *(float *)(in_ECX + 0x18);
        fVar13 = *(float *)(in_ECX + 0x1c);
        fVar14 = *(float *)(in_ECX + 0x20);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(float *)(iVar6 + 0xc) = fVar15 + (float)(int)((iVar9 >> 0x10 & 0xfU) - 8) / 800.0;
        *(float *)(iVar6 + 0x10) =
             fVar13 + -((float)((iVar5 >> 0x10 & 0x7fffU) % 10) / 130.0 + 0.006);
        *(float *)(iVar6 + 0x14) = fVar14 + (float)(int)((uVar3 & 0xf) - 8) / 800.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar9 + 0x28) = 0x4009999a;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar9 + 0x2c) = 0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar9 + 0x34) = 0xffffffff;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar9 + 0x38) = 0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar9 + 0x30) = 0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_34 = *(int *)(in_ECX + 0x54);
        }
        else {
          local_34 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(uint *)(local_34 + 0x3c) = (uVar3 & 3) << 0x10;
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
LAB_004a3448:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar1 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    do {
      if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar2 = *(int *)(in_ECX + 0x54);
        iVar9 = iVar2;
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        iVar9 = *(int *)(in_ECX + 0x54);
      }
      if (*(int *)(iVar2 + 0x2c) != -10000) {
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar2;
        }
        else {
          iVar2 = iVar9 + iVar1 * 0x44;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar10 = (float *)(iVar9 + iVar1 * 0x44);
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
        fVar15 = *pfVar10;
        fVar13 = *(float *)(in_ECX + 0xc);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = pfVar7 + iVar1 * 0x11;
        }
        *pfVar7 = (fVar13 * 8.0 + fVar15 * 92.0) / 100.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = iVar9 + iVar1 * 0x44;
        }
        *(float *)(iVar9 + 8) =
             (*(float *)(iVar2 + 8) * 92.0 + *(float *)(in_ECX + 0x14) * 8.0) / 100.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar5;
        }
        else {
          iVar5 = iVar9 + iVar1 * 0x44;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar6;
        }
        else {
          iVar6 = iVar9 + iVar1 * 0x44;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = iVar9 + iVar1 * 0x44;
        }
        iVar5 = *(int *)(iVar6 + 0x2c) * *(int *)(iVar5 + 0x2c);
        iVar5 = 0x1f - ((int)((iVar5 >> 0x1f & 0x1fU) + iVar5) >> 5);
        *(uint *)(iVar9 + 0x3c) =
             (int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2 | *(uint *)(iVar2 + 0x3c) & 0xffff0000;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        *(float *)(iVar2 + 0x30) = in_XMM2_Da * 0.2 + *(float *)(iVar2 + 0x30);
        fVar15 = *(float *)(in_ECX + 0x24);
        fVar13 = *(float *)(in_ECX + 0x28);
        fVar14 = *(float *)(in_ECX + 0x2c);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        *(float *)(iVar2 + 0xc) = *(float *)(iVar2 + 0xc) + fVar15 * 0.12 * in_XMM2_Da;
        *(float *)(iVar2 + 0x10) = fVar13 * 0.12 * in_XMM2_Da + *(float *)(iVar2 + 0x10);
        *(float *)(iVar2 + 0x14) = *(float *)(iVar2 + 0x14) + fVar14 * 0.12 * in_XMM2_Da;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        if (*(int *)(iVar2 + 0x2c) < 0x10) {
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
        fVar13 = ABS(*pfVar10 - *(float *)(in_ECX + 0xc));
        fVar15 = 0.1;
        if (fVar13 <= 0.1) {
          fVar15 = fVar13;
        }
        fVar15 = (0.1 - fVar15) * 8.0;
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
        iVar2 = (int)ROUND((float)iVar2 * fVar15);
        fVar15 = fVar15 * 0.0;
        fVar13 = fVar15 - (float)(iVar2 * 0x14);
        iVar9 = (int)ROUND(fVar13);
        uVar3 = (uint)ROUND(fVar13);
        DAT_00772dd8 = (uint)ROUND((float)(iVar2 * 0x1e) + fVar15);
        iVar2 = iVar2 * -0x14 + 0xff;
        if (0xff < iVar9) {
          iVar9 = 0xff;
        }
        if (iVar9 < 0) {
          iVar9 = 0;
        }
        if (0xff < (int)uVar3) {
          uVar3 = 0xff;
        }
        if ((int)uVar3 < 0) {
          uVar3 = 0;
        }
        uVar8 = DAT_00772dd8;
        if (0xff < (int)DAT_00772dd8) {
          uVar8 = 0xff;
        }
        if ((int)uVar8 < 0) {
          uVar8 = 0;
        }
        if (0xff < iVar2) {
          iVar2 = 0xff;
        }
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        *(uint *)(iVar5 + 0x38) = (iVar9 << 8 | uVar3) << 8 | uVar8;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        fVar13 = ((float)*(int *)(iVar9 + 0x2c) - 16.0) * 0.0625;
        fVar15 = 0.0;
        if (0.0 <= fVar13) {
          fVar15 = fVar13;
        }
        fVar13 = 1.0;
        if (fVar15 <= 1.0) {
          fVar13 = fVar15;
        }
        fVar15 = (float)iVar2 * (1.0 - fVar13);
        uVar3 = (uint)ROUND((1.0 - fVar13) * 255.0);
        DAT_00772dd8 = uVar3;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
        }
        *(uint *)(iVar2 + 0x34) = ((int)ROUND(fVar15) << 8 | (int)ROUND(fVar15)) << 8 | uVar3;
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
          iVar9 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar1 * 0x44;
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar2 + 0x2c) < 0x20) {
          fVar15 = *(float *)(in_ECX + 0x60);
          if (fVar15 != 0.0) {
            if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar10 = *(float **)(in_ECX + 0x54);
              fVar15 = *(float *)(in_ECX + 0x60);
            }
            else {
              pfVar10 = (float *)(iVar9 + iVar1 * 0x44);
            }
            fVar16 = *(float *)(in_ECX + 0x10) - pfVar10[1];
            fVar14 = *(float *)(in_ECX + 0xc) - *pfVar10;
            fVar13 = *(float *)(in_ECX + 0x14) - pfVar10[2];
            if (fVar15 < fVar16 * fVar16 + fVar14 * fVar14 + fVar13 * fVar13) goto LAB_004a3d7c;
          }
        }
        else {
LAB_004a3d7c:
          FUN_00493010(iVar1);
        }
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

