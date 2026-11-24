
undefined4
CTclGlobalMethods__GetDigEdge(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 in_XMM0 [16];
  undefined1 auVar9 [16];
  undefined8 uVar10;
  int local_64;
  undefined4 *local_54;
  uint local_50;
  int local_4c;
  float local_40;
  float local_3c;
  int *local_38;
  int local_34;
  int *local_30;
  int local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  double dVar8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d0a5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6ef8) &&
     (FUN_006cebf4(&DAT_00ca6ef8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca6ef8 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca6efc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::GetDigEdge()";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6ef8);
  }
  iVar6 = DAT_00ca6efc;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6efc * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar10 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  if (param_3 < 3) {
    FUN_006bc8f0(2);
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
  }
  else {
    local_8 = CONCAT31(local_8._1_3_,5);
    if (local_4c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_54;
      if (local_50 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_50 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_54 + 1;
    }
    piVar2 = (int *)*puVar7;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
      *piVar2 = *piVar2 + 1;
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (piVar2 == (int *)0x0) {
      local_18 = (int *)0x0;
      local_14 = 0.0;
    }
    else {
      iVar4 = Tcl_ListObjIndex(0,piVar2,0,&local_28);
      if (iVar4 == 0) {
        iVar4 = Tcl_ListObjIndex(0,piVar2,1,&local_30);
        if (iVar4 == 0) {
          iVar4 = Tcl_ListObjIndex(0,piVar2,2,&local_38);
          if (iVar4 == 0) {
            local_24 = local_28;
            if (local_28 != (int *)0x0) {
              *local_28 = *local_28 + 1;
            }
            local_20 = local_30;
            if (local_30 != (int *)0x0) {
              *local_30 = *local_30 + 1;
            }
            local_1c = local_38;
            if (local_38 != (int *)0x0) {
              *local_38 = *local_38 + 1;
            }
            FUN_006baf40();
            auVar9._4_12_ = in_XMM0._4_12_;
            auVar9._0_4_ = (int *)(float)in_XMM0._0_8_;
            dVar8 = auVar9._0_8_;
            local_18 = auVar9._0_4_;
            FUN_006baf40();
            local_14 = (float)dVar8;
            FUN_006baf40();
            FUN_006bad60();
            FUN_006bad60();
            FUN_006bad60();
          }
          else {
            local_18 = (int *)0x0;
            local_14 = 0.0;
          }
        }
        else {
          local_18 = (int *)0x0;
          local_14 = 0.0;
        }
      }
      else {
        local_18 = (int *)0x0;
        local_14 = 0.0;
      }
    }
    iVar4 = FUN_005c71c0(param_4,3,2);
    piVar3 = local_18;
    if (iVar4 != 0) {
      local_38 = (int *)(int)ROUND(*(float *)(iVar4 + 0x10) + 0.5);
      local_3c = (float)(int)ROUND(*(float *)(iVar4 + 0xc) + 0.5);
      local_30 = (int *)(int)ROUND(local_14);
      DAT_00772dd8 = (int)ROUND((float)local_18);
      local_34 = DAT_00772dd8;
      FUN_005981d0(&local_2c,&local_34,&local_3c,*(undefined4 *)(iVar4 + 0x36c));
      local_40 = (float)local_2c;
      local_38 = (int *)0x41600000;
      local_3c = (float)(int)local_28;
      piVar5 = (int *)FUN_006badc0(&local_40);
      if (local_64 != 0) {
        if (*piVar5 == 0) {
          Tcl_ResetResult(local_64);
        }
        else {
          Tcl_SetObjResult(local_64,*piVar5);
        }
      }
      if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
        TclFreeObj(piVar3);
      }
      if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
        TclFreeObj(piVar2);
      }
      local_8._0_1_ = 8;
      FUN_004297b0(0);
      local_8 = CONCAT31(local_8._1_3_,9);
      FUN_004297b0(0);
      if (local_54 != (undefined4 *)0x0) {
        FUN_006ba940();
      }
      FUN_006bc0d0();
      FUN_0043fd30();
      ExceptionList = local_10;
      return 0;
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_8._0_1_ = 6;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,7);
  }
  FUN_004297b0(0);
  if (local_54 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

