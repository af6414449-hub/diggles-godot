
undefined4
CTclGlobalMethods__Ref2Path(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  code *pcVar9;
  undefined8 uVar10;
  int local_34;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070bf7d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6cd8) &&
     (FUN_006cebf4(&DAT_00ca6cd8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6cd8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6cdc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::Ref2Path()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6cd8);
  }
  iVar5 = DAT_00ca6cdc;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6cdc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar10 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar10;
  }
  piVar1 = param_3;
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (piVar1 != (int *)0x2) {
    FUN_006bc8f0(1);
    uVar6 = 1;
    goto LAB_006259eb;
  }
  if (local_1c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_24;
    if (local_20 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_24 + 1;
  }
  piVar1 = (int *)*puVar7;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  piVar3 = (int *)FUN_006ba810(0x19);
  piVar8 = piVar3 + 3;
  piVar3[2] = -1;
  *piVar3 = 0;
  *(undefined1 *)piVar8 = 0;
  piVar3[1] = 0x14;
  *piVar8 = 0x73696874;
  *(undefined1 *)(piVar3 + 4) = 0;
  piVar3[2] = 4;
  *piVar3 = 1;
  if (local_34 == 0) {
    uVar6 = 0;
    iVar2 = 1;
  }
  else {
    uVar6 = Tcl_GetAssocData(local_34,piVar8,0);
    iVar2 = *piVar3;
  }
  local_8._0_1_ = 4;
  *piVar3 = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 3;
  if (piVar1 == (int *)0x0) {
    ppuVar4 = &PTR_0071ce50;
  }
  else {
    ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
  }
  FUN_006b8fb0(ppuVar4);
  local_8._0_1_ = 5;
  iVar2 = FUN_006055d0(param_2,uVar6,&param_3);
  local_8._0_1_ = 6;
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
    FUN_006ba940();
  }
  pcVar9 = TclFreeObj_exref;
  local_8 = CONCAT31(local_8._1_3_,3);
  if (iVar2 == 0) {
    FUN_006bc6a0("invalid reference",0);
    uVar6 = 1;
  }
  else {
    FUN_006b95d0(iVar2 + 0xd8);
    if (param_3 + 3 == (int *)0x0) {
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = (int *)Tcl_NewStringObj(param_3 + 3,0xffffffff);
      *piVar8 = *piVar8 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,7);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
      FUN_006ba940();
    }
    if (local_34 == 0) {
      if (piVar8 != (int *)0x0) goto LAB_00625a5a;
    }
    else if (piVar8 == (int *)0x0) {
      Tcl_ResetResult(local_34);
    }
    else {
      Tcl_SetObjResult(local_34,piVar8);
LAB_00625a5a:
      *piVar8 = *piVar8 + -1;
      pcVar9 = TclFreeObj_exref;
      uVar6 = 0;
      if (*piVar8 < 1) {
        TclFreeObj(piVar8);
        goto LAB_006259da;
      }
    }
    uVar6 = 0;
    pcVar9 = TclFreeObj_exref;
  }
LAB_006259da:
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar9)(piVar1);
  }
LAB_006259eb:
  FUN_006bc0d0();
  local_8._0_1_ = 8;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

