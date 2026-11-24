
void FUN_004b3fd0(uint param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int in_ECX;
  int iVar10;
  code *pcVar11;
  byte *pbVar12;
  uint local_c;
  int local_8;
  
  pcVar11 = RaiseException_exref;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar4 = FUN_00592f10(PTR_0077241c);
      pbVar12 = (byte *)(iVar4 + 0x34);
      if (param_1 < 8) {
        pbVar12 = pbVar12 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar12 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar6 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar12 = (byte *)FUN_00423700(uVar6);
        if (*pbVar12 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar6 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar12 = (byte *)FUN_00423700(uVar6);
          if (*pbVar12 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar12 = (byte *)FUN_00423700(param_1);
            if (*pbVar12 < 0x81) goto LAB_004b4517;
          }
        }
      }
    }
    param_1 = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        if ((DAT_00767980 >> 0x10 & 0x7fffU) < 0x2000) {
          iVar4 = FUN_00492f80();
          iVar10 = DAT_00767980 * 0x343fd + 0x269ec3;
          iVar5 = iVar10 * 0x343fd + 0x269ec3;
          DAT_00767980 = iVar5 * 0x343fd + 0x269ec3;
          fVar1 = *(float *)(in_ECX + 0xc);
          uVar6 = DAT_00767980 >> 0x10;
          fVar2 = *(float *)(in_ECX + 0x10);
          fVar3 = *(float *)(in_ECX + 0x14);
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar11)(0xc000008c,1,0,0);
            pfVar7 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar7 = (float *)(*(int *)(in_ECX + 0x54) + iVar4 * 0x44);
          }
          iVar9 = iVar4 * 0x44;
          pfVar7[1] = fVar2 + (float)(int)((iVar5 >> 0x10 & 0xfU) - 8) * 0.125;
          pfVar7[2] = fVar3 + (float)(int)((uVar6 & 0xf) - 8) * 0.2;
          *pfVar7 = fVar1 + (float)(int)((iVar10 >> 0x10 & 0xfU) - 8) * 0.125;
          iVar5 = DAT_00767980 * 0x343fd + 0x269ec3;
          iVar10 = iVar5 * 0x343fd + 0x269ec3;
          DAT_00767980 = iVar10 * 0x343fd + 0x269ec3;
          uVar6 = DAT_00767980 >> 0x10;
          fVar1 = *(float *)(in_ECX + 0x18);
          fVar2 = *(float *)(in_ECX + 0x1c);
          fVar3 = *(float *)(in_ECX + 0x20);
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + iVar9;
          }
          *(float *)(iVar8 + 0xc) = fVar1 + (float)(int)((iVar5 >> 0x10 & 0xfU) - 8) / 540.0;
          *(float *)(iVar8 + 0x10) = fVar2 + (float)(int)((iVar10 >> 0x10 & 0xfU) - 8) / 340.0;
          *(float *)(iVar8 + 0x14) = fVar3 + (float)(int)((uVar6 & 0xf) - 8) / 540.0;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar5 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar5 = *(int *)(in_ECX + 0x54) + iVar9;
          }
          *(undefined4 *)(iVar5 + 0x28) = 0x40b00000;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar5 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar5 = *(int *)(in_ECX + 0x54) + iVar9;
          }
          *(undefined4 *)(iVar5 + 0x2c) = 0;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar5 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar5 = *(int *)(in_ECX + 0x54) + iVar9;
          }
          *(undefined4 *)(iVar5 + 0x30) = 0x3f490fdb;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar5 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar5 = *(int *)(in_ECX + 0x54) + iVar9;
          }
          *(undefined4 *)(iVar5 + 0x34) = 0x7f7f7f7f;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar5 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar5 = *(int *)(in_ECX + 0x54) + iVar9;
          }
          *(undefined4 *)(iVar5 + 0x38) = 0x7f7f7f7f;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar5 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar5 = *(int *)(in_ECX + 0x54) + iVar9;
          }
          *(undefined4 *)(iVar5 + 0x3c) = 0x20000;
          pcVar11 = RaiseException_exref;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar9 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar9 = *(int *)(in_ECX + 0x54) + iVar9;
          }
          *(undefined1 *)(iVar9 + 0x40) = 0;
        }
        param_1 = param_1 + 1;
      } while ((int)param_1 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004b4517:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar4 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    param_1 = 0;
    do {
      if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
        (*pcVar11)(0xc000008c,1,0,0);
        iVar5 = *(int *)(in_ECX + 0x54);
        iVar10 = iVar5;
      }
      else {
        iVar5 = *(int *)(in_ECX + 0x54);
        iVar10 = param_1 + iVar5;
      }
      if (*(int *)(iVar10 + 0x2c) != -10000) {
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          (*pcVar11)(0xc000008c,1,0,0);
          iVar5 = *(int *)(in_ECX + 0x54);
          iVar10 = iVar5;
        }
        else {
          iVar10 = param_1 + iVar5;
        }
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          (*pcVar11)(0xc000008c,1,0,0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = (float *)(iVar5 + param_1);
        }
        *pfVar7 = *(float *)(iVar10 + 0xc) + *pfVar7;
        pfVar7[1] = *(float *)(iVar10 + 0x10) + pfVar7[1];
        pfVar7[2] = *(float *)(iVar10 + 0x14) + pfVar7[2];
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          (*pcVar11)(0xc000008c,1,0,0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + param_1;
        }
        *(float *)(iVar5 + 0xc) = *(float *)(iVar5 + 0xc) + 0.0;
        *(float *)(iVar5 + 0x10) = *(float *)(iVar5 + 0x10) + 0.008;
        *(float *)(iVar5 + 0x14) = *(float *)(iVar5 + 0x14) + 0.0;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          (*pcVar11)(0xc000008c,1,0,0);
          local_8 = *(int *)(in_ECX + 0x54);
          iVar5 = local_8;
        }
        else {
          local_8 = *(int *)(in_ECX + 0x54);
          iVar5 = param_1 + local_8;
        }
        if (*(int *)(iVar5 + 0x2c) < 0x10) {
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar11)(0xc000008c,1,0,0);
            iVar5 = *(int *)(in_ECX + 0x54);
            local_8 = iVar5;
          }
          else {
            iVar5 = local_8 + param_1;
          }
          local_c = 7 - *(int *)(iVar5 + 0x2c) / 2;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar11)(0xc000008c,1,0,0);
            local_8 = *(int *)(in_ECX + 0x54);
          }
          else {
            local_8 = local_8 + param_1;
          }
        }
        else {
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar11)(0xc000008c,1,0,0);
            iVar5 = *(int *)(in_ECX + 0x54);
            local_8 = iVar5;
          }
          else {
            iVar5 = local_8 + param_1;
          }
          local_c = (*(int *)(iVar5 + 0x2c) + -0x10) / 2;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar11)(0xc000008c,1,0,0);
            local_8 = *(int *)(in_ECX + 0x54);
          }
          else {
            local_8 = local_8 + param_1;
          }
        }
        uVar6 = local_c & 0x80000003;
        if ((int)uVar6 < 0) {
          uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
        }
        *(uint *)(local_8 + 0x3c) =
             (((int)(local_c + ((int)local_c >> 0x1f & 3U)) >> 2) + 2) * 0x10000 | uVar6;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          (*pcVar11)(0xc000008c,1,0,0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + param_1;
        }
        *(int *)(iVar5 + 0x2c) = *(int *)(iVar5 + 0x2c) + 1;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          (*pcVar11)(0xc000008c,1,0,0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + param_1;
        }
        if (0x20 < *(int *)(iVar5 + 0x2c)) {
          FUN_00493010(iVar4);
        }
      }
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 0x44;
    } while (iVar4 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

