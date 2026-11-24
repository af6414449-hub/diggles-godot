
undefined4
CTclGlobalMethods__GetWeaponID
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  undefined8 uVar8;
  int local_30;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e00d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7130) &&
     (FUN_006cebf4(&DAT_00ca7130,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7130 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7134 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::GetWeaponID()";
    *(int *)(&DAT_00773650 + iVar3) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7130);
  }
  iVar3 = DAT_00ca7134;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7134 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar1 == 0) {
    uVar8 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar2 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (piVar2 != (int *)0x2) {
    FUN_006bc8f0(1);
    uVar4 = 1;
    goto LAB_0064b2b4;
  }
  if (local_18 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_20;
    if (local_1c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_20 + 1;
  }
  piVar2 = (int *)*puVar5;
  if (piVar2 == (int *)0x0) {
    uVar6 = 0;
  }
  else {
    *piVar2 = *piVar2 + 1;
    iVar1 = Tcl_GetIntFromObj(0,piVar2,&param_3);
    *piVar2 = *piVar2 + -1;
    uVar6 = -(uint)(iVar1 != 1) & (uint)param_3;
    if (*piVar2 < 1) {
      TclFreeObj(piVar2);
    }
  }
  iVar1 = FUN_005bbb20();
  if (*(uint *)(iVar1 + 0xc) <= uVar6) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  switch(*(undefined4 *)(uVar6 * 0x40 + 0x28 + *(int *)(iVar1 + 8))) {
  case 0:
    FUN_006b8fb0("normal");
    piVar2 = param_3;
    break;
  case 1:
    FUN_006b8fb0("kungfu");
    piVar2 = param_3;
    break;
  case 2:
    FUN_006b8fb0("sword");
    piVar2 = param_3;
    break;
  case 3:
    FUN_006b8fb0("twohand");
    piVar2 = param_3;
    break;
  case 4:
    FUN_006b8fb0("ballistic");
    piVar2 = param_3;
    break;
  case 5:
    FUN_006b8fb0("shield");
    piVar2 = param_3;
    break;
  default:
    piVar2 = (int *)FUN_006ba810(0x19);
    piVar2[1] = 0x14;
    piVar2[3] = 0x61766e69;
    piVar2[4] = 0x64696c;
    piVar2[2] = 7;
    *piVar2 = 1;
  }
  if (piVar2 + 3 == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)Tcl_NewStringObj(piVar2 + 3,0xffffffff);
    *piVar7 = *piVar7 + 1;
  }
  if (local_30 == 0) {
    if (piVar7 != (int *)0x0) goto LAB_0064b28d;
  }
  else if (piVar7 == (int *)0x0) {
    Tcl_ResetResult(local_30);
  }
  else {
    Tcl_SetObjResult(local_30,piVar7);
LAB_0064b28d:
    *piVar7 = *piVar7 + -1;
    if (*piVar7 < 1) {
      TclFreeObj(piVar7);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  uVar4 = 0;
LAB_0064b2b4:
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

