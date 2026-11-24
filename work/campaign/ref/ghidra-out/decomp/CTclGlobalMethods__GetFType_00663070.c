
undefined4
CTclGlobalMethods__GetFType(undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  float fVar8;
  undefined8 uVar9;
  undefined1 uVar10;
  int local_58;
  undefined4 *local_48;
  uint local_44;
  int local_40;
  double local_3c;
  double local_34;
  double local_2c;
  double local_24;
  undefined4 *local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f455;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7400) &&
     (FUN_006cebf4(&DAT_00ca7400,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7400 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7404 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::GetFType()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7400);
  }
  iVar5 = DAT_00ca7404;
  local_1c = &DAT_00ca7404;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7404 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar6;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == 4.2039e-45) {
    FUN_004298b0(3,param_4);
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_48 + 1;
    }
    piVar4 = (int *)*puVar7;
    if (piVar4 == (int *)0x0) {
      DAT_00772dd8 = 0;
      local_18 = DAT_00772dd8;
    }
    else {
      *piVar4 = *piVar4 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar4,&local_24);
      if (iVar3 == 1) {
        param_3 = 0.0;
      }
      else {
        param_3 = (float)local_24;
      }
      local_18 = (int)ROUND(param_3);
      DAT_00772dd8 = local_18;
      *piVar4 = *piVar4 + -1;
      if (*piVar4 < 1) {
        TclFreeObj(piVar4);
      }
    }
    if (local_40 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_48 + 2;
    }
    piVar4 = (int *)*puVar7;
    if (piVar4 == (int *)0x0) {
      DAT_00772dd8 = 0;
      local_14 = DAT_00772dd8;
    }
    else {
      *piVar4 = *piVar4 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar4,&local_2c);
      if (iVar3 == 1) {
        param_3 = 0.0;
      }
      else {
        param_3 = (float)local_2c;
      }
      local_14 = (int)ROUND(param_3);
      DAT_00772dd8 = local_14;
      *piVar4 = *piVar4 + -1;
      if (*piVar4 < 1) {
        TclFreeObj(piVar4);
      }
    }
    if (local_40 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_48 + 2;
    }
    piVar4 = (int *)*puVar7;
    if (piVar4 != (int *)0x0) {
      *piVar4 = *piVar4 + 1;
    }
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_48 + 1;
    }
    piVar1 = (int *)*puVar7;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (piVar4 == (int *)0x0) {
      param_3 = 0.0;
    }
    else {
      iVar3 = Tcl_GetDoubleFromObj(0,piVar4,&local_34);
      if (iVar3 == 1) {
        param_3 = 0.0;
      }
      else {
        param_3 = (float)local_34;
      }
    }
    if (piVar1 == (int *)0x0) {
      fVar8 = 0.0;
    }
    else {
      iVar3 = Tcl_GetDoubleFromObj(0,piVar1,&local_3c);
      if (iVar3 == 1) {
        fVar8 = 0.0;
      }
      else {
        fVar8 = (float)local_3c;
      }
    }
    if ((((fVar8 < *(float *)(DAT_0077241c + 0xa4) + 0.0) ||
         (*(float *)(DAT_0077241c + 0xac) - 0.0 <= fVar8)) ||
        (param_3 < *(float *)(DAT_0077241c + 0xa8) + 0.0)) ||
       (bVar2 = false, *(float *)(DAT_0077241c + 0xb0) - 0.0 <= param_3)) {
      bVar2 = true;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
    if (bVar2) {
      uVar10 = 0;
    }
    else {
      iVar3 = FUN_00592f10(local_18,local_14);
      uVar10 = *(undefined1 *)(iVar3 + 0x1b);
    }
    piVar4 = (int *)Tcl_NewIntObj(uVar10);
    *piVar4 = *piVar4 + 1;
    iVar3 = *piVar4;
    if (local_58 != 0) {
      Tcl_SetObjResult(local_58,piVar4);
      iVar3 = *piVar4;
    }
    *piVar4 = iVar3 + -1;
    if (iVar3 + -1 < 1) {
      TclFreeObj(piVar4);
    }
    uVar6 = 0;
    local_8._0_1_ = 2;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_004297b0(0);
    if (local_48 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar6 = 1;
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

