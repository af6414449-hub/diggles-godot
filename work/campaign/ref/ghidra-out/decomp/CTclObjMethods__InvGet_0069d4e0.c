
undefined4
CTclObjMethods__InvGet(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *lp;
  BOOL BVar4;
  code *pcVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711e95;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7b50) &&
     (FUN_006cebf4(&DAT_00ca7b50,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7b50 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7b54 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::InvGet()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7b50);
  }
  iVar3 = DAT_00ca7b54;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7b54 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar8;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_005c71c0(param_4,3,1);
  if (iVar2 == 0) {
    uVar8 = 1;
    goto LAB_0069d714;
  }
  if (local_24 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_2c;
    if (local_28 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_2c + 2;
  }
  piVar1 = (int *)*puVar6;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (piVar1 == (int *)0x0) {
    piVar7 = (int *)0x0;
LAB_0069d649:
    if (*(int *)(iVar2 + 0x5c) <= (int)piVar7) goto LAB_0069d6e0;
    lp = (void *)FUN_005cf1d0(piVar7);
    if ((((lp == (void *)0x0) || (BVar4 = IsBadReadPtr(lp,0x10), BVar4 != 0)) ||
        (*(int *)((int)lp + 8) != 0x616e4f62)) ||
       ((DAT_00768398 != '\0' && (*(int *)((int)lp + 0xdc) == 0)))) goto LAB_0069d6f8;
    FUN_005cf1d0(piVar7);
    iVar2 = FUN_005caf90();
    if (iVar2 == 0) {
      piVar7 = (int *)0x0;
    }
    else {
      piVar7 = (int *)Tcl_NewStringObj(iVar2,0xffffffff);
      *piVar7 = *piVar7 + 1;
    }
    local_14 = piVar7;
    FUN_006bc670(&local_14);
    pcVar5 = TclFreeObj_exref;
    if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
      TclFreeObj(piVar7);
    }
    uVar8 = 0;
  }
  else {
    iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_14);
    if (iVar3 == 1) {
      piVar7 = (int *)0x0;
      goto LAB_0069d649;
    }
    piVar7 = local_14;
    if (-1 < (int)local_14) goto LAB_0069d649;
LAB_0069d6e0:
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("inv_get:invalid index",piVar1);
LAB_0069d6f8:
    uVar8 = 1;
    pcVar5 = TclFreeObj_exref;
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar5)(piVar1);
  }
LAB_0069d714:
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

