
undefined4
CTclGlobalMethods__Cwd(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 uVar7;
  int local_34;
  int local_24;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070bec5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6cc8) &&
     (FUN_006cebf4(&DAT_00ca6cc8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6cc8 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca6ccc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::Cwd()";
    *(int *)(&DAT_00773650 + iVar6) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6cc8);
  }
  iVar6 = DAT_00ca6ccc;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6ccc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar3 = (int *)FUN_006ba810(0x19);
  piVar4 = piVar3 + 3;
  piVar3[2] = -1;
  *piVar3 = 0;
  *(undefined1 *)piVar4 = 0;
  piVar3[1] = 0x14;
  *piVar4 = 0x73696874;
  *(undefined1 *)(piVar3 + 4) = 0;
  piVar3[2] = 4;
  *piVar3 = 1;
  if (local_34 == 0) {
    iVar6 = 0;
    iVar2 = 1;
  }
  else {
    iVar6 = Tcl_GetAssocData(local_34,piVar4,0);
    iVar2 = *piVar3;
  }
  local_8._0_1_ = 3;
  *piVar3 = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 2;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (iVar6 == 0) {
    uVar5 = 1;
    local_8._0_1_ = uVar1;
    goto LAB_00625308;
  }
  if (*(int *)(iVar6 + 0xd0) == 0) {
    piVar4 = (int *)Tcl_NewStringObj(&PTR_0071ce50,0xffffffff);
    *piVar4 = *piVar4 + 1;
    iVar2 = *piVar4;
    if (local_34 != 0) {
      Tcl_SetObjResult(local_34,piVar4);
      iVar2 = *piVar4;
    }
    *piVar4 = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      TclFreeObj(piVar4);
    }
  }
  else {
    FUN_006b95d0(*(int *)(iVar6 + 0xd0) + 0xd8);
    local_8 = CONCAT31(local_8._1_3_,4);
    iVar2 = local_14[2];
    if (iVar2 == -1) {
      piVar4 = local_14 + 3;
      do {
        iVar2 = *piVar4;
        piVar4 = (int *)((int)piVar4 + 1);
      } while ((char)iVar2 != '\0');
      iVar2 = (int)piVar4 - ((int)local_14 + 0xd);
      local_14[2] = iVar2;
    }
    if (iVar2 == 0) {
      FUN_006b9200(&DAT_007268dc);
    }
    if (local_14 + 3 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)Tcl_NewStringObj(local_14 + 3,0xffffffff);
      *piVar4 = *piVar4 + 1;
    }
    if (local_34 == 0) {
      if (piVar4 != (int *)0x0) goto LAB_006252e1;
    }
    else if (piVar4 == (int *)0x0) {
      Tcl_ResetResult(local_34);
    }
    else {
      Tcl_SetObjResult(local_34,piVar4);
LAB_006252e1:
      *piVar4 = *piVar4 + -1;
      if (*piVar4 < 1) {
        TclFreeObj(piVar4);
      }
    }
    local_8._0_1_ = 5;
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
      FUN_006ba940();
    }
  }
  uVar5 = 0;
LAB_00625308:
  FUN_006bc0d0();
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_24 != 0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

