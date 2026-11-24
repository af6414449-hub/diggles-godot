
undefined4
CTclObjMethods__SetProdSlotCnt
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined8 uVar8;
  int local_38;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c3dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7958) &&
     (FUN_006cebf4(&DAT_00ca7958,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7958 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca795c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclObjMethods::SetProdSlotCnt()";
    *(int *)(&DAT_00773650 + iVar7) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7958);
  }
  iVar7 = DAT_00ca795c;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca795c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_005c71c0(param_4,4,1);
  if ((iVar2 == 0) || (*(int *)(iVar2 + 0x3e0) == 0)) {
    uVar5 = 1;
  }
  else {
    if (local_20 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_28 + 2;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      *piVar1 = *piVar1 + 1;
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    local_14 = FUN_005edb60(ppuVar3);
    if (local_14 == -1) {
      uVar5 = 1;
    }
    else {
      puVar4 = (undefined4 *)FUN_004295e0(3);
      piVar6 = (int *)*puVar4;
      if (piVar6 == (int *)0x0) {
        FUN_005eda20(local_14,0);
      }
      else {
        *piVar6 = *piVar6 + 1;
        iVar2 = Tcl_GetIntFromObj(0,piVar6,&local_18);
        if (iVar2 == 1) {
          local_18 = 0;
        }
        FUN_005eda20(local_14,local_18);
        *piVar6 = *piVar6 + -1;
        if (*piVar6 < 1) {
          TclFreeObj(piVar6);
        }
      }
      uVar5 = FUN_005ed9d0(local_14);
      piVar6 = (int *)Tcl_NewIntObj(uVar5);
      *piVar6 = *piVar6 + 1;
      iVar2 = *piVar6;
      if (local_38 != 0) {
        Tcl_SetObjResult(local_38,piVar6);
        iVar2 = *piVar6;
      }
      *piVar6 = iVar2 + -1;
      if (iVar2 + -1 < 1) {
        TclFreeObj(piVar6);
      }
      uVar5 = 0;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

