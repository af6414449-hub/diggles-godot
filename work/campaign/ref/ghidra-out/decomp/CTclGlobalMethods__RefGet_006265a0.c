
undefined4
CTclGlobalMethods__RefGet(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined **ppuVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  code *pcVar9;
  undefined8 uVar10;
  int local_3c;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c0dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6cf8) &&
     (FUN_006cebf4(&DAT_00ca6cf8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6cf8 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca6cfc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::RefGet()";
    *(int *)(&DAT_00773650 + iVar6) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6cf8);
  }
  iVar6 = DAT_00ca6cfc;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6cfc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar2 == 0) {
    uVar10 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (piVar1 == (int *)0x3) {
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar1 = piVar3 + 3;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)piVar1 = 0;
    piVar3[1] = 0x14;
    *piVar1 = 0x73696874;
    *(undefined1 *)(piVar3 + 4) = 0;
    piVar3[2] = 4;
    *piVar3 = 1;
    if (local_3c == 0) {
      uVar7 = 0;
      iVar2 = 1;
    }
    else {
      uVar7 = Tcl_GetAssocData(local_3c,piVar1,0);
      iVar2 = *piVar3;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    *piVar3 = iVar2 + -1;
    if (iVar2 + -1 == 0) {
      FUN_006ba940();
    }
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_28 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_2c + 1;
    }
    piVar1 = (int *)*puVar8;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_24 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_28 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_2c + 2;
    }
    piVar3 = (int *)*puVar8;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8._0_1_ = 5;
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar4);
    local_8._0_1_ = 6;
    iVar2 = FUN_006055d0(param_2,uVar7,&param_3);
    local_8._0_1_ = 7;
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    if (iVar2 == 0) {
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      FUN_006bc6a0("invalid reference",piVar1);
      uVar7 = 1;
    }
    else {
      piVar5 = (int *)FUN_005c9cc0();
      if (*piVar5 == 0) {
        param_3 = (int *)0x0;
      }
      else {
        param_3 = (int *)Tcl_ObjGetVar2(*piVar5,piVar3,0,0);
        if (param_3 != (int *)0x0) {
          *param_3 = *param_3 + 1;
        }
      }
      local_8 = CONCAT31(local_8._1_3_,8);
      if (param_3 == (int *)0x0) {
        if (piVar3 != (int *)0x0) {
          *piVar3 = *piVar3 + 1;
        }
        FUN_006bc6a0("unknown var",piVar3);
        uVar7 = 1;
      }
      else {
        if (local_3c != 0) {
          Tcl_SetObjResult(local_3c,param_3);
        }
        *param_3 = *param_3 + -1;
        uVar7 = 0;
        if (*param_3 < 1) {
          TclFreeObj(param_3);
        }
      }
    }
    pcVar9 = TclFreeObj_exref;
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, pcVar9 = TclFreeObj_exref, *piVar3 < 1))
    {
      TclFreeObj(piVar3);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      (*pcVar9)(piVar1);
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar7 = 1;
  }
  local_8._0_1_ = 9;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,10);
  FUN_004297b0(0);
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

