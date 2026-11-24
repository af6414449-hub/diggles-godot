
undefined4
CTclGlobalMethods__VectorUnpackY
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  int local_30;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070b7cd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6f90) &&
     (FUN_006cebf4(&DAT_00ca6f90,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6f90 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca6f94 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::VectorUnpackY()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6f90);
  }
  iVar3 = DAT_00ca6f94;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6f94 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar4;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)piVar1 < 2) {
    FUN_006bc8f0(1);
    uVar4 = 1;
    goto LAB_006398b9;
  }
  if (local_18 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_20;
    if (local_1c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_20 + 1;
  }
  piVar1 = (int *)*puVar6;
  if (piVar1 == (int *)0x0) {
LAB_0063986b:
    piVar5 = (int *)0x0;
  }
  else {
    *piVar1 = *piVar1 + 1;
    iVar2 = Tcl_ListObjIndex(0,piVar1,1,&param_3);
    if (iVar2 != 0) goto LAB_0063986b;
    piVar5 = param_3;
    if (param_3 != (int *)0x0) {
      *param_3 = *param_3 + 1;
    }
  }
  if (local_30 == 0) {
    if (piVar5 != (int *)0x0) goto LAB_00639892;
  }
  else if (piVar5 == (int *)0x0) {
    Tcl_ResetResult(local_30);
  }
  else {
    Tcl_SetObjResult(local_30,piVar5);
LAB_00639892:
    *piVar5 = *piVar5 + -1;
    if (*piVar5 < 1) {
      TclFreeObj(piVar5);
    }
  }
  uVar4 = 0;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
LAB_006398b9:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

