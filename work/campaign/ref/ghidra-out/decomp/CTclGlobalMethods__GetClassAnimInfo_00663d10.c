
undefined4
CTclGlobalMethods__GetClassAnimInfo
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined **ppuVar5;
  undefined4 *puVar6;
  int iVar7;
  code *pcVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  int local_48;
  undefined1 local_38 [8];
  uint local_30;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int *local_20;
  undefined4 *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f4fd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7418) &&
     (FUN_006cebf4(&DAT_00ca7418,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7418 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca741c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::GetClassAnimInfo()";
    *(int *)(&DAT_00773650 + iVar7) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7418);
  }
  iVar7 = DAT_00ca741c;
  local_1c = &DAT_00ca741c;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca741c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar10;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar3 == 0) {
    uVar11 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)piVar1 < 2) {
    FUN_006bc8f0(1);
    uVar10 = 1;
  }
  else {
    piVar9 = (int *)0x0;
    local_18 = (int *)0x0;
    local_8._0_1_ = 3;
    piVar4 = (int *)FUN_006ba810(0x19);
    piVar4[1] = 0x14;
    piVar4[2] = -1;
    *(undefined1 *)(piVar4 + 3) = 0;
    *piVar4 = 1;
    local_8 = CONCAT31(local_8._1_3_,4);
    param_3 = piVar4;
    if (piVar1 == (int *)0x3) {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_2c;
        if (local_28 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar6 = local_2c;
        }
      }
      else {
        if (local_28 < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar6 = local_2c + 1;
      }
      piVar1 = (int *)*puVar6;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,5);
      local_20 = piVar1;
      if (piVar1 == (int *)0x0) {
        ppuVar5 = &PTR_0071ce50;
        piVar4 = (int *)0x0;
      }
      else {
        ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
        piVar4 = piVar1;
      }
      FUN_006b8fb0(ppuVar5);
      if ((piVar4 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
        TclFreeObj(piVar1);
      }
      piVar4 = (int *)FUN_00601f90(&local_14);
      if (local_24 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_2c;
        if (local_28 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar6 = local_2c;
        }
      }
      else {
        if (local_28 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar6 = local_2c + 2;
      }
      piVar1 = (int *)*puVar6;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,8);
      local_20 = piVar1;
      if (piVar1 == (int *)0x0) {
        FUN_006b9200(&PTR_0071ce50);
      }
      else {
        uVar10 = Tcl_GetStringFromObj(piVar1,0);
        FUN_006b9200(uVar10);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
        }
      }
      local_8 = CONCAT31(local_8._1_3_,9);
      if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
        FUN_006ba940();
      }
    }
    else if (piVar1 == (int *)0x2) {
      FUN_006b8fb0(&DAT_007210c8);
      if (local_48 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = Tcl_GetAssocData(local_48,local_14 + 3,0);
      }
      local_8._0_1_ = 10;
      if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
        FUN_006ba940();
      }
      piVar4 = param_3;
      if (iVar3 != 0) {
        piVar4 = *(int **)(iVar3 + 0xd4);
      }
      puVar6 = (undefined4 *)FUN_004295e0(1);
      piVar1 = (int *)*puVar6;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,0xb);
      local_20 = piVar1;
      if (piVar1 == (int *)0x0) {
        FUN_006b9200(&PTR_0071ce50);
      }
      else {
        uVar10 = Tcl_GetStringFromObj(piVar1,0);
        FUN_006b9200(uVar10);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
        }
      }
    }
    if (piVar4 != (int *)0x0) {
      piVar9 = (int *)0x0;
      pcVar8 = TclFreeObj_exref;
      if (piVar4[0x331] != 0) {
        cVar2 = FUN_004613d0(&param_3,local_38);
        if (cVar2 == '\0') {
          piVar9 = (int *)Tcl_NewStringObj("Illegel Anim",0xffffffff);
          pcVar8 = TclFreeObj_exref;
          iVar3 = *piVar9;
          *piVar9 = iVar3 + 1;
          if (iVar3 + 1 < 1) {
            TclFreeObj(piVar9);
          }
        }
        else {
          pcVar8 = TclFreeObj_exref;
          if (local_30 != 0xffffffff) {
            if ((uint)piVar4[0x333] <= local_30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            pcVar8 = TclFreeObj_exref;
            piVar9 = *(int **)(piVar4[0x332] + local_30 * 4);
            if (piVar9 != (int *)0x0) {
              *piVar9 = *piVar9 + 1;
            }
          }
        }
      }
      local_18 = piVar9;
      if ((piVar9 != (int *)0x0) && (iVar3 = *piVar9, *piVar9 = iVar3, iVar3 < 1)) {
        (*pcVar8)(piVar9);
      }
    }
    if (local_48 != 0) {
      if (piVar9 == (int *)0x0) {
        Tcl_ResetResult(local_48);
      }
      else {
        Tcl_SetObjResult(local_48,piVar9);
      }
    }
    uVar10 = 0;
    local_8 = CONCAT31(local_8._1_3_,0xc);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
      FUN_006ba940();
    }
    if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
      TclFreeObj(piVar9);
    }
  }
  local_8._0_1_ = 0xd;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xe);
  FUN_004297b0(0);
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar10;
}

