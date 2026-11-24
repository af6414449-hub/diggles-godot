
undefined4
CTclGlobalMethods__SetBrightness
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  float fVar6;
  undefined8 uVar7;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  double local_28;
  double local_20;
  int *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d535;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7000) &&
     (FUN_006cebf4(&DAT_00ca7000,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7000 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7004 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::SetBrightness()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7000);
  }
  iVar3 = DAT_00ca7004;
  local_14 = &DAT_00ca7004;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7004 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 2) {
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_34 + 1;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    local_18 = piVar1;
    if (piVar1 == (int *)0x0) {
      fVar6 = 0.0;
    }
    else {
      iVar2 = Tcl_GetDoubleFromObj(0,piVar1,&local_20);
      if (iVar2 == 1) {
        fVar6 = 0.0;
      }
      else {
        fVar6 = (float)local_20;
      }
    }
    DAT_0076a32c = (int)ROUND(fVar6 * 30.0 - 30.0);
    DAT_0076a330 = DAT_0076a32c;
    DAT_0076a334 = DAT_0076a32c;
    DAT_00772dd8 = DAT_0076a32c;
    if (DAT_0076a338 != 0) {
      if (piVar1 == (int *)0x0) {
        fVar6 = 0.0;
      }
      else {
        iVar2 = Tcl_GetDoubleFromObj(0,piVar1,&local_28);
        if (iVar2 == 1) {
          fVar6 = 0.0;
        }
        else {
          fVar6 = (float)local_28;
        }
      }
      *(float *)(DAT_0076a338 + 0x38e4) = fVar6 * 0.1;
      FUN_00464cc0();
    }
    uVar5 = 0;
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar5 = 1;
  }
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

