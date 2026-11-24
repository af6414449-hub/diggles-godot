
undefined4
CTclGlobalMethods__ClassInfo(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  int local_34;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070cd05;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6e78) &&
     (FUN_006cebf4(&DAT_00ca6e78,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6e78 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6e7c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::ClassInfo()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6e78);
  }
  iVar4 = DAT_00ca6e7c;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e7c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar3 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  if ((int)piVar3 < 2) {
    FUN_006bc8f0(1);
    uVar5 = 1;
    goto LAB_00632179;
  }
  if (local_1c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_24;
    if (local_20 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_24 + 1;
  }
  piVar3 = (int *)*puVar6;
  if (piVar3 != (int *)0x0) {
    *piVar3 = *piVar3 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  local_14 = piVar3;
  if (piVar3 == (int *)0x0) {
    FUN_006b8fb0(&PTR_0071ce50);
  }
  else {
    uVar5 = Tcl_GetStringFromObj(piVar3,0);
    FUN_006b8fb0(uVar5);
    *piVar3 = *piVar3 + -1;
    if (*piVar3 < 1) {
      TclFreeObj(piVar3);
    }
  }
  iVar2 = DAT_00772478;
  cVar1 = FUN_006037d0(&param_3,&local_14);
  if (cVar1 == '\0') {
LAB_00632130:
    uVar5 = 0xffffffff;
  }
  else {
    if (*(int **)(iVar2 + 0x801c) <= local_14) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar2 = *(int *)(*(int *)(iVar2 + 0x8018) + (int)local_14 * 4);
    if (iVar2 == 0) goto LAB_00632130;
    uVar5 = *(undefined4 *)(iVar2 + 8);
  }
  piVar3 = (int *)Tcl_NewIntObj(uVar5);
  *piVar3 = *piVar3 + 1;
  iVar2 = *piVar3;
  if (local_34 != 0) {
    Tcl_SetObjResult(local_34,piVar3);
    iVar2 = *piVar3;
  }
  *piVar3 = iVar2 + -1;
  if (iVar2 + -1 < 1) {
    TclFreeObj(piVar3);
  }
  local_8._0_1_ = 5;
  uVar5 = 0;
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
    FUN_006ba940();
  }
LAB_00632179:
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

