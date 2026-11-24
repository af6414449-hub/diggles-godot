
undefined4
CTclObjMethods__GetRenderMaterial
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined8 uVar7;
  int local_30;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007119fd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7940) &&
     (FUN_006cebf4(&DAT_00ca7940,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7940 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca7944 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::GetRenderMaterial()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7940);
  }
  iVar4 = DAT_00ca7944;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7944 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar5;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar7 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  if (param_3 < 2) {
    FUN_006bc8f0(1);
    uVar5 = 1;
    goto LAB_0069037b;
  }
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  iVar3 = FUN_005c71c0(param_4,2,1);
  if (iVar3 == 0) {
    uVar5 = 1;
  }
  else {
    uVar1 = *(uint *)(iVar3 + 0x3cc);
    iVar3 = FUN_0045a470();
    if (*(uint *)(iVar3 + 0x105c) <= uVar1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar2 = *(int **)(*(int *)(iVar3 + 0x1058) + 0x40 + uVar1 * 0x48);
    if ((piVar2 == (int *)0x0) || (*piVar2 = *piVar2 + 1, piVar2 + 3 != (int *)0x0)) {
      piVar6 = (int *)Tcl_NewStringObj(piVar2 + 3,0xffffffff);
      *piVar6 = *piVar6 + 1;
    }
    else {
      piVar6 = (int *)0x0;
    }
    if (local_30 == 0) {
      if (piVar6 != (int *)0x0) goto LAB_0069032c;
    }
    else if (piVar6 == (int *)0x0) {
      Tcl_ResetResult(local_30);
    }
    else {
      Tcl_SetObjResult(local_30,piVar6);
LAB_0069032c:
      *piVar6 = *piVar6 + -1;
      if (*piVar6 < 1) {
        TclFreeObj(piVar6);
      }
    }
    uVar5 = 0;
    local_8._0_1_ = 3;
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
      FUN_006ba940();
    }
  }
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  if (local_20 != 0) {
    FUN_006ba940();
  }
LAB_0069037b:
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

