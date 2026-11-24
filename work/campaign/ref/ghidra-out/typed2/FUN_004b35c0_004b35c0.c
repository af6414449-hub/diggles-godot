
void FUN_004b35c0(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int in_ECX;
  int iVar8;
  byte *pbVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float in_XMM2_Da;
  float fVar13;
  float *local_14;
  int local_c;
  
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
            if (*pbVar9 < 0x81) goto LAB_004b3b42;
          }
        }
      }
    }
    local_c = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar1 = FUN_00492f80();
        iVar8 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar2 = iVar8 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar2 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        fVar10 = *(float *)(in_ECX + 0x10);
        fVar11 = *(float *)(in_ECX + 0x14);
        fVar12 = *(float *)(in_ECX + 0xc);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar4 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar4 = (float *)(*(int *)(in_ECX + 0x54) + iVar1 * 0x44);
        }
        iVar6 = iVar1 * 0x44;
        *pfVar4 = (float)(int)((iVar8 >> 0x10 & 0xfU) - 8) / 180.0 + fVar12;
        pfVar4[2] = fVar11 + (float)(int)((uVar3 & 0xf) - 8) / 180.0;
        pfVar4[1] = fVar10 + (float)(int)((iVar2 >> 0x10 & 0xfU) - 8) / 180.0;
        iVar2 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar8 = iVar2 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar8 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        fVar10 = *(float *)(in_ECX + 0x18);
        fVar11 = *(float *)(in_ECX + 0x1c);
        fVar12 = *(float *)(in_ECX + 0x20);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(float *)(iVar5 + 0xc) = fVar10 + (float)(int)((iVar2 >> 0x10 & 0xfU) - 8) / 180.0;
        *(float *)(iVar5 + 0x10) = fVar11 + (float)(int)((iVar8 >> 0x10 & 0xfU) - 0x10) / 185.0;
        *(float *)(iVar5 + 0x14) = fVar12 + (float)(int)((uVar3 & 0xf) - 8) / 180.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined4 *)(iVar2 + 0x28) = 0x40200000;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(uint *)(iVar2 + 0x2c) = uVar3 & 0x1f;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(float *)(iVar2 + 0x30) = (float)(uVar3 & 0x7fff) / 5215.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined4 *)(iVar2 + 0x34) = 0xffffffff;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined4 *)(iVar2 + 0x38) = 0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar3 = DAT_00767980 >> 0x10;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(uint *)(iVar2 + 0x3c) = (uVar3 & 1) << 0x10;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined1 *)(iVar6 + 0x40) = 0;
        local_c = local_c + 1;
      } while (local_c < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004b3b42:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar1 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    param_1 = 0;
    do {
      if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar2 = *(int *)(in_ECX + 0x54);
        iVar8 = iVar2;
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x54);
        iVar8 = param_1 + iVar2;
      }
      if (*(int *)(iVar8 + 0x2c) != -10000) {
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar2;
        }
        else {
          iVar8 = param_1 + iVar2;
        }
        if (0.0 < *(float *)(iVar8 + 0x30) || *(float *)(iVar8 + 0x30) == 0.0) {
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar2 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar2 = iVar2 + param_1;
          }
          fVar10 = in_XMM2_Da * 0.06 + *(float *)(iVar2 + 0x30);
        }
        else {
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar2 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar2 = iVar2 + param_1;
          }
          fVar10 = *(float *)(iVar2 + 0x30) - in_XMM2_Da * 0.06;
        }
        *(float *)(iVar2 + 0x30) = fVar10;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + param_1;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        fVar10 = *(float *)(iVar2 + 0xc);
        fVar11 = *(float *)(iVar2 + 0x10);
        fVar12 = *(float *)(iVar2 + 0x14);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar4 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar4 = (float *)(param_1 + iVar8);
        }
        *pfVar4 = fVar10 * in_XMM2_Da + *pfVar4;
        pfVar4[1] = fVar11 * in_XMM2_Da + pfVar4[1];
        pfVar4[2] = fVar12 * in_XMM2_Da + pfVar4[2];
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar2 + param_1;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
          iVar6 = iVar2;
        }
        else {
          iVar6 = param_1 + iVar2;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = param_1 + iVar2;
        }
        *(uint *)(iVar2 + 0x3c) =
             (int)(*(int *)(iVar6 + 0x2c) + (*(int *)(iVar6 + 0x2c) >> 0x1f & 3U)) >> 2 |
             *(uint *)(iVar8 + 0x3c) & 0xffff0000;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar4 = *(float **)(in_ECX + 0x54);
          local_14 = pfVar4;
        }
        else {
          pfVar4 = (float *)((int)*(float **)(in_ECX + 0x54) + param_1);
          local_14 = *(float **)(in_ECX + 0x54);
        }
        if ((((*pfVar4 < PTR_0077241c->x0f + 1.0) || (PTR_0077241c->x1f - 1.0 <= *pfVar4)) ||
            (pfVar4[1] < PTR_0077241c->y0f + 1.0)) || (PTR_0077241c->y1f - 1.0 <= pfVar4[1])) {
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar7 = *(undefined4 **)(in_ECX + 0x54);
          }
          else {
            puVar7 = (undefined4 *)((int)local_14 + param_1);
          }
          *puVar7 = 0x40000000;
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar2 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar2 = *(int *)(in_ECX + 0x54) + param_1;
          }
          *(undefined4 *)(iVar2 + 4) = 0x40000000;
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar2 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar2 = *(int *)(in_ECX + 0x54) + param_1;
          }
          *(undefined4 *)(iVar2 + 0x2c) = 0xffffd8f0;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + param_1;
        }
        *(float *)(iVar2 + 0xc) = *(float *)(iVar2 + 0xc) + in_XMM2_Da * 0.0;
        *(float *)(iVar2 + 0x10) = in_XMM2_Da * 0.01 + *(float *)(iVar2 + 0x10);
        *(float *)(iVar2 + 0x14) = *(float *)(iVar2 + 0x14) + in_XMM2_Da * 0.0;
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
          iVar8 = iVar2;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x54) + param_1;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar2 + 0x2c) < 0x20) {
          fVar10 = *(float *)(in_ECX + 0x60);
          if (fVar10 != 0.0) {
            if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar4 = *(float **)(in_ECX + 0x54);
              fVar10 = *(float *)(in_ECX + 0x60);
            }
            else {
              pfVar4 = (float *)(param_1 + iVar8);
            }
            fVar13 = *(float *)(in_ECX + 0x10) - pfVar4[1];
            fVar12 = *(float *)(in_ECX + 0xc) - *pfVar4;
            fVar11 = *(float *)(in_ECX + 0x14) - pfVar4[2];
            if (fVar10 < fVar13 * fVar13 + fVar12 * fVar12 + fVar11 * fVar11) goto LAB_004b3f9d;
          }
        }
        else {
LAB_004b3f9d:
          FUN_00493010(iVar1);
        }
      }
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 0x44;
    } while (iVar1 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

