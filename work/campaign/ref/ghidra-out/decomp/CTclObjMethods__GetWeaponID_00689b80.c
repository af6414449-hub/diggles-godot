
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
CTclObjMethods__GetWeaponID
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int local_40;
  char local_3c;
  int *local_38;
  int *local_34;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int local_1c;
  int local_18;
  bool local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710b5d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_18 = *ThreadLocalStoragePointer;
  if ((*(int *)(local_18 + 4) < DAT_00ca7820) &&
     (FUN_006cebf4(&DAT_00ca7820,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7820 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7824 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::GetWeaponID()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7820);
  }
  iVar3 = DAT_00ca7824;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7824 * 0x40);
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
  }
  else {
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_30 + 2;
    }
    piVar4 = (int *)*puVar6;
    if (piVar4 == (int *)0x0) {
      local_11 = false;
    }
    else {
      *piVar4 = *piVar4 + 1;
      iVar3 = Tcl_GetBooleanFromObj(0,piVar4,&local_1c);
      local_11 = iVar3 != 1 && local_1c != 0;
      *piVar4 = *piVar4 + -1;
      if (*piVar4 < 1) {
        TclFreeObj(piVar4);
      }
    }
    uVar7 = 0;
    while( true ) {
      if ((*(int *)(local_18 + 4) < DAT_00ca65a0) &&
         (FUN_006cebf4(&DAT_00ca65a0), DAT_00ca65a0 == -1)) {
        _DAT_00ca65b0 = 0;
        uRam00ca65b4 = 0;
        DAT_00ca65b8 = 0;
        DAT_00ca65bc = 0;
        DAT_00ca65c0 = 0;
        DAT_00ca65c4 = 0;
        _DAT_00ca65c8 = 0;
        uRam00ca65cc = 0;
        DAT_00ca65d0 = 0;
        DAT_00ca65d4 = 0;
        _DAT_00ca65d8 = 0;
        uRam00ca65dc = 0;
        _atexit(FUN_007143d0);
        FUN_006cebaa(&DAT_00ca65a0);
      }
      if ((int)DAT_00ca65bc <= (int)uVar7) {
        uVar5 = 0;
        goto LAB_00689d9f;
      }
      if ((*(int *)(local_18 + 4) < DAT_00ca65a0) &&
         (FUN_006cebf4(&DAT_00ca65a0), DAT_00ca65a0 == -1)) {
        _DAT_00ca65b0 = 0;
        uRam00ca65b4 = 0;
        DAT_00ca65b8 = 0;
        DAT_00ca65bc = 0;
        DAT_00ca65c0 = 0;
        DAT_00ca65c4 = 0;
        _DAT_00ca65c8 = 0;
        uRam00ca65cc = 0;
        DAT_00ca65d0 = 0;
        DAT_00ca65d4 = 0;
        _DAT_00ca65d8 = 0;
        uRam00ca65dc = 0;
        _atexit(FUN_007143d0);
        FUN_006cebaa(&DAT_00ca65a0);
      }
      if (DAT_00ca65bc <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      cVar1 = FUN_006b97f0(*(int *)(iVar2 + 0xd4) + 0xc);
      if (cVar1 != '\0') break;
      uVar7 = uVar7 + 1;
    }
    if ((*(int *)(local_18 + 4) < DAT_00ca65a0) && (FUN_006cebf4(&DAT_00ca65a0), DAT_00ca65a0 == -1)
       ) {
      _DAT_00ca65b0 = 0;
      uRam00ca65b4 = 0;
      DAT_00ca65b8 = 0;
      DAT_00ca65bc = 0;
      DAT_00ca65c0 = 0;
      DAT_00ca65c4 = 0;
      _DAT_00ca65c8 = 0;
      uRam00ca65cc = 0;
      DAT_00ca65d0 = 0;
      DAT_00ca65d4 = 0;
      _DAT_00ca65d8 = 0;
      uRam00ca65dc = 0;
      _atexit(FUN_007143d0);
      FUN_006cebaa(&DAT_00ca65a0);
    }
    if (DAT_00ca65bc <= uVar7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar5 = 0;
    if ((bool)*(char *)(uVar7 * 0x40 + 4 + DAT_00ca65b8) == local_11) {
      uVar5 = uVar7;
    }
LAB_00689d9f:
    piVar4 = (int *)Tcl_NewIntObj(uVar5);
    *piVar4 = *piVar4 + 1;
    iVar2 = *piVar4;
    if (local_40 != 0) {
      Tcl_SetObjResult(local_40,piVar4);
      iVar2 = *piVar4;
    }
    *piVar4 = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      TclFreeObj(piVar4);
    }
    uVar8 = 0;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
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
  local_8._0_1_ = 5;
  if ((local_34 != (int *)0x0) && (*local_34 = *local_34 + -1, *local_34 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

