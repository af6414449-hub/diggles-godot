
void FUN_004b81d0(uint param_1)

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
  int in_ECX;
  float *pfVar11;
  uint uVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float in_XMM2_Da;
  float fVar16;
  int local_20;
  int local_1c;
  int local_14;
  
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
            if (*pbVar5 < 0x81) goto LAB_004b89cc;
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
    local_1c = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      local_20 = 0;
      do {
        iVar2 = FUN_00492f80();
        if ((*(int *)(in_ECX + 0x70) == -1) || (*(int *)(in_ECX + 0x7c) <= local_1c)) {
          fVar16 = *(float *)(in_ECX + 0x14);
          fVar14 = *(float *)(in_ECX + 0x10);
          fVar15 = *(float *)(in_ECX + 0xc);
        }
        else if ((local_1c < 0) || (*(int *)(in_ECX + 0x7c) <= local_1c)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x78);
          fVar16 = pfVar7[2];
          fVar14 = pfVar7[1];
          fVar15 = *pfVar7;
        }
        else {
          pfVar7 = (float *)(*(int *)(in_ECX + 0x78) + local_20);
          fVar16 = pfVar7[2];
          fVar14 = pfVar7[1];
          fVar15 = *pfVar7;
        }
        iVar3 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar8 = iVar3 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar8 * 0x343fd + 0x269ec3;
        uVar4 = DAT_00767980 >> 0x10;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = (float *)(*(int *)(in_ECX + 0x54) + iVar2 * 0x44);
        }
        iVar10 = iVar2 * 0x44;
        *pfVar7 = fVar15 + (float)(int)((iVar3 >> 0x10 & 0xfU) - 8) / 800.0;
        pfVar7[1] = fVar14 + -((float)((iVar8 >> 0x10 & 0x7fffU) % 10) / 600.0 + 0.008);
        pfVar7[2] = fVar16 + (float)(int)((uVar4 & 0xf) - 8) / 800.0;
        iVar3 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar8 = iVar3 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar8 * 0x343fd + 0x269ec3;
        uVar4 = DAT_00767980 >> 0x10;
        fVar16 = *(float *)(in_ECX + 0x18);
        fVar14 = *(float *)(in_ECX + 0x1c);
        fVar15 = *(float *)(in_ECX + 0x20);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar10;
        }
        *(float *)(iVar9 + 0x14) = fVar15 + (float)(int)((uVar4 & 0xf) - 8) / 800.0;
        *(float *)(iVar9 + 0x10) =
             fVar14 + -((float)((iVar8 >> 0x10 & 0x7fffU) % 10) / 600.0 + 0.008);
        *(float *)(iVar9 + 0xc) = fVar16 + (float)(int)((iVar3 >> 0x10 & 0xfU) - 8) / 800.0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        fVar16 = *(float *)(in_ECX + 0x18);
        fVar14 = *(float *)(in_ECX + 0x20);
        fVar13 = (float)(DAT_00767980 >> 0x10 & 0x7fff);
        fVar15 = *(float *)(in_ECX + 0x1c);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = (float *)(*(int *)(in_ECX + 0x54) + iVar10);
        }
        *pfVar7 = *pfVar7 + fVar16 * fVar13 * 3.0517578e-05;
        pfVar7[1] = fVar15 * fVar13 * 3.0517578e-05 + pfVar7[1];
        pfVar7[2] = pfVar7[2] + fVar14 * fVar13 * 3.0517578e-05;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar10;
        }
        *(undefined4 *)(iVar3 + 0x28) = 0x3f933333;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar10;
        }
        *(undefined4 *)(iVar3 + 0x2c) = 0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar10;
        }
        *(undefined4 *)(iVar3 + 0x34) = 0xffffffff;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar10;
        }
        *(undefined4 *)(iVar3 + 0x38) = 0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar10;
        }
        *(undefined4 *)(iVar3 + 0x30) = 0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar4 = DAT_00767980 >> 0x10;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar10;
        }
        *(uint *)(iVar3 + 0x3c) = ((uVar4 & 0x7fff) % 3) * 0x10000;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar10 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar10 = *(int *)(in_ECX + 0x54) + iVar10;
        }
        local_20 = local_20 + 0xc;
        *(undefined1 *)(iVar10 + 0x40) = 0;
        local_1c = local_1c + 1;
      } while (local_1c < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004b89cc:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar2 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_14 = 0;
    do {
      if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar3 = *(int *)(in_ECX + 0x54);
        iVar8 = iVar3;
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x54);
        iVar8 = local_14 + iVar3;
      }
      if (*(int *)(iVar8 + 0x2c) != -10000) {
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar3;
        }
        else {
          iVar8 = local_14 + iVar3;
        }
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = (float *)(iVar3 + local_14);
        }
        *pfVar7 = *pfVar7 + *(float *)(iVar8 + 0xc);
        pfVar7[1] = *(float *)(iVar8 + 0x10) + pfVar7[1];
        pfVar7[2] = *(float *)(iVar8 + 0x14) + pfVar7[2];
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar3;
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar8 = local_14 + iVar3;
        }
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar10 = iVar3;
        }
        else {
          iVar10 = local_14 + iVar3;
        }
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar3;
        }
        else {
          iVar9 = local_14 + iVar3;
        }
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = local_14 + iVar3;
        }
        iVar10 = *(int *)(iVar9 + 0x2c) * *(int *)(iVar10 + 0x2c);
        iVar10 = 0x1f - ((int)((iVar10 >> 0x1f & 0x1fU) + iVar10) >> 5);
        *(uint *)(iVar3 + 0x3c) =
             (int)(iVar10 + (iVar10 >> 0x1f & 3U)) >> 2 | *(uint *)(iVar8 + 0x3c) & 0xffff0000;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(float *)(iVar3 + 0x30) = in_XMM2_Da * 0.2 + *(float *)(iVar3 + 0x30);
        fVar16 = *(float *)(in_ECX + 0x24);
        fVar14 = *(float *)(in_ECX + 0x28);
        fVar15 = *(float *)(in_ECX + 0x2c);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(float *)(iVar3 + 0xc) = *(float *)(iVar3 + 0xc) + fVar16 * 0.1 * in_XMM2_Da;
        *(float *)(iVar3 + 0x10) = *(float *)(iVar3 + 0x10) + fVar14 * 0.1 * in_XMM2_Da;
        *(float *)(iVar3 + 0x14) = *(float *)(iVar3 + 0x14) + fVar15 * 0.1 * in_XMM2_Da;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + local_14;
        }
        if (*(int *)(iVar3 + 0x2c) < 6) {
          DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
          uVar4 = DAT_00767980 >> 0x10;
          if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar3 = *(int *)(in_ECX + 0x54) + local_14;
          }
          *(float *)(iVar3 + 0x10) =
               ((float)(uVar4 & 0x7fff) + 32768.0) * -0.0008 * 1.5258789e-05 +
               *(float *)(iVar3 + 0x10);
          *(float *)(iVar3 + 0xc) = *(float *)(iVar3 + 0xc) + 0.0;
          *(float *)(iVar3 + 0x14) = *(float *)(iVar3 + 0x14) + 0.0;
        }
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(undefined4 *)(iVar3 + 0x34) = 0xffffffff;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(undefined4 *)(iVar3 + 0x38) = 0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
          pfVar11 = pfVar7;
        }
        else {
          pfVar7 = (float *)(local_14 + (int)*(float **)(in_ECX + 0x54));
          pfVar11 = *(float **)(in_ECX + 0x54);
        }
        fVar14 = ABS(*pfVar7 - *(float *)(in_ECX + 0xc));
        fVar16 = 0.1;
        if (fVar14 <= 0.1) {
          fVar16 = fVar14;
        }
        fVar16 = (0.1 - fVar16) * 8.0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = local_14 + (int)pfVar11;
        }
        iVar3 = 0x10 - *(int *)(iVar3 + 0x2c);
        if (iVar3 < 0) {
          iVar3 = 0;
        }
        if (5 < iVar3) {
          iVar3 = 5;
        }
        iVar3 = (int)ROUND((float)iVar3 * fVar16);
        fVar16 = fVar16 * 0.0;
        fVar14 = fVar16 - (float)(iVar3 * 0x14);
        iVar8 = (int)ROUND(fVar14);
        uVar4 = (uint)ROUND(fVar14);
        DAT_00772dd8 = (uint)ROUND((float)(iVar3 * 0x1e) + fVar16);
        iVar3 = iVar3 * -0x14 + 0xff;
        if (0xff < iVar8) {
          iVar8 = 0xff;
        }
        if (iVar8 < 0) {
          iVar8 = 0;
        }
        if (0xff < (int)uVar4) {
          uVar4 = 0xff;
        }
        if ((int)uVar4 < 0) {
          uVar4 = 0;
        }
        uVar12 = DAT_00772dd8;
        if (0xff < (int)DAT_00772dd8) {
          uVar12 = 0xff;
        }
        if ((int)uVar12 < 0) {
          uVar12 = 0;
        }
        if (0xff < iVar3) {
          iVar3 = 0xff;
        }
        if (iVar3 < 0) {
          iVar3 = 0;
        }
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar10 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar10 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(uint *)(iVar10 + 0x38) = (iVar8 << 8 | uVar4) << 8 | uVar12;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + local_14;
        }
        fVar14 = ((float)*(int *)(iVar8 + 0x2c) - 16.0) * 0.0625;
        fVar16 = 0.0;
        if (0.0 <= fVar14) {
          fVar16 = fVar14;
        }
        fVar14 = 1.0;
        if (fVar16 <= 1.0) {
          fVar14 = fVar16;
        }
        fVar16 = (float)iVar3 * (1.0 - fVar14);
        uVar4 = (uint)ROUND((1.0 - fVar14) * 255.0);
        DAT_00772dd8 = uVar4;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(uint *)(iVar3 + 0x34) = ((int)ROUND(fVar16) << 8 | (int)ROUND(fVar16)) << 8 | uVar4;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(int *)(iVar3 + 0x2c) = *(int *)(iVar3 + 0x2c) + 1;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar3;
        }
        else {
          iVar3 = local_14 + *(int *)(in_ECX + 0x54);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar3 + 0x2c) < 0x20) {
          fVar16 = *(float *)(in_ECX + 0x60);
          if (fVar16 != 0.0) {
            if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar7 = *(float **)(in_ECX + 0x54);
              fVar16 = *(float *)(in_ECX + 0x60);
            }
            else {
              pfVar7 = (float *)(local_14 + iVar8);
            }
            fVar13 = *(float *)(in_ECX + 0x10) - pfVar7[1];
            fVar15 = *(float *)(in_ECX + 0xc) - *pfVar7;
            fVar14 = *(float *)(in_ECX + 0x14) - pfVar7[2];
            if (fVar16 < fVar13 * fVar13 + fVar15 * fVar15 + fVar14 * fVar14) goto LAB_004b9122;
          }
        }
        else {
LAB_004b9122:
          FUN_00493010(iVar2);
        }
      }
      iVar2 = iVar2 + 1;
      local_14 = local_14 + 0x44;
    } while (iVar2 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

