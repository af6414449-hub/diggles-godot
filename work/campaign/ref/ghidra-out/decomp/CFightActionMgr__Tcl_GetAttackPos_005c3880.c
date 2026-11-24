
undefined4
CFightActionMgr__Tcl_GetAttackPos
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *in_XMM0_Da;
  undefined8 uVar6;
  int local_58;
  float local_48 [3];
  int local_3c;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 *local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070801d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca65e8) {
    FUN_006cebf4(&DAT_00ca65e8,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca65e8 == -1) {
      iVar5 = DAT_00783650 * 0x40;
      DAT_00ca65ec = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar5) = "TCL:CFightActionMgr::Tcl_GetAttackPos()";
      *(int *)(&DAT_00773650 + iVar5) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca65e8);
    }
  }
  iVar5 = DAT_00ca65ec;
  local_24 = &DAT_00ca65ec;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca65ec * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar4;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar6 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_18 = (int *)FUN_005c71c0(param_4,3,1);
  if (local_18 == (int *)0x0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
  }
  else {
    iVar2 = FUN_005c71c0(param_4,3,2);
    piVar3 = local_18;
    if (iVar2 != 0) {
      FUN_005c3620();
      local_14 = in_XMM0_Da;
      FUN_005c3620();
      if ((float)local_14 <= (float)in_XMM0_Da) {
        local_14 = in_XMM0_Da;
      }
      local_1c = piVar3[3];
      local_18 = (int *)piVar3[4];
      local_20 = piVar3[5];
      FUN_005c37b0();
      cVar1 = FUN_005bf200();
      if (cVar1 == '\0') {
        iVar5 = *(int *)(DAT_0077241c + 0x1c);
        FUN_005a9190();
        *(float *)(iVar5 + 8) = local_30;
        *(float *)(iVar5 + 0xc) = local_2c;
        *(float *)(iVar5 + 0x10) = local_28;
        *(undefined1 *)(iVar5 + 0x14) = 0;
        *(float *)(iVar5 + 0x28) = (float)local_14 + 0.2;
        FUN_005aaa30(piVar3[0x37]);
        *(int **)(iVar5 + 0x30) = local_14;
        *(int *)(iVar5 + 0x40) = local_1c;
        *(int **)(iVar5 + 0x44) = local_18;
        *(undefined1 *)(iVar5 + 0x58) = 1;
        *(int *)(iVar5 + 0x48) = local_20;
        *(undefined1 *)(iVar5 + 0x50) = 0;
        *(undefined4 *)(iVar5 + 0x34) = 0x3f19999a;
        *(undefined4 *)(iVar5 + 0x38) = 0x3e4ccccd;
        *(int *)(iVar5 + 0x3c) = iVar2;
        CPlaceFinder__FindPlace(local_48);
        if (local_48[0] == -1.0) {
          local_18 = (int *)Tcl_NewIntObj(0);
          *local_18 = *local_18 + 1;
          FUN_006bc670(&local_18);
        }
        else {
          FUN_005aa900(local_48,piVar3[0x37],0x3f800000);
          uVar4 = FUN_006badc0(local_48);
          FUN_006bc670(uVar4);
        }
        FUN_006bad60();
        FUN_00429650();
      }
      else {
        local_30 = local_30 + 0.0;
        local_28 = local_28 + 0.0;
        if (local_2c <= (float)local_18) {
          local_2c = local_2c - 1.2;
        }
        else {
          local_2c = local_2c + 1.2;
        }
        piVar3 = (int *)FUN_006badc0(&local_30);
        if (local_58 != 0) {
          if (*piVar3 == 0) {
            Tcl_ResetResult(local_58);
          }
          else {
            Tcl_SetObjResult(local_58,*piVar3);
          }
        }
        if (local_14 != (int *)0x0) {
          *local_14 = *local_14 + -1;
          if (*local_14 < 1) {
            TclFreeObj(local_14);
          }
        }
        local_8._0_1_ = 7;
        FUN_004297b0(0);
        local_8._0_1_ = 8;
        FUN_004297b0(0);
        if (local_3c != 0) {
          FUN_006ba940();
        }
      }
      FUN_006bc0d0();
      FUN_0043fd30();
      ExceptionList = local_10;
      return 0;
    }
    local_8._0_1_ = 5;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,6);
  }
  FUN_004297b0(0);
  if (local_3c != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

