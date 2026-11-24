
undefined4 TclCmd_ai_getprodlocations(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  undefined **ppuVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int *piVar10;
  double dVar11;
  char *pcVar12;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_58;
  float local_54;
  float local_50;
  float local_4c;
  int *local_48;
  int *local_44;
  int *local_40;
  undefined4 local_3c;
  float local_38;
  undefined1 local_34 [4];
  float fStack_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fae15;
  local_10 = ExceptionList;
  uVar5 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_006bc170(param_2);
  local_8 = 0;
  if (param_3 != 4) {
    FUN_006bc8f0(3);
    goto LAB_0042eacb;
  }
  piVar1 = *(int **)(param_4 + 4);
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  piVar2 = *(int **)(param_4 + 8);
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  piVar3 = *(int **)(param_4 + 0xc);
  if (piVar3 != (int *)0x0) {
    *piVar3 = *piVar3 + 1;
  }
  local_8 = 3;
  local_48 = piVar3;
  local_44 = piVar2;
  local_40 = piVar1;
  if (piVar1 == (int *)0x0) {
    ppuVar6 = &PTR_0071ce50;
  }
  else {
    ppuVar6 = (undefined **)Tcl_GetStringFromObj(piVar1,0,uVar5);
  }
  FUN_006b8fb0(ppuVar6);
  iVar7 = DAT_00772478;
  cVar4 = FUN_006037d0(&local_18,&local_14);
  if (cVar4 == '\0') {
    piVar10 = (int *)0x0;
  }
  else {
    if (*(int **)(iVar7 + 0x801c) <= local_14) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar10 = *(int **)(*(int *)(iVar7 + 0x8018) + (int)local_14 * 4);
  }
  local_8._0_1_ = 4;
  local_14 = piVar10;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (piVar10 == (int *)0x0) {
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    pcVar12 = "unknown class";
  }
  else {
    if ((((piVar2 != (int *)0x0) && (iVar7 = Tcl_ListObjIndex(0,piVar2,0,&local_24), iVar7 == 0)) &&
        (iVar7 = Tcl_ListObjIndex(0,piVar2,1,&local_28), iVar7 == 0)) &&
       (iVar7 = Tcl_ListObjIndex(0,piVar2,2,&local_2c), iVar7 == 0)) {
      local_20 = local_24;
      if (local_24 != (int *)0x0) {
        *local_24 = *local_24 + 1;
      }
      local_1c = local_28;
      if (local_28 != (int *)0x0) {
        *local_28 = *local_28 + 1;
      }
      local_18 = local_2c;
      if (local_2c != (int *)0x0) {
        *local_2c = *local_2c + 1;
      }
      FUN_006baf40();
      FUN_006baf40();
      FUN_006baf40();
      FUN_006bad60();
      FUN_006bad60();
      FUN_006bad60();
    }
    if (local_14[5] == 0) {
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
LAB_0042e7e4:
      pcVar12 = "no default anim set";
    }
    else if (local_14[7] == 0) {
      if (piVar1 == (int *)0x0) goto LAB_0042e7e4;
      *piVar1 = *piVar1 + 1;
      pcVar12 = "no default anim set";
    }
    else {
      puVar8 = (undefined4 *)FUN_0040b900(0);
      local_24 = (int *)*puVar8;
      puVar8 = (undefined4 *)FUN_0040b900(0);
      if ((local_24 < (int *)0x100) &&
         (local_28 = *(int **)(DAT_00772400 + 0x5c8 + (int)local_24 * 4), local_28 != (int *)0x0)) {
        local_2c = (int *)FUN_00405960(*puVar8);
        if (local_2c[3] != 0) {
          if (local_2c[3] < 1) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          local_3c = *(undefined4 *)local_2c[2];
          iVar7 = FUN_004059a0(local_3c);
          local_6c = *(undefined4 *)(iVar7 + 0x44);
          local_68 = *(undefined4 *)(iVar7 + 0x48);
          local_64 = *(undefined4 *)(iVar7 + 0x4c);
          local_60 = *(undefined4 *)(iVar7 + 0x50);
          local_5c = *(undefined4 *)(iVar7 + 0x54);
          local_58 = *(uint *)(iVar7 + 0x58);
          dVar11 = (double)(ulonglong)local_58;
          if (((piVar2 == (int *)0x0) ||
              (iVar7 = Tcl_ListObjIndex(0,piVar2,0,&local_2c), iVar7 != 0)) ||
             ((iVar7 = Tcl_ListObjIndex(0,piVar2,1,&local_28), iVar7 != 0 ||
              (iVar7 = Tcl_ListObjIndex(0,piVar2,2,&local_14), iVar7 != 0)))) {
            local_54 = 0.0;
            local_50 = 0.0;
            local_4c = 0.0;
          }
          else {
            local_18 = local_2c;
            if (local_2c != (int *)0x0) {
              *local_2c = *local_2c + 1;
            }
            local_1c = local_28;
            if (local_28 != (int *)0x0) {
              *local_28 = *local_28 + 1;
            }
            local_20 = local_14;
            if (local_14 != (int *)0x0) {
              *local_14 = *local_14 + 1;
            }
            FUN_006baf40();
            fStack_30 = (float)dVar11;
            dVar11 = (double)CONCAT44((int)((ulonglong)dVar11 >> 0x20),fStack_30);
            FUN_006baf40();
            local_38 = (float)dVar11;
            dVar11 = (double)CONCAT44((int)((ulonglong)dVar11 >> 0x20),local_38);
            FUN_006baf40();
            local_4c = (float)dVar11;
            local_54 = fStack_30;
            local_50 = local_38;
            FUN_006bad60();
            FUN_006bad60();
            FUN_006bad60();
          }
          if (piVar3 != (int *)0x0) {
            Tcl_GetDoubleFromObj(0,piVar3,local_34);
          }
          uVar9 = FUN_0042eaf0(&local_38,&local_54,local_24,local_3c,&local_6c,&local_60);
          FUN_006bc670(uVar9);
          FUN_006bad60();
          if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
            TclFreeObj(piVar3);
          }
          if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
            TclFreeObj(piVar2);
          }
          if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
            TclFreeObj(piVar1);
          }
          FUN_006bc0d0();
          ExceptionList = local_10;
          return 0;
        }
        if (piVar1 != (int *)0x0) {
          *piVar1 = *piVar1 + 1;
        }
        pcVar12 = "invalid anim";
      }
      else {
        if (piVar1 != (int *)0x0) {
          *piVar1 = *piVar1 + 1;
        }
        pcVar12 = "invalid database";
      }
    }
  }
  FUN_006bc6a0(pcVar12,piVar1);
  if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
    TclFreeObj(piVar3);
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    TclFreeObj(piVar2);
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
LAB_0042eacb:
  FUN_006bc0d0();
  ExceptionList = local_10;
  return 1;
}

