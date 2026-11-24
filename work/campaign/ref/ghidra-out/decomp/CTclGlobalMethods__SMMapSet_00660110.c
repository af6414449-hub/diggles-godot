
undefined4
CTclGlobalMethods__SMMapSet(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f11d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7388) &&
     (FUN_006cebf4(&DAT_00ca7388,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7388 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca738c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::SMMapSet()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7388);
  }
  iVar4 = DAT_00ca738c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca738c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  if ((param_3 == 3) || (param_3 == 5)) {
    FUN_004298b0(param_3,param_4);
    local_8 = CONCAT31(local_8._1_3_,2);
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
    if (piVar1 == (int *)0x0) {
      local_18 = 0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar2 = Tcl_GetIntFromObj(0,piVar1,&local_18);
      *piVar1 = *piVar1 + -1;
      local_18 = local_18 & -(uint)(iVar2 != 1);
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
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
    piVar1 = (int *)*puVar8;
    if (piVar1 == (int *)0x0) {
      local_14 = 0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar2 = Tcl_GetIntFromObj(0,piVar1,&local_14);
      *piVar1 = *piVar1 + -1;
      local_14 = local_14 & -(uint)(iVar2 != 1);
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    uVar5 = 0;
    uVar3 = 0;
    if (4 < (int)param_3) {
      if (local_24 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_2c;
        if (local_28 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_28 < 4) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar8 = local_2c + 3;
      }
      piVar1 = (int *)*puVar8;
      if (piVar1 == (int *)0x0) {
        param_3 = 0;
        pcVar6 = Tcl_GetIntFromObj_exref;
      }
      else {
        *piVar1 = *piVar1 + 1;
        pcVar6 = Tcl_GetIntFromObj_exref;
        iVar2 = Tcl_GetIntFromObj(0,piVar1,&param_3);
        *piVar1 = *piVar1 + -1;
        param_3 = param_3 & -(uint)(iVar2 != 1);
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
        }
      }
      if (local_24 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_2c;
        if (local_28 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_28 < 5) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar8 = local_2c + 4;
      }
      piVar1 = (int *)*puVar8;
      if (piVar1 == (int *)0x0) {
        uVar5 = 0;
        uVar3 = param_3;
      }
      else {
        *piVar1 = *piVar1 + 1;
        iVar2 = (*pcVar6)(0,piVar1,&local_1c);
        *piVar1 = *piVar1 + -1;
        uVar5 = -(uint)(iVar2 != 1) & local_1c;
        uVar3 = param_3;
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
          uVar3 = param_3;
        }
      }
    }
    uVar10 = local_18;
    uVar11 = local_14;
    FUN_005f8080(local_18,local_14,uVar3,uVar5);
    FUN_005fa510(uVar10,uVar11,uVar3,uVar5);
    uVar7 = 0;
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8._0_1_ = 4;
    FUN_004297b0(0);
    if (local_2c != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar7 = 1;
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

