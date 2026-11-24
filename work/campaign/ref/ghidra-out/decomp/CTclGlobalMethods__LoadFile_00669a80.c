
undefined4
CTclGlobalMethods__LoadFile(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  undefined **ppuVar2;
  FILE *_File;
  undefined4 *puVar3;
  int iVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  code *pcVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  int local_38;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  int *local_18;
  bool local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070fae5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7448) &&
     (FUN_006cebf4(&DAT_00ca7448,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7448 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca744c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::LoadFile()";
    *(int *)(&DAT_00773650 + iVar4) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7448);
  }
  iVar4 = DAT_00ca744c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca744c * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar7;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar1 == 0) {
    uVar8 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar8;
  }
  piVar6 = param_3;
  (&DAT_00773654)[iVar4 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)piVar6 < 2) {
    FUN_006bc8f0(1);
    uVar7 = 1;
    goto LAB_00669ded;
  }
  param_3 = (int *)CONCAT13(1,param_3._0_3_);
  if (piVar6 == (int *)0x3) {
    if (local_20 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_28 + 2;
    }
    piVar6 = (int *)*puVar3;
    if (piVar6 == (int *)0x0) {
      param_3 = (int *)((uint)param_3 & 0xffffff);
    }
    else {
      *piVar6 = *piVar6 + 1;
      iVar1 = Tcl_GetBooleanFromObj(0,piVar6,&param_3);
      if (iVar1 == 1) {
        param_3 = (int *)((uint)param_3 & 0xffffff);
      }
      else {
        param_3 = (int *)CONCAT13(param_3 != (int *)0x0,param_3._0_3_);
      }
      *piVar6 = *piVar6 + -1;
      if (*piVar6 < 1) {
        TclFreeObj(piVar6);
      }
    }
  }
  if (local_20 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar3 = local_28;
    if (local_24 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar3 = local_28 + 1;
  }
  piVar6 = (int *)*puVar3;
  if (piVar6 == (int *)0x0) {
    ppuVar2 = &PTR_0071ce50;
  }
  else {
    *piVar6 = *piVar6 + 1;
    ppuVar2 = (undefined **)Tcl_GetStringFromObj(piVar6,0);
    *piVar6 = *piVar6 + -1;
    if (*piVar6 < 1) {
      TclFreeObj(piVar6);
    }
  }
  FUN_006b8fb0(ppuVar2);
  _File = _fopen((char *)(local_18 + 3),"rb");
  uVar7 = extraout_ECX;
  if (_File != (FILE *)0x0) {
    _fclose(_File);
    uVar7 = extraout_ECX_00;
  }
  local_11 = _File == (FILE *)0x0;
  local_8._0_1_ = 3;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
    uVar7 = extraout_ECX_01;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_11) {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_28 + 1;
    }
    piVar6 = (int *)*puVar3;
    if (piVar6 != (int *)0x0) {
      *piVar6 = *piVar6 + 1;
    }
    FUN_006bc6a0("File not found",piVar6);
    uVar7 = 1;
    goto LAB_00669ded;
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  if (param_3._3_1_ == '\0') {
    puVar3 = (undefined4 *)FUN_006bb140();
    piVar6 = (int *)*puVar3;
    if (piVar6 != (int *)0x0) {
      *piVar6 = *piVar6 + 1;
    }
    pcVar5 = TclFreeObj_exref;
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
      TclFreeObj(param_3);
    }
  }
  else {
    if (DAT_00772dd0 == 0) {
      FUN_006bb140();
    }
    else {
      FUN_006bbb00(&param_3,ppuVar2,uVar7);
    }
    piVar6 = param_3;
    pcVar5 = TclFreeObj_exref;
    if (((param_3 != (int *)0x0) &&
        (*param_3 = *param_3 + 1, pcVar5 = TclFreeObj_exref, param_3 != (int *)0x0)) &&
       (*param_3 = *param_3 + -1, pcVar5 = TclFreeObj_exref, *param_3 < 1)) {
      TclFreeObj(param_3);
    }
  }
  if (local_38 == 0) {
    uVar7 = 0;
    if (piVar6 == (int *)0x0) goto LAB_00669ded;
LAB_00669ddd:
    *piVar6 = *piVar6 + -1;
    uVar7 = 0;
    if (0 < *piVar6) goto LAB_00669ded;
    (*pcVar5)(piVar6);
  }
  else {
    if (piVar6 != (int *)0x0) {
      Tcl_SetObjResult(local_38,piVar6);
      goto LAB_00669ddd;
    }
    Tcl_ResetResult(local_38);
  }
  uVar7 = 0;
LAB_00669ded:
  FUN_006bc0d0();
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

