
undefined4
CTclGlobalMethods__MapSetLayer2
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  int *piVar6;
  int iVar7;
  CFluid *this;
  undefined4 uVar8;
  int *piVar9;
  undefined8 uVar10;
  undefined4 *local_48;
  uint local_44;
  int local_40;
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e1b5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7180) &&
     (FUN_006cebf4(&DAT_00ca7180,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7180 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca7184 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::MapSetLayer2()";
    *(int *)(&DAT_00773650 + iVar7) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7180);
  }
  iVar7 = DAT_00ca7184;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7184 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar8;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar3 == 0) {
    uVar10 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (piVar1 == (int *)&DAT_00000004) {
    if (local_40 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_48 + 3;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_48 + 1;
    }
    local_18 = (int *)*puVar4;
    if (local_18 != (int *)0x0) {
      *local_18 = *local_18 + 1;
    }
    if (local_40 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_48 + 2;
    }
    local_14 = (int *)*puVar4;
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
    local_8._0_1_ = 5;
    if (piVar1 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar5);
    local_8._0_1_ = 6;
    iVar3 = FUN_006b9e50(0x2f);
    piVar9 = param_3;
    if (iVar3 == -1) {
      iVar3 = FUN_006b9f40("splt_");
      if (iVar3 == -1) {
        piVar6 = (int *)FUN_006b9410(&param_3);
        local_8._0_1_ = 7;
        piVar9 = (int *)*piVar6;
        if (piVar9 != (int *)0x0) {
          *piVar9 = *piVar9 + 1;
        }
        piVar2 = piVar9;
        if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
          param_3 = piVar9;
          FUN_006ba940();
          piVar2 = param_3;
        }
        param_3 = piVar2;
        piVar9[2] = *(int *)(*piVar6 + 8);
        local_8 = CONCAT31(local_8._1_3_,8);
      }
      else {
        FUN_006b9500("split/");
        local_8._0_1_ = 9;
        piVar6 = (int *)FUN_006b9410(&param_3);
        local_8._0_1_ = 10;
        piVar9 = (int *)*piVar6;
        if (piVar9 != (int *)0x0) {
          *piVar9 = *piVar9 + 1;
        }
        piVar2 = piVar9;
        if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
          param_3 = piVar9;
          FUN_006ba940();
          piVar2 = param_3;
        }
        param_3 = piVar2;
        piVar9[2] = *(int *)(*piVar6 + 8);
        local_8._0_1_ = 0xb;
        if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
          FUN_006ba940();
        }
        local_8 = CONCAT31(local_8._1_3_,0xc);
        local_1c = local_20;
      }
      if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 6;
    }
    if (local_18 != (int *)0x0) {
      Tcl_GetIntFromObj(0,local_18,local_24);
    }
    if (local_14 != (int *)0x0) {
      Tcl_GetIntFromObj(0,local_14,local_28);
    }
    this = (CFluid *)piVar9[2];
    if (this == (CFluid *)0xffffffff) {
      piVar6 = piVar9 + 3;
      do {
        iVar3 = *piVar6;
        piVar6 = (int *)((int)piVar6 + 1);
      } while ((char)iVar3 != '\0');
      this = (CFluid *)((int)piVar6 - (int)((int)piVar9 + 0xd));
      piVar9[2] = (int)this;
    }
    if ((this != (CFluid *)0x0) && ((char)PTR_0077241c->mapFlags != '\0')) {
      CFluid__Tick(this);
    }
    local_8 = CONCAT31(local_8._1_3_,0xf);
    *piVar9 = *piVar9 + -1;
    if (*piVar9 == 0) {
      FUN_006ba940();
    }
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 < 1)) {
      TclFreeObj(local_14);
    }
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
      TclFreeObj(local_18);
    }
    uVar8 = 0;
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  else {
    FUN_006bc8f0(3);
    uVar8 = 1;
  }
  local_8._0_1_ = 0x10;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x11);
  FUN_004297b0(0);
  if (local_48 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

