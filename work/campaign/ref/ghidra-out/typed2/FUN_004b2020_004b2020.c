
void FUN_004b2020(uint param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  int in_ECX;
  int iVar12;
  byte *pbVar13;
  float fVar14;
  double dVar15;
  float in_XMM2_Da;
  float fVar16;
  int local_34;
  float *local_2c;
  int local_28;
  
  iVar5 = DAT_00767980 * 0x343fd + 0x269ec3;
  iVar6 = iVar5 * 0x343fd + 0x269ec3;
  DAT_00767980 = iVar6 * 0x343fd + 0x269ec3;
  uVar7 = DAT_00767980 >> 0x10;
  *(float *)(in_ECX + 0x24) =
       (*(float *)(in_ECX + 0x24) + (float)(int)((iVar5 >> 0x10 & 0xfU) - 8) / 6200.0) * 0.98;
  *(float *)(in_ECX + 0x28) =
       (*(float *)(in_ECX + 0x28) + (float)(int)((iVar6 >> 0x10 & 0xfU) - 8) / 5500.0) * 0.98;
  *(float *)(in_ECX + 0x2c) =
       (*(float *)(in_ECX + 0x2c) + (float)(int)((uVar7 & 0xf) - 8) / 6200.0) * 0.98;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar5 = FUN_00592f10(PTR_0077241c);
      pbVar13 = (byte *)(iVar5 + 0x34);
      if (param_1 < 8) {
        pbVar13 = pbVar13 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar13 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar7 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar13 = (byte *)FUN_00423700(uVar7);
        if (*pbVar13 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar7 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar13 = (byte *)FUN_00423700(uVar7);
          if (*pbVar13 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar13 = (byte *)FUN_00423700(param_1);
            if (*pbVar13 < 0x81) goto LAB_004b28ce;
          }
        }
      }
    }
    local_28 = 0;
    DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
    if (0 < (int)(*(int *)(in_ECX + 0x50) + -1 + (DAT_00767980 >> 0x10 & 0x7fffU) % 3)) {
      do {
        iVar5 = FUN_00492f80();
        iVar12 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar6 = iVar12 * 0x343fd + 0x269ec3;
        iVar8 = iVar6 * 0x343fd + 0x269ec3;
        fVar14 = *(float *)(in_ECX + 0x18);
        DAT_00767980 = iVar8 * 0x343fd + 0x269ec3;
        fVar16 = *(float *)(in_ECX + 0x1c);
        fVar1 = *(float *)(in_ECX + 0x20);
        uVar7 = DAT_00767980 >> 0x10;
        fVar2 = *(float *)(in_ECX + 0xc);
        fVar3 = *(float *)(in_ECX + 0x10);
        fVar4 = *(float *)(in_ECX + 0x14);
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar9 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar9 = (float *)(*(int *)(in_ECX + 0x54) + iVar5 * 0x44);
        }
        iVar11 = iVar5 * 0x44;
        *pfVar9 = fVar2 + ((float)(iVar6 >> 0x10 & 0x7fff) * 3.0517578e-05 * fVar14 - fVar14 * 0.5);
        pfVar9[2] = fVar4 + ((float)(uVar7 & 0x7fff) * 3.0517578e-05 * fVar1 - fVar1 * 0.5);
        pfVar9[1] = fVar3 + -(float)(iVar8 >> 0x10 & 0x7fff) * 3.0517578e-05 * fVar16;
        iVar6 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar8 = iVar6 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar8 * 0x343fd + 0x269ec3;
        uVar7 = DAT_00767980 >> 0x10;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar10 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar10 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(float *)(iVar10 + 0xc) = (float)(iVar6 >> 0x10 & 0x7fff) * 3.0517578e-05 * 0.05 - 0.025;
        *(float *)(iVar10 + 0x10) = (float)(iVar8 >> 0x10 & 0x7fff) * 3.0517578e-05 * 0.05 - 0.025;
        *(float *)(iVar10 + 0x14) = (float)(uVar7 & 0x7fff) * 3.0517578e-05 * 0.05 - 0.025;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar7 = DAT_00767980 >> 0x10;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(float *)(iVar6 + 0x28) = ((float)(uVar7 & 0x7fff) / 16847.0) * 1.8;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar7 = DAT_00767980 >> 0x10;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(uint *)(iVar6 + 0x2c) = uVar7 & 0x1f;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(float *)(iVar6 + 0x30) = ((float)((iVar12 >> 0x10 & 0x7fffU) % 0x168) / 180.0) * 3.1415927
        ;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(undefined4 *)(iVar6 + 0x34) = 0xffb29567;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(undefined4 *)(iVar6 + 0x38) = 0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar7 = DAT_00767980 >> 0x10;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(uint *)(iVar6 + 0x3c) = (uVar7 & 0x7fff) % 3 + 0x10000;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(undefined1 *)(iVar11 + 0x40) = 0;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar9 = *(float **)(in_ECX + 0x54);
          local_2c = pfVar9;
        }
        else {
          pfVar9 = *(float **)(in_ECX + 0x54) + iVar5 * 0x11;
          local_2c = *(float **)(in_ECX + 0x54);
        }
        fVar14 = pfVar9[2] - *(float *)(in_ECX + 0x14);
        fVar16 = *pfVar9 - *(float *)(in_ECX + 0xc);
        dVar15 = (double)(fVar14 * fVar14 + fVar16 * fVar16);
        if (dVar15 < 0.0) {
          __libm_sse2_sqrt_precise();
        }
        else {
          dVar15 = SQRT(dVar15);
        }
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_2c = *(float **)(in_ECX + 0x54);
        }
        else {
          local_2c = local_2c + iVar5 * 0x11;
        }
        local_2c[6] = ((float)dVar15 / 100.0) * fVar16;
        local_2c[7] = 0.0;
        local_2c[8] = ((float)dVar15 / 100.0) * fVar14;
        local_28 = local_28 + 1;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
      } while (local_28 < (int)(*(int *)(in_ECX + 0x50) + -1 + (DAT_00767980 >> 0x10 & 0x7fffU) % 3)
              );
    }
  }
LAB_004b28ce:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar5 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_34 = 0;
    do {
      if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = *(int *)(in_ECX + 0x54);
        iVar8 = iVar6;
      }
      else {
        iVar6 = *(int *)(in_ECX + 0x54);
        iVar8 = iVar6 + local_34;
      }
      if (*(int *)(iVar8 + 0x2c) != -10000) {
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar6;
        }
        else {
          iVar8 = local_34 + iVar6;
        }
        if (0.0 < *(float *)(iVar8 + 0x30) || *(float *)(iVar8 + 0x30) == 0.0) {
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = iVar6 + local_34;
          }
          fVar14 = in_XMM2_Da * 0.01 + *(float *)(iVar6 + 0x30);
        }
        else {
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = iVar6 + local_34;
          }
          fVar14 = *(float *)(iVar6 + 0x30) - in_XMM2_Da * 0.01;
        }
        *(float *)(iVar6 + 0x30) = fVar14;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + local_34;
        }
        *(int *)(iVar6 + 0x2c) = *(int *)(iVar6 + 0x2c) + 1;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar6;
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + local_34;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar6 + 0x2c) < 0x31) {
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = local_34 + iVar8;
          }
          *(float *)(iVar8 + 0x28) = *(float *)(iVar8 + 0x28) * 1.03;
        }
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar6;
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + local_34;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar9 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar9 = (float *)(local_34 + iVar8);
        }
        *pfVar9 = *(float *)(iVar6 + 0xc) + *pfVar9;
        pfVar9[1] = *(float *)(iVar6 + 0x10) + pfVar9[1];
        pfVar9[2] = *(float *)(iVar6 + 0x14) + pfVar9[2];
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + local_34;
        }
        if (0x3f < *(int *)(iVar6 + 0x2c)) {
          FUN_00493010(iVar5);
        }
      }
      iVar5 = iVar5 + 1;
      local_34 = local_34 + 0x44;
    } while (iVar5 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

