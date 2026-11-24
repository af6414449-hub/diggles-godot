
undefined4
CTclGlobalMethods__SetObjDetail
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f54d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7428) &&
     (FUN_006cebf4(&DAT_00ca7428,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7428 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca742c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::SetObjDetail()";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7428);
  }
  iVar6 = DAT_00ca742c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca742c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar7;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  if ((int)param_3 < 2) {
    FUN_006bc8f0(1);
    uVar7 = 1;
  }
  else {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_28 + 1;
    }
    piVar1 = (int *)*puVar8;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
      piVar5 = (int *)0x0;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
      piVar5 = piVar1;
    }
    FUN_006b8fb0(ppuVar4);
    local_8._0_1_ = 5;
    if ((piVar5 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    piVar5 = (int *)FUN_006ba810(0x19);
    piVar5[1] = 0x14;
    piVar5[2] = -1;
    *piVar5 = 0;
    *(undefined1 *)(piVar5 + 3) = 0;
    piVar5[3] = 0x68676968;
    *(undefined1 *)(piVar5 + 4) = 0;
    piVar5[2] = 4;
    *piVar5 = 1;
    local_14 = piVar5;
    cVar2 = FUN_006b97f0(&local_14);
    local_8._0_1_ = 6;
    *piVar5 = *piVar5 + -1;
    if (*piVar5 == 0) {
      FUN_006ba940();
    }
    local_8._0_1_ = 5;
    if (cVar2 == '\0') {
      uVar7 = FUN_006b8fb0("medium");
      cVar2 = FUN_006b97f0(uVar7);
      local_8._0_1_ = 7;
      if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 5;
      if (cVar2 == '\0') {
        uVar7 = FUN_006b8fb0(&DAT_007314a4);
        cVar2 = FUN_006b97f0(uVar7);
        local_8._0_1_ = 8;
        if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
          FUN_006ba940();
        }
        iVar3 = (cVar2 != '\0') - 1;
      }
      else {
        iVar3 = 1;
      }
    }
    else {
      iVar3 = 2;
    }
    uVar7 = 0;
    *(int *)(DAT_00772400 + 0xa3f8) = iVar3;
    local_8._0_1_ = 9;
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
      FUN_006ba940();
    }
  }
  local_8._0_1_ = 10;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

