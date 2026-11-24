
undefined4
CTclObjMethods__InvGet(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  void *lp;
  BOOL BVar3;
  int iVar4;
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
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7b28) &&
     (FUN_006cebf4(&DAT_00ca7b28,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7b28 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca7b2c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::InvGet()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7b28);
  }
  iVar4 = DAT_00ca7b2c;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7b2c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar8;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_005c71c0(param_4,3,1);
  if (iVar2 == 0) {
    uVar8 = 1;
    goto LAB_0069c9aa;
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
LAB_0069c8d9:
    iVar2 = FUN_005cf210();
    if (iVar2 <= (int)piVar7) goto LAB_0069c976;
    lp = (void *)FUN_005cef70(piVar7);
    if ((((lp == (void *)0x0) || (BVar3 = IsBadReadPtr(lp,0x10), BVar3 != 0)) ||
        (*(int *)((int)lp + 8) != 0x616e4f62)) ||
       ((DAT_00768398 != '\0' && (*(int *)((int)lp + 0xdc) == 0)))) goto LAB_0069c98e;
    FUN_005cef70(piVar7);
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
    iVar2 = Tcl_GetIntFromObj(0,piVar1,&local_14);
    if (iVar2 == 1) {
      piVar7 = (int *)0x0;
      goto LAB_0069c8d9;
    }
    piVar7 = local_14;
    if (-1 < (int)local_14) goto LAB_0069c8d9;
LAB_0069c976:
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("inv_get:invalid index",piVar1);
LAB_0069c98e:
    uVar8 = 1;
    pcVar5 = TclFreeObj_exref;
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar5)(piVar1);
  }
LAB_0069c9aa:
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

