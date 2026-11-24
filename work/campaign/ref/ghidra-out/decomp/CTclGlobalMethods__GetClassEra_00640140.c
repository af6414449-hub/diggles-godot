
undefined4
CTclGlobalMethods__GetClassEra
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  undefined **ppuVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  int local_38;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d7c5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7058) &&
     (FUN_006cebf4(&DAT_00ca7058,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7058 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca705c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::GetClassEra()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7058);
  }
  iVar7 = DAT_00ca705c;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca705c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar9;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar10 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar2 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (uVar2 == 2) {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_28 + 1;
    }
    piVar1 = (int *)*puVar8;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    iVar4 = DAT_00772478;
    local_8 = CONCAT31(local_8._1_3_,3);
    if (piVar1 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar5);
    cVar3 = FUN_006037d0(&local_14,&param_3);
    if (cVar3 == '\0') {
      iVar4 = 0;
    }
    else {
      if (*(uint *)(iVar4 + 0x801c) <= param_3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar4 = *(int *)(*(int *)(iVar4 + 0x8018) + param_3 * 4);
    }
    local_8._0_1_ = 4;
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (iVar4 == 0) {
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      FUN_006bc6a0("unknown class",piVar1);
      uVar9 = 1;
    }
    else {
      piVar6 = (int *)Tcl_NewIntObj(*(undefined4 *)(iVar4 + 0x60));
      *piVar6 = *piVar6 + 1;
      iVar4 = *piVar6;
      if (local_38 != 0) {
        Tcl_SetObjResult(local_38,piVar6);
        iVar4 = *piVar6;
      }
      *piVar6 = iVar4 + -1;
      if (iVar4 + -1 < 1) {
        TclFreeObj(piVar6);
      }
      uVar9 = 0;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar9 = 1;
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

