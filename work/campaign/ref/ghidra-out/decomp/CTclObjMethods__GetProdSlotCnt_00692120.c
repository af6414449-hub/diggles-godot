
undefined4
CTclObjMethods__GetProdSlotCnt
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined **ppuVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  int local_30;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ccbd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7960) &&
     (FUN_006cebf4(&DAT_00ca7960,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7960 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7964 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::GetProdSlotCnt()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7960);
  }
  iVar5 = DAT_00ca7964;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7964 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar8;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_005c71c0(param_4,3,1);
  if ((iVar2 == 0) || (*(int *)(iVar2 + 0x3e0) == 0)) {
    uVar8 = 1;
  }
  else {
    if (local_18 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_20 + 2;
    }
    piVar1 = (int *)*puVar6;
    if (piVar1 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      *piVar1 = *piVar1 + 1;
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    iVar2 = FUN_005edb60(ppuVar3);
    if (iVar2 == -1) {
      uVar8 = 0;
    }
    else {
      uVar8 = FUN_005ed9d0(iVar2);
    }
    piVar4 = (int *)Tcl_NewIntObj(uVar8);
    *piVar4 = *piVar4 + 1;
    iVar2 = *piVar4;
    if (local_30 != 0) {
      Tcl_SetObjResult(local_30,piVar4);
      iVar2 = *piVar4;
    }
    *piVar4 = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      TclFreeObj(piVar4);
    }
    uVar8 = 0;
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
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
  return uVar8;
}

