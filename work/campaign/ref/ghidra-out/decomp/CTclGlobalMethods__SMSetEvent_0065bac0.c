
undefined4
CTclGlobalMethods__SMSetEvent(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined **ppuVar3;
  int *piVar4;
  AchievementManager *this;
  int iVar5;
  undefined4 *puVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int local_3c;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070eeed;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7318) &&
     (FUN_006cebf4(&DAT_00ca7318,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7318 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca731c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::SMSetEvent()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7318);
  }
  iVar5 = DAT_00ca731c;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca731c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar8;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar1 = param_3;
  local_8 = CONCAT31(local_8._1_3_,1);
  if ((int)param_3 < 2) {
    FUN_006bc8f0(1);
    uVar8 = 1;
  }
  else {
    FUN_004298b0(param_3,param_4);
    uVar7 = true;
    param_3 = CONCAT13(1,(undefined3)param_3);
    if (uVar1 == 3) {
      if (local_24 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_2c;
        if (local_28 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_28 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar6 = local_2c + 2;
      }
      piVar4 = (int *)*puVar6;
      if (piVar4 == (int *)0x0) {
        uVar7 = false;
        param_3 = param_3 & 0xffffff;
      }
      else {
        *piVar4 = *piVar4 + 1;
        iVar2 = Tcl_GetBooleanFromObj(0,piVar4,&param_3);
        uVar7 = iVar2 != 1 && param_3 != 0;
        *piVar4 = *piVar4 + -1;
        param_3 = CONCAT13(uVar7,(undefined3)param_3);
        if (*piVar4 < 1) {
          TclFreeObj(piVar4);
        }
      }
    }
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_28 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_2c + 1;
    }
    piVar4 = (int *)*puVar6;
    if (piVar4 != (int *)0x0) {
      *piVar4 = *piVar4 + 1;
    }
    local_8._0_1_ = 3;
    local_1c = piVar4;
    if (piVar4 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar4,0);
    }
    local_14 = piVar4;
    FUN_006b8fb0(ppuVar3);
    local_8._0_1_ = 5;
    if ((local_14 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
    local_14 = (int *)FUN_005f8080();
    if ((bool)uVar7 != false) {
      piVar4 = (int *)FUN_006ba810(0x19);
      piVar4[1] = 4;
      *(undefined1 *)(piVar4 + 3) = 0;
      piVar4[2] = 0;
      *piVar4 = 1;
      local_1c = piVar4;
      FUN_006b97f0(&local_1c);
      local_8._0_1_ = 6;
      *piVar4 = *piVar4 + -1;
      if (*piVar4 == 0) {
        FUN_006ba940();
      }
      local_8._0_1_ = 5;
      this = AchievementManager::GetInstance();
      AchievementManager::CheckTriggerName(this,(char *)(local_18 + 3));
      FUN_005f8840();
      uVar7 = param_3._3_1_;
    }
    param_3 = FUN_005f8a70(&local_18);
    if (param_3 == 0xffffffff) {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_2c;
        if (local_28 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_28 < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar6 = local_2c + 1;
      }
      piVar4 = (int *)*puVar6;
      if (piVar4 != (int *)0x0) {
        *piVar4 = *piVar4 + 1;
      }
      FUN_006bc6a0("Story Event not found",piVar4);
      uVar8 = 1;
    }
    else {
      if ((uint)local_14[1] <= param_3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined1 *)(*local_14 + 0xc + param_3 * 0x10) = uVar7;
      piVar4 = (int *)Tcl_NewIntObj(param_3);
      *piVar4 = *piVar4 + 1;
      iVar2 = *piVar4;
      if (local_3c != 0) {
        Tcl_SetObjResult(local_3c,piVar4);
        iVar2 = *piVar4;
      }
      *piVar4 = iVar2 + -1;
      if (iVar2 + -1 < 1) {
        TclFreeObj(piVar4);
      }
      uVar8 = 0;
    }
    local_8._0_1_ = 8;
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 9;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,10);
    FUN_004297b0(0);
    if (local_2c != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

