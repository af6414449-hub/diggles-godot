
undefined4
CTclObjMethods__GnomeStoppedWork
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  int local_38;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710ad5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7588) &&
     (FUN_006cebf4(&DAT_00ca7588,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7588 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca758c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclObjMethods::GnomeStoppedWork";
    *(int *)(&DAT_00773650 + iVar6) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7588);
  }
  iVar6 = DAT_00ca758c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca758c * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar7;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar1 == 0) {
    uVar8 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_005c71c0(param_4,2,1);
  if (iVar1 == 0) {
    uVar7 = 1;
  }
  else {
    iVar1 = 0;
    if (param_3 == 3) {
      if (local_20 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_28;
        if (local_24 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_24 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_28 + 2;
      }
      piVar3 = (int *)*puVar5;
      if (piVar3 != (int *)0x0) {
        *piVar3 = *piVar3 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,3);
      if (piVar3 == (int *)0x0) {
        iVar1 = FUN_005cb3a0(0);
        pcVar4 = TclFreeObj_exref;
      }
      else {
        iVar1 = Tcl_GetIntFromObj(0,piVar3,&local_14);
        if (iVar1 == 1) {
          local_14 = 0;
        }
        iVar1 = FUN_005cb3a0(local_14);
        *piVar3 = *piVar3 + -1;
        pcVar4 = TclFreeObj_exref;
        if (*piVar3 < 1) {
          TclFreeObj(piVar3);
        }
      }
    }
    else {
      iVar6 = 0;
      do {
        iVar2 = FUN_005cb3a0(iVar6);
        if (iVar1 < iVar2) {
          iVar1 = iVar2;
        }
        iVar6 = iVar6 + 1;
        pcVar4 = TclFreeObj_exref;
      } while (iVar6 < 8);
    }
    piVar3 = (int *)Tcl_NewIntObj(iVar1);
    *piVar3 = *piVar3 + 1;
    iVar1 = *piVar3;
    if (local_38 != 0) {
      Tcl_SetObjResult(local_38,piVar3);
      iVar1 = *piVar3;
    }
    *piVar3 = iVar1 + -1;
    if (iVar1 + -1 < 1) {
      (*pcVar4)(piVar3);
    }
    uVar7 = 0;
  }
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

