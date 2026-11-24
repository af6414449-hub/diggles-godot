
undefined4
CTclGlobalMethods__CheckMethod(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined **ppuVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  code *pcVar10;
  undefined8 uVar11;
  int local_40;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c1dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6d08) &&
     (FUN_006cebf4(&DAT_00ca6d08,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca6d08 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca6d0c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::CheckMethod()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6d08);
  }
  iVar7 = DAT_00ca6d0c;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6d0c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar9;
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
  local_8._0_1_ = 2;
  if (param_3 == 3) {
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_30 + 1;
    }
    piVar1 = (int *)*puVar8;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_30 + 2;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,4);
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
    local_8._0_1_ = 4;
    if (param_3 == 0) {
      if (local_28 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_30;
        if (local_2c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_2c < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar8 = local_30 + 1;
      }
      piVar6 = (int *)*puVar8;
      if (piVar6 != (int *)0x0) {
        *piVar6 = *piVar6 + 1;
      }
      FUN_006bc6a0("unknown class",piVar6);
      uVar9 = 1;
    }
    else {
      if (piVar2 == (int *)0x0) {
        ppuVar5 = &PTR_0071ce50;
      }
      else {
        ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
      }
      FUN_006b8fb0(ppuVar5);
      iVar4 = FUN_00601d30(&local_18);
      local_8._0_1_ = 6;
      if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
        FUN_006ba940();
      }
      piVar6 = (int *)Tcl_NewBooleanObj(iVar4 != -1);
      *piVar6 = *piVar6 + 1;
      iVar4 = *piVar6;
      if (local_40 != 0) {
        Tcl_SetObjResult(local_40,piVar6);
        iVar4 = *piVar6;
      }
      *piVar6 = iVar4 + -1;
      if (iVar4 + -1 < 1) {
        TclFreeObj(piVar6);
      }
      uVar9 = 0;
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
    uVar9 = 1;
  }
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

