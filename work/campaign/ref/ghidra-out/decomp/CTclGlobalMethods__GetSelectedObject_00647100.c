
undefined4
CTclGlobalMethods__GetSelectedObject
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  bool bVar7;
  undefined8 uVar8;
  int local_30;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070dd75;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca70e8) &&
     (FUN_006cebf4(&DAT_00ca70e8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca70e8 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca70ec = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::GetSelectedObject()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca70e8);
  }
  iVar4 = DAT_00ca70ec;
  uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca70ec * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar2;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004298b0(param_3,param_4);
  if (*(int *)(DAT_00772400 + 0xa0c8) == 0) {
LAB_006472be:
    piVar5 = (int *)Tcl_NewIntObj(0);
    *piVar5 = *piVar5 + 1;
    iVar3 = *piVar5;
    if (local_30 != 0) {
      Tcl_SetObjResult(local_30,piVar5);
      iVar3 = *piVar5;
    }
    iVar3 = iVar3 + -1;
    bVar7 = iVar3 < 0;
    bVar6 = iVar3 == 0;
    *piVar5 = iVar3;
  }
  else {
    puVar1 = (undefined4 *)(DAT_00772400 + 0xa0c4);
    if (*(int *)(DAT_00772400 + 0xa0c8) < 1) goto LAB_006472be;
    if (*(int *)(DAT_00772400 + 0xa0c8) == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar5 = (int *)(DAT_0077244c + 0x488);
    if (*(uint *)*puVar1 < 0x2000) {
      piVar5 = piVar5 + *(uint *)*puVar1;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    if (*piVar5 == 0) goto LAB_006472be;
    if ((0 < *(int *)(DAT_00772400 + 0xa0c8)) && (0x1fff < **(uint **)(DAT_00772400 + 0xa0c4))) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar3 = FUN_005caf90();
    if (iVar3 == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)Tcl_NewStringObj(iVar3,0xffffffff);
      *piVar5 = *piVar5 + 1;
    }
    if (local_30 == 0) {
      if (piVar5 == (int *)0x0) goto LAB_006472f4;
      *piVar5 = *piVar5 + -1;
      bVar7 = *piVar5 < 0;
      bVar6 = *piVar5 == 0;
    }
    else {
      if (piVar5 == (int *)0x0) {
        Tcl_ResetResult(local_30);
        goto LAB_006472f4;
      }
      Tcl_SetObjResult(local_30,piVar5);
      *piVar5 = *piVar5 + -1;
      bVar7 = *piVar5 < 0;
      bVar6 = *piVar5 == 0;
    }
  }
  if (bVar6 || bVar7) {
    TclFreeObj(piVar5);
  }
LAB_006472f4:
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_20 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

