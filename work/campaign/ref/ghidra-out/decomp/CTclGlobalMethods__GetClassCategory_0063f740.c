
undefined4
CTclGlobalMethods__GetClassCategory
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined8 uVar9;
  int local_38;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d775;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7040) &&
     (FUN_006cebf4(&DAT_00ca7040,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7040 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7044 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::GetClassCategory()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7040);
  }
  iVar5 = DAT_00ca7044;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7044 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar7;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (piVar1 != (int *)0x2) {
    FUN_006bc8f0(1);
    uVar7 = 1;
    goto LAB_0063fa59;
  }
  if (local_20 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_28;
    if (local_24 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_28 + 1;
  }
  piVar1 = (int *)*puVar6;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  iVar3 = DAT_00772478;
  local_8 = CONCAT31(local_8._1_3_,3);
  if (piVar1 == (int *)0x0) {
    ppuVar4 = &PTR_0071ce50;
  }
  else {
    ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
  }
  FUN_006b8fb0(ppuVar4);
  cVar2 = FUN_006037d0(&local_14,&param_3);
  if (cVar2 == '\0') {
    iVar3 = 0;
  }
  else {
    if (*(int **)(iVar3 + 0x801c) <= param_3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar3 = *(int *)(*(int *)(iVar3 + 0x8018) + (int)param_3 * 4);
  }
  local_8._0_1_ = 4;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (iVar3 == 0) {
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("unknown class",piVar1);
    uVar7 = 1;
  }
  else {
    switch(*(undefined4 *)(iVar3 + 0x58)) {
    case 0:
      FUN_006b8fb0(&DAT_00722ca4);
      break;
    case 1:
      FUN_006b8fb0(&DAT_0072c678);
      break;
    case 2:
      FUN_006b8fb0("stone");
      break;
    case 3:
      FUN_006b8fb0("metal");
      break;
    case 4:
      FUN_006b8fb0("energy");
      break;
    case 5:
      FUN_006b8fb0("service");
      break;
    case 6:
      FUN_006b8fb0("fight");
      break;
    case 7:
      FUN_006b8fb0(&DAT_0072c698);
      break;
    default:
      param_3 = (int *)FUN_006ba810(0x19);
      param_3[1] = 0x14;
      param_3[3] = 0x656c6c69;
      param_3[4] = 0x6c6167;
      param_3[2] = 7;
      *param_3 = 1;
    }
    if (param_3 + 3 == (int *)0x0) {
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = (int *)Tcl_NewStringObj(param_3 + 3,0xffffffff);
      *piVar8 = *piVar8 + 1;
    }
    if (local_38 == 0) {
      if (piVar8 != (int *)0x0) goto LAB_0063fa05;
    }
    else if (piVar8 == (int *)0x0) {
      Tcl_ResetResult(local_38);
    }
    else {
      Tcl_SetObjResult(local_38,piVar8);
LAB_0063fa05:
      *piVar8 = *piVar8 + -1;
      if (*piVar8 < 1) {
        TclFreeObj(piVar8);
      }
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
      FUN_006ba940();
    }
    uVar7 = 0;
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
LAB_0063fa59:
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

