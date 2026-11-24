
undefined4
CTclObjMethods__SetRenderMaterial
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007119bd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7938) &&
     (FUN_006cebf4(&DAT_00ca7938,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7938 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca793c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::SetRenderMaterial()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7938);
  }
  iVar5 = DAT_00ca793c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca793c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar7;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar7 = param_4;
  local_8._0_1_ = 1;
  if ((int)param_3 < 2) {
    FUN_006bc8f0(1);
    uVar7 = 1;
  }
  else {
    FUN_004298b0(param_3,param_4);
    local_8 = CONCAT31(local_8._1_3_,2);
    iVar3 = FUN_005c71c0(uVar7,2,1);
    if (iVar3 == 0) {
      uVar7 = 1;
    }
    else {
      if (local_20 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_28;
        if (local_24 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_24 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar6 = local_28 + 2;
      }
      piVar1 = (int *)*puVar6;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      local_8._0_1_ = 3;
      if (piVar1 == (int *)0x0) {
        ppuVar4 = &PTR_0071ce50;
      }
      else {
        ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
      }
      FUN_006b8fb0(ppuVar4);
      local_8._0_1_ = 4;
      FUN_0045a470();
      cVar2 = FUN_00444990(&param_3,&local_14);
      if (cVar2 == '\0') {
        local_14 = -1;
      }
      local_8._0_1_ = 5;
      if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
        FUN_006ba940();
      }
      local_8 = CONCAT31(local_8._1_3_,3);
      if (local_14 == -1) {
        if (piVar1 != (int *)0x0) {
          *piVar1 = *piVar1 + 1;
        }
        FUN_006bc6a0("invalid material",piVar1);
        uVar7 = 1;
      }
      else {
        *(int *)(iVar3 + 0x3cc) = local_14;
        FUN_005ca820();
        uVar7 = 0;
      }
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
        TclFreeObj(piVar1);
      }
    }
    local_8._0_1_ = 6;
    FUN_004297b0(0);
    local_8._0_1_ = 7;
    FUN_004297b0(0);
    if (local_28 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

