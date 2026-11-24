
void FUN_004a7570(uint param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  float *pfVar10;
  undefined4 *puVar11;
  int iVar12;
  byte *pbVar13;
  float fVar14;
  float in_XMM2_Da;
  int local_24;
  int local_14;
  
  iVar6 = DAT_00767980 * 0x343fd + 0x269ec3;
  iVar7 = iVar6 * 0x343fd + 0x269ec3;
  DAT_00767980 = iVar7 * 0x343fd + 0x269ec3;
  uVar8 = DAT_00767980 >> 0x10;
  *(float *)(in_ECX + 0x28) =
       (*(float *)(in_ECX + 0x28) + (float)(int)((iVar7 >> 0x10 & 0xfU) - 8) / 5500.0) * 0.3;
  *(float *)(in_ECX + 0x24) =
       ((float)(int)((iVar6 >> 0x10 & 0xfU) - 8) / 3200.0 + *(float *)(in_ECX + 0x24)) * 0.3;
  *(float *)(in_ECX + 0x2c) =
       (*(float *)(in_ECX + 0x2c) + (float)(int)((uVar8 & 0xf) - 8) / 3200.0) * 0.3;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar6 = FUN_00592f10(PTR_0077241c);
      pbVar13 = (byte *)(iVar6 + 0x34);
      if (param_1 < 8) {
        pbVar13 = pbVar13 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar13 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar8 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar13 = (byte *)FUN_00423700(uVar8);
        if (*pbVar13 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar8 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar13 = (byte *)FUN_00423700(uVar8);
          if (*pbVar13 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar13 = (byte *)FUN_00423700(param_1);
            if (*pbVar13 < 0x81) goto LAB_004a7af8;
          }
        }
      }
    }
    local_24 = 0;
    iVar6 = DAT_00767980 * 0x343fd + 0x269ec3;
    DAT_00767980 = ((iVar6 * 0x343fd + 0x269ec3) * 0x343fd + 0x269ec3) * 0x343fd + 0x269ec3;
    if (0 < (int)(*(int *)(in_ECX + 0x50) + -1 + (DAT_00767980 >> 0x10 & 0x7fffU) % 3)) {
      do {
        iVar7 = FUN_00492f80();
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar11 = *(undefined4 **)(in_ECX + 0x54);
        }
        else {
          puVar11 = (undefined4 *)(*(int *)(in_ECX + 0x54) + iVar7 * 0x44);
        }
        iVar9 = iVar7 * 0x44;
        *puVar11 = *(undefined4 *)(in_ECX + 0xc);
        puVar11[1] = *(undefined4 *)(in_ECX + 0x10);
        puVar11[2] = *(undefined4 *)(in_ECX + 0x14);
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(undefined4 *)(iVar12 + 0xc) = *(undefined4 *)(in_ECX + 0x18);
        *(undefined4 *)(iVar12 + 0x10) = *(undefined4 *)(in_ECX + 0x1c);
        *(undefined4 *)(iVar12 + 0x14) = *(undefined4 *)(in_ECX + 0x20);
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(undefined4 *)(iVar12 + 0x28) = 0x3fc00000;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar8 = DAT_00767980 >> 0x10;
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(uint *)(iVar12 + 0x2c) = (uVar8 & 0x7fff) % 0x14;
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(float *)(iVar12 + 0x30) = -((float)(int)((iVar6 >> 0x10 & 0xfU) - 8) / 140.0);
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(undefined4 *)(iVar12 + 0x34) = 0xffffffff;
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(undefined4 *)(iVar12 + 0x38) = 0;
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(undefined4 *)(iVar12 + 0x3c) = 0x50000;
        if ((iVar7 < 0) || (*(int *)(in_ECX + 0x58) <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar9;
        }
        *(undefined1 *)(iVar9 + 0x40) = 0;
        local_24 = local_24 + 1;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
      } while (local_24 < (int)(*(int *)(in_ECX + 0x50) + -1 + (DAT_00767980 >> 0x10 & 0x7fffU) % 3)
              );
    }
  }
LAB_004a7af8:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar6 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_14 = 0;
    do {
      if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar7 = *(int *)(in_ECX + 0x54);
        iVar9 = iVar7;
      }
      else {
        iVar7 = *(int *)(in_ECX + 0x54);
        iVar9 = iVar7 + local_14;
      }
      if (*(int *)(iVar9 + 0x2c) != -10000) {
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar7;
        }
        else {
          iVar9 = iVar7 + local_14;
        }
        fVar14 = *(float *)(iVar9 + 0xc);
        fVar1 = *(float *)(iVar9 + 0x10);
        fVar2 = *(float *)(iVar9 + 0x14);
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar10 = (float *)(iVar7 + local_14);
        }
        *pfVar10 = fVar14 * in_XMM2_Da + *pfVar10;
        pfVar10[1] = fVar1 * in_XMM2_Da + pfVar10[1];
        pfVar10[2] = fVar2 * in_XMM2_Da + pfVar10[2];
        fVar14 = *(float *)(in_ECX + 0x24);
        fVar1 = *(float *)(in_ECX + 0x28);
        fVar2 = *(float *)(in_ECX + 0x2c);
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar7;
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x54) + local_14;
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        fVar3 = *(float *)(iVar7 + 0xc);
        fVar4 = *(float *)(iVar7 + 0x10);
        fVar5 = *(float *)(iVar7 + 0x14);
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = iVar9 + local_14;
        }
        *(float *)(iVar9 + 0xc) = (fVar3 * 90.0 + (fVar14 * 4.0 + 0.0) * 10.0) / 130.0;
        *(float *)(iVar9 + 0x10) = (fVar4 * 90.0 + (fVar1 * 4.0 - 0.05) * 10.0) / 130.0;
        *(float *)(iVar9 + 0x14) = (fVar5 * 90.0 + (fVar2 * 4.0 + 0.0) * 10.0) / 130.0;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar7;
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar7 + local_14;
        }
        if (0.0 < *(float *)(iVar9 + 0x30) || *(float *)(iVar9 + 0x30) == 0.0) {
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar7 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar7 = iVar7 + local_14;
          }
          fVar14 = in_XMM2_Da * 0.1 + *(float *)(iVar7 + 0x30);
        }
        else {
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar7 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar7 = iVar7 + local_14;
          }
          fVar14 = *(float *)(iVar7 + 0x30) - in_XMM2_Da * 0.1;
        }
        *(float *)(iVar7 + 0x30) = fVar14;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar7;
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar7 + local_14;
        }
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar7 = local_14 + iVar7;
        }
        *(int *)(iVar7 + 0x3c) = *(int *)(iVar9 + 0x2c) / 7 + 0x50000;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(int *)(iVar7 + 0x2c) = *(int *)(iVar7 + 0x2c) + 1;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x54) + local_14;
        }
        if (0x6f < *(int *)(iVar7 + 0x2c)) {
          FUN_00493010(iVar6);
        }
      }
      iVar6 = iVar6 + 1;
      local_14 = local_14 + 0x44;
    } while (iVar6 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

