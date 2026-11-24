
void FUN_004b9150(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  int in_ECX;
  undefined4 *puVar9;
  float *pfVar10;
  uint uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float in_XMM2_Da;
  float fVar15;
  int local_24;
  int local_20;
  int local_14;
  
  iVar1 = DAT_00767980 * 0x343fd + 0x269ec3;
  iVar2 = iVar1 * 0x343fd + 0x269ec3;
  DAT_00767980 = iVar2 * 0x343fd + 0x269ec3;
  uVar3 = DAT_00767980 >> 0x10;
  *(float *)(in_ECX + 0x28) =
       (*(float *)(in_ECX + 0x28) + (float)(int)((iVar2 >> 0x10 & 0xfU) - 8) / 9500.0) * 0.9;
  *(float *)(in_ECX + 0x24) =
       ((float)(int)((iVar1 >> 0x10 & 0xfU) - 8) / 8200.0 + *(float *)(in_ECX + 0x24)) * 0.9;
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
            if (*pbVar4 < 0x81) goto LAB_004b9758;
          }
        }
      }
    }
    local_20 = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar1 = FUN_00492f80();
        DAT_00767980 = (DAT_00767980 * 0x343fd + 0x269ec3) * 0x343fd + 0x269ec3;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar9 = *(undefined4 **)(in_ECX + 0x54);
        }
        else {
          puVar9 = (undefined4 *)(*(int *)(in_ECX + 0x54) + iVar1 * 0x44);
        }
        iVar2 = iVar1 * 0x44;
        *puVar9 = *(undefined4 *)(in_ECX + 0xc);
        puVar9[1] = *(undefined4 *)(in_ECX + 0x10);
        puVar9[2] = *(undefined4 *)(in_ECX + 0x14);
        iVar5 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar6 = iVar5 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar6 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        fVar12 = *(float *)(in_ECX + 0x18);
        fVar13 = *(float *)(in_ECX + 0x1c);
        fVar14 = *(float *)(in_ECX + 0x20);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(float *)(iVar7 + 0xc) = fVar12 + (float)(int)((iVar5 >> 0x10 & 0xfU) - 8) / 800.0;
        *(float *)(iVar7 + 0x10) =
             fVar13 + -((float)((iVar6 >> 0x10 & 0x7fffU) % 10) / 600.0 + 0.006);
        *(float *)(iVar7 + 0x14) = (float)(int)((uVar3 & 0xf) - 8) / 800.0 + fVar14;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar5 + 0x28) = 0x3e19999a;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar5 + 0x2c) = 0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar5 + 0x34) = 0xffffffff;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar5 + 0x38) = 0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        *(float *)(iVar5 + 0x30) = (float)(uVar3 & 0x7fff) / 5215.0;
        uVar3 = DAT_00767980 >> 0x10;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(uint *)(iVar5 + 0x3c) = (uVar3 & 0x7fff) % 3;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined1 *)(iVar2 + 0x40) = 0;
        local_20 = local_20 + 1;
      } while (local_20 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004b9758:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar1 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_24 = 0xff;
    local_14 = 0;
    do {
      if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar2 = *(int *)(in_ECX + 0x54);
        iVar5 = iVar2;
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x54);
        iVar5 = local_14 + iVar2;
      }
      if (*(int *)(iVar5 + 0x2c) != -10000) {
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar5 = iVar2;
        }
        else {
          iVar5 = local_14 + iVar2;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar8 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar8 = (float *)(iVar2 + local_14);
        }
        *pfVar8 = *(float *)(iVar5 + 0xc) + *pfVar8;
        pfVar8[1] = *(float *)(iVar5 + 0x10) + pfVar8[1];
        pfVar8[2] = *(float *)(iVar5 + 0x14) + pfVar8[2];
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(float *)(iVar2 + 0x30) = in_XMM2_Da * 0.2 + *(float *)(iVar2 + 0x30);
        fVar12 = *(float *)(in_ECX + 0x24);
        fVar13 = *(float *)(in_ECX + 0x28);
        fVar14 = *(float *)(in_ECX + 0x2c);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(float *)(iVar2 + 0xc) = *(float *)(iVar2 + 0xc) + fVar12 * 0.1 * in_XMM2_Da;
        *(float *)(iVar2 + 0x10) = *(float *)(iVar2 + 0x10) + fVar13 * 0.1 * in_XMM2_Da;
        *(float *)(iVar2 + 0x14) = *(float *)(iVar2 + 0x14) + fVar14 * 0.1 * in_XMM2_Da;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_14;
        }
        if (*(int *)(iVar2 + 0x2c) < 0x10) {
          DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
          uVar3 = DAT_00767980 >> 0x10;
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar2 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar2 = *(int *)(in_ECX + 0x54) + local_14;
          }
          *(float *)(iVar2 + 0xc) = *(float *)(iVar2 + 0xc) + 0.0;
          *(float *)(iVar2 + 0x10) =
               *(float *)(iVar2 + 0x10) +
               ((float)(uVar3 & 0x7fff) + 32768.0) * -0.0008 * 1.5258789e-05;
          *(float *)(iVar2 + 0x14) = *(float *)(iVar2 + 0x14) + 0.0;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(float *)(iVar2 + 0x28) = *(float *)(iVar2 + 0x28) + 0.071875;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(undefined4 *)(iVar2 + 0x34) = 0xffffffff;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(undefined4 *)(iVar2 + 0x38) = 0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar8 = *(float **)(in_ECX + 0x54);
          pfVar10 = pfVar8;
        }
        else {
          pfVar8 = (float *)(local_14 + (int)*(float **)(in_ECX + 0x54));
          pfVar10 = *(float **)(in_ECX + 0x54);
        }
        fVar12 = ABS(*pfVar8 - *(float *)(in_ECX + 0xc));
        if (0.1 < fVar12) {
          fVar12 = 0.1;
        }
        fVar12 = (0.1 - fVar12) * 8.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = (int)pfVar10 + local_14;
        }
        iVar2 = 0x10 - *(int *)(iVar2 + 0x2c);
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        if (5 < iVar2) {
          iVar2 = 5;
        }
        uVar11 = (int)ROUND((float)iVar2 * fVar12) * -0x14;
        DAT_00772dd8 = (uint)ROUND(fVar12);
        uVar3 = uVar11;
        if (0xff < (int)uVar11) {
          uVar3 = 0xff;
        }
        if ((int)uVar3 < 0) {
          uVar3 = 0;
        }
        iVar2 = uVar11 + 0xff;
        if (0xff < (int)(uVar11 + 0xff)) {
          iVar2 = local_24;
        }
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(uint *)(iVar5 + 0x38) = (uVar3 << 8 | uVar3) << 8 | 0xff;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + local_14;
        }
        fVar12 = ((float)*(int *)(iVar5 + 0x2c) - 16.0) * 0.0625;
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
          iVar2 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(uint *)(iVar2 + 0x34) = ((int)ROUND(fVar13) << 8 | (int)ROUND(fVar13)) << 8 | uVar3;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(int *)(iVar2 + 0x2c) = *(int *)(iVar2 + 0x2c) + 1;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar5 = iVar2;
        }
        else {
          iVar2 = local_14 + *(int *)(in_ECX + 0x54);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar2 + 0x2c) < 0x20) {
          fVar12 = *(float *)(in_ECX + 0x60);
          if (fVar12 != 0.0) {
            if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar8 = *(float **)(in_ECX + 0x54);
              fVar12 = *(float *)(in_ECX + 0x60);
            }
            else {
              pfVar8 = (float *)(local_14 + iVar5);
            }
            fVar15 = *(float *)(in_ECX + 0x10) - pfVar8[1];
            fVar14 = *(float *)(in_ECX + 0xc) - *pfVar8;
            fVar13 = *(float *)(in_ECX + 0x14) - pfVar8[2];
            if (fVar12 < fVar15 * fVar15 + fVar14 * fVar14 + fVar13 * fVar13) goto LAB_004b9d93;
          }
        }
        else {
LAB_004b9d93:
          FUN_00493010(iVar1);
        }
      }
      iVar1 = iVar1 + 1;
      local_14 = local_14 + 0x44;
    } while (iVar1 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

