
void FUN_004a9810(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  int in_ECX;
  undefined4 *puVar7;
  int iVar8;
  byte *pbVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float in_XMM2_Da;
  float fVar13;
  int local_1c;
  int local_14;
  
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
      pbVar9 = (byte *)(iVar1 + 0x34);
      if (param_1 < 8) {
        pbVar9 = pbVar9 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar9 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar3 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar9 = (byte *)FUN_00423700(uVar3);
        if (*pbVar9 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar3 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar9 = (byte *)FUN_00423700(uVar3);
          if (*pbVar9 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar9 = (byte *)FUN_00423700(param_1);
            if (*pbVar9 < 0x81) goto LAB_004a9db1;
          }
        }
      }
    }
    local_1c = 0;
    iVar1 = DAT_00767980 * 0x343fd + 0x269ec3;
    iVar2 = ((iVar1 * 0x343fd + 0x269ec3) * 0x343fd + 0x269ec3) * 0x343fd + 0x269ec3;
    DAT_00767980 = iVar2 * 0x343fd + 0x269ec3;
    if (0 < (int)(*(int *)(in_ECX + 0x50) + -1 + (DAT_00767980 >> 0x10 & 0x7fffU) % 3)) {
      do {
        iVar4 = FUN_00492f80();
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar7 = *(undefined4 **)(in_ECX + 0x54);
        }
        else {
          puVar7 = (undefined4 *)(*(int *)(in_ECX + 0x54) + iVar4 * 0x44);
        }
        iVar5 = iVar4 * 0x44;
        *puVar7 = *(undefined4 *)(in_ECX + 0xc);
        puVar7[1] = *(undefined4 *)(in_ECX + 0x10);
        puVar7[2] = *(undefined4 *)(in_ECX + 0x14);
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar5;
        }
        *(undefined4 *)(iVar8 + 0xc) = *(undefined4 *)(in_ECX + 0x18);
        *(undefined4 *)(iVar8 + 0x10) = *(undefined4 *)(in_ECX + 0x1c);
        *(undefined4 *)(iVar8 + 0x14) = *(undefined4 *)(in_ECX + 0x20);
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar5;
        }
        *(undefined4 *)(iVar8 + 0x28) = 0x3f000000;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar5;
        }
        *(uint *)(iVar8 + 0x2c) = (uVar3 & 7) + (iVar2 >> 0x10 & 0x7fffU) % 0xc;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar5;
        }
        *(float *)(iVar8 + 0x30) = -((float)(int)((iVar1 >> 0x10 & 0xfU) - 8) / 140.0);
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar5;
        }
        *(undefined4 *)(iVar8 + 0x34) = 0xffffffff;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar5;
        }
        *(undefined4 *)(iVar8 + 0x38) = 0;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar5;
        }
        *(undefined4 *)(iVar8 + 0x3c) = 0xf0007;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar5;
        }
        *(undefined1 *)(iVar5 + 0x40) = 0;
        local_1c = local_1c + 1;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
      } while (local_1c < (int)(*(int *)(in_ECX + 0x50) + -1 + (DAT_00767980 >> 0x10 & 0x7fffU) % 3)
              );
    }
  }
LAB_004a9db1:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar1 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_14 = 0;
    do {
      if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar2 = *(int *)(in_ECX + 0x54);
        iVar4 = iVar2;
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x54);
        iVar4 = iVar2 + local_14;
      }
      if (*(int *)(iVar4 + 0x2c) != -10000) {
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar4 = iVar2;
        }
        else {
          iVar4 = iVar2 + local_14;
        }
        fVar10 = *(float *)(iVar4 + 0xc);
        fVar11 = *(float *)(iVar4 + 0x10);
        fVar12 = *(float *)(iVar4 + 0x14);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar6 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar6 = (float *)(iVar2 + local_14);
        }
        *pfVar6 = fVar10 * in_XMM2_Da + *pfVar6;
        pfVar6[1] = fVar11 * in_XMM2_Da + pfVar6[1];
        pfVar6[2] = fVar12 * in_XMM2_Da + pfVar6[2];
        fVar10 = *(float *)(in_ECX + 0x24);
        fVar11 = *(float *)(in_ECX + 0x28);
        fVar12 = *(float *)(in_ECX + 0x2c);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(float *)(iVar2 + 0xc) = fVar10 * 0.05 + *(float *)(iVar2 + 0xc);
        *(float *)(iVar2 + 0x10) = fVar11 * 0.05 + *(float *)(iVar2 + 0x10);
        *(float *)(iVar2 + 0x14) = fVar12 * 0.05 + *(float *)(iVar2 + 0x14);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_14;
        }
        *(float *)(iVar2 + 0x28) = in_XMM2_Da * 0.15 + *(float *)(iVar2 + 0x28);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar4 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar4 = iVar2 + local_14;
        }
        if (0.0 < *(float *)(iVar4 + 0x30) || *(float *)(iVar4 + 0x30) == 0.0) {
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar2 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar2 = iVar2 + local_14;
          }
          fVar10 = in_XMM2_Da * 0.2 + *(float *)(iVar2 + 0x30);
        }
        else {
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar2 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar2 = iVar2 + local_14;
          }
          fVar10 = *(float *)(iVar2 + 0x30) - in_XMM2_Da * 0.2;
        }
        *(float *)(iVar2 + 0x30) = fVar10;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar4 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar4 = iVar2 + local_14;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = iVar2 + local_14;
        }
        *(int *)(iVar2 + 0x3c) =
             ((int)(*(int *)(iVar4 + 0x2c) + (*(int *)(iVar4 + 0x2c) >> 0x1f & 0xfU)) >> 4) +
             0xf0004;
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
          iVar4 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + local_14;
          iVar4 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar2 + 0x2c) < 0x40) {
          fVar10 = *(float *)(in_ECX + 0x60);
          if (fVar10 != 0.0) {
            if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar6 = *(float **)(in_ECX + 0x54);
              fVar10 = *(float *)(in_ECX + 0x60);
            }
            else {
              pfVar6 = (float *)(iVar4 + local_14);
            }
            fVar13 = *(float *)(in_ECX + 0x10) - pfVar6[1];
            fVar12 = *(float *)(in_ECX + 0xc) - *pfVar6;
            fVar11 = *(float *)(in_ECX + 0x14) - pfVar6[2];
            if (fVar10 < fVar13 * fVar13 + fVar12 * fVar12 + fVar11 * fVar11) goto LAB_004aa154;
          }
        }
        else {
LAB_004aa154:
          FUN_00493010(iVar1);
        }
      }
      iVar1 = iVar1 + 1;
      local_14 = local_14 + 0x44;
    } while (iVar1 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

