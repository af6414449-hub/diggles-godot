
void FUN_004ab4d0(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int in_ECX;
  int iVar9;
  byte *pbVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float in_XMM2_Da;
  float fVar14;
  float fVar15;
  int local_14;
  float local_c;
  float local_8;
  
  iVar2 = DAT_00767980 * 0x343fd + 0x269ec3;
  iVar3 = iVar2 * 0x343fd + 0x269ec3;
  DAT_00767980 = iVar3 * 0x343fd + 0x269ec3;
  uVar4 = DAT_00767980 >> 0x10;
  *(float *)(in_ECX + 0x24) =
       (*(float *)(in_ECX + 0x24) + (float)(int)((iVar2 >> 0x10 & 0xfU) - 8) / 3200.0) * 0.98;
  *(float *)(in_ECX + 0x28) =
       (*(float *)(in_ECX + 0x28) + (float)(int)((iVar3 >> 0x10 & 0xfU) - 8) / 5500.0) * 0.98;
  *(float *)(in_ECX + 0x2c) =
       (*(float *)(in_ECX + 0x2c) + (float)(int)((uVar4 & 0xf) - 8) / 3200.0) * 0.98;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar2 = FUN_00592f10(PTR_0077241c);
      pbVar10 = (byte *)(iVar2 + 0x34);
      if (param_1 < 8) {
        pbVar10 = pbVar10 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar10 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar4 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar10 = (byte *)FUN_00423700(uVar4);
        if (*pbVar10 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar4 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar10 = (byte *)FUN_00423700(uVar4);
          if (*pbVar10 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar10 = (byte *)FUN_00423700(param_1);
            if (*pbVar10 < 0x81) goto LAB_004abc21;
          }
        }
      }
    }
    local_14 = 0;
    DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
    uVar4 = DAT_00767980 >> 0x10;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar2 = FUN_00492f80();
        iVar9 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar3 = iVar9 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar3 * 0x343fd + 0x269ec3;
        local_8 = (float)(iVar3 >> 0x10 & 0x7fff) * 3.0517578e-05 - 0.5;
        fVar15 = (float)(iVar9 >> 0x10 & 0x7fff) * 3.0517578e-05 - 0.5;
        local_c = (float)(DAT_00767980 >> 0x10 & 0x7fff) * 3.0517578e-05 - 0.5;
        fVar11 = local_8 * local_8 + fVar15 * fVar15 + local_c * local_c;
        FUN_0040b7e0();
        fVar12 = 0.0;
        if (fVar11 <= 0.0) {
          local_c = 0.0;
          local_8 = 0.0;
        }
        else {
          local_c = local_c / fVar11;
          local_8 = local_8 / fVar11;
          fVar12 = fVar15 / fVar11;
        }
        fVar11 = *(float *)(in_ECX + 0x18) * *(float *)(in_ECX + 0x18) +
                 *(float *)(in_ECX + 0x1c) * *(float *)(in_ECX + 0x1c) +
                 *(float *)(in_ECX + 0x20) * *(float *)(in_ECX + 0x20);
        FUN_0040b7e0();
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        fVar13 = (float)(DAT_00767980 >> 0x10 & 0x7fff) * fVar11 * 3.0517578e-05;
        fVar11 = *(float *)(in_ECX + 0x10);
        fVar15 = *(float *)(in_ECX + 0x14);
        fVar14 = *(float *)(in_ECX + 0xc);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar5 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar5 = (float *)(*(int *)(in_ECX + 0x54) + iVar2 * 0x44);
        }
        iVar3 = iVar2 * 0x44;
        *pfVar5 = fVar13 * fVar12 + fVar14;
        pfVar5[1] = fVar13 * local_8 + fVar11;
        pfVar5[2] = fVar13 * local_c + fVar15;
        iVar9 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar6 = iVar9 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar6 * 0x343fd + 0x269ec3;
        uVar7 = DAT_00767980 >> 0x10;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(float *)(iVar8 + 0xc) = (float)(int)((iVar9 >> 0x10 & 0xfU) - 8) / 500.0;
        *(float *)(iVar8 + 0x10) = (float)(int)((iVar6 >> 0x10 & 0xfU) - 0x10) / 500.0;
        *(float *)(iVar8 + 0x14) = (float)(int)((uVar7 & 0xf) - 8) / 500.0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar9 + 0x28) = 0x40000000;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar7 = DAT_00767980 >> 0x10;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(uint *)(iVar9 + 0x2c) = (uVar7 & 7) + (uVar4 & 0x7fff) % 0xc;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
          iVar6 = iVar9;
        }
        else {
          iVar9 = iVar3 + *(int *)(in_ECX + 0x54);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        uVar1 = *(undefined4 *)(iVar9 + 0xc);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = iVar3 + iVar6;
        }
        *(undefined4 *)(iVar6 + 0x30) = uVar1;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar9 + 0x34) = 0xffffffff;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar9 + 0x38) = 0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar7 = DAT_00767980 >> 0x10;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(uint *)(iVar9 + 0x3c) = (uVar7 & 3) * 0x10000 + 4;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined1 *)(iVar3 + 0x40) = 0;
        local_14 = local_14 + 1;
      } while (local_14 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004abc21:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar2 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    param_1 = 0;
    do {
      if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar3 = *(int *)(in_ECX + 0x54);
        iVar9 = iVar3;
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x54);
        iVar9 = param_1 + iVar3;
      }
      if (*(int *)(iVar9 + 0x2c) != -10000) {
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar3;
        }
        else {
          iVar9 = param_1 + iVar3;
        }
        fVar11 = *(float *)(iVar9 + 0xc);
        fVar12 = *(float *)(iVar9 + 0x10);
        fVar15 = *(float *)(iVar9 + 0x14);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar5 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar5 = (float *)(iVar3 + param_1);
        }
        *pfVar5 = *pfVar5 + fVar11 * in_XMM2_Da;
        pfVar5[1] = pfVar5[1] + fVar12 * in_XMM2_Da;
        pfVar5[2] = pfVar5[2] + fVar15 * in_XMM2_Da;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + param_1;
        }
        *(float *)(iVar3 + 0xc) = *(float *)(iVar3 + 0xc) * 0.98;
        *(float *)(iVar3 + 0x10) = *(float *)(iVar3 + 0x10) * 0.98;
        *(float *)(iVar3 + 0x14) = *(float *)(iVar3 + 0x14) * 0.98;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + param_1;
        }
        *(float *)(iVar3 + 0x28) = in_XMM2_Da * 0.015 + *(float *)(iVar3 + 0x28);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar3;
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar3 + param_1;
        }
        if (0.0 < *(float *)(iVar9 + 0x30) || *(float *)(iVar9 + 0x30) == 0.0) {
          if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar3 = iVar3 + param_1;
          }
          fVar11 = in_XMM2_Da * 0.002 + *(float *)(iVar3 + 0x30);
        }
        else {
          if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar3 = iVar3 + param_1;
          }
          fVar11 = *(float *)(iVar3 + 0x30) - in_XMM2_Da * 0.002;
        }
        *(float *)(iVar3 + 0x30) = fVar11;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          local_14 = iVar3;
        }
        else {
          iVar3 = param_1 + *(int *)(in_ECX + 0x54);
          local_14 = *(int *)(in_ECX + 0x54);
        }
        iVar3 = 0x40 - *(int *)(iVar3 + 0x2c);
        uVar4 = iVar3 * 0x19;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_14 = *(int *)(in_ECX + 0x54);
        }
        else {
          local_14 = local_14 + param_1;
        }
        *(uint *)(local_14 + 0x38) = (iVar3 * 0x1900 | uVar4) << 8 | uVar4;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          local_14 = iVar3;
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + param_1;
          local_14 = *(int *)(in_ECX + 0x54);
        }
        iVar3 = *(int *)(iVar3 + 0x2c) + (*(int *)(iVar3 + 0x2c) >> 0x1f & 3U);
        uVar4 = iVar3 >> 2;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_14 = *(int *)(in_ECX + 0x54);
        }
        else {
          local_14 = local_14 + param_1;
        }
        uVar7 = uVar4 & 0x80000003;
        if ((int)uVar7 < 0) {
          uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
        }
        *(uint *)(local_14 + 0x3c) = ((int)(uVar4 + (iVar3 >> 0x1f & 3U)) >> 2) * 0x10000 + uVar7;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + param_1;
        }
        *(int *)(iVar3 + 0x2c) = *(int *)(iVar3 + 0x2c) + 1;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar3;
        }
        else {
          iVar3 = param_1 + *(int *)(in_ECX + 0x54);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar3 + 0x2c) < 0x40) {
          fVar11 = *(float *)(in_ECX + 0x60);
          if (fVar11 != 0.0) {
            if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar5 = *(float **)(in_ECX + 0x54);
              fVar11 = *(float *)(in_ECX + 0x60);
            }
            else {
              pfVar5 = (float *)(param_1 + iVar9);
            }
            fVar14 = *(float *)(in_ECX + 0x10) - pfVar5[1];
            fVar15 = *(float *)(in_ECX + 0xc) - *pfVar5;
            fVar12 = *(float *)(in_ECX + 0x14) - pfVar5[2];
            if (fVar11 < fVar14 * fVar14 + fVar15 * fVar15 + fVar12 * fVar12) goto LAB_004abff1;
          }
        }
        else {
LAB_004abff1:
          FUN_00493010(iVar2);
        }
      }
      iVar2 = iVar2 + 1;
      param_1 = param_1 + 0x44;
    } while (iVar2 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

