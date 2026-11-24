
undefined4
CTclObjMethods__SetParticleSource
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c3dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca78e0) &&
     (FUN_006cebf4(&DAT_00ca78e0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca78e0 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca78e4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::SetParticleSource()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca78e0);
  }
  iVar3 = DAT_00ca78e4;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca78e4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
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
  iVar2 = FUN_005c71c0(param_4,4,1);
  if (iVar2 == 0) {
    uVar6 = 1;
  }
  else {
    if (local_20 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_28 + 2;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 == (int *)0x0) {
      uVar4 = 0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_14);
      *piVar1 = *piVar1 + -1;
      uVar4 = -(uint)(iVar3 != 1) & local_14;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    if (local_20 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_28 + 3;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 == (int *)0x0) {
      FUN_005d8660(uVar4,0);
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_14);
      *piVar1 = *piVar1 + -1;
      local_14 = -(uint)(iVar3 != 1) & local_14;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
      FUN_005d8660(uVar4,local_14);
      if (((local_14 == 2) || (local_14 == 3)) &&
         (puVar5 = *(undefined4 **)(iVar2 + 0x2b0), puVar5 != (undefined4 *)0x0)) {
        if (uVar4 < 0x20) {
          puVar5[uVar4] = 0xffffffff;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          *puVar5 = 0xffffffff;
        }
      }
    }
    uVar6 = 0;
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
  return uVar6;
}

