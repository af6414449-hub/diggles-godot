
undefined4
CTclObjMethods__TaskListGet
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined8 uVar8;
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
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c18) &&
     (FUN_006cebf4(&DAT_00ca7c18,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7c18 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7c1c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::TaskListGet()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7c18);
  }
  iVar5 = DAT_00ca7c1c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c1c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_005c71c0(param_4,3,1);
  if (iVar2 == 0) {
    uVar7 = 1;
    goto LAB_006a19b0;
  }
  if (local_20 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_28;
    if (local_24 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_24 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_28 + 2;
  }
  piVar1 = (int *)*puVar6;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0;
  }
  else {
    iVar2 = Tcl_GetIntFromObj(0,piVar1,&local_14);
    uVar3 = -(uint)(iVar2 != 1) & (uint)local_14;
  }
  piVar4 = (int *)FUN_005cdd80(&local_14,uVar3);
  if (*piVar4 + 0xc == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)Tcl_NewStringObj(*piVar4 + 0xc,0xffffffff);
    *piVar4 = *piVar4 + 1;
  }
  if (local_38 == 0) {
    if (piVar4 != (int *)0x0) goto LAB_006a197c;
  }
  else if (piVar4 == (int *)0x0) {
    Tcl_ResetResult(local_38);
  }
  else {
    Tcl_SetObjResult(local_38,piVar4);
LAB_006a197c:
    *piVar4 = *piVar4 + -1;
    if (*piVar4 < 1) {
      TclFreeObj(piVar4);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  uVar7 = 0;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
LAB_006a19b0:
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
  return uVar7;
}

