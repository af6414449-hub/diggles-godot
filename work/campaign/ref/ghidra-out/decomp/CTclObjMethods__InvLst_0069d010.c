
undefined4
CTclObjMethods__InvLst(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  void *lp;
  BOOL BVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  int local_3c;
  char local_38;
  int *local_34;
  int *local_30;
  int local_2c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711f2d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7b40) &&
     (FUN_006cebf4(&DAT_00ca7b40,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7b40 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7b44 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::InvLst()";
    *(int *)(&DAT_00773650 + iVar5) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7b40);
  }
  iVar5 = DAT_00ca7b44;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7b44 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar6;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar1 == 0) {
    uVar7 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_005c71c0(param_4,2,1);
  if (iVar1 == 0) {
    uVar6 = 1;
  }
  else {
    iVar1 = FUN_005cf210();
    local_14 = (int *)Tcl_NewListObj(0,0);
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
    iVar5 = 0;
    if (0 < iVar1) {
      do {
        lp = (void *)FUN_005cef70(iVar5);
        if ((((lp == (void *)0x0) || (BVar2 = IsBadReadPtr(lp,0x10), BVar2 != 0)) ||
            (*(int *)((int)lp + 8) != 0x616e4f62)) ||
           ((DAT_00768398 != '\0' && (*(int *)((int)lp + 0xdc) == 0)))) {
          uVar6 = 1;
          piVar4 = local_14;
          goto LAB_0069d1e2;
        }
        FUN_005cef70(iVar5);
        iVar3 = FUN_005caf90();
        if (iVar3 == 0) {
          piVar4 = (int *)0x0;
        }
        else {
          piVar4 = (int *)Tcl_NewStringObj(iVar3,0xffffffff);
          *piVar4 = *piVar4 + 1;
        }
        local_18 = piVar4;
        FUN_006bb930(&local_18);
        if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
          TclFreeObj(piVar4);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    piVar4 = local_14;
    if (local_3c != 0) {
      if (local_14 == (int *)0x0) {
        Tcl_ResetResult(local_3c);
      }
      else {
        Tcl_SetObjResult(local_3c,local_14);
      }
    }
    uVar6 = 0;
LAB_0069d1e2:
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_2c != 0) {
    FUN_006ba940();
  }
  if ((local_38 != '\0') && (local_3c != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_3c);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 5;
  if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  if ((local_34 != (int *)0x0) && (*local_34 = *local_34 + -1, *local_34 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

