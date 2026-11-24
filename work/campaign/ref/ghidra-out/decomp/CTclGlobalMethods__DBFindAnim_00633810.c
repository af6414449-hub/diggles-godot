
uint CTclGlobalMethods__DBFindAnim
               (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined **ppuVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  char *pcVar11;
  undefined4 *local_38;
  uint local_34;
  int local_30;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070cf25;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6eb0) &&
     (FUN_006cebf4(&DAT_00ca6eb0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca6eb0 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca6eb4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::DBFindAnim()";
    *(int *)(&DAT_00773650 + iVar8) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6eb0);
  }
  iVar8 = DAT_00ca6eb4;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6eb4 * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar1;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar5 == 0) {
    uVar10 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar9 = (uint)param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)uVar9 < 4) {
    FUN_006bc8f0(3);
    uVar9 = 1;
    goto LAB_00633b4b;
  }
  if (local_30 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_38;
    if (local_34 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_34 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_38 + 1;
  }
  piVar2 = (int *)*puVar6;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  if (local_30 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_38;
    if (local_34 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_34 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_38 + 2;
  }
  piVar3 = (int *)*puVar6;
  if (piVar3 != (int *)0x0) {
    *piVar3 = *piVar3 + 1;
  }
  if (local_30 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_38;
    if (local_34 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_34 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_38 + 3;
  }
  piVar4 = (int *)*puVar6;
  if (piVar4 != (int *)0x0) {
    *piVar4 = *piVar4 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  if (piVar2 == (int *)0x0) {
    uVar9 = 0;
  }
  else {
    iVar5 = Tcl_GetIntFromObj(0,piVar2,&param_3);
    uVar9 = -(uint)(iVar5 != 1) & (uint)param_3;
  }
  if (piVar3 == (int *)0x0) {
    ppuVar7 = &PTR_0071ce50;
  }
  else {
    ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar3,0);
  }
  FUN_006b8fb0(ppuVar7);
  local_8._0_1_ = 6;
  if (piVar4 == (int *)0x0) {
    ppuVar7 = &PTR_0071ce50;
  }
  else {
    ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar4,0);
  }
  FUN_006b8fb0(ppuVar7);
  local_8 = CONCAT31(local_8._1_3_,7);
  if ((uVar9 < 0x100) && (*(int *)(DAT_00772400 + 0x5c8 + uVar9 * 4) != 0)) {
    iVar5 = FUN_00405350(&local_18);
    if (iVar5 == -1) {
      pcVar11 = "invalid DB object";
      goto LAB_00633acd;
    }
    iVar5 = FUN_004053c0(iVar5,&local_14);
    if (iVar5 == -1) {
      pcVar11 = "invalid DB anim";
      goto LAB_00633acd;
    }
    param_3 = (int *)Tcl_NewIntObj(iVar5);
    *param_3 = *param_3 + 1;
    FUN_006bc670(&param_3);
    FUN_006bad60();
    param_3 = (int *)0x0;
  }
  else {
    pcVar11 = "invalid DB id";
LAB_00633acd:
    FUN_006bc6a0(pcVar11,0);
    param_3 = (int *)0x1;
  }
  local_8._0_1_ = 0xe;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0xf);
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
    TclFreeObj(piVar4);
  }
  if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
    TclFreeObj(piVar3);
  }
  uVar9 = (uint)param_3;
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    TclFreeObj(piVar2);
    uVar9 = (uint)param_3;
  }
LAB_00633b4b:
  local_8._0_1_ = 0x10;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x11);
  FUN_004297b0(0);
  if (local_38 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

