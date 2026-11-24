
/* WARNING: Removing unreachable block (ram,0x00629f0e) */
/* WARNING: Removing unreachable block (ram,0x00629f1d) */
/* WARNING: Removing unreachable block (ram,0x00629f24) */

undefined4
CTclGlobalMethods__GetView(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  int local_34;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c415;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6d48) &&
     (FUN_006cebf4(&DAT_00ca6d48,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6d48 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca6d4c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::GetView()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6d48);
  }
  iVar3 = DAT_00ca6d4c;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6d4c * 0x40);
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
  uVar1 = (uint)param_3;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004298b0(param_3,param_4);
  param_3 = (int *)((uint)param_3 & 0xffffff);
  iVar2 = *(int *)(DAT_00772400 + 0x5a4);
  if (uVar1 == 2) {
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_24 + 1;
    }
    piVar4 = (int *)*puVar6;
    if (piVar4 == (int *)0x0) {
      param_3 = (int *)((uint)param_3 & 0xffffff);
    }
    else {
      *piVar4 = *piVar4 + 1;
      iVar3 = Tcl_GetBooleanFromObj(0,piVar4,&param_3);
      if (iVar3 == 1) {
        param_3 = (int *)((uint)param_3 & 0xffffff);
      }
      else {
        param_3 = (int *)CONCAT13(param_3 != (int *)0x0,param_3._0_3_);
      }
      *piVar4 = *piVar4 + -1;
      if (*piVar4 < 1) {
        TclFreeObj(piVar4);
      }
    }
  }
  piVar4 = (int *)Tcl_NewListObj(0,0);
  if ((piVar4 != (int *)0x0) && (iVar3 = *piVar4, *piVar4 = iVar3, iVar3 < 1)) {
    TclFreeObj(piVar4);
  }
  if ((param_3._3_1_ == '\0') || (*(float *)(iVar2 + 0x134) < 0.0)) {
    uVar5 = FUN_006bad90();
    FUN_006bb930(uVar5);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
      TclFreeObj(param_3);
    }
    uVar5 = FUN_006bad90();
    FUN_006bb930(uVar5);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
      TclFreeObj(param_3);
    }
    uVar5 = FUN_006bad90();
    FUN_006bb930(uVar5);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
      TclFreeObj(param_3);
    }
    uVar5 = FUN_006bad90();
    FUN_006bb930(uVar5);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
      TclFreeObj(param_3);
    }
  }
  else {
    uVar5 = FUN_006bad90();
    FUN_006bb930(uVar5);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
      TclFreeObj(param_3);
    }
    uVar5 = FUN_006bad90();
    FUN_006bb930(uVar5);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
      TclFreeObj(param_3);
    }
    uVar5 = FUN_006bad90();
    FUN_006bb930(uVar5);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
      TclFreeObj(param_3);
    }
    uVar5 = FUN_006bad90();
    FUN_006bb930(uVar5);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
      TclFreeObj(param_3);
    }
  }
  uVar5 = FUN_006bad90();
  FUN_006bb930(uVar5);
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
    TclFreeObj(param_3);
  }
  if (local_34 != 0) {
    Tcl_ResetResult(local_34);
  }
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

