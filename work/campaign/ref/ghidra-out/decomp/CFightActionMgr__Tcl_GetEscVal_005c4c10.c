
undefined4
CFightActionMgr__Tcl_GetEscVal
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined **ppuVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  code *pcVar10;
  undefined8 uVar11;
  int local_40;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int *local_20;
  int *local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070812d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6600) &&
     (FUN_006cebf4(&DAT_00ca6600,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca6600 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca6604 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CFightActionMgr::Tcl_GetEscVal()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6600);
  }
  iVar7 = DAT_00ca6604;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6604 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar11 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 3) {
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_30 + 1;
    }
    piVar1 = (int *)*puVar9;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_20 = piVar1;
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_30 + 2;
    }
    piVar2 = (int *)*puVar9;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    local_1c = piVar2;
    if (piVar1 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar5);
    iVar4 = DAT_00772478;
    cVar3 = FUN_006037d0(&local_18,&local_14);
    if (cVar3 == '\0') {
      param_3 = 0;
    }
    else {
      if (*(uint *)(iVar4 + 0x801c) <= local_14) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      param_3 = *(int *)(*(int *)(iVar4 + 0x8018) + local_14 * 4);
    }
    local_8._0_1_ = 5;
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    if (param_3 == 0) {
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      FUN_006bc6a0("unknown class",piVar1);
      uVar8 = 1;
    }
    else {
      local_18 = *(int **)(param_3 + 8);
      if (piVar2 == (int *)0x0) {
        param_3 = 0;
      }
      else {
        iVar4 = Tcl_GetIntFromObj(0,piVar2,&local_20);
        param_3 = -(uint)(iVar4 != 1) & (uint)local_20;
      }
      iVar4 = FUN_005bbb20();
      local_14 = iVar4 + 0x20;
      local_18 = (int *)FUN_005c4470(local_18);
      if (((local_18 != (int *)0xffffffff) && (param_3 + 1 < 9)) &&
         (*(int **)(local_14 + 4) <= local_18)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar6 = (int *)FUN_006bad90();
      if (local_40 != 0) {
        if (*piVar6 == 0) {
          Tcl_ResetResult(local_40);
        }
        else {
          Tcl_SetObjResult(local_40,*piVar6);
        }
      }
      if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c < 1)) {
        TclFreeObj(local_1c);
      }
      uVar8 = 0;
    }
    pcVar10 = TclFreeObj_exref;
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, pcVar10 = TclFreeObj_exref, *piVar2 < 1))
    {
      TclFreeObj(piVar2);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      (*pcVar10)(piVar1);
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar8 = 1;
  }
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

