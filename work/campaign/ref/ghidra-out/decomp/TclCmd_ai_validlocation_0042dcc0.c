
undefined4 TclCmd_ai_validlocation(int param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 extraout_ECX;
  undefined4 uVar7;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  char *pcVar11;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_58;
  undefined8 local_54;
  float local_4c;
  undefined4 *local_48;
  uint local_44;
  int local_40;
  int *local_3c;
  int *local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  double dVar8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fada8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_006bc170(param_2);
  iVar5 = (int)param_3;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  if (iVar5 != 3) {
    FUN_006bc8f0(2);
    local_8._0_1_ = 2;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_004297b0(0);
    if (local_48 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    ExceptionList = local_10;
    return 0;
  }
  if (local_40 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_48;
    if (local_44 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_48;
    }
  }
  else {
    if (local_44 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_48 + 1;
  }
  piVar1 = (int *)*puVar6;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_38 = piVar1;
  if (local_40 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_48;
    if (local_44 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_48;
    }
  }
  else {
    if (local_44 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_48 + 2;
  }
  piVar2 = (int *)*puVar6;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  local_3c = piVar2;
  if (piVar1 == (int *)0x0) {
    ppuVar4 = &PTR_0071ce50;
  }
  else {
    ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
  }
  FUN_006b8fb0(ppuVar4);
  param_3 = (int *)DAT_00772478;
  cVar3 = FUN_006037d0(&local_18,&local_14);
  if (cVar3 == '\0') {
    param_3 = (int *)0x0;
  }
  else {
    if (*(int **)((int)param_3 + 0x801c) <= local_14) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    param_3 = *(int **)(*(int *)((int)param_3 + 0x8018) + (int)local_14 * 4);
  }
  local_8._0_1_ = 6;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  if (param_3 == (int *)0x0) {
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("unknown class",piVar1);
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    local_8._0_1_ = 7;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,8);
  }
  else {
    if ((((piVar2 != (int *)0x0) && (iVar5 = Tcl_ListObjIndex(0,piVar2,0,&local_20), iVar5 == 0)) &&
        (iVar5 = Tcl_ListObjIndex(0,piVar2,1,&local_24), iVar5 == 0)) &&
       (iVar5 = Tcl_ListObjIndex(0,piVar2,2,&local_28), iVar5 == 0)) {
      local_1c = local_20;
      if (local_20 != (int *)0x0) {
        *local_20 = *local_20 + 1;
      }
      local_14 = local_24;
      if (local_24 != (int *)0x0) {
        *local_24 = *local_24 + 1;
      }
      local_18 = local_28;
      if (local_28 != (int *)0x0) {
        *local_28 = *local_28 + 1;
      }
      FUN_006baf40();
      FUN_006baf40();
      FUN_006baf40();
      FUN_006bad60();
      FUN_006bad60();
      FUN_006bad60();
    }
    if (param_3[5] != 0) {
      if (param_3[7] == 0) {
        if (piVar1 != (int *)0x0) {
          *piVar1 = *piVar1 + 1;
        }
        pcVar11 = "no default anim set";
      }
      else {
        puVar6 = (undefined4 *)FUN_0040b900(0);
        local_14 = (int *)*puVar6;
        puVar6 = (undefined4 *)FUN_0040b900(0);
        if ((local_14 < (int *)0x100) &&
           (local_28 = *(int **)(DAT_00772400 + 0x5c8 + (int)local_14 * 4), local_28 != (int *)0x0))
        {
          param_3 = (int *)FUN_00405960(*puVar6);
          if (param_3[3] != 0) {
            if (param_3[3] < 1) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            local_34 = *(undefined4 *)param_3[2];
            iVar5 = FUN_004059a0(local_34);
            local_6c = *(undefined4 *)(iVar5 + 0x44);
            local_68 = *(undefined4 *)(iVar5 + 0x48);
            local_64 = *(undefined4 *)(iVar5 + 0x4c);
            local_60 = *(undefined4 *)(iVar5 + 0x50);
            local_5c = *(undefined4 *)(iVar5 + 0x54);
            local_58 = *(uint *)(iVar5 + 0x58);
            auVar9 = ZEXT416(local_58);
            if (((piVar2 == (int *)0x0) ||
                (iVar5 = Tcl_ListObjIndex(0,piVar2,0,&local_28), iVar5 != 0)) ||
               ((iVar5 = Tcl_ListObjIndex(0,piVar2,1,&local_24), iVar5 != 0 ||
                (iVar5 = Tcl_ListObjIndex(0,piVar2,2,&local_20), iVar5 != 0)))) {
              local_54 = 0;
              local_4c = 0.0;
            }
            else {
              local_18 = local_28;
              if (local_28 != (int *)0x0) {
                *local_28 = *local_28 + 1;
              }
              local_1c = local_24;
              if (local_24 != (int *)0x0) {
                *local_24 = *local_24 + 1;
              }
              param_3 = local_20;
              if (local_20 != (int *)0x0) {
                *local_20 = *local_20 + 1;
              }
              FUN_006baf40();
              auVar9._0_4_ = (float)auVar9._0_8_;
              local_2c = auVar9._0_4_;
              FUN_006baf40();
              auVar10._4_12_ = auVar9._4_12_;
              auVar10._0_4_ = (float)auVar9._0_8_;
              dVar8 = auVar10._0_8_;
              local_30 = auVar10._0_4_;
              FUN_006baf40();
              local_4c = (float)dVar8;
              local_54 = CONCAT44(local_30,local_2c);
              FUN_006bad60();
              FUN_006bad60();
              FUN_006bad60();
            }
            FUN_00595770(&local_78,&local_54,(int)&param_3 + 3);
            local_4c = (float)local_70;
            local_54 = local_78;
            cVar3 = FUN_005e76a0(local_34,*(undefined4 *)(param_1 + 0x14));
            if (cVar3 == '\0') {
              uVar7 = 1;
              cVar3 = FUN_005e6be0(&local_60,0xffffffff,0xffffffff,*(undefined4 *)(param_1 + 0x14),
                                   extraout_ECX);
              if (cVar3 != '\0') {
                uVar7 = 0;
              }
            }
            else {
              uVar7 = 0;
            }
            param_3 = (int *)Tcl_NewBooleanObj(uVar7);
            *param_3 = *param_3 + 1;
            FUN_006bc670(&param_3);
            FUN_006bad60();
            if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
              TclFreeObj(piVar2);
            }
            if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
              TclFreeObj(piVar1);
            }
            FUN_00429650();
            FUN_006bc0d0();
            ExceptionList = local_10;
            return 0;
          }
          if (piVar1 != (int *)0x0) {
            *piVar1 = *piVar1 + 1;
          }
          pcVar11 = "invalid anim";
        }
        else {
          if (piVar1 != (int *)0x0) {
            *piVar1 = *piVar1 + 1;
          }
          pcVar11 = "invalid database";
        }
      }
      FUN_006bc6a0(pcVar11,piVar1);
      if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
        TclFreeObj(piVar2);
      }
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
        TclFreeObj(piVar1);
      }
      FUN_00429650();
      goto LAB_0042e31d;
    }
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("no default anim set",piVar1);
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    local_8._0_1_ = 9;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,10);
  }
  FUN_004297b0(0);
  if (local_48 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
LAB_0042e31d:
  FUN_006bc0d0();
  ExceptionList = local_10;
  return 1;
}

