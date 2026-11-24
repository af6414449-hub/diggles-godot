
void FUN_004b9dc0(uint param_1)

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
  float *pfVar9;
  uint uVar10;
  float fVar11;
  float fVar12;
  double dVar13;
  double dVar14;
  float fVar15;
  float in_XMM2_Da;
  float fVar16;
  int local_44;
  int local_38;
  int local_34;
  
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
            if (*pbVar4 < 0x81) goto LAB_004ba529;
          }
        }
      }
    }
    local_34 = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar1 = FUN_00492f80();
        iVar8 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar2 = iVar8 * 0x343fd + 0x269ec3;
        fVar15 = ((float)((iVar8 >> 0x10 & 0x7fffU) % 0x168) / 180.0) * 3.1415927;
        DAT_00767980 = iVar2 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        fVar16 = (float)((iVar2 >> 0x10 & 0x7fffU) % 100) / 380.0;
        dVar13 = (double)fVar15;
        FUN_006f6ad0();
        fVar11 = *(float *)(in_ECX + 0xc);
        fVar12 = *(float *)(in_ECX + 0x10);
        dVar14 = (double)fVar15;
        FUN_006f5ae0();
        fVar15 = *(float *)(in_ECX + 0x14);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar9 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar9 = (float *)(*(int *)(in_ECX + 0x54) + iVar1 * 0x44);
        }
        iVar2 = iVar1 * 0x44;
        *pfVar9 = (float)dVar13 * fVar16 + fVar11;
        pfVar9[1] = (float)((uVar3 & 0x7fff) % 10) / 200.0 + fVar12;
        iVar8 = DAT_00767980 * 0x343fd + 0x269ec3;
        pfVar9[2] = (float)dVar14 * fVar16 + fVar15;
        iVar5 = iVar8 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar5 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        fVar11 = *(float *)(in_ECX + 0x18);
        fVar12 = *(float *)(in_ECX + 0x1c);
        fVar15 = *(float *)(in_ECX + 0x20);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(float *)(iVar6 + 0xc) = fVar11 + (float)(int)((iVar8 >> 0x10 & 0xfU) - 8) / 800.0;
        *(float *)(iVar6 + 0x10) =
             fVar12 + -((float)((iVar5 >> 0x10 & 0x7fffU) % 10) / 600.0 + 0.006);
        *(float *)(iVar6 + 0x14) = fVar15 + (float)(int)((uVar3 & 0xf) - 8) / 800.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined4 *)(iVar8 + 0x28) = 0x3fe66666;
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
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(float *)(iVar8 + 0x30) = (float)(uVar3 & 0x7fff) / 5215.0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(uint *)(iVar8 + 0x3c) = (uVar3 & 0x7fff) % 3;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar2;
        }
        *(undefined1 *)(iVar2 + 0x40) = 0;
        local_34 = local_34 + 1;
      } while (local_34 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004ba529:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar1 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_38 = 0xff;
    local_44 = 0;
    do {
      if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar2 = *(int *)(in_ECX + 0x54);
        iVar8 = iVar2;
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x54);
        iVar8 = local_44 + iVar2;
      }
      if (*(int *)(iVar8 + 0x2c) != -10000) {
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar2;
        }
        else {
          iVar8 = iVar2 + local_44;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar9 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar9 = (float *)(iVar2 + local_44);
        }
        *pfVar9 = *(float *)(iVar8 + 0xc) + *pfVar9;
        pfVar9[1] = *(float *)(iVar8 + 0x10) + pfVar9[1];
        pfVar9[2] = *(float *)(iVar8 + 0x14) + pfVar9[2];
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar9 = *(float **)(in_ECX + 0x54);
          pfVar7 = pfVar9;
        }
        else {
          pfVar9 = (float *)(local_44 + (int)*(float **)(in_ECX + 0x54));
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        fVar11 = *pfVar9;
        fVar12 = *(float *)(in_ECX + 0xc);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = (float *)((int)pfVar7 + local_44);
        }
        *pfVar7 = (fVar12 * 8.0 + fVar11 * 92.0) / 100.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar8 = local_44 + iVar2;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = iVar2 + local_44;
        }
        *(float *)(iVar2 + 8) =
             (*(float *)(iVar8 + 8) * 92.0 + *(float *)(in_ECX + 0x14) * 8.0) / 100.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_44;
        }
        *(float *)(iVar2 + 0x30) = in_XMM2_Da * 0.2 + *(float *)(iVar2 + 0x30);
        fVar11 = *(float *)(in_ECX + 0x24);
        fVar12 = *(float *)(in_ECX + 0x2c);
        fVar15 = *(float *)(in_ECX + 0x28);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_44;
        }
        *(float *)(iVar2 + 0xc) = *(float *)(iVar2 + 0xc) + fVar11 * 0.1 * in_XMM2_Da;
        *(float *)(iVar2 + 0x14) = fVar12 * 0.1 * in_XMM2_Da + *(float *)(iVar2 + 0x14);
        *(float *)(iVar2 + 0x10) = *(float *)(iVar2 + 0x10) + fVar15 * 0.1 * in_XMM2_Da;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_44;
        }
        if (*(int *)(iVar2 + 0x2c) < 0x10) {
          DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
          uVar3 = DAT_00767980 >> 0x10;
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar2 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar2 = *(int *)(in_ECX + 0x54) + local_44;
          }
          *(float *)(iVar2 + 0x10) =
               ((float)(uVar3 & 0x7fff) + 32768.0) * -0.0008 * 1.5258789e-05 +
               *(float *)(iVar2 + 0x10);
          *(float *)(iVar2 + 0xc) = *(float *)(iVar2 + 0xc) + 0.0;
          *(float *)(iVar2 + 0x14) = *(float *)(iVar2 + 0x14) + 0.0;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_44;
        }
        *(undefined4 *)(iVar2 + 0x34) = 0xffffffff;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_44;
        }
        *(undefined4 *)(iVar2 + 0x38) = 0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar9 = *(float **)(in_ECX + 0x54);
          pfVar7 = pfVar9;
        }
        else {
          pfVar9 = (float *)(local_44 + (int)*(float **)(in_ECX + 0x54));
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        fVar11 = ABS(*pfVar9 - *(float *)(in_ECX + 0xc));
        if (0.1 < fVar11) {
          fVar11 = 0.1;
        }
        fVar11 = (0.1 - fVar11) * 8.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = (int)pfVar7 + local_44;
        }
        iVar2 = 0x10 - *(int *)(iVar2 + 0x2c);
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        if (5 < iVar2) {
          iVar2 = 5;
        }
        uVar10 = (int)ROUND((float)iVar2 * fVar11) * -0x14;
        DAT_00772dd8 = (uint)ROUND(fVar11);
        uVar3 = uVar10;
        if (0xff < (int)uVar10) {
          uVar3 = 0xff;
        }
        if ((int)uVar3 < 0) {
          uVar3 = 0;
        }
        iVar2 = uVar10 + 0xff;
        if (0xff < (int)(uVar10 + 0xff)) {
          iVar2 = local_38;
        }
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + local_44;
        }
        *(uint *)(iVar8 + 0x38) = (uVar3 << 8 | uVar3) << 8 | 0xff;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + local_44;
        }
        fVar11 = ((float)*(int *)(iVar8 + 0x2c) - 16.0) * 0.0625;
        if (0.0 <= fVar11) {
          if (1.0 < fVar11) {
            fVar11 = 1.0;
          }
        }
        else {
          fVar11 = 0.0;
        }
        fVar12 = (float)iVar2 * (1.0 - fVar11);
        uVar3 = (uint)ROUND((1.0 - fVar11) * 255.0);
        DAT_00772dd8 = uVar3;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_44;
        }
        *(uint *)(iVar2 + 0x34) = ((int)ROUND(fVar12) << 8 | (int)ROUND(fVar12)) << 8 | uVar3;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_44;
        }
        *(int *)(iVar2 + 0x2c) = *(int *)(iVar2 + 0x2c) + 1;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_44;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar2 + 0x2c) < 0x20) {
          fVar11 = *(float *)(in_ECX + 0x60);
          if (fVar11 != 0.0) {
            if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar9 = *(float **)(in_ECX + 0x54);
              fVar11 = *(float *)(in_ECX + 0x60);
            }
            else {
              pfVar9 = (float *)(iVar8 + local_44);
            }
            fVar16 = *(float *)(in_ECX + 0x10) - pfVar9[1];
            fVar15 = *(float *)(in_ECX + 0xc) - *pfVar9;
            fVar12 = *(float *)(in_ECX + 0x14) - pfVar9[2];
            if (fVar11 < fVar16 * fVar16 + fVar15 * fVar15 + fVar12 * fVar12) goto LAB_004bac85;
          }
        }
        else {
LAB_004bac85:
          FUN_00493010(iVar1);
        }
      }
      iVar1 = iVar1 + 1;
      local_44 = local_44 + 0x44;
    } while (iVar1 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

