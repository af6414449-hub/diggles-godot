
void FUN_004b2b50(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int in_ECX;
  int iVar10;
  byte *pbVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float in_XMM2_Da;
  float fVar15;
  int local_10;
  
  iVar1 = DAT_00767980 * 0x343fd + 0x269ec3;
  iVar2 = iVar1 * 0x343fd + 0x269ec3;
  DAT_00767980 = iVar2 * 0x343fd + 0x269ec3;
  uVar3 = DAT_00767980 >> 0x10;
  *(float *)(in_ECX + 0x24) =
       (*(float *)(in_ECX + 0x24) + (float)(int)((iVar1 >> 0x10 & 0xfU) - 8) / 6200.0) * 0.98;
  *(float *)(in_ECX + 0x28) =
       (*(float *)(in_ECX + 0x28) + (float)(int)((iVar2 >> 0x10 & 0xfU) - 8) / 5500.0) * 0.98;
  *(float *)(in_ECX + 0x2c) =
       (*(float *)(in_ECX + 0x2c) + (float)(int)((uVar3 & 0xf) - 8) / 6200.0) * 0.98;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar1 = FUN_00592f10(PTR_0077241c);
      pbVar11 = (byte *)(iVar1 + 0x34);
      if (param_1 < 8) {
        pbVar11 = pbVar11 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar11 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar3 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar11 = (byte *)FUN_00423700(uVar3);
        if (*pbVar11 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar3 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar11 = (byte *)FUN_00423700(uVar3);
          if (*pbVar11 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar11 = (byte *)FUN_00423700(param_1);
            if (*pbVar11 < 0x81) goto LAB_004b32b1;
          }
        }
      }
    }
    local_10 = 0;
    iVar1 = DAT_00767980 * 0x343fd + 0x269ec3;
    DAT_00767980 = iVar1 * 0x343fd + 0x269ec3;
    if (0 < (int)(*(int *)(in_ECX + 0x50) + -1 + (DAT_00767980 >> 0x10 & 0x7fffU) % 3)) {
      do {
        iVar2 = FUN_00492f80();
        iVar10 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar4 = iVar10 * 0x343fd + 0x269ec3;
        iVar5 = iVar4 * 0x343fd + 0x269ec3;
        iVar6 = iVar5 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar6 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        fVar12 = *(float *)(in_ECX + 0xc);
        fVar13 = *(float *)(in_ECX + 0x10);
        fVar14 = *(float *)(in_ECX + 0x14);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = (float *)(*(int *)(in_ECX + 0x54) + iVar2 * 0x44);
        }
        iVar9 = iVar2 * 0x44;
        pfVar7[1] = fVar13 + (float)(int)((iVar6 >> 0x10 & 0xfU) - 8) / 20.0;
        pfVar7[2] = fVar14 + (float)(int)((uVar3 & 0xf) - 8) / 20.0;
        *pfVar7 = fVar12 + (float)(int)((iVar5 >> 0x10 & 0xfU) - 8) / 20.0;
        iVar5 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar6 = iVar5 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar6 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        fVar12 = *(float *)(in_ECX + 0x18);
        fVar13 = *(float *)(in_ECX + 0x1c);
        fVar14 = *(float *)(in_ECX + 0x20);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(float *)(iVar8 + 0xc) = fVar12 + (float)(int)((iVar5 >> 0x10 & 0xfU) - 8) / 200.0;
        *(float *)(iVar8 + 0x10) = fVar13 + (float)(int)((iVar6 >> 0x10 & 0xfU) - 8) / 200.0;
        *(float *)(iVar8 + 0x14) = fVar14 + (float)(int)((uVar3 & 0xf) - 8) / 200.0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(undefined4 *)(iVar5 + 0x28) = 0x3fd9999a;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(uint *)(iVar5 + 0x2c) = (uVar3 & 7) + (iVar1 >> 0x10 & 0x7fffU) % 0xc;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(float *)(iVar5 + 0x30) =
             (float)((iVar4 >> 0x10 & 0x7fffU) % 0x50) / 180.0 +
             ((float)((iVar10 >> 0x10 & 0x7fffU) % 0x168) / 180.0) * 3.1415927;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar4 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(undefined **)(iVar4 + 0x34) = &DAT_007f753f;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar4 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(undefined4 *)(iVar4 + 0x38) = 0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar4 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(uint *)(iVar4 + 0x3c) = (uVar3 & 1) + 0x20000;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(undefined1 *)(iVar9 + 0x40) = 0;
        local_10 = local_10 + 1;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
      } while (local_10 < (int)(*(int *)(in_ECX + 0x50) + -1 + (DAT_00767980 >> 0x10 & 0x7fffU) % 3)
              );
    }
  }
LAB_004b32b1:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar1 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    param_1 = 0;
    do {
      if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar2 = *(int *)(in_ECX + 0x54);
        iVar4 = iVar2;
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x54);
        iVar4 = iVar2 + param_1;
      }
      if (*(int *)(iVar4 + 0x2c) != -10000) {
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar4 = iVar2;
        }
        else {
          iVar4 = param_1 + iVar2;
        }
        fVar12 = *(float *)(iVar4 + 0xc);
        fVar13 = *(float *)(iVar4 + 0x10);
        fVar14 = *(float *)(iVar4 + 0x14);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = (float *)(iVar2 + param_1);
        }
        *pfVar7 = *pfVar7 + fVar12 * in_XMM2_Da;
        pfVar7[1] = fVar13 * in_XMM2_Da + pfVar7[1];
        pfVar7[2] = pfVar7[2] + fVar14 * in_XMM2_Da;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + param_1;
        }
        *(float *)(iVar2 + 0x28) = *(float *)(iVar2 + 0x28) - in_XMM2_Da * 0.03;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + param_1;
        }
        *(float *)(iVar2 + 0xc) = *(float *)(iVar2 + 0xc) * 0.95;
        *(float *)(iVar2 + 0x10) = *(float *)(iVar2 + 0x10) * 0.95;
        *(float *)(iVar2 + 0x14) = *(float *)(iVar2 + 0x14) * 0.95;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar4 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar4 = iVar2 + param_1;
        }
        if (0.0 < *(float *)(iVar4 + 0x30) || *(float *)(iVar4 + 0x30) == 0.0) {
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar2 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar2 = iVar2 + param_1;
          }
          fVar12 = in_XMM2_Da * 0.01 + *(float *)(iVar2 + 0x30);
        }
        else {
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar2 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar2 = iVar2 + param_1;
          }
          fVar12 = *(float *)(iVar2 + 0x30) - in_XMM2_Da * 0.01;
        }
        *(float *)(iVar2 + 0x30) = fVar12;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + param_1;
        }
        *(int *)(iVar2 + 0x2c) = *(int *)(iVar2 + 0x2c) + 1;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar4 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + param_1;
          iVar4 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar2 + 0x2c) < 0x20) {
          fVar12 = *(float *)(in_ECX + 0x60);
          if (fVar12 != 0.0) {
            if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar7 = *(float **)(in_ECX + 0x54);
              fVar12 = *(float *)(in_ECX + 0x60);
            }
            else {
              pfVar7 = (float *)(param_1 + iVar4);
            }
            fVar15 = *(float *)(in_ECX + 0x10) - pfVar7[1];
            fVar14 = *(float *)(in_ECX + 0xc) - *pfVar7;
            fVar13 = *(float *)(in_ECX + 0x14) - pfVar7[2];
            if (fVar12 < fVar15 * fVar15 + fVar14 * fVar14 + fVar13 * fVar13) goto LAB_004b3591;
          }
        }
        else {
LAB_004b3591:
          FUN_00493010(iVar1);
        }
      }
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 0x44;
    } while (iVar1 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

