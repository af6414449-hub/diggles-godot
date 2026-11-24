
undefined4
CTclClassDefMethods__ClassFlagOffset
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  float fVar7;
  undefined8 uVar8;
  undefined4 *local_38;
  uint local_34;
  int local_30;
  double local_2c;
  double local_24;
  undefined4 *local_1c;
  int local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a81d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6b98) &&
     (FUN_006cebf4(&DAT_00ca6b98,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6b98 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6b9c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclClassDefMethods::ClassFlagOffset()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6b98);
  }
  iVar4 = DAT_00ca6b9c;
  local_1c = &DAT_00ca6b9c;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6b9c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar5;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_18 = DAT_00772440;
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar5 = 1;
    goto LAB_00614202;
  }
  if (param_3 != 3) {
    FUN_006bc8f0(2);
    uVar5 = 1;
    goto LAB_00614202;
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
  piVar1 = (int *)*puVar6;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
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
  piVar2 = (int *)*puVar6;
  if (piVar2 == (int *)0x0) {
LAB_00614183:
    local_14 = 0.0;
  }
  else {
    *piVar2 = *piVar2 + 1;
    iVar3 = Tcl_GetDoubleFromObj(0,piVar2,&local_24);
    if (iVar3 == 1) goto LAB_00614183;
    local_14 = (float)local_24;
  }
  if (piVar1 == (int *)0x0) {
    fVar7 = 0.0;
  }
  else {
    iVar3 = Tcl_GetDoubleFromObj(0,piVar1,&local_2c);
    if (iVar3 == 1) {
      fVar7 = 0.0;
    }
    else {
      fVar7 = (float)local_2c;
    }
  }
  iVar3 = *(int *)(local_18 + 4);
  *(float *)(iVar3 + 0xcec) = fVar7;
  *(undefined4 *)(iVar3 + 0xcf0) = 0x3f800000;
  *(float *)(iVar3 + 0xcf4) = local_14;
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    TclFreeObj(piVar2);
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  uVar5 = 0;
LAB_00614202:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_38 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

