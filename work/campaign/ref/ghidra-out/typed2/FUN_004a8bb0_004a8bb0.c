
void FUN_004a8bb0(uint param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  int in_ECX;
  int iVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float in_XMM2_Da;
  float fVar18;
  int local_24;
  int local_20;
  int local_14;
  
  iVar2 = DAT_00767980 * 0x343fd + 0x269ec3;
  iVar3 = iVar2 * 0x343fd + 0x269ec3;
  DAT_00767980 = iVar3 * 0x343fd + 0x269ec3;
  uVar4 = DAT_00767980 >> 0x10;
  *(float *)(in_ECX + 0x24) =
       (*(float *)(in_ECX + 0x24) + (float)(int)((iVar2 >> 0x10 & 0xfU) - 8) / 6200.0) * 0.98;
  *(float *)(in_ECX + 0x28) =
       (*(float *)(in_ECX + 0x28) + (float)(int)((iVar3 >> 0x10 & 0xfU) - 8) / 5500.0) * 0.98;
  *(float *)(in_ECX + 0x2c) =
       (*(float *)(in_ECX + 0x2c) + (float)(int)((uVar4 & 0xf) - 8) / 6200.0) * 0.98;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar2 = FUN_00592f10(PTR_0077241c);
      pbVar5 = (byte *)(iVar2 + 0x34);
      if (param_1 < 8) {
        pbVar5 = pbVar5 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar5 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar4 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar5 = (byte *)FUN_00423700(uVar4);
        if (*pbVar5 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar4 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar5 = (byte *)FUN_00423700(uVar4);
          if (*pbVar5 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar5 = (byte *)FUN_00423700(param_1);
            if (*pbVar5 < 0x81) goto LAB_004a93a6;
          }
        }
      }
    }
    local_24 = 0;
    iVar2 = DAT_00767980 * 0x343fd + 0x269ec3;
    iVar3 = iVar2 * 0x343fd + 0x269ec3;
    fVar13 = (float)(int)((iVar2 >> 0x10 & 0xfU) - 8) / 140.0;
    iVar2 = iVar3 * 0x343fd + 0x269ec3;
    iVar6 = iVar2 * 0x343fd + 0x269ec3;
    DAT_00767980 = iVar6 * 0x343fd + 0x269ec3;
    if (0 < (int)(*(int *)(in_ECX + 0x50) + -1 + (DAT_00767980 >> 0x10 & 0x7fffU) % 3)) {
      do {
        iVar7 = FUN_00492f80();
        iVar12 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar8 = iVar12 * 0x343fd + 0x269ec3;
        fVar15 = ((float)((iVar12 >> 0x10 & 0x7fffU) % 0x168) / 180.0) * 3.1415927;
        DAT_00767980 = iVar8 * 0x343fd + 0x269ec3;
        uVar4 = DAT_00767980 >> 0x10;
        fVar1 = (float)((iVar8 >> 0x10 & 0x7fffU) % 0x50) / 180.0;
        fVar14 = fVar15;
        FUN_004089d0();
        fVar16 = *(float *)(in_ECX + 0xc);
        fVar17 = *(float *)(in_ECX + 0x10);
        FUN_004089f0();
        fVar18 = *(float *)(in_ECX + 0x14);
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar9 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar9 = (float *)(*(int *)(in_ECX + 0x54) + iVar7 * 0x44);
        }
        iVar8 = iVar7 * 0x44;
        *pfVar9 = fVar14 * fVar1 + fVar16;
        pfVar9[1] = (float)((uVar4 & 0x7fff) % 10) / 200.0 + fVar17;
        pfVar9[2] = fVar15 * fVar1 + fVar18;
        iVar12 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar10 = iVar12 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar10 * 0x343fd + 0x269ec3;
        uVar4 = DAT_00767980 >> 0x10;
        fVar16 = *(float *)(in_ECX + 0x18);
        fVar17 = *(float *)(in_ECX + 0x1c);
        fVar18 = *(float *)(in_ECX + 0x20);
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(float *)(iVar11 + 0xc) =
             fVar16 + fVar13 + (float)(int)((iVar12 >> 0x10 & 0xfU) - 8) / 400.0;
        *(float *)(iVar11 + 0x10) =
             fVar17 + (float)(int)((iVar3 >> 0x10 & 0xfU) - 8) / 140.0 +
             (float)(int)((iVar10 >> 0x10 & 0xfU) - 8) / 400.0;
        *(float *)(iVar11 + 0x14) =
             fVar18 + (float)(int)((iVar2 >> 0x10 & 0xfU) - 8) / 140.0 +
             (float)(int)((uVar4 & 0xf) - 8) / 400.0;
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(undefined4 *)(iVar12 + 0x28) = 0x40200000;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar4 = DAT_00767980 >> 0x10;
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_20 = *(int *)(in_ECX + 0x54);
        }
        else {
          local_20 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(uint *)(local_20 + 0x2c) = (uVar4 & 7) + (iVar6 >> 0x10 & 0x7fffU) % 0xc;
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(float *)(iVar12 + 0x30) = -fVar13;
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(undefined4 *)(iVar12 + 0x34) = 0xffffffff;
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(undefined4 *)(iVar12 + 0x38) = 0;
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(undefined4 *)(iVar12 + 0x3c) = 0xf0007;
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(undefined1 *)(iVar8 + 0x40) = 0;
        local_24 = local_24 + 1;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
      } while (local_24 < (int)(*(int *)(in_ECX + 0x50) + -1 + (DAT_00767980 >> 0x10 & 0x7fffU) % 3)
              );
    }
  }
LAB_004a93a6:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar2 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_14 = 0;
    do {
      if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar3 = *(int *)(in_ECX + 0x54);
        iVar6 = iVar3;
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x54);
        iVar6 = local_14 + iVar3;
      }
      if (*(int *)(iVar6 + 0x2c) != -10000) {
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar6 = iVar3;
        }
        else {
          iVar6 = iVar3 + local_14;
        }
        fVar13 = *(float *)(iVar6 + 0xc);
        fVar16 = *(float *)(iVar6 + 0x10);
        fVar17 = *(float *)(iVar6 + 0x14);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar9 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar9 = (float *)(iVar3 + local_14);
        }
        *pfVar9 = *pfVar9 + fVar13 * in_XMM2_Da;
        pfVar9[1] = pfVar9[1] + fVar16 * in_XMM2_Da;
        pfVar9[2] = pfVar9[2] + fVar17 * in_XMM2_Da;
        fVar13 = *(float *)(in_ECX + 0x24);
        fVar16 = *(float *)(in_ECX + 0x28);
        fVar17 = *(float *)(in_ECX + 0x2c);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar6 = iVar3;
        }
        else {
          iVar3 = local_14 + *(int *)(in_ECX + 0x54);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        fVar18 = *(float *)(iVar3 + 0xc);
        fVar15 = *(float *)(iVar3 + 0x10);
        fVar1 = *(float *)(iVar3 + 0x14);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = iVar6 + local_14;
        }
        *(float *)(iVar6 + 0xc) = (fVar18 * 90.0 + (fVar13 * 4.0 + 0.0) * 10.0) / 140.0;
        *(float *)(iVar6 + 0x10) = (fVar15 * 90.0 + (fVar16 * 4.0 - 0.12) * 10.0) / 140.0;
        *(float *)(iVar6 + 0x14) = (fVar1 * 90.0 + (fVar17 * 4.0 + 0.0) * 10.0) / 140.0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(float *)(iVar3 + 0x28) = in_XMM2_Da * 0.15 + *(float *)(iVar3 + 0x28);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar6 = iVar3;
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar6 = iVar3 + local_14;
        }
        if (0.0 < *(float *)(iVar6 + 0x30) || *(float *)(iVar6 + 0x30) == 0.0) {
          if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar3 = iVar3 + local_14;
          }
          fVar13 = in_XMM2_Da * 0.02 + *(float *)(iVar3 + 0x30);
        }
        else {
          if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar3 = iVar3 + local_14;
          }
          fVar13 = *(float *)(iVar3 + 0x30) - in_XMM2_Da * 0.02;
        }
        *(float *)(iVar3 + 0x30) = fVar13;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar6 = iVar3;
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar6 = iVar3 + local_14;
        }
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = iVar3 + local_14;
        }
        *(int *)(iVar3 + 0x3c) =
             ((int)(*(int *)(iVar6 + 0x2c) + (*(int *)(iVar6 + 0x2c) >> 0x1f & 0xfU)) >> 4) +
             0xf0004;
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
          iVar6 = iVar3;
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + local_14;
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar3 + 0x2c) < 0x40) {
          fVar13 = *(float *)(in_ECX + 0x60);
          if (fVar13 != 0.0) {
            if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar9 = *(float **)(in_ECX + 0x54);
              fVar13 = *(float *)(in_ECX + 0x60);
            }
            else {
              pfVar9 = (float *)(iVar6 + local_14);
            }
            fVar18 = *(float *)(in_ECX + 0x10) - pfVar9[1];
            fVar17 = *(float *)(in_ECX + 0xc) - *pfVar9;
            fVar16 = *(float *)(in_ECX + 0x14) - pfVar9[2];
            if (fVar13 < fVar18 * fVar18 + fVar17 * fVar17 + fVar16 * fVar16) goto LAB_004a97dd;
          }
        }
        else {
LAB_004a97dd:
          FUN_00493010(iVar2);
        }
      }
      iVar2 = iVar2 + 1;
      local_14 = local_14 + 0x44;
    } while (iVar2 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

