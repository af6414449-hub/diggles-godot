
undefined4
CTclObjMethods__TaskListLst
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int local_40;
  char local_3c;
  int *local_38;
  int *local_34;
  int local_30;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00712115;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c20) &&
     (FUN_006cebf4(&DAT_00ca7c20,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7c20 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7c24 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::TaskListLst()";
    *(int *)(&DAT_00773650 + iVar3) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7c20);
  }
  iVar3 = DAT_00ca7c24;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c24 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar1 == 0) {
    uVar5 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_1c = FUN_005c71c0(param_4,2,1);
  if (local_1c == 0) {
    uVar4 = 1;
  }
  else {
    iVar1 = *(int *)(local_1c + 100);
    local_18 = (int *)Tcl_NewListObj(0,0);
    if (local_18 != (int *)0x0) {
      *local_18 = *local_18 + 1;
    }
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        local_8._0_1_ = 3;
        piVar2 = (int *)FUN_005cdd80(&local_20,iVar3);
        if (*piVar2 + 0xc == 0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = (int *)Tcl_NewStringObj(*piVar2 + 0xc,0xffffffff);
          *piVar2 = *piVar2 + 1;
        }
        local_14 = piVar2;
        FUN_006bb930(&local_14);
        if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
          TclFreeObj(piVar2);
        }
        local_8._0_1_ = 4;
        if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
          FUN_006ba940();
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
    piVar2 = local_18;
    local_8._0_1_ = 3;
    if (local_40 != 0) {
      if (local_18 == (int *)0x0) {
        Tcl_ResetResult(local_40);
        uVar4 = 0;
        goto LAB_006a1c0a;
      }
      Tcl_SetObjResult(local_40,local_18);
    }
    uVar4 = 0;
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
  }
LAB_006a1c0a:
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_30 != 0) {
    FUN_006ba940();
  }
  if ((local_3c != '\0') && (local_40 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_40);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 7;
  if ((local_34 != (int *)0x0) && (*local_34 = *local_34 + -1, *local_34 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

