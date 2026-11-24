
undefined4
CTclGlobalMethods__GetHMap(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  float fVar9;
  undefined8 uVar10;
  int local_44;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  double local_28;
  double local_20;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070cb15;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6e18) &&
     (FUN_006cebf4(&DAT_00ca6e18,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca6e18 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca6e1c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::GetHMap()";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6e18);
  }
  iVar6 = DAT_00ca6e1c;
  local_18 = &DAT_00ca6e1c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e1c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar7;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar10 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004298b0(param_3,param_4);
  if ((param_3 == 3) && (*(char *)(DAT_0077241c + 0x29) != '\0')) {
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_34 + 1;
    }
    piVar1 = (int *)*puVar8;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_34 + 2;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    fVar9 = 0.0;
    if (piVar1 != (int *)0x0) {
      iVar4 = Tcl_GetDoubleFromObj(0,piVar1,&local_20);
      if (iVar4 == 1) {
        fVar9 = 0.0;
      }
      else {
        fVar9 = (float)local_20;
      }
    }
    DAT_00772dd8 = (int)ROUND(fVar9 * 8.0);
    local_14 = DAT_00772dd8;
    if (piVar2 == (int *)0x0) {
      fVar9 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,piVar2,&local_28);
      if (iVar4 == 1) {
        fVar9 = 0.0;
      }
      else {
        fVar9 = (float)local_28;
      }
    }
    DAT_00772dd8 = (int)ROUND(fVar9 * 8.0);
    if ((((local_14 < *(int *)(DAT_0077241c + 0x94)) || (*(int *)(DAT_0077241c + 0x9c) <= local_14))
        || (DAT_00772dd8 < *(int *)(DAT_0077241c + 0x98))) ||
       (*(int *)(DAT_0077241c + 0xa0) <= DAT_00772dd8)) {
      uVar3 = 0xf;
    }
    else {
      uVar3 = FUN_004093f0(local_14,DAT_00772dd8);
    }
    piVar5 = (int *)Tcl_NewIntObj(uVar3);
    *piVar5 = *piVar5 + 1;
    iVar4 = *piVar5;
    if (local_44 != 0) {
      Tcl_SetObjResult(local_44,piVar5);
      iVar4 = *piVar5;
    }
    *piVar5 = iVar4 + -1;
    if (iVar4 + -1 < 1) {
      TclFreeObj(piVar5);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

