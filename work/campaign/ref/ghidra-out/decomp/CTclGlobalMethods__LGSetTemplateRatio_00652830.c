
undefined4
CTclGlobalMethods__LGSetTemplateRatio
          (undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  float fVar7;
  undefined8 uVar8;
  undefined4 *local_44;
  uint local_40;
  int local_3c;
  double local_38;
  double local_30;
  double local_28;
  undefined4 *local_20;
  int *local_1c;
  int local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e81d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7230) &&
     (FUN_006cebf4(&DAT_00ca7230,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7230 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7234 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::LGSetTemplateRatio()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7230);
  }
  iVar5 = DAT_00ca7234;
  local_20 = &DAT_00ca7234;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7234 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar6;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 5.60519e-45) {
    local_18 = FUN_0058a820();
    if (local_3c < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_44;
      if (local_40 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_40 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_44 + 3;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_3c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_44;
      if (local_40 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_40 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_44 + 2;
    }
    piVar2 = (int *)*puVar4;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    if (local_3c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_44;
      if (local_40 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_40 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_44 + 1;
    }
    local_1c = (int *)*puVar4;
    if (local_1c != (int *)0x0) {
      *local_1c = *local_1c + 1;
    }
    if (piVar1 == (int *)0x0) {
      param_3 = 0.0;
    }
    else {
      iVar3 = Tcl_GetDoubleFromObj(0,piVar1,&local_28);
      if (iVar3 == 1) {
        param_3 = 0.0;
      }
      else {
        param_3 = (float)local_28;
      }
    }
    local_14 = 0.0;
    if (piVar2 != (int *)0x0) {
      iVar3 = Tcl_GetDoubleFromObj(0,piVar2,&local_30);
      if (iVar3 == 1) {
        local_14 = 0.0;
      }
      else {
        local_14 = (float)local_30;
      }
    }
    if (local_1c == (int *)0x0) {
      *(float *)(local_18 + 0x74) = local_14;
      *(undefined4 *)(local_18 + 0x70) = 0;
      *(float *)(local_18 + 0x78) = param_3;
    }
    else {
      iVar3 = Tcl_GetDoubleFromObj(0,local_1c,&local_38);
      if (iVar3 == 1) {
        fVar7 = 0.0;
      }
      else {
        fVar7 = (float)local_38;
      }
      *(float *)(local_18 + 0x70) = fVar7;
      *(float *)(local_18 + 0x74) = local_14;
      *(float *)(local_18 + 0x78) = param_3;
      *local_1c = *local_1c + -1;
      if (*local_1c < 1) {
        TclFreeObj(local_1c);
      }
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    uVar6 = 0;
  }
  else {
    FUN_006bc8f0(3);
    uVar6 = 1;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_44 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

