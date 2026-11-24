
undefined4
CTclObjMethods__GnomeIdle(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710ad5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca74d8) &&
     (FUN_006cebf4(&DAT_00ca74d8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca74d8 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca74dc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::GnomeIdle()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca74d8);
  }
  iVar4 = DAT_00ca74dc;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca74dc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar6 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  iVar2 = FUN_005c71c0(param_4,2,1);
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 0x3e4) != 0) {
      if (param_3 == 2) {
        FUN_005ece90();
        uVar5 = 0;
        goto LAB_006761b9;
      }
      puVar3 = (undefined4 *)FUN_004295e0(2);
      piVar1 = (int *)*puVar3;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      local_8._0_1_ = 3;
      if (((piVar1 == (int *)0x0) || (iVar2 = Tcl_GetBooleanFromObj(0,piVar1,&local_14), iVar2 == 1)
          ) || (local_14 == 0)) {
        FUN_005ed0b0();
        if (piVar1 != (int *)0x0) goto LAB_0067626d;
      }
      else {
        FUN_005ece90();
LAB_0067626d:
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
        }
      }
      uVar5 = 0;
      goto LAB_006761b9;
    }
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_28 + 1;
    }
    piVar1 = (int *)*puVar3;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("no prod control",piVar1);
  }
  uVar5 = 1;
LAB_006761b9:
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

