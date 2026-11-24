
undefined4
CTclGlobalMethods__SMSetZone(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ccbd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7328) &&
     (FUN_006cebf4(&DAT_00ca7328,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7328 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca732c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::SMSetZone()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7328);
  }
  iVar3 = DAT_00ca732c;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca732c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  if (param_3 == 3) {
    FUN_004298b0(3,param_4);
    local_8 = CONCAT31(local_8._1_3_,2);
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_20 + 1;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 == (int *)0x0) {
      uVar5 = 0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar2 = Tcl_GetIntFromObj(0,piVar1,&param_3);
      *piVar1 = *piVar1 + -1;
      uVar5 = -(uint)(iVar2 != 1) & param_3;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    if (local_18 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_20 + 2;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 == (int *)0x0) {
      uVar7 = 0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar2 = Tcl_GetIntFromObj(0,piVar1,&param_3);
      *piVar1 = *piVar1 + -1;
      param_3 = param_3 & -(uint)(iVar2 != 1);
      uVar7 = param_3;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
        uVar7 = param_3;
      }
    }
    param_3 = FUN_005f8080();
    if (((int)uVar5 < *(int *)(param_3 + 0x70)) && (-1 < (int)uVar5)) {
      if (*(uint *)(param_3 + 0x70) <= uVar5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(uint *)(*(int *)(param_3 + 0x6c) + 4 + uVar5 * 8) = uVar7;
      uVar6 = 0;
    }
    else {
      if (local_18 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar4 = local_20;
        if (local_1c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_1c < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar4 = local_20 + 1;
      }
      piVar1 = (int *)*puVar4;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      FUN_006bc6a0("invalid zone id",piVar1);
      uVar6 = 1;
    }
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8._0_1_ = 4;
    FUN_004297b0(0);
    if (local_20 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar6 = 1;
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

