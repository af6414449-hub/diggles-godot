
void FUN_004b1480(uint param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  int in_ECX;
  int iVar10;
  int iVar11;
  float fVar12;
  double dVar13;
  float fVar14;
  float in_XMM2_Da;
  float fVar15;
  float fVar16;
  int local_40;
  float *local_34;
  int local_30;
  
  iVar3 = DAT_00767980 * 0x343fd + 0x269ec3;
  iVar4 = iVar3 * 0x343fd + 0x269ec3;
  DAT_00767980 = iVar4 * 0x343fd + 0x269ec3;
  uVar5 = DAT_00767980 >> 0x10;
  *(float *)(in_ECX + 0x24) =
       (*(float *)(in_ECX + 0x24) + (float)(int)((iVar3 >> 0x10 & 0xfU) - 8) / 6200.0) * 0.98;
  *(float *)(in_ECX + 0x28) =
       (*(float *)(in_ECX + 0x28) + (float)(int)((iVar4 >> 0x10 & 0xfU) - 8) / 5500.0) * 0.98;
  *(float *)(in_ECX + 0x2c) =
       (*(float *)(in_ECX + 0x2c) + (float)(int)((uVar5 & 0xf) - 8) / 6200.0) * 0.98;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar3 = FUN_00592f10(PTR_0077241c);
      pbVar6 = (byte *)(iVar3 + 0x34);
      if (param_1 < 8) {
        pbVar6 = pbVar6 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar6 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar5 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar6 = (byte *)FUN_00423700(uVar5);
        if (*pbVar6 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar5 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar6 = (byte *)FUN_00423700(uVar5);
          if (*pbVar6 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar6 = (byte *)FUN_00423700(param_1);
            if (*pbVar6 < 0x81) goto LAB_004b1cb6;
          }
        }
      }
    }
    local_30 = 0;
    iVar3 = DAT_00767980 * 0x343fd + 0x269ec3;
    DAT_00767980 = iVar3 * 0x343fd + 0x269ec3;
    if (0 < (int)(*(int *)(in_ECX + 0x50) + -1 + (DAT_00767980 >> 0x10 & 0x7fffU) % 3)) {
      do {
        iVar4 = FUN_00492f80();
        iVar10 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar7 = iVar10 * 0x343fd + 0x269ec3;
        iVar8 = iVar7 * 0x343fd + 0x269ec3;
        fVar12 = *(float *)(in_ECX + 0x18);
        fVar15 = *(float *)(in_ECX + 0x1c);
        DAT_00767980 = iVar8 * 0x343fd + 0x269ec3;
        uVar5 = DAT_00767980 >> 0x10;
        fVar14 = *(float *)(in_ECX + 0x20);
        fVar16 = *(float *)(in_ECX + 0xc);
        fVar1 = *(float *)(in_ECX + 0x10);
        fVar2 = *(float *)(in_ECX + 0x14);
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar9 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar9 = (float *)(*(int *)(in_ECX + 0x54) + iVar4 * 0x44);
        }
        iVar11 = iVar4 * 0x44;
        *pfVar9 = fVar16 + ((float)(iVar7 >> 0x10 & 0x7fff) * 3.0517578e-05 * fVar12 - fVar12 * 0.5)
        ;
        pfVar9[1] = fVar1 + fVar15 * -(float)(iVar8 >> 0x10 & 0x7fff) * 3.0517578e-05;
        pfVar9[2] = fVar2 + ((float)(uVar5 & 0x7fff) * 3.0517578e-05 * fVar14 - fVar14 * 0.5);
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(undefined4 *)(iVar7 + 0x14) = 0;
        *(undefined4 *)(iVar7 + 0x10) = 0;
        *(undefined4 *)(iVar7 + 0xc) = 0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar5 = DAT_00767980 >> 0x10;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(float *)(iVar7 + 0x28) = ((float)(uVar5 & 0x7fff) / 16847.0) * 1.8;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar5 = DAT_00767980 >> 0x10;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_34 = *(float **)(in_ECX + 0x54);
        }
        else {
          local_34 = (float *)(*(int *)(in_ECX + 0x54) + iVar11);
        }
        *(uint *)((int)local_34 + 0x2c) = (uVar5 & 7) + (iVar3 >> 0x10 & 0x7fffU) % 0xc;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(float *)(iVar7 + 0x30) = ((float)((iVar10 >> 0x10 & 0x7fffU) % 0x168) / 180.0) * 3.1415927
        ;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(undefined4 *)(iVar7 + 0x34) = 0xffffffff;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(undefined4 *)(iVar7 + 0x38) = 0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar5 = DAT_00767980 >> 0x10;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(uint *)(iVar7 + 0x3c) = (uVar5 & 0x7fff) % 3 + 0x10000;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(undefined1 *)(iVar11 + 0x40) = 0;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar9 = *(float **)(in_ECX + 0x54);
          local_34 = pfVar9;
        }
        else {
          pfVar9 = *(float **)(in_ECX + 0x54) + iVar4 * 0x11;
          local_34 = *(float **)(in_ECX + 0x54);
        }
        fVar12 = pfVar9[2] - *(float *)(in_ECX + 0x14);
        fVar15 = *pfVar9 - *(float *)(in_ECX + 0xc);
        dVar13 = (double)(fVar12 * fVar12 + fVar15 * fVar15);
        if (dVar13 < 0.0) {
          __libm_sse2_sqrt_precise();
        }
        else {
          dVar13 = SQRT(dVar13);
        }
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_34 = *(float **)(in_ECX + 0x54);
        }
        else {
          local_34 = local_34 + iVar4 * 0x11;
        }
        local_34[6] = ((float)dVar13 / 100.0) * fVar15;
        local_34[7] = 0.0;
        local_34[8] = ((float)dVar13 / 100.0) * fVar12;
        local_30 = local_30 + 1;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
      } while (local_30 < (int)(*(int *)(in_ECX + 0x50) + -1 + (DAT_00767980 >> 0x10 & 0x7fffU) % 3)
              );
    }
  }
LAB_004b1cb6:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar3 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_40 = 0;
    do {
      if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar4 = *(int *)(in_ECX + 0x54);
        iVar7 = iVar4;
      }
      else {
        iVar4 = *(int *)(in_ECX + 0x54);
        iVar7 = iVar4 + local_40;
      }
      if (*(int *)(iVar7 + 0x2c) != -10000) {
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar4 = *(int *)(in_ECX + 0x54);
          iVar7 = iVar4;
        }
        else {
          iVar7 = local_40 + iVar4;
        }
        if (0.0 < *(float *)(iVar7 + 0x30) || *(float *)(iVar7 + 0x30) == 0.0) {
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar4 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar4 = iVar4 + local_40;
          }
          fVar12 = in_XMM2_Da * 0.01 + *(float *)(iVar4 + 0x30);
        }
        else {
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar4 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar4 = iVar4 + local_40;
          }
          fVar12 = *(float *)(iVar4 + 0x30) - in_XMM2_Da * 0.01;
        }
        *(float *)(iVar4 + 0x30) = fVar12;
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar4 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54) + local_40;
        }
        *(int *)(iVar4 + 0x2c) = *(int *)(iVar4 + 0x2c) + 1;
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar4 = *(int *)(in_ECX + 0x54);
          iVar7 = iVar4;
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54);
          iVar7 = iVar4 + local_40;
        }
        if (*(int *)(iVar7 + 0x2c) < 0x31) {
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar4 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar4 = iVar4 + local_40;
          }
          *(float *)(iVar4 + 0x28) = *(float *)(iVar4 + 0x28) * 1.03;
        }
        else {
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar4 = *(int *)(in_ECX + 0x54);
            iVar7 = iVar4;
          }
          else {
            iVar7 = local_40 + iVar4;
          }
          if (*(float *)(in_ECX + 0x10) - *(float *)(iVar7 + 4) <= 0.5) {
            if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar4 = *(int *)(in_ECX + 0x54);
              iVar7 = iVar4;
            }
            else {
              iVar7 = local_40 + iVar4;
            }
            if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar9 = *(float **)(in_ECX + 0x54);
            }
            else {
              pfVar9 = (float *)(iVar4 + local_40);
            }
            *pfVar9 = *(float *)(iVar7 + 0x18) + *pfVar9;
            pfVar9[1] = *(float *)(iVar7 + 0x1c) + pfVar9[1];
            pfVar9[2] = *(float *)(iVar7 + 0x20) + pfVar9[2];
          }
          else {
            if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar4 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar4 = iVar4 + local_40;
            }
            *(float *)(iVar4 + 4) = *(float *)(iVar4 + 4) + 0.005;
          }
        }
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar4 = *(int *)(in_ECX + 0x54);
          iVar7 = iVar4;
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54) + local_40;
          iVar7 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar4 + 0x2c) < 0x80) {
          fVar12 = *(float *)(in_ECX + 0x60);
          if (fVar12 != 0.0) {
            if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar9 = *(float **)(in_ECX + 0x54);
              fVar12 = *(float *)(in_ECX + 0x60);
            }
            else {
              pfVar9 = (float *)(local_40 + iVar7);
            }
            fVar16 = *(float *)(in_ECX + 0x10) - pfVar9[1];
            fVar14 = *(float *)(in_ECX + 0xc) - *pfVar9;
            fVar15 = *(float *)(in_ECX + 0x14) - pfVar9[2];
            if (fVar12 < fVar16 * fVar16 + fVar14 * fVar14 + fVar15 * fVar15) goto LAB_004b1fef;
          }
        }
        else {
LAB_004b1fef:
          FUN_00493010(iVar3);
        }
      }
      iVar3 = iVar3 + 1;
      local_40 = local_40 + 0x44;
    } while (iVar3 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

