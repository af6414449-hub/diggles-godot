
undefined4
CTclGlobalMethods__fincr(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  float fVar8;
  double dVar9;
  undefined8 uVar10;
  int local_44;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  double local_28;
  undefined4 *local_20;
  undefined8 local_1c;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d42d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6fe8) &&
     (FUN_006cebf4(&DAT_00ca6fe8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6fe8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6fec = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::fincr()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6fe8);
  }
  iVar5 = DAT_00ca6fec;
  local_20 = &DAT_00ca6fec;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6fec * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar10 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)param_3 < 2) {
    FUN_006bc8f0(3);
    uVar6 = 1;
  }
  else {
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_34 + 1;
    }
    if (local_44 == 0) {
      local_14 = (int *)0x0;
    }
    else {
      local_14 = (int *)Tcl_ObjGetVar2(local_44,*puVar3,0,0);
      if (local_14 != (int *)0x0) {
        *local_14 = *local_14 + 1;
      }
    }
    piVar1 = local_14;
    local_8 = CONCAT31(local_8._1_3_,3);
    if (local_14 == (int *)0x0) {
      if (local_2c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar3 = local_34;
        if (local_30 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_30 < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar3 = local_34 + 1;
      }
      piVar4 = (int *)*puVar3;
      if (piVar4 != (int *)0x0) {
        *piVar4 = *piVar4 + 1;
      }
      FUN_006bc6a0("unknown variable",piVar4);
      fVar8 = 0.0;
    }
    else {
      iVar2 = Tcl_GetDoubleFromObj(0,local_14,&local_28);
      if (iVar2 == 1) {
        fVar8 = 0.0;
      }
      else {
        fVar8 = (float)local_28;
      }
    }
    local_1c = (double)fVar8;
    pcVar7 = TclFreeObj_exref;
    dVar9 = 1.0;
    if (param_3 == (int *)0x3) {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar3 = local_34;
        if (local_30 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_30 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar3 = local_34 + 2;
      }
      piVar4 = (int *)*puVar3;
      if (piVar4 == (int *)0x0) {
        dVar9 = 0.0;
        pcVar7 = TclFreeObj_exref;
      }
      else {
        *piVar4 = *piVar4 + 1;
        iVar2 = Tcl_GetDoubleFromObj(0,piVar4,&local_28);
        if (iVar2 == 1) {
          fVar8 = 0.0;
        }
        else {
          fVar8 = (float)local_28;
        }
        *piVar4 = *piVar4 + -1;
        pcVar7 = TclFreeObj_exref;
        dVar9 = (double)fVar8;
        if (*piVar4 < 1) {
          local_28 = dVar9;
          TclFreeObj(piVar4);
          dVar9 = local_28;
        }
      }
    }
    local_28 = dVar9 + local_1c;
    uVar6 = FUN_006bad90();
    local_1c = (double)CONCAT44(uVar6,(undefined4)local_1c);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_34 + 1;
    }
    FUN_006bc9c0(puVar3,local_1c._4_4_);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
      (*pcVar7)(param_3);
    }
    piVar4 = (int *)FUN_006bad90();
    if (local_44 != 0) {
      if (*piVar4 == 0) {
        Tcl_ResetResult(local_44);
      }
      else {
        Tcl_SetObjResult(local_44,*piVar4);
      }
    }
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
      (*pcVar7)(param_3);
    }
    uVar6 = 0;
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

