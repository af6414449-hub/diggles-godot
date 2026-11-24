
undefined4
CTclObjMethods__SetProdOwnerStrength
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  float fVar5;
  undefined8 uVar6;
  int local_38;
  int *local_28;
  uint local_24;
  int local_20;
  undefined4 local_18;
  int *piStack_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071162d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca79a0) &&
     (FUN_006cebf4(&DAT_00ca79a0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca79a0 == -1)) {
    iVar2 = DAT_00783650 * 0x40;
    DAT_00ca79a4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar2) = "TCL:CTclObjMethods::SetProdOwnerStrength()";
    *(int *)(&DAT_00773650 + iVar2) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca79a0);
  }
  iVar2 = DAT_00ca79a4;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca79a4 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar2 * 0x10];
  if (iVar1 == 0) {
    uVar6 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar2 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar2 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar2 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_005c71c0(param_4,3,1);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x3e0) == 0)) {
    uVar4 = 1;
  }
  else {
    if (local_20 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_28 + 2;
    }
    if (*piVar3 == 0) {
      fVar5 = 0.0;
    }
    else {
      iVar2 = Tcl_GetDoubleFromObj(0,*piVar3,&local_18);
      if (iVar2 == 1) {
        fVar5 = 0.0;
      }
      else {
        fVar5 = (float)(double)CONCAT44(piStack_14,local_18);
      }
    }
    *(float *)(*(int *)(iVar1 + 0x3e0) + 0x68) = fVar5;
    piVar3 = (int *)FUN_006bad90();
    if (local_38 != 0) {
      if (*piVar3 == 0) {
        Tcl_ResetResult(local_38);
      }
      else {
        Tcl_SetObjResult(local_38,*piVar3);
      }
    }
    if ((piStack_14 != (int *)0x0) && (*piStack_14 = *piStack_14 + -1, *piStack_14 < 1)) {
      TclFreeObj(piStack_14);
    }
    uVar4 = 0;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_28 != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

