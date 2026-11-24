
void FUN_004bbbd0(uint param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int in_ECX;
  undefined4 *puVar5;
  int iVar6;
  code *pcVar7;
  byte *pbVar8;
  float fVar9;
  double dVar10;
  float in_XMM2_Da;
  uint uVar11;
  int local_1c;
  int local_18;
  
  pcVar7 = RaiseException_exref;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar2 = FUN_00592f10(PTR_0077241c);
      pbVar8 = (byte *)(iVar2 + 0x34);
      if (param_1 < 8) {
        pbVar8 = pbVar8 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar8 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar11 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar8 = (byte *)FUN_00423700(uVar11);
        if (*pbVar8 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar11 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar8 = (byte *)FUN_00423700(uVar11);
          if (*pbVar8 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar8 = (byte *)FUN_00423700(param_1);
            if (*pbVar8 < 0x81) goto LAB_004bbf9f;
          }
        }
      }
    }
    DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
    if (((DAT_00767980 >> 0x10 & 0x7fffU) < 2000) && (local_18 = 0, 0 < *(int *)(in_ECX + 0x50))) {
      do {
        iVar2 = FUN_00492f80();
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          (*pcVar7)(0xc000008c,1,0,0);
          puVar5 = *(undefined4 **)(in_ECX + 0x54);
        }
        else {
          puVar5 = (undefined4 *)(*(int *)(in_ECX + 0x54) + iVar2 * 0x44);
        }
        iVar3 = iVar2 * 0x44;
        *puVar5 = *(undefined4 *)(in_ECX + 0xc);
        puVar5[1] = *(undefined4 *)(in_ECX + 0x10);
        puVar5[2] = *(undefined4 *)(in_ECX + 0x14);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(in_ECX + 0x18);
        *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(in_ECX + 0x1c);
        *(undefined4 *)(iVar6 + 0x14) = *(undefined4 *)(in_ECX + 0x20);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar6 + 0x28) = 0x3f000000;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar6 + 0x2c) = 0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar6 + 0x30) = 0x3f490fdb;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar6 + 0x34) = 0xffffffff;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar6 + 0x38) = 0;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar6 + 0x3c) = 0x40005;
        pcVar7 = RaiseException_exref;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined1 *)(iVar3 + 0x40) = 0;
        local_18 = local_18 + 1;
      } while (local_18 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004bbf9f:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar2 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    iVar3 = 0;
    do {
      if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        local_1c = *(int *)(in_ECX + 0x54);
        iVar6 = local_1c;
      }
      else {
        local_1c = *(int *)(in_ECX + 0x54);
        iVar6 = local_1c + iVar3;
      }
      if (*(int *)(iVar6 + 0x2c) != -10000) {
        fVar9 = in_XMM2_Da * 0.04;
        fVar1 = *(float *)(in_ECX + 0xc);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
          local_1c = iVar6;
        }
        else {
          iVar6 = local_1c + iVar3;
        }
        dVar10 = (double)((float)*(int *)(iVar6 + 0x2c) * 0.5);
        FUN_006f6ad0();
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_1c = *(int *)(in_ECX + 0x54);
          iVar6 = local_1c;
        }
        else {
          iVar6 = iVar3 + local_1c;
        }
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar4 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar4 = (float *)(local_1c + iVar3);
        }
        *pfVar4 = ((float)dVar10 * fVar9 * (float)*(int *)(iVar6 + 0x2c)) / 30.0 + fVar1;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(float *)(iVar6 + 4) = *(float *)(iVar6 + 4) - fVar9 * 0.5;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
          local_1c = iVar6;
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar3;
          local_1c = *(int *)(in_ECX + 0x54);
        }
        dVar10 = (double)((float)*(int *)(iVar6 + 0x2c) * 0.5);
        FUN_006f5ae0();
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_1c = *(int *)(in_ECX + 0x54);
          iVar6 = local_1c;
        }
        else {
          iVar6 = iVar3 + local_1c;
        }
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_1c = *(int *)(in_ECX + 0x54);
        }
        else {
          local_1c = iVar3 + local_1c;
        }
        *(float *)(local_1c + 8) =
             ((float)dVar10 * fVar9 * (float)*(int *)(iVar6 + 0x2c)) / 30.0 +
             *(float *)(in_ECX + 0x14);
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(float *)(iVar6 + 0x28) = *(float *)(iVar6 + 0x28) + 0.05;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(int *)(iVar6 + 0x2c) = *(int *)(iVar6 + 0x2c) + 1;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x58) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        if (0x20 < *(int *)(iVar6 + 0x2c)) {
          FUN_00493010(iVar2);
        }
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x44;
    } while (iVar2 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

