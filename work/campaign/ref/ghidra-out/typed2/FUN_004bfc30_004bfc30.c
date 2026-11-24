
void FUN_004bfc30(uint param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  int iVar5;
  code *pcVar6;
  uint uVar7;
  
  pcVar6 = RaiseException_exref;
  if ((*(byte *)(in_ECX + 0x5c) & 1) != 0) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar1 = FUN_00592f10(PTR_0077241c);
      pbVar2 = (byte *)(iVar1 + 0x34);
      if (param_1 < 8) {
        pbVar2 = pbVar2 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar2 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        iVar1 = FUN_00592f10(PTR_0077241c);
        pbVar2 = (byte *)(iVar1 + 0x34);
        if (param_1 < 8) {
          pbVar2 = pbVar2 + param_1;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (*pbVar2 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar7 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar2 = (byte *)FUN_00423700(uVar7);
          if (*pbVar2 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar2 = (byte *)FUN_00423700(param_1);
            if (*pbVar2 < 0x81) goto LAB_004bffc6;
          }
        }
      }
    }
    param_1 = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar1 = FUN_00492f80();
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          (*pcVar6)(0xc000008c,1,0,0);
          puVar4 = *(undefined4 **)(in_ECX + 0x54);
        }
        else {
          puVar4 = (undefined4 *)(*(int *)(in_ECX + 0x54) + iVar1 * 0x44);
        }
        iVar3 = iVar1 * 0x44;
        *puVar4 = *(undefined4 *)(in_ECX + 0xc);
        puVar4[1] = *(undefined4 *)(in_ECX + 0x10);
        puVar4[2] = *(undefined4 *)(in_ECX + 0x14);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(in_ECX + 0x18);
        *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(in_ECX + 0x1c);
        *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(in_ECX + 0x20);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar5 + 0x28) = 0x40d00000;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar5 + 0x2c) = 0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar5 + 0x30) = 0x3f490fdb;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar5 + 0x34) = 0xffffffff;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar5 + 0x38) = 0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar5 + 0x3c) = 0x10000;
        pcVar6 = RaiseException_exref;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined1 *)(iVar3 + 0x40) = 0;
        param_1 = param_1 + 1;
      } while ((int)param_1 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004bffc6:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar1 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    param_1 = 0;
    do {
      if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
        (*pcVar6)(0xc000008c,1,0,0);
        iVar3 = *(int *)(in_ECX + 0x54);
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x54) + param_1;
      }
      if (*(int *)(iVar3 + 0x2c) != -10000) {
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          (*pcVar6)(0xc000008c,1,0,0);
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          (*pcVar6)(0xc000008c,1,0,0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + param_1;
        }
        *(undefined4 *)(iVar3 + 0x3c) = 0x20005;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          (*pcVar6)(0xc000008c,1,0,0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + param_1;
        }
        *(float *)(iVar3 + 0x28) = *(float *)(iVar3 + 0x28) + 0.1;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          (*pcVar6)(0xc000008c,1,0,0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + param_1;
        }
        *(int *)(iVar3 + 0x2c) = *(int *)(iVar3 + 0x2c) + 1;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          (*pcVar6)(0xc000008c,1,0,0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + param_1;
        }
        if (0x30 < *(int *)(iVar3 + 0x2c)) {
          FUN_00493010(iVar1);
        }
      }
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 0x44;
    } while (iVar1 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

