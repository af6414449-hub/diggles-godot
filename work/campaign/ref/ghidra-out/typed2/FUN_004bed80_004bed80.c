
void FUN_004bed80(uint param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  byte *pbVar9;
  uint uVar10;
  
  pcVar8 = RaiseException_exref;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar3 = FUN_00592f10(PTR_0077241c);
      pbVar9 = (byte *)(iVar3 + 0x34);
      if (param_1 < 8) {
        pbVar9 = pbVar9 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar9 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar10 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar9 = (byte *)FUN_00423700(uVar10);
        if (*pbVar9 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar10 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar9 = (byte *)FUN_00423700(uVar10);
          if (*pbVar9 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar9 = (byte *)FUN_00423700(param_1);
            if (*pbVar9 < 0x81) goto LAB_004bf107;
          }
        }
      }
    }
    param_1 = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar3 = FUN_00492f80();
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          (*pcVar8)(0xc000008c,1,0,0);
          puVar5 = *(undefined4 **)(in_ECX + 0x54);
        }
        else {
          puVar5 = (undefined4 *)(*(int *)(in_ECX + 0x54) + iVar3 * 0x44);
        }
        iVar4 = iVar3 * 0x44;
        *puVar5 = *(undefined4 *)(in_ECX + 0xc);
        puVar5[1] = *(undefined4 *)(in_ECX + 0x10);
        puVar5[2] = *(undefined4 *)(in_ECX + 0x14);
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar4;
        }
        *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(in_ECX + 0x18);
        *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(in_ECX + 0x1c);
        *(undefined4 *)(iVar6 + 0x14) = *(undefined4 *)(in_ECX + 0x20);
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar4;
        }
        *(undefined4 *)(iVar6 + 0x28) = 0x40d00000;
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar4;
        }
        *(undefined4 *)(iVar6 + 0x2c) = 0;
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar4;
        }
        *(undefined4 *)(iVar6 + 0x30) = 0x3f490fdb;
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar4;
        }
        *(undefined4 *)(iVar6 + 0x34) = 0xffffffff;
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar4;
        }
        *(undefined4 *)(iVar6 + 0x38) = 0;
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar4;
        }
        *(undefined4 *)(iVar6 + 0x3c) = 0x10000;
        pcVar8 = RaiseException_exref;
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar4 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54) + iVar4;
        }
        *(undefined1 *)(iVar4 + 0x40) = 0;
        param_1 = param_1 + 1;
      } while ((int)param_1 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004bf107:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar3 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    iVar4 = 0;
    do {
      if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = *(int *)(in_ECX + 0x54);
        iVar7 = iVar6;
      }
      else {
        iVar6 = *(int *)(in_ECX + 0x54);
        iVar7 = iVar6 + iVar4;
      }
      if (*(int *)(iVar7 + 0x2c) != -10000) {
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar7 = iVar6;
        }
        else {
          iVar7 = iVar4 + iVar6;
        }
        uVar10 = *(uint *)(iVar7 + 0x2c);
        if (uVar10 < 9) {
          bVar1 = (&DAT_007244a4)[uVar10];
          bVar2 = (&DAT_007244b0)[uVar10];
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = iVar4 + iVar6;
          }
          *(uint *)(iVar6 + 0x3c) = (uint)bVar1 * 0x10000 + (uint)bVar2;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + iVar4;
          }
          *(float *)(iVar6 + 0x28) = *(float *)(iVar6 + 0x28) + 0.05;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + iVar4;
          }
          *(int *)(iVar6 + 0x2c) = *(int *)(iVar6 + 0x2c) + 1;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + iVar4;
          }
          if (*(int *)(iVar6 + 0x2c) < 10) goto LAB_004bf259;
        }
        FUN_00493010(iVar3);
      }
LAB_004bf259:
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x44;
    } while (iVar3 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

