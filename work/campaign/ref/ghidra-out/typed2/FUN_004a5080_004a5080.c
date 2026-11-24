
void FUN_004a5080(uint param_1)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  int *piVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  float *pfVar17;
  int in_ECX;
  code *pcVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float in_XMM2_Da;
  float fVar22;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_20;
  int local_14;
  
  pcVar18 = RaiseException_exref;
  iVar5 = DAT_00767980 * 0x343fd + 0x269ec3;
  iVar6 = iVar5 * 0x343fd + 0x269ec3;
  DAT_00767980 = iVar6 * 0x343fd + 0x269ec3;
  uVar7 = DAT_00767980 >> 0x10;
  *(float *)(in_ECX + 0x24) =
       (*(float *)(in_ECX + 0x24) + (float)(int)((iVar5 >> 0x10 & 0xfU) - 8) / 3200.0) * 0.98;
  *(float *)(in_ECX + 0x28) =
       (*(float *)(in_ECX + 0x28) + (float)(int)((iVar6 >> 0x10 & 0xfU) - 8) / 5500.0) * 0.98;
  *(float *)(in_ECX + 0x2c) =
       (*(float *)(in_ECX + 0x2c) + (float)(int)((uVar7 & 0xf) - 8) / 3200.0) * 0.98;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar5 = FUN_00592f10(PTR_0077241c);
      pbVar8 = (byte *)(iVar5 + 0x34);
      if (param_1 < 8) {
        pbVar8 = pbVar8 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar8 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar7 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar8 = (byte *)FUN_00423700(uVar7);
        if (*pbVar8 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar7 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar8 = (byte *)FUN_00423700(uVar7);
          if (*pbVar8 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar8 = (byte *)FUN_00423700(param_1);
            if (*pbVar8 < 0x81) goto LAB_004a582e;
          }
        }
      }
    }
    iVar5 = DAT_00767980 * 0x343fd + 0x269ec3;
    iVar6 = iVar5 * 0x343fd + 0x269ec3;
    fVar20 = (float)(int)((iVar5 >> 0x10 & 0xfU) - 8) / 140.0;
    iVar5 = iVar6 * 0x343fd + 0x269ec3;
    DAT_00767980 = iVar5 * 0x343fd + 0x269ec3;
    uVar9 = DAT_00767980 >> 0x10;
    uVar7 = *(uint *)(in_ECX + 0x70);
    if (uVar7 != 0xffffffff) {
      piVar10 = (int *)(DAT_0077244c + 0x488);
      if (uVar7 < 0x2000) {
        piVar10 = piVar10 + uVar7;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar12 = *piVar10;
      if (((iVar12 != 0) &&
          (cVar4 = FUN_0049aaa0(iVar12,*(undefined4 *)(in_ECX + 0x50),*(undefined4 *)(in_ECX + 0x74)
                               ), cVar4 == '\0')) || (iVar12 == 0)) {
        FUN_0049aa20();
        *(undefined4 *)(in_ECX + 0x70) = 0xffffffff;
      }
    }
    local_30 = 0;
    DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
    if (0 < (int)(*(int *)(in_ECX + 0x50) + -1 + (DAT_00767980 >> 0x10 & 0x7fffU) % 3)) {
      local_20 = 0;
      do {
        if ((*(int *)(in_ECX + 0x70) == -1) || (*(int *)(in_ECX + 0x7c) <= local_30)) {
          local_2c = *(undefined4 *)(in_ECX + 0x14);
          local_28 = *(undefined4 *)(in_ECX + 0x10);
          uVar1 = *(undefined4 *)(in_ECX + 0xc);
        }
        else {
          if ((local_30 < 0) || (*(int *)(in_ECX + 0x7c) <= local_30)) {
            (*pcVar18)(0xc000008c,1,0,0);
            puVar11 = *(undefined4 **)(in_ECX + 0x78);
          }
          else {
            puVar11 = (undefined4 *)(*(int *)(in_ECX + 0x78) + local_20);
          }
          local_2c = puVar11[2];
          local_28 = puVar11[1];
          uVar1 = *puVar11;
        }
        iVar12 = FUN_00492f80();
        if ((iVar12 < 0) || (*(int *)(in_ECX + 0x58) <= iVar12)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar11 = *(undefined4 **)(in_ECX + 0x54);
        }
        else {
          puVar11 = (undefined4 *)(*(int *)(in_ECX + 0x54) + iVar12 * 0x44);
        }
        iVar16 = iVar12 * 0x44;
        *puVar11 = uVar1;
        puVar11[1] = local_28;
        puVar11[2] = local_2c;
        iVar13 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar14 = iVar13 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar14 * 0x343fd + 0x269ec3;
        uVar7 = DAT_00767980 >> 0x10;
        fVar19 = *(float *)(in_ECX + 0x18);
        fVar21 = *(float *)(in_ECX + 0x1c);
        fVar22 = *(float *)(in_ECX + 0x20);
        if ((iVar12 < 0) || (*(int *)(in_ECX + 0x58) <= iVar12)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar15 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar15 = *(int *)(in_ECX + 0x54) + iVar16;
        }
        *(float *)(iVar15 + 0xc) =
             fVar19 + fVar20 + (float)(int)((iVar13 >> 0x10 & 0xfU) - 8) / 400.0;
        *(float *)(iVar15 + 0x10) =
             fVar21 + (float)(int)((iVar6 >> 0x10 & 0xfU) - 8) / 140.0 +
             (float)(int)((iVar14 >> 0x10 & 0xfU) - 8) / 400.0;
        *(float *)(iVar15 + 0x14) =
             fVar22 + (float)(int)((iVar5 >> 0x10 & 0xfU) - 8) / 140.0 +
             (float)(int)((uVar7 & 0xf) - 8) / 400.0;
        if ((iVar12 < 0) || (*(int *)(in_ECX + 0x58) <= iVar12)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar13 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar13 = *(int *)(in_ECX + 0x54) + iVar16;
        }
        *(undefined4 *)(iVar13 + 0x28) = 0x40200000;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar7 = DAT_00767980 >> 0x10;
        if ((iVar12 < 0) || (*(int *)(in_ECX + 0x58) <= iVar12)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar13 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar13 = *(int *)(in_ECX + 0x54) + iVar16;
        }
        *(uint *)(iVar13 + 0x2c) = (uVar7 & 7) + (uVar9 & 0x7fff) % 0xc;
        if ((iVar12 < 0) || (*(int *)(in_ECX + 0x58) <= iVar12)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar13 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar13 = *(int *)(in_ECX + 0x54) + iVar16;
        }
        *(float *)(iVar13 + 0x30) = -fVar20;
        if ((iVar12 < 0) || (*(int *)(in_ECX + 0x58) <= iVar12)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar13 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar13 = *(int *)(in_ECX + 0x54) + iVar16;
        }
        *(undefined4 *)(iVar13 + 0x34) = 0xffffffff;
        if ((iVar12 < 0) || (*(int *)(in_ECX + 0x58) <= iVar12)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar13 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar13 = *(int *)(in_ECX + 0x54) + iVar16;
        }
        *(undefined4 *)(iVar13 + 0x38) = 0;
        if ((iVar12 < 0) || (*(int *)(in_ECX + 0x58) <= iVar12)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar13 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar13 = *(int *)(in_ECX + 0x54) + iVar16;
        }
        *(undefined4 *)(iVar13 + 0x3c) = 0xf0007;
        pcVar18 = RaiseException_exref;
        if ((iVar12 < 0) || (*(int *)(in_ECX + 0x58) <= iVar12)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar16 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar16 = *(int *)(in_ECX + 0x54) + iVar16;
        }
        *(undefined1 *)(iVar16 + 0x40) = 0;
        local_20 = local_20 + 0xc;
        local_30 = local_30 + 1;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
      } while (local_30 < (int)(*(int *)(in_ECX + 0x50) + -1 + (DAT_00767980 >> 0x10 & 0x7fffU) % 3)
              );
    }
  }
LAB_004a582e:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar5 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_14 = 0;
    do {
      if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = *(int *)(in_ECX + 0x54);
        iVar12 = iVar6;
      }
      else {
        iVar6 = *(int *)(in_ECX + 0x54);
        iVar12 = local_14 + iVar6;
      }
      if (*(int *)(iVar12 + 0x2c) != -10000) {
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar12 = iVar6;
        }
        else {
          iVar12 = iVar6 + local_14;
        }
        fVar20 = *(float *)(iVar12 + 0x10);
        fVar19 = *(float *)(iVar12 + 0xc);
        fVar21 = *(float *)(iVar12 + 0x14);
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar17 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar17 = (float *)(iVar6 + local_14);
        }
        *pfVar17 = *pfVar17 + in_XMM2_Da * fVar19;
        pfVar17[1] = fVar20 * in_XMM2_Da + pfVar17[1];
        pfVar17[2] = pfVar17[2] + fVar21 * in_XMM2_Da;
        fVar20 = *(float *)(in_ECX + 0x24);
        fVar19 = *(float *)(in_ECX + 0x28);
        fVar21 = *(float *)(in_ECX + 0x2c);
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar12 = iVar6;
        }
        else {
          iVar6 = local_14 + *(int *)(in_ECX + 0x54);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        fVar22 = *(float *)(iVar6 + 0xc);
        fVar2 = *(float *)(iVar6 + 0x10);
        fVar3 = *(float *)(iVar6 + 0x14);
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = iVar12 + local_14;
        }
        *(float *)(iVar12 + 0xc) = (fVar22 * 90.0 + (fVar20 * 4.0 + 0.0) * 10.0) / 100.0;
        *(float *)(iVar12 + 0x10) = (fVar2 * 90.0 + (fVar19 * 4.0 - 0.05) * 10.0) / 100.0;
        *(float *)(iVar12 + 0x14) = (fVar3 * 90.0 + (fVar21 * 4.0 + 0.0) * 10.0) / 100.0;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(float *)(iVar6 + 0x28) = in_XMM2_Da * 0.15 + *(float *)(iVar6 + 0x28);
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar12 = iVar6;
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar12 = iVar6 + local_14;
        }
        if (0.0 < *(float *)(iVar12 + 0x30) || *(float *)(iVar12 + 0x30) == 0.0) {
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = iVar6 + local_14;
          }
          fVar20 = in_XMM2_Da * 0.2 + *(float *)(iVar6 + 0x30);
        }
        else {
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = iVar6 + local_14;
          }
          fVar20 = *(float *)(iVar6 + 0x30) - in_XMM2_Da * 0.2;
        }
        *(float *)(iVar6 + 0x30) = fVar20;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar12 = iVar6;
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar12 = iVar6 + local_14;
        }
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = iVar6 + local_14;
        }
        *(int *)(iVar6 + 0x3c) =
             ((int)(*(int *)(iVar12 + 0x2c) + (*(int *)(iVar12 + 0x2c) >> 0x1f & 7U)) >> 3) +
             0xf0004;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(int *)(iVar6 + 0x2c) = *(int *)(iVar6 + 0x2c) + 1;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar12 = iVar6;
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + local_14;
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar6 + 0x2c) < 0x20) {
          fVar20 = *(float *)(in_ECX + 0x60);
          if (fVar20 != 0.0) {
            if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar17 = *(float **)(in_ECX + 0x54);
              fVar20 = *(float *)(in_ECX + 0x60);
            }
            else {
              pfVar17 = (float *)(iVar12 + local_14);
            }
            fVar22 = *(float *)(in_ECX + 0x10) - pfVar17[1];
            fVar21 = *(float *)(in_ECX + 0xc) - *pfVar17;
            fVar19 = *(float *)(in_ECX + 0x14) - pfVar17[2];
            if (fVar20 < fVar22 * fVar22 + fVar21 * fVar21 + fVar19 * fVar19) goto LAB_004a5c68;
          }
        }
        else {
LAB_004a5c68:
          FUN_00493010(iVar5);
        }
      }
      iVar5 = iVar5 + 1;
      local_14 = local_14 + 0x44;
    } while (iVar5 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

