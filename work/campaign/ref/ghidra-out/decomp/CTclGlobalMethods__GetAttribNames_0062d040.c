
undefined4
CTclGlobalMethods__GetAttribNames
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  undefined8 uVar8;
  int local_38;
  char local_34;
  int *local_30;
  int *local_2c;
  int local_28;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c7e5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6db8) &&
     (FUN_006cebf4(&DAT_00ca6db8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca6db8 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6dbc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::GetAttribNames()";
    *(int *)(&DAT_00773650 + iVar4) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6db8);
  }
  iVar4 = DAT_00ca6dbc;
  uVar3 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6dbc * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar3;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar1 == 0) {
    uVar8 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  piVar2 = (int *)FUN_005da0f0();
  FUN_004298b0(param_3,param_4);
  uVar5 = 0;
  piVar6 = (int *)0x0;
  if (0 < *piVar2) {
    do {
      if (uVar5 < 0x200) {
        piVar7 = piVar2 + 1 + uVar5;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar7 = piVar2 + 1;
      }
      if (*piVar7 + 0xc == 0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = (int *)Tcl_NewStringObj(*piVar7 + 0xc,0xffffffff);
        *piVar7 = *piVar7 + 1;
      }
      if (piVar6 == (int *)0x0) {
        piVar6 = (int *)Tcl_NewListObj(0,0);
        if (piVar6 != (int *)0x0) {
          *piVar6 = *piVar6 + 1;
          goto LAB_0062d165;
        }
        if (piVar7 != (int *)0x0) goto LAB_0062d1ae;
      }
      else {
LAB_0062d165:
        if (1 < *piVar6) {
          *piVar6 = *piVar6 + -1;
          piVar6 = (int *)Tcl_DuplicateObj(piVar6);
          *piVar6 = *piVar6 + 1;
        }
        if (piVar7 != (int *)0x0) {
          if (*piVar7 < 2) {
            Tcl_ListObjAppendElement(0,piVar6,piVar7);
          }
          else {
            uVar3 = Tcl_DuplicateObj();
            Tcl_ListObjAppendElement(0,piVar6,uVar3);
          }
LAB_0062d1ae:
          *piVar7 = *piVar7 + -1;
          if (*piVar7 < 1) {
            TclFreeObj(piVar7);
          }
        }
      }
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < *piVar2);
  }
  if (local_38 == 0) {
    if (piVar6 == (int *)0x0) goto LAB_0062d204;
  }
  else {
    if (piVar6 == (int *)0x0) {
      Tcl_ResetResult(local_38);
      goto LAB_0062d204;
    }
    Tcl_SetObjResult(local_38,piVar6);
  }
  *piVar6 = *piVar6 + -1;
  if (*piVar6 < 1) {
    TclFreeObj(piVar6);
  }
LAB_0062d204:
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_28 != 0) {
    FUN_006ba940();
  }
  if ((local_34 != '\0') && (local_38 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_38);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 4;
  if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

