
undefined4
CTclObjMethods__SetRot(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  code *pcVar8;
  float fVar9;
  float fVar10;
  undefined8 uVar11;
  float local_58;
  float local_50;
  undefined4 *local_4c;
  uint local_48;
  int local_44;
  undefined4 local_3c;
  undefined4 uStack_38;
  int *local_30;
  int *local_2c;
  undefined4 local_28;
  int *piStack_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071139d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7758) &&
     (FUN_006cebf4(), iVar5 = DAT_00783650, DAT_00ca7758 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca775c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclObjMethods::SetRot()";
    *(int *)(&DAT_00773650 + iVar7) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar7 = DAT_00ca775c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca775c * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar1;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar5 == 0) {
    uVar11 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_004298b0(param_3);
  local_8._0_1_ = 1;
  iVar5 = FUN_005c71c0(param_4,3);
  if (iVar5 == 0) {
    local_8._0_1_ = 2;
    FUN_004297b0();
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_004297b0();
    if (local_4c != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  if (param_3 == 3) {
    if (local_44 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_4c + 2;
    }
    piVar2 = (int *)*puVar6;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8._0_1_ = 4;
    FUN_006bafe0();
    if ((*(int *)(iVar5 + 0xe8) == 1) && ((0.1 < ABS(local_58) || (0.1 < ABS(local_50))))) {
      local_8._0_1_ = 5;
      FUN_006bc170(param_2);
      local_8 = CONCAT31(local_8._1_3_,7);
      FUN_006bc6a0("gnome xz-rot!=0");
      FUN_006bc0d0();
      if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
        TclFreeObj();
      }
      local_8._0_1_ = 8;
      FUN_004297b0();
      local_8 = CONCAT31(local_8._1_3_,9);
      FUN_004297b0();
      if (local_4c != (undefined4 *)0x0) {
        FUN_006ba940();
      }
      FUN_0043fd30();
      ExceptionList = local_10;
      return 1;
    }
    if (piVar2 == (int *)0x0) {
      FUN_005cd840();
    }
    else {
      iVar5 = Tcl_ListObjIndex(0,piVar2,0);
      if (((iVar5 == 0) && (iVar5 = Tcl_ListObjIndex(0,piVar2,1), iVar5 == 0)) &&
         (iVar5 = Tcl_ListObjIndex(0,piVar2,2), iVar5 == 0)) {
        if (piStack_24 != (int *)0x0) {
          *piStack_24 = *piStack_24 + 1;
        }
        if (local_2c != (int *)0x0) {
          *local_2c = *local_2c + 1;
        }
        if (local_30 != (int *)0x0) {
          *local_30 = *local_30 + 1;
        }
        FUN_006baf40();
        FUN_006baf40();
        FUN_006baf40();
        FUN_006bad60();
        FUN_006bad60();
        FUN_006bad60();
      }
      FUN_005cd840();
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        TclFreeObj();
      }
    }
  }
  else {
    if (local_44 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_4c + 2;
    }
    piVar2 = (int *)*puVar6;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    if (local_44 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_4c + 3;
    }
    piVar3 = (int *)*puVar6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8._0_1_ = 0xb;
    if (piVar2 == (int *)0x0) {
      fVar9 = 0.0;
    }
    else {
      iVar7 = Tcl_GetDoubleFromObj(0,piVar2);
      if (iVar7 == 1) {
        fVar9 = 0.0;
      }
      else {
        fVar9 = (float)(double)CONCAT44(uStack_38,local_3c);
      }
    }
    if (piVar3 != (int *)0x0) {
      Tcl_GetDoubleFromObj(0,piVar3);
    }
    if (param_3 == 5) {
      puVar6 = (undefined4 *)FUN_004295e0();
      piVar4 = (int *)*puVar6;
      if (piVar4 == (int *)0x0) {
        fVar10 = 0.0;
      }
      else {
        *piVar4 = *piVar4 + 1;
        iVar7 = Tcl_GetDoubleFromObj(0,piVar4);
        if (iVar7 == 1) {
          fVar10 = 0.0;
        }
        else {
          fVar10 = (float)(double)CONCAT44(piStack_24,local_28);
        }
        *piVar4 = *piVar4 + -1;
        if (*piVar4 < 1) {
          TclFreeObj();
        }
      }
    }
    else {
      fVar10 = 14.0;
    }
    if ((*(int *)(iVar5 + 0xe8) == 1) && ((0.1 < ABS(fVar9) || (0.1 < ABS(fVar10))))) {
      local_8._0_1_ = 0xc;
      FUN_006bc170(param_2);
      local_8 = CONCAT31(local_8._1_3_,0xe);
      FUN_006bc6a0("gnome xz-rot!=0");
      FUN_006bc0d0();
      pcVar8 = TclFreeObj_exref;
      if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, pcVar8 = TclFreeObj_exref, *piVar3 < 1)
         ) {
        TclFreeObj();
      }
      if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
        (*pcVar8)();
      }
      local_8._0_1_ = 0xf;
      FUN_004297b0();
      local_8 = CONCAT31(local_8._1_3_,0x10);
      FUN_004297b0();
      if (local_4c != (undefined4 *)0x0) {
        FUN_006ba940();
      }
      FUN_0043fd30();
      ExceptionList = local_10;
      return 1;
    }
    FUN_005cd840();
    pcVar8 = TclFreeObj_exref;
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, pcVar8 = TclFreeObj_exref, *piVar3 < 1))
    {
      TclFreeObj();
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      (*pcVar8)();
    }
  }
  local_8._0_1_ = 0x11;
  FUN_004297b0();
  local_8 = CONCAT31(local_8._1_3_,0x12);
  FUN_004297b0();
  if (local_4c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

