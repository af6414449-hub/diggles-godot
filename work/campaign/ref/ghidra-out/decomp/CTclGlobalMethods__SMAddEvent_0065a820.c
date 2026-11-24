
undefined4
CTclGlobalMethods__SMAddEvent(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  undefined **ppuVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  int **ppiVar12;
  int local_44;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  int *local_20;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ed9d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7300) &&
     (FUN_006cebf4(&DAT_00ca7300,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7300 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca7304 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "TCL:CTclGlobalMethods::SMAddEvent()";
    *(int *)(&DAT_00773650 + iVar9) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7300);
  }
  iVar9 = DAT_00ca7304;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7304 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar10;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar3 == 0) {
    uVar11 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 < 2) {
    FUN_006bc8f0(1);
    uVar10 = 1;
  }
  else {
    FUN_004298b0(param_3,param_4);
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_34 + 1;
    }
    piVar7 = (int *)*puVar6;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar7 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar7,0);
    }
    FUN_006b8fb0(ppuVar4);
    local_8._0_1_ = 5;
    if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
      TclFreeObj(piVar7);
    }
    ppiVar12 = &local_18;
    FUN_005f8080(ppiVar12);
    uVar5 = FUN_005f8670(ppiVar12);
    if (uVar5 == 0xffffffff) {
      if (local_2c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_34;
        if (local_30 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_30 < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar6 = local_34 + 1;
      }
      piVar7 = (int *)*puVar6;
      if (piVar7 != (int *)0x0) {
        *piVar7 = *piVar7 + 1;
      }
      FUN_006bc6a0("Story Event redefinition",piVar7);
      uVar10 = 1;
    }
    else {
      if (2 < param_3) {
        puVar6 = (undefined4 *)FUN_004295e0(2);
        piVar7 = (int *)*puVar6;
        if (piVar7 != (int *)0x0) {
          *piVar7 = *piVar7 + 1;
        }
        local_8._0_1_ = 7;
        if (piVar7 == (int *)0x0) {
          ppuVar4 = &PTR_0071ce50;
        }
        else {
          ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar7,0);
        }
        local_14 = piVar7;
        FUN_006b8fb0(ppuVar4);
        local_8._0_1_ = 9;
        if ((local_14 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
          TclFreeObj(piVar7);
        }
        FUN_006b8fb0("activate");
        local_8._0_1_ = 10;
        uVar2 = (undefined1)local_8;
        local_8._0_1_ = 10;
        if (param_3 == 4) {
          puVar6 = (undefined4 *)FUN_004295e0(3);
          piVar7 = (int *)*puVar6;
          if (piVar7 != (int *)0x0) {
            *piVar7 = *piVar7 + 1;
          }
          local_8._0_1_ = 0xb;
          if (piVar7 == (int *)0x0) {
            ppuVar4 = &PTR_0071ce50;
          }
          else {
            ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar7,0);
          }
          FUN_006b9200(ppuVar4);
          local_8._0_1_ = 10;
          FUN_006bad60();
          uVar2 = (undefined1)local_8;
        }
        local_8._0_1_ = uVar2;
        piVar7 = (int *)FUN_005f8080();
        if ((uint)piVar7[1] <= uVar5) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar8 = (int *)(*piVar7 + uVar5 * 0x10 + 4);
        piVar1 = (int *)*piVar8;
        *piVar8 = (int)local_20;
        if (local_20 != (int *)0x0) {
          *local_20 = *local_20 + 1;
        }
        if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
          FUN_006ba940();
        }
        *(int *)(*piVar8 + 8) = local_20[2];
        if ((uint)piVar7[1] <= uVar5) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar1 = local_14;
        iVar3 = uVar5 * 0x10 + *piVar7;
        piVar7 = *(int **)(iVar3 + 8);
        *(int **)(iVar3 + 8) = local_14;
        if (local_14 != (int *)0x0) {
          *local_14 = *local_14 + 1;
        }
        if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 == 0)) {
          FUN_006ba940();
        }
        *(int *)(*(int *)(iVar3 + 8) + 8) = piVar1[2];
        local_8._0_1_ = 0xc;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          FUN_006ba940();
        }
        local_8._0_1_ = 0xd;
        *local_20 = *local_20 + -1;
        if (*local_20 == 0) {
          FUN_006ba940();
        }
      }
      piVar7 = (int *)Tcl_NewIntObj(uVar5);
      *piVar7 = *piVar7 + 1;
      iVar3 = *piVar7;
      if (local_44 != 0) {
        Tcl_SetObjResult(local_44,piVar7);
        iVar3 = *piVar7;
      }
      *piVar7 = iVar3 + -1;
      if (iVar3 + -1 < 1) {
        TclFreeObj(piVar7);
      }
      uVar10 = 0;
    }
    local_8._0_1_ = 0xe;
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 0xf;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,0x10);
    FUN_004297b0(0);
    if (local_34 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar10;
}

