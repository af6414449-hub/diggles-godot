
undefined4
CTclObjMethods__SetPosY(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  float local_24;
  float local_20;
  float fStack_1c;
  int *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007112ad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7718) &&
     (FUN_006cebf4(&DAT_00ca7718,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7718 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca771c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::SetPosY()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7718);
  }
  iVar4 = DAT_00ca771c;
  local_14 = &DAT_00ca771c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca771c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar6 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  iVar3 = FUN_005c71c0(param_4,3,1);
  if (iVar3 != 0) {
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_30 + 2;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    local_18 = piVar2;
    if (piVar2 == (int *)0x0) {
      local_20 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,piVar2,&local_20);
      if (iVar4 == 1) {
        local_20 = 0.0;
      }
      else {
        local_20 = (float)(double)CONCAT44(fStack_1c,local_20);
      }
    }
    local_24 = *(float *)(iVar3 + 0xc);
    fStack_1c = *(float *)(iVar3 + 0x14);
    if ((((NAN(local_24)) || (*(float *)(iVar3 + 0x10) != local_20)) || (NAN(fStack_1c))) &&
       (FUN_005cd8e0(&local_24), *(int *)(iVar3 + 0x238) == 0)) {
      FUN_005ebc90(iVar3);
      FUN_005eb470(iVar3);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_8._0_1_ = 5;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_004297b0(0);
    if (local_30 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_0043fd30();
    ExceptionList = local_10;
    return 0;
  }
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

