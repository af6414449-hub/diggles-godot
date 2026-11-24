
void FUN_004b47c0(uint param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  float *pfVar6;
  int iVar7;
  int in_ECX;
  int iVar8;
  code *pcVar9;
  byte *pbVar10;
  float fVar11;
  float in_XMM2_Da;
  
  pcVar9 = RaiseException_exref;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar3 = FUN_00592f10(PTR_0077241c);
      pbVar10 = (byte *)(iVar3 + 0x34);
      if (param_1 < 8) {
        pbVar10 = pbVar10 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar10 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar5 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar10 = (byte *)FUN_00423700(uVar5);
        if (*pbVar10 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar5 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar10 = (byte *)FUN_00423700(uVar5);
          if (*pbVar10 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar10 = (byte *)FUN_00423700(param_1);
            if (*pbVar10 < 0x81) goto LAB_004b4c8c;
          }
        }
      }
    }
    param_1 = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        if ((DAT_00767980 >> 0x10 & 0x7fffU) < 0x2000) {
          iVar3 = FUN_00492f80();
          iVar8 = DAT_00767980 * 0x343fd + 0x269ec3;
          iVar4 = iVar8 * 0x343fd + 0x269ec3;
          DAT_00767980 = iVar4 * 0x343fd + 0x269ec3;
          uVar5 = DAT_00767980 >> 0x10;
          fVar11 = *(float *)(in_ECX + 0xc);
          fVar1 = *(float *)(in_ECX + 0x10);
          fVar2 = *(float *)(in_ECX + 0x14);
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            (*pcVar9)(0xc000008c,1,0,0);
            pfVar6 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar6 = (float *)(*(int *)(in_ECX + 0x54) + iVar3 * 0x44);
          }
          iVar7 = iVar3 * 0x44;
          *pfVar6 = fVar11 + (float)(int)((iVar8 >> 0x10 & 0xfU) - 8) * 0.125;
          pfVar6[1] = fVar1 + (float)(int)((iVar4 >> 0x10 & 0xfU) - 8) * 0.125 + 4.0;
          pfVar6[2] = fVar2 + (float)(int)((uVar5 & 0xf) - 8) * 0.125;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar4 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar4 = *(int *)(in_ECX + 0x54) + iVar7;
          }
          *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(in_ECX + 0x18);
          *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(in_ECX + 0x1c);
          *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(in_ECX + 0x20);
          DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
          uVar5 = DAT_00767980 >> 0x10;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar4 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar4 = *(int *)(in_ECX + 0x54) + iVar7;
          }
          *(float *)(iVar4 + 0x28) = (float)(uVar5 & 0x7fff) / 23768.0 + 0.5;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar4 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar4 = *(int *)(in_ECX + 0x54) + iVar7;
          }
          *(undefined4 *)(iVar4 + 0x2c) = 0;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar4 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar4 = *(int *)(in_ECX + 0x54) + iVar7;
          }
          *(undefined4 *)(iVar4 + 0x30) = 0x3f490fdb;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar4 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar4 = *(int *)(in_ECX + 0x54) + iVar7;
          }
          *(undefined4 *)(iVar4 + 0x34) = 0x7f7f7f7f;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar4 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar4 = *(int *)(in_ECX + 0x54) + iVar7;
          }
          *(undefined4 *)(iVar4 + 0x38) = 0x7f7f7f7f;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar4 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar4 = *(int *)(in_ECX + 0x54) + iVar7;
          }
          *(undefined4 *)(iVar4 + 0x3c) = 0x20000;
          pcVar9 = RaiseException_exref;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar7 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar7 = *(int *)(in_ECX + 0x54) + iVar7;
          }
          *(undefined1 *)(iVar7 + 0x40) = 0;
        }
        param_1 = param_1 + 1;
      } while ((int)param_1 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004b4c8c:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar3 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    param_1 = 0;
    do {
      if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
        (*pcVar9)(0xc000008c,1,0,0);
        iVar4 = *(int *)(in_ECX + 0x54);
        iVar8 = iVar4;
      }
      else {
        iVar4 = *(int *)(in_ECX + 0x54);
        iVar8 = param_1 + iVar4;
      }
      if (*(int *)(iVar8 + 0x2c) != -10000) {
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          (*pcVar9)(0xc000008c,1,0,0);
          iVar4 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar4;
        }
        else {
          iVar8 = param_1 + iVar4;
        }
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          (*pcVar9)(0xc000008c,1,0,0);
          pfVar6 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar6 = (float *)(iVar4 + param_1);
        }
        *pfVar6 = *(float *)(iVar8 + 0xc) + *pfVar6;
        pfVar6[1] = *(float *)(iVar8 + 0x10) + pfVar6[1];
        pfVar6[2] = *(float *)(iVar8 + 0x14) + pfVar6[2];
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          (*pcVar9)(0xc000008c,1,0,0);
          iVar4 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54) + param_1;
        }
        *(float *)(iVar4 + 0xc) = *(float *)(iVar4 + 0xc) + 0.0;
        *(float *)(iVar4 + 0x10) = *(float *)(iVar4 + 0x10) - 0.008;
        *(float *)(iVar4 + 0x14) = *(float *)(iVar4 + 0x14) + 0.0;
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          (*pcVar9)(0xc000008c,1,0,0);
          iVar4 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar4;
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54);
          iVar8 = param_1 + iVar4;
        }
        if (0.0 < *(float *)(iVar8 + 0x30) || *(float *)(iVar8 + 0x30) == 0.0) {
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            (*pcVar9)(0xc000008c,1,0,0);
            iVar4 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar4 = iVar4 + param_1;
          }
          fVar11 = in_XMM2_Da * 0.002 + *(float *)(iVar4 + 0x30);
        }
        else {
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            (*pcVar9)(0xc000008c,1,0,0);
            iVar4 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar4 = iVar4 + param_1;
          }
          fVar11 = *(float *)(iVar4 + 0x30) - in_XMM2_Da * 0.002;
        }
        *(float *)(iVar4 + 0x30) = fVar11;
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          (*pcVar9)(0xc000008c,1,0,0);
          iVar4 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54) + param_1;
        }
        *(int *)(iVar4 + 0x2c) = *(int *)(iVar4 + 0x2c) + 1;
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          (*pcVar9)(0xc000008c,1,0,0);
          iVar4 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54) + param_1;
        }
        if (0x20 < *(int *)(iVar4 + 0x2c)) {
          FUN_00493010(iVar3);
        }
      }
      iVar3 = iVar3 + 1;
      param_1 = param_1 + 0x44;
    } while (iVar3 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

