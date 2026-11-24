
undefined4
CTclGlobalMethods__ObjEval
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  int local_3c;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070b975;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6c30) &&
     (FUN_006cebf4(&DAT_00ca6c30,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6c30 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6c34 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::ObjEval()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6c30);
  }
  iVar5 = DAT_00ca6c34;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6c34 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar6;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar3 = FUN_005c71c0(param_4,3,1);
  if (iVar3 == 0) {
    uVar6 = 1;
    goto LAB_00620e02;
  }
  if (local_24 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_2c;
    if (local_28 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_2c + 2;
  }
  piVar1 = (int *)*puVar7;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  local_14 = piVar1;
  cVar2 = FUN_00555a00(&local_14);
  if (cVar2 == '\0') {
    FUN_006bc6a0(*(int *)(iVar3 + 200) + 0xc,0);
  }
  else {
    piVar4 = (int *)Tcl_GetObjResult(*(undefined4 *)(iVar3 + 0xc0));
    if (piVar4 != (int *)0x0) {
      *piVar4 = *piVar4 + 1;
    }
    if (local_3c == 0) {
      if (piVar4 != (int *)0x0) goto LAB_00620dc3;
    }
    else if (piVar4 == (int *)0x0) {
      Tcl_ResetResult(local_3c);
    }
    else {
      Tcl_SetObjResult(local_3c,piVar4);
LAB_00620dc3:
      *piVar4 = *piVar4 + -1;
      if (*piVar4 < 1) {
        TclFreeObj(piVar4);
      }
    }
  }
  uVar6 = 0;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
LAB_00620e02:
  FUN_006bc0d0();
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

