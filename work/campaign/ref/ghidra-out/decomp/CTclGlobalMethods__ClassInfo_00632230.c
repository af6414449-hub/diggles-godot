
undefined4
CTclGlobalMethods__ClassInfo(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  undefined8 uVar9;
  int local_34;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070cd65;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6e80) &&
     (FUN_006cebf4(&DAT_00ca6e80,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6e80 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6e84 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::ClassInfo()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6e80);
  }
  iVar4 = DAT_00ca6e84;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e84 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar7 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  if ((int)piVar7 < 2) {
    FUN_006bc8f0(1);
    uVar6 = 1;
    goto LAB_0063253c;
  }
  if (local_1c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_24;
    if (local_20 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_24 + 1;
  }
  piVar7 = (int *)*puVar5;
  if (piVar7 != (int *)0x0) {
    *piVar7 = *piVar7 + 1;
  }
  local_8._0_1_ = 3;
  param_3 = piVar7;
  if (piVar7 == (int *)0x0) {
    ppuVar3 = &PTR_0071ce50;
    piVar8 = (int *)0x0;
  }
  else {
    ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar7,0);
    piVar8 = piVar7;
  }
  FUN_006b8fb0(ppuVar3);
  local_8._0_1_ = 5;
  if ((piVar8 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
    TclFreeObj(piVar7);
  }
  iVar2 = DAT_00772478;
  cVar1 = FUN_006037d0(&local_14,&param_3);
  if (cVar1 == '\0') {
LAB_006324c5:
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_24 + 1;
    }
    piVar7 = (int *)*puVar5;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
    }
    FUN_006bc6a0("not a class",piVar7);
    uVar6 = 1;
  }
  else {
    if (*(int **)(iVar2 + 0x801c) <= param_3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = *(undefined4 **)(*(int *)(iVar2 + 0x8018) + (int)param_3 * 4);
    if (puVar5 == (undefined4 *)0x0) goto LAB_006324c5;
    param_3 = (int *)FUN_006ba810(0x19);
    param_3[1] = 0x14;
    param_3[2] = -1;
    *(undefined1 *)(param_3 + 3) = 0;
    *param_3 = 1;
    local_8 = CONCAT31(local_8._1_3_,7);
    if (puVar5[0x1b] == 0) {
      FUN_006b9040(&param_3,"%s: no base  instances:%d",local_14 + 3,*puVar5);
    }
    else {
      FUN_006b9040(&param_3,"%s: base:%s instances:%d",local_14 + 3,
                   *(int *)(puVar5[0x1b] + 0xc) + 0xc);
    }
    if (param_3 + 3 == (int *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      piVar7 = (int *)Tcl_NewStringObj(param_3 + 3,0xffffffff);
      *piVar7 = *piVar7 + 1;
    }
    if (local_34 == 0) {
      if (piVar7 != (int *)0x0) goto LAB_00632499;
    }
    else if (piVar7 == (int *)0x0) {
      Tcl_ResetResult(local_34);
    }
    else {
      Tcl_SetObjResult(local_34,piVar7);
LAB_00632499:
      *piVar7 = *piVar7 + -1;
      if (*piVar7 < 1) {
        TclFreeObj(piVar7);
      }
    }
    uVar6 = 0;
    local_8._0_1_ = 8;
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
      FUN_006ba940();
    }
  }
  local_8._0_1_ = 9;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
LAB_0063253c:
  local_8._0_1_ = 10;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

