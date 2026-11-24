
undefined4
CTclGlobalMethods__HF2I(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  float fVar6;
  double dVar7;
  undefined8 uVar8;
  int local_38;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  double local_1c;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a85d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6fd0) &&
     (FUN_006cebf4(&DAT_00ca6fd0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca6fd0 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca6fd4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::HF2I()";
    *(int *)(&DAT_00773650 + iVar3) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6fd0);
  }
  iVar3 = DAT_00ca6fd4;
  local_14 = &DAT_00ca6fd4;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6fd4 * 0x40);
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
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 2) {
    FUN_006bc8f0(3);
    uVar4 = 1;
  }
  else {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_28 + 1;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 == (int *)0x0) {
      dVar7 = 0.0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar1 = Tcl_GetDoubleFromObj(0,piVar2,&local_1c);
      if (iVar1 == 1) {
        fVar6 = 0.0;
      }
      else {
        fVar6 = (float)local_1c;
      }
      *piVar2 = *piVar2 + -1;
      local_1c = (double)fVar6;
      dVar7 = local_1c;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
        dVar7 = local_1c;
      }
    }
    DAT_00772dd8 = (int)ROUND((float)dVar7);
    piVar2 = (int *)Tcl_NewIntObj(DAT_00772dd8);
    *piVar2 = *piVar2 + 1;
    iVar1 = *piVar2;
    if (local_38 != 0) {
      Tcl_SetObjResult(local_38,piVar2);
      iVar1 = *piVar2;
    }
    *piVar2 = iVar1 + -1;
    if (iVar1 + -1 < 1) {
      TclFreeObj(piVar2);
    }
    uVar4 = 0;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

