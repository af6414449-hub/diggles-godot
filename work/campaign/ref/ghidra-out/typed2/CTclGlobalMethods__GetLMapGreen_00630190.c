
undefined4
CTclGlobalMethods__GetLMapGreen
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  float fVar7;
  undefined8 uVar8;
  undefined4 uVar9;
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
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6e28) &&
     (FUN_006cebf4(&DAT_00ca6e28,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6e28 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6e2c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::GetLMapGreen()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6e28);
  }
  iVar5 = DAT_00ca6e2c;
  local_18 = &DAT_00ca6e2c;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e2c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar9;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004298b0(param_3,param_4);
  if ((param_3 == 3) && ((char)PTR_0077241c->mapFlags != '\0')) {
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_34 + 1;
    }
    piVar1 = (int *)*puVar6;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_34 + 2;
    }
    piVar2 = (int *)*puVar6;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    fVar7 = 0.0;
    if (piVar1 != (int *)0x0) {
      iVar3 = Tcl_GetDoubleFromObj(0,piVar1,&local_20);
      if (iVar3 == 1) {
        fVar7 = 0.0;
      }
      else {
        fVar7 = (float)local_20;
      }
    }
    DAT_00772dd8 = (int)ROUND(fVar7 * 8.0);
    local_14 = DAT_00772dd8;
    if (piVar2 == (int *)0x0) {
      fVar7 = 0.0;
    }
    else {
      iVar3 = Tcl_GetDoubleFromObj(0,piVar2,&local_28);
      if (iVar3 == 1) {
        fVar7 = 0.0;
      }
      else {
        fVar7 = (float)local_28;
      }
    }
    DAT_00772dd8 = (int)ROUND(fVar7 * 8.0);
    if ((((local_14 < PTR_0077241c->x0_8) || (PTR_0077241c->x1_8 <= local_14)) ||
        (DAT_00772dd8 < PTR_0077241c->y0_8)) || (PTR_0077241c->y1_8 <= DAT_00772dd8)) {
      uVar9 = 0;
    }
    else {
      uVar9 = 8;
    }
    piVar4 = (int *)Tcl_NewIntObj(uVar9);
    *piVar4 = *piVar4 + 1;
    iVar3 = *piVar4;
    if (local_44 != 0) {
      Tcl_SetObjResult(local_44,piVar4);
      iVar3 = *piVar4;
    }
    *piVar4 = iVar3 + -1;
    if (iVar3 + -1 < 1) {
      TclFreeObj(piVar4);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    uVar9 = 0;
  }
  else {
    uVar9 = 1;
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
  return uVar9;
}

