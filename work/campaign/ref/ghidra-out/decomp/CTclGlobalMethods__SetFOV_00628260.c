
undefined4
CTclGlobalMethods__SetFOV(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  int local_38;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  double local_1c;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c295;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6d18) &&
     (FUN_006cebf4(&DAT_00ca6d18,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6d18 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6d1c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::SetFOV()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6d18);
  }
  iVar4 = DAT_00ca6d1c;
  local_14 = &DAT_00ca6d1c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6d1c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar6 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004298b0(param_3,param_4);
  if (param_3 != (int *)0x2) goto LAB_006283df;
  if (local_20 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_28;
    if (local_24 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_28 + 1;
  }
  piVar3 = (int *)*puVar5;
  if (piVar3 == (int *)0x0) {
LAB_006283c4:
    DAT_0076797c = 0.1;
    if (piVar3 == (int *)0x0) goto LAB_006283df;
  }
  else {
    *piVar3 = *piVar3 + 1;
    iVar2 = Tcl_GetDoubleFromObj(0,piVar3,&local_1c);
    if ((iVar2 == 1) || (DAT_0076797c = (float)local_1c, DAT_0076797c < 0.1)) goto LAB_006283c4;
    if (5.0 < DAT_0076797c) {
      DAT_0076797c = 5.0;
    }
  }
  *piVar3 = *piVar3 + -1;
  if (*piVar3 < 1) {
    TclFreeObj(piVar3);
  }
LAB_006283df:
  piVar3 = (int *)FUN_006bad90();
  if (local_38 != 0) {
    if (*piVar3 == 0) {
      Tcl_ResetResult(local_38);
    }
    else {
      Tcl_SetObjResult(local_38,*piVar3);
    }
  }
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
    TclFreeObj(param_3);
  }
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

